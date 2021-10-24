/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2013-2018 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for WASAPI
 * File     : cri_le_atom_wasapi.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_wasapi.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef CRI_INCL_CRI_ATOM_WASAPI_H
#define CRI_INCL_CRI_ATOM_WASAPI_H

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include <Windows.h>
#include <sdkddkver.h>
#include <Audioclient.h>
#include <AudioSessionTypes.h>
#include <mmdeviceapi.h>
#include <cri_le_xpt.h>
#include <cri_le_atom.h>
#include <cri_le_atom_ex.h>
#include <cri_le_atom_asr.h>

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/

/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_WASAPI
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtom_Initialize_WASAPI �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomConfig_WASAPI �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \attention
 * �{�}�N���͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�}�N���̑���� 
 * ::criAtomEx_SetDefaultConfig_WASAPI �}�N���������p���������B
 * \sa CriAtomConfig_WASAPI
 */
#define criAtom_SetDefaultConfig_WASAPI(p_config)			\
{															\
	criAtom_SetDefaultConfig(&(p_config)->atom);			\
	criAtomAsr_SetDefaultConfig(&(p_config)->asr);			\
	criAtomHcaMx_SetDefaultConfig(&(p_config)->hca_mx);		\
}

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_WASAPI
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomEx_Initialize_WASAPI �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExConfig_WASAPI �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExConfig_WASAPI
 */
#define criAtomEx_SetDefaultConfig_WASAPI(p_config)			\
{															\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
	criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
}

