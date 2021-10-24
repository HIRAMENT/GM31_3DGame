/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2009-2018 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header
 * File     : cri_atom.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_atom.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef CRI_INCL_CRI_ATOM_H
#define CRI_INCL_CRI_ATOM_H

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include "cri_le_xpt.h"
#include <cri_le_file_system.h>

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/
/* �o�[�W������� */
/* Version Number */
#define CRI_ATOM_VER_NAME		"CRI Atom (LE)"
#define CRI_ATOM_VER_NUM		"2.21.141"
#define CRI_ATOM_VER_MAJOR		(2)
#define CRI_ATOM_VER_MINOR		(21)
#define CRI_ATOM_VER_PATCH		(141)
#define CRI_ATOM_VER_RELEASE	(0)
#define CRI_ATOM_VER_REVISION	(0)

/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
#if defined(XPT_TGT_PSP)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(44100)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(44100)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(1)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(2)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_NATIVE)
#elif defined(XPT_TGT_VITA)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_NATIVE)
#elif defined(XPT_TGT_3DS)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(32728)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(32728)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(2)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_NATIVE)
#elif defined(XPT_TGT_WII)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(32000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(32000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(4)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_NATIVE)
#elif defined(XPT_TGT_WIIU)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(6)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_NATIVE)
#elif defined(XPT_TGT_ANDROID) || defined(XPT_TGT_IOS) || defined(XPT_TGT_IPHONE)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#elif defined(XPT_TGT_NACL)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#elif defined(XPT_TGT_ACRODEA)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(22050)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(22050)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(2)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#elif defined(XPT_TGT_JS)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(2)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(44100)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(44100)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#elif defined(XPT_TGT_XBOXONE) || defined(XPT_TGT_PS4) || defined(XPT_TGT_PS5) || defined(XPT_TGT_SCARLETT)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(8)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#elif defined(XPT_TGT_SWITCH)
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(6)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#else
#define CRIATOM_DEFAULT_OUTPUT_CHANNELS				(6)
#define CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_INPUT_MAX_CHANNELS			(2)
#define CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE		(48000)
#define CRIATOM_DEFAULT_DECODE_LATENCY				(0)
#define CRIATOM_DEFAULT_DBAS_MAX_STREAMS			(8)
#define CRIATOM_SOUND_RENDERER_DEFAULT				(CRIATOM_SOUND_RENDERER_ASR)
#endif

/*==========================================================================
 *      CRI Atom Player API
 *=========================================================================*/
/*JP
 * \brief ���[�v�񐔐���p
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 */
#define CRIATOMPLAYER_NO_LOOP_LIMITATION	(-1)		/*JP<���[�v�񐔐����Ȃ�	*/
#define CRIATOMPLAYER_IGNORE_LOOP			(-2)		/*JP<���[�v���𖳎�	*/
#define CRIATOMPLAYER_FORCE_LOOP			(-3)		/*JP<�������[�v�Đ�		*/

/*==========================================================================
 *      CRI Atom AWB API
 *=========================================================================*/
/*JP
 * \brief �I��������AWB�n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y
 * \ingroup ATOMLIB_AWB
 * \par ����:
 * �I��������AWB�n���h���̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y�ł��B<br>
 * \sa criAtomAwb_LoadFromMemory
 */
#define CRIATOMAWB_WORKSIZE_FOR_LOADFROMMEMORY	(64)

/*==========================================================================
 *      CRI Atom D-BAS API
 *=========================================================================*/
/*JP
 * \brief Atom D-BAS ID
 * \ingroup ATOMLIB_DBAS
 * \par ����:
 * ::criAtomDbas_Create �֐��Ɏ��s�����ۂɕԂ�l�ł��B <br>
 * \sa criAtomDbas_Create, criAtomDbas_Destroy
 */
#define CRIATOMDBAS_ILLEGAL_ID	(-1)

/*JP
 * \brief D-BAS�쐬�p�̃f�t�H���g�������ő�r�b�g���[�g�l
 * \ingroup ATOMLIB_AWB
 * \par ����:
 * D-BAS�쐬�p�̃f�t�H���g�������p�����[�^�[�l��`�ł��B<br>
 * �e�v���b�g�t�H�[���Œ�`���Ă���f�t�H���g�̍ő�X�g���[���{�����A
 * �X�e���IADX�f�[�^���X�g���[�~���O�Đ�����O��Ōv�Z���Ă��܂��B <br>
 * \sa criAtomDbas_Create, criAtomDbas_CalculateWorkSize, criAtom_CalculateAdxBitrate
 */
#define CRIATOM_DEFAULT_DBAS_MAX_BPS \
	(criAtom_CalculateAdxBitrate(CRIATOM_DEFAULT_INPUT_MAX_CHANNELS,\
								 CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE)\
								 * CRIATOM_DEFAULT_DBAS_MAX_STREAMS)

/*JP
 * \brief D-BAS�쐬�p�̃f�t�H���g�̃o�b�t�@�[�ۏؐ�
 * \ingroup ATOMLIB_DBAS
 * \par ����:
 * D-BAS�쐬�p�̃f�t�H���g�̃o�b�t�@�[�ۏؐ��ł��B
 * ���[�v�擪�A����у��[�v�I�[�ŋɒ[�Ƀf�[�^�����Ȃ��Ȃ鉹���f�[�^�ł����Ă�
 * �r�؂�Ȃ��悤�ɃX�g���[�~���O�Đ��\�Ȉ��S�Ȓl��ݒ肵�Ă��܂��B
 * \sa criAtomDbas_Create, criAtomDbas_CalculateWorkSize
 */
#define CRIATOMDBAS_DEFAULT_NUM_SECUREMENT_BUFFERS	(4)

/*JP
 * \brief D-BAS�쐬���Ɏw��\�ȃo�b�t�@�[�ۏؐ��̉����l
 * \ingroup ATOMLIB_DBAS
 * \par ����:
 * D-BAS�쐬���Ɏw��\�ȃo�b�t�@�[�ۏؐ��̉����l�ł��B
 * �r�؂ꂸ�ɃX�g���[�~���O�Đ����邽�߂ɂ́A
 * �Œ�ł�2�o�b�t�@�[�i�_�u���o�b�t�@�����O�j�K�v�Ȃ��߁A
 * 2�����̒l�ɐݒ肷�鎖�͂ł��܂���B
 * \sa criAtomDbas_Create, criAtomDbas_CalculateWorkSize
 */
#define CRIATOMDBAS_MINIMUM_NUM_SECUREMENT_BUFFERS	(2)


/* ========================================================================*/
/*       CRI Atom Streaming Cache API                                      */
/* ========================================================================*/
/*JP
 * \brief �s���ȃX�g���[�~���O�L���b�V��ID�l
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \par ����:
 * ::criAtomStreamingCache_Create �֐��Ɏ��s�����ۂɕԂ�l�ł��B <br>
 * \sa criAtomStreamingCache_Create, criAtomStreamingCache_Destroy
 */
#define CRIATOM_STREAMING_CACHE_ILLEGAL_ID	(0)

/*JP
 * \brief �X�g���[�~���O�L���b�V���ɃL���b�V������t�@�C�����̃f�t�H���g�l
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \par ����:
 * �X�g���[�~���O�L���b�V���쐬�p�̃f�t�H���g�������p�����[�^�[�l��`�ł��B<br>
 * �L���b�V���\�ȃt�@�C�������w�肵�܂��B<br>
 * �f�t�H���g�l��10�t�@�C�����ł��B<br>
 * \sa CriAtomStreamingCacheConfig
 */
#define CRIATOM_STREAMING_CACHE_DEFAULT_NUM_FILES	(10)

/*JP
 * \brief �X�g���[�~���O�L���b�V���ɃL���b�V������t�@�C���T�C�Y�̃f�t�H���g�l
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \par ����:
 * �X�g���[�~���O�L���b�V���쐬�p�̃f�t�H���g�������p�����[�^�[�l��`�ł��B<br>
 * �L���b�V���\�ȃt�@�C���T�C�Y�� byte�P�ʂŎw�肵�܂��B<br>
 * �f�t�H���g�l�� 1 MB �ł��B<br>
 * \sa CriAtomStreamingCacheConfig
 */
#define CRIATOM_STREAMING_CACHE_DEFAULT_CACHE_SIZE	(1 * 1024 * 1024)

/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief CriAtomConfig�ւ̃f�t�H���g�p�����[�^�[���Z�b�g
 * \ingroup ATOMLIB_GLOBAL
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtom_Initialize �֐��ɐݒ肷��R���t�B�O�\���́i ::CriAtomConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa
 * CriAtomConfig
*/
#define criAtom_SetDefaultConfig(p_config)	\
{\
	(p_config)->thread_model = CRIATOM_THREAD_MODEL_MULTI;\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->fs_config = NULL;\
	(p_config)->context = NULL;\
	(p_config)->version = CRI_ATOM_VERSION;\
	(p_config)->version_string = CRI_ATOM_VER_NUM;\
	(p_config)->max_players = 16;\
}

/*JP
 * \brief ���[�U�A���P�[�^�[�̓o�^
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	p_malloc_func	�������m�ۊ֐�
 * \param[in]	p_free_func		����������֐�
 * \param[in]	p_obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom ���C�u�����Ƀ������A���P�[�^�[�i�������̊m�ہ^����֐��j��o�^���܂��B<br>
 * �{�}�N���ŃA���P�[�^�[��o�^����ƁAAtom���C�u���������[�N�̈��K�v�Ƃ���^�C�~���O�ŁA
 * ���[�U���o�^�����������m�ہ^����������Ăяo����邱�ƂɂȂ�܂��B<br>
 * ���̌��ʁA���[�N�̈��K�v�Ƃ���֐��i ::criAtomPlayer_CreateAdxPlayer �֐����j�ɑ΂��A
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
 * �{�}�N���͓����I�� ::criAtom_SetUserMallocFunction �֐���
 * ::criAtom_SetUserFreeFunction �֐����Ăяo���܂��B<br>
 * �{�֐��Ƃ����� API �𕹗p���Ȃ��悤�����ӂ��������B<br>
 * �i�{�֐��̌Ăяo���ɂ��A��L API �ɃZ�b�g�������e���㏑������܂��B�j<br>
 * <br>
 * �܂��A�o�^���ꂽ�������A���P�[�^�[�֐��̓}���X���b�h���[�h���ɕ����̃X���b�h����R�[��
 * ����邱�Ƃ�����܂��B�]���āA�������A���P�[�g�������X���b�h�Z�[�t�łȂ��ꍇ�͓Ǝ���
 * �������A���P�[�g������r�����䂷��K�v������܂��B
 */
#define criAtom_SetUserAllocator(p_malloc_func, p_free_func, p_obj)	\
{\
	criAtom_SetUserMallocFunction(p_malloc_func, p_obj);\
	criAtom_SetUserFreeFunction(p_free_func, p_obj);\
}

/*==========================================================================
 *      CRI Atom HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_HCA_MX
 * \par ����:
 * ::criAtomHcaMx_Initialize �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomHcaMxConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomHcaMx_Initialize, CriAtomHcaMxConfig
 */
#define criAtomHcaMx_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->num_mixers = 1;\
	(p_config)->max_players = 16;\
	(p_config)->max_input_channels = CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
}

/*==========================================================================
 *      CRI Atom Player API
 *=========================================================================*/
/*JP
 * \brief CriAtomStandardPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	�W���v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateStandardPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomStandardPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomStandardPlayerConfig, criAtomPlayer_CreateStandardPlayer
 */
#define criAtomPlayer_SetDefaultConfigForStandardPlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomAdxPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	ADX�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateAdxPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomAdxPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer
 */
#define criAtomPlayer_SetDefaultConfigForAdxPlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomHcaPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	HCA�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateHcaPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomHcaPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomHcaPlayerConfig, criAtomPlayer_CreateHcaPlayer
 */
#define criAtomPlayer_SetDefaultConfigForHcaPlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomHcaMxPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	HCA-MX�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateHcaMxPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomHcaMxPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomHcaMxPlayerConfig, criAtomPlayer_CreateHcaMxPlayer
 */
#define criAtomPlayer_SetDefaultConfigForHcaMxPlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
}

/*JP
 * \brief CriAtomWavePlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	WAVE�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateWavePlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomWavePlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomWavePlayerConfig, criAtomPlayer_CreateWavePlayer
 */
#define criAtomPlayer_SetDefaultConfigForWavePlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomAiffPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	AIFF�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateAiffPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomAiffPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomAiffPlayerConfig, criAtomPlayer_CreateAiffPlayer
 */
