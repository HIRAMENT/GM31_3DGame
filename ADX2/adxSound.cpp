#include "adxSound.h"
#include "ADX2_samples_acf.h"
#include "GMSummer.h"
#define USE_INGAME_PREVIEW

/* �L���[�ꗗ */
static AppCueListItem g_cue_list[] = {
	CRI_GMSUMMER_TITLE,    
	CRI_GMSUMMER_GAME,     
	CRI_GMSUMMER_CLEAR,    
	CRI_GMSUMMER_GAMEOVER, 
	CRI_GMSUMMER_SELECT,   
	CRI_GMSUMMER_CLICK,    
	CRI_GMSUMMER_SLASH,    
	CRI_GMSUMMER_DAMAGE,   
	CRI_GMSUMMER_ENEMYEX,
	CRI_GMSUMMER_PLAYERDAMAGE,
};

void ErrorCallBack(const CriChar8 * errid, CriUint32 p1, CriUint32 p2, CriUint32 * parray);
void *UserAlloc(void * obj, CriUint32 size);
void User_Free(void * obj, void * ptr);

/* �f�[�^�f�B���N�g���ւ̃p�X */
#define PATH	"ADX2/"

/* �T���v���Ŏg�p����t�@�C���� */
#define ACF_FILE			PATH"GM31Summer.acf"
#define ACB_FILE			PATH"GMSummer.acb"
#define AWB_FILE			PATH"GMSummer.awb"

/* �ő�{�C�X���𑝂₷���߂̊֘A�p�����[�^ */
#define MAX_VOICE			(24)
#define MAX_VIRTUAL_VOICE	(64)		/* �������葽��(�ʏ�{�C�X�{HCA-MX�{�C�X�{��) */
#define MAX_CRIFS_LOADER	(64)		/* �������葽��(�ʏ�{�C�X�{HCA-MX�{�C�X�{��) */

/* �ő�T���v�����O���[�g�i�s�b�`�ύX�܂ށj */
#define MAX_SAMPLING_RATE	(48000*2)

/* HCA-MX�R�[�f�b�N�̃T���v�����O���[�g */
#define SAMPLINGRATE_HCAMX		(32000)


#define X_POS_OFFSET_FOR_MAP_DRAW	(20)
#define PITCH_CHANGE_VALUE			(-200.0f)

void ADXSound::Init()
{
	AppObj obj = { 0 };
	m_AppObj = new AppObj(obj);

	/* �G���[�R�[���o�b�N�֐��̓o�^ */
	criErr_SetCallback(ErrorCallBack);

	/* �������A���P�[�^�̓o�^ */
	criAtomEx_SetUserAllocator(UserAlloc, User_Free, NULL);

	/* ���C�u�����̏������i�ő�{�C�X���ύX�j */
	CriAtomExConfig_WASAPI lib_config;
	CriFsConfig fs_config;
	criAtomEx_SetDefaultConfig_WASAPI(&lib_config);
	criFs_SetDefaultConfig(&fs_config);
	lib_config.atom_ex.max_virtual_voices = MAX_VIRTUAL_VOICE;
	lib_config.hca_mx.output_sampling_rate = SAMPLINGRATE_HCAMX;
	fs_config.num_loaders = MAX_CRIFS_LOADER;
	lib_config.atom_ex.fs_config = &fs_config;
	criAtomEx_Initialize_WASAPI(&lib_config, NULL, 0);

	/* D-Bas�̍쐬�i�ő�X�g���[�����͂����Ō��܂�܂��j */
	m_AppObj->dbas_id = criAtomDbas_Create(NULL, NULL, 0);

#if defined(USE_INGAME_PREVIEW)
	CriAtomExAsrBusAnalyzerConfig analyze_config;
	CriSint32 bus_no;
	/* �C���Q�[���v���r���[�p�̃��j�^���C�u������������ */
	criAtomExMonitor_Initialize(NULL, NULL, 0);
	/* ���x������@�\��ǉ� */
	criAtomExAsr_SetDefaultConfigForBusAnalyzer(&analyze_config);
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_AttachBusAnalyzer(bus_no, &analyze_config);
	}