/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief Atom���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMLIB_WASAPI
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtom_Initialize_WASAPI �֐��̈����Ɏw�肵�܂��B<br>
 * \attention
 * �{�\���͉̂��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�\���̂̑���� 
 * ::CriAtomExConfig_WASAPI �\���̂������p���������B
 * \sa criAtom_Initialize_WASAPI, criAtom_SetDefaultConfig_WASAPI
 */
typedef struct CriAtomConfigTag_WASAPI {
	CriAtomConfig			atom;		/*JP< Atom�������p�R���t�B�O�\����		*/
	CriAtomAsrConfig		asr;		/*JP< ASR�������p�R���t�B�O			*/
	CriAtomHcaMxConfig		hca_mx;		/*JP< HCA-MX�������p�R���t�B�O�\����	*/
} CriAtomConfig_WASAPI;

/*JP
 * \brief �I�[�f�B�I�G���h�|�C���g�񋓃R�[���o�b�N
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	object				���[�U�w��I�u�W�F�N�g
 * \param[in]	device				IMMDevice�C���X�^���X
 * \par ����:
 * �I�[�f�B�I�G���h�|�C���g�̒ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtom_EnumAudioEndpoints_WASAPI �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * IMMDevice�C���X�^���X���R�[���o�b�N�o�R�Ŏ󂯎�邱�Ƃ��\�ł��B<br>
 * \attention
 * IMMDevice�C���X�^���X���R�[���o�b�N�֐����Ŕj�����Ă͂����܂���B<br>
 * \sa criAtom_EnumAudioEndpoints_WASAPI
 */
typedef void (CRIAPI *CriAtomAudioEndpointCbFunc_WASAPI)(void *object, IMMDevice *device);

/*JP
 * \brief �f�o�C�X�X�V�ʒm�R�[���o�b�N
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	object				���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�o�C�X�̍X�V�ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtom_SetDeviceUpdateCallback_WASAPI �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * �f�o�C�X���X�V���ꂽ�ۂɃR�[���o�b�N�o�R�Œʒm���󂯎�邱�Ƃ��\�ł��B<br>
 * \sa criAtom_SetDeviceUpdateCallback_WASAPI
 */
typedef void (CRIAPI *CriAtomDeviceUpdateCbFunc_WASAPI)(void *object);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief Atom���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMLIB_WASAPI
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomEx_Initialize_WASAPI �֐��̈����Ɏw�肵�܂��B<br>
 * \sa criAtomEx_Initialize_WASAPI, criAtomEx_SetDefaultConfig_WASAPI
 */
typedef struct CriAtomExConfigTag_WASAPI {
	CriAtomExConfig			atom_ex;	/*JP< AtomEx�������p�R���t�B�O�\����	*/
	CriAtomExAsrConfig		asr;		/*JP< ASR�������p�R���t�B�O			*/
	CriAtomExHcaMxConfig	hca_mx;		/*JP< HCA-MX�������p�R���t�B�O�\����	*/
} CriAtomExConfig_WASAPI;

/***************************************************************************
 *      �ϐ��錾
 *      Prototype Variables
 ***************************************************************************/

/***************************************************************************
 *      �֐��錾
 *      Prototype Functions
 ***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomConfig_WASAPI �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_CalculateWorkSize_WASAPI �֐��������p���������B
 * \sa CriAtomConfig_WASAPI, criAtom_Initialize_WASAPI
 */
CriSint32 CRIAPI criAtom_CalculateWorkSize_WASAPI(const CriAtomConfig_WASAPI *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtom_Finalize_WASAPI �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�������p�R���t�B�O�\���̂̓��e�ɉ�����
 * �ω����܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�ɂ́A ::criAtom_CalculateWorkSize_WASAPI 
 * �֐����g�p���Ă��������B<br>
 * \par ���l:
 * ::criAtom_SetUserAllocator �}�N�����g�p���ăA���P�[�^��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtom_Initialize
 * 	- ::criAtomAsr_Initialize
 * 	- ::criAtomHcaMx_Initialize
 * 	.
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtom_Finalize_WASAPI �֐������s���Ă��������B<br>
 * �܂��A ::criAtom_Finalize_WASAPI �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_Initialize_WASAPI �֐��������p���������B
 * \sa CriAtomConfig_WASAPI, criAtom_Finalize_WASAPI,
 * criAtom_SetUserAllocator, criAtom_CalculateWorkSize_WASAPI
 */
void CRIAPI criAtom_Initialize_WASAPI(
	const CriAtomConfig_WASAPI *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMLIB_WASAPI
 * \par ����:
 * ���C�u�������I�����܂��B<br>
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtom_Finalize
 * 	- ::criAtomAsr_Finalize
 * 	- ::criAtomHcaMx_Finalize
 * 	.
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * ::criAtom_Initialize_WASAPI �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * <br>
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_Finalize_WASAPI �֐��������p���������B
 * \sa criAtom_Initialize_WASAPI
 */
void CRIAPI criAtom_Finalize_WASAPI(void);

/*JP
 * \brief �~�L�T�t�H�[�}�b�g�̎擾
 * \ingroup ATOMLIB_WASAPI
 * \param[out]	format		�~�L�T�̃t�H�[�}�b�g
 * \return		CriBool		�~�L�T�̃t�H�[�}�b�g���擾�ł������ǂ����i CRI_TRUE = �����ACRI_FALSE = ���s�j
 * \par ����:
 * ���L���[�h���Ɏg�p�����~�L�T�̃t�H�[�}�b�g���擾���܂��B<br>
 * \par ���l:
 * �{�֐��� IAudioClient::GetMixFormat �֐��̃��b�p�[�ł��B<br>
 * �{�֐������s����ƁA�֐����� AudioClient ���쐬���AGetMixFormat �֐������s���܂��B<br>
 * \attention
 * �{�֐��̓��C�u�����������O�ɂ̂ݎg�p�\�ł��B<br>
 * <br>
 * ���L���[�h�Ɣr�����[�h�Ƃł́A�g�p�ł���t�H�[�}�b�g���قȂ�܂��B<br>
 * �{�֐��Ŏ擾���� WAVEFORMATEXTENSIBLE �\���̂� IEEE float �`����PCM�f�[�^�t�H�[�}�b�g��Ԃ��܂����A
 * ���̃t�H�[�}�b�g�͔r�����[�h�ł͂قƂ�ǂ̏ꍇ�g�p�ł��܂���B<br>
 */
CriBool CRIAPI criAtom_GetAudioClientMixFormat_WASAPI(WAVEFORMATEXTENSIBLE *format);

/*JP
 * \brief �w�肵���t�H�[�}�b�g�����p�\���ǂ����`�F�b�N
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	format		�g�p����t�H�[�}�b�g
 * \return		CriBool		�w�肳�ꂽ�t�H�[�}�b�g�����p�\���ǂ����i CRI_TRUE = ���p�\�ACRI_FALSE = ���p�s�\�j
 * \par ����:
 * �����Ŏw�肵���t�H�[�}�b�g���A�r�����[�h�ŗ��p�\���ǂ������`�F�b�N���܂��B<br>
 * \par ���l:
 * �{�֐��� IAudioClient::IsFormatSupported �֐��̃��b�p�[�ł��B<br>
 * �{�֐������s����ƁA�֐����� AudioClient ���쐬���AIsFormatSupported �֐������s���܂��B<br>
 * \attention
 * �{�֐��̓��C�u�����������O�ɂ̂ݎg�p�\�ł��B<br>
 * <br>
 * �ꕔ�̃f�o�C�X�^�p�����[�^�ɂ��āA�{�֐�����������ɂ�������炸�A
 * WASAPI �̏������Ɏ��s����P�[�X���m�F����Ă��܂��B<br>
 * �{�֐��� CRI_TRUE ��Ԃ����ɂ�������炸�A���C�u�����̏������Ɏ��s����ꍇ�ɂ́A
 * �w�肷��t�H�[�}�b�g��ύX���邩�A�܂��͋��L���[�h�����g�p���������B<br>
 */
CriBool CRIAPI criAtom_GetAudioClientIsFormatSupported_WASAPI(const WAVEFORMATEX *format);

/*JP
 * \brief ���L�����̎w��
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	mode	�g�p���郂�[�h
 * \par ����:
 * WASAPI�����L���[�h�Ŏg�p���邩�A�r�����[�h�Ŏg�p���邩���w�肵�܂��B<br>
 * <br>
 * �{�֐������s���Ȃ��ꍇ��A AUDCLNT_SHAREMODE_SHARED ���w�肵�Ď��s�����ꍇ�A
 * Atom���C�u������ WASAPI �����L���[�h�ŏ��������܂��B<br>
 * AUDCLNT_SHAREMODE_EXCLUSIVE ���w�肵�Ė{�֐������s�����ꍇ�A
 * Atom���C�u������ WASAPI ��r�����[�h�ŏ��������܂��B<br>
 * \attention
 * �{�֐��̓��C�u�����̏�����������Ɏ��s���Ă����K�v������܂��B<br>
 * <br>
 * �r�����[�h���g�p����ꍇ�A�{�֐��ł̃��[�h�w��ɉ����A
 * ::criAtom_SetAudioClientFormat_WASAPI �֐��ɂ��t�H�[�}�b�g�̎w�肪�K�v�ł��B<br>
 * \sa criAtom_SetAudioClientFormat_WASAPI
 */
void CRIAPI criAtom_SetAudioClientShareMode_WASAPI(AUDCLNT_SHAREMODE mode);

/*JP
 * \brief �o�̓t�H�[�}�b�g�̎w��
 * \ingroup ATOMLIB_WASAPI
 * \par ����:
 * \param[in]	format		�g�p����t�H�[�}�b�g
 * \par ����:
 * �r�����[�h�Ŏg�p����t�H�[�}�b�g���w�肵�܂��B<br>
 * \par ���l:
 * �{�֐��Ɏw�肵���t�H�[�}�b�g���A IAudioClient::Initialize �֐��ɓn����܂��B<br>
 * \attention
 * �{�֐��̓��C�u�����̏�����������Ɏ��s���Ă����K�v������܂��B<br>
 * <br>
 * �r�����[�h���g�p����ꍇ�A�{�֐��ł̃��[�h�w��ɉ����A
 * ::criAtom_SetAudioClientShareMode_WASAPI �֐��ɂ�郂�[�h�w�肪�K�v�ł��B<br>
 * \sa criAtom_SetAudioClientShareMode_WASAPI
 */
void CRIAPI criAtom_SetAudioClientFormat_WASAPI(const WAVEFORMATEX *format);

/*JP
 * \brief �o�b�t�@�����O���Ԃ̎w��
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	ref_time	�o�b�t�@�����O����
 * \par ����:
 * WASAPI ���������Ɏw�肷��o�b�t�@�����O���Ԃ��w�肵�܂��B<br>
 * Atom���C�u�����́A�{�֐��Ŏw�肳�ꂽ���ԕ��̃f�[�^��ێ��\�ȃT�C�Y�̃T�E���h�o�b�t�@���m�ۂ��܂��B<br>
 * \par ���l:
 * �{�֐��Ɏw�肵���l�� IAudioClient::Initialize �֐��ɓn����܂��B<br>
 * <br>
 * ref_time��0���w�肵���ꍇ��A�{�֐����g�p���Ȃ��ꍇ�A
 * Atom���C�u�����͏��������Ɏw�肳���T�[�o�������g���̒l����A
 * �K�؂ȃo�b�t�@�����O���Ԃ��v�Z���܂��B<br>
 * <br>
 * PC���ł̓n�[�h�E�F�A���\�ɂ΂�������邽�߁A
 * ���[�X�g���\�̃n�[�h�E�F�A�ɍ��킹�ăf�t�H���g�̃o�b�t�@�����O�ʂ����߂ɐݒ肳��Ă��܂��B<br>
 * �i�f�t�H���g��Ԃł�4V���̃o�b�t�@�������Ă��܂��B�j
 * \attention
 * �{�֐��̓��C�u�����̏�����������Ɏ��s���Ă����K�v������܂��B<br>
 * <br>
 * �o�b�t�@�����O���Ԃ���������������ƁA���r�؂ꓙ�̖�肪�������܂��B<br>
 * <br>
 * PC���ł̓n�[�h�E�F�A�Ɉˑ����ĕK�v�ȃo�b�t�@�����O�ʂ��قȂ邽�߁A
 * �{�֐����g�p�����ꍇ�A�e�X�g���ł��܂����삵�Ă��Ă��A
 * ���[�U�̊��ɂ���Ă͉��r�؂ꂪ��������\��������܂��B<br>
 * ���̂��߁A�o�b�t�@�����O�ʂ�ύX����ꍇ�ɂ́A
 * ���[�U���ݒ�l��ύX�ł���d�g�݁i�I�v�V������ʓ��j��񋟂��邱�Ƃ����������������B
 */
void CRIAPI criAtom_SetAudioClientBufferDuration_WASAPI(REFERENCE_TIME ref_time);

/*JP
 * \brief AudioClient�̎擾
 * \ingroup ATOMLIB_WASAPI
 * \return IAudioClient	AudioClient
 * \par ����:
 * Atom���C�u�������ō쐬���ꂽAudioClient���擾���܂��B
 * \par ���l:
 * �T�E���h�f�o�C�X�����ڂ���Ă��Ȃ�PC�Ŗ{�֐������s�����ꍇ�A
 * �{�֐���NULL��Ԃ��܂��B
 * \par ����:
 * �{�֐������s����O�ɁA���C�u����������������K�v������܂��B
 */
IAudioClient * CRIAPI criAtom_GetAudioClient_WASAPI(void);

/*JP
 * \brief �f�o�C�X�����������ꂽ���ǂ����̃`�F�b�N
 * \ingroup ATOMLIB_WASAPI
 * \return	CriBool	�f�o�C�X�����������ꂽ���ǂ����iCRI_TRUE = ���������ꂽ�ACRI_FALSE = ����ɓ��쒆�j
 * \par ����:
 * �T�E���h�f�o�C�X�����������ꂽ���ǂ�����Ԃ��܂��B
 * \par ���l:
 * �{�֐���CRI_TRUE��Ԃ��̂́A�A�v���P�[�V�������s���ɃT�E���h�f�o�C�X�𖳌��������ꍇ�݂̂ł��B<br>
 * ���X�T�E���h�f�o�C�X�����ڂ���Ă��Ȃ�PC�Ŗ{�֐������s�����ꍇ�A�{�֐���CRI_FALSE��Ԃ��܂��B<br>
 * �i�T�E���h�f�o�C�X�̗L���͕ʓr ::criAtom_GetAudioClient_WASAPI �֐��Ń`�F�b�N����K�v������܂��B�j
 * \sa criAtom_GetAudioClient_WASAPI
 */
CriBool CRIAPI criAtom_IsDeviceInvalidated_WASAPI(void);

/*JP
 * \brief �T�E���h�f�o�C�X�̎w��
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	type		�T�E���h�����_���^�C�v
 * \param[in]	device_id	�f�o�C�XID
 * \par ����:
 * �T�E���h�����_���^�C�v�ƃT�E���h�f�o�C�X�̕R�Â����s���܂��B<br>
 * <br>
 * �{�֐��ŃT�E���h�����_���ɑ΂��ăf�o�C�XID��ݒ肷��ƁA
 * ���Y�T�E���h�����_�����w�肵�ďo�͂��������́A
 * �S�Ďw�肵��ID�ɍ��v����T�E���h�f�o�C�X����o�͂���܂��B
 * <br>
 * type �ɂ́A�ȉ��̒l���w��\�ł��B<br>
 * 	- CRIATOM_SOUND_RENDERER_HW1�iCRIATOM_SOUND_RENDERER_NATIVE�Ɠ����l�j
 * 	- CRIATOM_SOUND_RENDERER_HW2
 * 	- CRIATOM_SOUND_RENDERER_HW3
 * 	- CRIATOM_SOUND_RENDERER_HW4
 * 	.
 * ��2�����idevice_id�j��NULL�܂��͒���0�̕�������w�肵���ꍇ�A
 * ���Y�T�E���h�����_���ƃf�o�C�XID�̕R�Â�����������܂��B<br>
 * �i����̃f�o�C�X���特�����o�͂���悤�A���삪�ύX����܂��B�j
 * \par ���l:
 * �T�E���h�f�o�C�X��ID�� IMMDevice::GetId �Ŏ擾����K�v������܂��B<br>
 * �w�肳�ꂽID�Ɉ�v����T�E���h�f�o�C�X��������Ȃ��ꍇ�A
 * ���Y�f�o�C�X���w�肵�čĐ����ꂽ�����́A����̃f�o�C�X����o�͂���܂��B<br>
 */
void CRIAPI criAtom_SetDeviceId_WASAPI(CriAtomSoundRendererType type, LPCWSTR device_id);

/*JP
 * \brief �I�[�f�B�I�G���h�|�C���g�̗�
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	callback	�I�[�f�B�I�G���h�|�C���g�R�[���o�b�N�֐�
 * \param[in]	object		���[�U�w��I�u�W�F�N�g
 * \return		CriSint32	�񋓂��ꂽACB�n���h���̐�
 * \par ����:
 * �I�[�f�B�I�G���h�|�C���g��񋓂��܂��B<br>
 * <br>
 * �{�֐������s����ƁA�� 1 �����i callback �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐����I�[�f�B�I�G���h�|�C���g���������Ăяo����܂��B<br>
 * �R�[���o�b�N�֐��ɂ́AIMMDevice�C���X�^���X�������Ƃ��ēn����܂��B<br>
 * \par ���l:
 * �� 2 �����i object �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomAudioEndpointCbFunc_WASAPI �̐��������Q�Ƃ��������B<br>
 * <br>
 * �߂�l�͗񋓂��ꂽ�I�[�f�B�I�G���h�|�C���g�̐��i�o�^�����R�[���o�b�N�֐����Ăяo���ꂽ�񐔁j�ł��B<br>
 * �I�[�f�B�I�G���h�|�C���g�����݂��Ȃ��ꍇ�A�{�֐��� 0 ��Ԃ��܂��B<br>
 * �G���[�����������ۂɂ� -1 ��Ԃ��܂��B<br>
 * \attention
 * IMMDevice�C���X�^���X���R�[���o�b�N�֐����Ŕj�����Ă͂����܂���B<br>
 * \sa CriAtomAudioEndpointCbFunc_WASAPI
 */
CriSint32 CRIAPI criAtom_EnumAudioEndpoints_WASAPI(CriAtomAudioEndpointCbFunc_WASAPI callback, void *object);

/*JP
 * \brief �f�o�C�X�X�V�ʒm�̓o�^
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	callback	�f�o�C�X�X�V�ʒm�R�[���o�b�N�֐�
 * \param[in]	object		���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�o�C�X�̍X�V�ʒm���󂯎�邽�߂̃R�[���o�b�N��ݒ肵�܂��B<br>
 * <br>
 * �{�֐������s����ƁA�f�o�C�X���X�V���ꂽ�ہA�� 1 �����i callback �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐����Ăяo����܂��B<br>
 * \par ���l:
 * �� 2 �����i object �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * \sa CriAtomAudioEndpointCbFunc_WASAPI
 */
void CRIAPI criAtom_SetDeviceUpdateCallback_WASAPI(CriAtomDeviceUpdateCbFunc_WASAPI callback, void *object);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomExConfig_WASAPI �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ::CriAtomExConfig_WASAPI �\���̂�acf_info�����o�ɒl��ݒ肵�Ă���ꍇ�A�{�֐��͎��s��-1��Ԃ��܂��B<br>
 * ��������������ACF�f�[�^�̓o�^���s���ꍇ�́A�{�֐��l���g�p�����������m�ۂł͂Ȃ�ADX2�V�X�e���ɂ��
 * �������A���P�[�^���g�p�����������m�ۏ������K�v�ɂȂ�܂��B
 * \sa CriAtomExConfig_WASAPI, criAtomEx_Initialize_WASAPI
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_WASAPI(const CriAtomExConfig_WASAPI *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMLIB_WASAPI
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtomEx_Finalize_WASAPI �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�������p�R���t�B�O�\���̂̓��e�ɉ�����
 * �ω����܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�ɂ́A ::criAtomEx_CalculateWorkSize_WASAPI 
 * �֐����g�p���Ă��������B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtomEx_Initialize
 * 	- ::criAtomExAsr_Initialize
 * 	- ::criAtomExHcaMx_Initialize
 * 	.
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomEx_Finalize_WASAPI �֐������s���Ă��������B<br>
 * �܂��A ::criAtomEx_Finalize_WASAPI �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa CriAtomExConfig_WASAPI, criAtomEx_Finalize_WASAPI,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_WASAPI
 */
void CRIAPI criAtomEx_Initialize_WASAPI(
	const CriAtomExConfig_WASAPI *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMLIB_WASAPI
 * \par ����:
 * ���C�u�������I�����܂��B<br>
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtomEx_Finalize
 * 	- ::criAtomExAsr_Finalize
 * 	- ::criAtomExHcaMx_Finalize
 * 	.
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * ::criAtomEx_Initialize_WASAPI �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomEx_Initialize_WASAPI
 */
void CRIAPI criAtomEx_Finalize_WASAPI(void);

#ifdef __cplusplus
}
#endif

/***************************************************************************
 *      ���o�[�W�����Ƃ̌݊��p
 *      For compatibility with old version
 ***************************************************************************/

#endif	/* CRI_INCL_CRI_ATOM_WASAPI_H */

/* --- end of file --- */
