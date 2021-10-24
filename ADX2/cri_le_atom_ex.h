/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2016 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : AtomEx.
 * File     : cri_atom_ex.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_atom_ex.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef CRI_INCL_CRI_ATOM_EX_H
#define CRI_INCL_CRI_ATOM_EX_H

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include <cri_le_xpt.h>
#include <cri_le_atom.h>
#include <cri_le_file_system.h>

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/
/* �o�[�W������� */
/* Version Number */
#define CRIATOMEX_VER_NAME		"CRI AtomEx"
#define CRIATOMEX_VER_NUM		"2.21.11"
#define CRIATOMEX_VER_MAJOR		(2)
#define CRIATOMEX_VER_MINOR		(21)
#define CRIATOMEX_VER_PATCH		(11)
#define CRIATOMEX_VER_RELEASE	(0)
#define CRIATOMEX_VER_REVISION	(0)
#define CRIATOMEX_VER_OPTION

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief �o�[�`�����{�C�X���̐ݒ�\���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �o�[�`�����{�C�X�̐ݒ�\����l�ł��B
 * CriAtomExConfig::max_virtual_voices �̒l�́A���̒l�ȉ��ɐݒ肷��K�v������܂��B
 * \sa CriAtomExConfig
 */
#define CRIATOMEX_MAX_VIRTUAL_VOICES	(32767)

/*==========================================================================
 *      CRI AtomEx ACF API
 *=========================================================================*/
/*JP
 * \brief AISAC�R���g���[��ID�̖����l
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * AISAC�R���g���[��ID�̖����l�ł��B<br>
 * \sa CriAtomExAisacControlId, criAtomExPlayer_SetAisacControlById, criAtomExAcf_GetAisacControlIdByName, criAtomExAcf_GetAisacControlNameById
 */
#define CRIATOMEX_INVALID_AISAC_CONTROL_ID	(0xffff)

/*JP
 * \brief �ő�DSP�o�X��
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�ݒ�Őݒ�\�ȍő�o�X���ł��B<br>
 * \sa CriAtomExAcfDspSettingInfo, CriAtomExAcfDspBusInfo
 */
#define CRIATOMEXACF_MAX_BUSES			(64)

/*JP
 * \brief �ő�DSP FX��
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�ݒ�Őݒ�\�ȍő�DSP FX���ł��B<br>
 * \sa CriAtomExAcfDspBusInfo
 */
#define CRIATOMEXACF_MAX_FXES			(8)

/*JP
 * \brief �L���[���~�b�g�����l
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * �L���[���~�b�g���̖����l�ł��B<br>
 * \sa CriAtomExCategoryInfo
 */
#define CRIATOMEXACF_INVALID_CUE_LIMITS		(0xffffffff)

/*JP
 * \brief �e�햼�O������̍ő啶����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * �L���[����O���[�o��AISAC�����A�e�햼�O������̍ő啶�����ł��B<br>
 * \par ���l:
 * �c�[�����ł̓��͐������u�o�C�g���v�ł͂Ȃ��u�������v�ōs���Ă��āA
 * ���S�p������Shift_JIS�Ƃ��Ĉ����Ă��邽�߁A
 * �S�p�������g�p�����ꍇ�̃o�C�g���͍ő�128�o�C�g�ƂȂ�܂��B
 */
#define CRIATOMEXACF_MAX_NAME_STRING_COUNT	(64)

/*==========================================================================
 *      CRI AtomEx Voice Pool API
 *=========================================================================*/
/*JP
 * \brief �f�t�H���g�{�C�X��
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �{�C�X�v�[��������̃{�C�X���̃f�t�H���g�l�ł��B<br>
 * �{�C�X�v�[���쐬���Ƀf�t�H���g�l�ݒ���g�p����ƁA
 * ::CRIATOMEX_DEFAULT_VOICES_PER_POOL �����̃{�C�X���m�ۂ���܂��B<br>
 * \sa criAtomExVoicePool_SetDefaultConfigForStandardVoicePool
 */
#define CRIATOMEX_DEFAULT_VOICES_PER_POOL	(8)

/*==========================================================================
 *      CRI AtomEx Player API
 *=========================================================================*/
/*JP
 * \brief �O���[�v�����Ȃ�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * �{�C�X���~�b�g�O���[�v�ɂ�鐧�����������邽�߂̒萔�ł��B<br>
 * ::criAtomExPlayer_SetGroupNumber �֐��ɑ΂��Ă��̒l���w�肷��ƁA
 * �w�肳�ꂽ�v���[���[�̓{�C�X���~�b�g�O���[�v�ɂ�鐧�����󂯂Ȃ��Ȃ�܂��B<br>
 * �i�󂫃{�C�X�����邩�A�܂��͎��g����v���C�I���e�B�̃{�C�X������΁A
 * �{�C�X���~�b�g�O���[�v�Ɋ֌W�Ȃ��{�C�X���擾���܂��B�j
 * \sa criAtomExPlayer_SetGroupNumber
 */
#define CRIATOMEXPLAYER_NO_GROUP_LIMITATION	(-1)

/*JP
 * \brief ���[�v�񐔐���p
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 */
#define CRIATOMEXPLAYER_NO_LOOP_LIMITATION	(CRIATOMPLAYER_NO_LOOP_LIMITATION)	/*JP<���[�v�񐔐����Ȃ�	*/
#define CRIATOMEXPLAYER_IGNORE_LOOP			(CRIATOMPLAYER_IGNORE_LOOP)			/*JP<���[�v���𖳎�	*/
#define CRIATOMEXPLAYER_FORCE_LOOP			(CRIATOMPLAYER_FORCE_LOOP)			/*JP<�������[�v�Đ�		*/

/*JP
 * \brief �v���[���[�Ɏw��\�ȍő�ASR���b�N��
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * 1�̃v���[���[�ɑ΂��Ďw��\��ASR���b�N�̍ő吔�ł��B
 * \sa criAtomExPlayer_SetAsrRackIdArray
 */
#define CRIATOMEXPLAYER_MAX_ASR_RACKS		(8)

/*==========================================================================
 *      CRI AtomEx Playback API
 *=========================================================================*/
/*JP
 * \brief �����ȍĐ�ID
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ŉ����̍Đ����J�n�����ہA
 * �{�C�X���~�b�g�R���g���[�����ɂ��{�C�X���m�ۂł��Ȃ������ꍇ�ɕԂ����A
 * �����ȍĐ�ID�ł��B<br>
 * \par ���l:
 * �Đ� ID ���w�肷�� API �ɑ΂��Ė{ ID ���Z�b�g�����ꍇ�ł��A
 * �G���[�R�[���o�b�N�͔������܂���B<br>
 * �i�������ꂸ�Ɋ֐����烊�^�[�����܂��B�j<br>
 * ���̂��߁A ::criAtomExPlayer_Start �֐��̌��ʂɂ�����炸�A
 * �Đ� ID ���g�p�����������펞�s���Ă��A���ɖ�肠��܂���B<br>
 * \sa CriAtomExPlaybackId, criAtomExPlayer_Start
 */
#define CRIATOMEX_INVALID_PLAYBACK_ID	(0xFFFFFFFF)

/*JP
 * \brief �����ȃu���b�N�C���f�b�N�X
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * ::criAtomExPlayback_GetCurrentBlockIndex �֐��ōĐ����̉����̃J�����g�u���b�N
 * �C���f�b�N�X���擾�����ہA�Đ����̉������u���b�N�V�[�P���X�ł͂Ȃ��ꍇ��
 * �Ԃ���閳���ȃC���f�b�N�X�ł��B<br>
 * \sa criAtomExPlayback_GetCurrentBlockIndex
 */
#define CRIATOMEX_INVALID_BLOCK_INDEX	(0xFFFFFFFF)

/*==========================================================================
 *      CRI AtomEx Fader API
 *=========================================================================*/
/*JP
 * \brief �t�F�[�h�A�E�g�����̖������w��l
 * \ingroup ATOMEXLIB_FADER
 * \par ����:
 * �t�F�[�_�[�̃t�F�[�h�A�E�g�����𖳌������邽�߂̒l�ł��B<br>
 * ::criAtomExPlayer_SetFadeOutTime �֐��̑�2�����ɖ{�p�����[�^�[���Z�b�g���邱�ƂŁA
 * �t�F�[�h�A�E�g�����𖳌������邱�Ƃ��\�ł��B<br>
 * \sa criAtomExPlayer_SetFadeOutTime
 */
#define CRIATOMEX_IGNORE_FADE_OUT		(-1)

/*==========================================================================
 *      CRI AtomEx D-BAS API
 *=========================================================================*/
/*JP
 * \brief AtomEx D-BAS ID
 * \ingroup ATOMEXLIB_DBAS
 * \par ����:
 * ::criAtomExDbas_Create �֐��Ɏ��s�����ۂɕԂ�l�ł��B <br>
 * \sa criAtomExDbas_Create, criAtomExDbas_Destroy
 */
#define CRIATOMEXDBAS_ILLEGAL_ID		(CRIATOMDBAS_ILLEGAL_ID)

/* ========================================================================*/
/*       CRI AtomEx Streaming Cache API                                    */
/* ========================================================================*/
/*JP
 * \brief �s���ȃX�g���[�~���O�L���b�V��ID�l
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \par ����:
 * ::criAtomExStreamingCache_Create �֐��Ɏ��s�����ۂɕԂ�l�ł��B <br>
 * \sa criAtomExStreamingCache_Create, criAtomExStreamingCache_Destroy
 */
#define CRIATOMEX_STREAMING_CACHE_ILLEGAL_ID	(CRIATOM_STREAMING_CACHE_ILLEGAL_ID)

/*==========================================================================
 *      CRI AtomEx 3D API
 *=========================================================================*/
/*JP
 * \brief 3D�����̃����_�����ɂ�����e��Z�o���@�Ɋւ���p�����[�^�[���̍ő�l
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * ::CriAtomEx3dSourceRandomPositionConfig::calculation_parameters �z��ɂ�����
 * �ő�v�f���ł��B
 * \sa CriAtomEx3dSourceRandomPositionConfig
 */
#define CRIATOMEX3DSOURCE_MAX_RANDOM_POSITION_CALCULATION_PARAMETERS	(3)

/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���[�U�A���P�[�^�[�̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	p_malloc_func	�������m�ۊ֐�
 * \param[in]	p_free_func		����������֐�
 * \param[in]	p_obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom ���C�u�����Ƀ������A���P�[�^�[�i�������̊m�ہ^����֐��j��o�^���܂��B<br>
 * �{�}�N���ŃA���P�[�^�[��o�^����ƁAAtom���C�u���������[�N�̈��K�v�Ƃ���^�C�~���O�ŁA
 * ���[�U���o�^�����������m�ہ^����������Ăяo����邱�ƂɂȂ�܂��B<br>
 * ���̌��ʁA���[�N�̈��K�v�Ƃ���֐��i ::criAtomExPlayer_Create �֐����j�ɑ΂��A
 * �ʂɃ��[�N�̈���Z�b�g���鏈�����ȗ����邱�Ƃ��\�ɂȂ�܂��B<br>
 * �i���[�N�̈�� NULL �|�C���^�A���[�N�̈�T�C�Y�� 0 �o�C�g���w�肵���ꍇ�ł��A
 * �A���P�[�^�[����̓��I�������m�ۂɂ�胉�C�u���������Ȃ����삷��悤�ɂȂ�܂��B�j<br>
 * \par ����:
 * �������m�ہ^����֐��̃|�C���^�� NULL ���w�肷�邱�ƂŁA
 * �A���P�[�^�[�̓o�^���������邱�Ƃ��\�ł��B<br>
 * �������A������̃������̈悪�c���Ă����Ԃœo�^����������ƁA
 * �G���[�R�[���o�b�N���Ԃ���A�o�^�̉����Ɏ��s���܂��B<br>
 * �i���������o�^�ς݂̃A���P�[�^�[���Ăяo����邱�ƂɂȂ�܂��B�j<br>
 * <br>
 * �{�}�N���͓����I�� ::criAtom_SetUserAllocator �}�N����
 * ::criAtom_SetUserMallocFunction �֐��A ::criAtom_SetUserFreeFunction
 * �֐����Ăяo���܂��B<br>
 * �{�֐��Ƃ����� API �𕹗p���Ȃ��悤�����ӂ��������B<br>
 * �i�{�֐��̌Ăяo���ɂ��A��L API �ɃZ�b�g�������e���㏑������܂��B�j<br>
 * <br>
 * �܂��A�o�^���ꂽ�������A���P�[�^�[�֐��̓}���X���b�h���[�h���ɕ����̃X���b�h����R�[��
 * ����邱�Ƃ�����܂��B�]���āA�������A���P�[�g�������X���b�h�Z�[�t�łȂ��ꍇ�͓Ǝ���
 * �������A���P�[�g������r�����䂷��K�v������܂��B
 */
#define criAtomEx_SetUserAllocator(p_malloc_func, p_free_func, p_obj)	\
	criAtom_SetUserAllocator((p_malloc_func), (p_free_func), (p_obj))

/*JP
 * \brief ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomEx_Initialize �֐��ɐݒ肷��R���t�B�O�\���́i ::CriAtomExConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa
 * CriAtomExConfig
 */
#define criAtomEx_SetDefaultConfig(p_config)	\
{\
	(p_config)->thread_model = CRIATOMEX_THREAD_MODEL_MULTI;\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->parameter_update_interval = 1;\
	(p_config)->enable_atom_sound_disabled_mode = CRI_FALSE;\
	(p_config)->max_virtual_voices = 16;\
	(p_config)->max_parameter_blocks = 1024;\
	(p_config)->max_voice_limit_groups = 16;\
	(p_config)->max_categories = 16;\
	(p_config)->max_aisacs = 8;\
	(p_config)->categories_per_playback = 4;\
	(p_config)->max_sequences = (p_config)->max_virtual_voices;\
	(p_config)->max_tracks = (p_config)->max_virtual_voices * 2;\
	(p_config)->max_track_items = (p_config)->max_virtual_voices * 2;\
	(p_config)->max_aisac_auto_modulations = 0;\
	(p_config)->max_pitch = 2400.0f;\
	(p_config)->max_faders = 4;\
	(p_config)->coordinate_system = CRIATOMEX_COORDINATE_SYSTEM_LEFT_HANDED;\
	(p_config)->enable_auto_matching_in_pan_type_auto = CRI_FALSE;\
	(p_config)->enable_category_override_by_ex_player = CRI_FALSE;\
	(p_config)->sequence_prepare_ratio = 1.5;\
	(p_config)->rng_if = NULL;\
	(p_config)->fs_config = NULL;\
	(p_config)->acf_info = NULL;\
	(p_config)->context = NULL;\
	(p_config)->version = CRI_ATOM_VERSION;\
	(p_config)->version_ex = CRIATOMEX_VERSION;\
	(p_config)->version_string = CRI_ATOM_VER_NUM;\
	(p_config)->version_ex_string = CRIATOMEX_VER_NUM;\
}

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�@�\�̒ǉ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�v���@�\��ǉ����A�p�t�H�[�}���X�v���������J�n���܂��B<br>
 * �{�֐������s��A ::criAtomEx_GetPerformanceInfo �֐������s���邱�ƂŁA
 * �T�[�o�[�����̕��ׂ�A�T�[�o�[�����̎��s�Ԋu���A���C�u�����̃p�t�H�[�}���X����
 * �擾���邱�Ƃ��\�ł��B
 * \sa criAtomEx_GetPerformanceInfo, criAtomEx_DetachPerformanceMonitor
 * \par ��:
 * \code
 * 	// �p�t�H�[�}���X���擾�p�\����
 * 	CriAtomExPerformanceInfo info;
 * 	
 * 	// ���C�u�����̏�����
 * 	criAtomEx_Initialize(�c);
 * 	
 * 	// �p�t�H�[�}���X���j�^�[�@�\�̒ǉ�
 * 	criAtomEx_AttachPerformanceMonitor();
 * 	
 * 	// �p�t�H�[�}���X���j�^�[�̃��Z�b�g
 * 	criAtomEx_ResetPerformanceMonitor();
 * 	
 * 	// �p�t�H�[�}���X�v�����
 * 	�c
 * 	
 * 	// �p�t�H�[�}���X���̎擾
 * 	criAtomEx_GetPerformanceInfo(&info);
 * 	
 * 	// �v�����ʂ̕\��
 * 	printf(
 * 		"Max CPU Load            : %d (us)\n"	\
 * 		"Average CPU Load        : %d (us)\n"	\
 * 		"Max Server Interval     : %d (us)\n"	\
 * 		"Average Server Interval : %d (us)\n",
 * 		info.max_server_time, info.average_server_time,
 * 		info.max_server_interval, info.average_server_interval
 * 	);
 * \endcode
 */
#define criAtomEx_AttachPerformanceMonitor()	criAtom_AttachPerformanceMonitor()

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�@�\�̍폜
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�v���������I�����A�p�t�H�[�}���X�v���@�\���폜���܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 */
#define criAtomEx_DetachPerformanceMonitor()	criAtom_DetachPerformanceMonitor()

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�̃��Z�b�g
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ���݂܂ł̌v�����ʂ�j�����܂��B<br>
 * �p�t�H�[�}���X���j�^�[�́A ::criAtomEx_AttachPerformanceMonitor �֐����s����
 * ����p�t�H�[�}���X���̎擾���J�n���A�v�����ʂ�ݐς��܂��B<br>
 * �ȑO�̌v�����ʂ��ȍ~�̌v�����ʂɊ܂߂����Ȃ��ꍇ�ɂ́A
 * �{�֐������s���A�ݐς��ꂽ�v�����ʂ���U�j������K�v������܂��B
 */
#define criAtomEx_ResetPerformanceMonitor()		criAtom_ResetPerformanceMonitor()

/*JP
 * \brief �p�t�H�[�}���X���̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�����擾���܂��B<br>
 * �{�֐��́A ::criAtomEx_AttachPerformanceMonitor �֐����s�ォ��
 * ::criAtomEx_DetachPerformanceMonitor �֐������s����܂ł̊ԁA���p�\�ł��B<br>
 * \sa criAtomEx_AttachPerformanceMonitor, criAtomEx_DetachPerformanceMonitor
 */
#define criAtomEx_GetPerformanceInfo(p_info)	criAtom_GetPerformanceInfo(p_info)

/*JP
 * \brief �`�����l���}�b�s���O�p�^�[���̎w��
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	nch		�}�b�s���O�p�^�[����ύX����`�����l����
 * \param[in]	type	�}�b�s���O�p�^�[��
 * \par ����:
 * �����f�[�^�̊e�`�����l���Əo�̓X�s�[�J�[�̑Ή��t����ύX���܂��B<br>
 * �Ⴆ�΁A5ch�����f�[�^���Đ������ꍇ�A�f�t�H���g��Ԃł͊e�`�����l���� 
 * L, R, C, Ls, Rs �̏��ŏo�͂���܂��B<br>
 * ����ɑ΂��A::criAtomEx_SetChannelMapping(5, 1); �����s�����ꍇ�A
 * 5ch�����f�[�^�̊e�`�����l���� L, R, LFE, Ls, Rs �̏��ŏo�͂����悤�ɂȂ�܂��B<br>
 * \par ���l:
 * ����A�{�֐���5ch�����f�[�^�̃}�b�s���O�p�^�[���ύX�ɂ����Ή����Ă��܂���B<br>
 */
#define criAtomEx_SetChannelMapping(nch, type)	\
	criAtom_SetChannelMapping((nch), (type))

/*JP
 * \brief ADX�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * ADX�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 */
#define criAtomEx_CalculateAdxBitrate(num_channels, sampling_rate) \
	criAtom_CalculateAdxBitrate(num_channels, sampling_rate)

/*JP
 * \brief HCA�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \param[in]	quality			�f�[�^�̃G���R�[�h�i��
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * HCA�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * quality�ɂ�CRI Atom Craft�܂���CRI Atom Encoder�Őݒ肵���G���R�[�h�i�����w�肵�܂��B
 */
#define criAtomEx_CalculateHcaBitrate(num_channels, sampling_rate, quality) \
	criAtom_CalculateHcaBitrate(num_channels, sampling_rate, quality)

/*JP
 * \brief HCA-MX�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \param[in]	quality			�f�[�^�̃G���R�[�h�i��
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * HCA-MX�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * quality�ɂ�CRI Atom Craft�܂���CRI Atom Encoder�Őݒ肵���G���R�[�h�i�����w�肵�܂��B
 */
#define criAtomEx_CalculateHcaMxBitrate(num_channels, sampling_rate, quality) \
	criAtom_CalculateHcaMxBitrate(num_channels, sampling_rate, quality)

/*JP
 * \brief Wave�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \param[in]	num_bits		�T���v��������̃r�b�g��
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * Wave�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 */
#define criAtomEx_CalculateWaveBitrate(num_channels, sampling_rate, num_bits)	\
	criAtom_CalculateWaveBitrate(num_channels, sampling_rate, num_bits)

/*JP
 * \brief AIFF�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \param[in]	num_bits		�T���v��������̃r�b�g��
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * AIFF�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 */
#define criAtomEx_CalculateAiffBitrate(num_channels, sampling_rate, num_bits)	\
	criAtom_CalculateAiffBitrate(num_channels, sampling_rate, num_bits)

/*==========================================================================
 *      CRI AtomEx HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_HCA_MX
 * \par ����:
 * ::criAtomExHcaMx_Initialize �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExHcaMxConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomExHcaMx_Initialize, CriAtomExHcaMxConfig
 */
#define criAtomExHcaMx_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->num_mixers = 1;\
	(p_config)->max_voices = 16;\
	(p_config)->max_input_channels = CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
}

/*==========================================================================
 *      CRI AtomEx Voice Pool API
 *=========================================================================*/
/*JP
 * \brief �W���{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	�W���{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateStandardVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExStandardVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExStandardVoicePoolConfig, criAtomExVoicePool_AllocateStandardVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForStandardVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForStandardPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief ADX�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	ADX�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateAdxVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExAdxVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExAdxVoicePoolConfig, criAtomExVoicePool_AllocateAdxVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForAdxVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForAdxPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief HCA�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	HCA�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateHcaVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExHcaVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExHcaVoicePoolConfig, criAtomExVoicePool_AllocateHcaVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForHcaVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForHcaPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief HCA-MX�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	HCA-MX�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateHcaMxVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExHcaMxVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExHcaMxVoicePoolConfig, criAtomExVoicePool_AllocateHcaMxVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForHcaMxPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief Wave�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	Wave�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateWaveVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExWaveVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExWaveVoicePoolConfig, criAtomExVoicePool_AllocateWaveVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForWaveVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForWavePlayer(&(p_config)->player_config);\
}

/*JP
 * \brief AIFF�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	AIFF�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateAiffVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExAiffVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExAiffVoicePoolConfig, criAtomExVoicePool_AllocateAiffVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForAiffVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForAiffPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateRawPcmVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExRawPcmVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExRawPcmVoicePoolConfig, criAtomExVoicePool_AllocateRawPcmVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForRawPcmVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForRawPcmPlayer(&(p_config)->player_config);\
}

/*JP
 * \brief �C���X�g�D�������g�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[out]	p_config	RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExVoicePool_AllocateInstrumentVoicePool �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::  CriAtomExInstrumentVoicePoolConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \par ����:
 * �f�t�H���g�l�̂܂܂ł̓v�[���̍쐬�Ɏ��s���܂��B<br>
 * ���[�U���o�^�����C���^�[�t�F�[�X�̃C���X�g�D�������g����ݒ肷��K�v������܂��B
 * \sa  CriAtomExInstrumentVoicePoolConfig, criAtomExVoicePool_AllocateInstrumentVoicePool
 */
#define criAtomExVoicePool_SetDefaultConfigForInstrumentVoicePool(p_config)	\
{\
	(p_config)->identifier = 0;\
	(p_config)->num_voices = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	criAtomPlayer_SetDefaultConfigForInstrumentPlayer(&(p_config)->player_config);\
}
/*==========================================================================
 *      CRI AtomEx Player API
 *=========================================================================*/
/*JP
 * \brief �v���[���[�쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_PLAYER
 * \param[out]	p_config	AtomEx�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExPlayer_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create
 */
#define criAtomExPlayer_SetDefaultConfig(p_config)	\
{\
	(p_config)->voice_allocation_method = CRIATOMEX_ALLOCATE_VOICE_ONCE;\
	(p_config)->max_path_strings = 1;\
	(p_config)->max_path = 0;\
	(p_config)->updates_time = CRI_TRUE;\
	(p_config)->enable_audio_synced_timer = CRI_FALSE;\
	(p_config)->max_aisacs = 8;\
}

/*==========================================================================
 *      CRI AtomEx Fader API
 *=========================================================================*/
/*JP
 * \brief �t�F�[�_�[�A�^�b�`�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_FADER
 * \param[out]	p_config	�t�F�[�_�[�A�^�b�`�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExPlayer_AttachFader �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExFaderConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExFaderConfig, criAtomExPlayer_AttachFader
 */
#define criAtomExFader_SetDefaultConfig(p_config)	\
{\
	(p_config)->reserved = 0;\
}

/*==========================================================================
 *      CRI AtomEx D-BAS API
 *=========================================================================*/
/*JP
 * \brief CriAtomExDbasConfig �ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMEXLIB_DBAS
 * \param[out]	p_config	D-BAS�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExDbas_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExDbasConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExDbasConfig, criAtomExDbas_Create, criAtomExDbas_CalculateWorkSize
 */
#define criAtomExDbas_SetDefaultConfig(p_config)	\
	criAtomDbas_SetDefaultConfig(p_config)

/*JP
 * \brief D-BAS�쐬�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_DBAS
 * \param[in]	config		D-BAS�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	D-BAS�쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * D-BAS�쐬�p�p�����[�^�[�Ɋ�Â��āAD-BAS�̍쐬�ɕK�v���[�N�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExDbas_Create, criAtomEx_Initialize
 */
#define criAtomExDbas_CalculateWorkSize(config)	\
	criAtomDbas_CalculateWorkSize(config)

/*JP
 * \brief D-BAS�̍쐬
 * \ingroup ATOMEXLIB_DBAS
 * \param[in]	config			D-BAS�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work			D-BAS�쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size		D-BAS�쐬�p���[�N�T�C�Y
 * \return		CriAtomExDbasId	D-BAS�Ǘ��pID
 * \par ����:
 * D-BAS�쐬�p�p�����[�^�[�Ɋ�Â��āAD-BAS���쐬���܂��B<br>
 * �쐬�ɐ�������ƁAD-BAS�����C�u�����ɓo�^���A�L���ȊǗ��pID��Ԃ��܂��B<br>
 * D-BAS�̍쐬�Ɏ��s�����ꍇ�A�{�֐��� ::CRIATOMEXDBAS_ILLEGAL_ID ��Ԃ��܂��B<br>
 * �i�G���[�̌����̓G���[�R�[���o�b�N�ɕԂ���܂��B�j<br>
 * <br>
 * �擾����ID��::criAtomExDbas_Destroy �֐��Ŏg�p���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExDbas_CalculateWorkSize, criAtomExDbas_Destroy
 */
#define criAtomExDbas_Create(config, work, work_size)	\
	criAtomDbas_Create((config), (work), (work_size))

/*JP
 * \brief D-BAS�̔j��
 * \ingroup ATOMEXLIB_DBAS
 * \param[in]	atom_dbas_id	D-BAS�Ǘ��pID
 * \par ����:
 * ::criAtomExDbas_Create �֐��Ŏ擾�����Ǘ��pID���w�肵�āAD-BAS��j�����܂��B<br>
 * \sa criAtomExDbas_Create
 */
#define criAtomExDbas_Destroy(atom_dbas_id)	\
	criAtomDbas_Destroy(atom_dbas_id);

/*JP
 * \brief �X�g���[���Đ�����Atom�v���[���[�n���h�����擾
 * \ingroup ATOMEXLIB_DBAS
 * \param[in]	dbas_id			D-BAS�Ǘ��pID
 * \param[out]	players			�v���[���[�n���h���󂯎��p�z��
 * \param[in]	length			�v���[���[�n���h���󂯎��p�z��v�f��
 * \return		CriSint32		�v���[���[��
 * \retval		0�ȏ�			����ɏ���������
 * \retval		-1				�G���[������
 * \par ����:
 * �X�g���[���Đ�����Atom�v���[���[�n���h�����擾���܂��B<br>
 * �v���[���[�n���h���̎擾�ɐ�������ƁA
 * ��3�����iplayers�z��j�Ƀv���[���[�n���h���̃A�h���X���ۑ�����A
 * �v���[���[�n���h�������߂�l�Ƃ��ĕԂ���܂��B<br>
 * \par ���l:
 * ��3�����iplayers�z��j��NULL�A��4�����ilength�j��0���w�肷�邱�ƂŁA
 * �X�g���[���Đ����̃v���[���[�̐�������߂�l�Ƃ��Ď擾�\�ł��B<br>
 * \attention
 * �v���[���[�����擾���Ă���n���h�����擾����ꍇ�A
 * �v���[���[���擾�ƃn���h���擾�̊ԂɃT�[�o�[���������荞�܂Ȃ��悤�A
 * criAtom_Lock �֐��Ŕr��������s���K�v������܂��B<br>
 * �i�T�[�o�[�����̃^�C�~���O�ŁA�v���[���[�����ς��\��������܂��B�j<br>
 * <br>
 * �z��v�f�����X�g���[���Đ����̃v���[���[���ɖ����Ȃ��ꍇ�A
 * �{�֐��̓G���[�l�i-1�j��Ԃ��܂��B<br>
 */
#define criAtomExDbas_GetStreamingPlayerHandles(dbas_id, players, length)	\
	criAtomDbas_GetStreamingPlayerHandles((dbas_id), (players), (length))

/* ========================================================================*/
/*       CRI AtomEx Streaming Cache API                                    */
/* ========================================================================*/
/*JP
 * \brief CriAtomExStreamingCacheConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[out]	p_config	�X�g���[�~���O�L���b�V���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExStreamingCache_CalculateWorkSize �֐��A
 * ::criAtomExStreamingCache_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExStreamingCacheConfig �j�ɑ΂��A�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomExStreamingCache_CalculateWorkSize, criAtomExStreamingCache_Create
 */
#define criAtomExStreamingCache_SetDefaultConfig(p_config)	\
	criAtomStreamingCache_SetDefaultConfig(p_config)

/*JP
 * \brief �X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	p_config	�X�g���[�~���O�L���b�V���쐬�p�\����
 * \return		CriSint32	�X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y���v�Z���܂��B<br>
 * config�ŗ^������p�����[�^�[�Ɉˑ����A�K�v�ȃ��[�N�T�C�Y�͑������܂��B<br>
 * \sa criAtomExStreamingCache_Create
 */
#define criAtomExStreamingCache_CalculateWorkSize(p_config)	\
	criAtomStreamingCache_CalculateWorkSize(p_config)

/*JP
 * \brief �X�g���[�~���O�L���b�V���̍쐬
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	config		�X�g���[�~���O�L���b�V���쐬�p�\����
 * \param[in]	work		�X�g���[�~���O�L���b�V���쐬�p���[�N
 * \param[in]	work_size	�X�g���[�~���O�L���b�V���쐬�p���[�N�T�C�Y
 * return		CriAtomExStreamingCacheId	�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �X�g���[�~���O�L���b�V�����쐬���܂��B<br>
 * Atom�v���[���[�ɃX�g���[�~���O�L���b�V����ݒ肷�邱�ƂŁA
 * �X�g���[�~���O�Đ����s����������Ƀt�@�C���S�̂�ێ��i�L���b�V���j���܂��B<br>
 * �����t�@�C����2��ڈȍ~�̍Đ��ł́A�L���b�V�����g�����������Đ��Ɏ����I�ɐ؂�ւ��܂��B<br>
 * �܂��A�Đ��f�[�^�����[�v�f�[�^�������Ă����ꍇ�A
 * ���[�v�ȍ~�̍Đ��͎����I�Ƀ������Đ��ōs����悤�ɂȂ�܂��B<br>
 * �{�@�\��Atom�v���[���[���X�g���[�~���O�Đ����s���ꍇ�̂݋@�\���܂��B<br>
 * �{�֐��Ɏ��s�����ꍇ�ACRIATOMEX_STREAMING_CACHE_ILLEGAL_ID���Ԃ�܂��B<br>
 * \attention
 * �t�@�C���S�̂��L���b�V�����鎖���O��ł��̂ŁA�L���b�V���p�Ɋ��蓖�Ă�ꂽ�������T�C�Y��
 * �X�g���[�~���O�Đ��ΏۂƂ���ǂ̃t�@�C���T�C�Y�����������ꍇ�A
 * ��؃L���b�V������܂���B
 * \sa criAtomExStreamingCache_CalculateWorkSize, criAtomExStreamingCache_Destroy,
 */
#define criAtomExStreamingCache_Create(config, work, work_size)	\
	criAtomStreamingCache_Create((config), (work), (work_size));

/*JP
 * \brief �X�g���[�~���O�L���b�V���̔j��
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id		�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V����j�����܂��B<br>
 * \attention
 * �w�肵���X�g���[�~���O�L���b�V���𗘗p���Ă���v���[���[�����݂��Ȃ���ԂŁA
 * �{�֐������s���Ă��������B
 * \sa criAtomExStreamingCache_Create
 */
#define criAtomExStreamingCache_Destroy(stm_cache_id)	\
	criAtomStreamingCache_Destroy(stm_cache_id)

/*JP
 * \brief �X�g���[�~���O�L���b�V���̃L���b�V�����e���N���A
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	cache_id		�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V���̓��e���N���A���܂��B<br>
 * �L���b�V���͌Â����ɃN���A����܂��B<br>
 * �w�肵���X�g���[�~���O�L���b�V�����g�p���̃v���[���[�����݂���ꍇ�A
 * �L���b�V���̃N���A�͓r���Œ��f����܂��B<br>
 * \attention
 * ��ԌÂ��L���b�V�����g�p���̃v���[���[�����݂���ꍇ�A�{�֐������s���Ă�
 * �L���b�V���͈�؃N���A����܂���B
 * \sa criAtomExStreamingCache_Create
 */
#define criAtomExStreamingCache_Clear(cache_id)	\
	criAtomStreamingCache_Clear(cache_id)

/*JP
 * \brief WaveID�w��ŃL���b�V���ς݌���
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id		�X�g���[�~���O�L���b�V��ID
 * \param[in]	awb					AWB�n���h��
 * \param[in]	id					WaveID
 * \return		CriBool				�L���b�V���ς݂ł����CRI_TRUE�A����ȊO��CRI_FALSE
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V�����ɁA�w��̉����f�[�^���L���b�V������Ă��邩���������܂��B<br>
 * �w��̉����f�[�^���L���b�V������Ă����Ԃł����CRI_TRUE���A
 * �L���b�V������Ă��Ȃ���Ԃł����CRI_FALSE��Ԃ��܂��B<br>
 * \attention
 * AWB�n���h�����������Đ��p�̏ꍇ�A�{�֐��͉����f�[�^�̗L���ɂ�����炸CRI_TRUE��Ԃ��܂��B<br>
 * \sa criAtomExStreamingCache_Create
 */
#define criAtomExStreamingCache_IsCachedWaveId(stm_cache_id, awb, id)	\
	criAtomStreamingCache_IsCachedWaveId((stm_cache_id), (awb), (id))

/*JP
 * \brief �p�X�w��ŃL���b�V���ς݌���
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id		�X�g���[�~���O�L���b�V��ID
 * \param[in]	src_binder			�����f�[�^�t�@�C���ǂݍ��݌��̃o�C���_�[�n���h��
 * \param[in]	path				�����f�[�^�t�@�C���̃p�X
 * \return		CriBool				�L���b�V���ς݂ł����CRI_TRUE�A����ȊO��CRI_FALSE
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V�����ɁA�w��̉����f�[�^���L���b�V������Ă��邩���������܂��B<br>
 * �w��̉����f�[�^���L���b�V������Ă����Ԃł����CRI_TRUE���A
 * �L���b�V������Ă��Ȃ���Ԃł����CRI_FALSE��Ԃ��܂��B<br>
 * \sa criAtomStreamingCache_Create
 */
#define criAtomExStreamingCache_IsCachedFile(stm_cache_id, src_binder, path)	\
	criAtomStreamingCache_IsCachedFile((stm_cache_id), (src_binder), (path))

/*==========================================================================
 *      CRI AtomEx 3D API
 *=========================================================================*/
/*JP
 * \brief 3D�����n���h���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D�����n���h���쐬�p�R���t�B�O�\���́i ::CriAtomEx3dSourceConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa
 * CriAtomEx3dSourceConfig
 */
#define criAtomEx3dSource_SetDefaultConfig(p_config)	\
{\
	(p_config)->enable_voice_priority_decay = CRI_FALSE;\
	(p_config)->random_position_list_max_length = 0;\
}

/*JP
 * \brief 3D�����n���h�����X�g�쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D�����n���h�����X�g�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D�����n���h�����X�g�쐬�p�R���t�B�O�\���́i ::CriAtomEx3dSourceListConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa
 * CriAtomEx3dSourceListConfig
 */
#define criAtomEx3dSourceList_SetDefaultConfig(p_config)	\
{\
	(p_config)->reserved = 0;\
}

/*JP
 * \brief 3D���X�i�[�n���h���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D���X�i�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D���X�i�[�n���h���쐬�p�R���t�B�O�\���́i ::CriAtomEx3dListenerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa
 * CriAtomEx3dListenerConfig
 */
#define criAtomEx3dListener_SetDefaultConfig(p_config)	\
{\
	(p_config)->reserved = 0;\
}

/*JP
 * \brief 3D���[�W�����n���h���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D���[�W�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D���[�W�����n���h���쐬�p�R���t�B�O�\���́i ::CriAtomEx3dRegionConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa
 * CriAtomEx3dRegionConfig
 */
#define criAtomEx3dRegion_SetDefaultConfig(p_config)	\
{\
	(p_config)->reserved = 0;\
}

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\���́i ::CriAtomEx3dTransceiverConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa
 * CriAtomEx3dTransceiverConfig
 */
#define criAtomEx3dTransceiver_SetDefaultConfig(p_config)	\
{\
	(p_config)->reserved = 0;\
}

/*JP
 * \brief 3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_3D
 * \param[out]	p_config	3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * 3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\���́i ::CriAtomEx3dSourceRandomPositionConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B
 * \sa CriAtomEx3dSourceRandomPositionConfig
 */
#define criAtomEx3dSource_SetDefaultConfigForRandomPosition(p_config)	\
{\
	(p_config)->follows_original_source = CRI_FALSE;\
	(p_config)->calculation_type = CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_RECTANGLE;\
	(p_config)->calculation_parameters[0] = 1.0f;\
	(p_config)->calculation_parameters[1] = 1.0f;\
	(p_config)->calculation_parameters[2] = 0.0f;\
}

/*JP
 * \brief 3D�����̍ŏ������^�ő勗���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	min_attenuation_distance		�ŏ�����
 * \param[in]	max_attenuation_distance		�ő勗��
 * \par ����:
 * 3D�����̍ŏ������^�ő勗����ݒ肵�܂��B<br>
 * �ŏ������́A����ȏ㉹�ʂ��傫���Ȃ�Ȃ�������\���܂��B�ő勗���́A�ŏ����ʂɂȂ鋗����\���܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- �ŏ������F0.0f
 * 	- �ő勗���F0.0f
 * 	
 * �f�t�H���g�l�́A::criAtomEx3dSource_ChangeDefaultMinMaxAttenuationDistance �֐��ɂĕύX�\�ł��B<br>
 * �f�[�^���ɓ��Y�p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA�f�[�^���̒l���㏑���i�����j���ēK�p����܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultMinMaxDistance
 */
#define criAtomEx3dSource_SetMinMaxDistance(ex_3d_source, min_attenuation_distance, max_attenuation_distance) \
	criAtomEx3dSource_SetMinMaxAttenuationDistance((ex_3d_source), (min_attenuation_distance), (max_attenuation_distance))

/*JP
 * \brief 3D�����̍ŏ������^�ő勗���̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	min_attenuation_distance		�ŏ�����
 * \param[in]	max_attenuation_distance		�ő勗��
 * \par ����:
 * 3D�����̍ŏ������^�ő勗���̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �ŏ������^�ő勗���̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * \attention
 * ���Y�p�����[�^�[�Ɋւ��āu�c�[�����Œl���ύX����Ă��Ȃ��i�f�t�H���g��ԁj�v�f�[�^�̏ꍇ�A�ÖٓI�Ƀf�t�H���g�l���K�p����܂��B<br>
 * ���̂��߁A�{�֐��Ńf�t�H���g�l��ύX����ƁA�c�[���ł̕ҏW���ɈӐ}���Ă����p�����[�^�[�ƈقȂ��Ă��܂��\��������܂��B<br>
 * �A���A�ȉ��ɊY������f�[�^�͖{�֐��̉e�����󂯂܂���B<br>
 * 	- �c�[���̃v���p�e�B�ɂāA�ŏ������^�ő勗���̏����l�ݒ��0.0�ȊO�ɐݒ肵�Ă���
 * 	- �C���Q�[���v���r���[�p�Ƀr���h���Ă���
 * 	
 * \sa criAtomEx3dSource_SetMinMaxDistance
 */
#define criAtomEx3dSource_ChangeDefaultMinMaxDistance(min_attenuation_distance, max_attenuation_distance) \
	criAtomEx3dSource_ChangeDefaultMinMaxAttenuationDistance((min_attenuation_distance), (max_attenuation_distance))

/*==========================================================================
 *      CRI AtomEx DSP API
 *=========================================================================*/

/*JP
 * \brief �s�b�`�V�t�^DSP�̃A�^�b�`�p�R���t�B�O�Ƀf�t�H���g�l���f�t�H���g�Z�b�g
 * \ingroup ATOMEXLIB_DSP
 * \param[out]	p_config	�s�b�`�V�t�^DSP�̃A�^�b�`�p�R���t�B�O�ւ̃|�C���^
 * \par ����:
 * �s�b�`�V�t�^DSP�̃A�^�b�`�p�R���t�B�O�i ::CriAtomExDspPitchShifterConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B
 * \sa CriAtomExDspPitchShifterConfig, criAtomExVoicePool_AttachDspPitchShifter
 */
#define criAtomExVoicePool_SetDefaultConfigForDspPitchShifter(p_config)	\
{\
	(p_config)->num_dsp = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	(p_config)->max_channels = CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate = CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->specific.mode = 0;\
	(p_config)->specific.window_size = 1024;\
	(p_config)->specific.overlap_times = 4;\
}

/*JP
 * \brief �^�C���X�g���b�`DSP�̃A�^�b�`�p�R���t�B�O�Ƀf�t�H���g�l���f�t�H���g�Z�b�g
 * \ingroup ATOMEXLIB_DSP
 * \param[out]	p_config	�^�C���X�g���b�`DSP�̃A�^�b�`�p�R���t�B�O�ւ̃|�C���^
 * \par ����:
 * �^�C���X�g���b�`DSP�̃A�^�b�`�p�R���t�B�O�i ::CriAtomExDspTimeStretchConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B
 * \sa CriAtomExDspTimeStretchConfig, criAtomExVoicePool_AttachDspTimeStretch
 */
#define criAtomExVoicePool_SetDefaultConfigForDspTimeStretch(p_config)	\
{\
	(p_config)->num_dsp = CRIATOMEX_DEFAULT_VOICES_PER_POOL;\
	(p_config)->max_channels = CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate = CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->specific.reserved = 0;\
}

/*==========================================================================
 *      CRI AtomEx Tween API
 *=========================================================================*/
/*JP
 * \brief �g�D�C�[���쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_TWEEN
 * \param[out]	p_config	�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExTween_Create �֐��ɐݒ肷��R���t�B�O�\���́i ::CriAtomExTweenConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa
 * CriAtomExTweenConfig
 */
#define criAtomExTween_SetDefaultConfig(p_config)	\
{\
	(p_config)->id.parameter_id = CRIATOMEX_PARAMETER_ID_VOLUME;\
	(p_config)->parameter_type = CRIATOMEX_PARAMETER_TYPE_BASIC;\
}

/*==========================================================================
 *      CRI AtomEx Sound Object API
 *=========================================================================*/
/*JP
 * \brief �T�E���h�I�u�W�F�N�g�쐬�p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[out]	p_config	�T�E���h�I�u�W�F�N�g�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomExSoundObject_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExSoundObjectConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExSoundObjectConfig, criAtomExSoundObject_Create
 */
#define criAtomExSoundObject_SetDefaultConfig(p_config)	\
{\
	(p_config)->enable_voice_limit_scope = CRI_FALSE;\
	(p_config)->enable_category_cue_limit_scope = CRI_FALSE;\
}

/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief �������m�ۊ֐�
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �A���P�[�^�[�o�^���Ɏg�p���郁�����m�ۊ֐��̌^�ł��B
 * \sa criAtomEx_SetUserAllocator
 */
typedef CriAtomMallocFunc CriAtomExMallocFunc;

/*JP
 * \brief ����������֐�
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �A���P�[�^�[�o�^���Ɏg�p���郁��������֐��̌^�ł��B
 * \sa criAtomEx_SetUserAllocator
 */
typedef CriAtomFreeFunc CriAtomExFreeFunc;

/*JP
 * \brief �X���b�h���f��
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * Atom���C�u�������ǂ̂悤�ȃX���b�h���f���œ��삷�邩��\���܂��B<br>
 * ���C�u�������������i ::criAtomEx_Initialize �֐� �j�� ::CriAtomExConfig 
 * �\���̂ɂĎw�肵�܂��B
 * \sa criAtomEx_Initialize, CriAtomExConfig
 */
typedef enum CriAtomExThreadModelTag {
	/*JP
	 * \brief �}���`�X���b�h
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criAtomEx_Initialize �֐��Ăяo�����ɍ쐬����܂��B<br>
	 * ���C�u�����̃T�[�o�[�����́A�쐬���ꂽ�X���b�h��Œ���I�Ɏ��s����܂��B<br>
	 */
	CRIATOMEX_THREAD_MODEL_MULTI = 0,
	
	/*JP
	 * \brief �}���`�X���b�h�i���[�U�쓮���j
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criAtomEx_Initialize �֐��Ăяo�����ɍ쐬����܂��B<br>
	 * �T�[�o�[�������͍̂쐬���ꂽ�X���b�h��Ŏ��s����܂����A
	 * CRIATOMEX_THREAD_MODEL_MULTI �Ƃ͈قȂ�A�����I�ɂ͎��s����܂���B<br>
	 * ���[�U�� ::criAtomEx_ExecuteMain �֐��Ŗ����I�ɃT�[�o�[�������쓮����K�v������܂��B<br>
	 * �i  ::criAtomEx_ExecuteMain �֐������s����ƁA�X���b�h���N�����A�T�[�o�[���������s����܂��B�j<br>
	 */
	CRIATOMEX_THREAD_MODEL_MULTI_USER_DRIVEN = 3,
	
	/*JP
	 * \brief ���[�U�}���`�X���b�h
	 * \par ����:
	 * ���C�u���������ł̓X���b�h���쐬���܂��񂪁A���[�U���Ǝ��ɍ쐬�����X���b�h
	 * ����T�[�o�[�����֐����Ăяo����悤�A�����̔r������͍s���܂��B<br>
	 * �T�[�o�[������ ::criAtomEx_ExecuteMain �֐����œ������s����܂��B<br>
	 */
	CRIATOMEX_THREAD_MODEL_USER_MULTI = 1,
	
	/*JP
	 * \brief �V���O���X���b�h
	 * \par ����:
	 * ���C�u���������ŃX���b�h���쐬���܂���B�܂��A�����̔r��������s���܂���B<br>
	 * �T�[�o�[������ ::criAtomEx_ExecuteMain �֐����œ������s����܂��B<br>
	 * \attention
	 * ���̃��f����I�������ꍇ�A�eAPI�ƃT�[�o�[�����֐��Ƃ𓯈�X���b�h����Ăяo���悤�ɂ��Ă��������B<br>
	 */
	CRIATOMEX_THREAD_MODEL_SINGLE = 2,
	
	/* enum size is 4bytes */
	CRIATOMEX_THREAD_MODEL_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExThreadModel;

/*JP
 * \brief ���W�n
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * Atom���C�u������3D�|�W�V�����v�Z���s���ہA�ǂ̍��W�n���g�p���邩��\���܂��B<br>
 * ���C�u�������������i ::criAtomEx_Initialize �֐� �j�� ::CriAtomExConfig 
 * �\���̂ɂĎw�肵�܂��B
 * \sa criAtomEx_Initialize, CriAtomExConfig
 */
typedef enum CriAtomExCoordinateSystemTag {
	/*JP
	 * \brief ������W�n
	 * \par ����:
	 * x�̐��������E�Ay�̐���������Az�̐����������ƂȂ�悤�ȁA����f�J���g���W�n�ł��B
	 */
	CRIATOMEX_COORDINATE_SYSTEM_LEFT_HANDED = 0,
	
	/*JP
	 * \brief �E����W�n
	 * \par ����:
	 * x�̐��������E�Ay�̐���������Az�̐���������O�ƂȂ�悤�ȁA�E��f�J���g���W�n�ł��B
	 */
	CRIATOMEX_COORDINATE_SYSTEM_RIGHT_HANDED = 1,
	
	/* enum size is 4bytes */
	CRIATOMEX_COORDINATE_SYSTEM_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExCoordinateSystem;

/*JP
 * \brief ACF�w��^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * Atom���C�u�����̏�������������ACF�o�^���s���ۂ́AACF���̎w��^�C�v��\���܂��B<br>
 * ���C�u�������������i ::criAtomEx_Initialize �֐� �j�� ::CriAtomExConfig 
 * �\���̂� ::CriAtomExAcfRegistrationInfo �ɂĎw�肵�܂��B
 * \sa criAtomEx_Initialize, CriAtomExConfig, CriAtomExAcfRegistrationInfo
 */
typedef enum CriAtomExAcfLocationInfoTypeTag {
	CRIATOMEX_ACF_LOCATION_INFO_TYPE_NONE = 0,	/*JP< ���ݒ� */
	CRIATOMEX_ACF_LOCATION_INFO_TYPE_NAME,		/*JP< �t�@�C���� */
	CRIATOMEX_ACF_LOCATION_INFO_TYPE_ID,		/*JP< �R���e���cID */
	CRIATOMEX_ACF_LOCATION_INFO_TYPE_DATA,		/*JP< �I���������f�[�^ */
	CRIATOMEX_ACF_LOCATION_INFO_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAcfLocationInfoType;

/*JP
 * \brief �^������������iRandom Number Generator�j�n���h��
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef void *CriAtomExRngHn;

/*JP
 * \brief �^������������iRandom Number Generator�j�C���^�[�t�F�[�X
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef struct CriAtomExRngInterfaceTag {
	/*JP
	 * \brief ���[�N�̈�T�C�Y�̌v�Z
	 * \return	CriSint32	���[�N�̈�T�C�Y
	 * \par ����:
	 * �^��������������쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
	 */
	CriSint32 (*CalculateWorkSize)(void);

	/*JP
	 * \brief �^������������̍쐬
	 * \param[in]	work			���[�N�̈�
	 * \param[in]	work_size		���[�N�̈�T�C�Y
	 * \return		CriAtomExRngHn	�^������������n���h��
	 * \par ����:
	 * �^��������������쐬���܂��B<br>
	 * �^������������̍쐬�Ɏ��s�����ꍇ��NULL��Ԃ��܂��B<br>
	 */
	CriAtomExRngHn (*Create)(void* work, CriSint32 work_size);

	/*JP
	 * \brief �^������������̔j��
	 * \param[in]	rng		�^������������n���h��
	 * \par ����:
	 * �^�������������j�����܂��B<br>
	 */
	void (*Destroy)(CriAtomExRngHn rng);

	/*JP
	 * \brief �^�������̐���
	 * \param[in]	rng			�^������������n���h��
	 * \param[in]	min			�ŏ��l
	 * \param[in]	max			�ő�l
	 * \return		CriSint32	�^������
	 * \par ����:
	 * �V�����^�������𐶐����܂��B<br>
	 * �������ꂽ�^��������min�ȏ�max�ȉ��ł���K�v������܂��B�imin,max�͔͈͂Ɋ܂ށj
	 */
	CriSint32 (*Generate)(CriAtomExRngHn rng, CriSint32 min, CriSint32 max);

	/*JP
	 * \brief ������̐ݒ�
	 * \param[in]	rng			�^������������n���h��
	 * \param[in]	seed		������
	 * \par ����:
	 * �[�����������̌��ƂȂ闐�����ݒ肵�܂��B<br>
	 */
	void (*SetSeed)(CriAtomExRngHn rng, CriUint32 seed);

} CriAtomExRngInterface;

/*JP
 * \brief ACF�ʒu���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * Atom���C�u�����̏�������������ACF�o�^���s���ۂ́AACF�f�[�^�̎w����ł��B<br>
 * ���C�u�������������i ::criAtomEx_Initialize �֐� �j�� ::CriAtomExConfig 
 * �\���̂�acf_info�����o�ɐݒ肵�܂��B
 * \par ���l
 * �f�[�^�w��̃^�C�v�ɂ���āA�ݒ肷�ׂ���񂪈قȂ�܂��B<br>
 * �K�؂�type��ݒ肵�A���p��info�̒��̑Ή��\���̂ɐݒ���s���Ă��������B<br>
 * \code
 * CriAtomExConfig config;
 * CriAtomExAcfLocationInfo acf_info;
 *
 * criAtomEx_SetDefaultConfig(&config);
 * 
 * acf_info.type = CRIATOMEX_ACF_LOCATION_INFO_TYPE_NAME;
 * acf_info.name.binder = NULL;
 * acf_info.name.path = "sounddata/project.scf";
 *
 * config.acf_info = &acf_info;
 *
 * criAtomEx_Initialize(&config);
 *
 * \endcode
 * \sa criAtomEx_Initialize, CriAtomExConfig
 */
typedef struct CriAtomExAcfRegistrationInfoTag {
	/*JP �w��^�C�v */
	CriAtomExAcfLocationInfoType type;

	/*JP ACF�ʒu��񋤗p�� */
	union CriAtomExAcfLocationInfoTag {
		/*JP �t�@�C�����w�莞��� */
		struct CriAtomExAcfLocationInfoNameTag {
			CriFsBinderHn binder;	/*JP< �o�C���_�[�n���h�� */
			const CriChar8 *path;	/*JP< ACF�t�@�C���p�X */
		} name;
		/*JP �t�@�C��ID�w�莞��� */
		struct CriAtomExAcfLocationInfoIdTag {
			CriFsBinderHn binder;	/*JP< �o�C���_�[�n���h�� */
			CriSint32 id;			/*JP< �R���e���cID */
		} id;
		/*JP �I���������f�[�^�w�莞��� */
		struct CriAtomExAcfLocationInfoDataTag {
			void *buffer;			/*JP< �������A�h���X */
			CriSint32 size;			/*JP< �T�C�Y */
		} data;
	} info;	
} CriAtomExAcfRegistrationInfo;

/*JP
 * \brief Atom���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_GLOBAL
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomEx_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * CRI Atom���C�u�����́A���������ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA�������\�[�X��
 * �K�v�Ȃ����m�ۂ��܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ�����
 * �ω����܂��B
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomEx_SetDefaultConfig �}�N���ō\���̂Ƀf�t�H���g
 * �p�����[�^�[���Z�b�g������A ::criAtomEx_Initialize �֐��ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomEx_SetDefaultConfig �}�N�����g�p���Ȃ�
 * �ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomEx_Initialize, criAtomEx_SetDefaultConfig
 */
typedef struct CriAtomExConfigTag {
	/*JP
		\brief �X���b�h���f��
		\par ����:
		CRI Atom���C�u�����̃X���b�h���f�����w�肵�܂��B<br>
		\sa CriAtomExThreadModel
	*/
	CriAtomExThreadModel thread_model;
	
	/*JP
		\brief �T�[�o�[�����̎��s�p�x
		\par ����:
		�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		�ʏ�A�A�v���P�[�V�����̃t���[�����[�g�Ɠ����l���w�肵�܂��B<br>
		<br>
		CRI Atom���C�u�����́A�t�@�C���ǂݍ��݂̊Ǘ���A�����f�[�^�̃f�R�[�h�A�����̏o�́A
		�X�e�[�^�X�̍X�V���A���C�u���������ōs�������̂قƂ�ǂ�1�̊֐��ł܂Ƃ߂�
		�s���܂��B<br>
		CRI�~�h���E�F�A�ł́A�������������C�u�������̏������ꊇ���čs���֐��̂��Ƃ�
		"�T�[�o�[����"�ƌĂ�ł��܂��B<br>
		<br>
		�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI �̏ꍇ�A�T�[�o�[������
		CRI Atom���C�u�������쐬����X���b�h�ŁA����I�Ɏ��s����܂��B<br>
		�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_SINGLE �� ::CRIATOMEX_THREAD_MODEL_USER_MULTI 
		�̏ꍇ�A�T�[�o�[������ ::criAtomEx_ExecuteMain �֐����Ŏ��s����܂��B<br>
		<br>
		server_frequency �ɂ́A�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI �̏ꍇ�ACRI Atom���C�u�����͎w�肳�ꂽ
		�p�x�ŃT�[�o�[���������s�����悤�A�T�[�o�[�����̌Ăяo���Ԋu�𒲐߂��܂��B<br>
		�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_SINGLE �� ::CRIATOMEX_THREAD_MODEL_USER_MULTI 
		�̏ꍇ�A���[�U�� ::criAtomEx_ExecuteMain �֐��� server_frequency �Ŏw�肵���p�x�ȏ�
		�Ŏ��s����K�v������܂��B<br>
		<br>
		�A�v���P�[�V�����̃t���[�����[�g�̕ϓ����傫���A�T�[�o�[���������s����p�x�Ƀo���c�L
		���ł��Ă��܂��ꍇ�ɂ́A�ň��̃t���[�����[�g��z�肵�� server_frequency �̒l���w��
		���邩�A�܂��̓X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI ���w�肵�Ă��������B
		\par ���l:
		Atom���C�u�����̃T�[�o�[�����ł́A�ȉ��̂悤�ȏ������s���܂��B<br>
		- �������N�G�X�g�̏����i�{�C�X�̎擾���j
		- �p�����[�^�[�̍X�V�i�{�����[����p���A�s�b�`���̕ύX�̓K�p�j
		- �����f�[�^�̃f�R�[�h�Əo��
		
		�T�[�o�[�����̎��s�p�x�𑽂�����ƁA�P�ʃT�[�o�[����������̉����f�[�^�f�R�[�h�ʂ����Ȃ��Ȃ�܂��B<br>
		���̌��ʁA�P�ʃT�[�o�[������̏������ׂ͏������Ȃ�܂��i���ׂ����U����܂��j���A
		�T�[�o�[�����̎��s�ɔ����I�[�o�[�w�b�h�͑傫���Ȃ�܂��B<br>
		�i�X���b�h�̋N���񐔂�p�����[�^�[�̍X�V�񐔂������Ȃ�܂��B�j<br>
		<br>
		�T�[�o�[�����̎��s�p�x�����Ȃ�����ƁA�X���b�h�̋N���┭�����N�G�X�g�̏����A
		�p�����[�^�[�̍X�V�����̉񐔂�����A�A�v���P�[�V�����S�̂̏������ׂ͉�����܂��B<br>
		���ʁA�f�[�^�������[�h����p�x�������邽�߁A�P�ʃT�[�o�[����������f�R�[�h�ʂ͑����A
		�f�R�[�h���ʂ�ێ����邽�߂̃o�b�t�@�[�T�C�Y���]���ɕK�v�ɂȂ�܂��B<br>
		�܂��A�������N�G�X�g����������p�x�������邽�߁A
		�������N�G�X�g���特���o�͊J�n�܂łɂ����鎞�Ԃ͒����Ȃ�܂��B<br>
		\attention
		�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_SINGLE �� ::CRIATOMEX_THREAD_MODEL_USER_MULTI 
		���w�肵���ɂ�������炸�A ::criAtomEx_ExecuteMain �֐��� server_frequency ��
		�w�肵���l�ȉ��̕p�x�ł������s����Ȃ������ꍇ�A�Đ����̉����r�؂�铙�̖�肪
		��������\��������܂��̂ŁA�����ӂ��������B<br>
		\sa criAtomEx_ExecuteMain
	*/
	CriFloat32 server_frequency;
	
	/*JP
		\brief �p�����[�^�[�X�V�Ԋu
		\par ����:
		�T�[�o�[�������s���Ƀp�����[�^�[�̍X�V�������s���Ԋu���w�肵�܂��B<br>
		parameter_update_interval �̒l��ύX���邱�ƂŁA
		�T�[�o�[�����̎��s�񐔂�ς��邱�ƂȂ��p�����[�^�[�X�V�p�x�������邱�Ƃ��\�ł��B<br>
		<br>
		parameter_update_interval �ɂ́A�p�����[�^�[�̍X�V���������T�[�o�[���Ƃɍs�������w�肵�܂��B<br>
		�Ⴆ�΁A parameter_update_interval �� 2 �ɐݒ肷��ƁA
		�T�[�o�[���� 2 ��ɑ΂��A 1 �񂾂��p�����[�^�[�̕ύX���s���܂��B<br>
		�i�p�����[�^�[�̍X�V�p�x�� 1/2 �ɂȂ�܂��B�j<br>
		\par ���l:
		�T�[�o�[�������g���i server_frequency �j��������ƁA
		�T�[�o�[�����̎��s�񐔂����邽�߁A�A�v���P�[�V�����S�̂̏������ׂ͉�����܂����A
		�T�[�o�[�������m�̊Ԋu���J�����߁A�o�b�t�@�����O���ׂ��f�[�^�̗ʂ��������܂��B<br>
		���̌��ʁA�o�b�t�@�����O�̂��߂ɕK�v�ȃ������̃T�C�Y�͑������܂��B<br>
		<br>
		����ɑ΂��A�T�[�o�[�������g����ύX�����Ƀp�����[�^�[�X�V�Ԋu�i parameter_update_interval �j
		�̒l���グ���ꍇ�A�������T�C�Y�𑝉��������ɕ��ׂ������邱�Ƃ��\�ƂȂ�܂��B<br>
		�������A�T�[�o�[�����̋쓮�ɔ��������̃I�[�o�[�w�b�h�i�X���b�h�̋N�����ד��j
		�͍팸����Ȃ����߁A�T�[�o�[�����̉񐔂����炷�ꍇ�ɔ�ׁA���׍팸�̌��ʂ͔����ł��B<br>
		\par ����:
		parameter_update_interval �̒l��ύX�����ꍇ�A
		�������N�G�X�g�̏����p�x�����Ȃ��Ȃ�܂��B<br>
		���̂��߁A parameter_update_interval �̒l��ύX����ƁA
		�������N�G�X�g���特���o�͊J�n�܂łɂ����鎞�Ԃ������Ȃ�܂��B<br>
	*/
	CriSint32 parameter_update_interval;
	
	/*JP
		\brief CRI Atom Library�ȊO���g���������o�͂��s�����Ƃ��w�肷��t���O
		\par ����:
		CRI Atom Library���g�p�����ɉ����o�͂���ۂ�CRI_TRUE���w�肵�܂��B<br>
		::criAtomEx_SetDefaultConfig �}�N���ł́ACRI Atom Library���w�肷�邽�߁ACRI_FALSE���w�肳��܂��B<br>
		CRI Atom Library�ȊO�̉����o�̓��C�u������p����ꍇ�́A�{�t���O��CRI_TRUE���w�肵�Ă���AcriAtomEx_Initialize��
		���s����悤�ɂ��Ă��������B
		\attention
		�{�t���O��؂�ւ���ۂɂ́AAtom���C�u������criAtomEx_Finalize�ŏI�����Ă���A�t���O�̓��e��ύX���A�ēx
		criAtomEx_Initialize�ɂď������������s���悤�ɂ��Ă��������B<br>
	*/
	CriBool enable_atom_sound_disabled_mode;
	
	/*JP
		\brief �ő�o�[�`�����{�C�X��
		\par ����:
		�A�v���P�[�V�����œ����ɔ���������s���{�C�X�̐��ł��B<br>
		Atom���C�u�����́A���������� max_virtual_voices �Ŏw�肳�ꂽ��������
		�����Ǘ��ɕK�v�ȃ��\�[�X���m�ۂ��܂��B<br>
		\par ���l:
		max_virtual_voices �Ŏw�肳�ꂽ���ȏ�̉����𓯎��ɔ������邱�Ƃ͂ł��܂���B<br>
		�܂��A max_virtual_voices ���̔������N�G�X�g���s�����Ƃ��Ă��A���ۂ�
		��������鉹���̐��́A�K������ max_virtual_voices �Ɉ�v����Ƃ͌���܂���B<br>
		���ۂɔ����\�ȉ����̐��́A�{�C�X�v�[���Ŋm�ۂ��ꂽ�{�C�X����A
		�^�[�Q�b�g�@�ŗ��p�\�ȃn�[�h�E�F�A�{�C�X�̐��Ɉˑ����܂��B<br>
		<br>
		�o�[�`�����{�C�X���̖ڈ��́A�u�ő哯���������{1V������̔������N�G�X�g���v�ł��B<br>
		�o�[�`�����{�C�X�����ő哯����������菭�Ȃ��ꍇ��A
		�������ƃ��N�G�X�g���̍��v���ő�o�[�`�����{�C�X�𒴂���ꍇ�A
		�G���[�R�[���o�b�N�֐��Ɍx�����Ԃ����\��������܂��B<br>
		<br>
		CRIATOMEX_RETRY_VOICE_ALLOCATION ���w�肵�� AtomEx �v���[���[���쐬����ꍇ�A
		��L��������ɑ����̃o�[�`�����{�C�X��K�v�Ƃ���\��������܂��B<br>
	*/
	CriSint32 max_virtual_voices;
	
	/*JP
		\brief �ő�p�����[�^�[�u���b�N��
		\par ����:
		�����Đ����Ƀp�����[�^�[�Ǘ����s�����߂̗̈�̐��ł��B<br>
		Atom���C�u�����́A���������� max_parameter_blocks �Ŏw�肳�ꂽ��������
		�p�����[�^�[�Ǘ��ɕK�v�ȃ��\�[�X���m�ۂ��܂��B<br>
		\par ���l:
		1�̃L���[���Đ�����̂ɕK�v�ȃp�����[�^�[�u���b�N���́A
		�Đ�����L���[�̓��e�ɂ���ĕω����܂��B<br>
		�i���삷��p�����[�^�[�̐��ɔ�Ⴕ�ĕK�v�ȃp�����[�^�[�u���b�N���͑������܂��B�j<br>
		<br>
		�p�����[�^�[�u���b�N�����s�������ꍇ�A�Đ�����L���[�ɑ΂���
		�ꕔ�̃p�����[�^�[���ݒ肳��Ȃ����ƂɂȂ�܂��B<br>
		�i�{�����[����s�b�`�A�t�B���^�[�����Ӑ}�����l�ɂȂ�Ȃ��\��������܂��B�j<br>
		�A�v���P�[�V�������s���Ƀp�����[�^�[�u���b�N���s���̃G���[�����������ꍇ�A
		max_parameter_blocks �̒l�𑝂₵�Ă��������B<br>
	*/
	CriSint32 max_parameter_blocks;
	
	/*JP
		\brief �ő�{�C�X���~�b�g�O���[�v��
		\par ����:
		�A�v���P�[�V�����ō쐬����{�C�X���~�b�g�O���[�v�̐��ł��B<br>
		Atom���C�u�����́A���������� max_voice_limit_groups �Ŏw�肳�ꂽ����
		�̃{�C�X���~�b�g�O���[�v���쐬�ł��郊�\�[�X���m�ۂ��܂��B<br>
		\attention
		max_voice_limit_groups �Ŏw�肳�ꂽ���ȏ�̃{�C�X���~�b�g�O���[�v��
		�쐬���邱�Ƃ͂ł��܂���B<br>
		�I�[�T�����O�c�[����ō쐬�����{�C�X���~�b�g�O���[�v�̐��� 
		max_voice_limit_groups �𒴂���ꍇ�AACF�t�@�C���̃��[�h�Ɏ��s���܂��B<br>
	*/
	CriSint32 max_voice_limit_groups;

	/*JP
		\brief �ő�J�e�S����
		\par ����:
		�A�v���P�[�V�����ō쐬����J�e�S���̐��ł��B<br>
		Atom���C�u�����́A���������� max_categories �Ŏw�肳�ꂽ����
		�̃J�e�S�����쐬�ł��郊�\�[�X���m�ۂ��܂��B<br>
		\attention
		max_categories �Ŏw�肳�ꂽ���ȏ�̃J�e�S�����쐬���邱�Ƃ͂ł��܂���B<br>
		�I�[�T�����O�c�[����ō쐬�����J�e�S���̐��� 
		max_categories �𒴂���ꍇ�AACF�t�@�C���̃��[�h�Ɏ��s���܂��B<br>
	*/
	CriSint32 max_categories;

	/*JP
		\brief �ő�AISAC��
		\par ����:
		��̃L���[�ɕR�Â��邱�Ƃ��ł���AISAC�̍ő吔�ł��B<br>
		Atom���C�u�����́A���������� AtomExPlayer �쐬����
		max_aisacs �Ŏw�肳�ꂽ������AISAC���Q�Ƃł��郊�\�[�X���m�ۂ��܂��B<br>
		max_aisacs �Ɏw�肷��l�̏����55�ł��B
	*/
	CriUint8 max_aisacs;

	/*JP
		\brief �Đ��P�ʂł̃J�e�S���Q�Ɛ�
		\par ����:
		�Đ��P�ʂŎQ�Ɖ\�ȃJ�e�S���̐��ł��B<br>
		Atom���C�u�����́A���������� categories_per_playback �Ŏw�肳�ꂽ����
		�̃J�e�S�����Q�Ƃł��郊�\�[�X���m�ۂ��܂��B<br>
		�w��\�ȍő�l�� ::CRIATOMEXCATEGORY_MAX_CATEGORIES_PER_PLAYBACK �ł��B
		\attention
		categories_per_playback �Ŏw�肳�ꂽ���ȏ�̃J�e�S�����L���[��v���[���[����Q�Ƃ��邱�Ƃ͂ł��܂���B<br>
		�I�[�T�����O�c�[����ō쐬�����L���[�̎Q�ƃJ�e�S������ 
		categories_per_playback �𒴂���ꍇ�AACF�t�@�C���̃��[�h�Ɏ��s���܂��B<br>
	*/
	CriSint32 categories_per_playback;

	/*JP
		\brief �ő�Đ��V�[�P���X��
		\par ����:
		�A�v���P�[�V�����œ����ɍĐ�����V�[�P���X�̐��ł��B<br>
		Atom���C�u�����́A���������� max_sequences �Ŏw�肳�ꂽ���� max_virtual_voices �Ŏw�肳�ꂽ���̑��a��
		�̃V�[�P���X���Đ��ł��郊�\�[�X���m�ۂ��܂��B<br>
		\attention
		Ver.2.00�ȍ~�̃��C�u�����ł͑S�ẴL���[���V�[�P���X�Ƃ��čĐ�����邽�߁A max_sequences �ɉ�����
		 max_virtual_voices �����̃��\�[�X���m�ۂ���܂��B<br>
		max_sequences �Ŏw�肳�ꂽ���ȏ�̃V�[�P���X���Đ����邱�Ƃ͂ł��܂���B<br>
		�G���[�R�[���o�b�N�����������ꍇ�A���̒l��傫�����Ă��������B<br>
	*/
	CriSint32 max_sequences;

	/*JP
		\brief �ő�Đ��g���b�N��
		\par ����:
		�A�v���P�[�V�����œ����Đ�����V�[�P���X���̃g���b�N�����ł��B<br>
		Atom���C�u�����́A���������� max_tracks �Ŏw�肳�ꂽ���� max_virtual_voices �Ŏw�肳�ꂽ���̑��a��
		�̃g���b�N���Đ��ł��郊�\�[�X���m�ۂ��܂��B<br>
		\attention
		Ver.2.00�ȍ~�̃��C�u�����ł͑S�ẴL���[���V�[�P���X�Ƃ��čĐ�����邽�߁A max_tracks �ɉ�����
		 max_virtual_voices �����̃��\�[�X���m�ۂ���܂��B<br>
		max_tracks �Ŏw�肳�ꂽ���ȏ�̃g���b�N���Đ����邱�Ƃ͂ł��܂���B<br>
		�G���[�R�[���o�b�N�����������ꍇ�A���̒l��傫�����Ă��������B<br>
	*/
	CriUint32 max_tracks;

	/*JP
		\brief �ő�g���b�N�A�C�e����
		\par ����:
		�A�v���P�[�V�����œ����Đ�����V�[�P���X���̃C�x���g�̑����ł��B<br>
		Atom���C�u�����́A���������� max_track_items �Ŏw�肳�ꂽ���� max_virtual_voices �Ŏw�肳�ꂽ���̑��a��
		�̃g���b�N�A�C�e�����쐬�ł��郊�\�[�X���m�ۂ��܂��B<br>
		\attention
		Ver.2.00�ȍ~�̃��C�u�����ł͑S�ẴL���[���V�[�P���X�Ƃ��čĐ�����邽�߁A max_track_items �ɉ�����
		 max_virtual_voices �����̃��\�[�X���m�ۂ���܂��B<br>
		max_track_items �Ŏw�肳�ꂽ���ȏ�̃g���b�N�A�C�e����
		�쐬���邱�Ƃ͂ł��܂���B<br>
		�g���b�N�A�C�e���͔g�`��A���[�v�C�x���g���̃V�[�P���X�g���b�N�Đ�����
		�Ǘ����K�v�ȃC�x���g�ł��B<br>
		�G���[�R�[���o�b�N�����������ꍇ�A���̒l��傫�����Ă��������B<br>
	*/
	CriUint32 max_track_items;
	
	/*JP
		\brief �ő�AISAC�I�[�g���W�����[�V�������i�d�l��~�j
		\par ����:
		Ver.2.00.00�ȍ~�̃��C�u�����ł͎g�p��~�ƂȂ�܂����B
		���C�u���������ł̖{�����o�ւ̎Q�Ƃ͍s���܂���B<br>
	*/
	CriUint32 max_aisac_auto_modulations;

	/*JP
		\brief �s�b�`�ύX�̏���l
		\par ����:
		Atom���C�u�������œK�p�����s�b�`�ύX�̏���l��ݒ肵�܂��B<br>
		max_pitch�ɐݒ肳�ꂽ�l�ȏ�̃s�b�`�ύX���A���C�u�������ŃN���b�v����܂��B<br>
		<br>
		�s�b�`�̓Z���g�P�ʂŎw�肵�܂��B<br>
		1�Z���g��1�I�N�^�[�u��1/1200�ł��B������100�Z���g�ł��B<br>
		<br>
		�Ⴆ�΁A max_pitch �� 1200.0f ��ݒ肵���ꍇ�A
		1200�Z���g�𒴂���s�b�`���ݒ肳�ꂽ�L���[���Đ������Ƃ��Ă��A
		�s�b�`��1200�Z���g�ɗ}�����čĐ�����܂��B<br>
		\par ���l:
		�L���[�ɐݒ肳�ꂽ�s�b�`�ɁAAISAC�ɂ��s�b�`�ύX��h�b�v���[���ʂ��ǉ��K�p���ꂽ�ꍇ�A
		�\�����ʃ��x���܂Ńs�b�`���オ�鋰�ꂪ����܂��B<br>
		�i�s�b�`�ɔ�Ⴕ�ĒP�ʎ��ԓ�����̃f�R�[�h�ʂ��������邽�߁A
		�s�b�`���������鉹���ʂɖ炵���ꍇ�A�������ׂ��}�����鋰�ꂪ����܂��B�j<br>
		<br>
		�{�p�����[�^�[�ł��炩���߃s�b�`�����ݒ肵�Ă������ƂŁA
		�z��O�̕��וϓ���������邱�Ƃ��\�ƂȂ�܂��B<br>
		�Ⴆ�΁A max_pitch �� 1200.0f ��ݒ肵���ꍇ�A
		�A�v���P�[�V�������łǂ̂悤�ȑ�����s�����Ƃ��Ă��s�b�`��1200�Z���g
		�i��2�{���Đ��j�܂łɗ}�����邽�߁A
		�P�ʎ��Ԃ�����̃f�R�[�h�ʂ͍ő�ł��ʏ펞��2�{�܂łɐ�������܂��B<br>
		\par ����:
		max_pitch�ɂ� 0.0f �ȏ�̒l��ݒ肷��K�v������܂��B<br>
		�i 0.0f ���w�肵���ꍇ�A�s�b�`�̕ύX�͈�؍s���Ȃ��Ȃ�܂��B�j<br>
	*/
	CriFloat32 max_pitch;

	/*JP
		\brief �ő�t�F�[�_�[��
		\par ����:
		Atom���C�u�������Ŏg�p����t�F�[�_�[�̏���l��ݒ肵�܂��B<br>
		�����Őݒ肵�A���������Ɋm�ۂ����t�F�[�_�[��TrackTransitionBySelector�f�[�^�Đ����Ƀ��C�u���C�����Ŏg�p���܂��B<br>
	*/
	CriUint32 max_faders;

	/*JP
		\brief 3D�|�W�V�����v�Z���s���ۂ̍��W�n
		\par ����:
		Atom���C�u������3D�|�W�V�����v�Z���s���ہA�ǂ̍��W�n���g�p���邩��ݒ肵�܂��B
	*/
	CriAtomExCoordinateSystem coordinate_system;

	/*JP
		\brief �p���^�C�v���I�[�g�̏ꍇ�ɂ�����A���X�i�[�̃I�[�g�}�b�`���O�@�\�̗L����
		\par ����:
		�p���^�C�v���I�[�g�̏ꍇ�A���X�i�[�̃I�[�g�}�b�`���O�@�\��L�������邩��ݒ肵�܂��B
		\par ���l�F
		�p���^�C�v��3D�|�W�V���j���O�̏ꍇ�̓��X�i�[�̃I�[�g�}�b�`���O�@�\�͏�ɗL���ł��B
	*/
	CriBool enable_auto_matching_in_pan_type_auto;

	/*JP
		\brief AtomExPlayer�ɂ��J�e�S���̏㏑���̗L����
		\par ����:
		AtomExPlayer��::criAtomExPlayer_SetCategoryById�֐���::criAtomExPlayer_SetCategoryByName�֐�
		��p���ăJ�e�S�����Z�b�g�����ꍇ�ɃL���[�̃J�e�S���ݒ���㏑������@�\��L�������܂��B
		\par ���l�F
		CRI Atom Ver.2.20.31�����̃��C�u�����́A�v���[���[�ɑ΂��ăJ�e�S���ݒ���s���ƁA
		�L���[�ɐݒ肳��Ă����J�e�S�����㏑���ɂ�薳���ɂȂ��Ă��܂����B
		Ver.2.20.31�����̋����ɖ߂��K�v������ꍇ�ɂ͖{�t���O��CRI_FALSE��ݒ肵�Ă��������B
	*/
	CriBool enable_category_override_by_ex_player;

	/*JP
		\brief �V�[�P���X��ǂ݊����̎w��
		\par ����:
		�V�[�P���T�[��1�T�[�o�[�����œǂݍ��ޗʂ̊������w�肵�܂��B
		1.5f���w�肷��Ǝ��̃T�[�o�[�������s����\�z�������炳���0.5�T�[�o�[�����ǂ݂��܂��B
		�ő��3.0f�A�ŏ���1.1f���w��\�ł��B�͈͂𒴂���ꍇ�̓N���b�v����܂��B
		\par ���l:
		�T�[�o�[�����̗h��ɂ���Ĕ������锭���^�C�~���O�̂��ꂪ�������Â炭�Ȃ�܂��B
	*/
	CriFloat32 sequence_prepare_ratio;

	/*JP
	 * \brief �^������������C���^�[�t�F�[�X
	 * \par ����:
	 * CRI Atom���C�u�����Ŏg�p����^������������C���^�[�t�F�[�X���w�肵�܂��B<br>
	 * NULL���w�肵���ꍇ�́A�f�t�H���g�̋^��������������g�p���܂��B<br>
	 */
	const CriAtomExRngInterface *rng_if;

	/*JP
		\brief CRI File System �̏������p�����[�^�[�ւ̃|�C���^
		\par ����:
		CRI File System�̏������p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�f�t�H���g�p�����[�^�[��CRI File System�����������܂��B
		\sa criAtomEx_Initialize
	*/
	const CriFsConfig *fs_config;

	/*JP
		\brief ACF���ւ̃|�C���^
		\par ����:
		����������ACF�̓o�^���s���ۂ�ACF���ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A����������ACF�̓o�^�͍s���܂���B
		�{�����o��ݒ肵�ď�������������ACF�̓o�^���s���ꍇ�A ::CriAtomExConfig �\���̂�
		max_voice_limit_groups, max_categories, categories_per_playback�̊e�����o�l��
		ACF�ݒ�l�Ɣ�r���đ傫�����̒l���������p�ݒ�l�Ƃ��Ďg�p����܂��B
		CriAtomEx����������ACF�̓o�^���s�����ꍇ�A���ɂ���Ă� CriAtomExAsr, CriAtomExHcaMx
		���̃��W���[���������ɂ��ꕔACF���̐ݒ�l���g�p����܂��B<br>
		ACF���̐ݒ�l���g�p�����ɂ����̃��W���[�����������������ꍇ�́A�{�����o���g�p������
		���C�u�����̏��������s���A���̌�ACF�̓o�^���s���Ă��������B<br>
		\attention
		�{�����o��ݒ肷��ꍇ�A�������������ł�ACF�f�[�^�̓o�^��ACF�f�[�^�����ɏ�������
		�K�v�ȃ��[�N�𓮓I�Ɋm�ۂ��邽�߁A�������֐��Ăяo���O�Ƀ������A���P�[�^�[�֐��̓o�^��
		�G���[�R�[���o�b�N�֐��̓o�^���K�v�ɂȂ�܂��B<br>
		�{�����o���g�p����ꍇ�A���[�N�̈�̊m�ۂ͓o�^���ꂽ�������A���P�[�^�[�֐����g�p���čs���܂��B
		�擾�ς݃������̈���g�p���Ă̏������͍s���܂���B<br>
		\sa criAtomEx_Initialize, criAtomEx_SetUserAllocator
	*/
	const CriAtomExAcfRegistrationInfo *acf_info;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̏������p�����[�^�[�ւ̃|�C���^
		\par ����:
		CRI Atom���C�u�����𓮍삳���邽�߂ɕK�v�ȁA
		�v���b�g�t�H�[���ŗL�̏������p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�f�t�H���g�p�����[�^�[�Ńv���b�g�t�H�[�����ɕK�v�ȏ��������s���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
		\sa criAtomEx_Initialize
	*/
	void *context;

	/*JP
		\brief ���C�u�����o�[�W�����ԍ�
		\par ����:
		CRI Atom ���C�u�����̃o�[�W�����ԍ��ł��B<br>
		::criAtomEx_SetDefaultConfig �}�N���ɂ��A cri_atom.h �w�b�_�[�ɒ�`����Ă���o�[�W�����ԍ����ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	CriUint32 version;

	/*JP
		\brief ���W���[���o�[�W�����ԍ�
		\par ����:
		CRI Atom Ex �̃o�[�W�����ԍ��ł��B<br>
		::criAtomEx_SetDefaultConfig �}�N���ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W�����ԍ����ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	CriUint32 version_ex;

	/*JP
		\brief ���C�u�����o�[�W����������
		\par ����:
		CRI Atom ���C�u�����̃o�[�W����������ł��B<br>
		::criAtomEx_SetDefaultConfig �}�N���ɂ��A cri_atom.h �w�b�_�[�ɒ�`����Ă���o�[�W���������񂪐ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	const CriChar8 *version_string;

	/*JP
		\brief ���W���[���o�[�W����������
		\par ����:
		CRI Atom Ex �̃o�[�W����������ł��B<br>
		::criAtomEx_SetDefaultConfig �}�N���ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W���������񂪐ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	const CriChar8 *version_ex_string;
} CriAtomExConfig;

/*JP
 * \brief �p�t�H�[�}���X���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomEx_GetPerformanceInfo �֐��ŗ��p���܂��B
 * \sa criAtomEx_GetPerformanceInfo
 */
typedef CriAtomPerformanceInfo CriAtomExPerformanceInfo;

/*JP
 * \brief �g�`�f�[�^ID
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �g�`�f�[�^ID�́A���[�U���I�[�T�����O�c�[�����AWB�R���e���c�ɑ΂��Ċ��蓖�Ă���ӂ�ID�ł��B<br>
 * �g�`�f�[�^ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExPlayer_SetWaveId
 */
typedef CriSint32 CriAtomExWaveId;

/*JP
 * \brief �U��ID
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �U��ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 */
typedef CriSint32 CriAtomExVibrationId;

/*JP
 * \brief �t�H�[�}�b�g���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̃t�H�[�}�b�g���w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_SetFormat �֐��ŗ��p���܂��B<br>
 * \sa criAtomExPlayer_SetFormat
 */
typedef CriAtomFormat CriAtomExFormat;
#define CRIATOMEX_FORMAT_NONE			(CRIATOM_FORMAT_NONE)			/*JP< �Ȃ�					*/
#define CRIATOMEX_FORMAT_ADX			(CRIATOM_FORMAT_ADX)			/*JP< ADX					*/
#define CRIATOMEX_FORMAT_HCA			(CRIATOM_FORMAT_HCA)			/*JP< HCA					*/
#define CRIATOMEX_FORMAT_HCA_MX			(CRIATOM_FORMAT_HCA_MX)			/*JP< HCA-MX				*/
#define CRIATOMEX_FORMAT_WAVE			(CRIATOM_FORMAT_WAVE)			/*JP< Wave					*/
#define CRIATOMEX_FORMAT_AIFF			(CRIATOM_FORMAT_AIFF)			/*JP< AIFF					*/
#define CRIATOMEX_FORMAT_RAW_PCM		(CRIATOM_FORMAT_RAW_PCM)		/*JP< RawPCM				*/
#define CRIATOMEX_FORMAT_VIBRATION		(CRIATOM_FORMAT_VIBRATION)		/*JP< �U��					*/
#define CRIATOMEX_FORMAT_AUDIO_BUFFER	(CRIATOM_FORMAT_AUDIO_BUFFER)	/*JP< �I�[�f�B�I�o�b�t�@�[	*/
#define CRIATOMEX_FORMAT_HW1			(CRIATOM_FORMAT_HW1)			/*JP< �n�[�h�E�F�A�ŗL1		*/
#define CRIATOMEX_FORMAT_HW2			(CRIATOM_FORMAT_HW2)			/*JP< �n�[�h�E�F�A�ŗL2		*/

/*JP
 * \brief �����f�[�^�t�H�[�}�b�g���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �����f�[�^�̃t�H�[�}�b�g���ł��B<br>
 * \par ���l:
 * ��������ɔz�u���ꂽ�����f�[�^�ɂ��ẮA ::criAtomEx_AnalyzeAudioHeader 
 * �֐������s���邱�Ƃŉ����f�[�^�̃t�H�[�}�b�g�����擾�\�ł��B<br>
 * �Đ����̉����f�[�^�̃t�H�[�}�b�g�ɂ��Ă�
 * ::criAtomExPlayback_GetFormatInfo �֐��Ŏ擾�\�ł��B<br>
 * \sa criAtomEx_AnalyzeAudioHeader, criAtomExPlayback_GetFormatInfo
 */
typedef struct CriAtomExFormatInfoTag {
	CriAtomExFormat format;				/*JP< �t�H�[�}�b�g���		*/
	CriSint32 sampling_rate;			/*JP< �T���v�����O���g��	*/
	CriSint64 num_samples;				/*JP< ���T���v����			*/
	CriSint64 loop_offset;				/*JP< ���[�v�J�n�T���v��	*/
	CriSint64 loop_length;				/*JP< ���[�v��ԃT���v����	*/
	CriSint32 num_channels;				/*JP< �`�����l����			*/
	CriUint32 reserved[1];				/*JP< �\��̈�				*/
} CriAtomExFormatInfo;

/*JP
 * \brief �|�[�Y�����Ώ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �|�[�Y����������Ώۂ��w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_Resume �֐��A����� ::criAtomExPlayback_Resume
 * �֐��̈����Ƃ��Ďg�p���܂��B
 * \sa criAtomExPlayer_Resume, criAtomExPlayback_Resume
 */
typedef enum CriAtomExResumeModeTag {
	CRIATOMEX_RESUME_ALL_PLAYBACK = 0,			/*JP< �ꎞ��~���@�Ɋ֌W�Ȃ��Đ����ĊJ					*/
	CRIATOMEX_RESUME_PAUSED_PLAYBACK = 1,		/*JP< Pause �֐��Ń|�[�Y�������������̂ݍĐ����ĊJ		*/
	CRIATOMEX_RESUME_PREPARED_PLAYBACK = 2,		/*JP< Prepare �֐��ōĐ��������w�����������̍Đ����J�n	*/
	CRIATOMEX_RESUME_MODE_RESERVED = 3,
	CRIATOMEX_RESUME_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExResumeMode;

/*JP
 * \brief �o�C�N�A�b�h�t�B���^�[�̃^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �o�C�N�A�b�h�t�B���^�[�̃^�C�v���w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_SetBiquadFilterParameters �֐��ŗ��p���܂��B
 * \sa criAtomExPlayer_SetBiquadFilterParameters
 */
typedef enum CriAtomExBiquadFilterTypeTag {
	CRIATOMEX_BIQUAD_FILTER_TYPE_OFF = 0,			/*JP<�t�B���^�[����			*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_LOWPASS = 1,		/*JP<���[�p�X�t�B���^�[		*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_HIGHPASS = 2,		/*JP<�n�C�p�X�t�B���^�[		*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_NOTCH = 3,			/*JP<�m�b�`�t�B���^�[			*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_LOWSHELF = 4,		/*JP<���[�V�F���t�t�B���^�[	*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_HIGHSHELF = 5,		/*JP<�n�C�V�F���t�t�B���^�[	*/
	CRIATOMEX_BIQUAD_FILTER_TYPE_PEAKING = 6,		/*JP<�s�[�L���O�t�t�B���^�[	*/

	/* enum size is 4bytes */
	CRIATOMEX_BIQUAD_FILTER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExBiquadFilterType;

/*JP
 * \brief �������������[�h
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �������������[�h���w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_SetSilentMode �֐��ŗ��p���܂��B<br>
 * �����ƂȂ������ǂ����́A�ȉ��̂����ꂩ���l��0�ɂȂ������ǂ����Ŕ��f���܂��B<br>
 * 	- �{�����[��
 * 	- 3D�p���j���O�̉��Z���ʂɂ��{�����[��
 * 	- 3D�|�W�V���j���O�̉��Z���ʂɂ��{�����[��
 * 	
 * \attention
 * �Z���h���x����2D�p���̐ݒ�l�ł͖����Ɣ��f����Ȃ��_�ɂ����ӂ��������B<br>
 * \sa criAtomExPlayer_SetSilentMode
 */
typedef enum CriAtomExSilentModeTag {
	/*JP
	 * \brief �������Ȃ�
	 * \par ����:
	 * �����ƂȂ��Ă����ʂȏ����͍s���܂���B�i�f�t�H���g�l�j
	 */
	CRIATOMEX_SILENT_MODE_NORMAL = 0,

	/*JP
	 * \brief ��~����
	 * \par ����:
	 * �����ƂȂ����ۂ͎����I�ɒ�~���܂��B
	 */
	CRIATOMEX_SILENT_MODE_STOP = 1,

	/*JP
	 * \brief �o�[�`����������
	 * \par ����:
	 * �����ƂȂ����ۂ͎����I�Ƀo�[�`���������܂��B
	 */
	CRIATOMEX_SILENT_MODE_VIRTUAL = 2,

	/*JP
	 * \brief �Ĕ����^�Ńo�[�`����������
	 * \par ����:
	 * �����ƂȂ����ۂ͎����I�ɍĔ����^�Ńo�[�`���������܂��B
	 */
	CRIATOMEX_SILENT_MODE_VIRTUAL_RETRIGGER = 3,

	/* enum size is 4bytes */
	CRIATOMEX_SILENT_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExSilentMode;

/*JP
 * \brief �p���^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �ǂ̂悤�ɂ��Ē�ʌv�Z���s�������w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_SetPanType �֐��ŗ��p���܂��B<br>
 * \sa criAtomExPlayer_SetPanType
 */
typedef enum CriAtomExPanTypeTag {
	/*JP
	 * \brief �s��
	 * \par ����:
	 * �p���^�C�v���������Ă��Ȃ���Ԃł��B
	 * ::criAtomExAcb_GetCueInfoByName �֐��ȂǂɂāA ACB Ver.1.35.00 ������
	 * ACB �f�[�^���̃L���[�̏��i ::CriAtomExCueInfo �j���擾�����ꍇ�ɓ����܂��B
	 * \attention
	 * ::criAtomExPlayer_SetPanType �֐��ɂĎw�肷��ƁA�G���[���������܂��B
	 */
	CRIATOMEX_PAN_TYPE_UNKNOWN = -1,
	/*JP
	 * \brief �p��3D
	 * \par ����:
	 * �p��3D�Œ�ʂ��v�Z���܂��B
	 */
	CRIATOMEX_PAN_TYPE_PAN3D = 0,
	/*JP
	 * \brief 3D�|�W�V���j���O
	 * \par ����:
	 * 3D�|�W�V���j���O�Œ�ʂ��v�Z���܂��B
	 */
	CRIATOMEX_PAN_TYPE_3D_POS,
	/*JP
	 * \brief ����
	 * \par ����:
	 * AtomEx�v���[���[��3D�����^3D���X�i�[���ݒ肳��Ă���ꍇ��3D�|�W�V���j���O�ŁA
	 * �ݒ肳��Ă��Ȃ��ꍇ�̓p��3D�ŁA���ꂼ���ʂ��v�Z���܂��B
	 */
	CRIATOMEX_PAN_TYPE_AUTO,
	/* enum size is 4bytes */
	CRIATOMEX_PAN_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPanType;

/*JP
 * \brief �p���j���O���̏o�̓X�s�[�J�[�^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ��ʌv�Z���s���ہA�o�͂Ƃ��Ăǂ̃X�s�[�J�[���g�p���邩��\���܂��B<br>
 * ::criAtomExPlayer_ChangeDefaultPanSpeakerType �֐��A::criAtomExPlayer_SetPanSpeakerType �֐��ŗ��p���܂��B<br>
 * \par ���l:
 * �X�e���I�X�s�[�J�[�̃v���b�g�t�H�[���ł́A�ǂ��I�񂾂Ƃ��Ă��ŏI�I�ɂ̓X�e���I�Ƀ_�E���~�b�N�X����܂��B
 * \sa criAtomExPlayer_SetPanSpeakerType
 */
typedef enum CriAtomExPanSpeakerTypeTag {
	/*JP
	 * \brief 4ch�p���j���O
	 * \par ����:
	 * L, R, Ls, Rs���g�p���ăp���j���O���s���܂��B<br>
	 * 
	 */
	CRIATOMEX_PAN_SPEAKER_TYPE_4CH = 0,

	/*JP
	 * \brief 5ch�p���j���O
	 * \par ����:
	 * L, R, C, Ls, Rs���g�p���ăp���j���O���s���܂��B
	 */
	CRIATOMEX_PAN_SPEAKER_TYPE_5CH = 1,

	/*JP
	 * \brief 6ch�p���j���O
	 * \par ����:
	 * L, R, Ls, Rs, Lsb, Rsb���g�p���ăp���j���O���s���܂��B
	 */
	CRIATOMEX_PAN_SPEAKER_TYPE_6CH = 2,

	/*JP
	 * \brief 7ch�p���j���O
	 * \par ����:
	 * L, R, C, Ls, Rs, Lsb, Rsb���g�p���ăp���j���O���s���܂��B
	 */
	CRIATOMEX_PAN_SPEAKER_TYPE_7CH = 3,

	/* enum size is 4bytes */
	CRIATOMEX_PAN_SPEAKER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPanSpeakerType;

/*JP
 * \brief �p���j���O���̊p�x�^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �}���`�`�����l���f�ނ̒�ʌv�Z���s���ہA�e���̓`�����l�����ǂ̂悤�Ȋp�x�Ƃ��Ĉ�������\���܂��B<br>
 * ::criAtomExPlayer_SetPanAngleType �֐��ŗ��p���܂��B<br>
 * \sa criAtomExPlayer_SetPanAngleType
 */
typedef enum CriAtomExPanAngleTypeTag {
	/*JP
	 * \brief �I�t�Z�b�g
	 * \par ����:
	 * �ݒ肳��Ă���p��3D�p�x�𒆐S�Ƃ��āA�X�s�[�J�[�̔z�u�����ɂ����I�t�Z�b�g�l���e�`�����l�����ɉ����āA
	 * ���ꂼ��̓��̓`�����l���ŌʂɃp���j���O�v�Z���s���܂��B<br>
	 * �Ⴆ�΃X�e���I�f�ނŃp��3D�p�x��0�x�Ɛݒ肵���ꍇ�AL�`�����l����-30�x�ƂȂ肻�̂܂�L�X�s�[�J�[����o�͂���A
	 * R�`�����l����+30�x�ƂȂ肻�̂܂�R�X�s�[�J�[����o�͂���܂��B
	 * �܂��p��3D�p�x��+30�x�Ɛݒ肵���ꍇ�AL�`�����l����0�x�AR�`�����l����60�x�̈ʒu�ɒ�ʂ��Ă�����̂Ƃ��āA
	 * �p���j���O�v�Z���s���܂��B
	 */
	CRIATOMEX_PAN_ANGLE_TYPE_OFFSET = 0,
	/*JP
	 * \brief �Œ�
	 * \par ����:
	 * ���̓`�����l�����ɉ����āA�e�`�����l�����Y���X�s�[�J�[�ʒu�ɌŒ肵�đ��݂��Ă�����̂Ƃ��āA
	 * �e�X�s�[�J�[�Ԃ̃o�����X���v�Z����悤�Ȍ`�Ńp���j���O�v�Z���s���܂��B<br>
	 * �Ⴆ�΃X�e���I�f�ނŃp��3D�p�x��0�x�Ɛݒ肵���ꍇ�AL�`�����l����L�X�s�[�J�[�����0.7�{�ŏo�͂���A
	 * R�`�����l���̓X�s�[�J�[�����0.7�{�ŏo�͂���܂��B
	 * �܂��p��3D�p�x��+30�x�Ɛݒ肵���ꍇ�AL�`�����l���͂܂������o�͂��ꂸ�AR�`�����l����R�X�s�[�J�[���炻�̂܂܏o�͂���܂��B<br>
	 * \par ���l:
	 * ���̋�����CRI Audio�̍��̃p��3D�Ɠ����ł��B<br>
	 * �ǂ̃X�s�[�J�[�ɂǂ̃`�����l�������蓖�Ă邩�́A::criAtomExPlayer_SetDrySendLevel �֐��Őݒ肷��h���C�Z���h���x���ł̈����Ɠ��l�ł��B
	 * \sa criAtomExPlayer_SetDrySendLevel
	 */
	CRIATOMEX_PAN_ANGLE_TYPE_FIX = 1,
	/*JP
	 * \brief �����~�b�N�X
	 * \par ����:
	 * ����ȃp���p�x�^�C�v�ł��B�g�p���Ȃ��ł��������B
	 */
	CRIATOMEX_PAN_ANGLE_TYPE_AMBIENCE_MIX = 4,
	/*JP
	 * \brief �����������
	 * \par ����:
	 * ����ȃp���p�x�^�C�v�ł��B�g�p���Ȃ��ł��������B
	 */
	CRIATOMEX_PAN_ANGLE_TYPE_AMBIENCE_STRAIGHT = 5,

	/* enum size is 4bytes */
	CRIATOMEX_PAN_ANGLE_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPanAngleType;

/*JP
 * \brief �o�̓X�s�[�J�[�̕��я�
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �e�`�����l���̓Y���Əo�̓X�s�[�J�[�̑Ή��֌W��\���܂��B<br>
 * ::criAtomEx_SetSpeakerAngleArray �֐��ŗ��p���܂��B<br>
 * \sa criAtomEx_SetSpeakerAngleArray CRIATOMEX_SPEAKER_SYSTEM_SURROUND_5_1 CRIATOMEX_SPEAKER_SYSTEM_SURROUND_7_1
 */
typedef CriUint32 CriAtomExSpeakerSystem;

/*JP
 * \brief 5.1ch�T���E���h
 * \par ����:
 * �o�̓X�s�[�J�[�̕��я��͈ȉ��̂Ƃ���ł��B
 * \par
 *	-# FRONT LEFT
 *	-# FRONT RIGHT
 *	-# FRONT CENTER
 *	-# LOW FREQUENCY
 *	-# SURROUND LEFT
 *	-# SURROUND RIGHT
 * 	
 * \sa CriAtomExSpeakerSystem
 */
#define CRIATOMEX_SPEAKER_SYSTEM_SURROUND_5_1 (0)

/*JP
 * \brief 7.1ch�T���E���h
 * \par ����:
 * �o�̓X�s�[�J�[�̕��я��͈ȉ��̂Ƃ���ł��B
 * \par
 *	-# FRONT LEFT
 *	-# FRONT RIGHT
 *	-# FRONT CENTER
 *	-# LOW FREQUENCY
 *	-# SURROUND LEFT
 *	-# SURROUND RIGHT
 *	-# SURROUND BACK LEFT
 *	-# SURROUND BACK RIGHT
 * 	
 * \sa CriAtomExSpeakerSystem
 */
#define CRIATOMEX_SPEAKER_SYSTEM_SURROUND_7_1 (1)

/*JP
 * \brief �u���b�N�C���f�b�N�X
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �u���b�N�C���f�b�N�X�́A�u���b�N�V�[�P���X���̃u���b�N�̃I�t�Z�b�g�������ԍ��ł��B<br>
 * �i�擪�̃u���b�N��0�ԁA���̎��̃u���b�N��1�ԁc�Ƃ����ӂ��ɁA�u���b�N��
 * ���ԂɊ��蓖�Ă���ԍ��ł��B�j<br>
 * �u���b�N�C���f�b�N�X���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExPlayer_SetFirstBlockIndex, criAtomExPlayback_SetNextBlockIndex, criAtomExPlayback_GetCurrentBlockIndex
 */
typedef CriSint32 CriAtomExBlockIndex;

/*JP
 * \brief �Q�[���ϐ�ID
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �Q�[���ϐ�ID�́A���[�U���I�[�T�����O�c�[����� ACF ���̃Q�[���ϐ��ɑ΂��Ċ��蓖�Ă�ID�ł��B<br>
 * �Q�[���ϐ�ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomEx_GetGameVariableById, criAtomEx_SetGameVariableById
 */
typedef CriUint32 CriAtomExGameVariableId;

/*JP
 * \brief �Q�[���ϐ����擾�p�\����
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �Q�[���ϐ������擾���邽�߂̍\���̂ł��B<br>
 * ::CriAtomExGameVariableInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomEx_GetGameVariableInfo
 */
typedef struct CriAtomExGameVariableInfoTag {
	const CriChar8* name;		/*JP< �Q�[���ϐ���	*/
	CriAtomExGameVariableId id;	/*JP< �Q�[���ϐ�ID	*/
	CriFloat32 value;			/*JP< �Q�[���ϐ��l	*/
} CriAtomExGameVariableInfo;

/*JP
 * \brief �X�g���[�~���O���
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ::criAtomEx_GetStreamingInfo �֐��Ŏ擾�������_�ł̃X�g���[�~���O�̏󋵂ł��B<br>
 * \sa criAtomEx_GetStreamingInfo
 */
typedef CriAtomStreamingInfo CriAtomExStreamingInfo;

/*JP
 * \brief �����R�[�h
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �����R�[�h�i���������������j��\���܂��B
 */
typedef enum CriAtomExCharacterEncodingTag {
	CRIATOMEX_CHARACTER_ENCODING_UTF8 = 0,	/*JP< UTF-8		*/
	CRIATOMEX_CHARACTER_ENCODING_SJIS = 1,	/*JP< Shift_JIS	*/
	
	/* enum size is 4bytes */
	CRIATOMEX_CHARACTER_ENCODING_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExCharacterEncoding;

/*JP
 * \brief �e�탊�\�[�X�̎g�p��
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �e�탊�\�[�X�̎g�p�󋵂�\�킷�\���̂ł��B
 */
typedef struct CriAtomExResourceUsageTag {
	CriUint32 use_count;	/*JP< �Ώۃ��\�[�X�̌��݂̎g�p��	*/
	CriUint32 limit;		/*JP< �Ώۃ��\�[�X�̐�����			*/
} CriAtomExResourceUsage;

/*==========================================================================
 *      CRI AtomEx Debug API
 *=========================================================================*/
/*JP
 * \brief CriAtomEx �����̊e�탊�\�[�X�̏�
 * \ingroup ATOMEXLIB_GLOBAL_DEBUG
 * \par ����:
 * CriAtomEx �����̊e�탊�\�[�X�̏󋵂�\���\���̂ł��B<br>
 * ::criAtomExDebug_GetResourcesInfo ���g�p���Ď擾���Ă��������B<br>
 * \attention
 * �J���x���f�o�b�O�@�\�ł��B�A�v���P�[�V�����J�����ɂ̂ݎg�p���Ă��������B
 * \sa criAtomExDebug_GetResourcesInfo
 */
typedef struct CriAtomExDebugResourcesInfoTag {
	/*JP �o�[�`�����{�C�X�̎g�p�󋵁ilimit �̓��C�u�������������Ɏw�肵�� CriAtomExConfig::max_virtual_voices �̐��j */
	CriAtomExResourceUsage virtual_voice_usage;
	/*JP �V�[�P���X�̎g�p�󋵁ilimit �̓��C�u�������������Ɏw�肵�� CriAtomExConfig::max_sequences �̐��j */
	CriAtomExResourceUsage sequence_usage;
	/*JP �V�[�P���X�g���b�N�̎g�p�󋵁ilimit �̓��C�u�������������Ɏw�肵�� CriAtomExConfig::max_tracks �̐��j */
	CriAtomExResourceUsage sequence_track_usage;
	/*JP �V�[�P���X�g���b�N�A�C�e���̎g�p�󋵁ilimit �̓��C�u�������������Ɏw�肵�� CriAtomExConfig::max_track_items �̐��j */
	CriAtomExResourceUsage sequence_track_item_usage;
} CriAtomExDebugResourcesInfo;

/*==========================================================================
 *      CRI AtomEx HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_HCA_MX
 * HCA-MX�̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExHcaMx_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomExHcaMx_SetDefaultConfig �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomExHcaMx_Initialize �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExHcaMx_SetDefaultConfig 
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExHcaMx_Initialize, criAtomExHcaMx_SetDefaultConfig
 */
typedef struct CriAtomExHcaMxConfigTag {
	/*JP
		\brief �T�[�o�[�����̎��s�p�x
		\par ����:
		�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		\attention
		Atom���C�u�������������Ɏw�肵���l�i ::CriAtomExConfig �\���̂�
		server_frequency �j�ƁA�����l���Z�b�g����K�v������܂��B<br>
		\sa CriAtomExConfig
	*/
	CriFloat32 server_frequency;
	
	/*JP
		\brief �~�L�T��
		\par ����:
		HCA-MX�f�R�[�h���ʂ𑗐M����~�L�T�̐����w�肵�܂��B<br>
		�~�L�T�𕡐��쐬���邱�ƂŁA
		�~�L�T���ƂɈقȂ�DSP�o�X��DSP FX��K�p���邱�Ƃ��\�ɂȂ�܂��B<br>
		\attention
		HCA-MX�̃f�R�[�h�����A����ђ���Ԃ̏������ׂ́A
		�~�L�T�̐��ɔ�Ⴕ�ďd���Ȃ�܂��B<br>
		<br>
		�{�p�����[�^�[��0�ɐݒ肵���ꍇ�ł��A�~�L�T�� 1 �����쐬����܂��B<br>
		�i���o�[�W�����Ƃ̌݊����ێ��̂��߁B�j<br>
		HCA-MX���g�p���Ȃ��ꍇ�ɂ́A�{�p�����[�^�[�� max_voices �̗����� 0 
		�ɐݒ肵�Ă��������B<br>
	*/
	CriSint32 num_mixers;
	
	/*JP
		\brief �~�L�T�ɓo�^�\�ȍő�{�C�X��
		\par ����:
		�~�L�T���Ƃɓo�^�\��HCA-MX�{�C�X�̐����w�肵�܂��B<br>
		HCA-MX�{�C�X�v�[�����쐬����ۂɂ́A�{�C�X�̑�����
		num_mixers �~ max_voices �𒴂��Ȃ��悤�����ӂ��������B
	*/
	CriSint32 max_voices;
	
	/*JP
		\brief ���̓f�[�^�̍ő�`�����l����
		\par ����:
		�A�v���P�[�V�������ōĐ�����HCA-MX�f�[�^�̍ő�`�����l�������w�肵�܂��B<br>
		�Đ�����f�[�^�����m�����̏ꍇ��1���A�X�e���I�̏ꍇ��2���w�肵�Ă��������B<br>
		\par ���l:
		HCA-MX���������� max_input_channels �Ɏw�肳�ꂽ���ȉ��̉����f�[�^��
		�Đ��\�ɂȂ�܂��B<br>
		�Ⴆ�΁A max_input_channels ��6���w�肵���ꍇ�A5.1ch���������łȂ��A
		���m����������X�e���I�������Đ��\�ɂȂ�܂��B<br>
		100�̃f�[�^�̂����A99�����m�����A1���X�e���I�̏ꍇ�ł��A
		max_input_channels �ɂ�2���w�肷��K�v������܂��B<br>
	*/
	CriSint32 max_input_channels;
	
	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		HCA-MX�̏o�͂Ɏw��ł���ő�T���v�����O���[�g�ł��B<br>
		�~�L�T�̍ŏI�o�͂Ńs�b�`��ύX����ꍇ�ɐݒ肵�܂��B<br>
		�~�L�T�̍ŏI�o�͂Ńs�b�`��ύX���Ȃ��ꍇ�́Aoutput_sampling_rate�Ɠ����l��ݒ肵�Ă��������B<br>
		\par ���l:
		�Ⴆ��HCA-MX�Đ�����::criAtomExHcaMx_SetFrequencyRatio �֐��� 2.0f ���w�肵�ăs�b�`���グ��ꍇ�́A
		output_sampling_rate * 2 ���w�肵��HCA-MX�����������Ă��������B<br>
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �o�̓`�����l����
		\par ����:
		HCA-MX�f�[�^�̏o�̓`�����l�������w�肵�܂��B<br>
		�ʏ�A�^�[�Q�b�g�@�ɐڑ����ꂽ�X�s�[�J�[�̐��i�o�̓f�o�C�X��
		�ő�`�����l�����j���w�肵�܂��B<br>
		\par ���l:
		���m���������݂̂��Đ����A�p�����R���g���[�����Ȃ��ꍇ�ɂ́A
		output_channels ��1�ɂ��邱�ƂŁA�������ׂ������邱�Ƃ��\�ł��B<br>
		\attention
		output_channels �̐��� max_input_channels �ȉ��̒l�ɐݒ肷�邱�Ƃ�
		�ł��܂���B<br>
	*/
	CriSint32 output_channels;
	
	/*JP
		\brief �o�̓T���v�����O���[�g
		\par ����:
		�Đ�����HCA-MX�f�[�^�̃T���v�����O���[�g���w�肵�܂��B<br>
		HCA-MX�f�[�^���쐬����ۂɂ́A�K���S�Ẳ����f�[�^�𓯈�̃T���v�����O
		���[�g�ō쐬���A���̒l�� output_sampling_rate �Ɏw�肵�Ă��������B<br>
		\par ���l:
		HCA-MX�́A���P�ʂ̃T���v�����O���[�g�ύX���s���܂���B<br>
	*/
	CriSint32 output_sampling_rate;
	
	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		HCA-MX�̏o�͐�T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;
} CriAtomExHcaMxConfig;

/*==========================================================================
 *      CRI AtomEx ACF API
 *=========================================================================*/
/*JP
 * \brief ACF���
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * ACF�f�[�^�̏ڍ׏��ł��B<br>
 * \sa criAtomExAcf_GetAcfInfo, criAtomExAcf_GetAcfInfoFromAcfData
 */
typedef struct CriAtomExAcfInfoTag {
	const CriChar8* name;							/*JP< ���O						*/
	CriUint32 size;									/*JP< �T�C�Y					*/
	CriUint32 version;								/*JP< ACB�o�[�W����				*/
	CriAtomExCharacterEncoding character_encoding;	/*JP< �����R�[�h				*/
	CriSint32 num_dsp_settings;						/*JP< DSP�ݒ萔					*/
	CriSint32 num_categories;						/*JP< �J�e�S����				*/
	CriSint32 num_categories_per_playback;			/*JP< �Đ����J�e�S���Q�Ɛ�		*/
	CriSint32 num_reacts;							/*JP< REACT��					*/
	CriSint32 num_aisac_controls;					/*JP< AISAC�R���g���[����		*/
	CriSint32 num_global_aisacs;					/*JP< �O���[�o��AISAC��			*/
	CriSint32 num_game_variables;					/*JP< �Q�[���ϐ���				*/
	CriSint32 max_buses_of_dsp_bus_settings;		/*JP< DSP�ݒ���ő�o�X��		*/
	CriSint32 num_buses;							/*JP< �o�X��					*/
	CriSint32 num_voice_limit_groups;				/*JP< �{�C�X���~�b�g�O���[�v��	*/
} CriAtomExAcfInfo;

/*JP
 * \brief AISAC�R���g���[��ID
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * AISAC�R���g���[��ID�́AAISAC�R���g���[���ɑ΂��Ċ��蓖�Ă��Ă����ӂ�ID�ł��B<br>
 * AISAC�R���g���[��ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExPlayer_SetAisacControlById, criAtomExAcf_GetAisacControlIdByName, criAtomExAcf_GetAisacControlNameById
 */
typedef CriUint32 CriAtomExAisacControlId;

/*JP
 * \brief AISAC�R���g���[�����擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * AISAC�R���g���[�������擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetAisacControlInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetAisacControlInfo
 */
typedef struct CriAtomExAisacControlInfoTag {
	const CriChar8*			name;		/*JP< AISAC�R���g���[����	*/
	CriAtomExAisacControlId	id;			/*JP< AISAC�R���g���[��ID	*/
} CriAtomExAisacControlInfo;

/*JP
 * \brief AISAC���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * AISAC�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExPlayer_GetAttachedAisacInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExPlayer_GetAttachedAisacInfo
 */
typedef struct CriAtomExAisacInfoTag {
	const CriChar8* name;		/*JP< AISAC��	*/
	CriBool default_control_flag;		/*JP< �f�t�H���g�R���g���[���l���ݒ肳��Ă��邩	*/
	CriFloat32 default_control_value;	/*JP< �f�t�H���gAISAC�R���g���[���l	*/
	CriAtomExAisacControlId control_id;			/*JP< Control Id	*/
	const CriChar8* control_name;	/*JP< Control Name	*/
} CriAtomExAisacInfo;

/*JP
 * \brief DSP�o�X�ݒ�̏��擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�ݒ�̏����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetDspSettingInformation �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetDspSettingInformation
 */
typedef struct CriAtomExAcfDspSettingInfoTag {
	const CriChar8* name;									/*JP< �Z�b�e�B���O��			*/
	CriUint16 bus_indexes[CRIATOMEXACF_MAX_BUSES];			/*JP< DSP�o�X�C���f�b�N�X�z��	*/
	CriUint16 extend_bus_indexes[CRIATOMEXACF_MAX_BUSES];	/*JP< DSP�g���o�X�C���f�b�N�X�z��	*/
	CriUint16 snapshot_start_index;							/*JP< �X�i�b�v�V���b�g�J�n�C���f�b�N�X	*/
	CriUint8 num_buses;										/*JP< �L��DSP�o�X��				*/
	CriUint8 num_extend_buses;								/*JP< �L���g��DSP�o�X��				*/
	CriUint16 num_snapshots;								/*JP< �X�i�b�v�V���b�g��				*/
	CriUint16 snapshot_work_size;							/*JP< �X�i�b�v�V���b�g�p���[�N�̈�T�C�Y	*/
	CriUint16 num_mixer_aisacs;								/*JP< �~�L�T�[AISAC��	*/
	CriUint16 mixer_aisac_start_index;						/*JP< �~�L�T�[AISAC�J�n�C���f�b�N�X	*/
} CriAtomExAcfDspSettingInfo;

/*JP
 * \brief DSP�o�X�ݒ�X�i�b�v�V���b�g�̏��擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�ݒ�̃X�i�b�v�V���b�g�����擾���邽�߂̍\���̂ł��B<br>
 */
typedef struct CriAtomExAcfDspSettingSnapshotInfoTag {
	const CriChar8* name;									/*JP< �X�i�b�v�V���b�g��			*/
	CriUint8 num_buses;										/*JP< �L��DSP�o�X��					*/
	CriUint8 num_extend_buses;								/*JP< �L���g��DSP�o�X��				*/
	CriUint8 reserved[2];									/*JP< �\��̈�						*/
	CriUint16 bus_indexes[CRIATOMEXACF_MAX_BUSES];			/*JP< DSP�o�X�C���f�b�N�X�z��		*/
	CriUint16 extend_bus_indexes[CRIATOMEXACF_MAX_BUSES];	/*JP< DSP�g���o�X�C���f�b�N�X�z��	*/
} CriAtomExAcfDspSettingSnapshotInfo;

/*JP
 * \brief DSP�o�X�ݒ���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�ݒ�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetDspBusInformation �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetDspBusInformation
 */
typedef struct CriAtomExAcfDspBusInfoTag {
	const CriChar8* name;								/*JP< ���O							*/
	CriFloat32 volume;									/*JP< ����							*/
	CriFloat32 pan3d_volume;							/*JP< Pan3D ����					*/
	CriFloat32 pan3d_angle;								/*JP< Pan3D �p�x					*/
	CriFloat32 pan3d_distance;							/*JP< Pan3D �C���e���A����			*/
	CriFloat32 pan3d_spread;							/*JP< Pan3D �X�v���b�h				*/
	CriUint16 fx_indexes[CRIATOMEXACF_MAX_FXES];		/*JP< DSP FX�C���f�b�N�X�z��		*/
	CriUint16 bus_link_indexes[CRIATOMEXACF_MAX_BUSES];	/*JP< DSP�o�X�����N�C���f�b�N�X�z��	*/
	CriUint16 bus_no;									/*JP< �Z�b�e�B���O��DSP�o�X�ԍ�		*/
	CriUint8 num_fxes;									/*JP< DSP FX��						*/
	CriUint8 num_bus_links;								/*JP< DSP�o�X�����N��				*/
} CriAtomExAcfDspBusInfo;

/*JP
 * \brief DSP�o�X�����N�^�C�v
 * \ingroup ATOMEXLIB_ACF
 * \sa CriAtomExAcfDspBusLinkInfo
 */
typedef enum CriAtomExAcfDspBusLinkTypeTag {
	CRIATOMEXACF_DSP_BUS_LINK_TYPE_PRE_VOLUME,		/*JP< �v���{�����[���^�C�v		*/
	CRIATOMEXACF_DSP_BUS_LINK_TYPE_POST_VOLUME,		/*JP< �|�X�g�{�����[���^�C�v	*/
	CRIATOMEXACF_DSP_BUS_LINK_TYPE_POST_PAN,		/*JP< �|�X�g�p���^�C�v			*/
	/* enum size is 4bytes */
	CRIATOMEXACF_DSP_BUS_LINK_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAcfDspBusLinkType;

/*JP
 * \brief DSP�o�X�����N���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * DSP�o�X�����N�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetDspBusLinkInformation �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetDspBusLinkInformation
 */
typedef struct CriAtomExAcfDspBusLinkInfoTag {
	CriAtomExAcfDspBusLinkType type;	/*JP< �^�C�v							*/
	CriFloat32 send_level;				/*JP< �Z���h���x��						*/
	CriUint16 bus_no;					/*JP< �����̃Z�b�e�B���O��DSP�o�X�ԍ�	*/
	CriUint16 bus_id;					/*JP< �����̃Z�b�e�B���O��DSP�o�XID	*/
} CriAtomExAcfDspBusLinkInfo;

/*JP
 * \brief Aisac�^�C�v
 * \ingroup ATOMEXLIB_ACF
 * \sa CriAtomExGlobalAisacInfo
 */
typedef enum CriAtomExAcfAisacTypeTag {
	CRIATOMEXACF_AISAC_TYPE_NORMAL,				/*JP< �m�[�}���^�C�v				*/
	CRIATOMEXACF_AISAC_TYPE_AUTO_MODULATION,	/*JP< �I�[�g���W�����[�V�����^�C�v	*/
	/* enum size is 4bytes */
	CRIATOMEXACF_AISAC_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAcfAisacType;


/*JP
 * \brief Global Aisac���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * Global Aisac�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetGlobalAisacInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * type��::CRIATOMEXACF_AISAC_TYPE_AUTO_MODULATION �̏ꍇ�A
 * control_id�͓����I�Ɏg�p�����C���f�b�N�X�l�ƂȂ�܂��B
 * \sa criAtomExAcf_GetGlobalAisacInfo
 */
typedef struct CriAtomExGlobalAisacInfoTag {
	const CriChar8* name;				/*JP< Global Aisac��	*/
	CriUint16 index;					/*JP< �f�[�^�C���f�b�N�X*/
	CriUint16 num_graphs;				/*JP< �O���t��			*/
	CriAtomExAcfAisacType type;			/*JP< Aisac�^�C�v		*/
	CriFloat32 random_range;			/*JP< �����_�������W	*/
	CriUint16 control_id;				/*JP< Control Id		*/
	CriUint16 dummy;					/*JP< ���g�p			*/
} CriAtomExGlobalAisacInfo;

/* Aisac�O���t�^�C�v */
/*JP
 * \brief Aisac�O���t�^�C�v
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * Aisac�O���t�̃^�C�v�ł��B<br>
 * \sa CriAtomExAisacGraphInfo
 */
typedef enum CriAtomExAisacGraphTypeTag {
	CRIATOMEX_AISAC_GRAPH_TYPE_NON = 0,					/*JP< ���g�p	 */
	CRIATOMEX_AISAC_GRAPH_TYPE_VOLUME,					/*JP< �{�����[�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PITCH,					/*JP< �s�b�` */
	CRIATOMEX_AISAC_GRAPH_TYPE_BANDPASS_HI,				/*JP< �o���h�p�X�t�B���^�[�̍���J�b�g�I�t���g�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_BANDPASS_LOW,			/*JP< �o���h�p�X�t�B���^�[�̒��J�b�g�I�t���g�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_BIQUAD_FREQ,				/*JP< �o�C�N�A�b�h�t�B���^�[�̎��g�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_BIQUAD_Q,				/*JP< �o�C�N�A�b�h�t�B���^�[��Q�l */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_0_SEND,				/*JP< �o�X�Z���h���x��0 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_1_SEND,				/*JP< �o�X�Z���h���x��1 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_2_SEND,				/*JP< �o�X�Z���h���x��2 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_3_SEND,				/*JP< �o�X�Z���h���x��3 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_4_SEND,				/*JP< �o�X�Z���h���x��4 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_5_SEND,				/*JP< �o�X�Z���h���x��5 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_6_SEND,				/*JP< �o�X�Z���h���x��6 */
	CRIATOMEX_AISAC_GRAPH_TYPE_BUS_7_SEND,				/*JP< �o�X�Z���h���x��7 */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_ANGLE,				/*JP< �p���j���O3D�p�x */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_VOLUME,			/*JP< �p���j���O3D�{�����[�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_INTERIOR_DISTANCE,	/*JP< �p���j���O3D���� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_CENTER,			/*JP< ACB Ver.0.11.00�ȍ~�ł͎g�p���Ȃ� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_LFE,				/*JP< ACB Ver.0.11.00�ȍ~�ł͎g�p���Ȃ� */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_0,					/*JP< AISAC�R���g���[��ID 0 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_1,					/*JP< AISAC�R���g���[��ID 1 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_2,					/*JP< AISAC�R���g���[��ID 2 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_3,					/*JP< AISAC�R���g���[��ID 3 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_4,					/*JP< AISAC�R���g���[��ID 4 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_5,					/*JP< AISAC�R���g���[��ID 5 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_6,					/*JP< AISAC�R���g���[��ID 6 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_7,					/*JP< AISAC�R���g���[��ID 7 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_8,					/*JP< AISAC�R���g���[��ID 8 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_9,					/*JP< AISAC�R���g���[��ID 9 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_10,				/*JP< AISAC�R���g���[��ID 10 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_11,				/*JP< AISAC�R���g���[��ID 11 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_12,				/*JP< AISAC�R���g���[��ID 12 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_13,				/*JP< AISAC�R���g���[��ID 13 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_14,				/*JP< AISAC�R���g���[��ID 14 */
	CRIATOMEX_AISAC_GRAPH_TYPE_AISAC_15,				/*JP< AISAC�R���g���[��ID 15 */
	CRIATOMEX_AISAC_GRAPH_TYPE_PRIORITY,				/*JP< �{�C�X�v���C�I���e�B */
	CRIATOMEX_AISAC_GRAPH_TYPE_PRE_DELAY_TIME,			/*JP< �v���f�B���C */
	CRIATOMEX_AISAC_GRAPH_TYPE_BIQUAD_GAIN,				/*JP< �o�C�N�A�b�h�t�B���^�[�̃Q�C�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_MIXDOWN_CENTER,	/*JP< �p���j���O3D �Z���^�[���x�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN3D_MIXDOWN_LFE,		/*JP< �p���j���O3D LFE���x�� */
	CRIATOMEX_AISAC_GRAPH_TYPE_EG_ATTACK,				/*JP< �G���x���[�v �A�^�b�N */
	CRIATOMEX_AISAC_GRAPH_TYPE_EG_RELEASE,				/*JP< �G���x���[�v �����[�X */
	CRIATOMEX_AISAC_GRAPH_TYPE_PLAYBACK_RATIO,			/*JP< �V�[�P���X�Đ����V�I */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_L,				/*JP< L ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_R,				/*JP< R ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_CENTER,			/*JP< Center ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_LFE,			/*JP< LFE ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_SL,				/*JP< Surround L ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_SR,				/*JP< Surround R ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_EX1,			/*JP< Ex1 ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_DRY_SEND_EX2,			/*JP< Ex2 ch�h���C�Z���h */
	CRIATOMEX_AISAC_GRAPH_TYPE_PAN_SPREAD,				/*JP< �p���X�v���b�h */

	/* enum size is 4bytes */
	CRIATOMEX_AISAC_GRAPH_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAisacGraphType;

/*JP
 * \brief Aisac Graph���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * Global Aisac Graph�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetGlobalAisacGraphInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetGlobalAisacGraphInfo
 */
typedef struct CriAtomExAisacGraphInfoTag {
	CriAtomExAisacGraphType type;		/*JP< Graph�^�C�v		*/
} CriAtomExAisacGraphInfo;

/*JP
 * \brief �Z���N�^�[���擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * �Z���N�^�[�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetSelectorInfoByIndex �֐��܂��� ::criAtomExAcf_GetSelectorInfoByName �֐���
 * �����Ƃ��ēn���܂��B<br>
 * \attention
 * \sa criAtomExAcf_GetSelectorInfoByIndex, criAtomExAcf_GetSelectorInfoByName
 */
typedef struct CriAtomExSelectorInfoTag {
	const CriChar8* name;				/*JP< �Z���N�^�[��		*/
	CriUint16 index;					/*JP< �f�[�^�C���f�b�N�X*/
	CriUint16 num_labels;				/*JP< ���x����			*/
	CriUint16 global_label_index;		/*JP< �O���[�o���Q�ƃ��x���C���f�b�N�X	*/
} CriAtomExSelectorInfo;

/*JP
 * \brief �Z���N�^�[���x�����擾�p�\����
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * �Z���N�^�[���x�������擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetSelectorLabelInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetSelectorLabelInfo
 */
typedef struct CriAtomExSelectorLabelInfoTag {
	const CriChar8* selector_name;			/*JP< �Z���N�^�[��					*/
	const CriChar8* label_name;				/*JP< �Z���N�^�[���x����				*/
} CriAtomExSelectorLabelInfo;

/*JP
 * \brief �~�L�T�[Aisac�O���t�^�C�v
 * \ingroup ATOMEXLIB_ACF
 * \par ����:
 * �~�L�T�[Aisac�O���t�̃^�C�v�ł��B<br>
 */
typedef enum CriAtomExMixerAisacGraphTypeTag {
	CRIATOMEX_MIXER_AISAC_GRAPH_TYPE_VOLUME = 0,		/*JP< �{�����[�� */
	CRIATOMEX_MIXER_AISAC_GRAPH_TYPE_PAN3D_ANGLE,		/*JP< �p���j���O3D�p�x */
	CRIATOMEX_MIXER_AISAC_GRAPH_TYPE_BUS_SEND_LEVEL,	/*JP< �o�X�Z���h���x�� */
	CRIATOMEX_MIXER_AISAC_GRAPH_TYPE_PAN_SPREAD,		/*JP< �p���X�v���b�h */

	/* enum size is 4bytes */
	CRIATOMEX_MIXER_AISAC_GRAPH_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExMixerAisacGraphType;
/*==========================================================================
 *      CRI AtomEx Category API
 *=========================================================================*/
/*JP
 * \brief �J�e�S��ID
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * �J�e�S��ID�́A���[�U���I�[�T�����O�c�[����ŃJ�e�S���ɑ΂��Ċ��蓖�Ă���ӂ�ID�ł��B<br>
 * �J�e�S��ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExCategory_SetVolumeById, criAtomExCategory_MuteById, criAtomExCategory_SoloById
 */
typedef CriUint32 CriAtomExCategoryId;

/*JP
 * \brief �ő�Đ����J�e�S���Q�Ɛ�
 * \ingroup ATOMEXLIB_CATEGORY
 * �Đ����̍ő�J�e�S���Q�Ɛ��ł��B<br>
 * \sa CriAtomExCueInfo
 */
#define CRIATOMEXCATEGORY_MAX_CATEGORIES_PER_PLAYBACK	(16)

/*JP
 * \brief �J�e�S�����擾�p�\����
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * �J�e�S�������擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAcf_GetCategoryInfo �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExAcf_GetCategoryInfo
 */
typedef struct CriAtomExCategoryInfoTag {
	CriUint32 group_no;			/*JP< �O���[�v�ԍ�		*/
	CriUint32 id;				/*JP< �J�e�S��ID		*/
	const CriChar8* name;		/*JP< �J�e�S����		*/
	CriUint32 num_cue_limits;	/*JP< �L���[���~�b�g��	*/
	CriFloat32 volume;			/*JP< �{�����[��		*/
} CriAtomExCategoryInfo;

/*JP
 * \brief REACT�^�C�v
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�̃^�C�v�ł��B<br>
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef enum CriAtomExReactTypeTag {
	CRIATOMEX_REACT_TYPE_DUCKER = 0,					/*JP< �_�b�J�[						*/
	CRIATOMEX_REACT_TYPE_AISAC_MODULATION_TRIGGER,		/*JP< AISAC���W�����[�V�����g���K�[	*/

	/* enum size is 4bytes */
	CRIATOMEX_REACT_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExReactType;

/*JP
 * \brief REACT�ɂ��_�b�L���O�̃^�[�Q�b�g
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�ɂ��_�b�L���O�Ώۂ̃^�C�v�ł��B
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef enum CriAtomExReactDuckerTargetTypeTag {
	CRIATOMEX_REACT_DUCKER_TARGET_TYPE_VOLUME = 0,					/*JP< �{�����[���̃_�b�J�[				*/
	CRIATOMEX_REACT_DUCKER_TARGET_TYPE_AISAC_CONTROL_VALUE,			/*JP< AISAC�R���g���[���l�̃_�b�J�[	*/

	/* enum size is 4bytes */
	CRIATOMEX_REACT_DUCKER_TARGET_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExReactDuckerTargetType;

/*JP
 * \brief REACT�ɂ��_�b�L���O�̋Ȑ��^�C�v
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�ɂ��_�b�L���O�Ȑ��̃^�C�v�ł��B
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef enum CriAtomExReactDuckerCurveTypeTag {
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_LINEAR = 0,		/*JP< ����		*/
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_SQUARE,			/*JP< �ᑬ�ω�	*/
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_SQUARE_REVERSE,	/*JP< �����ω�	*/
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_S,				/*JP< S���Ȑ�	*/
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_FLAT_AT_HALF,		/*JP< �tS���Ȑ�	*/

	/* enum size is 4bytes */
	CRIATOMEX_REACT_DUCKER_CURVE_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExReactDuckerCurveType;

/*JP
 * \brief REACT�t�F�[�h�p�����[�^�[�\����
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�̃t�F�[�h�쓮�p�����[�^�[����ݒ�擾���邽�߂̍\���̂ł��B<br>
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef struct CriAtomExReactFadeParameterTag {
	CriAtomExReactDuckerCurveType	curve_type;			/*JP< �ω��Ȑ��^�C�v					*/
	CriFloat32						curve_strength;		/*JP< �ω��Ȑ��̋����i0.0f �` 2.0f�j	*/
	CriUint16						fade_time_ms;		/*JP< �t�F�[�h���ԁi�~���b�j			*/
} CriAtomExReactFadeParameter;

/*JP
 * \brief REACT�z�[���h�^�C�v
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�z�[���h�i�������Ԃ̈ێ��j�^�C�v�ł��B<br>
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef enum CriAtomExReactHoldTypeTag {
	CRIATOMEX_REACT_HOLD_TYPE_WHILE_PLAYING,		/*JP< �Đ����Ƀz�[���h���s��		*/
	CRIATOMEX_REACT_HOLD_TYPE_FIXED_TIME,			/*JP< �Œ莞�ԂŃz�[���h���s��		*/

	/* enum size is 4bytes */
	CRIATOMEX_REACT_HOLD_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExReactHoldType;

/*JP
 * \brief REACT�ɂ��_�b�J�[�p�����[�^�[�\����
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�ɂ��_�b�J�[�̋쓮�p�����[�^�[����ݒ�擾���邽�߂̍\���̂ł��B
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef struct CriAtomExReactDuckerParameterTag {
	union {
		struct {
			CriFloat32	level;							/*JP< �����{�����[�����x��				*/
		} volume;
		struct {
			CriUint16	control_id;						/*JP< AISAC�R���g���[��id				*/
			CriFloat32	control_value;					/*JP< AISAC�R���g���[���l				*/
		} aisac_control_value;
	} target;
	CriAtomExReactDuckerTargetType	target_type;		/*JP< �_�b�J�[�̑���Ώ�				*/
	CriAtomExReactFadeParameter		entry;				/*JP< �ω��J�n�t�F�[�h�p�����[�^�[		*/
	CriAtomExReactFadeParameter		exit;				/*JP< �ω��I���t�F�[�h�p�����[�^�[		*/
	CriAtomExReactHoldType			hold_type;			/*JP< �z�[���h�^�C�v					*/
	CriUint16						hold_time_ms;		/*JP< �z�[���h���ԁi�~���b�j			*/
} CriAtomExReactDuckerParameter;

/*JP
 * \brief AISAC���W�����[�V�����g���K�[�p�����[�^�[�\����
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * AISAC���W�����[�V�����g���K�[�̋쓮�p�����[�^�[����ݒ�擾���邽�߂̍\���̂ł��B
 * \sa CriAtomExReactParameter, criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef struct CriAtomExReactAisacModulationParameterTag {
	CriBool		enable_decrement_aisac_modulation_key;	/*JP< �ω�AISAC���W�����[�V�����L�[���L�����ۂ�	*/
	CriUint32	decrement_aisac_modulation_key;			/*JP< �ω�AISAC���W�����[�V�����L�[			*/
	CriBool		enable_increment_aisac_modulation_key;	/*JP< �߂�AISAC���W�����[�V�����L�[���L�����ۂ�	*/
	CriUint32	increment_aisac_modulation_key;			/*JP< �߂�AISAC���W�����[�V�����L�[			*/
} CriAtomExReactAisacModulationParameter;

/*JP
 * \brief REACT�쓮�p�����[�^�[�\����
 * \ingroup ATOMEXLIB_CATEGORY
 * \par ����:
 * REACT�̋쓮�p�����[�^�[����ݒ�擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExCategory_SetReactParameter , ::criAtomExCategory_GetReactParameter �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \sa criAtomExCategory_SetReactParameter, criAtomExCategory_GetReactParameter
 */
typedef struct CriAtomExReactParameterTag {
	union {
		CriAtomExReactDuckerParameter			ducker;				/*JP< �_�b�J�[�p�����[�^�[						*/
		CriAtomExReactAisacModulationParameter	aisac_modulation;	/*JP< AISAC���W�����[�V�����g���K�[�p�����[�^�[	*/
	} parameter;
	CriAtomExReactType	type;										/*JP< REACT�^�C�v							*/
	CriBool				enable_pausing_cue;							/*JP< �|�[�Y���̃L���[�͓K�p���邩				*/
} CriAtomExReactParameter;

/*==========================================================================
 *      CRI AtomEx ACB API
 *=========================================================================*/
struct CriAtomExAcbTag;
typedef struct CriAtomExAcbTag CriAtomExAcbObj;
/*JP
 * \brief ACB�n���h��
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �L���[�V�[�g�����Ǘ�����n���h���ł��B<br>
 * ::criAtomExAcb_LoadAcbFile �֐����œǂݍ��񂾃L���[�V�[�g�t�@�C������
 * �������Đ�����ꍇ�A�{�n���h���ƃL���[ID���v���[���[�ɑ΂��ăZ�b�g���܂��B<br>
 * \sa criAtomExAcb_LoadAcbFile, criAtomExPlayer_SetCueId
 */
typedef CriAtomExAcbObj *CriAtomExAcbHn;

/*JP
 * \brief �L���[ID
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �L���[ID�́A���[�U���I�[�T�����O�c�[����ŃL���[�ɑ΂��Ċ��蓖�Ă���ӂ�ID�ł��B<br>
 * �L���[ID���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExPlayer_SetCueId
 */
typedef CriSint32 CriAtomExCueId;

/*JP
 * \brief �L���[�C���f�b�N�X
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �L���[�C���f�b�N�X�́AACB�t�@�C�����̃R���e���c�̃I�t�Z�b�g�������ԍ��ł��B<br>
 * �i�擪�̃R���e���c��0�ԁA���̎��̃R���e���c��1�ԁc�Ƃ����ӂ��ɁA�R���e���c��
 * ���ԂɊ��蓖�Ă���ԍ��ł��B�j<br>
 * �L���[�C���f�b�N�X���v���O�������ŕێ�����ۂɂ́A�{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \sa criAtomExPlayer_SetCueIndex
 */
typedef CriSint32 CriAtomExCueIndex;

/*JP
 * \brief ACB���
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * ACB�f�[�^�̊e����ł��B<br>
 * \sa criAtomExAcb_GetAcbInfo
 */
typedef struct CriAtomExAcbInfoTag {
	const CriChar8* name;							/*JP< ���O						*/
	CriUint32 size;									/*JP< �T�C�Y					*/
	CriUint32 version;								/*JP< ACB�o�[�W����				*/
	CriAtomExCharacterEncoding character_encoding;	/*JP< �����R�[�h				*/
	CriFloat32 volume;								/*JP< �L���[�V�[�g�{�����[��	*/
	CriSint32 num_cues;								/*JP< �L���[��					*/
} CriAtomExAcbInfo;

/*JP
 * \brief �����g�`���
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �g�`���́A�e�L���[����Đ�����鉹���g�`�̏ڍ׏��ł��B<br>
 * \sa criAtomExAcb_GetWaveformInfoById, criAtomExAcb_GetWaveformInfoByName
 */
/* Waveform information */
typedef struct CriAtomExWaveformInfoTag {
	CriAtomExWaveId wave_id;	/*JP< �g�`�f�[�^ID			*/
	CriAtomExFormat format;		/*JP< �t�H�[�}�b�g���		*/
	CriSint32 sampling_rate;	/*JP< �T���v�����O���g��	*/
	CriSint32 num_channels;		/*JP< �`�����l����			*/
	CriSint64 num_samples;		/*JP< �g�[�^���T���v����	*/
	CriBool streaming_flag;		/*JP< �X�g���[�~���O�t���O	*/
	CriUint32 reserved[1];		/*JP< �\��̈�				*/
} CriAtomExWaveformInfo;

/*JP
 * \brief �L���[�^�C�v
 * \ingroup ATOMEXLIB_ACB
 * \sa CriAtomExCueInfo
 */
typedef enum CriAtomExAcbCueTypeTag {
	CRIATOMEXACB_CUE_TYPE_POLYPHONIC = (0),		/*JP< �|���t�H�j�b�N											*/
	CRIATOMEXACB_CUE_TYPE_SEQUENTIAL,			/*JP< �V�[�P���V����											*/
	CRIATOMEXACB_CUE_TYPE_SHUFFLE,				/*JP< �V���b�t���Đ�											*/
	CRIATOMEXACB_CUE_TYPE_RANDOM,				/*JP< �����_��													*/
	CRIATOMEXACB_CUE_TYPE_RANDOM_NO_REPEAT,		/*JP< �����_����A���i�O��Đ��������ȊO�������_���ɖ炷�j	*/
	CRIATOMEXACB_CUE_TYPE_SWITCH_GAME_VARIABLE,	/*JP< �X�C�b�`�Đ��i�Q�[���ϐ����Q�Ƃ��čĐ��g���b�N�̐؂�ւ���j	*/
	CRIATOMEXACB_CUE_TYPE_COMBO_SEQUENTIAL,		/*JP< �R���{�V�[�P���V�����i�u�R���{���ԁv���ɘA���R���{�����܂�ƃV�[�P���V�����A�Ō�܂ł����Ɓu�R���{���[�v�o�b�N�v�n�_�ɖ߂�j*/
	CRIATOMEXACB_CUE_TYPE_SWITCH_SELECTOR,		/*JP< �X�C�b�`�Đ��i�Z���N�^�[���Q�Ƃ��čĐ��g���b�N��؂�ւ���j	*/
	CRIATOMEXACB_CUE_TYPE_TRACK_TRANSITION_BY_SELECTOR,		/*JP< �g���b�N�g�����W�V�����Đ��i�Z���N�^�[���Q�Ƃ��čĐ��g���b�N��؂�ւ���j	*/
	/* enum size is 4bytes */
	CRIATOMEXACB_CUE_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAcbCueType;

/*JP
 * \brief �L���[3D���
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �g�`���́A�L���[��3D�ڍ׏��ł��B<br>
 * \sa CriAtomExCueInfo
 */
typedef struct CriAtomExCuePos3dInfoTag {
	CriFloat32 cone_inside_angle;		/*JP< �R�[�������p�x				*/
	CriFloat32 cone_outside_angle;		/*JP< �R�[���O���p�x				*/
	CriFloat32 min_distance;			/*JP< �ŏ���������					*/
	CriFloat32 max_distance;			/*JP< �ő匸������					*/
	CriFloat32 source_radius;			/*JP< Zero����InteriorPan�K�p����	*/
	CriFloat32 interior_distance;		/*JP< InteriorPan�K�p���E����		*/
	CriFloat32 doppler_factor;			/*JP< �h�b�v���[�W��				*/
	struct {
		CriBool follows_original_source;	/*JP< ����3D�����ɒǏ]���邩�ǂ��� */
		CriSint32 calculation_type;			/*JP< �ʒu���W�̎Z�o���@ */
		CriFloat32 calculation_parameters[CRIATOMEX3DSOURCE_MAX_RANDOM_POSITION_CALCULATION_PARAMETERS];	/*JP< �ʒu���W�̎Z�o���@�Ɋւ���e��p�����[�^�[�z�� */
	} random_position;
	CriUint16 distance_aisac_control;	/*JP< ��������AISAC�R���g���[��		*/
	CriUint16 listener_base_angle_aisac_control;		/*JP< ���X�i�[����ʊpAISAC�R���g���[��	*/
	CriUint16 source_base_angle_aisac_control;			/*JP< ��������ʊpAISAC�R���g���[��		*/
	CriUint16 listener_base_elevation_aisac_control;	/*JP< ���X�i�[���pAISAC�R���g���[��	*/
	CriUint16 source_base_elevation_aisac_control;		/*JP< �������pAISAC�R���g���[��		*/
	CriUint16 reserved[1];				/*JP< �\��̈�				*/
} CriAtomExCuePos3dInfo;

/*JP
 * \brief �L���[���
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * �L���[�̏ڍ׏��ł��B<br>
 * \sa criAtomExAcb_GetCueInfoByName, criAtomExAcb_GetCueInfoById, criAtomExAcb_GetCueInfoByIndex
 */
typedef struct CriAtomExCueInfoTag {
	CriAtomExCueId id;					/*JP< �L���[ID				*/
	CriAtomExAcbCueType type;			/*JP< �^�C�v				*/
	const CriChar8* name;				/*JP< �L���[��				*/
	const CriChar8* user_data;			/*JP< ���[�U�[�f�[�^		*/
	CriSint64 length;					/*JP< ����(msec)			*/
	CriUint16 categories[CRIATOMEXCATEGORY_MAX_CATEGORIES_PER_PLAYBACK];			/*JP< �J�e�S��ID	*/
	CriSint16 num_limits;				/*JP< �L���[���~�b�g		*/
	CriUint16 num_blocks;				/*JP< �u���b�N��			*/
	CriUint16 num_tracks;				/*JP< �g���b�N��			*/
	CriUint16 num_related_waveforms;	/*JP< �֘A����g�`��		*/
	CriUint8 priority;					/*JP< �v���C�I���e�B		*/
	CriUint8 header_visibility;			/*JP< �w�b�_�[���J�t���O	*/
	CriUint8 ignore_player_parameter;	/*JP< �v���[���[�p�����[�^�[�������t���O	*/
	CriUint8 probability;				/*JP< �Đ��m��				*/
	CriAtomExPanType pan_type;			/*JP< �p���^�C�v			*/
	CriAtomExCuePos3dInfo pos3d_info;	/*JP< 3D���				*/
	CriAtomExGameVariableInfo game_variable_info;	/*JP< �Q�[���ϐ�            */
} CriAtomExCueInfo;

/*JP
 * \brief ACB�n���h���R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	acb_hn				ACB�n���h��
 * \return		CriBool				�񋓂𑱂��邩�ǂ����iCRI_TRUE�F�p���ACRI_FALSE�F���~�j
 * \par ����:
 * ACB�n���h���̒ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomExAcb_EnumerateHandles �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * ACB�n���h�����R�[���o�b�N�o�R�Ŏ󂯎�邱�Ƃ��\�ł��B<br>
 * \attention
 * ACB�n���h�����R�[���o�b�N�֐����Ŕj�����Ă͂����܂���B<br>
 * \sa criAtomExAcb_EnumerateHandles, CriAtomExAcbHn
 */
typedef CriBool (CRIAPI *CriAtomExAcbHandleCbFunc)(void *obj, CriAtomExAcbHn acb_hn);

/*JP
 * \brief �C���Q�[���v���r���[�p�f�[�^�̃��[�h���m�R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \param[in]	acb_name	ACB��
 * \return					�Ȃ�
 * \par ����:
 * �C���Q�[���v���r���[�p�f�[�^�̃��[�h�����m�����ꍇ�ɌĂяo���R�[���o�b�N�֐��ł��B<br>
 * �C���Q�[���v���r���[�p�f�[�^���g�p���Ă��邩��������ۂɎg�p���܂��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExAcb_SetDetectionInGamePreviewDataCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AACB���[�h�֐�����ACB�̓��e��͂��s�����^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExAcb_SetDetectionInGamePreviewDataCallback
 */
typedef void (CRIAPI *CriAtomExAcbDetectionInGamePreviewDataCbFunc)(
	void *obj, const CriChar8* acb_name);

/*==========================================================================
 *      CRI AtomEx Voice Pool API
 *=========================================================================*/
struct CriAtomExVoicePoolTag;
typedef struct CriAtomExVoicePoolTag CriAtomExVoicePoolObj;
/*JP
 * \brief �{�C�X�v�[���n���h��
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �{�C�X�v�[���𐧌䂷�邽�߂̃n���h���ł��B<br>
 * ::criAtomExVoicePool_AllocateStandardVoicePool �֐����Ń{�C�X�v�[�����쐬�����ہA
 * �֐��̖߂�l�Ƃ��ĕԂ���܂��B<br>
 * �{�C�X�v�[���n���h���́A�{�C�X�v�[���̏��擾��A�{�C�X�v�[�����������
 * �ۂɎg�p���܂��B
 * \sa criAtomExVoicePool_AllocateStandardVoicePool, criAtomExVoicePool_Free
 */
typedef struct CriAtomExVoicePoolTag *CriAtomExVoicePoolHn;

/*JP
 * \brief �{�C�X�v�[�����ʎq
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �{�C�X�v�[�����ʎq�́A�{�C�X�v�[������ӂɎ��ʂ��邽�߂�ID�ł��B<br>
 * �{�C�X�v�[�����ʎq���v���O�������ŕێ�����ۂɂ́A
 * �{�ϐ��^��p���Ēl����舵���K�v������܂��B<br>
 * \par ���l
 * �{�C�X�v�[�����ʎq�́A�ȉ���2�ɑ΂��Ďw�肷��K�v������܂��B<br>
 * 	- �{�C�X�v�[���i�{�C�X�v�[���쐬�p�R���t�B�O�\���̂Ŏw��j
 * 	- �v���[���[�icriAtomExPlayer_SetVoicePoolIdentifier �֐��Ŏw��j
 * �{�C�X�v�[���ƃv���[���[�̗����Ɏ��ʎq��ݒ肷�邱�ƂŁA
 * ���Y�v���[���[�͓��Y�{�C�X�v�[������̂݃{�C�X���擾����悤�ɂȂ�܂��B<br>
 * <br>
 * �����̃{�C�X�v�[���ɓ���̃{�C�X�v�[�����ʎq���w�肷�邱�Ƃ��\�ł��B<br>
 * \sa CriAtomExStandardVoicePoolConfig, criAtomExPlayer_SetVoicePoolIdentifier
 */
typedef CriUint32 CriAtomExVoicePoolIdentifier;

/*JP
 * \brief �W���{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �W���{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateStandardVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForStandardVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateStandardVoicePool, criAtomExVoicePool_SetDefaultConfigForStandardVoicePool
 */
typedef struct CriAtomExStandardVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomStandardPlayerConfig player_config;	/*JP< �{�C�X�̎d�l			*/
} CriAtomExStandardVoicePoolConfig;

/*JP
 * \brief ADX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * ADX�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateAdxVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForAdxVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateAdxVoicePool, criAtomExVoicePool_SetDefaultConfigForAdxVoicePool
 */
typedef struct CriAtomExAdxVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomAdxPlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExAdxVoicePoolConfig;

/*JP
 * \brief HCA�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * HCA�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateHcaVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForHcaVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateHcaVoicePool, criAtomExVoicePool_SetDefaultConfigForHcaVoicePool
 */
typedef struct CriAtomExHcaVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomHcaPlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExHcaVoicePoolConfig;

/*JP
 * \brief HCA-MX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * HCA-MX�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateHcaMxVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateHcaMxVoicePool, criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool
 */
typedef struct CriAtomExHcaMxVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomHcaMxPlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExHcaMxVoicePoolConfig;

/*JP
 * \brief Wave�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * Wave�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateWaveVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForWaveVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateWaveVoicePool, criAtomExVoicePool_SetDefaultConfigForWaveVoicePool
 */
typedef struct CriAtomExWaveVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomWavePlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExWaveVoicePoolConfig;

/*JP
 * \brief AIFF�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * AIFF�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateAiffVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForAiffVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateAiffVoicePool, criAtomExVoicePool_SetDefaultConfigForAiffVoicePool
 */
typedef struct CriAtomExAiffVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomAiffPlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExAiffVoicePoolConfig;

/*JP
 * \brief RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * RawPCM�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExVoicePool_AllocateRawPcmVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForRawPcmVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateRawPcmVoicePool, criAtomExVoicePool_SetDefaultConfigForRawPcmVoicePool
 */
typedef struct CriAtomExRawPcmVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;	/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;						/*JP< �v�[������{�C�X�̐�	*/
	CriAtomRawPcmPlayerConfig player_config;		/*JP< �{�C�X�̎d�l			*/
} CriAtomExRawPcmVoicePoolConfig;

/*JP
 * \brief �C���X�g�D�������g�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �C���X�g�D�������g�{�C�X�v�[���̎d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * :: criAtomExVoicePool_AllocateInstrumentVoicePool �֐��Ɉ����Ƃ��ēn���܂��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForInstrumentVoicePool
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AllocateInstrumentVoicePool, criAtomExVoicePool_SetDefaultConfigForInstrumentVoicePool
 */
typedef struct CriAtomExInstrumentVoicePoolConfigTag {
	CriAtomExVoicePoolIdentifier identifier;		/*JP< �{�C�X�v�[�����ʎq	*/
	CriSint32 num_voices;							/*JP< �v�[������{�C�X�̐�	*/
	CriAtomInstrumentPlayerConfig player_config;	/*JP< �{�C�X�̎d�l			*/
} CriAtomExInstrumentVoicePoolConfig;

/*==========================================================================
 *      CRI AtomEx Player API
 *=========================================================================*/
/*JP
 * \brief �{�C�X�m�ە���
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * AtomEx �v���[���[���{�C�X���m�ۂ���ۂ̓���d�l���w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * AtomEx �v���[���[���쐬����ہA ::CriAtomExPlayerConfig �\���̂̃����o�Ɏw�肵�܂��B<br>
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create
 */
typedef enum CriAtomExVoiceAllocationMethodTag {
	CRIATOMEX_ALLOCATE_VOICE_ONCE = 0,		/*JP< �{�C�X�̊m�ۂ�1�����		*/
	CRIATOMEX_RETRY_VOICE_ALLOCATION,		/*JP< �{�C�X���J��Ԃ��m�ۂ���	*/
	CRIATOMEX_VOICE_ALLOCATION_METHOD_IS_4BYTE = 0x7FFFFFFF
} CriAtomExVoiceAllocationMethod;

/*JP
 * \brief �v���[���[�쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * AtomEx�v���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExPlayer_Create �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExPlayer_SetDefaultConfig
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExPlayer_Create,  criAtomExPlayer_SetDefaultConfig
 */
typedef struct CriAtomExPlayerConfigTag {
	/*JP
		\brief �{�C�X�m�ە���
		\par ����:
		AtomEx�v���[���[���{�C�X���m�ۂ���ۂ̕������w�肵�܂��B<br>
		<br>
		voice_allocation_method �� CRIATOMEX_ALLOCATE_VOICE_ONCE ���w�肵���ꍇ�A
		AtomEx�v���[���[�̓{�C�X�̊m�ۂ𔭉��J�n�̃^�C�~���O�ł̂ݍs���܂��B<br>
		�Đ��J�n���_�Ń{�C�X���m�ۂł��Ȃ������ꍇ��A
		����������ɂ��Đ����Ƀ{�C�X���D�����ꂽ�ꍇ�A
		�����Ɋ֘A���郊�\�[�X���������邽�߁A���̔g�`�f�[�^�͂��̎��_�Œ�~���܂��B<br>
		�i�Đ����n�܂�Ȃ������g�`�f�[�^��A�Đ����r���Œ�~���ꂽ�g�`�f�[�^���A
		�ǉ��̍Đ����N�G�X�g�Ȃ��ɍĐ�����邱�Ƃ͂���܂���B�j<br>
		<br>
		����ɑ΂��A voice_allocation_method �� CRIATOMEX_RETRY_VOICE_ALLOCATION 
		���w�肵���ꍇ�AAtomEx�v���[���[�̓{�C�X�̊m�ۂ�K�v�Ȍ��艽�x���J��Ԃ��܂��B<br>
		�{�C�X���m�ۂł��Ȃ��ꍇ��{�C�X��D�����ꂽ�ꍇ�ł��A
		�������Ǘ����郊�\�[�X�i�o�[�`�����{�C�X�j�͉�����Ȃ��̂ŁA
		�ēx�{�C�X�ɋ󂫂��ł������_�ŁA�����������ĊJ����܂��B<br>
		\par ���l:
		CRIATOMEX_RETRY_VOICE_ALLOCATION ���w�肵���ꍇ�A�������̃{�C�X�̏����ɉ����A
		�������s���Ă��Ȃ��o�[�`�����{�C�X�ɂ��Ă�����I�Ƀ{�C�X�̍Ď擾���������s���邽�߁A
		CRIATOMEX_ALLOCATE_VOICE_ONCE ���w�肵���ꍇ�ɔ�ׁA
		�������ׂ������Ȃ�\��������܂��B<br>
		<br>
		CRIATOMEX_RETRY_VOICE_ALLOCATION �w�莞�A
		�{�C�X�̍Ċm�ۂɐ�������ƁA�g�`�f�[�^��<b>�Đ��������l�������ʒu����</b>�V�[�N�Đ�����܂��B<br>
		\attention
		CRIATOMEX_RETRY_VOICE_ALLOCATION ���w�肵�� AtomEx �v���[���[���쐬�����ꍇ�ł��A
		Atom ���C�u�������������Ɏw�肷�� max_virtual_voices 
		�̐��𒴂���Đ��v�����������ꍇ�A�����͍ĊJ����Ȃ��Ȃ�܂��B<br>
		�i�G���[�R�[���o�b�N�֐��Ɍx�����Ԃ���A�o�[�`�����{�C�X���폜����܂��B�j<br>
		CRIATOMEX_RETRY_VOICE_ALLOCATION ���w�肷��ۂɂ́A
		���������ɕK�v�[���ȃo�[�`�����{�C�X���m�ۂ��Ă��������B<br>
		�i max_virtual_voices �ɑ傫�߂̒l���w�肵�Ă��������B�j<br>
		<br>
		CRIATOMEX_RETRY_VOICE_ALLOCATION ���w�肵���ꍇ�A
		�Đ�����Ȃ������g�`�f�[�^��{�C�X���D�����ꂽ�g�`�f�[�^���A
		���ǂ�����Đ��ĊJ����邩�A�����ɐ��䂷�邱�Ƃ͂ł��܂���B<br>
		�i���s�^�C�~���O�ɂ�薈��قȂ������ʂɂȂ�\��������܂��B�j<br>
	*/
	CriAtomExVoiceAllocationMethod voice_allocation_method;
	
	/*JP
		\brief �ő�p�X������
		\par ����:
		AtomEx�v���[���[���ێ�����p�X������̐��ł��B<br>
		\par ���l:
		::criAtomExPlayer_SetFile �֐������s����ƁA
		�w�肵���p�X������AtomEx�v���[���[���ɕێ�����܂��B<br>
		AtomEx�v���[���[�̓f�t�H���g��Ԃł̓p�X�������1�����ێ����܂���B<br>
		�i�������T�C�Y�팸�̂��߁B�j<br>
		�v���[���[�쐬���Ɏw�肷�� max_path_strings �̐��𑝂₹�΁A
		AtomEx�v���[���[�͎w�肳�ꂽ�����̃p�X�������ۑ�����悤�ɂȂ�܂��B<br>
		max_path_strings ��2�ȏ�̒l���w�肷�邱�ƂŁA
		1�̃v���[���[�ŕ����̃t�@�C���𓯎��Ƀp�X�w��ōĐ����邱�Ƃ��\�ƂȂ�܂��B<br>
		�������A max_path_strings �̒l�ɉ����ĕK�v�ȃ��[�N�̈�̃T�C�Y�͑������܂��B<br>
		�imax_path_strings�~max_path�o�C�g�̃��������K�v�ƂȂ�܂��B�j<br>
		\sa criAtomExPlayer_SetDefaultConfig, criAtomExPlayer_SetFile
	*/
	CriSint32 max_path_strings;
	
	/*JP
		\brief �ő�p�X��
		\par ����:
		AtomEx�v���[���[�Ɏw��\�ȃt�@�C���p�X�̍ő咷�ł��B<br>
		�t�@�C�������w�肵�ĉ������Đ����s���ꍇ�A�g�p����p�X�̍ő咷�� max_path 
		�Ƃ��Ďw�肷��K�v������܂��B<br>
		\par ���l:
		�{�p�����[�^�[�́A�p�b�L���O����Ă��Ȃ������t�@�C�����A
		�t�@�C�������w�肵�čĐ�����ۂɂ̂݃Z�b�g����K�v������܂��B<br>
		�t�@�C�����w��̍Đ����s�킸�A�L���[ID��g�`�f�[�^ID���w�肵�čĐ����s���ꍇ�A
		max_path �� 0 �ɐݒ肷�邱�Ƃ��\�ł��B<br>
		\attention
		::criAtomExPlayer_SetDefaultConfig �}�N���� CriAtomExPlayerConfig �\���̂�
		�f�t�H���g�l��ݒ肵���ꍇ�A max_path �ɂ� 0 ���Z�b�g����܂��B<br>
		�t�@�C�������w�肵�čĐ����s���ꍇ�A ::criAtomExPlayer_SetDefaultConfig 
		�}�N�����g�p���Ȃ����A�܂��� ::criAtomExPlayer_SetDefaultConfig �}�N�����s��
		�ɍēx�p�X�̍ő咷���Z�b�g����K�v������܂��B<br>
		\sa criAtomExPlayer_SetDefaultConfig, criAtomExPlayer_SetFile
	*/
	CriSint32 max_path;
	
	/*JP
		\brief �ő�AISAC��
		\par ����:
		��̃L���[�ɕR�Â��邱�Ƃ��ł���AISAC�̍ő吔�ł��B<br>
		Atom���C�u�����́A���������� AtomExPlayer �쐬����
		max_aisacs �Ŏw�肳�ꂽ������AISAC���Q�Ƃł��郊�\�[�X���m�ۂ��܂��B<br>
		max_aisacs �Ɏw�肷��l�̏����55�ł��B
	*/
	CriUint8 max_aisacs;

	/*JP 
		\brief �����X�V�̗L��
		\par ����:
		AtomEx�v���[���[�������X�V�������s�����ǂ������w�肵�܂��B<br>
		\par ���l:
		updates_time �� CRI_FALSE ���w�肵���ꍇ�A
		�쐬���ꂽAtomEx�v���[���[�͍Đ������̍X�V���s���܂���B<br>
		���̌��ʁA ::criAtomExPlayer_GetTime �֐��ɂ��Đ������̎擾�͍s���Ȃ��Ȃ�܂����A
		�����Đ����̏������ׂ��킸���ɉ����邱�Ƃ��\�ƂȂ�܂��B<br>
		\sa criAtomExPlayer_GetTime
	*/
	CriBool updates_time;

	/*JP
		\brief �������������X�V�̗L��
		\par ����:
		AtomEx�v���[���[���Đ������ɓ������������X�V�������s�����ǂ������w�肵�܂��B<br>
		\par ���l:
		enable_audio_synced_timer �� CRI_TRUE ���w�肵���ꍇ�A
		�쐬���ꂽAtomEx�v���[���[��p���čĐ����ꂽ�����ɑ΂��āA
		�Đ��ς݃T���v�����ɓ�������悤�ɕ␳�����Đ������̍X�V���s���悤�ɂȂ�܂��B<br>
		�␳���ꂽ�Đ������� ::criAtomExPlayback_GetTimeSyncedWithAudio �֐��ɂ���Ď擾�ł��܂��B<br>
		�����Đ����̏������ׂ��オ�邽�߁A�����ɓ����������m�ȍĐ��������擾�������v���[���[��
		�쐬���̂� CRI_TRUE ���w�肷��悤�ɂ��Ă��������B<br>
		\attention
		�{�t���O��L���ɂ����ꍇ�AAtomEx�v���[���[�ɑ΂���s�b�`�w�肪�s���Ȃ��Ȃ�܂��B<br>
		\sa criAtomExPlayer_GetTimeSyncedWithAudio
	*/
	CriBool enable_audio_synced_timer;
} CriAtomExPlayerConfig;

struct CriAtomExPlayerTag;
typedef struct CriAtomExPlayerTag CriAtomExPlayerObj;
/*JP
 * \brief �v���[���[�n���h��
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * CriAtomExPlayerHn �́A�����Đ��p�ɍ��ꂽ�v���[���[�𑀍삷�邽�߂̃n���h���ł��B<br>
 * ::criAtomExPlayer_Create �֐��ŉ����Đ��p�̃v���[���[���쐬����ƁA
 * �֐��̓v���[���[����p�ɁA����"AtomEx�v���[���[�n���h��"��Ԃ��܂��B
 * <br>
 * �f�[�^�̃Z�b�g��Đ��̊J�n�A�X�e�[�^�X�̎擾���A�v���[���[�ɑ΂��čs������́A
 * �S��AtomEx�v���[���[�n���h������Ď��s����܂��B<br>
 * \sa criAtomExPlayer_Create
 */
typedef CriAtomExPlayerObj *CriAtomExPlayerHn;

/*JP
 * \brief �v���[���[�X�e�[�^�X
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * AtomEx�v���[���[�̍Đ���Ԃ������l�ł��B<br>
 * ::criAtomExPlayer_GetStatus �֐��Ŏ擾�\�ł��B<br>
 * <br>
 * �Đ���Ԃ́A�ʏ�ȉ��̏����őJ�ڂ��܂��B<br>
 * -# CRIATOMEXPLAYER_STATUS_STOP
 * -# CRIATOMEXPLAYER_STATUS_PREP
 * -# CRIATOMEXPLAYER_STATUS_PLAYING
 * -# CRIATOMEXPLAYER_STATUS_PLAYEND
 * 
 * AtomEx�v���[���[�쐬����̏�Ԃ́A��~��ԁi CRIATOMEXPLAYER_STATUS_STOP �j�ł��B<br>
 * ::criAtomExPlayer_SetData �֐����Ńf�[�^���Z�b�g���A ::criAtomExPlayer_Start �֐���
 * ���s����ƁA�Đ�������ԁi CRIATOMEXPLAYER_STATUS_PREP �j�ɑJ�ڂ��A�Đ��������n�߂܂��B<br>
 * �f�[�^���[����������A�Đ������������ƁA�X�e�[�^�X�͍Đ����i CRIATOMEXPLAYER_STATUS_PLAYING �j
 * �ɕς��A�����̏o�͂��J�n����܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I�������_�ŁA�X�e�[�^�X�͍Đ�����
 * �i CRIATOMEXPLAYER_STATUS_PLAYEND �j�ɕς��܂��B
 * \par ���l
 * AtomEx�v���[���[�́AAtom�v���[���[�ƈقȂ�A1�̃v���[���[�ŕ������̍Đ����\�ł��B<br>
 * ���̂��߁A�Đ�����AtomEx�v���[���[�ɑ΂��� ::criAtomExPlayer_Start �֐������s����ƁA
 * 2�̉����d�Ȃ��čĐ�����܂��B<br>
 * �Đ����� ::criAtomExPlayer_Stop �֐������s�����ꍇ�AAtomEx�v���[���[�ōĐ����̑S�Ẳ���
 * ����~���A�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_STOP �ɖ߂�܂��B<br>
 * �i ::criAtomExPlayer_Stop �֐��̌Ăяo���^�C�~���O�ɂ���ẮA CRIATOMEXPLAYER_STATUS_STOP 
 * �ɑJ�ڂ���܂łɎ��Ԃ�������ꍇ������܂��B�j<br>
 * <br>
 * 1��AtomEx�v���[���[�ŕ����� ::criAtomExPlayer_Start �֐������s�����ꍇ�A
 * 1�ł��Đ��������̉�������΁A�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PREP ��ԂɂȂ�܂��B<br>
 * �i�S�Ẳ������Đ����̏�ԂɂȂ�܂ŁA�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYING ��Ԃ�
 * �J�ڂ��܂���B�j<br>
 * �܂��A CRIATOMEXPLAYER_STATUS_PLAYING ��Ԃ̃v���[���[�ɑ΂��A�ēx ::criAtomExPlayer_Start 
 * �֐������s�����ꍇ�A�X�e�[�^�X�͈ꎞ�I�� CRIATOMEXPLAYER_STATUS_PREP �ɖ߂�܂��B<br>
 * <br>
 * �Đ����ɕs���ȃf�[�^��ǂݍ��񂾏ꍇ��A�t�@�C���A�N�Z�X�Ɏ��s�����ꍇ�A
 * �X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_ERROR �ɑJ�ڂ��܂��B<br>
 * �����̉������Đ����ɂ��鉹���ŃG���[�����������ꍇ�A�v���[���[�̃X�e�[�^�X��
 * ���̉����̏�ԂɊ֌W�Ȃ��A CRIATOMEXPLAYER_STATUS_ERROR �ɑJ�ڂ��܂��B<br>
 * \sa criAtomExPlayer_GetStatus, criAtomExPlayer_SetData, criAtomExPlayer_Start, criAtomExPlayer_Stop
 */
typedef enum CriAtomExPlayerStatusTag {
	CRIATOMEXPLAYER_STATUS_STOP = 0,		/*JP< ��~��		*/
	CRIATOMEXPLAYER_STATUS_PREP,			/*JP< �Đ�������	*/
	CRIATOMEXPLAYER_STATUS_PLAYING,			/*JP< �Đ���		*/
	CRIATOMEXPLAYER_STATUS_PLAYEND,			/*JP< �Đ�����		*/
	CRIATOMEXPLAYER_STATUS_ERROR,			/*JP< �G���[������	*/
	CRIATOMEXPLAYER_STATUS_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPlayerStatus;

/*JP
 * \brief �{�C�X�������
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̔���������@���w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * ::criAtomExPlayer_SetVoiceControlMethod �֐��ŗ��p���܂��B<br>
 * \sa criAtomExPlayer_SetVoiceControlMethod
 */
typedef enum CriAtomExVoiceControlMethodTag {
	CRIATOMEX_PREFER_LAST = 0,				/*JP< �㒅�D��			*/
	CRIATOMEX_PREFER_FIRST = 1,				/*JP< �撅�D��			*/
	CRIATOMEX_PREFER_DATA = 2,				/*JP< �f�[�^�ݒ�D��	*/
	CRIATOMEX_CONTROL_METHOD_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExVoiceControlMethod;

/*JP
 * \brief �X�s�[�J�[ID
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * �������o�͂���X�s�[�J�[���w�肷�邽�߂�ID�ł��B<br>
 * ::criAtomExPlayer_SetSendLevel �֐��ŗ��p���܂��B
 * \sa criAtomExPlayer_SetSendLevel
 */
typedef enum CriAtomExSpeakerIdTag {
	CRIATOMEX_SPEAKER_FRONT_LEFT = 0,			/*JP<�t�����g���t�g�X�s�[�J�[			*/
	CRIATOMEX_SPEAKER_FRONT_RIGHT = 1,			/*JP<�t�����g���C�g�X�s�[�J�[			*/
	CRIATOMEX_SPEAKER_FRONT_CENTER = 2,			/*JP<�t�����g�Z���^�[�X�s�[�J�[			*/
	CRIATOMEX_SPEAKER_LOW_FREQUENCY = 3,		/*JP<LFE�i���T�u�E�[�n�[�j				*/
	CRIATOMEX_SPEAKER_SURROUND_LEFT = 4,		/*JP<�T���E���h���t�g�X�s�[�J�[			*/
	CRIATOMEX_SPEAKER_SURROUND_RIGHT = 5,		/*JP<�T���E���h���C�g�X�s�[�J�[			*/
	CRIATOMEX_SPEAKER_SURROUND_BACK_LEFT = 6,	/*JP<�T���E���h�o�b�N���t�g�X�s�[�J�[	*/
	CRIATOMEX_SPEAKER_SURROUND_BACK_RIGHT = 7,	/*JP<�T���E���h�o�b�N���C�g�X�s�[�J�[	*/

	/* enum size is 4bytes */
	CRIATOMEX_SPEAKER_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExSpeakerId;

/*JP
 * \brief �Đ�ID
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * ::criAtomExPlayer_Start �֐����s���ɕԂ����ID�ł��B<br>
 * �v���[���[�P�ʂł͂Ȃ��A ::criAtomExPlayer_Start �֐��ōĐ������X�̉����ɑ΂���
 * �p�����[�^�[�ύX���Ԏ擾���s�������ꍇ�A�{ID���g�p���Đ�����s���K�v������܂��B<br>
 * �����ȍĐ�ID��::CRIATOMEX_INVALID_PLAYBACK_ID�ł��B
 * \sa criAtomExPlayer_Start, criAtomExPlayback_GetStatus, CRIATOMEX_INVALID_PLAYBACK_ID
 */
typedef CriUint32 CriAtomExPlaybackId;

/*JP
 * \brief �v���[���[�R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	player				AtomEx�v���[���[
 * \par ����:
 * �v���[���[�̗񋓂Ɏg�p����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomExPlayer_EnumeratePlayers �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * �A�v���P�[�V�������ō쐬�����v���[���[���R�[���o�b�N�Ŏ󂯎�邱�Ƃ��\�ƂȂ�܂��B<br>
 * \attention
 * �����œn���ꂽAtomEx�v���[���[��j�����Ă͂����܂���B<br>
 * �i�A�N�Z�X�ᔽ��n���O�A�b�v���̏d�Ăȕs����������鋰�ꂪ����܂��B�j<br>
 * <br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExPlayer_EnumeratePlayers
 */
typedef void (CRIAPI *CriAtomExPlayerCbFunc)(void *obj, CriAtomExPlayerHn player);

/*JP
 * \brief �f�[�^�v���R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	id		�Đ�ID
 * \param[in]	player	Atom�v���[���[�n���h��
 * \return				�Ȃ�
 * \par ����:
 * ���ɍĐ�����f�[�^���w�肷�邽�߂̃R�[���o�b�N�֐��ł��B<br>
 * �����̉����f�[�^���V�[�����X�ɘA�����čĐ�����ۂɎg�p���܂��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExPlayer_SetDataRequestCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�{�C�X�������I�Ɏg�p���Ă��� Atom �v���[���[��
 * �A���Đ��p�̃f�[�^��v������^�C�~���O�Ŏ��s����܂��B<br>
 * �i�O��̃f�[�^��ǂݍ��ݏI���āA���ɍĐ����ׂ��f�[�^��v������^�C�~���O��
 * �R�[���o�b�N�֐������s����܂��B�j<br>
 * <br>
 * �R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐�����p���� Atom �v���[���[�Ƀf�[�^���Z�b�g����ƁA
 * �Z�b�g���ꂽ�f�[�^�͌��ݍĐ����̃f�[�^�ɑ����ăV�[�����X�ɘA������čĐ�����܂��B<br>
 * �܂��A�{�֐����� ::criAtomPlayer_SetPreviousDataAgain �֐������s���邱�ƂŁA
 * ����f�[�^���J��Ԃ��Đ��������邱�Ƃ��\�ł��B
 * \par ���l:
 * �{�֐����Ńf�[�^���w�肵�Ȃ������ꍇ�A���݂̃f�[�^���Đ����I�������_�ŁA
 * AtomEx �v���[���[�̃X�e�[�^�X�� ::CRIATOMEXPLAYER_STATUS_PLAYEND �ɑJ�ڂ��܂��B<br>
 * <br>
 * �^�C�~���O���̖��ɂ��A�f�[�^���w�肷�邱�Ƃ��ł��Ȃ����A�X�e�[�^�X��
 * ::CRIATOMEXPLAYER_STATUS_PLAYEND �ɑJ�ڂ��������Ȃ��ꍇ�ɂ́A�R�[���o�b�N�֐�����
 * ::criAtomPlayer_DeferCallback �֐������s���Ă��������B<br>
 * ::criAtomPlayer_DeferCallback �֐������s���邱�ƂŁA��1V��ɍēx�f�[�^�v��
 * �R�[���o�b�N�֐����Ăяo����܂��B�i�R�[���o�b�N���������g���C�\�B�j<br>
 * �������A ::criAtomPlayer_DeferCallback �֐������s�����ꍇ�A�Đ����r�؂��
 * �i�A���ӏ��Ɉ�莞�Ԗ���������j�\��������܂��B<br>
 * \attention
 * �{�R�[���o�b�N�̑� 3 �����i player �j�́A AtomEx �v���[���[�ł͂Ȃ��A
 * ���ʃ��C���� Atom �v���[���[�ł��B<br>
 * �i AtomExPlayerHn �ɃL���X�g����ƁA�A�N�Z�X�ᔽ���̏d��ȕs����������܂��B�j<br>
 * <br>
 * �����̔g�`�f�[�^���܂ރL���[���Đ������ꍇ�A
 * �ŏ��Ɍ��������g�`�f�[�^�̍Đ����I������^�C�~���O�ŃR�[���o�b�N�֐������s����܂��B<br>
 * ���̂��߁A�����̔g�`�f�[�^���܂ރL���[�ɑ΂��ĘA���Đ��̑�����s�����ꍇ�A
 * �Ӑ}�Ƃ��Ȃ��g�ݍ��킹�Ŕg�`���A���Đ������\��������܂��B<br>
 * �{�@�\���g�p����ۂɂ́A 1 �̔g�`�f�[�^�݂̂��܂ރL���[���Đ����邩�A
 * �܂��̓t�@�C����I���������f�[�^�����Đ����Ă��������B<br>
 * <br>
 * ����A�R�[���o�b�N�͔g�`�f�[�^���Đ����n�߂��{�C�X�ɑ΂��Ă̂݊��蓖�Ă��܂��B<br>
 * ���̂��߁A�g�`�f�[�^�Đ���Ƀ{�C�X���o�[�`�����������ꍇ�A�R�[���o�b�N�͎��s����܂���B<br>
 * �i�f�[�^�I�[�ɓ��B�������_�ŁA�R�[���o�b�N�����s���ꂸ��PLAYEND��ԂɑJ�ڂ��܂��B�j<br>
 * <br>
 * �{�R�[���o�b�N�֐����ŁA�V�[�����X�A���Đ��ȊO�̐�����s��Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Ŏ��s�\��API�́A�ȉ��̂Ƃ���ł��B<br>
 * 	- criAtomExAcb_GetWaveformInfoById�i������NULL�w��͕s�j
 * 	- criAtomExAcb_GetWaveformInfoByName�i������NULL�w��͕s�j
 * 	- criAtomExAcb_GetOnMemoryAwbHandle
 * 	- criAtomExAcb_GetStreamingAwbHandle
 * 	- criAtomPlayer_SetData
 * 	- criAtomPlayer_SetFile
 * 	- criAtomPlayer_SetContentId
 * 	- criAtomPlayer_SetWaveId
 * 	- criAtomPlayer_SetPreviousDataAgain
 * 	- criAtomPlayer_DeferCallback
 * 	
 * <br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExPlayer_SetDataRequestCallback, criAtomPlayer_SetData,
 * criAtomPlayer_SetPreviousDataAgain, criAtomPlayer_DeferCallback
 */
typedef void (CRIAPI *CriAtomExPlayerDataRequestCbFunc)(
	void *obj, CriAtomExPlaybackId id, CriAtomPlayerHn player);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * \param[in]		obj				���[�U�w��I�u�W�F�N�g
 * \param[in]		id				�Đ�ID
 * \param[in]		format			PCM�̌`��
 * \param[in]		num_channels	�`�����l����
 * \param[in]		num_samples		�T���v����
 * \param[in,out]	data			PCM�f�[�^�̃`�����l���z��
 * \return							�Ȃ�
 * \par ����:
 * �f�R�[�h���ʂ� PCM �f�[�^���󂯎��R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExPlayer_SetFilterCallback �֐����g�p���܂��B<br>
 * �R�[���o�b�N�֐���o�^����ƁA�{�C�X�������f�[�^���f�R�[�h����x�ɁA
 * �R�[���o�b�N�֐������s�����悤�ɂȂ�܂��B<br>
 * <br>
 * �t�B���^�[�R�[���o�b�N�֐��ɂ́A PCM �f�[�^�̃t�H�[�}�b�g��`�����l�����A
 * �Q�Ɖ\�ȃT���v�����A PCM �f�[�^���i�[�����̈�̃A�h���X���Ԃ���܂��B<br>
 * �R�[���o�b�N���ł� PCM �f�[�^�̒l�𒼐ڎQ�Ɖ\�ɂȂ�̂ŁA
 * �Đ����̉����̐U�����`�F�b�N����Ƃ������p�r�ɗ��p�\�ł��B<br>
 * <br>
 * �܂��A�R�[���o�b�N�֐����� PCM �f�[�^�����H����ƁA�Đ����ɔ��f����邽�߁A
 * PCM �f�[�^�ɑ΂��ă��[�U�Ǝ��̃G�t�F�N�g�������邱�Ƃ��\�ł��B<br>
 * �i�������A�^�C���X�g���b�`�����̂悤�ȃf�[�^�ʂ�����������H���s�����Ƃ͂ł��܂���B�j<br>
 * \par ���l:
 * PCM �f�[�^�̓`�����l���P�ʂŕ�������Ă��܂��B<br>
 * �i�C���^�[���[�u����Ă��܂���B�j<br>
 * �� 6 �����i data �z��j�ɂ́A�e�`�����l���� PCM �f�[�^�z��̐擪�A�h���X���i�[����Ă��܂��B<br>
 * �i�񎟌��z��̐擪�A�h���X�ł͂Ȃ��A�`�����l�����Ƃ� PCM �f�[�^�z��̐擪�A�h���X���i�[����
 * �ꎟ���̃|�C���^�z��ł��B�j<br>
 * <br>
 * �v���b�g�t�H�[���ɂ���āA PCM �f�[�^�̃t�H�[�}�b�g�͈قȂ�܂��B<br>
 * ���s���̃f�[�^�t�H�[�}�b�g�ɂ��ẮA�� 3 �����i format �j�Ŕ��ʉ\�ł��B<br>
 * PCM �f�[�^�̃t�H�[�}�b�g�� 16 bit �����^�̏ꍇ�A format �� CRIATOM_PCM_FORMAT_SINT16 �ƂȂ�A
 * PCM �f�[�^�̃t�H�[�}�b�g�� 32 bit ���������_���^�̏ꍇ�A format �� CRIATOM_PCM_FORMAT_FLOAT32 �ƂȂ�܂��B<br>
 * ���ꂼ��̃P�[�X�� PCM �f�[�^�̒l��͈قȂ�܂��̂ł����ӂ��������B<br>
 * - CRIATOM_PCM_FORMAT_SINT16 ���� -32768 �` +32767
 * - CRIATOM_PCM_FORMAT_FLOAT32 ���� -1.0f �` +1.0f
 * 
 * �i�f�R�[�h���_�ł̓N���b�s���O���s���Ă��Ȃ����߁A CRIATOM_PCM_FORMAT_FLOAT32 
 * ���͏�L�͈͂��킸���ɒ������l���o��\��������܂��B�j<br>
 * \attention
 * <br>
 * �{�R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪��������\��������܂��B<br>
 * \sa criAtomExPlayer_SetFilterCallback
 */
typedef void (CRIAPI *CriAtomExPlayerFilterCbFunc)(
	void *obj, CriAtomExPlaybackId id, CriAtomPcmFormat format,
	CriSint32 num_channels, CriSint32 num_samples, void *data[]);

/*JP
 * \brief �u���b�N�g�����W�V�����R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * \param[in]		obj				���[�U�w��I�u�W�F�N�g
 * \param[in]		id				�Đ�ID
 * \param[in]		index			�L���[���̃u���b�N�C���f�b�N�X�l
 * \return							�Ȃ�
 * \par ����:
 * �u���b�N�V�[�P���X�Đ����Ƀu���b�N�g�����W�V���������������Ƃ��ɌĂяo�����R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExPlayer_SetBlockTransitionCallback �֐����g�p���܂��B<br>
 * �R�[���o�b�N�֐���o�^����ƁA�u���b�N�g�����W�V��������������x�ɁA
 * �R�[���o�b�N�֐������s�����悤�ɂȂ�܂��B<br>
 * <br>
 * \attention
 * <br>
 * �{�R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪��������\��������܂��B<br>
 * \sa criAtomExPlayer_SetBlockTransitionCallback
 */
typedef void (CRIAPI *CriAtomExPlayerBlockTransitionCbFunc)(
	void *obj, CriAtomExPlaybackId id, CriAtomExBlockIndex index);

/*JP
 * \brief �Đ��g���b�N���pInfo�\����
 * \ingroup ATOMEXLIB_PLAYER
 */
typedef struct CriAtomExPlaybackTrackInfoTag {
	CriAtomExPlaybackId id;				/*JP< �Đ�ID				*/
	CriAtomExAcbCueType sequence_type;	/*JP< �e�V�[�P���X�^�C�v	*/
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��		*/
	CriUint16 track_no;					/*JP< �g���b�N�ԍ�			*/
	CriUint16 reserved[1];				/*JP< �\��̈�				*/
} CriAtomExPlaybackTrackInfo;

/*JP
 * \brief �Đ��g���b�N���擾�R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * \param[in]		obj				���[�U�w��I�u�W�F�N�g
 * \param[in]		info			�Đ��g���b�N���
 * \return							�Ȃ�
 * \par ����:
 * �|���t�H�j�b�N�^�C�v�A�g���b�N�J�ڃ^�C�v�ȊO�̃L���[�Đ����ɍĐ������g���b�N����ʒm����R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExPlayer_SetPlaybackTrackInfoNotificationCallback �֐����g�p���܂��B<br>
 * <br>
 * \attention
 * <br>
 * �{�R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪��������\��������܂��B<br>
 * \sa criAtomExPlayer_SetPlaybackTrackInfoNotificationCallback
 */
typedef void (CRIAPI *CriAtomExPlayerPlaybackTrackInfoNotificationCbFunc)(
	void *obj, const CriAtomExPlaybackTrackInfo* info);

/*JP
 * \brief �p�����[�^�[ID
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * �p�����[�^�[���w�肷�邽�߂�ID�ł��B<br>
 * ::criAtomExPlayer_GetParameterFloat32 �֐����ŗ��p���܂��B
 * \sa criAtomExPlayer_GetParameterFloat32, criAtomExPlayer_GetParameterSint32,
 * criAtomExPlayer_GetParameterUint32
 */
typedef enum CriAtomExParameterIdTag {
	CRIATOMEX_PARAMETER_ID_VOLUME					=  0,	/*JP< �{�����[�� */
	CRIATOMEX_PARAMETER_ID_PITCH					=  1,	/*JP< �s�b�` */
	CRIATOMEX_PARAMETER_ID_PAN3D_ANGLE				=  2,	/*JP< �p���j���O3D�p�x */
	CRIATOMEX_PARAMETER_ID_PAN3D_DISTANCE			=  3,	/*JP< �p���j���O3D���� */
	CRIATOMEX_PARAMETER_ID_PAN3D_VOLUME				=  4,	/*JP< �p���j���O3D�{�����[�� */
	CRIATOMEX_PARAMETER_ID_PAN_TYPE					=  5,	/*JP< �p���^�C�v */
	CRIATOMEX_PARAMETER_ID_PAN_SPEAKER_TYPE			=  6,	/*JP< �p���X�s�[�J�[�^�C�v */
	CRIATOMEX_PARAMETER_ID_PAN_CH0					=  7,	/*JP< 2D�p���i�`�����l��0�j */
	CRIATOMEX_PARAMETER_ID_PAN_CH1					=  8,	/*JP< 2D�p���i�`�����l��1�j */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_0			=  9,	/*JP< �o�X�Z���h���x��0 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_1			= 10,	/*JP< �o�X�Z���h���x��1 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_2			= 11,	/*JP< �o�X�Z���h���x��2 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_3			= 12,	/*JP< �o�X�Z���h���x��3 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_4			= 13,	/*JP< �o�X�Z���h���x��4 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_5			= 14,	/*JP< �o�X�Z���h���x��5 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_6			= 15,	/*JP< �o�X�Z���h���x��6 */
	CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_7			= 16,	/*JP< �o�X�Z���h���x��7 */
	CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_LOW	= 17,	/*JP< �o���h�p�X�t�B���^�[�̒��J�b�g�I�t���g�� */
	CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_HIGH	= 18,	/*JP< �o���h�p�X�t�B���^�[�̍���J�b�g�I�t���g�� */
	CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_TYPE		= 19,	/*JP< �o�C�N�A�b�h�t�B���^�[�̃t�B���^�[�^�C�v */
	CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_FREQ		= 20,	/*JP< �o�C�N�A�b�h�t�B���^�[�̎��g�� */
	CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_Q			= 21,	/*JP< �o�C�N�A�b�h�t�B���^�[��Q�l */
	CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_GAIN		= 22,	/*JP< �o�C�N�A�b�h�t�B���^�[�̃Q�C�� */
	CRIATOMEX_PARAMETER_ID_ENVELOPE_ATTACK_TIME		= 23,	/*JP< �G���x���[�v�̃A�^�b�N�^�C�� */
	CRIATOMEX_PARAMETER_ID_ENVELOPE_HOLD_TIME		= 24,	/*JP< �G���x���[�v�̃z�[���h�^�C�� */
	CRIATOMEX_PARAMETER_ID_ENVELOPE_DECAY_TIME		= 25,	/*JP< �G���x���[�v�̃f�B�P�C�^�C�� */
	CRIATOMEX_PARAMETER_ID_ENVELOPE_RELEASE_TIME	= 26,	/*JP< �G���x���[�v�̃����[�X�^�C�� */
	CRIATOMEX_PARAMETER_ID_ENVELOPE_SUSTAIN_LEVEL	= 27,	/*JP< �G���x���[�v�̃T�X�e�B�����x�� */
	CRIATOMEX_PARAMETER_ID_START_TIME				= 28,	/*JP< �Đ��J�n�ʒu */
	CRIATOMEX_PARAMETER_ID_PRIORITY					= 31,	/*JP< �{�C�X�v���C�I���e�B */
	CRIATOMEX_PARAMETER_ID_SILENT_MODE				= 32,	/*JP< �������������[�h */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_0			= 33,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[0 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_1			= 34,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[1 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_2			= 35,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[2 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_3			= 36,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[3 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_4			= 37,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[4 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_5			= 38,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[5 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_6			= 39,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[6 */
	CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_7			= 40,	/*JP< �C���T�[�V����DSP�̃p�����[�^�[7 */

	/* enum size is 4bytes */
	CRIATOMEX_PARAMETER_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExParameterId;

/*==========================================================================
 *      CRI AtomEx Sequencer API
 *=========================================================================*/
/*JP
 * \brief �V�[�P���X�C�x���g�R�[���o�b�N
 * \ingroup ATOMEXLIB_SEQUENCER
 * \par ����:
 * AtomEx���C�u�����̃V�[�P���X�C�x���g�R�[���o�b�N�^�C�v�ł��B<br>
 * \sa CriAtomExSequenceEventInfo
 */
typedef enum CriAtomExSequecneEventTypeTag {
	/*JP
	 * \brief �V�[�P���X�R�[���o�b�N
	 * \par ����:
	 * �V�[�P���X�f�[�^���ɖ��ߍ��܂ꂽ�R�[���o�b�N�C�x���g���B
	 */
	CRIATOMEX_SEQUENCE_EVENT_TYPE_CALLBACK = 0,
		
	/* enum size is 4bytes */
	CRIATOMEX_SEQUENCE_EVENT_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExSequecneEventType;

/*JP
 * \brief �V�[�P���X�R�[���o�b�N�C�x���g�pInfo�\����
 * \ingroup ATOMEXLIB_SEQUENCER
 */
typedef struct CriAtomExSequenceEventInfoTag {
	CriUint64 position;					/*JP< �C�x���g�ʒu			*/
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��		*/
	const CriChar8* string;				/*JP< �f�[�^���ߍ��ݕ�����	*/
	CriAtomExPlaybackId id;				/*JP< �Đ�ID				*/
	CriAtomExSequecneEventType type;	/*JP< �C�x���g�^�C�v		*/
	CriUint32 value;					/*JP< �f�[�^���ߍ��ݒl		*/
	CriUint32 reserved[1];				/*JP< �\��̈�				*/
} CriAtomExSequenceEventInfo;

/*JP
 * \brief �V�[�P���X�R�[���o�b�N
 * \ingroup ATOMEXLIB_SEQUENCER
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	info	�V�[�P���X�C�x���g���
 * \return				���g�p
 * AtomEx���C�u�����̃V�[�P���X�R�[���o�b�N�֐��^�ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExSequencer_SetEventCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�T�[�o�[�֐����ŃV�[�P���X�����������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExSequencer_SetEventCallback
 */
typedef CriSint32 (CRIAPI *CriAtomExSequencerEventCbFunc)(void* obj, const CriAtomExSequenceEventInfo* info);

/*==========================================================================
 *      CRI AtomEx Beat Sync API
 *=========================================================================*/
/*JP
 * \brief �r�[�g�����ʒu���o�R�[���o�b�N�p�\����
 * \ingroup ATOMEXLIB_BEATSYNC
 */
typedef struct CriAtomExBeatSyncInfoTag {
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��			*/
	CriAtomExPlaybackId playback_id;	/*JP< �Đ�ID					*/
	CriUint32 bar_count;				/*JP< ���ߐ�					*/
	CriUint32 beat_count;				/*JP< ����						*/
	CriFloat32 beat_progress;			/*JP< ���̐i��(0.0f�`1.0f)		*/
	CriFloat32 bpm;						/*JP< �e���|(��/��)				*/
	CriSint32 offset;					/*JP< �����I�t�Z�b�g(ms)		*/
	CriUint32 num_beats;				/*JP< ���q���@�@				*/
} CriAtomExBeatSyncInfo;

/*JP
 * \brief �r�[�g�����ʒu���o�R�[���o�b�N
 * \ingroup ATOMEXLIB_BEATSYNC
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	info	�r�[�g�����ʒu���o���
 * \return				���g�p
 * AtomEx���C�u�����̃r�[�g�����ʒu���o�R�[���o�b�N�֐��^�ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExBeatSync_SetCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�T�[�o�[�֐����Ńr�[�g�����ʒu���o�����������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExBeatSync_SetCallback
 */
typedef CriSint32 (CRIAPI *CriAtomExBeatSyncCbFunc)(void* obj, const CriAtomExBeatSyncInfo* info);

/*==========================================================================
 *      CRI AtomEx Playback API
 *=========================================================================*/
/*JP
 * \brief �Đ��X�e�[�^�X
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * AtomEx�v���[���[�ōĐ��ς݂̉����̃X�e�[�^�X�ł��B<br>
 * ::criAtomExPlayback_GetStatus �֐��Ŏ擾�\�ł��B<br>
 * <br>
 * �Đ���Ԃ́A�ʏ�ȉ��̏����őJ�ڂ��܂��B<br>
 * -# CRIATOMEXPLAYBACK_STATUS_PREP
 * -# CRIATOMEXPLAYBACK_STATUS_PLAYING
 * -# CRIATOMEXPLAYBACK_STATUS_REMOVED
 * 
 * \par ���l
 * CriAtomExPlaybackStatus��AtomEx�v���[���[�̃X�e�[�^�X�ł͂Ȃ��A
 * �v���[���[�ōĐ����s�����i ::criAtomExPlayer_Start �֐������s�����j
 * �����̃X�e�[�^�X�ł��B<br>
 * <br>
 * �Đ����̉������\�[�X�́A��������~���ꂽ���_�Ŕj������܂��B<br>
 * ���̂��߁A�ȉ��̃P�[�X�ōĐ����̃X�e�[�^�X��
 * CRIATOMEXPLAYBACK_STATUS_REMOVED �ɑJ�ڂ��܂��B<br>
 * - �Đ������������ꍇ�B
 * - criAtomExPlayback_Stop �֐��ōĐ����̉������~�����ꍇ�B
 * - ���v���C�I���e�B�̔������N�G�X�g�ɂ��Đ����̃{�C�X���D�����ꂽ�ꍇ�B
 * - �Đ����ɃG���[�����������ꍇ�B
 * 
 * \sa criAtomExPlayer_Start, criAtomExPlayback_GetStatus, criAtomExPlayback_Stop
 */
typedef enum CriAtomExPlaybackStatusTag {
	CRIATOMEXPLAYBACK_STATUS_PREP = 1,	/*JP< �Đ�������	*/
	CRIATOMEXPLAYBACK_STATUS_PLAYING,	/*JP< �Đ���		*/
	CRIATOMEXPLAYBACK_STATUS_REMOVED,	/*JP< �폜���ꂽ	*/
	CRIATOMEXPLAYBACK_STATUS_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPlaybackStatus;

/*JP
 * \brief �Đ����̃^�C�v
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * AtomEx�v���[���[�ōĐ�����܂��͍Đ����̉����́A�Đ����̃^�C�v�ł��B<br>
 * \sa CriAtomExSourceInfo
 */
typedef enum CriAtomExSourceTypeTag {
	CRIATOMEX_SOURCE_TYPE_NONE = 0,				/*JP< ���ݒ�					*/
	CRIATOMEX_SOURCE_TYPE_CUE_ID,				/*JP< �L���[ID					*/
	CRIATOMEX_SOURCE_TYPE_CUE_NAME,				/*JP< �L���[��					*/
	CRIATOMEX_SOURCE_TYPE_CUE_INDEX,			/*JP< �L���[�C���f�b�N�X		*/
	CRIATOMEX_SOURCE_TYPE_DATA,					/*JP< �I���������f�[�^			*/
	CRIATOMEX_SOURCE_TYPE_FILE,					/*JP< �t�@�C����				*/
	CRIATOMEX_SOURCE_TYPE_CONTENT_ID,			/*JP< CPK�R���e���cID			*/
	CRIATOMEX_SOURCE_TYPE_WAVE_ID,				/*JP< �����f�[�^ID				*/
	CRIATOMEX_SOURCE_TYPE_VIBRATION_ID,			/*JP< �U��ID					*/
	CRIATOMEX_SOURCE_TYPE_SOUND_GENERATOR_ID,	/*JP< �T�E���h�W�F�l���[�^ID	*/
	CRIATOMEX_SOURCE_TYPE_RAW_PCM_FLOAT_ID,		/*JP< RawPcmFloatID				*/
	CRIATOMEX_SOURCE_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExSourceType;

/*JP
 * \brief �Đ����̏��
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * AtomEx�v���[���[�ōĐ�����܂��͍Đ����̉����́A�Đ����i�����Đ�����^���Ă���j�̏��ł��B<br>
 * ::criAtomExPlayback_GetSource �֐��Ŏ擾�\�ł��B<br>
 * �擾�����������ɁA::criAtomExAcb_GetCueInfoByIndex �֐����𗘗p���邱�ƂŁA
 * ���ڍׂȏ����擾���邱�Ƃ��ł��܂��B
 * \par ���l
 * �Đ����̃^�C�v�ɂ���āA�擾�ł����񂪈قȂ�܂��B<br>
 * type���Q�Ƃ��A���p��source�̒��̂ǂ̍\���̂Ƃ��ăA�N�Z�X���邩��I�����Ă��������B<br>
 * \code
 * CriAtomExSourceInfo source;
 * criAtomExPlayback_GetSource(playback_id, &source);
 * 
 * switch (source.type) {
 * case CRIATOMEXPLAYBACK_SOURCE_TYPE_CUE_ID:
 * 	{
 * 		CriAtomExCueInfo cue_info;
 * 		criAtomExAcb_GetCueInfoById(source.info.cue_id.acb, source.info.cue_id.id, &cue_info);
 *			:
 * 	}
 * 	break;
 * 		:
 * }
 * \endcode
 * \sa criAtomExPlayback_GetSource, criAtomExAcb_GetCueInfoByIndex
 */
typedef struct CriAtomExSourceInfoTag {
	/*JP �Đ����̃^�C�v */
	CriAtomExSourceType type;

	/*JP �Đ�����񋤗p�� */
	union CriAtomExSourceInfoInfoTag {
		/*JP �L���[ID��� */
		struct CriAtomExSourceInfoCueIdTag {
			/*JP ACB�n���h�� */
			CriAtomExAcbHn acb;
			/*JP �L���[ID */
			CriAtomExCueId id;
		} cue_id;
		/*JP �L���[����� */
		struct CriAtomExSourceInfoCueNameTag {
			/*JP ACB�n���h�� */
			CriAtomExAcbHn acb;
			/*JP �L���[�� */
			const CriChar8 *name;
		} cue_name;
		/*JP �L���[�C���f�b�N�X��� */
		struct CriAtomExSourceInfoCueIndexTag {
			/*JP ACB�n���h�� */
			CriAtomExAcbHn acb;
			/*JP �L���[�C���f�b�N�X */
			CriAtomExCueIndex index;
		} cue_index;
		/*JP �I���������f�[�^��� */
		struct CriAtomExSourceInfoDataTag {
			/*JP �������A�h���X */
			void *buffer;
			/*JP �T�C�Y */
			CriSint32 size;
		} data;
		/*JP �t�@�C����� */
		struct CriAtomExSourceInfoFileTag {
			/*JP �o�C���_�[�n���h�� */
			CriFsBinderHn binder;
			/*JP �t�@�C���p�X */
			const CriChar8 *path;
		} file;
		/*JP CPK�R���e���cID��� */
		struct CriAtomExSourceInfoContentIdTag {
			/*JP �o�C���_�[�n���h�� */
			CriFsBinderHn binder;
			/*JP �R���e���cID */
			CriSint32 id;
		} content_id;
		/*JP �g�`�f�[�^ID��� */
		struct CriAtomExSourceInfoWaveIdTag {
			/*JP AWB�n���h�� */
			CriAtomAwbHn awb;
			/*JP �g�`�f�[�^ID */
			CriAtomExWaveId id;
		} wave_id;
		/*JP �U��ID��� */
		struct CriAtomExSourceInfoVibrationIdTag {
			/*JP �U���f�[�^ID */
			CriAtomExVibrationId id;
		} vibration_id;
		struct CriAtomExSourceInfoVibrationNameTag {
			/*JP �U���f�[�^�� */
			const CriChar8 *name;
		} vibration_name;
		/* �T�E���h�W�F�l���[�^ID��� */
		struct CriAtomExSourceInfoSoundGeneratorParameterTag {
			/*JP ���g�� */
			CriFloat32 frequency;
			/*JP �g�` */
			CriAtomWaveType wave_type;
		} sound_generator_parameter;
		/* RawPCM FloatID��� */
		struct CriAtomExSourceInfoRawPcmFloatParameterTag {
			/*JP �f�[�^�A�h���X */
			CriFloat32 *data;
			/*JP ���T���v���� */
			CriUint32 total_samples;
		} raw_pcm_float_parameter;
	} info;
} CriAtomExSourceInfo;

/*JP
 * \brief �Đ��C�x���g
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * �Đ��C�x���g�̎�ʂ������l�ł��B<br>
 * �Đ��C�x���g�R�[���o�b�N�Ɉ����Ƃ��ēn����܂��B<br>
 * \sa CriAtomExPlaybackEventCbFunc, criAtomExPlayer_SetPlaybackEventCallback
 */
typedef enum CriAtomExPlaybackEventTag {
	/*JP
	 * \brief �V�K�Đ����\�[�X�̊m��
	 * \par ����:
	 * �L���[�̍Đ��ɕK�v�ȃ��\�[�X���m�ۂ��ꂽ���Ƃ������l�ł��B<br>
	 * ���\�[�X�m�ێ��_�ł̓{�C�X�̊��蓖�Ă͍s���Ă��炸�A
	 * ����������Ă��܂���i�o�[�`������������Ԃō쐬����܂��j�B
	 */
	CRIATOMEX_PLAYBACK_EVENT_ALLOCATE = 0,
	
	/*JP
	 * \brief �{�C�X�̊��蓖��
	 * \par ����:
	 * �o�[�`������Ԃ̍Đ����\�[�X�ɑ΂��ă{�C�X�����蓖�Ă�ꂽ���Ƃ������l�ł��B<br>
	 * �{�C�X�����蓖�Ă�ꂽ���ƂŁA�L���[�̔������J�n����܂��B
	 * \par ���l:
	 * �L���[�ɕ����̔g�`�f�[�^���܂܂��ꍇ�A�����ꂩ1�̔g�`�f�[�^���Đ����ꂽ���_�Ŗ{�C�x���g���������܂��B<br>
	 * �i�L���[�Đ��Ɋ֘A����{�C�X�̐���0����1�ɑ���u�Ԃɖ{�C�x���g���������܂��B�j<br>
	 * ���Ƀ{�C�X�����蓖�Ă�ꂽ��ԂŁA����ɒǉ��̃{�C�X�����蓖�Ă���^�C�~���O�ł͖{�C�x���g�͔����܂���B
	 */
	CRIATOMEX_PLAYBACK_EVENT_FROM_VIRTUAL_TO_NORMAL,
	
	/*JP
	 * \brief �o�[�`������
	 * \par ����:
	 * �L���[�̍Đ����o�[�`���������ꂽ���Ƃ������l�ł��B<br>
	 * �ȉ��̂����ꂩ�̗v���ɂ��A�������̃L���[����{�C�X���؂藣���ꂽ�ꍇ�ɔ������܂��B<br>
	 * - �L���[�Ɋ܂܂��g�`�f�[�^���I�[�܂ōĐ��������߁A�{�C�X���s�v�ɂȂ���
	 * - ::criAtomExPlayer_Stop �֐����̌Ăяo���ɂ��A�Đ����̔g�`�f�[�^����~���ꂽ
	 * - �v���C�I���e�B����ɂ��A�Đ����̔g�`�f�[�^����~����A�{�C�X���D�����ꂽ
	 * 
	 * \par ���l:
	 * �{�C�x���g�́A�L���[�Ɋ܂܂��"�g�`�f�[�^"���Đ�����Ȃ��Ȃ�����Ԃ������܂��B<br>
	 * �{�C�x���g�������_�ł́A�L���[�̍Đ��͏I�����Ă��܂���B<br>
	 * �i�L���[�̍Đ����I�������ۂɂ́A�ʓr ::CRIATOMEX_PLAYBACK_EVENT_REMOVE �C�x���g���������܂��B�j<br>
	 * <br>
	 * �L���[�ɕ����̔g�`�f�[�^���܂܂��ꍇ�A�S�Ă̔g�`�f�[�^���Đ�����Ȃ��Ȃ������_�Ŗ{�C�x���g���������܂��B<br>
	 * �i�L���[�Đ��Ɋ֘A����{�C�X�̐���1����0�ɑ���u�Ԃɖ{�C�x���g���������܂��B�j<br>
	 * �����̃{�C�X�����蓖�Ă�ꂽ��Ԃł��̂�����1����~���ꂽ�ꍇ�ɂ́A�{�C�x���g�͔����܂���B
	 */
	CRIATOMEX_PLAYBACK_EVENT_FROM_NORMAL_TO_VIRTUAL,
	
	/*JP
	 * \brief �Đ����\�[�X�̉��
	 * \par ����:
	 * �Đ����\�[�X��������ꂽ���Ƃ������l�ł��B<br>
	 * �L���[�̍Đ������������ۂ�A�Đ���~�v���ɂ��L���[����~���ꂽ�ꍇ�ɖ{�C�x���g���������܂��B
	 * \par ���l:
	 * �L���[�Ɋ܂܂��g�`�f�[�^���Đ�����Ă���ꍇ�A
	 * �{�C�x���g�����O�ɁA�K�� ::CRIATOMEX_PLAYBACK_EVENT_FROM_NORMAL_TO_VIRTUAL �C�x���g���������܂��B
	 */
	CRIATOMEX_PLAYBACK_EVENT_REMOVE,
	
	CRIATOMEX_PLAYBACK_EVENT_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExPlaybackEvent;

/*JP
 * �Đ����ڍ�
 * \ingroup ATOMEXLIB_PLAYBACK
 * \par ����:
 * �Đ��C�x���g�������ɁA���Y�Đ��Ɋւ���ڍ׏���ʒm���邽�߂̍\���̂ł��B<br>
 * �Đ��C�x���g�R�[���o�b�N�Ɉ����Ƃ��ēn����܂��B<br>
 * \sa CriAtomExPlaybackEventCbFunc, criAtomExPlayer_SetPlaybackEventCallback
 */
typedef struct CriAtomExPlaybackInfoDetailTag {
	CriAtomExPlayerHn player;			/*JP< �Đ����̃v���[���[	*/
	CriAtomExPlaybackId id;				/*JP< �Đ�ID			*/
} CriAtomExPlaybackInfoDetail;

/*JP
 * �Đ��C�x���g�R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	playback_event		���������C�x���g
 * \param[in]	info				�ڍ׏��
 * \par ����:
 * �Đ��C�x���g�̒ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomExPlayer_SetPlaybackEventCallback �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * �Đ��C�x���g�������ɃR�[���o�b�N���󂯎�邱�Ƃ��\�ƂȂ�܂��B<br>
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomExPlayer_SetPlaybackEventCallback, CriAtomExPlaybackEvent, CriAtomExPlaybackInfoDetail
 */
typedef void (CRIAPI *CriAtomExPlaybackEventCbFunc)(void *obj,
	CriAtomExPlaybackEvent playback_event, const CriAtomExPlaybackInfoDetail *info);

/*==========================================================================
 *      CRI AtomEx Fader API
 *=========================================================================*/
/*JP
 * \brief �t�F�[�_�[�A�^�b�`�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_FADER
 * \par ����:
 * ::criAtomExPlayer_AttachFader �֐��̈����Ɏw�肷��A�t�F�[�_�[�A�^�b�`�p�̃R���t�B�O�\���̂ł��B<br>
 * \attention
 * ����w��\�ȃp�����[�^�[�͂���܂��񂪁A�����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomExFader_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomExFader_SetDefaultConfig, criAtomExPlayer_CalculateWorkSizeForFader, criAtomExPlayer_AttachFader
 */
typedef struct CriAtomExFaderConfigTag {
	CriSint32 reserved;					/*JP< �\��l�i0���w�肵�Ă��������j	*/
} CriAtomExFaderConfig;

/*==========================================================================
 *      CRI AtomEx D-BAS API
 *=========================================================================*/
/*JP
 * \brief AtomEx D-BAS ID
 * \ingroup ATOMEXLIB_DBAS
 * \par ����:
 * CriAtomExDbasId �́AD-BAS�Ǘ��p��ID�ł��B<br>
 * ::criAtomExDbas_Create �֐���D-BAS���쐬����Ǝ擾�ł��܂��B
 * <br>
 * �A�v���P�[�V����������D-BAS ID�𗘗p����̂́AD-BAS�̔j�����݂̂ł��B
 * \sa criAtomExDbas_Create, criAtomExDbas_Destroy
 */
typedef CriAtomDbasId CriAtomExDbasId;

/*JP
 * \brief D-BAS�쐬�p�����[�^�[�\����
 * \ingroup ATOMEXLIB_DBAS
 * \par ����:
 * ::criAtomExDbas_Create �֐��̈����Ɏw�肷��AD-BAS�̍쐬�p�����[�^�[�\���̂ł��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExDbas_SetDefaultConfig
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExDbas_Create, criAtomExDbas_CalculateWorkSize, criAtomExDbas_SetDefaultConfig
 */
typedef CriAtomDbasConfig CriAtomExDbasConfig;

/* ========================================================================*/
/*       CRI AtomEx Streaming Cache API                                      */
/* ========================================================================*/
/*JP
 * \brief �X�g���[�~���O�L���b�V��ID
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \par ����:
 * CriAtomExStreamingCacheId �́A�X�g���[�~���O�L���b�V���Ǘ��pID�ł��B<br>
 * ::criAtomExStreamingCache_Create �֐��ŃX�g���[�~���O�L���b�V�����쐬����Ǝ擾�ł��܂��B<br>
 * \sa criAtomExStreamingCache_Create
 */
typedef CriAtomStreamingCacheId CriAtomExStreamingCacheId;

/*JP
 * \brief �X�g���[�~���O�L���b�V���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \par ����:
 * �v���[���[�ɃX�g���[�~���O�L���b�V�����쐬����ۂɁA
 * �L���b�V���\�ȃt�@�C���T�C�Y����o�^���邽�߂̍\���̂ł��B<br>
 * ::criAtomExStreamingCache_CalculateWorkSize �֐��A
 * ::criAtomExStreamingCache_Create �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomStreamingCache_CalculateWorkSize, criAtomStreamingCache_Create
 */
typedef CriAtomStreamingCacheConfig CriAtomExStreamingCacheConfig;

/*==========================================================================
 *      CRI AtomEx 3D API
 *=========================================================================*/
/*JP
 * \brief 3�����x�N�g���\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3�����x�N�g�����������߂̍\���̂ł��B<br>
 * \sa CriAtomEx3dListener, CriAtomEx3dSource
 */
typedef struct CriAtomExVectorTag {
	CriFloat32 x;	/*JP< X���̗v�f */
	CriFloat32 y;	/*JP< Y���̗v�f */
	CriFloat32 z;	/*JP< Z���̗v�f */
} CriAtomExVector;

/*JP
 * \brief 3D�����n���h���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����n���h�����쐬����ꍇ�Ɏg�p����\���̂ł��B<br>
 * �����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomEx3dSource_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomEx3dSource_SetDefaultConfig, criAtomEx3dSource_CalculateWorkSize, criAtomEx3dSource_Create
 */
typedef struct CriAtomEx3dSourceConfigTag {
	/*JP
		\brief �����ɂ��{�C�X�v���C�I���e�B������L���ɂ���
		\par ����:
		�����ɂ��v���C�I���e�B������L���ɂ��邩�ǂ�����ݒ肵�܂��B<br>
		�{�p�����[�^�[��CRI_TRUE�ɐݒ肵��3D�����n���h�����쐬����ƁA����3D�����n���h���Ŕ��������
		3D���̃{�C�X�v���C�I���e�B�́A���X�i�[�Ƃ̋����ɂ���Č������󂯂�悤�ɂȂ�܂��B<br>
		�{�C�X�v���C�I���e�B�̌����l�́A���̃{�C�X�ɐݒ肳��Ă���ŏ�������0�A�ő勗����-255�ł��B<br>
		\par ���l:
		�����ɂ��{�C�X�v���C�I���e�B�����́A���̃{�C�X�v���C�I���e�B�ݒ�Ɖ��Z����ēK�p����܂��B<br>
		���Ȃ킿�A�ŏI�I�ȃ{�C�X�v���C�I���e�B�́A�ȉ��̂��ꂼ������Z�����l�ɂȂ�܂��B<br>
		- �f�[�^�ɐݒ肳��Ă���l
		- ::criAtomExPlayer_SetVoicePriority �֐��ɂ��ݒ�l
		- �����ɂ��{�C�X�v���C�I���e�B�����l
		
		�{�p�����[�^�[�̃f�t�H���g�l��CRI_FALSE�i�����ɂ��{�C�X�v���C�I���e�B�����j�ł��B	
		\sa criAtomExPlayer_SetVoicePriority
	*/
	CriBool enable_voice_priority_decay;

	/*JP
	 *	\brief 3D�����ɂ�����ʒu�̃����_�����Ɋւ�����W���X�g�̗v�f���̍ő�l
	 *	\par ����:
	 *	3D�����ɂ�����ʒu�̃����_�����Ɋւ�����W���X�g�̗v�f���̍ő�l��
	 *	�ݒ肵�܂��B<br>
	 *	�{�ݒ�l�ɏ]���āA�����I�Ɉʒu���W���X�g�̗̈���m�ۂ��܂��B
	 *	\par ���l:
	 *	3D�����ɂ�����ʒu�̃����_�������g�p���Ȃ��ꍇ��
	 *	::CriAtomEx3dSourceRandomPositionConfig �\���̂̕ϐ� calculation_type ��
	 *	�΂��āA ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_LIST ���w��
	 *	���Ȃ��ꍇ�A�{�ݒ�l�� 0 ���w�肵�Ă��������B
	 *	\sa CriAtomEx3dSourceRandomPositionConfig
	 */
	CriUint32 random_position_list_max_length;
} CriAtomEx3dSourceConfig;

/*JP
 * \brief 3D�����n���h�����X�g�쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����n���h�����X�g���쐬����ꍇ�Ɏg�p����\���̂ł��B<br>
 * ����w��\�ȃp�����[�^�[�͂���܂��񂪁A�����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomEx3dSourceList_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomEx3dSourceList_SetDefaultConfig, criAtomEx3dSourceList_CalculateWorkSize, criAtomEx3dSourceList_Create
 */
typedef struct CriAtomEx3dSourceListConfigTag {
	CriSint32 reserved;
} CriAtomEx3dSourceListConfig;

/*JP
 * \brief 3D���X�i�[�n���h���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D���X�i�[�n���h�����쐬����ꍇ�Ɏg�p����\���̂ł��B<br>
 * ����w��\�ȃp�����[�^�[�͂���܂��񂪁A�����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomEx3dListener_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomEx3dListener_SetDefaultConfig, criAtomEx3dListener_CalculateWorkSize, criAtomEx3dListener_Create
 */
typedef struct CriAtomEx3dListenerConfigTag {
	CriSint32 reserved;
} CriAtomEx3dListenerConfig;

struct CriAtomEx3dSourceObjTag;
typedef struct CriAtomEx3dSourceObjTag CriAtomEx3dSourceObj;
/*JP
 * \brief 3D�����n���h��
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�������������߂̃n���h���ł��B<br>
 * 3D�|�W�V���j���O�@�\�Ɏg�p���܂��B<br>
 * <br>
 * 3D�����̃p�����[�^�[�A�ʒu���̐ݒ蓙�́A3D�����n���h������Ď��s����܂��B
 * \sa criAtomEx3dSource_Create
 */
typedef CriAtomEx3dSourceObj *CriAtomEx3dSourceHn;

struct CriAtomEx3dSourceListObjTag;
typedef struct CriAtomEx3dSourceListObjTag CriAtomEx3dSourceListObj;
/*JP
 * \brief 3D�����n���h�����X�g
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����n���h�����Ǘ����郊�X�g�n���h���ł��B<br>
 * 3D�|�W�V���j���O�@�\�ɂ�����}���`�|�W�V���j���O�Đ��Ɏg�p���܂��B
 * \sa criAtomEx3dSourceList_Create
 */
typedef CriAtomEx3dSourceListObj *CriAtomEx3dSourceListHn;

struct CriAtomEx3dListenerObjTag;
typedef struct CriAtomEx3dListenerObjTag CriAtomEx3dListenerObj;
/*JP
 * \brief 3D���X�i�[�n���h��
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D���X�i�[���������߂̃n���h���ł��B<br>
 * 3D�|�W�V���j���O�@�\�Ɏg�p���܂��B<br>
 * <br>
 * 3D���X�i�[�̃p�����[�^�[�A�ʒu���̐ݒ蓙�́A3D���X�i�[�n���h������Ď��s����܂��B
 * \sa criAtomEx3dListener_Create
 */
typedef CriAtomEx3dListenerObj *CriAtomEx3dListenerHn;

/*JP
 * \brief 3D���[�W�����n���h���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D���[�W�����n���h�����쐬����ꍇ�Ɏg�p����\���̂ł��B<br>
 * ����w��\�ȃp�����[�^�[�͂���܂��񂪁A�����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomEx3dRegion_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomEx3dRegion_SetDefaultConfig, criAtomEx3dRegion_CalculateWorkSize, criAtomEx3dRegion_Create
 */
typedef struct CriAtomEx3dRegionConfigTag {
	CriSint32 reserved;					/*JP< �\��l�i0���w�肵�Ă��������j	*/
} CriAtomEx3dRegionConfig;

struct CriAtomEx3dRegionObjTag;
typedef struct CriAtomEx3dRegionObjTag CriAtomEx3dRegionObj;
/*JP
 * \brief 3D���[�W�����n���h��
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D���[�W�������������߂̃n���h���ł��B<br>
 * 3D�g�����V�[�o�[�@�\�Ɏg�p���܂��B
 * \sa criAtomEx3dRegion_Create
 */
typedef CriAtomEx3dRegionObj *CriAtomEx3dRegionHn;

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�g�����V�[�o�[�n���h�����쐬����ꍇ�Ɏg�p����\���̂ł��B<br>
 * ����w��\�ȃp�����[�^�[�͂���܂��񂪁A�����p�����[�^�[���ǉ������\�������邽�߁A
 * �{�\���̂��g�p����ۂɂ� ::criAtomEx3dTransceiver_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomEx3dTransceiver_SetDefaultConfig, criAtomEx3dTransceiver_CalculateWorkSize, criAtomEx3dTransceiver_Create
 */
typedef struct CriAtomEx3dTransceiverConfigTag {
	CriSint32 reserved;					/*JP< �\��l�i0���w�肵�Ă��������j */
} CriAtomEx3dTransceiverConfig;

struct CriAtomEx3dTransceiverObjTag;
typedef struct CriAtomEx3dTransceiverObjTag CriAtomEx3dTransceiverObj;
/*JP
 * \brief 3D�g�����V�[�o�[�n���h��
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�g�����V�[�o�[���������߂̃n���h���ł��B<br>
 * 3D�g�����V�[�o�[�@�\�Ɏg�p���܂��B<br>
 * <br>
 * 3D�g�����V�[�o�[�̃p�����[�^�[�A�ʒu���̐ݒ蓙�́A3D�g�����V�[�o�[�n���h������Ď��s����܂��B
 * \sa criAtomEx3dTransceiver_Create
 */
typedef CriAtomEx3dTransceiverObj *CriAtomEx3dTransceiverHn;

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�̎Z�o���@
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�̎Z�o���@�̒�`�ł��B<br>
 * \sa CriAtomEx3dSourceRandomPositionConfig
 */
typedef enum CriAtomEx3dSourceRandomPositionCalculationTypeTag {
	/*JP
	 * \brief �ݒ薳��
	 * \par ����:
	 * ���W�Z�o�������s���܂���B
	 * \attention
	 * �{��`�͏��擾�p�ɂ̂ݗp�����܂��B<br>
	 * ���̂��߁A�{�ݒ�l�� ::CriAtomEx3dSourceRandomPositionConfig �\���̂�
	 * �w�肵�� ::criAtomEx3dSource_SetRandomPositionConfig �֐������s�����ꍇ�A
	 * �G���[���������܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_NONE = -1,

	/*JP
	 * \brief ��`
	 * \par ����:
	 * xz ���ʏ�̋�`���ō��W���Z�o���܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_RECTANGLE = 0,

	/*JP
	 * \brief ������
	 * \par ����:
	 * xyz ��ԏ�̒����̓��ō��W���Z�o���܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CUBOID,

	/*JP
	 * \brief �~
	 * \par ����:
	 * xz ���ʏ�̉~���ō��W���Z�o���܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CIRCLE,

	/*JP
	 * \brief �~��
	 * \par ����:
	 * xyz ��ԏ�̉~�����ō��W���Z�o���܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CYLINDER,

	/*JP
	 * \brief ��
	 * \par ����:
	 * xyz ��ԏ�̋����ō��W���Z�o���܂��B
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_SPHERE,

	/*JP
	 * \brief �R�[���o�b�N
	 * \par ����:
	 * ���[�U�[��`�̃R�[���o�b�N�֐����ɂč��W�����肵�܂��B
	 * \par ���l:
	 * �ʓr���W�Z�o���s���R�[���o�b�N�֐��̓o�^���K�v�ƂȂ�܂��B
	 * \sa CriAtomEx3dSourceRandomPositionCalculationCbFunc, criAtomEx3dSource_SetRandomPositionCalculationCallback
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CALLBACK,

	/*JP
	 * \brief ���W���X�g
	 * \par ����:
	 * ���O�ɐݒ肵�����W���X�g�����ɍ��W�����肵�܂��B
	 * \par ���l:
	 * �ʓr���W���X�g�̐ݒ肪�K�v�ƂȂ�܂��B
	 * \sa criAtomEx3dSource_SetRandomPositionList
	 */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_LIST,

	/* enum size is 4bytes */
	CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomEx3dSourceRandomPositionCalculationType;

/*JP
 * \brief 3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\����
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����̈ʒu�̃����_�����Ɋւ���ݒ���܂Ƃ߂��\���̂ł��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomEx3dSource_SetDefaultConfigForRandomPosition
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomEx3dSource_SetRandomPositionConfig, criAtomEx3dSource_SetDefaultConfigForRandomPosition
 */
typedef struct CriAtomEx3dSourceRandomPositionConfigTag {
	/*JP
	 * \brief ����3D�����ɒǏ]���邩�ǂ���
	 * \par ����:
	 * �����_���Ɍ��肳�ꂽ3D����������3D�����ɒǏ]���ē������ǂ�����ݒ肵�܂��B<br>
	 * CRI_TRUE�̏ꍇ��3D�����̈ʒu������ɒǏ]���܂��B<br>
	 * CRI_FALSE�̏ꍇ��3D�����ɒǏ]�����A�Đ��J�n���̈ʒu�ɗ��܂�܂��B
	 */
	CriBool follows_original_source;

	/*JP
	 * \brief ���W�̎Z�o���@
	 * \par ����:
	 * �����_���ȍ��W�����肷��ۂ̎Z�o���@��ݒ肵�܂��B<br>
	 * �ڍׂ� ::CriAtomEx3dSourceRandomPositionCalculationType ���Q�Ƃ��Ă��������B
	 * \sa CriAtomEx3dSourceRandomPositionCalculationType
	 */
	CriAtomEx3dSourceRandomPositionCalculationType calculation_type;

	/*JP
	 * \brief ���W�̎Z�o���@�Ɋւ���e��p�����[�^�[�z��
	 * \par ����:
	 * �e���W�̎Z�o���@�ɂĎg�p����p�����[�^�[�z��ł��B<br>
	 * calculation_type �ɐݒ肵�����W�̎Z�o���@�ɑ΂���p�����[�^�[�z���
	 * �΂���e�v�f�̐ݒ�͈ȉ��̒ʂ�ł��B
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_RECTANGLE
	 *     - 0: ���E��(x��), 1: �O�㕝(z��), 2: 0.0f
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CUBOID
	 *     - 0: ���E��(x��), 1: �O�㕝(z��), 2: �㉺��(y��)
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CIRCLE
	 *     - 0: ���a, 1: 0.0f, 2: 0.0f
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CYLINDER
	 *     - 0: ���a, 1: �㉺��(y��), 2: 0.0f
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_SPHERE
	 *     - 0: ���a, 1: 0.0f, 2: 0.0f
	 * .
	 * �Ȃ��A�e�}�`�͌���3D�����𒆐S�Ƃ��܂��B
	 * \par ���l:
	 * �ȉ��̍��W�̎Z�o���@�ł́A�{�p�����[�^�[�͖�������܂��B
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CALLBACK
	 * - ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_LIST
	 * .
	 * \sa CriAtomEx3dSourceRandomPositionCalculationType
	 */
	CriFloat32 calculation_parameters[CRIATOMEX3DSOURCE_MAX_RANDOM_POSITION_CALCULATION_PARAMETERS];
} CriAtomEx3dSourceRandomPositionConfig;

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���ʂ̏ڍ�
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�̌��ʏo�͎��ɁA���Y�Đ��Ɋւ���ڍ׏���ʒm���邽�߂̍\���̂ł��B<br>
 * 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���ʃR�[���o�b�N�֐��Ɉ����Ƃ��ēn����܂��B
 * \sa CriAtomEx3dSourceRandomPositionResultCbFunc
 */
typedef struct CriAtomEx3dSourceRandomPositionResultInfoDetailTag {
	CriAtomEx3dSourceHn ex_3d_source;	/*JP< ����3D�����̃n���h�� */
	CriAtomExVector result_pos;			/*JP< �ŏI�I�Ȉʒu���W */
	CriAtomExVector offset_pos;			/*JP< ����3D�����̈ʒu�ɑ΂���I�t�Z�b�g���W */
} CriAtomEx3dSourceRandomPositionResultInfoDetail;

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�Z�o�R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_3D
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	ex_3d_source		����3D�����̃n���h��
 * \param[out]	result_pos			�������ʂ̈ʒu
 * \par ����:
 * 3D�����̃����_�����ɂ�����ʒu���W�Z�o�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomEx3dSource_SetRandomPositionCalculationCallback �֐������s���邱�ƂŁA
 * �R�[���o�b�N�֐��̓o�^���\�ł��B<br>
 * �{�R�[���o�b�N�֐��́A3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���Z�o����ۂ�
 * �Ăяo����܂��B<br>
 * �A�v���P�[�V�������ňʒu���W�����肵�����ꍇ�ɂ����p���������B
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �{�R�[���o�b�N�֐��� ::CriAtomEx3dSourceRandomPositionConfig �\���̂�
 * ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CALLBACK ���w�肵���Ƃ��̂݌Ăяo����܂��B
 * \sa CriAtomEx3dSourceRandomPositionConfig, criAtomEx3dSource_SetRandomPositionCalculationCallback
 */
typedef void (CRIAPI *CriAtomEx3dSourceRandomPositionCalculationCbFunc)(
	void *obj, const CriAtomEx3dSourceHn ex_3d_source, CriAtomExVector *result_pos);

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���ʃR�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_3D
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	result_info			�ʒu���W���ʂ̏ڍ�
 * \par ����:
 * 3D�����̈ʒu�̃����_�����ɂ�����ʒu�����ʃR�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomEx3dSource_SetRandomPositionResultCallback �֐������s���邱�ƂŁA
 * �R�[���o�b�N�֐��̓o�^���\�ł��B<br>
 * �{�R�[���o�b�N�֐��́A3D�����̈ʒu�̃����_�������L���ȏꍇ�A�ʒu���W�̎Z�o���s��ꂽ���
 * �Ăяo����܂��B<br>
 * �A�v���P�[�V�������Ń����_�������ꂽ�ʒu���W�����擾�������ꍇ�ɂ����p���������B
 * \par ���l:
 * ����3D�����ɒǏ]����ݒ肪�L���̏ꍇ�A����3D�����̈ʒu�̕ύX�ɉ����Ė{�R�[���o�b�N�֐������s����܂��B
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B
 * \sa criAtomEx3dSource_SetRandomPositionResultCallback, CriAtomEx3dSourceRandomPositionResultInfoDetail
 */
typedef void (CRIAPI *CriAtomEx3dSourceRandomPositionResultCbFunc)(
	void *obj, const CriAtomEx3dSourceRandomPositionResultInfoDetail *result_info);

/*==========================================================================
 *      CRI AtomEx DSP API
 *=========================================================================*/

/*JP
 * \brief �s�b�`�V�t�^DSP�̃A�^�b�`�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_DSP
 * \par ����:
 * �s�b�`�V�t�^DSP���{�C�X�v�[���ɃA�^�b�`���邽�߂̍\���̂ł��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForDspPitchShifter
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AttachDspPitchShifter, criAtomExVoicePool_CalculateWorkSizeForDspPitchShifter, criAtomExVoicePool_SetDefaultConfigForDspPitchShifter
 */
typedef struct CriAtomExDspPitchShifterConfigTag {
	/*JP
		\brief �쐬����DSP�̐�
		\par ����:
		�A�^�b�`��̃{�C�X���Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 num_dsp;
	
	/*JP
		\brief DSP�̍ő�`�����l����
		\par ����:
		DSP�������\�ȍő�`�����l�����ł��B<br>
		�A�^�b�`��{�C�X�v�[���̃v���[���[�ݒ�̍ő�`�����l�����imax_channels�j�Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 max_channels;
	
	/*JP
		\brief DSP�̍ő�T���v�����O���[�g
		\par ����:
		DSP�������\�ȍő�T���v�����O���[�g�ł��B<br>
		�A�^�b�`��{�C�X�v�[���̃v���[���[�ݒ�̍ő�T���v�����O���[�g�imax_sampling_rate�j�Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 max_sampling_rate;
	
	/*JP
		\brief DSP�ŗL�ݒ�̍\����
		\par ����:
		DSP�ŗL�̃R���t�B�O�ݒ���s���܂��B<br>
		�ڂ����� ::CriAtomDspPitchShifterConfig �����Q�Ƃ��������B<br>
	*/
	CriAtomDspPitchShifterConfig specific;
} CriAtomExDspPitchShifterConfig;

/*JP
 * \brief �^�C���X�g���b�`DSP�̃A�^�b�`�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_DSP
 * \par ����:
 * �^�C���X�g���b�`DSP���{�C�X�v�[���ɃA�^�b�`���邽�߂̍\���̂ł��B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExVoicePool_SetDefaultConfigForDspTimeStretch
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExVoicePool_AttachDspTimeStretch, criAtomExVoicePool_CalculateWorkSizeForDspTimeStretch, criAtomExVoicePool_SetDefaultConfigForDspTimeStretch
 */
typedef struct CriAtomExDspTimeStretchConfigTag {
	/*JP
		\brief �쐬����DSP�̐�
		\par ����:
		�A�^�b�`��̃{�C�X���Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 num_dsp;
	
	/*JP
		\brief DSP�̍ő�`�����l����
		\par ����:
		DSP�������\�ȍő�`�����l�����ł��B<br>
		�A�^�b�`��{�C�X�v�[���̃v���[���[�ݒ�̍ő�`�����l�����imax_channels�j�Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 max_channels;
	
	/*JP
		\brief DSP�̍ő�T���v�����O���[�g
		\par ����:
		DSP�������\�ȍő�T���v�����O���[�g�ł��B<br>
		�A�^�b�`��{�C�X�v�[���̃v���[���[�ݒ�̍ő�T���v�����O���[�g�imax_sampling_rate�j�Ɠ����l���w�肷��K�v������܂��B<br>
	*/
	CriSint32 max_sampling_rate;
	
	/*JP
		\brief DSP�ŗL�ݒ�̍\����
		\par ����:
		DSP�ŗL�̃R���t�B�O�ݒ���s���܂��B<br>
		�ڂ����� ::CriAtomDspTimeStretchConfig �����Q�Ƃ��������B<br>
	*/
	CriAtomDspTimeStretchConfig specific;
} CriAtomExDspTimeStretchConfig;

/*==========================================================================
 *      CRI AtomEx Tween API
 *=========================================================================*/
/*JP
 * \brief Tween�̃p�����[�^�[�^�C�v
 * \ingroup ATOMEXLIB_TWEEN
 * \par ����:
 * Tween�ő��삷��p�����[�^�[�̃^�C�v�ł��B<br>
 * \sa CriAtomExTweenConfig
 */
typedef enum CriAtomExTweenParameterTypeTag {
	/*JP
		\brief ��{�p�����[�^�[
		\par ����:
		�{�����[���A�s�b�`���ACriAtomExParameterId�Ŏw�肷��p�����[�^�[�𑀍삷��ۂɎw�肵�܂��B
	*/
	CRIATOMEX_PARAMETER_TYPE_BASIC,

	/*JP
		\brief AISAC�R���g���[���l
		\par ����:
		AISAC�R���g���[���l�𑀍삷��ۂɎw�肵�܂��B
	*/
	CRIATOMEX_PARAMETER_TYPE_AISAC,

	/* enum size is 4bytes */
	CRIATOMEX_PARAMETER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExTweenParameterType;

/*JP
 * \brief �g�D�C�[���쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_TWEEN
 * \par ����:
 * �g�D�C�[�����쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExTween_Create �֐��̈����Ɏw�肵�܂��B<br>
 * �{�\���̂��g�p����ۂɂ� ::criAtomExTween_SetDefaultConfig �}�N�����g�p���A
 * �\���̂̏��������s���Ă��������B
 * \sa criAtomExTween_SetDefaultConfig, criAtomExTween_CalculateWorkSize, criAtomExTween_Create
 */
typedef struct CriAtomExTweenConfigTag {
	/*JP
		\brief ID�w�苤�p��
		\par ����:
		�p�����[�^�[�^�C�v�ɏ]���A�p�����[�^�[ID�܂���AISAC�R���g���[��ID���w�肵�܂��B
	*/
	union CriAtomExTweenConfigParameterIdTag {
		/*JP
			\brief �p�����[�^�[ID
			\par ����:
			�p�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_BASIC���w�肷��ꍇ�A���̃����o�Ńp�����[�^�[ID���w�肵�܂��B
		*/
		CriAtomExParameterId parameter_id;

		/*JP
			\brief AISAC�R���g���[��ID
			\par ����:
			�p�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_AISAC���w�肷��ꍇ�A���̃����o��AISAC�R���g���[��ID���w�肵�܂��B
		*/
		CriAtomExAisacControlId aisac_control_id;
	} id;

	/*JP
		\brief �p�����[�^�[�^�C�v
		\par ����:
		�p�����[�^�[�^�C�v���w�肵�܂��B
	*/
	CriAtomExTweenParameterType parameter_type;
} CriAtomExTweenConfig;

/*JP
 * \brief �g�D�C�[���n���h��
 * \ingroup ATOMEXLIB_TWEEN
 * \par ����:
 * CriAtomExTweenHn �́A�g�D�C�[���𑀍삷�邽�߂̃n���h���ł��B<br>
 * �g�D�C�[���Ƃ́A�ȒP�Ȏ菇�Ńp�����[�^�[�̎��ԕω����s�����߂̃��W���[���ł��B
 * ::criAtomExTween_Create �֐��Ńg�D�C�[�����쐬����ƁA
 * �{�֐��̓g�D�C�[������p�ɁA����"�g�D�C�[���n���h��"��Ԃ��܂��B
 * <br>
 * �p�����[�^�[�̎��ԕω��̊J�n���A�g�D�C�[���ɑ΂��čs������́A
 * �S�ăg�D�C�[���n���h������Ď��s����܂��B<br>
 * �܂��AAtomEx�v���[���[�Ƀg�D�C�[�����֘A�Â���ۂɂ��g�p���܂��B
 * \sa criAtomExTween_Create, criAtomExPlayer_AttachTween
 */
typedef struct CriAtomExTweenTag *CriAtomExTweenHn;

/*==========================================================================
 *      CRI AtomEx Voice Event API
 *=========================================================================*/
/*JP
 * \brief �{�C�X�C�x���g
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �{�C�X�C�x���g�̎�ʂ������l�ł��B<br>
 * �{�C�X�C�x���g�R�[���o�b�N�Ɉ����Ƃ��ēn����܂��B<br>
 * \sa CriAtomExVoiceEventCbFunc, criAtomEx_SetVoiceEventCallback
 */
typedef enum CriAtomExVoiceEventTag {
	/*JP
	 * \brief �{�C�X�̐V�K�m��
	 * \par ����:
	 * �{�C�X�v�[������󂫃{�C�X���擾����A�V�K�ɔ������J�n���ꂽ���Ƃ������l�ł��B<br>
	 */
	CRIATOMEX_VOICE_EVENT_ALLOCATE = 0,
	
	/*JP
	 * \brief �{�C�X�̒D�����
	 * \par ����:
	 * �Đ����̃{�C�X���D�����ꂽ���Ƃ������l�ł��B<br>
	 * �Đ����̃{�C�X��1��~����A���̃{�C�X���ʂ̉����̍Đ��ɍė��p����܂����B<br>
	 * ��~�����g�`�f�[�^�ƐV�K�ɍĐ�����g�`�f�[�^�́A
	 * �قȂ�{�C�X���~�b�g�O���[�v�ɏ������Ă��܂��B<br>
	 * �i�ǂ��炩����A�������͗����̔g�`�f�[�^���{�C�X���~�b�g�O���[�v�ɏ������Ă��Ȃ��ꍇ���A
	 * �{�C�X�̒D����蔭�����ɖ{�C�x���g���������܂��B�j<br>
	 */
	CRIATOMEX_VOICE_EVENT_ALLOCATE_AND_REMOVE,
	
	/*JP
	 * \brief �O���[�v���ł̃{�C�X�̒D�����
	 * \par ����:
	 * �Đ����̃{�C�X���D�����ꂽ���Ƃ������l�ł��B<br>
	 * �Đ����̃{�C�X��1��~����A���̃{�C�X���ʂ̉����̍Đ��ɍė��p����܂����B<br>
	 * ::CRIATOMEX_VOICE_EVENT_ALLOCATE_AND_REMOVE �ƈقȂ�A
	 * ��~�����g�`�f�[�^�ƐV�K�ɍĐ�����g�`�f�[�^�Ƃ��A
	 * ����̃{�C�X���~�b�g�O���[�v�ɏ�������ꍇ�ɖ{�C�x���g���������܂��B<br>
	 */
	CRIATOMEX_VOICE_EVENT_ALLOCATE_AND_REMOVE_IN_GROUP,
	
	/*JP
	 * \brief �{�C�X�̒D�����ƃ{�C�X���̒���
	 * \par ����:
	 * �Đ����̃{�C�X���D������A����Ƀ{�C�X���̒������s��ꂽ���Ƃ������l�ł��B<br>
	 * 2�̃{�C�X����~����A���̂���1�̃{�C�X���ʂ̉����̍Đ��ɍė��p����܂��B<br>
	 * �i��~���ꂽ�����̃{�C�X�́A�󂫃{�C�X�Ƃ��ă{�C�X�v�[���ɖ߂���܂��B�j<br>
	 * �����f�[�^�̍Đ��v���𖞂����{�C�X��D����������ʁA�O���[�v���̃{�C�X�������ӂ�A
	 * �O���[�v���Ń{�C�X���𒲐������ꍇ�ɖ{�C�x���g���������܂��B<br>
	 * \par ���l:
	 * ���̃P�[�X�́A�{�C�X���~�b�g�O���[�v���������HCA�f�[�^���Đ����ɁA
	 * ����{�C�X���~�b�g�O���[�v�ɏ�������ADX�f�[�^���Đ������ꍇ���ɔ������܂��B<br>
	 * ADX�f�[�^���Đ����邽�߁A�O���[�v�O��ADX�{�C�X���~�������ʁA
	 * HCA�f�[�^��ADX�f�[�^�̍��v�����{�C�X���~�b�g�O���[�v����𒴂����ꍇ�A
	 * ��v���C�I���e�B��HCA�f�[�^�������1��~�����`�ɂȂ�܂��B<br>
	 * �i1�̔������N�G�X�g�ɑ΂��A2�̉�������~����`�ɂȂ�܂��B�j<br>
	 */
	CRIATOMEX_VOICE_EVENT_ALOOCATE_AND_REMOVE_TWO,
	
	/*JP
	 * \brief �����v���̊��p
	 * \par ����:
	 * �Đ����悤�Ƃ����g�`�f�[�^�̃v���C�I���e�B���A
	 * �S�{�C�X���ōł��Ⴉ�����ꍇ�i���̃{�C�X��D�����Ȃ������ꍇ�j�ɁA
	 * �{�C�x���g���������܂��B<br>
	 */
	CRIATOMEX_VOICE_EVENT_REJECT,
	
	/*JP
	 * \brief �O���[�v���ł̔����v���̊��p
	 * \par ����:
	 * �Đ����悤�Ƃ����g�`�f�[�^�̃v���C�I���e�B���A
	 * ��������O���[�v���ōł��Ⴉ�����ꍇ�i�O���[�v���̑��̃{�C�X��D�����Ȃ������ꍇ�j�ɁA
	 * �{�C�x���g���������܂��B<br>
	 */
	CRIATOMEX_VOICE_EVENT_REJECT_BY_GROUP_LIMIT,
	
	/*JP
	 * \brief �{�C�X�̒�~
	 * \par ����:
	 * �Đ�������Đ���~�v���ɂ��A�{�C�X����~���ꂽ�ꍇ�ɖ{�C�x���g���������܂��B<br>
	 * ��~���ꂽ�{�C�X�́A�󂫃{�C�X�Ƃ��ă{�C�X�v�[���ɖ߂���܂��B<br>
	 */
	CRIATOMEX_VOICE_EVENT_REMOVE,
	
	CRIATOMEX_VOICE_EVENT_ENUM_IS_4BYTE = 0x7FFFFFFF
} CriAtomExVoiceEvent;

/*JP
 * \brief �{�C�X�̏ڍ׏��
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �{�C�X�C�x���g�������̃{�C�X�̏ڍ׏���ێ������\���̂ł��B<br>
 * �{�C�X�C�x���g�R�[���o�b�N�Ɉ����Ƃ��ēn����܂��B<br>
 * \sa CriAtomExVoiceEventCbFunc, criAtomEx_SetVoiceEventCallback
 */
typedef struct CriAtomExVoiceInfoDetailTag {
	CriAtomExPlaybackId playback_id;					/*JP< �Đ�ID					*/
	CriAtomExSourceInfo cue_info;						/*JP< �L���[���				*/
	CriAtomExSourceInfo wave_info;						/*JP< �g�`���					*/
	CriSint32 group_no;									/*JP< �O���[�v�ԍ�				*/
	CriSint32 priority;									/*JP< �v���C�I���e�B			*/
	CriAtomExVoiceControlMethod control_method;			/*JP< �{�C�X������@			*/
	CriAtomExVoiceAllocationMethod allocation_method;	/*JP< �{�C�X�m�ە��@			*/
	CriUint32 identifier;								/*JP< �{�C�X�v�[�����ʎq		*/
	CriAtomExFormat format;								/*JP< �t�H�[�}�b�g���			*/
	CriSint32 sampling_rate;							/*JP< �T���v�����O���g��		*/
	CriSint32 num_channels;								/*JP< �`�����l����				*/
	CriBool streaming_flag;								/*JP< �X�g���[���Đ����ǂ���	*/
	CriAtomPlayerHn atom_player;						/*JP< �����Ɏg�p����v���[���[	*/
} CriAtomExVoiceInfoDetail;

/*JP
 * \brief �{�C�X�C�x���g�R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	voice_event			�����C�x���g
 * \param[in]	request				�����v���̏ڍ׏��
 * \param[in]	removed				��~�{�C�X�̏ڍ׏��
 * \param[in]	removed_in_group	�O���[�v����~�{�C�X�̏ڍ׏��
 * \par ����:
 * �{�C�X�C�x���g�̒ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomEx_SetVoiceEventCallback �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * �{�C�X�C�x���g�������ɃR�[���o�b�N���󂯎�邱�Ƃ��\�ƂȂ�܂��B<br>
 * <br>
 * �R�[���o�b�N�֐��̑�3�`5�����irequest�Aremoved�Aremoved_in_group�j�ɓ���l�́A
 * �{�C�X�C�x���g�̎�ʁi��2������voice_event�̒l�j�ɂ��ȉ��̂悤�ɕς��܂��B<br>
 * <br>
 * (1) CRIATOMEX_VOICE_EVENT_ALLOCATE��<br>
 * ��3����request�ɁA�{�C�X���擾�����������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4�����A��5�����ɂ�NULL������܂��B<br>
 * <br>
 * (2) CRIATOMEX_VOICE_EVENT_ALLOCATE_AND_REMOVE��<br>
 * ��3����request�ɁA�{�C�X���擾�����������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4����removed�ɂ́A�{�C�X��D������A��������~�����Đ��̏�񂪓���܂��B<br>
 * ��5�����ɂ�NULL������܂��B<br>
 * <br>
 * (3) CRIATOMEX_VOICE_EVENT_ALLOCATE_AND_REMOVE_IN_GROUP��<br>
 * ��3����request�ɁA�{�C�X���擾�����������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4�����ɂ�NULL������܂��B<br>
 * ��5����removed_in_group�ɂ́A�{�C�X��D������A��������~�����Đ��̏�񂪓���܂��B<br>
 * <br>
 * (4) CRIATOMEX_VOICE_EVENT_ALOOCATE_AND_REMOVE_TWO��<br>
 * ��3����request�ɁA�{�C�X���擾�����������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4����removed�ɂ́A�{�C�X��D������A��������~�����Đ��̏�񂪓���܂��B<br>
 * ��5����removed_in_group�ɂ́A�O���[�v���̔����������ɂ��A��~���ꂽ�Đ��̏�񂪓���܂��B<br>
 * <br>
 * (5) CRIATOMEX_VOICE_EVENT_REJECT��<br>
 * ��3����request�ɁA�{�C�X�̎擾�����p���ꂽ�������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4�����A��5�����ɂ�NULL������܂��B<br>
 * <br>
 * (6) CRIATOMEX_VOICE_EVENT_REJECT_BY_GROUP_LIMIT��<br>
 * ��3����request�ɁA�{�C�X�̎擾�����p���ꂽ�������N�G�X�g�̏�񂪓���܂��B<br>
 * ��4�����A��5�����ɂ�NULL������܂��B<br>
 * <br>
 * (7) CRIATOMEX_VOICE_EVENT_REMOVE��<br>
 * ��4����removed�ɁA�Đ����I���܂��͒�~�����{�C�X�̏�񂪓���܂��B<br>
 * ��3�����A��5�����ɂ�NULL������܂��B<br>
 * \attention
 * �{�R�[���o�b�N�ł́A�{�C�X�P�ʂ̃��~�b�g����
 *�i�{�C�X�v���C�I���e�B�Ɋ�Â����g�`�P�ʂ̃v���C�I���e�B����j
 * �Ɋւ�����݂̂��擾�\�ł��B<br>
 * �{�C�X�擾�O�ɃL���[���~�b�g����Ŕ��������p���ꂽ�ꍇ�A
 * �{�R�[���o�b�N��CRIATOMEX_VOICE_EVENT_REJECT���̏��͕Ԃ���܂���B<br>
 * �i�J�e�S���L���[�v���C�I���e�B�ɂ�鐧��Ɋւ�����́A����擾�ł��܂���B�j<br>
 * <br>
 * �{�C�X�C�x���g�R�[���o�b�N���_�ł́A request->atom_player
 * �ɂ͍Đ����ׂ������f�[�^���܂��Z�b�g����Ă��܂���B<br>
 * ���̂��߁A�Đ����鉹���f�[�^�̏�񓙂ɂ��ẮA atom_player �ɖ₢���킹���A
 * ::CriAtomExVoiceInfoDetail �\���̂̃����o�l���g�p���Ă��������B<br>
 * <br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_SetVoiceEventCallback, CriAtomExVoiceEvent, CriAtomExVoiceInfoDetail
 */
typedef void (CRIAPI *CriAtomExVoiceEventCbFunc)(
	void *obj, CriAtomExVoiceEvent voice_event,
	const CriAtomExVoiceInfoDetail *request,
	const CriAtomExVoiceInfoDetail *removed,
	const CriAtomExVoiceInfoDetail *removed_in_group);

/*JP
 * \brief �{�C�X���R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	voice_info			�{�C�X�̏ڍ׏��
 * \par ����:
 * �{�C�X���̒ʒm�Ɏg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * ::criAtomEx_EnumerateVoiceInfos �֐��ɖ{�֐��^�̃R�[���o�b�N�֐���o�^���邱�ƂŁA
 * �Đ����̃{�C�X�̏����R�[���o�b�N�Ŏ󂯎�邱�Ƃ��\�ƂȂ�܂��B<br>
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_EnumerateVoiceInfos, CriAtomExVoiceInfoDetail
 */
typedef void (CRIAPI *CriAtomExVoiceInfoCbFunc)(
	void *obj, const CriAtomExVoiceInfoDetail *voice_info);

/*JP
 * \brief �{�C�X��~���擾�p�\����
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �{�C�X��~�����擾���邽�߂̍\���̂ł��B<br>
 * ::CriAtomExMonitoringVoiceStopCbFunc �֐��^�̈����Ƃ��ēn����܂��B<br>
 * \sa CriAtomExMonitoringVoiceStopCbFunc
 */
typedef struct CriAtomExMonitoringVoiceStopInfoTag {
	CriAtomExPlaybackId playback_id;		/*JP< �Đ�ID			*/
	CriAtomVoiceStopReason reason;			/*JP< ��~���R			*/
	CriAtomPlayerHn atom_player;			/*JP< ��~AtomPlayer	*/
} CriAtomExMonitoringVoiceStopInfo;

/*JP
 * \brief �{�C�X��~���Ď�����R�[���o�b�N�֐��^
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	obj					���[�U�w��I�u�W�F�N�g
 * \param[in]	voice_stop			�{�C�X��~���e
 * \par ����:
 * �Ď����Ă���Đ�ID���Ŕ������Ă���{�C�X����~�����ۂɎg�p�����A�R�[���o�b�N�֐��̌^�ł��B<br>
 * \attention
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_SetMonitoringVoiceStopCallback
 */
typedef void (CRIAPI *CriAtomExMonitoringVoiceStopCbFunc)(void *obj, CriAtomExMonitoringVoiceStopInfo* voice_stop);


/*==========================================================================
 *      CRI AtomEx Cue Link Callback API
 *=========================================================================*/
/*JP
 * \brief �L���[�����N�R�[���o�b�N�^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef enum CriAtomExCueLinkTypeTag {
	CRIATOMEX_CUELINK_TYPE_STATIC		=  0,	/*JP< �ÓI�����N */
	CRIATOMEX_CUELINK_TYPE_DYNAMIC		=  1,	/*JP< ���I�����N */

	/* enum size is 4bytes */
	CRIATOMEX_CUELINK_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExCueLinkType;

/*JP
 * \brief �L���[�����N�R�[���o�b�N�pInfo�\����
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef struct CriAtomExCueLinkInfoTag {
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��		*/
	CriAtomExPlaybackId base_id;		/*JP< �����N���Đ�ID		*/
	CriAtomExSourceInfo base_cue;		/*JP< �����N���L���[		*/
	CriAtomExPlaybackId target_id;		/*JP< �����N��Đ�ID		*/
	CriAtomExSourceInfo target_cue;		/*JP< �����N��L���[		*/
	CriAtomExCueLinkType link_type;		/*JP< �����N�^�C�v			*/
} CriAtomExCueLinkInfo;

/*JP
 * \brief �L���[�����N�R�[���o�b�N
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	info	�L���[�����N���
 * \return				���g�p
 * AtomEx���C�u�����̃L���[�����N�R�[���o�b�N�֐��^�ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomEx_SetCueLinkCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A���C�u�������ŃL���[�����N�����������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_SetCueLinkCallback
 */
typedef CriSint32 (CRIAPI *CriAtomExCueLinkCbFunc)(void* obj, const CriAtomExCueLinkInfo* info);

/*==========================================================================
 *      CRI AtomEx Playback Cancel Callback API
 *=========================================================================*/
/*JP
 * \brief �v���C�o�b�N�L�����Z���^�C�v
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �v���C�o�b�N�L�����Z���̎�ʂ������l�ł��B<br>
 * \sa CriAtomExPlaybackCancelInfo, criAtomEx_SetPlaybackCancelCallback
 */
typedef enum CriAtomExPlaybackCancelTypeTag {
	/*JP
	 * \brief �L���[���~�b�g
	 * \par ����:
	 * �L���[���~�b�g�ɂ�锭���L�����Z���B<br>
	 */
	CRIATOMEX_PLAYBACK_CANCEL_TYPE_CUE_LIMIT = 0,

	/*JP
	 * \brief �J�e�S���L���[���~�b�g
	 * \par ����:
	 * �J�e�S���L���[���~�b�g�ɂ�锭���L�����Z���B<br>
	 */
	CRIATOMEX_PLAYBACK_CANCEL_TYPE_CATEGORY_CUE_LIMIT,
	
	/*JP
	 * \brief �v���C�I���e�B
	 * \par ����:
	 * �v���C�I���e�B�ɂ�锭���L�����Z���B<br>
	 */
	CRIATOMEX_PLAYBACK_CANCEL_TYPE_PROBABILITY,

	/*JP
	 * \brief �L���[���~�b�g
	 * \par ����:
	 * �L���[���~�b�g�ɂ�锭����~�B<br>
	 */
	CRIATOMEX_PLAYBACK_CANCEL_TYPE_STOP_BY_CUE_LIMIT,
		
	/*JP
	 * \brief �X�C�b�`
	 * \par ����:
	 * �X�C�b�`�ɂ�锭���L�����Z���B<br>
	 */
	CRIATOMEX_PLAYBACK_CANCEL_TYPE_SWITCH,


	CRIATOMEX_PLAYBACK_CANCEL_TYPE_ENUM_IS_4BYTE = 0x7FFFFFFF
} CriAtomExPlaybackCancelType;

/*JP
 * \brief �v���C�o�b�N�L�����Z���R�[���o�b�N�pInfo�\����
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef struct CriAtomExPlaybackCancelInfoTag {
	CriAtomExPlaybackCancelType type;	/*JP< �L�����Z���^�C�v		*/
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��		*/
	CriAtomExPlaybackId id;				/*JP< �Đ�ID				*/
} CriAtomExPlaybackCancelInfo;

/*JP
 * \brief �v���C�o�b�N�L�����Z���R�[���o�b�N
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	info	�v���C�o�b�N�L�����Z�����
 * \return				���g�p
 * AtomEx���C�u�����̃v���C�o�b�N�L�����Z���R�[���o�b�N�֐��^�ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomEx_SetPlaybackCancelCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A���C�u�������ōĐ��J�n�������L�����Z�������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_SetPlaybackCancelCallback
 */
typedef void (CRIAPI *CriAtomExPlaybackCancelCbFunc)(void *obj, const CriAtomExPlaybackCancelInfo* info);

/*==========================================================================
 *      CRI AtomEx Track Transition Callback API
 *=========================================================================*/
/*JP
 * \brief �g���b�N�g�����W�V�����o�C�Z���N�^�[�R�[���o�b�N�pInfo�\����
 * \ingroup ATOMEXLIB_GLOBAL
 */
typedef struct CriAtomExTrackTransitionBySelectorInfoTag {
	CriAtomExPlayerHn player;			/*JP< �v���[���[�n���h��		*/
	CriAtomExPlaybackId id;				/*JP< �Đ�ID				*/
	const CriChar8* selector;			/*JP< �Z���N�^�[��			*/
	const CriChar8* label;				/*JP< ���x����				*/
} CriAtomExTrackTransitionBySelectorInfo;

/*JP
 * \brief �g���b�N�g�����W�V�����o�C�Z���N�^�[�R�[���o�b�N
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	info	�g���b�N�g�����W�V�����o�C�Z���N�^�[���
 * \return				���g�p
 * AtomEx���C�u�����̃g���b�N�g�����W�V�����o�C�Z���N�^�[�R�[���o�b�N�֐��^�ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomEx_SetTrackTransitionBySelectorCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A���C�u�������Ńg�����W�V�����������J�n�����^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomEx_SetTrackTransitionBySelectorCallback
 */

typedef void (CRIAPI *CriAtomExTrackTransitionBySelectorCbFunc)(void *obj, const CriAtomExTrackTransitionBySelectorInfo* info);


/*==========================================================================
 *      CRI AtomEx Sound Object API
 *=========================================================================*/
/*JP
 * \brief �T�E���h�I�u�W�F�N�g�쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \par ����:
 * �T�E���h�I�u�W�F�N�g���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExSoundObject_Create �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����T�E���h�I�u�W�F�N�g�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �T�E���h�I�u�W�F�N�g���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A�e�����o�̐ݒ�O�ɕK��
 * ::criAtomExSoundObject_SetDefaultConfig �}�N�����g�p���ăf�t�H���g�l���Z�b�g���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExSoundObject_Create,  criAtomExSoundObject_SetDefaultConfig
 */
typedef struct CriAtomExSoundObjectConfigTag {
	/*JP 
	 * \brief �{�C�X���~�b�g�X�R�[�v�̗L����
	 * \par ����:
	 * �{�C�X���~�b�g�O���[�v�ɂ�锭����������A���̃T�E���h�I�u�W�F�N�g�œƗ����čs�����ǂ������w�肵�܂��B<br>
	 * CRI_TRUE���w�肷��ƁA���̃T�E���h�I�u�W�F�N�g�Ɋ֘A�t����ꂽEx�v���[���[����Đ����������̔������ɂ��āA<br>
	 * ���̃T�E���h�I�u�W�F�N�g���ł̂݃J�E���g���A�{�C�X���~�b�g�O���[�v�ɂ�锭����������s���܂��B<br>
	 * CRI_FALSE���w�肵���ꍇ�A�T�E���h�I�u�W�F�N�g�ł̓{�C�X���~�b�g�O���[�v�ɂ�锭��������͍s�킸�A<br>
	 * CRI Atom���C�u�����S�̂ł̔���������ɏ]���܂��B
	 * \par ���l:
	 * �f�t�H���g�l��CRI_FALSE�i�T�E���h�I�u�W�F�N�g�Ń{�C�X���~�b�g���s��Ȃ��j�ł��B
	*/
	CriBool enable_voice_limit_scope;
	/*JP 
	 * \brief �J�e�S���L���[���~�b�g�X�R�[�v�̗L����
	 * \par ����:
	 * �J�e�S���ɂ��L���[�Đ���������A���̃T�E���h�I�u�W�F�N�g�œƗ����čs�����ǂ������w�肵�܂��B<br>
	 * CRI_TRUE���w�肷��ƁA���̃T�E���h�I�u�W�F�N�g�Ɋ֘A�t����ꂽEx�v���[���[����Đ������L���[�̃J�e�S���Đ����ɂ��āA<br>
	 * ���̃T�E���h�I�u�W�F�N�g���ł̂݃J�E���g���A�Đ���������s���܂��B<br>
	 * CRI_FALSE���w�肵���ꍇ�A���̃T�E���h�I�u�W�F�N�g�ł̓J�e�S���ɂ��Đ�������͍s�킸�A<br>
	 * CRI Atom���C�u�����S�̂ł̃J�e�S���ɂ��Đ�������ɏ]���܂��B
	 * \par ���l:
	 * �f�t�H���g�l��CRI_FALSE�i�T�E���h�I�u�W�F�N�g�ŃJ�e�S���L���[���~�b�g���s��Ȃ��j�ł��B
	*/
	CriBool enable_category_cue_limit_scope;
} CriAtomExSoundObjectConfig;

struct CriAtomExSoundObjectTag;
typedef struct CriAtomExSoundObjectTag CriAtomExSoundObjectObj;
/*JP
 * \brief �T�E���h�I�u�W�F�N�g�n���h��
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \par ����:
 * CriAtomExSoundObjectHn �́A�T�E���h�I�u�W�F�N�g�𑀍삷�邽�߂̃n���h���ł��B<br>
 * <br>
 * ::criAtomExSoundObject_Create �֐��ŃT�E���h�I�u�W�F�N�g���쐬����ƁA
 * �֐��̓T�E���h�I�u�W�F�N�g����p�ɁA����"�T�E���h�I�u�W�F�N�g�n���h��"��Ԃ��܂��B
 * <br>
 * �T�E���h�I�u�W�F�N�g�ɑ΂��čs������́A�S�ăT�E���h�I�u�W�F�N�g�n���h������Ď��s����܂��B
 * \par ���l:
 * �T�E���h�I�u�W�F�N�g�Ƃ́A�����̉�����u���́v��u��ԁv�A�u�󋵁v���𒊏� �������T�O�ł��B<br>
 * <br>
 * �T�E���h�I�u�W�F�N�g���A�v���P�[�V�������́u���́v��u��ԁv�A�u�󋵁v���Ɋ֘A�t���邱�Ƃɂ��A
 * ��莩�R�ɉ����̃R���g���[�����s�����Ƃ��ł��܂��B<br>
 * �Ⴆ�΁A����L�����N�^�����݂���Ƃ��A���̃L�����N�^�p�̃T�E���h�I�u�W�F�N�g���쐬���邱�ƂŁA
 * �L�����N�^���ɔ������������s������A�L�����N�^���łƂƂ��ɂ܂Ƃ߂čĐ���~���s���A
 * �Ƃ����悤�Ȃ��Ƃ��ȒP�ɂł���悤�ɂȂ�܂��B<br>
 * <br>
 * �T�E���h�I�u�W�F�N�g���g�́A�����̂��߂̋@�\�������܂���B
 * ������ʂ̃R���g���[���́A�T�E���h�I�u�W�F�N�g�Ɋ֘A�t����ꂽAtomEx�v���[���[�ōs���܂��B
 * \sa criAtomExSoundObject_Create
 */
typedef CriAtomExSoundObjectObj *CriAtomExSoundObjectHn;

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
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomExConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ::CriAtomExConfig �\���̂�acf_info�����o�ɒl��ݒ肵�Ă���ꍇ�A�{�֐��͎��s��-1��Ԃ��܂��B<br>
 * ��������������ACF�f�[�^�̓o�^���s���ꍇ�́A�{�֐��l���g�p�����������m�ۂł͂Ȃ�ADX2�V�X�e���ɂ��
 * �������A���P�[�^�[���g�p�����������m�ۏ������K�v�ɂȂ�܂��B
 * \sa CriAtomExConfig, criAtomEx_Initialize
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize(const CriAtomExConfig *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriBool		�������ł������ǂ����H�i�ł����FCRI_TRUE�^�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * ���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtomEx_Finalize �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * ::CriAtomExConfig �\���̂�acf_info�����o���g�p����Ə�������������ACF�f�[�^�̓o�^���s���܂��B<br>
 * �������������ł�ACF�f�[�^�o�^���s���ꍇ�́AUser Allocator�����Ń������̈���m�ۂ���K�v������܂��B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�̓��C�u�����Ƀ������m�ۊ֐���o�^���Ă����܂��B<br>
 * work��NULL�Awork_size��0���w�肵�Ė{�֐����Ăяo�����ƂŁA
 * ���C�u�����͓o�^�ς݂̃������m�ۊ֐����g�p���ĕK�v�ȃ������������I�Ɋm�ۂ��܂��B<br>
 * ���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * ���������Ɋm�ۂ��ꂽ�������́A�I���������i ::criAtomEx_Finalize �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtomEx_CalculateWorkSize �֐��Ŏ擾�\�ł��B<br>
 * �����������̑O�� ::criAtomEx_CalculateWorkSize �֐��Ŏ擾�����T�C�Y���̃�������\��
 * �m�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈�̓��C�u�����̏I�������i ::criAtomEx_Finalize �֐��j
 * ���s�Ȃ��܂ł̊ԁA���C�u�������ŗ��p���ꑱ���܂��B<br>
 * ���C�u�����̏I���������s�Ȃ��O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B<br>
 * \par ��:
 * �yUser Allocator�����ɂ�郉�C�u�����̏������z<br>
 * User Allocator������p����ꍇ�A���C�u�����̏������^�I���̎菇�͈ȉ��̈ȉ��̒ʂ�ł��B<br>
 * 	-# �������������s�O�ɁA ::criAtomEx_SetUserAllocator �֐���p���ă������m�ہ^����֐���o�^����B<br>
 * 	-# �������p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ::criAtomEx_Initialize �֐��ŏ������������s���B<br>
 * �iwork�ɂ�NULL�Awork_size�ɂ�0���w�肷��B�j<br>
 * 	-# �A�v���P�[�V�����I������ ::criAtomEx_Finalize �֐��ŏI���������s�Ȃ��B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * // �Ǝ��̃������m�ۊ֐�
 * void *user_malloc(void *obj, CriUint32 size)
 * {
 * 	void *mem;
 * 	
 * 	// �������̊m��
 * 	mem = malloc(size);
 * 	
 * 	return (mem);
 * }
 * 
 * // �Ǝ��̃���������֐���p��
 * void user_free(void *obj, void *mem)
 * {
 * 	// �������̉��
 * 	free(mem);
 * 	
 * 	return;
 * }
 * 
 * main()
 * {
 * 	CriAtomExConfig config;	// ���C�u�����������p�R���t�B�O�\����
 * 		:
 * 	// �Ǝ��̃������A���P�[�^�[��o�^
 * 	criAtomEx_SetUserAllocator(user_malloc, user_free, NULL);
 * 	
 * 	// ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * 	criAtomEx_SetDefaultConfig(&config);
 * 	
 * 	// ���C�u�����̏�����
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������́A�o�^�����������m�ۊ֐����g���Ċm�ۂ����B
 * 	criAtomEx_Initialize(&config, NULL, 0);
 * 		:
 * 	// �A�v���P�[�V�����̃��C������
 * 		:
 * 	// �A�v���P�[�V�������I������ۂɏI���������s��
 * 	// �����������Ɋm�ۂ��ꂽ�������́A�o�^��������������֐����g���ĉ�������B
 * 	criAtomEx_Finalize();
 * 		:
 * }
 * \endcode
 * <br>
 * �yFixed Memory�����ɂ�郉�C�u�����̏������z<br>
 * Fixed Memory������p����ꍇ�A���C�u�����̏������^�I���̎菇�͈ȉ��̈ȉ��̒ʂ�ł��B<br>
 * 	-# �������p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ���C�u�����̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���A ::criAtomEx_CalculateWorkSize 
 * �֐����g���Čv�Z����B<br>
 * 	-# ���[�N�̈�T�C�Y���̃��������m�ۂ���B<br>
 * 	-# ::criAtomEx_Initialize �֐��ŏ������������s���B<br>
 * �iwork�ɂ͊m�ۂ����������̃A�h���X���Awork_size�ɂ̓��[�N�̈�̃T�C�Y���w�肷��B�j<br>
 * 	-# �A�v���P�[�V�����I������ ::criAtomEx_Finalize �֐��ŏI���������s�Ȃ��B<br>
 * 	-# ���[�N�̈�̃��������������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 	CriAtomExConfig config;	// ���C�u�����������p�R���t�B�O�\����
 * 	void *work;				// ���[�N�̈�A�h���X
 * 	CriSint32 work_size;	// ���[�N�̈�T�C�Y
 * 		:
 * 	// ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * 	criAtomEx_SetDefaultConfig(&config);
 * 	
 * 	// ���C�u�����̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z
 * 	work_size = criAtomEx_CalculateWorkSize(&config);
 * 	
 * 	// ���[�N�̈�p�Ƀ��������m��
 * 	work = malloc((size_t)work_size);
 * 	
 * 	// ���C�u�����̏�����
 * 	// ���m�ۍς݂̃��[�N�̈���w�肷��B
 * 	criAtomEx_Initialize(&config, NULL, 0);
 * 		:
 * 	// �A�v���P�[�V�����̃��C������
 * 	// �����̊ԁA�m�ۂ����������͕ێ���������B
 * 		:
 * 	// �A�v���P�[�V�������I������ۂɏI���������s��
 * 	criAtomEx_Finalize();
 * 	
 * 	// �K�v�Ȃ��Ȃ������[�N�̈���������
 * 	free(work);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�������p�R���t�B�O�\���̂̓��e�ɉ�����
 * �ω����܂��B<br>
 * �܂��A�K�v�ȃ��[�N�̈�̃T�C�Y�́A�v���b�g�t�H�[���ɂ���Ă��قȂ�܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ����A�X�g���[���Đ����s�����ǂ����Ɋ֌W�Ȃ��A Atom ���C�u�����͕K�� 
 * CRI File System ���C�u�����̋@�\���g�p���܂��B<br>
 * ���̂��߁ACRI File System���C�u�����̏��������s���Ă��Ȃ��ꍇ�A
 * Atom ���C�u�����͏������������ɓ����� CRI File System ���C�u�����̏��������s���܂��B<br>
 * <br>
 * Atom ���C�u������������ CRI File System ���C�u����������������ꍇ�A
 * CRI File System �̏������p�����[�^�[�Ƃ��āA ::CriAtomExConfig �\���̂�
 * fs_config �p�����[�^�[���g�p���܂��B<br>
 * fs_config �� NULL �̏ꍇ�A Atom ���C�u�����̓f�t�H���g�p�����[�^�[�i 
 * ::criFs_SetDefaultConfig �}�N���̐ݒ�l�j�� CRI File System ���C�u���������������܂��B<br>
 * <br>
 * ���A�{�֐������s���鎞�_�ŁA���� CRI File System ���C�u�������������ς݂ł���ꍇ�A
 * �{�֐����ł� CRI File System ���C�u�����̏������͍s���܂���B<br>
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomEx_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtomEx_Finalize �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa CriAtomExConfig, criAtomEx_Finalize, criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize
 */
CriBool CRIAPI criAtomEx_Initialize(
	const CriAtomExConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ���C�u�������I�����܂��B<br>
 * \attention
 * ::criAtomEx_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomEx_Initialize
 */
void CRIAPI criAtomEx_Finalize(void);

/*JP
 * \brief ���C�u������������Ԃ̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \return	CriBool		�����������ǂ���
 * \retval	CRI_FALSE	�����������
 * \retval	CRI_TRUE	�������ς�
 * \par ����:
 * ���C�u���������ɏ���������Ă��邩�ǂ������`�F�b�N���܂��B<br>
 * \sa criAtomEx_Initialize, criAtomEx_Finalize
 */
CriBool CRIAPI criAtomEx_IsInitialized(void);

/*JP
 * \brief �T�[�o�[�����̎��s
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�����̓�����Ԃ��X�V���܂��B<br>
 * �A�v���P�[�V�����́A���̊֐������I�Ɏ��s����K�v������܂��B<br>
 * <br>
 * �T�[�o�[���������s���ׂ��񐔂́A���C�u�������������̃p�����[�^�[�Ɉˑ����܂��B<br>
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI �ɐݒ肵���ꍇ�A
 * ���A���^�C�����̗v������鏈���͑S��CRI Atom���C�u�������Œ���I�Ɏ������s����邽�߁A
 * �{�֐��̌Ăяo���p�x�͏��Ȃ��Ă����͔������܂���B<br>
 * �i�Œ�ł����b1����x���s����Ă���΁A���؂ꓙ�̖�肪�������邱�Ƃ͂���܂���B�j<br>
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOMEX_THREAD_MODEL_SINGLE ��
 * ::CRIATOMEX_THREAD_MODEL_USER_MULTI �ɐݒ肵���ꍇ�A�t�@�C���̓ǂݍ��݊Ǘ���A
 * �f�[�^�̃f�R�[�h�A�����̏o�͓��A�����Đ��ɕK�v�ȏ����̂قڑS�Ă��{�֐����Ŏ��s����܂��B<br>
 * �܂��A�����Đ������ɓ������āACRI File System���C�u�����̃t�@�C���A�N�Z�X�ƃf�[�^�W�J���������s���܂��B<br>
 * ���̂��߁A���C�u�������������Ɏw�肵���T�[�o�[�����̎��s�p�x�i ::CriAtomExConfig �\���̂�
 * server_frequency �j�������p�x�Ŗ{�֐������s�����ꍇ��A
 * �傫���f�[�^�̓ǂݍ��݁A���k�t�@�C���̓ǂݍ��ݓ����s���ꍇ�A
 * ���؂ꓙ�̖�肪��������\��������̂Œ��ӂ��Ă��������B<br>
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI �ɐݒ肵���ꍇ�ł��A
 * �{�֐������s����K�v������܂��B<br>
 * �i�X���b�h���f���� ::CRIATOMEX_THREAD_MODEL_MULTI �̏ꍇ�A�X�e�[�^�X�X�V���A�����ꕔ��
 * �����݂̂��s�����߁A�{�֐����Œ����ԏ������u���b�N����邱�Ƃ͂���܂���B�j
 * <br>
 * CRI File System���C�u�����̃T�[�o�[�����́ACRI Atom���C�u���������Ŏ��s����܂��B<br>
 * ���̂��߁A�{�֐������s���Ă���ꍇ�A�A�v���P�[�V�������ŕʓrCRI File System���C�u����
 * �̃T�[�o�[�������Ăяo���K�v�͂���܂���B<br>
 */
void CRIAPI criAtomEx_ExecuteMain(void);

/*JP
 * \brief ���[�U�[�}���`�X���b�h�p�T�[�o�[�����̎��s
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�����݂̂��X�V���܂��B<br>
 * �X���b�h���f����::CRIATOMEX_THREAD_MODEL_USER_MULTI�̏ꍇ�A
 * �A�v���P�[�V�����́A���̊֐������I�Ɏ��s����K�v������܂��B<br>
 * <br>
 * �t�@�C���̓ǂݍ��݊Ǘ���A�f�[�^�̃f�R�[�h�A�����̏o�͓��A
 * �����Đ��ɕK�v�ȏ����̂قڑS�Ă��{�֐����Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u�������������Ɏw�肵���T�[�o�[�����̎��s�p�x�i ::CriAtomExConfig �\���̂�
 * server_frequency �j�������p�x�Ŗ{�֐������s�����ꍇ�A���؂ꓙ�̖�肪��������\��
 * ������܂��B<br>
 * �܂��A�{�֐���::criAtomEx_ExecuteMain �֐��ƈقȂ�ACRI File System���C�u�����̃T�[�o�[���������s���܂���B<br>
 * �A�v���P�[�V�������K�v�ȃT�[�o�[�����𐳂��������Ŏ��s���Ă��������B<br>
 * \par ���l:
 * ::CRIATOMEX_THREAD_MODEL_SINGLE �ɐݒ肵���ꍇ�A�T�[�o�[�����̔r�����䂪�s���Ȃ��̂ŁA
 * �����̃X���b�h����Ăяo���Ȃ��悤�ɂ��Ă��������B<br>
 * \sa criAtomEx_ExecuteMain
 */
void CRIAPI criAtomEx_ExecuteAudioProcess(void);

/*JP
 * \brief �T�[�o�[�����̊��荞�݂�h�~
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * �T�[�o�[�����̊��荞�ݗ}�~���܂��B<br>
 * �{�֐����s��A::criAtomEx_Unlock �֐����s�܂ł̊ԁA�T�[�o�[�����̓��삪�}�~����܂��B<br>
 * ������API�𓯈�I�[�f�B�I�t���[�����Ŋm���Ɏ��s�������ꍇ�ɂ́A�{�֐��ŃT�[�o�[������
 * ���荞�݂�h�~���A�����̊֐������s���Ă��������B
 * \par ��:
 * \code
 * 	�F
 * // �T�[�o�[�����̊��荞�݂�h�~
 * criAtomEx_Lock();
 * 
 * // �����̉����̃p�����[�^�[�𓯎��ɍX�V
 * criAtomExPlayer_SetVolume(player1, 0.5f);
 * criAtomExPlayer_SetVolume(player2, 0.6f);
 * criAtomExPlayer_SetVolume(player3, 0.7f);
 * criAtomExPlayer_SetVolume(player4, 0.8f);
 * criAtomExPlayer_UpdateAll(player1);
 * criAtomExPlayer_UpdateAll(player2);
 * criAtomExPlayer_UpdateAll(player3);
 * criAtomExPlayer_UpdateAll(player4);
 * 
 * // �T�[�o�[�����̊��荞�ݖh�~������
 * criAtomEx_Unlock();
 * 	�F
 * \endcode
 * \attention
 * ���荞�ݖh�~��Ԃœ����ɕ����̃v���[���[�̍Đ����X�^�[�g�����ꍇ�ł��A
 * �ȉ��̗v���ɂ��Đ�����g�`���T���v���P�ʂœ������Ȃ��ꍇ������܂��B<br>
 * - �X�g���[���Đ����̃f�[�^�����ɔ��������x��<br>
 * - �������\�[�X�̒D�����ɔ��������x��<br>
 * �Đ��������s�������ꍇ�́A::criAtomExPlayer_Prepare �֐����g�p���čĐ��������s���A
 * ����������Ɋ��荞�ݖh�~��ԂōĐ����J�n���Ă��������B<br>
 * <br>
 * �{�֐����s��A������::criAtomEx_Unlock �֐����Ă΂Ȃ��ꍇ�A�����Đ����r�؂�鋰�ꂪ����܂��B<br>
 * �T�[�o�[�����̊��荞�݂�h�~�����Ԃ́A�ŏ����ɗ}����K�v������܂��B
 * \sa criAtomEx_Unlock
 */
void CRIAPI criAtomEx_Lock(void);

/*JP
 * \brief �T�[�o�[�����̊��荞�ݖh�~������
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ::criAtomEx_Lock �֐��ɂ��A�T�[�o�[�����̊��荞�ݖh�~���������܂��B
 * \sa criAtomEx_Lock
 */
void CRIAPI criAtomEx_Unlock(void);

/*JP
 * \brief �����̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \return CriUint64	�����i�}�C�N���b�P�ʁj
 * \par ����:
 * Atom���C�u�������̃}�X�^�^�C�}���玞�����擾���܂��B
 * \sa criAtomEx_ResetTimer
 */
CriUint64 CRIAPI criAtomEx_GetTimeMicro(void);

/*JP
 * \brief �^�C�}�̃��Z�b�g
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * Atom���C�u�������̃}�X�^�^�C�}�̎��������Z�b�g���܂��B<br>
 * \par ���l:
 * �{�֐��� ::criAtomEx_GetTimeMicro �֐����Ԃ��l�ɑ΂��Ă̂݉e�����܂��B<br>
 * �{�֐������s���Ă��AAtomEx�v���[���[�̍Đ��������N���A����邱�Ƃ͂���܂���B<br>
 * \sa criAtomEx_ResetTimer
 */
void CRIAPI criAtomEx_ResetTimer(void);

/*JP
 * \brief �^�C�}�̃|�[�Y
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	sw		CRI_TRUE=�^�C�}�ꎞ��~�ACRI_FALSE=�^�C�}�ĊJ
 * \par ����:
 * Atom���C�u�������̃}�X�^�^�C�}���ꎞ��~�^�ĊJ���܂��B<br>
 * �}�X�^�^�C�}���ꎞ��~����ƁA�V�[�P���X�������i�s���Ȃ��Ȃ�܂��B<br>
 * \par ���l:
 * �{�֐��� �A�v���P�[�V�������x�~������ꎞ��~����悤�ȃv���b�g�t�H�[���ɂ����āA<br>
 * �x�~����ꎞ��~���ł��^�C�}���i�s���Ă��܂��v���b�g�t�H�[�������̋@�\�ł��B<br>
 * �A�v���P�[�V�������x�~��Ԃ�ꎞ��~��ԂɑJ�ڂ���O��<br>
 * �{�֐��Ń}�X�^�^�C�}���ꎞ��~���Ă������ƂŁA�x�~���̃V�[�P���X�̐i�s���~�߂鎖���ł��܂��B<br>
 * \attention
 * �{�֐��ňꎞ��~����Ώۂ͂����܂�Atom���C�u�������̃}�X�^�^�C�}�ł��B<br>
 * �{�֐��ł͔������̃{�C�X�����ꎞ��~�ł��܂���B
 * �{�֐��Őݒ肵���|�[�Y�t���O�́ACRI Atom�T�[�o�[���������s���ꂽ�^�C�~���O�Ŕ��f����܂��B<br>
 * �����ɓ������Ƃ�K�v������ꍇ�́A::criAtomEx_ExecuteAudioProcess �֐����Ăяo�����œ������Ƃ邱�Ƃ��ł��܂��B<br>
 * �������A::criAtomEx_ExecuteAudioProcess���Ăяo�����X���b�h�ŃI�[�f�B�I���������s����邽�߁A
 * ����CPU���ׂ����e�ł��邩�ɒ��ӂ��Ă��������B<br>
 * \sa criAtomEx_ResetTimer
 */
void CRIAPI criAtomEx_PauseTimer(CriBool sw);

/*JP
 * \brief ���[�N�̈�T�C�Y�v�Z�p�R���t�B�O�\���̂̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \par ����:
 * ���[�N�̈�T�C�Y�̌v�Z�p�ɁA���C�u�����������p�R���t�B�O�\����
 * �i ::CriAtomExConfig �\���́j�����o�^���܂��B<br>
 * <br>
 * ACF�̓o�^��{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ���C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �ɐݒ肷��\���̂̃p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�ʏ��ACF�̓o�^��{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z����O�ɁA
 * ���C�u����������������K�v������܂��B<br>
 * �{�֐����g�p���ă��C�u�����������p�R���t�B�O�\���̂�o�^�����ꍇ�A
 * ACF�̓o�^��{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���A
 * �����������Ȃ��Ɍv�Z�\�ɂȂ�܂��B<br>
 * <br>
 * �{�֐������s���邱�ƂŁA�ȉ��̏����������������Ȃ��Ɏ��s�\�ƂȂ�܂��B<br>
 * - ::criAtomEx_CalculateWorkSizeForRegisterAcfData �֐�
 * - �{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z<br>
 * �i ::criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool �֐����j
 * 
 * \par ���l:
 * �����i config �j�� NULL ���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ����A�{�֐��ň�U�R���t�B�O�\���̂�ݒ肷��ƁA
 * �ݒ�O�̏�ԁi����������Ԃł̃��[�N�̈�T�C�Y�v�Z���G���[�Ƃ��铮��j
 * �ɖ߂����Ƃ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�֐����ēx���s���ăp�����[�^�[���㏑�����邱�Ƃ͉\�ł��B�j<br>
 * \attention
 * �{�֐��œo�^�����������p�R���t�B�O�\���̂́A
 * ���C�u��������������Ԃł̃��[�N�̈�T�C�Y�v�Z�ɂ����g�p����܂���B<br>
 * ���C�u������������ɂ͖{�֐��ɐݒ肵���p�����[�^�[�ł͂Ȃ��A
 * ���������Ɏw�肳�ꂽ�p�����[�^�[�����[�N�̈�T�C�Y�̌v�Z�Ɏg�p����܂��B<br>
 * �i�{�֐��œo�^����\���̂̃p�����[�^�[�ƁA
 * ���C�u�����̏������Ɏg�p����\���̂̃p�����[�^�[���قȂ�ꍇ�A
 * ���[�N�̈�T�C�Y���s�����A�n���h���̍쐬�Ɏ��s���鋰�ꂪ����܂��B�j<br>
 * <br>
 * ::criAtomEx_RegisterAcfFile �֐��� ::criAtomExAcb_LoadAcbFile �֐����A
 * ���[�N�̈�v�Z���Ƀt�@�C���A�N�Z�X���K�v�ɂȂ� API �ɂ��ẮA
 * �{�֐������s�����ꍇ�ł����[�N�̈�T�C�Y�̌v�Z���s���܂���B<br>
 * �i���[�N�̈�T�C�Y���v�Z���邽�߂ɂ̓��C�u����������������K�v��
 * ����܂��B�j<br>
 * \par ��:
 * \code
 * 	CriAtomExConfig atomex_config;
 * 	
 * 	// ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l��ݒ�
 * 	criAtomEx_SetDefaultConfig(&atomex_config);
 * 	
 * 	// ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * 	lib_work_size = criAtomEx_CalculateWorkSize(&atomex_config);
 * 	
 * 	// �T�u���W���[���̃��[�N�̈�T�C�Y�v�Z�p�Ƀp�����[�^�[�����o�^
 * 	criAtomEx_SetConfigForWorkSizeCalculation(&atomex_config);
 * 	
 * 	// �T�u���W���[���̃��[�N�̈�T�C�Y���v�Z
 * 	acf_work_size = criAtomEx_CalculateWorkSizeForRegisterAcfData(acf_data, acf_data_size);
 * 	vp_work_size = criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool(NULL);
 * 		�F
 * \endcode
 * \sa criAtomEx_CalculateWorkSizeForRegisterAcfData, criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool
 */
void CRIAPI criAtomEx_SetConfigForWorkSizeCalculation(const CriAtomExConfig *config);

/*JP
 * \brief �I��������ACF�f�[�^�̓o�^�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	acf_data		ACF�f�[�^�A�h���X
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return		CriSint32		���[�N�̈�T�C�Y
 * \retval		0�ȏ�			����ɏ���������
 * \retval		-1				�G���[������
 * \par ����:
 * ::criAtomEx_RegisterAcfData �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomEx_RegisterAcfData �֐���ACF����o�^����ۂɂ́A
 * �{�֐����Ԃ��T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomEx_RegisterAcfData
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForRegisterAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief �I��������ACF�f�[�^�̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	acf_data		ACF�f�[�^�A�h���X
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ��������ɔz�u���ꂽACF�f�[�^�����C�u�����Ɏ�荞�݂܂��B<br>
 * ACF���̓o�^�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ::criAtomEx_CalculateWorkSizeForRegisterAcfData �֐��Ōv�Z���܂��B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��́A�֐����s���ɍĐ����̉��������ׂĒ�~���܂��B<br>
 * �܂��A�v���[���[�ɐݒ肵���ȉ���ACF�Ɋ֘A����p�����[�^�[��S�ă��Z�b�g���܂��B<br>
 *  -# AISAC
 *  -# AISAC�R���g���[���l
 *  -# �J�e�S��
 *  -# �Z���N�^�[���x��
 *  -# �o�X�Z���h
 * 	
 * <br>
 * �{�֐��ɃZ�b�g�����f�[�^�̈�ƃ��[�N�̈�́A ::criAtomEx_UnregisterAcf �֐������s����܂ł̊ԁA
 * �A�v���P�[�V�����ŕێ�����K�v������܂��B<br>
 * �i ::criAtomEx_UnregisterAcf �֐����s�O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B�j
 * �܂��A�f�[�^�̈�̈ꕔ�̓��[�N�Ƃ��Ďg�p����܂��B<br>
 * \sa criAtomEx_UnregisterAcf
 */
void CRIAPI criAtomEx_RegisterAcfData(
	void *acf_data, CriSint32 acf_data_size, void *work, CriSint32 work_size);

/*JP
 * \brief ACF�t�@�C���̓o�^�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		�t�@�C���p�X
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ::criAtomEx_RegisterAcfFile �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * �{�֐��́A ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^�̗L���ɂ����
 * �v�Z�Ɏg�p����v�f���قȂ�܂��B
 * - �A���P�[�^�[�o�^���FACF�t�@�C�����ꎞ�I�ɓǂݍ��݁AACF���ɋL�^����Ă���J�e�S�����A
 * �Đ��P�ʂł̃J�e�S���Q�Ɛ��AREACT�����g�p�����T�C�Y�v�Z���s���܂��B<br>
 * - �A���P�[�^�[���o�^���F���C�u�������������Ɏw�肵�� ::CriAtomExConfig �\���̂�
 * max_categories�����o�Acategories_per_playback�����o���g�p�����T�C�Y�v�Z���s���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomEx_RegisterAcfFile
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForRegisterAcfFile(
	CriFsBinderHn binder, const CriChar8 *path);

/*JP
 * \brief ACF�t�@�C���̓o�^�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			CPK�R���e���cID
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ::criAtomEx_RegisterAcfFileById �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomEx_CalculateWorkSizeForRegisterAcfFile �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomEx_CalculateWorkSizeForRegisterAcfFile, criAtomEx_RegisterAcfFileById
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForRegisterAcfFileById(
	CriFsBinderHn binder, CriUint16 id);

/*JP
 * \brief ACF�t�@�C���̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		�t�@�C���p�X
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriBool		�t�@�C���ǂݍ��݌���
 * \par ����:
 * ACF�t�@�C�������[�h���A���C�u�����Ɏ�荞�݂܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * ���[�N�̈���w�肵�Ė{�֐����g�p����ꍇ�A ::criAtomEx_CalculateWorkSizeForRegisterAcfFile �֐�
 * ���g�p���ă��[�N�T�C�Y���v�Z���Ă��������B<br>
 * <br>
 * ACF�t�@�C���̓o�^�ɐ�������ƁA�{�֐��͖߂�l�Ƃ��� CRI_TRUE ��Ԃ��܂��B<br>
 * ���[�h�G���[���ɂ��ACF�t�@�C���̓ǂݍ��݂Ɏ��s�����ꍇ�A�{�֐��͖߂�l�Ƃ���
 * CRI_FALSE ��Ԃ��܂��B<br>
 * \par ���l:
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��́A�֐����s���ɍĐ����̉��������ׂĒ�~���܂��B<br>
 * �܂��A�v���[���[�ɐݒ肵���ȉ���ACF�Ɋ֘A����p�����[�^�[��S�ă��Z�b�g���܂��B<br>
 *  -# AISAC
 *  -# AISAC�R���g���[���l
 *  -# �J�e�S��
 *  -# �Z���N�^�[���x��
 *  -# �o�X�Z���h
 * 	
 * <br>
 * �{�֐��́A�֐����s�J�n���� criFsLoader_Create �֐��Ń��[�_�[���m�ۂ��A
 * �I������ criFsLoader_Destroy �֐��Ń��[�_�[��j�����܂��B<br>
 * �{�֐������s����ۂɂ́A�󂫃��[�_�[�n���h�����P�ȏ゠���ԂɂȂ�悤�A
 * ���[�_�[���𒲐����Ă��������B<br>
 * <br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomEx_CalculateWorkSizeForRegisterAcfFile �֐��ɂ���Čv�Z�������[�N�T�C�Y����
 * ���[�N�̈���w�肵���{�֐��̌Ăяo����CRI_FALSE���Ԃ��ꂽ�ꍇ�A���[�N�̈�s�����v��
 * �̉\��������܂��B<br>
 * ���C�u�������������Ɏw�肷�� ::CriAtomExConfig �\���̂̈ȉ��̃����o�̐ݒ�l
 * ���K�؂ł��邩�m�F���Ă��������B<br>
 * - max_categories�FACF���̃J�e�S�����AREACT���Ɠ��l�ȏ�<br>
 * - categories_per_playback�FACF���̍Đ��P�ʂł̃J�e�S���Q�Ɛ��Ɠ��l�ȏ�<br>
 * <br>
 * �{�֐��ɃZ�b�g�������[�N�̈�́A ::criAtomEx_UnregisterAcf �֐������s����܂ł̊ԁA
 * �A�v���P�[�V�����ŕێ�����K�v������܂��B<br>
 * �i ::criAtomEx_UnregisterAcf �֐����s�O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B�j
 * \sa criAtomEx_UnregisterAcf
 */
CriBool CRIAPI criAtomEx_RegisterAcfFile(
	CriFsBinderHn binder, const CriChar8 *path, void *work, CriSint32 work_size);

/*JP
 * \brief ACF�t�@�C���̓o�^�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			CPK�R���e���cID
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriBool		�t�@�C���ǂݍ��݌���
 * \par ����:
 * ACF�t�@�C�������[�h���A���C�u�����Ɏ�荞�݂܂��B<br>
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomEx_RegisterAcfFile �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐��́A�֐����s���ɍĐ����̉��������ׂĒ�~���܂��B<br>
 * �܂��A�v���[���[�ɐݒ肵���p�����[�^�[��S�ă��Z�b�g���܂��B<br>
 * \sa criAtomEx_RegisterAcfFile
 */
CriBool CRIAPI criAtomEx_RegisterAcfFileById(
	CriFsBinderHn binder, CriUint16 id, void *work, CriSint32 work_size);

/*JP
 * \brief ACF�̓o�^����
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ACF���̓o�^���������܂��B<br>
 * \attention
 * �{�֐��́A�֐����s���ɍĐ����̉��������ׂĒ�~���܂��B<br>
 * �܂��A�v���[���[�ɐݒ肵���p�����[�^�[��S�ă��Z�b�g���܂��B<br>
 * �iACF�t�@�C�����o�^����ĂȂ��ۂɁA�����Đ����ɖ{�֐������s�����ꍇ�͉����͒�~����܂���j
 * ::criAtomEx_RegisterAcfFile �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomEx_RegisterAcfData, criAtomEx_RegisterAcfFile, criAtomEx_RegisterAcfFileById
 */
void CRIAPI criAtomEx_UnregisterAcf(void);

/*JP
 * \brief �I��������ACF�̃o�[�W�����擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	acf_data		ACF�f�[�^�A�h���X
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \param[out]	flag			���W�X�g�\�t���O
 * \return		CriUint32		ACF�t�H�[�}�b�g�o�[�W����
 * \par ����:
 * ��������ɔz�u���ꂽACF�f�[�^�̃t�H�[�}�b�g�o�[�W�������擾���܂��B<br>
 * �܂��Aflag�����Ƀ��W�X�g�\�ȃo�[�W�������ǂ�����Bool�l�ŕԂ��܂��B<br>
 */
CriUint32 CRIAPI criAtomEx_GetAcfVersion(
	void *acf_data, CriSint32 acf_data_size, CriBool *flag);

/*JP
 * \brief ACF�t�@�C���̃o�[�W�����擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		�t�@�C���p�X
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \param[out]	flag		���W�X�g�\�t���O
 * \return		CriUint2	ACF�t�H�[�}�b�g�o�[�W����
 * \par ����:
 * ACF�t�@�C�������[�h���AACF�f�[�^�̃t�H�[�}�b�g�o�[�W�������擾���܂��B<br>
 * ACF���̓o�^�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ::criAtomEx_CalculateWorkSizeForRegisterAcfFile �֐��Ōv�Z���܂��B<br>
 * <br>
 * ACF�t�@�C���t�H�[�}�b�g�o�[�W����������flag�����Ƀ��W�X�g�\�ȃo�[�W�������ǂ�����Bool�l�ŕԂ��܂��B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐��́A�֐����s�J�n���� criFsLoader_Create �֐��Ń��[�_�[���m�ۂ��A
 * �I������ criFsLoader_Destroy �֐��Ń��[�_�[��j�����܂��B<br>
 * �{�֐������s����ۂɂ́A�󂫃��[�_�[�n���h�����P�ȏ゠���ԂɂȂ�悤�A
 * ���[�_�[���𒲐����Ă��������B<br>
 * <br>
 * �{�֐��ɃZ�b�g�������[�N�̈�́A �A�v���P�[�V�����ŕێ�����K�v�͂���܂���B<br>
 * �i���[�h�����f�[�^�͊֐��I�����ɉ������܂��B�j
 */
CriUint32 CRIAPI criAtomEx_GetAcfVersionFromFile(
	CriFsBinderHn binder, const CriChar8 *path, void *work, CriSint32 work_size, CriBool *flag);

/*JP
 * \brief ACF�t�@�C���̃o�[�W�����擾�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			CPK�R���e���cID
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \param[out]	flag		���W�X�g�\�t���O
 * \return		CriUint2	ACF�t�H�[�}�b�g�o�[�W����
 * \par ����:
 * ACF�t�@�C�������[�h���AACF�f�[�^�̃t�H�[�}�b�g�o�[�W�������擾���܂��B<br>
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomEx_GetAcfVersionFromFile �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomEx_GetAcfVersionFromFile
 */
CriUint32 CRIAPI criAtomEx_GetAcfVersionFromFileById(
	CriFsBinderHn binder, CriUint16 id, void *work, CriSint32 work_size, CriBool *flag);

/*JP
 * \brief ���W�X�g�\�o�[�W�������擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[out]	version_low		���W�X�g�\���ʃo�[�W����
 * \param[out]	version_high	���W�X�g�\��ʃo�[�W����
 * \par ����:
 * ���W�X�g�\��ACF�̃o�[�W���������擾���܂��B<br>
 * ��ʃo�[�W�����̓��C�u�����r���h���_�ł̏��̂��߁A���̒l����ʂ�ACF�ł�
 * ���W�X�g�\�ȏꍇ������܂��B<br>
 */
void CRIAPI criAtomEx_GetSupportedAcfVersion(
	CriUint32 *version_low, CriUint32 *version_high);

/*JP
 * \brief �I�[�f�B�I�w�b�_�[�̉��
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	buffer			�I�[�f�B�I�f�[�^���i�[�����o�b�t�@�[
 * \param[in]	buffer_size		�I�[�f�B�I�f�[�^���i�[�����o�b�t�@�[�̃T�C�Y
 * \param[out]	info			�t�H�[�}�b�g���
 * \return		CriBool			�t�H�[�}�b�g��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �������Ƀ��[�h���ꂽ�����f�[�^�̃t�H�[�}�b�g����͂��܂��B<br>
 * ��͂ɐ�������ƁA�{�֐��� CRI_TRUE ��Ԃ��A�����f�[�^�̃t�H�[�}�b�g����
 * ��3�����i info �j�Ɋi�[���܂��B<br>
 * ��͂Ɏ��s�����ꍇ�A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \par ���l:
 * �{�֐��̑�1�����i buffer �j�ɂ́A�I�[�f�B�I�f�[�^�̃w�b�_�[�̈�
 * �i�����t�@�C���̐擪���������[�h�������́j���i�[���Ă����K�v������܂��B<br>
 * �����f�[�^�̓r���������Z�b�g�����ꍇ��A�w�b�_�[�O�ɗ]�v�ȃf�[�^���t������Ă���ꍇ�A
 * �w�b�_�[�̓r���܂ł����i�[����Ă��Ȃ��ꍇ�ɂ́A�{�֐��̓t�H�[�}�b�g�̉�͂Ɏ��s���܂��B<br>
 * ADX�f�[�^��HCA�f�[�^�ɂ��ẮA�����t�@�C���̐擪����2048�o�C�g���̗̈���Z�b�g����΁A
 * �t�H�[�}�b�g�̉�͂Ɏ��s���邱�Ƃ͂���܂���B<br>
 * \attention
 * ����A�{�֐���ADX�f�[�^��HCA�f�[�^�̉�͂ɂ����Ή����Ă��܂���B<br>
 * HCA-MX�f�[�^�ɂ��Ă͉�͉͂\�ł����A�w�b�_�[��񂩂��HCA�f�[�^�Ȃ̂�
 * HCA-MX�f�[�^�Ȃ̂��͋�ʂł��Ȃ����߁A�t�H�[�}�b�g��ʂƂ���
 * CRIATOMEX_FORMAT_HCA ���Ԃ���܂��B<br>
 */
CriBool CRIAPI criAtomEx_AnalyzeAudioHeader(
	const void *buffer, CriSint32 buffer_size, CriAtomExFormatInfo *info);

/*JP
 * \brief ������̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	seed		������
 * \par ����:
 * CRI Atom���C�u�����S�̂ŋ��L����^������������ɗ������ݒ肵�܂��B<br>
 * �������ݒ肷�邱�Ƃɂ��A�e�탉���_���Đ������ɍČ������������邱�Ƃ��ł��܂��B<br>
 * AtomEx�v���[���[���ƂɍČ����������������ꍇ�́A::criAtomExPlayer_SetRandomSeed �֐����g�p���Ă��������B
 * <br>
 * \sa criAtomExPlayer_SetRandomSeed
 */
void CRIAPI criAtomEx_SetRandomSeed(CriUint32 seed);

/*JP
 * \brief ACB�n���h������������\���ǂ����̃`�F�b�N
 * \ingroup ATOMLIBEX_ACB
 * \param[in]	buffer		�o�b�t�@�[
 * \param[in]	size		�o�b�t�@�[�T�C�Y
 * \return		CriBool		�Đ������ǂ����iCRI_TRUE = �Đ����̃v���[���[����ACRI_FALSE = �Đ����̃v���[���[�Ȃ��j
 * \par ����:
 * ::criAtomExPlayer_SetData �֐��ŃZ�b�g�����o�b�t�@�[�̈悪����\���ǂ������`�F�b�N���܂��B<br>
 * \par ���l:
 * �������Đ����s���Ă���AtomEx�v���[���[��S�Ē�~�������ꍇ�ł��A
 * ���C�u�������ɂ͓��Y�������̈���Q�Ƃ��Ă���{�C�X�����݂���\��������܂��B<br>
 * �i ::criAtomExPlayer_StopWithoutReleaseTime �֐��Œ�~�������s�����ꍇ��A
 * �{�C�X�̒D����肪���������ꍇ�AAtomEx�v���[���[����{�C�X�͐؂藣����܂����A
 * �{�C�X�����S�ɒ�~����܂ł̊ԁA�f�[�^�͎Q�Ƃ����\��������܂��B�j<br>
 * \attention
 * �{�֐������s����ƁA�w�肵���f�[�^�̈���Q�Ƃ��Ă���Atom�v���[���[�����݂��Ȃ����A
 * ���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * Atom�v���[���[�̍쐬�^�j���� ::criAtomEx_Lock �֐��Ń��b�N���Ă�����s���������B<br>
 * <br>
 * ::criAtomExPlayer_SetData �֐��ŃZ�b�g�����o�b�t�@�[���������ۂɂ́A
 * �f�[�^���Z�b�g�����v���[���[�ɑ΂���~�������s������A
 * �{�֐��� CRI_FALSE ��Ԃ���ԂɂȂ�܂ő҂K�v������܂��B<br>
 * �{�֐��� CRI_TRUE ��Ԃ��^�C�~���O�Ńo�b�t�@�[�̈����������ꍇ�A
 * �A�N�Z�X�ᔽ���̒v���I�Ȗ�肪��������\��������܂��B<br>
 * \sa criAtomExPlayer_SetData
 */
CriBool CRIAPI criAtomEx_IsDataPlaying(void *buffer, CriSint32 size);

/*JP
 * \brief �X�g���[�~���O���̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[out]	streaming_info	�X�g���[�~���O���ۑ���̃|�C���^
 * \retval		CRI_TRUE	�l���擾�ł���
 * \retval		CRI_FALSE	�l���擾�ł��Ȃ�����
 * \par ����:
 * CRI Atom���C�u�����̃X�g���[�~���O�Ǘ����W���[������X�g���[�~���O�����擾���܂��B<br>
 * �{�֐��́A�Ăяo���ꂽ���_�̃X�g���[�~���O���� streaming_info �ɕۑ����܂��B<br>
 * \attention
 * Atom�T�[�o�[���̏����ƈꕔ�r�����䂵�Ă��邽�߁A
 * �D��x�t�]�ɂ��Atom�T�[�o�[���~�߂Ă��܂�Ȃ��悤�ɒ��ӂ��Ă��������B<br>
 * �ꕔ�̃v���b�g�t�H�[���ł́A�X�g���[�~���O�����擾�ł��܂���B<br>
 * �{�֐��̖߂�l���m�F���Ă��������B<br>
 * �G���[�������ŃX�g���[�~���O�����擾�ł��Ȃ������ꍇ�ɂ��ẮA<br>
 * �G���[�R�[���o�b�N���������Ă��Ȃ������m�F���Ă��������B
 * \sa CriExAtomStreamingInfo
 */
#define criAtomEx_GetStreamingInfo(streaming_info) \
	criAtom_GetStreamingInfo(streaming_info)

/*JP
 * \brief �t�@�C��I/O�̋󂫎��Ԃ��g�����X�g���[�~���O�ǂݍ��݂��s�����ǂ���
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	flag	CRI_TRUE=�t�@�C��I/O�̋󂫎��Ԃ��g���ēǂݍ���
 * \retval		CRI_TRUE	����ɏ���������
 * \retval		CRI_FALSE	�G���[������
 * \par ����:
 * CRI Atom���C�u�����̃X�g���[�~���O�Ǘ����W���[���ɑ΂��āA<br>
 * �t�@�C��I/O�̋󂫎��Ԃ��g���ăX�g���[�~���O�ǂݍ��݂��s�����ǂ�����ݒ肵�܂��B<br>
 * CRI_TRUE��ݒ肷��ƁACRI Atom���C�u�����̃X�g���[�~���O�Ǘ����W���[����
 * �t�@�C��I/O�̋󂫎��Ԃ��g���āA�󂫃o�b�t�@�[�ɑ΂��ăf�[�^��]���ɓǂݍ��݂܂��B<br>
 * CRI_FALSE��ݒ肷��ƁACRI Atom���C�u�����̃X�g���[�~���O�Ǘ����W���[����
 * �t�@�C��I/O�̋󂫎��Ԃ��g��Ȃ��Ȃ�A�]���ȃX�g���[�~���O�ǂݍ��݂��s��Ȃ��Ȃ�܂��B<br>
 * �f�t�H���g�ł�CRI_TRUE��ݒ肵����Ԃł��B<br>
 * \par ���l�F
 * �t�@�C��I/O�̋󂫎��Ԃ��g���A�󂫃o�b�t�@�[�ɑ΂��ăf�[�^��]���ɓǂݍ���ł������ƂŁA
 * �V�[�N�̔����p�x�����炷�����ł��A�����I�ȃt�@�C��I/O�̌��������サ�܂��B<br>
 * ����A�ʏ�t�@�C���̃��[�h�����́A�X�g���[�~���O�̓ǂݍ��݂����D��x���Ⴂ���߁A
 * �󂫃o�b�t�@�[���傫������ƒʏ�t�@�C���̃��[�h������啝�ɒx�������Ă��܂��܂��B<br>
 * \attention
 * Atom�T�[�o�[���̏����ƈꕔ�r�����䂵�Ă��邽�߁A
 * �D��x�t�]�ɂ��Atom�T�[�o�[���~�߂Ă��܂�Ȃ��悤�ɒ��ӂ��Ă��������B
 */
#define criAtomEx_SetFreeTimeBufferingFlagForDefaultDevice(flag) \
	criAtom_SetFreeTimeBufferingFlagForDefaultDevice(flag)

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	setting		DSP�o�X�ݒ�̖��O
 * \return		CriSint32	�K�v���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * DSP�o�X�ݒ肩��DSP�o�X���\�z����̂ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * �{�֐������s����ɂ́A���炩����ACF����o�^���Ă����K�v������܂�<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́ACRI Atom Craft�ō쐬����
 * DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \sa criAtomEx_AttachDspBusSetting, criAtomEx_RegisterAcfData, criAtomEx_RegisterAcfFile,
 * criAtomEx_RegisterAcfFileById
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForDspBusSetting(
	const CriChar8 *setting);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_buffer_size	ACF�f�[�^�T�C�Y
 * \param[in]	setting_name	DSP�o�X�ݒ�̖��O
 * \return		CriSint32		�K�v���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��DSP�o�X���\�z����̂ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_CalculateWorkSizeForDspBusSetting �֐��ƈႢ�A
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B<br>
 * �i�������AACF�f�[�^�����O�Ƀ������Ƀ��[�h���A
 * ::criAtomExAsr_SetConfigForWorkSizeCalculation 
 * �֐���ASR�������p�R���t�B�O�\���̂����o�^���Ă����K�v������܂��B�j<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA
 * �G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́ACRI Atom Craft�ō쐬����
 * DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \attention
 * �n�[�h�E�F�ADSP���g�p����v���b�g�t�H�[���iASR���g�p���Ȃ��v���b�g�t�H�[���j�ł́A
 * �{�֐��Ń��[�N�̈�T�C�Y���擾���邱�Ƃ��ł��Ȃ��\��������܂��B<br>
 * �i�{�֐����s���ɃG���[�R�[���o�b�N������������A���l���Ԃ����\��������܂��B�j<br>
 * �{�֐������삵�Ȃ��v���b�g�t�H�[���ɂ��ẮA
 * ���C�u�����̏�������� ::criAtomEx_CalculateWorkSizeForDspBusSetting 
 * �֐����g�p���ĕK�v�ȃ��[�N�̈�T�C�Y���v�Z���Ă��������B<br>
 * \sa criAtomEx_AttachDspBusSetting, criAtomEx_RegisterAcfData, criAtomEx_RegisterAcfFile,
 * criAtomEx_RegisterAcfFileById, criAtomExAsr_SetConfigForWorkSizeCalculation, 
 * criAtomEx_CalculateWorkSizeForDspBusSetting
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData(
	void *acf_data, CriSint32 acf_buffer_size, const CriChar8 *setting_name);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	setting		DSP�o�X�ݒ�̖��O
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��DSP�o�X���\�z���ăT�E���h�����_���ɃA�^�b�`���܂��B<br>
 * �{�֐������s����ɂ́A���炩����ACF����o�^���Ă����K�v������܂��B<br>
 * \code
 *		�F
 * 	// ACF�t�@�C���̓ǂݍ��݂Ɠo�^
 * 	criAtomEx_RegisterAcfFile(NULL, "Sample.acf", NULL, 0);
 * 	
 * 	// DSP�o�X�ݒ�̓K�p
 * 	criAtomEx_AttachDspBusSetting("DspBusSetting_0", NULL, 0);
 * 		�F
 * \endcode
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́A
 * CRI Atom Craft�ō쐬����DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa criAtomEx_DetachDspBusSetting, criAtomEx_RegisterAcfData, criAtomEx_RegisterAcfFile,
 * criAtomEx_RegisterAcfFileById
 */
void CRIAPI criAtomEx_AttachDspBusSetting(
	const CriChar8 *setting, void *work, CriSint32 work_size);

/*JP
 * \brief DSP�o�X�ݒ�̃f�^�b�`
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * DSP�o�X�ݒ���f�^�b�`���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * DSP�o�X�ݒ�A�^�b�`���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iDSP�o�X�ݒ�A�^�b�`���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx_AttachDspBusSetting
 */
void CRIAPI criAtomEx_DetachDspBusSetting(void);

/*JP
 * \brief DSP�o�X�X�i�b�v�V���b�g�̓K�p
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	snapshot_name	�X�i�b�v�V���b�g��
 * \param[in]	time_ms			���ԁi�~���b�j
 * \par ����:
 * DSP�o�X�X�i�b�v�V���b�g��K�p���܂��B<br>
 * �{�֐����Ăяo���ƁA�X�i�b�v�V���b�g�Őݒ肵���p�����[�^�[�� time_ms �|���ĕω����܂��B<br>
 * ���� snapshot_name �� CRI_NULL ���w�肷��ƁA����DSP�o�X�ݒ�̏�ԁi�X�i�b�v�V���b�g���K�p����Ă��Ȃ���ԁj�ɖ߂�܂��B<br>
 * \sa criAtomEx_AttachDspBusSetting
 */
void CRIAPI criAtomEx_ApplyDspBusSnapshot(const CriChar8 *snapshot_name, CriSint32 time_ms);

/*JP
 * \brief �K�p����DSP�o�X�X�i�b�v�V���b�g���̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \return	const CriChar8*	�X�i�b�v�V���b�g��������ւ̃|�C���^�B
 *							�X�i�b�v�V���b�g���K�p����Ă��Ȃ��ꍇ��擾�Ɏ��s�����ꍇ��CRI_NULL���Ԃ�܂��B
 * \par ����:
 * �K�p����DSP�o�X�X�i�b�v�V���b�g�����擾���܂��B
 * �X�i�b�v�V���b�g���K�p����Ă��Ȃ��ꍇ��CRI_NULL���Ԃ�܂��B
 * \sa criAtomEx_ApplyDspBusSnapshot
 */
const CriChar8* CRIAPI criAtomEx_GetAppliedDspBusSnapshotName(void);

/*JP
 * \brief �L���[�����N�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�L���[�����N�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �L���[�Đ����ɃL���[�����N�����������ۂɁA�L���[�����N�����󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * \attention
 * �o�^���ꂽ�R�[���o�b�N�֐��́A���C�u�������ŃL���[�����N�����������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExCueLinkCbFunc
 */
void CRIAPI criAtomEx_SetCueLinkCallback(CriAtomExCueLinkCbFunc func, void* obj);

/*JP
 * \brief 5.1ch�X�s�[�J�[�p�x�̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	angle_l		�t�����g���t�g�X�s�[�J�[�̊p�x
 * \param[in]	angle_r		�t�����g���C�g�X�s�[�J�[�̊p�x
 * \param[in]	angle_sl	�T���E���h���t�g�X�s�[�J�[�̊p�x
 * \param[in]	angle_sr	�T���E���h���t�g�X�s�[�J�[�̊p�x
 * \par ����:
 * �p��3D��3D�|�W�V���j���O�̌v�Z���Ɏg�p����A�o�̓X�s�[�J�[�̊p�x�i�z�u�j��ݒ肵�܂��B<br>
 * �p�x�́A���ʕ�����0�x�Ƃ���-180�x����180�x�̊ԂŐݒ肵�Ă��������B
 * \attention
 * �{�֐���5.1ch�����̃p���X�s�[�J�[�^�C�v (4CH �܂��� 5CH) �ɂ̂݉e�����܂��B<br>
 * 7.1ch�����̃p���X�s�[�J�[�^�C�v (6CH �܂��� 7CH) �̃X�s�[�J�[�p�x��ύX����ꍇ�́A::criAtomEx_SetSpeakerAngleArray �֐����g�p���Ă��������B<br>
 * <br>
 * �ݒ肷��X�s�[�J�[�p�x�́Aangle_sl < angle_l < angle_r < angle_sr �̏��ƂȂ�悤�Ȕz�u�ɂ���K�v������܂��B<br>
 * ��F
 * \code 
 * criAtomEx_SetSpeakerAngles(-45.0f, 45.0f, -135.0f, 135.0f);
 * \endcode
 * \sa criAtomEx_SetSpeakerAngleArray
 */
void CRIAPI criAtomEx_SetSpeakerAngles(CriFloat32 angle_l, CriFloat32 angle_r, CriFloat32 angle_sl, CriFloat32 angle_sr);

/*JP
 * \brief �X�s�[�J�[�p�x�̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	speaker_system	�o�̓X�s�[�J�[�̕��я�
 * \param[in]	angle_array		�o�̓X�s�[�J�[�̊p�x�z��
 * \par ����:
 * �p��3D��3D�|�W�V���j���O�̌v�Z���Ɏg�p����A�o�̓X�s�[�J�[�̊p�x�i�z�u�j��ݒ肵�܂��B<br>
 * �p�x�́A���ʕ�����0�x�Ƃ���-180�x����180�x�̊ԂŐݒ肵�Ă��������B<br>
 * �p�x�z��́A�o�̓X�s�[�J�[�̕��я��̃X�s�[�J�[���ȏ�̗v�f���̔z����w�肵�Ă��������B<br>
 * �p�x�z��� NULL ���w�肷��ƁA�o�̓X�s�[�J�[�̕��я��ɍ��킹�āA�f�t�H���g�̊p�x��ݒ肵�܂��B<br>
 * \attention
 * FRONT LEFT��FRONT RIGHT�̈ʒu�����ւ���悤�Ȑݒ�������ꍇ�A�Ӑ}���Ȃ������ɂȂ�\��������܂��B
 * \par �⑫:
 * LOW FREQUENCY�̊p�x��ύX���Ă��A�p��3D��3D�|�W�V���j���O�̌v�Z���ʂ͕ω����܂���B<br>
 * �ݒ肵���p�x�́A�e�X�s�[�J�[�V�X�e�����ƂɓƗ����Đݒ肳��܂��B
 * \par ��F
 * \code
 * CriFloat32 angle_array[8] = {-30.0f, 30.0f, 0.0f, 0.0f, -90.0f, 90.0f, -150.0f, 150.0f}
 * criAtomEx_SetSpeakerAngleArray(CRIATOMEX_SPEAKER_SYSTEM_SURROUND_7_1, angle_array);
 * \endcode
 * \sa criAtomEx_SetSpeakerAngles
 */
void CRIAPI criAtomEx_SetSpeakerAngleArray(CriAtomExSpeakerSystem speaker_system, const CriFloat32 *angle_array);

/*JP
 * \brief �o�[�`�����X�s�[�J�[�p�x�̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	speaker_system	�o�[�`�����X�s�[�J�[�̕��я�
 * \param[in]	angle_array		�o�[�`�����X�s�[�J�[�̊p�x�z��
 * \par ����:
 * �o�[�`�����X�s�[�J�[�ɂ�����p��3D��3D�|�W�V���j���O�̌v�Z���Ɏg�p����A
 * �o�̓X�s�[�J�[�̊p�x�i�z�u�j��ݒ肵�܂��B<br>
 * �{�֐��̑���� ::criAtomEx_SetSpeakerAngleArray �֐��Ɠ��l�Ȃ��߁A��{�I�Ȑ����͂�������Q�Ƃ��ĉ������B<br>
 * \attention
 * �{�֐��ł̐ݒ�� ::criAtomEx_ControlVirtualSpeakerSetting �֐��ɂăo�[�`�����X�s�[�J�[�ݒ��L���ɂ��Ȃ�����A
 * �ݒ肵���o�[�`�����X�s�[�J�[�p�x�̓p��3D��3D�|�W�V���j���O�̌v�Z�ɔ��f����܂���B
 * \sa criAtomEx_SetSpeakerAngleArray, criAtomEx_ControlVirtualSpeakerSetting
 */
void CRIAPI criAtomEx_SetVirtualSpeakerAngleArray(CriAtomExSpeakerSystem speaker_system, const CriFloat32 *angle_array);

/*JP
 * \brief �o�[�`�����X�s�[�J�[�ݒ��ON/OFF
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	sw	�X�C�b�`�iCRI_FALSE = �����ACRI_TRUE = �L���j
 * \par ����:
 * �p��3D��3D�|�W�V���j���O�̌v�Z���Ƀo�[�`�����X�s�[�J�[�̐ݒ���g�p����@�\��ON/OFF��ݒ肵�܂��B<br>
 * ���̐ݒ��L���ɂ���ƁA�}���`�`�����l���T�E���h�� ::criAtomEx_SetVirtualSpeakerAngleArray �֐��ɂĐݒ肵��
 * �o�[�`�����X�s�[�J�[�p�x���炻�ꂼ��Đ�����܂��B
 * \attention
 * �f�t�H���g�̏�Ԃ́u�����v�ɂȂ��Ă��܂��B<br>
 * �܂��A�����{�C�X���Đ����Ɂu�L���v�ɂ����ꍇ�A�p��3D��3D�|�W�V���j���O�̌v�Z�ɂ͑������f����܂���B
 * ����{�C�X�Đ������甽�f����܂��B
 * \sa criAtomEx_SetVirtualSpeakerAngleArray
 */
void CRIAPI criAtomEx_ControlVirtualSpeakerSetting(CriBool sw);

/*JP
 * \brief �Q�[���ϐ��̑����̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \return		CriSint32	�Q�[���ϐ��̑���
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Q�[���ϐ��̑������擾���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 * ACF�t�@�C�����o�^����Ă��Ȃ��ꍇ�A-1���Ԃ�܂��B
 * \sa criAtomEx_GetGameVariableInfo
 */
CriSint32 CRIAPI criAtomEx_GetNumGameVariables(void);

/*JP
 * \brief �Q�[���ϐ����̎擾�i�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	index		�Q�[���ϐ��C���f�b�N�X
 * \param[out]	info		�Q�[���ϐ����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �Q�[���ϐ��C���f�b�N�X����Q�[���ϐ������擾���܂��B<br>
 * �w�肵���C���f�b�N�X�̃Q�[���ϐ������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 * \sa CriAtomExGameVariableInfo
 */
CriBool CRIAPI criAtomEx_GetGameVariableInfo(CriUint16 index, CriAtomExGameVariableInfo* info);

/*JP
 * \brief �Q�[���ϐ��̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	id			�Q�[���ϐ�ID
 * \return		CriFloat32	�Q�[���ϐ��l
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Q�[���ϐ��l���擾���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 */
CriFloat32 CRIAPI criAtomEx_GetGameVariableById(CriAtomExGameVariableId id);

/*JP
 * \brief �Q�[���ϐ��̎擾
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	name		�Q�[���ϐ���
 * \return		CriFloat32	�Q�[���ϐ��l
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Q�[���ϐ����擾���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 */
CriFloat32 CRIAPI criAtomEx_GetGameVariableByName(const CriChar8* name);

/*JP
 * \brief �Q�[���ϐ��̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	id			�Q�[���ϐ�ID
 * \param[in]	value		�Q�[���ϐ��l
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Q�[���ϐ��ɒl��ݒ肵�܂��B<br>
 * �ݒ�\�Ȕ͈͂�0.0f�`1.0f�̊Ԃł��B
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 */
void CRIAPI criAtomEx_SetGameVariableById(CriAtomExGameVariableId id, CriFloat32 value);

/*JP
 * \brief �Q�[���ϐ��̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	name		�Q�[���ϐ���
 * \param[in]	value		�Q�[���ϐ��l
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Q�[���ϐ��ɒl��ݒ肵�܂��B<br>
 * �ݒ�\�Ȕ͈͂�0.0f�`1.0f�̊Ԃł��B
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 */
void CRIAPI criAtomEx_SetGameVariableByName(const CriChar8* name, CriFloat32 value);

/*JP
 * \brief �v���C�o�b�N�L�����Z���R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�v���C�o�b�N�L�����Z���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �L���[�Đ����ɍĐ��J�n�����̃L�����Z�������������ۂɁA�v���C�o�b�N�L�����Z�������󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * \attention
 * �o�^���ꂽ�R�[���o�b�N�֐��́A���C�u�������ōĐ��J�n�������L�����Z�������^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExPlaybackCancelCbFunc
 */
void CRIAPI criAtomEx_SetPlaybackCancelCallback(CriAtomExPlaybackCancelCbFunc func, void* obj);

/*JP
 * \brief ACF�������`�F�b�N�@�\��ON/OFF
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	sw		�X�C�b�`�iCRI_FALSE = �`�F�b�N�����ACRI_TRUE = �`�F�b�N�L���j
 * \par ����:
 * ACB���[�h����ACF�Ƃ̐������`�F�b�N�@�\��ON/OFF��ݒ肵�܂��B<br>
 * \attention
 * �f�t�H���g�̏�Ԃ́u�`�F�b�N�L���v�ɂȂ��Ă��܂��B�u�`�F�b�N�����v�ɐݒ肵���ꍇ�ɁA
 * ������������Ȃ��g�ݍ��킹�̃f�[�^���g�p����ƁA�{���ړI�Ƃ�����ʂ������܂���B<br>
 * �܂��A�u�`�F�b�N�����v�ɂ����ꍇ�ł��A�����������s����ACB����Q�Ƃ��Ă���ACF���ڂ�
 * ������Ȃ��Ƃ��ɂ͕ʓr�G���[�R�[���o�b�N�������܂��B<br>
 */
void CRIAPI criAtomEx_ControlAcfConsistencyCheck(CriBool sw);

/*JP
 * \brief ACF�������`�F�b�N�G���[���x���̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	level		�G���[���x��
 * \par ����:
 * ACB���[�h����ACF�Ƃ̐������`�F�b�N�Ŕ�������G���[�̒ʒm���x����ݒ肵�܂��B<br>
 * �f�t�H���g��Ԃł̒ʒm���x���� CRIERR_LEVEL_WARNING �ł��B
 */
void CRIAPI criAtomEx_SetAcfConsistencyCheckErrorLevel(CriErrorLevel level);

/*JP
 * \brief �g���b�N�g�����W�V�����o�C�Z���N�^�[�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�g���b�N�g�����W�V�����o�C�Z���N�^�[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �g���b�N�g�����W�V�����o�C�Z���N�^�[�^�C�v�L���[�̍Đ����Ƀg�����W�V�����������s�����ۂ̏����󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * \attention
 * �o�^���ꂽ�R�[���o�b�N�֐��́A���C�u�������Ńg�����W�V�����������J�n�����^�C�~���O�Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u���������ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExTrackTransitionBySelectorCbFunc
 */
void CRIAPI criAtomEx_SetTrackTransitionBySelectorCallback(CriAtomExTrackTransitionBySelectorCbFunc func, void* obj);

/*==========================================================================
 *      CRI AtomEx Debug API
 *=========================================================================*/
/*JP
 * \brief CriAtomEx �����̊e�탊�\�[�X�̏󋵂̎擾
 * \ingroup ATOMEXLIB_GLOBAL_DEBUG
 * \param[out]	resources_info		CriAtomEx �����̊e�탊�\�[�X�̏�
 * \par ����:
 * CriAtomEx �����̊e�탊�\�[�X�̏󋵎擾���܂��B<br>
 * \attention
 * �J���x���f�o�b�O�@�\�ł��B�A�v���P�[�V�����J�����ɂ̂ݎg�p���Ă��������B
 * \sa CriAtomExDebugResourcesInfo
 */
void CRIAPI criAtomExDebug_GetResourcesInfo(CriAtomExDebugResourcesInfo *resources_info);

/*==========================================================================
 *      CRI AtomEx HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	config		HCA-MX�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExHcaMx_Initialize �֐���HCA-MX�̏��������s���ꍇ�A
 * �{�֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AHCA-MX�������p�R���t�B�O
 * �\���́i ::CriAtomExHcaMxConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExHcaMx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx_SetUserAllocator, criAtomExHcaMx_Initialize
 */
CriSint32 CRIAPI criAtomExHcaMx_CalculateWorkSize(const CriAtomExHcaMxConfig *config);

/*JP
 * \brief ���[�N�̈�T�C�Y�v�Z�p�R���t�B�O�\���̂̐ݒ�
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	config		HCA-MX�������p�R���t�B�O�\����
 * \par ����:
 * ���[�N�̈�T�C�Y�̌v�Z�p�ɁAHCA-MX�������p�R���t�B�O�\����
 * �i ::CriAtomExHcaMxConfig �\���́j�����o�^���܂��B<br>
 * <br>
 * HCA-MX�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * HCA-MX���������i ::criAtomExHcaMx_Initialize �֐����s���j
 * �ɐݒ肷��\���̂̃p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�ʏ�̓{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z����O�ɁA
 * HCA-MX������������K�v������܂��B<br>
 * �{�֐����g�p����HCA-MX�������p�R���t�B�O�\���̂�o�^�����ꍇ�A
 * ::criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool 
 * �֐��������������Ȃ��Ɏg�p�\�ƂȂ�܂��B<br>
 * \par ���l:
 * �����i config �j�� NULL ���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool 
 * �K�p���Ɠ����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ����A�{�֐��ň�U�R���t�B�O�\���̂�ݒ肷��ƁA
 * �ݒ�O�̏�ԁi����������Ԃł̃��[�N�̈�T�C�Y�v�Z���G���[�Ƃ��铮��j
 * �ɖ߂����Ƃ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�֐����ēx���s���ăp�����[�^�[���㏑�����邱�Ƃ͉\�ł��B�j<br>
 * \attention
 * �{�֐��œo�^�����������p�R���t�B�O�\���̂́A
 * HCA-MX����������Ԃł̃��[�N�̈�T�C�Y�v�Z�ɂ����g�p����܂���B<br>
 * HCA-MX��������ɂ͖{�֐��ɐݒ肵���p�����[�^�[�ł͂Ȃ��A
 * ���������Ɏw�肳�ꂽ�p�����[�^�[�����[�N�̈�T�C�Y�̌v�Z�Ɏg�p����܂��B<br>
 * �i�{�֐��œo�^����\���̂̃p�����[�^�[�ƁA
 * HCA-MX���������Ɏg�p����\���̂̃p�����[�^�[���قȂ�ꍇ�A
 * ���[�N�̈�T�C�Y���s�����A�n���h���̍쐬�Ɏ��s���鋰�ꂪ����܂��B�j<br>
 * \par ��:
 * \code
 * 	CriAtomExHcaMxConfig hca_mx_config;
 * 	
 * 	// ���[�N�̈�v�Z�p��HCA-MX�������ݒ�����o�^
 * 	criAtomExHcaMx_SetDefaultConfig(&hca_mx_config);
 * 	criAtomExHcaMx_SetConfigForWorkSizeCalculation(&hca_mx_config);
 * 	
 * 	// HCA-MX�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * 	hca_mx_vp_work_size = criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool(NULL);
 * 		�F
 * \endcode
 * \sa criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool, criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool
 */
void CRIAPI criAtomExHcaMx_SetConfigForWorkSizeCalculation(const CriAtomExHcaMxConfig *config);

/*JP
 * \brief HCA-MX�̏�����
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	config	HCA-MX�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * HCA-MX�̏��������s���܂��B<br>
 * �{�֐������s���邱�ƂŁAHCA-MX�f�[�^�̏o�͋@�\���N������܂��B<br>
 * \par ���l:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AHCA-MX�������p�R���t�B�O
 * �\���́i ::CriAtomExHcaMxConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExHcaMx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j�ŏ������������s���܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomExHcaMx_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtomExHcaMx_Finalize �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa criAtomEx_SetUserAllocator, criAtomExHcaMx_CalculateWorkSize
 */
void CRIAPI criAtomExHcaMx_Initialize(
	const CriAtomExHcaMxConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA-MX�̏I��
 * \ingroup ATOMEXLIB_HCA_MX
 * \par ����:
 * HCA-MX�̏I���������s���܂��B<br>
 * �{�֐������s���邱�ƂŁAHCA-MX�f�[�^�̏o�͂���~����܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * HCA-MX���������Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iHCA-MX���������Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx_SetUserAllocator, criAtomExHcaMx_Initialize
 */
void CRIAPI criAtomExHcaMx_Finalize(void);

/*JP
 * \brief �~�L�T�̃o�X�Z���h���x���ݒ�
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	mixer_id	�~�L�TID
 * \param[in]	bus_name	�o�X��
 * \param[in]	level		�Z���h���x���l�i0.0f�`1.0f�j
 * \par ����:
 * �~�L�T�̃o�X�Z���h���x����ݒ肵�܂��B<br>
 * �f�t�H���g��Ԃł́AHCA-MX�̃f�R�[�h���ʂ̓~�L�T�Ɋi�[���ꂽ��A
 * �o�X0��1.0f�̃��x���ő��M����܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�f�R�[�h���ʂ𑼂̃o�X�ւ��Z���h���邱�Ƃ��\�ɂȂ�܂��B<br>
 * �i�~�L�T���ƂɈقȂ�o�X�G�t�F�N�g��K�p�\�ɂȂ�܂��B�j<br>
 */
void CRIAPI criAtomExHcaMx_SetBusSendLevelByName(
	CriSint32 mixer_id, const CriChar8* bus_name, CriFloat32 level);

/*JP
 * \brief �~�L�T�̏o�͎��g��������̐ݒ�
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	mixer_id	�~�L�TID
 * \param[in]	ratio		�Z���h���x���l�i0.25f�`4.0f�j
 * \par ����:
 * �~�L�T�̏o�͎��g���������ݒ肵�܂��B<br>
 * ���g��������́A�����f�[�^�̎��g���ƍĐ����g���̔䗦�ŁA�Đ����x�̔{���Ɠ����ł��B<br>
 * ���g���䂪1.0f�𒴂���ꍇ�A�����f�[�^�͌�����荂���ɍĐ�����A
 * 1.0f�����̏ꍇ�́A�����f�[�^�͌������ᑬ�ōĐ�����܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�Ώۂ̃~�L�T���g�p����v���[���[�ōĐ������S�Ă�HCA-MX�{�C�X
 * �iHCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�̍Đ��j�ɂ��āA�Đ����x���ύX����܂�
 * �iHCA-MX�{�C�X���Đ�����ꍇ�A�X�̃v���[���[�ł̍Đ����x�̐ݒ�͖�������܂��j�B<br>
 */
void CRIAPI criAtomExHcaMx_SetFrequencyRatio(CriSint32 mixer_id, CriFloat32 ratio);

/*JP
 * \brief ASR���b�NID�̎w��
 * \ingroup ATOMEXLIB_HCA_MX
 * \param[in]	mixer_id	�~�L�TID
 * \param[in]	rack_id		ASR���b�NID
 * \par ����:
 * �~�L�T�̏o�͐�ASR���b�NID���w�肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�Ώۂ̃~�L�T���g�p����v���[���[�ōĐ������S�Ă�HCA-MX�{�C�X
 * �iHCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�̍Đ��j�ɂ��āA�o�͐�ASR���b�NID���ύX����܂�
 * �iHCA-MX�{�C�X���Đ�����ꍇ�A�X�̃v���[���[�ł�ASR���b�NID�̐ݒ�͖�������܂��j�B<br>
 * \attention
 * �{�֐��� �~�L�T�̃T�E���h�����_���^�C�v��ASR���g�p����ꍇ�ɂ̂݌��ʂ�����܂��B<br>
 * �i���̃T�E���h�����_���^�C�v�̏ꍇ�A�{�֐��̐ݒ�l�͖�������܂��B�j<br>
 * \sa CriAtomExAsr_CreateRack
 */
void CRIAPI criAtomExHcaMx_SetAsrRackId(CriSint32 mixer_id, CriSint32 rack_id);

/*==========================================================================
 *      CRI AtomEx ACF API
 *=========================================================================*/
/*JP
 * \brief AISAC�R���g���[�����̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	AISAC�R���g���[����
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��AISAC�R���g���[���̐����擾���܂��B<br>
 * ACF���o�^����Ă��Ȃ��ꍇ�A-1���Ԃ�܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumAisacControls(void);

/*JP
 * \brief AISAC�R���g���[�����̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		AISAC�R���g���[���C���f�b�N�X
 * \param[out]	info		AISAC�R���g���[�����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * AISAC�R���g���[���C���f�b�N�X����AISAC�R���g���[�������擾���܂��B<br>
 * �w�肵���C���f�b�N�X��AISAC�R���g���[�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetAisacControlInfo(CriUint16 index, CriAtomExAisacControlInfo* info);

/*JP
 * \brief AISAC�R���g���[��ID�̎擾�iAISAC�R���g���[�����w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	name					AISAC�R���g���[����
 * \return		CriAtomExAisacControlId	AISAC�R���g���[��ID
 * \par ����:
 * AISAC�R���g���[��������AISAC�R���g���[��ID���擾���܂��B<br>
 * ACF���o�^����Ă��Ȃ��A�܂��͎w�肵��AISAC�R���g���[������AISAC�R���g���[�������݂��Ȃ��ꍇ�ACRIATOMEX_INVALID_AISAC_CONTROL_ID���Ԃ�܂��B
 */
CriAtomExAisacControlId CRIAPI criAtomExAcf_GetAisacControlIdByName(const CriChar8* name);

/*JP
 * \brief AISAC�R���g���[�����̎擾�iAISAC�R���g���[��ID�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	id				AISAC�R���g���[��ID
 * \return		const CriChar8* AISAC�R���g���[����
 * \par ����:
 * AISAC�R���g���[��ID����AISAC�R���g���[�������擾���܂��B<br>
 * ACF���o�^����Ă��Ȃ��A�܂��͎w�肵��AISAC�R���g���[��ID��AISAC�R���g���[�������݂��Ȃ��ꍇ�ANULL���Ԃ�܂��B
 */
const CriChar8 * CRIAPI criAtomExAcf_GetAisacControlNameById(CriAtomExAisacControlId id);

/*JP
 * \brief DSP�o�X�ݒ萔�̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	DSP�o�X�ݒ萔
 * \par ����:
 * ���C�u�����ɓo�^���ꂽACF�f�[�^�Ɋ܂܂��DSP�o�X�ݒ�̐����擾���܂��B<br>
 * ACF�f�[�^���o�^����Ă��Ȃ��ꍇ�A�{�֐��� -1 ��Ԃ��܂��B<br>
 * \sa criAtomExAcf_GetDspSettingNameByIndex
 */
CriSint32 CRIAPI criAtomExAcf_GetNumDspSettings(void);

/*JP
 * \brief ACF�f�[�^����DSP�o�X�ݒ萔���擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return		CriSint32		DSP�o�X�ݒ萔
 * \par ����:
 * �w�肳�ꂽACF�Ɋ܂܂��DSP�o�X�ݒ�̐����擾���܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetNumDspSettings �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetNumDspSettings
 */
CriSint32 CRIAPI criAtomExAcf_GetNumDspSettingsFromAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief DSP�o�X�ݒ薼�̎擾�iindex�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index			DSP�o�X�ݒ�C���f�b�N�X
 * \return		const CriChar8* DSP�o�X�ݒ薼
 * \par ����:
 * ���C�u�����ɓo�^���ꂽACF�f�[�^����DSP�o�X�ݒ薼���擾���܂��B<br>
 * ACF�f�[�^���o�^����Ă��Ȃ����A
 * �܂��͎w�肵��DSP�o�X�ݒ�C���f�b�N�X��DSP�o�X�ݒ肪���݂��Ȃ��ꍇ�A
 * �{�֐��� NULL ��Ԃ��܂��B<br>
 * \sa criAtomExAcf_GetDspSettingInformation 
 */
const CriChar8 * CRIAPI criAtomExAcf_GetDspSettingNameByIndex(CriUint16 index);

/*JP
 * \brief ACF�f�[�^����DSP�o�X�ݒ薼���擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \param[in]	index			DSP�o�X�ݒ�C���f�b�N�X
 * \return		const CriChar8* DSP�o�X�ݒ薼
 * \par ����:
 * �w�肳�ꂽACF�f�[�^�Ɋ܂܂��DSP�o�X�ݒ薼���擾���܂��B<br>
 * �� 3 �����i index �j�ɂ́A���Ԗڂ�DSP�o�X�ݒ�̖��̂��擾���邩���w�肵�܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetDspSettingNameByIndex �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetDspSettingNameByIndex 
 */
const CriChar8 * CRIAPI criAtomExAcf_GetDspSettingNameByIndexFromAcfData(
	void *acf_data, CriSint32 acf_data_size, CriUint16 index);

/*JP
 * \brief DSP�o�X�ݒ���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	name		�Z�b�e�B���O��
 * \param[out]	info		�Z�b�e�B���O���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �Z�b�e�B���O�����w�肵�ăZ�b�e�B���O�����擾���܂��B<br>
 * �w�肵���Z�b�e�B���O����Dsp setting�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExAcf_GetDspSettingNameByIndex,  criAtomExAcf_GetDspBusInformation
 */
CriBool CRIAPI criAtomExAcf_GetDspSettingInformation(const CriChar8* name, CriAtomExAcfDspSettingInfo* info);

/*JP
 * \brief DSP�o�X�ݒ�X�i�b�v�V���b�g���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		�X�i�b�v�V���b�g�C���f�b�N�X
 * \param[out]	info		�X�i�b�v�V���b�g���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �X�i�b�v�V���b�g�C���f�b�N�X���w�肵�ăX�i�b�v�V���b�g�����擾���܂��B<br>
 * �w�肵���Z�b�e�B���O���̃X�i�b�v�V���b�g�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * �X�i�b�v�V���b�g�C���f�b�N�X�͐e�ƂȂ�DSP�o�X�ݒ���� ::CriAtomExAcfDspSettingInfo �\���̓���
 * snapshot_start_index�����o��num_snapshots�����o�����ɓK�؂Ȓl���Z�o���Ă��������B
 * \sa criAtomExAcf_GetDspBusInformation
 */
CriBool CRIAPI criAtomExAcf_GetDspSettingSnapshotInformation(CriUint16 index, CriAtomExAcfDspSettingSnapshotInfo* info);

/*JP
 * \brief DSP�o�X�̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		�o�X�C���f�b�N�X
 * \param[out]	info		�o�X���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �C���f�b�N�X���w�肵��DSP�o�X�����擾���܂��B<br>
 * �w�肵���C���f�b�N�X����DSP�o�X�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExAcf_GetDspSettingInformation,  criAtomExAcf_GetDspFxName, criAtomExAcf_GetDspFxParameters, criAtomExAcf_GetDspBusLinkInformation
 */
CriBool CRIAPI criAtomExAcf_GetDspBusInformation(CriUint16 index, CriAtomExAcfDspBusInfo* info);

/*JP
 * \brief DSP FX���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		DSP FX�C���f�b�N�X
 * \return		const CriChar8* ������ւ̃|�C���^�B���s�����ꍇ�́ACRI_NULL���Ԃ�܂��B
 * \par ����:
 * �C���f�b�N�X���w�肵��DSP FX���𕶎���Ŏ擾���܂��B<br>
 * DSP FX����ASR���g�p��������AACF Ver.1.16.00 �ȍ~��ACF���g�p�������Ɏ擾�\�ł��B<br>
 * ASR���g�p���Ȃ����A�܂���ACF Ver.1.15.01 �ȑO�ł�CRI_NULL�� <br>
 * �Ԃ�܂��B::criAtomExAcf_GetAcfInfo �֐���ACF�̃o�[�W�������m�F���Ă��g�p�������B
 * \sa criAtomExAcf_GetDspBusInformation, criAtomExAcf_GetDspFxParameters, criAtomExAcf_GetAcfInfo
 */
const CriChar8* CRIAPI criAtomExAcf_GetDspFxName(CriUint16 index);

/*JP
 * \brief DSP FX�p�����[�^�[�̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		DSP FX�C���f�b�N�X
 * \param[out]	parameters	DSP FX�p�����[�^�[
 * \param[in]	size		DSP FX�p�����[�^�[���[�N�T�C�Y
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �C���f�b�N�X���w�肵��ACF����FX�p�����[�^�[���擾���܂��B<br>
 * �w�肵���C���f�b�N�X����DSP FX�����݂��Ȃ��ꍇ�ACRI FALSE���Ԃ�܂��B<br>
 * size�����ɂ�DSP FX�^�C�v�ɉ������p�����[�^�[�̃T�C�Y���w�肵�Ă��������B<br>
 * �T�E���h�����_����ASR���w�肵���ꍇ�́AACF�ɂ�����s���p�����[�^�[��float�z��̌`����parameters�Ɏ擾����܂��B
 * ASR�ȊO�ł̃T�E���h�����_���ł́A�p�����[�^�[�\���̂������܂��B
 * \sa criAtomExAcf_GetDspBusInformation, criAtomExAcf_GetDspFxName
 */
CriBool CRIAPI criAtomExAcf_GetDspFxParameters(CriUint16 index, void* parameters, CriSint32 size);

/*JP
 * \brief DSP�o�X�����N�̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		DSP�o�X�����N�C���f�b�N�X
 * \param[out]	info		DSP�o�X�����N���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �C���f�b�N�X���w�肵�ăo�X�����N�����擾���܂��B<br>
 * �w�肵���C���f�b�N�X����DSP�o�X�����N�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExAcf_GetDspBusInformation
 */
CriBool CRIAPI criAtomExAcf_GetDspBusLinkInformation(CriUint16 index, CriAtomExAcfDspBusLinkInfo* info);

/*JP
 * \brief ACF�f�[�^����J�e�S�������擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return	CriSint32			�J�e�S����
 * \par ����:
 * �w�肳�ꂽACF�Ɋ܂܂��J�e�S���̐����擾���܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetNumCategories �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetNumCategories
 */
CriSint32 CRIAPI criAtomExAcf_GetNumCategoriesFromAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief �J�e�S�����̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	�J�e�S����
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��J�e�S���̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumCategories(void);

/*JP
 * \brief ACF�f�[�^����Đ����J�e�S���Q�Ɛ����擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return	CriSint32			�Đ����J�e�S���Q�Ɛ�
 * \par ����:
 * �w�肳�ꂽACF�Ɋ܂܂��J�e�S���̐����擾���܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetNumCategoriesPerPlayback �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetNumCategoriesPerPlayback
 */
CriSint32 CRIAPI criAtomExAcf_GetNumCategoriesPerPlaybackFromAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief �Đ����J�e�S���Q�Ɛ��̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	�Đ����J�e�S���Q�Ɛ�
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��Đ����J�e�S���Q�Ɛ����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumCategoriesPerPlayback(void);

/*JP
 * \brief �J�e�S�����̎擾�i�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		�J�e�S���C���f�b�N�X
 * \param[out]	info		�J�e�S�����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �J�e�S���C���f�b�N�X����J�e�S�������擾���܂��B<br>
 * �w�肵���C���f�b�N�X�̃J�e�S�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetCategoryInfo(CriUint16 index, CriAtomExCategoryInfo* info);

/*JP
 * \brief �J�e�S�����̎擾�i�J�e�S�����w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	name		�J�e�S����
 * \param[out]	info		�J�e�S�����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �J�e�S��������J�e�S�������擾���܂��B<br>
 * �w�肵���J�e�S�����̃J�e�S�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetCategoryInfoByName(const CriChar8* name, CriAtomExCategoryInfo* info);

/*JP
 * \brief �J�e�S�����̎擾�i�J�e�S��ID�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	id			�J�e�S��ID
 * \param[out]	info		�J�e�S�����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �J�e�S��ID����J�e�S�������擾���܂��B<br>
 * �w�肵���J�e�S��ID�̃J�e�S�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetCategoryInfoById(CriUint32 id, CriAtomExCategoryInfo* info);

/*JP
 * \brief Global Aisac���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	Global Aisac��
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��Global Aisac�̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumGlobalAisacs(void);

/*JP
 * \brief Global Aisac���̎擾�i�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		Global Aisac�C���f�b�N�X
 * \param[out]	info		Global Aisac���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * Global Aisac�C���f�b�N�X����Aisac�����擾���܂��B<br>
 * �w�肵���C���f�b�N�X��Global Aisac�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetGlobalAisacInfo(CriUint16 index, CriAtomExGlobalAisacInfo* info);

/*JP
 * \brief Global Aisac���̎擾�i���O�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	name		Global Aisac��
 * \param[out]	info		Global Aisac���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * Global Aisac������Aisac�����擾���܂��B<br>
 * �w�肵�����O��Global Aisac�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetGlobalAisacInfoByName(const CriChar8* name, CriAtomExGlobalAisacInfo* info);

/*JP
 * \brief Global Aisac Graph���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	aisac_info		Global Aisac���
 * \param[in]	graph_index		Aisac graph�C���f�b�N�X
 * \param[out]	graph_info		Aisac graph���
 * \return		CriBool			��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * Global Aisac����graph�C���f�b�N�X����graph�����擾���܂��B<br>
 * �w�肵���C���f�b�N�X��Global Aisac�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetGlobalAisacGraphInfo(
	const CriAtomExGlobalAisacInfo* aisac_info,
	CriUint16 graph_index,
	CriAtomExAisacGraphInfo* graph_info);

/*JP
 * \brief Global Aisac�l�̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	aisac_info					Global Aisac���
 * \param[in]	control						AISAC�R���g���[���l
 * \param[in]	type						�O���t�^�C�v
 * \param[out]	value						AISAC�l
 * \return		CriBool						�l���擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * Global Aisac���A�R���g���[���l�A�O���t�^�C�v���w�肵��Aisac�l���擾���܂��B<br>
 * �w�肵���C���f�b�N�X��Global Aisac�����݂��Ȃ��ꍇ��O���t�����݂��Ȃ��ꍇ�́ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetGlobalAisacValue(
	const CriAtomExGlobalAisacInfo* aisac_info,
	CriFloat32 control,
	CriAtomExAisacGraphType type,
	CriFloat32* value);

/*JP
 * \brief ACF���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[out]	acf_info		ACF���
 * \return		CriBool			��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * ���C�u�����ɓo�^���ꂽACF�f�[�^�̊e������擾���܂��B<br>
 * ACF���̎擾�Ɏ��s�����ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetAcfInfo(CriAtomExAcfInfo *acf_info);

/*JP
 * \brief ACF�f�[�^����ACF�����擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \param[out]	acf_info		ACF���
 * \return		CriBool			��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肳�ꂽACF�f�[�^�̊e������擾���܂��B<br>
 * ACF���̎擾�Ɏ��s�����ꍇ�ACRI_FALSE���Ԃ�܂��B
 * \par ���l:
 * ::criAtomExAcf_GetAcfInfo �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \attention
 * �擾����ACF�����̃|�C���^�����o�́AACF�f�[�^�̈�����w���Ă��܂��B�i���O������ւ̃|�C���^���j<br>
 * �擾����ACF�����Q�Ƃ��Ă���Ԃ́AACF�f�[�^�̈��������Ȃ��悤�����ӂ��������B
 * \sa criAtomExAcf_GetAcfInfo 
 */
CriBool CRIAPI criAtomExAcf_GetAcfInfoFromAcfData(
	void *acf_data, CriSint32 acf_data_size, CriAtomExAcfInfo *acf_info);

/*JP
 * \brief �Z���N�^�[���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	�Z���N�^�[��
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��Z���N�^�[�̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumSelectors(void);

/*JP
 * \brief �Z���N�^�[���̎擾�i�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	index		�Z���N�^�[�C���f�b�N�X
 * \param[out]	info		�Z���N�^�[���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �Z���N�^�[�C���f�b�N�X����Z���N�^�[�����擾���܂��B<br>
 * �w�肵���C���f�b�N�X�̃Z���N�^�[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetSelectorInfoByIndex(CriUint16 index, CriAtomExSelectorInfo* info);

/*JP
 * \brief �Z���N�^�[���̎擾�i���O�w��j
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	name		�Z���N�^�[��
 * \param[out]	info		�Z���N�^�[���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �Z���N�^�[������Z���N�^�[�����擾���܂��B<br>
 * �w�肵�����O�̃Z���N�^�[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetSelectorInfoByName(const CriChar8* name, CriAtomExSelectorInfo* info);

/*JP
 * \brief �Z���N�^�[���x�����̎擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	selector_info		�Z���N�^�[���
 * \param[in]	label_index			���x���C���f�b�N�X
 * \param[out]	label_info			�Z���N�^�[���x�����
 * \return		CriBool				��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �Z���N�^�[���ƃZ���N�^�[���x���C���f�b�N�X����Z���N�^�[���x�������擾���܂��B<br>
 * �w�肵���C���f�b�N�X�̃Z���N�^�[���x�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExAcf_GetSelectorLabelInfo(
	const CriAtomExSelectorInfo* selector_info,
	CriUint16 label_index,
	CriAtomExSelectorLabelInfo* label_info);

/*JP
 * \brief �Z���N�^�[�ɑ΂���O���[�o���Q�ƃ��x���̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	selsector_name	�Z���N�^�[��
 * \param[in]	label_name		���x����
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Z���N�^�[�ɑ΂��ăO���[�o���Q�Ƃ���郉�x����ݒ肵�܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 * \sa criAtomExAcf_SetGlobalLabelToSelectorByIndex
 */
void CRIAPI criAtomExAcf_SetGlobalLabelToSelectorByName(const CriChar8* selsector_name, const CriChar8* label_name);

/*JP
 * \brief �Z���N�^�[�ɑ΂���O���[�o���Q�ƃ��x���̐ݒ�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	selsector_index	�Z���N�^�[�C���f�b�N�X
 * \param[in]	label_index		���x���C���f�b�N�X
 * \par ����:
 * ACF�t�@�C�����ɓo�^����Ă���Z���N�^�[�ɑ΂��ăO���[�o���Q�Ƃ���郉�x����ݒ肵�܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAACF�t�@�C����o�^���Ă����K�v������܂��B<br>
 * \sa criAtomExAcf_SetGlobalLabelToSelectorByName
 */
void CRIAPI criAtomExAcf_SetGlobalLabelToSelectorByIndex(CriUint16 selsector_index, CriUint16 label_index);

/*JP
 * \brief ACF�f�[�^����o�X�����擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return	CriSint32			�o�X��
 * \par ����:
 * �w�肳�ꂽACF�Ɋ܂܂��o�X�̐����擾���܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetNumBuses �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetNumBuses
 */
CriSint32 CRIAPI criAtomExAcf_GetNumBusesFromAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief �o�X���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	�o�X��
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��o�X�̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetNumBuses(void);

/*JP
 * \brief ACF�f�[�^����DSP�o�X�ݒ���̍ő�o�X�����擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \return	CriSint32			DSP�o�X�ݒ���̍ő�o�X��
 * \par ����:
 * �w�肳�ꂽACF�Ɋ܂܂��DSP�o�X�ݒ���̍ő�o�X�̐����擾���܂��B<br>
 * \par ���l:
 * ::criAtomExAcf_GetMaxBusesOfDspBusSettings �֐��ƈقȂ�A<br>
 * ACF����o�^����O�ł��{�֐��͎��s�\�ł��B
 * \sa criAtomExAcf_GetMaxBusesOfDspBusSettings
 */
CriSint32 CRIAPI criAtomExAcf_GetMaxBusesOfDspBusSettingsFromAcfData(
	void *acf_data, CriSint32 acf_data_size);

/*JP
 * \brief DSP�o�X�ݒ���̍ő�o�X���̎擾
 * \ingroup ATOMEXLIB_ACF
 * \return		CriSint32	DSP�o�X�ݒ���̍ő�o�X��
 * \par ����:
 * �o�^���ꂽACF�Ɋ܂܂��DSP�o�X�ݒ���̍ő�o�X�̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExAcf_GetMaxBusesOfDspBusSettings(void);

/*JP
 * \brief ACF���̃o�X���擾
 * \ingroup ATOMEXLIB_ACF
 * \param[in]	bus_name		�o�X��
 * \return	st CriChar8*		ACF���o�X��
 * \par ����:
 * �w�肳�ꂽ�o�X����ACF����������擾���܂��B<br>
 * ���݂��Ȃ��o�X�����w�肵���ꍇ��NULL���Ԃ�܂��B<br>	 
 */
const CriChar8* CRIAPI criAtomExAcf_FindBusName(const CriChar8* bus_name);


/*==========================================================================
 *      CRI AtomEx ACB API
 *=========================================================================*/
/*JP
 * \brief �I��������ACB�f�[�^�̃��[�h�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_data		ACB�f�[�^�A�h���X
 * \param[in]	acb_data_size	ACB�f�[�^�T�C�Y
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path		AWB�t�@�C���̃p�X
 * \return		CriSint32		���[�N�̈�T�C�Y
 * \retval		0�ȏ�			����ɏ���������
 * \retval		-1				�G���[������
 * \par ����:
 * ::criAtomExAcb_LoadAcbData �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExAcb_LoadAcbData �֐���AWB�f�[�^�����[�h����ۂɂ́A
 * �{�֐����Ԃ��T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExAcb_LoadAcbData
 */
CriSint32 CRIAPI criAtomExAcb_CalculateWorkSizeForLoadAcbData(
	void *acb_data, CriSint32 acb_data_size,
	CriFsBinderHn awb_binder, const CriChar8 *awb_path);

/*JP
 * \brief �I��������ACB�f�[�^�̃��[�h�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_data		ACB�f�[�^�A�h���X
 * \param[in]	acb_data_size	ACB�f�[�^�T�C�Y
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_id			CPK�t�@�C������AWB�f�[�^��ID
 * \return		CriSint32		���[�N�̈�T�C�Y
 * \retval		0�ȏ�			����ɏ���������
 * \retval		-1				�G���[������
 * \par ����:
 * ::criAtomExAcb_LoadAcbDataById �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomExAcb_CalculateWorkSizeForLoadAcbData �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_CalculateWorkSizeForLoadAcbData, criAtomExAcb_LoadAcbDataById
 */
CriSint32 CRIAPI criAtomExAcb_CalculateWorkSizeForLoadAcbDataById(
	void *acb_data, CriSint32 acb_data_size, CriFsBinderHn awb_binder, CriUint16 awb_id);

/*JP
 * \brief �I��������ACB�f�[�^�̃��[�h
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_data		ACB�f�[�^�A�h���X
 * \param[in]	acb_data_size	ACB�f�[�^�T�C�Y
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path		AWB�t�@�C���̃p�X
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \return		CriAtomExAcbHn	ACB�n���h��
 * \par ����:
 * ACB�f�[�^�����[�h���A�L���[�Đ��ɕK�v�ȏ�����荞�݂܂��B<br>
 * ACB�f�[�^�̃��[�h�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ::criAtomExAcb_CalculateWorkSizeForLoadAcbData �֐��Ōv�Z���܂��B<br>
 * <br>
 * ��3������ awb_binder �A����ё�4������ awb_path �ɂ́A�X�g���[���Đ��p
 * ��AWB�t�@�C�����w�肵�܂��B<br>
 * �i�I���������Đ��݂̂�ACB�f�[�^�����[�h����ꍇ�A awb_binder �����
 * awb_path �ɃZ�b�g�����l�͖�������܂��B�j<br>
 * <br>
 * ACB�f�[�^�����[�h����ƁAACB�f�[�^�ɃA�N�Z�X���邽�߂�ACB�n���h��
 * �i ::CriAtomExAcbHn �j���Ԃ���܂��B<br>
 * AtomEx�v���[���[�ɑ΂��A ::criAtomExPlayer_SetCueId �֐���ACB�n���h���A����эĐ�����
 * �L���[��ID���Z�b�g���邱�ƂŁAACB�f�[�^���̃L���[���Đ����邱�Ƃ��\�ł��B<br>
 * <br>
 * ACB�t�@�C���̃��[�h�ɐ�������ƁA�{�֐��͖߂�l�Ƃ��� ACB �n���h����Ԃ��܂��B<br>
 * ���[�h�G���[���ɂ��ACB�t�@�C���̃��[�h�Ɏ��s�����ꍇ�A�{�֐��͖߂�l�Ƃ���
 * CRI_NULL ��Ԃ��܂��B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * �{�֐��͑������A�֐��ł��B<br>
 * ACB�t�@�C�������O�Ƀ������Ƀ��[�h���Ă���{�֐������s���邱�ƂŁA
 * ACB�n���h���쐬���ɏ������u���b�N�����̂�����\�ł��B
 * <br>
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐��ɂăZ�b�g�����f�[�^�̈�⃏�[�N�̈�̃��������e��ACB�n���h���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * �܂��A�f�[�^�̈�̈ꕔ�̓��[�N�Ƃ��Ďg�p����܂��B<br>
 * <br>
 * ACB�f�[�^�ɂ̓��[�N�̈���܂܂�Ă��܂��B<br>
 * ���̂��߁A1��ACB�f�[�^�̈�𕡐��񓯎��Ƀ��[�h���邱�Ƃ͂ł��܂���B<br>
 * �i�쐬���ꂽACB�n���h���𕡐���AtomEx�v���[���[�ŋ��L���邱�Ƃ͉\�ł��B�j<br>
 * <br>
 * ACB�n���h���͓����I�Ƀo�C���_�[�i CriFsBinderHn �j���m�ۂ��܂��B<br>
 * ACB�t�@�C�������[�h����ꍇ�AACB�n���h�������̃o�C���_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExAcb_CalculateWorkSizeForLoadAcbData, CriAtomExAcbHn, criAtomExPlayer_SetCueId
 */
CriAtomExAcbHn CRIAPI criAtomExAcb_LoadAcbData(
	void *acb_data, CriSint32 acb_data_size,
	CriFsBinderHn awb_binder, const CriChar8 *awb_path,
	void *work, CriSint32 work_size);

/*JP
 * \brief �I��������ACB�f�[�^�̃��[�h�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_data		ACB�f�[�^�A�h���X
 * \param[in]	acb_data_size	ACB�f�[�^�T�C�Y
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_id			CPK�t�@�C������AWB�f�[�^��ID
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \return		CriAtomExAcbHn	ACB�n���h��
 * \par ����:
 * ACB�f�[�^�����[�h���A�L���[�Đ��ɕK�v�ȏ�����荞�݂܂��B<br>
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomExAcb_LoadAcbData �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_LoadAcbData
 */
CriAtomExAcbHn CRIAPI criAtomExAcb_LoadAcbDataById(
	void *acb_data, CriSint32 acb_data_size, CriFsBinderHn awb_binder, CriUint16 awb_id,
	void *work, CriSint32 work_size);

/*JP
 * \brief ACB�t�@�C���̃��[�h�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_binder	ACB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	acb_path	ACB�t�@�C���̃p�X
 * \param[in]	awb_binder	AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path	AWB�t�@�C���̃p�X
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ::criAtomExAcb_LoadAcbFile �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExAcb_LoadAcbFile �֐���ACB�t�@�C�������[�h����ۂɂ́A
 * �{�֐����Ԃ��T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��́A�֐����s�J�n���� criFsLoader_Create �֐��Ń��[�_�[���m�ۂ��A
 * �I������ criFsLoader_Destroy �֐��Ń��[�_�[��j�����܂��B<br>
 * �{�֐������s����ۂɂ́A�󂫃��[�_�[�n���h�����P�ȏ゠���ԂɂȂ�悤�A
 * ���[�_�[���𒲐����Ă��������B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * ACB�t�@�C���̃��[�h�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * ACB�t�@�C���̃��[�h�́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomExAcb_LoadAcbFile
 */
CriSint32 CRIAPI criAtomExAcb_CalculateWorkSizeForLoadAcbFile(
	CriFsBinderHn acb_binder, const CriChar8 *acb_path,
	CriFsBinderHn awb_binder, const CriChar8 *awb_path);

/*JP
 * \brief ACB�t�@�C���̃��[�h�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_binder	ACB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	acb_id		CPK�t�@�C������ACB�f�[�^��ID
 * \param[in]	awb_binder	AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_id		CPK�t�@�C������AWB�f�[�^��ID
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ::criAtomExAcb_LoadAcbFileById �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomExAcb_CalculateWorkSizeForLoadAcbFile �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_CalculateWorkSizeForLoadAcbFile, criAtomExAcb_LoadAcbFileById
 */
CriSint32 CRIAPI criAtomExAcb_CalculateWorkSizeForLoadAcbFileById(
	CriFsBinderHn acb_binder, CriUint16 acb_id, CriFsBinderHn awb_binder, CriUint16 awb_id);

/*JP
 * \brief ACB�t�@�C���̃��[�h
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_binder		ACB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	acb_path		ACB�t�@�C���̃p�X
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path		AWB�t�@�C���̃p�X
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \return		CriAtomExAcbHn	ACB�n���h��
 * \par ����:
 * ACB�t�@�C�������[�h���A�L���[�Đ��ɕK�v�ȏ�����荞�݂܂��B<br>
 * ACB�t�@�C���̃��[�h�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ::criAtomExAcb_CalculateWorkSizeForLoadAcbFile �֐��Ōv�Z���܂��B<br>
 * <br>
 * ��3������ awb_binder �A����ё�4������ awb_path �ɂ́A�X�g���[���Đ��p
 * ��AWB�t�@�C�����w�肵�܂��B<br>
 * �i�I���������Đ��݂̂�ACB�f�[�^�����[�h����ꍇ�A awb_binder �����
 * awb_path �ɃZ�b�g�����l�͖�������܂��B�j<br>
 * <br>
 * ACB�t�@�C�������[�h����ƁAACB�f�[�^�ɃA�N�Z�X���邽�߂�ACB�n���h��
 * �i ::CriAtomExAcbHn �j���Ԃ���܂��B<br>
 * AtomEx�v���[���[�ɑ΂��A ::criAtomExPlayer_SetCueId �֐���ACB�n���h���A����эĐ�����
 * �L���[��ID���Z�b�g���邱�ƂŁAACB�t�@�C�����̃L���[���Đ����邱�Ƃ��\�ł��B<br>
 * <br>
 * ACB�t�@�C���̃��[�h�ɐ�������ƁA�{�֐��͖߂�l�Ƃ��� ACB �n���h����Ԃ��܂��B<br>
 * ���[�h�G���[���ɂ��ACB�t�@�C���̃��[�h�Ɏ��s�����ꍇ�A�{�֐��͖߂�l�Ƃ���
 * CRI_NULL ��Ԃ��܂��B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃�������ACB�n���h���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ACB�n���h���͓����I�Ƀo�C���_�[�i CriFsBinderHn �j�ƃ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * ACB�t�@�C�������[�h����ꍇ�AACB�n���h�������̃o�C���_�[�ƃ��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * ACB�t�@�C���̃��[�h�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * ACB�t�@�C���̃��[�h�́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomExAcb_CalculateWorkSizeForLoadAcbFile, CriAtomExAcbHn, criAtomExPlayer_SetCueId
 */
CriAtomExAcbHn CRIAPI criAtomExAcb_LoadAcbFile(
	CriFsBinderHn acb_binder, const CriChar8 *acb_path,
	CriFsBinderHn awb_binder, const CriChar8 *awb_path,
	void *work, CriSint32 work_size);

/*JP
 * \brief ACB�t�@�C���̃��[�h�iCPK�R���e���cID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_binder		ACB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	acb_id			CPK�t�@�C������ACB�f�[�^��ID
 * \param[in]	awb_binder		AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_id			CPK�t�@�C������AWB�f�[�^��ID
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \return		CriAtomExAcbHn	ACB�n���h��
 * \par ����:
 * ACB�t�@�C�������[�h���A�L���[�Đ��ɕK�v�ȏ�����荞�݂܂��B<br>
 * �t�@�C���p�X�̑����CPK�R���e���cID���w�肷��_�������΁A
 * ::criAtomExAcb_LoadAcbFile �֐��Ƌ@�\�͓����ł��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_LoadAcbFile
 */
CriAtomExAcbHn CRIAPI criAtomExAcb_LoadAcbFileById(
	CriFsBinderHn acb_binder, CriUint16 acb_id, CriFsBinderHn awb_binder, CriUint16 awb_id,
	void *work, CriSint32 work_size);

/*JP
 * \brief ACB�n���h���̃����[�X
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \par ����:
 * ACB�n���h����������܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * ACB�n���h���쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iACB�n���h���쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \par ���l:
 * �{�֐���ACB�n���h����j������ۂɂ́A
 * ���YACB�n���h�����Q�Ƃ��Ă���L���[�͑S�Ē�~����܂��B<br>
 * �i�{�֐����s��ɁAACB�n���h���̍쐬�Ɏg�p�������[�N�̈��A
 * ACB�f�[�^���z�u����Ă����̈悪�Q�Ƃ���邱�Ƃ͂���܂���B�j<br>
 * \attention
 * �{�֐������s����ƁA�j�����悤�Ƃ��Ă���ACB�f�[�^���Q�Ƃ��Ă���
 * Atom�v���[���[�����݂��Ȃ����A���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * Atom�v���[���[�̍쐬�^�j���� ::criAtomEx_Lock �֐��Ń��b�N���Ă�����s���������B<br>
 * \sa criAtomExAcb_LoadAcbData, criAtomExAcb_LoadAcbFile
 */
void CRIAPI criAtomExAcb_Release(CriAtomExAcbHn acb_hn);

/*JP
 * \brief ACB�n���h������������\���ǂ����̃`�F�b�N
 * \ingroup ATOMLIBEX_ACB
 * \param[in]	acb_hn		acb�n���h��
 * \return		CriBool		ACB�̏�ԁiCRI_TRUE = ��������\�ACRI_FALSE = �Đ����̃v���[���[����j
 * \par ����:
 * ACB�n���h���𑦍��ɉ���\���ǂ������`�F�b�N���܂��B<br>
 * �{�֐��� CRI_FALSE ��Ԃ��^�C�~���O�� ::criAtomExAcb_Release �֐������s����ƁA
 * ACB�n���h�����Q�Ƃ��Ă���v���[���[�ɑ΂����~�������s���܂��B<br>
 * �i�X�g���[���Đ��p��ACB�n���h���̏ꍇ�A�t�@�C���ǂݍ��݊�����҂��߁A
 * ::criAtomExAcb_Release �֐����Œ����ԏ������u���b�N�����\��������܂��B�j<br>
 * \par ���l:
 * ACB�n���h�����Đ����Ă����v���[���[��S�Ē�~�������ꍇ�ł��A
 * ���C�u�������ł͓��YACB�n���h�����Q�Ƃ��Ă���{�C�X�����݂���\��������܂��B<br>
 * �i ::criAtomExPlayer_StopWithoutReleaseTime �֐��Œ�~�������s�����ꍇ��A
 * �{�C�X�̒D����肪���������ꍇ�A�v���[���[����{�C�X�͐؂藣����܂����A
 * ���̌���{�C�X���Ńt�@�C���̓ǂݍ��݊����҂����s���P�[�X������܂��B�j<br>
 * ::criAtomExAcb_Release �֐����ŏ������u���b�N�����̂������K�v������ꍇ�ɂ́A
 * �{�֐��� CRI_TRUE ��Ԃ��܂ŁA::criAtomExAcb_Release �֐������s���Ȃ��ł��������B<br>
 * \attention
 * �{�֐������s����ƁA�w�肵��ACB�f�[�^���Q�Ƃ��Ă���Atom�v���[���[�����݂��Ȃ����A
 * ���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * Atom�v���[���[�̍쐬�^�j���� ::criAtomEx_Lock �֐��Ń��b�N���Ă�����s���������B<br>
 * \sa criAtomExAcb_Release
 */
CriBool CRIAPI criAtomExAcb_IsReadyToRelease(CriAtomExAcbHn acb_hn);

/*JP
 * \brief �S�Ă�ACB�n���h���������[�X
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * ���[�h�ς݂̑S�Ă�ACB�n���h����������܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * ACB�n���h���쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iACB�n���h���쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \par ���l:
 * �{�֐������s����ƁA�S�ẴL���[�Đ������̎��_�Œ�~���܂��B<br>
 * �i�{�֐����s��ɁAACB�n���h���̍쐬�Ɏg�p�������[�N�̈��A
 * ACB�f�[�^���z�u����Ă����̈悪�Q�Ƃ���邱�Ƃ͂���܂���B�j<br>
 * \attention
 * �{�֐������s����ƁA�w�肵��ACB�f�[�^���Q�Ƃ��Ă���Atom�v���[���[�����݂��Ȃ����A
 * ���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * Atom�v���[���[�̍쐬�^�j���� ::criAtomEx_Lock �֐��Ń��b�N���Ă�����s���������B<br>
 * \sa criAtomExAcb_LoadAcbData, criAtomExAcb_LoadAcbFile
 */
void CRIAPI criAtomExAcb_ReleaseAll(void);

/*JP
 * \brief ACB�n���h���̗�
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	func		ACB�n���h���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \return		CriSint32	�񋓂��ꂽACB�n���h���̐�
 * \par ����:
 * ACB�n���h����񋓂��܂��B<br>
 * <br>
 * �{�֐������s����ƁA�� 1 �����i func �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐���ACB�n���h���̐��������Ăяo����܂��B<br>
 * �R�[���o�b�N�֐��ɂ́AACB�n���h���������Ƃ��ēn����܂��B<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExAcbHandleCbFunc �̐��������Q�Ƃ��������B<br>
 * <br>
 * �߂�l�͗񋓂��ꂽACB�n���h���̐��i�o�^�����R�[���o�b�N�֐����Ăяo���ꂽ�񐔁j�ł��B<br>
 * �i����R�[���o�b�N���ɗ񋓂𒆎~�����ꍇ�ł� 1 ���Ԃ���܂��B�j<br>
 * ACB�n���h�������݂��Ȃ��ꍇ�A�{�֐��� 0 ��Ԃ��܂��B<br>
 * �܂��A�������s���ȏꍇ���A�G���[�����������ۂɂ� -1 ��Ԃ��܂��B<br>
 * \attention
 * ACB�n���h�����R�[���o�b�N�֐����Ŕj�����Ă͂����܂���B<br>
 * �S�Ă�ACB�n���h�����ꊇ�Ŕj������ꍇ�ɂ́A�{�֐��̑���ɁA
 * ::criAtomExAcb_ReleaseAll �֐����g�p���Ă��������B<br>
 * \sa CriAtomExAcbHandleCbFunc, criAtomExAcb_ReleaseAll
 */
CriSint32 CRIAPI criAtomExAcb_EnumerateHandles(CriAtomExAcbHandleCbFunc func, void *obj);

/*JP
 * \brief �I��������ACB�̃o�[�W�����擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_data		ACB�f�[�^�A�h���X
 * \param[in]	acb_data_size	ACB�f�[�^�T�C�Y
 * \param[out]	flag			���[�h�\�t���O
 * \return		CriUint2		ACB�t�H�[�}�b�g�o�[�W����
 * \par ����:
 * ��������ɔz�u���ꂽACB�f�[�^�̃t�H�[�}�b�g�o�[�W�������擾���܂��B<br>
 * �܂��Aflag�����Ƀ��[�h�\�ȃo�[�W�������ǂ�����Bool�l�ŕԂ��܂��B<br>
 */
CriUint32 CRIAPI criAtomExAcb_GetVersion(
	void *acb_data, CriSint32 acb_data_size, void *flag);

/*JP
 * \brief ACB�t�@�C���̃o�[�W�����擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_binder	ACB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	acb_path	ACB�t�@�C���̃p�X
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \param[out]	flag		���[�h�\�t���O
 * \return		CriUint2	ACB�t�H�[�}�b�g�o�[�W����
 * \par ����:
 * ACB�t�@�C�����������Ƀ��[�h��ACB�f�[�^�̃t�H�[�}�b�g�o�[�W�������擾���܂��B<br>
 * ACB���̓o�^�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ::criAtomExAcb_CalculateWorkSizeForLoadAcbFile �֐��Ōv�Z���܂��B<br>
 * <br>
 * ACB�t�@�C���t�H�[�}�b�g�o�[�W����������flag�����Ƀ��[�h�\�ȃo�[�W�������ǂ�����Bool�l�ŕԂ��܂��B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
 * ����K�v�ȃ��[�N�̈�T�C�Y���̃����������I�Ɋm�ۂ���܂��B�j
 * <br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * �{�֐��ɃZ�b�g�������[�N�̈�́A �A�v���P�[�V�����ŕێ�����K�v�͂���܂���B<br>
 * �i�������Ƀ��[�h�����f�[�^�͊֐��I�����ɉ������܂��B�j<br>
 * <br>
 * �{�֐��́A�֐����s�J�n���� criFsLoader_Create �֐��Ń��[�_�[���m�ۂ��A
 * �I������ criFsLoader_Destroy �֐��Ń��[�_�[��j�����܂��B<br>
 * �{�֐������s����ۂɂ́A�󂫃��[�_�[�n���h�����P�ȏ゠���ԂɂȂ�悤�A
 * ���[�_�[���𒲐����Ă��������B<br>
 */
CriUint32 CRIAPI criAtomExAcb_GetVersionFromFile(
	CriFsBinderHn acb_binder, const CriChar8 *acb_path, void *work, CriSint32 work_size, CriBool *flag);

/*JP
 * \brief ���[�h�\�o�[�W�������擾
 * \ingroup ATOMEXLIB_ACB
 * \param[out]	version_low		���[�h�\���ʃo�[�W����
 * \param[out]	version_high	���[�h�\��ʃo�[�W����
 * \par ����:
 * ���[�h�\��ACB�̃o�[�W���������擾���܂��B<br>
 * ��ʃo�[�W�����̓��C�u�����r���h���_�ł̏��̂��߁A���̒l����ʂ�ACB�ł�
 * ���[�h�\�ȏꍇ������܂��B<br>
 */
void CRIAPI criAtomExAcb_GetSupportedVersion(
	CriUint32 *version_low, CriUint32 *version_high);

/*JP
 * \brief �L���[���̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \return		CriSint32	�L���[��
 * \par ����:
 * ACB�f�[�^�Ɋ܂܂��L���[�����擾���܂��B<br>
 * \par ���l:
 * �����i acb_hn �j�� NULL ���w�肵���ꍇ�A�Ō�Ƀ��[�h����ACB�f�[�^�������ΏۂƂ��܂��B<br>
 */
CriSint32 CRIAPI criAtomExAcb_GetNumCues(CriAtomExAcbHn acb_hn);

/*JP
 * \brief �L���[�̑��݊m�F�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \return		CriBool		�L���[�����݂��邩�ǂ����i���݂���FCRI_TRUE�^���݂��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肵��ID�̃L���[�����݂��邩�ǂ������擾���܂��B<br>
 * ���݂����ꍇ�ɂ�CRI_TRUE��Ԃ��܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^�������ΏۂƂȂ�܂��B<br>
 * �i�w�肵��ID������ACB�f�[�^��1�ł����݂���΁A�{�֐��� CRI_TRUE ��Ԃ��܂��B�j<br>
 */
CriBool CRIAPI criAtomExAcb_ExistsId(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�̑��݊m�F�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		CriBool		�L���[�����݂��邩�ǂ����i���݂���FCRI_TRUE�^���݂��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肵�����O�̃L���[�����݂��邩�ǂ������擾���܂��B<br>
 * ���݂����ꍇ�ɂ�CRI_TRUE��Ԃ��܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^�������ΏۂƂȂ�܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^��1�ł����݂���΁A�{�֐��� CRI_TRUE ��Ԃ��܂��B�j<br>
 */
CriBool CRIAPI criAtomExAcb_ExistsName(CriAtomExAcbHn acb_hn, const CriChar8 *name);

/*JP
 * \brief �L���[�̑��݊m�F�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�L���[�C���f�b�N�X
 * \return		CriBool		�L���[�����݂��邩�ǂ����i���݂���FCRI_TRUE�^���݂��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肵���C���f�b�N�X�̃L���[�����݂��邩�ǂ������擾���܂��B<br>
 * ���݂����ꍇ�ɂ�CRI_TRUE��Ԃ��܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^�������ΏۂƂȂ�܂��B<br>
 * �i�w�肵���L���[�C���f�b�N�X������ACB�f�[�^��1�ł����݂���΁A�{�֐��� CRI_TRUE ��Ԃ��܂��B�j<br>
 */
CriBool CRIAPI criAtomExAcb_ExistsIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �L���[ID�̎擾�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	index			�L���[�C���f�b�N�X
 * \return		CriAtomExCueId	�L���[ID
 * \par ����:
 * �L���[�C���f�b�N�X����L���[ID���擾���܂��B<br>
 * �w�肵���L���[�C���f�b�N�X�̃L���[�����݂��Ȃ��ꍇ�A-1���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[�C���f�b�N�X��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[�C���f�b�N�X������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��ID���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExCueId CRIAPI criAtomExAcb_GetCueIdByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �L���[ID�̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	name			�L���[��
 * \return		CriAtomExCueId	�L���[ID
 * \par ����:
 * �L���[������L���[ID���擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�A-1���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��ID���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExCueId CRIAPI criAtomExAcb_GetCueIdByName(CriAtomExAcbHn acb_hn, const CriChar8* name);

/*JP
 * \brief �L���[���̎擾�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�L���[�C���f�b�N�X
 * \return		const CriChar8* �L���[��
 * \par ����:
 * �L���[�C���f�b�N�X����L���[�����擾���܂��B<br>
 * �w�肵���L���[�C���f�b�N�X�̃L���[�����݂��Ȃ��ꍇ�ANULL���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[�C���f�b�N�X��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[�C���f�b�N�X������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̖��O���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
const CriChar8 * CRIAPI criAtomExAcb_GetCueNameByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �L���[���̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \return		const CriChar8* �L���[��
 * \par ����:
 * �L���[ID����L���[�����擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�ANULL���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̖��O���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
const CriChar8 * CRIAPI criAtomExAcb_GetCueNameById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�C���f�b�N�X�̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	id					�L���[ID
 * \return		CriAtomExCueIndex	�L���[�C���f�b�N�X
 * \par ����:
 * �L���[ID����L���[�C���f�b�N�X���擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�A-1���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃C���f�b�N�X���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExCueIndex CRIAPI criAtomExAcb_GetCueIndexById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�C���f�b�N�X�̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	name				�L���[��
 * \return		CriAtomExCueIndex	�L���[�C���f�b�N�X
 * \par ����:
 * �L���[������L���[�C���f�b�N�X���擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�A-1���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃C���f�b�N�X���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExCueIndex CRIAPI criAtomExAcb_GetCueIndexByName(CriAtomExAcbHn acb_hn, const CriChar8* name);

/*JP
 * \brief ���[�U�f�[�^������̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	id					�L���[ID
 * \return		const CriChar8 *	���[�U�f�[�^������
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�̃��[�U�f�[�^��������擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�ANULL���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃��[�U�f�[�^���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
const CriChar8 * CRIAPI criAtomExAcb_GetUserDataById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief ���[�U�f�[�^������̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		const CriChar8 * ���[�U�f�[�^������
 * \par ����:
 * �L���[�����w�肵�āA�L���[�̃��[�U�f�[�^��������擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�ANULL���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃��[�U�f�[�^���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
const CriChar8 * CRIAPI criAtomExAcb_GetUserDataByName(CriAtomExAcbHn acb_hn, const CriChar8 *name);

/*JP
 * \brief �L���[�̒����̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \return		CriSint64	�L���[�̒����i�~���b�P�ʁj
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�̒������擾���܂��B�L���[�̒����̓~���b�P�ʂł��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ��A�������[�v����L���[�̏ꍇ�A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̒������Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriSint64 CRIAPI criAtomExAcb_GetLengthById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�̒����̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		CriSint64	�L���[�̒����i�~���b�P�ʁj
 * \par ����:
 * �L���[�����w�肵�āA�L���[�̒������擾���܂��B�L���[�̒����̓~���b�P�ʂł��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ��A�������[�v����L���[�̏ꍇ�A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̒������Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriSint64 CRIAPI criAtomExAcb_GetLengthByName(CriAtomExAcbHn acb_hn, const CriChar8 *name);

/*JP
 * \brief �L���[�ŃR���g���[���\��AISAC Control�̌��̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \return		CriSint32	AISAC Control�̌�
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�ŃR���g���[���\��AISAC Control�̌����擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�́A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃R���g���[���\��AISAC Control�̌����Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumUsableAisacControlsByName, criAtomExAcb_GetUsableAisacControlById, criAtomExAcb_GetUsableAisacControlByName
 */
CriSint32 CRIAPI criAtomExAcb_GetNumUsableAisacControlsById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�ŃR���g���[���\��AISAC Control�̌��̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		CriSint32	AISAC Control�̌�
 * \par ����:
 * �L���[�����w�肵�āA�L���[�ŃR���g���[���\��AISAC Control�̌����擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�́A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃R���g���[���\��AISAC Control�̌����Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumUsableAisacControlsById, criAtomExAcb_GetUsableAisacControlById, criAtomExAcb_GetUsableAisacControlByName
 */
CriSint32 CRIAPI criAtomExAcb_GetNumUsableAisacControlsByName(CriAtomExAcbHn acb_hn, const CriChar8 *name);

/*JP
 * \brief �L���[�ŃR���g���[���\��AISAC Control�̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \param[in]	index		AISAC Control�C���f�b�N�X
 * \param[out]	info		AISAC Control���
 * \return		CriBool		�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[ID��AISAC Control�C���f�b�N�X���w�肵�āAAISAC Control�����擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�́ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��AISAC Control��񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumUsableAisacControlsById, criAtomExAcb_GetNumUsableAisacControlsByName, criAtomExAcb_GetUsableAisacControlByName
 */
CriBool CRIAPI criAtomExAcb_GetUsableAisacControlById(CriAtomExAcbHn acb_hn, CriAtomExCueId id, CriUint16 index, CriAtomExAisacControlInfo* info);

/*JP
 * \brief �L���[�ŃR���g���[���\��AISAC Control�̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \param[in]	index		AISAC Control�C���f�b�N�X
 * \param[out]	info		AISAC Control���
 * \return		CriBool		�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[����AISAC Control�C���f�b�N�X���w�肵�āAAISAC Control�����擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�́ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��AISAC Control��񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumUsableAisacControlsById, criAtomExAcb_GetNumUsableAisacControlsByName, criAtomExAcb_GetUsableAisacControlById
 */
CriBool CRIAPI criAtomExAcb_GetUsableAisacControlByName(CriAtomExAcbHn acb_hn, const CriChar8 *name, CriUint16 index, CriAtomExAisacControlInfo* info);

/*JP
 * \brief �L���[��AISAC Control�ŃR���g���[���\���ǂ����̎擾�iID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	id					�L���[ID
 * \param[in]	aisac_control_id	AISAC Control id
 * \return		CriBool				�R���g���[���\���ǂ����i�\�FCRI_TRUE�A�s�\�FCRI_FALSE�j
 * \par ����:
 * �L���[ID��AISAC Control Id���w�肵�āA�L���[��AISAC Control�ŃR���g���[���\���ǂ������擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�́ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��AISAC Control�������ɒl��Ԃ��܂��j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_IsUsingAisacControlByName
 */
CriBool CRIAPI criAtomExAcb_IsUsingAisacControlById(CriAtomExAcbHn acb_hn, CriAtomExCueId id, CriAtomExAisacControlId aisac_control_id);

/*JP
 * \brief �L���[��AISAC Control�ŃR���g���[���\���ǂ����̎擾�i���O�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn					ACB�n���h��
 * \param[in]	name					�L���[��
 * \param[in]	aisac_control_name		AISAC Control�C���f�b�N�X
 * \return		CriBool					�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[����AISAC Control�C���f�b�N�X���w�肵�āAAISAC Control�����擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�́ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[��AISAC Control�������ɒl��Ԃ��܂��j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_IsUsingAisacControlById
 */
CriBool CRIAPI criAtomExAcb_IsUsingAisacControlByName(CriAtomExAcbHn acb_hn, const CriChar8 *name, const CriChar8 *aisac_control_name);

/*JP
 * \brief �L���[�ɐݒ肳��Ă���v���C�I���e�B�̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \return		CriSint32	�v���C�I���e�B�i�擾�Ɏ��s�����ꍇ-1���A��܂��j
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�ɐݒ肳��Ă���v���C�I���e�B���擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�́A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃v���C�I���e�B���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetCuePriorityByName
 */
CriSint32 CRIAPI criAtomExAcb_GetCuePriorityById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�ɐݒ肳��Ă���v���C�I���e�B�̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		CriSint32	�v���C�I���e�B�i�擾�Ɏ��s�����ꍇ-1���A��܂��j
 * \par ����:
 * �L���[�����w�肵�āA�L���[�ɐݒ肳��Ă���v���C�I���e�B���擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�́A-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̃v���C�I���e�B���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetCuePriorityById
 */
CriSint32 CRIAPI criAtomExAcb_GetCuePriorityByName(CriAtomExAcbHn acb_hn, const CriChar8 *name);

/*JP
 * \brief �����g�`���̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	id				�L���[ID
 * \param[out]	waveform_info	�����g�`���
 * \return		CriBool			�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[ID���w�肵�āA���̃L���[�ōĐ�����鉹���g�`�̏����擾���܂��B<br>
 * ���̃L���[�ōĐ�����鉹���g�`����������ꍇ�A���߂̃g���b�N�ŏ��߂ɍĐ�����鉹���g�`�̏�񂪎擾����܂��B
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̉����g�`��񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriBool CRIAPI criAtomExAcb_GetWaveformInfoById(
	CriAtomExAcbHn acb_hn, CriAtomExCueId id, CriAtomExWaveformInfo *waveform_info);

/*JP
 * \brief �����g�`���̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	name			�L���[��
 * \param[out]	waveform_info	�����g�`���
 * \return		CriBool			�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[�����w�肵�āA���̃L���[�ōĐ�����鉹���g�`�̏����擾���܂��B<br>
 * ���̃L���[�ōĐ�����鉹���g�`����������ꍇ�A���߂̃g���b�N�ŏ��߂ɍĐ�����鉹���g�`�̏�񂪎擾����܂��B
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̉����g�`��񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriBool CRIAPI criAtomExAcb_GetWaveformInfoByName(
	CriAtomExAcbHn acb_hn, const CriChar8 *name, CriAtomExWaveformInfo *waveform_info);

/*JP
 * \brief �I���������Đ��pAWB�n���h���̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \return		CriAtomAwbHn	AWB�n���h��
 * \par ����:
 * ACB �f�[�^����I���������Đ��p�� AWB �n���h�����擾���܂��B<br>
 * \par ���l:
 * ACB �f�[�^���ɂ́A�I���������Đ��p�̔g�`�f�[�^�� AWB �t�H�[�}�b�g�Ŋi�[����Ă��܂��B<br>
 * ACB �n���h�����쐬����ہA Atom ���C�u�����̓I���������Đ��p�� 
 * AWB �f�[�^��ǂݍ��݁A�Đ��p�̃n���h���i AWB �n���h���j���쐬���܂��B<br>
 * <br>
 * �{�֐����g�p���邱�ƂŁA Atom ���C�u�����������I�ɍ쐬���� AWB �n���h����
 * �擾���邱�Ƃ��\�ł��B<br>
 * �擾���� AWB �n���h�����g�p���邱�ƂŁA ACB �n���h�����̃I���������g�`�f�[�^���A
 * �A�v���P�[�V���������� ::criAtomExPlayer_SetWaveId 
 * �֐����g�p���čĐ����邱�Ƃ��\�ɂȂ�܂��B<br>
 * �i�L���[�Ɋ܂܂��g�`�f�[�^���V�[�����X�A���Đ�����ۂ�A
 * �f�o�b�O�p�r�� ACB �f�[�^���Ɋ܂܂��I���������g�`�f�[�^���Đ�����A
 * �Ƃ������p�r�ɗ��p�\�ł��B�j<br>
 * \attention
 * ACB �n���h�����ێ����� AWB �n���h���́A ACB �n���h�������[�X���ɔj������܂��B<br>
 * �{�֐��Ŏ擾���� AWB �n���h�����ʂɔj��������A
 * �擾�ς݂� AWB �n���h���� ACB �n���h�������[�X��ɃA�N�Z�X�����肷��ƁA
 * �A�N�Z�X�ᔽ���̏d��ȕs�����������\��������܂��B<br>
 * \sa criAtomExAcb_GetStreamingAwbHandle
 */
CriAtomAwbHn CRIAPI criAtomExAcb_GetOnMemoryAwbHandle(CriAtomExAcbHn acb_hn);

/*JP
 * \brief �X�g���[���Đ��pAWB�n���h���̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn			ACB�n���h��
 * \return		CriAtomAwbHn	AWB�n���h��
 * \par ����:
 * ACB �f�[�^����X�g���[���Đ��p�� AWB �n���h�����擾���܂��B<br>
 * \par ���l:
 * ACB �f�[�^���ɂ́A�X�g���[���Đ��p�� AWB �t�@�C�����֘A�t�����Ă��܂��B<br>
 * ACB �n���h�����쐬����ہA Atom ���C�u�����̓X�g���[���Đ��p��
 * AWB �f�[�^��ǂݍ��݁A�Đ��p�̃n���h���i AWB �n���h���j���쐬���܂��B<br>
 * <br>
 * �{�֐����g�p���邱�ƂŁA Atom ���C�u�����������I�ɍ쐬���� AWB �n���h����
 * �擾���邱�Ƃ��\�ł��B<br>
 * �擾���� AWB �n���h�����g�p���邱�ƂŁA �X�g���[���Đ��p�̔g�`�f�[�^���A
 * �A�v���P�[�V���������� ::criAtomExPlayer_SetWaveId 
 * �֐����g�p���čĐ����邱�Ƃ��\�ɂȂ�܂��B<br>
 * �i�L���[�Ɋ܂܂��g�`�f�[�^���V�[�����X�A���Đ�����ۂ�A
 * �f�o�b�O�p�r�� ACB �f�[�^�Ɋ֘A�t����ꂽ�X�g���[���Đ��p�g�`�f�[�^���Đ�����A
 * �Ƃ������p�r�ɗ��p�\�ł��B�j<br>
 * \attention
 * ACB �n���h�����ێ����� AWB �n���h���́A ACB �n���h�������[�X���ɔj������܂��B<br>
 * �{�֐��Ŏ擾���� AWB �n���h�����ʂɔj��������A
 * �擾�ς݂� AWB �n���h���� ACB �n���h�������[�X��ɃA�N�Z�X�����肷��ƁA
 * �A�N�Z�X�ᔽ���̏d��ȕs�����������\��������܂��B<br>
 * \sa criAtomExAcb_GetOnMemoryAwbHandle
 */
CriAtomAwbHn CRIAPI criAtomExAcb_GetStreamingAwbHandle(CriAtomExAcbHn acb_hn);

/*JP
 * \brief �L���[���̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \param[out]	info		�L���[���
 * \return		CriBool		�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[�����w�肵�āA�L���[�����擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̏�񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetCueInfoById, criAtomExAcb_GetCueInfoByIndex
 */
CriBool CRIAPI criAtomExAcb_GetCueInfoByName(CriAtomExAcbHn acb_hn, const CriChar8* name, CriAtomExCueInfo* info);

/*JP
 * \brief �L���[���̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \param[out]	info		�L���[���
 * \return		CriBool		�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�����擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̏�񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetCueInfoByName, criAtomExAcb_GetCueInfoByIndex
 */
CriBool CRIAPI criAtomExAcb_GetCueInfoById(CriAtomExAcbHn acb_hn, CriAtomExCueId id, CriAtomExCueInfo* info);

/*JP
 * \brief �L���[���̎擾�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�L���[�C���f�b�N�X
 * \param[out]	info		�L���[���
 * \return		CriBool		�擾�ɐ����������ǂ����i�����FCRI_TRUE�A���s�FCRI_FALSE�j
 * \par ����:
 * �L���[�C���f�b�N�X���w�肵�āA�L���[�����擾���܂��B<br>
 * �w�肵���L���[�C���f�b�N�X�̃L���[�����݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̏�񂪕Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetCueInfoByName, criAtomExAcb_GetCueInfoById
 */
CriBool CRIAPI criAtomExAcb_GetCueInfoByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index, CriAtomExCueInfo* info);

/*JP
 * \brief �L���[���~�b�g���ݒ肳��Ă���L���[�̔������̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \return		CriSint32	�������i�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ-1���A��܂��j
 * \par ����:
 * �L���[�����w�肵�āA�L���[���~�b�g���ݒ肳��Ă���L���[�̔��������擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ��A�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ��-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̔��������Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumCuePlayingCountById, criAtomExAcb_GetNumCuePlayingCountByIndex
 */
CriSint32 CRIAPI criAtomExAcb_GetNumCuePlayingCountByName(CriAtomExAcbHn acb_hn, const CriChar8* name);

/*JP
 * \brief �L���[���~�b�g���ݒ肳��Ă���L���[�̔������̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID��
 * \return		CriSint32	�������i�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ-1���A��܂��j
 * \par ����:
 * �L���[ID���w�肵�āA�L���[���~�b�g���ݒ肳��Ă���L���[�̔��������擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ��A�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ��-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̔��������Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumCuePlayingCountByName, criAtomExAcb_GetNumCuePlayingCountByIndex
 */
CriSint32 CRIAPI criAtomExAcb_GetNumCuePlayingCountById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[���~�b�g���ݒ肳��Ă���L���[�̔������̎擾�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�L���[�C���f�b�N�X
 * \return		CriSint32	�������i�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ-1���A��܂��j
 * \par ����:
 * �L���[�����w�肵�āA�L���[���~�b�g���ݒ肳��Ă���L���[�̔��������擾���܂��B<br>
 * �w�肵���L���[�C���f�b�N�X�̃L���[�����݂��Ȃ��ꍇ��A�L���[���~�b�g���ݒ肳��Ă��Ȃ��L���[���w�肵���ꍇ��-1���Ԃ�܂��B<br>
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[�̔��������Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * \sa criAtomExAcb_GetNumCuePlayingCountByName, criAtomExAcb_GetNumCuePlayingCountById
 */
CriSint32 CRIAPI criAtomExAcb_GetNumCuePlayingCountByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �u���b�N�C���f�b�N�X�̎擾�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	index				�L���[�C���f�b�N�X
 * \param[in]	block_name			�u���b�N��
 * \return		CriAtomExBlockIndex	�u���b�N�C���f�b�N�X
 * \par ����:
 * �L���[�C���f�b�N�X�ƃu���b�N������u���b�N�C���f�b�N�X���擾���܂��B<br>
 * �w�肵���L���[�C���f�b�N�X�̃L���[�����݂��Ȃ��ꍇ��u���b�N�������݂��Ȃ��ꍇ�́A
 * CRIATOMEX_INVALID_BLOCK_INDEX ���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[�C���f�b�N�X��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[�C���f�b�N�X������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[���̃u���b�N�C���f�b�N�X���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExBlockIndex CRIAPI criAtomExAcb_GetBlockIndexByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index, const CriChar8* block_name);

/*JP
 * \brief �u���b�N�C���f�b�N�X�̎擾�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	id					�L���[ID
 * \param[in]	block_name			�u���b�N��
 * \return		CriAtomExBlockIndex	�u���b�N�C���f�b�N�X
 * \par ����:
 * �L���[ID�ƃu���b�N������u���b�N�C���f�b�N�X���擾���܂��B<br>
 * �w�肵���L���[ID�̃L���[�����݂��Ȃ��ꍇ��u���b�N�������݂��Ȃ��ꍇ�́A
 * CRIATOMEX_INVALID_BLOCK_INDEX ���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[���̃u���b�N�C���f�b�N�X���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExBlockIndex CRIAPI criAtomExAcb_GetBlockIndexById(CriAtomExAcbHn acb_hn, CriAtomExCueId id, const CriChar8* block_name);

/*JP
 * \brief �u���b�N�C���f�b�N�X�̎擾�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn				ACB�n���h��
 * \param[in]	name				�L���[��
 * \param[in]	block_name			�u���b�N��
 * \return		CriAtomExBlockIndex	�u���b�N�C���f�b�N�X
 * \par ����:
 * �L���[���ƃu���b�N������u���b�N�C���f�b�N�X���擾���܂��B<br>
 * �w�肵���L���[���̃L���[�����݂��Ȃ��ꍇ��u���b�N�������݂��Ȃ��ꍇ�́A
 * CRIATOMEX_INVALID_BLOCK_INDEX ���Ԃ�܂��B
 * \par ���l:
 * ��1�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^���̃L���[���̃u���b�N�C���f�b�N�X���Ԃ���܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 */
CriAtomExBlockIndex CRIAPI criAtomExAcb_GetBlockIndexByName(CriAtomExAcbHn acb_hn, const CriChar8* name, const CriChar8* block_name);

/*JP
 * \brief �C���Q�[���v���r���[�p�f�[�^�̃��[�h���m�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	func		���[�h���m�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �C���Q�[���v���r���[�p�f�[�^�̃��[�h�����m�����ꍇ�ɌĂяo���R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́AACB���[�h�֐�����ACB�̓��e��͂��s�����^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExAcbDetectionInGamePreviewDataCbFunc
 */
void CRIAPI criAtomExAcb_SetDetectionInGamePreviewDataCallback(CriAtomExAcbDetectionInGamePreviewDataCbFunc func, void* obj);

/*JP
 * \brief ACB���̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[out]	acb_info	ACB���
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * ACB�f�[�^�̊e������擾���܂��B<br>
 * \par ���l:
 * �����i acb_hn �j�� NULL ���w�肵���ꍇ�A�Ō�Ƀ��[�h����ACB�f�[�^�������ΏۂƂ��܂��B<br>
 * \sa CriAtomExAcbInfo
 */
CriBool CRIAPI criAtomExAcb_GetAcbInfo(CriAtomExAcbHn acb_hn, CriAtomExAcbInfo *acb_info);

/*JP
 * \brief �L���[�^�C�v�X�e�[�g�̃��Z�b�g�i�L���[���w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	name		�L���[��
 * \par ����:
 * �L���[�����w�肵�āA�L���[�^�C�v�X�e�[�g�����Z�b�g���܂��B<br>
 * \attention
 * ���Z�b�g�Ώۂ͎w�肵���L���[�̃X�e�[�g�݂̂ł��B�L���[�Ɋ܂܂��T�u�V���Z��L���[�����N���
 * �X�e�[�g�̓��Z�b�g����܂���B
 * \par ���l:
 * �L���[�^�C�v�X�e�[�g�́A�|���t�H�j�b�N�^�C�v�L���[�ȊO�̃L���[�Đ����̑O��Đ��g���b�N��
 * �X�e�[�g�Ƃ��ĊǗ�����d�g�݂ł��B<br>
 * �{�֐��́A�X�e�[�g�Ǘ��̈�����Z�b�g��ACB���[�h����̏�Ԃɖ߂��܂��B
 * \sa criAtomExAcb_ResetCueTypeStateById, criAtomExAcb_ResetCueTypeStateByIndex
 */
void CRIAPI criAtomExAcb_ResetCueTypeStateByName(CriAtomExAcbHn acb_hn, const CriChar8* name);

/*JP
 * \brief �L���[�^�C�v�X�e�[�g�̃��Z�b�g�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	id			�L���[ID
 * \par ����:
 * �L���[ID���w�肵�āA�L���[�^�C�v�X�e�[�g�����Z�b�g���܂��B<br>
 * \attention
 * ���Z�b�g�Ώۂ͎w�肵���L���[�̃X�e�[�g�݂̂ł��B�L���[�Ɋ܂܂��T�u�V���Z��L���[�����N���
 * �X�e�[�g�̓��Z�b�g����܂���B
 * \par ���l:
 * �L���[�^�C�v�X�e�[�g�́A�|���t�H�j�b�N�^�C�v�L���[�ȊO�̃L���[�Đ����̑O��Đ��g���b�N��
 * �X�e�[�g�Ƃ��ĊǗ�����d�g�݂ł��B<br>
 * �{�֐��́A�X�e�[�g�Ǘ��̈�����Z�b�g��ACB���[�h����̏�Ԃɖ߂��܂��B
 * \sa criAtomExAcb_ResetCueTypeStateByName, criAtomExAcb_ResetCueTypeStateByIndex
 */
void CRIAPI criAtomExAcb_ResetCueTypeStateById(CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �L���[�^�C�v�X�e�[�g�̃��Z�b�g�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�L���[�C���f�b�N�X
 * \par ����:
 * �L���[�C���f�b�N�X���w�肵�āA�L���[�^�C�v�X�e�[�g�����Z�b�g���܂��B<br>
 * \attention
 * ���Z�b�g�Ώۂ͎w�肵���L���[�̃X�e�[�g�݂̂ł��B�L���[�Ɋ܂܂��T�u�V���Z��L���[�����N���
 * �X�e�[�g�̓��Z�b�g����܂���B
 * \par ���l:
 * �L���[�^�C�v�X�e�[�g�́A�|���t�H�j�b�N�^�C�v�L���[�ȊO�̃L���[�Đ����̑O��Đ��g���b�N��
 * �X�e�[�g�Ƃ��ĊǗ�����d�g�݂ł��B<br>
 * �{�֐��́A�X�e�[�g�Ǘ��̈�����Z�b�g��ACB���[�h����̏�Ԃɖ߂��܂��B
 * \sa criAtomExAcb_ResetCueTypeStateByName, criAtomExAcb_ResetCueTypeStateById
 */
void CRIAPI criAtomExAcb_ResetCueTypeStateByIndex(CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �X�g���[���pAWB�t�@�C���̃A�^�b�`
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	awb_binder	AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path	AWB�t�@�C���̃p�X
 * \param[in]	awb_name	AWB��
 * \param[in]	work		�A�^�b�`�ŕK�v�Ȓǉ����[�N
 * \param[in]	work_size	�ǉ����[�N�T�C�Y
 * \par ����:
 * ACB�n���h���ɑ΂��ăX�g���[���p��AWB�t�@�C�����A�^�b�`���܂��B
 * ��2������ awb_binder �A����ё�3������ awb_path �ɂ́A�X�g���[���Đ��p
 * ��AWB�t�@�C�����w�肵�܂��B<br>
 * ��5������ awb_name ��AWB���A�^�b�`����X���b�g���w�肷�邽�߂Ɏg�p���܂��B
 * ���̂��߁AAtomCraft���o�͂���AWB���i�t�@�C��������g���q����菜���������j��ύX���Ă���ꍇ
 * �̓I���W�i����AWB�����w�肵�Ă��������B<br>
 * AWB�t�@�C���̃A�^�b�`���s�Ȃ��ɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�
 * �i���[�N�̈�j���m�ۂ���K�v������܂��B<br>
 * AWB�t�@�C���̃A�^�b�`�Ɏ��s�����ꍇ�A�G���[�R�[���o�b�N���������܂��B<br>
 * ���s�̗��R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * work��NULL�Awork_size��0���w�肷�邾���ŁA�K�v�ȃ�������o�^�ς݂̃������m�ۊ֐�����m�ۂ��܂��B<br>
 * �A�^�b�`���Ɋm�ۂ��ꂽ�������́A�f�^�b�`���i ::criAtomExAcb_DetachAwbFile 
 * �֐����s���j���AACB�n���h�������[�X���i ::criAtomExAcb_Release �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtomExAcb_CalculateWorkSizeForAttachAwbFile �֐��Ŏ擾�\�ł��B<br>
 * �{�֐��Ăяo������ ::criAtomExAcb_CalculateWorkSizeForAttachAwbFile �֐��Ŏ擾����
 * �T�C�Y���̃�������\�ߊm�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈�̓f�^�b�`�����i ::criAtomExAcb_DetachAwbFile 
 * �֐����s���j���AACB�n���h�������[�X�����i ::criAtomExAcb_Release �֐����s���j���s�Ȃ��܂ł̊ԁA
 * ���C�u�������ŗ��p���ꑱ���܂��B<br>
 * AWB�t�@�C�����A�^�b�`����ƃ��C�u���������I�Ƀo�C���_�[�i CriFsBinderHn �j�ƃ��[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �ǉ���AWB�t�@�C�����A�^�b�`����ꍇ�A�ǉ������̃o�C���_�[�ƃ��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_DetachAwbFile, criAtomExAcb_Release, criAtomExAcb_CalculateWorkSizeForAttachAwbFile
*/
void CRIAPI criAtomExAcb_AttachAwbFile(
	CriAtomExAcbHn acb_hn,
	CriFsBinderHn awb_binder,
	const CriChar8* awb_path,
	const CriChar8* awb_name,
	void* work,
	CriSint32 work_size);

/*JP
 * \brief �X�g���[���pAWB�t�@�C���̃f�^�b�`
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	awb_name	AWB��
 * \par ����:
 * ACB�n���h���ɃA�^�b�`����Ă���X�g���[���p��AWB�t�@�C�����f�^�b�`���܂��B
 * ��2������ awb_name ��AWB���A�^�b�`���Ɏw�肵�����̂Ɠ���AWB�����w��w�肭�������B<br>
 * �A�^�b�`���̃��[�N�̈�m�ۂ�User Allocator������p�����ꍇ�́A�A�^�b�`���Ɋm�ۂ����������̈悪
 * �{�֐��������ɊJ������܂��B<br>
 * \sa criAtomExAcb_AttachAwbFile
 */
void CRIAPI criAtomExAcb_DetachAwbFile(
	CriAtomExAcbHn acb_hn,
	const CriChar8* awb_name);

/*JP
 * \brief �X�g���[���pAWB�t�@�C���̃A�^�b�`�ɕK�v�ȃ��[�N�T�C�Y�擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	awb_binder	AWB�t�@�C�����܂ރo�C���_�[�̃n���h��
 * \param[in]	awb_path	AWB�t�@�C���̃p�X
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ::criAtomExAcb_LoadAcbFileById �֐��̎��s�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \sa criAtomExAcb_AttachAwbFile
 */
CriSint32 CRIAPI criAtomExAcb_CalculateWorkSizeForAttachAwbFile(
	CriFsBinderHn awb_binder,
	const CriChar8* awb_path);

/*JP
 * \brief �X�g���[���pAWB�X���b�g���̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \return		CriSint32	�X�g���[��AWB�X���b�g��
 * \par ����:
 * ACB�n���h�����K�v�Ƃ���X�g���[��AWB�̐����擾���܂��B<br>
 */
CriSint32 CRIAPI criAtomExAcb_GetNumAwbFileSlots(
	CriAtomExAcbHn acb_hn);

/*JP
 * \brief �X�g���[���pAWB�X���b�g�̎擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	index		�X���b�g�C���f�b�N�X
 * \return		const CriChar8*	�X�g���[��AWB�|�[�g��
 * \par ����:
 * �C���f�b�N�X���w�肵��ACB�n���h�����̃X�g���[��AWB�X���b�g�����擾���܂��B<br>
 * �擾�����X���b�g���� ::criAtomExAcb_AttachAwbFile �֐��̑�4������A
 * ::criAtomExAcb_DetachAwbFile �֐��̑�2�����̃X���b�g�w��Ɏg�p���܂��B<br>
 */
const CriChar8* CRIAPI criAtomExAcb_GetAwbFileSlotName(
	CriAtomExAcbHn acb_hn, CriUint16 index);

/*JP
 * \brief �X�g���[���pAWB�t�@�C���̃A�^�b�`��Ԏ擾
 * \ingroup ATOMEXLIB_ACB
 * \param[in]	acb_hn		ACB�n���h��
 * \param[in]	awb_name	AWB��
 * \par ����:
 * ACB�n���h����AWB�t�@�C�����A�^�b�`����Ă��邩���擾���܂��B
 * ��2������ awb_name ��AWB���A�^�b�`����X���b�g���ł��A��Ԃ��擾�������X���b�g��AWB�����w�肵�Ă��������B<br>
 */
CriBool CRIAPI criAtomExAcb_IsAttachedAwbFile(
	CriAtomExAcbHn acb_hn,
	const CriChar8* awb_name);


/*==========================================================================
 *      CRI AtomEx Voice Pool API
 *=========================================================================*/
/*JP
 * \brief �W���{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		�W���{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �W���{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateStandardVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateStandardVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExStandardVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForStandardVoicePool �}�N���g�p��
 * �Ɠ����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateStandardVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool(
	const CriAtomExStandardVoicePoolConfig *config);

/*JP
 * \brief �W���{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		�W���{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * �W���{�C�X�v�[�����쐬���܂��B<br>
 * �i�W���{�C�X�́AADX�f�[�^��HCA�f�[�^�̗����̍Đ��ɑΉ������{�C�X�ł��B�j<br>
 * <br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAADX��HCA�̍Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��ADX��HCA�f�[�^�i��������ADX��HCA�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽ�W���{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExStandardVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\�ȉ����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExStandardVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I�̃f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���I�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���I���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExStandardVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * ���z����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�w�肳�ꂽ�T���v�����O���[�g�ȉ��̃f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExStandardVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExStandardVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForStandardVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateStandardVoicePool(
	const CriAtomExStandardVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ADX�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		ADX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ADX�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateAdxVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateAdxVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExAdxVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForAdxVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateAdxVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForAdxVoicePool(
	const CriAtomExAdxVoicePoolConfig *config);

/*JP
 * \brief ADX�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		ADX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * ADX�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForAdxVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAADX�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��ADX�f�[�^�i��������ADX�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽADX�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExAdxVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��ADX�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExAdxVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I�̃f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���I�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���I���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExAdxVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * ���z����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�w�肳�ꂽ�T���v�����O���[�g�ȉ��̃f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExAdxVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExAdxVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForAdxVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateAdxVoicePool(
	const CriAtomExAdxVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		HCA�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateHcaVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateHcaVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExHcaVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForHcaVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateHcaVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForHcaVoicePool(
	const CriAtomExHcaVoicePoolConfig *config);

/*JP
 * \brief HCA�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		HCA�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * HCA�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForHcaVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAHCA�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��HCA�f�[�^�i��������HCA�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽHCA�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExHcaVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��HCA�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExHcaVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����HCA�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I��HCA�f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���IHCA�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���IHCA���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExHcaVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * ���z����HCA�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�w�肳�ꂽ�T���v�����O���[�g�ȉ���HCA�f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExHcaVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExHcaVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForHcaVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateHcaVoicePool(
	const CriAtomExHcaVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA-MX�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		HCA-MX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA-MX�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateHcaMxVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateHcaMxVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExHcaMxVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y��HCA-MX���������i ::criAtomExHcaMx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁAHCA-MX�����������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateHcaMxVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool(
	const CriAtomExHcaMxVoicePoolConfig *config);

/*JP
 * \brief HCA-MX�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		HCA-MX�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * HCA-MX�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAHCA-MX�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��HCA-MX�f�[�^�i��������HCA-MX�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽHCA-MX�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExHcaMxVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��HCA-MX�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExHcaMxVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����HCA-MX�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I��HCA-MX�f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���IHCA-MX�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���IHCA-MX���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExHcaMxVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * �ȊO��HCA-MX�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i���̃{�C�X�v�[���ƈقȂ�A����T���v�����O���[�g�̃f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExHcaMxVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA�K��HCA-MX�̏����������i ::criAtomExHcaMx_Initialize �֐��j
 * �����s���Ă����K�v������܂��B<br>
 * �܂��A ::criAtomExHcaMx_Initialize �֐����s���Ɏw�肵�����ȏ��HCA-MX�f�[�^�͍Đ��ł��܂���B<br>
 * HCA-MX�{�C�X�v�[�����쐬����ۂɂ́A ::CriAtomExHcaMxVoicePoolConfig �\���̂� num_voices 
 * �̒l���AHCA-MX���������Ɏw�肷�� ::CriAtomExHcaMxConfig �\���̂� max_voices �̐��𒴂��Ȃ��悤�A
 * �����ӂ��������B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExHcaMxVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForHcaMxVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateHcaMxVoicePool(
	const CriAtomExHcaMxVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief Wave�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		Wave�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * Wave�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateWaveVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateWaveVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExWaveVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForWaveVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateWaveVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForWaveVoicePool(
	const CriAtomExWaveVoicePoolConfig *config);

/*JP
 * \brief Wave�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		Wave�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * Wave�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForWaveVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAWave�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��Wave�f�[�^�i��������Wave�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽWave�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExWaveVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��Wave�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExWaveVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����Wave�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I��Wave�f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���IWave�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���IWave���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExWaveVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * ���z����Wave�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�w�肳�ꂽ�T���v�����O���[�g�ȉ���Wave�f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExWaveVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * <br>
 * �Đ��\�ȃt�H�[�}�b�g�́A32bit�ȉ��̔񈳏kPCM�f�[�^�݂̂ł��B<br>
 * ���[�v�Đ����s���ꍇ�A�X�g���[���Đ��p�̉����f�[�^�ɂ��ẮA
 * smpl�`�����N��data�`�����N������O�ɔz�u����Ă���K�v������܂��B
 * \sa CriAtomExWaveVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForWaveVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateWaveVoicePool(
	const CriAtomExWaveVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief AIFF�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		AIFF�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * AIFF�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateAiffVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateAiffVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExAiffVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForAiffVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateAiffVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForAiffVoicePool(
	const CriAtomExAiffVoicePoolConfig *config);

/*JP
 * \brief AIFF�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		AIFF�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * AIFF�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForAiffVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁAAIFF�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��AIFF�f�[�^�i��������AIFF�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽAIFF�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExAiffVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��AIFF�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExAiffVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A�{�C�X�v�[�����̃{�C�X���Đ��ł���
 * �����f�[�^�̃`�����l�����ɂȂ�܂��B<br>
 * �`�����l���������Ȃ����邱�ƂŁA�{�C�X�v�[���̍쐬�ɕK�v�ȃ������T�C�Y��
 * �������Ȃ�܂����A�w�肳�ꂽ�`�����l�������z����AIFF�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �Ⴆ�΁A�{�C�X�v�[�������m�����ō쐬�����ꍇ�A�X�e���I��AIFF�f�[�^�͍Đ��ł��܂���B<br>
 * �i�X�e���IAIFF�f�[�^���Đ�����ꍇ�AAtomEx�v���[���[�́A�X�e���IAIFF���Đ��\��
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B�j<br>
 * �������A�X�e���I�̃{�C�X�v�[�����쐬�����ꍇ�A���m�����f�[�^�Đ����ɃX�e���I
 * �{�C�X�v�[���̃{�C�X���g�p�����\���͂���܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExAiffVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A�l�������邱�Ƃł��{�C�X�v�[��
 * �ɕK�v�ȃ������T�C�Y�͏��������邱�Ƃ��\�ł����A�w�肳�ꂽ�T���v�����O���[�g
 * ���z����AIFF�f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�w�肳�ꂽ�T���v�����O���[�g�ȉ���AIFF�f�[�^�݂̂��Đ��\�ł��B�j<br>
 * <br>
 * �X�g���[�~���O�Đ��̗L���i::CriAtomExAiffVoicePoolConfig �\���̂� 
 * player_config.streaming_flag �j�ɂ��Ă��A�I���������Đ��݂̂̃{�C�X�v�[����
 * �X�g���[�~���O�Đ��\�ȃ{�C�X�v�[���ɔ�ׁA�T�C�Y���������Ȃ�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * <br>
 * �Đ��\�ȃt�H�[�}�b�g�́A32bit�ȉ��̔񈳏kPCM�f�[�^�݂̂ł��B<br>
 * ���[�v�Đ����s���ꍇ�A�X�g���[���Đ��p�̉����f�[�^�ɂ��ẮA
 * INST�`�����N��SSND�`�����N������O�ɔz�u����Ă���K�v������܂��B
 * \sa CriAtomExAiffVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForAiffVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateAiffVoicePool(
	const CriAtomExAiffVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief RawPCM�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * RawPCM�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateRawPcmVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateRawPcmVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExRawPcmVoicePoolConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExVoicePool_SetDefaultConfigForRawPcmVoicePool �}�N���g�p����
 * �����p�����[�^�[�j�Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtomEx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomExVoicePool_AllocateRawPcmVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForRawPcmVoicePool(
	const CriAtomExRawPcmVoicePoolConfig *config);

/*JP
 * \brief RawPCM�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		RawPCM�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExVoicePoolHn	�{�C�X�v�[���n���h��
 * \par �����F
 * RawPCM�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForRawPcmVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁARawPCM�Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[��RawPCM�f�[�^�i��������RawPCM�f�[�^���܂ރL���[�j�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽRawPCM�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �{�C�X�v�[���쐬���ɂ́A�v�[���쐬�p�R���t�B�O�\����
 * �i ::CriAtomExRawPcmVoicePoolConfig �\���̂� num_voices �j
 * �Ŏw�肵�������̃{�C�X���A���C�u�������ō쐬����܂��B<br>
 * �쐬����{�C�X�̐��������قǁA�����ɍĐ��\��RawPCM�����̐��͑����܂����A
 * ���ʁA�g�p���郁�����͑������܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���ɂ́A�{�C�X���̑��ɁA�Đ��\�ȉ����̃`�����l�����A
 * �T���v�����O���g���A�X�g���[���Đ��̗L�����w�肵�܂��B<br>
 * <br>
 * �{�C�X�v�[���쐬���Ɏw�肷�鉹���`�����l�����i ::CriAtomExRawPcmVoicePoolConfig 
 * �\���̂� player_config.max_channels �j�́A���ۂɋ�������RawPCM�̃t�H�[�}�b�g��
 * �`�����l�������w�肵�܂��B<br>
 * <br>
 * �T���v�����O���[�g�i ::CriAtomExRawPcmVoicePoolConfig �\���̂� 
 * player_config.max_sampling_rate �j�ɂ��Ă��A���ۂɋ�������RawPCM��
 * �t�H�[�}�b�g�̃T���v�����O���[�g���w�肵�܂��B<br>
 * <br>
 * ���AAtomEx�v���[���[���f�[�^���Đ������ۂɁA
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������{�C�X�v�[���j����
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * <br>
 * �X�g���[���Đ��p�̃{�C�X�v�[���́A�����I�Ƀ{�C�X�̐����������[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p�̃{�C�X�v�[�����쐬����ꍇ�A�{�C�X�����̃��[�_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�C�X�v�[���̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExRawPcmVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForRawPcmVoicePool, criAtomExVoicePool_Free
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateRawPcmVoicePool(
	const CriAtomExRawPcmVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �C���X�g�D�������g�{�C�X�v�[���̍쐬
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		�C���X�g�D�������g�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExInstrumentVoicePoolHn 	�C���X�g�D�������g�{�C�X�v�[���n���h��
 * \par �����F
 * �C���X�g�D�������g�{�C�X�v�[�����쐬���܂��B<br>
 * �{�C�X�v�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExVoicePool_CalculateWorkSizeForInstrumentVoicePool 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �{�֐������s���邱�ƂŁA�C���X�g�D�������g�g���b�N�̍Đ����\�ȃ{�C�X���v�[������܂��B<br>
 * AtomEx�v���[���[�ŃC���X�g�D�������g�g���b�N�̍Đ����s���ƁA
 * AtomEx�v���[���[�͍쐬���ꂽ�C���X�g�D�������g�{�C�X�v�[������{�C�X���擾���A�Đ����s���܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�ɐ�������ƁA�߂�l�Ƃ��ă{�C�X�v�[���n���h�����Ԃ���܂��B<br>
 * �A�v���P�[�V�����I�����ɂ́A�쐬�����{�C�X�v�[���� ::criAtomExVoicePool_Free 
 * �֐��Ŕj������K�v������܂��B<br>
 * <br>
 * �{�C�X�v�[���̍쐬�Ɏ��s����ƁA�{�֐���NULL��Ԃ��܂��B<br>
 * �{�C�X�v�[���̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \sa CriAtomExInstrumentVoicePoolConfig, criAtomExVoicePool_CalculateWorkSizeForInstrumentVoicePool, criAtomExVoicePool_Free, 
 */
CriAtomExVoicePoolHn CRIAPI criAtomExVoicePool_AllocateInstrumentVoicePool(
	const CriAtomExInstrumentVoicePoolConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �{�C�X�v�[���̔j��
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	pool		�{�C�X�v�[���n���h��
 * \par ����:
 * �쐬�ς݂̃{�C�X�v�[����j�����܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�C�X�v�[���쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �i�{�C�X�v�[���쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �����Đ����Ƀ{�C�X�v�[����j�������ꍇ�A�{�֐����ōĐ���~��҂��Ă���
 * ���\�[�X�̉�����s���܂��B<br>
 * �i�t�@�C������Đ����Ă���ꍇ�́A����ɓǂݍ��݊����҂����s���܂��B�j<br>
 * ���̂��߁A�{�֐����ŏ����������ԁi���t���[���j�u���b�N�����\��������܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomExVoicePool_AllocateStandardVoicePool
 */
void CRIAPI criAtomExVoicePool_Free(CriAtomExVoicePoolHn pool);

/*JP
 * \brief �S�Ẵ{�C�X�v�[����j��
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \par ����:
 * �쐬�ς݂̃{�C�X�v�[����S�Ĕj�����܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�C�X�v�[���쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �i�{�C�X�v�[���쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �����Đ����Ƀ{�C�X�v�[����j�������ꍇ�A�{�֐����ōĐ���~��҂��Ă���
 * ���\�[�X�̉�����s���܂��B<br>
 * �i�t�@�C������Đ����Ă���ꍇ�́A����ɓǂݍ��݊����҂����s���܂��B�j<br>
 * ���̂��߁A�{�֐����ŏ����������ԁi���t���[���j�u���b�N�����\��������܂��B<br>
 * �{�C�X�v�[���̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomExVoicePool_AllocateStandardVoicePool
 */
void CRIAPI criAtomExVoicePool_FreeAll(void);

/*JP
 * \brief �{�C�X�̎g�p�󋵂̎擾
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	pool		�{�C�X�v�[���n���h��
 * \param[out]	cur_num		���ݎg�p���̃{�C�X��
 * \param[out]	limit		���p�\�ȃ{�C�X�̍ő吔
 * \par ����:
 * �{�C�X�v�[�����̃{�C�X�̓��A���ݎg�p���̃{�C�X�̐��A����ї��p�\��
 * �ő�{�C�X���i���v�[���쐬���Ɏw�肵�� max_voices �̐��j���擾���܂��B<br>
 */
void CRIAPI criAtomExVoicePool_GetNumUsedVoices(
	CriAtomExVoicePoolHn pool, CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \brief �v���[���[�n���h���̎擾
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	pool		�{�C�X�v�[���n���h��
 * \param[in]	index		�v���[���[�C���f�b�N�X
 * \return		CriAtomPlayerHn		Atom�v���[���[�n���h��
 * \par ����:
 * �{�C�X�v�[�����ō쐬���ꂽAtom�v���[���[�n���h�����擾���܂��B<br>
 * \par ���l:
 * �{�֐��͏��擾�p�r�ɂ݂̂ɗ��p�\�ȃf�o�b�O�֐��ł��B<br>
 */
CriAtomPlayerHn CRIAPI criAtomExVoicePool_GetPlayerHandle(
	CriAtomExVoicePoolHn pool, CriSint32 index);

/*JP
 * \brief �C���X�g�D�������g�{�C�X�v�[���쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_VOICE_POOL
 * \param[in]	config		�C���X�g�D�������g�{�C�X�v�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �C���X�g�D�������g�{�C�X�v�[���̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExVoicePool_AllocateInstrumentVoicePool �֐��Ń{�C�X�v�[�����쐬����ۂɂ́A
 * ::criAtomExVoicePool_AllocateInstrumentVoicePool �֐��ɖ{�֐����Ԃ��T�C�Y���̃����������[�N
 * �̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \sa criAtomExVoicePool_AllocateInstrumentVoicePool
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForInstrumentVoicePool(
	const CriAtomExInstrumentVoicePoolConfig *config);

/*==========================================================================
 *      CRI AtomEx Category API
 *=========================================================================*/
/*JP
 * \brief ID�w��ɂ��J�e�S���ɑ΂���{�����[���ݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id		�J�e�S��ID
 * \param[in]	volume	�{�����[���l
 * \par ����:
 * ID�w��ŃJ�e�S���ɑ΂��ă{�����[����ݒ肵�܂��B
 * \attention
 * �{�֐��ɂ��ݒ�l��ACF�ɂ���Đݒ肳��Ă���J�e�S���{�����[�����㏑���ύX���܂��B<br>
 * �{�֐��ɂ��ݒ�l��ACF�ݒ�l�Ƃ̏�Z�K�p�͍s���Ȃ����Ƃɒ��ӂ��Ă��������B
 */
void CRIAPI criAtomExCategory_SetVolumeById(CriAtomExCategoryId id, CriFloat32 volume);

/*JP
 * \brief ID�w��ɂ��J�e�S���{�����[���擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id		�J�e�S��ID
 * return		CriFloat32 �J�e�S���{�����[��
 * \par ����:
 * ID�w��ŃJ�e�S���̃{�����[�����擾���܂��B
 */
CriFloat32 CRIAPI criAtomExCategory_GetVolumeById(CriAtomExCategoryId id);

/*JP
 * \brief ID�w��ɂ��ŏI�J�e�S���{�����[���擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id		�J�e�S��ID
 * return		CriFloat32 �J�e�S���{�����[��
 * \par ����:
 * ID�w���REACT�AAISAC�Ȃǂ̉e�����󂯂��ŏI�I�ȃJ�e�S���̃{�����[���l���擾���܂��B
 * \par ���l:
 * �ŏI�I�ȃJ�e�S���̃{�����[���l���擾���邽�߂Ƀp�����[�^�[�̌v�Z�������s���̂ŁA
 * ���ׂ��傫���֐��ł��B
 */
CriFloat32 CRIAPI criAtomExCategory_GetTotalVolumeById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ɂ��J�e�S���ɑ΂���{�����[���ݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * \param[in]	volume	�{�����[���l
 * \par ����:
 * ���O�w��ŃJ�e�S���ɑ΂��ă{�����[����ݒ肵�܂��B
 * \attention
 * �{�֐��ɂ��ݒ�l��ACF�ɂ���Đݒ肳��Ă���J�e�S���{�����[�����㏑���ύX���܂��B<br>
 * �{�֐��ɂ��ݒ�l��ACF�ݒ�l�Ƃ̏�Z�K�p�͍s���Ȃ����Ƃɒ��ӂ��Ă��������B
 */
void CRIAPI criAtomExCategory_SetVolumeByName(const CriChar8* name, CriFloat32 volume);

/*JP
 * \brief ���O�w��ɂ��J�e�S���{�����[���擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name		�J�e�S����
 * return		CriFloat32 �J�e�S���{�����[��
 * \par ����:
 * ���O�w��ŃJ�e�S���̃{�����[�����擾���܂��B
 */
CriFloat32 CRIAPI criAtomExCategory_GetVolumeByName(const CriChar8* name);

/*JP
 * \brief ���O�w��ɂ��ŏI�J�e�S���{�����[���擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name		�J�e�S����
 * return		CriFloat32 �J�e�S���{�����[��
 * \par ����:
 * ���O�w���REACT�AAISAC�Ȃǂ̉e�����󂯂��ŏI�I�ȃJ�e�S���̃{�����[���l���擾���܂��B
 * \par ���l:
 * �ŏI�I�ȃJ�e�S���̃{�����[���l���擾���邽�߂Ƀp�����[�^�[�̌v�Z�������s���̂ŁA
 * ���ׂ��傫���֐��ł��B
 */
CriFloat32 CRIAPI criAtomExCategory_GetTotalVolumeByName(const CriChar8* name);

/*JP
 * \brief ID�w��ɂ��J�e�S���~���[�g��Ԑݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * \param[in]	mute �~���[�g��ԁiCRI_TRUE = �~���[�g�ACRI_FALSE = �~���[�g�����j
 * \par ����:
 * ID�w��ŃJ�e�S���̃~���[�g��Ԃ�ݒ肵�܂��B
 */
void CRIAPI criAtomExCategory_MuteById(CriAtomExCategoryId id, CriBool mute);

/*JP
 * \brief ID�w��ɂ��J�e�S���~���[�g��Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * return		CriBool �~���[�g��ԁiCRI_TRUE = �~���[�g���ACRI_FALSE = �~���[�g����Ă��Ȃ��j
 * \par ����:
 * ID�w��ŃJ�e�S���̃~���[�g��Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsMutedById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ɂ��J�e�S���~���[�g��Ԑݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * \param[in]	mute �~���[�g��ԁiCRI_TRUE = �~���[�g�ACRI_FALSE = �~���[�g�����j
 * \par ����:
 * ���O�w��ŃJ�e�S���̃~���[�g��Ԃ�ݒ肵�܂��B
 */
void CRIAPI criAtomExCategory_MuteByName(const CriChar8* name, CriBool mute);

/*JP
 * \brief ���O�w��ɂ��J�e�S���~���[�g��Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * return		CriBool �~���[�g��ԁiCRI_TRUE = �~���[�g���ACRI_FALSE = �~���[�g����Ă��Ȃ��j
 * \par ����:
 * ���O�w��ŃJ�e�S���̃~���[�g��Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsMutedByName(const CriChar8* name);

/*JP
 * \brief ID�w��ɂ��J�e�S���\����Ԑݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * \param[in]	solo �\����ԁiCRI_TRUE = �\���ACRI_FALSE = �\�������j
 * \param[in]	mute_volume ���̃J�e�S���ɓK�p����~���[�g�{�����[���l
 * \par ����:
 * ID�w��ŃJ�e�S���̃\����Ԃ�ݒ肵�܂��B<br>
 * mute_volume�Ŏw�肵���{�����[���͓���J�e�S���O���[�v�ɏ�������
 * �J�e�S���ɑ΂��ēK�p����܂��B
 */
void CRIAPI criAtomExCategory_SoloById(CriAtomExCategoryId id, CriBool solo, CriFloat32 mute_volume);

/*JP
 * \brief ID�w��ɂ��J�e�S���\����Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * return		CriBool �\����ԁiCRI_TRUE = �\�����ACRI_FALSE = �\���ł͂Ȃ��j
 * \par ����:
 * ID�w��ŃJ�e�S���̃\����Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsSoloedById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ɂ��J�e�S���\����Ԑݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name �J�e�S����
 * \param[in]	solo �\����ԁiCRI_TRUE = �\���ACRI_FALSE = �\�������j
 * \param[in]	mute_volume ���̃J�e�S���ɓK�p����~���[�g�{�����[���l
 * \par ����:
 * ���O�w��ŃJ�e�S���̃\����Ԃ�ݒ肵�܂��B<br>
 * mute_volume�Ŏw�肵���{�����[���͓���J�e�S���O���[�v�ɏ�������
 * �J�e�S���ɑ΂��ēK�p����܂��B
 */
void CRIAPI criAtomExCategory_SoloByName(const CriChar8* name, CriBool solo, CriFloat32 mute_volume);

/*JP
 * \brief ���O�w��ɂ��J�e�S���\����Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * return		CriBool �\����ԁiCRI_TRUE = �\�����ACRI_FALSE = �\���ł͂Ȃ��j
 * \par ����:
 * ���O�w��ŃJ�e�S���̃\����Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsSoloedByName(const CriChar8* name);

/*JP
 * \brief ID�w��ɂ��J�e�S���̃|�[�Y�^�|�[�Y����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * \param[in]	sw	�X�C�b�`�iCRI_FALSE = �|�[�Y�����ACRI_TRUE = �|�[�Y�j
 * \par ����:
 * ID�w��ŃJ�e�S���̃|�[�Y�^�|�[�Y�������s���܂��B<br>
 * ::criAtomExCategory_SetFadeOutTimeById �֐���::criAtomExCategory_SetFadeOutTimeByName
 * �֐��Ńt�F�[�h�A�E�g���Ԃ��ݒ肳��Ă���ꍇ�Ƀ|�[�Y���s���ƁA�ݒ肳�ꂽ���ԂŃt�F�[�h�A�E�g������Ɏ��ۂɃ|�[�Y���܂��B<br>
 * ::criAtomExCategory_SetFadeInTimeById �֐���::criAtomExCategory_SetFadeInTimeByName
 * �֐��Ńt�F�[�h�C�����Ԃ��ݒ肳��Ă���ꍇ�Ƀ|�[�Y�������s���ƁA�|�[�Y������A�ݒ肳�ꂽ���ԂŃt�F�[�h�C�����܂��B<br>
 * \par ���l:
 * �J�e�S���̃|�[�Y�́AAtomEx�v���[���[�^�Đ����̃|�[�Y
 * �i::criAtomExPlayer_Pause �֐���::criAtomExPlayback_Pause �֐��ł̃|�[�Y�j�Ƃ͓Ɨ����Ĉ����A
 * �����̍ŏI�I�ȃ|�[�Y��Ԃ́A���ꂼ��̃|�[�Y��Ԃ��l�����Č��܂�܂��B<br>
 * ���Ȃ킿�A�ǂ��炩���|�[�Y��ԂȂ�|�[�Y�A�ǂ�����|�[�Y������ԂȂ�|�[�Y�����A�ƂȂ�܂��B
 */
void CRIAPI criAtomExCategory_PauseById(CriAtomExCategoryId id, CriBool sw);

/*JP
 * \brief ID�w��ɂ��J�e�S���̃|�[�Y��Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id		�J�e�S��ID
 * return		CriBool	�|�[�Y���
 * \par ����:
 * ID�w��ŃJ�e�S���̃|�[�Y��Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsPausedById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ɂ��J�e�S���̃|�[�Y�^�|�[�Y����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * \param[in]	sw		�X�C�b�`�iCRI_FALSE = �|�[�Y�����ACRI_TRUE = �|�[�Y�j
 * \par ����:
 * ���O�w��ŃJ�e�S���̃|�[�Y�^�|�[�Y�������s���܂��B<br>
 * �J�e�S���𖼑O�Ŏw�肷��ȊO�́A::criAtomExCategory_PauseById �֐��Ǝd�l�͓����ł��B<br>
 * \sa criAtomExCategory_PauseById
 */
void CRIAPI criAtomExCategory_PauseByName(const CriChar8* name, CriBool sw);

/*JP
 * \brief ���O�w��ɂ��J�e�S���̃|�[�Y��Ԏ擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * return		CriBool �|�[�Y���
 * \par ����:
 * ���O�w��ŃJ�e�S���̃|�[�Y��Ԃ��擾���܂��B
 */
CriBool CRIAPI criAtomExCategory_IsPausedByName(const CriChar8* name);

/*JP
 * \brief �t�F�[�h�C�����Ԃ̐ݒ�i�J�e�S��ID�w��j
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * \param[in]	ms	�t�F�[�h�C�����ԁi�~���b�P�ʁj
 * \par ����:
 * �J�e�S���Ƀt�F�[�h�C�����Ԃ�ݒ肵�܂��B<br>
 * �t�F�[�h�C�����Ԃ̓|�[�Y�������s�����ۂɗ��p����܂��B<br>
 */
void CRIAPI criAtomExCategory_SetFadeInTimeById(CriAtomExCategoryId id, CriUint16 ms);

/*JP
 * \brief �t�F�[�h�C�����Ԃ̐ݒ�i�J�e�S�����w��j
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * \param[in]	ms		�t�F�[�h�C�����ԁi�~���b�P�ʁj
 * \par ����:
 * �J�e�S���Ƀt�F�[�h�C�����Ԃ�ݒ肵�܂��B<br>
 * �t�F�[�h�C�����Ԃ̓|�[�Y�������s�����ۂɗ��p����܂��B<br>
 */
void CRIAPI criAtomExCategory_SetFadeInTimeByName(const CriChar8* name, CriUint16 ms);

/*JP
 * \brief �t�F�[�h�A�E�g���Ԃ̐ݒ�i�J�e�S��ID�w��j
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id	�J�e�S��ID
 * \param[in]	ms	�t�F�[�h�A�E�g���ԁi�~���b�P�ʁj
 * \par ����:
 * �J�e�S���Ƀt�F�[�h�A�E�g���Ԃ�ݒ肵�܂��B<br>
 * �t�F�[�h�A�E�g���Ԃ̓|�[�Y���s�����ۂɗ��p����܂��B<br>
 */
void CRIAPI criAtomExCategory_SetFadeOutTimeById(CriAtomExCategoryId id, CriUint16 ms);

/*JP
 * \brief �t�F�[�h�A�E�g���Ԃ̐ݒ�i�J�e�S�����w��j
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name	�J�e�S����
 * \param[in]	ms		�t�F�[�h�A�E�g���ԁi�~���b�P�ʁj
 * \par ����:
 * �J�e�S���Ƀt�F�[�h�A�E�g���Ԃ�ݒ肵�܂��B<br>
 * �t�F�[�h�A�E�g���Ԃ̓|�[�Y���s�����ۂɗ��p����܂��B<br>
 */
void CRIAPI criAtomExCategory_SetFadeOutTimeByName(const CriChar8* name, CriUint16 ms);

/*JP
 * \brief ID�w��ɂ��J�e�S���ɑ΂���AISAC�R���g���[���l�ݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id				�J�e�S��ID
 * \param[in]	control_id		AISAC�R���g���[��ID
 * \param[in]	control_value	AISAC�R���g���[���l
 * \par ����:
 * ID�w��ŃJ�e�S���ɑ΂���AISAC�R���g���[���l��ݒ肵�܂��B<br>
 * \par ���l:
 * �J�e�S����ID�AAISAC�R���g���[���𖼑O�Ŏw�肵�����ꍇ�A::criAtomExAcf_GetAisacControlIdByName �֐��ɂĕϊ����s���Ă��������B
 * \attention
 * �L���[��g���b�N�ɐݒ肳��Ă���AISAC�Ɋւ��ẮA�v���[���[�ł�AISAC�R���g���[���l�ݒ�����A<b>�J�e�S����AISAC�R���g���[���l��D�悵��</b>�Q�Ƃ��܂��B<br>
 * �J�e�S���ɃA�^�b�`����AISAC�ɂ��ẮA���<b>�J�e�S���ɐݒ肵��AISAC�R���g���[���l�̂�</b>�A�Q�Ƃ���܂��B
 * \sa criAtomExCategory_SetAisacControlByName, criAtomExCategory_AttachAisacById, criAtomExCategory_AttachAisacByName
 */
void CRIAPI criAtomExCategory_SetAisacControlById(
	CriAtomExCategoryId id,
	CriAtomExAisacControlId control_id,
	CriFloat32 control_value
);

/*JP
 * \brief ���O�w��ɂ��J�e�S���ɑ΂���AISAC�R���g���[���l�ݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name			�J�e�S����
 * \param[in]	control_name	AISAC�R���g���[����
 * \param[in]	control_value	AISAC�R���g���[���l
 * \par ����:
 * ���O�w��ŃJ�e�S���ɑ΂���AISAC�R���g���[���l��ݒ肵�܂��B<br>
 * �J�e�S�������AISAC�R���g���[���𖼑O�Ŏw�肷��ȊO�́A::criAtomExCategory_SetAisacControlById �֐��Ǝd�l�͓����ł��B<br>
 * \par ���l:
 * �J�e�S���𖼑O�AAISAC�R���g���[����ID�Ŏw�肵�����ꍇ�A::criAtomExAcf_GetAisacControlNameById �֐��ɂĕϊ����s���Ă��������B
 * \sa criAtomExCategory_SetAisacControlById, criAtomExCategory_AttachAisacById, criAtomExCategory_AttachAisacByName
 */
void CRIAPI criAtomExCategory_SetAisacControlByName(
	const CriChar8* name,
	const CriChar8* control_name,
	CriFloat32 control_value
);

/*JP
 * \brief ID�w��ŃJ�e�S���ɃA�^�b�`����Ă���S�Ă�AISAC�R���g���[���l���f�t�H���g�l�ɐݒ肷��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	category_id		�J�e�S��ID
 * \retval	CRI_TRUE = ����
 * \retval	CRI_FALSE = ���s
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���S�Ă�AISAC�R���g���[���l���f�t�H���g�l�ɐݒ肵�܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsById
 */
CriBool CRIAPI criAtomExCategory_ResetAllAisacControlById(CriAtomExCategoryId category_id);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɃA�^�b�`����Ă���S�Ă�AISAC�R���g���[���l���f�t�H���g�l�ɐݒ肷��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	category_name					�J�e�S����
 * \retval	CRI_TRUE = ����
 * \retval	CRI_FALSE = ���s
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���S�Ă�AISAC�R���g���[���l���f�t�H���g�l�ɐݒ肵�܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsById
 */
CriBool CRIAPI criAtomExCategory_ResetAllAisacControlByName(const CriChar8* category_name);

/*JP
 * \brief ID�w��ŃJ�e�S����AISAC�����t����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \param[in]	global_aisac_name	���t����O���[�o��AISAC��
 * \par ����:
 * �J�e�S����AISAC���A�^�b�`�i���t���j���܂��B
 * AISAC���A�^�b�`���邱�Ƃɂ��A�L���[��g���b�N��AISAC��ݒ肵�Ă��Ȃ��Ă��AAISAC�̌��ʂ𓾂邱�Ƃ��ł��܂��B<br>
 * <br>
 * AISAC�̃A�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃A�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \par ���l:
 * �S�̐ݒ�iACF�t�@�C���j�Ɋ܂܂��O���[�o��AISAC�̂݁A�A�^�b�`�\�ł��B<br>
 * AISAC�̌��ʂ𓾂�ɂ́A�L���[��g���b�N�ɐݒ肳��Ă���AISAC�Ɠ��l�ɁA�Y������AISAC�R���g���[���l��ݒ肷��K�v������܂��B<br>
 * \attention
 * �L���[��g���b�N�ɁuAISAC�R���g���[���l��ύX����AISAC�v���ݒ肳��Ă����Ƃ��Ă��A
 * ���̓K�p���ʂ�AISAC�R���g���[���l�́A�J�e�S���ɃA�^�b�`����AISAC�ɂ͉e�����܂���B<br>
 * �J�e�S���ɃA�^�b�`����AISAC�ɂ��ẮA���<b>�J�e�S���ɐݒ肵��AISAC�R���g���[���l�̂�</b>�A�Q�Ƃ���܂��B<br>
 * ���݁A�u�I�[�g���W�����[�V�����v��u�����_���v�Ƃ������R���g���[���^�C�v��AISAC�̃A�^�b�`�ɂ͑Ή����Ă���܂���B<br>
 * ���݁A�J�e�S���ɃA�^�b�`�ł���AISAC�̍ő吔�́A8�Œ�ł��B
 * \sa criAtomExCategory_DetachAisacById
 */
void CRIAPI criAtomExCategory_AttachAisacById(CriAtomExCategoryId id, const CriChar8* global_aisac_name);

/*JP
 * \brief ���O�w��ŃJ�e�S����AISAC�����t����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name				�J�e�S����
 * \param[in]	global_aisac_name	���t����O���[�o��AISAC��
 * \par ����:
 * �J�e�S����AISAC���A�^�b�`�i���t���j���܂��B
 * �J�e�S���𖼑O�Ŏw�肷��ȊO�́A::criAtomExCategory_AttachAisacById �֐��Ǝd�l�͓����ł��B<br>
 * \sa criAtomExCategory_AttachAisacById, criAtomExCategory_DetachAisacByName
 */
void CRIAPI criAtomExCategory_AttachAisacByName(const CriChar8* name, const CriChar8* global_aisac_name);

/*JP
 * \brief ID�w��ŃJ�e�S������AISAC�����O��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \param[in]	global_aisac_name	���O���O���[�o��AISAC��
 * \par ����:
 * �J�e�S������AISAC���f�^�b�`�i���O���j���܂��B<br>
 * <br>
 * AISAC�̃f�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃f�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \sa criAtomExCategory_AttachAisacById
 */
void CRIAPI criAtomExCategory_DetachAisacById(CriAtomExCategoryId id, const CriChar8* global_aisac_name);

/*JP
 * \brief ���O�w��ŃJ�e�S������AISAC�����O��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \param[in]	global_aisac_name	���O���O���[�o��AISAC��
 * \par ����:
 * �J�e�S������AISAC���f�^�b�`�i���O���j���܂��B<br>
 * �J�e�S���𖼑O�Ŏw�肷��ȊO�́A::criAtomExCategory_DetachAisacById �֐��Ǝd�l�͓����ł��B<br>
 * \sa criAtomExCategory_DetachAisacById, criAtomExCategory_AttachAisacByName
 */
void CRIAPI criAtomExCategory_DetachAisacByName(const CriChar8* name, const CriChar8* global_aisac_name);

/*JP
 * \brief ID�w��ŃJ�e�S������S�Ă�AISAC�����O��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \par ����:
 * �J�e�S������S�Ă�AISAC���f�^�b�`�i���O���j���܂��B
 */
void CRIAPI criAtomExCategory_DetachAisacAllById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ŃJ�e�S������S�Ă�AISAC�����O��
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \par ����:
 * �J�e�S������S�Ă�AISAC���f�^�b�`�i���O���j���܂��B
 */
void CRIAPI criAtomExCategory_DetachAisacAllByName(const CriChar8* name);

/*JP
 * \brief ID�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \return	�J�e�S���ɃA�^�b�`����Ă���AISAC��
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�����擾���܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�A���l���Ԃ�܂��B
 */
CriSint32 CRIAPI criAtomExCategory_GetNumAttachedAisacsById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \return	�J�e�S���ɃA�^�b�`����Ă���AISAC��
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�����擾���܂��B
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�A���l���Ԃ�܂��B
 */
CriSint32 CRIAPI criAtomExCategory_GetNumAttachedAisacsByName(const CriChar8* name);

/*JP
 * \brief ID�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�̏����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id						�J�e�S��ID
 * \param[in]	aisac_attached_index	�A�^�b�`����Ă���AISAC�̃C���f�b�N�X
 * \param[out]	aisac_info				AISAC���
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�̏����擾���܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ��A�����ȃC���f�b�N�X���w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsById
 */
CriBool CRIAPI criAtomExCategory_GetAttachedAisacInfoById(
	CriAtomExCategoryId id, 
	CriSint32 aisac_attached_index,
	CriAtomExAisacInfo *aisac_info
);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�̏����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \param[in]	aisac_attached_index	�A�^�b�`����Ă���AISAC�̃C���f�b�N�X
 * \param[out]	aisac_info				AISAC���
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�̏����擾���܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ��A�����ȃC���f�b�N�X���w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsByName
 */
CriBool CRIAPI criAtomExCategory_GetAttachedAisacInfoByName(
	const CriChar8* name,
	CriSint32 aisac_attached_index,
	CriAtomExAisacInfo *aisac_info
);

/*JP
 * \brief ID�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�R���g���[���̌��ݒl���擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	category_id			�J�e�S��ID
 * \param[in]	aisac_control_id	AISAC�R���g���[��ID
 * \param[out]	control_value		AISAC�R���g���[���̌��ݒl
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�R���g���[���̌��ݒl���擾���܂��B<br>
 * ���݂��Ȃ��J�e�S����AISAC�R���g���[�����w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsById
 */
CriBool CRIAPI criAtomExCategory_GetCurrentAisacControlValueById(
	CriAtomExCategoryId category_id,
	CriAtomExAisacControlId aisac_control_id,
	CriFloat32 * control_value
);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɃA�^�b�`����Ă���AISAC�R���g���[���̌��ݒl���擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	category_name			�J�e�S����
 * \param[in]	aisac_control_name		AISAC�R���g���[����
 * \param[out]	control_value			AISAC�R���g���[���̌��ݒl
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * �J�e�S���ɃA�^�b�`����Ă���AISAC�R���g���[���̌��ݒl���擾���܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ��A�����ȃC���f�b�N�X���w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetNumAttachedAisacsById
 */
CriBool CRIAPI criAtomExCategory_GetCurrentAisacControlValueByName(
	const CriChar8* category_name,
	const CriChar8* aisac_control_name,
	CriFloat32 * control_value
);

/*JP
 * \brief REACT�쓮�p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	react_name			REACT��
 * \param[in]	react_parameter		REACT�쓮�p�����[�^�[�\����
 * \par ����:
 * REACT���쓮������p�����[�^�[��ݒ肵�܂��B<br>
 * REACT�����삵�Ă���Ԃ̓p�����[�^�[��ݒ肷�邱�Ƃ͂ł��܂���i�x�����������܂��j�B<br>
 * ���݂��Ȃ�REACT�����w�肵���ꍇ�́A�G���[�R�[���o�b�N���Ԃ�܂��B<br>
 * \sa criAtomExCategory_GetReactParameter
 */
void CRIAPI criAtomExCategory_SetReactParameter(
	const CriChar8* react_name, 
	const CriAtomExReactParameter* react_parameter);

/*JP
 * \brief REACT�쓮�p�����[�^�[�̎擾
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	react_name			REACT��
 * \param[out]	react_parameter		REACT�쓮�p�����[�^�[�\����
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * REACT���쓮������p�����[�^�[�̌��ݒl���擾���܂��B<br>
 * ���݂��Ȃ�REACT�����w�肵���ꍇ�́A�G���[�R�[���o�b�N��������CRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExCategory_SetReactParameter
 */
CriBool CRIAPI criAtomExCategory_GetReactParameter(
	const CriChar8* react_name, 
	CriAtomExReactParameter* react_parameter);

/*JP
 * \brief ID�w��ŃJ�e�S���ɏ������锭�����̃L���[�����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \return	�J�e�S���ɏ������锭�����̃L���[��
 * \par ����:
 * �J�e�S���ɏ������锭�����̃L���[�����擾���܂��B<br>
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�A���l���Ԃ�܂��B
 */
CriSint32 CRIAPI criAtomExCategory_GetNumCuePlayingCountById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɏ������锭�����̃L���[�����擾����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \return	�J�e�S���ɏ������锭�����̃L���[��
 * \par ����:
 * �J�e�S���ɏ������锭�����̃L���[�����擾���܂��B
 * ���݂��Ȃ��J�e�S�����w�肵���ꍇ�A���l���Ԃ�܂��B
 */
CriSint32 CRIAPI criAtomExCategory_GetNumCuePlayingCountByName(const CriChar8* name);

/*JP
 * \brief ID�w��ŃJ�e�S���ɏ������锭�����̃L���[���~����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \par ����:
 * �w�肵���J�e�S���ɏ������锭�����̃L���[���~���܂��B<br>
 */
void CRIAPI criAtomExCategory_StopById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɏ������锭�����̃L���[���~����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \par ����:
 * �w�肵���J�e�S���ɏ������锭�����̃L���[���~���܂��B<br>
 */
void CRIAPI criAtomExCategory_StopByName(const CriChar8* name);

/*JP
 * \brief ID�w��ŃJ�e�S���ɏ������锭�����̃L���[�𑦎���~����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	id					�J�e�S��ID
 * \par ����:
 * �w�肵���J�e�S���ɏ������锭�����̃L���[�𑦎���~���܂��B<br>
 */
void CRIAPI criAtomExCategory_StopWithoutReleaseTimeById(CriAtomExCategoryId id);

/*JP
 * \brief ���O�w��ŃJ�e�S���ɏ������锭�����̃L���[�𑦎���~����
 * \ingroup ATOMEXLIB_CATEGORY
 * \param[in]	name					�J�e�S����
 * \par ����:
 * �w�肵���J�e�S���ɏ������锭�����̃L���[�𑦎���~���܂��B<br>
 */
void CRIAPI criAtomExCategory_StopWithoutReleaseTimeByName(const CriChar8* name);
	
/*==========================================================================
 *      CRI AtomEx Player API
 *=========================================================================*/
/*JP
 * \brief AtomExPlayer�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	config		�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * AtomEx�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������AtomEx�v���[���[���쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomExPlayer_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExPlayer_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create
 */
CriSint32 CRIAPI criAtomExPlayer_CalculateWorkSize(
	const CriAtomExPlayerConfig *config);

/*JP
 * \brief AtomExPlayer�̍쐬
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	config		AtomEx�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExPlayerHn	AtomEx�v���[���[�n���h��
 * \par ����:
 * AtomEx�v���[���[���쐬���܂��B<br>
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * work��NULL�Awork_size��0���w�肷�邾���ŁA�K�v�ȃ�������o�^�ς݂̃������m�ۊ֐�����m�ۂ��܂��B<br>
 * AtomEx�v���[���[�쐬���Ɋm�ۂ��ꂽ�������́AAtomEx�v���[���[�j�����i ::criAtomExPlayer_Destroy 
 * �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtomExPlayer_CalculateWorkSize �֐��Ŏ擾�\�ł��B<br>
 * AtomEx�v���[���[�쐬�O�� ::criAtomExPlayer_CalculateWorkSize �֐��Ŏ擾����
 * �T�C�Y���̃�������\�ߊm�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈��AtomEx�v���[���[�̔j��
 * �i ::criAtomExPlayer_Destroy �֐��j���s�Ȃ��܂ł̊ԁA���C�u�������ŗ��p���ꑱ���܂��B<br>
 * AtomEx�v���[���[�̔j�����s�Ȃ��O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B<br>
 * \par ��:
 * �yUser Allocator�����ɂ��AtomEx�v���[���[�̍쐬�z<br>
 * User Allocator������p����ꍇ�AAtomEx�v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# AtomEx�v���[���[�쐬�O�ɁA ::criAtomEx_SetUserAllocator �֐���p���ă������m�ہ^����֐���o�^����B<br>
 * 	-# AtomEx�v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ::criAtomExPlayer_Create �֐���AtomEx�v���[���[���쐬����B<br>
 * �iwork�ɂ�NULL�Awork_size�ɂ�0���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomExPlayer_Destroy �֐���AtomEx�v���[���[��j������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * // �Ǝ��̃������m�ۊ֐�
 * void *user_malloc(void *obj, CriUint32 size)
 * {
 * 	void *mem;
 * 	
 * 	// �������̊m��
 * 	mem = malloc(size);
 * 	
 * 	return (mem);
 * }
 * 
 * // �Ǝ��̃���������֐���p��
 * void user_free(void *obj, void *mem)
 * {
 * 	// �������̉��
 * 	free(mem);
 * 	
 * 	return;
 * }
 * 
 * main()
 * {
 * 	CriAtomExPlayerConfig config;	// AtomEx�v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomExPlayerHn player;		// AtomEx�v���[���[�n���h��
 * 		:
 * 	// �Ǝ��̃������A���P�[�^�[��o�^
 * 	criAtomEx_SetUserAllocator(user_malloc, user_free, NULL);
 * 	
 * 	// AtomEx�v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	criAtomExPlayer_SetDefaultConfig(&config);
 * 	
 * 	// AtomEx�v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������́A�o�^�����������m�ۊ֐����g���Ċm�ۂ����B
 * 	player = criAtomExPlayer_Create(&config, NULL, 0);
 * 		:
 * 	// �����Đ�����
 * 		:
 * 	// AtomEx�v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	// ��AtomEx�v���[���[�쐬���Ƀ��C�u�������Ŋm�ۂ��ꂽ����������������B
 * 	criAtomExPlayer_Destroy(player);
 * 		:
 * }
 * \endcode
 * �����C�u�������������Ƀ������m�ہ^����֐���o�^�ς݂̏ꍇ�AAtomEx�v���[���[�쐬��
 * �ɍēx�֐���o�^����K�v�͂���܂���B<br>
 * <br>
 * �yFixed Memory�����ɂ��AtomEx�v���[���[�̍쐬�z<br>
 * Fixed Memory������p����ꍇ�AAtomEx�v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# AtomEx�v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# AtomEx�v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���A
 * ::criAtomExPlayer_CalculateWorkSize �֐����g���Čv�Z����B<br>
 * 	-# ���[�N�̈�T�C�Y���̃��������m�ۂ���B<br>
 * 	-# ::criAtomExPlayer_Create �֐���AtomEx�v���[���[���쐬����B<br>
 * �iwork�ɂ͊m�ۂ����������̃A�h���X���Awork_size�ɂ̓��[�N�̈�̃T�C�Y���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomExPlayer_Destroy �֐���AtomEx�v���[���[��j������B<br>
 * 	-# ���[�N�̈�̃��������������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 	CriAtomExPlayerConfig config;	// AtomEx�v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomExPlayerHn player;		// AtomEx�v���[���[�n���h��
 * 	void *work;						// ���[�N�̈�A�h���X
 * 	CriSint32 work_size;			// ���[�N�̈�T�C�Y
 * 		:
 * 	// AtomEx�v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	criAtomExPlayer_SetDefaultConfig(&config);
 * 	
 * 	// AtomEx�v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z
 * 	work_size = criAtomExPlayer_CalculateWorkSize(&config);
 * 	
 * 	// ���[�N�̈�p�Ƀ��������m��
 * 	work = malloc((size_t)work_size);
 * 	
 * 	// AtomEx�v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���m�ۍς݂̃��[�N�̈���w�肷��B
 * 	player = criAtomExPlayer_Create(&config, work, work_size);
 * 		:
 * 	// �����Đ�����
 * 	// �����̊ԁA�m�ۂ����������͕ێ���������B
 * 		:
 * 	// AtomEx�v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	criAtomExPlayer_Destroy(player);
 * 	
 * 	// �K�v�Ȃ��Ȃ������[�N�̈���������
 * 	free(work);
 * 		:
 * }
 * \endcode
 * ::criAtomExPlayer_Create �֐������s����ƁAAtomEx�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomExPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtomEx�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �v���[���[�̍쐬�Ɏ��s�����ꍇ�A�߂�l�Ƃ��� NULL ���Ԃ���܂��B<br>
 * �v���[���[�̍쐬�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * <br>
 * �쐬���ꂽAtomEx�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomExPlayer_SetData �֐����g�p���āAAtomEx�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomExPlayer_SetFile �֐��܂��� ::criAtomExPlayer_SetContentId 
 * �֐����g�p����B�j<br>
 * -# ::criAtomExPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * AtomEx�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * AtomEx�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_CalculateWorkSize,
 * CriAtomExPlayerHn, criAtomExPlayer_Destroy,
 * criAtomExPlayer_SetData, criAtomExPlayer_SetFile, criAtomExPlayer_SetContentId,
 * criAtomExPlayer_Start
 */
CriAtomExPlayerHn CRIAPI criAtomExPlayer_Create(
	const CriAtomExPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief AtomEx�v���[���[�̔j��
 * \ingroup ATOMExLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \par ����:
 * AtomEx�v���[���[��j�����܂��B<br>
 * �{�֐������s�������_�ŁAAtomEx�v���[���[�쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��AtomEx�v���[���[�n���h���������ɂȂ�܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �����Đ�����AtomEx�v���[���[��j�����悤�Ƃ����ꍇ�A�{�֐����ōĐ���~��
 * �҂��Ă��烊�\�[�X�̉�����s���܂��B<br>
 * �i�t�@�C������Đ����Ă���ꍇ�́A����ɓǂݍ��݊����҂����s���܂��B�j<br>
 * ���̂��߁A�{�֐����ŏ����������ԁi���t���[���j�u���b�N�����\��������܂��B<br>
 * AtomEx�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomExPlayer_Create, CriAtomExPlayerHn
 */
void CRIAPI criAtomExPlayer_Destroy(CriAtomExPlayerHn player);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�L���[ID�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	id				�L���[ID
 * \par ����:
 * �L���[ID���AAtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��ŃL���[ID���w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�L���[���Đ�����܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueId(player, acb_hn, 100);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����f�[�^�̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * ��2�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[ID��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[ID������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^�̃L���[���v���[���[�ɃZ�b�g����܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * <br>
 * ::criAtomExPlayer_SetCueId �֐��ŃL���[���Z�b�g�����ꍇ�A�ȉ��̊֐��Őݒ肳�ꂽ
 * �p�����[�^�[�͖�������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * �i�����t�H�[�}�b�g��`�����l�����A�T���v�����O���[�g���̏��́A
 * ACB �t�@�C���̏������Ɏ����I�ɃZ�b�g����܂��B�j<br>
 * \sa criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetCueId(
	CriAtomExPlayerHn player, CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�L���[���w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	cue_name		�L���[��
 * �L���[�����AAtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��ŃL���[�����w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�L���[���Đ�����܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueName(player, acb_hn, "gun_shot");
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����f�[�^�̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * ��2�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[����
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[��������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^�̃L���[���v���[���[�ɃZ�b�g����܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * <br>
 * ::criAtomExPlayer_SetCueName �֐��ŃL���[���Z�b�g�����ꍇ�A�ȉ��̊֐��Őݒ肳�ꂽ
 * �p�����[�^�[�͖�������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * �i�����t�H�[�}�b�g��`�����l�����A�T���v�����O���[�g���̏��́A
 * ACB �t�@�C���̏������Ɏ����I�ɃZ�b�g����܂��B�j<br>
 * \sa criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetCueName(
	CriAtomExPlayerHn player, CriAtomExAcbHn acb_hn, const CriChar8 *cue_name);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�L���[�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	acb_hn			ACB�n���h��
 * \param[in]	index			�L���[�C���f�b�N�X
 * �L���[�C���f�b�N�X���AAtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��ŃL���[�C���f�b�N�X���w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�L���[���Đ�����܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueIndex(player, acb_hn, 300);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����f�[�^�̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * ��2�����i ach_hn �j�� NULL ���w�肵���ꍇ�A�S�Ă�ACB�f�[�^��ΏۂɁA�w�肵���L���[�C���f�b�N�X��
 * ���v����f�[�^���Ȃ����A���C�u�������Ō������s���܂��B<br>
 * �i�w�肵���L���[�C���f�b�N�X������ACB�f�[�^�������������_�ŁA
 * ���YACB�f�[�^�̃L���[���v���[���[�ɃZ�b�g����܂��B�j<br>
 * ���̍ہA�����̏����́AACB�f�[�^�̃��[�h���Ƃ͋t���ōs���܂��B<br>
 * �i�ォ�烍�[�h���ꂽ�f�[�^����D��I�Ɍ������s���܂��B�j<br>
 * <br>
 * ::criAtomExPlayer_SetCueIndex �֐��ŃL���[���Z�b�g�����ꍇ�A�ȉ��̊֐��Őݒ肳�ꂽ
 * �p�����[�^�[�͖�������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * �i�����t�H�[�}�b�g��`�����l�����A�T���v�����O���[�g���̏��́A
 * ACB �t�@�C���̏������Ɏ����I�ɃZ�b�g����܂��B�j<br>
 * <br>
 * �{�֐����g�p���邱�ƂŁA�L���[����L���[ID���w�肹���Ƀv���[���[�ɑ΂���
 * �������Z�b�g���邱�Ƃ��\�ł��B<br>
 * �i�L���[����L���[ID���킩��Ȃ��ꍇ�ł��AACB�t�@�C�����̃R���e���c����ʂ�Đ�
 * �\�Ȃ̂ŁA�f�o�b�O�p�r�ɗ��p�\�ł��B�j<br>
 * \sa criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetCueIndex(
	CriAtomExPlayerHn player, CriAtomExAcbHn acb_hn, CriAtomExCueIndex index);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�I���������f�[�^�̎w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	buffer			�o�b�t�@�[�A�h���X
 * \param[in]	size			�o�b�t�@�[�T�C�Y
 * \par ����:
 * ��������ɔz�u���ꂽ�����f�[�^���AAtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��Ń������A�h���X�ƃT�C�Y���w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�f�[�^���Đ�����܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer, buffer_size);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_ADX);
 * 	criAtomExPlayer_SetNumChannels(player, 1);
 * 	criAtomExPlayer_SetSamplingRate(player, 24000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����f�[�^�̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \attention
 * �v���[���[���L������̂̓o�b�t�@�[�̃A�h���X�ƃT�C�Y�݂̂ł��B<br>
 * �i�o�b�t�@�[���̃f�[�^���R�s�[�����킯�ł͂���܂���B�j<br>
 * ���̂��߁A�w�肵���f�[�^�̍Đ����I������܂ł̊ԁA
 * �A�v���P�[�V�������Ńo�b�t�@�[��ێ���������K�v������܂��B<br>
 * <br>
 * �������Đ����s���Ă���AtomEx�v���[���[���~�������ꍇ�ł��A
 * ���C�u�������ɂ͓��Y�������̈���Q�Ƃ��Ă���{�C�X�����݂���\��������܂��B<br>
 * �{�֐��ŃZ�b�g�����������̈���������ۂɂ́A���O�� ::criAtomEx_IsDataPlaying
 * �֐������s���A���Y�������̈�ւ̎Q�Ƃ��s���Ă��Ȃ����Ƃ��m�F���Ă��������B
 * <br>
 * ::criAtomExPlayer_SetData �֐��ŉ����f�[�^���Z�b�g����ꍇ�A�ȉ��̊֐����g�p����
 * �Đ����鉹���f�[�^�̏���ʓr�w�肷��K�v������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * \sa criAtomExPlayer_SetFormat, criAtomExPlayer_Start, criAtomEx_IsDataPlaying
 */
void CRIAPI criAtomExPlayer_SetData(
	CriAtomExPlayerHn player, void *buffer, CriSint32 size);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�t�@�C�����̎w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		�t�@�C���p�X
 * \par ����:
 * �����t�@�C����AtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��Ńt�@�C�����w���A ::criAtomExPlayer_Start �֐��ōĐ����J�n����ƁA
 * �w�肳�ꂽ�t�@�C�����X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomExPlayer_Start �֐����s��ł��B<br>
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomExPlayer_SetFile(player, NULL, "sample.hca");
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_HCA);
 * 	criAtomExPlayer_SetNumChannels(player, 2);
 * 	criAtomExPlayer_SetSamplingRate(player, 48000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * ::criAtomExPlayer_SetFile �֐������s����ƁA
 * �w�肵���p�X������AtomEx�v���[���[���ɕێ�����܂��B<br>
 * AtomEx�v���[���[�̓f�t�H���g��Ԃł̓p�X�������ێ�����̈��1�����m�ۂ��܂���B<br>
 * �i�������T�C�Y�팸�̂��߁B�j<br>
 * �������A�t�@�C���Đ����ɕʂ̃t�@�C����AtomEx�v���[���[�ɃZ�b�g�������ꍇ�A
 * �Đ����̃t�@�C���ƃZ�b�g�����t�@�C���̗����̃p�X��ێ�����K�v�����邽�߁A
 * 2�̃p�X�������ۑ�����̈悪�K�v�ɂȂ�܂��B<br>
 * 2�ȏ�̃t�@�C���𓯎��ɍĐ��������ꍇ�ɂ́A�v���[���[�쐬���Ɏw�肷��
 * max_path_strings �̐��𑝂₷�K�v������܂��B<br>
 * max_path_strings �̐��𑝂₷���ƂŁAAtomEx�v���[���[�͎w�肳�ꂽ������
 * �p�X������𓯎��ɕۑ��ł���悤�ɂȂ�܂��B<br>
 * �imax_path_strings ��2�ȏ�̒l���w�肷�邱�ƂŁA
 * 1�̃v���[���[�ŕ����̃t�@�C���𓯎��Ƀp�X�w��ōĐ����邱�Ƃ��\�ƂȂ�܂��B�j<br>
 * �������A max_path_strings �̒l�ɉ����ĕK�v�ȃ��[�N�̈�̃T�C�Y�͑������܂��B<br>
 * <br>
 * ::criAtomExPlayer_SetFile �֐��ŉ����f�[�^���Z�b�g����ꍇ�A�ȉ��̊֐����g�p����
 * �Đ����鉹���f�[�^�̏���ʓr�w�肷��K�v������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create, criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetFile(
	CriAtomExPlayerHn player, CriFsBinderHn binder, const CriChar8 *path);

/*JP
 * \brief �����f�[�^�̃Z�b�g�iCPK�R���e���cID�̎w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			�R���e���cID
 * \par ����:
 * �R���e���c��AtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * CRI File System���C�u�������g�p����CPK�t�@�C�����̃R���e���c�t�@�C����
 * ID�w��ōĐ����邽�߂Ɏg�p���܂��B<br>
 * �{�֐��Ƀo�C���_�[�ƃR���e���cID���w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�R���e���c�t�@�C�����X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomExPlayer_Start �֐����s��ł��B<br>
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// CPK�t�@�C�����o�C���h
 * 	criFsBinder_BindCpk(binder, "sample.cpk", work, work_size, &bind_id);
 * 	
 * 	// �o�C���h�����҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		criFsBinder_GetStatus(binder, &status);
 * 		if (status == CRIFSBINDER_STATUS_COMPLETE) {
 * 			break;
 * 		}
 * 		
 * 		// �T�[�o�[�����̎��s
 * 		criFs_ExecuteMain();
 * 		
 * 		// Vsync�҂���
 * 			:
 * 	}
 * 		:
 * 	// �����t�@�C�����Z�b�g
 * 	// sample.cpk����1�Ԃ̃R���e���c���Z�b�g
 * 	criAtomExPlayer_SetContentId(player, binder, 1);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_ADX);
 * 	criAtomExPlayer_SetNumChannels(player, 2);
 * 	criAtomExPlayer_SetSamplingRate(player, 44100);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l�F
 * �f�[�^��CPK�Ƀp�b�N����Ă��Ȃ��ꍇ�A����binder�ɂ�NULL���w�肵�Ă��������B<br>
 * \attention
 * ::criAtomExPlayer_SetContentId �֐��ŉ����f�[�^���Z�b�g����ꍇ�A�ȉ��̊֐����g�p����
 * �Đ����鉹���f�[�^�̏���ʓr�w�肷��K�v������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create, criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetContentId(
	CriAtomExPlayerHn player, CriFsBinderHn binder, CriSint32 id);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�g�`�f�[�^ID�̎w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	awb			AWB�n���h��
 * \param[in]	id			�g�`�f�[�^ID
 * \par ����:
 * �Đ�����g�`�f�[�^��AtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐���AWB�n���h���Ɣg�`�f�[�^ID���w���A ::criAtomExPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肵���g�`�f�[�^���X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomExPlayer_Start �֐����s��ł��B<br>
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// AWB��TOC�������[�h����AWB�n���h�����쐬
 * 	awb = criAtomAwb_LoadToc(NULL, "sample.awb", NULL, 0);
 * 		:
 * 	// �g�`�f�[�^���Z�b�g
 * 	// AWB����1�Ԃ̔g�`�f�[�^���Z�b�g
 * 	criAtomExPlayer_SetWaveId(player, awb, 1);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_HCA_MX);
 * 	criAtomExPlayer_SetNumChannels(player, 2);
 * 	criAtomExPlayer_SetSamplingRate(player, 32000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�AtomEx�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \attention
 * �{�֐��ŉ����f�[�^���Z�b�g����ꍇ�A
 * �ȉ��̊֐����g�p���čĐ����鉹���f�[�^�̏���ʓr�w�肷��K�v������܂��B<br>
 * 	- ::criAtomExPlayer_SetFormat
 * 	- ::criAtomExPlayer_SetNumChannels
 * 	- ::criAtomExPlayer_SetSamplingRate
 * 	
 * <br>
 * �{�֐��ŃZ�b�g�����������Đ����ɁA ::criAtomAwb_Release �֐��Ńf�[�^��j�����Ȃ��ł��������B<br>
 * AWB�t�@�C����j������ۂɂ́A�K���Đ����~������Ԃ� ::criAtomAwb_Release �֐������s���Ă��������B<br>
 * \sa CriAtomExPlayerConfig, criAtomExPlayer_Create, criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetWaveId(
	CriAtomExPlayerHn player, CriAtomAwbHn awb, CriAtomExWaveId id);

/*JP
 * \brief �Đ��̊J�n
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriAtomExPlaybackId		�Đ�ID
 * \par ����:
 * �����f�[�^�̍Đ��������J�n���܂��B<br>
 * �{�֐������s����O�ɁA���O�� ::criAtomExPlayer_SetData �֐������g�p���A�Đ�����
 * �����f�[�^��AtomEx�v���[���[�ɃZ�b�g���Ă����K�v������܂��B<br>
 * �Ⴆ�΁A�I���������̉����f�[�^���Đ�����ꍇ�ɂ́A�ȉ��̂悤�Ɏ��O��
 * ::criAtomExPlayer_SetData �֐����g���ĉ����f�[�^���Z�b�g������A�{�֐������s����
 * �K�v������܂��B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer, buffer_size);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_HCA_MX);
 * 	criAtomExPlayer_SetNumChannels(player, 1);
 * 	criAtomExPlayer_SetSamplingRate(player, 24000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �{�֐����s��A�Đ��̐i�݋�i�������J�n���ꂽ���A�Đ����������������j���ǂ��Ȃ���
 * ���邩�́A�X�e�[�^�X���擾���邱�ƂŊm�F���\�ł��B<br>
 * �X�e�[�^�X�̎擾�ɂ́A ::criAtomExPlayer_GetStatus �֐����g�p���܂��B<br>
 * ::criAtomExPlayer_GetStatus �֐��͈ȉ���5�ʂ�̃X�e�[�^�X��Ԃ��܂��B<br>
 * 	-# CRIATOMEXPLAYER_STATUS_STOP
 * 	-# CRIATOMEXPLAYER_STATUS_PREP
 * 	-# CRIATOMEXPLAYER_STATUS_PLAYING
 * 	-# CRIATOMEXPLAYER_STATUS_PLAYEND
 * 	-# CRIATOMEXPLAYER_STATUS_ERROR
 * 	
 * AtomEx�v���[���[���쐬�������_�ł́AAtomEx�v���[���[�̃X�e�[�^�X�͒�~���
 * �i CRIATOMEXPLAYER_STATUS_STOP �j�ł��B<br>
 * �Đ����鉹���f�[�^���Z�b�g��A�{�֐������s���邱�ƂŁAAtomEx�v���[���[�̃X�e�[�^�X��
 * ������ԁi CRIATOMEXPLAYER_STATUS_PREP �j�ɕύX����܂��B<br>
 * �iCRIATOMEXPLAYER_STATUS_PREP �́A�f�[�^������f�R�[�h�̊J�n��҂��Ă����Ԃł��B�j<br>
 * �Đ��̊J�n�ɏ[���ȃf�[�^���������ꂽ���_�ŁAAtomEx�v���[���[�̓X�e�[�^�X��
 * �Đ���ԁi CRIATOMEXPLAYER_STATUS_PLAYING �j�ɕύX���A�����̏o�͂��J�n���܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I����ƁAAtomEx�v���[���[�̓X�e�[�^�X���Đ��I�����
 * �i CRIATOMEXPLAYER_STATUS_PLAYEND �j�ɕύX���܂��B<br>
 * ���A�Đ����ɃG���[�����������ꍇ�ɂ́AAtomEx�v���[���[�̓X�e�[�^�X���G���[���
 * �i CRIATOMEXPLAYER_STATUS_ERROR �j�ɕύX���܂��B<br>
 * <br>
 * AtomEx�v���[���[�̃X�e�[�^�X���`�F�b�N���A�X�e�[�^�X�ɉ����ď�����؂�ւ��邱�ƂŁA
 * �����̍Đ���ԂɘA�������v���O�������쐬���邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�����̍Đ�������҂��ď�����i�߂����ꍇ�ɂ́A�ȉ��̂悤�ȃR�[�h�ɂȂ�܂��B
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer, buffer_size);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_ADX);
 * 	criAtomExPlayer_SetNumChannels(player, 1);
 * 	criAtomExPlayer_SetSamplingRate(player, 22050);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 	
 * 	// �Đ������҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomExPlayer_GetStatus(player);
 * 		
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMEXPLAYER_STATUS_PLAYEND) {
 * 			// �Đ��I�����̓��[�v�𔲂���
 * 			break;
 * 		}
 * 		
 * 		// �T�[�o�[�����̎��s
 * 		criAtomEx_ExecuteMain();
 * 		
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 * 		:
 * }
 * \endcode
 * \par ���l:
 * �֐����s���ɔ������\�[�X���m�ۂł��Ȃ��ꍇ�i�S�Ẵ{�C�X���g�p���ŁA�Ȃ�����
 * ���̃{�C�X��D�����Ȃ��ꍇ���j�A�{�֐��� CRIATOMEX_INVALID_PLAYBACK_ID ��Ԃ��܂��B<br>
 * �������A�߂�l�����ɃG���[�`�F�b�N���s��Ȃ��Ă��A�قƂ�ǂ̃P�[�X�Ŗ��͔������܂���B<br>
 * �Đ�ID�i ::CriAtomExPlaybackId �j���g�p���� API �ɑ΂��A CRIATOMEX_INVALID_PLAYBACK_ID 
 * ���Z�b�g�����Ƃ��Ă��AAtom���C�u�����͓��ɉ����������܂���B<br>
 * ���̂��߁A�f�o�b�O�ړI�Ŕ������s��ꂽ���ǂ������`�F�b�N�������ꍇ�������A
 * �{�֐��̌��ʂɉ����ăA�v���P�[�V�������ŏ�����؂蕪����K�v�͂���܂���B<br>
 * �i CRIATOMEX_INVALID_PLAYBACK_ID ���Ԃ��ꂽ�ۂɁA�L���ȍĐ�ID���Ԃ��ꂽ�ꍇ��
 * ���l�̏������s���Ă��A�G���[�R�[���o�b�N���͔������܂���B�j
 * \sa criAtomExPlayer_SetData, criAtomExPlayer_SetFile, criAtomExPlayer_GetStatus,
 * criAtomExPlayer_Pause, criAtomEx_ExecuteMain
 */
CriAtomExPlaybackId CRIAPI criAtomExPlayer_Start(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��̏���
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriAtomExPlaybackId		�Đ�ID
 * \par ����:
 * �����f�[�^�̍Đ����������܂��B<br>
 * �{�֐������s����O�ɁA���O�� ::criAtomExPlayer_SetData �֐������g�p���A
 * �Đ����ׂ������f�[�^��AtomEx�v���[���[�ɃZ�b�g���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐������s����ƁA�|�[�Y����������Ԃŉ����̍Đ����J�n���܂��B<br>
 * �֐����s�̃^�C�~���O�ŉ����Đ��ɕK�v�ȃ��\�[�X���m�ۂ��A
 * �o�b�t�@�����O�i�X�g���[���Đ����s���t�@�C���̓ǂݍ��݁j���J�n���܂����A
 * �o�b�t�@�����O������������͍s���܂���B<br>
 * �i�����\�ȏ�ԂɂȂ��Ă��A�|�[�Y��Ԃőҋ@���܂��B�j<br>
 * <br>
 * 1���������Đ�����P�[�X�ł́A�{�֐��͈ȉ��̃R�[�h�Ɠ�����������܂��B<br>
 * \code
 * 		�F
 * 	// �v���[���[���|�[�Y��Ԃɐݒ�
 * 	criAtomExPlayer_Pause(player, CRI_TRUE);
 * 	
 * 	// �����̍Đ����J�n
 * 	id = criAtomExPlayer_Start(player);
 * 		�F
 * \endcode
 * <br>
 * �{�֐��ōĐ��������s���������𔭉�����ɂ́A
 * �{�֐����Ԃ��Đ� ID �i ::CriAtomExPlaybackId �j�ɑ΂��A
 * ::criAtomExPlayback_Pause (id, CRI_FALSE); �̑�����s���K�v������܂��B<br>
 * \par ���l:
 * �X�g���[�~���O�Đ����ɂ́A ::criAtomExPlayer_Start �֐��ōĐ����J�n���Ă��A
 * ���ۂɉ����̍Đ����J�n�����܂łɂ̓^�C�����O������܂��B<br>
 * �i�����f�[�^�̃o�b�t�@�����O�Ɏ��Ԃ������邽�߁B�j<br>
 * <br>
 * �ȉ��̑�����s�����ƂŁA�X�g���[���Đ��̉����ɂ��Ă��A�����̃^�C�~���O��
 * ���䂷�邱�Ƃ��\�ɂȂ�܂��B
 * 	-# ::criAtomExPlayer_Prepare �֐��ŏ������J�n����B
 * 	-# �菇1.�Ŏ擾�����Đ�ID�̃X�e�[�^�X�� ::criAtomExPlayback_GetStatus �֐��Ŋm�F�B
 * 	-# �X�e�[�^�X�� ::CRIATOMEXPLAYBACK_STATUS_PLAYING �ɂȂ������_�� ::criAtomExPlayback_Pause �֐��Ń|�[�Y�������B
 * 	-# �|�[�Y������A���ɃT�[�o�[���������삷��^�C�~���O�Ŕ������J�n�����B
 * 	
 * ��̓I�ȃR�[�h�́A�ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetFile(player, NULL, "sample.adx");
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_ADX);
 * 	criAtomExPlayer_SetNumChannels(player, 2);
 * 	criAtomExPlayer_SetSamplingRate(player, 48000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^�̍Đ��������J�n
 * 	playback_id = criAtomExPlayer_Prepare(player);
 * 		:
 * 	// �Đ����������҂�
 * 	for (;;) {
 * 		// �Đ��X�e�[�^�X���`�F�b�N
 * 		playback_status = criAtomExPlayback_GetStatus(playback_id);
 * 		if (playback_status == CRIATOMEXPLAYBACK_STATUS_PLAYING) {
 * 			// �X�e�[�^�X���Đ���ԂɂȂ������_�Ń��[�v�𔲂���
 * 			break;
 * 		}
 * 		
 * 		// �T�[�o�[�����̎��s
 * 		criAtomEx_ExecuteMain();
 * 		
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 * 	
 * 	// �|�[�Y������
 * 	criAtomExPlayback_Pause(playback_id, CRI_FALSE);
 * 		:
 * }
 * \endcode
 * �|�[�Y���������� ::criAtomExPlayback_Pause �֐����g�p�����ꍇ�A
 * �{�֐��ɂ��Đ������̂��߂̃|�[�Y�ƁA ::criAtomExPlayer_Pause
 * �֐��ɂ��ꎞ��~�����̗�������������܂��B<br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y�����������~�����܂�
 * �{�֐��ōĐ��������s�����������Đ��������ꍇ�A�|�[�Y�̉�����
 * ::criAtomExPlayer_Resume �֐��i�܂��� ::criAtomExPlayback_Resume
 * �֐��j�������p���������B<br>
 * \sa criAtomExPlayback_GetStatus, criAtomExPlayback_Pause
 */
CriAtomExPlaybackId CRIAPI criAtomExPlayer_Prepare(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��̒�~
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \par ����:
 * �Đ��̒�~�v���𔭍s���܂��B<br>
 * �����Đ�����AtomEx�v���[���[�ɑ΂��Ė{�֐������s����ƁA
 * AtomEx�v���[���[�͍Đ����~�i�t�@�C���̓ǂݍ��݂�A�������~�j���A
 * �X�e�[�^�X���~��ԁi CRIATOMEXPLAYER_STATUS_STOP �j�ɑJ�ڂ��܂��B<br>
 * \par ���l:
 * ���ɒ�~���Ă���AtomEx�v���[���[�i�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYEND ��
 * CRIATOMEXPLAYER_STATUS_ERROR ��AtomEx�v���[���[�j �ɑ΂��Ė{�֐������s����ƁA
 * AtomEx�v���[���[�̃X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_STOP �ɕύX���܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł͂���܂���B<br>
 * ���̂��߁A�֐����ŏ����������ԃu���b�N���邱�Ƃ͂���܂��񂪁A
 * �֐��𔲂������_�ł͍Đ�����~���Ă��Ȃ��\��������_�ɂ����ӂ��������B<br>
 * �i��~��ԂɂȂ�܂łɁA���Ԃ�������ꍇ������܂��B�j<br>
 * ��~��ۏ؂���K�v������ꍇ�ɂ́A�{�֐��Ăяo����A
 * AtomEx�v���[���[�̃X�e�[�^�X����~��ԁiCRIATOMEXPLAYER_STATUS_STOP�j
 * �ɂȂ邱�Ƃ��m�F���Ă��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
void CRIAPI criAtomExPlayer_Stop(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��̒�~�i�����[�X�^�C�������j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \par ����:
 * �Đ��̒�~�v���𔭍s���܂��B<br>
 * ���̍ہA�Đ����̉����ɃG���x���[�v�̃����[�X�^�C�����ݒ肳��Ă����Ƃ��Ă��A
 * ����𖳎����Ē�~���܂��B<br>
 * �����Đ�����AtomEx�v���[���[�ɑ΂��Ė{�֐������s����ƁA
 * AtomEx�v���[���[�͍Đ����~�i�t�@�C���̓ǂݍ��݂�A�������~�j���A
 * �X�e�[�^�X���~��ԁi CRIATOMEXPLAYER_STATUS_STOP �j�ɑJ�ڂ��܂��B<br>
 * \par ���l:
 * ���ɒ�~���Ă���AtomEx�v���[���[�i�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYEND ��
 * CRIATOMEXPLAYER_STATUS_ERROR ��AtomEx�v���[���[�j �ɑ΂��Ė{�֐������s����ƁA
 * AtomEx�v���[���[�̃X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_STOP �ɕύX���܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł͂���܂���B<br>
 * ���̂��߁A�֐����ŏ����������ԃu���b�N���邱�Ƃ͂���܂��񂪁A
 * �֐��𔲂������_�ł͍Đ�����~���Ă��Ȃ��\��������_�ɂ����ӂ��������B<br>
 * �i��~��ԂɂȂ�܂łɁA���Ԃ�������ꍇ������܂��B�j<br>
 * ��~��ۏ؂���K�v������ꍇ�ɂ́A�{�֐��Ăяo����A
 * AtomEx�v���[���[�̃X�e�[�^�X����~��ԁiCRIATOMEXPLAYER_STATUS_STOP�j
 * �ɂȂ邱�Ƃ��m�F���Ă��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
void CRIAPI criAtomExPlayer_StopWithoutReleaseTime(CriAtomExPlayerHn player);

/*JP
 * \brief �S�Ẵv���[���[�̍Đ����~
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * �S�Ă�AtomEx�v���[���[�ɑ΂��A�Đ��̒�~�v���𔭍s���܂��B<br>
 * �{�֐������s����ƁAAtomEx�v���[���[�͍Đ����~�i�t�@�C���̓ǂݍ��݂�A�������~�j���A
 * �X�e�[�^�X���~��ԁi CRIATOMEXPLAYER_STATUS_STOP �j�ɑJ�ڂ��܂��B<br>
 * \par ���l:
 * ���ɒ�~���Ă���AtomEx�v���[���[�i�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYEND ��
 * CRIATOMEXPLAYER_STATUS_ERROR ��AtomEx�v���[���[�j �ɂ��Ă��A
 * �{�֐������s�����ƃX�e�[�^�X�� CRIATOMEXPLAYER_STATUS_STOP �ɕύX����܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł͂���܂���B<br>
 * ���̂��߁A�֐����ŏ����������ԃu���b�N���邱�Ƃ͂���܂��񂪁A
 * �֐��𔲂������_�ł͍Đ�����~���Ă��Ȃ��\��������_�ɂ����ӂ��������B<br>
 * �i��~��ԂɂȂ�܂łɁA���Ԃ�������ꍇ������܂��B�j<br>
 * ��~��ۏ؂���K�v������ꍇ�ɂ́A�{�֐��Ăяo����A
 * AtomEx�v���[���[�̃X�e�[�^�X����~��ԁiCRIATOMEXPLAYER_STATUS_STOP�j
 * �ɂȂ邱�Ƃ��m�F���Ă��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
void CRIAPI criAtomExPlayer_StopAllPlayers(void);

/*JP
 * \brief �S�Ẵv���[���[�̍Đ����~�i�����[�X�^�C�������j
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * �S�Ă�AtomEx�v���[���[�ɑ΂��A�Đ��̒�~�v���𔭍s���܂��B<br>
 * ���̍ہA�Đ����̉����ɃG���x���[�v�̃����[�X�^�C�����ݒ肳��Ă����Ƃ��Ă��A
 * ����𖳎����Ē�~���܂��B<br>
 * �{�֐������s����ƁAAtomEx�v���[���[�͍Đ����~�i�t�@�C���̓ǂݍ��݂�A�������~�j���A
 * �X�e�[�^�X���~��ԁi CRIATOMEXPLAYER_STATUS_STOP �j�ɑJ�ڂ��܂��B<br>
 * \par ���l:
 * ���ɒ�~���Ă���AtomEx�v���[���[�i�X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYEND ��
 * CRIATOMEXPLAYER_STATUS_ERROR ��AtomEx�v���[���[�j �ɂ��Ă��A
 * �{�֐������s�����ƃX�e�[�^�X�� CRIATOMEXPLAYER_STATUS_STOP �ɕύX����܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł͂���܂���B<br>
 * ���̂��߁A�֐����ŏ����������ԃu���b�N���邱�Ƃ͂���܂��񂪁A
 * �֐��𔲂������_�ł͍Đ�����~���Ă��Ȃ��\��������_�ɂ����ӂ��������B<br>
 * �i��~��ԂɂȂ�܂łɁA���Ԃ�������ꍇ������܂��B�j<br>
 * ��~��ۏ؂���K�v������ꍇ�ɂ́A�{�֐��Ăяo����A
 * AtomEx�v���[���[�̃X�e�[�^�X����~��ԁiCRIATOMEXPLAYER_STATUS_STOP�j
 * �ɂȂ邱�Ƃ��m�F���Ă��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
void CRIAPI criAtomExPlayer_StopAllPlayersWithoutReleaseTime(void);

/*JP
 * \brief �v���[���[�̗�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�v���[���[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �A�v���P�[�V�������Ŋm�ۂ����v���[���[��񋓂��܂��B<br>
 * <br>
 * �{�֐������s����ƁA�� 1 �����i func �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐���AtomEx�v���[���[�̐��������Ăяo����܂��B<br>
 * �iAtomEx�v���[���[�n���h�����A�����Ƃ��ăR�[���o�b�N�֐��ɓn����܂��B�j<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExPlayerCbFunc �̐��������Q�Ƃ��������B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExVoiceInfoCbFunc
 */
void CRIAPI criAtomExPlayer_EnumeratePlayers(CriAtomExPlayerCbFunc func, void *obj);

/*JP
 * \brief �|�[�Y�^�|�[�Y����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	sw			�X�C�b�`�iCRI_FALSE = �|�[�Y�����ACRI_TRUE = �|�[�Y�j
 * \par ����:
 * �Đ��̃|�[�Y�^�|�[�Y�������s���܂��B<br>
 * sw �� CRI_TRUE ���w�肵�Ė{�֐������s����ƁAAtomEx�v���[���[�͍Đ�����
 * �������|�[�Y�i�ꎞ��~�j���܂��B<br>
 * sw �� CRI_FALSE ���w�肵�Ė{�֐������s����ƁAAtomEx�v���[���[�̓|�[�Y��
 * �������A�ꎞ��~���Ă��������̍Đ����ĊJ���܂��B<br>
 * \par ���l:
 * �f�t�H���g��ԁi�v���[���[�쐬����̏�ԁj�ł́A�|�[�Y�͉�������Ă��܂��B<br>
 * \attention
 * ��2�����isw�j�� CRI_FALSE ���w�肵�ă|�[�Y�����̑�����s�����ꍇ�A
 * �{�֐��Ń|�[�Y�����������������łȂ��A::criAtomExPlayer_Prepare 
 * �֐��ōĐ��������̉����ɂ��Ă��Đ����J�n����Ă��܂��܂��B<br>
 * �i���o�[�W�����Ƃ̌݊����ێ��̂��߂̎d�l�ł��B�j<br>
 * �{�֐��Ń|�[�Y�������������ɂ��Ă̂݃|�[�Y�������������ꍇ�A
 * �{�֐����g�p�����A criAtomExPlayer_Resume(player, CRIATOMEX_RESUME_PAUSED_PLAYBACK);
 * �����s���ă|�[�Y�������s���Ă��������B<br>
 * <br>
 * �{�֐������s����ƁA�v���[���[�ōĐ����Ă���"�S�Ă�"�����ɑ΂��ă|�[�Y�^�|�[�Y����
 * �̏������s���܂��B<br>
 * �Đ����̌X�̉����ɑ΂��A�ʂɃ|�[�Y�^�|�[�Y�����̏������s���ꍇ�ɂ́A
 * ::criAtomExPlayback_Pause �֐��������p���������B
 * \sa criAtomExPlayer_IsPaused, criAtomExPlayback_Pause, criAtomExPlayer_Resume
 */
void CRIAPI criAtomExPlayer_Pause(CriAtomExPlayerHn player, CriBool sw);

/*JP
 * \brief �|�[�Y����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	mode		�|�[�Y�����Ώ�
 * \par ����:
 * �ꎞ��~��Ԃ̉������s���܂��B<br>
 * ::criAtomExPlayer_Pause �֐��ƈقȂ�A ::criAtomExPlayer_Prepare
 * �֐��ōĐ��J�n�҂��̉����ƁA ::criAtomExPlayer_Pause �֐��i�܂��� 
 * ::criAtomExPlayback_Pause �֐��Ń|�[�Y�������������Ƃ��A
 * �ʂɍĊJ�����邱�Ƃ��\�ł��B<br>
 * <br>
 * ��2�����imode�j�� ::CRIATOMEX_RESUME_PAUSED_PLAYBACK ���w�肵�Ė{�֐������s����ƁA
 * ���[�U�� ::criAtomExPlayer_Pause �֐��i�܂��� ::criAtomExPlayback_Pause 
 * �֐��j�ňꎞ��~��ԂɂȂ��������̍Đ����ĊJ����܂��B<br>
 * ��2�����imode�j�� ::CRIATOMEX_RESUME_PREPARED_PLAYBACK ���w�肵�Ė{�֐������s����ƁA
 * ���[�U�� ::criAtomExPlayer_Prepare �֐��ōĐ��������w�����������̍Đ����J�n����܂��B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y��Ԃ̃v���[���[�ɑ΂��� ::criAtomExPlayer_Prepare
 * �֐��ōĐ��������s�����ꍇ�A���̉����� ::CRIATOMEX_RESUME_PAUSED_PLAYBACK
 * �w��̃|�[�Y���������ƁA ::CRIATOMEX_RESUME_PREPARED_PLAYBACK
 * �w��̃|�[�Y���������̗������s����܂ŁA�Đ����J�n����܂���B<br>
 * \par ���l:
 * ::criAtomExPlayer_Pause �֐��� ::criAtomExPlayer_Prepare �֐����Ɋ֌W�Ȃ��A
 * ��ɍĐ����J�n�������ꍇ�ɂ́A��2�����imode�j�� ::CRIATOMEX_RESUME_ALL_PLAYBACK
 * ���w�肵�Ė{�֐������s���邩�A�܂��� criAtomExPlayer_Pause(player, CRI_FALSE);
 * �����s���Ă��������B<br>
 * \attention
 * �{�֐������s����ƁA�v���[���[�ōĐ����Ă���"�S�Ă�"�����ɑ΂��ă|�[�Y����
 * �̏������s���܂��B<br>
 * �Đ����̌X�̉����ɑ΂��A�ʂɃ|�[�Y�����̏������s���ꍇ�ɂ́A
 * ::criAtomExPlayback_Resume �֐��������p���������B
 * \sa criAtomExPlayback_Resume, criAtomExPlayer_Pause
 */
void CRIAPI criAtomExPlayer_Resume(CriAtomExPlayerHn player, CriAtomExResumeMode mode);

/*JP
 * \brief �|�[�Y��Ԃ̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriBool		�|�[�Y�����ǂ����iCRI_FALSE = �|�[�Y����Ă��Ȃ��ACRI_TRUE = �|�[�Y���j
 * \par ����:
 * �v���[���[���|�[�Y�����ǂ�����Ԃ��܂��B<br>
 * \attention
 * �{�֐��� CRI_TRUE ��Ԃ��̂́A�u�S�Ă̍Đ������|�[�Y���̏ꍇ�v�݂̂ł��B<br>
 * ::criAtomExPlayer_Pause �֐����s��A�Đ�ID�w��ŌX�̉����̃|�[�Y������
 * �i ::criAtomExPlayback_Pause �֐������s�j�����ꍇ�A�{�֐��� CRI_FALSE ��
 * �Ԃ��܂��B<br>
 * <br>
 * �{�֐��� ::criAtomExPlayer_Pause �֐��Ń|�[�Y���ꂽ�����ƁA
 * ::criAtomExPlayer_Prepare �֐��Ń|�[�Y���ꂽ�����Ƃ���ʂ��܂���B<br>
 * �i�|�[�Y���@�Ɋ֌W�Ȃ��A�S�Ă̍Đ������|�[�Y����Ă��邩�ǂ����݂̂𔻒肵�܂��B�j<br>
 * \sa criAtomExPlayer_Pause, criAtomExPlayback_Pause
 */
CriBool CRIAPI criAtomExPlayer_IsPaused(CriAtomExPlayerHn player);

/*JP
 * \brief �X�e�[�^�X�̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriAtomExPlayerStatus	�X�e�[�^�X
 * \par ����:
 * AtomEx�v���[���[�̃X�e�[�^�X���擾���܂��B<br>
 * �X�e�[�^�X��AtomEx�v���[���[�̍Đ���Ԃ������l�ŁA�ȉ���5�ʂ�̒l�����݂��܂��B<br>
 * -# CRIATOMEXPLAYER_STATUS_STOP
 * -# CRIATOMEXPLAYER_STATUS_PREP
 * -# CRIATOMEXPLAYER_STATUS_PLAYING
 * -# CRIATOMEXPLAYER_STATUS_PLAYEND
 * -# CRIATOMEXPLAYER_STATUS_ERROR
 * 
 * AtomEx�v���[���[���쐬�������_�ł́AAtomEx�v���[���[�̃X�e�[�^�X�͒�~���
 * �i CRIATOMEXPLAYER_STATUS_STOP �j�ł��B<br>
 * �Đ����鉹���f�[�^���Z�b�g��A::criAtomExPlayer_Start �֐������s���邱�ƂŁA
 * AtomEx�v���[���[�̃X�e�[�^�X��������ԁi CRIATOMEXPLAYER_STATUS_PREP �j�ɕύX����܂��B<br>
 * �iCRIATOMEXPLAYER_STATUS_PREP �́A�f�[�^������f�R�[�h�̊J�n��҂��Ă����Ԃł��B�j<br>
 * �Đ��̊J�n�ɏ[���ȃf�[�^���������ꂽ���_�ŁAAtomEx�v���[���[�̓X�e�[�^�X��
 * �Đ���ԁi CRIATOMEXPLAYER_STATUS_PLAYING �j�ɕύX���A�����̏o�͂��J�n���܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I����ƁAAtomEx�v���[���[�̓X�e�[�^�X���Đ��I�����
 * �i CRIATOMEXPLAYER_STATUS_PLAYEND �j�ɕύX���܂��B<br>
 * ���A�Đ����ɃG���[�����������ꍇ�ɂ́AAtomEx�v���[���[�̓X�e�[�^�X���G���[���
 * �i CRIATOMEXPLAYER_STATUS_ERROR �j�ɕύX���܂��B<br>
 * <br>
 * AtomEx�v���[���[�̃X�e�[�^�X���`�F�b�N���A�X�e�[�^�X�ɉ����ď�����؂�ւ��邱�ƂŁA
 * �����̍Đ���ԂɘA�������v���O�������쐬���邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�����̍Đ�������҂��ď�����i�߂����ꍇ�ɂ́A�ȉ��̂悤�ȃR�[�h�ɂȂ�܂��B
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer, buffer_size);
 * 	
 * 	// �Đ����鉹���f�[�^�̃t�H�[�}�b�g���w��
 * 	criAtomExPlayer_SetFormat(player, CRIATOMEX_FORMAT_ADX);
 * 	criAtomExPlayer_SetNumChannels(player, 1);
 * 	criAtomExPlayer_SetSamplingRate(player, 24000);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 	
 * 	// �Đ������҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomExPlayer_GetStatus(player);
 * 		
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMEXPLAYER_STATUS_PLAYEND) {
 * 			// �Đ��I�����̓��[�v�𔲂���
 * 			break;
 * 		}
 * 		
 * 		// �T�[�o�[�����̎��s
 * 		criAtomEx_ExecuteMain();
 * 		
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 * 		:
 * }
 * \endcode
 * \sa criAtomExPlayer_Start
 */
CriAtomExPlayerStatus CRIAPI criAtomExPlayer_GetStatus(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ����̉������̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriSint32	�Đ�����
 * \par ����:
 * �v���[���[�Ō��ݍĐ����̉����̐����擾���܂��B<br>
 * \par ���l:
 * �{�֐��́A ::criAtomExPlayer_Start �֐��ōĐ����s���A�����݂��L���ȍĐ�ID�̐���Ԃ��܂��B<br>
 * �i �g�p���̃{�C�X���̐��ł͂���܂���B�����̔g�`�f�[�^���܂ރV�[�P���X��1��Đ������ꍇ�ł��A
 * 1�ƃJ�E���g����܂��B�j<br>
 * �g�p���̃{�C�X�����擾�������ꍇ�ɂ́A ::criAtomExVoicePool_GetNumUsedVoices �֐��������p���������B<br>
 * \sa criAtomExPlayer_Start, criAtomExVoicePool_GetNumUsedVoices
 */
CriSint32 CRIAPI criAtomExPlayer_GetNumPlaybacks(CriAtomExPlayerHn player);

/*JP
 * \brief �ŏI�Đ�ID�̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriSint32	�Đ�ID
 * \par ����:
 * �v���[���[�ōŌ�ɍĐ����������̍Đ�ID���擾���܂��B<br>
 * \par ���l:
 * \sa criAtomExPlayer_Start
 */
CriAtomExPlaybackId CRIAPI criAtomExPlayer_GetLastPlaybackId(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ������̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		Sint64	�Đ������i�~���b�P�ʁj
 * \par ����:
 * AtomEx�v���[���[�ōŌ�ɍĐ����������́A�Đ��������擾���܂��B<br>
 * <br>
 * �Đ��������擾�ł����ꍇ�A�{�֐��� 0 �ȏ�̒l��Ԃ��܂��B<br>
 * �Đ��������擾�ł��Ȃ��ꍇ�i�{�C�X�̎擾�Ɏ��s�����ꍇ���j�A�{�֐��͕��l��Ԃ��܂��B<br>
 * \par ���l:
 * ����v���[���[�ŕ����̉������Đ����A�{�֐������s�����ꍇ�A�{�֐���
 * "�Ō��"�Đ����������̎�����Ԃ��܂��B<br>
 * �����̉����ɑ΂��čĐ��������`�F�b�N����K�v������ꍇ�ɂ́A
 * �Đ����鉹���̐��������v���[���[���쐬���邩�A�܂���
 * ::criAtomExPlayback_GetTime �֐��������p���������B<br>
 * <br>
 * �{�֐����Ԃ��Đ������́u�Đ��J�n�ォ��̌o�ߎ��ԁv�ł��B<br>
 * ���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����Ď����������߂邱�Ƃ͂���܂���B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ������̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΍ēx�J�E���g�A�b�v���ĊJ����܂��B�j
 * <br>
 * �{�֐��Ŏ擾�\�Ȏ����̐��x�́A�T�[�o�[�����̎��g���Ɉˑ����܂��B<br>
 * �i�����̍X�V�̓T�[�o�[�����P�ʂōs���܂��B�j<br>
 * ��萸�x�̍����������擾����K�v������ꍇ�ɂ́A�{�֐��̑����
 * ::criAtomExPlayback_GetNumPlayedSamples �֐����g�p���A
 * �Đ��ς݃T���v�������擾���Ă��������B<br>
 * \attention
 * �߂�l�̌^��CriSint64�ł����A����A32bit�ȏ�̐��x�͂���܂���B<br>
 * �Đ����������ɐ�����s���ꍇ�A��24���ōĐ��������ُ�ɂȂ�_�ɒ��ӂ��K�v�ł��B<br>
 * �i 2147483647 �~���b�𒴂������_�ŁA�Đ��������I�[�o�[�t���[���A���l�ɂȂ�܂��B�j<br>
 * <br>
 * AtomEx�v���[���[�쐬���A ::CriAtomExPlayerConfig �\���̂� updates_time ��
 * CRI_FALSE �ɐݒ肵���ꍇ�A���Y�v���[���[����Đ��������擾���邱�Ƃ͂ł��Ȃ��Ȃ�܂��B<br>
 * <br>
 * �Đ����̉���������������ɂ���ď������ꂽ�ꍇ�A
 * �Đ������̃J�E���g�A�b�v�����̎��_�Œ�~���܂��B<br>
 * �܂��A�Đ��J�n���_�Ŕ���������ɂ��{�C�X�����蓖�Ă��Ȃ������ꍇ�A
 * �{�֐��͐�����������Ԃ��܂���B<br>
 * �i���l���Ԃ�܂��B�j<br>
 * <br>
 * �h���C�u�Ń��[�h���g���C���������������A�ꎞ�I�ɉ����f�[�^�̋������r�؂ꂽ�ꍇ�ł��A
 * �Đ������̃J�E���g�A�b�v���r�؂�邱�Ƃ͂���܂���B<br>
 * �i�f�[�^������~�ɂ��Đ�����~�����ꍇ�ł��A�����͐i�ݑ����܂��B�j<br>
 * ���̂��߁A�{�֐��Ŏ擾�������������ɉf���Ƃ̓������s�����ꍇ�A
 * ���[�h���g���C�������ɓ������傫���Y����\��������܂��B<br>
 * �g�`�f�[�^�Ɖf���̓����������Ɏ��K�v������ꍇ�́A�{�֐��̑����
 * ::criAtomExPlayback_GetNumPlayedSamples �֐����g�p���A
 * �Đ��ς݃T���v�����Ƃ̓���������Ă��������B<br>
 * \sa criAtomExPlayback_GetTime, criAtomExPlayback_GetNumPlayedSamples
 */
CriSint64 CRIAPI criAtomExPlayer_GetTime(CriAtomExPlayerHn player);

/*JP
 * \brief �t�H�[�}�b�g�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	format		�t�H�[�}�b�g
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̃t�H�[�}�b�g���w�肵�܂��B<br>
 * ::criAtomExPlayer_Start �֐��ŉ������Đ������ہAAtomEx�v���[���[�͖{�֐���
 * �w�肳�ꂽ�t�H�[�}�b�g�̃f�[�^���Đ��\�ȃ{�C�X���A�{�C�X�v�[������擾���܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l��ADX�t�H�[�}�b�g�ł��B<br>
 * \par ���l:
 * �{�֐��́AACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�ɂ̂݃Z�b�g����K�v������܂��B<br>
 * �L���[���Đ�����ꍇ�A�t�H�[�}�b�g�̓L���[�V�[�g���玩���Ŏ擾����邽�߁A
 * �ʓr�{�֐������s����K�v�͂���܂���B<br>
 */
void CRIAPI criAtomExPlayer_SetFormat(
	CriAtomExPlayerHn player, CriAtomExFormat format);

/*JP
 * \brief �`�����l�����̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	num_channels	�`�����l����
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
 * ::criAtomExPlayer_Start �֐��ŉ������Đ������ہAAtomEx�v���[���[�͖{�֐���
 * �w�肳�ꂽ�`�����l�����̃f�[�^���Đ��\�ȃ{�C�X���A�{�C�X�v�[������擾���܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l��2�`�����l���ł��B<br>
 * \par ���l:
 * �{�֐��́AACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�ɂ̂݃Z�b�g����K�v������܂��B<br>
 * �L���[���Đ�����ꍇ�A�t�H�[�}�b�g�̓L���[�V�[�g���玩���Ŏ擾����邽�߁A
 * �ʓr�{�֐������s����K�v�͂���܂���B<br>
 */
void CRIAPI criAtomExPlayer_SetNumChannels(
	CriAtomExPlayerHn player, CriSint32 num_channels);

/*JP
 * \brief �T���v�����O���[�g�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	sampling_rate	�T���v�����O���[�g
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
 * ::criAtomExPlayer_Start �֐��ŉ������Đ������ہAAtomEx�v���[���[�͖{�֐���
 * �w�肳�ꂽ�T���v�����O���[�g�̃f�[�^���Đ��\�ȃ{�C�X���A�{�C�X�v�[������擾���܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l�� CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE �ł��B<br>
 * \par ���l:
 * �{�֐��́AACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�ɂ̂݃Z�b�g����K�v������܂��B<br>
 * �L���[���Đ�����ꍇ�A�t�H�[�}�b�g�̓L���[�V�[�g���玩���Ŏ擾����邽�߁A
 * �ʓr�{�֐������s����K�v�͂���܂���B<br>
 */
void CRIAPI criAtomExPlayer_SetSamplingRate(
	CriAtomExPlayerHn player, CriSint32 sampling_rate);

/*JP
 * \brief �T�E���h�����_���^�C�v�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	type		�T�E���h�����_���^�C�v
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���̏o�͐�T�E���h�����_�����w�肵�܂��B<br>
 * ::criAtomExPlayer_Start �֐��ŉ������Đ������ہAAtomEx�v���[���[�͖{�֐���
 * �w�肳�ꂽ�T�E���h�����_������o�͂���{�C�X���A�{�C�X�v�[������擾���܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l�� ::CRIATOM_SOUND_RENDERER_ANY �ł��B<br>
 * \par ���l:
 * ::CRIATOM_SOUND_RENDERER_ANY ���w�肵���ꍇ�A�v���[���[�̓{�C�X�̏o�͐�Ɋ֌W�Ȃ��A
 * �ŏ��Ɍ��������{�C�X�v�[�����g�p���Ĕ������s���܂��B<br>
 * \sa CriAtomSoundRendererType
 */
void CRIAPI criAtomExPlayer_SetSoundRendererType(
	CriAtomExPlayerHn player, CriAtomSoundRendererType type);

/*JP
 * \brief �O���[�v�ԍ��̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	group_no	�O���[�v�ԍ�
 * \par ����:
 * �������Ƀ{�C�X���ǂ̃{�C�X���~�b�g�O���[�v����擾���邩���w�肵�܂��B<br>
 * group_no �� ::CRIATOMEXPLAYER_NO_GROUP_LIMITATION ���w�肵���ꍇ�A
 * �v���[���[�̓{�C�X���~�b�g�O���[�v�ɂ�鐧�����󂯂Ȃ��Ȃ�܂��B<br>
 * �i�󂫃{�C�X�����邩�A�܂��͎��g����v���C�I���e�B�̃{�C�X������΁A
 * �{�C�X���~�b�g�O���[�v�Ɋ֌W�Ȃ��{�C�X���擾���܂��B�j<br>
 * \par ���l:
 * ::criAtomExPlayer_Start �֐��ōĐ����J�n�����ہA
 * �w�肵���{�C�X���~�b�g�O���[�v�̃{�C�X���S�Ďg�p���������ꍇ�A
 * �Đ�������������������邩�ǂ����́A�{�C�X�v���C�I���e�B����ɂ���Č��܂�܂��B<br>
 * �i�{�C�X�v���C�I���e�B�̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * <br>
 * �L���[�Đ����ɖ{�֐����Ăяo���ƁA�f�[�^���ɐݒ肳��Ă���{�C�X���~�b�g�O���[�v�ݒ��<b>�㏑��</b>���܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * �������Agroup_no �� ::CRIATOMEXPLAYER_NO_GROUP_LIMITATION ���w�肵���ꍇ�̓f�[�^���ɐݒ肳��Ă���{�C�X���~�b�g�O���[�v���Q�Ƃ��܂��B
 * \sa CRIATOMEXPLAYER_NO_GROUP_LIMITATION, criAtomExPlayer_Start, criAtomExPlayer_SetVoicePriority, criAtomExPlayer_SetVoiceControlMethod
 */
void CRIAPI criAtomExPlayer_SetGroupNumber(
	CriAtomExPlayerHn player, CriSint32 group_no);

/*JP
 * \brief �{�C�X������@�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	method		�{�C�X������@
 * \par ����:
 * AtomEx�v���[���[�Ƀ{�C�X������@��ݒ肵�܂��B<br>
 * �{�֐��Ń{�C�X������@���Z�b�g��A ::criAtomExPlayer_Start �֐��ŉ������Đ�����ƁA
 * ���Y�v���[���[�ōĐ�����g�`�f�[�^�ɂ́A�{�֐��Ŏw�肵������������K�p����܂��B<br>
 * <br>
 * �{�C�X������@�i method �j�ɂ́A�ȉ��̂����ꂩ���w��\�ł��B<br>
 * - CRIATOMEX_PREFER_LAST
 * - CRIATOMEX_PREFER_FIRST
 * - CRIATOMEX_PREFER_DATA
 * 
 * <br>
 * �󂫃{�C�X���Ȃ���ԂōĐ����̃{�C�X�Ɠ��v���C�I���e�B�̉������Đ������ꍇ�A
 * �{�C�X��������� CRIATOMEX_PREFER_LAST ���w�肳��Ă���΁A
 * �Đ����̃{�C�X���~���ĐV�K�ɉ����̍Đ����J�n���܂��B<br>
 * �������� CRIATOMEX_PREFER_FIRST ���w�肳��Ă���ꍇ�A
 * �V�K�̍Đ����N�G�X�g���L�����Z������A�����̃{�C�X���Đ��𑱂��܂��B<br>
 * <br>
 * CRIATOMEX_PREFER_DATA ���w�肳��Ă���ꍇ�A
 * �f�[�^�ɂ��炩���ߐݒ肳��Ă���{�C�X��������i�I�[�T�����O�c�[����Őݒ肵���l�j
 * ���g�p����܂��B<br>
 * CRIATOMEX_PREFER_DATA ���w�肵�Ă���ɂ�������炸�A�P�̃t�@�C���Đ����A
 * �f�[�^�Ƀ{�C�X����������ݒ肳��Ă��Ȃ��ꍇ�A
 * �㒅�D��i CRIATOMEX_PREFER_LAST �j�Ń{�C�X�����䂳��܂��B<br>
 * <br>
 * �֐����s�O�̃f�t�H���g�ݒ�l�̓f�[�^�ˑ��i CRIATOMEX_PREFER_DATA �j�ł��B<br>
 * \par ���l:
 * AtomEx�v���[���[���g�`�f�[�^���Đ����悤�Ƃ����ہA
 * ���Y�g�`�f�[�^����������{�C�X���~�b�g�O���[�v�̔�����������ɒB���Ă����ꍇ��A
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * <br>
 * �{�֐��ŃZ�b�g�����{�C�X��������́A��������̍ہA
 * �Đ����悤�Ƃ����g�`�f�[�^�̃v���C�I���e�B�ƁA
 * �Đ����̔g�`�f�[�^�̃v���C�I���e�B�����v���C�I���e�B�ł������ꍇ�ɍl������܂��B<br>
 * �i�{�C�X�v���C�I���e�B�ɂ�锭������̏ڍׂ� ::criAtomExPlayer_SetVoicePriority 
 * �֐��̐��������Q�Ƃ��������B�j<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_SetVoicePriority
 */
void CRIAPI criAtomExPlayer_SetVoiceControlMethod(
	CriAtomExPlayerHn player, CriAtomExVoiceControlMethod method);

/*JP
 * \brief �{�C�X�v�[�����ʎq�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	identifier	�{�C�X�v�[�����ʎq
 * \par ����:
 * �������Ƀ{�C�X���ǂ̃{�C�X�v�[������擾���邩���w�肵�܂��B<br>
 * �{�֐������s����ƁA�v���[���[�͈ȍ~�w�肳�ꂽ�{�C�X�v�[�����ʎq�Ɉ�v����
 * �{�C�X�v�[������̂݃{�C�X���擾���܂��B<br>
 * \par ���l:
 * �{�C�X�v�[�����ʎq�̃f�t�H���g�l�� 0 �ł��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa CriAtomExStandardVoicePoolConfig, criAtomExVoicePool_AllocateStandardVoicePool, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetVoicePoolIdentifier(
	CriAtomExPlayerHn player, CriAtomExVoicePoolIdentifier identifier);

/*JP
 * \brief HCA�f�R�[�h��~�L�TID�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	mixer_id	�~�L�TID
 * \par ����:
 * HCA-MX�̃f�R�[�h��~�L�TID���w�肵�܂��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �{�֐��� HCA-MX �{�C�X���g�p����ꍇ�ɂ̂݌��ʂ�����܂��B<br>
 * �i���̃{�C�X���g�p����ꍇ�A�{�֐��̐ݒ�l�͖�������܂��B�j<br>
 * <br>
 * �~�L�TID�͍Đ��J�n�O�ɐݒ肷��K�v������܂��B<br>
 * ���ɍĐ����J�n���ꂽ�����ɑ΂��A�ォ��~�L�TID��ύX���邱�Ƃ͂ł��܂���B<br>
 * \sa CriAtomExHcaMxVoicePoolConfig, criAtomExVoicePool_AllocateHcaMxVoicePool, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetHcaMxMixerId(CriAtomExPlayerHn player, CriSint32 mixer_id);

/*JP
 * \brief ASR���b�NID�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	rack_id		ASR���b�NID
 * \par ����:
 * �{�C�X�̏o�͐�ASR���b�NID���w�肵�܂��B<br>
 * ������ASR���b�NID���w�肵�����ꍇ�A ::criAtomExPlayer_SetAsrRackIdArray �֐����g�p���Ă��������B
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B<br>
 * <br>
 * �L���[�Đ����ɖ{�֐����Ăяo���ƁA�f�[�^���ɐݒ肳��Ă���p�����[�^�[�p���b�g��ASR���b�NID�ݒ��<b>�㏑��</b>���܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B
 * \attention
 * �{�֐��� �{�C�X�̃T�E���h�����_���^�C�v��ASR���g�p����ꍇ�ɂ̂݌��ʂ�����܂��B<br>
 * �i���̃{�C�X���g�p����ꍇ�A�{�֐��̐ݒ�l�͖�������܂��B�j<br>
 * <br>
 * ASR���b�NID�͍Đ��J�n�O�ɐݒ肷��K�v������܂��B<br>
 * ���ɍĐ����J�n���ꂽ�����ɑ΂��A�ォ��ASR���b�NID��ύX���邱�Ƃ͂ł��܂���B<br>
 * <br>
 *  ::criAtomExPlayer_SetAsrRackIdArray �֐����s��ɖ{�֐������s����ƁA ::criAtomExPlayer_SetAsrRackIdArray �֐��ɂ�
 * �ݒ肵��������ASR���b�NID�ݒ�͏㏑������܂��B<br>
 * <br>
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�ɂ́A�{�֐��̐ݒ肪�K�p����܂���B<br>
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�ɂ��ďo�͐�ASR���b�NID��ݒ肷��ꍇ�A
 * ::criAtomExHcaMx_SetAsrRackId �֐����g�p���āAHCA-MX�~�L�T���̂̏o�͐�ASR���b�NID��ݒ肵�Ă��������B<br>
 * \sa criAtomExAsr_CreateRack, criAtomExPlayer_SetAsrRackIdArray, criAtomExHcaMx_SetAsrRackId, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetAsrRackId(CriAtomExPlayerHn player, CriSint32 rack_id);

/*JP
 * \brief ������ASR���b�NID�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	rack_id_array	ASR���b�NID�̔z��
 * \param[in]	num_racks		ASR���b�NID�w�萔
 * \par ����:
 * �{�C�X�̏o�͐�ASR���b�NID�𕡐��w�肵�܂��B<br>
 * ::CRIATOMEXPLAYER_MAX_ASR_RACKS �ɒ�`���ꂽ������ASR���b�NID���w�肷�邱�Ƃ��\�ł��B<br>
 * �P���ASR���b�NID���w�肷��ꍇ�́A ::criAtomExPlayer_SetAsrRackId �֐����g�p���邱�Ƃł��w��\�ł��B
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B<br>
 * <br>
 * �L���[�Đ����ɖ{�֐����Ăяo���ƁA�f�[�^���ɐݒ肳��Ă���p�����[�^�[�p���b�g��ASR���b�NID�ݒ��<b>�㏑��</b>���܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B
 * \attention
 * �{�֐��� �{�C�X�̃T�E���h�����_���^�C�v��ASR���g�p����ꍇ�ɂ̂݌��ʂ�����܂��B<br>
 * �i���̃{�C�X���g�p����ꍇ�A�{�֐��̐ݒ�l�͖�������܂��B�j<br>
 * <br>
 * ASR���b�NID�͍Đ��J�n�O�ɐݒ肷��K�v������܂��B<br>
 * ���ɍĐ����J�n���ꂽ�����ɑ΂��A�ォ��ASR���b�NID��ύX���邱�Ƃ͂ł��܂���B<br>
 * <br>
 * ������ASR���b�NID���w�肵���v���[���[���Đ������ꍇ�A�{�C�X�͂��̎w�肳�ꂽASR���b�NID�̐������g�p����܂��B<br>
 * ���̂��߁A���O�Ɏw�肷��ASR���b�NID�����̃{�C�X���m�ۂ��Ă����K�v������܂��B<br>
 * <br>
 * ::criAtomExPlayer_SetData �֐������g�p�����L���[�Đ��ȊO�̍Đ����ł́A�{�֐��ɂĎw�肵��������ASR���b�NID�̓��A
 * 1�ځi�z��̃C���f�b�N�X��0�j�̗v�f�Ɋi�[����Ă���ASR���b�NID�݂̂��K�p����܂��B<br>
 * <br>
 *  ::criAtomExPlayer_SetAsrRackId �֐����s��ɖ{�֐������s����ƁA ::criAtomExPlayer_SetAsrRackId �֐��ɂ�
 * �ݒ肵��ASR���b�NID�ݒ�͏㏑������܂��B<br>
 * <br>
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�ɂ́A�{�֐��̐ݒ肪�K�p����܂���B<br>
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�ɂ��ďo�͐�ASR���b�NID��ݒ肷��ꍇ�A
 * ::criAtomExHcaMx_SetAsrRackId �֐����g�p���āAHCA-MX�~�L�T���̂̏o�͐�ASR���b�NID��ݒ肵�Ă��������B<br>
 * \sa criAtomExAsr_CreateRack, criAtomExPlayer_SetAsrRackId, criAtomExHcaMx_SetAsrRackId, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetAsrRackIdArray(
	CriAtomExPlayerHn player, const CriSint32 *rack_id_array, CriSint32 num_racks);

/*JP
 * \brief �Đ��J�n�ʒu�̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	start_time_ms	�Đ��J�n�ʒu�i�~���b�w��j
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹���ɂ��āA�Đ����J�n����ʒu���w�肵�܂��B<br>
 * �����f�[�^��r������Đ��������ꍇ�A�Đ��J�n�O�ɖ{�֐��ōĐ��J�n�ʒu��
 * �w�肷��K�v������܂��B<br>
 * <br>
 * �Đ��J�n�ʒu�̎w��̓~���b�P�ʂōs���܂��B<br>
 * �Ⴆ�΁A start_time_ms �� 10000 ���Z�b�g���Ė{�֐������s����ƁA
 * ���ɍĐ����鉹���f�[�^�� 10 �b�ڂ̈ʒu����Đ�����܂��B
 * \par ���l:
 * �����f�[�^�r������̍Đ��́A�����f�[�^�擪����̍Đ��ɔ�ׁA�����J�n��
 * �^�C�~���O���x���Ȃ�܂��B<br>
 * ����́A��U�����f�[�^�̃w�b�_�[����͌�A�w��ʒu�ɃW�����v���Ă���f�[�^��ǂ�
 * �����čĐ����J�n���邽�߂ł��B<br>
 * \attention
 * start_time_ms �ɂ�64bit�l���Z�b�g�\�ł����A����A32bit�ȏ�̍Đ�������
 * �w�肷�邱�Ƃ͂ł��܂���B<br>
 * <br>
 * �@��ŗL�̉����t�H�[�}�b�g�ɂ��Ă��A�Đ��J�n�ʒu���w��ł��Ȃ��ꍇ������܂��B<br>
 * <br>
 * �Đ��J�n�ʒu���w�肵�ăV�[�P���X���Đ������ꍇ�A�w��ʒu�����O�ɔz�u���ꂽ
 * �g�`�f�[�^�͍Đ�����܂���B<br>
 * �i�V�[�P���X���̌X�̔g�`���r������Đ�����邱�Ƃ͂���܂���B�j<br>
 */
void CRIAPI criAtomExPlayer_SetStartTime(
	CriAtomExPlayerHn player, CriSint64 start_time_ms);

/*JP
 * \brief �����Đ�ID�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	playback_id	�����ΏۂƂȂ�Đ�ID
 * \par ����:
 * AtomEx�v���[���[�ōĐ����鉹�����A�w�肵���Đ�ID�̉����ɓ��������܂��B<br>
 * �{�֐��ōĐ�ID��ݒ��ɉ������Đ�����ƁA
 * ���̉����͎w�肳�ꂽ�Đ�ID�Ɠ����Đ��ʒu�ɃV�[�N���čĐ����n�߂܂��B<br>
 * \par ���l:
 * �����Ώۂ̍Đ�ID�������ȏꍇ�A�����f�[�^�̐擪����Đ����J�n����܂��B<br>
 * playback_id �� CRIATOMEX_INVALID_PLAYBACK_ID ���w�肷��ƁA
 * �Đ�ID�̓o�^���N���A����܂��B<br>
 * \attention
 * �{�֐��́A�P�̂̔g�`�f�[�^���Đ�����ꍇ�ɂ̂ݗ��p�\�ł��B<br>
 * �V�[�P���X�f�[�^�ɂ͗��p�ł��܂���B<br>
 * �i�V�[�P���X�f�[�^�ɑ΂��Ďg�p�����ꍇ�A
 * �V�[�P���X���ōŏ��Ɍ��������g�`�f�[�^�ɑ΂��ē����������s���Ă��܂��܂��B�j<br>
 * <br>
 * �{�֐��ōĐ��ʒu�𒲐��\�ȃR�[�f�b�N�́A�ȉ��̃R�[�f�b�N�݂̂ł��B<br>
 * 	- ADX
 * 	- HCA
 * 	- Wave
 * 	
 * <br>
 * ���̃R�[�f�b�N�ɂ��ẮA�{�֐���p���������Đ��͍s���܂���B<br>
 * �iHCA-MX��A�n�[�h�E�F�A�f�R�[�h���s�������R�[�f�b�N�ł́A�{�@�\�͗��p�ł��܂���B�j<br>
 * <br>
 * �{�@�\�ɂ��Đ��ʒu�̓����́A�\�Ȍ���T���v���P�ʂōs���܂����A
 * 1�T���v���̌덷�Ȃ��������邱�Ƃ�ۏ؂�����̂ł͂���܂���B<br>
 * �i�~���b���x���̃Y�������e�����ꍇ�ɂ݂̂����p���������B�j<br>
 * �܂��A�Đ��ʒu�̓������x�́A�v���b�g�t�H�[���ɂ���Ă��قȂ�܂��B<br>
 * <br>
 * �{�֐��� ::criAtomExPlayer_SetStartTime �֐��𕹗p���邱�Ƃ͂ł��܂���B<br>
 * �{�ւ��g�p�����ꍇ�A�����̍Đ��J�n�ʒu�̓��C�u�������Ŏ����I�ɒ�������܂��B<br>
 * ���̂��߁A�{�֐��� ::criAtomExPlayer_SetStartTime �֐��𕹗p���邱�Ƃ͂ł��܂���B<br>
 * �i ::criAtomExPlayer_SetStartTime �֐��̐ݒ�͖�������܂��B�j<br>
 * <br>
 * �{�֐����g�p���čĐ����s�����ꍇ�A�Đ��J�n���Ƀm�C�Y������ꍇ������܂��B<br>
 * �{�@�\���g�p����ꍇ�A�\�Ȍ���t�F�[�h�C�������𕹗p���Ă��������B<br>
 * <br>
 * �{�֐����g�p���ăL���[�Đ����s�����ꍇ�A ::criAtomExPlayer_GetTime �֐���
 * ::criAtomExPlayback_GetTime �֐��ɂ��Đ������̎擾�͐������s���܂���B<br>
 * �Đ������̊m�F�ɂ́A�����̊֐��̑���ɁA ::criAtomExPlayback_GetNumPlayedSamples
 * �֐��������p���������B<br>
 * \sa criAtomExPlayback_GetNumPlayedSamples
 */
void CRIAPI criAtomExPlayer_SetSyncPlaybackId(
	CriAtomExPlayerHn player, CriAtomExPlaybackId playback_id);

/*JP
 * \brief �V�[�P���X�Đ����V�I�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	playback_ratio	�V�[�P���X�Đ����V�I
 * \par ����:
 * AtomEx�v���[���[�ōĐ�����V�[�P���X�̍Đ����V�I��ݒ肵�܂��B<br>
 * �Đ����V�I�̐ݒ�͈͂� 0.0f �` 2.0f �ł��B<br>
 * �͈͊O�̒l��ݒ肵���ꍇ�́A�����l�������͏���l���ݒ肳��܂��B
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �{�֐��ɂ��ݒ�l�́A�V�[�P���X�^�C�v�̃L���[���Đ�����ꍇ�ɂ̂ݓK�p����܂��B<br>
 * �V�[�P���X�ɂĔ�������g�`�f�[�^�̍Đ����V�I�ɂ͗��p�ł��܂���B<br>
 * \sa criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPlaybackRatio(
	CriAtomExPlayerHn player, CriFloat32 playback_ratio);

/*JP
 * \brief ���[�v�񐔂̐���
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	count		���[�v������
 * \par ����:
 * �g�`�f�[�^�̃��[�v�Đ��񐔂𐧌����܂��B<br>
 * �Ⴆ�΁Acount��1���w�肵���ꍇ�A���[�v�g�`�f�[�^��1��̂݃��[�v���čĐ����I�����܂��B<br>
 * �i���[�v�G���h�|�C���g�ɓ��B��A1�񂾂����[�v�X�^�[�g�ʒu�ɖ߂�܂��B�j<br>
 * \par ���l:
 * �f�t�H���g��Ԃł́A���[�v�|�C���g�t���̉����f�[�^�͖����Ƀ��[�v�Đ�����܂��B<br>
 * ���[�v�񐔂���U����������A���[�v�񐔂��ēx������ɖ߂������ꍇ�ɂ́A
 * count �� ::CRIATOMEXPLAYER_NO_LOOP_LIMITATION ���w�肵�Ă��������B<br>
 * <br>
 * count �� ::CRIATOMEXPLAYER_IGNORE_LOOP ���w�肷�邱�ƂŁA
 * ���[�v�|�C���g�t���̉����f�[�^�����[�v�������ɍĐ����邱�Ƃ��\�ł��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * ���[�v�����񐔂̎w��́A�����Đ��J�n�O�ɍs���K�v������܂��B<br>
 * �Đ����ɖ{�֐������s���Ă��A���[�v�񐔂͕ύX����܂���B<br>
 * �Đ����̔C�ӂ̃^�C�~���O�Ń��[�v�Đ����~�������ꍇ�A
 * ���[�v�Đ��ł͂Ȃ��A�V�[�����X�A���Đ��Ő�����s���Ă��������B<br>
 * <br>
 * �{�֐��Ŏw�肵�����[�v�����񐔂́A
 * ���炩���߃��[�v�|�C���g���ݒ肳�ꂽ�g�`�f�[�^���Đ�����ꍇ�ɂ̂ݓK�p����܂��B<br>
 * �g�`�f�[�^���̂Ƀ��[�v�|�C���g���ݒ肳��Ă��Ȃ��ꍇ�A
 * �{�֐������s���Ă����̌��ʂ�����܂���B<br>
 * <br>
 * �{�֐����g�p���ă��[�v�񐔂��w�肵���ꍇ�ł��A
 * ���[�v�I�����Ƀ��[�v�G���h�|�C���g�ȍ~�̔g�`�f�[�^���Đ�����邱�Ƃ͂���܂���B<br>
 * �i�w��񐔕����[�v������A���[�v�G���h�|�C���g�ōĐ�����~���܂��B�j<br>
 * <br>
 * ��O�I�ɁA�ȉ��̏����𖞂����ꍇ�Ɍ���A�i���[�v�͂���܂��񂪁j
 * �����V���b�g�Ń��[�v�|�C���g�ȍ~�̃f�[�^���܂߂čĐ����邱�Ƃ��\�ł��B<br>
 * 	- criatomencd.exe �� -nodelterm ���w�肵�ăf�[�^���G���R�[�h����B
 * 	- �{�֐��� ::CRIATOMEXPLAYER_IGNORE_LOOP ���w�肵�Ă���Đ����s���B
 * 	
 * <br>
 * �{�֐��Ń��[�v�񐔂𐧌��ł���̂́AADX�R�[�f�b�N��HCA�R�[�f�b�N�݂̂ł��B<br>
 * �v���b�g�t�H�[���ˑ��̉����R�[�f�b�N�ɑ΂��Ė{�֐������s���Ȃ��ł��������B<br>
 * �i�Đ����I�����Ȃ��A�m�C�Y���������铙�̖�肪�������܂��B�j<br>
 * \sa criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_LimitLoopCount(CriAtomExPlayerHn player, CriSint32 count);

/*JP
 * \brief �Đ��p�����[�^�[�̍X�V�i�Đ����̉��S�āj
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���Đ��p�����[�^�[�iAISAC�R���g���[���l���܂ށj���g�p���āA
 * ����AtomEx�v���[���[�ōĐ����̉��S�Ă̍Đ��p�����[�^�[���X�V���܂��B<br>
 * \par ��:
 * \code
 * CriFloat32 volume;
 * // Start playback
 * criAtomExPlayer_Start(player);
 *                :
 * criAtomExPlayer_Start(player);
 *                :
 * // Change Volume
 * volume = 0.3f;
 * criAtomExPlayer_SetVolume(player, volume);
 * criAtomExPlayer_UpdateAll(player);
 * \endcode
 * \sa criAtomExPlayer_Update
 */
void CRIAPI criAtomExPlayer_UpdateAll(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��p�����[�^�[�̍X�V�i�Đ�ID�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	id			�Đ�ID
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���Đ��p�����[�^�[�iAISAC�R���g���[���l���܂ށj���g�p���āA
 * �Đ�ID�ɂ���Ďw�肳�ꂽ�����̍Đ��p�����[�^�[���X�V���܂��B<br>
 * \par ��:
 * \code
 * CriFloat32 volume;
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Change Volume
 * volume = 0.3f;
 * criAtomExPlayer_SetVolume(player, volume);
 * criAtomExPlayer_Update(player, id);
 * \endcode
 * \par ���l:
 * �Đ�ID�́A����AtomEx�v���[���[�ōĐ����ꂽ�������w���Ă���K�v������܂��B<br>
 * \sa criAtomExPlayer_UpdateAll
 */
void CRIAPI criAtomExPlayer_Update(
	CriAtomExPlayerHn player, CriAtomExPlaybackId id);

/*JP
 * \brief �Đ��p�����[�^�[�̏�����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���Đ��p�����[�^�[�iAISAC�R���g���[���l���܂ށj�����Z�b�g���A������ԁi���ݒ��ԁj�ɖ߂��܂��B<br>
 * �{�֐��Ăяo����A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA������Ԃ̍Đ��p�����[�^�[�ōĐ�����܂��B<br>
 * \par ��:
 * \code
 * CriFloat32 volume;
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Change Volume
 * volume = 0.3f;
 * criAtomExPlayer_SetVolume(player, volume);
 * criAtomExPlayer_Update(player, id);
 *                :
 * // Reset Parameters
 * criAtomExPlayer_ResetParameters(player);
 * id = criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �{�֐��Ăяo����A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃ��Ă��A���łɍĐ�����Ă��鉹���̃p�����[�^�[�͏����l�ɂ͖߂�܂���B<br>
 * ���łɍĐ�����Ă��鉹���̃p�����[�^�[��ς���ꍇ�́A�����I��::criAtomExPlayer_SetVolume �֐������Ăяo���Ă��������B<br>
 * <br>
 * �{�֐��Ń��Z�b�g�����p�����[�^�[�́A�e�p�����[�^�[�̐ݒ���s���֐��ɑΏۂ��ǂ������L�ڂ��Ă��邽�߁A��������Q�Ƃ��ĉ������B<br>
 * <br>
 * �Ȃ��A�{�֐��ł�3D�����n���h����3D���X�i�[�n���h�����̂̂��p�����[�^�[�i�ʒu���j�̓��Z�b�g����܂���B�uAtomEx�v���[���[�ɐݒ肳��Ă���n���h���������v�Ƃ����ݒ肾�������Z�b�g����܂��B
 * �����̃n���h�����̂̃p�����[�^�[�����Z�b�g�������ꍇ�ɂ́A���ꂼ��̃n���h���̃p�����[�^�[���Z�b�g�֐����Ăяo���Ă��������B
 * \sa criAtomEx3dSource_ResetParameters, criAtomEx3dListener_ResetParameters
 */
void CRIAPI criAtomExPlayer_ResetParameters(CriAtomExPlayerHn player);

/*JP
 * \brief �p�����[�^�[�̎擾�i���������_���j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	id		�p�����[�^�[ID
 * \return		�p�����[�^�[�ݒ�l
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕��������_���Ŏ擾����܂��B
 * \sa CriAtomExParameterId, criAtomExPlayer_GetParameterUint32, criAtomExPlayer_GetParameterSint32
 */
CriFloat32 CRIAPI criAtomExPlayer_GetParameterFloat32(CriAtomExPlayerHn player, CriAtomExParameterId id);

/*JP
 * \brief �p�����[�^�[�̎擾�i�����Ȃ������j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	id		�p�����[�^�[ID
 * \return		�p�����[�^�[�ݒ�l
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕����Ȃ������Ŏ擾����܂��B
 * \sa CriAtomExParameterId, criAtomExPlayer_GetParameterFloat32, criAtomExPlayer_GetParameterSint32
 */
CriUint32 CRIAPI criAtomExPlayer_GetParameterUint32(CriAtomExPlayerHn player, CriAtomExParameterId id);

/*JP
 * \brief �p�����[�^�[�̎擾�i�����t�������j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	id		�p�����[�^�[ID
 * \return		�p�����[�^�[�ݒ�l
 * \par ����:
 * AtomEx�v���[���[�ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕����t�������Ŏ擾����܂��B
 * \sa CriAtomExParameterId, criAtomExPlayer_GetParameterFloat32, criAtomExPlayer_GetParameterUint32
 */
CriSint32 CRIAPI criAtomExPlayer_GetParameterSint32(CriAtomExPlayerHn player, CriAtomExParameterId id);

/*JP
 * \brief �{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	volume		�{�����[���l
 * \par ����:
 * �o�͉����̃{�����[�����w�肵�܂��B<br>
 * �{�֐��Ń{�����[����ݒ��A::criAtomExPlayer_Start �֐��ōĐ����J�n����ƁA
 * �ݒ肳�ꂽ�{�����[���ŉ������Đ�����܂��B<br>
 * �܂��{�����[���ݒ��� ::criAtomExPlayer_Update �֐��� ::criAtomExPlayer_UpdateAll 
 * �֐����Ăяo�����ƂŁA���łɍĐ����ꂽ�����̃{�����[�����X�V���邱�Ƃ��\�ł��B<br>
 * <br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * �{�����[���̃f�t�H���g�l��1.0f�ł��B<br>
 * \par ��:
 * \code
 * 	�F
 * // �{�����[���̐ݒ�
 * criAtomExPlayer_SetVolume(player, 0.5f);
 * 
 * // �Đ��̊J�n
 * // ���l�j�{�����[���̓v���[���[�ɐݒ肳�ꂽ�l�i��0.5f�j�ōĐ������B
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �{�����[���̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃{�����[���͕ύX����Ȃ��B
 * criAtomExPlayer_SetVolume(player, 0.3f);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�{�����[�����Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �{�����[���l�ɂ�0.0f�ȏ�̒l���ݒ�\�ł��B<br>
 * �iAtom���C�u���� Ver.1.21.07���A
 * �{�����[���l��1.0f�𒴂���l���w��ł���悤�ɂȂ�܂����B�j<br>
 * 1.0f�𒴂���l���Z�b�g�����ꍇ�A<b>�v���b�g�t�H�[���ɂ���Ă�</b>�A
 * �g�`�f�[�^�����f�ނ����傫�ȉ��ʂōĐ��\�ł��B<br>
 * �{�����[���l��0.0f�����̒l���w�肵���ꍇ�A�l��0.0f�ɃN���b�v����܂��B<br>
 * �i�{�����[���l�ɕ��̒l��ݒ肵���ꍇ�ł��A
 * �g�`�f�[�^�̈ʑ������]����邱�Ƃ͂���܂���B�j<br>
 * <br>
 * �L���[�Đ����A�f�[�^���Ƀ{�����[�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>��Z</b>�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃{�����[����0.8f�AAtomEx�v���[���[�̃{�����[����0.5f�̏ꍇ�A
 * ���ۂɓK�p�����{�����[����0.4f�ɂȂ�܂��B<br>
 * <br>
 * �f�V�x���Őݒ肵�����ꍇ�A�ȉ��̌v�Z���ŕϊ����Ă���ݒ肵�Ă��������B<br>
 * \code
 * volume = powf(10.0f, db_vol / 20.0f);
 * \endcode
 * ��db_vol���f�V�x���l�Avolume���{�����[���l�ł��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * 1.0f�𒴂���{�����[�����w�肷��ꍇ�A�ȉ��̓_�ɒ��ӂ���K�v������܂��B<br>
 *  - �v���b�g�t�H�[�����Ƃɋ������قȂ�\��������B
 *  - �����ꂪ��������\��������B
 * 	
 * <br>
 * �{�֐���1.0f�𒴂���{�����[���l��ݒ肵���ꍇ�ł��A
 * ���������̔g�`�f�[�^�����傫�ȉ��ʂōĐ�����邩�ǂ����́A
 * �v���b�g�t�H�[���≹�����k�R�[�f�b�N�̎�ʂɂ���ĈقȂ�܂��B<br>
 * ���̂��߁A�}���`�v���b�g�t�H�[���^�C�g���Ń{�����[���𒲐�����ꍇ�ɂ́A
 * 1.0f�𒴂���{�����[���l���g�p���Ȃ����Ƃ��������߂��܂��B<br>
 * �i1.0f�𒴂���{�����[���l���w�肵���ꍇ�A�����g�`�f�[�^���Đ������ꍇ�ł��A
 * �@�킲�ƂɈقȂ鉹�ʂŏo�͂����\��������܂��B�j<br>
 * <br>
 * �܂��A���ʂ��グ�邱�Ƃ��\�ȋ@��ł����Ă��A
 * �n�[�h�E�F�A�ŏo�͉\�ȉ��ʂɂ͏�������邽�߁A
 * ������ɂ��m�C�Y����������\��������܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetVolume(
	CriAtomExPlayerHn player, CriFloat32 volume);

/*JP
 * \brief �s�b�`�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	pitch		�s�b�`�i�Z���g�P�ʁj
 * \par ����:
 * �o�͉����̃s�b�`���w�肵�܂��B<br>
 * �{�֐��Ńs�b�`��ݒ��A::criAtomExPlayer_Start �֐��ōĐ����J�n����ƁA
 * �ݒ肳�ꂽ�s�b�`�ŉ������Đ�����܂��B<br>
 * �܂��s�b�`��� ::criAtomExPlayer_Update �֐��� ::criAtomExPlayer_UpdateAll 
 * �֐����Ăяo�����Ƃɂ��A���łɍĐ����ꂽ�����̃s�b�`���X�V���邱�Ƃ��\�ł��B<br>
 * <br>
 * �s�b�`�̓Z���g�P�ʂŎw�肵�܂��B<br>
 * 1�Z���g��1�I�N�^�[�u��1/1200�ł��B������100�Z���g�ł��B<br>
 * �Ⴆ�΁A100.0f���w�肵���ꍇ�A�s�b�`�������オ��܂��B-100.0f���w�肵���ꍇ�A
 * �s�b�`������������܂��B<br>
 * �s�b�`�̃f�t�H���g�l��0.0f�ł��B<br>
 * \par ��:
 * \code
 * 	�F
 * // �s�b�`�̐ݒ�
 * criAtomExPlayer_SetPitch(player, 100.0f);
 * 
 * // �Đ��̊J�n
 * // ���l�j�s�b�`�̓v���[���[�ɐݒ肳�ꂽ�l�i��0.5f�j�ōĐ������B
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �s�b�`�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃s�b�`�͕ύX����Ȃ��B
 * criAtomExPlayer_SetPitch(player, -200.0f);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�s�b�`���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀs�b�`���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>���Z</b>�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃s�b�`��-100.0f�AAtomEx�v���[���[�̃s�b�`��200.0f�̏ꍇ�A
 * ���ۂɓK�p�����s�b�`��100.0f�ɂȂ�܂��B
 * <br>
 * �T���v�����O���[�g�̎��g���䗦�Őݒ肵�����ꍇ�A�ȉ��̌v�Z���ŕϊ����Ă���ݒ肵�Ă��������B<br>
 * \code
 * pitch = 1200.0f*logf(freq_ratio)/logf(2.0f);
 * \endcode
 * ��freq_ratio�����g���䗦�Apitch���s�b�`�̒l�ł��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�́A�s�b�`�̕ύX���ł��܂���B<br>
 * �i�{�֐������s���Ă��A�s�b�`�͕ς��܂���B�j<br>
 * �s�b�`��ύX�����������ɂ��ẮAADX��HCA���A���̃R�[�f�b�N�ŃG���R�[�h���s���Ă��������B<br>
 * <br>
 * �ݒ�\�ȍő�s�b�`�́A�����f�[�^�̃T���v�����O���[�g�ƃ{�C�X�v�[���̍ő�T���v�����O���[�g�Ɉˑ����܂��B<br>
 * �Ⴆ�΁A�����f�[�^�̃T���v�����O���[�g��24kHz�ŁA�{�C�X�v�[���̍ő�T���v�����O���[�g��48kHz�̏ꍇ�A
 * �ݒ�\�ȍő�s�b�`��1200(���g���䗦2�{)�ɂȂ�܂��B<br>
 * <br>
 * �Đ��T���v�����O���[�g�̏㉺�ɂ��s�b�`���������Ă��邽�߁A
 * �s�b�`��ύX����Ɖ����ƈꏏ�ɍĐ����x���ω����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetMaxPitch, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPitch(CriAtomExPlayerHn player, CriFloat32 pitch);

/*JP
 * \brief �ő�s�b�`�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	pitch		�ő�s�b�`
 * \par ����:
 * �����̍ő�s�b�`��ݒ肵�܂��B<br>
 * �{�֐��ōő�s�b�`���w�肷�邱�ƂŁA�w��͈͓��ł̃s�b�`�ύX�������ɔ��f�����悤�ɂȂ�܂��B<br>
 * \par ���l:
 * Atom Ver.2.10.00�ȑO�̃��C�u�����ł́A�s�b�`���グ���ۂɉ����r�؂��
 * �i�Đ����x�������Ȃ������ʁA�����f�[�^�̋���������Ȃ��Ȃ�j�P�[�X������܂����B<br>
 * ���̑΍�Ƃ��āAAtom Ver.2.10.00�ł̓s�b�`���グ�Ă������r�؂�Ȃ��悤�A
 * �������[���Ƀo�b�t�@�����O���Ă���s�b�`���グ��悤�����ύX���Ă��܂��B<br>
 * �C���ɂ��A�s�b�`����ɂ���ĉ����r�؂�邱�Ƃ͂Ȃ��Ȃ�܂������A
 * �s�b�`���グ��ۂɃo�b�t�@�����O��҂��ԕ������s�b�`�ύX���x���`�ɂȂ邽�߁A
 * ���̕ω����ȑO�̃o�[�W�����Ɣ�ׂĊɖ��ɂȂ�\��������܂��B<br>
 * �i�Z���ԂɃs�b�`���グ��������P�[�X�ɂ����āA���̖�����ς��\��������܂��B�j<br>
 * <br>
 * �{�֐��ōő�s�b�`�����炩���ߐݒ肵���ꍇ�A
 * �w�肳�ꂽ���x��z�肵�ď�Ƀo�b�t�@�����O���s����悤�ɂȂ邽�߁A
 * �i�w�肳�ꂽ�͈͓��̎��g���ɂ����Ắj�o�b�t�@�����O�Ȃ��Ƀs�b�`�ύX�������ɍs���܂��B<br>
 * �Z���ԂɃs�b�`���グ��������P�[�X�ɂ��ẮA
 * �\�z�����ő�s�b�`�����炩���ߖ{�֐��Őݒ肵�Ă���Đ����s���Ă��������B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_SetPitch, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetMaxPitch(CriAtomExPlayerHn player, CriFloat32 pitch);

/*JP
 * \brief �p���j���O3D�p�x�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	pan3d_angle	�p���j���O3D�p�x�i-180.0f�`180.0f�F�x�P�ʁj
 * \par ����:
 * �p���j���O3D�p�x���w�肵�܂��B<br>
 * �{�֐��Ńp���j���O3D�p�x��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�p���j���O3D�p�x�ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃p���j���O3D�p�x���X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �p�x�͓x�P�ʂŎw�肵�܂��B<br>
 * �O����0�x�Ƃ��A�E�����i���v���j��180.0f�A�������i�����v���j��-180.0f�܂Őݒ�ł��܂��B<br>
 * �Ⴆ�΁A45.0f���w�肵���ꍇ�A�E�O��45�x�ɒ�ʂ��܂��B-45.0f���w�肵���ꍇ�A���O��45�x�ɒ�ʂ��܂��B<br>
 * \par ��:
 * \code
 * 	�F
 * // �p���j���O3D�p�x�̐ݒ�
 * criAtomExPlayer_SetPan3dAngle(player, 45.0f);
 * 
 * // �Đ��̊J�n
 * // ���l�j�p���j���O3D�p�x�̓v���[���[�ɐݒ肳�ꂽ�l�i��45.0f�j�ōĐ������B
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p���j���O3D�p�x�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p���j���O3D�p�x�͕ύX����Ȃ��B
 * criAtomExPlayer_SetPan3dAngle(player, -45.0f);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p���j���O3D�p�x���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀp���j���O3D�p�x���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>���Z</b>�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃p���j���O3D�p�x��15.0f�AAtomEx�v���[���[�̃p���j���O3D�p�x��30.0f�̏ꍇ�A
 * ���ۂɓK�p�����p���j���O3D�p�x��45.0f�ɂȂ�܂��B
 * <br>
 * ���ۂɓK�p�����p���j���O3D�p�x��180.0f�𒴂���l�ɂȂ����ꍇ�A�l��-360.0f���Ĕ͈͓��ɔ[�߂܂��B<br>
 * ���l�ɁA���ۂɓK�p�����{�����[���l��-180.0f�����̒l�ɂȂ����ꍇ�́A�l��+360.0f���Ĕ͈͓��ɔ[�߂܂��B<br>
 * �i+360.0f, -360.0f���Ă���ʂ͕ς��Ȃ����߁A�����I�ɂ�-180.0f�`180.0f�͈̔͂𒴂��Đݒ�\�ł��B�j<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPan3dAngle(
	CriAtomExPlayerHn player, CriFloat32 pan3d_angle);

/*JP
 * \brief �p���j���O3D�����̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player					AtomEx�v���[���[�n���h��
 * \param[in]	pan3d_interior_distance	�p���j���O3D�����i-1.0f�`1.0f�j
 * \par ����:
 * �p���j���O3D�ŃC���e���A�p���j���O���s���ۂ̋������w�肵�܂��B<br>
 * �{�֐��Ńp���j���O3D������ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�p���j���O3D�����ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃p���j���O3D�������X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �����́A���X�i�[�ʒu��0.0f�A�X�s�[�J�[�̔z�u����Ă���~�����1.0f�Ƃ��āA-1.0f�`1.0f�͈̔͂Ŏw�肵�܂��B<br>
 * ���l���w�肷��ƁA�p���j���O3D�p�x��180�x���]���A�t�����ɒ�ʂ��܂��B
 * \par ��:
 * \code
 * 	�F
 * // �p���j���O3D�����̐ݒ�
 * criAtomExPlayer_SetPan3dInteriorDistance(player, 0.5f);
 * 
 * // �Đ��̊J�n
 * // ���l�j�p���j���O3D�����̓v���[���[�ɐݒ肳�ꂽ�l�i��0.5f�j�ōĐ������B
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p���j���O3D�����̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p���j���O3D�����͕ύX����Ȃ��B
 * // ���l�j�ȉ��̏����̓p��3D�p�x��180�x���]����̂Ɠ���
 * criAtomExPlayer_SetPan3dInteriorDistance(player, -0.5f);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p���j���O3D�������Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀp���j���O3D�������ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>��Z</b>�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃p���j���O3D������0.8f�AAtomEx�v���[���[�̃p���j���O3D������0.5f�̏ꍇ�A
 * ���ۂɓK�p�����p���j���O3D������0.4f�ɂȂ�܂��B
 * <br>
 * ���ۂɓK�p�����p���j���O3D������1.0f�𒴂���l�ɂȂ����ꍇ�A�l��1.0f�ɃN���b�v����܂��B<br>
 * ���l�ɁA���ۂɓK�p�����p���j���O3D������-1.0f�����̒l�ɂȂ����ꍇ���A�l��-1.0f�ɃN���b�v����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPan3dInteriorDistance(
	CriAtomExPlayerHn player, CriFloat32 pan3d_interior_distance);

/*JP
 * \brief �p���j���O3D�{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	pan3d_volume	�p���j���O3D�{�����[���i0.0f�`1.0f�j
 * \par ����:
 * �p���j���O3D�̃{�����[�����w�肵�܂��B<br>
 * �{�֐��Ńp���j���O3D�{�����[����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�p���j���O3D�{�����[���ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃p���j���O3D�{�����[�����X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �p���j���O3D�{�����[���́A�p���j���O3D�����ƁA
 * �Z���^�[�^LFE�ւ̏o�̓��x���Ƃ��ʂɐ��䂷��ꍇ�Ɏg�p���܂��B<br>
 * �Ⴆ�΁A�Z���h���x���ŏ��LFE������̃{�����[���ŏo�͂����Ă����A
 * ��ʂ̓p���j���O3D�ŃR���g���[������悤�ȏꍇ�ł��B
 * <br>
 * �l�͈̔͂∵���́A�ʏ�̃{�����[���Ɠ����ł��B::criAtomExPlayer_SetVolume �֐����Q�Ƃ��Ă��������B
 * \par ��:
 * \code
 * 	�F
 * // �p���j���O3D�{�����[���̐ݒ�
 * criAtomExPlayer_SetPan3dVolume(player, 0.8f);
 * 
 * // �Đ��̊J�n
 * // ���l�j�p���j���O3D�{�����[���̓v���[���[�ɐݒ肳�ꂽ�l�i��0.5f�j�ōĐ������B
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p���j���O3D�{�����[���̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p���j���O3D�{�����[���͕ύX����Ȃ��B
 * criAtomExPlayer_SetPan3dVolume(player, 0.7f);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p���j���O3D�{�����[�����Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetVolume, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPan3dVolume(
	CriAtomExPlayerHn player, CriFloat32 pan3d_volume);

/*JP
 * \brief �p���^�C�v�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	pan_type		�p���^�C�v
 * \par ����:
 * �p���^�C�v���w�肵�܂��B<br>
 * �{�֐��Ńp���^�C�v��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�p���^�C�v�ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃p���^�C�v���X�V���邱�Ƃ��ł��܂��B<br>
 * \par ���l:
 * �L���[�Đ����ɖ{�֐����Ăяo���ƁA�f�[�^���ɐݒ肳��Ă���p���^�C�v�ݒ��<b>�㏑��</b>���܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * �ʏ�̓f�[�^���Ńp���^�C�v���ݒ肳��Ă��邽�߁A�{�֐����Ăяo���K�v�͂���܂���B<br>
 * ACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�ɁA3D�|�W�V���j���O������L���ɂ��邽�߂ɂ́A�{�֐���::CRIATOMEX_PAN_TYPE_3D_POS��ݒ肵�Ă��������B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * ::CRIATOMEX_PAN_TYPE_UNKNOWN ���w�肵�Ď��s�����ꍇ�A�G���[���������܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, CriAtomExPanType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPanType(
	CriAtomExPlayerHn player, CriAtomExPanType pan_type);

/*JP
 * \brief �p���j���O���̏o�̓X�s�[�J�[�^�C�v�ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player				AtomEx�v���[���[�n���h��
 * \param[in]	pan_speaker_type	�p���j���O���̏o�̓X�s�[�J�[�^�C�v
 * \par ����:
 * �p���j���O���̏o�̓X�s�[�J�[�^�C�v���w�肵�܂��B<br>
 * �{�֐��Ńp���j���O���̏o�̓X�s�[�J�[�^�C�v��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�o�̓X�s�[�J�[�^�C�v�Ńp���j���O�v�Z����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̏o�̓X�s�[�J�[�^�C�v���X�V���邱�Ƃ��ł��܂��B<br>
 * \par ���l:
 * �{�֐��̐ݒ�̓p��3D��3D�|�W�V���j���O�ɂ�����p���j���O�v�Z�ɉe�����܂��B<br>
 * ���C�u�������������̃f�t�H���g�l��4ch�p���j���O�i::CRIATOMEX_PAN_SPEAKER_TYPE_4CH�j�ł��B<br>
 * �f�t�H���g�l��::criAtomExPlayer_ChangeDefaultPanSpeakerType �֐��ɂĕύX�\�ł��B<br>
 * �X�e���I�X�s�[�J�[�̃v���b�g�t�H�[���ł́A�ǂ��I�񂾂Ƃ��Ă��ŏI�I�ɂ̓X�e���I�Ƀ_�E���~�b�N�X����܂��B<br>
 * <br>
 * �{�p�����[�^�[�̓f�[�^���ɂ͐ݒ�ł��Ȃ����߁A��ɖ{�֐��̐ݒ�l���K�p����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, CriAtomExPanSpeakerType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPanSpeakerType(
	CriAtomExPlayerHn player, CriAtomExPanSpeakerType pan_speaker_type);

/*JP
 * \brief MixDownCenter�{�����[���I�t�Z�b�g�l�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player							AtomEx�v���[���[�n���h��
 * \param[in]	mixdown_center_volume_offset	MixDownCenter�{�����[���̃I�t�Z�b�g�l
 * \par ����:
 * Center, LFE�ȊO�̐M�������m�����Ƀ~�b�N�X����Center�ɏo�͂��邽�߂̃{�����[���l��ݒ肵�܂��B<br>
 * �{�֐��ɂ��ݒ�l�́ACRI Atom Craft�ɂ��f�[�^�ݒ�l�ɑ΂��ĉ��Z�K�p����܂��B<br>
 * �{�֐��̑�����mixdown_center_volume_offset�ɂ�0�`1�̕��������_�l�ŏo�̓{�����[����ݒ肵�Ă��������B<br>
 * \attention
 * �ݒ�l�͈̔͊O�m�F�͍s���܂���B�͈͊O��ݒ肷��ۂɂ͈ȉ��̓_�ɒ��ӂ��Ă��������B<br>
 * 1���傫���l�F�o�͐U���l�̑����ɂ��N���b�s���O�m�C�Y�����������邱�Ƃ�����܂��B<br>
 * ���l�F�f�[�^�ݒ�l�Ƃ̘a�����ƂȂ����ꍇ�́A���l���ʂɑ΂��Ĉʑ��𔽓]�������ʂ��o�͂���܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, CriAtomExPanSpeakerType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_AddMixDownCenterVolumeOffset(
	CriAtomExPlayerHn player, CriFloat32 mixdown_center_volume_offset);

/*JP
 * \brief MixDownLFE�{�����[���I�t�Z�b�g�l�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player							AtomEx�v���[���[�n���h��
 * \param[in]	mixdown_lfe_volume_offset		MixDownLFE�{�����[���̃I�t�Z�b�g�l
 * \par ����:
 * Center, LFE�ȊO�̐M�������m�����Ƀ~�b�N�X����LFE�ɏo�͂��邽�߂̃{�����[���l��ݒ肵�܂��B<br>
 * �{�֐��ɂ��ݒ�l�́ACRI Atom Craft�ɂ��f�[�^�ݒ�l�ɑ΂��ĉ��Z�K�p����܂��B<br>
 * �{�֐��̑�����mixdown_lfe_volume_offset�ɂ�0�`1�̕��������_�l�ŏo�̓{�����[����ݒ肵�Ă��������B<br>
 * \attention
 * �ݒ�l�͈̔͊O�m�F�͍s���܂���B�͈͊O��ݒ肷��ۂɂ͈ȉ��̓_�ɒ��ӂ��Ă��������B<br>
 * 1���傫���l�F�o�͐U���l�̑����ɂ��N���b�s���O�m�C�Y�����������邱�Ƃ�����܂��B<br>
 * ���l�F�f�[�^�ݒ�l�Ƃ̘a�����ƂȂ����ꍇ�́A���l���ʂɑ΂��Ĉʑ��𔽓]�������ʂ��o�͂���܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, CriAtomExPanSpeakerType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_AddMixDownLfeVolumeOffset(
	CriAtomExPlayerHn player, CriFloat32 mixdown_lfe_volume_offset);

/*JP
 * \brief �p���j���O���̏o�̓X�s�[�J�[�^�C�v�ݒ�̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	pan_speaker_type	�p���j���O���̏o�̓X�s�[�J�[�^�C�v
 * \par ����:
 * �p���j���O���̏o�̓X�s�[�J�[�^�C�v�̃f�t�H���g�l��ύX���܂��B<br>
 * ::criAtomExPlayer_SetPanSpeakerType �֐������s���Ă��Ȃ�AtomEx�v���[���[�́A�S�Ė{�֐��Őݒ肵���o�̓X�s�[�J�[�^�C�v�ōĐ�����܂��B<br>
 * \par ���l:
 * �{�֐��̐ݒ�̓p��3D��3D�|�W�V���j���O�ɂ�����p���j���O�v�Z�ɉe�����܂��B<br>
 * ���C�u�������������̃f�t�H���g�l��4ch�p���j���O�i::CRIATOMEX_PAN_SPEAKER_TYPE_4CH�j�ł��B<br>
 * �X�e���I�X�s�[�J�[�̃v���b�g�t�H�[���ł́A�ǂ��I�񂾂Ƃ��Ă��ŏI�I�ɂ̓X�e���I�Ƀ_�E���~�b�N�X����܂��B<br>
 * <br>
 * �{�p�����[�^�[�̓f�[�^���ɂ͐ݒ�ł��Ȃ����߁A��ɖ{�֐��̐ݒ�l���K�p����܂��B<br>
 * \attention
 * �Đ����̉������f�t�H���g�l���Q�Ƃ���^�C�~���O�̓��[�U�[�̑���Ɉˑ����܂��B<br>
 * ���̂��߁A�Đ����Ƀf�t�H���g�l��ύX�����ꍇ�A�Ӑ}�����^�C�~���O�ŕύX�����f�����Ƃ͌���܂���B<br>
 * �{�֐����g�p����ꍇ�A���������Ȃǉ������Đ�����O�Ɏ��s����悤�ɂ��Ă��������B<br>
 * \sa criAtomExPlayer_SetPanSpeakerType, CriAtomExPanSpeakerType
 */
void CRIAPI criAtomExPlayer_ChangeDefaultPanSpeakerType(
	CriAtomExPanSpeakerType pan_speaker_type);

/*JP
 * \brief �p���j���O���̊p�x�^�C�v�ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player				AtomEx�v���[���[�n���h��
 * \param[in]	pan_angle_type	�p���j���O���̊p�x�^�C�v
 * \par ����:
 * �p���j���O���̊p�x�^�C�v���w�肵�܂��B<br>
 * �p�x�^�C�v�́A�}���`�`�����l���i�X�e���I�A5.1ch���j�̉����f�ނ��p���j���O����Ƃ��ɁA�e���̓`�����l�����ǂ̂悤�Ȋp�x�Ƃ��Ĉ�������\���܂��B<br>
 * �{�֐��Ńp���j���O���̊p�x�^�C�v��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�p�x�^�C�v�Ńp���j���O�v�Z����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̊p�x�^�C�v���X�V���邱�Ƃ��ł��܂��B<br>
 * \par ���l:
 * �{�֐��̐ݒ�̓p��3D��3D�|�W�V���j���O�ɂ�����p���j���O�v�Z�ɉe�����܂��B<br>
 * �f�t�H���g�l�̓I�t�Z�b�g�i::CRIATOMEX_PAN_ANGLE_TYPE_OFFSET�j�ł��B<br>
 * �{�֐��́A��ɂ�CRI Audio�Ƃ̌݊��p�Ɏg�p���܂��B
 * �{�֐��� ::CRIATOMEX_PAN_ANGLE_TYPE_FIX ��ݒ肷�邱�ƂŁACRI Audio�ł̃p��3D�v�Z�Ɠ��������ɂȂ�܂��B<br>
 * <br>
 * �{�p�����[�^�[�̓f�[�^���ɂ͐ݒ�ł��Ȃ����߁A��ɖ{�֐��̐ݒ�l���K�p����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, CriAtomExPanAngleType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPanAngleType(
	CriAtomExPlayerHn player, CriAtomExPanAngleType pan_angle_type);

/*JP
 * \brief �p���j���O���̉��̍L����ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	spread		�}���`�`�����l�������̍L����
 * \par ����:
 * �p���j���O���̉��̍L������w�肵�܂��B<br>
 * �}���`�`�����l���i�X�e���I�A5.1ch���j�̉����f�ނ��p���j���O����Ƃ��ɁA�e���̓`�����l���Ԃ̊p�x���ǂꂾ���L���邩���w�肵�܂��B<br>
 * ���� spread �̒l��� 0.0 �` 1.0 �ł��B�f�t�H���g�l�� 1.0 �ł��B<br>
 * �Ⴆ�΃X�e���I�������L����0.5�ōĐ�����ƁA���ʂ��猩�č��`�����l����-15�x(-30�x*0.5)�A�E�`�����l����15�x(30�x*0.5)�ɒ�ʂ���悤�p���j���O�v�Z����܂��B<br>
 * ���m���������ɂ͉e�����܂���B<br>
 * \par ���l�F
 * �{�֐��Ńp���j���O���̊p�x�^�C�v��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�L����Ńp���j���O�v�Z����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̍L������X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �{�p�����[�^�[�̓f�[�^���ɂ͐ݒ�ł��Ȃ����߁A��ɖ{�֐��̐ݒ�l���K�p����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPanSpread(CriAtomExPlayerHn player, CriFloat32 spread);

/*JP
 * \brief �Z���h���x���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	ch			�`�����l���ԍ�
 * \param[in]	spk			�X�s�[�J�[ID
 * \param[in]	level		�Z���h���x���l�i0.0f�`1.0f�j
 * \par ����:
 * �Z���h���x�����w�肵�܂��B<br>
 * �Z���h���x���́A�����f�[�^�̊e�`�����l���̉������A�ǂ̃X�s�[�J�[����
 * �ǂ̒��x�̉��ʂŏo�͂��邩���w�肷�邽�߂̎d�g�݂ł��B<br>
 * �{�֐��ŃZ���h���x����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�Z���h���x���ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃Z���h���x�����X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * ��2�����̃`�����l���ԍ���"�����f�[�^�̃`�����l���ԍ�"���w�肵�܂��B<br>
 * ��3�����̃X�s�[�J�[ID�ɂ́A�w�肵���`�����l���ԍ��̃f�[�^���ǂ̃X�s�[�J�[����
 * �o�͂��邩���w�肵�A��4�����ł͑��M���̃��x���i�{�����[���j���w�肵�܂��B<br>
 * �Ⴆ�΁A�����f�[�^�̃`�����l��0�Ԃ̃f�[�^�����C�g�X�s�[�J�[����
 * �t���{�����[���i1.0f�j�ŏo�͂������ꍇ�A�w��͈ȉ��̂悤�ɂȂ�܂��B
 * \code
 * criAtomExPlayer_SetSendLevel(player, 0, CRIATOMEX_SPEAKER_FRONT_RIGHT, 1.0f);
 * \endcode
 * <br>
 * �Z���h���x���l�͈̔͂∵���́A�{�����[���Ɠ����ł��B::criAtomExPlayer_SetVolume �֐����Q�Ƃ��Ă��������B<br>
 * <br>
 * �Ȃ��A�Z���^�[�X�s�[�J�[�̂���v���b�g�t�H�[���ŁA���m���������Z���^�[�X�s�[�J�[�݂̂���o�͂������ꍇ�A
 * �{�֐��ł͂Ȃ�::criAtomExPlayer_SetPanSpeakerType �֐���::CRIATOMEX_PAN_SPEAKER_TYPE_5CH
 * ��ݒ肷�邱�Ƃ����E�߂��܂��B<br>
 * \par ��:
 * \code
 * CriSint32 ch = 0;	// channel number 0
 * CriAtomExSpeakerId spk = CRIATOMEX_SPEAKER_FRONT_CENTER;
 * CriFloat32 level = 1.0f;
 * // Set send level(ch0 to center)
 * criAtomExPlayer_SetSendLevel(player, ch, spk, level);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Change send level
 * level = 0.7f;
 * criAtomExPlayer_SetSendLevel(player, ch, spk, level);
 * criAtomExPlayer_Update(player, id);
 * \endcode
 * \par ���l:
 * �Z���h���x���̐ݒ�ɂ́u�����ݒ�v�u�蓮�ݒ�v��2�ʂ肪���݂��܂��B<br>
 * AtomEx�v���[���[���쐬���������A ::criAtomExPlayer_ResetParameters �֐���
 * �p�����[�^�[���N���A�����ꍇ�A�Z���h���x���̐ݒ�́u�����ݒ�v�ƂȂ�܂��B<br>
 * ����ɑ΂��A�{�֐������s�����ꍇ�A�Z���h���x���̐ݒ�́u�蓮�ݒ�v�ɂȂ�܂��B<br>
 * �i���[�U���e�X�s�[�J�[�ւ̃Z���h���x�����R���g���[�����A�p���j���O���s���K�v������܂��B�j<br>
 * <br>
 * �u�����ݒ�v�̏ꍇ�AAtomEx�v���[���[�͈ȉ��̂悤�ɉ��������[�e�B���O���܂��B<br>
 * <br>
 * �y���m�����������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������E�̃X�s�[�J�[�����0.7f�i-3dB�j�̃{�����[���ŏo�͂��܂��B<br>
 * <br>
 * �y�X�e���I�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A
 * �`�����l��1�̉��������C�g�X�s�[�J�[����o�͂��܂��B<br>
 * <br>
 * �y4ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��3�̉������T���E���h���C�g�X�s�[�J�[����ł��ꂼ��o�͂��܂��B<br>
 * <br>
 * �y5.1ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������Z���^�[�X�s�[�J�[����A�`�����l��3�̉�����LFE����A
 * �`�����l��4�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��5�̉������T���E���h���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * <br>
 * �y7.1ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������Z���^�[�X�s�[�J�[����A�`�����l��3�̉�����LFE����A
 * �`�����l��4�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��5�̉������T���E���h���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * �`�����l��6�̉������T���E���h�o�b�N���t�g�X�s�[�J�[����A
 * �`�����l��7�̉������T���E���h�o�b�N���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * <br>
 * ����ɑ΂��A�{�֐���p���āu�蓮�ݒ�v���s�����ꍇ�A�����f�[�^�̃`�����l������
 * �֌W�Ȃ��A�w�肳�ꂽ�Z���h���x���ݒ�ŉ������o�͂���܂��B<br>
 * �i�����f�[�^�̃`�����l�����ɉ����āA�K�X�Z���h���x���ݒ��؂�ւ���K�v������܂��B�j<br>
 * <br>
 * �ߋ��Ɏw�肵���Z���h���x�����N���A���A���[�e�B���O���u�����ݒ�v�̏�Ԃɖ߂������ꍇ�́A
 * ::criAtomExPlayer_ResetParameters �֐������s���Ă��������B<br>
 * <br>
 * �{�p�����[�^�[�̓f�[�^���ɂ͐ݒ�ł��Ȃ����߁A��ɖ{�֐��̐ݒ�l���K�p����܂��B<br>
 * \attention
 * �Z���h���x����ݒ肵�Ă��Ȃ��`�����l���ɂ��ẮA�������o�͂���܂���B<br>
 * �Ⴆ�΁A�Đ����鉹���f�[�^���X�e���I�ɂ�������炸�A�ǂ��炩����̃`�����l���ɑ΂���
 * �����Z���h���x�����ݒ肳��Ă��Ȃ��ꍇ�A�Z���h���x����ݒ肵�Ă��Ȃ��`�����l���̉���
 * �̓~���[�g����܂��B<br>
 * �Z���h���x�����R���g���[������ۂɂ́A�K���o�͂��s�������S�Ẵ`�����l���ɂ��ăZ���h
 * ���x���̐ݒ���s���Ă��������B<br>
 * <br>
 * �{�֐���p���ăZ���h���x����ݒ肵���ꍇ�A�p��3D��3D�|�W�V���j���O�̐ݒ�͖�������܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetVolume, criAtomExPlayer_SetPanSpeakerType, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetSendLevel(
	CriAtomExPlayerHn player, CriSint32 ch, CriAtomExSpeakerId spk, CriFloat32 level);

/*JP
 * \brief �o�X�Z���h���x���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	bus_name	�o�X��
 * \param[in]	level		�Z���h���x���l�i0.0f�`1.0f�j
 * \par ����:
 * �o�X�Z���h���x�����w�肵�܂��B<br>
 * �o�X�Z���h���x���́A�������ǂ̃o�X�ɂǂꂾ�����������w�肷�邽�߂̎d�g�݂ł��B<br>
 * �{�֐��Ńo�X�Z���h���x����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�o�X�Z���h���x���ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃o�X�Z���h���x�����X�V���邱�Ƃ��ł��܂��B<br>
 * �L���[�Đ����A�f�[�^���Ƀo�X�Z���h���x�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>��Z</b>�����l���K�p����܂��B<br>
 * <br>
 * ��2�����ɂ�DSP�o�X�ݒ���̃o�X�����w�肵�܂��B<br>
 * ��3�����ł͑��M���̃��x���i�{�����[���j���w�肵�܂��B<br>
 * <br>
 * ��2�����̃o�X���Ŏw�肵���o�X���K�p����DSP�o�X�ݒ�ɑ��݂��Ȃ��ꍇ�A�ݒ�l�͖����l�Ƃ��ď�������܂��B<br>
 * �Z���h���x���l�͈̔͂∵���́A�{�����[���Ɠ����ł��B::criAtomExPlayer_SetVolume �֐����Q�Ƃ��Ă��������B
 * \par ��:
 * \code
 * 	�F
 * // �o�X�Z���h���x����ݒ�
 * cosnt CriChar8* bus_name = "Reverb";
 * CriFloat32 level = 0.3f;
 * criAtomExPlayer_SetBusSendLevelByName(player, bus_name, level);
 * 
 * // �Đ��̊J�n
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p�����[�^�[�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p�����[�^�[�͕ύX����Ȃ��B
 * level = 0.5f;
 * criAtomExPlayer_SetBusSendLevelByName(player, bus_name, level);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p�����[�^�[���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �{�֐��ɈقȂ�o�X�����w�肵�ĕ�����Ăяo�����ƂŁA�����̃o�X�ɗ������Ƃ��ł��܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetVolume, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetBusSendLevelByName(
	CriAtomExPlayerHn player, const CriChar8* bus_name, CriFloat32 level);

/*JP
 * \brief �o�X�Z���h���x���̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx �v���[���[�n���h��
 * \param[in]	bus_name	�o�X��
 * \param[out]	level		�o�X�Z���h���x���l�i0.0f�`1.0f�j
 * \return		CriBool		�o�X�Z���h���x���l���擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肵�� AtomEx �v���[���[�ɐݒ肳��Ă������̃o�X�Z���h���x�����擾���܂��B<br>
 * <br>
 * ��2�����ɂ�DSP�o�X�ݒ���̃o�X�����w�肵�܂��B<br>
 * <br>
 * �Ȃ��A�ȉ��̃P�[�X�ɊY������ꍇ�A�o�X�Z���h���x���̎擾�Ɏ��s���܂��B
 *	- ��2�����̃o�X���Ŏw�肵���o�X���K�p����DSP�o�X�ݒ�ɑ��݂��Ȃ�
 *	- ��1�����ɂĎw�肵�� AtomEx �v���[���[�ɑ�2�����̃o�X���Ɋւ���o�X�Z���h���x���̐ݒ���s���Ă��Ȃ�
 * 	
 * \sa criAtomExPlayer_SetBusSendLevelByName
 */
CriBool CRIAPI criAtomExPlayer_GetBusSendLevelByName(
	CriAtomExPlayerHn player, const CriChar8* bus_name, CriFloat32* level);

/*JP
 * \brief �o�X�Z���h���x���̐ݒ�i�I�t�Z�b�g�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	bus_name		�o�X��
 * \param[in]	level_offset	�Z���h���x���l�i0.0f�`1.0f�j
 * \par ����:
 * �o�X�Z���h���x�����I�t�Z�b�g�Ŏw�肵�܂��B<br>
 * �L���[�Đ����A�f�[�^���Ƀo�X�Z���h���x�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>���Z</b>�����l���K�p����܂��B<br>
 * ����ȊO�̎d�l�� ::criAtomExPlayer_SetBusSendLevelByName �֐��Ɠ��l�ł��B
 * \par ���l:
 * ::criAtomExPlayer_SetBusSendLevelByName �֐��� 0.0f ��ݒ肵�A���{�֐��ŃI�t�Z�b�g�l��ݒ肷�邱�ƂŁA<br>
 * �f�[�^���ɐݒ肳��Ă����o�X�Z���h���x���𖳎����Ēl���ݒ�\�ł��B�i�㏑���ݒ�j<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_SetBusSendLevelByName, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetBusSendLevelOffsetByName(
	CriAtomExPlayerHn player, const CriChar8* bus_name, CriFloat32 level_offset);

/*JP
 * \brief �o�X�Z���h���x���̃I�t�Z�b�g�̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx �v���[���[�n���h��
 * \param[in]	bus_name		�o�X��
 * \param[out]	level_offset	�o�X�Z���h���x���̃I�t�Z�b�g�l�i0.0f�`1.0f�j
 * \return		CriBool			�o�X�Z���h���x���̃I�t�Z�b�g�l���擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �w�肵�� AtomEx �v���[���[�ɐݒ肳��Ă������̃o�X�Z���h���x���̃I�t�Z�b�g���擾���܂��B<br>
 * <br>
 * ��2�����ɂ�DSP�o�X�ݒ���̃o�X�����w�肵�܂��B<br>
 * <br>
 * �Ȃ��A�ȉ��̃P�[�X�ɊY������ꍇ�A�o�X�Z���h���x���̃I�t�Z�b�g�̎擾�Ɏ��s���܂��B
 *	- ��2�����̃o�X���Ŏw�肵���o�X���K�p����DSP�o�X�ݒ�ɑ��݂��Ȃ�
 *	- ��1�����ɂĎw�肵�� AtomEx �v���[���[�ɑ�2�����̃o�X���Ɋւ���o�X�Z���h���x���̐ݒ���s���Ă��Ȃ�
 * 	
 * \sa criAtomExPlayer_SetBusSendLevelByName
 */
CriBool CRIAPI criAtomExPlayer_GetBusSendLevelOffsetByName(
	CriAtomExPlayerHn player, const CriChar8* bus_name, CriFloat32* level_offset);

/*JP
 * \brief ADX1�݊��̃p���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	ch			�`�����l���ԍ�
 * \param[in]	pan			�p���ݒ�l�i-1.0f�`1.0f�j
 * \par ����:
 * ADX1�݊��̃p���ݒ�֐��ł��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �{�֐���ADX1����̈ڐA�^�C�g���p�ɗp�ӂ���Ă��܂��B<br>
 * ADX2���ŐV�K�Ƀp��������s���A�v���P�[�V�������쐬����ꍇ�A
 * ::criAtomExPlayer_SetPan3dAngle �֐����g�p���Ă��������B<br>
 * <br>
 * �{�֐��Ńp����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�p���ōĐ�����܂��B<br>
 * ���łɍĐ����ꂽ�����̃p����ύX����ꍇ�A�{�֐��ŐV���ȃp���ݒ���v���[���[�Ɏw�肵�A
 * ::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ōĐ����̉����ɂ��̃p�����[�^�[��K�p����K�v������܂��B<br>
 * <br>
 * �{�֐��Ńp�����R���g���[���\�Ȃ̂́A���m���������ƃX�e���I�����݂̂ł��B
 * �܂��A���E�̒�ʂ̂݃R���g���[���ł��܂��B<br>
 * 3ch�ȏ�̉����ɑ΂��ăp�����R���g���[���������ꍇ��A�O����܂߂���ʂ��R���g���[���������ꍇ�ɂ́A
 * ::criAtomExPlayer_SetPan3dAngle �֐���::criAtomExPlayer_SetSendLevel �֐����g�p����K�v������܂��B<br>
 * <br>
 * �Đ����鉹���f�[�^���X�e���I�̏ꍇ�A�`�����l��0�Ԃƃ`�����l��1�Ԃ̂��ꂼ��̃p��
 * �ɂ��āA�Ɨ����ăR���g���[�����邱�Ƃ��\�ł��B<br>
 * �������A�ݒ肳�ꂽ�p�������m�������������Ȃ̂��A�X�e���I���������Ȃ̂��͋��
 * ����Ȃ����߁A�X�e���I�ݒ�p�Ƀp���ݒ���s����AtomEx�v���[���[�Ń��m�����������Đ�
 * �����ꍇ�A�Ӑ}�Ƃ��Ȃ��ʒu�ɉ�������ʂ���\��������܂��B<br>
 * <br>
 * �Đ����鉹���f�[�^���X�e���I�ɂ�������炸�A�ǂ��炩����̃`�����l���ɑ΂���
 * �����p�����ݒ肳��Ă��Ȃ��ꍇ�A�p����ݒ肵�Ă��Ȃ��`�����l���̉����̒�ʈʒu
 * �� 0.0f �i��������̏o�́j�ɂȂ�܂��B<br>
 * �X�e���I�����̃p�����R���g���[������ۂɂ́A�K�������̃`�����l���ɂ��ăp����
 * �ݒ���s���Ă��������B<br>
 * <br>
 * �{�֐���::criAtomExPlayer_SetPan3dAngle �֐��� ::criAtomExPlayer_SetSendLevel �֐��𕹗p���Ȃ��ł��������B<br>
 * ���҂𕹗p�����ꍇ�A�Ӑ}���Ȃ��p���ōĐ������\��������܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll,
 * criAtomExPlayer_SetPan3dAngle, criAtomExPlayer_SetSendLevel, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetPanAdx1Compatible(
	CriAtomExPlayerHn player, CriSint32 ch, CriFloat32 pan);

/*JP
 * \brief �o���h�p�X�t�B���^�[�̃p�����[�^�[�ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	cof_low		���K�����J�b�g�I�t���g���i0.0f�`1.0f�j
 * \param[in]	cof_high	���K������J�b�g�I�t���g���i0.0f�`1.0f�j
 * \par ����:
 * �o���h�p�X�t�B���^�[�̃J�b�g�I�t���g�����w�肵�܂��B<br>
 * �{�֐��ŃJ�b�g�I�t���g����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�J�b�g�I�t���g���Ńo���h�p�X�t�B���^�[�����삵�܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��ăo���h�p�X�t�B���^�[�̃J�b�g�I�t���g�����X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * ���K���J�b�g�I�t���g���́A�ΐ������24Hz�`24000Hz���A0.0f�`1.0f�ɐ��K�������l�ł��B<br>
 * �Ⴆ�΁A���K�����J�b�g�I�t���g����0.0f�A���K������J�b�g�I�t���g����1.0f�Ǝw�肷��ƁA
 * �o���h�p�X�t�B���^�[�͑S�悪�ʉ߂��A���K�����J�b�g�I�t���g�����グ��قǁA
 * �܂����K������J�b�g�I�t���g����������قǁA�ʉ߈悪�����Ȃ��Ă����܂��B<br>
 * \par ��:
 * \code
 * 	�F
 * // �t�B���^�[�̃p�����[�^�[��ݒ�
 * CriFloat32 cof_low = 0.0f;
 * CriFloat32 cof_high = 0.3f;
 * criAtomExPlayer_SetBandpassFilterParameters(player, cof_low, cof_high);
 * 
 * // �Đ��̊J�n
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p�����[�^�[�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p�����[�^�[�͕ύX����Ȃ��B
 * cof_low = 0.7f;
 * cof_high = 1.0f;
 * criAtomExPlayer_SetBandpassFilterParameters(player, cof_low, cof_high);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p�����[�^�[���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀo���h�p�X�t�B���^�[�̃p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �ȉ��̂悤�ɐݒ肳��܂��B
 * - cof_low<br>
 * 	�f�[�^�ɐݒ肳�ꂽ�l�ɑ΂��A�ucof_low_rev = 1.0f - cof_low�v�Ƃ��Ă����Z���A�ŏI�I�ɂ܂��ucof_low = 1.0f - cof_low_rev�v�ƌ��ɖ߂��ēK�p����܂��B<br>
 * 	�܂�A0.0f���u��摤�ɍł��t�B���^�[���J���v�Ƃ��āA�J�������Z���ēK�p���Ă����`�ɂȂ�܂��B
 * - cof_high<br>
 * 	�f�[�^�ɐݒ肳�ꂽ�l�ɑ΂��A��Z���ēK�p����܂��B<br>
 * 	�܂�A1.0f���u���摤�ɍł��t�B���^�[���J���v�Ƃ��āA�J�������Z���ēK�p���Ă����`�ɂȂ�܂��B
 * 
 * <br>
 * ���ۂɓK�p����鐳�K���J�b�g�I�t���g����1.0f�𒴂���l�ɂȂ����ꍇ�A�l��1.0f�ɃN���b�v����܂��B<br>
 * ���l�ɁA���ۂɓK�p����鐳�K���J�b�g�I�t���g����0.0f�����̒l�ɂȂ����ꍇ���A�l��0.0f�ɃN���b�v����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetBandpassFilterParameters(
	CriAtomExPlayerHn player, CriFloat32 cof_low, CriFloat32 cof_high);

/*JP
 * \brief �o�C�N�A�b�h�t�B���^�[�̃p�����[�^�[�ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	type		�t�B���^�[�^�C�v
 * \param[in]	frequency	���K�����g���i0.0f�`1.0f�j
 * \param[in]	gain		�Q�C���i�f�V�x���l�j
 * \param[in]	q_value		Q�l
 * \par ����:
 * �o�C�N�A�b�h�t�B���^�[�̊e��p�����[�^�[���w�肵�܂��B<br>
 * �{�֐��Ńp�����[�^�[��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�p�����[�^�[�Ńo�C�N�A�b�h�t�B���^�[�����삵�܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��ăo�C�N�A�b�h�t�B���^�[�̃p�����[�^�[���X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * ���K�����g���́A�ΐ������24Hz�`24000Hz���A0.0f�`1.0f�ɐ��K�������l�ł��B<br>
 * �Q�C���̓f�V�x���Ŏw�肵�܂��B<br>
 * �Q�C���̓t�B���^�[�^�C�v���ȉ��̏ꍇ�̂ݗL���ł��B<br>
 * - CRIATOMEX_BIQUAD_FILTER_TYPE_LOWSHELF�F���[�V�F���t�t�B���^�[
 * - CRIATOMEX_BIQUAD_FILTER_TYPE_HIGHSHELF�F�n�C�V�F���t�t�B���^�[
 * - CRIATOMEX_BIQUAD_FILTER_TYPE_PEAKING�F�s�[�L���O�t�B���^�[
 * 
 * \par ��:
 * \code
 * 	�F
 * // �t�B���^�[�̃p�����[�^�[��ݒ�
 * CriAtomExBiquadFilterType type = CRIATOMEX_BIQUAD_FILTER_TYPE_LOWPASS;
 * CriFloat32 frequency = 0.5f;
 * CriFloat32 gain = 1.0f;
 * CriFloat32 q_value = 3.0f;
 * criAtomExPlayer_SetBiquadFilterParameters(player, type, frequency, gain, q_value);
 * 
 * // �Đ��̊J�n
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p�����[�^�[�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p�����[�^�[�͕ύX����Ȃ��B
 * frequency = 0.7f;
 * criAtomExPlayer_SetBiquadFilterParameters(player, type, frequency, gain, q_value);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p�����[�^�[���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * - type<br>
 * 	�f�[�^�ɐݒ肳�ꂽ�l���㏑�����܂��B
 * - frequency<br>
 * 	�f�[�^�ɐݒ肳�ꂽ�l�ɉ��Z����܂��B
 * - gain<br>
 * 	�f�[�^�ɐݒ肳�ꂽ�l�ɏ�Z����܂��B
 * - q_value<br>
 *	�f�[�^�ɐݒ肳�ꂽ�l�ɉ��Z����܂��B
 * 
 * <br>
 * ���ۂɓK�p����鐳�K���J�b�g�I�t���g����1.0f�𒴂���l�ɂȂ����ꍇ�A�l��1.0f�ɃN���b�v����܂��B<br>
 * ���l�ɁA���ۂɓK�p����鐳�K���J�b�g�I�t���g����0.0f�����̒l�ɂȂ����ꍇ���A�l��0.0f�ɃN���b�v����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * HCA-MX�p�ɃG���R�[�h���ꂽ�����f�[�^�ɂ́A�o�C�N�A�b�h�t�B���^�[���K�p����܂���B<br>
 * �o�C�N�A�b�h�t�B���^�[���g�p�����������́AADX��HCA���A���̃R�[�f�b�N�ŃG���R�[�h���Ă��������B<br>
 * <br>
 * ASR�����p�ł�����ł́A�l�C�e�B�u�{�C�X�o�͎��Ƀt�B���^�[���g�p�ł��܂���B<br>
 * ASR�����p�\�Ȋ��Ńo�C�N�A�b�h�t�B���^�[���g�p�������ꍇ�ɂ́A
 * �o�̓T�E���h�����_����ASR�ɐݒ肷��K�v������܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetBiquadFilterParameters(
	CriAtomExPlayerHn player, CriAtomExBiquadFilterType type, CriFloat32 frequency,
	CriFloat32 gain, CriFloat32 q_value);

/*JP
 * \brief �{�C�X�v���C�I���e�B�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	priority	�{�C�X�v���C�I���e�B�i-255�`255�j
 * \par ����:
 * AtomEx�v���[���[�Ƀ{�C�X�v���C�I���e�B��ݒ肵�܂��B<br>
 * �{�֐��Ńv���C�I���e�B���Z�b�g��A ::criAtomExPlayer_Start �֐��ŉ������Đ�����ƁA
 * �Đ����ꂽ�����͖{�֐��ŃZ�b�g�����v���C�I���e�B�Ŕ�������܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̃v���C�I���e�B���X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �{�C�X�v���C�I���e�B�ɂ́A-255�`255�͈̔͂Ő����l���w�肵�܂��B<br>
 * �͈͊O�̒l��ݒ肵���ꍇ�A�͈͂Ɏ��܂�悤�ɃN���b�s���O����܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l��0�ł��B<br>
 * \par ���l:
 * AtomEx�v���[���[���g�`�f�[�^���Đ����悤�Ƃ����ہA
 * ���Y�g�`�f�[�^����������{�C�X���~�b�g�O���[�v�̔�����������ɒB���Ă����ꍇ��A
 * �{�C�X�v�[�����̃{�C�X���S�Ďg�p���ł������ꍇ�A
 * �{�C�X�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * �i�w�肳�ꂽ�g�`�f�[�^���Đ����邩�ǂ������A�{�C�X�v���C�I���e�B�����ɔ��肵�܂��B�j<br>
 * <br>
 * ��̓I�ɂ́A�Đ����s�����Ƃ����g�`�f�[�^�̃v���C�I���e�B���A
 * ���݃{�C�X�ōĐ����̔g�`�f�[�^�̃v���C�I���e�B���������ꍇ�A
 * AtomEx�v���[���[�͍Đ����̃{�C�X��D�����A���N�G�X�g���ꂽ�g�`�f�[�^�̍Đ����J�n���܂��B<br>
 * �i�Đ����̉�������~����A�ʂ̉������Đ�����܂��B�j<br>
 * <br>
 * �t�ɁA�Đ����s�����Ƃ����g�`�f�[�^�̃v���C�I���e�B���A
 * �{�C�X�ōĐ����̔g�`�f�[�^�̃v���C�I���e�B�����Ⴂ�ꍇ�A
 * AtomEx�v���[���[�̓��N�G�X�g���ꂽ�g�`�f�[�^�̍Đ����s���܂���B<br>
 * �i���N�G�X�g���ꂽ�����͍Đ����ꂸ�A�Đ����̉��������������葱���܂��B�j<br>
 * <br>
 * �Đ����悤�Ƃ����g�`�f�[�^�̃v���C�I���e�B���A
 * �{�C�X�ōĐ����̔g�`�f�[�^�̃v���C�I���e�B�Ɠ������ꍇ�A
 * AtomEx�v���[���[�͔�����������i�撅�D�� or �㒅�D��j�ɏ]���A
 * �ȉ��̂悤�Ȑ��䂪�s���܂��B<br>
 * - �撅�D�掞�́A�Đ����̔g�`�f�[�^��D�悵�A���N�G�X�g���ꂽ�g�`�f�[�^���Đ����܂���B
 * - �㒅�D�掞�́A���N�G�X�g���ꂽ�g�`�f�[�^��D�悵�A�{�C�X��D�����܂��B
 * 
 * <br>
 * �L���[�Đ����A�f�[�^���Ƀ{�C�X�v���C�I���e�B���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��ɂ��ݒ�l�Ƃ�<b>���Z</b>�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃v���C�I���e�B��255�AAtomEx�v���[���[�̃v���C�I���e�B��45�̏ꍇ�A
 * ���ۂɓK�p�����v���C�I���e�B��300�ɂȂ�܂��B<br>
 * �{�֐��Őݒ�\�Ȓl�͈̔͂�-255�`255�ł����A���C�u���������̌v�Z�� CriSint32 �͈̔͂ōs���邽�߁A
 * �f�[�^���Ɖ��Z�������ʂ�-255�`255�𒴂���ꍇ������܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �{�֐��́A�g�`�f�[�^�ɃZ�b�g���ꂽ<b>�{�C�X�v���C�I���e�B</b>�𐧌䂵�܂��B<br>
 * Atom Craft��ŃL���[�ɑ΂��Đݒ肳�ꂽ<b>�J�e�S���L���[�v���C�I���e�B</b>�ɂ͉e����^���܂���̂ŁA
 * �����ӂ��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetVoiceControlMethod, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetVoicePriority(
	CriAtomExPlayerHn player, CriSint32 priority);

/*JP
 * \brief AISAC�R���g���[���l�̐ݒ�i�R���g���[��ID�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	control_id		�R���g���[��ID
 * \param[in]	control_value	�R���g���[���l�i0.0f�`1.0f�j
 * \par ����:
 * �R���g���[��ID�w���AISAC�̃R���g���[���l���w�肵�܂��B<br>
 * �{�֐���AISAC�R���g���[���l��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽAISAC�R���g���[���l�ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ������AISAC�R���g���[���l���X�V���邱�Ƃ��ł��܂��B<br>
 * �ݒ肵���R���g���[���l���폜����ɂ́A::criAtomExPlayer_ClearAisacControls �֐����g�p���Ă��������B<br>
 * <br>
 * AISAC�R���g���[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * \par ��:
 * \code
 * 	�F
 * // AISAC�R���g���[���l�̐ݒ�
 * CriAtomExAisacControlId control_id = 0;
 * CriFloat32 control_value = 0.5f;
 * criAtomExPlayer_SetAisacControlById(player, control_id, control_value);
 * 
 * // �Đ��̊J�n
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p�����[�^�[�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p�����[�^�[�͕ύX����Ȃ��B
 * control_value = 0.3f;
 * criAtomExPlayer_SetAisacControlById(player, control_id, control_value);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p�����[�^�[���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * AISAC�̃R���g���[���^�C�v�ɂ���āA�ȉ��̂悤�ɋ������ς��܂��B
 * - �I�t
 * 		- �{�֐����ɂ��AISAC�R���g���[���l�����ݒ�̏ꍇ�͂���AISAC�͓��삵�܂���B
 * - �I�[�g���W�����[�V����
 * 		- �{�֐��̐ݒ�l�ɂ͉e�����ꂸ�A���Ԍo�߂ƂƂ��Ɏ����I��AISAC�R���g���[���l���ω����܂��B
 * - �����_��
 * 		- �{�֐����ɂ���Đݒ肳�ꂽAISAC�R���g���[���l�𒆉��l�Ƃ��āA�f�[�^�ɐݒ肳�ꂽ�����_�����Ń����_�}�C�Y���A�ŏI�I��AISAC�R���g���[���l�����肵�܂��B
 * 		- �����_�}�C�Y�����͍Đ��J�n���̃p�����[�^�[�K�p�ł̂ݍs���A�Đ����̉����ɑ΂���AISAC�R���g���[���l�ύX�͂ł��܂���B
 * 		- �Đ��J�n����AISAC�R���g���[���l���ݒ肳��Ă��Ȃ������ꍇ�A0.0f�𒆉��l�Ƃ��ă����_�}�C�Y�������s���܂��B
 * 		
 * 
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetAisacControlByName, criAtomExPlayer_ClearAisacControls, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetAisacControlById(
	CriAtomExPlayerHn player, CriAtomExAisacControlId control_id, CriFloat32 control_value);

/*JP
 * \brief AISAC�R���g���[���l�̐ݒ�i�R���g���[�����w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	control_name	�R���g���[����
 * \param[in]	control_value	�R���g���[���l�i0.0f�`1.0f�j
 * \par ����:
 * �R���g���[�����w���AISAC�̃R���g���[���l���w�肵�܂��B<br>
 * �{�֐���AISAC�R���g���[���l��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽAISAC�R���g���[���l�ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ������AISAC�R���g���[���l���X�V���邱�Ƃ��ł��܂��B<br>
 * �ݒ肵���R���g���[���l���폜����ɂ́A::criAtomExPlayer_ClearAisacControls �֐����g�p���Ă��������B<br>
 * <br>
 * AISAC�R���g���[���l�̈�����::criAtomExPlayer_SetAisacControlById �֐��Ɠ��l�ł��B<br>
 * \par ��:
 * \code
 * 	�F
 * // AISAC�R���g���[���l�̐ݒ�
 * const CriChar8 *control_name = "Any";
 * CriFloat32 control_value = 0.5f;
 * criAtomExPlayer_SetAisacControlByName(player, control_name, control_value);
 * 
 * // �Đ��̊J�n
 * id = criAtomExPlayer_Start(player);
 * 	�F
 * // �p�����[�^�[�̕ύX
 * // ���Ӂj���̎��_�ł͍Đ����̉����̃p�����[�^�[�͕ύX����Ȃ��B
 * control_value = 0.3f;
 * criAtomExPlayer_SetAisacControlByName(player, control_name, control_value);
 * 
 * // �v���[���[�ɐݒ肳�ꂽ�p�����[�^�[���Đ����̉����ɂ����f
 * criAtomExPlayer_Update(player, id);
 * 	�F
 * \endcode
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_SetAisacControlById, criAtomExPlayer_ClearAisacControls, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetAisacControlByName(
	CriAtomExPlayerHn player, const CriChar8 *control_name, CriFloat32 control_value);

/*JP
 * \brief �v���[���[�ɐݒ肳��Ă���AISAC�R���g���[���l�̍폜
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \par ����:
 * �v���[���[�ɐݒ肳��Ă���AISAC�R���g���[���l��S�č폜���܂��B<br>
 * �܂��폜��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����̉����ɑ΂���AISAC�R���g���[���l�̍폜���s���܂��B
 * \sa criAtomExPlayer_SetAisacControlById, criAtomExPlayer_SetAisacControlByName, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll
 */
void CRIAPI criAtomExPlayer_ClearAisacControls(CriAtomExPlayerHn player);


/*JP
 * \brief 3D�����n���h���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	source		3D�����n���h��
 * \par ����:
 * 3D�|�W�V���j���O���������邽�߂�3D�����n���h����ݒ肵�܂��B<br>
 * 3D���X�i�[�n���h����3D�����n���h����ݒ肷�邱�ƂŁA3D���X�i�[�n���h����3D�����n���h���̈ʒu�֌W�������ʂ≹�ʁA�s�b�`���������I�ɓK�p����܂��B<br>
 * �{�֐���3D�����n���h����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ3D�����n���h�����Q�Ƃ��čĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�������Q�Ƃ���3D�����n���h����ύX���邱�Ƃ��ł��܂��B<br>
 * source��NULL��ݒ肵���ꍇ�́A���łɐݒ肳��Ă���3D�����n���h�����N���A���܂��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * 3D�����n���h���̃p�����[�^�[�̕ύX�A�X�V�́AAtomEx�v���[���[�̊֐��ł͂Ȃ��A3D�����n���h���̊֐����g�p���čs���܂��B<br>
 * �f�t�H���g�ł́A3D�|�W�V���j���O�̌v�Z�͍�����W�n�ōs���܂��B<br>
 * �E����W�n�Ŋe��x�N�g����ݒ肷��ꍇ�́A���C�u�������������i ::criAtomEx_Initialize �֐� �j�̐ݒ��
 * ::CriAtomExConfig::coordinate_system ��CRIATOMEX_COORDINATE_SYSTEM_RIGHT_HANDED ���w�肵�Ă��������B<br>
 * ACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�́A�����I��3D�|�W�V���j���O��L���ɂ��邽�߂ɁA::criAtomExSetPanType �֐���::CRIATOMEX_PAN_TYPE_3D_POS��ݒ肷��K�v������܂��B<br>
 * <br>
 * �{�֐��� ::criAtomExPlayer_Set3dSourceListHn �֐��͂��݂��ɐݒ���㏑�����܂��B<br>
 * �Ⴆ�΁A ::criAtomExPlayer_Set3dSourceListHn �֐��ɂ�3D�����n���h�����X�g��AtomEx�v���[���[�ɐݒ��A�{�֐��ɂ�AtomEx�v���[���[��3D�����n���h����ݒ肷��ƁA
 * AtomEx�v���[���[�ɂ͐V����3D�����n���h�����ݒ肳��A���ɐݒ肳��Ă���3D�����n���h�����X�g��AtomEx�v���[���[����N���A����܂��B
 * <br>
 * �{�֐���p����AtomEx�v���[���[�ɐݒ肳�ꂽ3D�����n���h���́A3D�����n���h�����X�g�ɒǉ����邱�Ƃ͂ł��܂���B
 * ����3D�����n���h�����X�g�ɒǉ�����ꍇ�́A���ɐݒ肳��Ă���AtomEx�v���[���[��3D�����n���h���Ɋւ���ݒ���N���A���Ă��������B
 * \par ��:
 * \code
 * CriAtomEx3dListenerHn listener;
 * CriAtomEx3dSourceHn source;
 * CriAtomExVector pos;
 *
 * listener = criAtomEx3dListener_Create(NULL, NULL, 0);
 * source = criAtomEx3dSource_Create(NULL, NULL, 0);
 * player = criAtomExPlayer_Create(NULL, NULL, 0);
 * criAtomExPlayer_Set3dListenerHn(player, listener);
 * criAtomExPlayer_Set3dSourceHn(player, source);
 *
 * pos.x = 0.0f;
 * pos.y = 0.0f;
 * pos.z = 0.0f;
 * criAtomEx3dSource_SetPosition(source, &pos);
 * criAtomEx3dSource_Update(source);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * pos.x += 10.0f;
 * criAtomEx3dSource_SetPosition(source, &pos);
 * criAtomEx3dSource_Update(source);
 * \endcode
 * \sa CriAtomEx3dSourceHn, CriAtomEx3dSourceListHn, criAtomExPlayer_Set3dSourceListHn, criAtomEx3dListenerHn, criAtomExPlayer_SetListenerHn, criAtomExPlayer_Update, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_Set3dSourceHn(
	CriAtomExPlayerHn player, CriAtomEx3dSourceHn source);

/*JP
 * \brief 3D�����n���h�����X�g�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	source_list		3D�����n���h�����X�g
 * \par ����:
 * �}���`�|�W�V���j���O�Đ����������邽�߂�3D�����n���h�����X�g��ݒ肵�܂��B<br>
 * 3D���X�i�[�n���h����3D�����n���h�����X�g��ݒ肷�邱�ƂŁA3D���X�i�[�n���h����3D�����n���h�����X�g����
 * �S�Ă�3D�����n���h���̈ʒu�֌W�������ʂ≹�ʁA�s�b�`���������I�ɓK�p����܂��B<br>
 * �{�֐���3D�����n���h�����X�g��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ3D�����n���h�����X�g���Q�Ƃ��čĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�������Q�Ƃ���3D�����n���h�����X�g��ύX���邱�Ƃ��ł��܂��B<br>
 * source_list��NULL��ݒ肵���ꍇ�́A���łɐݒ肳��Ă���3D�����n���h�����X�g���N���A���܂��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * 3D�����n���h�����X�g�ɒǉ�����Ă���3D�����n���h���̕ύX�A�X�V�́AAtomEx�v���[���[�̊֐��ł͂Ȃ��A3D�����n���h���̊֐����g�p���čs���܂��B<br>
 * �E����W�n�Ŋe��x�N�g����ݒ肷��ꍇ�́A���C�u�������������i ::criAtomEx_Initialize �֐� �j�̐ݒ��
 * ::CriAtomExConfig::coordinate_system ��CRIATOMEX_COORDINATE_SYSTEM_RIGHT_HANDED ���w�肵�Ă��������B<br>
 * ACB�t�@�C�����g�p�����ɉ������Đ�����ꍇ�́A�����I��3D�|�W�V���j���O��L���ɂ��邽�߂ɁA::criAtomExSetPanType �֐���::CRIATOMEX_PAN_TYPE_3D_POS��ݒ肷��K�v������܂��B<br>
 * <br>
 * �{�֐��� ::criAtomExPlayer_Set3dSourceHn �֐��͂��݂��ɐݒ���㏑�����܂��B<br>
 * �Ⴆ�΁A ::criAtomExPlayer_Set3dSourceHn �֐��ɂ�3D�����n���h����AtomEx�v���[���[�ɐݒ��A�{�֐��ɂ�AtomEx�v���[���[��3D�����n���h�����X�g��ݒ肷��ƁA
 * AtomEx�v���[���[�ɂ͐V����3D�����n���h�����X�g���ݒ肳��A���ɐݒ肳��Ă���3D�����n���h����AtomEx�v���[���[����N���A����܂��B
 * \par ��:
 * \code
 * CriAtomEx3dListenerHn listener;
 * CriAtomEx3dSourceListHn source_list;
 * CriAtomEx3dSourceHn source[8];
 * CriAtomExVector pos[8];
 * CriSint32 i;
 *
 * listener = criAtomEx3dListener_Create(NULL, NULL, 0);
 * source_list = criAtomEx3dSourceList_Create(NULL, NULL, 0);
 * for (i = 0; i < 8; i++) {
 *     source[i] = criAtomEx3dSource_Create(NULL, NULL, 0);
 * 
 *     pos[i].x = (CriFloat32)i;
 *     pos[i].y = 0.0f;
 *     pos[i].z = 0.0f;
 *     criAtomEx3dSource_SetPosition(source, &pos);
 *     criAtomEx3dSource_Update(source);
 * 
 *     criAtomEx3dSourceList_Add(source_list, source[i]);
 * }
 * 
 * player = criAtomExPlayer_Create(NULL, NULL, 0);
 * criAtomExPlayer_Set3dListenerHn(player, listener);
 * criAtomExPlayer_Set3dSourceListHn(player, source_list);
 *
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * pos[2].x += 25.0f;
 * criAtomEx3dSource_SetPosition(source[2], &pos);
 * criAtomEx3dSource_Update(source[2]);
 * pos[5].z += 10.0f;
 * criAtomEx3dSource_SetPosition(source[5], &pos);
 * criAtomEx3dSource_Update(source[5]);
 * \endcode
 * \sa CriAtomEx3dSourceListHn, CriAtomEx3dSourceHn, criAtomExPlayer_Set3dSourceHn, CriAtomEx3dListenerHn, CriAtomExPlayer_Set3dListenerHn, criAtomExPlayer_Update, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_Set3dSourceListHn(
	CriAtomExPlayerHn player, CriAtomEx3dSourceListHn source_list);

/*JP
 * \brief 3D���X�i�[�n���h���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	listener	3D���X�i�[�n���h��
 * \par ����:
 * 3D�|�W�V���j���O���������邽�߂�3D���X�i�[�n���h����ݒ肵�܂��B<br>
 * 3D���X�i�[�n���h����3D�����n���h���܂���3D�����n���h�����X�g��ݒ肷�邱�ƂŁA3D���X�i�[��3D�����n���h���܂���
 * 3D�����n���h�����X�g���̑S�Ă�3D�����n���h���̈ʒu�֌W�������ʂ≹�ʁA�s�b�`���������I�ɓK�p����܂��B<br>
 * �{�֐���3D���X�i�[�n���h����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ3D���X�i�[�n���h�����Q�Ƃ��čĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�������Q�Ƃ���3D���X�i�[�n���h����ύX���邱�Ƃ��ł��܂��B<br>
 * listener��NULL��ݒ肵���ꍇ�́A���łɐݒ肳��Ă���3D���X�i�[�n���h�����N���A���܂��B<br>
 * \par ���l:
 * �{�֐���3D���X�i�[�n���h����ݒ肵�Ă��Ȃ��Ă��A�ȉ��̏����𖞂����Ă���ꍇ�͎����I��3D�����ɑ΂��čł������̋߂�3D���X�i�[�����蓖�Ă��܂��B<br>
 *  - 3D�����n���h���܂���3D�����n���h�����X�g���ݒ肳��Ă���
 *  - 3D���X�i�[��criAtomEx3dListener_Create�ɂ���č쐬����Ă���
 * 	
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * 3D���X�i�[�n���h���̃p�����[�^�[�̕ύX�A�X�V�́AAtomEx�v���[���[�̊֐��ł͂Ȃ��A3D���X�i�[�n���h���̊֐����g�p���čs���܂��B<br>
 * �f�t�H���g�ł́A3D�|�W�V���j���O�̌v�Z�͍�����W�n�ōs���܂��B<br>
 * �E����W�n�Ŋe��x�N�g����ݒ肷��ꍇ�́A���C�u�������������i ::criAtomEx_Initialize �֐� �j�̐ݒ��
 * ::CriAtomExConfig::coordinate_system ��CRIATOMEX_COORDINATE_SYSTEM_RIGHT_HANDED ���w�肵�Ă��������B<br>
 * <br>
 * \par ��:
 * \code
 * CriAtomEx3dListenerHn listener;
 * CriAtomEx3dSourceHn source;
 * CriAtomExVector pos;
 *
 * listener = criAtomEx3dListener_Create(NULL, NULL, 0);
 * source = criAtomEx3dSource_Create(NULL, NULL, 0);
 * player = criAtomExPlayer_Create(NULL, NULL, 0);
 * criAtomExPlayer_Set3dListenerHn(player, listener);
 * criAtomExPlayer_Set3dSourceHn(player, source);
 *
 * pos.x = 0.0f;
 * pos.y = 0.0f;
 * pos.z = 0.0f;
 * criAtomEx3dSource_SetPosition(source, &pos);
 * criAtomEx3dSource_Update(source);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * pos.x += 10.0f;
 * criAtomEx3dSource_SetPosition(source, &pos);
 * criAtomEx3dSource_Update(source);
 * \endcode
 * \sa CriAtomEx3dListenerHn, criAtomExPlayer_Set3dSourceHn, criAtomExPlayer_Update, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_Set3dListenerHn(
	CriAtomExPlayerHn player, CriAtomEx3dListenerHn listener);

/*JP
 * \brief AISAC�R���g���[���l�̎擾�i�R���g���[��ID�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	control_id		�R���g���[��ID
 * \return		CriFloat32		�R���g���[���l�i0.0f�`1.0f�j�A���ݒ莞��-1.0f
 * \par ����:
 * �R���g���[��ID�w���AISAC�̃R���g���[���l���擾���܂��B<br>
 * �w�肵���R���g���[��ID��AISAC�R���g���[���l���ݒ肳��Ă��Ȃ������ꍇ�A-1.0f��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́AAtomEx�v���[���[�ɐݒ肳�ꂽAISAC�R���g���[���l���擾���܂��B<br>
 * �Đ����̉�����AISAC�R���g���[���l��ύX����AISAC���ݒ肳��Ă����Ƃ��Ă��A���̕ύX���ʂ��擾���邱�Ƃ͂ł��܂���B
 * \par ��:
 * \code
 * CriAtomExAisacControlId control_id = 0;
 * CriFloat32 control_value = 0.5f;
 * // Set AISAC control value
 * criAtomExPlayer_SetAisacControlById(player, control_id, control_value);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Get AISAC control value
 * control_value = criAtomExPlayer_GetAisacControlById(player, control_id);
 * \endcode
 * \sa criAtomExPlayer_SetAisacControlById, criAtomExPlayer_GetAisacControlByName
 */
CriFloat32 CRIAPI criAtomExPlayer_GetAisacControlById(
	CriAtomExPlayerHn player, CriAtomExAisacControlId control_id);

/*JP
 * \brief AISAC�R���g���[���l�̎擾�i�R���g���[�����w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	control_name	�R���g���[����
 * \return		CriFloat32		�R���g���[���l�i0.0f�`1.0f�j�A���ݒ莞��-1.0f
 * \par ����:
 * �R���g���[�����w���AISAC�̃R���g���[���l���擾���܂��B<br>
 * �w�肵���R���g���[������AISAC�R���g���[���l���ݒ肳��Ă��Ȃ������ꍇ�A-1.0f��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́AAtomEx�v���[���[�ɐݒ肳�ꂽAISAC�R���g���[���l���擾���܂��B<br>
 * �Đ����̉�����AISAC�R���g���[���l��ύX����AISAC���ݒ肳��Ă����Ƃ��Ă��A���̕ύX���ʂ��擾���邱�Ƃ͂ł��܂���B
 * \par ��:
 * \code
 * const CriChar8 *control_name = "Any";
 * CriFloat32 control_value = 0.5f;
 * // Set AISAC control value
 * criAtomExPlayer_SetAisacControlByName(player, control_name, control_value);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Get AISAC control value
 * control_value = criAtomExPlayer_GetAisacControlByName(player, control_name);
 * \endcode
 * \sa criAtomExPlayer_SetAisacControlByName, criAtomExPlayer_GetAisacControlById
 */
CriFloat32 CRIAPI criAtomExPlayer_GetAisacControlByName(
	CriAtomExPlayerHn player, const CriChar8 *control_name);

/*JP
 * \brief �J�e�S���̐ݒ�iID�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	category_id		�J�e�S��ID
 * \par ����:
 * �J�e�S��ID�w��ŃJ�e�S����ݒ肵�܂��B<br>
 * �ݒ肵���J�e�S�������폜����ɂ́A ::criAtomExPlayer_UnsetCategory �֐����g�p���܂��B<br>
 * \par ���l:
 * �L���[�Đ����ɖ{�֐����Ăяo���ƁA�f�[�^���ɐݒ肳��Ă���J�e�S���ݒ�ƃ}�[�W����܂��B
 * ���̍ہA�J�e�S���O���[�v���������Ă���ꍇ�ɂ͖{�֐��̐ݒ肪�L���ɂȂ�܂��B
 * CRI Atom���C�u���� Ver.2.20.31�����ł�
 * �f�[�^���ɐݒ肳��Ă���J�e�S���ݒ��<b>�㏑��</b>���Ă��܂����B�i�f�[�^���̐ݒ�l�͖�������Ă����j�B<br>
 * �]���̎d�l�œ��삳�������ꍇ�̓��C�u�������������i ::criAtomEx_Initialize �֐� �j��
 * ::CriAtomExConfig::enable_category_override_by_ex_player ��CRI_TRUE��ݒ肵�Ă��������B
 * �{�֐��Őݒ肵���J�e�S�����́AACF�̃��W�X�g�A�A�����W�X�g���s���ƃN���A����܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \par ��:
 * \code
 * // Set default category
 * criAtomExPlayer_SetCategoryById(player, (CriUint32)CRIATOMEXCATEGORY_DEFAULT_ID_BGM);
 * \endcode
 * \attention
 * �J�e�S���ݒ�͍Đ��J�n�O�ɍs���Ă��������B�Đ����̉����ɑ΂��ăJ�e�S���ݒ�̍X�V���s���ƁA�J�e�S���̍Đ����J�E���g���ُ�ɂȂ�댯������܂��B<br>
 * \sa criAtomExPlayer_UnsetCategory, criAtomExPlayer_SetCategoryByName, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetCategoryById(
	CriAtomExPlayerHn player, CriUint32 category_id);

/*JP
 * \brief �J�e�S���̐ݒ�i�J�e�S�����w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	category_name	�J�e�S����
 * \par ����:
 * �J�e�S�����w��ŃJ�e�S����ݒ肵�܂��B<br>
 * �ݒ肵���J�e�S�������폜����ɂ́A ::criAtomExPlayer_UnsetCategory �֐����g�p���܂��B<br>
 * \par ���l:
 * �J�e�S���w��𖼑O�ōs�����Ƃ������A��{�I�Ȏd�l��::criAtomExPlayer_SetCategoryById �֐��Ɠ��l�ł��B
 * �f�t�H���g�J�e�S�����ł̎w����s���ꍇ�� CRIATOMEXCATEGORY_DEFAULT_NAME_??? ���g�p���Ă��������B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \par ��:
 * \code
 * // Set default category
 * criAtomExPlayer_SetCategoryByName(player, CRIATOMEXCATEGORY_DEFAULT_NAME_BGM);
 * \endcode
 * \sa criAtomExPlayer_UnsetCategory, criAtomExPlayer_SetCategoryById, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetCategoryByName(
	CriAtomExPlayerHn player, const CriChar8 *category_name);

/*JP
 * \brief �J�e�S���̍폜
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \par ����:
 * �v���[���[�n���h���ɐݒ肳��Ă���J�e�S�������폜���܂��B<br>
 * \par ��:
 * \code
 * // Unset category
 * criAtomExPlayer_UnsetCategory(player);
 * \endcode
 * \sa criAtomExPlayer_SetCategoryByName, criAtomExPlayer_SetCategoryById
 */
void CRIAPI criAtomExPlayer_UnsetCategory(CriAtomExPlayerHn player);

/*JP
 * \brief �J�e�S�����̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return		CriSint32	�J�e�S����
 * \par ����:
 * �v���[���[�n���h���ɐݒ肳��Ă���J�e�S���̐����擾���܂��B
 */
CriSint32 CRIAPI criAtomExPlayer_GetNumCategories(CriAtomExPlayerHn player);

/*JP
 * \brief �J�e�S�����̎擾�i�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	index		�C���f�b�N�X
 * \param[out]	info		�J�e�S�����
 * \return		CriBool		��񂪎擾�ł������ǂ����H�i�擾�ł����FCRI_TRUE�^�擾�ł��Ȃ��FCRI_FALSE�j
 * \par ����:
 * �C���f�b�N�X���w�肵�ăv���[���[�n���h���ɐݒ肳��Ă���J�e�S�������擾���܂��B<br>
 * �w�肵���C���f�b�N�X�̃J�e�S�������݂��Ȃ��ꍇ�ACRI_FALSE���Ԃ�܂��B
 */
CriBool CRIAPI criAtomExPlayer_GetCategoryInfo(CriAtomExPlayerHn player, CriUint16 index, CriAtomExCategoryInfo* info);

/*JP
 * \brief �g���b�N���̎w��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player				AtomEx�v���[���[�n���h��
 * \param[in]	num_tracks			�g���b�N��
 * \param[in]	channels_per_track	�g���b�N������̃`�����l����
 * \par ����:
 * �}���`�`�����l�������̃g���b�N�\�����w�肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁA6ch�̉����f�[�^�����m����6�g���b�N�̉�����A
 * �X�e���I3�g���b�N�̉����Ƃ��Ĉ������Ƃ��\�ɂȂ�܂��B<br>
 * \par ��:
 * \code
 * 		�F
 * 	// �g���b�N���̐ݒ�
 * 	// ���l�j6ch�̉������X�e���I3�g���b�N�Ƃ��Ĉ���
 * 	CriSint32 channels_per_track[3] = { 2, 2, 2 };
 * 	criAtomExPlayer_SetTrackInfo(params.player, 3, channels_per_track);
 * 		�F
 * 	// �g���b�N���ƂɃ{�����[����ݒ�
 * 	criAtomExPlayer_SetTrackVolume(params.player, 0, 1.0f);
 * 	criAtomExPlayer_SetTrackVolume(params.player, 1, 0.5f);
 * 	criAtomExPlayer_SetTrackVolume(params.player, 2, 0.25f);
 * 		�F
 * \endcode
 * \attention
 * �{�֐��͓����I�� ::criAtomExPlayer_SetSendLevel �֐����g�p���Ă��܂��B<br>
 * ���̂��߁A�{�֐����s��� ::criAtomExPlayer_SetSendLevel �֐����g�p�����ꍇ�A
 * �����̏o�͈ʒu��o�̓{�����[�����Ӑ}�Ƃ��Ȃ����ʂɂȂ�\��������܂��B<br>
 * �i���l�ɁA ::criAtomExPlayer_SetPan3dAngle �֐��� ::criAtomExPlayer_SetSendLevel 
 * �֐������p�ł��܂���B�j<br>
 * �{�֐��́A�R�`�����l���ȏ�̓��͂ɑΉ������@��ł������p�ł��܂���B<br>
 * �Q�`�����l���i�X�e���I�j�ȉ��̓��͂܂ł����Ή����Ă��Ȃ��@��ł̓����N�G���[�ƂȂ�܂��B<br>
 * \sa criAtomExPlayer_SetTrackVolume
 */
void CRIAPI criAtomExPlayer_SetTrackInfo(CriAtomExPlayerHn player,
	CriSint32 num_tracks, const CriSint32 *channels_per_track);

/*JP
 * \brief �g���b�N�̃{�����[���ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	track_no	�g���b�N�ԍ�
 * \param[in]	volume		�g���b�N�̃{�����[��
 * \par ����:
 * �g���b�N���Ƃ̃{�����[����ݒ肵�܂��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �{�֐��� ::criAtomExPlayer_SetTrackInfo �֐��Ńg���b�N����ݒ肵��
 * �v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * <br>
 * �{�֐��͓����I�� ::criAtomExPlayer_SetSendLevel �֐����g�p���Ă��܂��B<br>
 * ���̂��߁A�{�֐����s��� ::criAtomExPlayer_SetSendLevel �֐����g�p�����ꍇ�A
 * �����̏o�͈ʒu��o�̓{�����[�����Ӑ}�Ƃ��Ȃ����ʂɂȂ�\��������܂��B<br>
 * �i���l�ɁA ::criAtomExPlayer_SetPan3dAngle �֐��� ::criAtomExPlayer_SetSendLevel 
 * �֐������p�ł��܂���B�j<br>
 * �{�֐��́A�R�`�����l���ȏ�̓��͂ɑΉ������@��ł������p�ł��܂���B<br>
 * �Q�`�����l���i�X�e���I�j�ȉ��̓��͂܂ł����Ή����Ă��Ȃ��@��ł̓����N�G���[�ƂȂ�܂��B<br>
 * \sa criAtomExPlayer_SetTrackInfo, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetTrackVolume(
	CriAtomExPlayerHn player, CriSint32 track_no, CriFloat32 volume);

/*JP
 * \brief �������������[�h�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	silent_mode	�������������[�h
 * \par ����:
 * �������������[�h���w�肵�܂��B<br>
 * �{�֐��Ŗ������������[�h��ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�������������[�h�ōĐ�����܂��B<br>
 * �܂��ݒ��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����̖������������[�h���X�V���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �������������[�h�̏ڍׂ́A::CriAtomExSilentMode ���Q�Ƃ��Ă��������B<br>
 * �������������[�h�̃f�t�H���g�l��::CRIATOMEX_SILENT_MODE_NORMAL �ł��B<br>
 * \par ��:
 * \code
 * // Set silent mode
 * criAtomExPlayer_SetSilentMode(player, CRIATOMEX_SILENT_MODE_STOP);
 * // Start playback
 * id = criAtomExPlayer_Start(player);
 *                :
 * // Change volume to silent
 * volume = 0.0f;
 * criAtomExPlayer_SetVolume(player, volume);
 * criAtomExPlayer_Update(player, id);
 * \endcode
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa CriAtomExSilentMode, criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetSilentMode(
	CriAtomExPlayerHn player, CriAtomExSilentMode silent_mode);

/*JP
 * \brief �L���[�v���C�I���e�B�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	cue_priority	�L���[�v���C�I���e�B
 * \par ����:
 * AtomEx�v���[���[�ɃL���[�v���C�I���e�B��ݒ肵�܂��B<br>
 * �{�֐��ŃL���[�v���C�I���e�B���Z�b�g��A ::criAtomExPlayer_Start �֐��ŉ������Đ�����ƁA
 * �Đ����ꂽ�����͖{�֐��ŃZ�b�g�����L���[�v���C�I���e�B�Ŕ�������܂��B<br>
 * �֐����s�O�̃f�t�H���g�ݒ�l��0�ł��B<br>
 * \par ���l:
 * AtomEx�v���[���[���L���[���Đ������ہA�Đ�����L���[�̏�����J�e�S�������~�b�g��
 * �������ς݂̏ꍇ�A�v���C�I���e�B�ɂ�锭�����䂪�s���܂��B<br>
 * ��̓I�ɂ́AAtomEx�v���[���[�̍Đ����N�G�X�g���A�Đ����̃L���[�̃v���C�I���e�B����
 * �����ꍇ�AAtomEx�v���[���[�͍Đ����̃L���[���~���A���N�G�X�g�ɂ��Đ����J�n���܂��B<br>
 * �i�Đ����̉�������~����A�ʂ̉������Đ�����܂��B�j<br>
 * �t�ɁAAtomEx�v���[���[�̍Đ����N�G�X�g���A�Đ����̃L���[�̃v���C�I���e�B�����Ⴂ�ꍇ�A
 * AtomEx�v���[���[�̍Đ����N�G�X�g�����ۂ���܂��B<br>
 * �i���N�G�X�g���ꂽ�L���[�͍Đ�����܂���B�j<br>
 * AtomEx�v���[���[�̍Đ����N�G�X�g���A�Đ����̃L���[�̃v���C�I���e�B�Ɠ������ꍇ�A
 * AtomEx�v���[���[�͌㒅�D��Ŕ���������s���܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetCuePriority(
	CriAtomExPlayerHn player, CriSint32 cue_priority);

/*JP
 * \brief �v���f�B���C�^�C���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player				AtomEx�v���[���[�n���h��
 * \param[in]	predelay_time_ms	�v���f�B���C�i0.0f�`10000.0f�j
 * \par ����:
 * �v���f�B���C�^�C����ݒ肵�܂��B<br>
 * �{�֐��Ńv���f�B���C�^�C����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA
 * �ݒ肳�ꂽ�v���f�B���C�^�C��������҂��܂��B<br>
 * <br>
 * �v���f�B���C�^�C���ɂ́A0.0f�`10000.0f�͈̔͂Ŏ����l���w�肵�܂��B�P�ʂ�ms�i�~���b�j�ł��B<br>
 * �v���f�B���C�^�C���̃f�t�H���g�l��0.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀv���f�B���C�^�C�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�Ɩ{�֐��̐ݒ�l��<b>���Z</b>�����l���K�p����܂��B<br>
 * \sa criAtomExPlayer_Start
 */
void CRIAPI criAtomExPlayer_SetPreDelayTime(
	CriAtomExPlayerHn player, CriFloat32 predelay_time_ms);

/*JP
 * \brief �G���x���[�v�̃A�^�b�N�^�C���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	attack_time_ms	�A�^�b�N�^�C���i0.0f�`2000.0f�j
 * \par ����:
 * �G���x���[�v�̃A�^�b�N�^�C����ݒ肵�܂��B<br>
 * �{�֐��ŃA�^�b�N�^�C����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�A�^�b�N�^�C���ōĐ�����܂��B<br>
 * <br>
 * �A�^�b�N�^�C���ɂ́A0.0f�`2000.0f�͈̔͂Ŏ����l���w�肵�܂��B�P�ʂ�ms�i�~���b�j�ł��B<br>
 * �A�^�b�N�^�C���̃f�t�H���g�l��0.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ��:
 * \code
 * CriFloat32 attack_time_ms = 10.0f;
 * // Set attack time
 * criAtomExPlayer_SetEnvelopeAttackTime(player, attack_time_ms);
 * // Start playback(attack time=10ms)
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���ɃA�^�b�N�^�C�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l��<b>�㏑��</b>���ēK�p����܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetEnvelopeAttackTime(
	CriAtomExPlayerHn player, CriFloat32 attack_time_ms);

/*JP
 * \brief �G���x���[�v�̃z�[���h�^�C���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	hold_time_ms	�z�[���h�^�C���i0.0f�`2000.0f�j
 * \par ����:
 * �G���x���[�v�̃z�[���h�^�C����ݒ肵�܂��B<br>
 * �{�֐��Ńz�[���h�^�C����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�z�[���h�^�C���ōĐ�����܂��B<br>
 * <br>
 * �z�[���h�^�C���ɂ́A0.0f�`2000.0f�͈̔͂Ŏ����l���w�肵�܂��B�P�ʂ�ms�i�~���b�j�ł��B<br>
 * �z�[���h�^�C���̃f�t�H���g�l��0.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ��:
 * \code
 * CriFloat32 hold_time_ms = 10.0f;
 * // Set hold time
 * criAtomExPlayer_SetEnvelopeHoldTime(player, hold_time_ms);
 * // Start playback(hold time=10ms)
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀz�[���h�^�C�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l��<b>�㏑��</b>���ēK�p����܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetEnvelopeHoldTime(
	CriAtomExPlayerHn player, CriFloat32 hold_time_ms);

/*JP
 * \brief �G���x���[�v�̃f�B�P�C�^�C���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	decay_time_ms	�f�B�P�C�^�C���i0.0f�`2000.0f�j
 * \par ����:
 * �G���x���[�v�̃f�B�P�C�^�C����ݒ肵�܂��B<br>
 * �{�֐��Ńf�B�P�C�^�C����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�f�B�P�C�^�C���ōĐ�����܂��B<br>
 * <br>
 * �f�B�P�C�^�C���ɂ́A0.0f�`2000.0f�͈̔͂Ŏ����l���w�肵�܂��B�P�ʂ�ms�i�~���b�j�ł��B<br>
 * �f�B�P�C�^�C���̃f�t�H���g�l��0.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ��:
 * \code
 * CriFloat32 decay_time_ms = 10.0f;
 * // Set decay time
 * criAtomExPlayer_SetEnvelopeDecayTime(player, decay_time_ms);
 * // Start playback(decay time=10ms)
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀf�B�P�C�^�C�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l��<b>�㏑��</b>���ēK�p����܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetEnvelopeDecayTime(
	CriAtomExPlayerHn player, CriFloat32 decay_time_ms);

/*JP
 * \brief �G���x���[�v�̃����[�X�^�C���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	release_time_ms	�����[�X�^�C���i0.0f�`10000.0f�j
 * \par ����:
 * �G���x���[�v�̃����[�X�^�C����ݒ肵�܂��B<br>
 * �{�֐��Ń����[�X�^�C����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�����[�X�^�C���ōĐ�����܂��B<br>
 * <br>
 * �����[�X�^�C���ɂ́A0.0f�`10000.0f�͈̔͂Ŏ����l���w�肵�܂��B�P�ʂ�ms�i�~���b�j�ł��B<br>
 * �����[�X�^�C���̃f�t�H���g�l��0.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ��:
 * \code
 * CriFloat32 release_time_ms = 3000.0f;
 * // Set release time
 * criAtomExPlayer_SetEnvelopeReleaseTime(player, release_time_ms);
 * // Start playback(release time=3000ms)
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀ����[�X�^�C�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l��<b>�㏑��</b>���ēK�p����܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetEnvelopeReleaseTime(
	CriAtomExPlayerHn player, CriFloat32 release_time_ms);

/*JP
 * \brief �G���x���[�v�̃T�X�e�B�����x���̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	susutain_level	�T�X�e�B�����x���i0.0f�`1.0f�j
 * \par ����:
 * �G���x���[�v�̃T�X�e�B�����x����ݒ肵�܂��B<br>
 * �{�֐��ŃT�X�e�B�����x����ݒ��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�ݒ肳�ꂽ�T�X�e�B�����x���ōĐ�����܂��B<br>
 * <br>
 * �T�X�e�B�����x���ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �T�X�e�B�����x���̃f�t�H���g�l��1.0f�ł��B<br>
 * \attention
 * �Đ�����::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐��ɂ���čX�V���邱�Ƃ͂ł��܂���B<br>
 * \par ��:
 * \code
 * CriFloat32 susutain_level = 0.5f;
 * // Set susutain level
 * criAtomExPlayer_SetEnvelopeSustainLevel(player, susutain_level);
 * // Start playback(sustain level=0.5)
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���ɃT�X�e�B�����x�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l��<b>�㏑��</b>���ēK�p����܂��i�f�[�^���̐ݒ�l�͖�������܂��j�B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetEnvelopeSustainLevel(
	CriAtomExPlayerHn player, CriFloat32 susutain_level);

/*JP
 * \brief �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	func		�f�[�^�v���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�[�^�v���R�[���o�b�N�֐��̓o�^���s���܂��B<br>
 * <br>
 * �f�[�^�v���R�[���o�b�N�́A�����̉����f�[�^���V�[�����X�ɘA�����čĐ�����ۂ�
 * �g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�{�C�X�������I�Ɏg�p���Ă��� Atom �v���[���[��
 * �A���Đ��p�̃f�[�^��v������^�C�~���O�Ŏ��s����܂��B<br>
 * �i�O��̃f�[�^��ǂݍ��ݏI���āA���ɍĐ����ׂ��f�[�^��v������^�C�~���O��
 * �R�[���o�b�N�֐������s����܂��B�j<br>
 * �o�^�����R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐�����p���� Atom �v���[���[��
 * �f�[�^���Z�b�g����ƁA�Z�b�g���ꂽ�f�[�^�͌��ݍĐ����̃f�[�^�ɑ����ăV�[�����X��
 * �A������čĐ�����܂��B<br>
 * �܂��A�R�[���o�b�N�֐����� ::criAtomPlayer_SetPreviousDataAgain �֐������s���邱�ƂŁA
 * ����f�[�^���J��Ԃ��Đ��������邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * �o�^�����R�[���o�b�N�֐����Ńf�[�^���w�肵�Ȃ������ꍇ�A���݂̃f�[�^���Đ���
 * �I�������_�ŁAAtomEx �v���[���[�̃X�e�[�^�X�� CRIATOMEXPLAYER_STATUS_PLAYEND �ɑJ�ڂ��܂��B<br>
 * <br>
 * �^�C�~���O���̖��ɂ��A�f�[�^���w�肷�邱�Ƃ��ł��Ȃ����A�X�e�[�^�X��
 * CRIATOMEXPLAYER_STATUS_PLAYEND �ɑJ�ڂ��������Ȃ��ꍇ�ɂ́A�R�[���o�b�N�֐�����
 * ::criAtomPlayer_DeferCallback �֐������s���Ă��������B<br>
 * ::criAtomPlayer_DeferCallback �֐������s���邱�ƂŁA��1V��ɍēx�f�[�^�v��
 * �R�[���o�b�N�֐����Ăяo����܂��B�i�R�[���o�b�N���������g���C�\�B�j<br>
 * �������A ::criAtomPlayer_DeferCallback �֐������s�����ꍇ�A�Đ����r�؂��
 * �i�A���ӏ��Ɉ�莞�Ԗ���������j�\��������܂��B<br>
 * \par ��:
 * �ȉ��̃R�[�h�����s����ƁAbuffer1�̃f�[�^��buffer2�̃f�[�^���V�[�����X��
 * �A�����čĐ�����܂��B<br>
 * �i���̌��buffer2�̃f�[�^���J��Ԃ��Đ�����܂��B�j<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomExPlaybackId id, CriAtomPlayerHn player)
 * {
 * 	// �����čĐ�����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer2, buffer_size2);
 * }
 * 
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomExPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 * 	
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer1, buffer_size1);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �ȉ��̏����ɂ��A���ꉹ���f�[�^�𖳌��Ƀ��[�v�Đ��\�ł��B<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomExPlaybackId id, CriAtomPlayerHn player)
 * {
 * 	// �O��Đ������f�[�^���ăZ�b�g
 * 	criAtomPlayer_SetPreviousDataAgain(player);
 * }
 * 
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomExPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 * 	
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetData(player, buffer, buffer_size);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \attention
 * �R�[���o�b�N�֐��͍Đ��J�n�O�ɐݒ肷��K�v������܂��B<br>
 * �Đ����̉����ɑ΂��R�[���o�b�N��ݒ肵����A
 * �ݒ�ς݂̃R�[���o�b�N���ォ��܂��͕ύX���邱�Ƃ͂ł��܂���B<br>
 * <br>
 * �����̔g�`�f�[�^���܂ރL���[���Đ������ꍇ�A
 * �ŏ��Ɍ��������g�`�f�[�^�̍Đ����I������^�C�~���O�ŃR�[���o�b�N�֐������s����܂��B<br>
 * ���̂��߁A�����̔g�`�f�[�^���܂ރL���[�ɑ΂��ĘA���Đ��̑�����s�����ꍇ�A
 * �Ӑ}�Ƃ��Ȃ��g�ݍ��킹�Ŕg�`���A���Đ������\��������܂��B<br>
 * �{�@�\���g�p����ۂɂ́A 1 �̔g�`�f�[�^�݂̂��܂ރL���[���Đ����邩�A
 * �܂��̓t�@�C����I���������f�[�^�����Đ����Ă��������B<br>
 * <br>
 * �f�[�^�v���R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪
 * �������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐����Ŏ��s�\��API�́A�ȉ��̂Ƃ���ł��B<br>
 * 	- criAtomExAcb_GetWaveformInfoById�i������NULL�w��͕s�j
 * 	- criAtomExAcb_GetWaveformInfoByName�i������NULL�w��͕s�j
 * 	- criAtomExAcb_GetOnMemoryAwbHandle
 * 	- criAtomExAcb_GetStreamingAwbHandle
 * 	- criAtomPlayer_SetData
 * 	- criAtomPlayer_SetFile
 * 	- criAtomPlayer_SetContentId
 * 	- criAtomPlayer_SetWaveId
 * 	- criAtomPlayer_SetPreviousDataAgain
 * 	- criAtomPlayer_DeferCallback
 * 	
 * �R�[���o�b�N�֐����ŏ�L�ȊO��API�����s�����ꍇ�A
 * �G���[�R�[���o�b�N��f�b�h���b�N���̖�肪��������\��������܂��B<br>
 * <br>
 * �V�[�����X�A���Đ����T�|�[�g���Ȃ��R�[�f�b�N���g�p���Ă���ꍇ�A
 * �f�[�^�v���R�[���o�b�N�֐����Ŏ��̃f�[�^���Z�b�g���Ă��A
 * �f�[�^�͑����čĐ�����܂���B<br>
 * - HCA-MX�R�[�f�b�N���g�p����ꍇ�A�f�[�^���V�[�����X�ɂ͘A�����ꂸ�A
 * �Đ����̉����Ǝ��ɍĐ����鉹���Ƃ̌p���ڂɖ���������܂��B
 * - �v���b�g�t�H�[���ŗL�̉������k�R�[�f�b�N���g�p���Ă���ꍇ�A
 * �G���[������������\��������܂��B
 * 
 * �V�[�����X�A���Đ��Ɏg�p����g�`�f�[�^�̃t�H�[�}�b�g�́A
 * �S�ē����ɂ���K�v������܂��B<br>
 * ��̓I�ɂ́A�ȉ��̃p�����[�^�[�������ł���K�v������܂��B<br>
 * 	- �R�[�f�b�N
 * 	- �`�����l����
 * 	- �T���v�����O���[�g
 * 	
 * �p�����[�^�[���قȂ�g�`��A�����悤�Ƃ����ꍇ�A
 * �Ӑ}�Ƃ��Ȃ����x�ŉ����f�[�^���Đ����ꂽ��A
 * �G���[�R�[���o�b�N���������铙�̖�肪�������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Ń��[�v�t���̔g�`�f�[�^���Z�b�g�����ꍇ�ł��A
 * ���[�v�Đ��͍s���܂���B<br>
 * �i���[�v�|�C���g����������A�Đ����I�����܂��B�j<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExPlayerDataRequestCbFunc, criAtomPlayer_SetData,
 * criAtomPlayer_SetPreviousDataAgain, criAtomPlayer_DeferCallback
 */
void CRIAPI criAtomExPlayer_SetDataRequestCallback(
	CriAtomExPlayerHn player, CriAtomExPlayerDataRequestCbFunc func, void *obj);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	func		�g�`�t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�R�[�h���ʂ� PCM �f�[�^���󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�{�C�X�������f�[�^���f�R�[�h�����^�C�~���O�ŌĂяo����܂��B<br>
 * \attention
 * �R�[���o�b�N�֐��̓o�^�́A��~���̃v���[���[�ɑ΂��Ă̂݉\�ł��B<br>
 * �Đ����̃v���[���[�ɑ΂��ăR�[���o�b�N��o�^���邱�Ƃ͂ł��܂���B<br>
 * �i�G���[�R�[���o�b�N���������A�o�^�Ɏ��s���܂��B�j<br>
 * <br>
 * �����̉����f�[�^���܂ރL���[���Đ������ꍇ�A
 * �ŏ��Ɍ��������g�`�f�[�^�ɂ��Ă̂݃R�[���o�b�N�����s����܂��B<br>
 * �i�����̔g�`�f�[�^���܂ރL���[�ɂ��ẮA
 * 2�ڈȍ~�̔g�`�f�[�^�̏�����邱�Ƃ��ł��܂���B�j<br>
 * <br>
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �g�`�t�B���^�[�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * HCA-MX�R�[�f�b�N��v���b�g�t�H�[���ŗL�̉������k�R�[�f�b�N���g�p���Ă���ꍇ�A
 * �t�B���^�[�R�[���o�b�N�͗��p�ł��܂���B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExPlayerFilterCbFunc
 */
void CRIAPI criAtomExPlayer_SetFilterCallback(
	CriAtomExPlayerHn player, CriAtomExPlayerFilterCbFunc func, void *obj);

/*JP
 * \brief ������̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	seed		������
 * \par ����:
 * AtomEx�v���[���[���ێ�����^������������ɗ������ݒ肵�܂��B<br>
 * �������ݒ肷�邱�Ƃɂ��A�e�탉���_���Đ������ɍČ������������邱�Ƃ��ł��܂��B<br>
 * <br>
 * \sa criAtomEx_SetRandomSeed
 */
void CRIAPI criAtomExPlayer_SetRandomSeed(CriAtomExPlayerHn player, CriUint32 seed);

/*JP
 * \brief DSP�p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	param_id	�p�����[�^�[ID�i0�`7�j
 * \param[in]	param_val	�p�����[�^�[ID�i0.0f�`1.0f�j
 * \par ����:
 * AtomEx�v���[���[���ێ�����C���T�[�V����DSP�̃p�����[�^�[��ݒ肵�܂��B<br>
 * DSP��L��������ɂ́A�{�C�X�v�[���ɂ��炩����DSP���A�^�b�`����Ă���K�v������܂��B<br>
 * \par ���l:
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetDspParameter(
	CriAtomExPlayerHn player, CriSint32 param_id, CriFloat32 param_val);

/*JP
 * \brief �v���[���[��AISAC�����t����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player				AtomEx�v���[���[�n���h��
 * \param[in]	global_aisac_name	���t����O���[�o��AISAC��
 * \par ����:
 * �v���[���[��AISAC���A�^�b�`�i���t���j���܂��B
 * AISAC���A�^�b�`���邱�Ƃɂ��A�L���[��g���b�N��AISAC��ݒ肵�Ă��Ȃ��Ă��AAISAC�̌��ʂ𓾂邱�Ƃ��ł��܂��B<br>
 * �{�֐���AISAC���A�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�A�^�b�`����AISAC���l�����āA�e��p�����[�^�[���K�p����܂��B<br>
 * �܂��A�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�A�^�b�`����AISAC�ɂ��e��p�����[�^�[�ݒ��K�p���邱�Ƃ��ł��܂��B<br>
 * <br>
 * AISAC�̃A�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃A�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \par ��:
 * \code
 * // Attach Aisac
 * criAtomExPlayer_AttachAisac(player, "GlobalAisac1");
 * criAtomExPlayer_SetAisacControlByName(player, "Any", 0.5f);
 * criAtomExPlayer_Start(player);
 * \endcode
 * \par ���l:
 * �S�̐ݒ�iACF�t�@�C���j�Ɋ܂܂��O���[�o��AISAC�̂݁A�A�^�b�`�\�ł��B<br>
 * AISAC�̌��ʂ𓾂�ɂ́A�L���[��g���b�N�ɐݒ肳��Ă���AISAC�Ɠ��l�ɁA�Y������AISAC�R���g���[���l��ݒ肷��K�v������܂��B
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \attention
 * �L���[��g���b�N�ɁuAISAC�R���g���[���l��ύX����AISAC�v���ݒ肳��Ă����Ƃ��Ă��A���̓K�p���ʂ�AISAC�R���g���[���l�́A�v���[���[�ɃA�^�b�`����AISAC�ɂ͉e�����܂���B
 * ���݁A�u�I�[�g���W�����[�V�����v��u�����_���v�Ƃ������R���g���[���^�C�v��AISAC�̃A�^�b�`�ɂ͑Ή����Ă���܂���B<br>
 * ���݁A�v���[���[�ɃA�^�b�`�ł���AISAC�̍ő吔�́A8�Œ�ł��B
 * \sa criAtomExPlayer_DetachAisac, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_AttachAisac(CriAtomExPlayerHn player, const CriChar8* global_aisac_name);
void CRIAPI criAtomExPlayer_AttachAisacByIndex(CriAtomExPlayerHn player, CriUint16 global_aisac_index);

/*JP
 * \brief �v���[���[����AISAC�����O��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[
 * \param[in]	global_aisac_name	���O���O���[�o��AISAC��
 * \par ����:
 * �v���[���[����AISAC���f�^�b�`�i���O���j���܂��B<br>
 * �{�֐���AISAC���f�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�f�^�b�`����AISAC�̉e���͎󂯂Ȃ��Ȃ�܂��B<br>
 * �܂��f�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�f�^�b�`����AISAC�ɂ��e�����󂯂Ȃ��Ȃ�܂��B<br>
 * <br>
 * AISAC�̃f�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃f�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \sa criAtomExPlayer_AttachAisac
 */
void CRIAPI criAtomExPlayer_DetachAisac(CriAtomExPlayerHn player, const CriChar8* global_aisac_name);
void CRIAPI criAtomExPlayer_DetachAisacByIndex(CriAtomExPlayerHn player, CriUint16 global_aisac_index);

/*JP
 * \brief �v���[���[����S�Ă�AISAC�����O��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[
 * \par ����:
 * �v���[���[����S�Ă�AISAC���f�^�b�`�i���O���j���܂��B<br>
 * �{�֐���AISAC���f�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�f�^�b�`����AISAC�̉e���͎󂯂Ȃ��Ȃ�܂��B<br>
 * �܂��f�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�f�^�b�`����AISAC�ɂ��e�����󂯂Ȃ��Ȃ�܂��B
 * \sa criAtomExPlayer_AttachAisac
 */
void CRIAPI criAtomExPlayer_DetachAisacAll(CriAtomExPlayerHn player);

/*JP
 * \brief �v���[���[�ɃA�^�b�`����Ă���AISAC�����擾����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[
 * \return	�v���[���[�ɃA�^�b�`����Ă���AISAC��
 * \par ����:
 * �v���[���[�ɃA�^�b�`����Ă���AISAC�����擾���܂��B
 */
CriSint32 CRIAPI criAtomExPlayer_GetNumAttachedAisacs(CriAtomExPlayerHn player);

/*JP
 * \brief �v���[���[�ɃA�^�b�`����Ă���AISAC�̏����擾����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player					AtomEx�v���[���[
 * \param[in]	aisac_attached_index	�A�^�b�`����Ă���AISAC�̃C���f�b�N�X
 * \param[out]	aisac_info				AISAC���
 * \retval	CRI_TRUE = ��񂪎擾�ł���
 * \retval	CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * �v���[���[�ɃA�^�b�`����Ă���AISAC�̏����擾���܂��B<br>
 * �����ȃC���f�b�N�X���w�肵���ꍇ�ACRI_FALSE���Ԃ�܂��B<br>
 * \sa criAtomExPlayer_GetNumAttachedAisacs
 */
CriBool CRIAPI criAtomExPlayer_GetAttachedAisacInfo(
	CriAtomExPlayerHn player,
	CriSint32 aisac_attached_index,
	CriAtomExAisacInfo *aisac_info
);

/*JP
 * \brief �v���[���[�ɃX�g���[�~���O�L���b�V����ݒ肵�܂�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[
 * \param[in]	cache_id		�v���[���[�Ŏg�p����X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �v���[���[�Ŏg�p����X�g���[�~���O�L���b�V����ID�w��Őݒ肵�܂��B<br>
 * \attention
 * �v���[���[�Ŏg�p���̃X�g���[�~���O�L���b�V����j������ꍇ�́A
 * ��Ƀv���[���[��j�����Ă��������B<br>
 * �t�̏����ŏ��������ꍇ�̌��ʂ͕s��ł��B<br>
 * \sa criAtomStreamingCache_Create, criAtomStreamingCache_Destroy
 */
void CRIAPI criAtomExPlayer_SetStreamingCacheId(
	CriAtomExPlayerHn player, CriAtomExStreamingCacheId cache_id);

/*JP
 * \brief �v���[���[�Ƀg�D�C�[�������t����
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	tween	�g�D�C�[���n���h��
 * \par ����:
 * �v���[���[�Ƀg�D�C�[�����A�^�b�`�i���t���j���܂��B
 * �g�D�C�[�����A�^�b�`���邱�Ƃɂ��A�ȒP�Ȏ菇�Ńp�����[�^�[�̎��ԕω����s�����Ƃ��ł��܂��B<br>
 * �{�֐��Ńg�D�C�[�����A�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�A�^�b�`�����g�D�C�[�����l�����āA�e��p�����[�^�[���K�p����܂��B<br>
 * �܂��A�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�A�^�b�`�����g�D�C�[���ɂ��e��p�����[�^�[�ݒ��K�p���邱�Ƃ��ł��܂��B<br>
 * \par ��:
 * \code
 * // �{�����[�����t�F�[�h����Tween�̍쐬
 * CriAtomExTweenConfig config;
 * criAtomExTween_SetDefaultConfig(&config);
 *
 * config.parameter_type = CRIATOMEX_PARAMETER_TYPE_BASIC;
 * config.id.parameter_id = CRIATOMEX_PARAMETER_ID_VOLUME;
 * fade_tween = criAtomExTween_Create(&config, NULL, 0);
 *
 * // Tween�̃A�^�b�`
 * criAtomExPlayer_AttachTween(player, fade_tween);
 *
 * // �Đ��J�n
 * criAtomExPlayer_Start(player);
 *             :
 * // 1�b�����ă{�����[��0.2�Ƀt�F�[�h
 * criAtomExTween_MoveTo(fade_tween, 1000, 0.2f);
 *             :
 * // 2�b�����ă{�����[��1.0�ɕ��A
 * criAtomExTween_MoveTo(fade_tween, 2000, 1.0f);
 * \endcode
 * \par ���l:
 * �g�D�C�[���ɂ���ĕω������p�����[�^�[�́AAtomEx�v���[���[�ɐݒ肳��Ă���p�����[�^�[�ɑ΂��A���Z�^��Z�^�㏑������܂��B<br>
 * ���Z�^��Z�^�㏑���̂ǂ�ɊY�����邩�́AAtomEx�v���[���[�ւ̐ݒ�֐��i::criAtomExPlayer_SetVolume �֐����j�Ɠ��l�ł��B
 * �Ⴆ�΁A�{�����[���ł���Ώ�Z����AAISAC�R���g���[���l�ł���Ώ㏑�����܂��B<br>
 * ���݁A�v���[���[�ɃA�^�b�`�ł���g�D�C�[���̍ő吔�́A8�Œ�ł��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_DetachTween, criAtomExPlayer_DetachTweenAll, criAtomExTween_Create, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_AttachTween(CriAtomExPlayerHn player, CriAtomExTweenHn tween);

/*JP
 * \brief �v���[���[����g�D�C�[�������O��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[
 * \param[in]	tween	���O���g�D�C�[���n���h��
 * \par ����:
 * �v���[���[����g�D�C�[�����f�^�b�`�i���O���j���܂��B<br>
 * �{�֐��Ńg�D�C�[�����f�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�f�^�b�`�����g�D�C�[���̉e���͎󂯂Ȃ��Ȃ�܂��B<br>
 * �܂��f�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�f�^�b�`�����g�D�C�[���ɂ��e�����󂯂Ȃ��Ȃ�܂��B<br>
 * \sa criAtomExPlayer_AttachTween
 */
void CRIAPI criAtomExPlayer_DetachTween(CriAtomExPlayerHn player, CriAtomExTweenHn tween);

/*JP
 * \brief �v���[���[����S�Ẵg�D�C�[�������O��
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player	AtomEx�v���[���[
 * \par ����:
 * �v���[���[����S�Ẵg�D�C�[�����f�^�b�`�i���O���j���܂��B<br>
 * �{�֐��Ńg�D�C�[�����f�^�b�`��A::criAtomExPlayer_Start �֐��ɂ��Đ��J�n����ƁA�f�^�b�`�����g�D�C�[���̉e���͎󂯂Ȃ��Ȃ�܂��B<br>
 * �܂��f�^�b�`��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����ꂽ�����ɑ΂��Ă��A�f�^�b�`�����g�D�C�[���ɂ��e�����󂯂Ȃ��Ȃ�܂��B
 * \sa criAtomExPlayer_AttachTween
 */
void CRIAPI criAtomExPlayer_DetachTweenAll(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��J�n�u���b�N�̃Z�b�g�i�u���b�N�C���f�b�N�X�w��j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	index			�u���b�N�C���f�b�N�X
 * \par ����:
 * �Đ��J�n�u���b�N�C���f�b�N�X���AAtomEx�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��ōĐ��J�n�u���b�N�C���f�b�N�X���w���A�u���b�N�V�[�P���X�L���[��
 * ::criAtomExPlayer_Start �֐��ōĐ��J�n����Ǝw�肵���u���b�N����Đ���
 * �J�n���܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueIndex(player, acb_hn, 300);
 * 	
 * 	// �J�n�u���b�N���Z�b�g
 * 	criAtomExPlayer_SetFirstBlockIndex(player, 1);
 * 	
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomExPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * AtomEx�v���[���[�̃f�t�H���g�u���b�N�C���f�b�N�X�� 0 �ł��B<br>
 * ::criAtomExPlayer_Start �֐��ɂ��Đ��J�n���Ƀv���[���[�ɐݒ肳��Ă���L���[��
 * �u���b�N�V�[�P���X�łȂ��ꍇ�́A�{�֐��Őݒ肵���l�͗��p����܂���B<br>
 * �w�肵���C���f�b�N�X�ɑΉ������u���b�N���Ȃ��ꍇ�͐擪�u���b�N����Đ����s���܂��B<br>
 * ���̍ہA�w��C���f�b�N�X�̃u���b�N�����݂��Ȃ����e�̃��[�j���O���������܂��B<br>
 * \par ���l:
 * �Đ��J�n��̃u���b�N�J�ڂ� ::criAtomExPlayback_SetNextBlockIndex �֐����g�p���čs���A
 * �Đ����̃u���b�N�C���f�b�N�X�擾�� ::criAtomExPlayback_GetCurrentBlockIndex �֐����g�p���܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayback_SetNextBlockIndex, criAtomExPlayback_GetCurrentBlockIndex, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetFirstBlockIndex(
	CriAtomExPlayerHn player, CriAtomExBlockIndex index);

/*JP
 * \brief �u���b�N�g�����W�V�����R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	func		�u���b�N�g�����W�V�����R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �u���b�N�V�[�P���X�Đ����Ƀu���b�N�g�����W�V���������������Ƃ��ɌĂяo�����R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�u���b�N�g�����W�V��������������ƌĂяo����܂��B<br>
 * \attention
 * �R�[���o�b�N�֐��̓o�^�́A��~���̃v���[���[�ɑ΂��Ă̂݉\�ł��B<br>
 * �Đ����̃v���[���[�ɑ΂��ăR�[���o�b�N��o�^���邱�Ƃ͂ł��܂���B<br>
 * �i�G���[�R�[���o�b�N���������A�o�^�Ɏ��s���܂��B�j<br>
 * <br>
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExPlayerBlockTransitionCbFunc
 */
void CRIAPI criAtomExPlayer_SetBlockTransitionCallback(
	CriAtomExPlayerHn player, CriAtomExPlayerBlockTransitionCbFunc func, void *obj);

/*JP
 * \brief �T�E���h�I�u�W�F�N�g�̎擾
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \return �T�E���h�I�u�W�F�N�g�n���h��
 * \par ����:
 * ����AtomEx�v���[���[�Ɋ֘A�t�����Ă���T�E���h�I�u�W�F�N�g���擾���܂��B<br>
 * �ǂ̃T�E���h�I�u�W�F�N�g�ɂ��֘A�t�����Ă��Ȃ��ꍇ��NULL��Ԃ��܂��B
 * \sa CriAtomExSoundObjectHn, criAtomExSoundObject_AddPlayer
 */
CriAtomExSoundObjectHn CRIAPI criAtomExPlayer_GetSoundObject(CriAtomExPlayerHn player); 

/*JP
 * \brief �h���C�Z���h���x���̐ݒ�iCRI Audio�݊��p�j
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	spk				�X�s�[�J�[ID
 * \param[in]	offset			�h���C�Z���h���x���I�t�Z�b�g�i���Z�l�j	
 * \param[in]	gain			�h���C�Z���h���x���Q�C���i��Z�l�j
 * \par ����:
 * �o�͉����̃h���C�Z���h���x����ݒ肵�܂��B<br>
 * �{�֐���CRI Audio�Ƃ̌݊��p�ł���ACRI Audio�ɂ������h���C�Z���h���x���Ɠ������������܂��B<br>
 * �{�֐��Ńh���C�Z���h���x����ݒ��A::criAtomExPlayer_Start �֐��ōĐ����J�n����ƁA
 * �ݒ肳�ꂽ�h���C�Z���h���x���ŉ������Đ�����܂��B<br>
 * �܂��h���C�Z���h���x���ݒ��� ::criAtomExPlayer_Update �֐��� ::criAtomExPlayer_UpdateAll 
 * �֐����Ăяo�����ƂŁA���łɍĐ����ꂽ�����̃h���C�Z���h���x�����X�V���邱�Ƃ��\�ł��B<br>
 * <br>
 * �h���C�Z���h���x���ł́A�Đ����̊e�X�s�[�J�[�ւ̏o�̓��x�����ʂɎw�肷�邱�Ƃ��ł��܂��B<br>
 * �e�X�s�[�J�[�ւ̏o�͂Ƃ��Ăǂ̓��̓`�����l�����g�p���邩�́A�g�`�̃`�����l�����Ɉˑ����܂��B
 * �Ⴆ�΃��m�����g�`�̏ꍇ�͑S�ẴX�s�[�J�[�ւ̏o�͂Ƃ���0�`�����l������͂Ƃ��Ďg�p���A
 * �X�e���I�g�`�̏ꍇ��L���̃X�s�[�J�[�iL,SL,SBL�j�ւ̏o�͂ɂ�0�`�����l���iL�`�����l���j�A
 * R���̃X�s�[�J�[�iR,SR,SBL�j�ւ̏o�͂ɂ�1�`�����l���iR�`�����l���j����͂Ƃ��Ďg�p���܂��B
 * �i�h���C�Z���h���x���̐ݒ�ł́A�X�e���I�̉��̓Z���^�[�X�s�[�J�[�ALFE�ւ͏o�͂ł��܂���B�j<br>
 * <br>
 * �h���C�Z���h���x���́A�p��3D��Z���h���x���̐ݒ�ɂ��o�̓��x���ɑ΂��ĉ��Z����܂��B<br>
 * �h���C�Z���h���x���l�͈̔͂∵���́A��{�I�ɂ̓{�����[���Ɠ����ł��B::criAtomExPlayer_SetVolume �֐����Q�Ƃ��Ă��������B<br>
 * �h���C�Z���h���x���̃f�t�H���g�l��0.0f�ł��B<br>
 * <br>
 * \par ��:
 * \code
 * main()
 * {
 *  	�F
 *  // ���l�j�Đ����鉹���̓��m�����ł���Ɖ���
 * 	// �h���C�Z���h���x����ݒ�i�f�[�^���̒l�𔼕��ɂ���0.2f���Z����j
 * 	criAtomExPlayer_SetDrySendLevel(player, CRIATOMEX_SPEAKER_FRONT_CENTER, 0.2f, 0.5f);
 *  
 *  // �Đ��̊J�n
 *  // ���l�j�h���C�Z���h���x���̓v���[���[�ɐݒ肳�ꂽ�l�ōĐ������B
 *  id = criAtomExPlayer_Start(player);
 *  	�F
 * 	// �h���C�Z���h���x����ݒ�i�f�[�^���̒l�𖳌��ɂ���0.8f�ŏ㏑������j
 *  // ���Ӂj���̎��_�ł͍Đ����̉����̃h���C�Z���h���x���͕ύX����Ȃ��B
 * 	criAtomExPlayer_SetDrySendLevel(player, CRIATOMEX_SPEAKER_FRONT_CENTER, 0.8f, 0.0f);
 *  
 *  // �v���[���[�ɐݒ肳�ꂽ�h���C�Z���h���x�����Đ����̉����ɂ����f
 *  criAtomExPlayer_Update(player, id);
 *  	�F
 * }
 * \endcode
 * \par ���l:
 * �L���[�Đ����A�f�[�^���Ƀh���C�Z���h���x�����ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA
 * �f�[�^���ɐݒ肳��Ă���l�ɑ΂� gain ����Z���A offset �����Z�����l���K�p����܂��B<br>
 * �Ⴆ�΁A�f�[�^���̃h���C�Z���h���x����1.0f�AAtomEx�v���[���[�̃h���C�Z���h���x���� offset 0.2f�Again 0.5f
 * �̏ꍇ�A���ۂɓK�p�����Z���h���x����0.7f�ɂȂ�܂��B<br>
 * �h���C�Z���h���x���͒ʏ�ł�CRI Atom Craft�ł͐ݒ�ł����ACRI Audio Craft�ō쐬����
 * �v���W�F�N�g�t�@�C�����C���|�[�g�����ꍇ�ɂ̂݁A�f�[�^���ɐݒ肳��Ă���ꍇ������܂��B<br>
 * �ʏ�ł�6ch�f�ނ��Đ������ہA�����I�ɃZ���^�[�^LFE����o�͂���܂����A
 * �f�[�^���܂��͖{�֐��Ńh���C�Z���h���x�����ݒ肳�ꂽ�ꍇ�A�����ł͏o�͂���Ȃ��Ȃ�܂��B
 * �܂����l�ɁA�f�[�^���܂��͖{�֐��Ńh���C�Z���h���x�����ݒ肳�ꂽ�ꍇ�ACRI Atom Craft�Őݒ肵���Z���^�[�^LFE�~�b�N�X���x���͖����ƂȂ�܂��B<br>
 * <br>
 * �{�p�����[�^�[�� ::criAtomExPlayer_ResetParameters �֐��ɂăN���A����܂��B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll, criAtomExPlayer_ResetParameters
 */
void CRIAPI criAtomExPlayer_SetDrySendLevel(
	CriAtomExPlayerHn player, CriAtomExSpeakerId spk, CriFloat32 offset, CriFloat32 gain);

/*JP
 * \brief �Z���N�^�[���̃v���[���[�ւ̐ݒ�
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	selector		�Z���N�^�[��
 * \param[in]	label			���x����
 * \par ����:
 * �Z���N�^�[���ƃ��x�������w�肵�āA�v���[���[�ɐݒ肵�܂��B<br>
 * �g���b�N�ɃZ���N�^�[���x�����w�肳��Ă���L���[���Đ������ꍇ�A�{�֐��Ŏw�肵���Z���N�^�[���x��
 * �ƈ�v�����g���b�N�������Đ����܂��B<br>
 * �Z���N�^�[���A���x������ACF�w�b�_�[�ɋL�ڂ���Ă��܂��B<br>
 * �v���[���[�ɐݒ肵�����x�����̌ʍ폜�́A ::criAtomExPlayer_UnsetSelectorLabel �֐������s���Ă��������B<br>
 * �v���[���[�ɐݒ肵�����x�����̈ꊇ�폜�́A ::criAtomExPlayer_ClearSelectorLabels �֐������s���Ă��������B<br>
 * ���x�������܂ޑS�Ẵv���[���[�ݒ�l�폜�́A ::criAtomExPlayer_ResetParameters �֐������s���Ă��������B<br>
 * \sa criAtomExPlayer_ClearSelectorLabels, criAtomExPlayer_ResetParameters, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll
 */
void CRIAPI criAtomExPlayer_SetSelectorLabel(
	CriAtomExPlayerHn player, const CriChar8 *selector, const CriChar8 *label);

/*JP
 * \brief �v���[���[�ɐݒ肳��Ă���Z���N�^�[���̍폜
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \param[in]	selector		�Z���N�^�[��
 * \par ����:
 * �v���[���[�ɐݒ肳��Ă���w�肳�ꂽ�Z���N�^�[���Ƃ���ɕR�Â����x�����̏����폜���܂��B<br>
 * �܂��폜��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����̉����ɑ΂��ăZ���N�^�[���̍폜���s���܂����A�Đ�����������~���邱�Ƃ͂���܂���B
 * \sa criAtomExPlayer_SetSelectorLabel, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll
 */
void CRIAPI criAtomExPlayer_UnsetSelectorLabel(CriAtomExPlayerHn player, const CriChar8 *selector);

/*JP
 * \brief �v���[���[�ɐݒ肳��Ă���S�ẴZ���N�^�[���̍폜
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player			AtomEx�v���[���[�n���h��
 * \par ����:
 * �v���[���[�ɐݒ肳��Ă���Z���N�^�[���A���x��������S�č폜���܂��B<br>
 * �܂��폜��A::criAtomExPlayer_Update �֐��A::criAtomExPlayer_UpdateAll �֐����Ăяo�����Ƃɂ��A
 * ���łɍĐ����̉����ɑ΂��ăZ���N�^�[���̍폜���s���܂����A�Đ�����������~���邱�Ƃ͂���܂���B
 * \sa criAtomExPlayer_SetSelectorLabel, criAtomExPlayer_Update, criAtomExPlayer_UpdateAll
 */
void CRIAPI criAtomExPlayer_ClearSelectorLabels(CriAtomExPlayerHn player);

/*JP
 * \brief �Đ��g���b�N�ԍ��ʒm�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	func		�Đ��g���b�N�ԍ��ʒm�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �Đ������g���b�N�ԍ���ʒm���邽�߂̃R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�|���t�H�j�b�N�^�C�v�ȊO�̃L���[�Đ����ɌĂяo����܂��B<br>
 * \attention
 * �R�[���o�b�N�֐��̓o�^�́A��~���̃v���[���[�ɑ΂��Ă̂݉\�ł��B<br>
 * �Đ����̃v���[���[�ɑ΂��ăR�[���o�b�N��o�^���邱�Ƃ͂ł��܂���B<br>
 * �i�G���[�R�[���o�b�N���������A�o�^�Ɏ��s���܂��B�j<br>
 * <br>
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExPlayerPlaybackTrackInfoNotificationCbFunc
 */
void CRIAPI criAtomExPlayer_SetPlaybackTrackInfoNotificationCallback(
	CriAtomExPlayerHn player, CriAtomExPlayerPlaybackTrackInfoNotificationCbFunc func, void *obj);

/*JP
 * �Đ��C�x���g�R�[���o�b�N�̓o�^
 * \ingroup ATOMEXLIB_PLAYER
 * \param[in]	player		AtomEx�v���[���[�n���h��
 * \param[in]	func		�Đ��C�x���g�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �Đ��C�x���g�R�[���o�b�N��o�^���܂��B<br>
 * �{�֐����g�p���čĐ��C�x���g�R�[���o�b�N��o�^���邱�ƂŁA
 * �Đ��C�x���g�i�Đ��p���\�[�X�̊m�ہ^�����A�{�C�X�̊��蓖�āA�o�[�`�������j�������̏ڍ׏��
 * �i�Đ�����AtomEx�v���[���[��Đ�ID�j���擾�\�ł��B<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExPlaybackEventCbFunc �̐��������Q�Ƃ��������B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \attention
 * 1��AtomEx�v���[���[�ɑ΂��A1�̃R�[���o�b�N�֐������o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * \sa CriAtomExVoiceEventCbFunc
 */
void CRIAPI criAtomExPlayer_SetPlaybackEventCallback(
	CriAtomExPlayerHn player, CriAtomExPlaybackEventCbFunc func, void *obj);

/*==========================================================================
 *      CRI AtomEx Playback API
 *=========================================================================*/
/*JP
 * \brief �Đ����̒�~
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \par ����:
 * �Đ����P�ʂŒ�~�������s���܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�v���[���[�ɂ���čĐ����ꂽ�������A�v���[���[�P�ʂł͂Ȃ��A
 * �ʂɒ�~�����邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * AtomEx �v���[���[�ɂ���čĐ����ꂽ�S�Ẳ������~�������ꍇ�A
 * �{�֐��ł͂Ȃ� ::criAtomExPlayer_Stop �֐��������p���������B<br>
 * �i ::criAtomExPlayer_Stop �֐��́A���̃v���[���[�ōĐ����̑S�Ẳ������~���܂��B�j<br>
 * \attention
 * �{�֐��ōĐ����̒�~���s���ƁA�Đ����̉����̃X�e�[�^�X��
 * ::CRIATOMEXPLAYBACK_STATUS_REMOVED �ɑJ�ڂ��܂��B<br>
 * ��~���Ƀ{�C�X���\�[�X���j������邽�߁A��U ::CRIATOMEXPLAYBACK_STATUS_REMOVED
 * ��ԂɑJ�ڂ����Đ� ID ����́A�ȍ~�����擾�ł��Ȃ��Ȃ�܂��B<br>
 * \sa criAtomExPlayer_Stop, criAtomExPlayback_GetStatus
 */
void CRIAPI criAtomExPlayback_Stop(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ����̒�~�i�����[�X�^�C�������j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \par ����:
 * �Đ����P�ʂŒ�~�������s���܂��B<br>
 * ���̍ہA�Đ����̉����ɃG���x���[�v�̃����[�X�^�C�����ݒ肳��Ă����Ƃ��Ă��A����𖳎����Ē�~���܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�v���[���[�ɂ���čĐ����ꂽ�������A�v���[���[�P�ʂł͂Ȃ��A
 * �ʂɒ�~�����邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * �v���[���[�ɂ���čĐ����ꂽ�S�Ẳ������~�������ꍇ�A
 * �{�֐��ł͂Ȃ� ::criAtomExPlayer_StopWithoutReleaseTime �֐��������p���������B<br>
 * \attention
 * �{�֐��ōĐ����̒�~���s���ƁA�Đ����̉����̃X�e�[�^�X��
 * ::CRIATOMEXPLAYBACK_STATUS_REMOVED �ɑJ�ڂ��܂��B<br>
 * ��~���Ƀ{�C�X���\�[�X���j������邽�߁A��U ::CRIATOMEXPLAYBACK_STATUS_REMOVED
 * ��ԂɑJ�ڂ����Đ� ID ����́A�ȍ~�����擾�ł��Ȃ��Ȃ�܂��B<br>
 * \sa criAtomExPlayer_StopWithoutReleaseTime
 */
void CRIAPI criAtomExPlayback_StopWithoutReleaseTime(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ����̃|�[�Y�^�|�[�Y����
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[in]	sw			�X�C�b�`�i CRI_FALSE = �|�[�Y�����A CRI_TRUE = �|�[�Y �j
 * \par ����:
 * �Đ����P�ʂŃ|�[�Y�^�|�[�Y�������s���܂��B<br>
 * sw �� CRI_TRUE ���w�肵�Ė{�֐������s����ƁA�w�肵��ID�̉������|�[�Y
 * �i�ꎞ��~�j����܂��B<br>
 * sw �� CRI_FALSE ���w�肵�Ė{�֐������s����ƁA�w�肵��ID�̉����̃|�[�Y��
 * ��������A�ꎞ��~���Ă��������̍Đ����ĊJ����܂��B<br>
 * <br>
 * �{�֐����g�p���邱�ƂŁA�v���[���[�ɂ���čĐ����ꂽ�������A�v���[���[�P�ʂł͂Ȃ��A
 * �ʂɃ|�[�Y�^�|�[�Y���������邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * �v���[���[�ɂ���čĐ����ꂽ�S�Ẳ������|�[�Y�^�|�[�Y�����������ꍇ�A
 * �{�֐��ł͂Ȃ� ::criAtomExPlayer_Pause �֐��������p���������B<br>
 * <br>
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ōĐ����������ɑ΂��Ė{�֐��ŌʂɃ|�[�Y�^�|�[�Y�����̑�����s�����ꍇ�A
 * �N���X�t�F�[�h�����̓t�F�[�h�C�����̉����̃|�[�Y��Ԃɓ������čs���܂��B<br>
 * �Ⴆ�΁A�N���X�t�F�[�h����criAtomExPlayer_Pause �֐��ŗ����̉������|�[�Y�����ꍇ�A
 * �t�F�[�h�C�����̉����̃|�[�Y����������΃N���X�t�F�[�h�������ĊJ����܂����A
 * �t�F�[�h�A�E�g���̉����̃|�[�Y���������Ă��N���X�t�F�[�h�����͍ĊJ����܂���B<br>
 * \attention
 * ��2�����isw�j�� CRI_FALSE ���w�肵�ă|�[�Y�����̑�����s�����ꍇ�A
 * �{�֐��Ń|�[�Y�����������������łȂ��A::criAtomExPlayer_Prepare 
 * �֐��ōĐ��������̉����ɂ��Ă��Đ����J�n����Ă��܂��܂��B<br>
 * �i���o�[�W�����Ƃ̌݊����ێ��̂��߂̎d�l�ł��B�j<br>
 * �{�֐��Ń|�[�Y�������������ɂ��Ă̂݃|�[�Y�������������ꍇ�A
 * �{�֐����g�p�����A criAtomExPlayback_Resume(id, CRIATOMEX_RESUME_PAUSED_PLAYBACK);
 * �����s���ă|�[�Y�������s���Ă��������B<br>
 * <br>
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ɑ΂��Đ�ID�w��Ń|�[�Y�̉������s���ƁA
 * �t�F�[�h�C�����鉹���̔������\�[�X���m�ۂł��Ȃ��ꍇ��A
 * �t�F�[�h�C�����鉹���̔������\�[�X���D�����ꂽ�ꍇ�Ƀ|�[�Y�������s�����A
 * �t�F�[�h�A�E�g���̉��������܂Ōo���Ă��t�F�[�h�A�E�g���Ȃ���ԂƂȂ�܂��B<br>
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ōĐ����������ɑ΂��ẮA�{�֐��ł͂Ȃ��A
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y�̉������s���Ă��������B<br>
 * \sa criAtomExPlayback_IsPaused, criAtomExPlayer_Pause, criAtomExPlayback_Resume
 */
void CRIAPI criAtomExPlayback_Pause(CriAtomExPlaybackId id, CriBool sw);

/*JP
 * \brief �Đ����̋@�\�ʂ̃|�[�Y����
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[in]	mode		�|�[�Y�����Ώ�
 * \par ����:
 * �Đ����P�ʂňꎞ��~��Ԃ̉������s���܂��B<br>
 * ::criAtomExPlayback_Pause �֐��ƈقȂ�A ::criAtomExPlayer_Prepare
 * �֐��ōĐ��J�n�҂��̉����ƁA ::criAtomExPlayer_Pause �֐��i�܂���
 * ::criAtomExPlayback_Pause �֐��Ń|�[�Y�������������Ƃ��A
 * �ʂɍĊJ�����邱�Ƃ��\�ł��B<br>
 * <br>
 * ��2�����imode�j�� ::CRIATOMEX_RESUME_PAUSED_PLAYBACK ���w�肵�Ė{�֐������s����ƁA
 * ���[�U�� ::criAtomExPlayer_Pause �֐��i�܂��� ::criAtomExPlayback_Pause 
 * �֐��j�ňꎞ��~��ԂɂȂ��������̍Đ����ĊJ����܂��B<br>
 * ��2�����imode�j�� ::CRIATOMEX_RESUME_PREPARED_PLAYBACK ���w�肵�Ė{�֐������s����ƁA
 * ���[�U�� ::criAtomExPlayer_Prepare �֐��ōĐ��������w�����������̍Đ����J�n����܂��B<br>
 * <br>
 * ::criAtomExPlayback_Pause �֐��Ń|�[�Y��Ԃ̃v���[���[�ɑ΂���
 * ::criAtomExPlayer_Prepare �֐��ōĐ��������s�����ꍇ�A
 * ���̉����� ::CRIATOMEX_RESUME_PAUSED_PLAYBACK
 * �w��̃|�[�Y���������ƁA ::CRIATOMEX_RESUME_PREPARED_PLAYBACK
 * �w��̃|�[�Y���������̗������s����܂ŁA�Đ����J�n����܂���B<br>
 * \par ���l:
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ōĐ����������ɑ΂��Ė{�֐��ŌʂɃ|�[�Y�����̑�����s�����ꍇ�A
 * �N���X�t�F�[�h�����̓t�F�[�h�C�����̉����̃|�[�Y��Ԃɓ������čs���܂��B<br>
 * �Ⴆ�΁A�N���X�t�F�[�h����criAtomExPlayer_Pause �֐��ŗ����̉������|�[�Y�����ꍇ�A
 * �t�F�[�h�C�����̉����̃|�[�Y����������΃N���X�t�F�[�h�������ĊJ����܂����A
 * �t�F�[�h�A�E�g���̉����̃|�[�Y���������Ă��N���X�t�F�[�h�����͍ĊJ����܂���B<br>
 * \attention
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ɑ΂��Đ�ID�w��Ń|�[�Y�̉������s���ƁA
 * �t�F�[�h�C�����鉹���̔������\�[�X���m�ۂł��Ȃ��ꍇ��A
 * �t�F�[�h�C�����鉹���̔������\�[�X���D�����ꂽ�ꍇ�Ƀ|�[�Y�������s�����A
 * �t�F�[�h�A�E�g���̉��������܂Ōo���Ă��t�F�[�h�A�E�g���Ȃ���ԂƂȂ�܂��B<br>
 * �t�F�[�_�[���A�^�b�`�����v���[���[�ōĐ����������ɑ΂��ẮA�{�֐��ł͂Ȃ��A
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y�̉������s���Ă��������B<br>
 * \sa criAtomExPlayback_IsPaused, criAtomExPlayer_Resume, criAtomExPlayer_Pause
 */
void CRIAPI criAtomExPlayback_Resume(CriAtomExPlaybackId id, CriAtomExResumeMode mode);

/*JP
 * \brief �Đ����̃|�[�Y��Ԃ̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \return		CriBool		�|�[�Y�����ǂ����iCRI_FALSE = �|�[�Y����Ă��Ȃ��ACRI_TRUE = �|�[�Y���j
 * \par ����:
 * �Đ����̉������|�[�Y�����ǂ�����Ԃ��܂��B<br>
 * \sa criAtomExPlayback_Pause
 */
CriBool CRIAPI criAtomExPlayback_IsPaused(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ��X�e�[�^�X�̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id						�Đ�ID
 * \return		CriAtomExPlaybackStatus	�Đ��X�e�[�^�X
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̃X�e�[�^�X���擾���܂��B<br>
 * \par ���l:
 * ::criAtomExPlayer_GetStatus �֐���AtomEx�v���[���[�̃X�e�[�^�X��Ԃ��̂ɑ΂��A
 * �{�֐��͍Đ��ς݂̌X�̉����̃X�e�[�^�X���擾���܂��B<br>
 * <br>
 * �Đ����̉����̃{�C�X���\�[�X�́A�ȉ��̏ꍇ�ɍ폜����܂��B<br>
 * - �Đ������������ꍇ�B
 * - criAtomExPlayback_Stop �֐��ōĐ����̉������~�����ꍇ�B
 * - ���v���C�I���e�B�̔������N�G�X�g�ɂ��Đ����̃{�C�X���D�����ꂽ�ꍇ�B
 * - �Đ����ɃG���[�����������ꍇ�B
 * 
 * ���̂��߁A ::criAtomExPlayback_Stop �֐����g�p���Ė����I�ɍĐ����~�������A
 * ���̑��̗v���ɂ���čĐ�����~���ꂽ���̈Ⴂ�Ɋ֌W�Ȃ��A
 * �Đ����̃X�e�[�^�X�͂�����̏ꍇ�� ::CRIATOMEXPLAYBACK_STATUS_REMOVED
 * �ɑJ�ڂ��܂��B<br>
 * �i�G���[�̔��������m����K�v������ꍇ�ɂ́A�{�֐��ł͂Ȃ��A::criAtomExPlayer_GetStatus
 * �֐��� AtomEx �v���[���[�̃X�e�[�^�X���`�F�b�N����K�v������܂��B�j<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus, criAtomExPlayback_Stop
 */
CriAtomExPlaybackStatus CRIAPI criAtomExPlayback_GetStatus(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ������̃t�H�[�}�b�g���̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[out]	info		�t�H�[�}�b�g���
 * \return		CriBool		��񂪎擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̃t�H�[�}�b�g�����擾���܂��B<br>
 * <br>
 * �t�H�[�}�b�g��񂪎擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \par ���l:
 * �����̉����f�[�^���܂ރL���[���Đ������ꍇ�A�ŏ��Ɍ�����������
 * �f�[�^�̏�񂪕Ԃ���܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂݃t�H�[�}�b�g�����擾�\�ł��B<br>
 * �Đ���������Đ��I����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �t�H�[�}�b�g���̎擾�Ɏ��s���܂��B<br>
 * �{�C�X�̍Đ���Ԃ� criAtomExPlayback_GetStatus �֐��Ŏ擾���邱�Ƃ͂ł��Ȃ����߂����ӂ��������B
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
CriBool CRIAPI criAtomExPlayback_GetFormatInfo(
	CriAtomExPlaybackId id, CriAtomExFormatInfo *info);

/*JP
 * \brief �Đ������̍Đ������̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[out]	source		�Đ������
 * \retval CRI_TRUE = ��񂪎擾�ł���
 * \retval CRI_FALSE = ��񂪎擾�ł��Ȃ�����
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̍Đ��������擾���܂��B<br>
 * �擾�����������ɁA::criAtomExAcb_GetCueInfoByIndex �֐����𗘗p���邱�ƂŁA
 * ���ڍׂȏ����擾���邱�Ƃ��ł��܂��B<br>
 * <br>
 * �Đ�����񂪎擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \par ���l
 * �Đ����̃^�C�v�ɂ���āA�擾�ł����񂪈قȂ�܂��B<br>
 * type���Q�Ƃ��A���p��source�̒��̂ǂ̍\���̂Ƃ��ăA�N�Z�X���邩��I�����Ă��������B<br>
 * \code
 * CriAtomExSourceInfo source;
 * criAtomExPlayback_GetSource(playback_id, &source);
 * 
 * switch (source.type) {
 * case CRIATOMEXPLAYBACK_SOURCE_TYPE_CUE_ID:
 * 	{
 * 		CriAtomExCueInfo cue_info;
 * 		criAtomExAcb_GetCueInfoById(source.info.cue_id.acb, source.info.cue_id.id, &cue_info);
 *			:
 * 	}
 * 	break;
 * 		:
 * }
 * \endcode
 * \attention
 * �{�֐��́A�����Đ����̂ݍĐ��������擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �Đ������̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetStatus
 */
CriBool CRIAPI criAtomExPlayback_GetSource(
	CriAtomExPlaybackId id, CriAtomExSourceInfo *source);

/*JP
 * \brief Atom�v���[���[�̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \retval CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * �Đ�ID�ɕR�Â���ꂽ�{�C�X�i��Atom�v���[���[�n���h���j���擾���܂��B<br>
 * \par ���l:
 * �����̔g�`�f�[�^���܂ރL���[���Đ����Ă���ꍇ�A
 * �{�֐��͍ŏ��Ɍ��������{�C�X�ɑΉ�����Atom�v���[���[�n���h����Ԃ��܂��B<br>
 * �g�`�f�[�^���Đ�����Ă��Ȃ��ꍇ�A�{�֐���NULL��Ԃ��܂��B<br>
 */
CriAtomPlayerHn CRIAPI criAtomExPlayback_GetAtomPlayer(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ������̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id		�Đ�ID
 * \return		Sint64	�Đ������i�~���b�P�ʁj
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̍Đ��������擾���܂��B<br>
 * <br>
 * �Đ��������擾�ł����ꍇ�A�{�֐��� 0 �ȏ�̒l��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��͕��l��Ԃ��܂��B<br>
 * \par ���l:
 * �{�֐����Ԃ��Đ������́u�Đ��J�n�ォ��̌o�ߎ��ԁv�ł��B<br>
 * ���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����Ď����������߂邱�Ƃ͂���܂���B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ������̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΍ēx�J�E���g�A�b�v���ĊJ����܂��B�j
 * <br>
 * �{�֐��Ŏ擾�\�Ȏ����̐��x�́A�T�[�o�[�����̎��g���Ɉˑ����܂��B<br>
 * �i�����̍X�V�̓T�[�o�[�����P�ʂōs���܂��B�j<br>
 * ��萸�x�̍����������擾����K�v������ꍇ�ɂ́A�{�֐��̑����
 * ::criAtomExPlayback_GetNumPlayedSamples �֐����g�p���A
 * �Đ��ς݃T���v�������擾���Ă��������B<br>
 * \attention
 * �߂�l�̌^��CriSint64�ł����A����A32bit�ȏ�̐��x�͂���܂���B<br>
 * �Đ����������ɐ�����s���ꍇ�A��24���ōĐ��������ُ�ɂȂ�_�ɒ��ӂ��K�v�ł��B<br>
 * �i 2147483647 �~���b�𒴂������_�ŁA�Đ��������I�[�o�[�t���[���A���l�ɂȂ�܂��B�j<br>
 * <br>
 * �{�֐��́A�����Đ����̂ݎ������擾�\�ł��B<br>
 * �i ::criAtomExPlayer_GetTime �֐��ƈقȂ�A�{�֐��͍Đ����̉������ƂɎ�����
 * �擾�\�ł����A�Đ��I����������邱�Ƃ��ł��܂���B�j<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �Đ������̎擾�Ɏ��s���܂��B<br>
 * �i���l���Ԃ�܂��B�j<br>
 * <br>
 * �h���C�u�Ń��[�h���g���C���������������A�ꎞ�I�ɉ����f�[�^�̋������r�؂ꂽ�ꍇ�ł��A
 * �Đ������̃J�E���g�A�b�v���r�؂�邱�Ƃ͂���܂���B<br>
 * �i�f�[�^������~�ɂ��Đ�����~�����ꍇ�ł��A�����͐i�ݑ����܂��B�j<br>
 * ���̂��߁A�{�֐��Ŏ擾�������������ɉf���Ƃ̓������s�����ꍇ�A
 * ���[�h���g���C�������ɓ������傫���Y����\��������܂��B<br>
 * �g�`�f�[�^�Ɖf���̓����������Ɏ��K�v������ꍇ�́A�{�֐��̑����
 * ::criAtomExPlayback_GetNumPlayedSamples �֐����g�p���A
 * �Đ��ς݃T���v�����Ƃ̓���������Ă��������B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_GetTime, criAtomExPlayback_GetNumPlayedSamples
 */
CriSint64 CRIAPI criAtomExPlayback_GetTime(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ������̎擾�i�Đ������ɓ��������␳���݁j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id		�Đ�ID
 * \return		Sint64	�Đ������i�~���b�P�ʁj
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̍Đ��������擾���܂��B<br>
 * <br>
 * �Đ��������擾�ł����ꍇ�A�{�֐��� 0 �ȏ�̒l��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��͕��l��Ԃ��܂��B<br>
 * \par ���l:
 * ::criAtomExPlayback_GetTime �֐����Ԃ��u�Đ��J�n�ォ��̌o�ߎ��ԁv�Ƃ�
 * �قȂ�A�{�֐�����͍Đ����̉����ɓ��������Đ��������擾���邱�Ƃ�
 * �\�ł��B<br>
 * �f�o�C�X�̃��[�h���g���C�������ɂ�艹���f�[�^�̋������r�؂��
 * �Đ�����~�����ꍇ�A�܂��̓V�X�e���ɂ�銄�荞�݂ɂ�艹���o�͂��W����ꂽ
 * �ꍇ�ɂ́A�Đ������̃J�E���g�A�b�v���ꎞ�I�ɒ�~���܂��B<br>
 * �Đ����ꂽ�����Ɍ����ɓ��������������s�������ꍇ�́A�{�֐���
 * �擾�����Đ�������p���Ă��������B<br>
 * �������A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����Ď����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A�g�`�̋l�܂��Ă��Ȃ��V�[�P���X�L���[��
 * �Đ��g�`���؂�ւ��u���b�N�V�[�P���X�L���[�ɑ΂��ẮA����ɍĐ�������
 * �擾���邱�Ƃ��ł��܂���B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ������̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΍ēx�J�E���g�A�b�v���ĊJ����܂��B�j<br>
 * <br>
 * �{�֐��ɂ��Đ������̎擾���s���ꍇ�́A�Ή�����AtomEx�v���[���[�쐬���ɁA
 * ::CriAtomExPlayerConfig �\���̂� enable_audio_synced_timer �� CRI_TRUE ��
 * �ݒ肵�Ă��������B<br>
 * �f�t�H���g�ł͖����ɂȂ��Ă��܂��B<br>
 * <br>
 * �߂�l�̌^�� long �ł����A����A32bit�ȏ�̐��x�͂���܂���B<br>
 * �Đ����������ɐ�����s���ꍇ�A��24���ōĐ��������ُ�ɂȂ�_�ɒ��ӂ��K�v�ł��B<br>
 * �i 2147483647 �~���b�𒴂������_�ŁA�Đ��������I�[�o�[�t���[���A���l�ɂȂ�܂��B�j<br>
 * <br>
 * �{�֐��́A�����Đ����̂ݎ������擾�\�ł��B<br>
 * �i ::criAtomExPlayer_GetTime �֐��ƈقȂ�A�{�֐��͍Đ����̉������ƂɎ�����
 * �擾�\�ł����A�Đ��I����������邱�Ƃ��ł��܂���B�j<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �Đ������̎擾�Ɏ��s���܂��B<br>
 * �i���l���Ԃ�܂��B�j<br>
 * <br>
 * �{�֐��͓����Ŏ����v�Z���s���Ă���A�v���b�g�t�H�[���ɂ���Ă͏������ׂ�
 * ���ɂȂ�\��������܂��B�܂��A�A�v���P�[�V�����̓����t���[�����ł����Ă��A
 * �Ăяo�����ɍX�V���ꂽ������Ԃ��܂��B<br>
 * �A�v���P�[�V�����ɂ��Đ������̗��p���@�ɂ����܂����A��{�I�ɖ{�֐���p����
 * �����擾��1�t���[���ɂ���x�̂ݍs���悤�ɂ��Ă��������B<br>
 * \sa criAtomExPlayer_Create, criAtomExPlayer_Start, criAtomExPlayback_GetTime
 */
CriSint64 CRIAPI criAtomExPlayback_GetTimeSyncedWithAudio(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ������̎擾�i�Đ������ɓ��������␳���݁j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id		�Đ�ID
 * \return		Sint64	�Đ������i�}�C�N���b�P�ʁj
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̍Đ��������擾���܂��B<br>
 * <br>
 * �Đ��������擾�ł����ꍇ�A�{�֐��� 0 �ȏ�̒l��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��͕��l��Ԃ��܂��B<br>
 * \par ���l:
 * ::criAtomExPlayback_GetTime �֐����Ԃ��u�Đ��J�n�ォ��̌o�ߎ��ԁv�Ƃ�
 * �قȂ�A�{�֐�����͍Đ����̉����ɓ��������Đ��������擾���邱�Ƃ�
 * �\�ł��B<br>
 * �f�o�C�X�̃��[�h���g���C�������ɂ�艹���f�[�^�̋������r�؂��
 * �Đ�����~�����ꍇ�A�܂��̓V�X�e���ɂ�銄�荞�݂ɂ�艹���o�͂��W����ꂽ
 * �ꍇ�ɂ́A�Đ������̃J�E���g�A�b�v���ꎞ�I�ɒ�~���܂��B<br>
 * �Đ����ꂽ�����Ɍ����ɓ��������������s�������ꍇ�́A�{�֐���
 * �擾�����Đ�������p���Ă��������B<br>
 * �������A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����Ď����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A�g�`�̋l�܂��Ă��Ȃ��V�[�P���X�L���[��
 * �Đ��g�`���؂�ւ��u���b�N�V�[�P���X�L���[�ɑ΂��ẮA����ɍĐ�������
 * �擾���邱�Ƃ��ł��܂���B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ������̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΍ēx�J�E���g�A�b�v���ĊJ����܂��B�j<br>
 * <br>
 * �{�֐��ɂ��Đ������̎擾���s���ꍇ�́A�Ή�����AtomEx�v���[���[�쐬���ɁA
 * ::CriAtomExPlayerConfig �\���̂� enable_audio_synced_timer �� CRI_TRUE ��
 * �ݒ肵�Ă��������B<br>
 * �f�t�H���g�ł͖����ɂȂ��Ă��܂��B<br>
 * <br>
 * �{�֐��́A�����Đ����̂ݎ������擾�\�ł��B<br>
 * �i ::criAtomExPlayer_GetTime �֐��ƈقȂ�A�{�֐��͍Đ����̉������ƂɎ�����
 * �擾�\�ł����A�Đ��I����������邱�Ƃ��ł��܂���B�j<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �Đ������̎擾�Ɏ��s���܂��B<br>
 * �i���l���Ԃ�܂��B�j<br>
 * <br>
 * �{�֐��͓����Ŏ����v�Z���s���Ă���A�v���b�g�t�H�[���ɂ���Ă͏������ׂ�
 * ���ɂȂ�\��������܂��B�܂��A�A�v���P�[�V�����̓����t���[�����ł����Ă��A
 * �Ăяo�����ɍX�V���ꂽ������Ԃ��܂��B<br>
 * �A�v���P�[�V�����ɂ��Đ������̗��p���@�ɂ����܂����A��{�I�ɖ{�֐���p����
 * �����擾��1�t���[���ɂ���x�̂ݍs���悤�ɂ��Ă��������B<br>
 * \sa criAtomExPlayer_Create, criAtomExPlayer_Start, criAtomExPlayback_GetTime
 */
CriSint64 CRIAPI criAtomExPlayback_GetTimeSyncedWithAudioMicro(CriAtomExPlaybackId id);

/*JP
 * \brief �V�[�P���X�Đ��ʒu�̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id		�Đ�ID
 * \return		Sint64	�V�[�P���X�Đ��ʒu�i�~���b�P�ʁj
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̃V�[�P���X�Đ��ʒu���擾���܂��B<br>
 * <br>
 * �Đ��ʒu���擾�ł����ꍇ�A�{�֐��� 0 �ȏ�̒l��Ԃ��܂��B<br>
 * �w�肵���V�[�P���X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��͕��l��Ԃ��܂��B<br>
 * \par ���l:
 * �{�֐����Ԃ��Đ������́u�V�[�P���X�f�[�^��̍Đ��ʒu�v�ł��B<br>
 * �V�[�P���X���[�v��A�u���b�N�J�ڂ��s�����ꍇ�́A�����߂����l���Ԃ�܂��B<br>
 * <br>
 * �L���[�w��ȊO�ł̍Đ��ł̓V�[�P���T�[�����삵�܂���B�L���[�Đ��ȊO�̍Đ��ɑ΂���
 * �{�֐��͕��l��Ԃ��܂��B<br>
 * <br>
 * ::criAtomExPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ��ʒu�̍X�V����~���܂��B<br>
 * �i�|�[�Y����������΍ēx�X�V���ĊJ����܂��B�j
 * <br>
 * �{�֐��Ŏ擾�\�Ȏ����̐��x�́A�T�[�o�[�����̎��g���Ɉˑ����܂��B<br>
 * �i�����̍X�V�̓T�[�o�[�����P�ʂōs���܂��B�j<br>
 * \attention
 * �߂�l�̌^��CriSint64�ł����A����A32bit�ȏ�̐��x�͂���܂���B<br>
 * �Đ��ʒu�����ɐ�����s���ꍇ�A�V�[�P���X���[�v���̐ݒ肪�Ȃ��f�[�^�ł͖�24���ōĐ��ʒu���ُ�ɂȂ�_�ɒ��ӂ��K�v�ł��B<br>
 * �i 2147483647 �~���b�𒴂������_�ŁA�Đ��ʒu���I�[�o�[�t���[���A���l�ɂȂ�܂��B�j<br>
 * <br>
 * �{�֐��́A�����Đ����݈̂ʒu���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��V�[�P���X���������ꂽ�ꍇ�ɂ́A
 * �Đ��ʒu�̎擾�Ɏ��s���܂��B<br>
 * �i���l���Ԃ�܂��B�j<br>
 */
CriSint64 CRIAPI criAtomExPlayback_GetSequencePosition(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ��T���v�����̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id				�Đ�ID
 * \param[out]	num_samples		�Đ��ς݃T���v����
 * \param[out]	sampling_rate	�T���v�����O���[�g
 * \return		CriBool			�T���v�������擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����̍Đ��T���v�����A
 * ����уT���v�����O���[�g��Ԃ��܂��B<br>
 * <br>
 * �Đ��T���v�������擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * �i�G���[�������� num_samples �� sampling_rate �̒l�����l�ɂȂ�܂��B�j<br>
 * \par ���l:
 * �Đ��ς݃T���v�����̒l�̐��x�́A�v���b�g�t�H�[�� SDK 
 * �̃T�E���h���C�u�����Ɉˑ����܂��B<br>
 * �i�v���b�g�t�H�[���ɂ���āA�Đ��ς݃T���v�����̐��m���͈قȂ�܂��B�j<br>
 * <br>
 * �����̉����f�[�^���܂ރL���[���Đ������ꍇ�A�ŏ��Ɍ�����������
 * �f�[�^�̏�񂪕Ԃ���܂��B<br>
 * \attention
 * �h���C�u�Ń��[�h���g���C���������������A�����f�[�^�̋������r�؂ꂽ�ꍇ�A
 * �Đ��T���v�����̃J�E���g�A�b�v����~���܂��B<br>
 * �i�f�[�^�������ĊJ�����΁A�J�E���g�A�b�v���ĊJ����܂��B�j<br>
 * <br>
 * �{�֐��́A�����Đ����̂ݍĐ��T���v�������擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �Đ��T���v�����̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomExPlayer_Start
 */
CriBool CRIAPI criAtomExPlayback_GetNumPlayedSamples(
	CriAtomExPlaybackId id, CriSint64 *num_samples, CriSint32 *sampling_rate);

/*JP
 * \brief �T�E���h�o�b�t�@�[�ւ̏������݃T���v�����̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id				�Đ�ID
 * \param[out]	num_samples		�������ݍς݃T���v����
 * \param[out]	sampling_rate	�T���v�����O���[�g
 * \return		CriBool			�T���v�������擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɂ��āA
 * �T�E���h�o�b�t�@�[�ւ̏������ݍς݃T���v�����A����уT���v�����O���[�g��Ԃ��܂��B<br>
 * �{�֐��� ::criAtomExPlayback_GetNumPlayedSamples �֐��ƈقȂ�A
 * �T�E���h�o�b�t�@�[�ɏ������܂ꂽ���o�͂̉����f�[�^�̃T���v�������܂ޒl��Ԃ��܂��B
 * <br>
 * �������ݍς݃T���v�������擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * �i�G���[�������� num_samples �� sampling_rate �̒l�����l�ɂȂ�܂��B�j<br>
 * \par ���l:
 * �������ݍς݃T���v�����̒l�̐��x�́A�v���b�g�t�H�[�� SDK 
 * �̃T�E���h���C�u�����Ɉˑ����܂��B<br>
 * �i�v���b�g�t�H�[���ɂ���āA�������ݍς݃T���v�����̐��m���͈قȂ�܂��B�j<br>
 * <br>
 * �����̉����f�[�^���܂ރL���[���Đ������ꍇ�A�ŏ��Ɍ�����������
 * �f�[�^�̏�񂪕Ԃ���܂��B<br>
 * \attention
 * �h���C�u�Ń��[�h���g���C���������������A�����f�[�^�̋������r�؂ꂽ�ꍇ�A
 * �������ݍς݃T���v�����̃J�E���g�A�b�v����~���܂��B<br>
 * �i�f�[�^�������ĊJ�����΁A�J�E���g�A�b�v���ĊJ����܂��B�j<br>
 * <br>
 * �{�֐��́A�����Đ����̂ݏ������ݍς݃T���v�������擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �������ݍς݃T���v�����̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomExPlayback_GetNumPlayedSamples
 */
CriBool CRIAPI criAtomExPlayback_GetNumRenderedSamples(
	CriAtomExPlaybackId id, CriSint64 *num_samples, CriSint32 *sampling_rate);

/*JP
 * \brief �p�����[�^�̎擾�i���������_���j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	playback_id		�Đ�ID
 * \param[in]	parameter_id	�p�����[�^�[ID
 * \param[out]	value_float32	�p�����[�^�[�ݒ�l
 * \return		�p�����[�^�[���擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕��������_���Ŏ擾����܂��B<br>
 * �p�����[�^�[���擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂݃p�����[�^�[���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �p�����[�^�[�̎擾�Ɏ��s���܂��B<br>
 * \sa CriAtomExParameterId, criAtomExPlayback_GetParameterUint32, criAtomExPlayback_GetParameterSint32
 */
CriBool CRIAPI criAtomExPlayback_GetParameterFloat32(
	CriAtomExPlaybackId playback_id,
	CriAtomExParameterId parameter_id,
	CriFloat32 *value_float32
);

/*JP
 * \brief �p�����[�^�[�̎擾�i�����Ȃ������j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	playback_id		�Đ�ID
 * \param[in]	parameter_id	�p�����[�^�[ID
 * \param[out]	value_uint32	�p�����[�^�[�ݒ�l
 * \return		�p�����[�^�[���擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕����Ȃ������Ŏ擾����܂��B<br>
 * �p�����[�^�[���擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂݃p�����[�^�[���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �p�����[�^�[�̎擾�Ɏ��s���܂��B<br>
 * \sa CriAtomExParameterId, criAtomExPlayback_GetParameterFloat32, criAtomExPlayback_GetParameterSint32
 */
CriBool CRIAPI criAtomExPlayback_GetParameterUint32(
	CriAtomExPlaybackId playback_id,
	CriAtomExParameterId parameter_id,
	CriUint32* value_uint32
);

/*JP
 * \brief �p�����[�^�[�̎擾�i�����t�������j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	playback_id		�Đ�ID
 * \param[in]	parameter_id	�p�����[�^�[ID
 * \param[out]	value_sint32	�p�����[�^�[�ݒ�l
 * \return		�p�����[�^�[���擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɐݒ肳��Ă���e��p�����[�^�[�̒l���擾���܂��B<br>
 * �l�͕����t�������Ŏ擾����܂��B<br>
 * �p�����[�^�[���擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂݃p�����[�^�[���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * �p�����[�^�[�̎擾�Ɏ��s���܂��B<br>
 * \sa CriAtomExParameterId, criAtomExPlayback_GetParameterFloat32, criAtomExPlayback_GetParameterUint32
 */
CriBool CRIAPI criAtomExPlayback_GetParameterSint32(
	CriAtomExPlaybackId playback_id,
	CriAtomExParameterId parameter_id,
	CriSint32* value_sint32
);

/*JP
 * \brief AISAC�R���g���[���l�̎擾�i�R���g���[��ID�w��j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	playback_id		�Đ�ID
 * \param[in]	control_id		�R���g���[��ID
 * \param[out]	control_value	�R���g���[���l�i0.0f�`1.0f�j�A���ݒ莞��-1.0f
 * \return		AISAC�R���g���[���l���擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɐݒ肳��Ă���AISAC�R���g���[���l���A�R���g���[��ID�w��Ŏ擾���܂��B<br>
 * AISAC�R���g���[���l���擾�ł����ꍇ�i���ݒ莞���u-1.0f���擾�ł����v�ƈ����܂��j�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂�AISAC�R���g���[���l���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * AISAC�R���g���[���l�̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomExPlayer_SetAisacControlById, criAtomExPlayback_GetAisacControlByName
 */
CriBool CRIAPI criAtomExPlayback_GetAisacControlById(
	CriAtomExPlaybackId playback_id, CriAtomExAisacControlId control_id, CriFloat32 *control_value);

/*JP
 * \brief AISAC�R���g���[���l�̎擾�i�R���g���[�����w��j
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	playback_id		�Đ�ID
 * \param[in]	control_name	�R���g���[����
 * \param[out]	control_value	�R���g���[���l�i0.0f�`1.0f�j�A���ݒ莞��-1.0f
 * \return		AISAC�R���g���[���l���擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�����ɐݒ肳��Ă���AISAC�R���g���[���l���A�R���g���[�����w��Ŏ擾���܂��B<br>
 * AISAC�R���g���[���l���擾�ł����ꍇ�i���ݒ莞���u-1.0f���擾�ł����v�ƈ����܂��j�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �w�肵���{�C�X�����ɏ�������Ă���ꍇ���ɂ́A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂�AISAC�R���g���[���l���擾�\�ł��B<br>
 * �Đ��I�����A����������ɂ��{�C�X���������ꂽ�ꍇ�ɂ́A
 * AISAC�R���g���[���l�̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomExPlayer_SetAisacControlById, criAtomExPlayback_GetAisacControlByName
 */
CriBool CRIAPI criAtomExPlayback_GetAisacControlByName(
	CriAtomExPlaybackId playback_id, const CriChar8 *control_name, CriFloat32 *control_value);

/*JP
 * \brief �Đ����̃u���b�N�J��
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[in]	index		�u���b�N�C���f�b�N�X
 * \par ����:
 * �Đ����P�ʂŃu���b�N�J�ڂ��s���܂��B<br>
 * �{�֐������s����ƁA�w�肵��ID�̉������u���b�N�V�[�P���X�̏ꍇ�̓f�[�^��
 * �ݒ�ɏ]�����C�ӂ̑J�ڃ^�C�~���O�Ŏw��u���b�N�ɑJ�ڂ��܂��B
 * <br>
 * \par ���l:
 * �Đ��J�n�u���b�N�̎w��� ::criAtomExPlayer_SetFirstBlockIndex �֐����g�p���čs���A
 * �Đ����̃u���b�N�C���f�b�N�X�擾�� ::criAtomExPlayback_GetCurrentBlockIndex �֐����g�p���܂��B
 * \sa criAtomExPlayer_SetFirstBlockIndex, criAtomExPlayback_GetCurrentBlockIndex
 */
void CRIAPI criAtomExPlayback_SetNextBlockIndex(CriAtomExPlaybackId id, CriAtomExBlockIndex index);

/*JP
 * \brief �Đ����̃J�����g�u���b�N�C���f�b�N�X�̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id						�Đ�ID
 * \return		CriAtomExBlockIndex		�J�����g�u���b�N�C���f�b�N�X
 * \par ����:
 * ::criAtomExPlayer_Start �֐��ōĐ����ꂽ�u���b�N�V�[�P���X��
 * �J�����g�u���b�N�C���f�b�N�X���擾���܂��B<br>
 * \par ���l:
 * �Đ�ID�ɂ��Đ����Ă���f�[�^���u���b�N�V�[�P���X�ł͂Ȃ��ꍇ�́A
 * ::CRIATOMEX_INVALID_BLOCK_INDEX ���Ԃ�܂��B<br>
 * \sa criAtomExPlayer_Start, criAtomExPlayer_SetFirstBlockIndex, criAtomExPlayback_SetNextBlockIndex
 */
CriAtomExBlockIndex CRIAPI criAtomExPlayback_GetCurrentBlockIndex(CriAtomExPlaybackId id);

/*JP
 * \brief �Đ��g���b�N���̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[out]	info		�Đ��g���b�N���
 * \return		CriBool		�����^���s
 * \par ����:
 * �Đ����̃L���[�̃g���b�N�����擾���܂��B<br>
 * �擾�ł���g���b�N���̓L���[�����̏�񂾂��ł��A�T�u�V�[�P���X��L���[�����N�̏��͎擾�ł��܂���B<br>
 * \par ���l:
 * �ȉ��ɊY������f�[�^���Đ����̏ꍇ�A�g���b�N���̎擾�Ɏ��s���܂��B<br>
 * - �L���[�ȊO�̃f�[�^���Đ����Ă���B�i�g���b�N��񂪑��݂��Ȃ����߁j<br>
 * - �Đ����̃L���[���|���t�H�j�b�N�^�C�v�A�܂��̓Z���N�^�[�Q�Ƃ̃X�C�b�`�^�C�v�ł���B�i�g���b�N��񂪕������݂���\�������邽�߁j<br>
 * - �Đ����̃L���[���g���b�N�J�ڃ^�C�v�ł���B�i�J�ڂɂ��Đ��g���b�N���ς�邽�߁j<br>
 */
CriBool CRIAPI criAtomExPlayback_GetPlaybackTrackInfo(CriAtomExPlaybackId id, CriAtomExPlaybackTrackInfo* info);

/*JP
 * \brief �r�[�g�������̎擾
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[out]	info		�r�[�g�������
 * \return		CriBool		�����^���s
 * \par ����:
 * �Đ����̃L���[�̃r�[�g���������擾���܂��B<br>
 * ���݂�BPM�A���߂̃J�E���g�A���̃J�E���g�A���̐i������(0.0�`1.0)���擾���邱�Ƃ��ł��܂��B<br>
 * �L���[�ɂ̓r�[�g������񂪐ݒ肳��Ă���K�v������܂��B<br>
 * �L���[�����N��X�^�[�g�A�N�V�����ōĐ����Ă���L���[�̏��͎擾�ł��܂���B<br>
 * \par ���l:
 * �ȉ��ɊY������f�[�^���Đ����̏ꍇ�A�r�[�g�������̎擾�Ɏ��s���܂��B<br>
 * - �L���[�ȊO�̃f�[�^���Đ����Ă���B�i�r�[�g������񂪑��݂��Ȃ����߁j<br>
 * - �r�[�g������񂪐ݒ肳��Ă��Ȃ��L���[���Đ����Ă���B<br>
 * - �r�[�g������񂪐ݒ肳��Ă���L���[��"�ԐړI"�ɍĐ����Ă���B�i�L���[�����N��X�^�[�g�A�N�V�����ōĐ����Ă���j<br>
 */
CriBool CRIAPI criAtomExPlayback_GetBeatSyncInfo(CriAtomExPlaybackId id, CriAtomExBeatSyncInfo* info);

/*JP
 * \brief �r�[�g�����I�t�Z�b�g�̐ݒ�
 * \ingroup ATOMEXLIB_PLAYBACK
 * \param[in]	id			�Đ�ID
 * \param[in]	time_ms		�I�t�Z�b�g����
 * \return		CriBool		�����^���s
 * \par ����:
 * �Đ����̃L���[�̃r�[�g�����I�t�Z�b�g��ݒ肵�܂��B<br>
 * �L���[�ɂ̓r�[�g������񂪐ݒ肳��Ă���K�v������܂��B<br>
 * �L���[�����N��X�^�[�g�A�N�V�����ōĐ����Ă���L���[�ւ̐ݒ�͂ł��܂���B<br>
 * \par ���l:
 * �ȉ��ɊY������f�[�^���Đ����̏ꍇ�A�r�[�g�����I�t�Z�b�g�̐ݒ�Ɏ��s���܂��B<br>
 * - �L���[�ȊO�̃f�[�^���Đ����Ă���B�i�r�[�g������񂪑��݂��Ȃ����߁j<br>
 * - �r�[�g������񂪐ݒ肳��Ă��Ȃ��L���[���Đ����Ă���B<br>
 * - �r�[�g������񂪐ݒ肳��Ă���L���[��"�ԐړI"�ɍĐ����Ă���B�i�L���[�����N��X�^�[�g�A�N�V�����ōĐ����Ă���j<br>
 */
CriBool CRIAPI criAtomExPlayback_SetBeatSyncOffset(CriAtomExPlaybackId id, CriSint16 time_ms);

/*==========================================================================
 *      CRI AtomEx Fader API
 *=========================================================================*/
/*JP
 * \brief �t�F�[�_�[�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	config		�t�F�[�_�[�A�^�b�`�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * AtomEx�v���[���[�Ƀt�F�[�_�[���A�^�b�`����̂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^�����Ƀt�F�[�_�[���A�^�b�`����ꍇ�A���炩���ߖ{�֐��Ōv�Z����
 * ���[�N�̈�T�C�Y���̃����������[�N�̈�Ƃ��� ::criAtomExPlayer_AttachFader �֐���
 * �Z�b�g����K�v������܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExFader_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomExFaderConfig, criAtomExPlayer_AttachFader
 */
CriSint32 CRIAPI criAtomExPlayer_CalculateWorkSizeForFader(
	const CriAtomExFaderConfig *config);

/*JP
 * \brief �v���[���[�Ƀt�F�[�_�[�����t����
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player		AtomEx�v���[���[
 * \param[in]	config		�t�F�[�_�[�A�^�b�`�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * �v���[���[�Ƀt�F�[�_�[���A�^�b�`�i���t���j���A
 * AtomExPlayer���N���X�t�F�[�h��p�̃v���[���[�ɕω������܂��B<br>
 * �i�������̓����Đ����A�]����AtomExPlayer�̎��@�\���ꕔ���p�ł��Ȃ��Ȃ�܂��B�j<br>
 * <br>
 * �{�֐��Ńt�F�[�_�[���A�^�b�`�����v���[���[�́A�ȍ~�����Đ��J�n��
 * �i ::criAtomExPlayer_Start �֐��� ::criAtomExPlayer_Prepare ���s�����s���閈�j�ɁA
 * �ȉ��̐�����s���܂��B<br>
 * - ���Ƀt�F�[�h�A�E�g���̉�������΋�����~�B
 * - ���ݍĐ����i�܂��̓t�F�[�h�C�����j�̉������t�F�[�h�A�E�g�B
 * - �V�K�ɍĐ����J�n���鉹�����t�F�[�h�C���B
 * 
 * <br>
 * �܂��A�Đ���~���i ::criAtomExPlayer_Stop �֐����s���j�ɂ́A
 * �ȉ��̐�����s���܂��B<br>
 * - ���Ƀt�F�[�h�A�E�g���̉�������΋�����~�B
 * - ���ݍĐ����i�܂��̓t�F�[�h�C�����j�̉������t�F�[�h�A�E�g�B
 * 
 * <br>
 * �v���[���[�Ƀt�F�[�_�[�����t����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExPlayer_CalculateWorkSizeForFader 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * <br>
 * �t�F�[�_�[�̃A�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * �t�F�[�_�[�̃A�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \par ��:
 * 2 �̃L���[�i MUSIC1 �� MUSIC2 �j���N���X�t�F�[�h������ꍇ�̏����́A�ȉ��̂Ƃ���ł��B<br>
 * \code
 * 		�F
 * 	// AtomEx�v���[���[�̍쐬
 * 	player = criAtomExPlayer_Create(NULL, NULL, 0);
 * 	
 * 	// �v���[���[�Ƀt�F�[�_�[���A�^�b�`
 * 	criAtomExPlayer_AttachFader(player, NULL, NULL, 0);
 * 	
 * 	// �t�F�[�h�C���^�A�E�g���Ԃ̎w��
 * 	// ���l�j���L�̗�ł�5�b�ŃN���X�t�F�[�h���s���悤�w��B
 * 	criAtomExPlayer_SetFadeInTime(player, 5000);	// �t�F�[�h�C�����Ԃ̎w��
 * 	criAtomExPlayer_SetFadeOutTime(player, 5000);	// �t�F�[�h�A�E�g���Ԃ̎w��
 * 	
 * 	// �Đ����鉹���f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueName(player, acb_hn, "MUSIC1");
 * 	
 * 	// �Đ��̊J�n
 * 	// ���l�j���̏����ɂ��AMUSIC1��5�b�Ńt�F�[�h�C�����Ȃ���Đ������B
 * 	criAtomExPlayer_Start(player);
 * 		�F
 * 	�i�Đ����[�v�j
 * 		�F
 * 	// ���ɍĐ����鉹���f�[�^���Z�b�g
 * 	criAtomExPlayer_SetCueName(player, acb_hn, "MUSIC2");
 * 	
 * 	// �Đ��̊J�n
 * 	// ���l�j���̏����ɂ��AMUSIC1���t�F�[�h�A�E�g���AMUSIC2���t�F�[�h�C�����Ȃ���Đ������B
 * 	criAtomExPlayer_Start(player);
 * 		�F
 * \endcode
 * \par ���l:
 * �t�F�[�_�[���A�^�b�`����v���[���[�������Đ����̏ꍇ�A�{�֐������s�����^�C�~���O��
 * �v���[���[���Đ����̉����͑S�Ē�~����܂��B<br>
 * <br>
 * �t�F�[�_�[�́A�A�^�b�`���̃v���[���[�ɑ΂��� ::criAtomExPlayer_Start
 * �֐���A ::criAtomExPlayer_Stop �֐������s�����x�A
 * ���Y�v���[���[�ōĐ����̉����ɑ΂��Ĉȉ��̐�����s���܂��B<br>
 * <br>
 * -# ���Ƀt�F�[�h�A�E�g���̉��������݂���ꍇ�A���̉����𑦍��ɒ�~����B
 * -# �t�F�[�h�C�����̉����i�܂��͍Đ����̉����j�����݂���ꍇ�A
 * ���̉��������̎��_�̉��ʂ��� ::criAtomExPlayer_SetFadeOutTime 
 * �֐��Ŏw�肳�ꂽ���Ԃ������ăt�F�[�h�A�E�g������B
 * -# ::criAtomExPlayer_Start �֐������s���ꂽ�ꍇ�A
 * �v���[���[�ɃZ�b�g����Ă��鉹���f�[�^���{�����[��0�ōĐ��J�n���A
 * ::criAtomExPlayer_SetFadeInTime �֐��Ŏw�肳�ꂽ���Ԃ������ăt�F�[�h�C��������B
 * 
 * <br>
 * �i ::criAtomExPlayer_Start �֐��̑���� ::criAtomExPlayer_Prepare 
 * �֐����g�p�����ꍇ�A�|�[�Y���������鎞�_�ŏ�L�̐��䂪�s���܂��B�j<br>
 * \attention
 * �{�֐������s����ƁAAtomExPlayer�ɑ΂���Đ��^��~���삪�傫���ύX����܂��B<br>
 * �i�t�F�[�_�[�A�^�b�`�O��ŋ������傫���ς��܂��B�j<br>
 * ��̓I�ɂ́A�����ɔ����\�ȉ����̐���1���i�N���X�t�F�[�h���̂�2���j�Ɍ��肳��A
 * ::CriAtomExPlaybackId ��p����������s���Ȃ��Ȃ�܂��B<br>
 * <br>
 * �{�֐��́A�N���X�t�F�[�h�������s�������ꍇ�ɂ̂ݕK�v�ƂȂ�܂��B<br>
 * 1�������̃t�F�[�h�C���^�A�E�g�ɂ��ẮA�G���x���[�v��Tween�������p���������B<br>
 * <br>
 * �{�֐��Ƀ��[�N�̈���Z�b�g�����ꍇ�A�Z�b�g�����̈�̃��������t�F�[�_�[�f�^�b�`��
 * �܂ŃA�v���P�[�V�������ŕێ���������K�v������܂��B<br>
 * �i�Z�b�g�ς݂̃��[�N�̈�ɒl���������񂾂�A��������������肵�Ă͂����܂���B�j<br>
 * <br>
 * �t�F�[�_�[�̓���d�l�̓s����A�t�F�[�h�C���^�A�E�g�̏����ΏۂƂȂ�̂́A
 * �ߋ�2��̉����Đ��݂̂ł��B<br>
 * ����ȑO�ɍĐ����ꂽ�����́A ::criAtomExPlayer_Start �֐���
 * ::criAtomExPlayer_Stop �֐������s���ꂽ���_�ŋ����I�ɒ�~����܂��B<br>
 * ������~�����̃^�C�~���O�ňӐ}���Ȃ��m�C�Y���������鋰�ꂪ����܂��̂ŁA
 * �����Đ�����3���ȏ�ɂȂ�Ȃ��悤���ӂ��Ă��������B<br>
 * �i ::criAtomExPlayer_GetNumPlaybacks �֐��œ����Đ������m�F���Ă��������B�j<br>
 * <br>
 * �t�F�[�h�C���^�A�E�g���@�\����̂́wAtomEx�v���[���[�ɑ΂��鑀��x�݂̂ł��B<br>
 * ::criAtomExPlayer_Start �֐����s���Ɏ擾�����Đ�ID�ɑ΂��A
 * ::criAtomExPlayback_Stop �����s���Ă��A�t�F�[�h�A�E�g�͍s���܂���B<br>
 * �i�t�F�[�_�[�̐ݒ肪��������A�����ɒ�~�������s���܂��B�j<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa CriAtomExFaderConfig, criAtomExPlayer_CalculateWorkSizeForFader
 */
void CRIAPI criAtomExPlayer_AttachFader(CriAtomExPlayerHn player,
	const CriAtomExFaderConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �v���[���[����t�F�[�_�[�����O��
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player		AtomEx�v���[���[
 * \par ����:
 * �v���[���[����t�F�[�_�[���f�^�b�`�i���O���j���܂��B<br>
 * �{�֐��Ńt�F�[�_�[���f�^�b�`�����v���[���[�ɂ́A�ȍ~�t�F�[�h�C���^�A�E�g�̏������s���Ȃ��Ȃ�܂��B<br>
 * \par ���l:
 * �t�F�[�_�[���f�^�b�`����v���[���[�������Đ����̏ꍇ�A�{�֐������s�����^�C�~���O��
 * �v���[���[���Đ����̉����͑S�Ē�~����܂��B<br>
 * <br>
 * �{�֐������s�����Ƀv���[���[��j�������ꍇ�A�v���[���[�j�����i ::criAtomExPlayer_Destroy �֐����s���j
 * �Ƀ��C�u�������Ńt�F�[�_�[�̃f�^�b�`���s���܂��B<br>
 * \sa criAtomExPlayer_AttachFader
 */
void CRIAPI criAtomExPlayer_DetachFader(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�h�A�E�g���Ԃ̐ݒ�
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	ms		�t�F�[�h�A�E�g���ԁi�~���b�w��j
 * \par ����:
 * �t�F�[�_�[���A�^�b�`�ς݂̃v���[���[�ɑ΂��A�t�F�[�h�A�E�g���Ԃ��w�肵�܂��B<br>
 * ���񉹐��Đ����i ::criAtomExPlayer_Start �֐����s���j�ɂ́A�{�֐��Őݒ肳�ꂽ
 * ���ԂōĐ����̉������t�F�[�h�A�E�g���܂��B<br>
 * <br>
 * �t�F�[�h�A�E�g���Ԃ̃f�t�H���g�l�� 500 �~���b�ł��B<br>
 * \par ���l:
 * �t�F�[�h�A�E�g���Ԃ��ݒ肳��Ă���ꍇ�AAtomEx�v���[���[�͈ȉ��̏����ōĐ����~���܂��B<br>
 * <br>
 *	-# �w�肳�ꂽ���Ԃŉ����̃{�����[���� 0 �܂ŗ��Ƃ��B
 *	-# �{�����[���� 0 �̏�ԂŃf�B���C���Ԃ��o�߂���܂ōĐ��𑱂���B
 *	-# �f�B���C���Ԍo�ߌ�ɍĐ����~����B
 * 	
 * <br>
 * �t�F�[�h�A�E�g���̃{�����[���R���g���[���́A�����Đ���~�O�ɍs���܂��B<br>
 * ���̂��߁A�g�`�f�[�^�ɂ��炩���ߐݒ肳�ꂽ�G���x���[�v�̃����[�X���Ԃ͖�������܂��B<br>
 * �i�����ɂ́A�{�����[���� 0 �ɂȂ��Ă���G���x���[�v�̃����[�X�������K�p����܂��B�j<br>
 * <br>
 * ��2�����i ms �j�� 0 ���w�肷��ꍇ�ƁA ::CRIATOMEX_IGNORE_FADE_OUT
 * ���w�肷��ꍇ�Ƃł́A�ȉ��̂悤�ɋ������قȂ�܂��B<br>
 * <br>
 *	- 0�w�莞�F�����Ƀ{�����[���� 0 �ɗ��Ƃ���A��~�������s����B
 *	- CRIATOMEX_IGNORE_FADE_OUT�w�莞�F�{�����[���ύX�͍s��ꂸ�A��~�������s����B
 * 	
 * <br>
 * �Đ���~���Ƀt�F�[�h�A�E�g�������s�킸�A�g�`�ɂ��炩���ߐݒ肳��Ă���
 * �G���x���[�v�̃����[�X������L���ɂ������ꍇ�A��2�����i ms �j�ɁA
 * ::CRIATOMEX_IGNORE_FADE_OUT ���w�肵�Ă��������B<br>
 * ::CRIATOMEX_IGNORE_FADE_OUT ���w�肷�邱�ƂŁA
 * �t�F�[�h�A�E�g�����ɂ��{�����[�����䂪�s���Ȃ��Ȃ邽�߁A
 * ::criAtomExPlayer_Stop �֐����s��A�f�B���C���Ԍo�ߌ�ɒʏ�̒�~�������s���܂��B<br>
 * �i�g�`�f�[�^�ɃG���x���[�v�̃����[�X���ݒ肳��Ă���ꍇ�A�����[�X�������s���܂��B�j<br>
 * \attention
 * �{�֐������s����O�ɁA ::criAtomExPlayer_AttachFader �֐����g�p����
 * ���炩���߃v���[���[�Ƀt�F�[�_�[���A�^�b�`���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Őݒ肵���l�́A���ɍĐ����̉����ɂ͈�؉e�����܂���B<br>
 * �{�֐��Őݒ肵���t�F�[�h���Ԃ́A�{�֐����s��� ::criAtomExPlayer_Start �֐���
 * ::criAtomExPlayer_Stop �֐������s����^�C�~���O�œK�p����܂��B<br>
 * �i���Ƀt�F�[�h�A�E�g���J�n���Ă��鉹���ɑ΂��ẮA
 * �{�֐��Ōォ��t�F�[�h�A�E�g���Ԃ�ύX���邱�Ƃ͂ł��܂���B�j<br>
 * \sa criAtomExPlayer_AttachFader, criAtomExPlayer_SetFadeInTime
 */
void CRIAPI criAtomExPlayer_SetFadeOutTime(CriAtomExPlayerHn player, CriSint32 ms);

/*JP
 * \brief �t�F�[�h�A�E�g���Ԃ̎擾
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \return	CriSint32	�t�F�[�h�A�E�g���ԁi�~���b�P�ʁj
 * \par ����:
 * �t�F�[�h�A�E�g���Ԃ��擾���܂��B<br>
 * \par ���l:
 * �{�֐��� ::criAtomExPlayer_SetFadeOutTime �֐��ŃZ�b�g�����l��Ԃ��܂��B<br>
 * \sa criAtomExPlayer_SetFadeOutTime
 */
CriSint32 CRIAPI criAtomExPlayer_GetFadeOutTime(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�h�C�����Ԃ̐ݒ�
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	ms		�t�F�[�h�C�����ԁi�~���b�w��j
 * \par ����:
 * �t�F�[�_�[���A�^�b�`�ς݂̃v���[���[�ɑ΂��A�t�F�[�h�C�����Ԃ��w�肵�܂��B<br>
 * ���񉹐��Đ����i ::criAtomExPlayer_Start �֐����s���j�ɂ́A�{�֐��Őݒ肳�ꂽ
 * ���ԂŐV�K�ɉ������t�F�[�h�C���Đ�����܂��B<br>
 * <br>
 * �t�F�[�h�C�����Ԃ̃f�t�H���g�l�� 0 �b�ł��B<br>
 * ���̂��߁A�{�֐����g�p���Ȃ��ꍇ�t�F�[�h�C���͍s��ꂸ�A�����Ƀt���{�����[��
 * �ŉ����̍Đ����J�n����܂��B<br>
 * \attention
 * �{�֐������s����O�ɁA ::criAtomExPlayer_AttachFader �֐����g�p����
 * ���炩���߃v���[���[�Ƀt�F�[�_�[���A�^�b�`���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Őݒ肵���l�́A���ɍĐ����̉����ɂ͈�؉e�����܂���B<br>
 * �{�֐��Őݒ肵���t�F�[�h���Ԃ́A�{�֐����s��� ::criAtomExPlayer_Start �֐���
 * ���s����^�C�~���O�œK�p����܂��B<br>
 * �i���Ƀt�F�[�h�C�����J�n���Ă��鉹���ɑ΂��ẮA
 * �{�֐��Ōォ��t�F�[�h�C�����Ԃ�ύX���邱�Ƃ͂ł��܂���B�j<br>
 * \sa criAtomExPlayer_AttachFader, criAtomExPlayer_SetFadeInTime
 */
void CRIAPI criAtomExPlayer_SetFadeInTime(CriAtomExPlayerHn player, CriSint32 ms);

/*JP
 * \brief �t�F�[�h�C�����Ԃ̎擾
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \return	CriSint32	�t�F�[�h�C�����ԁi�~���b�P�ʁj
 * \par ����:
 * �t�F�[�h�C�����Ԃ��擾���܂��B<br>
 * \par ���l:
 * �{�֐��� ::criAtomExPlayer_SetFadeInTime �֐��ŃZ�b�g�����l��Ԃ��܂��B<br>
 * \sa criAtomExPlayer_SetFadeInTime
 */
CriSint32 CRIAPI criAtomExPlayer_GetFadeInTime(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�h�C���J�n�I�t�Z�b�g�̐ݒ�
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	ms		�t�F�[�h�C���J�n�I�t�Z�b�g�i�~���b�w��j
 * \par ����:
 * �t�F�[�_�[���A�^�b�`�ς݂̃v���[���[�ɑ΂��A�t�F�[�h�C���J�n�I�t�Z�b�g���w�肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�t�F�[�h�C�����J�n����^�C�~���O���t�F�[�h�A�E�g�ɑ΂���
 * �C�ӂ̎��ԑ��߂���A�x�点�邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�t�F�[�h�A�E�g���Ԃ�5�b�A�t�F�[�h�C���J�n�I�t�Z�b�g��5�b�ɐݒ肵���ꍇ�A
 * �t�F�[�h�A�E�g��5�b�Ŋ�����������Ɏ��̉������t�F�[�h�C�������邱�Ƃ��\�ł��B<br>
 * �t�ɁA�t�F�[�h�C�����Ԃ�5�b�A�t�F�[�h�C���J�n�I�t�Z�b�g��-5�b�ɐݒ肵���ꍇ�A
 * �t�F�[�h�C����5�b�Ŋ�����������ɍĐ����̉��̃t�F�[�h�A�E�g���J�n�����邱�Ƃ��\�ł��B<br>
 * <br>
 * �t�F�[�h�C���J�n�I�t�Z�b�g�̃f�t�H���g�l�� 0 �b�ł��B<br>
 * �i�t�F�[�h�C���ƃt�F�[�h�A�E�g�������ɊJ�n����܂��B�j<br>
 * \par ���l:
 * �t�F�[�h�C���J�n�̃^�C�~���O�́A�t�F�[�h�C�����鉹���̍Đ��������������^�C�~���O�ł��B<br>
 * ���̂��߁A�t�F�[�h�C���J�n�I�t�Z�b�g�� 0 �b�ɐݒ肳��Ă���ꍇ�ł��A�t�F�[�h�C������
 * �̃o�b�t�@�����O�Ɏ��Ԃ�������ꍇ�i�X�g���[���Đ������j�ɂ́A�t�F�[�h�A�E�g�̊J�n�܂ł�
 * ���΂炭���Ԃ�������܂��B<br>
 * �i�{�p�����[�^�[�́A�t�F�[�h�C���ƃt�F�[�h�A�E�g�̃^�C�~���O�𒲐����邽�߂̑��Βl�ł��B�j<br>
 * \attention
 * �{�֐������s����O�ɁA ::criAtomExPlayer_AttachFader �֐����g�p����
 * ���炩���߃v���[���[�Ƀt�F�[�_�[���A�^�b�`���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Őݒ肵���l�́A���ɍĐ����̉����ɂ͈�؉e�����܂���B<br>
 * �{�֐��Őݒ肵���t�F�[�h���Ԃ́A�{�֐����s��� ::criAtomExPlayer_Start �֐���
 * ::criAtomExPlayer_Stop �֐������s����^�C�~���O�œK�p����܂��B<br>
 * �i���Ƀt�F�[�h�������J�n���Ă��鉹���ɑ΂��ẮA
 * �{�֐��Ōォ��t�F�[�h�����̃^�C�~���O��ύX���邱�Ƃ͂ł��܂���B�j<br>
 * \sa criAtomExPlayer_AttachFader, criAtomExPlayer_SetFadeInTime
 */
void CRIAPI criAtomExPlayer_SetFadeInStartOffset(CriAtomExPlayerHn player, CriSint32 ms);

/*JP
 * \brief �t�F�[�h�C���J�n�I�t�Z�b�g�̎擾
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \return	CriSint32	�t�F�[�h�C���J�n�I�t�Z�b�g�i�~���b�P�ʁj
 * \par ����:
 * �t�F�[�h�C���J�n�I�t�Z�b�g���擾���܂��B<br>
 * \par ���l:
 * �{�֐��� ::criAtomExPlayer_SetFadeInStartOffset �֐��ŃZ�b�g�����l��Ԃ��܂��B<br>
 * \sa criAtomExPlayer_SetFadeInStartOffset
 */
CriSint32 CRIAPI criAtomExPlayer_GetFadeInStartOffset(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�h�A�E�g��̃f�B���C���Ԃ̐ݒ�
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \param[in]	ms		�t�F�[�h�C���J�n�I�t�Z�b�g�i�~���b�w��j
 * \par ����:
 * �t�F�[�h�A�E�g������A�{�C�X��j������܂ł̃f�B���C���Ԃ�ݒ肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�t�F�[�h�A�E�g���I�����{�C�X���j�������܂ł̃^�C�~���O��C�ӂɐݒ�\�ł��B<br>
 * <br>
 * �f�B���C���Ԃ̃f�t�H���g�l�� 500 �~���b�ł��B<br>
 * �i�t�F�[�h�A�E�g�����Đ�����{�C�X�́A�{�����[���� 0 �ɐݒ肳�ꂽ��A 500 �~���b��ɔj������܂��B�j<br>
 * \par ���l:
 * �����̃t�F�[�h�A�E�g����������O�Ƀ{�C�X����~�����v���b�g�t�H�[���ȊO�́A
 * �{�֐����g�p����K�v�͂���܂���B<br>
 * \attention
 * �{�֐������s����O�ɁA ::criAtomExPlayer_AttachFader �֐����g�p����
 * ���炩���߃v���[���[�Ƀt�F�[�_�[���A�^�b�`���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Őݒ肵���l�́A���ɍĐ����̉����ɂ͈�؉e�����܂���B<br>
 * �{�֐��Őݒ肵���t�F�[�h���Ԃ́A�{�֐����s��� ::criAtomExPlayer_Start �֐���
 * ::criAtomExPlayer_Stop �֐������s����^�C�~���O�œK�p����܂��B<br>
 * �i���Ƀt�F�[�h�A�E�g���J�n���Ă��鉹���ɑ΂��ẮA
 * �{�֐��Ōォ��t�F�[�h�A�E�g��̃f�B���C���Ԃ�ύX���邱�Ƃ͂ł��܂���B�j<br>
 * <br>
 * �{�����[���̐���ƃ{�C�X�̒�~�����f�����^�C�~���O�́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * ���̂��߁A�{�֐��� 0 ���w�肵���ꍇ�A�v���b�g�t�H�[���ɂ���Ă̓{�����[���̕ύX�����f�����
 * �O�Ƀ{�C�X����~����鋰�ꂪ����܂��B<br>
 * \sa criAtomExPlayer_AttachFader, criAtomExPlayer_SetFadeInTime
 */
void CRIAPI criAtomExPlayer_SetFadeOutEndDelay(CriAtomExPlayerHn player, CriSint32 ms);

/*JP
 * \brief �t�F�[�h�A�E�g��̃f�B���C���Ԃ̎擾
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \return	CriSint32	�t�F�[�h�A�E�g��̃f�B���C���ԁi�~���b�P�ʁj
 * \par ����:
 * �t�F�[�h�A�E�g��̃f�B���C���Ԃ��擾���܂��B<br>
 * \par ���l:
 * �{�֐��� ::criAtomExPlayer_SetFadeOutEndDelay �֐��ŃZ�b�g�����l��Ԃ��܂��B<br>
 * \sa criAtomExPlayer_SetFadeOutEndDelay
 */
CriSint32 CRIAPI criAtomExPlayer_GetFadeOutEndDelay(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�h���������ǂ����̃`�F�b�N
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \return	CriBool		�t�F�[�h���������ǂ����iCRI_TRUE = �t�F�[�h�������ACRI_FALSE = �t�F�[�h�������ł͂Ȃ��j
 * \par ����:
 * �t�F�[�h�������s���Ă���Œ����ǂ������`�F�b�N���܂��B<br>
 * \par ���l:
 * �{�֐��́A�ȉ��̏������Ԓ� CRI_TRUE ��Ԃ��܂��B<br>
 * - �N���X�t�F�[�h�J�n�̂��߂̓����҂����B
 * - �t�F�[�h�C���^�t�F�[�h�A�E�g�������i�{�����[���ύX���j�B
 * - �t�F�[�h�A�E�g������̃f�B���C���Ԓ��B
 * 
 */
CriBool CRIAPI criAtomExPlayer_IsFading(CriAtomExPlayerHn player);

/*JP
 * \brief �t�F�[�_�[�p�����[�^�[�̏�����
 * \ingroup ATOMEXLIB_FADER
 * \param[in]	player	AtomEx�v���[���[�n���h��
 * \par ����:
 * �t�F�[�_�[�ɐݒ肳��Ă���e��p�����[�^�[���N���A���A�����l�ɖ߂��܂��B<br>
 * \attention
 * �{�֐������s����O�ɁA ::criAtomExPlayer_AttachFader �֐����g�p����
 * ���炩���߃v���[���[�Ƀt�F�[�_�[���A�^�b�`���Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��Ńt�F�[�_�[�p�����[�^�[���N���A���Ă��A���ɍĐ����̉����ɂ͈�؉e�����܂���B<br>
 * �{�֐��ŃN���A�����t�F�[�_�[�p�����[�^�[�́A�{�֐����s��� ::criAtomExPlayer_Start �֐���
 * ::criAtomExPlayer_Stop �֐������s����^�C�~���O�œK�p����܂��B<br>
 * �i���Ƀt�F�[�h�������J�n���Ă��鉹���ɑ΂��ẮA
 * �{�֐��ŃN���A�����t�F�[�_�[�p�����[�^�[��K�p���邱�Ƃ͂ł��܂���B�j<br>
 * \sa criAtomExPlayer_AttachFader, criAtomExPlayer_SetFadeInTime
 */
void CRIAPI criAtomExPlayer_ResetFaderParameters(CriAtomExPlayerHn player);


/*==========================================================================
 *      CRI AtomEx Sequencer API
 *=========================================================================*/
/*JP
 * \brief �V�[�P���X�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_SEQUENCER
 * \param[in]	func		�V�[�P���X�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �V�[�P���X�f�[�^�ɖ��ߍ��܂ꂽ�R�[���o�b�N�����󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�T�[�o�[�֐����ŃR�[���o�b�N�C�x���g�����������^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExSequencerEventCbFunc
 */
void CRIAPI criAtomExSequencer_SetEventCallback(CriAtomExSequencerEventCbFunc func, void* obj);

/*==========================================================================
 *      CRI AtomEx Beat Sync API
 *=========================================================================*/
/*JP
 * \brief �r�[�g�����ʒu���o�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_BEATSYNC
 * \param[in]	func		�r�[�g�����ʒu���o�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �r�[�g�����ʒu���o�����󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�T�[�o�[�֐����Ńr�[�g�����ʒu���o�����������^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomExBeatSyncCbFunc
 */
void CRIAPI criAtomExBeatSync_SetCallback(CriAtomExBeatSyncCbFunc func, void* obj);

/*==========================================================================
 *      CRI AtomEx 3D API
 *=========================================================================*/
/*JP
 * \brief 3D�����n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config		3D�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	3D�����n���h���쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * 3D�����n���h�����쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������3D�����n���h�����쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomEx3dSource_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * 3D�����n���h���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A3D�����n���h���쐬�p�R���t�B�O
 * �\���́i ::CriAtomEx3dSourceConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx3dSource_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B

 * \sa criAtomEx3dSource_Create, CriAtomEx3dSourceConfig
 */
CriSint32 CRIAPI criAtomEx3dSource_CalculateWorkSize(const CriAtomEx3dSourceConfig *config);

/*JP
 * \brief 3D�����n���h���̍쐬
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config				3D�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work				3D�����n���h���쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size			3D�����n���h���쐬�p���[�N�T�C�Y
 * \return		CriAtomEx3dSourceHn	3D�����n���h��
 * \par ����:
 * 3D�����n���h���쐬�p�R���t�B�O�Ɋ�Â��āA3D�����n���h�����쐬���܂��B<br>
 * �쐬�ɐ�������ƁA3D�����n���h����Ԃ��܂��B<br>
 * 3D�����n���h�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomEx3dSource_CalculateWorkSize 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomEx3dSource_CalculateWorkSize, criAtomEx3dSource_Destroy
 */
CriAtomEx3dSourceHn CRIAPI criAtomEx3dSource_Create(
	const CriAtomEx3dSourceConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief 3D�����n���h���̔j��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \par ����:
 * 3D�����n���h����j�����܂��B<br>
 * �{�֐������s�������_�ŁA3D�����n���h���쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��3D�����n���h���������ɂȂ�܂��B<br>
 * 3D�����n���h�����Z�b�g����AtomEx�v���[���[�ōĐ����Ă��鉹��������ꍇ�A
 * �{�֐������s����O�ɁA�����̉������~���邩�A����AtomEx�v���[���[��j�����Ă��������B
 * \sa criAtomEx3dSource_Create
 */
void CRIAPI criAtomEx3dSource_Destroy(CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����̍X�V
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \par ����:
 * 3D�����ɐݒ肳��Ă���p�����[�^�[���g�p���āA3D�������X�V���܂��B<br>
 * �{�֐��ł́A3D�����ɐݒ肳��Ă���S�Ẵp�����[�^�[���X�V���܂��B
 * �p�����[�^�[���ЂƂύX����x�ɖ{�֐��ɂčX�V�������s�������A
 * �����̃p�����[�^�[��ύX���Ă���X�V�������s�������������I�ł��B
 * \par ��:
 * \code
 * CriAtomExVector pos;
 * CriAtomExVector vel;
 * 
 * // Set position
 * pos.x = 0.0f
 * pos.y = 0.0f
 * pos.z = 1.0f
 * criAtomEx3dSource_SetPosition(source, &pos);
 * // Set velocity
 * vel.x = 1.0f
 * vel.y = 0.0f
 * vel.z = 0.0f
 * criAtomEx3dSource_SetVelocity(source, &vel);
 * 
 * // Update source parameters
 * criAtomEx3dSource_Update(source);
 * \endcode
 * \attention
 * �{�֐���AtomEx�v���[���[�̃p�����[�^�[�X�V�i::criAtomExPlayer_UpdateAll, criAtomExPlayer_Update�j
 * �Ƃ͓Ɨ����ē��삵�܂��B3D�����̃p�����[�^�[��ύX�����ۂ́A�{�֐��ɂčX�V�������s���Ă��������B
 */
void CRIAPI criAtomEx3dSource_Update(CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����p�����[�^�[�̏�����
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \par ����:
 * 3D�����ɐݒ肳��Ă���p�����[�^�[���N���A���A�����l�ɖ߂��܂��B<br>
 * \attention
 * �N���A�����p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_ResetParameters(CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����̈ʒu�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	position			�ʒu�x�N�g��
 * \par ����:
 * 3D�����̈ʒu��ݒ肵�܂��B<br>
 * �ʒu�́A���������A����ђ�ʌv�Z�Ɏg�p����܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏw�肵�܂��B<br>
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * �f�[�^���ɂ͈ʒu�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetPosition(CriAtomEx3dSourceHn ex_3d_source, const CriAtomExVector *position);

/*JP
 * \brief 3D�����̈ʒu�̎擾
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \par ����:
 * 3D�����̈ʒu���擾���܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏ擾���܂��B<br>
 */
CriAtomExVector CRIAPI criAtomEx3dSource_GetPosition(CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����̑��x�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	velocity			���x�x�N�g��
 * \par ����:
 * 3D�����̑��x��ݒ肵�܂��B<br>
 * ���x�́A�h�b�v���[���ʂ̌v�Z�Ɏg�p����܂��B<br>
 * ���x�́A3�����x�N�g���Ŏw�肵�܂��B���x�̒P�ʂ́A1�b������̈ړ������ł��B
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * �f�[�^���ɂ͑��x�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetVelocity(CriAtomEx3dSourceHn ex_3d_source, const CriAtomExVector *velocity);

/*JP
 * \brief 3D�����̌����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	front				�O���x�N�g��
 * \param[in]	top					����x�N�g��			
 * \par ����:
 * 3D�����̌�����ݒ肵�܂��B<br>
 * �{�֐��Őݒ肵�������́A�T�E���h�R�[���̌����Ƃ��Đݒ肳��܂��B<br>
 * �T�E���h�R�[���́A�������特���������������\���A���̎w�����̕\���Ɏg�p����܂��B<br>
 * �T�E���h�R�[���̌����́A3�����x�N�g���Ŏw�肵�܂��B�ݒ肳�ꂽ�����x�N�g���́A���C�u���������Ő��K�����Ďg�p����܂��B<br>
 * �f�[�^���ɂ̓T�E���h�R�[���̌����͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * �f�t�H���g�l�ȉ��̂Ƃ���ł��B<br>
 * 	- �O���x�N�g���F(0.0f, 0.0f, 1.0f)
 * 	- ����x�N�g���F(0.0f, 1.0f, 0.0f)
 * 	
 * \par ���l:
 * �T�E���h�R�[���̌�����ݒ肵���ꍇ�A����x�N�g���͖�������A�O���x�N�g���݂̂��g�p����܂��B<br>
 * �܂��AAmbisonics�Đ����g�p���Ă���ꍇ�A�{�֐��Ŏw�肵����������у��X�i�[�̌����ɏ]����Ambisonics����]���܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �܂��AAmbiosnics�ɑ΂��ăT�E���h�R�[����K�p���邱�Ƃ͏o���܂���B
 * \sa criAtomEx3dSource_SetConeParameter, criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetOrientation(CriAtomEx3dSourceHn ex_3d_source, const CriAtomExVector *front, const CriAtomExVector *top);

/*JP
 * \brief 3D�����̃T�E���h�R�[���p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	inside_angle		�T�E���h�R�[���̃C���T�C�h�A���O��
 * \param[in]	outside_angle		�T�E���h�R�[���̃A�E�g�T�C�h�A���O��
 * \param[in]	outside_volume		�T�E���h�R�[���̃A�E�g�T�C�h�{�����[��
 * \par ����:
 * 3D�����̃T�E���h�R�[���p�����[�^�[��ݒ肵�܂��B<br>
 * �T�E���h�R�[���́A�������特���������������\���A���̎w�����̕\���Ɏg�p����܂��B<br>
 * �T�E���h�R�[���́A�����R�[���A�O���R�[���ō\������܂��B�C���T�C�h�A���O���͓����R�[���̊p�x�A
 * �A�E�g�T�C�h�A���O���͊O���R�[���̊p�x�A�A�E�g�T�C�h�{�����[���͊O���R�[���̊p�x�ȏ�̕����ł̉��ʂ����ꂼ��\���܂��B<br>
 * �����R�[���̊p�x��菬�����p�x�̕����ł́A�R�[���ɂ�錸�����󂯂܂���B
 * �����R�[���ƊO���R�[���̊Ԃ̕����ł́A���X�ɃA�E�g�T�C�h�{�����[���܂Ō������܂��B<br>
 * �C���T�C�h�A���O������уA�E�g�T�C�h�A���O���́A0.0f�`360.0f��x�Ŏw�肵�܂��B<br>
 * �A�E�g�T�C�h�{�����[���́A0.0f�`1.0f��U���ɑ΂���{���Ŏw�肵�܂��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł���A�R�[���ɂ�錸���͍s���܂���B<br>
 * 	- �C���T�C�h�A���O���F360.0f
 * 	- �A�E�g�T�C�h�A���O���F360.0f
 * 	- �A�E�g�T�C�h�{�����[���F0.0f
 * 	
 * �f�t�H���g�l�́A::criAtomEx3dSource_ChangeDefaultConeParameter �֐��ɂĕύX�\�ł��B<br>
 * �f�[�^���ɓ��Y�p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA�ȉ��̂悤�ɓK�p����܂��B
 * 	- �C���T�C�h�A���O���F���Z
 * 	- �A�E�g�T�C�h�A���O���F���Z
 * 	- �A�E�g�T�C�h�{�����[���F��Z
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultConeParameter
 */
void CRIAPI criAtomEx3dSource_SetConeParameter(CriAtomEx3dSourceHn ex_3d_source,
	CriFloat32 inside_angle,
	CriFloat32 outside_angle,
	CriFloat32 outside_volume
);

/*JP
 * \brief 3D�����̃T�E���h�R�[���p�����[�^�[�̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	inside_angle		�T�E���h�R�[���̃C���T�C�h�A���O��
 * \param[in]	outside_angle		�T�E���h�R�[���̃A�E�g�T�C�h�A���O��
 * \param[in]	outside_volume		�T�E���h�R�[���̃A�E�g�T�C�h�{�����[��
 * \par ����:
 * 3D�����̃T�E���h�R�[���p�����[�^�[�̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �T�E���h�R�[���p�����[�^�[�̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�ɂ��ẮA ::criAtomEx3dSource_SetConeParameter �֐����Q�Ƃ��ĉ������B<br>
 * \attention
 * ���Y�p�����[�^�[�Ɋւ��āu�c�[�����Œl���ύX����Ă��Ȃ��i�f�t�H���g��ԁj�v�f�[�^�̏ꍇ�A�ÖٓI�Ƀf�t�H���g�l���K�p����܂��B<br>
 * ���̂��߁A�{�֐��Ńf�t�H���g�l��ύX����ƁA�c�[���ł̕ҏW���ɈӐ}���Ă����p�����[�^�[�ƈقȂ��Ă��܂��\��������܂��B<br>
 * �A���A�C���Q�[���v���r���[�p�Ƀr���h���ꂽ�f�[�^�͖{�֐��̉e�����󂯂܂���B
 * \sa criAtomEx3dSource_SetConeParameter
 */
void CRIAPI criAtomEx3dSource_ChangeDefaultConeParameter(
	CriFloat32 inside_angle,
	CriFloat32 outside_angle,
	CriFloat32 outside_volume
);

/*JP
 * \brief 3D�����̍ŏ������^�ő勗���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	min_attenuation_distance		�ŏ�����
 * \param[in]	max_attenuation_distance		�ő勗��
 * \par ����:
 * 3D�����̍ŏ������^�ő勗����ݒ肵�܂��B<br>
 * �ŏ������́A����ȏ㉹�ʂ��傫���Ȃ�Ȃ�������\���܂��B�ő勗���́A�ŏ����ʂɂȂ鋗����\���܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- �ŏ������F0.0f
 * 	- �ő勗���F0.0f
 * 	
 * �f�t�H���g�l�́A::criAtomEx3dSource_ChangeDefaultMinMaxAttenuationDistance �֐��ɂĕύX�\�ł��B<br>
 * �f�[�^���ɓ��Y�p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA�f�[�^���̒l���㏑���i�����j���ēK�p����܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultMinMaxAttenuationDistance
 */
void CRIAPI criAtomEx3dSource_SetMinMaxAttenuationDistance(CriAtomEx3dSourceHn ex_3d_source,
	CriFloat32 min_attenuation_distance,
	CriFloat32 max_attenuation_distance
);

/*JP
 * \brief 3D�����̍ŏ������^�ő勗���̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	min_attenuation_distance		�ŏ�����
 * \param[in]	max_attenuation_distance		�ő勗��
 * \par ����:
 * 3D�����̍ŏ������^�ő勗���̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �ŏ������^�ő勗���̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�ɂ��ẮA ::criAtomEx3dSource_SetMinMaxAttenuationDistance �֐����Q�Ƃ��ĉ������B<br
 * \attention
 * ���Y�p�����[�^�[�Ɋւ��āu�c�[�����Œl���ύX����Ă��Ȃ��i�f�t�H���g��ԁj�v�f�[�^�̏ꍇ�A�ÖٓI�Ƀf�t�H���g�l���K�p����܂��B<br>
 * ���̂��߁A�{�֐��Ńf�t�H���g�l��ύX����ƁA�c�[���ł̕ҏW���ɈӐ}���Ă����p�����[�^�[�ƈقȂ��Ă��܂��\��������܂��B<br>
 * �A���A�ȉ��ɊY������f�[�^�͖{�֐��̉e�����󂯂܂���B<br>
 * 	- �c�[���̃v���p�e�B�ɂāA�ŏ������^�ő勗���̏����l�ݒ��0.0�ȊO�ɐݒ肵�Ă���
 * 	- �C���Q�[���v���r���[�p�Ƀr���h���Ă���
 * 	
 * \sa criAtomEx3dSource_SetMinMaxAttenuationDistance
 */
void CRIAPI criAtomEx3dSource_ChangeDefaultMinMaxAttenuationDistance(
	CriFloat32 min_attenuation_distance,
	CriFloat32 max_attenuation_distance
);

/*JP
 * \brief 3D�����̃C���e���A�p���j���O���E�����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	source_radius		3D�����̔��a
 * \param[in]	interior_distance	�C���e���A����
 * \par ����:
 * 3D�����̃C���e���A�p���j���O���E�����̐ݒ�����܂��B<br>
 * 3D�����̔��a�́A3D���������Ƃ����Ƃ��̔��a�ł��B<br>
 * �C���e���A�����́A�C���e���A�p���j���O�K�p�����3D�����̔��a����̋����ł��B<br>
 * 3D�����̔��a���ł́A�C���e���A�p���j���O�K�p����܂����A�C���e���A������0.0�ƈ����邽�߁A
 * �S�ẴX�s�[�J�[���瓯�����ʂŉ������Đ�����܂��B<br>
 * �C���e���A�������ł́A�C���e���A�p���j���O�K�p����܂��B<br>
 * �C���e���A�����O�ł́A�C���e���A�p���j���O�K�p���ꂸ�A�����ʒu�ɍł��߂�1�A
 * �܂���2�̃X�s�[�J�[���特�����Đ�����܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- 3D�����̔��a�F0.0f
 * 	- �C���e���A�����F0.0f�i3D�����̍ŏ������Ɉˑ��j
 * 	
 * �f�t�H���g�l�́A ::criAtomEx3dSource_ChangeDefaultInteriorPanField �֐��ɂĕύX�\�ł��B<br>
 * �܂��A���݃c�[���ɂē��Y�p�����[�^�[��ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultInteriorPanField
 */
void CRIAPI criAtomEx3dSource_SetInteriorPanField(CriAtomEx3dSourceHn ex_3d_source, CriFloat32 source_radius, CriFloat32 interior_distance);

/*JP
 * \brief 3D�����̃C���e���A�p���j���O���E�����̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	source_radius		3D�����̔��a
 * \param[in]	interior_distance	�C���e���A����
 * \par ����:
 * 3D�����̃C���e���A�p���j���O���E�����̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �C���e���A�p���j���O���E�����̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�ɂ��ẮA ::criAtomEx3dSource_SetInteriorPanField �֐����Q�Ƃ��ĉ������B<br>
 * \sa criAtomEx3dSource_SetInteriorPanField
 */
void CRIAPI criAtomEx3dSource_ChangeDefaultInteriorPanField(CriFloat32 source_radius, CriFloat32 interior_distance);

/*JP
 * \brief 3D�����̃h�b�v���[�W���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	doppler_factor		�h�b�v���[�W��
 * \par ����:
 * 3D�����̃h�b�v���[�W����ݒ肵�܂��B<br>
 * �h�b�v���[�W���́A������340m/s�Ƃ��Čv�Z���ꂽ�h�b�v���[���ʂɑ΂��āA�֒��\�����邽�߂̔{�����w�肵�܂��B<br>
 * �Ⴆ�΁A2.0f���w�肷��ƁA������340m/s�Ƃ��Čv�Z�����s�b�`��2�{���ēK�p���܂��B<br>
 * 0.0f���w�肷��ƁA�h�b�v���[���ʂ͖����ɂȂ�܂��B
 * ���C�u�������������̃f�t�H���g�l��0.0f�ł��B<br>
 * �f�t�H���g�l�́A::criAtomEx3dSource_ChangeDefaultDopplerFactor �֐��ɂĕύX�\�ł��B<br>
 * �f�[�^���ɓ��Y�p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA�f�[�^���̒l���㏑���i�����j���ēK�p����܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultDopplerFactor
 */
void CRIAPI criAtomEx3dSource_SetDopplerFactor(CriAtomEx3dSourceHn ex_3d_source, CriFloat32 doppler_factor);

/*JP
 * \brief 3D�����̃h�b�v���[�W���̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	doppler_factor		�h�b�v���[�W��
 * \par ����:
 * 3D�����̃h�b�v���[�W���̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �h�b�v���[�W���̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�ɂ��ẮA ::criAtomEx3dSource_SetDopplerFactor �֐����Q�Ƃ��ĉ������B<br>
 * \attention
 * ���Y�p�����[�^�[�Ɋւ��āu�c�[�����Œl���ύX����Ă��Ȃ��i�f�t�H���g��ԁj�v�f�[�^�̏ꍇ�A�ÖٓI�Ƀf�t�H���g�l���K�p����܂��B<br>
 * ���̂��߁A�{�֐��Ńf�t�H���g�l��ύX����ƁA�c�[���ł̕ҏW���ɈӐ}���Ă����p�����[�^�[�ƈقȂ��Ă��܂��\��������܂��B<br>
 * �A���A�C���Q�[���v���r���[�p�Ƀr���h���ꂽ�f�[�^�͖{�֐��̉e�����󂯂܂���B
 * \sa criAtomEx3dSource_SetDopplerFactor
 */
void CRIAPI criAtomEx3dSource_ChangeDefaultDopplerFactor(CriFloat32 doppler_factor);

/*JP
 * \brief 3D�����̃{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	volume				�{�����[��
 * \par ����:
 * 3D�����̃{�����[����ݒ肵�܂��B<br>
 * 3D�����̃{�����[���́A��ʂɊւ�鉹�ʁiL,R,SL,SR�j�ɂ̂݉e�����ALFE��Z���^�[�ւ̏o�̓��x���ɂ͉e�����܂���B<br>
 * �{�����[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * ���C�u�������������̃f�t�H���g�l��1.0f�ł��B<br>
 * �f�t�H���g�l�́A::criAtomEx3dSource_ChangeDefaultVolume �֐��ɂĕύX�\�ł��B<br>
 * �f�[�^���ɓ��Y�p�����[�^�[���ݒ肳��Ă���ꍇ�ɖ{�֐����Ăяo���ƁA�f�[�^���̒l�Ə�Z���ēK�p����܂��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dSource_Update, criAtomEx3dSource_ChangeDefaultVolume
 */
void CRIAPI criAtomEx3dSource_SetVolume(CriAtomEx3dSourceHn ex_3d_source, CriFloat32 volume);

/*JP
 * \brief 3D�����̃{�����[���̃f�t�H���g�l�ύX
 * \ingroup ATOMEXLIB_3D
 * \param[in]	volume				�{�����[��
 * \par ����:
 * 3D�����̃{�����[���̃f�t�H���g�l��ύX���܂��B<br>
 * �{�֐��ɂ���ăf�t�H���g�l��ύX����ƁA�ȍ~�ɍ쐬����3D�����n���h���i ::CriAtomEx3dSourceHn �j��
 * �{�����[���̏����l���{�֐��Őݒ肵���l�ƂȂ�܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�ɂ��ẮA ::criAtomEx3dSource_SetVolume �֐����Q�Ƃ��ĉ������B<br>
 * \attention
 * ���Y�p�����[�^�[�Ɋւ��āu�c�[�����Œl���ύX����Ă��Ȃ��i�f�t�H���g��ԁj�v�f�[�^�̏ꍇ�A�ÖٓI�Ƀf�t�H���g�l���K�p����܂��B<br>
 * ���̂��߁A�{�֐��Ńf�t�H���g�l��ύX����ƁA�c�[���ł̕ҏW���ɈӐ}���Ă����p�����[�^�[�ƈقȂ��Ă��܂��\��������܂��B<br>
 * �A���A�C���Q�[���v���r���[�p�Ƀr���h���ꂽ�f�[�^�͖{�֐��̉e�����󂯂܂���B
 * \sa criAtomEx3dSource_SetVolume
 */
void CRIAPI criAtomEx3dSource_ChangeDefaultVolume(CriFloat32 volume);

/*JP
 * \brief �p�xAISAC�R���g���[���l�̍ő�ω��ʂ̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	max_delta			�p�xAISAC�R���g���[���l�̍ő�ω���
 * \par ����:
 * �p�xAISAC�ɂ��AISAC�R���g���[���l���ύX�����ۂ́A�ő�ω��ʂ�ݒ肵�܂��B<br>
 * �ő�ω��ʂ��߂ɕύX����ƁA�����ƃ��X�i�[�Ԃ̑��Ίp�x���}���ɕς�����ꍇ�ł��A
 * �p�xAISAC�ɂ��AISAC�R���g���[���l�̕ω����X���[�Y�ɂ��邱�Ƃ��ł��܂��B<br>
 * �Ⴆ�΁A(0.5f / 30.0f)��ݒ肷��ƁA�p�x��0�x��180�x�ɕω������ꍇ�ɁA30�t���[�������ĕω�����悤�ȕω��ʂƂȂ�܂��B<br>
 * �f�t�H���g�l��1.0f�i�����Ȃ��j�ł��B
 * �f�[�^���ł͖{�p�����[�^�[�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐��Őݒ肵�Ă���ő�ω��ʂ́A��ʊp�x�����Ɍv�Z����Ă���A�p�xAISAC�R���g���[���l�̕ω��ɂ̂ݓK�p����܂��B
 * ��ʊp�x���̂ɂ͉e���͂���܂���B
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetMaxAngleAisacDelta(CriAtomEx3dSourceHn ex_3d_source, CriFloat32 max_delta);

/*JP
 * \brief ����AISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	aisac_control_id	����AISAC�R���g���[��ID
 * \par ����:
 * �ŏ������A�ő勗���Ԃ̋��������ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �{�֐���AISAC�R���g���[��ID��ݒ肵���ꍇ�A�f�t�H���g�̋��������͖����ɂȂ�܂��B<br>
 * �f�[�^���ɐݒ肳��Ă��鋗��AISAC�R���g���[��ID�́A�{�֐��ɂ���ď㏑���K�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐������s����Ǝw�肵��3D�����ɑO�ɐݒ肳��Ă���AISAC�R���g�[��ID�̒l�̕ύX�ɂ��p�����[�^�[�ύX�͖���������܂����A<br>
 * �Đ��ς݂̉����ɂ��Ă͑O�ɓK�p���ꂽ�p�����[�^�[���K�p���ꑱ���܂��B<br>
 * �w�肷��3D�����ɕR�Â��������Đ�����Ă��Ȃ���ԂŖ{�֐������s���邱�Ƃ𐄏����܂��B<br>
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetDistanceAisacControlId(CriAtomEx3dSourceHn ex_3d_source, CriUint16 aisac_control_id);

/*JP
 * \brief ���X�i�[����ʊpAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	aisac_control_id	���X�i�[����ʊpAISAC�R���g���[��ID
 * \par ����:
 * ���X�i�[���猩�������̕��ʊp�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �f�[�^���ɐݒ肳��Ă��郊�X�i�[����ʊpAISAC�R���g���[��ID�́A�{�֐��ɂ���ď㏑���K�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐������s����Ǝw�肵��3D�����ɑO�ɐݒ肳��Ă���AISAC�R���g�[��ID�̒l�̕ύX�ɂ��p�����[�^�[�ύX�͖���������܂����A<br>
 * �Đ��ς݂̉����ɂ��Ă͑O�ɓK�p���ꂽ�p�����[�^�[���K�p���ꑱ���܂��B<br>
 * �w�肷��3D�����ɕR�Â��������Đ�����Ă��Ȃ���ԂŖ{�֐������s���邱�Ƃ𐄏����܂��B<br>
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetListenerBasedAzimuthAngleAisacControlId(CriAtomEx3dSourceHn ex_3d_source, CriUint16 aisac_control_id);

/*JP
 * \brief ���X�i�[���pAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	aisac_control_id	���X�i�[���pAISAC�R���g���[��ID
 * \par ����:
 * ���X�i�[���猩�������̋�p�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �f�[�^���ɐݒ肳��Ă��郊�X�i�[���pAISAC�R���g���[��ID�́A�{�֐��ɂ���ď㏑���K�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐������s����Ǝw�肵��3D�����ɑO�ɐݒ肳��Ă���AISAC�R���g�[��ID�̒l�̕ύX�ɂ��p�����[�^�[�ύX�͖���������܂����A<br>
 * �Đ��ς݂̉����ɂ��Ă͑O�ɓK�p���ꂽ�p�����[�^�[���K�p���ꑱ���܂��B<br>
 * �w�肷��3D�����ɕR�Â��������Đ�����Ă��Ȃ���ԂŖ{�֐������s���邱�Ƃ𐄏����܂��B<br>
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetListenerBasedElevationAngleAisacControlId(CriAtomEx3dSourceHn ex_3d_source, CriUint16 aisac_control_id);

/*JP
 * \brief ��������ʊpAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	aisac_control_id	��������ʊpAISAC�R���g���[��ID
 * \par ����:
 * �������猩�����X�i�[�̕��ʊp�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �f�[�^���ɐݒ肳��Ă��鉹������ʊpAISAC�R���g���[��ID�́A�{�֐��ɂ���ď㏑���K�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐������s����Ǝw�肵��3D�����ɑO�ɐݒ肳��Ă���AISAC�R���g�[��ID�̒l�̕ύX�ɂ��p�����[�^�[�ύX�͖���������܂����A<br>
 * �Đ��ς݂̉����ɂ��Ă͑O�ɓK�p���ꂽ�p�����[�^�[���K�p���ꑱ���܂��B<br>
 * �w�肷��3D�����ɕR�Â��������Đ�����Ă��Ȃ���ԂŖ{�֐������s���邱�Ƃ𐄏����܂��B<br>
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetSourceBasedAzimuthAngleAisacControlId(CriAtomEx3dSourceHn ex_3d_source, CriUint16 aisac_control_id);

/*JP
 * \brief �������pAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source		3D�����n���h��
 * \param[in]	aisac_control_id	�������pAISAC�R���g���[��ID
 * \par ����:
 * �������猩�����X�i�[�̋�p�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �f�[�^���ɐݒ肳��Ă��鉹�����pAISAC�R���g���[��ID�́A�{�֐��ɂ���ď㏑���K�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐������s����Ǝw�肵��3D�����ɑO�ɐݒ肳��Ă���AISAC�R���g�[��ID�̒l�̕ύX�ɂ��p�����[�^�[�ύX�͖���������܂����A<br>
 * �Đ��ς݂̉����ɂ��Ă͑O�ɓK�p���ꂽ�p�����[�^�[���K�p���ꑱ���܂��B<br>
 * �w�肷��3D�����ɕR�Â��������Đ�����Ă��Ȃ���ԂŖ{�֐������s���邱�Ƃ𐄏����܂��B<br>
 * \sa criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_SetSourceBasedElevationAngleAisacControlId(CriAtomEx3dSourceHn ex_3d_source, CriUint16 aisac_control_id);

/*JP
 * \brief 3D�����n���h���ɑ΂���3D���[�W�����n���h���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�����n���h���ɑ΂���3D���[�W�����n���h����ݒ肵�܂��B
 *
 * \attention
 * �����ExPlayer�ɐݒ肳��Ă���3D������3D���X�i�[�ɐݒ肳��Ă��郊�[�W�������قȂ�A
 * ����3D�����Ɠ������[�W�������ݒ肳��Ă���3D�g�����V�[�o�[���Ȃ��ꍇ�A�����̓~���[�g����܂��B<br>
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B
 * <br>
 * \sa criAtomEx3dRegion_Create, criAtomEx3dSource_Update
 */
void CRIAPI criAtomEx3dSource_Set3dRegionHn(CriAtomEx3dSourceHn ex_3d_source, CriAtomEx3dRegionHn ex_3d_region);

/*JP
 * \brief 3D�����ɑ΂���ʒu�̃����_�����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source	3D�����n���h��
 * \param[in]	config			3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\���̂̃|�C���^
 * \par ����:
 * 3D�����n���h���ɑ΂��Ĉʒu�̃����_�����̐ݒ�����܂��B
 * �{�֐������s����ƁA�Đ����ɉ����̈ʒu�����̈ʒu��񂨂�ѐݒ�l�ɏ]����
 * �����_���ɕω����܂��B
 * \par ���l:
 * ��2���� config �ɑ΂��� NULL ���w�肷��ƁA�ݒ���������邱�Ƃ��\�ł��B
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * <br>
 * �{�֐��͍Đ����̉����ɑ΂��ăp�����[�^�[�͓K�p����܂���B<br>
 * ����Đ��̉�������K�p����܂��B
 * \sa CriAtomEx3dSourceRandomPositionConfig
 */
void CRIAPI criAtomEx3dSource_SetRandomPositionConfig(
	CriAtomEx3dSourceHn ex_3d_source, const CriAtomEx3dSourceRandomPositionConfig *config);

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�Z�o�R�[���o�b�N�֐��̓o�^
 * \param[in]	ex_3d_source	3D�����n���h��
 * \param[in]	func			3D�����̃����_�����ɂ�����ʒu���W�Z�o�R�[���o�b�N�֐�
 * \param[in]	obj				���[�U�[�w��I�u�W�F�N�g
 * \par ����:
 * 3D�����ɑ΂��āA3D�����̈ʒu�̃����_�����ɂ�����ʒu���W�Z�o�R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A3D�����̈ʒu�̃����_�������L���ȏꍇ�A
 * ���W�Z�o���s���^�C�~���O�Ŏ��s����܂��B
 * \par ���l:
 * 3D�����̈ʒu�̃����_�����Ɋւ���R���t�B�O�\���̂ł���
 * ::CriAtomEx3dSourceRandomPositionConfig �̕ϐ� calculation_type �ɑ΂���
 * ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_CALLBACK
 * ��ݒ肵�Ă���ꍇ�̂݁A���W�Z�o���Ɏw�肵���R�[���o�b�N�֐������s���܂��B
 * \attention
 * �R�[���o�b�N�o�^�̓K�p�ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * <br>
 * �T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐��͊e3D�����̃n���h���ɂ��A1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B
 * \sa CriAtomEx3dSourceRandomPositionCalculationCbFunc, CriAtomEx3dSourceRandomPositionConfig
 */
void CRIAPI criAtomEx3dSource_SetRandomPositionCalculationCallback(
	CriAtomEx3dSourceHn ex_3d_source, CriAtomEx3dSourceRandomPositionCalculationCbFunc func, void *obj);

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���X�g�̐ݒ�
 * \param[in]	ex_3d_source	3D�����n���h��
 * \param[in]	position_list	�ʒu���W���X�g
 * \param[in]	length			���X�g�̗v�f��
 * \par ����:
 * �ʒu���W���X�g�̔z����w�肵�܂��B<br>
 * 3D�����̈ʒu�̃����_�������L���̏ꍇ�A�w�肵���z��̍��W���烉���_���ɍ��W�����肳��܂��B
 * \par ���l:
 * �ʒu���W�̎Z�o���@�Ƃ��� ::CRIATOMEX3DSOURCE_RANDOM_POSITION_CALCULATION_TYPE_LIST
 * ��ݒ肵�Ă���ꍇ�̂݁A�{�p�����[�^�[���Q�Ƃ��܂��B<br>
 * ���̑��̎Z�o���@��ݒ肵�Ă���ꍇ�A�{�p�����[�^�[�͖�������܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * <br>
 * �{�֐��ɐݒ肵���̈�́A ::criAtomEx3dSource_SetRandomPositionList �֐�
 * �̎��s������́A��������͎Q�Ƃ���܂���B<br>
 * ����ɓ����Ŋm�ۂ����ʒu���W���X�g�ɕۑ����܂��B<br>
 * ���̂��߁A ::CriAtomEx3dSourceConfig::random_position_list_max_length ��
 * ������l��ݒ肷��ƃG���[���������܂��B
 * \sa CriAtomEx3dSourceRandomPositionConfig, CriAtomEx3dSourceConfig
 */
void CRIAPI criAtomEx3dSource_SetRandomPositionList(
	CriAtomEx3dSourceHn ex_3d_source, const CriAtomExVector *position_list, CriUint32 length);

/*JP
 * \brief 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���ʃR�[���o�b�N�֐��̓o�^
 * \param[in]	ex_3d_source	3D�����n���h��
 * \param[in]	func			3D�����̃����_�����ɂ�����ʒu���W���ʃR�[���o�b�N�֐�
 * \param[in]	obj				���[�U�[�w��I�u�W�F�N�g
 * \par ����:
 * 3D�����̈ʒu�̃����_�����ɂ�����ʒu���W���ʃR�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A3D�����̈ʒu�̃����_�������L���ȏꍇ�A
 * ���W�Z�o���s��ꂽ��̃^�C�~���O�Ŏ��s����܂��B
 * \par ���l:
 * �Ǐ]�ݒ肪�L���̏ꍇ�A���̃\�[�X�̈ړ��ɉ����Ė{�R�[���o�b�N�֐������s����܂��B
 * \attention
 * �R�[���o�b�N�o�^�̓K�p�ɂ́A::criAtomEx3dSource_Update �֐����Ăяo���K�v������܂��B<br>
 * <br>
 * �T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������܂��B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B
 * \sa CriAtomEx3dSourceRandomPositionResultCbFunc
 */
void CRIAPI criAtomEx3dSource_SetRandomPositionResultCallback(
	CriAtomEx3dSourceHn ex_3d_source, CriAtomEx3dSourceRandomPositionResultCbFunc func, void *obj);

/*JP
 * \brief 3D�����n���h�����X�g�̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config		3D�����n���h�����X�g�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	3D�����n���h�����X�g�쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * 3D�����n���h�����X�g���쐬���邽�߂ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������3D�����n���h�����X�g���쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomEx3dSourceList_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * 3D�����n���h�����X�g�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A3D�����n���h�����X�g���X�g�쐬�p�R���t�B�O
 * �\���́i ::CriAtomEx3dSourceListConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx3dSourceList_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx3dSourceList_Create, CriAtomEx3dSourceListConfig
 */
CriSint32 CRIAPI criAtomEx3dSourceList_CalculateWorkSize(const CriAtomEx3dSourceListConfig *config);

/*JP
 * \brief 3D�����n���h�����X�g�̍쐬
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config					3D�����n���h�����X�g�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work					3D�����n���h�����X�g�쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size				3D�����n���h�����X�g�쐬�p���[�N�T�C�Y
 * \return		CriAtomEx3dSourceListHn	3D�����n���h�����X�g
 * \par ����:
 * 3D�����n���h�����X�g�쐬�p�R���t�B�O�Ɋ�Â��āA3D�����n���h�����X�g���쐬���܂��B<br>
 * �쐬�ɐ�������ƁA3D�����n���h�����X�g��Ԃ��܂��B<br>
 * 3D�����n���h�����X�g���쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomEx3dSourceList_CalculateWorkSize 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomEx3dSourceList_CalculateWorkSize, criAtomEx3dSourceList_Destroy
 */
CriAtomEx3dSourceListHn CRIAPI criAtomEx3dSourceList_Create(
	const CriAtomEx3dSourceListConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief 3D�����n���h�����X�g�̔j��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source_list		3D�����n���h�����X�g
 * \par ����:
 * 3D�����n���h�����X�g��j�����܂��B<br>
 * �{�֐������s�������_�ŁA3D�����n���h�����X�g�쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��3D�����n���h�����X�g�������ɂȂ�܂��B<br>
 * 3D�����n���h�����X�g���Z�b�g����AtomEx�v���[���[�ōĐ����Ă��鉹��������ꍇ�A
 * �{�֐������s����O�ɁA�����̉������~���邩�A����AtomEx�v���[���[��j�����Ă��������B
 * \par ���l:
 * 3D�����n���h�����X�g��3D�����n���h�����ǉ�����Ă����ԂŖ{�֐������s�����ꍇ�A
 * �ǉ�����Ă���3D�����n���h���͎����I��3D�����n���h�����X�g����폜����܂��B
 * \sa criAtomEx3dSourceList_Create
 */
void CRIAPI criAtomEx3dSourceList_Destroy(CriAtomEx3dSourceListHn ex_3d_source_list);

/*JP
 * \brief 3D�����n���h�����X�g�ւ�3D�����n���h���̒ǉ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source_list		3D�����n���h�����X�g
 * \param[in]	ex_3d_source			3D�����n���h��
 * \par ����:
 * 3D�����n���h�����X�g��3D�����n���h����ǉ����܂��B<br>
 * �ǉ�����AtomEx�v���[���[��3D�����n���h�����X�g�Ɗ֘A�t�����A
 * �}���`�|�W�V���j���O�Đ����\�ƂȂ�܂��B<br>
 * �ǉ�����3D�����n���h����3D�����n���h�����X�g����폜����ꍇ�́A ::criAtomEx3dSourceList_Remove �֐��܂���
 * ::criAtomEx3dSourceList_RemoveAll �֐����Ăяo���Ă��������B<br>
 * \par ���l:
 * �ȉ��̏����ɓ��Ă͂܂�3D�����n���h����3D�����n���h�����X�g�ɒǉ����邱�Ƃ͂ł��܂���B<br>
 * - ����AtomEx�v���[���[�ɐݒ肳��Ă���
 * - ���ɑ���3D�����n���h�����X�g�ɒǉ�����Ă���
 * <br>
 * �{�֐��͍Đ�����AtomEx�v���[���[�Ɏ��t�����Ă���3D�����n���h�����X�g�ɑ΂��Ă��g�p�\�ł��B<br>
 * \attention ����:
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx3dSourceList_Remove, criAtomEx3dSourceList_RemoveAll
 */
void CRIAPI criAtomEx3dSourceList_Add(
	CriAtomEx3dSourceListHn ex_3d_source_list, CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����n���h�����X�g����3D�����n���h���̍폜
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source_list		3D�����n���h�����X�g
 * \param[in]	ex_3d_source			3D�����n���h��
 * \par ����:
 * 3D�����n���h�����X�g����ǉ�����Ă���3D�����n���h���̓��A�w�肵��3D�����n���h�����폜���܂��B<br>
 * 3D�����n���h�����X�g����S�Ă�3D�����n���h�����폜�������ꍇ�́A ::criAtomEx3dSourceList_Remove �֐���
 * �Ăяo���Ă��������B<br>
 * 3D�����n���h�����X�g��3D�����n���h����ǉ��������ꍇ�́A ::criAtomEx3dSourceList_Add �֐����Ăяo���Ă��������B 
 * \par ���l:
 * �{�֐��͍Đ�����AtomEx�v���[���[�Ɏ��t�����Ă���3D�����n���h�����X�g�ɑ΂��Ă��g�p�\�ł��B<br>
 * \attention ����:
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx3dSourceList_RemoveAll
 */
void CRIAPI criAtomEx3dSourceList_Remove(
	CriAtomEx3dSourceListHn ex_3d_source_list, CriAtomEx3dSourceHn ex_3d_source);

/*JP
 * \brief 3D�����n���h�����X�g����3D�����n���h���̑S�폜
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_source_list		3D�����n���h�����X�g
 * \par ����:
 * 3D�����n���h�����X�g����ǉ�����Ă���S�Ă�3D�����n���h�����폜���܂��B<br>
 * 3D�����n���h�����X�g��������3D�����n���h�����폜�������ꍇ�́A ::criAtomEx3dSourceList_Remove �֐���
 * �Ăяo���Ă��������B<br>
 * 3D�����n���h�����X�g��3D�����n���h����ǉ��������ꍇ�́A ::criAtomEx3dSourceList_Add �֐����Ăяo���Ă��������B 
 * \par ���l:
 * �{�֐��͍Đ�����AtomEx�v���[���[�Ɏ��t�����Ă���3D�����n���h�����X�g�ɑ΂��Ă��g�p�\�ł��B<br>
 * \attention ����:
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx3dSourceList_Remove
 */
void CRIAPI criAtomEx3dSourceList_RemoveAll(CriAtomEx3dSourceListHn ex_3d_source_list);

/*JP
 * \brief 3D���X�i�[�n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config		3D���X�i�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	3D���X�i�[�n���h���쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * 3D���X�i�[�n���h�����쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������3D���X�i�[�n���h�����쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomEx3dListener_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * 3D���X�i�[�n���h���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A3D���X�i�[�n���h���쐬�p�R���t�B�O
 * �\���́i ::CriAtomEx3dListenerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx3dListener_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx3dListener_Create, CriAtomEx3dListenerConfig
 */
CriSint32 CRIAPI criAtomEx3dListener_CalculateWorkSize(const CriAtomEx3dListenerConfig *config);

/* 3D���X�i�[�̍쐬 */
/*JP
 * \brief 3D���X�i�[�n���h���̍쐬
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config				3D���X�i�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work				3D���X�i�[�n���h���쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size			3D���X�i�[�n���h���쐬�p���[�N�T�C�Y
 * \return		CriAtomEx3dListenerHn	3D���X�i�[�n���h��
 * \par ����:
 * 3D���X�i�[�n���h���쐬�p�R���t�B�O�Ɋ�Â��āA3D���X�i�[�n���h�����쐬���܂��B<br>
 * �쐬�ɐ�������ƁA3D���X�i�[�n���h����Ԃ��܂��B<br>
 * 3D���X�i�[�n���h�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomEx3dListener_CalculateWorkSize 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomEx3dListener_CalculateWorkSize, criAtomEx3dListener_Destroy
 */
CriAtomEx3dListenerHn CRIAPI criAtomEx3dListener_Create(
	const CriAtomEx3dListenerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief 3D���X�i�[�n���h���̔j��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \par ����:
 * 3D���X�i�[�n���h����j�����܂��B<br>
 * �{�֐������s�������_�ŁA3D���X�i�[�n���h���쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��3D���X�i�[�n���h���������ɂȂ�܂��B<br>
 * 3D���X�i�[�n���h�����Z�b�g����AtomEx�v���[���[�ōĐ����Ă��鉹��������ꍇ�A
 * �{�֐������s����O�ɁA�����̉������~���邩�A����AtomEx�v���[���[��j�����Ă��������B
 * \sa criAtomEx3dListener_Create
 */
void CRIAPI criAtomEx3dListener_Destroy(CriAtomEx3dListenerHn ex_3d_listener);

/*JP
 * \brief 3D���X�i�[�̍X�V
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \par ����:
 * 3D���X�i�[�ɐݒ肳��Ă���p�����[�^�[���g�p���āA3D���X�i�[���X�V���܂��B<br>
 * �{�֐��ł́A3D���X�i�[�ɐݒ肳��Ă���S�Ẵp�����[�^�[���X�V���܂��B
 * �p�����[�^�[���ЂƂύX����x�ɖ{�֐��ɂčX�V�������s�������A
 * �����̃p�����[�^�[��ύX���Ă���X�V�������s�������������I�ł��B
 * \par ��:
 * \code
 * CriAtomExVector pos;
 * CriAtomExVector vel;
 * 
 * // Set position
 * pos.x = 0.0f
 * pos.y = 0.0f
 * pos.z = 1.0f
 * criAtomEx3dListener_SetPosition(source, &pos);
 * // Set velocity
 * vel.x = 1.0f
 * vel.y = 0.0f
 * vel.z = 0.0f
 * criAtomEx3dListener_SetVelocity(source, &vel);
 * 
 * // Update source parameters
 * criAtomEx3dListener_Update(source);
 * \endcode
 * \attention
 * �{�֐���AtomEx�v���[���[�̃p�����[�^�[�X�V�i::criAtomExPlayer_UpdateAll, criAtomExPlayer_Update�j
 * �Ƃ͓Ɨ����ē��삵�܂��B3D���X�i�[�̃p�����[�^�[��ύX�����ۂ́A�{�֐��ɂčX�V�������s���Ă��������B
 */
void CRIAPI criAtomEx3dListener_Update(CriAtomEx3dListenerHn ex_3d_listener);

/*JP
 * \brief 3D�����p�����[�^�[�̏�����
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \par ����:
 * 3D���X�i�[�ɐݒ肳��Ă���p�����[�^�[���N���A���A�����l�ɖ߂��܂��B<br>
 * \attention
 * �N���A�����p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_ResetParameters(CriAtomEx3dListenerHn ex_3d_listener);

/*JP
 * \brief 3D���X�i�[�̈ʒu�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \param[in]	position			�ʒu�x�N�g��
 * \par ����:
 * 3D���X�i�[�̈ʒu��ݒ肵�܂��B<br>
 * �ʒu�́A���������A����ђ�ʌv�Z�Ɏg�p����܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏw�肵�܂��B<br>
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * �f�[�^���ɂ͈ʒu�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_SetPosition(CriAtomEx3dListenerHn ex_3d_listener, const CriAtomExVector *position);

/*JP
 * \brief 3D���X�i�[�̈ʒu�̎擾
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��

 * \par ����:
 * 3D���X�i�[�̈ʒu���擾���܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏ擾���܂��B<br>
 */
CriAtomExVector CRIAPI criAtomEx3dListener_GetPosition(CriAtomEx3dListenerHn ex_3d_listener);

/*JP
 * \brief 3D���X�i�[�̑��x�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \param[in]	velocity			���x�x�N�g��
 * \par ����:
 * 3D���X�i�[�̑��x��ݒ肵�܂��B<br>
 * ���x�́A�h�b�v���[���ʂ̌v�Z�Ɏg�p����܂��B<br>
 * ���x�́A3�����x�N�g���Ŏw�肵�܂��B���x�̒P�ʂ́A1�b������̈ړ������ł��B
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * �f�[�^���ɂ͑��x�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_SetVelocity(CriAtomEx3dListenerHn ex_3d_listener, const CriAtomExVector *velocity);

/*JP
 * \brief 3D���X�i�[�̌����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \param[in]	front				�O���x�N�g��
 * \param[in]	top				����x�N�g��
 * \par ����:
 * 3D���X�i�[�̌�����O���x�N�g���Ə���x�N�g���Őݒ肵�܂��B<br>
 * �����́A3�����x�N�g���Ŏw�肵�܂��B�ݒ肳�ꂽ�����x�N�g���́A���C�u���������Ő��K�����Ďg�p����܂��B<br>
 * �f�t�H���g�l�ȉ��̂Ƃ���ł��B<br>
 * 	- �O���x�N�g���F(0.0f, 0.0f, 1.0f)
 * 	- ����x�N�g���F(0.0f, 1.0f, 0.0f)
 * 	
 * �f�[�^���ɂ̓��X�i�[�̌����͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_SetOrientation(CriAtomEx3dListenerHn ex_3d_listener, const CriAtomExVector *front, const CriAtomExVector *top);

/*JP
 * \brief 3D���X�i�[�̃h�b�v���[�{���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \param[in]	doppler_multiplier	�h�b�v���[�{��
 * \par ����:
 * 3D���X�i�[�̃h�b�v���[�{����ݒ肵�܂��B���̔{���̓h�b�v���[���ʂ̌v�Z�Ɏg�p����܂��B<br>
 * �Ⴆ�΁Adoppler_multiplier��10.0f���w�肷��ƁA�h�b�v���[���ʂ��ʏ��10�{�ɂȂ�܂��B<br>
 * doppler_multiplier�ɂ�0.0f�ȏ�̒l���w�肵�܂��B
 * �f�t�H���g�l��1.0f�ł��B<br>
 * �f�[�^���ɂ̓��X�i�[�̃h�b�v���[�{���͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_SetDopplerMultiplier(CriAtomEx3dListenerHn ex_3d_listener, CriFloat32 doppler_multiplier);

/*JP
 * \brief 3D���X�i�[�̒��ړ_�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener		3D���X�i�[�n���h��
 * \param[in]	focus_point			���ړ_�x�N�g��
 * \par ����:
 * 3D���X�i�[�̒��ړ_��ݒ肵�܂��B<br>
 * ���ړ_�́A3D�|�W�V���j���O���s���ɂ������āA
 * ���ړ_��ݒ肷��ƁA���X�i�[�̈ʒu�ƒ��ړ_�̊Ԃ������Ō��΂�A���̒�����Ń}�C�N���ړ������邱�Ƃ��ł���悤�ɂȂ�܂��B<br>
 * �Ⴆ�΁A���X�i�[�̓J�����Ə�ɓ��������Ă����A��v�L�����N�^�̈ʒu�ɒ��ړ_��ݒ肷�邱�ƂŁA�󋵂ɉ����āA�q�ϓI����ϓI�����_��ɕ\���^��������悤�Ȏg�������ł��܂��B<br>
 * �Ȃ��A���X�i�[�̈ʒu�ƒ��ړ_�̊Ԃňړ��ł���}�C�N�́A�������E�̃}�C�N�ƈقȂ�A�����Z���T�i���������v�Z�p�j�ƕ����Z���T�i��ʌv�Z�p�j�𕪗����Ă��܂��B<br>
 * ������Ɨ����đ��삷�邱�ƂŁA�Ⴆ�΁u����L�����ɒ��ڂ���̂ŁA���������̓L�����ʒu��ōs�������v�u��ʂ͉�ʂ̌����ڂɍ��킹�������߁A��ʌv�Z�̓J�����ʒu��ōs�������v�Ƃ����\�����s�����Ƃ��ł��܂��B<br>
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B�����Z���T������Z���T�̃t�H�[�J�X���x����ݒ肵�Ȃ��󋵂ł́A���ړ_��ݒ肷��K�v�͂���܂���B���̏ꍇ�A�]���ǂ���A�S�Ă�3D�|�W�V���j���O�v�Z�����X�i�[�ʒu��ōs���܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update, criAtomEx3dListener_SetDistanceFocusLevel, criAtomEx3dListener_SetDirectionFocusLevel
 */
void CRIAPI criAtomEx3dListener_SetFocusPoint(CriAtomEx3dListenerHn ex_3d_listener, const CriAtomExVector *focus_point);

/*JP
 * \brief �����Z���T�̃t�H�[�J�X���x���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener			3D���X�i�[�n���h��
 * \param[in]	distance_focus_level	�����Z���T�̃t�H�[�J�X���x��
 * \par ����:
 * �����Z���T�̃t�H�[�J�X���x����ݒ肵�܂��B<br>
 * �����Z���T�́A3D�|�W�V���j���O�v�Z�̂����A���������v�Z�̊�ƂȂ�ʒu��\���܂��B��ʂ𖳎����ċ��������̂������݂̂����m����}�C�N�A�Ƃ����������ł��B<br>
 * �t�H�[�J�X���x���́A���ړ_�ɑ΂��Ăǂꂾ���Z���T�i�}�C�N�j���߂Â��邩��\���܂��B�Z���T�i�}�C�N�j�́A���X�i�[�ʒu�ƒ��ړ_�̊Ԃ����񂾒�����œ��������Ƃ��ł��A0.0f�����X�i�[�ʒu�A1.0f�����ړ_�Ɠ����ʒu�ɂȂ�܂��B<br>
 * �Ⴆ�΁A�����Z���T�̃t�H�[�J�X���x����1.0f�A�����Z���T�̃t�H�[�J�X���x����0.0f�Ƃ��邱�ƂŁA���ړ_����ɋ���������K�p���A���X�i�[�ʒu����ɒ�ʂ����肵�܂��B<br>
 * �f�t�H���g�l��0.0f�ł��B�����Z���T������Z���T�̃t�H�[�J�X���x����ݒ肵�Ȃ��󋵂ł́A�]���ǂ���A�S�Ă�3D�|�W�V���j���O�v�Z�����X�i�[�ʒu��ōs���܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update, criAtomEx3dListener_SetFocusPoint, criAtomEx3dListener_SetDirectionFocusLevel
 */
void CRIAPI criAtomEx3dListener_SetDistanceFocusLevel(CriAtomEx3dListenerHn ex_3d_listener, CriFloat32 distance_focus_level);

/*JP
 * \brief �����Z���T�̃t�H�[�J�X���x���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_listener			3D���X�i�[�n���h��
 * \param[in]	direction_focus_level	�����Z���T�̃t�H�[�J�X���x��
 * \par ����:
 * �����Z���T�̃t�H�[�J�X���x����ݒ肵�܂��B<br>
 * �����Z���T�́A3D�|�W�V���j���O�v�Z�̂����A��ʌv�Z�̊�ƂȂ�ʒu��\���܂��B���������𖳎����Ē�ʂ݂̂����m����}�C�N�A�Ƃ����������ł��B<br>
 * �����Z���T�̌����ɂ��ẮA���X�i�[�̌����i::criAtomEx3dListener_SetOrientation �֐��Őݒ�j�����̂܂܎g�p���܂��B<br>
 * �t�H�[�J�X���x���́A���ړ_�ɑ΂��Ăǂꂾ���Z���T�i�}�C�N�j���߂Â��邩��\���܂��B�Z���T�i�}�C�N�j�́A���X�i�[�ʒu�ƒ��ړ_�̊Ԃ����񂾒�����œ��������Ƃ��ł��A0.0f�����X�i�[�ʒu�A1.0f�����ړ_�Ɠ����ʒu�ɂȂ�܂��B<br>
 * �Ⴆ�΁A�����Z���T�̃t�H�[�J�X���x����1.0f�A�����Z���T�̃t�H�[�J�X���x����0.0f�Ƃ��邱�ƂŁA���ړ_����ɋ���������K�p���A���X�i�[�ʒu����ɒ�ʂ����肵�܂��B<br>
 * �f�t�H���g�l��0.0f�ł��B�����Z���T������Z���T�̃t�H�[�J�X���x����ݒ肵�Ȃ��󋵂ł́A�]���ǂ���A�S�Ă�3D�|�W�V���j���O�v�Z�����X�i�[�ʒu��ōs���܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dListener_Update, criAtomEx3dListener_SetFocusPoint, criAtomEx3dListener_SetDistanceFocusLevel
 */
void CRIAPI criAtomEx3dListener_SetDirectionFocusLevel(CriAtomEx3dListenerHn ex_3d_listener, CriFloat32 direction_focus_level);

/*JP
 * \brief �p���^�C�v���p��3D�̎��ɁA��������AISAC�Ɗp�xAISAC�R���g���[���l�������ɔ��f���邩�ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	flag	AISAC�R���g���[���l��K�p���邩�H�iCRI_TRUE:����ACRI_FALSE:���Ȃ��j
 * \par ����:
 * ������ flag �� CRI_TRUE ��ݒ肷��ƁA�p���^�C�v���p��3D�̉������Đ�����ۂɁA3D�\�[�X��3D���X�i�[�n���h����<br>
 * �ݒ肳��Ă���Ƃ��͏�ɋ�������AISAC�Ɗp�xAISAC�̌v�Z���ʂ������ɓK�p����܂��B
 * \attention
 * Atom���C�u�����̃f�t�H���g�ł́A�p��3D�����ɑ΂��ċ�������AISAC�Ɗp�xAISAC�̌v�Z���ʂ͓K�p����܂���B<br>
 * �{�֐���CRI Atom���C�u���� Ver.2.17.19 �ȑO�̓���Ƃ̌݊��ׂ̈ɒǉ�����܂����B
 * <br>
 * \sa criAtomEx_IsEnableCalculationAisacControlFrom3dPosition
 */
void CRIAPI criAtomEx_EnableCalculationAisacControlFrom3dPosition(CriBool flag);

/*JP
 * \brief �p���^�C�v���p��3D�̎��ɁA��������AISAC�Ɗp�xAISAC�R���g���[���l�������ɔ��f���Ă��邩�擾
 * \ingroup ATOMEXLIB_3D
 * \retval	CRI_TRUE	�v�Z���ʂ�K�p���Ă���
 * \retval	CRI_FALSE	�v�Z���ʂ�K�p���Ă��Ȃ�
 * \par ����:
 * �p���^�C�v���p��3D�̉������Đ�����ۂɁA3D�\�[�X��3D���X�i�[�n���h����<br>
 * �ݒ肳��Ă���Ƃ��ɋ�������AISAC�Ɗp�xAISAC�̌v�Z���ʂ������ɓK�p����Ă��邩�ۂ����擾���܂��B
 * \attention
 * Atom���C�u�����̃f�t�H���g�ł́A�p��3D�����ɑ΂��ċ�������AISAC�Ɗp�xAISAC�̌v�Z���ʂ͓K�p����܂���B<br>
 * �{�֐���CRI Atom���C�u���� Ver.2.17.19 �ȑO�̓���Ƃ̌݊��ׂ̈ɒǉ�����܂����B
 * <br>
 * \sa criAtomEx_EnableCalculationAisacControlFrom3dPosition
 */
CriBool CRIAPI criAtomEx_IsEnableCalculationAisacControlFrom3dPosition(void);

/*JP
 * \brief 3D���X�i�[�n���h���ɑ΂���3D���[�W�����n���h���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D���X�i�[�n���h���ɑ΂���3D���[�W�����n���h����ݒ肵�܂��B
 *
 * \attention
 * �����ExPlayer�ɐݒ肳��Ă���3D������3D���X�i�[�ɐݒ肳��Ă��郊�[�W�������قȂ�A
 * ����3D�����Ɠ������[�W�������ݒ肳��Ă���3D�g�����V�[�o�[����s���ꍇ�A�����̓~���[�g����܂��B<br>
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dListener_Update �֐����Ăяo���K�v������܂��B
 * <br>
 * \sa criAtomEx3dRegion_Create, criAtomEx3dListener_Update
 */
void CRIAPI criAtomEx3dListener_Set3dRegionHn(CriAtomEx3dListenerHn ex_3d_listener, CriAtomEx3dRegionHn ex_3d_region);

/*JP
 * \brief 3D���[�W�����n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config		3D���[�W�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	3D���[�W�����n���h���쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * 3D���[�W�����n���h�����쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������3D���[�W�����n���h�����쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomEx3dRegion_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * 3D���[�W�����n���h���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A3D���[�W�����n���h���쐬�p�R���t�B�O
 * �\���́i ::CriAtomEx3dRegionConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx3dRegion_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx3dRegion_Create, CriAtomEx3dRegionConfig
 */
CriSint32 CRIAPI criAtomEx3dRegion_CalculateWorkSize(const CriAtomEx3dRegionConfig *config);

/*JP
 * \brief 3D���[�W�����n���h���̍쐬
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config				3D���[�W�����n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work				3D���[�W�����n���h���쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size			3D���[�W�����n���h���쐬�p���[�N�T�C�Y
 * \return		criAtomEx3dRegionHn	3D���[�W�����n���h��
 * \par ����:
 * 3D���[�W�����n���h���쐬�p�R���t�B�O�Ɋ�Â��āA3D���[�W�����n���h�����쐬���܂��B<br>
 * �쐬�ɐ�������ƁA3D���[�W�����n���h����Ԃ��܂��B<br>
 * 3D���[�W�����n���h�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomEx3dRegion_CalculateWorkSize
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomEx3dRegion_CalculateWorkSize, criAtomEx3dRegion_Destroy
 */
CriAtomEx3dRegionHn CRIAPI criAtomEx3dRegion_Create(
	const CriAtomEx3dRegionConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief 3D���[�W�����n���h���̔j��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_region		3D���[�W�����n���h��
 * \par ����:
 * 3D���[�W�����n���h����j�����܂��B<br>
 * �{�֐������s�������_�ŁA3D���[�W�����n���h���쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��3D���[�W�����n���h���������ɂȂ�܂��B<br>
 * \sa criAtomEx3dRegion_Create
 */
void CRIAPI criAtomEx3dRegion_Destroy(CriAtomEx3dRegionHn ex_3d_region);

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config		3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \return		CriSint32	3D�g�����V�[�o�[�n���h���쐬�p���[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * 3D�g�����V�[�o�[�n���h�����쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^������3D�g�����V�[�o�[�n���h�����쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomEx3dTransceiver_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * 3D�g�����V�[�o�[�n���h���̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O
 * �\���́i ::CriAtomEx3dTransceiverConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomEx3dTransceiver_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx3dTransceiver_Create, CriAtomEx3dTransceiverConfig
 */
CriSint32 CRIAPI criAtomEx3dTransceiver_CalculateWorkSize(const CriAtomEx3dTransceiverConfig *config);

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���̍쐬
 * \ingroup ATOMEXLIB_3D
 * \param[in]	config				3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work				3D�g�����V�[�o�[�n���h���쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size			3D�g�����V�[�o�[�n���h���쐬�p���[�N�T�C�Y
 * \return		criAtomEx3dTransceiverHn	3D�g�����V�[�o�[�n���h��
 * \par ����:
 * 3D�g�����V�[�o�[�n���h���쐬�p�R���t�B�O�Ɋ�Â��āA3D�g�����V�[�o�[�n���h�����쐬���܂��B<br>
 * �쐬�ɐ�������ƁA3D�g�����V�[�o�[�n���h����Ԃ��܂��B<br>
 * 3D�g�����V�[�o�[�n���h�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomEx3dTransceiver_CalculateWorkSize
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomEx3dTransceiver_CalculateWorkSize, criAtomEx3dTransceiver_Destroy
 */
CriAtomEx3dTransceiverHn CRIAPI criAtomEx3dTransceiver_Create(const CriAtomEx3dTransceiverConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���̔j��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \par ����:
 * 3D�g�����V�[�o�[�n���h����j�����܂��B<br>
 * �{�֐������s�������_�ŁA3D�g�����V�[�o�[�n���h���쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��3D�g�����V�[�o�[�n���h���������ɂȂ�܂��B<br>
 * \sa criAtomEx3dTransceiver_Create
 */
void CRIAPI criAtomEx3dTransceiver_Destroy(CriAtomEx3dTransceiverHn ex_3d_transceiver);

/*JP
 * \brief 3D�g�����V�[�o�[�̍X�V
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \par ����:
 * 3D�g�����V�[�o�[�ɐݒ肳��Ă���p�����[�^�[���g�p���āA3D�g�����V�[�o�[���X�V���܂��B<br>
 * �{�֐��ł́A3D�g�����V�[�o�[�ɐݒ肳��Ă���S�Ẵp�����[�^�[���X�V���܂��B
 * �p�����[�^�[���ЂƂύX����x�ɖ{�֐��ɂčX�V�������s�������A
 * �����̃p�����[�^�[��ύX���Ă���X�V�������s�������������I�ł��B
 * \par ��:
 * \code
 * CriAtomExVector in_pos, out_pos;
 *
 * // Set input position
 * in_pos.x = 0.0f
 * in_pos.y = 0.0f
 * in_pos.z = 1.0f
 * criAtomEx3dTransceiver_SetInputPosition(transceiver, &in_pos);
 *
 * // Set output position
 * out_pos.x = 0.0f
 * out_pos.y = 0.0f
 * out_pos.z = 1.0f
 * criAtomEx3dTransceiver_SetOutputPosition(transceiver, &out_pos);
 *
 * // Update transceiver parameters
 * criAtomEx3dTransceiver_Update(transceiver);
 * \endcode
 * \attention
 * �{�֐���AtomEx�v���[���[�̃p�����[�^�[�X�V�i::criAtomExPlayer_UpdateAll, criAtomExPlayer_Update�j
 * �Ƃ͓Ɨ����ē��삵�܂��B3D�g�����V�[�o�[�̃p�����[�^�[��ύX�����ۂ́A�{�֐��ɂčX�V�������s���Ă��������B
 */
void CRIAPI criAtomEx3dTransceiver_Update(CriAtomEx3dTransceiverHn ex_3d_transceiver);

/*JP
 * \brief 3D�g�����V�[�o�[���͂̈ʒu�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	position			�ʒu�x�N�g��
 * \par ����:
 * 3D�g�����V�[�o�[���͂̈ʒu��ݒ肵�܂��B<br>
 * �ʒu�́A���������A����ђ�ʌv�Z�Ɏg�p����܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏw�肵�܂��B<br>
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetInputPosition(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriAtomExVector *position);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͂̈ʒu�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	position			�ʒu�x�N�g��
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̈ʒu��ݒ肵�܂��B<br>
 * �ʒu�́A���������A����ђ�ʌv�Z�Ɏg�p����܂��B<br>
 * �ʒu�́A3�����x�N�g���Ŏw�肵�܂��B<br>
 * �f�t�H���g�l��(0.0f, 0.0f, 0.0f)�ł��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputPosition(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriAtomExVector *position);

/*JP
 * \brief 3D�g�����V�[�o�[���͂̌����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	front				�O���x�N�g��
 * \param[in]	top					����x�N�g��
 * \par ����:
 * 3D�g�����V�[�o�[�̌�����O���x�N�g���Ə���x�N�g���Őݒ肵�܂��B<br>
 * �����́A3�����x�N�g���Ŏw�肵�܂��B�ݒ肳�ꂽ�����x�N�g���́A���C�u���������Ő��K�����Ďg�p����܂��B<br>
 * �f�t�H���g�l�ȉ��̂Ƃ���ł��B<br>
 * 	- �O���x�N�g���F(0.0f, 0.0f, 1.0f)
 * 	- ����x�N�g���F(0.0f, 1.0f, 0.0f)
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetInputOrientation(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriAtomExVector *front, const CriAtomExVector *top);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͂̌����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	front				�O���x�N�g��
 * \param[in]	top					����x�N�g��
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̌�����ݒ肵�܂��B<br>
 * �{�֐��Őݒ肵�������́A�T�E���h�R�[���̌����Ƃ��Đݒ肳��܂��B<br>
 * �T�E���h�R�[���́A3D�g�����V�[�o�[���特���������������\���A���̎w�����̕\���Ɏg�p����܂��B<br>
 * �T�E���h�R�[���̌����́A3�����x�N�g���Ŏw�肵�܂��B�ݒ肳�ꂽ�����x�N�g���́A���C�u���������Ő��K�����Ďg�p����܂��B<br>
 * �f�t�H���g�l�ȉ��̂Ƃ���ł��B<br>
 * 	- �O���x�N�g���F(0.0f, 0.0f, 1.0f)
 * 	- ����x�N�g���F(0.0f, 1.0f, 0.0f)
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_SetOutputConeParameter, criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputOrientation(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriAtomExVector *front, const CriAtomExVector *top);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͂̃T�E���h�R�[���p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	inside_angle		�T�E���h�R�[���̃C���T�C�h�A���O��
 * \param[in]	outside_angle		�T�E���h�R�[���̃A�E�g�T�C�h�A���O��
 * \param[in]	outside_volume		�T�E���h�R�[���̃A�E�g�T�C�h�{�����[��
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̃T�E���h�R�[���p�����[�^�[��ݒ肵�܂��B<br>
 * �T�E���h�R�[���́A3D�g�����V�[�o�[���特���������������\���A���̎w�����̕\���Ɏg�p����܂��B<br>
 * �T�E���h�R�[���́A�����R�[���A�O���R�[���ō\������܂��B�C���T�C�h�A���O���͓����R�[���̊p�x�A
 * �A�E�g�T�C�h�A���O���͊O���R�[���̊p�x�A�A�E�g�T�C�h�{�����[���͊O���R�[���̊p�x�ȏ�̕����ł̉��ʂ����ꂼ��\���܂��B<br>
 * �����R�[���̊p�x��菬�����p�x�̕����ł́A�R�[���ɂ�錸�����󂯂܂���B
 * �����R�[���ƊO���R�[���̊Ԃ̕����ł́A���X�ɃA�E�g�T�C�h�{�����[���܂Ō������܂��B<br>
 * �C���T�C�h�A���O������уA�E�g�T�C�h�A���O���́A0.0f�`360.0f��x�Ŏw�肵�܂��B<br>
 * �A�E�g�T�C�h�{�����[���́A0.0f�`1.0f��U���ɑ΂���{���Ŏw�肵�܂��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł���A�R�[���ɂ�錸���͍s���܂���B<br>
 * 	- �C���T�C�h�A���O���F360.0f
 * 	- �A�E�g�T�C�h�A���O���F360.0f
 * 	- �A�E�g�T�C�h�{�����[���F0.0f
 * 	
 * �f�t�H���g�l�́A::criAtomEx3dTransceiver_ChangeDefaultConeParameter �֐��ɂĕύX�\�ł��B<br>
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputConeParameter(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 inside_angle, CriFloat32 outside_angle, CriFloat32 outside_volume);

/*JP
 * \brief 3D�g�����V�[�o�[�̍ŏ������^�ő勗���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	min_attenuation_distance		�ŏ�����
 * \param[in]	max_attenuation_distance		�ő勗��
 * \par ����:
 * 3D�g�����V�[�o�[�̍ŏ������^�ő勗����ݒ肵�܂��B<br>
 * �ŏ������́A����ȏ㉹�ʂ��傫���Ȃ�Ȃ�������\���܂��B�ő勗���́A�ŏ����ʂɂȂ鋗����\���܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- �ŏ������F0.0f
 * 	- �ő勗���F0.0f
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputMinMaxAttenuationDistance(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 min_attenuation_distance, CriFloat32 max_attenuation_distance);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͂̃C���e���A�p���j���O���E�����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	transceiver_radius		3D�g�����V�[�o�[�̔��a
 * \param[in]	interior_distance	�C���e���A����
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̃C���e���A�p���j���O���E�����̐ݒ�����܂��B<br>
 * 3D�g�����V�[�o�[�o�͂̔��a�́A3D�g�����V�[�o�[�o�͂����Ƃ����Ƃ��̔��a�ł��B<br>
 * �C���e���A�����́A�C���e���A�p���j���O�K�p�����3D�g�����V�[�o�[�̔��a����̋����ł��B<br>
 * 3D�g�����V�[�o�[�̔��a���ł́A�C���e���A�p���j���O�K�p����܂����A�C���e���A������0.0�ƈ����邽�߁A
 * �S�ẴX�s�[�J�[���瓯�����ʂŉ������Đ�����܂��B<br>
 * �C���e���A�������ł́A�C���e���A�p���j���O�K�p����܂��B<br>
 * �C���e���A�����O�ł́A�C���e���A�p���j���O�K�p���ꂸ�A3D�g�����V�[�o�[�ʒu�ɍł��߂�1�A
 * �܂���2�̃X�s�[�J�[���特�����Đ�����܂��B<br>
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- 3D�g�����V�[�o�[�̔��a�F0.0f
 * 	- �C���e���A�����F0.0f�i3D�g�����V�[�o�[�̍ŏ������Ɉˑ��j
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputInteriorPanField(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 transceiver_radius, CriFloat32 interior_distance);

/*JP
 * \brief 3D�g�����V�[�o�[���͂̃N���X�t�F�[�h���E�����̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	direct_audio_radius		���ډ��̈�̔��a
 * \param[in]	crossfade_distance	�N���X�t�F�[�h����
 * \par ����:
 * 3D�g�����V�[�o�[���͂̃N���X�t�F�[�h���E�����̐ݒ�����܂��B<br>
 * ���ډ��̈�̔��a���ł́A3D�g�����V�[�o�[�̏o�͂���̉����͍Đ����ꂸ�A3D��������̉����݂̂��Đ�����܂��B<br>
 * �N���X�t�F�[�h�����́A3D�g�����V�[�o�[�o�͂�3D��������̉����̃N���X�t�F�[�h���K�p����钼�ډ��̈悩��̋����ł��B<br>
 * ���ډ��̈�ł́A�N���X�t�F�[�h�̊�������������̉���=1�A3D�g�����V�[�o�[����̉���=0�ɂȂ�̂ŁA
 * 3D�g�����V�[�o�[�o�͂���̉����͕������Ȃ��Ȃ�A��������̉����݂̂��Đ�����܂��B<br>
 * �N���X�t�F�[�h�������ł́A���X�i�[�̈ʒu�ɉ����ăN���X�t�F�[�h���K�p����܂��B<br>
 * �N���X�t�F�[�h�����O�ł́A3D��������̉����͕��������A3D�g�����V�[�o�[�o�͂���̉����݂̂���������悤�ɂȂ�܂��B
 * ���C�u�������������̃f�t�H���g�l�͈ȉ��̂Ƃ���ł��B<br>
 * 	- ���ډ��̈�̔��a�F0.0f
 * 	- �N���X�t�F�[�h�����F0.0f
 * 	
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetInputCrossFadeField(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 direct_audio_radius, CriFloat32 crossfade_distance);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͂̃{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver		3D�g�����V�[�o�[�n���h��
 * \param[in]	volume				�{�����[��
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̃{�����[����ݒ肵�܂��B<br>
 * 3D�g�����V�[�o�[�o�͂̃{�����[���́A��ʂɊւ�鉹�ʁiL,R,SL,SR�j�ɂ̂݉e�����ALFE��Z���^�[�ւ̏o�̓��x���ɂ͉e�����܂���B<br>
 * �{�����[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * ���C�u�������������̃f�t�H���g�l��1.0f�ł��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetOutputVolume(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 volume);

/*JP
 * \brief 3D�g�����V�[�o�[��AISAC�����t����
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	global_aisac_name	���t����O���[�o��AISAC��
 * \par ����:
 * 3D�g�����V�[�o�[��AISAC���A�^�b�`�i���t���j���܂��B
 * AISAC���A�^�b�`���邱�Ƃɂ��A�L���[��g���b�N��AISAC��ݒ肵�Ă��Ȃ��Ă��AAISAC�̌��ʂ𓾂邱�Ƃ��ł��܂��B<br>
 * <br>
 * AISAC�̃A�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃A�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \par ���l:
 * �S�̐ݒ�iACF�t�@�C���j�Ɋ܂܂��O���[�o��AISAC�̂݁A�A�^�b�`�\�ł��B<br>
 * AISAC�̌��ʂ𓾂�ɂ́A�L���[��g���b�N�ɐݒ肳��Ă���AISAC�Ɠ��l�ɁA�Y������AISAC�R���g���[���l��ݒ肷��K�v������܂��B<br>
 * \attention
 * �L���[��g���b�N�ɁuAISAC�R���g���[���l��ύX����AISAC�v���ݒ肳��Ă����Ƃ��Ă��A
 * ���̓K�p���ʂ�AISAC�R���g���[���l�́A3D�g�����V�[�o�[�ɃA�^�b�`����AISAC�ɂ͉e�����܂���B<br>
 * ���݁A�u�I�[�g���W�����[�V�����v��u�����_���v�Ƃ������R���g���[���^�C�v��AISAC�̃A�^�b�`�ɂ͑Ή����Ă���܂���B<br>
 * ���݁A3D�g�����V�[�o�[�ɃA�^�b�`�ł���AISAC�̍ő吔�́A8�Œ�ł��B
 * \sa criAtomEx3dTransceiver_DetachAisac
 */
void CRIAPI criAtomEx3dTransceiver_AttachAisac(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriChar8* global_aisac_name);

/*JP
 * \brief 3D�g�����V�[�o�[����AISAC�����O��
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	global_aisac_name	���O���O���[�o��AISAC��
 * \par ����:
 * 3D�g�����V�[�o�[����AISAC���f�^�b�`�i���O���j���܂��B<br>
 * <br>
 * AISAC�̃f�^�b�`�Ɏ��s�����ꍇ�A�֐����ŃG���[�R�[���o�b�N���������܂��B<br>
 * AISAC�̃f�^�b�`�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W���m�F���Ă��������B<br>
 * \sa criAtomEx3dTransceiver_AttachAisac
 */
void CRIAPI criAtomEx3dTransceiver_DetachAisac(CriAtomEx3dTransceiverHn ex_3d_transceiver, const CriChar8* global_aisac_name);

/*JP
 * \brief �p�xAISAC�R���g���[���l�̍ő�ω��ʂ̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	max_delta			�p�xAISAC�R���g���[���l�̍ő�ω���
 * \par ����:
 * �p�xAISAC�ɂ��AISAC�R���g���[���l���ύX�����ۂ́A�ő�ω��ʂ�ݒ肵�܂��B<br>
 * �ő�ω��ʂ��߂ɕύX����ƁA3D�g�����V�[�o�[�ƃ��X�i�[�Ԃ̑��Ίp�x���}���ɕς�����ꍇ�ł��A
 * �p�xAISAC�ɂ��AISAC�R���g���[���l�̕ω����X���[�Y�ɂ��邱�Ƃ��ł��܂��B<br>
 * �Ⴆ�΁A(0.5f / 30.0f)��ݒ肷��ƁA�p�x��0�x��180�x�ɕω������ꍇ�ɁA30�t���[�������ĕω�����悤�ȕω��ʂƂȂ�܂��B<br>
 * �f�t�H���g�l��1.0f�i�����Ȃ��j�ł��B
 * �f�[�^���ł͖{�p�����[�^�[�͐ݒ�ł��Ȃ����߁A��ɖ{�֐��ł̐ݒ�l���g�p����܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * �{�֐��Őݒ肵�Ă���ő�ω��ʂ́A��ʊp�x�����Ɍv�Z����Ă���A�p�xAISAC�R���g���[���l�̕ω��ɂ̂ݓK�p����܂��B
 * ��ʊp�x���̂ɂ͉e���͂���܂���B
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetMaxAngleAisacDelta(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriFloat32 max_delta);

/*JP
 * \brief ����AISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	aisac_control_id	����AISAC�R���g���[��ID
 * \par ����:
 * �ŏ������A�ő勗���Ԃ̋��������ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * �{�֐���AISAC�R���g���[��ID��ݒ肵���ꍇ�A�f�t�H���g�̋��������͖����ɂȂ�܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetDistanceAisacControlId(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriUint16 aisac_control_id);

/*JP
 * \brief ���X�i�[����ʊpAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	aisac_control_id	���X�i�[����ʊpAISAC�R���g���[��ID
 * \par ����:
 * ���X�i�[���猩��3D�g�����V�[�o�[�̕��ʊp�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetListenerBasedAzimuthAngleAisacControlId(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriUint16 aisac_control_id);

/*JP
 * \brief ���X�i�[���pAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	aisac_control_id	���X�i�[���pAISAC�R���g���[��ID
 * \par ����:
 * ���X�i�[���猩��3D�g�����V�[�o�[�̋�p�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetListenerBasedElevationAngleAisacControlId(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriUint16 aisac_control_id);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͊���ʊpAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	aisac_control_id	3D�g�����V�[�o�[����ʊpAISAC�R���g���[��ID
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̈ʒu���猩�����X�i�[�̕��ʊp�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetTransceiverOutputBasedAzimuthAngleAisacControlId(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriUint16 aisac_control_id);

/*JP
 * \brief 3D�g�����V�[�o�[�o�͊��pAISAC�R���g���[��ID�̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \param[in]	ex_3d_transceiver	3D�g�����V�[�o�[�n���h��
 * \param[in]	aisac_control_id	3D�g�����V�[�o�[���pAISAC�R���g���[��ID
 * \par ����:
 * 3D�g�����V�[�o�[�o�͂̈ʒu���猩�����X�i�[�̋�p�ɘA������AISAC�R���g���[��ID���w�肵�܂��B<br>
 * \attention
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B<br>
 * \sa criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_SetTransceiverOutputBasedElevationAngleAisacControlId(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriUint16 aisac_control_id);

/*JP
 * \brief 3D�g�����V�[�o�[�n���h���ɑ΂���3D���[�W�����n���h���̐ݒ�
 * \ingroup ATOMEXLIB_3D
 * \par ����:
 * 3D�g�����V�[�o�[�n���h���ɑ΂���3D���[�W�����n���h����ݒ肵�܂��B
 *
 * \attention
 * �����ExPlayer�ɐݒ肳��Ă���3D������3D���X�i�[�ɐݒ肳��Ă��郊�[�W�������قȂ�A
 * ����3D�����Ɠ������[�W�������ݒ肳��Ă���3D�g�����V�[�o�[���Ȃ��ꍇ�A�����̓~���[�g����܂��B<br>
 * �ݒ肵���p�����[�^�[�����ۂɓK�p����ɂ́A::criAtomEx3dTransceiver_Update �֐����Ăяo���K�v������܂��B
 * <br>
 * \sa criAtomEx3dRegion_Create, criAtomEx3dTransceiver_Update
 */
void CRIAPI criAtomEx3dTransceiver_Set3dRegionHn(CriAtomEx3dTransceiverHn ex_3d_transceiver, CriAtomEx3dRegionHn ex_3d_region);

/*==========================================================================
 *      CRI AtomEx DSP API
 *=========================================================================*/

/*JP
 * \brief DSP�̃f�^�b�`
 * \ingroup ATOMEXLIB_DSP
 * \param[in]	pool		�{�C�X�v�[���n���h��
 * \par ����:
 * �{�C�X�v�[���ɒǉ�����DSP�����O���܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \attention ���l:
 * ���݁A�{�֐����g�p�ł��Ȃ��v���b�g�t�H�[�������݂��܂��B<br>
 */
void CRIAPI criAtomExVoicePool_DetachDsp(CriAtomExVoicePoolHn pool);

/*JP
 * \brief �s�b�`�V�t�^DSP�A�^�b�`�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_DSP
 * \param[in]	config		�A�^�b�`�p�R���t�B�O
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �s�b�`�V�t�^DSP�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * \sa criAtomExVoicePool_AttachDspPitchShifter
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForDspPitchShifter(
	const CriAtomExDspPitchShifterConfig *config);

/*JP
 * \brief �s�b�`�V�t�^DSP�̃A�^�b�`
 * \ingroup ATOMEXLIB_DSP
 * \param[in]	pool		�A�^�b�`��{�C�X�v�[���n���h��
 * \param[in]	config		�A�^�b�`�p�R���t�B�O
 * \param[in]	work		�A�^�b�`�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size	�A�^�b�`�p���[�N�̈�̃T�C�Y
 * \par ����:
 * �{�C�X�v�[���Ƀs�b�`�V�t�^DSP��ǉ����܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \attention ���l:
 * ���݁A�{�֐����g�p�ł��Ȃ��v���b�g�t�H�[�������݂��܂��B<br>
 */
void CRIAPI criAtomExVoicePool_AttachDspPitchShifter(CriAtomExVoicePoolHn pool,
	const CriAtomExDspPitchShifterConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �^�C���X�g���b�`DSP�A�^�b�`�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_DSP
 * \param[in]	config		�A�^�b�`�p�R���t�B�O
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �^�C���X�g���b�`DSP�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B
 * \sa criAtomExVoicePool_AttachDspTimeStretch
 */
CriSint32 CRIAPI criAtomExVoicePool_CalculateWorkSizeForDspTimeStretch(
	const CriAtomExDspTimeStretchConfig *config);

/*JP
 * \brief �^�C���X�g���b�`DSP�̃A�^�b�`
 * \ingroup ATOMEXLIB_DSP
 * \param[in]	pool		�A�^�b�`��{�C�X�v�[���n���h��
 * \param[in]	config		�A�^�b�`�p�R���t�B�O
 * \param[in]	work		�A�^�b�`�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size	�A�^�b�`�p���[�N�̈�̃T�C�Y
 * \par ����:
 * �{�C�X�v�[���Ƀ^�C���X�g���b�`DSP��ǉ����܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \attention ���l:
 * ���݁A�{�֐����g�p�ł��Ȃ��v���b�g�t�H�[�������݂��܂��B<br>
 */
void CRIAPI criAtomExVoicePool_AttachDspTimeStretch(CriAtomExVoicePoolHn pool,
	const CriAtomExDspTimeStretchConfig *config, void *work, CriSint32 work_size);

/* ========================================================================*/
/*       CRI AtomEx Streaming Cache API                                    */
/* ========================================================================*/
/*JP
 * \brief �w�肵��Cue�iID�w��j�̃X�g���[���p�f�[�^���L���b�V���ς݂����擾���܂�
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id	�ΏۂƂ���X�g���[�~���O�L���b�V��ID
 * \param[in]	acb_hn			Cue���܂�ł���ACB�n���h��
 * \param[in]	id				�L���b�V���ς݊m�F�Ώۂ�CueID
 * \retval	CRI_TRUE	= �L���b�V���ς�
 * \retval	CRI_FALSE	= ���L���b�V��
 * \par ����:
 * �ΏۂƂ���X�g���[�~���O�L���b�V���ɂ����āA
 * ID�Ŏw�肵��Cue�̃X�g���[�~���O�p�f�[�^���L���b�V���ς݂����擾���܂��B<br>
 * \attention
 * �{�֐��́ACue�������̃X�g���[���p�f�[�^�����ꍇ�ɂ��Ă͐��m�ȏ���Ԃ��܂���B<br>
 * Cue�������̃X�g���[���p�f�[�^�����ꍇ�A
 * Cue���ōŏ��Ɍ��������X�g���[���p�f�[�^���L���b�V�����ꂽ�i�K��
 * CRI_TRUE��Ԃ��܂��B<br>
 * \sa criAtomStreamingCache_IsCachedWaveformByName
 */
CriBool CRIAPI criAtomExStreamingCache_IsCachedWaveformById(
	CriAtomExStreamingCacheId stm_cache_id, CriAtomExAcbHn acb_hn, CriAtomExCueId id);

/*JP
 * \brief �w�肵��Cue�i���O�w��j�̃X�g���[���p�f�[�^���L���b�V���ς݂����擾���܂�
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id	�ΏۂƂ���X�g���[�~���O�L���b�V��ID
 * \param[in]	acb_hn			Cue���܂�ł���ACB�n���h��
 * \param[in]	name			�L���b�V���ς݊m�F�Ώۂ�Cue��
 * \retval	CRI_TRUE	= �L���b�V���ς�
 * \retval	CRI_FALSE	= ���L���b�V��
 * \par ����:
 * �ΏۂƂ���X�g���[�~���O�L���b�V���ɂ����āA
 * Cue���Ŏw�肵��Cue�̃X�g���[�~���O�p�f�[�^���L���b�V���ς݂����擾���܂��B<br>
 * \attention
 * �{�֐��́ACue�������̃X�g���[���p�f�[�^�����ꍇ�ɂ��Ă͐��m�ȏ���Ԃ��܂���B<br>
 * Cue�������̃X�g���[���p�f�[�^�����ꍇ�A
 * Cue���ōŏ��Ɍ��������X�g���[���p�f�[�^���L���b�V�����ꂽ�i�K��
 * CRI_TRUE��Ԃ��܂��B<br>
 * \sa criAtomStreamingCache_IsCachedWaveformById
 */
CriBool CRIAPI criAtomExStreamingCache_IsCachedWaveformByName(
	CriAtomExStreamingCacheId stm_cache_id, CriAtomExAcbHn acb_hn, const CriChar8 *name);



/*JP
 * \brief �w�肵��Cue�iID�w��j�̃X�g���[���p�f�[�^���L���b�V���Ƀ��[�h
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id	�ΏۂƂ���X�g���[�~���O�L���b�V��ID
 * \param[in]	acb_hn			Cue���܂�ł���ACB�n���h��
 * \param[in]	cue_id			�L���b�V���Ώۂ�CueID
 * \return		CriBool			�����^���s
 * \retval	CRI_FALSE	= ���[�h�̎��s
 * \retval	CRI_TRUE	= ���[�h�̐���
 * \par ����:
 * �X�g���[�~���O�L���b�V���ɑ΂��AID�Ŏw�肵��Cue�̃X�g���[�~���O�p�f�[�^�����[�h���܂��B<br>
 * �{�֐��ɐ��������::CRI_TRUE��Ԃ��A�w�肵��Cue���L���b�V��������ԂɂȂ�܂��B<br>
 * �{�֐��Ɏ��s����ƁA::CRI_FALSE��Ԃ��܂��B<br>
 * \par ���l:
 * �{�֐��͊������A�ł��B
 * \attention
 * Cue�������̃X�g���[���p�f�[�^�����ꍇ�A
 * �{�֐���Cue���ōŏ��Ɍ��������X�g���[���p�f�[�^�݂̂����[�h���܂��B<br>
 */
CriBool CRIAPI criAtomExStreamingCache_LoadWaveformById(
	CriAtomExStreamingCacheId stm_cache_id, CriAtomExAcbHn acb_hn, CriAtomExCueId cue_id);

/*JP
 * \brief �w�肵��Cue�i���O�w��j�̃X�g���[���p�f�[�^���L���b�V���Ƀ��[�h
 * \ingroup ATOMEXLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id	�ΏۂƂ���X�g���[�~���O�L���b�V��ID
 * \param[in]	acb_hn			Cue���܂�ł���ACB�n���h��
 * \param[in]	name			�L���b�V���Ώۂ�Cue��
 * \return		CriBool			�����^���s
 * \retval	CRI_FALSE	= ���[�h�̎��s
 * \retval	CRI_TRUE	= ���[�h�̐���
 * \par ����:
 * �X�g���[�~���O�L���b�V���ɑ΂��AID�Ŏw�肵��Cue�̃X�g���[�~���O�p�f�[�^�����[�h���܂��B<br>
 * �{�֐��ɐ��������::CRI_TRUE��Ԃ��A�w�肵��Cue���L���b�V��������ԂɂȂ�܂��B<br>
 * �{�֐��Ɏ��s����ƁA::CRI_FALSE��Ԃ��܂��B<br>
 * \par ���l:
 * �{�֐��͊������A�ł��B
 * \attention
 * Cue�������̃X�g���[���p�f�[�^�����ꍇ�A
 * �{�֐���Cue���ōŏ��Ɍ��������X�g���[���p�f�[�^�݂̂����[�h���܂��B<br>
 */
CriBool CRIAPI criAtomExStreamingCache_LoadWaveformByName(
	CriAtomExStreamingCacheId stm_cache_id, CriAtomExAcbHn acb_hn, const CriChar8 *name);


/* ========================================================================*/
/*       CRI AtomEx Tween(Parameter Animation) API                         */
/* ========================================================================*/
/*JP
 * \brief �g�D�C�[���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	config		�g�D�C�[���쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �g�D�C�[�����쐬����̂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^�����Ƀg�D�C�[�����쐬����ꍇ�A���炩���ߖ{�֐��Ōv�Z����
 * ���[�N�̈�T�C�Y���̃����������[�N�̈�Ƃ��� ::criAtomExTween_Create �֐���
 * �Z�b�g����K�v������܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExTween_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomExTweenConfig, criAtomExTween_Create
 */
/* �g�D�C�[���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�̌v�Z */
CriSint32 CRIAPI criAtomExTween_CalculateWorkSize(const CriAtomExTweenConfig *config);

/*JP
 * \brief �g�D�C�[���̍쐬
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	config				�g�D�C�[���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work				�g�D�C�[���쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size			�g�D�C�[���쐬�p���[�N�T�C�Y
 * \return		CriAtomExTweenHn	�g�D�C�[���n���h��
 * \par ����:
 * �g�D�C�[���쐬�p�R���t�B�O�Ɋ�Â��āA�g�D�C�[�����쐬���܂��B<br>
 * �쐬�ɐ�������ƁA�g�D�C�[���n���h����Ԃ��܂��B<br>
 * �g�D�C�[�����쐬����ۂɂ́A���[�N�̈�Ƃ��ă�������n���K�v������܂��B<br>
 * �K�v�ȃ������̃T�C�Y�́A ::criAtomExTween_CalculateWorkSize 
 * �֐��Ōv�Z���܂��B<br>
 * �i::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B�j<br>
 * �쐬�����g�D�C�[���́A::criAtomExPlayer_AttachTween �֐��ɂ�AtomEx�v���[���[�ɃA�^�b�`���邱�ƂŌ��ʂ𔭊����܂��B
 * \par ���l:
 * �g�D�C�[���̕ێ�����p�����[�^�[�̏����l�́A�R���t�B�O�\���̂Ńp�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_BASIC���w�肵���ꍇ�͊e�p�����[�^�[�̃f�t�H���g�l�A�܂��̓p�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_AISAC���w�肵���ꍇ��0.0f�ł��B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * \sa criAtomExTween_CalculateWorkSize, criAtomExTween_Destroy, criAtomExPlayer_AttachTween
 */
CriAtomExTweenHn CRIAPI criAtomExTween_Create(
	const CriAtomExTweenConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �g�D�C�[���̔j��
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \par ����:
 * �g�D�C�[����j�����܂��B<br>
 * �{�֐������s�������_�ŁA�g�D�C�[���쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵���g�D�C�[���n���h���������ɂȂ�܂��B<br>
 * �g�D�C�[�����A�^�b�`����AtomEx�v���[���[�ōĐ����Ă��鉹��������ꍇ�A
 * �{�֐������s����O�ɁA�����̉������~���邩�A����AtomEx�v���[���[��j�����Ă��������B
 * \sa criAtomExTween_Create
 */
void CRIAPI criAtomExTween_Destroy(CriAtomExTweenHn tween);

/*JP
 * \brief ���ݒl�̎擾
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \par ����:
 * �g�D�C�[�����ێ����Ă���p�����[�^�[�̌��ݒl���擾���܂��B<br>
 */
CriFloat32 CRIAPI criAtomExTween_GetValue(CriAtomExTweenHn tween);

/*JP
 * \brief ���ݒl����w��l�ɕω�
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \param[in]	time_ms		�ω��ɗv���鎞�ԁi�~���b�P�ʁj
 * \param[in]	value		�ω���̍ŏI�l
 * \par ����:
 * time_ms�Ŏw�肵�����Ԃ������āA�{�֐��Ăяo�����Ƀg�D�C�[�����ێ����Ă��錻�ݒl����Avalue�Ŏw�肵���l�ւƕω����܂��B<br>
 * �ω��J�[�u�̓��j�A�i���`�j�ł��B
 */
void CRIAPI criAtomExTween_MoveTo(CriAtomExTweenHn tween, CriUint16 time_ms, CriFloat32 value);

/*JP
 * \brief �w��l���猻�ݒl�ɕω�
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \param[in]	time_ms		�ω��ɗv���鎞�ԁi�~���b�P�ʁj
 * \param[in]	value		�ω��O�̊J�n�l
 * \par ����:
 * time_ms�Ŏw�肵�����Ԃ������āAvalue�Ŏw�肵���l����A�{�֐��Ăяo�����Ƀg�D�C�[�����ێ����Ă��錻�ݒl�ւƕω����܂��B<br>
 * �ω��J�[�u�̓��j�A�i���`�j�ł��B
 */
void CRIAPI criAtomExTween_MoveFrom(CriAtomExTweenHn tween, CriUint16 time_ms, CriFloat32 value);

/*JP
 * \brief �g�D�C�[���̒�~
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \par ����:
 * �g�D�C�[���ɂ��p�����[�^�[�̎��ԕω����~���܂��B<br>
 */
void CRIAPI criAtomExTween_Stop(CriAtomExTweenHn tween);

/*JP
 * \brief �g�D�C�[���̃��Z�b�g
 * \ingroup ATOMEXLIB_TWEEN
 * \param[in]	tween		�g�D�C�[���n���h��
 * \par ����:
 * �g�D�C�[���̕ێ����Ă���p�����[�^�[�̌��ݒl�����Z�b�g���A�����l�ɖ߂��܂��B<br>
 * �g�D�C�[���̕ێ�����p�����[�^�[�̏����l�́A�R���t�B�O�\���̂Ńp�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_BASIC���w�肵���ꍇ�͊e�p�����[�^�[�̃f�t�H���g�l�A�܂��̓p�����[�^�[�^�C�v��::CRIATOMEX_PARAMETER_TYPE_AISAC���w�肵���ꍇ��0.0f�ł��B
 * \par ���l:
 * �g�D�C�[���ɂ�鎞�ԕω������삵�Ă����ꍇ�A������~���܂��B
 */
void CRIAPI criAtomExTween_Reset(CriAtomExTweenHn tween);

/*==========================================================================
 *      CRI AtomEx Voice Event API
 *=========================================================================*/
/*JP
 * \brief �{�C�X�C�x���g�R�[���o�b�N�̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�{�C�X�C�x���g�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �{�C�X�C�x���g�R�[���o�b�N��o�^���܂��B<br>
 * �{�֐����g�p���ă{�C�X�C�x���g�R�[���o�b�N��o�^���邱�ƂŁA
 * �{�C�X�C�x���g�i�{�C�X�̎擾�^����^�D�����j�������̏ڍ׏��
 * �i�Đ��^��~����鉹���f�[�^�̏ڍ׏�񓙁j���擾�\�ł��B<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExVoiceEventCbFunc �̐��������Q�Ƃ��������B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \attention
 * �{�֐��œo�^�����R�[���o�b�N�ɂ́A�{�C�X�P�ʂ̃��~�b�g����
 *�i�{�C�X�v���C�I���e�B�Ɋ�Â����g�`�P�ʂ̃v���C�I���e�B����j
 * �Ɋւ�����݂̂��Ԃ���܂��B<br>
 * �i�J�e�S���L���[�v���C�I���e�B�ɂ�鐧��Ɋւ�����́A����擾�ł��܂���B�j<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * \sa CriAtomExVoiceEventCbFunc
 */
void CRIAPI criAtomEx_SetVoiceEventCallback(CriAtomExVoiceEventCbFunc func, void *obj);

/*JP
 * \brief �{�C�X���̗�
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�{�C�X���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �Đ����̃{�C�X�̏���񋓂��܂��B<br>
 * <br>
 * �{�֐������s����ƁA�� 1 �����i func �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐����Đ����̃{�C�X�̐��������Ăяo����܂��B<br>
 * �R�[���o�b�N�֐��ɂ́A�Đ����̃{�C�X�Ɋւ���ڍ׏��
 * CriAtomExVoiceInfoDetail �\���̂Ƃ��ēn����܂��B<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExVoiceInfoCbFunc �̐��������Q�Ƃ��������B<br>
 * <br>
 * func��NULL���w�肷�邱�Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \attention
 * �{�֐��œo�^�����R�[���o�b�N�ɂ́A
 * �����\�ȃ{�C�X���\�[�X�����{�C�X�̏�񂾂����Ԃ���܂��B<br>
 * �i�o�[�`���������ꂽ�{�C�X�̏��͕Ԃ���܂���B�j<br>
 * \sa CriAtomExVoiceInfoCbFunc
 */
void CRIAPI criAtomEx_EnumerateVoiceInfos(CriAtomExVoiceInfoCbFunc func, void *obj);

/*JP
 * \brief �{�C�X��~���Ď�����R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	func		�{�C�X��~�Ď��R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �{�C�X�̒�~���Ď�����R�[���o�b�N�֐��̓o�^�����܂��B<br>
 * <br>
 * �{�֐������s����ƁA�� 1 �����i func �j
 * �ŃZ�b�g���ꂽ�R�[���o�b�N�֐����Ď����Ă���Đ�ID���Ŕ������Ă���{�C�X����~����ۂɌĂяo����܂��B<br>
 * �R�[���o�b�N�֐��ɂ́A��~�{�C�X�Ɋւ�����
 * CriAtomExMonitoringVoiceStopInfo �\���̂Ƃ��ēn����܂��B<br>
 * \par ���l:
 * �� 2 �����i obj �j�ɃZ�b�g�����l�́A�R�[���o�b�N�֐��̈����Ƃ��ēn����܂��B<br>
 * �R�[���o�b�N�֐��̂��̑��̈����ɂ��ẮA
 * �ʓr ::CriAtomExMonitoringVoiceStopCbFunc �̐��������Q�Ƃ��������B<br>
 * \sa CriAtomExMonitoringVoiceStopCbFunc
 */
void CRIAPI criAtomEx_SetMonitoringVoiceStopCallback(CriAtomExMonitoringVoiceStopCbFunc func, void *obj);

/*JP
 * \brief �{�C�X��~���Ď�����Đ�ID�̓o�^
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	playback_id		�{�C�X��~���Ď�����Đ�ID
 * \par ����:
 * �{�C�X�̒�~���Ď�����Đ�ID��o�^�����܂��B<br>
 * <br>
 * �Ď��\�ȍĐ�ID�͂P�����ł��B<br>
 * ���ɍĐ�ID���ݒ�ς݂̏�ԂŖ{�֐����Ăяo�����ꍇ�́A�Ď��Đ�ID��񂪏㏑������܂��B<br>
 * �Ď����s�����߂ɂ�::criAtomEx_SetMonitoringVoiceStopCallback �֐��Œʒm���s�����߂̃R�[���o�b�N�֐���o�^���Ă��������B<br>
 * \sa criAtomEx_SetMonitoringVoiceStopCallback
 */
void CRIAPI criAtomEx_SetMonitoringVoiceStopPlaybackId(CriAtomExPlaybackId playback_id);


/*==========================================================================
 *      CRI AtomEx Sound Object API
 *=========================================================================*/
/*JP
 * \brief �T�E���h�I�u�W�F�N�g�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	config		�T�E���h�I�u�W�F�N�g�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �T�E���h�I�u�W�F�N�g���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * �A���P�[�^�[��o�^�����ɃT�E���h�I�u�W�F�N�g���쐬����ꍇ�A
 * ���炩���ߖ{�֐��Ōv�Z�������[�N�̈�T�C�Y���̃�������
 * ���[�N�̈�Ƃ��� ::criAtomExSoundObject_Create �֐��ɃZ�b�g����K�v������܂��B<br>
 * <br>
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomExSoundObjectConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExSoundObject_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���[�N�̈�T�C�Y�v�Z���Ɏ��s�����ꍇ�A�߂�l�� -1 �ɂȂ�܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N��
 * ���b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomExSoundObjectConfig, criAtomExSoundObject_Create
 */
CriSint32 CRIAPI criAtomExSoundObject_CalculateWorkSize(
	const CriAtomExSoundObjectConfig *config);

/*JP
 * \brief �T�E���h�I�u�W�F�N�g�̍쐬
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	config		�T�E���h�I�u�W�F�N�g�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomExSoundObjectHn	�T�E���h�I�u�W�F�N�g�n���h��
 * \par ����:
 * �T�E���h�I�u�W�F�N�g���쐬���܂��B<br>
 * \sa CriAtomExSoundObjectConfig, criAtomExSoundObject_CalculateWorkSize,
 * CriAtomExSoundObjectHn, criAtomExSoundObject_Destroy
 */
CriAtomExSoundObjectHn CRIAPI criAtomExSoundObject_Create(
	const CriAtomExSoundObjectConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �T�E���h�I�u�W�F�N�g�̔j��
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	sound_object	�T�E���h�I�u�W�F�N�g
 * \par ����:
 * �T�E���h�I�u�W�F�N�g��j�����܂��B<br>
 * �{�֐������s�������_�ŁA�T�E���h�I�u�W�F�N�g�쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵���T�E���h�I�u�W�F�N�g�n���h���������ɂȂ�܂��B<br>
 * \sa criAtomExSoundObject_Create, CriAtomExSoundObjectHn
 */
void CRIAPI criAtomExSoundObject_Destroy(CriAtomExSoundObjectHn sound_object);

/*JP
 * \brief AtomEx�v���[���[�̒ǉ�
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	sound_object	�T�E���h�I�u�W�F�N�g
 * \param[in]	player			AtomEx�v���[���[
 * \par ����:
 * �T�E���h�I�u�W�F�N�g��AtomEx�v���[���[��ǉ����܂��B<br>
 * �ǉ�����AtomEx�v���[���[�̓T�E���h�I�u�W�F�N�g�Ɗ֘A�t�����A
 * �T�E���h�I�u�W�F�N�g�ɂ��ȉ��̉e�����󂯂�悤�ɂȂ�܂��B<br>
 * - ������������C�x���g�@�\���e������͈́i�X�R�[�v�j�̌���
 * - �Đ��R���g���[���i��~�A�|�[�Y���j
 * - �p�����[�^�[�R���g���[��
 * 
 * �ǉ�����AtomEx�v���[���[���T�E���h�I�u�W�F�N�g����폜����ꍇ�́A ::criAtomExSoundObject_DeletePlayer
 * �֐����Ăяo���Ă��������B<br>
 * �Ώۂ�AtomEx�v���[���[�����ɃT�E���h�I�u�W�F�N�g�ɒǉ��ς݂̏ꍇ�́A�����N����܂���B<br>
 * \attention
 * �{�֐��̌Ăяo���́A�ǉ����悤�Ƃ��Ă���AtomEx�v���[���[�ŉ������Đ����Ă��Ȃ���Ԃōs���Ă��������B<br>
 * �X�e�[�^�X�� ::CRIATOMEXPLAYER_STATUS_STOP �ł͂Ȃ�AtomEx�v���[���[���w�肳�ꂽ�ꍇ�A
 * �ǉ����� ::criAtomExPlayer_StopWithoutReleaseTime �֐��ɂčĐ���~���s���܂��B
 * \sa criAtomExSoundObject_DeletePlayer, criAtomExSoundObject_DeleteAllPlayers
 */
void CRIAPI criAtomExSoundObject_AddPlayer(CriAtomExSoundObjectHn sound_object, CriAtomExPlayerHn player);

/*JP
 * \brief AtomEx�v���[���[�̍폜
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	sound_object	�T�E���h�I�u�W�F�N�g
 * \param[in]	player			AtomEx�v���[���[
 * \par ����:
 * �T�E���h�I�u�W�F�N�g����AtomEx�v���[���[���폜���܂��B<br>
 * �폜����AtomEx�v���[���[�̓T�E���h�I�u�W�F�N�g�Ƃ̊֘A�t�����؂��A
 * �T�E���h�I�u�W�F�N�g�ɂ��e�����󂯂Ȃ��Ȃ�܂��B<br>
 * \attention
 * �{�֐��̌Ăяo���́A�폜���悤�Ƃ��Ă���AtomEx�v���[���[�ŉ������Đ����Ă��Ȃ���Ԃōs���Ă��������B<br>
 * �X�e�[�^�X�� ::CRIATOMEXPLAYER_STATUS_STOP �ł͂Ȃ�AtomEx�v���[���[���w�肳�ꂽ�ꍇ�A
 * �폜���� ::criAtomExPlayer_StopWithoutReleaseTime �֐��ɂčĐ���~���s���܂��B
 * \sa criAtomExSoundObject_AddPlayer, criAtomExSoundObject_DeleteAllPlayers
 */
void CRIAPI criAtomExSoundObject_DeletePlayer(CriAtomExSoundObjectHn sound_object, CriAtomExPlayerHn player);

/*JP
 * \brief �S�Ă�AtomEx�v���[���[�̍폜
 * \ingroup ATOMEXLIB_SOUND_OBJECT
 * \param[in]	sound_object	�T�E���h�I�u�W�F�N�g
 * \par ����:
 * �T�E���h�I�u�W�F�N�g�Ɋ֘A�t�����Ă���S�Ă�AtomEx�v���[���[���폜���܂��B<br>
 * �폜����AtomEx�v���[���[�̓T�E���h�I�u�W�F�N�g�Ƃ̊֘A�t�����؂��A
 * �T�E���h�I�u�W�F�N�g�ɂ��e�����󂯂Ȃ��Ȃ�܂��B<br>
 * \attention
 * �{�֐��̌Ăяo���́A�폜���悤�Ƃ��Ă���AtomEx�v���[���[�ŉ������Đ����Ă��Ȃ���Ԃōs���Ă��������B<br>
 * �X�e�[�^�X�� ::CRIATOMEXPLAYER_STATUS_STOP �ł͂Ȃ�AtomEx�v���[���[���܂܂�Ă����ꍇ�A
 * �폜���� ::criAtomExPlayer_StopWithoutReleaseTime �֐��ɂčĐ���~���s���܂��B
 * \sa criAtomExSoundObject_AddPlayer, criAtomExSoundObject_DeletePlayer
 */
void CRIAPI criAtomExSoundObject_DeleteAllPlayers(CriAtomExSoundObjectHn sound_object);

/***************************************************************************
 *      �b��API�i�g�p�͂��T���������j
 *      Tentative API (Please don't use it)
 ***************************************************************************/
/* �ȉ��ɐ錾����Ă���֐���Atom�̓��������p�A�Q�[���G���W���Ƃ̘A�g���ɂ�
 * �b��I�Ɏg�p����Ă���API�ł��B
 * ����̃A�b�v�f�[�g�ɂė\���Ȃ��ύX�E�폜���s���邽�߁A�g�p�͂��T���������B
 */
typedef void (CRIAPI *CriAtomExAcbReleasedCbFunc)(void *obj);
void CRIAPI criAtomExAcb_ReleaseAsync(
	CriAtomExAcbHn acb_hn, CriAtomExAcbReleasedCbFunc func, void *obj);
CriBool CRIAPI criAtomExPlayer_IsReadyToStartAsync(CriAtomExPlayerHn player);
CriBool CRIAPI criAtomExPlayer_StartAsync(CriAtomExPlayerHn player);
void CRIAPI criAtomExPlayer_UpdateAllAsync(CriAtomExPlayerHn player);
CriSint64 CRIAPI criAtomExPlayer_GetTimeReal(CriAtomExPlayerHn player);
CriSint64 CRIAPI criAtomExPlayback_GetTimeReal(CriAtomExPlaybackId id);
void CRIAPI criAtomExPlayback_EnumerateAtomPlayers(
	CriAtomExPlaybackId id, CriAtomPlayerCbFunc func, void* obj);
void CRIAPI criAtomEx3dListener_GetFocusPoint(CriAtomEx3dListenerHn ex_3d_listener, CriAtomExVector *focus_point);
CriFloat32 CRIAPI criAtomEx3dListener_GetDistanceFocusLevel(CriAtomEx3dListenerHn ex_3d_listener);
CriFloat32 CRIAPI criAtomEx3dListener_GetDirectionFocusLevel(CriAtomEx3dListenerHn ex_3d_listener);
CriAtomExAcbHn CRIAPI criAtomExAcb_GetCurrentAcb(void);
CriBool CRIAPI criAtomExAcb_IsParameterPalletAssignedByName(CriAtomExAcbHn acb_hn, const CriChar8 *cue_name);
void CRIAPI criAtomEx3dSource_SetAttenuationDistanceSetting(CriAtomEx3dSourceHn ex_3d_source, CriBool sw);
CriBool CRIAPI criAtomEx3dSource_GetAttenuationDistanceSetting(const CriAtomEx3dSourceHn ex_3d_source);
CriBool CRIAPI criAtomExAcb_IsCompatibleWithAcf(CriAtomExAcbHn acb_hn);

#ifdef __cplusplus
}
#endif


#define criAtomExPlayer_SetAisacById(player, control_id, control_value) \
	criAtomExPlayer_SetAisacControlById(player, control_id, control_value)
#define criAtomExPlayer_SetAisacByName(player, control_name, control_value) \
	criAtomExPlayer_SetAisacControlByName(player, control_name, control_value)
#define criAtomExPlayer_GetAisacById(player, control_id) \
	criAtomExPlayer_GetAisacControlById(player, control_id)
#define criAtomExPlayer_GetAisacByName(player, control_name) \
	criAtomExPlayer_GetAisacControlByName(player,control_name)
#define criAtomExPlayback_GetAisacById(playback_id, control_id, control_value) \
	criAtomExPlayback_GetAisacControlById(playback_id, control_id, control_value)
#define criAtomExPlayback_GetAisacByName(playback_id, control_name, control_value) \
	criAtomExPlayback_GetAisacControlByName(playback_id, control_name, control_value)
#define criAtomExCategory_SetAisacById(id, control_id, control_value) \
	criAtomExCategory_SetAisacControlById(id, control_id, control_value)
#define criAtomExCategory_SetAisacByName(name, control_name, control_value) \
	criAtomExCategory_SetAisacControlByName(name, control_name, control_value)
#define criAtomEx3dSource_SetListenerBasedAngleAisacControlId(ex_3d_source, aisac_control_id) \
	criAtomEx3dSource_SetListenerBasedAzimuthAngleAisacControlId((ex_3d_source), (aisac_control_id))
#define criAtomEx3dSource_SetSourceBasedAngleAisacControlId(ex_3d_source, aisac_control_id) \
	criAtomEx3dSource_SetSourceBasedAzimuthAngleAisacControlId((ex_3d_source), (aisac_control_id))
/* �����_���[�̏o��Ch���ݒ�ɉ����āA�����Ń_�E���~�b�N�X���邽�߉��L�֐��͖����ɂ��Ă��܂� */

#define CRIATOMEX_VERSION					(0xFFFFFFFF)

#ifdef __cplusplus
extern "C" {
#endif
/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 */

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 */


/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExPlayer_SetBusSendLevelByName �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomExPlayer_SetBusSendLevel(
	CriAtomExPlayerHn player, CriSint32 bus_index, CriFloat32 level);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExPlayer_SetBusSendLevelOffsetByName �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomExPlayer_SetBusSendLevelOffset(
	CriAtomExPlayerHn player, CriSint32 bus_index, CriFloat32 level_offset);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExDebug_GetResourcesInfo �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomEx_GetNumUsedVirtualVoices(CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExDebug_GetResourcesInfo �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomEx_GetNumUsedSequences(CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExDebug_GetResourcesInfo �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomEx_GetNumUsedSequenceTracks(CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExDebug_GetResourcesInfo �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomEx_GetNumUsedSequenceTrackItems(CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomEx3dListener_SetDopplerMultiplier �֐��̎g�p���������Ă��������B
 * �������������Ɏw�肷��l��distance_factor�̋t���ɕύX����K�v������܂��B
 */
void CRIAPI criAtomEx3dListener_SetDistanceFactor(CriAtomEx3dListenerHn ex_3d_listener, CriFloat32 distance_factor);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���Ă����ʂ͂���܂���B
 */
void CRIAPI criAtomEx_GetNumUsedAisacAutoModulations(CriSint32 *cur_num, CriSint32 *limit);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomEx3dSource_SetOrientation �֐��̎g�p���������Ă��������B
 */
void CRIAPI criAtomEx3dSource_SetConeOrientation(CriAtomEx3dSourceHn ex_3d_source, const CriAtomExVector *cone_orient);



/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���Ă����ʂ͂���܂���B
 */
void CRIAPI criAtomExPlayer_SetSequencePrepareTime(
	CriAtomExPlayerHn player, CriUint32 seq_prep_time_ms);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAcf_GetDspFxName �֐��̎g�p���������Ă��������B
 */
CriUint32 CRIAPI criAtomExAcf_GetDspFxType(CriUint16 index);

#ifdef __cplusplus
}
#endif

/*JP
 * \endcond
 */

#endif /* CRI_INCL_CRI_ATOM_EX_H */

/* --- end of file --- */