#endif

	/* ACF�t�@�C���̓ǂݍ��݂Ɠo�^ */
	criAtomEx_RegisterAcfFile(NULL, ACF_FILE, NULL, 0);

	/* DSP�ݒ�̃A�^�b�` */
	criAtomEx_AttachDspBusSetting(CRI_ADX2_SAMPLES_DSPSETTING_DSPBUSSETTING_0, NULL, 0);

	/* �{�C�X�v�[���̍쐬�i�ő�{�C�X���ύX�^�ő�s�b�`�ύX�^�X�g���[���Đ��Ή��j */
	CriAtomExStandardVoicePoolConfig standard_vpool_config;
	criAtomExVoicePool_SetDefaultConfigForStandardVoicePool(&standard_vpool_config);
	standard_vpool_config.num_voices = MAX_VOICE;
	standard_vpool_config.player_config.max_sampling_rate = MAX_SAMPLING_RATE;
	standard_vpool_config.player_config.streaming_flag = CRI_TRUE;
	m_AppObj->standard_voice_pool = criAtomExVoicePool_AllocateStandardVoicePool(&standard_vpool_config, NULL, 0);

	/* HCA-MX�Đ��p�F�{�C�X�v�[���̍쐬 */
	CriAtomExHcaMxVoicePoolConfig hcamx_vpool_config;
	criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool(&hcamx_vpool_config);
	hcamx_vpool_config.num_voices = MAX_VOICE;
	hcamx_vpool_config.player_config.max_sampling_rate = MAX_SAMPLING_RATE;
	hcamx_vpool_config.player_config.streaming_flag = CRI_TRUE;
	m_AppObj->hcamx_voice_pool = criAtomExVoicePool_AllocateHcaMxVoicePool(&hcamx_vpool_config, NULL, 0);

	/* ACB�t�@�C����ǂݍ��݁AACB�n���h�����쐬 */
	m_AppObj->acb_hn = criAtomExAcb_LoadAcbFile(NULL, ACB_FILE, NULL, AWB_FILE, NULL, 0);

	/* �v���[���̍쐬 */
	m_AppObj->player = criAtomExPlayer_Create(NULL, NULL, 0);
}

void ADXSound::Update()
{
	/* �T�[�o�����̎��s */
	criAtomEx_ExecuteMain();

#if defined(USE_INGAME_PREVIEW)
	/* �o�X��͏��̎擾 */
	CriAtomExAsrBusAnalyzerInfo analyze_info;
	CriSint32 bus_no;
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_GetBusAnalyzerInfo(bus_no, &analyze_info);
	}
#endif
}

void ADXSound::Uninit()
{
	/* DSP�̃f�^�b�` */
	criAtomEx_DetachDspBusSetting();

	/* �v���[���n���h���̔j�� */
	criAtomExPlayer_Destroy(m_AppObj->player);

	/* �{�C�X�v�[���̔j�� */
	criAtomExVoicePool_Free(m_AppObj->hcamx_voice_pool);
	criAtomExVoicePool_Free(m_AppObj->standard_voice_pool);

	/* ACB�n���h���̔j�� */
	criAtomExAcb_Release(m_AppObj->acb_hn);

	/* ACF�̓o�^���� */
	criAtomEx_UnregisterAcf();

#if defined(USE_INGAME_PREVIEW)
	/* �C���Q�[���v���r���[�֘A�@�\�̏I������ */
	CriSint32 bus_no;
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_DetachBusAnalyzer(bus_no);
	}
	criAtomExMonitor_Finalize();
#endif

	/* D-BAS�̔j�� */
	criAtomDbas_Destroy(m_AppObj->dbas_id);

	/* ���C�u�����̏I�� */
	criAtomEx_Finalize_WASAPI();
}

unsigned ADXSound::Play(unsigned audioId)
{
	CriAtomExCueId start_cue_id = g_cue_list[audioId].id;

	/* �L���[ID�̎w�� */
	criAtomExPlayer_SetCueId(m_AppObj->player, m_AppObj->acb_hn, start_cue_id);

	static CriUint32 count = CriAtomExPerformanceInfo().server_process_count;

	/* �Đ��̊J�n */
	CriAtomExPlaybackId playback_id = criAtomExPlayer_Start(m_AppObj->player);

	return playback_id;
}

void ADXSound::Stop(unsigned playBackId)
{
	/* �v���[���̒�~ */
	criAtomExPlayback_Stop(playBackId);
}

void ADXSound::AllStop()
{
	/* ����̍Đ����̂ݒ�~ */
	criAtomExPlayer_Stop(m_AppObj->player);
}

void ErrorCallBack(const CriChar8 * errid, CriUint32 p1, CriUint32 p2, CriUint32 * parray)
{
	const CriChar8 *errmsg;

	/* �G���[������̕\�� */
	errmsg = criErr_ConvertIdToMessage(errid, p1, p2);

	return;
}

void * UserAlloc(void * obj, CriUint32 size)
{
	void *ptr;
	ptr = malloc(size);
	return ptr;
}

void User_Free(void * obj, void * ptr)
{
	free(ptr);
}