#define criAtomPlayer_SetDefaultConfigForAiffPlayer(p_config)	\
{\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->streaming_flag		= CRI_FALSE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomRawPcmPlayerConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	RawPCM�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateRawPcmPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomRawPcmPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomRawPcmPlayerConfig, criAtomPlayer_CreateRawPcmPlayer
 */
#define criAtomPlayer_SetDefaultConfigForRawPcmPlayer(p_config)	\
{\
	(p_config)->pcm_format			= CRIATOM_PCM_FORMAT_SINT16;\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_DEFAULT;\
	(p_config)->decode_latency		= CRIATOM_DEFAULT_DECODE_LATENCY;\
	(p_config)->context				= NULL;\
}

/*JP
 * \brief CriAtomInstrumentPlayerConfig�փf�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[out]	p_config	�C���X�g�D�������g�v���[���[�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomPlayer_CreateRawPcmPlayer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomRawPcmPlayerConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa criAtomExVoicePool_AllocateInstrumentVoicePool
 */
#define criAtomPlayer_SetDefaultConfigForInstrumentPlayer(p_config)	\
{\
	(p_config)->interface_name		= "";\
	(p_config)->instrument_name		= "";\
	(p_config)->max_channels		= CRIATOM_DEFAULT_INPUT_MAX_CHANNELS;\
	(p_config)->max_sampling_rate	= CRIATOM_DEFAULT_INPUT_MAX_SAMPLING_RATE;\
	(p_config)->sound_renderer_type = CRIATOM_SOUND_RENDERER_DEFAULT;\
}

/*==========================================================================
 *      CRI Atom D-BAS API
 *=========================================================================*/
/*JP
 * \brief CriAtomDbasConfig �ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_DBAS
 * \param[out]	p_config	D-BAS�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomDbas_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomDbasConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomDbasConfig, criAtomDbas_Create, criAtomDbas_CalculateWorkSize
 */
#define criAtomDbas_SetDefaultConfig(p_config)	\
{\
	(p_config)->identifier	= 0;\
	(p_config)->max_streams	= CRIATOM_DEFAULT_DBAS_MAX_STREAMS;\
	(p_config)->max_bps		= CRIATOM_DEFAULT_DBAS_MAX_BPS;\
	(p_config)->max_mana_streams	= 0;\
	(p_config)->max_mana_bps		= 0;\
	(p_config)->num_securement_buffers = CRIATOMDBAS_DEFAULT_NUM_SECUREMENT_BUFFERS;\
}

/* ========================================================================*/
/*       CRI Atom Streaming Cache API                                      */
/* ========================================================================*/
/*JP
 * \brief CriAtomStreamingCacheConfig�ւ̃f�t�H���g�p�����[�^�[�̃Z�b�g
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \param[out]	p_config	�X�g���[�~���O�L���b�V���쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomStreamingCache_CalculateWorkSize �֐��A
 * ::criAtomStreamingCache_Create �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomStreamingCacheConfig �j�ɑ΂��A�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomStreamingCache_CalculateWorkSize, criAtomStreamingCache_Create
 */
#define criAtomStreamingCache_SetDefaultConfig(p_config)	\
{\
	(p_config)->max_files		= CRIATOM_STREAMING_CACHE_DEFAULT_NUM_FILES;\
	(p_config)->max_path		= CRIFS_CONFIG_DEFAULT_MAX_PATH;\
	(p_config)->cache_size		= CRIATOM_STREAMING_CACHE_DEFAULT_CACHE_SIZE;\
}

/* ========================================================================*/
/*       CRI Atom Meter API                                                */
/* ========================================================================*/

/*JP
 * \brief ���x�����[�^�[�@�\�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ::criAtomMeter_AttachLevelMeter �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomLevelMeterConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomMeter_AttachLevelMeter, CriAtomLevelMeterConfig
 */
#define criAtomMeter_SetDefaultConfigForLevelMeter(p_config) \
{\
	(p_config)->interval = 50;\
	(p_config)->hold_time = 1000;\
}

/*JP
 * \brief ���E�h�l�X���[�^�[�@�\�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_ASR
 * \par ����:
 * ::criAtomMeter_AttachLoudnessMeter �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomLoudnessMeterConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomMeter_AttachLoudnessMeter, CriAtomLoudnessMeterConfig
 */
#define criAtomMeter_SetDefaultConfigForLoudnessMeter(p_config) \
{\
	(p_config)->short_term_time = 3;\
	(p_config)->integrated_time = 600;\
}

/*JP
 * \brief �g�D���[�s�[�N���[�^�[�@�\�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMLIB_ASR
 * \par ����:
 * ::criAtomMeter_AttachTruePeakMeter �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomTruePeakMeterConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomMeter_AttachTruePeakMeter, CriAtomTruePeakMeterConfig
 */
#define criAtomMeter_SetDefaultConfigForTruePeakMeter(p_config) \
{\
	(p_config)->sample_clipping = CRI_TRUE;\
	(p_config)->interval = 50;\
	(p_config)->hold_time = 1000; \
}

/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/
/*JP
 * \brief �X���b�h���f��
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�������ǂ̂悤�ȃX���b�h���f���œ��삷�邩��\���܂��B<br>
 * ���C�u�������������i ::criAtom_Initialize �֐� �j�� ::CriAtomConfig �\���̂ɂ�
 * �w�肵�܂��B
 * \sa criAtom_Initialize, CriAtomConfig
 */
typedef enum CriAtomThreadModelTag {
	/*JP
	 * \brief �}���`�X���b�h
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criAtom_Initialize �֐��Ăяo�����ɍ쐬����܂��B<br>
	 * ���C�u�����̃T�[�o�[�����́A�쐬���ꂽ�X���b�h��Œ���I�Ɏ��s����܂��B<br>
	 */
	CRIATOM_THREAD_MODEL_MULTI = 0,
	
	/*JP
	 * \brief �}���`�X���b�h�i���[�U�쓮���j
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criAtom_Initialize �֐��Ăяo�����ɍ쐬����܂��B<br>
	 * �T�[�o�[�������͍̂쐬���ꂽ�X���b�h��Ŏ��s����܂����A
	 * CRIATOM_THREAD_MODEL_MULTI �Ƃ͈قȂ�A�����I�ɂ͎��s����܂���B<br>
	 * ���[�U�� ::criAtom_ExecuteMain �֐��Ŗ����I�ɃT�[�o�[�������쓮����K�v������܂��B<br>
	 * �i  ::criAtom_ExecuteMain �֐������s����ƁA�X���b�h���N�����A�T�[�o�[���������s����܂��B�j<br>
	 */
	CRIATOM_THREAD_MODEL_MULTI_USER_DRIVEN = 3,
	
	/*JP
	 * \brief ���[�U�}���`�X���b�h
	 * \par ����:
	 * ���C�u���������ł̓X���b�h���쐬���܂��񂪁A���[�U���Ǝ��ɍ쐬�����X���b�h
	 * ����T�[�o�[�����֐����Ăяo����悤�A�����̔r������͍s���܂��B<br>
	 * �T�[�o�[������ ::criAtom_ExecuteMain �֐����œ������s����܂��B<br>
	 */
	CRIATOM_THREAD_MODEL_USER_MULTI = 1,
	
	/*JP
	 * \brief �V���O���X���b�h
	 * \par ����:
	 * ���C�u���������ŃX���b�h���쐬���܂���B�܂��A�����̔r��������s���܂���B<br>
	 * �T�[�o�[������ ::criAtom_ExecuteMain �֐����œ������s����܂��B<br>
	 * \attention
	 * ���̃��f����I�������ꍇ�A�eAPI�ƃT�[�o�[�����֐��Ƃ𓯈�X���b�h����Ăяo���悤�ɂ��Ă��������B<br>
	 */
	CRIATOM_THREAD_MODEL_SINGLE = 2,
	
	/* enum size is 4bytes */
	CRIATOM_THREAD_MODEL_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomThreadModel;

/*JP
 * \brief ���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtom_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * CRI Atom���C�u�����́A���������ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA�������\�[�X��
 * �K�v�Ȃ����m�ۂ��܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ�����
 * �ω����܂��B
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtom_SetDefaultConfig �}�N���ō\���̂Ƀf�t�H���g
 * �p�����[�^�[���Z�b�g������A ::criAtom_Initialize �֐��ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A
 * ::criAtom_SetDefaultConfig �}�N���ŕK���\���̂����������Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtom_Initialize, criAtom_SetDefaultConfig
 */
typedef struct CriAtomConfigTag {
	/*JP
		\brief �X���b�h���f��
		\par ����:
		CRI Atom���C�u�����̃X���b�h���f�����w�肵�܂��B<br>
		\sa CriAtomThreadModel
	*/
	CriAtomThreadModel thread_model;

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
		�X���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI �̏ꍇ�A�T�[�o�[������CRI Atom���C�u����
		���쐬����X���b�h�ŁA����I�Ɏ��s����܂��B<br>
		�X���b�h���f���� ::CRIATOM_THREAD_MODEL_SINGLE �� ::CRIATOM_THREAD_MODEL_USER_MULTI
		�̏ꍇ�A�T�[�o�[������ ::criAtom_ExecuteMain �֐����Ŏ��s����܂��B<br>
		<br>
		server_frequency �ɂ́A�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		�X���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI �̏ꍇ�ACRI Atom���C�u�����͎w�肳�ꂽ
		�p�x�ŃT�[�o�[���������s�����悤�A�T�[�o�[�����̌Ăяo���Ԋu�𒲐߂��܂��B<br>
		�X���b�h���f���� ::CRIATOM_THREAD_MODEL_SINGLE �� ::CRIATOM_THREAD_MODEL_USER_MULTI
		�̏ꍇ�A���[�U�� ::criAtom_ExecuteMain �֐��� server_frequency �Ŏw�肵���p�x�ȏ�
		�Ŏ��s����K�v������܂��B<br>
		<br>
		�A�v���P�[�V�����̃t���[�����[�g�̕ϓ����傫���A�T�[�o�[���������s����p�x�Ƀo���c�L
		���ł��Ă��܂��ꍇ�ɂ́A�ň��̃t���[�����[�g��z�肵�� server_frequency �̒l���w��
		���邩�A�܂��̓X���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI ���w�肵�Ă��������B
		\par ���l:
		�T�[�o�[�����̎��s�p�x�𑽂�����ƁA�P�ʃT�[�o�[����������̏����ʁi�f�R�[�h�ʓ��j
		�����Ȃ��Ȃ�܂��B
		���̌��ʁA�P�ʃT�[�o�[������̏������ׂ͏������Ȃ�܂��i���ׂ����U����܂��j���A
		�T�[�o�[�����̎��s�ɔ����I�[�o�[�w�b�h�͑傫���Ȃ�܂��B<br>
		�i�g�уQ�[���@���ACPU���\�[�X�����Ȃ����ŃT�[�o�[�����̎��s�p�x�𑽂����������ꍇ�A
		�T�[�o�[�����̎��s�ɔ����I�[�o�[�w�b�h�������ł��Ȃ��Ȃ�\��������܂��B�j<br>
		<br>
		�T�[�o�[�����̎��s�p�x�����Ȃ�����ƁA�P�ʃT�[�o�[����������̏����ʂ������Ȃ�܂��B<br>
		�T�[�o�[�����̎��s�ɔ����I�[�o�[�w�b�h�͒ጸ����܂����A�P�ʃT�[�o�[����������̕���
		�������Ȃ邽�߁A�t���[���������̖�肪�������鋰�ꂪ����܂��B<br>
		\attention
		�X���b�h���f���� ::CRIATOM_THREAD_MODEL_SINGLE �� ::CRIATOM_THREAD_MODEL_USER_MULTI
		���w�肵���ɂ�������炸�A ::criAtom_ExecuteMain �֐��� server_frequency ��
		�w�肵���l�ȉ��̕p�x�ł������s����Ȃ������ꍇ�A�Đ����̉����r�؂�铙�̖�肪
		��������\��������܂��̂ŁA�����ӂ��������B<br>
		\sa criAtom_ExecuteMain
	*/
	CriFloat32 server_frequency;

	/*JP
		\brief CRI File System �̏������p�����[�^�[�ւ̃|�C���^
		\par ����:
		CRI File System�̏������p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�f�t�H���g�p�����[�^�[��CRI File System�����������܂��B
		\sa criAtom_Initialize
	*/
	const CriFsConfig *fs_config;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̏������p�����[�^�[�ւ̃|�C���^
		\par ����:
		CRI Atom���C�u�����𓮍삳���邽�߂ɕK�v�ȁA
		�v���b�g�t�H�[���ŗL�̏������p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�f�t�H���g�p�����[�^�[�Ńv���b�g�t�H�[�����ɕK�v�ȏ��������s���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
		\sa criAtom_Initialize
	*/
	void *context;

	/*JP
		\brief ���C�u�����o�[�W�����ԍ�
		\par ����:
		CRI Atom���C�u�����̃o�[�W�����ԍ��ł��B<br>
		::criAtom_SetDefaultConfig �}�N���ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W�����ԍ����ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	CriUint32 version;

	/*JP
		\brief ���C�u�����o�[�W����������
		\par ����:
		CRI Atom���C�u�����̃o�[�W����������ł��B<br>
		::criAtom_SetDefaultConfig �}�N���ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W���������񂪐ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	const CriChar8 *version_string;

	/*JP
		\brief �ő�v���[���[��
		\par ����:
		�A�v���P�[�V�������Ŏg�p����v���[���[�iCriAtomPlayer�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criAtomPlayer_CreateStandardPlayer �֐����g�p���ăv���[���[���쐬����ꍇ�A
		�{�p�����[�^�[�Ɏg�p����v���[���[�̐����w�肷��K�v������܂��B<br>
		<br>
		max_players�ɂ́u�����Ɏg�p����v���[���[�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criAtomPlayer_CreateStandardPlayer �֐��� ::criAtomPlayer_Destroy �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃v���[���[�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�max_players��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃv���[���[��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃv���[���[��S���g�p���Ȃ��ꍇ�ł����Ă��A
		max_players��10���w�肷��K�v������܂��B<br>
		\sa criAtomPlayer_CreateStandardPlayer, criAtomPlayer_Destroy
	*/
	CriSint32 max_players;
} CriAtomConfig;

/*JP
 * \brief �������m�ۊ֐�
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	size	�v���������T�C�Y�i�o�C�g�P�ʁj
 * \return		void*	�m�ۂ����������̃A�h���X�i���s����NULL�j
 * \par ����:
 * �������m�ۊ֐��o�^�p�̃C���^�[�t�F�[�X�ł��B<br>
 * CRI Atom���C�u���������C�u�������ōs���������m�ۏ������A
 * ���[�U�Ǝ��̃������m�ۏ����ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * \par ���l:
 * �R�[���o�b�N�֐������s�����ۂɂ́Asize�ɕK�v�Ƃ���郁�����̃T�C�Y���Z�b�g
 * ����Ă��܂��B<br>
 * �R�[���o�b�N�֐�����size���̃��������m�ۂ��A�m�ۂ����������̃A�h���X��
 * �߂�l�Ƃ��ĕԂ��Ă��������B<br>
 * ���A������ obj �ɂ́A::criAtom_SetUserMallocFunction �֐��œo�^�������[�U�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g�� ::criAtom_SetUserMallocFunction �֐��̈����ɃZ�b�g���Ă����A
 * �{�R�[���o�b�N�֐��̈������o�R���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * �������̊m�ۂɎ��s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ��ꂽ��A�Ăяo�����̊֐���
 * ���s����\��������܂��̂ł����ӂ��������B
 * \sa CriAtomFreeFunc, criAtom_SetUserMallocFunction
 */
typedef void *(CRIAPI *CriAtomMallocFunc)(void *obj, CriUint32 size);

/*JP
 * \brief ����������֐�
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	mem		������郁�����A�h���X
 * \return				�Ȃ�
 * \par ����:
 * ����������֐��o�^�p�̃C���^�[�t�F�[�X�ł��B<br>
 * CRI Atom���C�u�����������C�u�������ōs������������������A
 * ���[�U�Ǝ��̃�������������ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * \par ���l:
 * �R�[���o�b�N�֐������s�����ۂɂ́Amem�ɉ�����ׂ��������̃A�h���X���Z�b�g
 * ����Ă��܂��B<br>
 * �R�[���o�b�N�֐�����mem�̗̈�̃�������������Ă��������B
 * ���A������ obj �ɂ́A::criAtom_SetUserFreeFunction �֐��œo�^�������[�U�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g�� ::criAtom_SetUserFreeFunction �֐��̈����ɃZ�b�g���Ă����A
 * �{�R�[���o�b�N�֐��̈������o�R���ĎQ�Ƃ��Ă��������B<br>
 * \sa CriAtomMallocFunc, criAtom_SetUserFreeFunction
 */
typedef void (CRIAPI *CriAtomFreeFunc)(void *obj, void *mem);

/*JP
 * \brief �I�[�f�B�I�t���[���J�n�R�[���o�b�N�֐�
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \return				�Ȃ�
 * \par ����:
 * �I�[�f�B�I�t���[���̊J�n���Ɏ��s�����R�[���o�b�N�֐��ł��B<br>
 * �I�[�f�B�I�t���[���́ACRI Atom���C�u�������ŃT�[�o�[���������s����^�C�~���O�������܂��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtom_SetAudioFrameStartCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�I�[�f�B�I�t���[���̊J�n���i�T�[�o�[�����J�n���O�j�Ɏ��s����܂��B
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f�����}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_MULTI �j
 * �ɐݒ肵���ꍇ�A�{�R�[���o�b�N�֐���CRI Atom���C�u�������ō쐬���ꂽ�X���b�h����
 * �Ăяo����܂��B<br>
 * ���C�u�������������ɃX���b�h���f�������[�U�}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_USER_MULTI �j�A
 * �܂��̓V���O���X���b�h�i ::CRIATOM_THREAD_MODEL_SINGLE �j�ɐݒ肵���ꍇ�A�{�R�[���o�b�N�֐�
 * ::criAtom_ExecuteMain �֐����ŌĂяo����܂��B<br>
 * <br>
 * ���A������ obj �ɂ́A::criAtom_SetAudioFrameStartCallback �֐��œo�^�������[�U�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * \sa criAtom_SetAudioFrameStartCallback
 */
typedef void (CRIAPI *CriAtomAudioFrameStartCbFunc)(void *obj);

/*JP
 * \brief �I�[�f�B�I�t���[���I���R�[���o�b�N�֐�
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \return				�Ȃ�
 * \par ����:
 * �I�[�f�B�I�t���[���̏I�����Ɏ��s�����R�[���o�b�N�֐��ł��B<br>
 * �I�[�f�B�I�t���[���́ACRI Atom���C�u�������ŃT�[�o�[���������s����^�C�~���O�������܂��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtom_SetAudioFrameEndCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�I�[�f�B�I�t���[���̏I�����i�T�[�o�[�����I������j�Ɏ��s����܂��B<br>
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f�����}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_MULTI �j
 * �ɐݒ肵���ꍇ�A�{�R�[���o�b�N�֐���CRI Atom���C�u�������ō쐬���ꂽ�X���b�h����
 * �Ăяo����܂��B<br>
 * ���C�u�������������ɃX���b�h���f�������[�U�}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_USER_MULTI �j�A
 * �܂��̓V���O���X���b�h�i ::CRIATOM_THREAD_MODEL_SINGLE �j�ɐݒ肵���ꍇ�A�{�R�[���o�b�N�֐�
 * ::criAtom_ExecuteMain �֐����ŌĂяo����܂��B<br>
 * <br>
 * ���A������ obj �ɂ́A::criAtom_SetAudioFrameEndCallback �֐��œo�^�������[�U�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * \sa criAtom_SetAudioFrameEndCallback
 */
typedef void (CRIAPI *CriAtomAudioFrameEndCbFunc)(void *obj);

/*JP
 * \brief �T�E���h�����_���^�C�v
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * Atom�v���[���[�������ō쐬����T�E���h�����_���̎�ʂ��w�肷�邽�߂̃f�[�^�^�ł��B<br>
 * Atom�v���[���[�쐬���ɃR���t�B�O�\���̂̃p�����[�^�[�Ƃ��Ďw�肵�܂��B
 * \attention
 * ::CRIATOM_SOUND_RENDERER_ANY �� ::criAtomExPlayer_SetSoundRendererType �֐��ɑ΂��Ă̂ݎw��\�ł��B<br>
 * �{�C�X�v�[���쐬���ɂ͎g�p�ł��܂���B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer
 */
typedef enum CriAtomSoundRendererTypeTag {
	CRIATOM_SOUND_RENDERER_NATIVE = 1,		/*JP<�v���b�g�t�H�[�����C�u�����֏o��	*/
	CRIATOM_SOUND_RENDERER_ASR = 2,			/*JP<Atom Sound Renderer�֏o��			*/
	CRIATOM_SOUND_RENDERER_EXTENDED = 3,

	CRIATOM_SOUND_RENDERER_HW1 = (0 << 2) | CRIATOM_SOUND_RENDERER_NATIVE,		/*JP<�@��ŗL��`1						*/
	CRIATOM_SOUND_RENDERER_HW2 = (1 << 2) | CRIATOM_SOUND_RENDERER_NATIVE,		/*JP<�@��ŗL��`2						*/
	CRIATOM_SOUND_RENDERER_HW3 = (2 << 2) | CRIATOM_SOUND_RENDERER_NATIVE,		/*JP<�@��ŗL��`3						*/
	CRIATOM_SOUND_RENDERER_HW4 = (3 << 2) | CRIATOM_SOUND_RENDERER_NATIVE,		/*JP<�@��ŗL��`4						*/

	CRIATOM_SOUND_RENDERER_HAPTIC = (0 << 2) | CRIATOM_SOUND_RENDERER_EXTENDED,	/*JP<�U��								*/
	CRIATOM_SOUND_RENDERER_PSEUDO = (1 << 2) | CRIATOM_SOUND_RENDERER_EXTENDED,	/*JP<����								*/
	CRIATOM_SOUND_RENDERER_OBJECT = (2 << 2) | CRIATOM_SOUND_RENDERER_EXTENDED,	/*JP<Object Based Audio					*/

	CRIATOM_SOUND_RENDERER_ANY = 0,			/*JP<�o�͕����𐧌����Ȃ�				*/

	/* enum size is 4bytes */
	CRIATOM_SOUND_RENDERER_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomSoundRendererType;

/*JP
 * \brief �X�s�[�J�[ID
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �������o�͂���X�s�[�J�[���w�肷�邽�߂�ID�ł��B<br>
 * ::criAtomPlayer_SetSendLevel �֐��ŗ��p���܂��B
 * \sa criAtomPlayer_SetSendLevel
 */
typedef enum CriAtomSpeakerIdTag {
	CRIATOM_SPEAKER_FRONT_LEFT = 0,				/*JP<�t�����g���t�g�X�s�[�J�[			*/
	CRIATOM_SPEAKER_FRONT_RIGHT = 1,			/*JP<�t�����g���C�g�X�s�[�J�[			*/
	CRIATOM_SPEAKER_FRONT_CENTER = 2,			/*JP<�t�����g�Z���^�[�X�s�[�J�[			*/
	CRIATOM_SPEAKER_LOW_FREQUENCY = 3,			/*JP<LFE�i���T�u�E�[�n�[�j				*/
	CRIATOM_SPEAKER_SURROUND_LEFT = 4,			/*JP<�T���E���h���t�g�X�s�[�J�[			*/
	CRIATOM_SPEAKER_SURROUND_RIGHT = 5,			/*JP<�T���E���h���C�g�X�s�[�J�[			*/
	CRIATOM_SPEAKER_SURROUND_BACK_LEFT = 6,		/*JP<�T���E���h�o�b�N���t�g�X�s�[�J�[	*/
	CRIATOM_SPEAKER_SURROUND_BACK_RIGHT = 7,	/*JP<�T���E���h�o�b�N���C�g�X�s�[�J�[	*/

	/* enum size is 4bytes */
	CRIATOM_SPEAKER_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomSpeakerId;

/*JP
 * \brief �p�t�H�[�}���X���
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtom_GetPerformanceInfo �֐��ŗ��p���܂��B
 * \sa criAtom_GetPerformanceInfo
 */
typedef struct CriAtomPerformanceInfoTag {
	CriUint32 server_process_count;		/*JP<�T�[�o�[�������s��									*/
	CriUint32 last_server_time;			/*JP<�T�[�o�[�������Ԃ̍ŏI�v���l�i�}�C�N���b�P�ʁj		*/
	CriUint32 max_server_time;			/*JP<�T�[�o�[�������Ԃ̍ő�l�i�}�C�N���b�P�ʁj			*/
	CriUint32 average_server_time;		/*JP<�T�[�o�[�������Ԃ̕��ϒl�i�}�C�N���b�P�ʁj			*/
	CriUint32 last_server_interval;		/*JP<�T�[�o�[�������s�Ԋu�̍ŏI�v���l�i�}�C�N���b�P�ʁj	*/
	CriUint32 max_server_interval;		/*JP<�T�[�o�[�������s�Ԋu�̍ő�l�i�}�C�N���b�P�ʁj		*/
	CriUint32 average_server_interval;	/*JP<�T�[�o�[�������s�Ԋu�̕��ϒl�i�}�C�N���b�P�ʁj		*/
} CriAtomPerformanceInfo;

/*JP
 * \brief �G���R�[�h�i��
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom Encoder, CRI Atom Craft�Őݒ肳���G���R�[�h�i���̃f�[�^�^�ł��B<br>
 * �����f�[�^�̃r�b�g���[�g���v�Z����Ƃ��Ɏg�p���܂��B
 * \sa criAtom_CalculateHcaBitrate, criAtom_CalculateHcaMxBitrate
 */
typedef enum CriAtomEncodeQualityTag {
	CRIATOM_ENCODE_QUALITY_LOWEST = 0,	/*JP<�Œ�i���ݒ�	*/
	CRIATOM_ENCODE_QUALITY_LOW,			/*JP<��i���ݒ�		*/
	CRIATOM_ENCODE_QUALITY_MIDDLE,		/*JP<���i���ݒ�		*/
	CRIATOM_ENCODE_QUALITY_HIGH,		/*JP<���i���ݒ�		*/
	CRIATOM_ENCODE_QUALITY_HIGHEST,		/*JP<�ō��i���ݒ�	*/

	/* enum size is 4bytes */
	CRIATOM_ENCODE_QUALITY_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomEncodeQuality;

/*JP
 * \brief �t�H�[�}�b�g���
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �����f�[�^�̃t�H�[�}�b�g�������f�[�^�^�ł��B<br>
 * �ȉ��̂����ꂩ�̒l�����p�\�ł��B<br>
 * - ::CRIATOM_FORMAT_ADX
 * - ::CRIATOM_FORMAT_HCA
 * - ::CRIATOM_FORMAT_HCA_MX
 * - ::CRIATOM_FORMAT_WAVE
 * - ::CRIATOM_FORMAT_RAW_PCM
 * - ::CRIATOM_FORMAT_AIFF
 * - ::CRIATOM_FORMAT_VIBRATION
 * - ::CRIATOM_FORMAT_AUDIO_BUFFER
 * - ::CRIATOM_FORMAT_HW1
 * - ::CRIATOM_FORMAT_HW2
 * 
 */
typedef CriUint32 CriAtomFormat;
#define CRIATOM_FORMAT_NONE			(0x00000000)		/*JP< �Ȃ�				*/
#define CRIATOM_FORMAT_ADX			(0x00000001)		/*JP< ADX				*/
#define CRIATOM_FORMAT_HCA			(0x00000003)		/*JP< HCA				*/
#define CRIATOM_FORMAT_HCA_MX		(0x00000004)		/*JP< HCA-MX			*/
#define CRIATOM_FORMAT_WAVE			(0x00000005)		/*JP< Wave				*/
#define CRIATOM_FORMAT_RAW_PCM		(0x00000006)		/*JP< Raw PCM			*/
#define CRIATOM_FORMAT_AIFF			(0x00000007)		/*JP< AIFF				*/
#define CRIATOM_FORMAT_VIBRATION	(0x00000008)		/*JP< �U��				*/
#define CRIATOM_FORMAT_AUDIO_BUFFER	(0x00000009)		/*JP< AudioBuffer		*/
#define CRIATOM_FORMAT_INSTRUMENT	(0x0000000C)		/*JP< �C���X�g�D�������g*/
#define CRIATOM_FORMAT_HW1			(0x00010001)		/*JP< �n�[�h�E�F�A�ŗL	*/
#define CRIATOM_FORMAT_HW2			(0x00010002)		/*JP< �n�[�h�E�F�A�ŗL	*/

/*JP
 * \brief �����f�[�^�t�H�[�}�b�g���
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �����f�[�^�̃t�H�[�}�b�g���ł��B<br>
 * ::criAtomPlayer_GetFormatInfo �֐��Ŏg�p���܂��B<br>
 * \sa criAtomPlayer_GetFormatInfo
 */
typedef struct CriAtomFormatInfoTag {
	CriAtomFormat format;				/*JP< �t�H�[�}�b�g���		*/
	CriSint32 sampling_rate;			/*JP< �T���v�����O���g��	*/
	CriSint64 num_samples;				/*JP< ���T���v����			*/
	CriSint64 loop_offset;				/*JP< ���[�v�J�n�T���v��	*/
	CriSint64 loop_length;				/*JP< ���[�v��ԃT���v����	*/
	CriSint32 num_channels;				/*JP< �`�����l����			*/
	CriUint32 reserved[1];				/*JP< �\��̈�				*/
} CriAtomFormatInfo;

/*JP
 * \brief PCM�t�H�[�}�b�g
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * PCM�f�[�^�̌^���ł��B
 * \sa criAtomPlayer_SetFilterCallback
 */
typedef enum CriAtomPcmFormatTag {
	CRIATOM_PCM_FORMAT_SINT16 = 0,
	CRIATOM_PCM_FORMAT_FLOAT32,

	/* enum size is 4bytes */
	CRIATOM_PCM_FORMAT_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomPcmFormat;

/*JP
 * \brief �X�g���[�~���O���
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * ::criAtom_GetStreamingInfo �֐��Ŏ擾�������_�ł̃X�g���[�~���O�̏󋵂ł��B<br>
 * \sa criAtom_GetStreamingInfo
 */
typedef struct CriAtomStreamingInfoTag {
	/*JP
		\brief ���݂̃X�g���[�~���O��
		\par ����:
		�����擾�������_�ł̃X�g���[�~���O���ł��B<br>
		�X�g���[�~���O�Đ��̑����ɔ����A���̒l���ω����܂��B<br>
	*/
	CriSint32	num_streaming;	/*JP< 				*/

	/*JP
		\brief ���݂̃X�g���[�~���O���r�b�g���[�g
		\par ����:
		�����擾�������_�ł̑S�X�g���[�~���O�Đ��̍��v����r�b�g���[�g�ł��B<br>
		�X�g���[�~���O�Đ��̑����ɔ����A���̒l���ω����܂��B<br>
		�P�ʂ� [bps] �ibit / �b�j�ł��B<br>
	*/
	CriFloat32	total_bps;

	/*JP
		\brief ���݂̍ň��Đ��J�n���C�e���V
		\par ����:
		�����擾�������_�ł́A�V�����X�g���[�~���O�Đ��̍Đ��J�n���C�e���V
		�̗\���ň��l�ł��B<br>
		�P�ʂ� [�b] �ł��B<br>
		���̒l�͒x���̍ő�l�ɂ��ė\���������ł���A
		�V�����X�g���[�~���O�Đ�����ɂ��̒l�̎��ԕ������x������킯�ł͂���܂���B<br>
		\attention
		���ۂɂ́A�V�����X�g���[�~���O�Đ����ǉ����ꂽ��A<br>
		�X�g���[���f�[�^�̃r�b�g���[�g���ǂݍ��܂�Ă��琳�m�Ȓx�����Ԃ��Čv�Z����܂��B<br>
	*/
	CriFloat32	worst_latency;
} CriAtomStreamingInfo;

/*JP
 * \brief �p�����[�^�[ID
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * �p�����[�^�[���w�肷�邽�߂�ID�ł��B<br>
 */
typedef enum CriAtomParameterIdTag {
	CRIATOM_PARAMETER_ID_VOLUME					=  0,	/*JP< �{�����[�� */
	CRIATOM_PARAMETER_ID_FREQUENCY_RATIO		=  1,	/*JP< ���g���� */

	/* enum size is 4bytes */
	CRIATOM_PARAMETER_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomParameterId;

/*JP
 * \brief �{�C�X��~���R
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �{�C�X�̒�~���R��\���܂��B
 */
typedef enum CriAtomVoiceStopReasonTag {
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_STOP = 0,					/*JP< EX�v���[���[��~		*/
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_STOPWITHOUTRELEASE,			/*JP< EX�v���[���[��~		*/
	CRIATOM_VOICE_STOP_REASON_PLAYBACK_STOP,						/*JP< �Đ�ID�w���~	*/
	CRIATOM_VOICE_STOP_REASON_PLAYBACK_STOPWITHOUTRELEASE,			/*JP< �Đ�ID�w�葦����~	*/
	CRIATOM_VOICE_STOP_REASON_SOUNDPLAYER_DESTROY,					/*JP< �T�E���h�v���[���[�j��		*/
	CRIATOM_VOICE_STOP_REASON_FADER_STOP,							/*JP< �t�F�[�_�[��~		*/
	CRIATOM_VOICE_STOP_REASON_PLAYER_STOP,							/*JP< �v���[���[��~		*/
	CRIATOM_VOICE_STOP_REASON_AWB_STOP,								/*JP< AWB��~			*/
	CRIATOM_VOICE_STOP_REASON_STREAMING_CACHE_STOP,					/*JP< �X�g���[�~���O�L���b�V����~			*/
	CRIATOM_VOICE_STOP_REASON_PLAYER_FORCE_STOP,					/*JP< �v���[���[��~		*/
	CRIATOM_VOICE_STOP_REASON_PLAYER_DESTROY,						/*JP< �v���[���[�j��		*/
	CRIATOM_VOICE_STOP_REASON_MTPLAYER_STOP,						/*JP< MT�v���[���[�j��		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_POOL_DESTROY,					/*JP< �{�C�X�v�[���j��		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_STEAL_CASE1,					/*JP< �{�C�X�D�����		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_STEAL_CASE2,					/*JP< �{�C�X�D�����		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_STEAL_CASE3,					/*JP< �{�C�X�D�����		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_STEAL_CASE4,					/*JP< �{�C�X�D�����		*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_VIRTUAL_VOICE_BEYOND_LIFE_TIME,	/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_CANT_CALC_3DPOS,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_INTERNAL_PLAYBACK_CANCEL,			/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_NO_PLAYER_NO_RETRY,				/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_FAILED_RETRY_BEYOND_LIFE_TIME,	/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_PLAYER_STATUS_PLAYEND,			/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_PLAYER_STATUS_ERROR,				/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_IMPOSSIBLE_RETRY,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_PLAYER_STATUS_STOP,				/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_INVALID_SERVER_REQUEST,			/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_SILENT_MODE_STOP,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_SOUNDCOMPLEX_STATUS_ERROR,		/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_NO_ELEMENT_CASE1,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_NO_ELEMENT_CASE2,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_STOP_NOT_PLAYING_ELEMENT,			/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_NOT_ACTIVE_VOICE,					/*JP< �T�[�o�[����			*/
	CRIATOM_VOICE_STOP_REASON_ELEMENT_FREE,							/*JP< �G�������g���		*/
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_STOP_ERROR_HN,				/*JP< �G���[�v���[���[�̒�~		*/
	CRIATOM_VOICE_STOP_REASON_ACB_RELEASE,							/*JP< ACB���		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_ALLOCATE_FAIL,					/*JP< �{�C�X�m�ێ��s		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_RESET,							/*JP< �{�C�X���Z�b�g		*/
	CRIATOM_VOICE_STOP_REASON_VOICE_VIRTUALIZE,						/*JP< �{�C�X���o�[�`������		*/
	CRIATOM_VOICE_STOP_REASON_PLAYBACKSOUND_ALLOCATE_FAIL,			/*JP< �v���C�o�b�N�T�E���h�m�ێ��s		*/
	CRIATOM_VOICE_STOP_REASON_STOP_ACTION_WITH_BEATSYNC,			/*JP< �r�[�g������~�A�N�V����		*/
	CRIATOM_VOICE_STOP_REASON_START_CANCEL_WITH_BEATSYNC,			/*JP< �r�[�g�����Đ��L�����Z��		*/
	CRIATOM_VOICE_STOP_REASON_STOP_ACTION,							/*JP< ��~�A�N�V����		*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE0,				/*JP< �u���b�N�J��			*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE1,				/*JP< �u���b�N�J��			*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE2,				/*JP< �u���b�N�J��			*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE3,				/*JP< �u���b�N�J��			*/
	CRIATOM_VOICE_STOP_REASON_CATEGORY_CUE_LIMIT,					/*JP< �J�e�S���L���[���~�b�g		*/
	CRIATOM_VOICE_STOP_REASON_UNSET_ACB,							/*JP< ACB�������		*/
	CRIATOM_VOICE_STOP_REASON_SEQUENCE_END,							/*JP< �V�[�P���X�G���h�}�[�J�[		*/
	CRIATOM_VOICE_STOP_REASON_BLODK_END,							/*JP< �u���b�N�G���h		*/
	CRIATOM_VOICE_STOP_REASON_SEQUENCE_EXECUTE,						/*JP< �V�[�P���X�T�[�o�[����	*/
	CRIATOM_VOICE_STOP_REASON_TRACK_MONO,							/*JP< �g���b�N���m���[�h����	*/
	CRIATOM_VOICE_STOP_REASON_FADER_STOP_IMMEDIATE,					/*JP< �t�F�[�_�[������~	*/
	CRIATOM_VOICE_STOP_REASON_CUE_LIMIT,							/*JP< �L���[���~�b�g����	*/
	CRIATOM_VOICE_STOP_REASON_STOP_ACB,								/*JP< �SACB��~����	*/
	CRIATOM_VOICE_STOP_REASON_SOUND_OBJECT_ADD_PLAYER,				/*JP< �T�E���h�I�u�W�F�N�g�ւ̃v���[���[�ǉ�����	*/
	CRIATOM_VOICE_STOP_REASON_SOUND_OBJECT_DELETE_PLAYER,			/*JP< �T�E���h�I�u�W�F�N�g����v���[���[�̍폜����	*/
	CRIATOM_VOICE_STOP_REASON_SOUND_OBJECT_DELETE_ALL_PLAYER,		/*JP< �T�E���h�I�u�W�F�N�g����v���[���[�̍폜����	*/
	CRIATOM_VOICE_STOP_REASON_UNREGISTER_ACF,						/*JP< ACF�̃A�����W�X�g����	*/
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_DESTROY,						/*JP< CriAtomExPlayer�n���h���̔j��	*/
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_ATTACH_FADER,				/*JP< CriAtomExPlayer�ւ̃t�F�[�_�[�t��	*/
	CRIATOM_VOICE_STOP_REASON_EXPLAYER_DETACH_FADER,				/*JP< CriAtomExPlayer�ւ̃t�F�[�_�[���O��	*/
	CRIATOM_VOICE_STOP_REASON_DETACH_AWB,							/*JP< AWB�������	*/
	CRIATOM_VOICE_STOP_MULTIPLE_PLAYBACK_PROHIBITION_TIME,			/*JP< ���d�Đ��֎~���ԓ��Đ�	*/
	CRIATOM_VOICE_STOP_REASON_CATEGORY_STOP,						/*JP< �J�e�S����~	*/
	CRIATOM_VOICE_STOP_REASON_CATEGORY_STOPWITHOUTRELEASE,			/*JP< �J�e�S��������~	*/
	CRIATOM_VOICE_STOP_REASON_NOTE_OFF,								/*JP< �^�C�����C����~		*/
	CRIATOM_VOICE_STOP_REASON_REGISTER_ACF,							/*JP< ACF�̓o�^���� */
	CRIATOM_VOICE_STOP_REASON_STOP_ACTION_WITH_FADE,				/*JP< �t�F�[�h�t����~�A�N�V����		*/
	CRIATOM_VOICE_STOP_REASON_RESET_TRACK_PARAMETER,				/*JP< �g���b�N�p�����[�^�[�̃��Z�b�g		*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE4,				/*JP< �u���b�N�J��		*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE5,				/*JP< �u���b�N�J��		*/
	CRIATOM_VOICE_STOP_REASON_BLOCK_TRANSITION_CASE6,				/*JP< �u���b�N�J��		*/
	CRIATOM_VOICE_STOP_REASON_NOTE_OFF2,							/*JP< �m�[�g��~		*/
	CRIATOM_VOICE_STOP_REASON_ALL_NOTE_OFF,							/*JP< �S�m�[�g��~		*/
	CRIATOM_VOICE_STOP_REASON_ALL_NOTE_OFF_WITHOUTRELEASE,			/*JP< �S�m�[�g��~		*/
	CRIATOM_VOICE_STOP_REASON_SOUND_SERVER_RESULT_ENVELOPE_LEVEL_ZERO,			/*JP< �T�[�o�[����			*/

	/* initial state */
	CRIATOM_VOICE_STOP_REASON_NONE = 0x7FFFFFFE,
	/* enum size is 4bytes */
	CRIATOM_VOICE_STOP_REASON_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomVoiceStopReason;

 /*JP
  * \brief Ambisonics�w��^�C�v
  * \ingroup ATOMEXLIB_ASR
  * \par ����:
  * Atom���C�u�������Đ��Ɏg�p����Ambisonics�̃I�[�_�[�^�C�v��\���܂��B<br>
  * ASR���������i ::criAtomExAsr_Initialize �֐� �j�� ::CriAtomExAsrConfig 
  * �\���̂ɂĎw�肵�܂��B
  * \sa criAtomExAsr_Initialize, CriAtomExAsrConfig
  */
typedef enum CriAtomAmbisonicsOrderTypeTag {
	CRIATOMAMBISONICS_ORDER_TYPE_NONE = 0,	/*JP< ���ݒ� */
	CRIATOMAMBISONICS_ORDER_TYPE_FIRST,		/*JP< 1st Order */
	CRIATOMAMBISONICS_ORDER_TYPE_1P = CRIATOMAMBISONICS_ORDER_TYPE_FIRST,	/*JP< 1 Periphonic(1st Order�Ɠ��`) */
	CRIATOMAMBISONICS_ORDER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomAmbisonicsOrderType;

/*==========================================================================
 *      CRI Atom HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������p�R���t�B�O�\����
 * \ingroup ATOMLIB_HCA_MX
 * HCA-MX�̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomHcaMx_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomHcaMx_SetDefaultConfig �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomHcaMx_Initialize �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomHcaMx_SetDefaultConfig
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomHcaMx_Initialize, criAtomHcaMx_SetDefaultConfig
 */
typedef struct CriAtomHcaMxConfigTag {
	/*JP
		\brief �T�[�o�[�����̎��s�p�x
		\par ����:
		�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		\attention
		Atom���C�u�������������Ɏw�肵���l�i ::CriAtomConfig �\���̂�
		server_frequency �j�ƁA�����l���Z�b�g����K�v������܂��B<br>
		\sa CriAtomConfig
	*/
	CriFloat32 server_frequency;

	/*JP
		\brief �~�L�T��
		\par ����:
		HCA-MX�f�R�[�h���ʂ𑗐M����~�L�T�̐����w�肵�܂��B<br>
		�~�L�T�𕡐��쐬���邱�ƂŁA
		�~�L�T���ƂɈقȂ�o�X�G�t�F�N�g��K�p���邱�Ƃ��\�ɂȂ�܂��B<br>
		\attention
		HCA-MX�̃f�R�[�h�����A����ђ���Ԃ̏������ׂ́A
		�~�L�T�̐��ɔ�Ⴕ�ďd���Ȃ�܂��B<br>
	*/
	CriSint32 num_mixers;

	/*JP
		\brief �~�L�T�ɓo�^�\�ȍő�v���[���[��
		\par ����:
		�~�L�T���Ƃɓo�^�\��HCA-MX�v���[���[�̐����w�肵�܂��B<br>
	*/
	CriSint32 max_players;

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
		\par ���l:
		�Ⴆ��::criAtomHcaMx_SetFrequencyRatio �֐��� 2.0f ���w�肷��ꍇ��
		output_sampling_rate * 2 ���w�肵�Ă��������B<br>
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
		HCA-MX�́A���P�ʂ̃T���v�����O���[�g�ύX���s���܂���B<br>
		HCA-MX�f�[�^���쐬����ۂɂ́A�K���S�Ẳ����f�[�^�𓯈�̃T���v�����O
		���[�g�ō쐬���A���̒l�� output_sampling_rate �Ɏw�肵�Ă��������B<br>
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
} CriAtomHcaMxConfig;

/*==========================================================================
 *      CRI Atom AWB API
 *=========================================================================*/
struct CriAtomAwbTag;
/*JP
 * \brief AWB�n���h��
 * \ingroup ATOMLIB_AWB
 * \par ����:
 * �Đ��f�[�^���܂܂�Ă���AWB�t�@�C����TOC���������n���h���ł��B<br>
 * ::criAtomAwb_LoadToc �֐��Ŏ擾���܂��B<br>
 * \sa criAtomAwb_LoadToc
 */
typedef struct CriAtomAwbTag *CriAtomAwbHn;

/*JP
 * \brief AWB�X�e�[�^�X
 * \ingroup ATOMLIB_AWB
 * \par ����:
 * AWB�̏�����Ԃ������l�ł��B<br>
 * ::criAtomAwb_GetStatus �֐��Ŏ擾���܂��B<br>
 * \sa criAtomAwb_GetStatus
 */
typedef enum CriAtomAwbStatusTag {
	CRIATOMAWB_STATUS_STOP = 0,		/*JP<��~��		*/
	CRIATOMAWB_STATUS_LOADING,		/*JP<���[�h��	*/
	CRIATOMAWB_STATUS_COMPLETE,		/*JP<���[�h����	*/
	CRIATOMAWB_STATUS_ERROR,		/*JP<���[�h���s	*/

	/* enum size is 4bytes */
	CRIATOMAWB_STATUS_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomAwbStatus;

/*JP
 * \brief AWB�̎��
 * \ingroup ATOMLIB_AWB
 * \par ����:
 * AWB�n���h����TOC���݂̂̃n���h���Ȃ̂��A��������Ƀ��[�h���ꂽAWB�n���h���Ȃ̂��������l�ł��B
 * ::criAtomAwb_GetType �֐��Ŏ擾���܂��B<br>
 * \sa criAtomAwb_GetType
 */
typedef enum CriAtomAwbTypeTag {
	CRIATOMAWB_TYPE_TOC = 0,	/*JP<TOC���݂̂�AWB�n���h��	*/
	CRIATOMAWB_TYPE_ONMEMORY,	/*JP<�I��������AWB�n���h��		*/
	CRIATOMAWB_TYPE_ERROR,		/*JP<������AWB�n���h��			*/

	/* enum size is 4bytes */
	CRIATOMAWB_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomAwbType;

/*==========================================================================
 *      CRI Atom Player API
 *=========================================================================*/
/*JP
 * �W���v���[���[�쐬�p�R���t�B�O�\����
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * �W���v���[���[�iADX��HCA���Đ��\�ȃv���[���[�j���쐬����ۂɁA
 * ����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateStandardPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForStandardPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateStandardPlayer, criAtomPlayer_SetDefaultConfigForStandardPlayer
 */
typedef struct CriAtomStandardPlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateStandardPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		�ő�o�̓`�����l�����Ƃ��Ďw�肷��l�ƁA�쐬���ꂽAtom�v���[���[�ōĐ��\�ȃf�[�^��
		�֌W���ȉ��Ɏ����܂��B<br>
		\table "�ő�o�̓`�����l�����ƍĐ��\�ȃf�[�^�̊֌W" align=center border=1 cellspacing=0 cellpadding=4
		[�ő�o�̓`�����l�����i�w�肷��l�j	| �쐬���ꂽAtom�v���[���[�ōĐ��\�ȃf�[�^	]
		[1									| ���m����									]
		[2									| ���m�����A�X�e���I						]
		[6									| ���m�����A�X�e���I�A5.1ch					]
		[8									| ���m�����A�X�e���I�A5.1ch�A7.1ch			]
		\endtable
		<br>
		\par ���l:
		�T�E���h�o�͎��Ƀn�[�h�E�F�A���\�[�X���g�p����v���b�g�t�H�[���ɂ����ẮA
		�o�̓`�����l���������������邱�ƂŁA�n�[�h�E�F�A���\�[�X�̏����}���邱�Ƃ�
		�\�ł��B<br>
		\attention
		�w�肳�ꂽ�ő�o�̓`�����l�����𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�o�̓`�����l������1�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		�X�e���I�������Đ����邱�Ƃ͂ł��܂���B<br>
		�i���m�����Ƀ_�E���~�b�N�X����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateStandardPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��24000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i�_�E���T���v�����O����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�͊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForAdxPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomStandardPlayerConfig;

/*JP
 * ADX�v���[���[�쐬�p�R���t�B�O�\����
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * ADX���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateAdxPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForAdxPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateAdxPlayer, criAtomPlayer_SetDefaultConfigForAdxPlayer
 */
typedef struct CriAtomAdxPlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateAdxPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		�ő�o�̓`�����l�����Ƃ��Ďw�肷��l�ƁA�쐬���ꂽAtom�v���[���[�ōĐ��\�ȃf�[�^��
		�֌W���ȉ��Ɏ����܂��B<br>
		\table "�ő�o�̓`�����l�����ƍĐ��\�ȃf�[�^�̊֌W" align=center border=1 cellspacing=0 cellpadding=4
		[�ő�o�̓`�����l�����i�w�肷��l�j	| �쐬���ꂽAtom�v���[���[�ōĐ��\�ȃf�[�^	]
		[1									| ���m����									]
		[2									| ���m�����A�X�e���I						]
		[6									| ���m�����A�X�e���I�A5.1ch					]
		[8									| ���m�����A�X�e���I�A5.1ch�A7.1ch			]
		\endtable
		<br>
		\par ���l:
		�T�E���h�o�͎��Ƀn�[�h�E�F�A���\�[�X���g�p����v���b�g�t�H�[���ɂ����ẮA
		�o�̓`�����l���������������邱�ƂŁA�n�[�h�E�F�A���\�[�X�̏����}���邱�Ƃ�
		�\�ł��B<br>
		\attention
		�w�肳�ꂽ�ő�o�̓`�����l�����𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�o�̓`�����l������1�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		�X�e���I�������Đ����邱�Ƃ͂ł��܂���B<br>
		�i���m�����Ƀ_�E���~�b�N�X����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateAdxPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��24000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i�_�E���T���v�����O����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForAdxPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomAdxPlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * HCA�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * HCA���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateHcaPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForHcaPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateHcaPlayer, criAtomPlayer_SetDefaultConfigForHcaPlayer
 */
typedef struct CriAtomHcaPlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateHcaPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateHcaPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��24000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i�_�E���T���v�����O����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForAdxPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomHcaPlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * HCA-MX�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * HCA-MX���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateHcaMxPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForHcaMxPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateHcaMxPlayer, criAtomPlayer_SetDefaultConfigForHcaMxPlayer
 */
typedef struct CriAtomHcaMxPlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateHcaMxPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateHcaMxPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g�ƈ�v���鉹���f�[�^�݂̂��Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�Ɉ�v���Ȃ��f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��48000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�ȊO�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i���[�g�ϊ�����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;
} CriAtomHcaMxPlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * WAVE�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * WAVE���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateWavePlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForWavePlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateWavePlayer, criAtomPlayer_SetDefaultConfigForWavePlayer
 */
typedef struct CriAtomWavePlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateWavePlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateWavePlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��24000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i�_�E���T���v�����O����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForAdxPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomWavePlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * AIFF�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * AIFF���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateAiffPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForAiffPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateAiffPlayer, criAtomPlayer_SetDefaultConfigForAiffPlayer
 */
typedef struct CriAtomAiffPlayerConfigTag {
	/*JP
		\brief �ő�o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateAiffPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_channels�Ŏw�肵��
		�`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
	*/
	CriSint32 max_channels;

	/*JP
		\brief �ő�T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateAiffPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�ő�T���v�����O���[�g�𒴂���f�[�^�́A�Đ����邱�Ƃ͂ł��܂���B<br>
		�Ⴆ�΁A�ő�T���v�����O���[�g��24000�ɐݒ肵���ꍇ�A�쐬���ꂽAtom�v���[���[��
		48000Hz�̉������Đ����邱�Ƃ͂ł��܂���B<br>
		�i�_�E���T���v�����O����ďo�͂���邱�Ƃ͂���܂���B�j
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �X�g���[�~���O�Đ����s�����ǂ���
		\par ����:
		Atom�v���[���[�ŃX�g���[�~���O�Đ��i�t�@�C������̍Đ��j���s�����ǂ������w�肵�܂��B<br>
		streaming_flag��CRI_FALSE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��i ::criAtomPlayer_SetData �֐��Ŏw�肵���������A�h���X�̍Đ��j�݂̂��T�|�[�g
		���܂��B�i�t�@�C������̍Đ��͂ł��܂���B�j<br>
		streaming_flag��CRI_TRUE���w�肵���ꍇ�A�쐬���ꂽAtom�v���[���[�̓I���������̃f�[�^
		�Đ��ɉ����A�t�@�C������̍Đ��i ::criAtomPlayer_SetFile �֐���
		::criAtomPlayer_SetContentId �֐��Ŏw�肳�ꂽ�t�@�C���̍Đ��j���T�|�[�g���܂��B<br>
		\par �⑫:
		streaming_flag��CRI_TRUE�ɂ����ꍇ�AAtom�v���[���[�쐬���Ƀt�@�C���ǂݍ��ݗp�̃��\�[�X
		���m�ۂ���܂��B<br>
		���̂��߁Astreaming_flag��CRI_FALSE�̏ꍇ�ɔ�ׁAAtom�v���[���[�̍쐬�ɕK�v�ȃ�������
		�T�C�Y���傫���Ȃ�܂��B
	*/
	CriBool streaming_flag;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForAdxPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomAiffPlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * RawPCM�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * RawPCM���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomPlayer_CreateRawPcmPlayer �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForRawPcmPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomPlayer_CreateRawPcmPlayer, criAtomPlayer_SetDefaultConfigForRawPcmPlayer
 */
typedef struct CriAtomRawPcmPlayerConfigTag {
	/*JP
		\brief PCM�t�H�[�}�b�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹����PCM�t�H�[�}�b�g���w�肵�܂��B<br>
		\attention
		�w�肳�ꂽ�t�H�[�}�b�g�ȊO��RawPCM�t�H�[�}�b�g�̃f�[�^�͍Đ��ł��܂���B<br>
		�Đ��f�[�^���ǂ�ȃt�H�[�}�b�g�ł����Ă��A�����Ŏw�肳�ꂽ�t�H�[�}�b�g�Ƃ��čĐ�����܂��B<br>
	*/
	CriAtomPcmFormat pcm_format;

	/*JP
		\brief �o�̓`�����l����
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃`�����l�������w�肵�܂��B<br>
		::criAtomPlayer_CreateRawPcmPlayer �֐��ō쐬���ꂽAtom�v���[���[�́A
		max_channels�Ŏw�肵���`�����l����"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		\attention
		�w�肳�ꂽ�`�����l�����ȊO��RawPCM�t�H�[�}�b�g�̃f�[�^�͍Đ��ł��܂���B<br>
		�Đ��f�[�^���ǂ�ȃt�H�[�}�b�g�ł����Ă��A�����Ŏw�肳�ꂽ�`�����l�����Ƃ��čĐ�����܂��B<br>
	*/
	CriSint32 max_channels;

	/*JP
		\brief �T���v�����O���[�g
		\par ����:
		Atom�v���[���[�ōĐ����鉹���̃T���v�����O���[�g���w�肵�܂��B<br>
		::criAtomPlayer_CreateRawPcmPlayer �֐��ō쐬���ꂽAtom�v���[���[�́Amax_sampling_rate�Ŏw�肵��
		�T���v�����O���[�g"�ȉ���"�����f�[�^���Đ��\�ł��B<br>
		<br>
		\par ���l:
		�ő�T���v�����O���[�g�������邱�ƂŁAAtom�v���[���[�쐬���ɕK�v�ƂȂ郏�[�N������
		�̃T�C�Y��}���邱�Ƃ��\�ł��B
		\attention
		�w�肳�ꂽ�T���v�����O���[�g�ƈႤ�f�[�^�͍Đ��ł��܂���B<br>
		�Đ��f�[�^���ǂ�ȃt�H�[�}�b�g�ł����Ă��A�����Ŏw�肳�ꂽ�T���v�����O���[�g�Ƃ��čĐ�����܂��B<br>
	*/
	CriSint32 max_sampling_rate;

	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		Atom�v���[���[���g�p����T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_DEFAULT ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̃T�E���h�����_���ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�A
		�����f�[�^��ASR�iAtom Sound Renderer�j�ɓ]������܂��B<br>
		�iASR�̏o�͐�́AASR���������ɕʓr�w��B�j
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �f�R�[�h�����̃��C�e���V
		\par ����:
		�f�R�[�h�����̃��C�e���V���w�肵�܂��B<br>
		decode_latency �� 0 �ɐݒ肵���ꍇ�A�v���[���[�͉����Đ��J�n����
		�����f�[�^�̃f�R�[�h���\�Ȍ���x���Ȃ��s���܂��B<br>
		�i�I���������Đ����� ::criAtomPlayer_Start �֐������s��A
		�ŏ��̃T�[�o�[�������ōĐ��J�n�ɕK�v�ȗʂ̃f�[�^���f�R�[�h���A
		�����̏o�͂��J�n���܂��B�j<br>
		����ɑ΂� decode_latency �� 1 �ȏ�ɐݒ肵���ꍇ�A
		�Đ��J�n�ɕK�v�ȃf�[�^�̃f�R�[�h���A������̃T�[�o�[�����ɕ������čs���܂��B<br>
		�i�I���������Đ����ł����Ă� ::criAtomPlayer_Start �֐������s��A
		decode_latency �Ɏw�肵���񐔃T�[�o�[���������삷��܂ł͉����̏o�͂��J�n����܂���B�j<br>
		\par ���l:
		Atom�v���[���[�̓T�E���h�o�b�t�@�[���̃f�[�^�c�ʂ����ɁA
		�T�[�o�[����������̉����f�[�^�̃f�R�[�h�ʂ����肵�Ă��܂��B<br>
		�����Đ��J�n�O�̓T�E���h�o�b�t�@�[����̏�Ԃ̂��߁A
		�����Đ����ɔ�ׂđ����̃f�[�^�i�Đ����� 2 �` 4 �{���x�j���f�R�[�h����܂��B<br>
		�v���[���[������̉����f�[�^�̃f�R�[�h�������ׂ͏��������߁A
		�ꉹ�ꉹ�̔����J�n���̏������ׂ����ɂȂ邱�Ƃ͂قƂ�ǂ���܂���B<br>
		�������A�A�v���P�[�V�������� 1V �ɑ�ʂ̔������N�G�X�g�𓯎��ɔ��s�����ꍇ�A
		�S�Ẵv���[���[�̏������ׂ̃s�[�N���������A���ׂ��ڂɌ����đ傫���Ȃ�ꍇ������܂��B<br>
		����������������s���P�[�X�ł́A decode_latency �̒l�𑝂₷���ƂŁA
		�Ǐ��I�ɏ������ׂ������Ȃ�Ǐ��������邱�Ƃ��\�ł��B<br>
		<br>
		decode_latency �̃f�t�H���g�l�́A�قƂ�ǂ̊��� 0 �ɐݒ肳��Ă��܂��B<br>
		�������A�g�уQ�[���@���A�킸���ȕ��וϓ��ł��A�v���P�[�V�����ɑ傫�ȉe�����y�ڂ����ł́A
		�f�t�H���g�l�� 1 �ȏ�ɐݒ肳��Ă���\��������܂��B<br>
		�i���ۂɃZ�b�g�����l�ɂ��Ă� ::criAtomPlayer_SetDefaultConfigForRawPcmPlayer
		�}�N���̓K�p���ʂ��m�F���Ă��������B�j<br>
		<br>
		���� decode_latency �̒l�� 4 �ȏ�̒l���w�肷�邱�Ƃ͂ł��܂���B<br>
		�i decode_latency �� 4 �ȏ�̒l���w�肵���ꍇ�ł��A���C�u�������� 3 �ɕύX����܂��B�j<br>
	*/
	CriSint32 decode_latency;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[�Ńv���[���[���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomRawPcmPlayerConfig;

/*JP
 * \ingroup ATOMLIB_PLAYER
 * �C���X�g�D�������g�v���[���[�쐬�p�R���t�B�O�\����
 * \par ����:
 * �C���X�g�D�������g���Đ��\�ȃv���[���[���쐬����ۂɁA����d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * <br>
 * �쐬�����v���[���[�́A�n���h���쐬���ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA
 * �������\�[�X��K�v�Ȃ����m�ۂ��܂��B<br>
 * �v���[���[���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ����ĕω����܂��B
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomPlayer_SetDefaultConfigForInstrumentPlayer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 */
typedef struct CriAtomInstrumentPlayerConfigTag {
	const CriChar8				*interface_name;			/*JP< �C���^�[�t�F�[�X��					*/
	const CriChar8				*instrument_name;			/*JP< �C���X�g�D�������g��					*/
	CriSint32					max_channels;				/*JP< �ő�`�����l����						*/
	CriSint32					max_sampling_rate;			/*JP< �ő�T���v�����O���[�g				*/
	CriAtomSoundRendererType	sound_renderer_type;		/*JP< �o�͐�̃T�E���h�����_���^�C�v		*/
} CriAtomInstrumentPlayerConfig;

/*JP
 * \brief �Đ��X�e�[�^�X
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * Atom�v���[���[�̍Đ���Ԃ������l�ł��B<br>
 * ::criAtomPlayer_GetStatus �֐��Ŏ擾�\�ł��B
 * <br>
 * �Đ���Ԃ́A�ʏ�ȉ��̏����őJ�ڂ��܂��B<br>
 * -# CRIATOMPLAYER_STATUS_STOP
 * -# CRIATOMPLAYER_STATUS_PREP
 * -# CRIATOMPLAYER_STATUS_PLAYING
 * -# CRIATOMPLAYER_STATUS_PLAYEND
 * 
 * Atom�v���[���[�쐬����̏�Ԃ́A��~��ԁi CRIATOMPLAYER_STATUS_STOP �j�ł��B<br>
 * ::criAtomPlayer_SetData �֐����Ńf�[�^���Z�b�g���A ::criAtomPlayer_Start �֐���
 * ���s����ƁA�Đ�������ԁi CRIATOMPLAYER_STATUS_PREP �j�ɑJ�ڂ��A�Đ��������n�߂܂��B<br>
 * �f�[�^���[����������A�Đ������������ƁA�X�e�[�^�X�͍Đ����i CRIATOMPLAYER_STATUS_PLAYING �j
 * �ɕς��A�������o�͂��J�n����܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I�������_�ŁA�X�e�[�^�X�͍Đ�����
 * �i CRIATOMPLAYER_STATUS_PLAYEND �j�ɕς��܂��B
 * \par ���l
 * �Đ����� ::criAtomPlayer_Stop �֐������s�����ꍇ�A��L�̗���Ɋ֌W�Ȃ��A
 * �ŏI�I�ɃX�e�[�^�X�� CRIATOMPLAYER_STATUS_STOP �ɖ߂�܂��B<br>
 * �i ::criAtomPlayer_Stop �֐��̌Ăяo���^�C�~���O�ɂ���ẮA CRIATOMPLAYER_STATUS_STOP
 * �ɑJ�ڂ���܂łɎ��Ԃ�������ꍇ������܂��B�j<br>
 * �܂��A�Đ����ɕs���ȃf�[�^��ǂݍ��񂾏ꍇ��A�t�@�C���A�N�Z�X�Ɏ��s�����ꍇ���A
 * ��L�̗���Ɋ֌W�Ȃ��A�X�e�[�^�X�� CRIATOMPLAYER_STATUS_ERROR �ɑJ�ڂ��܂��B
 * \attention
 * �X�e�[�^�X�� CRIATOMPLAYER_STATUS_PREP �� CRIATOMPLAYER_STATUS_PLAYING �̃^�C�~���O�ł́A
 * �f�[�^�̃Z�b�g�i ::criAtomPlayer_SetData �֐��j��A�Đ��̊J�n�i ::criAtomPlayer_Start �֐��j
 * �͍s���܂���B<br>
 * ���ݍĐ�����Atom�v���[���[���~���ĕʂ̃f�[�^���Đ��������ꍇ�́A��U ::criAtomPlayer_Stop
 * �֐��ōĐ����~�����A�X�e�[�^�X�� CRIATOMPLAYER_STATUS_STOP �ɑJ�ڂ��Ă��玟�̃f�[�^��
 * �Z�b�g�^�Đ�����K�v������܂��B
 * \sa criAtomPlayer_GetStatus, criAtomPlayer_SetData, criAtomPlayer_Start, criAtomPlayer_Stop
 */
typedef enum CriAtomPlayerStatusTag {
	CRIATOMPLAYER_STATUS_STOP = 0,		/*JP< ��~��		*/
	CRIATOMPLAYER_STATUS_PREP = 1,		/*JP< �Đ�������	*/
	CRIATOMPLAYER_STATUS_PLAYING = 2,	/*JP< �Đ���		*/
	CRIATOMPLAYER_STATUS_PLAYEND = 3,	/*JP< �Đ�����		*/
	CRIATOMPLAYER_STATUS_ERROR = 4,		/*JP< �G���[������	*/

	/* enum size is 4bytes */
	CRIATOMPLAYER_STATUS_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomPlayerStatus;

struct CriAtomPlayerTag;
/*JP
 * \brief Atom�v���[���[�n���h��
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * CriAtomPlayerHn �́A�����Đ��p�ɍ��ꂽ�v���[���[�𑀍삷�邽�߂̃n���h���ł��B<br>
 * ::criAtomPlayer_CreateAdxPlayer �֐����ŉ����Đ��p�̃v���[���[���쐬����ƁA
 * �֐��̓v���[���[����p�ɁA����"Atom�v���[���[�n���h��"��Ԃ��܂��B
 * <br>
 * Atom�v���[���[�Ƃ́A�R�[�f�b�N�Ɉˑ����Ȃ��Đ�����̂��߂̃C���^�[�t�F�[�X��񋟂���A
 * ���ۉ����ꂽ�v���[���[�I�u�W�F�N�g�ł��B<br>
 * Atom�v���[���[�̍쐬���@�͍Đ����鉹���R�[�f�b�N�ɂ��قȂ�܂����A
 * �쐬���ꂽ�v���[���[�̐���ɂ��ẮAAtom�v���[���[�p��API�����ʂŗ��p�\�ł��B
 * <br>
 * �f�[�^�̃Z�b�g��Đ��̊J�n�A�X�e�[�^�X�̎擾���A�v���[���[�ɑ΂��čs������́A
 * �S��Atom�v���[���[�n���h������Ď��s����܂��B<br>
 * \sa criAtomPlayer_CreateAdxPlayer
 */
typedef struct CriAtomPlayerTag *CriAtomPlayerHn;

/*JP
 * \brief �f�[�^�v���R�[���o�b�N�֐�
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	player	Atom�v���[���[�n���h��
 * \return				�Ȃ�
 * \par ����:
 * ���ɍĐ�����f�[�^���w�肷�邽�߂̃R�[���o�b�N�֐��ł��B<br>
 * �����̉����f�[�^���V�[�����X�ɘA�����čĐ�����ۂɎg�p���܂��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomPlayer_SetDataRequestCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[���A���Đ��p�̃f�[�^��v������^�C�~���O��
 * ���s����܂��B<br>
 * �i�O��̃f�[�^��ǂݍ��ݏI���āA���ɍĐ����ׂ��f�[�^��v������^�C�~���O��
 * �R�[���o�b�N�֐������s����܂��B�j
 * �{�֐����� ::criAtomPlayer_SetData �֐�����p����Atom�v���[���[�Ƀf�[�^���Z�b�g����ƁA
 * �Z�b�g���ꂽ�f�[�^�͌��ݍĐ����̃f�[�^�ɑ����ăV�[�����X�ɘA������čĐ�����܂��B<br>
 * �܂��A�{�֐����� ::criAtomPlayer_SetPreviousDataAgain �֐������s���邱�ƂŁA
 * ����f�[�^���J��Ԃ��Đ��������邱�Ƃ��\�ł��B
 * \par ���l:
 * �{�֐����Ńf�[�^���w�肵�Ȃ������ꍇ�A���݂̃f�[�^���Đ����I�������_�ŁA
 * Atom�v���[���[�̃X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYEND �ɑJ�ڂ��܂��B<br>
 * <br>
 * �^�C�~���O���̖��ɂ��A�f�[�^���w�肷�邱�Ƃ��ł��Ȃ����A�X�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYEND �ɑJ�ڂ��������Ȃ��ꍇ�ɂ́A�R�[���o�b�N�֐�����
 * ::criAtomPlayer_DeferCallback �֐������s���Ă��������B<br>
 * ::criAtomPlayer_DeferCallback �֐������s���邱�ƂŁA��1V��ɍēx�f�[�^�v��
 * �R�[���o�b�N�֐����Ăяo����܂��B�i�R�[���o�b�N���������g���C�\�B�j<br>
 * �������A ::criAtomPlayer_DeferCallback �֐������s�����ꍇ�A�Đ����r�؂��
 * �i�A���ӏ��Ɉ�莞�Ԗ���������j�\��������܂��B<br>
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomPlayer_SetDataRequestCallback, criAtomPlayer_SetData,
 * criAtomPlayer_SetPreviousDataAgain, criAtomPlayer_DeferCallback
 */
typedef void (CRIAPI *CriAtomPlayerDataRequestCbFunc)(void *obj, CriAtomPlayerHn player);

/*JP
 * \brief �X�e�[�^�X�ύX�R�[���o�b�N�֐�
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	player	Atom�v���[���[�n���h��
 * \return				�Ȃ�
 * \par ����:
 * Atom�v���[���[�̃X�e�[�^�X���ύX�����^�C�~���O�Ŏ��s�����R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomPlayer_SetStatusChangeCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[�̃X�e�[�^�X���X�V�����^�C�~���O��
 * ���s����܂��B<br>
 * �ύX���ꂽ�X�e�[�^�X�ɂ��ẮA�����œn�����Atom�v���[���[�n���h���iplayer�j�ɑ΂��A
 * ::criAtomPlayer_GetStatus �֐������s���邱�ƂŎ擾�\�ł��B
 * \par ���l:
 * �����ɂ́A�X�e�[�^�X�J�ځ`�R�[���o�b�N�֐����s�܂ł̊Ԃɑ��̏��������荞�݂œ��삷��
 * �]�n�����邽�߁A�X�e�[�^�X�J�ڂƃR�[���o�b�N�֐����s�̃^�C�~���O���Y����\��������܂��B<br>
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomPlayer_SetStatusChangeCallback, criAtomPlayer_GetStatus
 */
typedef void (CRIAPI *CriAtomPlayerStatusChangeCbFunc)(void *obj, CriAtomPlayerHn player);

/*JP
 * \brief �p�����[�^�[�ύX�R�[���o�b�N�֐�
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * \param[in]	obj				���[�U�w��I�u�W�F�N�g
 * \param[in]	player			Atom�v���[���[�n���h��
 * \param[in]	id				�p�����[�^�[ID
 * \param[in]	value			�p�����[�^�[�l
 * \return				�Ȃ�
 * \par ����:
 * Atom�v���[���[�̃p�����[�^�[���ύX�����^�C�~���O�Ŏ��s�����R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomPlayer_SetParameterChangeCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[�̃p�����[�^�[���X�V�����^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomPlayer_SetParameterChangeCallback
 */
typedef void (CRIAPI *CriAtomPlayerParameterChangeCbFunc)(void *obj,
	CriAtomPlayerHn player, CriAtomParameterId id, CriFloat32 value);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐�
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * \param[in]		obj				���[�U�w��I�u�W�F�N�g
 * \param[in]		format			PCM�̌`��
 * \param[in]		num_channels	�`�����l����
 * \param[in]		num_samples		�T���v����
 * \param[in,out]	data			PCM�f�[�^�̃`�����l���z��
 * \return						�Ȃ�
 * \par ����:
 * �f�R�[�h���ʂ� PCM �f�[�^���󂯎��R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomPlayer_SetFilterCallback �֐����g�p���܂��B<br>
 * �R�[���o�b�N�֐���o�^����ƁA Atom �v���[���[�������f�[�^���f�R�[�h����x�ɁA
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
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪��������\��������܂��B<br>
 * \sa criAtomPlayer_SetFilterCallback
 */
typedef void (CRIAPI *CriAtomPlayerFilterCbFunc)(void *obj, CriAtomPcmFormat format,
	CriSint32 num_channels, CriSint32 num_samples, void *data[]);

/*JP
 * \brief ���[�h�v���R�[���o�b�N�֐�
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * \param[in]	obj		���[�U�w��I�u�W�F�N�g
 * \param[in]	binder	�t�@�C�����[�h��o�C���_�[
 * \param[in]	path	�t�@�C���p�X
 * \param[in]	offset	���[�h�J�n�ʒu
 * \param[in]	length	���[�h�v���T�C�Y
 * \return				�Ȃ�
 * \par ����:
 * Atom�v���[���[�̃t�@�C�����[�h��Ԃ��Ď����邽�߂́A�f�o�b�O�p�̃R�[���o�b�N�֐��ł��B<br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomPlayer_SetLoadRequestCallback �֐����g�p���܂��B<br>
 * <br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[�������f�[�^�̃��[�h�v���𔭍s����^�C�~���O�Ŏ��s����܂��B<br>
 * \par ���l:
 * \attention
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * \sa criAtomPlayer_SetLoadRequestCallback
 */
typedef void (CRIAPI *CriAtomPlayerLoadRequestCbFunc)(void *obj,
	CriFsBinderHn binder, const CriChar8 *path, CriSint64 offset, CriSint64 length);

/*==========================================================================
 *      CRI Atom D-BAS API
 *=========================================================================*/
/*JP
 * \brief Atom D-BAS ID
 * \ingroup ATOMLIB_DBAS
 * \par ����:
 * CriAtomDbasId �́AD-BAS�Ǘ��p��ID�ł��B<br>
 * ::criAtomDbas_Create �֐���D-BAS���쐬����Ǝ擾�ł��܂��B
 * <br>
 * �A�v���P�[�V����������D-BAS ID�𗘗p����̂́AD-BAS�̔j�����݂̂ł��B
 * \sa criAtomDbas_Create, criAtomDbas_Destroy
 */
typedef CriSint32 CriAtomDbasId;

/*JP
 * \brief D-BAS�쐬�p�����[�^�[�\����
 * \ingroup ATOMLIB_DBAS
 * \par ����:
 * ::criAtomDbas_Create �֐��̈����Ɏw�肷��AD-BAS�̍쐬�p�����[�^�[�\���̂ł��B<br>
 * <br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomDbas_SetDefaultConfig
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomDbas_Create, criAtomDbas_CalculateWorkSize, criAtomDbas_SetDefaultConfig
 */
typedef struct CriAtomDbasConfigTag {
	/*JP
		\brief D-BAS ���ʎq
		\par ����:
		�A�v���P�[�V��������D-BAS���쐬����ۂɎw�肷�鎯�ʎq�ł��B<br>
		�A�v���P�[�V���������ǂ�D-BAS���g���������I�Ɏw�肷��ۂɎg�p���܂��B<br>
	*/
	CriUint32 identifier;				/*JP< D-BAS ���ʎq	*/
	/*JP
		\brief �ő�X�g���[�~���O��
		\par ����:
		D-BAS�ŊǗ�����u�ԍő�X�g���[�~���O�{�����w�肵�܂��B<br>
		�I�[�f�B�I�����łȂ��ASofdec2�ōĐ����郀�[�r�[�f�[�^�̃X�g���[�~���O�{������������K�v������܂��B<br>
		�Ⴆ�΁A�V�[��A�ł̓I�[�f�B�I�f�[�^���Q�{�A
		�V�[��B�ł̓I�[�f�B�I�f�[�^���P�{�ƃ��[�r�[�f�[�^���Q�{�A�X�g���[�~���O�Đ�����Ƃ��܂��B<br>
		���̏ꍇ�A�u�ԍő�X�g���[�~���O�{���̓V�[��B�̂R�{��ݒ肵�Ă��������B<br>
		�܂�A�A�v���P�[�V�����S�̂�ʂ��āA�ň���Ԃ̃X�g���[�~���O�{����z�肵���l��ݒ肵�Ă��������B
	*/
	CriSint32 max_streams;
	/*JP
		\brief �ő�r�b�g���[�g
		\par ����:
		�X�g���[�~���O�S�̂ɂ�����u�ԍő�r�b�g���[�g���w�肵�܂��B<br>
		���̒l�ɂ́A�A�v���P�[�V�����S�̂�ʂ��āA
		�X�g���[�~���O�Đ�����f�[�^�̏���r�b�g���[�g�̃s�[�N�l��ݒ肵�Ă��������B<br>
		�I�[�f�B�I�����łȂ��ASofdec2�ōĐ����郀�[�r�[�f�[�^�̏���r�b�g���[�g����������K�v������܂��B<br>
		�Ⴆ�΁A�V�[��A�ł̓I�[�f�B�I�f�[�^���S�{�A�V�[��B�ł̓��[�r�[�f�[�^���P�{�A�X�g���[�~���O�Đ�����Ƃ��܂��B<br>
		���̎��A�I�[�f�B�I�f�[�^�S�{���̏���r�b�g���[�g�������[�r�[�f�[�^�P�{�̏���r�b�g���[�g���傫���ꍇ�A<br>
		���[�r�[�f�[�^�̏���r�b�g���[�g��ݒ肵�Ă��������B<br>
		�܂�A�A�v���P�[�V�����S�̂�ʂ��āA�ň���Ԃ̏���r�b�g���[�g��z�肵���l��ݒ肵�Ă��������B
	*/
	CriSint32 max_bps;
	/*JP
		\brief CRI Mana���ōĐ�����ő�X�g���[�~���O��
		\par ����:
		CRI Mana���ōĐ�����u�ԍő�X�g���[�~���O�{�����w�肵�܂��B<br>
		D-BAS�̃������g�p�ʂ̌v�Z�ł́Amax_streams ���炱�̒l���������X�g���[�~���O�{�����A<br>
		CRI Atom�̍ő�X�g���[�~���O�{���Ƃ��Ĉ����܂��B<br>
		CRI Mana���ŃX�g���[�~���O�Đ����s��Ȃ��ꍇ�� 0 �ɐݒ肵�Ă��������B<br>
	*/
	CriSint32 max_mana_streams;
	/*JP
		\brief CRI Mana���ōĐ�����ő�r�b�g���[�g
		\par ����:
		CRI Mana���ōĐ�����u�ԍő�r�b�g���[�g���w�肵�܂��B<br>
		D-BAS�̃������g�p�ʂ̌v�Z�ł́Amax_bps ���炱�̒l���������r�b�g���[�g���A<br>
		CRI Atom�̍ő�r�b�g���[�g�Ƃ��Ĉ����܂��B<br>
		CRI Mana���ŃX�g���[�~���O�Đ����s��Ȃ��ꍇ�� 0 �ɐݒ肵�Ă��������B<br>
	*/
	CriSint32 max_mana_bps;
	/*JP
		\brief �P�X�g���[���Ɋ��蓖�Ă�Œ�ۏ؃o�b�t�@�[��
		\par ����:
		�P�X�g���[���Ɋ��蓖�Ă�Œ�ۏ؃o�b�t�@�[�����w�肵�܂��B�P�ʂ�[��]�ł��B<br>
		ADX2�����ł̓o�b�t�@�[���u���b�N�P�ʂŊǗ����Ă��邽�߁A
		�t�@�C���I�[�⃋�[�v�擪���̔��[�ȃf�[�^�T�C�Y�ɑ΂��Ă��A
		�o�b�t�@�[�u���b�N���P�����蓖�Ă܂��B<br>
		�����V���b�g�̃X�g���[�~���O�Đ��ł́A
		�_�u���o�b�t�@�����O�Ńf�[�^��ǂނ����̒P���ȏ����ł����Ă��A
		�X�g���[�����r�؂�鎖�͂���܂���B<br>
		����A���[�v�t���f�[�^�̏ꍇ�ł́A���[�v�I�[�̂킸���ȃf�[�^�ɂP�u���b�N�A
		���[�v�擪�̂킸���ȃf�[�^�ɂ��P�u���b�N���g���Ă��܂��ƁA<br>
		�o�b�t�@�����O�ς݂̃f�[�^���ɒ[�ɏ��Ȃ��ɂ�������炸�A
		���̃f�[�^��ǂݍ��ރo�b�t�@�[���󂩂Ȃ����߃X�g���[�����r�؂�Ă��܂��܂��B<br>
		�{�p�����[�^�[�́AD-BAS���m�ۂ���X�g���[�~���O�o�b�t�@�[�T�C�Y�ɉe����^���܂��B<br>
		�����r�؂�Ȃ������\���Ɋm�F�ł��Ă���΁A
		�{�p�����[�^�[�̉����l�� ::CRIATOMDBAS_MINIMUM_NUM_SECUREMENT_BUFFERS �ł��B<br>
	*/
	CriSint32 num_securement_buffers;
} CriAtomDbasConfig;

/* ========================================================================*/
/*       CRI Atom Streaming Cache API                                      */
/* ========================================================================*/
/*JP
 * \brief �X�g���[�~���O�L���b�V��ID
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \par ����:
 * CriAtomStreamingCacheId �́A�X�g���[�~���O�L���b�V���Ǘ��pID�ł��B<br>
 * ::criAtomStreamingCache_Create �֐��ŃX�g���[�~���O�L���b�V�����쐬����Ǝ擾�ł��܂��B<br>
 * \sa criAtomStreamingCache_Create
 */
typedef CriUintPtr CriAtomStreamingCacheId;

/*JP
 * \brief �X�g���[�~���O�L���b�V���쐬�p�R���t�B�O�\����
 * \ingroup ATOMLIB_PLAYER
 * \par ����:
 * �v���[���[�ɃX�g���[�~���O�L���b�V�����쐬����ۂɁA
 * �L���b�V���\�ȃt�@�C���T�C�Y����o�^���邽�߂̍\���̂ł��B<br>
 * ::criAtomStreamingCache_CalculateWorkSize �֐��A
 * ::criAtomStreamingCache_Create �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomStreamingCache_CalculateWorkSize, criAtomStreamingCache_Create
 */
typedef struct CriAtomStreamingCacheConfigTag {
	/*JP
		\brief �L���b�V������t�@�C���̍ő�p�X��
		\par ����:
		�X�g���[�~���O�L���b�V���ŃL���b�V������t�@�C���̍ő�p�X�����w�肵�܂��B<br>
	*/
	CriSint32 max_path;
	/*JP
		\brief �L���b�V���\�ȃt�@�C���̍ő吔
		\par ����:
		�X�g���[�~���O�L���b�V���ŃL���b�V������t�@�C�������w�肵�܂��B<br>
	*/
	CriSint32 max_files;
	/*JP
		\brief �L���b�V���\�ȃt�@�C���T�C�Y
		\par ����:
		�X�g���[�~���O�L���b�V���ŃL���b�V���\�ȃt�@�C���T�C�Y���w�肵�܂��B<br>
		���̃p�����[�^�[�Ŏw�肵���ȏ�̃t�@�C�����L���b�V�����邱�Ƃ͂ł��܂���B<br>
		�܂��A�X�g���[�~���O�L���b�V���̕K�v���[�N�T�C�Y�́A
		���̃p�����[�^�[�Ŏw�肵���T�C�Y�ȏ�̃T�C�Y��v������܂��B<br>
	*/
	CriSint32 cache_size;
} CriAtomStreamingCacheConfig;

/* ========================================================================*/
/*       CRI Atom DSP API                                                  */
/* ========================================================================*/

/*JP
 * \brief �s�b�`�V�t�^�A�^�b�`�p�p�����[�^�[�\����
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �s�b�`�V�t�^DSP���A�^�b�`����ۂɎw�肷��p�����[�^�[�ł��B<br>
 * ::criAtomExVoicePool_AttachDspPitchShifter �֐���
 * ::CriAtomExDspPitchShifterConfig �\���̂̃����o�Ƃ��Ďw�肵�܂��B<br>
 * \sa criAtomExVoicePool_AttachDspPitchShifter
 */
typedef struct CriAtomDspPitchShifterConfigTag {
	/*JP
		\brief �s�b�`�V�t�g���[�h
		\par ����:
		�s�b�`�V�t�g�̏������@�i�A���S���Y���j���w�肵�܂��B<br>
		�����ɂ���Đݒ��ύX����Ɖ��������シ�邱�Ƃ�����܂��B<br>
		���L�͎w��\�Ȓl�ƑΉ����郂�[�h���ł��B<br>
		0: Music<br>
		1: Vocal<br>
		2: SoundEffect<br>
		3: Speech<br>
	*/
	CriSint32 mode;

	/*JP
		\brief �E�C���h�E�T�C�Y
		\par ����:
		�s�b�`�V�t�g�̏����P�ʂł��B<br>
		�����ɂ���Đݒ��ύX����Ɖ��������シ�邱�Ƃ�����܂��B<br>
		128,256,512,1024,2048�̂����ꂩ���ݒ�\�ł��B<br>
	*/
	CriSint32 window_size;

	/*JP
		\brief �I�[�o�[���b�v��
		\par ����:
		�s�b�`�V�t�g�̌��ʂ̃I�[�o�[���b�v�񐔂ł��B<br>
		�����ݒ肷��قǕi�������サ�܂����A�������ׂƂ̃g���[�h�I�t�ł��B<br>
		1,2,4,8�̂����ꂩ���ݒ�\�ł��B<br>
	*/
	CriSint32 overlap_times;
} CriAtomDspPitchShifterConfig;

/*JP
 * \brief �s�b�`�V�t�^�p�p�����[�^�[
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �s�b�`�V�t�^DSP�Ɏw�肷��p�����[�^�[�ł��B<br>
 * ::criAtomExPlayer_SetDspParameter �֐��� param_id �Ɏw�肵�܂��B
 * \sa criAtomExPlayer_SetDspParameter
 */
typedef enum CriAtomDspPitchShifterParameterIdTag {
	/*JP
		\brief �s�b�`
		\par ����:
		�s�b�`�V�t�^�̃s�b�`�V�t�g�ʂł��B<br>
		�P�ʂ̓Z���g�ł��B<br>
		�ݒ�\�Ȓl�͈̔͂� -2400 �` 2400 �܂łł��B<br>
		\par ���l:
		�����Ɣ�ׂ� 1200 �� 2�{�A-1200 �� 1/2�{ �̃s�b�`�V�t�g�ɂȂ�܂��B<br>
	*/
	CRIATOMDSP_PITCHSHIFTER_PARAM_PITCH		= 0,

	/*JP
		\brief �t�H���}���g
		\par ����:
		�s�b�`�V�t�^�̃t�H���}���g�V�t�g�ʂł��B<br>
		�P�ʂ̓Z���g�ł��B<br>
		�ݒ�\�Ȓl�͈̔͂� -2400 �` 2400 �܂łł��B<br>
		\par ���l:
		�����Ɣ�ׂ� 1200 �� 2�{�A-1200 �� 1/2�{ �̃t�H���}���g�V�t�g�ɂȂ�܂��B<br>
		\attention
		�t�H���}���g�V�t�g���L���ɂȂ�̂̓s�b�`�V�t�g���[�h�� Vocal �� Speech ��<br>
		�ꍇ�݂̂ł��B<br>
	*/
	CRIATOMDSP_PITCHSHIFTER_PARAM_FORMANT	= 1,

	/*JP
		\brief �s�b�`�V�t�g���[�h
		\par ����:
		�s�b�`�V�t�g�̏������@�i�A���S���Y���j���w�肵�܂��B<br>
		�����ɂ���Đݒ��ύX����Ɖ��������シ�邱�Ƃ�����܂��B<br>
		���L�͎w��\�Ȓl�ƑΉ����郂�[�h���ł��B<br>
		0: Music<br>
		1: Vocal<br>
		2: SoundEffect<br>
		3: Speech<br>
	*/
	CRIATOMDSP_PITCHSHIFTER_PARAM_MODE		= 2
} CriAtomDspPitchShifterParameterId;

/*JP
 * \brief �^�C���X�g���b�`�p�p�����[�^�[�\����
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �^�C���X�g���b�`DSP���A�^�b�`����ۂɎw�肷��p�����[�^�[�ł��B<br>
 * ::criAtomExVoicePool_AttachDspTimeStretch �֐���
 * ::CriAtomExDspTimeStretchConfig �\���̂̃����o�Ƃ��Ďw�肵�܂��B<br>
 * \sa criAtomExVoicePool_AttachDspTimeStretch
 */
typedef struct CriAtomDspTimeStretchConfigTag {
	CriSint32 reserved;
} CriAtomDspTimeStretchConfig;

/*JP
 * \brief �^�C���X�g���b�`�p�p�����[�^�[
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �^�C���X�g���b�`DSP�Ɏw�肷��p�����[�^�[�ł��B<br>
 * ::criAtomExPlayer_SetDspParameter �֐��� param_id �Ɏw�肵�܂��B
 * \sa criAtomExPlayer_SetDspParameter
 */
typedef enum CriAtomDspTimeStretchParameterIdTag {
	/*JP
		\brief �X�g���b�`�䗦
		\par ����:
		�Đ����Ԃ̔{���ł��B<br>
		���f�[�^�̍Đ������� ratio ���|�����l���X�g���b�`���ʂ̍Đ����ԂƂȂ�܂��B<br>
		�ݒ�\�Ȓl�͈̔͂� 0.5f �` 2.0f �܂łł��B<br>
		\attention
		�ݒ肷��l�͍Đ����x�ł͂Ȃ��u�Đ����ԁv�ɑ΂���{���ł��B<br>
		�X�g���b�`�̊������Đ����x�Ŏw�肷��ꍇ�A�Đ����x�̔{���̋t����ݒ肵�Ă��������B<br>
	*/
	CRIATOMDSP_TIMESTRETCH_PARAM_RATIO		= 0,

	/*JP
		\brief �t���[������
		\par ����:
		�^�C���X�g���b�`����ۂ̃t���[������(�P��:�~���b)�ł��B<br>
		�Đ����鉹�̎�ނɂ���Ē������邱�Ƃŕi�������コ�����܂��B<br>
		�ݒ�\�Ȓl�͈̔͂� 10 �` 60 �܂łł��B<br>
		\par ���l:
		�{�C�X������ 20msec �ӂ�A���y�� 50msec �ӂ�ŗǍD�ȕi���ɂȂ�܂��B<br>
	*/
	CRIATOMDSP_TIMESTRETCH_PARAM_FRAME_TIME	= 1,

	/*JP
		\brief �����i��
		\par ����:
		�^�C���X�g���b�`�����̕i���ł��B<br>
		�����قǕi�����オ��܂����ACPU���ׂƂ̃g���[�h�I�t�ł��B<br>
		�ݒ�\�Ȓl�͈̔͂� 0 �` 10 �܂łł��B<br>
		\par ���l:
		�l�̐��͒�߂ł��\���ŁA���y���^�C���X�g���b�`����ꍇ�́A
		�����ݒ肷��قǗǍD�ɂȂ�܂��B<br>
	*/
	CRIATOMDSP_TIMESTRETCH_PARAM_QUALITY	= 2
} CriAtomDspTimeStretchParameterId;

/*JP
 * \brief �X�y�N�g�����A�i���C�U�쐬�p�p�����[�^�[�\����
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �X�y�N�g�����A�i���C�U���A�^�b�`����ۂɎw�肷��p�����[�^�[�ł��B<br>
 * ::criAtomDspSpectra_Create �֐��̈����Ɏg�p���܂��B<br>
 * \sa criAtomDspSpectra_Create
 */
typedef struct CriAtomDspSpectraConfigTag {
	/*JP
		\brief �ш敪����
		\par ����:
		���g�����������̑ш�ɕ������Čv�����邩���w�肵�܂��B<br>
		::criAtomDspSpectra_GetLevels �֐��̖߂�l�i CriFloat32 �z��j�́A
		�{�p�����[�^�[�Ŏw�肵�����Ɠ��������ɂȂ�܂��B<br>
	*/
	CriUint32 num_bands;
} CriAtomDspSpectraConfig;

/* �X�y�N�g�����A�i���C�U�n���h�� */
struct CriAtomDspSpectraObj;
typedef struct CriAtomDspSpectraObj *CriAtomDspSpectraHn;

/* ========================================================================*/
/*       CRI Atom Meter API                                                */
/* ========================================================================*/

/*JP
 * \brief ���x�����[�^�[�@�\�ǉ��p�R���t�B�O�\����
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���x�����[�^�[�@�\��ǉ����邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_AttachLevelMeter �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomMeter_SetDefaultConfigForLevelMeter �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomMeter_AttachLevelMeter �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomMeter_SetDefaultConfigForLevelMeter
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomMeter_AttachLevelMeter
 */
typedef struct {
	/*JP
		\brief ����Ԋu�i�~���b�P�ʁj
		\par ����:
		���茋�ʂ��X�V����Ԋu�ł��B<br>
	*/
	CriSint32 interval;

	/*JP
		\brief �s�[�N�z�[���h���ԁi�~���b�P�ʁj
		\par ����:
		�s�[�N�l�����傫���l�ōX�V���ꂽ�Ƃ��A������Ȃ��悤�Ƀz�[���h���鎞�Ԃł��B<br>
	*/
	CriSint32 hold_time;
} CriAtomLevelMeterConfig;

/*JP
 * \brief ���x�����
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���x�������擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_GetLevelInfo �֐��ŗ��p���܂��B
 * \par ���l:
 * �e���x���l�̒P�ʂ�dB�ł��B<br>
 * \sa criAtomMeter_GetLevelInfo
 */
typedef struct CriAtomLevelInfoTag {
	/*JP
		\brief �L���`�����l����
		\par ����:
		���茋�ʂ��L���ȃ`�����l�����ł��B<br>
	*/
	CriSint32 num_channels;
	
	/*JP
		\brief RMS���x��
		\par ����:
		����Ԋu�Ԃ̉����U����RMS�i��敽�ϕ������j���v�Z�����l�ł��B<br>
		�������x���Ƃ��Ĉ����܂��B
	*/
	CriFloat32 rms_levels[8];
	
	/*JP
		\brief �s�[�N���x��
		\par ����:
		����Ԋu�Ԃ̉����U���̍ő�l�ł��B<br>
	*/
	CriFloat32 peak_levels[8];
	
	/*JP
		\brief �s�[�N�z�[���h���x��
		\par ����:
		�z�[���h���Ă���s�[�N���x���l�ł��B<br>
	*/
	CriFloat32 peak_hold_levels[8];
} CriAtomLevelInfo;

/*JP
 * \brief ���E�h�l�X���[�^�[�@�\�ǉ��p�R���t�B�O�\����
 * \ingroup ATOMLIB_METER
 * ���E�h�l�X���[�^�[�@�\��ǉ����邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_AttachLoudnessMeter �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomMeter_SetDefaultConfigForLoudnessMeter �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomMeter_AttachLoudnessMeter �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomMeter_SetDefaultConfigForLoudnessMeter
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomMeter_AttachLoudnessMeter
 */
typedef struct {
	/*JP
		\brief �V���[�g�^�[�����莞��
		\par ����:
		�Z���̕��σ��E�h�l�X�̑��莞�ԁi�b�P�ʁj�ł��B<br>
		�W����3�b�ł��B<br>
	*/
	CriSint32 short_term_time;

	/*JP
		\brief �C���e�O���[�e�b�h���莞��
		\par ����:
		�����̕��σ��E�h�l�X�̑��莞�ԁi�b�P�ʁj�ł��B<br>
		�C���e�O���[�e�b�h�l�̓R���e���c�P�ʂ̕��σ��E�h�l�X�ł��B<br>
	*/
	CriSint32 integrated_time;
} CriAtomLoudnessMeterConfig;

/*JP
 * \brief ���E�h�l�X���
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���E�h�l�X�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_GetLoudnessInfo �֐��ŗ��p���܂��B
 * \par ���l:
 * �e���x���l�̒P�ʂ�LKFS�ł��B<br>
 * \sa criAtomMeter_GetLoudnessInfo
 */
typedef struct CriAtomLoudnessInfoTag {
	/*JP
		\brief ����J�E���g
		\par ����:
		���肵���񐔂ł��B<br>
		0.1�b��1�񑪒肳��܂��B<br>
	*/
	CriSint32		count;
	/*JP
		\brief ���[�����^���[�l
		\par ����:
		�u�Ԃ̃��E�h�l�X���x���ł��B<br>
	*/
	CriFloat32		momentary;
	/*JP
		\brief �V���[�g�^�[���l
		\par ����:
		�Z���̃��E�h�l�X���σ��x���ł��B<br>
	*/
	CriFloat32		short_term;
	/*JP
		\brief �C���e�O���[�e�b�h�l
		\par ����:
		�����̃��E�h�l�X���σ��x���ł��B<br>
	*/
	CriFloat32		integrated;
} CriAtomLoudnessInfo;

/*JP
 * \brief �g�D���[�s�[�N���[�^�[�@�\�ǉ��p�R���t�B�O�\����
 * \ingroup ATOMLIB_METER
 * �g�D���[�s�[�N���[�^�[�@�\��ǉ����邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_AttachTruePeakMeter �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomMeter_SetDefaultConfigForTruePeakMeter �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomMeter_AttachTruePeakMeter �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomMeter_SetDefaultConfigForTruePeakMeter
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomMeter_AttachTruePeakMeter
 */
typedef struct {
	/*JP
		\brief �N���b�s���O
		\par ����:
		�g�`�̃T���v���𑪒�O�ɃN���b�v����t���O�ł��B<br>
		�g�`�̃T���v���𑪒�O�ɃN���b�v����t���O�ł��B<br>
	*/
	CriBool sample_clipping;

	/*JP
		\brief ����Ԋu�i�~���b�P�ʁj
		\par ����:
		���茋�ʂ��X�V����Ԋu�ł��B<br>
	*/
	CriSint32 interval;

	/*JP
		\brief �z�[���h���ԁi�~���b�P�ʁj
		\par ����:
		�s�[�N�l�����傫���l�ōX�V���ꂽ�Ƃ��A������Ȃ��悤�Ƀz�[���h���鎞�Ԃł��B<br>
	*/
	CriSint32 hold_time;
} CriAtomTruePeakMeterConfig;

/*JP
 * \brief �g�D���[�s�[�N���
 * \ingroup ATOMLIB_METER
 * \par ����:
 * �g�D���[�s�[�N�����擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomMeter_GetTruePeakInfo �֐��ŗ��p���܂��B
 * \par ���l:
 * �e���x���l�̒P�ʂ�dB�ł��B<br>
 * \sa criAtomMeter_GetTruePeakInfo
 */
typedef struct CriAtomTruePeakInfoTag {
	/*JP
		\brief �L���`�����l����
		\par ����:
		���茋�ʂ��L���ȃ`�����l�����ł��B<br>
	*/
	CriSint32		num_channels;
	
	/*JP
		\brief �g�D���[�s�[�N���x��
		\par ����:
		�g�D���[�s�[�N���[�^�[�̑��茋�ʂł��B<br>
	*/
	CriFloat32		levels[8];
	
	/*JP
		\brief �s�[�N�z�[���h���x��
		\par ����:
		�z�[���h���Ă���s�[�N���x���ł��B<br>
	*/
	CriFloat32		hold_levels[8];
} CriAtomTruePeakInfo;

/*==========================================================================
 *      CRI Atom Instrument API
 *=========================================================================*/
/*JP
 * \brief �o�[�W�������t���C���^�[�t�F�[�X�^
 * \par ����:
 * �C���X�g�D�������g�C���^�[�t�F�[�X�o�^�֐��̈����^�ł��B
 * \sa  criAtomInstrument_RegisterInstrumentInterface, criAtomInstrument_UnregisterInstrumentInterface
 */
typedef const struct CriAinstInterfaceWithVersionTag* CriAtomAinstInterfaceWithVersionPtr;

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
 * \brief ���C�u�����̃o�[�W�����ԍ���r���h����Ԃ��܂��B
 * \ingroup ATOMLIB_GLOBAL
 * \return	const CriChar8*	���C�u������񕶎���
 * \par ����:
 * ���C�u�����̃o�[�W�����A�r���h���������A�v���b�g�t�H�[���̏�񂪕\������܂��B
 */
const CriChar8* CRIAPI criAtom_GetVersionString(void);

/*JP
 * \brief ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * CRI Atom���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * CRI Atom���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtom_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa CriAtomConfig, criAtom_Initialize
 */
CriSint32 CRIAPI criAtom_CalculateWorkSize(const CriAtomConfig *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * CRI Atom���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtom_Finalize �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U��CRI Atom���C�u�����Ƀ������m�ۊ֐���o�^���Ă����܂��B<br>
 * work��NULL�Awork_size��0���w�肵�Ė{�֐����Ăяo�����ƂŁA
 * ���C�u�����͓o�^�ς݂̃������m�ۊ֐����g�p���ĕK�v�ȃ������������I�Ɋm�ۂ��܂��B<br>
 * ���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * ���������Ɋm�ۂ��ꂽ�������́A�I���������i ::criAtom_Finalize �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtom_CalculateWorkSize �֐��Ŏ擾�\�ł��B<br>
 * �����������̑O�� ::criAtom_CalculateWorkSize �֐��Ŏ擾�����T�C�Y���̃�������\��
 * �m�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈�̓��C�u�����̏I�������i ::criAtom_Finalize �֐��j
 * ���s���܂ł̊ԁA���C�u�������ŗ��p���ꑱ���܂��B<br>
 * ���C�u�����̏I���������s���O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B<br>
 * \par ��:
 * �yUser Allocator�����ɂ�郉�C�u�����̏������z<br>
 * User Allocator������p����ꍇ�A���C�u�����̏������^�I���̎菇�͈ȉ��̈ȉ��̒ʂ�ł��B<br>
 * 	-# �������������s�O�ɁA ::criAtom_SetUserMallocFunction �֐���
 * ::criAtom_SetUserFreeFunction �֐���p���ă������m�ہ^����֐���o�^����B<br>
 * 	-# �������p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ::criAtom_Initialize �֐��ŏ������������s���B<br>
 * �iwork�ɂ�NULL�Awork_size�ɂ�0���w�肷��B�j<br>
 * 	-# �A�v���P�[�V�����I������ ::criAtom_Finalize �֐��ŏI���������s���B<br>
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
 * 	CriAtomConfig config;	// ���C�u�����������p�R���t�B�O�\����
 * 		:
 * 	// �Ǝ��̃������m�ۊ֐���o�^
 * 	criAtom_SetUserMallocFunction(user_malloc, NULL);
 *
 * 	// �Ǝ��̃���������֐���o�^
 * 	criAtom_SetUserFreeFunction(user_free, NULL);
 *
 * 	// ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * 	criAtom_SetDefaultConfig(&config);
 *
 * 	// ���C�u�����̏�����
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������́A�o�^�����������m�ۊ֐����g���Ċm�ۂ����B
 * 	criAtom_Initialize(&config, NULL, 0);
 * 		:
 * 	// �A�v���P�[�V�����̃��C������
 * 		:
 * 	// �A�v���P�[�V�������I������ۂɏI���������s��
 * 	// �����������Ɋm�ۂ��ꂽ�������́A�o�^��������������֐����g���ĉ�������B
 * 	criAtom_Finalize();
 * 		:
 * }
 * \endcode
 * <br>
 * �yFixed Memory�����ɂ�郉�C�u�����̏������z<br>
 * Fixed Memory������p����ꍇ�A���C�u�����̏������^�I���̎菇�͈ȉ��̈ȉ��̒ʂ�ł��B<br>
 * 	-# �������p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ���C�u�����̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���A ::criAtom_CalculateWorkSize
 * �֐����g���Čv�Z����B<br>
 * 	-# ���[�N�̈�T�C�Y���̃��������m�ۂ���B<br>
 * 	-# ::criAtom_Initialize �֐��ŏ������������s���B<br>
 * �iwork�ɂ͊m�ۂ����������̃A�h���X���Awork_size�ɂ̓��[�N�̈�̃T�C�Y���w�肷��B�j<br>
 * 	-# �A�v���P�[�V�����I������ ::criAtom_Finalize �֐��ŏI���������s���B<br>
 * 	-# ���[�N�̈�̃��������������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 	CriAtomConfig config;	// ���C�u�����������p�R���t�B�O�\����
 * 	void *work;				// ���[�N�̈�A�h���X
 * 	CriSint32 work_size;	// ���[�N�̈�T�C�Y
 * 		:
 * 	// ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * 	criAtom_SetDefaultConfig(&config);
 *
 * 	// ���C�u�����̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z
 * 	work_size = criAtom_CalculateWorkSize(&config);
 *
 * 	// ���[�N�̈�p�Ƀ��������m��
 * 	work = malloc((size_t)work_size);
 *
 * 	// ���C�u�����̏�����
 * 	// ���m�ۍς݂̃��[�N�̈���w�肷��B
 * 	criAtom_Initialize(&config, NULL, 0);
 * 		:
 * 	// �A�v���P�[�V�����̃��C������
 * 	// �����̊ԁA�m�ۂ����������͕ێ���������B
 * 		:
 * 	// �A�v���P�[�V�������I������ۂɏI���������s��
 * 	criAtom_Finalize();
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
 * ����A�X�g���[���Đ��̗L���Ɋ֌W�Ȃ��ACRI Atom���C�u�����̏������O�ɕK��
 * CRI File System���C�u���������������Ă����K�v������܂��B<br>
 * CRI File System���C�u�����̏��������s���Ă��Ȃ��ꍇ�́A
 * CRI Atom���C�u����������CRI File System���C�u���������������܂��B<br>
 * ���̍ۂ̏������p�����[�^�[��criFs_SetDefaultConfig�����}�N���Őݒ肳���l�ł��B
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtom_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtom_Finalize �֐������s����܂ł́A�{�֐����ēx���s���邱�Ƃ͂ł��܂���B<br>
 * \sa CriAtomConfig, criAtom_Finalize, criAtom_SetUserMallocFunction,
 * criAtom_SetUserFreeFunction, criAtom_CalculateWorkSize
 */
void CRIAPI criAtom_Initialize(const CriAtomConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�������I�����܂��B<br>
 * \attention
 * ::criAtom_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtom_Initialize
 */
void CRIAPI criAtom_Finalize(void);

/*JP
 * \brief ���C�u������������Ԃ̎擾
 * \ingroup ATOMLIB_GLOBAL
 * \return	CriBool		�����������ǂ���
 * \retval	CRI_FALSE	�����������
 * \retval	CRI_TRUE	�������ς�
 * \par ����:
 * CRI Atom���C�u���������ɏ���������Ă��邩�ǂ������`�F�b�N���܂��B<br>
 * \sa criAtom_Initialize, criAtom_Finalize
 */
CriBool CRIAPI criAtom_IsInitialized(void);

/*JP
 * \brief �I�[�f�B�I�o�͂��L�����ǂ����̃`�F�b�N
 * \ingroup ATOMLIB_GLOBAL
 * \return	CriBool		�I�[�f�B�I�o�͂��L�����ǂ���
 * \retval	CRI_TRUE	�L��
 * \retval	CRI_FALSE	����
 * \par ����:
 * �I�[�f�B�I�o�͂��L�����ǂ������`�F�b�N���܂��B<br>
 * CRI Atom���C�u�������������A�T�E���h�f�o�C�X�����p�\�ł������ꍇ�A
 * �{�֐���CRI_TRUE��Ԃ��܂��B<br>
 * CRI Atom���C�u�������������ɁA�T�E���h�f�o�C�X�����p�s�\�ł������ꍇ�A
 * �{�֐���CRI_FALSE��Ԃ��܂��B<br>
 * \par �⑫:
 * �T�E���h�f�o�C�X�������ȏꍇ�ł��AAtom���C�u�����͉������o�͂����ɓ��삵�܂��B<br>
 * �i�����f�[�^����ʂ��^�C�}�����Ɍv�Z���A�\�Ȍ��艹���o�͂��L���ȏꍇ�Ɠ����̓�����G�~�����[�g���܂��B�j<br>
 * ���̂��߁A�����o�̓f�o�C�X���g�p�ł��Ȃ��P�[�X�ł����Ă��A
 * �A�v���P�[�V��������Atom���C�u������API�Ăяo�����������K�v�͂���܂���B<br>
 * �iPC�����A���[�U���T�E���h�f�o�C�X�𖳌������Ă���P�[�X�ɑ΂��ʒm���s�������ꍇ�ɁA
 * �{�֐����g�p���Ă��������B�j<br>
 * \attention
 * �{�֐��́A�uAtom���C�u�������������_�ŃI�[�f�B�I�f�o�C�X�����p�\���������ǂ����v��Ԃ��܂��B<br>
 * ���C�u������������Ƀ��[�U���T�E���h�f�o�C�X�𔲂���������P�[�X�ɂ��ẮA�{�֐��ł͌��m�ł��܂���B<br>
 * �i�e�@��ŗL��API���g�p����K�v������܂��B�j<br>
 * <br>
 * �I�[�f�B�I�o�͂������ȏ�Ԃ�Atom���C�u��������������A
 * ���[�U���I�[�f�B�I�f�o�C�X��L���������Ƃ��Ă��AAtom���C�u�����͉����o�͂��s���܂���B<br>
 * �i�I�[�f�B�I�f�o�C�X���h���ꂽ���Ƃ�Atom���C�u�����������Ō��o���邱�Ƃ͂���܂���B�j<br>
 * �A�v���P�[�V�������s���ɃI�[�f�B�I�f�o�C�X��L�����������ꍇ�ɂ́A
 * Atom���C�u�����̏�������������蒼���K�v������܂��B<br>
 * \sa criAtom_Initialize
 */
CriBool CRIAPI criAtom_IsAudioOutputActive(void);

/*JP
 * \brief �}���`�X���b�h�p�T�[�o�[�����̎��s
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�����̓�����Ԃ��X�V���܂��B<br>
 * �A�v���P�[�V�����́A���̊֐������I�Ɏ��s����K�v������܂��B<br>
 * <br>
 * �T�[�o�[���������s���ׂ��񐔂́A���C�u�������������̃p�����[�^�[�Ɉˑ����܂��B<br>
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI �ɐݒ肵���ꍇ�A
 * ���A���^�C�����̗v������鏈���͑S��CRI Atom���C�u�������Œ���I�Ɏ������s����邽�߁A
 * �{�֐��̌Ăяo���p�x�͏��Ȃ��Ă����͔������܂���B<br>
 * �i�Œ�ł����b1����x���s����Ă���΁A���؂ꓙ�̖�肪�������邱�Ƃ͂���܂���B�j<br>
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOM_THREAD_MODEL_SINGLE ��
 * ::CRIATOM_THREAD_MODEL_USER_MULTI �ɐݒ肵���ꍇ�A�t�@�C���̓ǂݍ��݊Ǘ���A
 * �f�[�^�̃f�R�[�h�A�����̏o�͓��A�����Đ��ɕK�v�ȏ����̂قڑS�Ă��{�֐����Ŏ��s����܂��B<br>
 * �܂��A�����Đ������ɓ������āACRI File System���C�u�����̃t�@�C���A�N�Z�X�ƃf�[�^�W�J���������s���܂��B<br>
 * ���̂��߁A���C�u�������������Ɏw�肵���T�[�o�[�����̎��s�p�x�i ::CriAtomConfig �\���̂�
 * server_frequency �j�������p�x�Ŗ{�֐������s�����ꍇ��A
 * �傫���f�[�^�̓ǂݍ��݁A���k�t�@�C���̓ǂݍ��ݓ����s���ꍇ�A
 * ���؂ꓙ�̖�肪��������\��������̂Œ��ӂ��Ă��������B<br>
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI �ɐݒ肵���ꍇ�ł��A
 * �{�֐������s����K�v������܂��B<br>
 * �i�X���b�h���f���� ::CRIATOM_THREAD_MODEL_MULTI �̏ꍇ�A�X�e�[�^�X�X�V���A�����ꕔ��
 * <br>
 * CRI File System���C�u�����̃T�[�o�[�����́ACRI Atom���C�u���������Ŏ��s����܂��B<br>�A
 * ���̂��߁A�{�֐������s���Ă���ꍇ�A�A�v���P�[�V�������ŕʓrCRI File System���C�u����
 * �̃T�[�o�[�������Ăяo���K�v�͂���܂���B<br>
 * \sa criAtom_ExecuteAudioProcess
 */
void CRIAPI criAtom_ExecuteMain(void);

/*JP
 * \brief ���[�U�[�}���`�X���b�h�p�T�[�o�[�����̎��s
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * CRI Atom���C�u�����݂̂��X�V���܂��B<br>
 * �X���b�h���f����::CRIATOM_THREAD_MODEL_USER_MULTI�̏ꍇ�A
 * �A�v���P�[�V�����́A���̊֐������I�Ɏ��s����K�v������܂��B<br>
 *
 * <br>
 * �t�@�C���̓ǂݍ��݊Ǘ���A�f�[�^�̃f�R�[�h�A�����̏o�͓��A
 * �����Đ��ɕK�v�ȏ����̂قڑS�Ă��{�֐����Ŏ��s����܂��B<br>
 * ���̂��߁A���C�u�������������Ɏw�肵���T�[�o�[�����̎��s�p�x�i ::CriAtomConfig �\���̂�
 * server_frequency �j�������p�x�Ŗ{�֐������s�����ꍇ�A���؂ꓙ�̖�肪��������\��
 * ������܂��B<br>
 * �܂��A�{�֐���::criAtom_ExecuteMain �֐��ƈقȂ�ACRI File System���C�u�����̃T�[�o�[���������s���܂���B<br>
 * �A�v���P�[�V�������K�v�ȃT�[�o�[�����𐳂��������Ŏ��s���Ă��������B<br>
 * \par ���l:
 * ::CRIATOM_THREAD_MODEL_SINGLE �ɐݒ肵���ꍇ�A�T�[�o�[�����̔r�����䂪�s���Ȃ��̂ŁA
 * �����̃X���b�h����Ăяo���Ȃ��悤�ɂ��Ă��������B<br>
 * \sa criAtom_ExecuteMain
 */
void CRIAPI criAtom_ExecuteAudioProcess(void);

/*JP
 * \brief �������m�ۊ֐��̓o�^
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	func		�������m�ۊ֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom���C�u�����Ƀ������m�ۊ֐���o�^���܂��B<br>
 * CRI Atom���C�u�����������C�u�������ōs���������m�ۏ������A
 * ���[�U�Ǝ��̃������m�ۏ����ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * <br>
 * �{�֐��̎g�p�菇�͈ȉ��̂Ƃ���ł��B<br>
 * (1) ::CriAtomMallocFunc �C���^�[�t�F�[�X�ɕ������������m�ۊ֐���p�ӂ���B<br>
 * (2) ::criAtom_SetUserMallocFunction �֐����g�p���ACRI Atom���C�u�����ɑ΂���
 * �������m�ۊ֐���o�^����B<br>
 * <br>
 * ��̓I�ȃR�[�h�̗�͈ȉ��̂Ƃ���ł��B
 * \par ��:
 * \code
 * // �Ǝ��̃������m�ۊ֐���p��
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
 * main()
 * {
 * 		:
 * 	// �������m�ۊ֐��̓o�^
 * 	criAtom_SetUserMallocFunction(user_malloc, NULL);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * ������ obj �Ɏw�肵���l�́A ::CriAtomMallocFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g��{�֐��̈����ɃZ�b�g���Ă����A�R�[���o�b�N�֐��ň������o�R
 * ���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * �������m�ۊ֐���o�^����ۂɂ́A���킹�ă���������֐��i ::CriAtomFreeFunc �j��
 * �o�^����K�v������܂��B
 * \sa CriAtomMallocFunc, criAtom_SetUserFreeFunction
 */
void CRIAPI criAtom_SetUserMallocFunction(CriAtomMallocFunc func, void *obj);

/*JP
 * \brief ����������֐��̓o�^
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	func		����������֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom���C�u�����Ƀ���������֐���o�^���܂��B<br>
 * CRI Atom���C�u�����������C�u�������ōs������������������A
 * ���[�U�Ǝ��̃�������������ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * <br>
 * �{�֐��̎g�p�菇�͈ȉ��̂Ƃ���ł��B<br>
 * (1) ::CriAtomFreeFunc �C���^�[�t�F�[�X�ɕ���������������֐���p�ӂ���B<br>
 * (2) ::criAtom_SetUserFreeFunction �֐����g�p���ACRI Atom���C�u�����ɑ΂���
 * ����������֐���o�^����B<br>
 * <br>
 * ��̓I�ȃR�[�h�̗�͈ȉ��̂Ƃ���ł��B
 * \par ��:
 * \code
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
 * 		:
 * 	// ����������֐��̓o�^
 * 	criAtom_SetUserFreeFunction(user_free, NULL);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * ������ obj �Ɏw�肵���l�́A ::CriAtomFreeFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g��{�֐��̈����ɃZ�b�g���Ă����A�R�[���o�b�N�֐��ň������o�R
 * ���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * ����������֐���o�^����ۂɂ́A���킹�ă������m�ۊ֐��i ::CriAtomMallocFunc �j��
 * �o�^����K�v������܂��B
 * \sa CriAtomFreeFunc, criAtom_SetUserMallocFunction
 */
void CRIAPI criAtom_SetUserFreeFunction(CriAtomFreeFunc func, void *obj);

/*JP
 * \brief �I�[�f�B�I�t���[���J�n�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	func		�I�[�f�B�I�t���[���J�n�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom���C�u�����ɃI�[�f�B�I�t���[���J�n�R�[���o�b�N��o�^���܂��B<br>
 * �I�[�f�B�I�t���[���́ACRI Atom���C�u�������ŃT�[�o�[���������s����^�C�~���O�������܂��B<br>
 * �{�֐��œo�^�����R�[���o�b�N�֐��́A�I�[�f�B�I�t���[���̊J�n���i�T�[�o�[�����J�n���O�j��
 * ���s����܂��B
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f�����}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_MULTI �j
 * �ɐݒ肵���ꍇ�A�R�[���o�b�N�֐���CRI Atom���C�u�������ō쐬���ꂽ�X���b�h����
 * �Ăяo����܂��B<br>
 * ���C�u�������������ɃX���b�h���f�������[�U�}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_USER_MULTI �j�A
 * �܂��̓V���O���X���b�h�i ::CRIATOM_THREAD_MODEL_SINGLE �j�ɐݒ肵���ꍇ�A�R�[���o�b�N�֐�
 * ::criAtom_ExecuteMain �֐����ŌĂяo����܂��B<br>
 * <br>
 * ������ obj �Ɏw�肵���l�́A ::CriAtomAudioFrameStartCbFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * \attention
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 */
void CRIAPI criAtom_SetAudioFrameStartCallback(
	CriAtomAudioFrameStartCbFunc func, void *obj);

/*JP
 * \brief �I�[�f�B�I�t���[���I���R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	func		�I�[�f�B�I�t���[���I���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * CRI Atom���C�u�����ɃI�[�f�B�I�t���[���I���R�[���o�b�N��o�^���܂��B<br>
 * �I�[�f�B�I�t���[���́ACRI Atom���C�u�������ŃT�[�o�[���������s����^�C�~���O�������܂��B<br>
 * �{�֐��œo�^�����R�[���o�b�N�֐��́A�I�[�f�B�I�t���[���̏I�����i�T�[�o�[�����I������j��
 * ���s����܂��B
 * \par ���l:
 * ���C�u�������������ɃX���b�h���f�����}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_MULTI �j
 * �ɐݒ肵���ꍇ�A�R�[���o�b�N�֐���CRI Atom���C�u�������ō쐬���ꂽ�X���b�h����
 * �Ăяo����܂��B<br>
 * ���C�u�������������ɃX���b�h���f�������[�U�}���`�X���b�h�i ::CRIATOM_THREAD_MODEL_USER_MULTI �j�A
 * �܂��̓V���O���X���b�h�i ::CRIATOM_THREAD_MODEL_SINGLE �j�ɐݒ肵���ꍇ�A�R�[���o�b�N�֐�
 * ::criAtom_ExecuteMain �֐����ŌĂяo����܂��B<br>
 * <br>
 * ������ obj �Ɏw�肵���l�́A ::CriAtomAudioFrameEndCbFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * \attention
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 */
void CRIAPI criAtom_SetAudioFrameEndCallback(
	CriAtomAudioFrameEndCbFunc func, void *obj);

/*JP
 * \brief �T�[�o�[�����̊��荞�݂�h�~
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �T�[�o�[�����̊��荞�ݗ}�~���܂��B<br>
 * �{�֐����s��A::criAtom_Unlock �֐����s�܂ł̊ԁA�T�[�o�[�����̓��삪�}�~����܂��B<br>
 * ������API�𓯈�I�[�f�B�I�t���[�����Ŋm���Ɏ��s�������ꍇ�ɂ́A�{�֐��ŃT�[�o�[������
 * ���荞�݂�h�~���A�����̊֐������s���Ă��������B
 * \par ��:
 * \code
 * 	�F
 * // �T�[�o�[�����̊��荞�݂�h�~
 * criAtom_Lock();
 *
 * // �����̉����𓯎��ɍĐ��J�n
 * criAtomPlayer_Start(player1);
 * criAtomPlayer_Start(player2);
 * criAtomPlayer_Start(player3);
 * criAtomPlayer_Start(player4);
 *
 * // �T�[�o�[�����̊��荞�ݖh�~������
 * criAtom_Unlock();
 * 	�F
 * \endcode
 * \attention
 * ��L�̗�̂悤�ɁA�����̃v���[���[�œ����ɍĐ����X�^�[�g����ꍇ�ł��A
 * �X�g���[���Đ����͓����ɔ������J�n�����Ƃ͌���܂���B<br>
 * �i�o�b�t�@�����O�ɔ����Đ��x�������邽�߁B�j<br>
 * <br>
 * �{�֐����s��A������::criAtom_Unlock �֐����Ă΂Ȃ��ꍇ�A�����Đ����r�؂�鋰�ꂪ����܂��B<br>
 * �T�[�o�[�����̊��荞�݂�h�~�����Ԃ́A�ŏ����ɗ}����K�v������܂��B
 * \sa criAtom_Unlock
 */
void CRIAPI criAtom_Lock(void);

/*JP
 * \brief �T�[�o�[�����̊��荞�ݖh�~������
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * ::criAtom_Lock �֐��ɂ��A�T�[�o�[�����̊��荞�ݖh�~���������܂��B
 * \sa criAtom_Lock
 */
void CRIAPI criAtom_Unlock(void);

/*JP
 * \brief �`�����l���}�b�s���O�p�^�[���̎w��
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	nch		�}�b�s���O�p�^�[����ύX����`�����l����
 * \param[in]	type	�}�b�s���O�p�^�[��
 * \par ����:
 * �����f�[�^�̊e�`�����l���Əo�̓X�s�[�J�[�̑Ή��t����ύX���܂��B<br>
 * <br>
 * [5ch�����f�[�^�ɂ���]
 * 5ch�����f�[�^���Đ������ꍇ�A�f�t�H���g��Ԃł͊e�`�����l����
 * L, R, C, Ls, Rs �̏��ŏo�͂���܂��B<br>
 * ����ɑ΂��A::criAtom_SetChannelMapping(5, 1); �����s�����ꍇ�A
 * 5ch�����f�[�^�̊e�`�����l���� L, R, LFE, Ls, Rs �̏��ŏo�͂����悤�ɂȂ�܂��B<br>
 * <br>
 * [6ch�����f�[�^�ɂ���]
 * 6ch�����f�[�^���Đ������ꍇ�A�f�t�H���g��Ԃł͊e�`�����l����
 * L, R, C, LFE, Ls, Rs �̏��ŏo�͂���܂��B<br>
 * ����ɑ΂��A::criAtom_SetChannelMapping(6, 1); �����s�����ꍇ�A
 * 6ch�����f�[�^�̊e�`�����l���� L, C, R, Ls, Rs ,LFE�̏��ŏo�͂����悤�ɂȂ�܂��B<br>
 * \par ���l:
 * ����A�{�֐��ł�5ch��6ch�̉����f�[�^�̃}�b�s���O�p�^�[�������ύX�ł��܂���B<br>
 */
void CRIAPI criAtom_SetChannelMapping(CriSint32 nch, CriUint32 type);

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�@�\�̒ǉ�
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�v���@�\��ǉ����A�p�t�H�[�}���X�v���������J�n���܂��B<br>
 * �{�֐������s��A ::criAtom_GetPerformanceInfo �֐������s���邱�ƂŁA
 * �T�[�o�[�����̕��ׂ�A�T�[�o�[�����̎��s�Ԋu���A���C�u�����̃p�t�H�[�}���X����
 * �擾���邱�Ƃ��\�ł��B
 * \sa criAtom_GetPerformanceInfo, criAtom_DetachPerformanceMonitor
 * \par ��:
 * \code
 * 	// �p�t�H�[�}���X���擾�p�\����
 * 	CriAtomPerformanceInfo info;
 *
 * 	// ���C�u�����̏�����
 * 	criAtom_Initialize(�c);
 *
 * 	// �p�t�H�[�}���X���j�^�[�@�\�̒ǉ�
 * 	criAtom_AttachPerformanceMonitor();
 *
 * 	// �p�t�H�[�}���X���j�^�[�̃��Z�b�g
 * 	criAtom_ResetPerformanceMonitor();
 *
 * 	// �p�t�H�[�}���X�v�����
 * 	�c
 *
 * 	// �p�t�H�[�}���X���̎擾
 * 	criAtom_GetPerformanceInfo(&info);
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
void CRIAPI criAtom_AttachPerformanceMonitor(void);

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�@�\�̍폜
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�v���������I�����A�p�t�H�[�}���X�v���@�\���폜���܂��B
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 */
void CRIAPI criAtom_DetachPerformanceMonitor(void);

/*JP
 * \brief �p�t�H�[�}���X���j�^�[�̃��Z�b�g
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * ���݂܂ł̌v�����ʂ�j�����܂��B<br>
 * �p�t�H�[�}���X���j�^�[�́A ::criAtom_AttachPerformanceMonitor �֐����s����
 * ����p�t�H�[�}���X���̎擾���J�n���A�v�����ʂ�ݐς��܂��B<br>
 * ���ꂩ��v�������Ԃɑ΂��A�ȑO�̌v�����ʂ��ȍ~�̌v�����ʂɊ܂߂����Ȃ��ꍇ�ɂ́A
 * �{�֐������s���A�ݐς��ꂽ�v�����ʂ���U�j������K�v������܂��B
 */
void CRIAPI criAtom_ResetPerformanceMonitor(void);

/*JP
 * \brief �p�t�H�[�}���X���̎擾
 * \ingroup ATOMLIB_GLOBAL
 * \par ����:
 * �p�t�H�[�}���X�����擾���܂��B<br>
 * �{�֐��́A ::criAtom_AttachPerformanceMonitor �֐����s�ォ��
 * ::criAtom_DetachPerformanceMonitor �֐������s����܂ł̊ԁA���p�\�ł��B<br>
 * \sa criAtom_AttachPerformanceMonitor, criAtom_DetachPerformanceMonitor
 */
void CRIAPI criAtom_GetPerformanceInfo(CriAtomPerformanceInfo *info);

/*JP
 * \brief ADX�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMLIB_GLOBAL
 * \param[in]	num_channels	�f�[�^�̃`�����l����
 * \param[in]	sampling_rate	�f�[�^�̃T���v�����O���[�g
 * \return		CriSint32		�r�b�g���[�g[bps]
 * \par ����:
 * ADX�f�[�^�̃r�b�g���[�g���v�Z���܂��B<br>
 * �v�Z�Ɏ��s����Ɩ{�֐���-1��Ԃ��܂��B<br>
 * �v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 */
CriSint32 CRIAPI criAtom_CalculateAdxBitrate(
	CriSint32 num_channels, CriSint32 sampling_rate);

/*JP
 * \brief HCA�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMLIB_GLOBAL
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
CriSint32 CRIAPI criAtom_CalculateHcaBitrate(
	CriSint32 num_channels, CriSint32 sampling_rate, CriAtomEncodeQuality quality);

/*JP
 * \brief HCA-MX�f�[�^�̃r�b�g���[�g�v�Z
 * \ingroup ATOMLIB_GLOBAL
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
CriSint32 CRIAPI criAtom_CalculateHcaMxBitrate(
	CriSint32 num_channels, CriSint32 sampling_rate, CriAtomEncodeQuality quality);

/*JP
 * \brief �X�g���[�~���O���̎擾
 * \ingroup ATOMLIB_GLOBAL
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
 * \sa CriAtomStreamingInfo
 */
CriBool CRIAPI criAtom_GetStreamingInfo(CriAtomStreamingInfo* streaming_info);

/*JP
 * \brief �t�@�C��I/O�̋󂫎��Ԃ��g�����X�g���[�~���O�ǂݍ��݂��s�����ǂ���
 * \ingroup ATOMLIB_GLOBAL
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
CriBool CRIAPI criAtom_SetFreeTimeBufferingFlagForDefaultDevice(CriBool flag);


/*==========================================================================
 *      CRI Atom HCA-MX API
 *=========================================================================*/
/*JP
 * \brief HCA-MX�������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_HCA_MX
 * \param[in]	config		HCA-MX�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * ::criAtom_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomHcaMx_Initialize �֐���HCA-MX�̏��������s���ꍇ�A
 * �{�֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AHCA-MX�������p�R���t�B�O
 * �\���́i ::CriAtomHcaMxConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomHcaMx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtom_SetUserAllocator, criAtomHcaMx_Initialize
 */
CriSint32 CRIAPI criAtomHcaMx_CalculateWorkSize(const CriAtomHcaMxConfig *config);

/*JP
 * \brief ���[�N�̈�T�C�Y�v�Z�p�R���t�B�O�\���̂̐ݒ�
 * \ingroup ATOMLIB_HCA_MX
 * \param[in]	config		HCA-MX�������p�R���t�B�O�\����
 * \par ����:
 * ���[�N�̈�T�C�Y�̌v�Z�p�ɁAHCA-MX�������p�R���t�B�O�\����
 * �i ::CriAtomHcaMxConfig �\���́j�����o�^���܂��B<br>
 * <br>
 * HCA-MX�v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * HCA-MX���������i ::criAtomHcaMx_Initialize �֐����s���j
 * �ɐݒ肷��\���̂̃p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�ʏ�̓v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z����O�ɁA
 * HCA-MX������������K�v������܂��B<br>
 * �{�֐����g�p����HCA-MX�������p�R���t�B�O�\���̂�o�^�����ꍇ�A
 * ::criAtomPlayer_CalculateWorkSizeForHcaMxPlayer
 * �֐��������������Ȃ��Ɏg�p�\�ƂȂ�܂��B<br>
 * \par ���l:
 * �����i config �j�� NULL ���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForHcaMxPlayer
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
 * 	CriAtomHcaMxConfig hca_mx_config;
 *
 * 	// ���[�N�̈�v�Z�p��HCA-MX�������ݒ�����o�^
 * 	criAtomHcaMx_SetDefaultConfig(&hca_mx_config);
 * 	criAtomHcaMx_SetConfigForWorkSizeCalculation(&hca_mx_config);
 *
 * 	// HCA-MX�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * 	hca_mx_vp_work_size = criAtomPlayer_CalculateWorkSizeForHcaMxPlayer(NULL);
 * 		�F
 * \endcode
 * \sa criAtomPlayer_CalculateWorkSizeForHcaMxPlayer, criAtomPlayer_SetDefaultConfigForHcaMxPlayer
 */
void CRIAPI criAtomHcaMx_SetConfigForWorkSizeCalculation(const CriAtomHcaMxConfig *config);

/*JP
 * \brief HCA-MX�̏�����
 * \ingroup ATOMLIB_HCA_MX
 * \param[in]	config	HCA-MX�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * HCA-MX�̏��������s���܂��B<br>
 * �{�֐������s���邱�ƂŁAHCA-MX�f�[�^�̏o�͋@�\���N������܂��B<br>
 * \par ���l:
 * HCA-MX�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AHCA-MX�������p�R���t�B�O
 * �\���́i ::CriAtomHcaMxConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomHcaMx_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j�ŏ������������s���܂��B<br>
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
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomHcaMx_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtomHcaMx_Finalize �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa criAtom_SetUserAllocator, criAtomHcaMx_CalculateWorkSize
 */
void CRIAPI criAtomHcaMx_Initialize(
	const CriAtomHcaMxConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA-MX�̏I��
 * \ingroup ATOMLIB_HCA_MX
 * \par ����:
 * HCA-MX�̏I���������s���܂��B<br>
 * �{�֐������s���邱�ƂŁAHCA-MX�f�[�^�̏o�͂���~����܂��B<br>
 * ::criAtom_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * HCA-MX���������Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iHCA-MX���������Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtom_SetUserAllocator, criAtomHcaMx_Initialize
 */
void CRIAPI criAtomHcaMx_Finalize(void);

/*JP
 * \brief �~�L�T�̃o�X�Z���h���x���ݒ�
 * \ingroup ATOMLIB_HCA_MX
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
void CRIAPI criAtomHcaMx_SetBusSendLevelByName(
	CriSint32 mixer_id, const CriChar8* bus_name, CriFloat32 level);

/*JP
 * \brief �~�L�T�̏o�͎��g��������̐ݒ�
 * \ingroup ATOMLIB_HCA_MX
 * \param[in]	mixer_id	�~�L�TID
 * \param[in]	ratio		�Z���h���x���l�i0.25f�`4.0f�j
 * \par ����:
 * �~�L�T�̏o�͎��g���������ݒ肵�܂��B<br>
 * ���g��������́A�����f�[�^�̎��g���ƍĐ����g���̔䗦�ŁA�Đ����x�̔{���Ɠ����ł��B<br>
 * ���g���䂪1.0f�𒴂���ꍇ�A�����f�[�^�͌�����荂���ɍĐ�����A
 * 1.0f�����̏ꍇ�́A�����f�[�^�͌������ᑬ�ōĐ�����܂��B<br>
 * �{�֐����g�p���邱�ƂŁA�Ώۂ̃~�L�T���g�p����S�Ẵv���[���[�̍Đ����x��
 * �ύX���邱�Ƃ��ł��܂��i�X�̃v���[���[�̍Đ����x�͕ύX�ł��܂���j�B<br>
 */
void CRIAPI criAtomHcaMx_SetFrequencyRatio(CriSint32 mixer_id, CriFloat32 ratio);

/*==========================================================================
 *      CRI Atom AWB API
 *=========================================================================*/
/*JP
 * \brief AWB�t�@�C����TOC��񃍁[�h�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_AWB
 * \param[in]	num			AWB�t�@�C���Ɋ܂܂��R���e���c��
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * AWB�t�@�C����TOC�������[�h���邽�߂ɏ\���ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomAwb_LoadToc, criAtomAwb_LoadTocAsync
 */
CriSint32 CRIAPI criAtomAwb_CalculateWorkSizeForLoadToc(CriSint32 num);

/*JP
 * \brief AWB�t�@�C����TOC��񃍁[�h�i�����Łj
 * \ingroup ATOMLIB_AWB
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		AWB�t�@�C����
 * \param[in]	work		AWB�t�@�C����TOC��񃍁[�h�p���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomAwbHn AWB�n���h��
 * \par ����:
 * �����Đ��̉����Ƃ��Ďg�p����AWB�t�@�C����TOC�������[�h���܂��B<br>
 * ���[�h�����܂Ŗ{�֐��͕��A���܂���̂ŁA�V�[���̐؂�ւ���A
 * ���וϓ������e�ł���^�C�~���O�Ŏ��s���Ă��������B<br>
 * ���[�h�ɐ�������ƁA�߂�l�ɗL����AWB�n���h�����Ԃ�܂��̂ŁA
 * ::criAtomPlayer_SetWaveId �֐��Ɏw�肵�Ďg�p���Ă��������B<br>
 * �g���I�����AWB�n���h���́A::criAtomAwb_Release �֐��ŉ�����Ă��������B<br>
 * TOC���̃��[�h�Ɏ��s�����ꍇ��NULL���Ԃ�܂��B<br>
 * \par ���l:
 * ��O������NULL�A��l������0���w�肵�Ď��s����ƁA
 * �K�v�ȃ��[�N�̈���֐������œ��I�Ɋm�ۂ��܂��B
 * ���I�Ɋm�ۂ����̈�́A::criAtomAwb_Release �֐��ŉ������܂��B
 * \attention
 * AWB�n���h���͓����I�Ƀo�C���_�[�i CriFsBinderHn �j�A����у��[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * AWB�t�@�C����TOC�������[�h����ꍇ�AAWB�n���h�������̃o�C���_�[�A����у��[�_�[��
 * �m�ۂł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * \sa criAtomPlayer_SetWaveId, criAtomAwb_Release, criAtomAwb_LoadTocById
 */
CriAtomAwbHn CRIAPI criAtomAwb_LoadToc(
	CriFsBinderHn binder, const CriChar8 *path, void *work, CriSint32 work_size);

/*JP
 * \brief ID�w��ɂ��AWB�t�@�C����TOC��񃍁[�h�i�����Łj
 * \ingroup ATOMLIB_AWB
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			AWB�t�@�C�����i�[����Ă���CPK�R���e���cID
 * \param[in]	work		AWB�t�@�C����TOC��񃍁[�h�p���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomAwbHn AWB�n���h��
 * \par ����:
 * ::criAtomAwb_LoadToc �֐��Ƃقړ��l�̋@�\�����֐��ł��B
 * ::criAtomAwb_LoadToc �֐��ƈقȂ�_�́A
 * �p�X�w��ł͂Ȃ�CPK���̃R���e���cID�w���AWB�t�@�C����TOC�������[�h����_�ł��B<br>
 * \sa criAtomPlayer_SetWaveId, criAtomAwb_Release, criAtomAwb_LoadToc
 */
CriAtomAwbHn CRIAPI criAtomAwb_LoadTocById(
	CriFsBinderHn binder, CriUint16 id, void *work, CriSint32 work_size);

/*JP
 * \brief AWB�t�@�C����TOC��񃍁[�h�i�񓯊��Łj
 * \ingroup ATOMLIB_AWB
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		AWB�t�@�C����
 * \param[in]	work		AWB�t�@�C����TOC��񃍁[�h�p���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomAwbHn AWB�n���h��
 * \par ����:
 * �����Đ��̉����Ƃ��Ďg�p����AWB�t�@�C����TOC�������[�h���܂��B<br>
 * �{�֐��̓��[�h�v���𔭍s����񓯊��֐��Ȃ̂ŁA
 * ���[�h�̊������A�v���P�[�V�������ő҂K�v������܂��B<br>
 * ::criAtomAwb_GetStatus �֐���AWB�n���h���̃X�e�[�^�X�����I�Ɏ擾���A
 * ���[�h�̊������m�F���Ă��������B<br>
 * ���[�h�̊�����҂��Ă���Ԃ�AWB�n���h���̃X�e�[�^�X�X�V�̂��߂ɁA
 * ����I��::criAtom_ExecuteMain �֐������s����K�v������܂��B<br>
 * ���[�h�v���̔��s�ɐ�������Ɩ߂�l�ɗL����AWB�n���h�����Ԃ�܂��B<br>
 * ���[�h������������������́A::criAtomPlayer_SetWaveId �֐��Ɏw�肵�Ďg�p���Ă��������B<br>
 * �g���I�����AWB�n���h���́A::criAtomAwb_Release �֐��ŉ�����Ă��������B<br>
 * TOC���̃��[�h�v���̔��s�Ɏ��s�����ꍇ��NULL���Ԃ�܂��B<br>
 * \par ���l:
 * ��O������NULL�A��l������0���w�肵�Ď��s����ƁA
 * �K�v�ȃ��[�N�̈���֐������œ��I�Ɋm�ۂ��܂��B
 * ���I�Ɋm�ۂ����̈�́A::criAtomAwb_Release �֐��ŉ������܂��B<br>
 * �{�֐��Ŏ擾����AWB�n���h���̃X�e�[�^�X���G���[��ԁi::CRIATOMAWB_STATUS_ERROR�j�ɂȂ����ꍇ���A
 * ::criAtomAwb_Release �֐��ŉ�����Ă��������B
 * \attention
 * AWB�n���h���͓����I�Ƀo�C���_�[�i CriFsBinderHn �j�A����у��[�_�[�i CriFsLoaderHn �j
 * ���m�ۂ��܂��B<br>
 * AWB�t�@�C����TOC�������[�h����ꍇ�AAWB�n���h�������̃o�C���_�[�A����у��[�_�[��
 * �m�ۂł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * \sa criAtomPlayer_SetWaveId, criAtomAwb_Release, criAtomAwb_GetStatus, criAtomAwb_LoadTocAsyncById
 */
CriAtomAwbHn CRIAPI criAtomAwb_LoadTocAsync(
	CriFsBinderHn binder, const CriChar8 *path, void *work, CriSint32 work_size);

/*JP
 * \brief ID�w��ɂ��AWB�t�@�C����TOC��񃍁[�h�i�񓯊��Łj
 * \ingroup ATOMLIB_AWB
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			AWB�t�@�C�����i�[����Ă���CPK�R���e���cID
 * \param[in]	work		AWB�t�@�C����TOC��񃍁[�h�p���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomAwbHn AWB�n���h��
 * \par ����:
 * ::criAtomAwb_LoadTocAsync �֐��Ƃقړ��l�̋@�\�����֐��ł��B
 * ::criAtomAwb_LoadTocAsync �֐��ƈقȂ�_�́A
 * �p�X�w��ł͂Ȃ�CPK���̃R���e���cID�w���AWB�t�@�C����TOC�������[�h����_�ł��B<br>
 * \sa criAtomPlayer_SetWaveId, criAtomAwb_Release, criAtomAwb_GetStatus, criAtomAwb_LoadTocAsync
 */
CriAtomAwbHn CRIAPI criAtomAwb_LoadTocAsyncById(
	CriFsBinderHn binder, CriUint16 id, void *work, CriSint32 work_size);

/*JP
 * \brief �I��������AWB�n���h���̍쐬
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb_mem			AWB�t�@�C����ǂݍ��񂾃������̈�ւ̃|�C���^
 * \param[in]	awb_mem_size	AWB�t�@�C���T�C�Y
 * \param[in]	work			�I��������AWB�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size		�I��������AWB�p���[�N�̈�T�C�Y
 * \return		CriAtomAwbHn �I��������AWB�n���h��
 * \par ����:
 * ��������ɓǂݍ��܂ꂽAWB�t�@�C���C���[�W����A�I��������AWB�n���h�����쐬���܂��B<br>
 * �����I��������AWB�t�@�C���C���[�W���畡���̃I��������AWB�n���h�����쐬���邱�Ƃ��ł��܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * work��NULL�Awork_size��0���w�肷�邾���ŁA�K�v�ȃ�������o�^�ς݂̃������m�ۊ֐�����m�ۂ��܂��B<br>
 * �I��������AWB�n���h���쐬���ɓ��I�Ɋm�ۂ��ꂽ�������́A<br>
 * �I��������AWB�j�����i ::criAtomAwb_Release �֐����s���j�ɉ������܂��B<br>
 * Fixed Memor������p����ꍇ�́A::CRIATOMAWB_WORKSIZE_FOR_LOADFROMMEMORY �֐����g����
 * �K�v�ȃ��[�N�̈�T�C�Y�����߂Ă��������B<br>
 * ���[�N�̈�Ƃ͈قȂ�Aawb_mem �͕K�����[�U�̐ӔC�ŊǗ�����K�v������_�ɂ͒��ӂ��Ă��������B<br>
 * <br>
 * \attention
 * �{�֐�����������ƁA awb_mem�œn���ꂽ�������̈���I��������AWB�f�[�^�p�ɏ��������܂��B<br>
 * ���̂��߁A�����X���b�h����::CRIATOMAWB_WORKSIZE_FOR_LOADFROMMEMORY �֐����Ăяo���Ă���ꍇ�́A<br>
 * �r�������ɂ��X���b�h�̎��s��������ւ��ꍇ������܂��B<br>
 * �Ȃ��Aawb_mem �Ŏw���������̈�� ::criAtomAwb_Release �֐����s��Ɏ蓮�ŉ�����Ă��������B
 * <br>
 * AWB�n���h���͓����I�Ƀo�C���_�[�i CriFsBinderHn �j���m�ۂ��܂��B<br>
 * AWB�t�@�C����TOC�������[�h����ꍇ�AAWB�n���h�������̃o�C���_�[���m�ۂł���ݒ��
 * Atom���C�u�����i�܂���CRI File System���C�u�����j������������K�v������܂��B<br>
 * \sa CRIATOMAWB_WORKSIZE_FOR_LOADFROMMEMORY,criAtomAwb_Release
 */
CriAtomAwbHn CRIAPI criAtomAwb_LoadFromMemory(
	void *awb_mem, CriSint32 awb_mem_size, void *work, CriSint32 work_size);

/*JP
 * \brief AWB�n���h���̎�ʂ������l���擾
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb				���擾���AWB�n���h��
 * \return		CriAtomAwbType 	AWB�n���h���̎�ʂ������l
 * \par ����:
 * AWB�n���h����TOC���݂̂ł��邩�A�I��������AWB�n���h���Ȃ̂��������l���擾���܂��B
 * �{�֐������s�����ꍇ��::CRIATOMAWB_TYPE_ERROR��Ԃ��܂��B<br>
 * \sa criAtomAwb_GetWaveDataInfo, criAtomPlayer_SetData,
 */
CriAtomAwbType CRIAPI criAtomAwb_GetType(CriAtomAwbHn awb);

/*JP
 * \brief AWB��TOC��񂩂�g�`�f�[�^�̃t�@�C�������擾
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb			���擾���AWB�n���h��
 * \param[in]	id			�g�`�f�[�^ID
 * \param[out]	offset		�g�`�f�[�^�̃I�t�Z�b�g�iByte�j
 * \param[out]	size		�g�`�f�[�^�̃T�C�Y�iByte�j
 * \return		�Ȃ�
 * \par ����:
 * AWB�n���h������id�Ŏw�肵���g�`�f�[�^�̃t�@�C���I�t�Z�b�g�ƃT�C�Y���擾���܂��B<br>
 * �擾�����I�t�Z�b�g�ƃT�C�Y�́AAWB�t�@�C������g�`�f�[�^�𒼐ړǂݍ��ޏꍇ�Ɏg�p���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁAAWB�n���h���̎�ʂ�::criAtomAwb_GetType �֐��Ŋm�F���Ă��������B<br>
 * AWB�n���h���̎�ʂ�::CRIATOMAWB_TYPE_TOC�ƈقȂ�ꍇ�A�܂��͕s����AWB�n���h���������ꍇ�A�{�֐��͎��s���A�G���[�R�[���o�b�N���������܂��B<br>
 * �{�֐������s�����ꍇ�A�o�͒l�ł���offset��size�̒l�͕s��ł��B<br>
 * \sa criAtomAwb_GetType, criAtomAwb_GetWaveDataInfo, criAtomPlayer_SetData,criAtomAwb_GetType
 */
CriBool CRIAPI criAtomAwb_GetWaveFileInfo(
	CriAtomAwbHn awb, CriSint32 id, CriSint64 *offset, CriUint32 *size);

/*JP
 * \brief �I��������AWB����g�`�f�[�^�̏����擾
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb				���擾���AWB�n���h��
 * \param[in]	id				�g�`�f�[�^ID
 * \param[out]	wave_data_start	�g�`�f�[�^�̐擪�|�C���^�iByte�j
 * \param[out]	size			�g�`�f�[�^�̃T�C�Y�iByte�j
 * \return		�Ȃ�
 * \par ����:
 * �I��������AWB����id�Ŏw�肵���g�`�f�[�^�̐擪�|�C���^�ƃT�C�Y���擾���܂��B<br>
 * �I��������AWB����g�`�f�[�^���Đ�����ꍇ�A�ʏ��::criAtomPlayer_SetWaveId �֐��ŏ\���Ȃ̂ŁA��������Q�Ƃ��Ă��������B<br>
 * \attention
 * �{�֐������s����O�ɁAAWB�n���h���̎�ʂ�::criAtomAwb_GetType �֐��Ŋm�F���Ă��������B<br>
 * AWB�n���h���̎�ʂ��قȂ�ꍇ�A�܂��͕s����AWB�n���h���������ꍇ�A�{�֐��͎��s���A�G���[�R�[���o�b�N���������܂��B<br>
 * �{�֐������s�����ꍇ�A�o�͒l�ł���wave_data_start��size�̒l�͕s��ł��B<br>
 *
 * \sa criAtomAwb_GetType, criAtomAwb_GetWaveFileInfo, criAtomPlayer_SetData,criAtomPlayer_SetWaveId
 *
 */
void CRIAPI criAtomAwb_GetWaveDataInfo(CriAtomAwbHn awb, CriSint32 id, void **wave_data_start, CriUint32 *size);

/*JP
 * \brief AWB�n���h�������AWB�t�@�C���Ɋ܂܂��R���e���c�����擾
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb				���擾���AWB�n���h��
 * \return		�R���e���c�t�@�C�����i0�`65535�j
 * \par ����:
 * AWB�n���h�������AWB�t�@�C���Ɋ܂܂�Ă���R���e���c���i�g�`�f�[�^���j���擾���܂��B<br>
 * �R���e���c�t�@�C�����̒l�̗L���͈͂�1�`65535�ł��B<br>
 * �G���[�����������ꍇ�� 0 ��Ԃ��܂��B<br>
 * \sa criAtomAwb_LoadToc, criAtomAwb_LoadFromMemory
 */
CriUint16 CRIAPI criAtomAwb_GetNumContents(CriAtomAwbHn awb);

/*JP
 * \brief AWB�n���h���̉��
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb	AWB�n���h��
 * \return		�Ȃ�
 * \par ����:
 * AWB�n���h����������܂��B<br>
 * �g���I�����AWB�n���h���́A�{�֐��ŉ�����Ă��������B<br>
 * �������AWB�n���h���͖����ȃn���h���ɂȂ�̂ŁA�g�p���Ȃ��ł��������B<br>
 * \attention
 * �{�֐������s����ƁA�w�肵��AWB�f�[�^���Q�Ƃ��Ă���Atom�v���[���[�����݂��Ȃ����A
 * ���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * �{�֐��� ::criAtom_Lock �֐��Ń��b�N���Ă�����s���Ă��������B<br>
 * <br>
 * AtomEx�v���[���[���g�p����AWB�t�@�C�����Đ�����ꍇ�A
 * �Đ����ɖ{�֐���AWB�n���h����j�����Ă͂����܂���B<br>
 * �K��AtomEx�v���[���[���~�����Ă����Ă���{�֐������s���Ă��������B<br>
 * \sa criAtomAwb_LoadToc, criAtomAwb_LoadTocAsync, criAtomAwb_GetStatus
 */
void CRIAPI criAtomAwb_Release(CriAtomAwbHn awb);

/*JP
 * \brief AWB�n���h������������\���ǂ����̃`�F�b�N
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb	AWB�n���h��
 * \return		CriBool		AWB�̏�ԁiCRI_TRUE = ��������\�ACRI_FALSE = �Đ����̃v���[���[����j
 * \par ����:
 * AWB�n���h���𑦍��ɉ���\���ǂ������`�F�b�N���܂��B<br>
 * �{�֐��� CRI_FALSE ��Ԃ��^�C�~���O�� ::criAtomAwb_Release �֐������s����ƁA
 * AWB�n���h�����Q�Ƃ��Ă���v���[���[�ɑ΂����~�������s���܂��B<br>
 * �i�X�g���[���Đ��p��AWB�n���h���̏ꍇ�A�t�@�C���ǂݍ��݊�����҂��߁A
 * ::criAtomAwb_Release �֐����Œ����ԏ������u���b�N�����\��������܂��B�j<br>
 * \attention
 * �{�֐������s����ƁA�w�肵��AWB�f�[�^���Q�Ƃ��Ă���Atom�v���[���[�����݂��Ȃ����A
 * ���C�u�������Ō����������s���܂��B<br>
 * ���̂��߁A�{�֐����s���ɑ��X���b�h��Atom�v���[���[�̍쐬�^�j�����s���ƁA
 * �A�N�Z�X�ᔽ��f�b�h���b�N���̏d��ȕs���U�����鋰�ꂪ����܂��B<br>
 * �{�֐����s����Atom�v���[���[�̍쐬�^�j���𑼃X���b�h�ōs���K�v������ꍇ�A
 * �{�֐��� ::criAtom_Lock �֐��Ń��b�N���Ă�����s���Ă��������B<br>
 * \sa criAtomAwb_Release
 */
CriBool CRIAPI criAtomAwb_IsReadyToRelease(CriAtomAwbHn awb);

/*JP
 * \brief AWB�n���h���̃X�e�[�^�X�擾
 * \ingroup ATOMLIB_AWB
 * \param[in]	awb AWB�n���h��
 * \return		CriAtomAwbStatus AWB�n���h���̏�Ԃ������l
 * \par ����:
 * AWB�n���h���̃X�e�[�^�X���擾���܂��B<br>
 * �{�֐��Ŏ擾����AWB�n���h���̃X�e�[�^�X�́A::criAtom_ExecuteMain �֐���
 * ���s���邱�ƂōX�V����܂��B<br>
 * \sa criAtomAwb_LoadToc, criAtomAwb_LoadTocAsync
 */
CriAtomAwbStatus CRIAPI criAtomAwb_GetStatus(CriAtomAwbHn awb);

/*==========================================================================
 *      CRI Atom Player API
 *=========================================================================*/
/*JP
 * \brief �W���v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		�W���v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �W���v���[���[�iADX��HCA���Đ��\�ȃv���[���[�j���쐬���邽�߂ɕK�v�ȁA
 * ���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomStandardPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForStandardPlayer �K�p���Ɠ����p�����[�^�[�j
 * �Ń��[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomStandardPlayerConfig, criAtomPlayer_CreateStandardPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForStandardPlayer(
	const CriAtomStandardPlayerConfig *config);

/*JP
 * \brief �W���v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		�W���v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * ADX��HCA���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AADX�f�[�^��HCA�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForStandardPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * work��NULL�Awork_size��0���w�肷�邾���ŁA�K�v�ȃ�������o�^�ς݂̃������m�ۊ֐�����m�ۂ��܂��B<br>
 * �W���v���[���[�쐬���Ɋm�ۂ��ꂽ�������́A�W���v���[���[�j�����i ::criAtomPlayer_Destroy
 * �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtomPlayer_CalculateWorkSizeForStandardPlayer �֐��Ŏ擾�\�ł��B<br>
 * �W���v���[���[�쐬�O�� ::criAtomPlayer_CalculateWorkSizeForStandardPlayer �֐��Ŏ擾����
 * �T�C�Y���̃�������\�ߊm�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈�͕W���v���[���[�̔j��
 * �i ::criAtomPlayer_Destroy �֐��j���s���܂ł̊ԁA���C�u�������ŗ��p���ꑱ���܂��B<br>
 * �W���v���[���[�̔j�����s���O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B<br>
 * \par ��:
 * �yUser Allocator�����ɂ��W���v���[���[�̍쐬�z<br>
 * User Allocator������p����ꍇ�A�W���v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# �W���v���[���[�쐬�O�ɁA ::criAtom_SetUserMallocFunction �֐���
 * ::criAtom_SetUserFreeFunction �֐���p���ă������m�ہ^����֐���o�^����B<br>
 * 	-# �W���v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ::criAtomPlayer_CreateStandardPlayer �֐��ŕW���v���[���[���쐬����B<br>
 * �iwork�ɂ�NULL�Awork_size�ɂ�0���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomPlayer_Destroy �֐��ŕW���v���[���[��j������B<br>
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
 * 	CriAtomStandardPlayerConfig config;	// �W���v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomPlayerHn player;				// Atom�v���[���[�n���h��
 * 		:
 * 	// �Ǝ��̃������m�ۊ֐���o�^
 * 	criAtom_SetUserMallocFunction(user_malloc, NULL);
 *
 * 	// �Ǝ��̃���������֐���o�^
 * 	criAtom_SetUserFreeFunction(user_free, NULL);
 *
 * 	// �W���v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	memset(&config, 0, sizeof(config));
 * 	config.max_channels = 2;			// �X�e���I�Đ��\�ȃv���[���[���쐬����
 * 	config.max_sampling_rate = 48000;	// �ő��48000Hz�̉������Đ�����
 *
 * 	// �W���v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������́A�o�^�����������m�ۊ֐����g���Ċm�ۂ����B
 * 	player = criAtomPlayer_CreateStandardPlayer(&config, NULL, 0);
 * 		:
 * 	// �����Đ�����
 * 		:
 * 	// �W���v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	// ���W���v���[���[�쐬���Ƀ��C�u�������Ŋm�ۂ��ꂽ����������������B
 * 	criAtomPlayer_Destroy(player);
 * 		:
 * }
 * \endcode
 * �����C�u�������������Ƀ������m�ہ^����֐���o�^�ς݂̏ꍇ�A�W���v���[���[�쐬��
 * �ɍēx�֐���o�^����K�v�͂���܂���B<br>
 * <br>
 * �yFixed Memory�����ɂ��W���v���[���[�̍쐬�z<br>
 * Fixed Memory������p����ꍇ�A�W���v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# �W���v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# �W���v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���A
 * ::criAtomPlayer_CalculateWorkSizeForStandardPlayer �֐����g���Čv�Z����B<br>
 * 	-# ���[�N�̈�T�C�Y���̃��������m�ۂ���B<br>
 * 	-# ::criAtomPlayer_CreateStandardPlayer �֐��ŕW���v���[���[���쐬����B<br>
 * �iwork�ɂ͊m�ۂ����������̃A�h���X���Awork_size�ɂ̓��[�N�̈�̃T�C�Y���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomPlayer_Destroy �֐��ŕW���v���[���[��j������B<br>
 * 	-# ���[�N�̈�̃��������������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 	CriAtomStandardPlayerConfig config;	// �W���v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomPlayerHn player;				// Atom�v���[���[�n���h��
 * 	void *work;							// ���[�N�̈�A�h���X
 * 	CriSint32 work_size;				// ���[�N�̈�T�C�Y
 * 		:
 * 	// �W���v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	memset(&config, 0, sizeof(config));
 * 	config.max_channels = 2;			// �X�e���I�Đ��\�ȃv���[���[���쐬����
 * 	config.max_sampling_rate = 48000;	// �ő��48000Hz�̉������Đ�����
 *
 * 	// �W���v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z
 * 	work_size = criAtomPlayer_CalculateWorkSizeForStandardPlayer(&config);
 *
 * 	// ���[�N�̈�p�Ƀ��������m��
 * 	work = malloc((size_t)work_size);
 *
 * 	// �W���v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���m�ۍς݂̃��[�N�̈���w�肷��B
 * 	player = criAtomPlayer_CreateStandardPlayer(&config, work, work_size);
 * 		:
 * 	// �����Đ�����
 * 	// �����̊ԁA�m�ۂ����������͕ێ���������B
 * 		:
 * 	// �W���v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	criAtomPlayer_Destroy(player);
 *
 * 	// �K�v�Ȃ��Ȃ������[�N�̈���������
 * 	free(work);
 * 		:
 * }
 * \endcode
 * ::criAtomPlayer_CreateStandardPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �W���v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * �W���v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomStandardPlayerConfig, criAtomPlayer_CalculateWorkSizeForStandardPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateStandardPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateStandardPlayer(
	const CriAtomStandardPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ADX�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		ADX�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * ADX�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomAdxPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForAdxPlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForAdxPlayer(
	const CriAtomAdxPlayerConfig *config);

/*JP
 * \brief ADX�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		ADX�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * ADX���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AADX�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForAdxPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * <br>
 * User Allocator������p����ꍇ�A���[�U�����[�N�̈��p�ӂ���K�v�͂���܂���B<br>
 * work��NULL�Awork_size��0���w�肷�邾���ŁA�K�v�ȃ�������o�^�ς݂̃������m�ۊ֐�����m�ۂ��܂��B<br>
 * ADX�v���[���[�쐬���Ɋm�ۂ��ꂽ�������́AADX�v���[���[�j�����i ::criAtomPlayer_Destroy
 * �֐����s���j�ɉ������܂��B<br>
 * <br>
 * Fixed Memory������p����ꍇ�A���[�N�̈�Ƃ��ĕʓr�m�ۍς݂̃������̈��{�֐���
 * �ݒ肷��K�v������܂��B<br>
 * ���[�N�̈�̃T�C�Y�� ::criAtomPlayer_CalculateWorkSizeForAdxPlayer �֐��Ŏ擾�\�ł��B<br>
 * ADX�v���[���[�쐬�O�� ::criAtomPlayer_CalculateWorkSizeForAdxPlayer �֐��Ŏ擾����
 * �T�C�Y���̃�������\�ߊm�ۂ��Ă����A�{�֐��ɐݒ肵�Ă��������B<br>
 * ���AFixed Memory������p�����ꍇ�A���[�N�̈��ADX�v���[���[�̔j��
 * �i ::criAtomPlayer_Destroy �֐��j���s���܂ł̊ԁA���C�u�������ŗ��p���ꑱ���܂��B<br>
 * ADX�v���[���[�̔j�����s���O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B<br>
 * \par ��:
 * �yUser Allocator�����ɂ��ADX�v���[���[�̍쐬�z<br>
 * User Allocator������p����ꍇ�AADX�v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# ADX�v���[���[�쐬�O�ɁA ::criAtom_SetUserMallocFunction �֐���
 * ::criAtom_SetUserFreeFunction �֐���p���ă������m�ہ^����֐���o�^����B<br>
 * 	-# ADX�v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ::criAtomPlayer_CreateAdxPlayer �֐���ADX�v���[���[���쐬����B<br>
 * �iwork�ɂ�NULL�Awork_size�ɂ�0���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomPlayer_Destroy �֐���ADX�v���[���[��j������B<br>
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
 * 	CriAtomAdxPlayerConfig config;	// ADX�v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomPlayerHn player;			// Atom�v���[���[�n���h��
 * 		:
 * 	// �Ǝ��̃������m�ۊ֐���o�^
 * 	criAtom_SetUserMallocFunction(user_malloc, NULL);
 *
 * 	// �Ǝ��̃���������֐���o�^
 * 	criAtom_SetUserFreeFunction(user_free, NULL);
 *
 * 	// ADX�v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	memset(&config, 0, sizeof(config));
 * 	config.max_channels = 2;			// �X�e���I�Đ��\�ȃv���[���[���쐬����
 * 	config.max_sampling_rate = 48000;	// �ő��48000Hz�̉������Đ�����
 *
 * 	// ADX�v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������́A�o�^�����������m�ۊ֐����g���Ċm�ۂ����B
 * 	player = criAtomPlayer_CreateAdxPlayer(&config, NULL, 0);
 * 		:
 * 	// �����Đ�����
 * 		:
 * 	// ADX�v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	// ��ADX�v���[���[�쐬���Ƀ��C�u�������Ŋm�ۂ��ꂽ����������������B
 * 	criAtomPlayer_Destroy(player);
 * 		:
 * }
 * \endcode
 * �����C�u�������������Ƀ������m�ہ^����֐���o�^�ς݂̏ꍇ�AADX�v���[���[�쐬��
 * �ɍēx�֐���o�^����K�v�͂���܂���B<br>
 * <br>
 * �yFixed Memory�����ɂ��ADX�v���[���[�̍쐬�z<br>
 * Fixed Memory������p����ꍇ�AADX�v���[���[�̍쐬�^�j���̎菇�͈ȉ��̂悤�ɂȂ�܂��B<br>
 * 	-# ADX�v���[���[�쐬�p�R���t�B�O�\���̂Ƀp�����[�^�[���Z�b�g����B<br>
 * 	-# ADX�v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���A
 * ::criAtomPlayer_CalculateWorkSizeForAdxPlayer �֐����g���Čv�Z����B<br>
 * 	-# ���[�N�̈�T�C�Y���̃��������m�ۂ���B<br>
 * 	-# ::criAtomPlayer_CreateAdxPlayer �֐���ADX�v���[���[���쐬����B<br>
 * �iwork�ɂ͊m�ۂ����������̃A�h���X���Awork_size�ɂ̓��[�N�̈�̃T�C�Y���w�肷��B�j<br>
 * 	-# �n���h�����s�v�ɂȂ����� ::criAtomPlayer_Destroy �֐���ADX�v���[���[��j������B<br>
 * 	-# ���[�N�̈�̃��������������B<br>
 * 	
 * <br>��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 	CriAtomAdxPlayerConfig config;	// ADX�v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomPlayerHn player;			// Atom�v���[���[�n���h��
 * 	void *work;						// ���[�N�̈�A�h���X
 * 	CriSint32 work_size;			// ���[�N�̈�T�C�Y
 * 		:
 * 	// ADX�v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	memset(&config, 0, sizeof(config));
 * 	config.max_channels = 2;			// �X�e���I�Đ��\�ȃv���[���[���쐬����
 * 	config.max_sampling_rate = 48000;	// �ő��48000Hz�̉������Đ�����
 *
 * 	// ADX�v���[���[�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���v�Z
 * 	work_size = criAtomPlayer_CalculateWorkSizeForAdxPlayer(&config);
 *
 * 	// ���[�N�̈�p�Ƀ��������m��
 * 	work = malloc((size_t)work_size);
 *
 * 	// ADX�v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���m�ۍς݂̃��[�N�̈���w�肷��B
 * 	player = criAtomPlayer_CreateAdxPlayer(&config, work, work_size);
 * 		:
 * 	// �����Đ�����
 * 	// �����̊ԁA�m�ۂ����������͕ێ���������B
 * 		:
 * 	// ADX�v���[���[���s�v�ɂȂ������_�Ŕj��
 * 	criAtomPlayer_Destroy(player);
 *
 * 	// �K�v�Ȃ��Ȃ������[�N�̈���������
 * 	free(work);
 * 		:
 * }
 * \endcode
 * ::criAtomPlayer_CreateAdxPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * ADX�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * ADX�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CalculateWorkSizeForAdxPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateAdxPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateAdxPlayer(
	const CriAtomAdxPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		HCA�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomHcaPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForHcaPlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomHcaPlayerConfig, criAtomPlayer_CreateHcaPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForHcaPlayer(
	const CriAtomHcaPlayerConfig *config);

/*JP
 * \brief HCA�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		HCA�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * HCA���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AHCA�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForHcaPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * �e�����̏ڍׂɂ��ẮA�ʓr ::criAtomPlayer_CreateAdxPlayer �֐��̐��������Q�Ƃ��������B<br>
 * <br>
 * ::criAtomPlayer_CreateHcaPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * HCA�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * HCA�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomHcaPlayerConfig, criAtomPlayer_CalculateWorkSizeForHcaPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateHcaPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateHcaPlayer(
	const CriAtomHcaPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief HCA-MX�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		HCA-MX�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * HCA-MX�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomHcaMxPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForHcaMxPlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y��HCA-MX���������i ::criAtomHcaMx_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁAHCA-MX�����������Ă����K�v������܂��B<br>
 * \sa CriAtomHcaMxPlayerConfig, criAtomPlayer_CreateHcaMxPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForHcaMxPlayer(
	const CriAtomHcaMxPlayerConfig *config);

/*JP
 * \brief HCA-MX�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		HCA-MX�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * HCA-MX���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AHCA-MX�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForHcaMxPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * �e�����̏ڍׂɂ��ẮA�ʓr ::criAtomPlayer_CreateAdxPlayer �֐��̐��������Q�Ƃ��������B<br>
 * <br>
 * ::criAtomPlayer_CreateHcaMxPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐������s����O�ɁAHCA-MX�����������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * HCA-MX�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * HCA-MX�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomHcaMxPlayerConfig, criAtomPlayer_CalculateWorkSizeForHcaMxPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateHcaMxPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateHcaMxPlayer(
	const CriAtomHcaMxPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief WAVE�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		WAVE�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * WAVE�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomWavePlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForWavePlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomWavePlayerConfig, criAtomPlayer_CreateWavePlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForWavePlayer(
	const CriAtomWavePlayerConfig *config);

/*JP
 * \brief WAVE�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		WAVE�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * WAVE���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AWAVE�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForWavePlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * �e�����̏ڍׂɂ��ẮA�ʓr ::criAtomPlayer_CreateAdxPlayer �֐��̐��������Q�Ƃ��������B<br>
 * <br>
 * ::criAtomPlayer_CreateWavePlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * WAVE�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * WAVE�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * <br>
 * ����AWave�t�@�C���̃`�����N��͂͌����ɂ͍s���Ă��܂���B<br>
 * �`�����N�̕��я���FORM�`�����N�ACOMM�`�����N�ASSND�`�����N�ł͂Ȃ��ꍇ��A
 * ���̑��̃`�����N���܂�Wave�t�@�C���́A��͂Ɏ��s����\��������܂��B<br>
 * �܂��A�����_�őΉ����Ă���t�H�[�}�b�g�́A���m�����܂��̓X�e���I��
 * 16bit �񈳏k�f�[�^�݂̂ł��B<br>
 * \sa CriAtomWavePlayerConfig, criAtomPlayer_CalculateWorkSizeForWavePlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateWavePlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateWavePlayer(
	const CriAtomWavePlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief AIFF�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		AIFF�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * AIFF�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomAiffPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForAiffPlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomAiffPlayerConfig, criAtomPlayer_CreateAiffPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForAiffPlayer(
	const CriAtomAiffPlayerConfig *config);

/*JP
 * \brief AIFF�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		AIFF�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * AIFF���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́AAIFF�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForAiffPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * �e�����̏ڍׂɂ��ẮA�ʓr ::criAtomPlayer_CreateAdxPlayer �֐��̐��������Q�Ƃ��������B<br>
 * <br>
 * ::criAtomPlayer_CreateAiffPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * AIFF�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * AIFF�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * <br>
 * ����AAIFF�t�@�C���̃`�����N��͂͌����ɂ͍s���Ă��܂���B<br>
 * �`�����N�̕��я���FORM�`�����N�ACOMM�`�����N�ASSND�`�����N�ł͂Ȃ��ꍇ��A
 * ���̑��̃`�����N���܂�AIFF�t�@�C���́A��͂Ɏ��s����\��������܂��B<br>
 * �܂��A�����_�őΉ����Ă���t�H�[�}�b�g�́A���m�����܂��̓X�e���I��
 * 16bit �񈳏k�f�[�^�݂̂ł��B<br>
 * \sa CriAtomAiffPlayerConfig, criAtomPlayer_CalculateWorkSizeForAiffPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateAiffPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateAiffPlayer(
	const CriAtomAiffPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief RawPCM�v���[���[�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		RawPCM�v���[���[�쐬�p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * RawPCM�Đ��p�v���[���[���쐬���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * �v���[���[�̍쐬�ɕK�v�ȃ��[�N�������̃T�C�Y�́A�v���[���[�쐬�p�R���t�B�O
 * �\���́i ::CriAtomRawPcmPlayerConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomPlayer_SetDefaultConfigForRawPcmPlayer �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ���[�N�̈�̃T�C�Y�̓��C�u�������������i ::criAtom_Initialize �֐����s���j
 * �Ɏw�肵���p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa CriAtomRawPcmPlayerConfig, criAtomPlayer_CreateRawPcmPlayer
 */
CriSint32 CRIAPI criAtomPlayer_CalculateWorkSizeForRawPcmPlayer(
	const CriAtomRawPcmPlayerConfig *config);

/*JP
 * \brief RawPCM�v���[���[�̍쐬
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	config		RawPCM�v���[���[�쐬�p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomPlayerHn	Atom�v���[���[�n���h��
 * \par ����:
 * RawPCM���Đ��\�ȃv���[���[���쐬���܂��B<br>
 * �{�֐��ō쐬���ꂽAtom�v���[���[�ɂ́ARawPCM�f�[�^�̃f�R�[�h�@�\���t������Ă��܂��B<br>
 * <br>
 * �쐬���ꂽ�v���[���[�ōĐ��ł��鉹���̃t�H�[�}�b�g�́A�������iconfig�j�Ɏw�肵��
 * �p�����[�^�[�ɂ���Č��܂�܂��B<br>
 * �Ⴆ�΁Aconfig��max_sampling_rate��24000��ݒ肵���ꍇ�A�쐬���ꂽ�v���[���[�ł�
 * 24kHz�𒴂���T���v�����O���[�g�̉����f�[�^�͍Đ��ł��Ȃ��Ȃ�܂��B<br>
 * config��NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�i ::criAtomPlayer_SetDefaultConfigForRawPcmPlayer
 * �K�p���Ɠ����p�����[�^�[�j�Ńv���[���[���쐬���܂��B
 * <br>
 * �v���[���[���쐬����ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���[�N�̈���m�ۂ�����@�ɂ́A�ȉ���2�ʂ�̕��@������܂��B<br>
 * <b>(a) User Allocator����</b>�F�������̊m�ہ^����ɁA���[�U���p�ӂ����֐����g�p������@�B<br>
 * <b>(b) Fixed Memory����</b>�F�K�v�ȃ������̈�𒼐ڃ��C�u�����ɓn�����@�B<br>
 * �e�����̏ڍׂɂ��ẮA�ʓr ::criAtomPlayer_CreateAdxPlayer �֐��̐��������Q�Ƃ��������B<br>
 * <br>
 * ::criAtomPlayer_CreateRawPcmPlayer �֐������s����ƁAAtom�v���[���[���쐬����A
 * �v���[���[�𐧌䂷�邽�߂̃n���h���i ::CriAtomPlayerHn �j���Ԃ���܂��B<br>
 * �f�[�^��f�R�[�_�[�̃Z�b�g�A�Đ��̊J�n�A�X�e�[�^�X�̎擾���AAtom�v���[���[�ɑ΂���
 * �s������́A�S�ăn���h���ɑ΂��čs���܂��B<br>
 * <br>
 * �쐬���ꂽAtom�v���[���[�n���h�����g�p���ĉ����f�[�^���Đ�����菇�͈ȉ��̂Ƃ���ł��B<br>
 * -# ::criAtomPlayer_SetData �֐����g�p���āAAtom�v���[���[�ɍĐ�����f�[�^���Z�b�g����B<br>
 * �i�t�@�C���Đ����́A ::criAtomPlayer_SetFile �֐��܂��� ::criAtomPlayer_SetContentId
 * �֐����g�p����B�j<br>
 * -# ::criAtomPlayer_Start �֐��ōĐ����J�n����B<br>
 * \par ���l:
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �X�g���[���Đ��p��Atom�v���[���[�́A�����I�Ƀ��[�_�[�i CriFsLoaderHn �j���m�ۂ��܂��B<br>
 * �X�g���[���Đ��p��Atom�v���[���[���쐬����ꍇ�A�v���[���[�n���h�������̃��[�_�[���m��
 * �ł���ݒ��Atom���C�u�����i�܂���CRI File System���C�u�����j������������
 * �K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * RawPCM�v���[���[�̍쐬�ɂ����鎞�Ԃ́A�v���b�g�t�H�[���ɂ���ĈقȂ�܂��B<br>
 * �Q�[�����[�v���̉�ʍX�V���K�v�ȃ^�C�~���O�Ŗ{�֐������s����ƃ~���b�P�ʂ�
 * �������u���b�N����A�t���[���������������鋰�ꂪ����܂��B<br>
 * RawPCM�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa CriAtomRawPcmPlayerConfig, criAtomPlayer_CalculateWorkSizeForRawPcmPlayer,
 * CriAtomPlayerHn, criAtomPlayer_Destroy,
 * criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_SetContentId,
 * criAtomPlayer_Start, criAtomPlayer_CreateRawPcmPlayer
 */
CriAtomPlayerHn CRIAPI criAtomPlayer_CreateRawPcmPlayer(
	const CriAtomRawPcmPlayerConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief Atom�v���[���[�̔j��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * Atom�v���[���[��j�����܂��B<br>
 * �{�֐������s�������_�ŁAAtom�v���[���[�쐬���Ɋm�ۂ��ꂽ���\�[�X���S�ĉ������܂��B<br>
 * �܂��A�����Ɏw�肵��Atom�v���[���[�n���h���������ɂȂ�܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �����Đ�����Atom�v���[���[��j�����悤�Ƃ����ꍇ�A�{�֐����ōĐ���~��
 * �҂��Ă��烊�\�[�X�̉�����s���܂��B<br>
 * �i�t�@�C������Đ����Ă���ꍇ�́A����ɓǂݍ��݊����҂����s���܂��B�j<br>
 * ���̂��߁A�{�֐����ŏ����������ԁi���t���[���j�u���b�N�����\��������܂��B<br>
 * Atom�v���[���[�̍쐬�^�j���́A�V�[���̐؂�ւ�蓙�A���וϓ������e�ł���
 * �^�C�~���O�ōs���悤���肢�������܂��B<br>
 * \sa criAtomPlayer_CreateAdxPlayer, CriAtomPlayerHn
 */
void CRIAPI criAtomPlayer_Destroy(CriAtomPlayerHn player);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�I���������f�[�^�̎w��j
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���[�n���h��
 * \param[in]	buffer			�o�b�t�@�[�A�h���X
 * \param[in]	buffer_size		�o�b�t�@�[�T�C�Y
 * \par ����:
 * ��������ɔz�u���ꂽ�����f�[�^���AAtom�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��Ń������A�h���X�ƃT�C�Y���w���A ::criAtomPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�f�[�^���Đ�����܂��B
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����f�[�^�̏��́A���̃f�[�^���Z�b�g�����܂�Atom�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * �f�[�^�v���R�[���o�b�N�֐��i ::CriAtomPlayerDataRequestCbFunc �j���Ŗ{�֐������s����ƁA
 * �O��Z�b�g���������̏I�[�ɘA�����Ď��̃f�[�^���Đ�����܂��B<br>
 * �Ⴆ�΁A�ȉ��̃R�[�h�����s����ƁAbuffer1�̃f�[�^��buffer2�̃f�[�^���V�[�����X��
 * �A�����čĐ�����܂��B<br>
 * �i���̌��buffer2�̃f�[�^���J��Ԃ��Đ�����܂��B�j<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �����čĐ�����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer2, buffer_size2);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 *
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer1, buffer_size1);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �f�[�^�v���R�[���o�b�N�֐����� ::criAtomPlayer_SetFile �֐������s���邱�ƂŁA
 * �I���������f�[�^�ƃt�@�C����A�����čĐ����邱�Ƃ��\�ł��B<br>
 * �i�������A��ɍĐ�����I���������f�[�^���Z������ꍇ�A���ɍĐ�����t�@�C����
 * �ǂݍ��݂��Ԃɍ��킸�A�������r�؂��\��������܂��B�j<br>
 * \attention
 * �v���[���[���L������̂̓o�b�t�@�[�̃A�h���X�ƃT�C�Y�݂̂ł��B<br>
 * �i�o�b�t�@�[���̃f�[�^���R�s�[�����킯�ł͂���܂���B�j<br>
 * ���̂��߁A�w�肵���f�[�^�̍Đ����I������܂ł̊ԁA
 * �A�v���P�[�V�������Ńo�b�t�@�[��ێ���������K�v������܂��B<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_SetData(
	CriAtomPlayerHn player, void *buffer, CriSint32 buffer_size);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�t�@�C���̎w��j
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	path		�t�@�C���p�X
 * \par ����:
 * �����t�@�C����Atom�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐��Ńt�@�C�����w���A ::criAtomPlayer_Start �֐��ōĐ����J�n����ƁA
 * �w�肳�ꂽ�t�@�C�����X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomPlayer_Start �֐����s��ł��B<br>
 * \par ��:
 * \code
 * main()
 * {
 * 		:
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetFile(player, NULL, "sample.adx");
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�Atom�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * �f�[�^�v���R�[���o�b�N�֐��i ::CriAtomPlayerDataRequestCbFunc �j���Ŗ{�֐������s����ƁA
 * �O��Z�b�g���������̏I�[�ɘA�����Ď��̃f�[�^���Đ�����܂��B<br>
 * �Ⴆ�΁A�ȉ��̃R�[�h�����s����ƁA"sample1.adx"��"sample2.adx"�Ƃ��V�[�����X��
 * �A�����čĐ�����܂��B<br>
 * �i���̌��"sample2.adx"���J��Ԃ��Đ�����܂��B�j<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �����čĐ�����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetFile(player, NULL, "sample2.adx");
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 *
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetFile(player, NULL, "sample1.adx");
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A�������ibinder�j�Ƀo�C���_�[���w�肷�邱�ƂŁA
 * CPK�t�@�C�����̃R���e���c���Đ����邱�Ƃ��\�ł��B<br>
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
 * 	// sample.cpk����content.adx���Z�b�g
 * 	criAtomPlayer_SetFile(player, binder, "content.adx");
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �f�[�^�v���R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐������s���邱�ƂŁA
 * �t�@�C���ƃI���������f�[�^��A�����čĐ����邱�Ƃ��\�ł��B
 * \attention
 * �t�@�C������̍Đ����s���ꍇ�ɂ́A�X�g���[�~���O�Đ��ɑΉ�����
 * Atom�v���[���[���g�p����K�v������܂��B<br>
 * �i ::CriAtomAdxPlayerConfig ��streaming_flag��CRI_TRUE��ݒ肵��
 * Atom�v���[���[���쐬����K�v������܂��B�j<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer, criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_SetFile(
	CriAtomPlayerHn player, CriFsBinderHn binder, const CriChar8 *path);

/*JP
 * \brief �����f�[�^�̃Z�b�g�iCPK�R���e���cID�̎w��j
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	binder		�o�C���_�[�n���h��
 * \param[in]	id			�R���e���cID
 * \par ����:
 * �R���e���c��Atom�v���[���[�Ɋ֘A�t���܂��B<br>
 * CRI File System���C�u�������g�p����CPK�t�@�C�����̃R���e���c�t�@�C����
 * ID�w��ōĐ����邽�߂Ɏg�p���܂��B<br>
 * �{�֐��Ƀo�C���_�[�ƃR���e���cID���w���A ::criAtomPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肳�ꂽ�R���e���c�t�@�C�����X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomPlayer_Start �֐����s��ł��B<br>
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
 * 	criAtomPlayer_SetContentId(player, binder, 1);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�Atom�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * �f�[�^�v���R�[���o�b�N�֐��i ::CriAtomPlayerDataRequestCbFunc �j���Ŗ{�֐������s����ƁA
 * �O��Z�b�g���������̏I�[�ɘA�����Ď��̃f�[�^���Đ�����܂��B<br>
 * �Ⴆ�΁A�ȉ��̃R�[�h�����s����ƁA1�Ԃ̃f�[�^��2�Ԃ̃f�[�^�Ƃ��V�[�����X��
 * �A�����čĐ�����܂��B<br>
 * �i���̌��2�Ԃ̃f�[�^���J��Ԃ��Đ�����܂��B�j<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �o�C���_�[�̎擾
 * 	binder = (CriFsBinderHn)obj;
 *
 * 	// �����čĐ�����t�@�C�����Z�b�g
 * 	// ���o�C���_�[����2�Ԃ̃R���e���c���Z�b�g
 * 	criAtomPlayer_SetContentId(player, binder, 2);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, binder);
 *
 * 	// �����t�@�C�����Z�b�g
 * 	// ���o�C���_�[����1�Ԃ̃R���e���c���Z�b�g
 * 	criAtomPlayer_SetContentId(player, binder, 1);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �f�[�^�v���R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐������s���邱�ƂŁA
 * �t�@�C���ƃI���������f�[�^��A�����čĐ����邱�Ƃ��\�ł��B
 * \attention
 * �t�@�C������̍Đ����s���ꍇ�ɂ́A�X�g���[�~���O�Đ��ɑΉ�����
 * Atom�v���[���[���g�p����K�v������܂��B<br>
 * �i ::CriAtomAdxPlayerConfig ��streaming_flag��CRI_TRUE��ݒ肵��
 * Atom�v���[���[���쐬����K�v������܂��B�j<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer, criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_SetContentId(
	CriAtomPlayerHn player, CriFsBinderHn binder, CriSint32 id);

/*JP
 * \brief �����f�[�^�̃Z�b�g�i�����f�[�^ID�̎w��j
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	awb			AWB�n���h��
 * \param[in]	id			�g�`�f�[�^ID
 * \par ����:
 * �Đ�����g�`�f�[�^��Atom�v���[���[�Ɋ֘A�t���܂��B<br>
 * �{�֐���AWB�n���h���Ɣg�`�f�[�^ID���w���A ::criAtomPlayer_Start �֐��ōĐ���
 * �J�n����ƁA�w�肵���g�`�f�[�^���X�g���[�~���O�Đ�����܂��B<br>
 * ���A�{�֐������s�������_�ł́A�t�@�C���̓ǂݍ��݂͊J�n����܂���B<br>
 * �t�@�C���̓ǂݍ��݂��J�n�����̂́A ::criAtomPlayer_Start �֐����s��ł��B<br>
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
 * 	criAtomPlayer_SetWaveId(player, awb, 1);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * ���A��U�Z�b�g�����t�@�C���̏��́A���̃f�[�^���Z�b�g�����܂�Atom�v���[���[���ɕێ�
 * ����܂��B<br>
 * ���̂��߁A�����f�[�^�����x���Đ�����ꍇ�ɂ́A�Đ����Ƀf�[�^���Z�b�g���Ȃ����K�v
 * �͂���܂���B
 * \par ���l:
 * �f�[�^�v���R�[���o�b�N�֐��i ::CriAtomPlayerDataRequestCbFunc �j���Ŗ{�֐������s����ƁA
 * �O��Z�b�g���������̏I�[�ɘA�����Ď��̃f�[�^���Đ�����܂��B<br>
 * �Ⴆ�΁A�ȉ��̃R�[�h�����s����ƁA1�Ԃ̃f�[�^��2�Ԃ̃f�[�^�Ƃ��V�[�����X��
 * �A�����čĐ�����܂��B<br>
 * �i���̌��2�Ԃ̃f�[�^���J��Ԃ��Đ�����܂��B�j<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// AWB�n���h���̎擾
 * 	awb = (CriAtomAwbHn)obj;
 *
 * 	// �����čĐ�����t�@�C�����Z�b�g
 * 	// ��AWB����2�Ԃ̔g�`�f�[�^���Z�b�g
 * 	criAtomPlayer_SetWaveId(player, awb, 2);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, awb);
 *
 * 	// �g�`�f�[�^���Z�b�g
 * 	// ��AWB����1�Ԃ̔g�`�f�[�^���Z�b�g
 * 	criAtomPlayer_SetWaveId(player, awb, 1);
 *
 * 	// �Z�b�g���ꂽ�g�`�f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �f�[�^�v���R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐������s���邱�ƂŁA
 * �t�@�C���ƃI���������f�[�^��A�����čĐ����邱�Ƃ��\�ł��B
 * \attention
 * �t�@�C������̍Đ����s���ꍇ�ɂ́A�X�g���[�~���O�Đ��ɑΉ�����
 * Atom�v���[���[���g�p����K�v������܂��B<br>
 * �i ::CriAtomAdxPlayerConfig ��streaming_flag��CRI_TRUE��ݒ肵��
 * Atom�v���[���[���쐬����K�v������܂��B�j<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer, criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_SetWaveId(
	CriAtomPlayerHn player, CriAtomAwbHn awb, CriSint32 id);

/*JP
 * \brief ���ꉹ���f�[�^�̍ăZ�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �O��Đ������f�[�^���A�ēx�Đ�����悤Atom�v���[���[�Ɏw�����܂��B<br>
 * \par ��:
 * �ȉ��̏����ɂ��A���ꉹ���f�[�^�𖳌��Ƀ��[�v�Đ��\�ł��B<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �O��Đ������f�[�^���ăZ�b�g
 * 	criAtomPlayer_SetPreviousDataAgain(player);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 *
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \attention
 * �{�֐��̓f�[�^�v���R�[���o�b�N�֐����ł̂ݎg�p���܂��B<br>
 * �i�f�[�^�v���R�[���o�b�N�֐��O�ł����s�\�ł����A���̏ꍇ���̌��ʂ�����܂���B�j<br>
 * \sa criAtomPlayer_SetDataRequestCallback
 */
void CRIAPI criAtomPlayer_SetPreviousDataAgain(CriAtomPlayerHn player);

/*JP
 * \brief �R�[���o�b�N�֐��̍Ď��s�v��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �f�[�^�v���R�[���o�b�N�֐��̏�����扄�΂����܂��B<br>
 * �f�[�^�v���R�[���o�b�N�֐������s���ꂽ���_�ŁA���ɍĐ����鉹���f�[�^��
 * �܂����܂��Ă��Ȃ��ꍇ�A�{�֐������s���邱�ƂŁA�R�[���o�b�N�֐������g���C
 * ���邱�Ƃ��\�ɂȂ�܂��B<br>
 * �i���~���b��ɍēx�f�[�^�v���R�[���o�b�N�֐����Ă΂�܂��B�j
 * \par ���l:
 * �f�[�^�v���R�[���o�b�N�֐����ŉ������Ȃ������ꍇ�AAtom�v���[���[�̃X�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYEND �ɑJ�ڂ��܂��B<br>
 * �������A�f�[�^�v���R�[���o�b�N�֐����Ŗ{�֐������s�����ꍇ�AAtom�v���[���[��
 * �X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING ���ێ��������܂��B
 * \attention
 * �{�֐������s�����ꍇ�AAtom�v���[���[�̃X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING
 * ���ێ��������܂����A�����o�͓͂r�؂��\��������܂��B<br>
 * �i�f�[�^�̓ǂݍ��݂��Ԃɍ���Ȃ��ꍇ�A�O��Đ����������ƁA���ɃZ�b�g���鉹��
 * �Ƃ̊ԂɁA����������\��������܂��B�j<br>
 * <br>
 * �{�֐��̓f�[�^�v���R�[���o�b�N�֐����ł̂ݎg�p�\�ł��B<br>
 * �i�f�[�^�v���R�[���o�b�N�֐��O�Ŏ��s�����ꍇ�A�G���[���������܂��B�j<br>
 * \sa criAtomPlayer_SetDataRequestCallback
 */
void CRIAPI criAtomPlayer_DeferCallback(CriAtomPlayerHn player);

/*JP
 * \brief �Đ��̊J�n
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �����f�[�^�̍Đ��������J�n���܂��B<br>
 * �{�֐������s����O�ɁA���O�� ::criAtomPlayer_SetData �֐������g�p���A�Đ�����
 * �����f�[�^��Atom�v���[���[�ɃZ�b�g���Ă����K�v������܂��B<br>
 * �Ⴆ�΁A�I���������̉����f�[�^���Đ�����ꍇ�ɂ́A�ȉ��̂悤�Ɏ��O��
 * ::criAtomPlayer_SetData �֐����g���ĉ����f�[�^���Z�b�g������A�{�֐������s����
 * �K�v������܂��B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �{�֐����s��A�Đ��̐i�݋�i�������J�n���ꂽ���A�Đ����������������j���ǂ��Ȃ���
 * ���邩�́A�X�e�[�^�X���擾���邱�ƂŊm�F���\�ł��B<br>
 * �X�e�[�^�X�̎擾�ɂ́A ::criAtomPlayer_GetStatus �֐����g�p���܂��B<br>
 * ::criAtomPlayer_GetStatus �֐��͈ȉ���5�ʂ�̃X�e�[�^�X��Ԃ��܂��B<br>
 * 	-# CRIATOMPLAYER_STATUS_STOP
 * 	-# CRIATOMPLAYER_STATUS_PREP
 * 	-# CRIATOMPLAYER_STATUS_PLAYING
 * 	-# CRIATOMPLAYER_STATUS_PLAYEND
 * 	-# CRIATOMPLAYER_STATUS_ERROR
 * 	
 * Atom�v���[���[���쐬�������_�ł́AAtom�v���[���[�̃X�e�[�^�X�͒�~���
 * �i CRIATOMPLAYER_STATUS_STOP �j�ł��B<br>
 * �Đ����鉹���f�[�^���Z�b�g��A�{�֐������s���邱�ƂŁAAtom�v���[���[�̃X�e�[�^�X��
 * ������ԁi CRIATOMPLAYER_STATUS_PREP �j�ɕύX����܂��B<br>
 * �iCRIATOMPLAYER_STATUS_PREP �́A�f�[�^������f�R�[�h�̊J�n��҂��Ă����Ԃł��B�j<br>
 * �Đ��̊J�n�ɏ[���ȃf�[�^���������ꂽ���_�ŁAAtom�v���[���[�̓X�e�[�^�X��
 * �Đ���ԁi CRIATOMPLAYER_STATUS_PLAYING �j�ɕύX���A�����̏o�͂��J�n���܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I����ƁAAtom�v���[���[�̓X�e�[�^�X���Đ��I�����
 * �i CRIATOMPLAYER_STATUS_PLAYEND �j�ɕύX���܂��B<br>
 * ���A�Đ����ɃG���[�����������ꍇ�ɂ́AAtom�v���[���[�̓X�e�[�^�X���G���[���
 * �i CRIATOMPLAYER_STATUS_ERROR �j�ɕύX���܂��B<br>
 * <br>
 * Atom�v���[���[�̃X�e�[�^�X���`�F�b�N���A�X�e�[�^�X�ɉ����ď�����؂�ւ��邱�ƂŁA
 * �����̍Đ���ԂɘA�������v���O�������쐬���邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�����̍Đ�������҂��ď�����i�߂����ꍇ�ɂ́A�ȉ��̂悤�ȃR�[�h�ɂȂ�܂��B
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 *
 * 	// �Đ������҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomPlayer_GetStatus(player);
 *
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMPLAYER_STATUS_PLAYEND) {
 * 			// �Đ��I�����̓��[�v�𔲂���
 * 			break;
 * 		}
 *
 * 		// �T�[�o�[�����̎��s
 * 		criAtom_ExecuteMain();
 *
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 * 		:
 * }
 * \endcode
 * \par ���l:
 * �Đ��J�n��A���ۂɉ������o�͂����܂łɂ́A�^�C�����O������܂��B<br>
 * �I���������̃f�[�^�Đ����i ::criAtomPlayer_SetData �֐��Ńf�[�^���Z�b�g�����ꍇ�j�́A
 * �{�֐����s��A�ŏ��ɃT�[�o�[���������s���ꂽ�^�C�~���O�ŃX�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYING �ɑJ�ڂ��܂��B<br>
 * �������A�X�g���[�~���O�Đ����́A�Đ����ێ����邽�߂ɕK�v�ȃf�[�^���[���o�b�t�@�����O
 * �����܂ł̊ԁACRIATOMPLAYER_STATUS_PREP ���ێ��������܂��B<br>
 * �i�K�v�[���ȃf�[�^���������ꂽ���_�ŁA CRIATOMPLAYER_STATUS_PLAYING �ɑJ�ڂ��܂��B�j<br>
 * <br>
 * ���A�X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING �ɑJ�ڂ���^�C�~���O�́A
 * �����܂�"�T�E���h���C�u�����ɑ΂��čĐ��w���𔭍s����"�^�C�~���O�ɂȂ�܂��B<br>
 * ���̂��߁A���ۂɃX�s�[�J�[���特���o��^�C�~���O�́A�e�v���b�g�t�H�[���̃T�E���h
 * ���C�u�����̏������ԂɈˑ����܂��B<br>
 * <br>
 * �X�g���[�~���O�Đ����ɔ������J�n�����^�C�~���O�́A�����ɃX�g���[�~���O�Đ����s��
 * �����̐���A�f�o�C�X�̓ǂݍ��ݑ��x�ɂ���ĕω����܂��B<br>
 * �X�g���[�~���O�Đ����ɈӐ}�Ƃ����^�C�~���O�Ŕ������J�n���������ꍇ�ɂ́A
 * ::criAtomPlayer_Pause �֐��Ŏ��O�Ƀ|�[�Y�������Ă����AAtom�v���[���[�̃X�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYING �ɑJ�ڂ������_�ŁA�|�[�Y���������Ă��������B<br>
 * �i�|�[�Y����������ԂŃX�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING �ɑJ�ڂ����ꍇ�A
 * �|�[�Y������ŏ��̃T�[�o�[���������s���ꂽ�^�C�~���O�ŁA�������J�n����܂��B<br>
 * <br>
 * ��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetData(player, NULL, "sample.adx");
 *
 * 	// �Đ��J�n�O�Ƀ|�[�Y�������Ă���
 * 	criAtomPlayer_Pause(player, CRI_TRUE);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 *
 * 	// �X�e�[�^�X��CRIATOMPLAYER_STATUS_PLAYING�ɑJ�ڂ���̂�҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomPlayer_GetStatus(player);
 *
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMPLAYER_STATUS_PLAYING) {
 * 			// CRIATOMPLAYER_STATUS_PLAYING��ԂɂȂ������_�Ń��[�v�𔲂���
 * 			break;
 * 		}
 *
 * 		// �T�[�o�[�����̎��s
 * 		criAtom_ExecuteMain();
 *
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 *
 * 	// �|�[�Y�̉���
 * 	// �����̃T�[�o�[���������s�����^�C�~���O�Ŕ������J�n�����
 * 	criAtomPlayer_Pause(player, CRI_FALSE);
 * 		:
 * }
 * \endcode
 * \attention
 * ���ɍĐ����J�n����Atom�v���[���[�ɑ΂��Ė{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * �iADX���C�u�����Ƃ͈قȂ�A�Đ�����Atom�v���[���[�ɑ΂��čēx�Đ��̊J�n���w�������ꍇ�A
 * �G���[�ɂȂ�܂��B�j<br>
 * Atom�v���[���[�ɑ΂��čĐ����w������ꍇ�ɂ́A�K�����O�ɃX�e�[�^�X���`�F�b�N���A
 * �X�e�[�^�X���������i CRIATOMPLAYER_STATUS_PREP �j��Đ����i CRIATOMPLAYER_STATUS_PLAYING �j
 * �ɂȂ��Ă��Ȃ����Ƃ����m�F���������B
 * \sa criAtomPlayer_SetData, criAtomPlayer_SetFile, criAtomPlayer_GetStatus,
 * criAtomPlayer_Pause, criAtom_ExecuteMain
 */
void CRIAPI criAtomPlayer_Start(CriAtomPlayerHn player);

/*JP
 * \brief �Đ��̒�~
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �Đ��̒�~�v���𔭍s���܂��B<br>
 * �����Đ�����Atom�v���[���[�ɑ΂��Ė{�֐������s����ƁAAtom�v���[���[�͍Đ����~
 * �i�t�@�C���̓ǂݍ��݂�A�������~�߂�j���A�X�e�[�^�X���~���
 * �i CRIATOMPLAYER_STATUS_STOP �j�ɑJ�ڂ��܂��B<br>
 * ���ɒ�~���Ă���Atom�v���[���[�i�X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYEND ��
 * CRIATOMPLAYER_STATUS_ERROR ��Atom�v���[���[�j �ɑ΂��Ė{�֐������s����ƁA
 * Atom�v���[���[�̃X�e�[�^�X�� CRIATOMPLAYER_STATUS_STOP �ɕύX���܂��B
 * \attention
 * �����Đ�����Atom�v���[���[�ɑ΂��Ė{�֐������s�����ꍇ�A�X�e�[�^�X��������
 * CRIATOMPLAYER_STATUS_STOP �ɂȂ�Ƃ͌���܂���B<br>
 * �i��~��ԂɂȂ�܂łɁA���Ԃ�������ꍇ������܂��B�j<br>
 * ���̂��߁A�{�֐��ōĐ����~��A�����ĕʂ̉����f�[�^���Đ�����ꍇ�ɂ́A
 * �K���X�e�[�^�X�� CRIATOMPLAYER_STATUS_STOP �ɑJ�ڂ������Ƃ��m�F���Ă���
 * ���̃f�[�^���Z�b�g�i�܂��͍Đ��̊J�n�j���s���Ă��������B<br>
 * <br>
 * \code
 * main()
 * {
 * 		:
 * 	// �Đ��̒�~��v��
 * 	criAtomPlayer_Stop(player);
 *
 * 	// �X�e�[�^�X��CRIATOMPLAYER_STATUS_STOP�ɑJ�ڂ���̂�҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomPlayer_GetStatus(player);
 *
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMPLAYER_STATUS_STOP) {
 * 			// CRIATOMPLAYER_STATUS_STOP��ԂɂȂ������_�Ń��[�v�𔲂���
 * 			break;
 * 		}
 *
 * 		// �T�[�o�[�����̎��s
 * 		criAtom_ExecuteMain();
 *
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 *
 * 	// �ʂ̉����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetData(player, NULL, "sample.adx");
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \sa criAtomPlayer_Start, criAtomPlayer_GetStatus
 */
void CRIAPI criAtomPlayer_Stop(CriAtomPlayerHn player);

/*JP
 * \brief �Đ��̃|�[�Y�^�|�[�Y����
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	flag		����t���O�iCRI_TRUE = �|�[�Y�ACRI_FALSE = �|�[�Y�����j
 * \par ����:
 * �Đ����|�[�Y�i�ꎞ��~�j������A�|�[�Y���������܂��B<br>
 * �|�[�Y���邩�A�|�[�Y���������邩�́A������flag�Ŏw�肵�܂��B<br>
 * flag��CRI_TRUE���w�肵���ꍇ�A�Đ��̓|�[�Y����܂��B<br>
 * flag��CRI_FALSE���w�肵���ꍇ�A�|�[�Y����������܂��B<br>
 * Atom�v���[���[���|�[�Y����Ă��邩�ǂ����� ::criAtomPlayer_IsPaused �֐����g�p����
 * ���ƂŊm�F���\�ł��B<br>
 * <br>
 * �{�֐��͎�Ɉȉ���2�ʂ�̗p�r�ɗ��p���܂��B<br>
 * 	- �����o�͂̈ꎞ��~�^�ꎞ��~�����B
 * 	- �X�g���[�~���O�Đ��̓��o���B
 * 	
 * <br>
 * �y�����o�͂̈ꎞ��~�^�ꎞ��~�����ɂ��āz
 * �Đ�����Atom�v���[���[�ɑ΂��ă|�[�Y���s���ƁA���̎��_�ŉ����̏o�͂𒆒f���܂��B<br>
 * �|�[�Y���ꂽAtom�v���[���[�ɑ΂��ă|�[�Y�������s���ƁA�|�[�Y���ɒ��f���ꂽ�ӏ�����
 * �Đ����ĊJ����܂��B<br>
 * <br>
 * �y�X�g���[�~���O�Đ��̓��o���ɂ��āz
 * �|�[�Y�����͍Đ��J�n�O��Atom�v���[���[�ɑ΂��Ă��L���ł��B<br>
 * �Đ��J�n�O��Atom�v���[���[�ɑ΂��ă|�[�Y���������ꍇ�A�|�[�Y���ꂽAtom�v���[���[��
 * ::criAtomPlayer_Start �֐��ōĐ��w�����Ă��A�����̏o�͍͂s���܂���B<br>
 * �������A�Đ������͍s���邽�߁A�f�[�^���[���ɋ�������Ă���΁A�X�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYING �܂őJ�ڂ��܂��B<br>
 * <br>
 * �X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING �̏�ԂŃ|�[�Y����Ă���Atom�v���[���[
 * �ɂ��ẮA�|�[�Y�������s�����^�C�~���O�Ŕ������J�n�����邱�Ƃ��\�ł��B<br>
 * ���̂��߁A�ȉ��̏����菇�𓥂ނ��ƂŁA�X�g���[�~���O�Đ��̔����^�C�~���O��
 * ���̃A�N�V�����ɓ��������邱�Ƃ��\�ł��B<br>
 * 	-# ::criAtomPlayer_Pause �֐���Atom�v���[���[���|�[�Y������B
 * 	-# ::criAtomPlayer_Start �֐���Atom�v���[���[�ɍĐ��J�n���w������B
 * 	-# Atom�v���[���[�̃X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYING �ɂȂ�̂�҂B
 * 	-# �������J�n�������^�C�~���O�� ::criAtomPlayer_Pause �֐������s���A�|�[�Y����������B
 * 	
 * <br>
 * ��̓I�ȃR�[�h�͈ȉ��̂Ƃ���ł��B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetData(player, NULL, "sample.adx");
 *
 * 	// �Đ��J�n�O�Ƀ|�[�Y�������Ă���
 * 	criAtomPlayer_Pause(player, CRI_TRUE);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 *
 * 	// �X�e�[�^�X��CRIATOMPLAYER_STATUS_PLAYING�ɑJ�ڂ���̂�҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomPlayer_GetStatus(player);
 *
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMPLAYER_STATUS_PLAYING) {
 * 			// CRIATOMPLAYER_STATUS_PLAYING��ԂɂȂ������_�Ń��[�v�𔲂���
 * 			break;
 * 		}
 *
 * 		// �T�[�o�[�����̎��s
 * 		criAtom_ExecuteMain();
 *
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 *
 * 	// �|�[�Y�̉���
 * 	// �����̃T�[�o�[���������s�����^�C�~���O�Ŕ������J�n�����
 * 	criAtomPlayer_Pause(player, CRI_FALSE);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * �����ɂ́A ::criAtomPlayer_Pause �֐����s��A�ŏ��ɃT�[�o�[���������삵�����_��
 * �|�[�Y�������s���܂��B<br>
 * ���̂��߁A�T�[�o�[���������s�����O�Ƀ|�[�Y�˃|�[�Y�����̑��삪�s��ꂽ�ꍇ��
 * �s���ƁA�������~�܂邱�ƂȂ��Đ����i�ނ��ƂɂȂ�܂��B
 * <br>
 * ���A�|�[�Y���ꂽAtom�v���[���[�ɑ΂��čēx�|�[�Y���s������A�|�[�Y����Ă��Ȃ�
 * Atom�v���[���[�ɑ΂��ă|�[�Y�������s���Ă��A�G���[�͔������܂���B<br>
 * �i�����������ꂸ�Ɋ֐��𔲂��܂��B�j
 * \sa criAtomPlayer_IsPaused, criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_Pause(CriAtomPlayerHn player, CriBool flag);

/*JP
 * \brief �|�[�Y����Ă��邩�ǂ����̃`�F�b�N
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriBool		�|�[�Y��ԁiCRI_TRUE = �|�[�Y����Ă���ACRI_FALSE = �|�[�Y����Ă��Ȃ��j
 * \par ����:
 * Atom�v���[���[���|�[�Y����Ă��邩�ǂ������`�F�b�N���܂��B<br>
 * �|�[�Y����Ă��邩�ǂ����́A������flag�ɃZ�b�g�����l�Ŕ��肵�܂��B<br>
 * flag��CRI_TRUE�������ꍇ�AAtom�v���[���[�̓|�[�Y����Ă��܂��B<br>
 * flag��CRI_FALSE�������ꍇ�AAtom�v���[���[�̓|�[�Y����Ă��܂���B<br>
 * \par ���l:
 * �{�֐��� ::criAtomPlayer_Pause �֐��Ŏw�肳�ꂽ����t���O�����̂܂ܕԂ��܂��B<br>
 * �i ::criAtomPlayer_Pause �֐��̑�2�����ɃZ�b�g�����l��flag�Ƃ��ĕԂ���܂��B�j<br>
 * ���̂��߁A�{�֐��̌��ʂƎ��ۂɉ����o�͂���~���Ă��邩�ǂ����́A�K��������v����Ƃ�
 * ����܂���B<br>
 * �i ::criAtomPlayer_Pause �֐��̎��s�^�C�~���O�ƁA���ۂɉ����o�͂���~����^�C�~���O��
 * �^�C�����O�����݂��邽�߁B�j
 * \sa criAtomPlayer_Pause
 */
CriBool CRIAPI criAtomPlayer_IsPaused(CriAtomPlayerHn player);

/*JP
 * \brief �X�e�[�^�X�̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriAtomPlayerStatus	�X�e�[�^�X
 * \par ����:
 * Atom�v���[���[�̃X�e�[�^�X���擾���܂��B<br>
 * �X�e�[�^�X��Atom�v���[���[�̍Đ���Ԃ������l�ŁA�ȉ���5�ʂ�̒l�����݂��܂��B<br>
 * -# CRIATOMPLAYER_STATUS_STOP
 * -# CRIATOMPLAYER_STATUS_PREP
 * -# CRIATOMPLAYER_STATUS_PLAYING
 * -# CRIATOMPLAYER_STATUS_PLAYEND
 * -# CRIATOMPLAYER_STATUS_ERROR
 * 
 * Atom�v���[���[���쐬�������_�ł́AAtom�v���[���[�̃X�e�[�^�X�͒�~���
 * �i ::CRIATOMPLAYER_STATUS_STOP �j�ł��B<br>
 * �Đ����鉹���f�[�^���Z�b�g��A::criAtomPlayer_Start �֐������s���邱�ƂŁA
 * Atom�v���[���[�̃X�e�[�^�X��������ԁi ::CRIATOMPLAYER_STATUS_PREP �j�ɕύX����܂��B<br>
 * �i ::CRIATOMPLAYER_STATUS_PREP �́A�f�[�^������f�R�[�h�̊J�n��҂��Ă����Ԃł��B�j<br>
 * �Đ��̊J�n�ɏ[���ȃf�[�^���������ꂽ���_�ŁAAtom�v���[���[�̓X�e�[�^�X��
 * �Đ���ԁi ::CRIATOMPLAYER_STATUS_PLAYING �j�ɕύX���A�����̏o�͂��J�n���܂��B<br>
 * �Z�b�g���ꂽ�f�[�^��S�čĐ����I����ƁAAtom�v���[���[�̓X�e�[�^�X���Đ��I�����
 * �i ::CRIATOMPLAYER_STATUS_PLAYEND �j�ɕύX���܂��B<br>
 * ���A�Đ����ɃG���[�����������ꍇ�ɂ́AAtom�v���[���[�̓X�e�[�^�X���G���[���
 * �i ::CRIATOMPLAYER_STATUS_ERROR �j�ɕύX���܂��B<br>
 * <br>
 * Atom�v���[���[�̃X�e�[�^�X���`�F�b�N���A�X�e�[�^�X�ɉ����ď�����؂�ւ��邱�ƂŁA
 * �����̍Đ���ԂɘA�������v���O�������쐬���邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�����̍Đ�������҂��ď�����i�߂����ꍇ�ɂ́A�ȉ��̂悤�ȃR�[�h�ɂȂ�܂��B
 * \code
 * main()
 * {
 * 		:
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 *
 * 	// �Đ������҂�
 * 	for (;;) {
 * 		// �X�e�[�^�X�̎擾
 * 		status = criAtomPlayer_GetStatus(player);
 *
 * 		// �X�e�[�^�X�̃`�F�b�N
 * 		if (status == CRIATOMPLAYER_STATUS_PLAYEND) {
 * 			// �Đ��I�����̓��[�v�𔲂���
 * 			break;
 * 		}
 *
 * 		// �T�[�o�[�����̎��s
 * 		criAtom_ExecuteMain();
 *
 * 		// ��ʕ\���̍X�V��
 * 			:
 * 	}
 * 		:
 * }
 * \endcode
 * \par ���l:
 * �f�o�C�X����̃f�[�^�ǂݍ��݂Ɏ��s�����ꍇ��A�f�[�^�G���[�����������ꍇ
 * �i�s���ȃf�[�^��ǂݍ��񂾏ꍇ�j�AAtom�v���[���[�̃X�e�[�^�X�̓G���[��ԂɂȂ�܂��B<br>
 * �f�[�^�ǂݍ��݃G���[�������ɃA�v���P�[�V�����ŃG���[���b�Z�[�W����\������ꍇ�ɂ́A
 * �X�e�[�^�X�� CRIATOMPLAYER_STATUS_ERROR �ɂȂ��Ă��Ȃ����ǂ������`�F�b�N���A
 * �K�X�G���[���b�Z�[�W�̕\�����s���Ă��������B<br>
 * \code
 * main()
 * {
 * 		:
 * 	// �X�e�[�^�X�̎擾
 * 	status = criAtomPlayer_GetStatus(player);
 *
 * 	// �X�e�[�^�X�̃`�F�b�N
 * 	if (status == CRIATOMPLAYER_STATUS_ERROR) {
 * 		// CRIATOMPLAYER_STATUS_ERROR�ɂȂ������_�ŃG���[���b�Z�[�W��\������
 * 			:
 * 	}
 * 		:
 * }
 * \endcode
 * \sa criAtomPlayer_Start
 */
CriAtomPlayerStatus CRIAPI criAtomPlayer_GetStatus(CriAtomPlayerHn player);

/*JP
 * \brief �`�����l�����̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriSint32	�`�����l����
 * \par ����:
 * Atom�v���[���[�ōĐ����̉����ɂ��āA�`�����l�������擾���܂��B<br>
 * <br>
 * �`�����l�������擾�ł��Ȃ������ꍇ�A�{�֐��� -1 ��Ԃ��܂��B<br>
 * \attention
 * �Đ������́A�v���[���[�̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING
 * �ɂȂ�܂Ŏ擾�ł��܂���B<br>
 * �i ::CRIATOMPLAYER_STATUS_PREP ���ɖ{�֐������s�����ꍇ�A�G���[�l���Ԃ���܂��B�j<br>
 */
CriSint32 CRIAPI criAtomPlayer_GetNumChannels(CriAtomPlayerHn player);

/*JP
 * \brief �Đ��ς݃T���v�����̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���[�n���h��
 * \param[out]	num_played		�Đ��ς݃T���v�����i�T���v�����P�ʁj
 * \param[out]	sampling_rate	�T���v�����O���[�g�iHz�P�ʁj
 * \return		CriBool			�T���v�������擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * Atom�v���[���[�ōĐ����̉����ɂ��āA�Đ��ς݂̃T���v�����A
 * ����уT���v�����O���[�g���擾���܂��B<br>
 * �Đ������̓T���v�����P�ʁA�T���v�����O���[�g��Hz�P�ʂł��B<br>
 * <br>
 * �T���v�������������擾�ł����ꍇ�A�߂�l�� CRI_TRUE �ɂȂ�܂��B<br>
 * �Đ��ς݃T���v�������擾�ł��Ȃ������ꍇ�A�߂�l�� CRI_FALSE �ɂȂ�܂��B<br>
 * �i�����ɁA sampling_rate �� -1 �ɂȂ�܂��B�j<br>
 * \par ���l
 * �擾����K�v�̂Ȃ������ɂ��ẮA NULL ���w��\�ł��B<br>
 * �Ⴆ�΁A�T���v�����O���[�g�݂̂��擾�������ꍇ�A��2�����i num_played �j
 * �ɂ� NULL ���w��\�ł��B
 * <br>
 * �{�֐����Ԃ��Đ��ς݃T���v�����́A�o�͍ς݉����f�[�^�̗ݐϒl�ł��B<br>
 * ���̂��߁A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����ăT���v�����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A ::criAtomPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ��ς݃T���v�����̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΃J�E���g�A�b�v���ĊJ����܂��B�j
 * \attention
 * �Đ��ς݃T���v�����́A�v���[���[�̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING
 * �ɂȂ�܂Ŏ擾�ł��܂���B<br>
 * �i ::CRIATOMPLAYER_STATUS_PREP ���ɖ{�֐������s�����ꍇ�A�G���[�l���Ԃ���܂��B�j<br>
 * <br>
 * �Đ��T���v�����̐��x�́A�v���b�g�t�H�[���̃T�E���h���C�u�����Ɉˑ����܂��B
 */
CriBool CRIAPI criAtomPlayer_GetNumPlayedSamples(
	CriAtomPlayerHn player, CriSint64 *num_played, CriSint32 *sampling_rate);

/*JP
 * \brief �T�E���h�o�b�t�@�ւ̏������݃T���v�����̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���n���h��
 * \param[out]	num_rendered	�������ݍς݃T���v�����i�T���v�����P�ʁj
 * \param[out]	sampling_rate	�T���v�����O���[�g�iHz�P�ʁj
 * \return		CriBool			�T���v�������擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * Atom�v���[���ōĐ����̉����ɂ��āA�T�E���h�o�b�t�@�ւ̏������ݍς݂̃T���v�����A
 * ����уT���v�����O���[�g���擾���܂��B<br>
 * ::criAtomPlayer_GetNumPlayedSamples �֐��ƈقȂ�A
 * �T�E���h�o�b�t�@�ɏ������܂ꂽ���o�͂̉����f�[�^�̃T���v�������܂ޒl��Ԃ��܂��B
 * <br>
 * �T���v�������������擾�ł����ꍇ�A�߂�l�� CRI_TRUE �ɂȂ�܂��B<br>
 * �������ݍς݃T���v�������擾�ł��Ȃ������ꍇ�A�߂�l�� CRI_FALSE �ɂȂ�܂��B<br>
 * �i�����ɁA sampling_rate �� -1 �ɂȂ�܂��B�j<br>
 * \par ���l
 * �擾����K�v�̂Ȃ������ɂ��ẮA NULL ���w��\�ł��B<br>
 * �Ⴆ�΁A�T���v�����O���[�g�݂̂��擾�������ꍇ�A��2�����i num_rendered �j
 * �ɂ� NULL ���w��\�ł��B
 * <br>
 * �{�֐����Ԃ��T���v�����́A�������ݍς݃T���v�����̗ݐϒl�ł��B<br>
 * ���̂��߁A���[�v�Đ���V�[�����X�A���Đ����s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����ăT���v�����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A ::criAtomPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �������ݍς݃T���v�����̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΃J�E���g�A�b�v���ĊJ����܂��B�j
 * \attention
 * �������ݍς݃T���v�����́A�v���[���̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING
 * �ɂȂ�܂Ŏ擾�ł��܂���B<br>
 * �i ::CRIATOMPLAYER_STATUS_PREP ���ɖ{�֐������s�����ꍇ�A�G���[�l���Ԃ���܂��B�j<br>
 * <br>
 * �������ݍς݃T���v�����̐��x�́A�v���b�g�t�H�[���̃T�E���h���C�u�����Ɉˑ����܂��B
 * \sa criAtomPlayer_GetNumPlayedSamples
 */
CriBool CRIAPI criAtomPlayer_GetNumRenderedSamples(
	CriAtomPlayerHn player, CriSint64 *num_rendered, CriSint32 *sampling_rate);

/*JP
 * \brief �f�R�[�h�f�[�^�T�C�Y�̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���[�n���h��
 * \return		CriSint64		�f�R�[�h�f�[�^�ʁi�P�ʂ̓o�C�g�j
 * \par ����:
 * Atom�v���[���[���Ńf�R�[�h���������f�[�^�̃o�C�g����Ԃ��܂��B<br>
 * \par ���l
 * �{�֐����Ԃ��f�R�[�h�ʂ́A�Đ��J�n���_����̗ݐϒl�ł��B<br>
 * ���̂��߁A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����ăf�R�[�h�ʂ������߂邱�Ƃ͂���܂���B<br>
 * �܂��A ::criAtomPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �f�R�[�h�ʂ̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΃J�E���g�A�b�v���ĊJ����܂��B�j
 * \attention
 * HCA-MX���g�p����ꍇ��A���k���ꂽ�����f�[�^�𒼐ڃn�[�h�E�F�A�ɑ��M����v���b�g�t�H�[��
 * �i�f�R�[�h�������v���b�g�t�H�[��SDK�ɉB������Ă���R�[�f�b�N�j
 * �ɂ��ẮA�{�֐��Ńf�R�[�h�ʂ��擾�ł��܂���B<br>
 */
CriSint64 CRIAPI criAtomPlayer_GetDecodedDataSize(CriAtomPlayerHn player);

/*JP
 * \brief �f�R�[�h�T���v�����̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���[�n���h��
 * \return		CriSint64		�f�R�[�h�T���v����
 * \par ����:
 * Atom�v���[���[���Ńf�R�[�h���������f�[�^�̃o�C�g����Ԃ��܂��B<br>
 * \par ���l
 * �{�֐����Ԃ��f�R�[�h�T���v�����́A�Đ��J�n���_����̗ݐϒl�ł��B<br>
 * ���̂��߁A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����ăf�R�[�h�T���v�����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A ::criAtomPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �f�R�[�h�T���v�����̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΃J�E���g�A�b�v���ĊJ����܂��B�j
 * \attention
 * HCA-MX���g�p����ꍇ��A���k���ꂽ�����f�[�^�𒼐ڃn�[�h�E�F�A�ɑ��M����v���b�g�t�H�[��
 * �i�f�R�[�h�������v���b�g�t�H�[��SDK�ɉB������Ă���R�[�f�b�N�j
 * �ɂ��ẮA�{�֐��Ńf�R�[�h�T���v�������擾�ł��܂���B<br>
 */
CriSint64 CRIAPI criAtomPlayer_GetNumDecodedSamples(CriAtomPlayerHn player);

/*JP
 * \brief �Đ������̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriSint64	�Đ������i�~���b�P�ʁj
 * \par ����:
 * Atom�v���[���[�ōĐ����̉����ɂ��āA���݂̍Đ��������擾���܂��B<br>
 * �Đ������̒P�ʂ̓~���b�P�ʂł��B<br>
 * <br>
 * �����Ɍ�肪����ꍇ�i player �� NULL �̏ꍇ�j�A�{�֐��� -1 ��Ԃ��܂��B<br>
 * ��~����Đ����������A�Đ��������擾�ł��Ȃ��^�C�~���O�Ŗ{�֐������s�����ꍇ�A
 * �{�֐��� 0 ��Ԃ��܂��B<br>
 * \par ���l
 * �Đ������͍Đ��ς݃T���v���������Ɍv�Z����Ă��܂��B<br>
 * ���̂��߁A ::criAtomPlayer_SetFrequencyRatio �֐���p���ăs�b�`���グ���ꍇ�A
 * �Đ������͎����Ԃ��������i�݂܂��B<br>
 * �i�s�b�`���������ꍇ�A�Đ������͎����������x���i�݂܂��B�j<br>
 * <br>
 * �{�֐����Ԃ��Đ������́A�o�͍ς݉����f�[�^�̗ݐϒl�ł��B<br>
 * ���̂��߁A���[�v�Đ�����A�V�[�����X�A���Đ������s�����ꍇ�ł��A
 * �Đ��ʒu�ɉ����Ď����������߂邱�Ƃ͂���܂���B<br>
 * �܂��A ::criAtomPlayer_Pause �֐��Ń|�[�Y���������ꍇ�A
 * �Đ������̃J�E���g�A�b�v����~���܂��B<br>
 * �i�|�[�Y����������΃J�E���g�A�b�v���ĊJ����܂��B�j
 * \attention
 * �Đ������́A�v���[���[�̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING
 * �ɂȂ�܂Ŏ擾�ł��܂���B<br>
 * �i ::CRIATOMPLAYER_STATUS_PREP ���ɖ{�֐������s�����ꍇ�A 0 ���Ԃ���܂��B�j<br>
 * <br>
 * �Đ������̐��x�́A�v���b�g�t�H�[���̃T�E���h���C�u�����Ɉˑ����܂��B
 * \sa criAtomPlayer_GetStatus, criAtomPlayer_SetFrequencyRatio
 */
CriSint64 CRIAPI criAtomPlayer_GetTime(CriAtomPlayerHn player);

/*JP
 * \brief �Đ������̃t�H�[�}�b�g���̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[out]	info		�t�H�[�}�b�g���
 * \return		CriBool		��񂪎擾�ł������ǂ����i CRI_TRUE = �擾�ł����A CRI_FALSE = �擾�ł��Ȃ������j
 * \par ����:
 * ::criAtomPlayer_Start �֐��ōĐ����ꂽ�����̃t�H�[�}�b�g�����擾���܂��B<br>
 * <br>
 * �t�H�[�}�b�g��񂪎擾�ł����ꍇ�A�{�֐��� CRI_TRUE ��Ԃ��܂��B<br>
 * �t�H�[�}�b�g��񂪎擾�ł��Ȃ������ꍇ�A�{�֐��� CRI_FALSE ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��́A�����Đ����̂݃t�H�[�}�b�g�����擾�\�ł��B<br>
 * �Đ��J�n�O��Đ��������ɖ{�֐������s����ƁA�t�H�[�}�b�g���̎擾�Ɏ��s���܂��B<br>
 * \sa criAtomPlayer_Start, criAtomPlayer_GetStatus
 */
CriBool CRIAPI criAtomPlayer_GetFormatInfo(
	CriAtomPlayerHn player, CriAtomFormatInfo *info);

/*JP
 * \brief ���̓o�b�t�@�[���f�[�^�c�ʂ̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriSint32	���̓o�b�t�@�[���̃f�[�^�c�ʁiByte�P�ʁj
 * \par ����:
 * Atom�v���[���[�̓��̓o�b�t�@�[���̃f�[�^�c�ʂ��擾���܂��B<br>
 * \par ���l:
 * �{�֐��͏��擾�p�r�ɂ݂̂ɗ��p�\�ȃf�o�b�O�֐��ł��B<br>
 * <br>
 * ���r�؂�̕s������������ہA�{�֐����g�p���čĐ����̃v���[���[��
 * ���̓o�b�t�@�[�Ƀf�[�^���c���Ă��邩�ǂ������`�F�b�N�\�ł��B<br>
 * �v���[���[�̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING �ɂ�������炸�A
 * �f�[�^�c�ʂ������� 0 �̏ꍇ�A���炩�ُ̈�ɂ��f�[�^�̋�����
 * �u���b�N����Ă���\��������܂��B<br>
 */
CriSint32 CRIAPI criAtomPlayer_GetInputBufferRemainSize(CriAtomPlayerHn player);

/*JP
 * \brief �o�̓o�b�t�@�[���f�[�^�c�ʂ̎擾
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriSint32	�o�̓o�b�t�@�[���̃f�[�^�c�ʁi�T���v�����P�ʁj
 * \par ����:
 * Atom�v���[���[�̏o�̓o�b�t�@�[���̃f�[�^�c�ʂ��擾���܂��B<br>
 * \par ���l:
 * �{�֐��͏��擾�p�r�ɂ݂̂ɗ��p�\�ȃf�o�b�O�֐��ł��B<br>
 * <br>
 * ���r�؂�̕s������������ہA�{�֐����g�p���čĐ����̃v���[���[��
 * �o�̓o�b�t�@�[�Ƀf�[�^���c���Ă��邩�ǂ������`�F�b�N�\�ł��B<br>
 * �v���[���[�̃X�e�[�^�X�� ::CRIATOMPLAYER_STATUS_PLAYING �ɂ�������炸�A
 * �f�[�^�c�ʂ������� 0 �̏ꍇ�A���炩�ُ̈�ɂ��f�R�[�h������
 * �s���Ă��Ȃ��\��������܂��B<br>
 * \attention
 * �{�֐��́A�����f�[�^��Atom���C�u�������Ńf�R�[�h����P�[�X�ɂ��Ă̂ݗL���ł��B<br>
 * ���k���ꂽ�����f�[�^�𒼐ڃn�[�h�E�F�A�ɑ��M����v���b�g�t�H�[��
 * �i�f�R�[�h�������v���b�g�t�H�[��SDK�ɉB������Ă���R�[�f�b�N�j
 * �ɂ��ẮA�{�֐��Ńf�[�^�c�ʂ��擾�ł��܂���B<br>
 */
CriSint32 CRIAPI criAtomPlayer_GetOutputBufferRemainSamples(CriAtomPlayerHn player);

/*JP
 * \brief �Đ��J�n�ʒu�̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	start_time_ms	�Đ��J�n�ʒu�i�~���b�w��j
 * \par ����:
 * Atom�v���[���[�ōĐ����鉹���ɂ��āA�Đ����J�n����ʒu���w�肵�܂��B<br>
 * �����f�[�^��r������Đ��������ꍇ�A�Đ��J�n�O�ɖ{�֐��ōĐ��J�n�ʒu��
 * �w�肷��K�v������܂��B<br>
 * <br>
 * �Đ��J�n�ʒu�̎w��̓~���b�P�ʂōs���܂��B<br>
 * �Ⴆ�΁A start_time_ms �� 10000 ���Z�b�g���Ė{�֐������s����ƁA
 * ���ɍĐ����鉹���f�[�^�� 10 �b�ڂ̈ʒu����Đ�����܂��B
 * \par ���l
 * �{�֐��ōĐ��ʒu���w�肵���ꍇ�ł��A�w�肵�������҂�����̈ʒu����Đ���
 * �J�n�����Ƃ͌���܂���B<br>
 * �i�g�p���鉹���R�[�f�b�N�ɂ���ẮA�w�莞���̏�����O����Đ����J�n����܂��B�j<br>
 * <br>
 * �����f�[�^�r������̍Đ��́A�����f�[�^�擪����̍Đ��ɔ�ׁA�����J�n��
 * �^�C�~���O���x���Ȃ�܂��B<br>
 * ����́A��U�����f�[�^�̃w�b�_�[����͌�A�w��ʒu�ɃW�����v���Ă���f�[�^��ǂ�
 * �����čĐ����J�n���邽�߂ł��B
 * \attention
 * start_time_ms �ɂ�64bit�l���Z�b�g�\�ł����A����A32bit�ȏ�̍Đ�������
 * �w�肷�邱�Ƃ͂ł��܂���B<br>
 * <br>
 * �����Đ����ɖ{�֐������s���Ă��A�Đ����̉����̍Đ��ʒu�͕ύX����܂���B<br>
 * �{�֐��Őݒ肵���l�́A ::criAtomPlayer_Start �֐��ŉ����̍Đ����J�n����
 * �^�C�~���O�ł̂ݎQ�Ƃ���܂��B<br>
 * <br>
 * �@��ŗL�̉����t�H�[�}�b�g�ɂ��Ă��A�Đ��J�n�ʒu���w��ł��Ȃ��ꍇ������܂��B<br>
 * \sa criAtomPlayer_Start
 */
void CRIAPI criAtomPlayer_SetStartTime(CriAtomPlayerHn player, CriSint64 start_time_ms);

/*JP
 * \brief �{�����[���̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	vol			�{�����[���l
 * \par ����:
 * �o�͉����̃{�����[�����w�肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁAAtom�v���[���[�ōĐ����鉹���̃{�����[�������R��
 * �ύX�\�ł��B<br>
 * <br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * (1.0f / 65536.0f) �ȉ��̒l���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B
 * \���l:
 * �{�����[���l�ɂ�0.0f�ȏ�̒l���ݒ�\�ł��B<br>
 * �iAtom���C�u���� Ver.1.21.07���A
 * �{�����[���l��1.0f�𒴂���l���w��ł���悤�ɂȂ�܂����B�j<br>
 * 1.0f�𒴂���l���Z�b�g�����ꍇ�A<b>�v���b�g�t�H�[���ɂ���Ă�</b>�A
 * �g�`�f�[�^�����f�ނ����傫�ȉ��ʂōĐ��\�ł��B<br>
 * �{�����[���l�� (1.0f / 65536.0f) �ȉ��̒l���w�肵���ꍇ�A�l��0.0f�ɃN���b�v����܂��B<br>
 * �i�{�����[���l�ɕ��̒l��ݒ肵���ꍇ�ł��A
 * �g�`�f�[�^�̈ʑ������]����邱�Ƃ͂���܂���B�j<br>
 * <br>
 * �{�֐��̐ݒ�l�ƁA�ȉ��̊֐��̃{�����[���ݒ�l�͓Ɨ����Đ��䂳��܂��B<br>
 * 	- ::criAtomPlayer_SetChannelVolume
 * 	- ::criAtomPlayer_SetSendLevel
 * 	
 * �Ⴆ�΁A�{�֐���0.5f���A ::criAtomPlayer_SetChannelVolume
 * �֐��ɂ�0.5f��ݒ肵���ꍇ�A
 * �o�͉����̃{�����[���͌�����0.25f�{�����{�����[���ŏo�͂���܂��B<br>
 * �i0.5f�~0.5f��0.25f�̉��Z���s���܂��B�j<br>
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
 * \sa criAtomPlayer_GetVolume
 */
void CRIAPI criAtomPlayer_SetVolume(CriAtomPlayerHn player, CriFloat32 vol);

/*JP
 * \brief �{�����[���̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \return		CriFloat32	�{�����[���l
 * \par ����:
 * �o�͉����̃{�����[�����擾���܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * \sa criAtomPlayer_SetVolume
 */
CriFloat32 CRIAPI criAtomPlayer_GetVolume(CriAtomPlayerHn player);

/*JP
 * \brief �`�����l���P�ʂ̃{�����[���w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	ch			�`�����l���ԍ�
 * \param[in]	vol			�{�����[���l�i0.0f�`1.0f�j
 * \par ����:
 * �o�͉����̃{�����[�����`�����l���P�ʂŎw�肵�܂��B<br>
 * �{�֐����g�p���邱�ƂŁAAtom�v���[���[�ōĐ����鉹���̃{�����[�����A
 * �`�����l���P�ʂŎ��R�ɕύX�\�ł��B<br>
 * <br>
 * ��2�����̃`�����l���ԍ���"�����f�[�^�̃`�����l���ԍ�"���w�肵�܂��B<br>
 * �i�o�̓X�s�[�J�[��ID�ł͂���܂���B�j<br>
 * �Ⴆ�΁A���m����������0�Ԃ̃{�����[����ύX�����ꍇ�A
 * �X�s�[�J�[����o�͂���鉹���̃{�����[���S�Ă��ύX����܂��B<br>
 * �i ::criAtomPlayer_SetVolume �֐������s����̂Ɠ�����������܂��B�j<br>
 * ����ɑ΂��A�X�e���I������0�Ԃ̃{�����[����ύX����ƁA�f�t�H���g�ݒ�
 * �ł̓��t�g�X�s�[�J�[����o�͂���鉹���̃{�����[���݂̂��ύX����܂��B<br>
 * �i ::criAtomPlayer_SetSendLevel �֐��𕹗p���Ă���ꍇ�́A
 * �K���������t�g�X�s�[�J�[����o�͂���鉹�ʂ̃{�����[�����ύX�����
 * �Ƃ͌���܂���B�j<br>
 * <br>
 * �{�����[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B
 * \���l:
 * �{�����[���l��1.0f�𒴂���l���w�肵���ꍇ�A�l��1.0f�ɃN���b�v����܂��B<br>
 * �i�������傫�ȉ��ʂŉ������Đ�����邱�Ƃ͂���܂���B�j<br>
 * ���l�ɁA�{�����[���l��0.0f�����̒l���w�肵���ꍇ���A�l��0.0f�ɃN���b�v����܂��B<br>
 * �i�ʑ������]����邱�Ƃ͂���܂���B�j
 * <br>
 * �{�֐��̐ݒ�l�ƁA�ȉ��̊֐��̃{�����[���ݒ�l�͓Ɨ����Đ��䂳��܂��B<br>
 * 	- ::criAtomPlayer_SetVolume
 * 	- ::criAtomPlayer_SetSendLevel
 * �Ⴆ�΁A�{�֐���0.5f���A ::criAtomPlayer_SetVolume �֐��ɂ�0.5f��ݒ肵���ꍇ�A
 * �o�͉����̃{�����[���͌�����0.25f�{�����{�����[���ŏo�͂���܂��B<br>
 * �i0.5f�~0.5f��0.25f�̉��Z���s���܂��B�j
 * \sa criAtomPlayer_SetVolume, criAtomPlayer_SetSendLevel, criAtomPlayer_SetPanAdx1Compatible
 */
void CRIAPI criAtomPlayer_SetChannelVolume(
	CriAtomPlayerHn player, CriSint32 ch, CriFloat32 vol);

/*JP
 * \brief �Z���h���x���̐ݒ�
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	ch			�`�����l���ԍ�
 * \param[in]	spk			�X�s�[�J�[ID
 * \param[in]	level		�{�����[���l�i0.0f�`1.0f�j
 * \par ����:
 * �Z���h���x�����w�肵�܂��B<br>
 * �Z���h���x���́A�����f�[�^�̊e�`�����l���̉������A�ǂ̃X�s�[�J�[����
 * �ǂ̒��x�̉��ʂŏo�͂��邩���w�肷�邽�߂̎d�g�݂ł��B<br>
 * <br>
 * ��2�����̃`�����l���ԍ���"�����f�[�^�̃`�����l���ԍ�"���w�肵�܂��B<br>
 * ��3�����̃X�s�[�J�[ID�ɂ́A�w�肵���`�����l���ԍ��̃f�[�^���ǂ̃X�s�[�J�[����
 * �o�͂��邩���w�肵�A��4�����̑��M���̃{�����[�����w�肵�܂��B<br>
 * �{�����[���l�́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B
 * <br>
 * �Ⴆ�΁A�����f�[�^�̃`�����l��0�Ԃ̃f�[�^�����C�g�X�s�[�J�[����
 * �t���{�����[���i1.0f�j�ŏo�͂������ꍇ�A�w��͈ȉ��̂悤�ɂȂ�܂��B
 * \code
 * criAtomPlayer_SetSendLevel(player, 0, CRIATOM_SPEAKER_FRONT_RIGHT, 1.0f);
 * \endcode
 * �`�����l���P�ʂ̃{�����[���w��i ::criAtomPlayer_SetChannelVolume �֐��j
 * �ƈقȂ�A�{�֐��ł�1�̃`�����l���̃f�[�^�𕡐��̃X�s�[�J�[����قȂ�
 * �{�����[���ŏo�͂��邱�Ƃ��\�ł��B<br>
 * �Ⴆ�΁A�`�����l��1�Ԃ̉��������t�g�X�s�[�J�[����0.3f�A���C�g�X�s�[�J�[
 * ����0.5f�A�Z���^�[�X�s�[�J�[����0.7f�ŏo�͂������ꍇ�A�w��͈ȉ��̂悤�ɂȂ�܂��B
 * \code
 * criAtomPlayer_SetSendLevel(player, 1, CRIATOM_SPEAKER_FRONT_LEFT, 0.3f);
 * criAtomPlayer_SetSendLevel(player, 1, CRIATOM_SPEAKER_FRONT_RIGHT, 0.5f);
 * criAtomPlayer_SetSendLevel(player, 1, CRIATOM_SPEAKER_FRONT_CENTER, 0.7f);
 * \endcode
 * ���A�Z�b�g���ꂽ�Z���h���x���̒l�� ::criAtomPlayer_ResetSendLevel �֐���
 * ���Z�b�g���邱�Ƃ��\�ł��B<br>
 * \���l:
 * �Z���h���x���̐ݒ�ɂ́u�����ݒ�v�u�蓮�ݒ�v��2�ʂ肪���݂��܂��B<br>
 * Atom�v���[���[���쐬���������A ::criAtomPlayer_ResetSendLevel �֐���
 * �Z���h���x�����N���A�����ꍇ�A�Z���h���x���̐ݒ�́u�����ݒ�v�ƂȂ�܂��B<br>
 * �{�֐������s�����ꍇ�A�Z���h���x���̐ݒ�́u�蓮�ݒ�v�ƂȂ�܂��B<br>
 * <br>
 * �u�����ݒ�v�̏ꍇ�AAtom�v���[���[�͈ȉ��̂悤�ɉ��������[�e�B���O���܂��B<br>
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
 * �y5ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������Z���^�[�X�s�[�J�[����A
 * �`�����l��3�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��4�̉������T���E���h���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * �i 5ch�������Đ�����ꍇ�A ::criAtom_SetChannelMapping
 * �֐��ŕʂ̕��я��ɕύX���邱�Ƃ��\�ł��B�j<br>
 * <br>
 * �y5.1ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������Z���^�[�X�s�[�J�[����A�`�����l��3�̉�����LFE����A
 * �`�����l��4�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��5�̉������T���E���h���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * �i 6ch�������Đ�����ꍇ�A ::criAtom_SetChannelMapping
 * �֐��ŕʂ̕��я��ɕύX���邱�Ƃ��\�ł��B�j<br>
 * <br>
 * �y7.1ch�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A�`�����l��1�̉��������C�g�X�s�[�J�[����A
 * �`�����l��2�̉������Z���^�[�X�s�[�J�[����A�`�����l��3�̉�����LFE����A
 * �`�����l��4�̉������T���E���h���t�g�X�s�[�J�[����A
 * �`�����l��5�̉������T���E���h���C�g�X�s�[�J�[����A<br>
 * �`�����l��6�̉������T���E���h�o�b�N���t�g�X�s�[�J�[����A
 * �`�����l��7�̉������T���E���h�o�b�N���C�g�X�s�[�J�[���炻�ꂼ��o�͂��܂��B<br>
 * <br>
 * ����ɑ΂��A�{�֐���p���āu�蓮�ݒ�v���s�����ꍇ�A�����f�[�^�̃`�����l������
 * �֌W�Ȃ��A�w�肳�ꂽ���[�e�B���O�ŉ������o�͂���܂��B<br>
 * �i�Z���h���x����ݒ肵�Ă��Ȃ��`�����l���̉����͏o�͂���܂���B�j<br>
 * �Z���h���x���̐ݒ���N���A���A���[�e�B���O���u�����ݒ�v�̏�Ԃɖ߂������ꍇ�́A
 * ::criAtomPlayer_ResetSendLevel �֐������s���Ă��������B<br>
 * <br>
 * �{�����[���l��1.0f�𒴂���l���w�肵���ꍇ�A�l��1.0f�ɃN���b�v����܂��B<br>
 * �i�������傫�ȉ��ʂŉ������Đ�����邱�Ƃ͂���܂���B�j<br>
 * ���l�ɁA�{�����[���l��0.0f�����̒l���w�肵���ꍇ���A�l��0.0f�ɃN���b�v����܂��B<br>
 * �i�ʑ������]����邱�Ƃ͂���܂���B�j
 * <br>
 * �{�֐��̐ݒ�l�ƁA�ȉ��̊֐��̃{�����[���ݒ�l�͓Ɨ����Đ��䂳��܂��B<br>
 * 	- ::criAtomPlayer_SetVolume
 * 	- ::criAtomPlayer_SetChannelVolume
 * �Ⴆ�΁A�{�֐���0.5f���A ::criAtomPlayer_SetVolume �֐��ɂ�0.5f��ݒ肵���ꍇ�A
 * �o�͉����̃{�����[���͌�����0.25f�{�����{�����[���ŏo�͂���܂��B<br>
 * �i0.5f�~0.5f��0.25f�̉��Z���s���܂��B�j
 * \attention
 * �Đ����鉹���f�[�^���}���`�`�����l���̃f�[�^�ł����Ă��A�Z���h���x�����ꕔ��
 * �`�����l���݂̂ɂ����ݒ肳��Ă��Ȃ��ꍇ�A�Z���h���x���̐ݒ肳��Ă��Ȃ�
 * �`�����l���̉����͏o�͂���܂���B<br>
 * <br>
 * �{�֐��� ::criAtomPlayer_SetPanAdx1Compatible �֐��𕹗p���Ȃ��ł��������B<br>
 * ::criAtomPlayer_SetPanAdx1Compatible �֐����A�����I�ɖ{�֐����Ăяo�����߁A
 * ���҂𕹗p�����ꍇ�A�ォ����s�����֐��ɂ��ݒ肪�㏑�������\��������܂��B<br>
 * �����̒�ʂ��R���g���[������ۂɂ́A�{�֐����܂��� ::criAtomPlayer_SetPanAdx1Compatible �֐�
 * �̂����ꂩ����݂̂������p���������B<br>
 * �i3D�p���𗘗p����ꍇ�͖{�֐����A2D�p���݂̂��s���ꍇ�� ::criAtomPlayer_SetPanAdx1Compatible
 * �֐��������p���������B�j
 * <br>
 * �{�֐��͈ꕔ�̋@��ł̂ݗ��p���\�ł��B<br>
 * �i�v���b�g�t�H�[���̃T�E���h���C�u�����̎d�l�ɂ���Ă͎���������ȏꍇ��
 * ���邽�߁A�S�Ă̊��ŗ��p�ł��郏�P�ł͂���܂���B�j<br>
 * �{�֐������p�\���ǂ����́A�ʓr�}�j���A���̋@��ˑ����̃y�[�W�����Q�Ƃ��������B
 * \sa criAtomPlayer_SetVolume, criAtomPlayer_SetChannelVolume, criAtomPlayer_SetPanAdx1Compatible,
 * criAtomPlayer_ResetSendLevel, criAtom_SetChannelMapping
 */
void CRIAPI criAtomPlayer_SetSendLevel(
	CriAtomPlayerHn player, CriSint32 ch, CriAtomSpeakerId spk, CriFloat32 level);

/*JP
 * \brief �Z���h���x���̃��Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �Z���h���x���̐ݒ�����Z�b�g���܂��B<br>
 * �{�֐������s���邱�ƂŁA�ߋ��ɃZ�b�g���ꂽ�Z���h���x���ݒ肪�S�ăN���A����܂��B<br>
 * \���l:
 * �Z���h���x���̐ݒ�ɂ́u�����ݒ�v�u�蓮�ݒ�v��2�ʂ肪���݂��܂��B<br>
 * Atom�v���[���[���쐬���������A�{�֐��ŃZ���h���x�������Z�b�g�����ꍇ�A
 * �Z���h���x���̐ݒ�́u�����ݒ�v�ƂȂ�܂��B<br>
 * �i�����ݒ莞�̃��[�e�B���O�ɂ��ẮA ::criAtomPlayer_SetSendLevel
 * �֐��̐������Q�Ƃ��Ă��������B�j<br>
 * \attention
 * �{�֐��� ::criAtomPlayer_ResetPan �֐��𕹗p���Ȃ��ł��������B<br>
 * ::criAtomPlayer_ResetPan �֐����A�����I�ɖ{�֐����Ăяo�����߁A
 * ���҂𕹗p�����ꍇ�A�ォ����s�����֐��ɂ��ݒ肪�㏑�������\��������܂��B
 * \sa criAtomPlayer_SetSendLevel, criAtomPlayer_ResetPan
 */
void CRIAPI criAtomPlayer_ResetSendLevel(CriAtomPlayerHn player);

/*JP
 * \brief �p���̐ݒ�
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	ch			�`�����l���ԍ�
 * \param[in]	pan			�p���ݒ�l�i-1.0f�`1.0f�j
 * \par ����:
 * �p���i�����̒�ʈʒu�j���w�肵�܂��B<br>
 * �{�֐������s���邱�ƂŁA���m����������X�e���I�����ɑ΂��A�����̒�ʈʒu�����R
 * �ɃR���g���[�����邱�Ƃ��\�ł��B<br>
 * <br>
 * ��2�����̃`�����l���ԍ���"�����f�[�^�̃`�����l���ԍ�"���w�肵�܂��B<br>
 * ��3�����̃p���ݒ�l�ɂ́A�w�肵���`�����l���ԍ��̃f�[�^�̒�ʂ��ǂ̈ʒu�ɂ���
 * �����w�肵�܂��B<br>
 * �p���ݒ�l�́A-1.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �����́A���̒l���w�肷��ƒ�����荶���i�l���������قǍ����j�A0.0f���w�肷���
 * �����A���̒l���w�肷��ƒ������E���i�l���傫���قǉE���j�ɒ�ʂ��܂��B<br>
 * �i�L���̂����l�ł́A-1.0f�����[�A0.0f�������A1.0f���E�[�ɂȂ�܂��B�j<br>
 * -1.0f��1.0f�̊Ԃł́A�����̈ʒu�̓��j�A�ɕω����܂��B
 * �܂�A�p���ݒ�l�����ʂ��ω������Ȃ���-1.0�`1.0�܂ŕύX�����ꍇ�A
 * �����͍��[����E�[�ֈ�葬�x�ňړ����邱�ƂɂȂ�܂��B<br>
 * \par ���l:
 * �p���̐ݒ�ɂ́u�����ݒ�v�u�蓮�ݒ�v��2�ʂ肪���݂��܂��B<br>
 * Atom�v���[���[���쐬���������A ::criAtomPlayer_ResetPan �֐���
 * �p�����N���A�����ꍇ�A�p���̐ݒ�́u�����ݒ�v�ƂȂ�܂��B<br>
 * �{�֐������s�����ꍇ�A�p���̐ݒ�́u�蓮�ݒ�v�ƂȂ�܂��B<br>
 * <br>
 * �u�����ݒ�v�̏ꍇ�AAtom�v���[���[�͈ȉ��̂悤�ɉ��������[�e�B���O���܂��B<br>
 * <br>
 * �y���m�����������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������E�̃X�s�[�J�[�����0.7f�i-3dB�j�̃{�����[���ŏo�͂��܂��B<br>
 * <br>
 * �y�X�e���I�������Đ�����ꍇ�z<br>
 * �`�����l��0�̉��������t�g�X�s�[�J�[����A
 * �`�����l��1�̉��������C�g�X�s�[�J�[����o�͂��܂��B<br>
 * <br>
 * ����ɑ΂��A�{�֐���p���āu�蓮�ݒ�v���s�����ꍇ�A�����f�[�^�̃`�����l������
 * �֌W�Ȃ��A�w�肳�ꂽ���[�e�B���O�ŉ������o�͂���܂��B<br>
 * �p���̐ݒ���N���A���A���[�e�B���O���u�����ݒ�v�̏�Ԃɖ߂������ꍇ�́A
 * ::criAtomPlayer_ResetPan �֐������s���Ă��������B<br>
 * \attention
 * �{�֐��Ńp�����R���g���[���\�Ȃ̂́A���m���������ƃX�e���I�����݂̂ł��B<br>
 * 3ch�ȏ�̉����ɑ΂��ăp�����R���g���[���������ꍇ�ɂ́A ::criAtomPlayer_SetSendLevel
 * �֐����g�p����K�v������܂��B<br>
 * <br>
 * �Đ����鉹���f�[�^���X�e���I�̏ꍇ�A�`�����l��0�Ԃƃ`�����l��1�Ԃ̂��ꂼ���
 * �ɂ��āA�Ɨ����ăp�����R���g���[�����邱�Ƃ��\�ł��B<br>
 * �������A�ݒ肳�ꂽ�p�������m�������������Ȃ̂��A�X�e���I���������Ȃ̂��͋��
 * ����Ȃ����߁A�X�e���I�ݒ�p�Ƀp���ݒ���s����Atom�v���[���[�Ń��m�����������Đ�
 * �����ꍇ�A�Ӑ}�Ƃ��Ȃ��ʒu�ɉ�������ʂ���\��������܂��B<br>
 * <br>
 * �Đ����鉹���f�[�^���X�e���I�ɂ�������炸�A�ǂ��炩����̃`�����l���ɑ΂���
 * �����p�����ݒ肳��Ă��Ȃ��ꍇ�A�p����ݒ肵�Ă��Ȃ��`�����l���̉����̒�ʈʒu
 * �� 0.0f �i��������̏o�́j�ɂȂ�܂��B<br>
 * �X�e���I�����̃p�����R���g���[������ۂɂ́A�K�������̃`�����l���ɂ��ăp����
 * �ݒ���s���Ă��������B<br>
 * <br>
 * �{�֐��� ::criAtomPlayer_SetSendLevel �֐��𕹗p���Ȃ��ł��������B<br>
 * �{�֐��������I�� ::criAtomPlayer_SetSendLevel �֐����Ăяo�����߁A
 * ���҂𕹗p�����ꍇ�A�ォ����s�����֐��ɂ��ݒ肪�㏑�������\��������܂��B<br>
 * �����̒�ʂ��R���g���[������ۂɂ́A�{�֐����܂��� ::criAtomPlayer_SetSendLevel �֐�
 * �̂����ꂩ����݂̂������p���������B<br>
 * �i3D�p���𗘗p����ꍇ�� ::criAtomPlayer_SetSendLevel �֐����A2D�p���݂̂��s���ꍇ��
 * �{�֐��������p���������B�j
 * \sa criAtomPlayer_SetVolume, criAtomPlayer_SetChannelVolume, criAtomPlayer_SetPanAdx1Compatible
 * criAtomPlayer_ResetPan
 */
void CRIAPI criAtomPlayer_SetPanAdx1Compatible(
	CriAtomPlayerHn player, CriSint32 ch, CriFloat32 pan);

/*JP
 * \brief �p���̃��Z�b�g
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \par ����:
 * �p���̐ݒ�����Z�b�g���܂��B<br>
 * �{�֐������s���邱�ƂŁA�ߋ��ɃZ�b�g���ꂽ�p���ݒ肪�S�ăN���A����܂��B<br>
 * \���l:
 * �p���̐ݒ�ɂ́u�����ݒ�v�u�蓮�ݒ�v��2�ʂ肪���݂��܂��B<br>
 * Atom�v���[���[���쐬���������A�{�֐��Ńp�������Z�b�g�����ꍇ�A
 * �p���̐ݒ�́u�����ݒ�v�ƂȂ�܂��B<br>
 * �i�����ݒ莞�̃��[�e�B���O�ɂ��ẮA ::criAtomPlayer_SetPanAdx1Compatible
 * �֐��̐������Q�Ƃ��Ă��������B�j<br>
 * \attention
 * �{�֐��� ::criAtomPlayer_ResetSendLevel �֐��𕹗p���Ȃ��ł��������B<br>
 * �{�֐��������I�� ::criAtomPlayer_ResetSendLevel �֐����Ăяo�����߁A
 * ���҂𕹗p�����ꍇ�A�ォ����s�����֐��ɂ��ݒ肪�㏑�������\��������܂��B
 * \sa criAtomPlayer_SetPanAdx1Compatible, criAtomPlayer_ResetSendLevel
 */
void CRIAPI criAtomPlayer_ResetPan(CriAtomPlayerHn player);

/*JP
 * \brief ���g��������̐ݒ�
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	ratio		���g��������
 * \par ����:
 * �����̎��g���������ݒ肵�܂��B<br>
 * ���g��������́A�����f�[�^�̎��g���ƍĐ����g���̔䗦�ŁA�Đ����x�̔{���Ɠ����ł��B<br>
 * ���g���䂪1.0f�𒴂���ꍇ�A�����f�[�^�͌�����荂���ɍĐ�����A
 * 1.0f�����̏ꍇ�́A�����f�[�^�͌������ᑬ�ōĐ�����܂��B<br>
 * <br>
 * ���g����́A�����̃s�b�`�ɂ��e�����܂��B<br>
 * �Ⴆ�΁A���g�����1.0f�ōĐ������ꍇ�A�����f�[�^�͌����ʂ�̃s�b�`�ōĐ�����܂����A
 * ���g�����2.0f�ɕύX�����ꍇ�A�s�b�`��1�I�N�^�[�u�オ�܂��B<br>
 * �i�Đ����x��2�{�ɂȂ邽�߁B�j<br>
 * \par ��:
 * \code
 * // 1/2�̑��x�i-1�I�N�^�[�u�j�ŉ������Đ�����悤�w��
 * criAtomPlayer_SetFrequencyRatio(player, 0.5f);
 * \endcode
 * \attention
 * ���g�����1.0f�𒴂���l��ݒ肵���ꍇ�A�Đ����鉹���̃f�[�^���ʏ���
 * ���������邽�߁A�����f�[�^�̋�����A�f�[�^�̃f�R�[�h���Ԃɍ���Ȃ��Ȃ�
 * �\��������܂��B<br>
 * �i���؂ꓙ�̖�肪��������\��������܂��B�j<br>
 * ���g�����1.0f�𒴂���l��ݒ肷��ꍇ�ɂ́AAtom�v���[���[�쐬���Ɏw�肷��
 * �ő�T���v�����O���[�g�̒l���A���g������l�������l�ɐݒ肵�Ă��������B<br>
 * �iAtom�v���[���[�쐬���Ɏw�肷�� ::CriAtomAdxPlayerConfig �\����
 * �� max_sampling_rate �̒l�ɁA�u�����̃T���v�����O���[�g�~���g����v��
 * �v�Z�����l���w�肷��K�v������܂��B�j<br>
 * \code
 * main()
 * {
 * 	CriAtomAdxPlayerConfig config;	// Atom�v���[���[�쐬�p�R���t�B�O�\����
 * 	CriAtomAdxPlayerHn player;		// Atom�v���[���[�n���h��
 * 		:
 * 	// Atom�v���[���[�쐬�p�R���t�B�O�\���̂�ݒ�
 * 	memset(&config, 0, sizeof(config));
 * 	config.max_channels = 2;			// �X�e���I�Đ��\�ȃv���[���[���쐬����
 *
 * 	// 48000Hz�̉�����1.5�{���ōĐ�����ꍇ
 * 	// 48000�~1.5��72000Hz�̐ݒ��Atom�v���[���[���쐬����
 * 	config.max_sampling_rate = 72000;	// �ő��72000Hz�̉������Đ�����
 *
 * 	// Atom�v���[���[�̍쐬
 * 	// ���[�N�̈�ɂ�NULL��0���w�肷��B
 * 	// ���K�v�ȃ������̓��C�u�������œ��I�Ɋm�ۂ����B
 * 	player = criAtomPlayer_CreateAdxPlayer(&config, NULL, 0);
 * 		:
 * 	// ���g�����ύX����
 * 	criAtomPlayer_SetFrequencyRatio(player, 1.5f);
 * 		:
 * }
 * \endcode
 * �{�֐��͈ꕔ�̋@��ł̂ݗ��p���\�ł��B<br>
 * �i�v���b�g�t�H�[���̃T�E���h���C�u�����̎d�l�ɂ���Ă͎���������ȏꍇ��
 * ���邽�߁A�S�Ă̊��ŗ��p�ł��郏�P�ł͂���܂���B�j<br>
 * �{�֐������p�\���ǂ����́A�ʓr�}�j���A���̋@��ˑ����̃y�[�W�����Q�Ƃ��������B
 * \sa CriAtomAdxPlayerConfig, criAtomPlayer_CreateAdxPlayer, criAtomPlayer_SetMaxFrequencyRatio
 */
void CRIAPI criAtomPlayer_SetFrequencyRatio(CriAtomPlayerHn player, CriFloat32 ratio);

/*JP
 * \brief �ő���g��������̐ݒ�
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	ratio		�ő���g��������
 * \par ����:
 * �����̍ő���g���������ݒ肵�܂��B<br>
 * �{�֐��ōő���g����������w�肷�邱�ƂŁA�w��͈͓��ł̃s�b�`�ύX�������ɔ��f�����悤�ɂȂ�܂��B<br>
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
 * �{�֐��ōő���g������������炩���ߐݒ肵���ꍇ�A
 * �w�肳�ꂽ���x��z�肵�ď�Ƀo�b�t�@�����O���s����悤�ɂȂ邽�߁A
 * �i�w�肳�ꂽ�͈͓��̎��g���ɂ����Ắj�o�b�t�@�����O�Ȃ��Ƀs�b�`�ύX�������ɍs���܂��B<br>
 * �Z���ԂɃs�b�`���グ��������P�[�X�ɂ��ẮA
 * �\�z�����ő���g������������炩���ߖ{�֐��Őݒ肵�Ă���Đ����s���Ă��������B<br>
 * \sa criAtomPlayer_SetFrequencyRatio
 */
void CRIAPI criAtomPlayer_SetMaxFrequencyRatio(CriAtomPlayerHn player, CriFloat32 ratio);

/*JP
 * \brief ���[�v�񐔂̐���
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	count		���[�v������
 * \par ����:
 * �g�`�f�[�^�̃��[�v�Đ��񐔂𐧌����܂��B<br>
 * �Ⴆ�΁Acount��1���w�肵���ꍇ�A���[�v�g�`�f�[�^��1��̂݃��[�v���čĐ����I�����܂��B<br>
 * �i���[�v�G���h�|�C���g�ɓ��B��A1�񂾂����[�v�X�^�[�g�ʒu�ɖ߂�܂��B�j<br>
 * \par ���l:
 * �f�t�H���g��Ԃł́A���[�v�|�C���g�t���̉����f�[�^�͖����Ƀ��[�v�Đ�����܂��B<br>
 * ���[�v�񐔂���U����������A���[�v�񐔂��ēx������ɖ߂������ꍇ�ɂ́A
 * count �� ::CRIATOMPLAYER_NO_LOOP_LIMITATION ���w�肵�Ă��������B<br>
 * <br>
 * count �� ::CRIATOMPLAYER_IGNORE_LOOP ���w�肷�邱�ƂŁA
 * ���[�v�|�C���g�t���̉����f�[�^�����[�v�������ɍĐ����邱�Ƃ��\�ł��B<br>
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
 * 	- �{�֐��� ::CRIATOMPLAYER_IGNORE_LOOP ���w�肵�Ă���Đ����s���B
 * 	
 * <br>
 * �{�֐��Ń��[�v�񐔂𐧌��ł���̂́AADX�R�[�f�b�N��HCA�R�[�f�b�N�݂̂ł��B<br>
 * �v���b�g�t�H�[���ˑ��̉����R�[�f�b�N�ɑ΂��Ė{�֐������s���Ȃ��ł��������B<br>
 * �i�Đ����I�����Ȃ��A�m�C�Y���������铙�̖�肪�������܂��B�j<br>
 */
void CRIAPI criAtomPlayer_LimitLoopCount(CriAtomPlayerHn player, CriSint32 count);

/*JP
 * \brief HCA-MX�f�R�[�h��~�L�TID�̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	mixer_id	�~�L�TID
 * \par ����:
 * HCA-MX�̃f�R�[�h��~�L�TID���w�肵�܂��B<br>
 * \attention
 * �{�֐��� ::criAtomPlayer_CreateHcaMxPlayer
 * �֐��ō쐬���ꂽ�v���[���[�ɑ΂��Ă̂݌��ʂ�����܂��B<br>
 * �i���̊֐��ō쐬���ꂽ�v���[���[�ɑ΂��ẮA���̌��ʂ�����܂���B�j<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa criAtomPlayer_CreateHcaMxPlayer
 */
void CRIAPI criAtomPlayer_SetHcaMxMixerId(CriAtomPlayerHn player, CriSint32 mixer_id);

/*JP
 * \brief ASR���b�NID�̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	rack_id		���b�NID
 * \par ����:
 * �{�C�X�̏o�͐�̃��b�NID���w�肵�܂��B<br>
 * \attention
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 */
void CRIAPI criAtomPlayer_SetAsrRackId(CriAtomPlayerHn player, CriSint32 rack_id);

/*JP
 * \brief RawPCM�t�H�[�}�b�g�̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player			Atom�v���[���[�n���h��
 * \param[in]	pcm_format		RawPCM�̃f�[�^�t�H�[�}�b�g
 * \param[in]	num_channels	�`�����l����
 * \param[in]	sampling_rate	�T���v�����O���[�g
 * \par ����:
 * RawPCM�̃f�[�^�t�H�[�}�b�g�����w�肵�܂��B<br>
 * \attention
 * �{�֐��� ::criAtomPlayer_CreateRawPcmPlayer
 * �֐��ō쐬���ꂽ�v���[���[�ɑ΂��Ă̂݌��ʂ�����܂��B<br>
 * �i���̊֐��ō쐬���ꂽ�v���[���[�ɑ΂��ẮA���̌��ʂ�����܂���B�j<br>
 * <br>
 * �{�֐��͒�~���̃v���[���[�ɑ΂��Ă̂ݎ��s�\�ł��B<br>
 * \sa criAtomPlayer_CreateRawPcmPlayer
 */
void CRIAPI criAtomPlayer_SetRawPcmFormat(CriAtomPlayerHn player,
	CriAtomPcmFormat pcm_format, CriSint32 num_channels, CriSint32 sampling_rate);

/*JP
 * \brief �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	func		�f�[�^�v���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�[�^�v���R�[���o�b�N�֐��̓o�^���s���܂��B<br>
 * <br>
 * �f�[�^�v���R�[���o�b�N�́A�����̉����f�[�^���V�[�����X�ɘA�����čĐ�����ۂ�
 * �g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[���A���Đ��p�̃f�[�^��v������^�C�~���O��
 * ���s����܂��B<br>
 * �i�O��̃f�[�^��ǂݍ��ݏI���āA���ɍĐ����ׂ��f�[�^��v������^�C�~���O��
 * �R�[���o�b�N�֐������s����܂��B�j<br>
 * �o�^�����R�[���o�b�N�֐����� ::criAtomPlayer_SetData �֐�����p����Atom�v���[���[��
 * �f�[�^���Z�b�g����ƁA�Z�b�g���ꂽ�f�[�^�͌��ݍĐ����̃f�[�^�ɑ����ăV�[�����X��
 * �A������čĐ�����܂��B<br>
 * �܂��A�R�[���o�b�N�֐����� ::criAtomPlayer_SetPreviousDataAgain �֐������s���邱�ƂŁA
 * ����f�[�^���J��Ԃ��Đ��������邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * �o�^�����R�[���o�b�N�֐����Ńf�[�^���w�肵�Ȃ������ꍇ�A���݂̃f�[�^���Đ���
 * �I�������_�ŁAAtom�v���[���[�̃X�e�[�^�X�� CRIATOMPLAYER_STATUS_PLAYEND �ɑJ�ڂ��܂��B<br>
 * <br>
 * �^�C�~���O���̖��ɂ��A�f�[�^���w�肷�邱�Ƃ��ł��Ȃ����A�X�e�[�^�X��
 * CRIATOMPLAYER_STATUS_PLAYEND �ɑJ�ڂ��������Ȃ��ꍇ�ɂ́A�R�[���o�b�N�֐�����
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
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �����čĐ�����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer2, buffer_size2);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 *
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer1, buffer_size1);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * �ȉ��̏����ɂ��A���ꉹ���f�[�^�𖳌��Ƀ��[�v�Đ��\�ł��B<br>
 * \code
 * // �f�[�^�v���R�[���o�b�N�֐�
 * void on_data_request(void *obj, CriAtomPlayerHn player)
 * {
 * 	// �O��Đ������f�[�^���ăZ�b�g
 * 	criAtomPlayer_SetPreviousDataAgain(player);
 * }
 *
 * main()
 * {
 * 		:
 * 	// �f�[�^�v���R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetDataRequestCallback(player, on_data_request, NULL);
 *
 * 	// �����f�[�^���Z�b�g
 * 	criAtomPlayer_SetData(player, buffer, buffer_size);
 *
 * 	// �Z�b�g���ꂽ�����f�[�^���Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \attention
 * �f�[�^�v���R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪
 * �������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �V�[�����X�A���Đ����T�|�[�g���Ȃ��R�[�f�b�N���g�p���Ă���ꍇ�A
 * �f�[�^�v���R�[���o�b�N�֐����Ŏ��̃f�[�^���Z�b�g���Ă��A
 * �f�[�^�͑����čĐ�����܂���B<br>
 * �iHCA-MX��v���b�g�t�H�[���ŗL�̉������k�R�[�f�b�N���g�p���Ă���ꍇ�A
 * �V�[�����X�A���Đ��͂ł��܂���B�j<br>
 * <br>
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
 * �R�[���o�b�N�֐�����Atom�v���[���[��j�����Ȃ��ł��������B<br>
 * �R�[���o�b�N�𔲂�������A���΂炭�̊Ԃ̓T�[�o�[�������œ��Y�n���h���̃��\�[�X
 * ���Q�Ƃ���邽�߁A�A�N�Z�X�ᔽ���̏d��Ȗ�肪��������\��������܂��B
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomPlayerDataRequestCbFunc, criAtomPlayer_SetData,
 * criAtomPlayer_SetPreviousDataAgain, criAtomPlayer_DeferCallback
 */
void CRIAPI criAtomPlayer_SetDataRequestCallback(
	CriAtomPlayerHn player, CriAtomPlayerDataRequestCbFunc func, void *obj);

/*JP
 * \brief �X�e�[�^�X�ύX�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	func		�X�e�[�^�X�ύX�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �X�e�[�^�X�ύX�R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[�̃X�e�[�^�X���X�V�����^�C�~���O��
 * ���s����܂��B<br>
 * �ύX���ꂽ�X�e�[�^�X�ɂ��ẮA�R�[���o�b�N�֐��̈����Ƃ��ēn�����Atom�v���[���[
 * �n���h���ɑ΂��A ::criAtomPlayer_GetStatus �֐������s���邱�ƂŎ擾�\�ł��B<br>
 * <br>
 * �X�e�[�^�X�ύX�R�[���o�b�N�𗘗p���邱�ƂŁAAtom�v���[���[�̃X�e�[�^�X�ύX��
 * ���킹�ē���̏������s�����Ƃ��\�ɂȂ�܂��B<br>
 * �Ⴆ�΁A�ȉ��̂悤�ȃR�[�h�ŁA�X�e�[�^�X�� CRIATOMPLAYER_STATUS_ERROR �ɂȂ���
 * �ꍇ�Ƀ��[�h�G���[���b�Z�[�W��\�����邱�Ƃ��\�ł��B<br>
 * \code
 * // �X�e�[�^�X�ύX�R�[���o�b�N�֐�
 * void on_status_change(void *obj, CriAtomPlayerHn player)
 * {
 * 	CriAtomPlayerStatus status;
 *
 * 	// �X�e�[�^�X�̎擾
 * 	status = criAtomPlayer_GetStatus(player);
 * 	if (status == CRIATOMPLAYER_STATUS_ERROR) {
 * 		// ���[�h�G���[�������̏���
 * 			:
 * 	}
 * }
 *
 * main()
 * {
 * 		:
 * 	// �X�e�[�^�X�ύX�R�[���o�b�N�֐��̓o�^
 * 	criAtomPlayer_SetStatusChangeCallback(player, on_status_change, NULL);
 *
 * 	// �����t�@�C�����Z�b�g
 * 	criAtomPlayer_SetFile(player, NULL, "sample.adx");
 *
 * 	// �Z�b�g���ꂽ�����t�@�C�����Đ�
 * 	criAtomPlayer_Start(player);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * �����ɂ́A�X�e�[�^�X�J�ځ`�R�[���o�b�N�֐����s�܂ł̊Ԃɑ��̏��������荞�݂œ��삷��
 * �]�n�����邽�߁A�X�e�[�^�X�J�ڂƃR�[���o�b�N�֐����s�̃^�C�~���O���Y����\��������܂��B<br>
 * \attention
 * �X�e�[�^�X�ύX�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �X�e�[�^�X�ύX�R�[���o�b�N�֐��𔲂���܂ł́AAtom�v���[���[�̃X�e�[�^�X��
 * �ύX����邱�Ƃ͂���܂���B<br>
 * ���̂��߁A�X�e�[�^�X�ύX�R�[���o�b�N�֐�����Atom�v���[���[�̃X�e�[�^�X�J�ڂ�
 * �҂������s���ƁA�f�b�h���b�N���������A��������ɐi�܂Ȃ��Ȃ�܂��B<br>
 * <br>
 * �R�[���o�b�N�֐�����Atom�v���[���[��j�����Ȃ��ł��������B<br>
 * �R�[���o�b�N�𔲂�������A���΂炭�̊Ԃ̓T�[�o�[�������œ��Y�n���h���̃��\�[�X
 * ���Q�Ƃ���邽�߁A�A�N�Z�X�ᔽ���̏d��Ȗ�肪��������\��������܂��B
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa criAtomPlayer_GetStatus
 */
void CRIAPI criAtomPlayer_SetStatusChangeCallback(
	CriAtomPlayerHn player, CriAtomPlayerStatusChangeCbFunc func, void *obj);

/*JP
 * \brief �p�����[�^�[�ύX�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	func		�p�����[�^�[�ύX�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �p�����[�^�[�ύX�R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́AAtom�v���[���[�̃p�����[�^�[���X�V�����^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * �p�����[�^�[�ύX�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐�����Atom�v���[���[��j�����Ȃ��ł��������B<br>
 * �R�[���o�b�N�𔲂�������A���΂炭�̊Ԃ̓T�[�o�[�������œ��Y�n���h���̃��\�[�X
 * ���Q�Ƃ���邽�߁A�A�N�Z�X�ᔽ���̏d��Ȗ�肪��������\��������܂��B
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 */
void CRIAPI criAtomPlayer_SetParameterChangeCallback(
	CriAtomPlayerHn player, CriAtomPlayerParameterChangeCbFunc func, void *obj);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	func		�g�`�t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �f�R�[�h���ʂ� PCM �f�[�^���󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A Atom �v���[���[�������f�[�^���f�R�[�h�����^�C�~���O�ŌĂяo����܂��B<br>
 * \attention
 * �X�e�[�^�X�ύX�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * HCA-MX�R�[�f�b�N��v���b�g�t�H�[���ŗL�̉������k�R�[�f�b�N���g�p���Ă���ꍇ�A
 * �t�B���^�[�R�[���o�b�N�͗��p�ł��܂���B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomPlayerFilterCbFunc
 */
void CRIAPI criAtomPlayer_SetFilterCallback(
	CriAtomPlayerHn player, CriAtomPlayerFilterCbFunc func, void *obj);

/*JP
 * \brief ���[�h�v���R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player		Atom�v���[���[�n���h��
 * \param[in]	func		���[�h�v���R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * ���[�h�v���R�[���o�b�N�֐��̓o�^���s���܂��B<br>
 * <br>
 * ���[�h�v���R�[���o�b�N�́AAtom�v���[���[�̃t�@�C�����[�h��Ԃ��Ď�����ۂɎg�p���܂��B<br>
 * �i�f�o�b�O�ړI�̊֐��Ȃ̂ŁA�ʏ�{�֐����g�p����K�v�͂���܂���B�j<br>
 * \attention
 * ���[�h�v���R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪
 * �������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐�����Atom�v���[���[��j�����Ȃ��ł��������B<br>
 * �R�[���o�b�N�𔲂�������A���΂炭�̊Ԃ̓T�[�o�[�������œ��Y�n���h���̃��\�[�X
 * ���Q�Ƃ���邽�߁A�A�N�Z�X�ᔽ���̏d��Ȗ�肪��������\��������܂��B
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriAtomPlayerLoadRequestCbFunc
 */
void CRIAPI criAtomPlayer_SetLoadRequestCallback(
	CriAtomPlayerHn player, CriAtomPlayerLoadRequestCbFunc func, void *obj);

/*==========================================================================
 *      Functions for HCA Streaming
 *=========================================================================*/

/*JP
 * \brief HCA�t�H�[�}�b�g�̎w��
 * \ingroup ATOMLIB_PLAYER
 * \param[in]	player				Atom�v���[���[
 * \param[in]	num_channels		�`�����l����
 * \param[in]	sampling_rate		�T���v�����O���g��
 * \param[in]	bitrate				�r�b�g���[�g
 * \par ����:
 * HCA�f�[�^�̃t�H�[�}�b�g����ݒ肵�܂��B<br>
 * �{�֐������s���邱�ƂŁA�w�b�_�[���X��HCA�f�[�^���Đ����邱�Ƃ��\�ɂȂ�܂��B<br>
 */
void CRIAPI criAtomPlayer_SetHcaFormat(CriAtomPlayerHn player,
	CriSint32 num_channels, CriSint32 sampling_rate, CriSint32 bitrate);

/*==========================================================================
 *      CRI Atom D-BAS API
 *=========================================================================*/
/*JP
 * \brief D-BAS�쐬�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_DBAS
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
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �ݒ�ɂ���ẮAD-BAS��2GB�ȏ�̃��[�N�T�C�Y��K�v�Ƃ���ꍇ������A<br>
 * ���̍ۂ̓G���[�ɂȂ�A -1 ��Ԃ��܂��B<br>
 * �G���[�����������ꍇ�́Amax_streams��max_bps�̒l��Ⴍ�ݒ肵�Ă��������B<br>
 * \sa criAtomDbas_Create
 */
CriSint32 CRIAPI criAtomDbas_CalculateWorkSize(const CriAtomDbasConfig *config);

/*JP
 * \brief D-BAS�̍쐬
 * \ingroup ATOMLIB_DBAS
 * \param[in]	config			D-BAS�쐬�p�R���t�B�O�\���̂ւ̃|�C���^
 * \param[in]	work			D-BAS�쐬�p���[�N�̈�ւ̃|�C���^
 * \param[in]	work_size		D-BAS�쐬�p���[�N�T�C�Y
 * \return		CriAtomDbasId	D-BAS�Ǘ��pID
 * \par ����:
 * D-BAS�쐬�p�p�����[�^�[�Ɋ�Â��āAD-BAS���쐬���܂��B<br>
 * �쐬�ɐ�������ƁAD-BAS�����C�u�����ɓo�^���A�L���ȊǗ��pID��Ԃ��܂��B<br>
 * D-BAS�̍쐬�Ɏ��s�����ꍇ�A�{�֐��� ::CRIATOMDBAS_ILLEGAL_ID ��Ԃ��܂��B<br>
 * �i�G���[�̌����̓G���[�R�[���o�b�N�ɕԂ���܂��B�j<br>
 * <br>
 * �擾����ID��::criAtomDbas_Destroy �֐��Ŏg�p���܂��B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * \sa criAtomDbas_CalculateWorkSize, criAtomDbas_Destroy
 */
CriAtomDbasId CRIAPI criAtomDbas_Create(
	const CriAtomDbasConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief D-BAS�̔j��
 * \ingroup ATOMLIB_DBAS
 * \param[in]	atom_dbas_id	D-BAS�Ǘ��pID
 * \par ����:
 * ::criAtomDbas_Create �֐��Ŏ擾�����Ǘ��pID���w�肵�āAD-BAS��j�����܂��B<br>
 * \sa criAtomDbas_Create
 */
void CRIAPI criAtomDbas_Destroy(CriAtomDbasId atom_dbas_id);

/*JP
 * \brief �X�g���[���Đ�����Atom�v���[���[�n���h�����擾
 * \ingroup ATOMLIB_DBAS
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
CriSint32 CRIAPI criAtomDbas_GetStreamingPlayerHandles(
	CriAtomDbasId dbas_id, CriAtomPlayerHn *players, CriSint32 length);

/* ========================================================================*/
/*       CRI Atom Streaming Cache API                                      */
/* ========================================================================*/
/*JP
 * \brief �X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \param[in]	config		�X�g���[�~���O�L���b�V���쐬�p�\����
 * return		CriSint32	�X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y
 * \retval		0�ȏ�		����ɏ���������
 * \retval		-1			�G���[������
 * \par ����:
 * �X�g���[�~���O�L���b�V���쐬�ɕK�v�ȃ��[�N�T�C�Y���v�Z���܂��B<br>
 * config�ŗ^������p�����[�^�[�Ɉˑ����A�K�v�ȃ��[�N�T�C�Y�͑������܂��B<br>
 * \sa criAtomStreamingCache_Create
 */
CriSint32 CRIAPI criAtomStreamingCache_CalculateWorkSize(
	const CriAtomStreamingCacheConfig* config);

/*JP
 * \brief �X�g���[�~���O�L���b�V���̍쐬
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \param[in]	config		�X�g���[�~���O�L���b�V���쐬�p�\����
 * \param[in]	work		�X�g���[�~���O�L���b�V���쐬�p���[�N
 * \param[in]	work_size	�X�g���[�~���O�L���b�V���쐬�p���[�N�T�C�Y
 * return		CriAtomStreamingCacheId	�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �X�g���[�~���O�L���b�V�����쐬���܂��B<br>
 * Atom�v���[���[�ɃX�g���[�~���O�L���b�V����ݒ肷�邱�ƂŁA
 * �X�g���[�~���O�Đ����s����������Ƀt�@�C���S�̂�ێ��i�L���b�V���j���܂��B<br>
 * �����t�@�C����2��ڈȍ~�̍Đ��ł́A�L���b�V�����g�����������Đ��Ɏ����I�ɐ؂�ւ��܂��B<br>
 * �܂��A�Đ��f�[�^�����[�v�f�[�^�������Ă����ꍇ�A
 * ���[�v�ȍ~�̍Đ��͎����I�Ƀ������Đ��ōs����悤�ɂȂ�܂��B<br>
 * �{�@�\��Atom�v���[���[���X�g���[�~���O�Đ����s���ꍇ�̂݋@�\���܂��B<br>
 * �{�֐��Ɏ��s�����ꍇ�ACRIATOM_STREAMING_CACHE_ILLEGAL_ID���Ԃ�܂��B<br>
 * \attention
 * �t�@�C���S�̂��L���b�V�����鎖���O��ł��̂ŁA�L���b�V���p�Ɋ��蓖�Ă�ꂽ�������T�C�Y��
 * �X�g���[�~���O�Đ��ΏۂƂ���ǂ̃t�@�C���T�C�Y�����������ꍇ�A
 * ��؃L���b�V������܂���B
 * \sa criAtomStreamingCache_CalculateWorkSize, criAtomStreamingCache_Destroy,
 */
CriAtomStreamingCacheId CRIAPI criAtomStreamingCache_Create(
	const CriAtomStreamingCacheConfig* config, void* work, CriSint32 work_size);

/*JP
 * \brief �X�g���[�~���O�L���b�V���̔j��
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \param[in]	stm_cache_id		�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V����j�����܂��B<br>
 * \attention
 * �w�肵���X�g���[�~���O�L���b�V���𗘗p���Ă���v���[���[�����݂��Ȃ���ԂŁA
 * �{�֐������s���Ă��������B
 * \sa criAtomStreamingCache_Create
 */
void CRIAPI criAtomStreamingCache_Destroy(CriAtomStreamingCacheId stm_cache_id);

/*JP
 * \brief �X�g���[�~���O�L���b�V���̃L���b�V�����e���N���A
 * \ingroup ATOMLIB_STREAMING_CACHE
 * \param[in]	cache_id		�X�g���[�~���O�L���b�V��ID
 * \par ����:
 * �w�肵���X�g���[�~���O�L���b�V���̓��e���N���A���܂��B<br>
 * �L���b�V���͌Â����ɃN���A����܂��B<br>
 * �w�肵���X�g���[�~���O�L���b�V�����g�p���̃v���[���[�����݂���ꍇ�A
 * �L���b�V���̃N���A�͓r���Œ��f����܂��B<br>
 * \attention
 * ��ԌÂ��L���b�V�����g�p���̃v���[���[�����݂���ꍇ�A�{�֐������s���Ă�
 * �L���b�V���͈�؃N���A����܂���B
 * \sa criAtomStreamingCache_Create
 */
void CRIAPI criAtomStreamingCache_Clear(CriAtomStreamingCacheId cache_id);

/*JP
 * \brief WaveID�w��ŃL���b�V���ς݌���
 * \ingroup ATOMLIB_STREAMING_CACHE
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
 * \sa criAtomStreamingCache_Create
 */
CriBool CRIAPI criAtomStreamingCache_IsCachedWaveId(
	CriAtomStreamingCacheId stm_cache_id, CriAtomAwbHn awb, CriSint32 id);

/*JP
 * \brief �p�X�w��ŃL���b�V���ς݌���
 * \ingroup ATOMLIB_STREAMING_CACHE
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
CriBool CRIAPI criAtomStreamingCache_IsCachedFile(
	CriAtomStreamingCacheId stm_cache_id, CriFsBinderHn src_binder, const CriChar8 *path);

/*==========================================================================
 *      CRI Atom DSP API
 *=========================================================================*/
/*JP
 * \brief �Z���g�l����DSP�p�����[�^�[�ւ̕ϊ�
 * \ingroup ATOMLIB_DSP
 * \param[in]	cent		�Z���g�l
 * \return		CriFloat32	DSP�p�����[�^�[�l
 * \par ����:
 * -1200�`1200�͈̔͂�0.0f�`1.0f�͈̔͂ɐ��K�����܂��B<br>
 */
CriFloat32 criAtomDsp_ConvertParameterFromCent(CriFloat32 cent);

/*JP
 * \brief �X�y�N�g�����A�i���C�U�쐬�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z
 * \ingroup ATOMLIB_DSP
 * \param[in]	config		�X�y�N�g�����A�i���C�U�쐬�p�����[�^�[
 * \return		CriSint32	�K�v�ȃ��[�N�̈�̃T�C�Y�i�P�ʂ̓o�C�g�j
 * \par ����:
 * �X�y�N�g�����A�i���C�U�̍쐬�ɕK�v�ȃ��[�N�T�C�Y���v�Z���܂��B<br>
 * config�ŗ^������p�����[�^�[�Ɉˑ����A�K�v�ȃ��[�N�T�C�Y�͕ω����܂��B<br>
 * \par ���l:
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�����ꍇ�A�{�֐��͕��l��Ԃ��܂��B<br>
 * �i���s�̌����̓G���[�R�[���o�b�N�Œʒm����܂��B�j<br>
 * \sa CriAtomDspSpectraConfig, criAtomDspSpectra_Create
 */
CriSint32 criAtomDspSpectra_CalculateWorkSize(const CriAtomDspSpectraConfig *config);

/*JP
 * \brief �X�y�N�g�����A�i���C�U�̍쐬
 * \ingroup ATOMLIB_DSP
 * \param[in]	config		�X�y�N�g�����A�i���C�U�쐬�p�����[�^�[
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \return		CriAtomDspSpectraHn	�X�y�N�g�����A�i���C�U�n���h��
 * \par ����:
 * �X�y�N�g�����A�i���C�U���쐬���܂��B<br>
 * �X�y�N�g�����A�i���C�U�́APCM�f�[�^����͂��A
 * �ш悲�Ƃ̐M���̋������v�����郂�W���[���ł��B<br>
 * <br>
 * PCM�f�[�^�̓��͂ɂ́A ::criAtomDspSpectra_Process �֐����g�p���܂��B<br>
 * ��͌��ʂ̎擾�ɂ́A ::criAtomDspSpectra_GetLevels �֐����g�p���܂��B<br>
 * <br>
 * �s�v�ɂȂ����X�y�N�g�����A�i���C�U�́A ::criAtomDspSpectra_Destroy
 * �֐��Ŗ����I�ɔj������K�v������܂��B<br>
 * \par ���l:
 * �X�y�N�g�����A�i���C�U�̍쐬�Ɏ��s�����ꍇ�A�{�֐���NULL��Ԃ��܂��B<br>
 * �i���s�̌����̓G���[�R�[���o�b�N�Œʒm����܂��B�j
 * <br>
 * ::criAtom_SetUserAllocator �ɂ��A���P�[�^�[�o�^���s�킸�ɖ{�֐������s����ꍇ�A
 * ::criAtomDspSpectra_CalculateWorkSize
 * �֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��ɃZ�b�g�������[�N�̈�́A ::criAtomDspSpectra_Destroy
 * �֐������s����܂ł̊ԁA�A�v���P�[�V�����ŕێ�����K�v������܂��B<br>
 * �i ::criAtomDspSpectra_Destroy �֐����s�O�ɁA���[�N�̈�̃�������������Ȃ��ł��������B�j<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa CriAtomDspSpectraConfig, criAtomDspSpectra_CalculateWorkSize, criAtomDspSpectra_Destroy
 */
CriAtomDspSpectraHn criAtomDspSpectra_Create(
	const CriAtomDspSpectraConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �X�y�N�g�����A�i���C�U�̔j��
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �X�y�N�g�����A�i���C�U��j�����܂��B<br>
 * �X�y�N�g�����A�i���C�U�쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �i�X�y�N�g�����A�i���C�U�쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomDspSpectra_Create
 */
void criAtomDspSpectra_Destroy(CriAtomDspSpectraHn spectra);

/*JP
 * \brief �X�y�N�g�����A�i���C�U�̃��Z�b�g
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * �X�y�N�g�����A�i���C�U�����Z�b�g���܂��B<br>
 * �{�֐������s�������_�ŁA ::criAtomDspSpectra_Process
 * �֐��ɃZ�b�g����PCM�̏�񂪃N���A����܂��B<br>
 * \par ���l:
 * ::criAtomDspSpectra_GetLevels �֐��̖߂�l���[���N���A�������ꍇ�A
 * �{�֐������s���Ă��������B<br>
 * \sa criAtomDspSpectra_Process, criAtomDspSpectra_GetLevels
 */
void criAtomDspSpectra_Reset(CriAtomDspSpectraHn spectra);

/*JP
 * \brief �X�y�N�g�������
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * PCM�f�[�^����͂��܂��B<br>
 * ��͌��ʂ� ::criAtomDspSpectra_GetLevels �֐��Ŏ擾�\�ł��B<br>
 * \par ���l:
 * ���͂���f�[�^��ipcm�j�̒l�� -1.0f �` +1.0f �͈̔͂�z�肵�Ă��܂��B<br>
 * �����A�}1�͈̔͂𒴂���l����͂����ꍇ�ł��AcriAtomDspSpectra_GetLevels
 * �֐����Ԃ��l���傫���Ȃ邾���Ȃ̂ŁA
 * �f�[�^���͎��_�ŃN���b�s���O���s���K�v�͂���܂���B<br>
 * �{�֐��͓�����1024�_�̃T���v�����~�ς����̂�҂��Ă���FFT�������s���ׁA
 * �X�y�N�g������1024�T���v�����͖��ɍX�V����܂��B
 * \sa criAtomDspSpectra_GetLevels
 */
void criAtomDspSpectra_Process(CriAtomDspSpectraHn spectra,
	CriUint32 num_channels, CriUint32 num_samples, CriFloat32 *pcm[]);

/*JP
 * \brief �X�y�N�g����͌��ʂ̎擾
 * \ingroup ATOMLIB_DSP
 * \par ����:
 * ::criAtomDspSpectra_Process �֐��ŃZ�b�g����PCM�f�[�^�́A��͌��ʂ�Ԃ��܂��B<br>
 * <br>
 * ��͌��ʂ� CriFloat32 �^�̔z��ł��B<br>
 * �z��̗v�f���́A ::criAtomDspSpectra_Create �֐����s����
 * CriAtomDspSpectraConfig::num_bands �Ŏw�肵�����ɂȂ�܂��B<br>
 * 0 �Ԗڂ̗v�f���Œ�ш�̐U���l�A (num_bands - 1) �Ԗڂ̗v�f���ō��ш�̐U���l�ł��B<br>
 * \par ���l:
 * �����`�����l����PCM�f�[�^����͂����ꍇ�A
 * �S�Ẵ`�����l����PCM�f�[�^����U�~�b�N�X���A�~�b�N�X���ʂɑ΂���͂��s���܂��B<br>
 * ���̂��߁A criAtomDspSpectra_Process �֐��ɕ����`�����l���̉����f�[�^���Z�b�g�����ꍇ�ł��A
 * �{�֐��͒����� num_bands ��1�����z���Ԃ��܂��B<br>
 * \attention
 * criAtomDspSpectra_GetLevels �֐����Ԃ��l�́A�ш悲�Ƃ̐U���l�ł��B<br>
 * ��͌��ʂ��s�̂̃X�y�N�g���A�i���C�U�̂悤�ɕ\�����������ꍇ�A
 * �{�֐����Ԃ��l���f�V�x���l�ɕϊ�����K�v������܂��B<br>
 * \sa criAtomDspSpectra_Process
 */
const CriFloat32* criAtomDspSpectra_GetLevels(CriAtomDspSpectraHn spectra);

/* ========================================================================*/
/*       CRI Atom Meter API                                                */
/* ========================================================================*/

/*JP
 * \brief ���x�����[�^�[�@�\�p�̃��[�N�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_METER
 * \param[in]	config			���x�����[�^�[�ǉ��p�̃R���t�B�O�\����
 * \return		CriSint32		�K�v�ȃ��[�N�̈�T�C�Y
 * \par ����:
 * ���x�����[�^�[�ǉ��ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ōv�Z����܂��B<br>
 * \sa criAtomMeter_AttachLevelMeter
 */
CriSint32 CRIAPI criAtomMeter_CalculateWorkSizeForLevelMeter(
	const CriAtomLevelMeterConfig *config);

/*JP
 * \brief ���x�����[�^�[�@�\�̒ǉ�
 * \ingroup ATOMLIB_METER
 * \param[in]	config			���x�����[�^�[�ǉ��p�̃R���t�B�O�\����
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u�����Ƀ��x�����[�^�[�@�\��ǉ����܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ń��x�����[�^�[���ǉ�����܂��B<br>
 * work ��NULL�Awork_size ��0���w�肷��ƁA�o�^���ꂽ���[�U�A���P�[�^�[�ɂ����
 * ���[�N�̈悪�m�ۂ���܂��B<br>
 * \sa criAtomMeter_GetLevelInfo
 */
void CRIAPI criAtomMeter_AttachLevelMeter(
	const CriAtomLevelMeterConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���x�����[�^�[�@�\�̉���
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���C�u�����̃��x�����[�^�[�@�\���������܂��B<br>
 * \sa criAtomMeter_AttachLevelMeter
 */
void CRIAPI criAtomMeter_DetachLevelMeter(void);

/*JP
 * \brief ���x�����̎擾
 * \ingroup ATOMLIB_METER
 * \param[out]	info			���x�����̍\����
 * \par ����:
 * ���x�����[�^�[�̌��ʂ��擾���܂��B<br>
 * �w�肷��o�X�ɂ� ::criAtomMeter_AttachLevelMeter �֐��ł��炩����
 * ���x�����[�^�[�@�\��ǉ����Ă����K�v������܂��B<br>
 * \sa criAtomMeter_AttachLevelMeter
 */
void CRIAPI criAtomMeter_GetLevelInfo(CriAtomLevelInfo *info);

/*JP
 * \brief ���E�h�l�X���[�^�[�@�\�p�̃��[�N�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_METER
 * \param[in]	config			���E�h�l�X���[�^�[�ǉ��p�̃R���t�B�O�\����
 * \return		CriSint32		�K�v�ȃ��[�N�̈�T�C�Y
 * \par ����:
 * ITU-R BS.1770-3�K�i�̃��E�h�l�X���[�^�[�ǉ��ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ōv�Z����܂��B<br>
 * \sa criAtomMeter_AttachLoudnessMeter
 */
CriSint32 CRIAPI criAtomMeter_CalculateWorkSizeForLoudnessMeter(const CriAtomLoudnessMeterConfig *config);

/*JP
 * \brief ���E�h�l�X���[�^�[�@�\�̒ǉ�
 * \ingroup ATOMLIB_METER
 * \param[in]	config			���E�h�l�X���[�^�[�ǉ��p�̃R���t�B�O�\����
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u������ITU-R BS.1770-3�K�i�̃��E�h�l�X���[�^�[�@�\��ǉ����܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ń��E�h�l�X���[�^�[���ǉ�����܂��B<br>
 * work ��NULL�Awork_size ��0���w�肷��ƁA�o�^���ꂽ���[�U�A���P�[�^�[�ɂ����
 * ���[�N�̈悪�m�ۂ���܂��B<br>
 * \sa criAtomMeter_GetLoudnessInfo
 */
void CRIAPI criAtomMeter_AttachLoudnessMeter(const CriAtomLoudnessMeterConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���E�h�l�X���[�^�[�@�\�̉���
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���C�u�����̃��E�h�l�X���[�^�[�@�\���������܂��B<br>
 * \sa criAtomMeter_AttachLoudnessMeter
 */
void CRIAPI criAtomMeter_DetachLoudnessMeter(void);

/*JP
 * \brief ���E�h�l�X���̎擾
 * \ingroup ATOMLIB_METER
 * \param[out]	info		���E�h�l�X���̍\����
 * \par ����:
 * ���E�h�l�X���[�^�[�̑��茋�ʂ��擾���܂��B
 * �{�֐����Ăяo���O�Ƀ��C�u�����փ��E�h�l�X���[�^�[��ǉ����Ă����K�v������܂��B
 * \sa criAtomMeter_AttachLoudnessMeter
 */
void CRIAPI criAtomMeter_GetLoudnessInfo(CriAtomLoudnessInfo *info);

/*JP
 * \brief ���E�h�l�X���[�^�[�̃��Z�b�g
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���E�h�l�X���[�^�[�̒~�σf�[�^�����Z�b�g���܂��B
 * �{�֐����Ăяo���O�Ƀ��C�u�����փ��E�h�l�X���[�^�[��ǉ����Ă����K�v������܂��B
 * \sa criAtomMeter_AttachLoudnessMeter
 */
void CRIAPI criAtomMeter_ResetLoudnessMeter(void);

/*JP
 * \brief �g�D���[�s�[�N���[�^�[�@�\�p�̃��[�N�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_METER
 * \param[in]	config			�g�D���[�s�[�N���[�^�[�ǉ��p�̃R���t�B�O�\����
 * \return		CriSint32		�K�v�ȃ��[�N�̈�T�C�Y
 * \par ����:
 * ITU-R BS.1770-3�K�i�̃g�D���[�s�[�N���[�^�[�ǉ��ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ōv�Z����܂��B<br>
 * \sa criAtomMeter_AttachTruePeakMeter
 */
CriSint32 CRIAPI criAtomMeter_CalculateWorkSizeForTruePeakMeter(const CriAtomTruePeakMeterConfig *config);

/*JP
 * \brief �g�D���[�s�[�N���[�^�[�@�\�̒ǉ�
 * \ingroup ATOMLIB_METER
 * \param[in]	config			�g�D���[�s�[�N���[�^�[�ǉ��p�̃R���t�B�O�\����
 * \param[in]	work			���[�N�̈�
 * \param[in]	work_size		���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u������ITU-R BS.1770-3�K�i�̃g�D���[�s�[�N���[�^�[�@�\��ǉ����܂��B<br>
 * config ��NULL���w�肷��ƃf�t�H���g�ݒ�Ńg�D���[�s�[�N���[�^�[���ǉ�����܂��B<br>
 * work ��NULL�Awork_size ��0���w�肷��ƁA�o�^���ꂽ���[�U�A���P�[�^�[�ɂ����
 * ���[�N�̈悪�m�ۂ���܂��B<br>
 * \sa criAtomMeter_GetTruePeakInfo
 */
void CRIAPI criAtomMeter_AttachTruePeakMeter(const CriAtomTruePeakMeterConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief �g�D���[�s�[�N���[�^�[�@�\�̉���
 * \ingroup ATOMLIB_METER
 * \par ����:
 * ���C�u�����̃g�D���[�s�[�N���[�^�[�@�\���������܂��B<br>
 * \sa criAtomMeter_AttachLoudnessMeter
 */
void CRIAPI criAtomMeter_DetachTruePeakMeter(void);

/*JP
 * \brief �g�D���[�s�[�N���̎擾
 * \ingroup ATOMLIB_METER
 * \param[out]	info		�g�D���[�s�[�N���̍\����
 * \par ����:
 * �g�D���[�s�[�N���[�^�[�̑��茋�ʂ��擾���܂��B
 * �{�֐����Ăяo���O�Ƀ��C�u�����փg�D���[�s�[�N���[�^�[��ǉ����Ă����K�v������܂��B
 * \sa criAtomMeter_AttachTruePeakMeter
 */
void CRIAPI criAtomMeter_GetTruePeakInfo(CriAtomTruePeakInfo *info);

/* ========================================================================*/
/*       CRI Atom Instrument API                                           */
/* ========================================================================*/
/*JP
 * \brief ���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^
 * \param[in]	ainst_interface	���[�U��`�C���X�g�D�������g�̃o�[�W�������t���C���^�[�t�F�[�X
 * \return						�o�^�ɐ����������H�iCRI_TRUE:�o�^�ɐ�������, CRI_FALSE:�o�^�Ɏ��s�����j
 * \par ����:
 * ���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X��Atom���C�u�����ɓo�^���܂��B<br>
 * ���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X��o�^�����C���X�g�D�������g�̓C���X�g�D�������g�g���b�N�̍Đ��ɂɎg�p�ł���悤�ɂȂ�܂��B<br>
 * �ȉ��̏����ɊY������ꍇ�́A���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^�Ɏ��s���A�G���[�R�[���o�b�N���Ԃ�܂�:
 *  - ����̃G�t�F�N�g���������[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�����ɓo�^����Ă���
 *  - Atom���g�p���Ă��郆�[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�ƈقȂ�
 *  - ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^������i ::CRIATOMEXASR_MAX_NUM_USER_EFFECT_INTERFACES �j�ɒB����
 * \par ����:
 * ���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�́A�C���X�g�D�������g�g���b�N���Đ�����O��<br>
 * �{�֐��ɂ���ēo�^���s���ĉ������B<br>
 * Atom���C�u�����g�p���ɃC���^�[�t�F�[�X�̓o�^�������s���ꍇ�́A ::criAtomInstrument_UnregisterInstrumentInterface ���g�p���ĉ������B
 * \sa criAtomInstrument_UnregisterInstrumentInterface 
 */
CriBool CRIAPI criAtomInstrument_RegisterInstrumentInterface(CriAtomAinstInterfaceWithVersionPtr ainst_interface);

/*JP
 * \brief ���[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^����
 * \param[in]	ainst_interface	���[�U��`�C���X�g�D�������g�̃o�[�W�������t���C���^�[�t�F�[�X
 * \par ����:
 * �C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^���������܂��B<br>
 * �o�^�����������C���X�g�D�������g�̓C���X�g�D�������g�g���b�N���Đ�����ۂɎg�p�ł��Ȃ��Ȃ�܂��B<br>
 * �o�^�������s���Ă��Ȃ��C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^���������邱�Ƃ͂ł��܂���i�G���[�R�[���o�b�N���Ԃ�܂��j�B
 * \par ����:
 * �o�^���s�������[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�̓v���[���[�̍Đ����ɎQ�Ƃ��ꑱ���邽�߁A<br>
 * �S�Ẵv���[���[����~��������ŁA�{�֐������s���Ă��������B<br>
 * Atom���C�u�����̏I�����i::criAtom_Finalize �֐��̌Ăяo�����j�ɂ͑S�Ẵ��[�U��`�C���X�g�D�������g�C���^�[�t�F�[�X�̓o�^����������܂��B
 * \sa  criAtomInstrument_RegisterInstrumentInterface
 */
void CRIAPI criAtomInstrument_UnregisterInstrumentInterface(CriAtomAinstInterfaceWithVersionPtr ainst_interface);

/***************************************************************************
 *      �b��API�i�g�p�͂��T���������j
 *      Tentative API (Please don't use it)
 ***************************************************************************/
/* �ȉ��ɐ錾����Ă���֐���Atom�̓��������p�A�Q�[���G���W���Ƃ̘A�g���ɂ�
 * �b��I�Ɏg�p����Ă���API�ł��B
 * ����̃A�b�v�f�[�g�ɂė\���Ȃ��ύX�E�폜���s���邽�߁A�g�p�͂��T���������B
 */
typedef void (CRIAPI *CriAtomPlayerDataEndCbFunc)(void *obj, void *buffer, CriSint32 size);
typedef void (CRIAPI *CriAtomPlayerCbFunc)(void *obj, CriAtomPlayerHn player);
typedef void (CRIAPI *CriAtomPlayerDecodeCbFunc)(void *obj, CriAtomPcmFormat format,
	CriSint32 num_channels, CriSint32 num_samples, void *data[]);
void CRIAPI criAtomPlayer_SetDecodeCallback(
	CriAtomPlayerHn player, CriAtomPlayerDecodeCbFunc func, void *obj);
void CRIAPI criAtomPlayer_DiscardSamples(CriAtomPlayerHn player, CriSint32 num_discard);
typedef CriSint32 CriAtomWaveType;

#ifdef __cplusplus
}
#endif

/***************************************************************************
 *      ���o�[�W�����Ƃ̌݊��p
 *      For compatibility with old version
 ***************************************************************************/

#define CRI_ATOM_VERSION				(0xFFFFFFFF)
/* �����_���[�̏o��Ch���ݒ�ɉ����āA�����Ń_�E���~�b�N�X���邽�߉��L�֐��͖����ɂ��Ă��܂� */
#define criAtomHcaMx_SetBusSendLevel(mixer_id, bus_no, level) \
	criAtomExHcaMx_SetBusSendLevel(mixer_id, bus_no, level)

#ifdef __cplusplus
extern "C" {
#endif

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �{�֐����s���A��� 0xFFFFFFFF ���ԋp����܂��B
 * ::criAtom_GetVersionString �֐��̎g�p���Ă��������B
 */
CriUint32 CRIAPI criAtom_GetVersionNumber(void);

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_ATOM_H */

/* --- end of file --- */
