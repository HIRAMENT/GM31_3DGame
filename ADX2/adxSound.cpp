#include "adxSound.h"
#include "ADX2_samples_acf.h"
#include "GMSummer.h"
#define USE_INGAME_PREVIEW

/* キュー一覧 */
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

/* データディレクトリへのパス */
#define PATH	"ADX2/"

/* サンプルで使用するファイル名 */
#define ACF_FILE			PATH"GM31Summer.acf"
#define ACB_FILE			PATH"GMSummer.acb"
#define AWB_FILE			PATH"GMSummer.awb"

/* 最大ボイス数を増やすための関連パラメータ */
#define MAX_VOICE			(24)
#define MAX_VIRTUAL_VOICE	(64)		/* ざっくり多め(通常ボイス＋HCA-MXボイス＋α) */
#define MAX_CRIFS_LOADER	(64)		/* ざっくり多め(通常ボイス＋HCA-MXボイス＋α) */

/* 最大サンプリングレート（ピッチ変更含む） */
#define MAX_SAMPLING_RATE	(48000*2)

/* HCA-MXコーデックのサンプリングレート */
#define SAMPLINGRATE_HCAMX		(32000)


#define X_POS_OFFSET_FOR_MAP_DRAW	(20)
#define PITCH_CHANGE_VALUE			(-200.0f)

void ADXSound::Init()
{
	AppObj obj = { 0 };
	m_AppObj = new AppObj(obj);

	/* エラーコールバック関数の登録 */
	criErr_SetCallback(ErrorCallBack);

	/* メモリアロケータの登録 */
	criAtomEx_SetUserAllocator(UserAlloc, User_Free, NULL);

	/* ライブラリの初期化（最大ボイス数変更） */
	CriAtomExConfig_WASAPI lib_config;
	CriFsConfig fs_config;
	criAtomEx_SetDefaultConfig_WASAPI(&lib_config);
	criFs_SetDefaultConfig(&fs_config);
	lib_config.atom_ex.max_virtual_voices = MAX_VIRTUAL_VOICE;
	lib_config.hca_mx.output_sampling_rate = SAMPLINGRATE_HCAMX;
	fs_config.num_loaders = MAX_CRIFS_LOADER;
	lib_config.atom_ex.fs_config = &fs_config;
	criAtomEx_Initialize_WASAPI(&lib_config, NULL, 0);

	/* D-Basの作成（最大ストリーム数はここで決まります） */
	m_AppObj->dbas_id = criAtomDbas_Create(NULL, NULL, 0);

#if defined(USE_INGAME_PREVIEW)
	CriAtomExAsrBusAnalyzerConfig analyze_config;
	CriSint32 bus_no;
	/* インゲームプレビュー用のモニタライブラリを初期化 */
	criAtomExMonitor_Initialize(NULL, NULL, 0);
	/* レベル測定機能を追加 */
	criAtomExAsr_SetDefaultConfigForBusAnalyzer(&analyze_config);
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_AttachBusAnalyzer(bus_no, &analyze_config);
	}
#endif

	/* ACFファイルの読み込みと登録 */
	criAtomEx_RegisterAcfFile(NULL, ACF_FILE, NULL, 0);

	/* DSP設定のアタッチ */
	criAtomEx_AttachDspBusSetting(CRI_ADX2_SAMPLES_DSPSETTING_DSPBUSSETTING_0, NULL, 0);

	/* ボイスプールの作成（最大ボイス数変更／最大ピッチ変更／ストリーム再生対応） */
	CriAtomExStandardVoicePoolConfig standard_vpool_config;
	criAtomExVoicePool_SetDefaultConfigForStandardVoicePool(&standard_vpool_config);
	standard_vpool_config.num_voices = MAX_VOICE;
	standard_vpool_config.player_config.max_sampling_rate = MAX_SAMPLING_RATE;
	standard_vpool_config.player_config.streaming_flag = CRI_TRUE;
	m_AppObj->standard_voice_pool = criAtomExVoicePool_AllocateStandardVoicePool(&standard_vpool_config, NULL, 0);

	/* HCA-MX再生用：ボイスプールの作成 */
	CriAtomExHcaMxVoicePoolConfig hcamx_vpool_config;
	criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool(&hcamx_vpool_config);
	hcamx_vpool_config.num_voices = MAX_VOICE;
	hcamx_vpool_config.player_config.max_sampling_rate = MAX_SAMPLING_RATE;
	hcamx_vpool_config.player_config.streaming_flag = CRI_TRUE;
	m_AppObj->hcamx_voice_pool = criAtomExVoicePool_AllocateHcaMxVoicePool(&hcamx_vpool_config, NULL, 0);

	/* ACBファイルを読み込み、ACBハンドルを作成 */
	m_AppObj->acb_hn = criAtomExAcb_LoadAcbFile(NULL, ACB_FILE, NULL, AWB_FILE, NULL, 0);

	/* プレーヤの作成 */
	m_AppObj->player = criAtomExPlayer_Create(NULL, NULL, 0);
}

void ADXSound::Update()
{
	/* サーバ処理の実行 */
	criAtomEx_ExecuteMain();

#if defined(USE_INGAME_PREVIEW)
	/* バス解析情報の取得 */
	CriAtomExAsrBusAnalyzerInfo analyze_info;
	CriSint32 bus_no;
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_GetBusAnalyzerInfo(bus_no, &analyze_info);
	}
#endif
}

void ADXSound::Uninit()
{
	/* DSPのデタッチ */
	criAtomEx_DetachDspBusSetting();

	/* プレーヤハンドルの破棄 */
	criAtomExPlayer_Destroy(m_AppObj->player);

	/* ボイスプールの破棄 */
	criAtomExVoicePool_Free(m_AppObj->hcamx_voice_pool);
	criAtomExVoicePool_Free(m_AppObj->standard_voice_pool);

	/* ACBハンドルの破棄 */
	criAtomExAcb_Release(m_AppObj->acb_hn);

	/* ACFの登録解除 */
	criAtomEx_UnregisterAcf();

#if defined(USE_INGAME_PREVIEW)
	/* インゲームプレビュー関連機能の終了処理 */
	CriSint32 bus_no;
	for (bus_no = 0; bus_no < 8; bus_no++) {
		criAtomExAsr_DetachBusAnalyzer(bus_no);
	}
	criAtomExMonitor_Finalize();
#endif

	/* D-BASの破棄 */
	criAtomDbas_Destroy(m_AppObj->dbas_id);

	/* ライブラリの終了 */
	criAtomEx_Finalize_WASAPI();
}

unsigned ADXSound::Play(unsigned audioId)
{
	CriAtomExCueId start_cue_id = g_cue_list[audioId].id;

	/* キューIDの指定 */
	criAtomExPlayer_SetCueId(m_AppObj->player, m_AppObj->acb_hn, start_cue_id);

	static CriUint32 count = CriAtomExPerformanceInfo().server_process_count;

	/* 再生の開始 */
	CriAtomExPlaybackId playback_id = criAtomExPlayer_Start(m_AppObj->player);

	return playback_id;
}

void ADXSound::Stop(unsigned playBackId)
{
	/* プレーヤの停止 */
	criAtomExPlayback_Stop(playBackId);
}

void ADXSound::AllStop()
{
	/* 特定の再生音のみ停止 */
	criAtomExPlayer_Stop(m_AppObj->player);
}

void ErrorCallBack(const CriChar8 * errid, CriUint32 p1, CriUint32 p2, CriUint32 * parray)
{
	const CriChar8 *errmsg;

	/* エラー文字列の表示 */
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
