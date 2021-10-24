/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2006-2017 CRI Middleware Co., Ltd.
 *
 * Library  : CRI File System
 * Module   : Library User's Header
 * File     : cri_file_system.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_file_system.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef	CRI_FILE_SYSTEM_H_INCLUDED
#define	CRI_FILE_SYSTEM_H_INCLUDED

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include "cri_le_xpt.h"
#include "cri_le_error.h"

#ifdef __cplusplus
#if defined(XPT_TGT_TBCG)
#if !defined(XPT_DISABLE_FSV1API)
	/* ���o�[�W����API */
	/* Old version API */
	#include "cri_file_system_ver1api.h"
#endif
#endif
#endif

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/
/* �o�[�W������� */
/* Version Number */
#define CRI_FS_VER_NAME		"CRI File System (LE)"
#define CRI_FS_VER_NUM		"2.80.17"
#define CRI_FS_VER_MAJOR	(2)
#define CRI_FS_VER_MINOR	(80)
#define CRI_FS_VER_PATCH	(17)
#define CRI_FS_VER_RELEASE	(0)
#define CRI_FS_VER_REVISION	(0)

/*JP
 * \brief �R���t�B�M�����[�V�����̃f�t�H���g�l
 */
#if defined(XPT_TGT_NITRO)
#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_MULTI
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(8)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(32)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(2)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(4)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(8)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(32)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(128)
#elif defined(XPT_TGT_3DS)
#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_MULTI
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(8)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(32)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(2)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(4)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(8)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(32)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(256)
#elif defined(XPT_TGT_TBCG)
#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_MULTI
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(8)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(32)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(1)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(32)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(256)
#elif defined(XPT_TGT_EMSCRIPTEN)
#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_SINGLE
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(8)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(32)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(1)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(32)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(256)
#elif defined(CRI_USE_FILESYSTEM_PLATFORM_HEADER)
#include "cri_file_system_platform.h"
#else
#define	CRIFS_CONFIG_DEFAULT_THREAD_MODEL		CRIFS_THREAD_MODEL_MULTI
#define	CRIFS_CONFIG_DEFAULT_NUM_BINDERS		(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_LOADERS		(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS	(2)
#define	CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES	(16)
#define	CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS		(0)
#define	CRIFS_CONFIG_DEFAULT_MAX_BINDS			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_FILES			(16)
#define	CRIFS_CONFIG_DEFAULT_MAX_PATH			(256)
#endif

/*JP
 * \brief �f�t�H���g�f�o�C�XID
 */
#define CRIFS_DEVICE_DEFAULT	(CRIFS_DEVICE_00)
/*JP
 * \brief �������t�@�C���V�X�e���f�o�C�XID
 */

/*JP
 * \brief �f�t�H���g�f�o�C�XID����`
 * \par ���l:
 * ���̒�`�͔p�~�\��ł��B������::CRIFS_DEVICE_DEFAULT���g�p���Ă��������B
 * \sa CRIFS_DEVICE_DEFAULT
 */
#define CRIFS_DEFAULT_DEVICE	(CRIFS_DEVICE_DEFAULT)

/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*JP
 * \brief ���[�U�[�A���P�[�^�[�̓o�^
 * \ingroup FSLIB_CRIFS
 * \param[in]	p_malloc_func	�������m�ۊ֐�
 * \param[in]	p_free_func		����������֐�
 * \param[in]	p_obj			���[�U�[�w��I�u�W�F�N�g
 * \par ����:
 * CRI File System���C�u�����Ƀ������A���P�[�^�[�i�������̊m�ہ^����֐��j��o�^���܂��B<br>
 * CRI File System���C�u�����������C�u�������ōs�Ȃ�����������������A
 * ���[�U�[�Ǝ��̃�������������ɒu�����������ꍇ�Ɏg�p���܂��B
 */
#define criFs_SetUserAllocator(p_malloc_func, p_free_func, p_obj)	\
{\
	criFs_SetUserMallocFunction(p_malloc_func, p_obj);\
	criFs_SetUserFreeFunction(p_free_func, p_obj);\
}

/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI File System API
 *=========================================================================*/
/*JP
 * \brief �X���b�h���f��
 * \par ����:
 * CRI File System���C�u�������ǂ̂悤�ȃX���b�h���f���œ��삷�邩��\���܂��B<br>
 * ���C�u�������������i::criFs_InitializeLibrary �֐��j�ɁA::CriFsConfig �\���̂ɂĎw�肵�܂��B
 * \sa CriFsConfig
 * \sa criFs_InitializeLibrary
 */
typedef enum CriFsThreadModelTag {
	/*JP
	 * \brief �}���`�X���b�h
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criFs_InitializeLibrary �֐��Ăяo�����ɍ쐬����܂��B
	 */
	/*EN
	 * \brief Multithread
	 * \par Description:
	 * The library creates threads inside and operates in multithread environment. <br>
	 * A thread is created when the ::criFs_InitializeLibrary function is called.
	 */
	CRIFS_THREAD_MODEL_MULTI = 0,

	/*JP
	 * \brief �}���`�X���b�h�i���[�U�[�쓮���j
	 * \par ����:
	 * ���C�u�����͓����ŃX���b�h���쐬���A�}���`�X���b�h�ɂē��삵�܂��B<br>
	 * �X���b�h�� ::criFs_InitializeLibrary �֐��Ăяo�����ɍ쐬����܂��B<br>
	 * �T�[�o�[�������͍̂쐬���ꂽ�X���b�h��Ŏ��s����܂����A
	 * CRIFS_THREAD_MODEL_MULTI �Ƃ͈قȂ�A�����I�ɂ͎��s����܂���B<br>
	 * ���[�U�[�� ::criFs_ExecuteMain �֐��Ŗ����I�ɃT�[�o�[�������쓮����K�v������܂��B<br>
	 * �i  ::criFs_ExecuteMain �֐������s����ƁA�X���b�h���N�����A�T�[�o�[���������s����܂��B�j<br>
	 */
	CRIFS_THREAD_MODEL_MULTI_USER_DRIVEN = 3,

	/*JP
	 * \brief ���[�U�[�}���`�X���b�h
	 * \par ����:
	 * ���C�u���������ł̓X���b�h���쐬���܂��񂪁A���[�U�[���Ǝ��ɍ쐬�����X���b�h����T�[�o�[�����֐��i::criFs_ExecuteFileAccess �֐��A::criFs_ExecuteDataDecompression �֐��j���Ăяo����悤�A�����̔r������͍s���܂��B
	 */
	/*EN
	 * \brief User multithread
	 * \par Description:
	 * No thread is created but exclusion control is performed inside the library for the server processing functions (::criFs_ExecuteFileAccess, ::criFs_ExecuteDataDecompression) to be able to be called from a user-created thread.
	 */
	CRIFS_THREAD_MODEL_USER_MULTI = 1,

	/*JP
	 * \brief �V���O���X���b�h
	 * \par ����:
	 * ���C�u���������ŃX���b�h���쐬���܂���B�܂��A�����̔r��������s���܂���B<br>
	 * ���̃��f����I�������ꍇ�A�eAPI�ƃT�[�o�[�����֐��i::criFs_ExecuteFileAccess �֐��A::criFs_ExecuteDataDecompression �֐��j�Ƃ𓯈�X���b�h����Ăяo���悤�ɂ��Ă��������B
	 */
	/*EN
	 * \brief Single thread
	 * \par Description:
	 * No thread is created inside the library. Exclusion control is not performed inside the library either. <br>
	 * When selecting this model, call the APIs and server processing functions (::criFs_ExecuteFileAccess, ::criFs_ExecuteDataDecompression) from the same thread.
	 */
	CRIFS_THREAD_MODEL_SINGLE = 2,

	/* enum be 4bytes */
	CRIFS_THREAD_MODEL_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsThreadModel;

/*JP
 * \brief �R���t�B�M�����[�V����
 * \par ����:
 * CRI File System���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ���C�u�������������i ::criFs_InitializeLibrary �֐��j�Ɉ����Ƃ��Ė{�\���̂��w�肵�܂��B<br>
 * \par
 * CRI File System���C�u�����́A���������Ɏw�肳�ꂽ�R���t�B�M�����[�V�����ɉ����āA�������\�[�X��K�v�Ȑ��������m�ۂ��܂��B<br>
 * ���̂��߁A�R���t�B�M�����[�V�����Ɏw�肷��l�����������邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y���������}���邱�Ƃ��\�ł��B<br>
 * �������A�R���t�B�M�����[�V�����Ɏw�肵�����ȏ�̃n���h�����m�ۂ��邱�Ƃ͂ł��Ȃ��Ȃ邽�߁A�l����������������ƁA�n���h���̊m�ۂɎ��s����\��������܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criFs_SetDefaultConfig �֐��Ńf�t�H���g�p�����[�^���Z�b�g���A ::criFs_InitializeLibrary �֐��Ɏw�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o�[��������\���ɔ����A�ݒ�O��::criFs_SetDefaultConfig �֐��ŏ��������Ă���g�p���Ă��������B<br>
 * \sa criFs_InitializeLibrary, criFs_SetDefaultConfig
 */
typedef struct CriFsConfigTag {
	/*JP
		\brief �X���b�h���f��
		\par ����:
		CRI File System�̃X���b�h���f�����w�肵�܂��B<br>
		\sa CriFsThreadModel
	*/
	CriFsThreadModel thread_model;

	/*JP
		\brief �g�p����CriFsBinder�̐�
		\par ����:
		�A�v���P�[�V�������Ŏg�p����o�C���_�[�iCriFsBinder�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsBinder_Create �֐����g�p���ăo�C���_�[���쐬����ꍇ�A
		�{�p�����[�^�Ɏg�p����o�C���_�[�̐����w�肷��K�v������܂��B<br>
		<br>
		num_binders�ɂ́u�����Ɏg�p����o�C���_�[�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsBinder_Create �֐��� ::criFsBinder_Destroy �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃o�C���_�[�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�num_binders��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃo�C���_�[��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃo�C���_�[��S���g�p���Ȃ��ꍇ�ł����Ă��A
		num_binders��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p����o�C���_�[�̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Anum_binders�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\sa criFsBinder_Create, criFsBinder_Destroy
	*/
	CriSint32 num_binders;

	/*JP
		\brief �g�p����CriFsLoader�̐�
		\par ����:
		�A�v���P�[�V�������Ŏg�p���郍�[�_�[�iCriFsLoader�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsLoader_Create �֐����g�p���ă��[�_�[���쐬����ꍇ�A
		�{�p�����[�^�Ɏg�p���郍�[�_�[�̐����w�肷��K�v������܂��B<br>
		<br>
		num_loaders�ɂ́u�����Ɏg�p���郍�[�_�[�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsLoader_Create �֐��� ::criFsLoader_Destroy �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃��[�_�[�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�num_loaders��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃ��[�_�[��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃ��[�_�[��S���g�p���Ȃ��ꍇ�ł����Ă��A
		num_loaders��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p���郍�[�_�[�̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Anum_loaders�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\sa criFsLoader_Create, criFsLoader_Destroy
	*/
	CriSint32 num_loaders;

	/*JP
		\brief �g�p����CriFsGroupLoader�̐�
		\par ����:
		�A�v���P�[�V�������Ŏg�p����O���[�v���[�_�[�iCriFsGroupLoader�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsGroupLoader_Create �֐����g�p���ăO���[�v���[�_�[���쐬����ꍇ�A
		�{�p�����[�^�Ɏg�p����O���[�v���[�_�[�̐����w�肷��K�v������܂��B<br>
		<br>
		num_group_loaders�ɂ́u�����Ɏg�p����O���[�v���[�_�[�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsGroupLoader_Create �֐��� ::criFsGroupLoader_Destroy �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃O���[�v���[�_�[�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�num_group_loaders��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃO���[�v���[�_�[��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃO���[�v���[�_�[��S���g�p���Ȃ��ꍇ�ł����Ă��A
		num_group_loaders��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p����O���[�v���[�_�[�̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Anum_group_loaders�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\sa criFsGroupLoader_Create, criFsGroupLoader_Destroy
	*/
	CriSint32 num_group_loaders;

	/*JP
		\brief �g�p����CriFsStdio�̐�
		\par ����:
		�A�v���P�[�V�������Ŏg�p����CriFsStdio�n���h���̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsStdio_OpenFile �֐����g�p����CriFsStdio�n���h�����쐬����ꍇ�A
		�{�p�����[�^�Ɏg�p����CriFsStdio�n���h���̐����w�肷��K�v������܂��B<br>
		<br>
		num_stdio_handles�ɂ́u�����Ɏg�p����CriFsStdio�n���h���̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsStdio_OpenFile �֐��� ::criFsStdio_CloseFile �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1��CriFsStdio�n���h�������g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�num_stdio_handles��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂ�CriFsStdio�n���h����10�g�p����ꍇ�ɂ́A���̑��̏�ʂ�CriFsStdio�n���h����S���g�p���Ȃ��ꍇ�ł����Ă��A
		num_stdio_handles��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p����CriFsStdio�n���h���̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Anum_stdio_handles�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\attention
		�u���b�W���C�u�������g�p����ADX���C�u������~���僉�C�u�����𕹗p����ꍇ�A
		ADXT�n���h����criSsPly�n���h���͓����I��CriFsStdio�n���h�����쐬���܂��B<br>
		���̂��߁A�u���b�W���C�u�������g�p����ꍇ�ɂ́ACRI File System���C�u��������������
		num_stdio_handles��ADXT�n���h����criSsPly�n���h���̐����������l���w�肵�Ă��������B<br>
		\sa criFsStdio_OpenFile, criFsStdio_CloseFile
	*/
	CriSint32 num_stdio_handles;

	/*JP
		\brief �g�p����CriFsInstaller�̐�
		\par ����:
		�A�v���P�[�V�������Ŏg�p����C���X�g�[���[�iCriFsInstaller�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� criFsInstaller_Create �֐����g�p���ăC���X�g�[���[���쐬����ꍇ�A
		�{�p�����[�^�Ɏg�p����C���X�g�[���[�̐����w�肷��K�v������܂��B<br>
		<br>
		num_installers�ɂ́u�����Ɏg�p����C���X�g�[���[�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A criFsInstaller_Create �֐��� criFsInstaller_Destroy �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃C���X�g�[���[�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�num_installers��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃC���X�g�[���[��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃC���X�g�[���[��S���g�p���Ȃ��ꍇ�ł����Ă��A
		num_installers��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p����C���X�g�[���[�̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Anum_installers�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\attention
		::criFs_SetDefaultConfig �}�N�����g�p���ăR���t�B�M�����[�V����������������ꍇ�Anum_installers�̐���0�ɐݒ肳��܂��B<br>
		���̂��߁A�C���X�g�[���[���g�p����ꍇ�ɂ́A�A�v���P�[�V��������num_installers�𖾎��I�Ɏw�肷��K�v������܂��B<br>
	*/
	CriSint32 num_installers;

	/*JP
		\brief �ő哯���o�C���h��
		\par ����:
		�A�v���P�[�V�������Ńo�C���h�������s���A�ێ�����o�C���hID�iCriFsBindId�j�̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsBinder_BindCpk �֐������g�p���ăo�C���h�������s���ꍇ�A
		�{�p�����[�^�Ɏg�p����o�C���hID�̐����w�肷��K�v������܂��B<br>
		<br>
		max_binds�ɂ́u�����Ɏg�p����o�C���hID�̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsBinder_BindCpk �֐��� ::criFsBinder_Unbind �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃o�C���hID�����g�p���Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�max_binds��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃo�C���hID��10�g�p����ꍇ�ɂ́A���̑��̏�ʂŃo�C���h����؍s��Ȃ��ꍇ�ł����Ă��A
		max_binds��10���w�肷��K�v������܂��B<br>
		\par ���l:
		CRI File System���C�u�����́A�g�p����o�C���hID�̐��������̃����������������ɗv�����܂��B<br>
		���̂��߁Amax_binds�ɕK�v�ŏ����̒l���Z�b�g���邱�ƂŁA���C�u�������K�v�Ƃ��郁�����̃T�C�Y��}���邱�Ƃ��\�ł��B<br>
		\sa criFsBinder_BindCpk, criFsBinder_BindFile, criFsBinder_BindFiles, criFsBinder_BindDirectory, criFsBinder_Unbind
	*/
	CriSint32 max_binds;

	/*JP
		\brief �ő哯���I�[�v���t�@�C����
		\par ����:
		�A�v���P�[�V�������ŃI�[�v������t�@�C���̐����w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsStdio_OpenFile �֐������g�p���ăt�@�C�����I�[�v������ꍇ�A
		�{�p�����[�^�ɃI�[�v������t�@�C���̐����w�肷��K�v������܂��B<br>
		<br>
		max_files�ɂ́u�����ɃI�[�v������t�@�C���̍ő吔�v���w�肵�܂��B<br>
		�Ⴆ�΁A ::criFsStdio_OpenFile �֐��� ::criFsStdio_CloseFile �֐������݂ɑ����Ď��s����P�[�X�ɂ����ẮA
		�ő哯���ɂ�1�̃t�@�C�������I�[�v�����Ȃ����߁A�֐��̌Ăяo���񐔂Ɋ֌W�Ȃ�max_files��1���w�肷�邱�Ƃ��\�ł��B<br>
		�t�ɁA�����ʂŃt�@�C����10�I�[�v������ꍇ�ɂ́A���̑��̏�ʂŃt�@�C����1�����I�[�v�����Ȃ��ꍇ�ł����Ă��A
		max_files��10���w�肷��K�v������܂��B<br>
		\par �⑫:
		CRI File System���C�u�����́A�ȉ��̊֐������s�����ꍇ�Ƀt�@�C�����I�[�v�����܂��B<br>
		\table "�t�@�C�����I�[�v���������" align=center border=1 cellspacing=0 cellpadding=4
		{�֐�					|���l	}
		[criFsBinder_BindCpk	|�I�[�v�������t�@�C���̐���1�B<br> criFsBinder_Unbind �֐������s�����܂ł̊ԃt�@�C���̓I�[�v�����ꑱ����B	]
		[criFsBinder_BindFile	|�I�[�v�������t�@�C���̐���1�B<br> criFsBinder_Unbind �֐������s�����܂ł̊ԃt�@�C���̓I�[�v�����ꑱ����B	]
		[criFsBinder_BindFiles	|���X�g�Ɋ܂܂�鐔���t�@�C�����I�[�v�������B<br> criFsBinder_Unbind �֐������s�����܂Ńt�@�C���̓I�[�v�����ꑱ����B	]
		[criFsLoader_Load		|�I�[�v�������t�@�C���̐���1�B<br> ���[�h����������܂ł̊ԃt�@�C���̓I�[�v�����ꑱ����B<br> �o�C���_�[���w�肵���ꍇ�A�t�@�C���̓I�[�v������Ȃ��i�o�C���_�[�����ɃI�[�v���ς݂̂��߁j�B	]
		[criFsStdio_OpenFile	|�I�[�v�������t�@�C���̐���1�B<br> criFsStdio_CloseFile �֐������s�����܂ł̊ԃt�@�C���̓I�[�v�����ꑱ����B<br> �o�C���_�[���w�肵���ꍇ�A�t�@�C���̓I�[�v������Ȃ��i�o�C���_�[�����ɃI�[�v���ς݂̂��߁j�B	]
		[criFsInstaller_Copy	|�I�[�v�������t�@�C���̐���2�B<br> �t�@�C���R�s�[����������܂ł̊ԃt�@�C���̓I�[�v�����ꑱ����B<br> �o�C���_�[���w�肵���ꍇ�A�I�[�v�������t�@�C����1�ɂȂ�i1���o�C���_�[�����ɃI�[�v���ς݂̂��߁j�B	]
		\endtable
		\attention
		�u���b�W���C�u�������g�p����ADX���C�u������~���僉�C�u�����𕹗p����ꍇ�A
		ADXT�n���h����criSsPly�n���h���͓����I��CriFsStdio�n���h�����쐬���܂��B<br>
		���̂��߁A�u���b�W���C�u�������g�p����ꍇ�ɂ́ACRI File System���C�u��������������
		max_files��ADXT�n���h����criSsPly�n���h���̐����������l���w�肵�Ă��������B<br>
	*/
	CriSint32 max_files;

	/*JP
		\brief �p�X�̍ő咷�i�o�C�g�P�ʁj
		\par ����:
		�A�v���P�[�V�������Ŏw�肷��t�@�C���p�X�̍ő咷���w�肵�܂��B<br>
		�A�v���P�[�V�������� ::criFsLoader_Load �֐������g�p���ăt�@�C���ɃA�N�Z�X����ꍇ�A
		�{�p�����[�^�ɃA�v���P�[�V�����Ŏg�p����p�X������̍ő咷���w�肷��K�v������܂��B<br>
		<br>
		max_path�ɂ́u�g�p����p�X������̍ő吔�v���w�肵�܂��B<br>
		�����ʂ�256�o�C�g�̃t�@�C���p�X���g�p����ꍇ�A���̑��̏�ʂ�32�o�C�g�̃t�@�C���p�X�����g��Ȃ��ꍇ�ł��A
		max_path�ɂ�256���w�肷��K�v������܂��B<br>
		\par ���l:
		�p�X�̍ő咷�ɂ́A�I�[��NULL�������܂񂾐����w�肷��K�v������܂��B<br>
		�i�u�������{�P�o�C�g�v�̒l���w�肷��K�v������܂��B�j<br>
		\attention
		PC���A���[�U�[���A�v���P�[�V���������R�ȏꏊ�ɃC���X�g�[���\�ȏꍇ�ɂ́A�z�肳���ő�T�C�Y�� max_path �Ɏw�肷��K�v������܂��̂ŁA�����ӂ��������B<br>
	*/
	CriSint32 max_path;

	/*JP
		\brief ���C�u�����o�[�W�����ԍ�
		\par ����:
		CRI File System���C�u�����̃o�[�W�����ԍ��ł��B<br>
		::criFs_SetDefaultConfig �֐��ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W�����ԍ����ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	*/
	CriUint32 version;

	/*JP
		\brief ���C�u�����o�[�W����������
		\par ����:
		CRI File System���C�u�����̃o�[�W����������ł��B<br>
		::criFs_SetDefaultConfig �֐��ɂ��A�{�w�b�_�[�ɒ�`����Ă���o�[�W���������񂪐ݒ肳��܂��B<br>
		\attention
		�A�v���P�[�V�����ł́A���̒l��ύX���Ȃ��ł��������B<br>
	 */
	const CriChar8 *version_string;

	/*JP
		\brief CPK�t�@�C����CRC�`�F�b�N���s�����ǂ���
		\par ����:
		CPK�t�@�C������CRC�����g�p���A�f�[�^�������`�F�b�N���s�������ǂ�����؂�ւ���t���O�ł��B<br>
		�{�t���O�� CRI_TRUE �ɐݒ肷��ƁA�ȉ��̃^�C�~���O��CRC�`�F�b�N���s���܂��B
		 - CPK�o�C���h����TOC����CRC�`�F�b�N
		 - �R���e���c�t�@�C�����[�h���ɃR���e���c�t�@�C���P�ʂ�CRC�`�F�b�N
		CPK�ɕt�����ꂽCRC���ƁA���ۂɓǂ݂��񂾃f�[�^��CRC����v���Ȃ��ꍇ�A�G���[�ƂȂ�܂��B
	 */
	CriBool enable_crc_check;
} CriFsConfig;

/*JP
 * \brief �������m�ۊ֐�
 * \ingroup FSLIB_CRIFS
 * \param[in]	obj		���[�U�[�w��I�u�W�F�N�g
 * \param[in]	size	�v���������T�C�Y�i�o�C�g�P�ʁj
 * \return		void*	�m�ۂ����������̃A�h���X�i���s����NULL�j
 * \par ����:
 * �������m�ۊ֐��o�^�p�̃C���^�[�t�F�C�X�ł��B<br>
 * CRI File System���C�u���������C�u�������ōs�Ȃ��������m�ۏ������A
 * ���[�U�[�Ǝ��̃������m�ۏ����ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * \par ���l:
 * �R�[���o�b�N�֐������s�����ۂɂ́Asize�ɕK�v�Ƃ���郁�����̃T�C�Y���Z�b�g
 * ����Ă��܂��B<br>
 * �R�[���o�b�N�֐�����size���̃��������m�ۂ��A�m�ۂ����������̃A�h���X��
 * �߂�l�Ƃ��ĕԂ��Ă��������B<br>
 * ���A������ obj �ɂ́A::criFs_SetUserMallocFunction �֐��œo�^�������[�U�[�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g�� ::criFs_SetUserMallocFunction �֐��̈����ɃZ�b�g���Ă����A
 * �{�R�[���o�b�N�֐��̈������o�R���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * �������̊m�ۂɎ��s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ��ꂽ��A�Ăяo�����̊֐���
 * ���s����\��������܂��̂ł����ӂ��������B
 * \sa CriFsFreeFunc, criFs_SetUserMallocFunction
 */
typedef void *(CRIAPI *CriFsMallocFunc)(void *obj, CriUint32 size);

/*JP
 * \brief ����������֐�
 * \ingroup FSLIB_CRIFS
 * \param[in]	obj		���[�U�[�w��I�u�W�F�N�g
 * \param[in]	mem		������郁�����A�h���X
 * \return				�Ȃ�
 * \par ����:
 * ����������֐��o�^�p�̃C���^�[�t�F�C�X�ł��B<br>
 * CRI File System���C�u�����������C�u�������ōs�Ȃ�����������������A
 * ���[�U�[�Ǝ��̃�������������ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * \par ���l:
 * �R�[���o�b�N�֐������s�����ۂɂ́Amem�ɉ�����ׂ��������̃A�h���X���Z�b�g
 * ����Ă��܂��B<br>
 * �R�[���o�b�N�֐�����mem�̗̈�̃�������������Ă��������B
 * ���A������ obj �ɂ́A::criFs_SetUserFreeFunction �֐��œo�^�������[�U�[�w��
 * �I�u�W�F�N�g���n����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g�� ::criFs_SetUserFreeFunction �֐��̈����ɃZ�b�g���Ă����A
 * �{�R�[���o�b�N�֐��̈������o�R���ĎQ�Ƃ��Ă��������B<br>
 * \sa criFsMallocFunc, criFs_SetUserFreeFunction
 */
typedef void (CRIAPI *CriFsFreeFunc)(void *obj, void *mem);


/*==========================================================================
 *      CriFsIo API
 *=========================================================================*/
/*JP
 * \brief �f�o�C�XID
 */
/*EN
 * \brief Device ID
 */
typedef enum CriFsDeviceIdTag {
	CRIFS_DEVICE_00 = 0,	/*JP< �f�t�H���g�f�o�C�X */
	CRIFS_DEVICE_01,
	CRIFS_DEVICE_02,
	CRIFS_DEVICE_03,
	CRIFS_DEVICE_04,
	CRIFS_DEVICE_05,
	CRIFS_DEVICE_06,
	CRIFS_DEVICE_07,		/*JP< ������ */
	CRIFS_DEVICE_MAX,

	CRIFS_DEVICE_INVALID	= -1,	/*JP< ���� */

	/* enum be 4bytes */
	CRIFS_DEVICE_ENUM_BE_SINT32 = 0x7fffffff
} CriFsDeviceId;


/*JP
 * \brief �t�@�C���I�[�v�����[�h
 */
/*EN
 * \brief File Opening Mode
 */
typedef enum {
	CRIFS_FILE_MODE_APPEND			= 0,	/*JP< �����t�@�C���ɒǋL								*/	/*EN< Appends to an existing file						*/
	CRIFS_FILE_MODE_CREATE			= 1,	/*JP< �t�@�C���̐V�K�쐬�i�����̃t�@�C���͏㏑���j		*/	/*EN< Creates a new file always							*/
	CRIFS_FILE_MODE_CREATE_NEW		= 2,	/*JP< �t�@�C���̐V�K�쐬�i�㏑���s�j					*/	/*EN< Creates a new file (Can not overwrite)			*/
	CRIFS_FILE_MODE_OPEN			= 3,	/*JP< �����t�@�C���̃I�[�v��							*/	/*EN< Opens an existing file							*/
	CRIFS_FILE_MODE_OPEN_OR_CREATE	= 4,	/*JP< �t�@�C���̃I�[�v���i���݂��Ȃ��ꍇ�͐V�K�쐬�j	*/	/*EN< Opens a file if available (Or creates new file)	*/
	CRIFS_FILE_MODE_TRUNCATE		= 5,	/*JP< �����t�@�C����0Byte�ɐ؂�l�߂ăI�[�v��			*/	/*EN< Opens a file and truncates it						*/

	/* enum be 4bytes */
	CRIFS_FILE_MODE_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsFileMode;

/*JP
 * \brief �t�@�C���A�N�Z�X���
 */
/*EN
 * \brief Kind of File Access
 */
typedef enum {
	CRIFS_FILE_ACCESS_READ			= 0,	/*JP< �ǂݍ��݂̂�		*/	/*EN< Read Only			*/
	CRIFS_FILE_ACCESS_WRITE			= 1,	/*JP< �������݂̂�		*/	/*EN< Write Only		*/
	CRIFS_FILE_ACCESS_READ_WRITE	= 2,	/*JP< �ǂݏ���			*/	/*EN< Read and Write	*/

	/* enum be 4bytes */
	CRIFS_FILE_ACCESS_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsFileAccess;

/*JP
 * \brief I/O�C���^�[�t�F�C�X�̃G���[�R�[�h
 */
/*JP
 * \brief Error of I/O Interface
 */
typedef enum {
	CRIFS_IO_ERROR_OK				=   0,	/*JP< �G���[�Ȃ� */
	CRIFS_IO_ERROR_NG				=  -1,	/*JP< ��ʃG���[ */
	CRIFS_IO_ERROR_TRY_AGAIN		=  -2,	/*JP< ���g���C���ׂ� */

											/* ���� */
	CRIFS_IO_ERROR_NG_NO_ENTRY		= -11,	/*JP< �ʃG���[�i�t�@�C�������j */
	CRIFS_IO_ERROR_NG_INVALID_DATA	= -12,	/*JP< �ʃG���[�i�f�[�^���s���j */

	/* enum be 4bytes */
	CRIFS_IO_ERROR_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsIoError;

/*JP
 * \brief �t�@�C���n���h��
 */
/*EN
 * \brief File Handle
 */
typedef void *CriFsFileHn;

/*JP
 * \brief I/O�C���^�[�t�F�C�X
 */
/*EN
 * \brief I/O Interface
 */
typedef struct CriFsIoInterfaceTag {
	/*JP
	 * \brief �t�@�C���̗L���̊m�F
	 * \param[in]	path	�t�@�C���̃p�X
	 * \param[out]	result	�t�@�C�������݂��邩�ǂ���
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �w�肳�ꂽ�t�@�C���̗L�����m�F����֐��ł��B<br>
	 * �t�@�C�������݂���ꍇ�� CRI_TRUE ���A
	 * ���݂��Ȃ��ꍇ�� CRI_FALSE �� result �ɃZ�b�g����K�v������܂��B<br>
	 */
	CriFsIoError (CRIAPI *Exists)(const CriChar8 *path, CriBool *result);

	/*JP
	 * \brief �t�@�C���̍폜
	 * \param[in]	path	�t�@�C���̃p�X
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �w�肳�ꂽ�t�@�C�����폜����֐��ł��B<br>
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *Remove)(const CriChar8 *path);

	/*JP
	 * \brief �t�@�C�����̕ύX
	 * \param[in]	old_path	���l�[���O�̃t�@�C���̃p�X
	 * \param[in]	new_path	���l�[����̃t�@�C���̃p�X
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �t�@�C�����̕ύX���s�Ȃ��֐��ł��B<br>
	 * old_path �Ŏw�肳�ꂽ�t�@�C�����A new_path �Ƀ��l�[�����܂��B<br>
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *Rename)(const CriChar8 *old_path, const CriChar8 *new_path);

	/*JP
	 * \brief �t�@�C���̃I�[�v��
	 * \param[in]	path	�t�@�C���̃p�X
	 * \param[in]	mode	�t�@�C���I�[�v�����[�h
	 * \param[in]	access	�t�@�C���A�N�Z�X���
	 * \param[out]	filehn	�t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �w�肳�ꂽ�t�@�C�����I�[�v������֐��ł��B<br>
	 * �I�[�v���ɐ��������ꍇ�ACriFsFileHn �^�̃t�@�C���n���h����Ԃ��K�v������܂��B<br>
	 * \par �⑫:
	 * CriFsFileHn �� void �|�C���^�[�Ƃ��Ē�`����Ă��܂��B<br>
	 * �Ǝ��̃t�@�C�����\���̂��`���A���̃A�h���X�� CriFsFileHn �^�ɃL���X�g���ĕԂ��Ă��������B<br>
	 * ���A�t�@�C���I�[�v�����Ƀ������̊m�ۂ��K�v�ȏꍇ�ɂ́A�{�֐����œ��I�Ƀ������̊m�ۂ��s�Ȃ��Ă��������B<br>
	 * \attention
	 * �߂�l�̃G���[�R�[�h�i CriFsIoError �j�ɂ́A�֐����Ōp���s�\�ȃG���[����������
	 * �ꍇ�Ɍ��� CRIFS_IO_ERROR_NG ���Z�b�g���Ă��������B<br>
	 * �i�t�@�C���̃I�[�v���Ɏ��s�����ꍇ�ł��A�A�v���P�[�V�����ŏ������p���\�ȏꍇ�ɂ�
	 * filehn �� NULL ���Z�b�g���ACRIFS_IO_ERROR_OK ��Ԃ��K�v������܂��B�j<br>
	 * �܂��A�f�B�X�N�}���҂����̗��R�ɂ��A�֐������s���ꂽ�^�C�~���O�ŃI�[�v������
	 * �����s�ł��Ȃ��ꍇ�A�G���[�R�[�h�Ƃ��� CRIFS_IO_ERROR_TRY_AGAIN ��Ԃ����ƂŁA
	 * ��莞�Ԍ�i��10ms��j�ɍēx�I�[�v����������蒼�����Ƃ��\�ł��B<br>
	 * �i�֐��̎��s�^�C�~���O��摗�肷�邱�Ƃ��\�ł��B�j
	 */
	CriFsIoError (CRIAPI *Open)(
		const CriChar8 *path, CriFsFileMode mode, CriFsFileAccess access, CriFsFileHn *filehn);

	/*JP
	 * \brief �t�@�C���̃N���[�Y
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �w�肳�ꂽ�t�@�C���n���h�����N���[�Y����֐��ł��B<br>
	 * �t�@�C���I�[�v�����ɓ��I�Ƀ������̊m�ۂ��s�Ȃ����ꍇ�́A�N���[�Y���Ƀ�������������Ă��������B<br>
	 */
	CriFsIoError (CRIAPI *Close)(CriFsFileHn filehn);

	/*JP
	 * \brief �t�@�C���T�C�Y�̎擾
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	file_size	�t�@�C���T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �w�肳�ꂽ�t�@�C���n���h������A���Y�t�@�C���̃T�C�Y���擾����֐��ł��B<br>
	 * \attention
	 * ���̊֐��̓��C���X���b�h�ォ�璼�ڎ��s�����\��������܂��B<br>
	 * ���̂��߁A���̊֐��̒��Œ����ԏ������u���b�N���邱�Ƃ͔�����K�v������܂��B<br>
	 * �t�@�C���n���h������t�@�C���T�C�Y���擾����̂Ɏ��Ԃ�������ꍇ�ɂ́A
	 * �t�@�C���I�[�v�����ɂ��炩���߃t�@�C���T�C�Y���擾�i�t�@�C���n���h�����ɕێ��j
	 * ���Ă����A�{�֐����s���ɂ��̒l��Ԃ��悤�֐����������Ă��������B<br>
	 */
	CriFsIoError (CRIAPI *GetFileSize)(CriFsFileHn filehn, CriSint64 *file_size);

	/*JP
	 * \brief �ǂݍ��݂̊J�n
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[in]	offset	�ǂݍ��݊J�n�ʒu
	 * \param[in]	read_size	�ǂݍ��݃T�C�Y
	 * \param[in]	buffer	�ǂݍ��ݐ�o�b�t�@�[
	 * \param[in]	buffer_size	�o�b�t�@�[�T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �f�[�^�̓ǂݍ��݂��J�n����֐��ł��B<br>
	 * offset �Ŏw�肳�ꂽ�ʒu����A read_size �Ŏw�肳�ꂽ�T�C�Y�������f�[�^��
	 * buffer �ɓǂݍ��݂܂��B<br>
	 * �֐��̃C���^�[�t�F�C�X�Ƃ��Ă͔񓯊�I/O�����ɂ�������z�肵�Ă��܂����A
	 * �X���b�h���g�p����ꍇ�i�X���b�h���f���� CRIFS_THREAD_MODEL_MULTI ���w�肷��ꍇ�j
	 * �ɂ́A���̊֐��𓯊�I/O�������g���Ď������Ă���肠��܂���B<br>
	 * �i�֐����Ńt�@�C���̓ǂݍ��݂���������܂ő҂��Ă���肠��܂���B�j<br>
	 * \attention
	 * ���ۂɓǂݍ��߂��T�C�Y�́A GetReadSize �֐��ŕԂ��K�v������܂��B<br>
	 * ����I/O�����ɂ��{�֐�����������ꍇ�ł��A�ǂݍ��߂��T�C�Y�� GetReadSize �֐�
	 * �����s�����܂ŁA�t�@�C���n���h�����ɕێ�����K�v������܂��B<br>
	 */
	CriFsIoError (CRIAPI *Read)(CriFsFileHn filehn, CriSint64 offset, CriSint64 read_size, void *buffer, CriSint64 buffer_size);

	/*JP
	 * \brief �ǂݍ��݊����`�F�b�N
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	result	�t�@�C���̓ǂݍ��݂������������ǂ���
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �t�@�C���̓ǂݍ��݂������������ǂ������m�F����֐��ł��B<br>
	 * �t�@�C���̓ǂݍ��݂����������ꍇ�� CRI_TRUE ���A
	 * �ǂݍ��ݓr���̏ꍇ�� CRI_FALSE �� result �ɃZ�b�g����K�v������܂��B<br>
	 * \attention
	 * result �ɂ́A���[�h�����̐��ۂɊ֌W�Ȃ��A���[�h�����������������_
	 * �i�f�o�C�X�ւ̃A�N�Z�X���I���������_�j�� CRI_TRUE ���Z�b�g����K�v������܂��B<br>
	 * ���[�h�G���[�����������ꍇ�ł��A result �� CRI_TRUE ���Z�b�g���A
	 * �֐��̖߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B<br>
	 * �i���[�h�����������������ǂ����ɂ��ẮA GetReadSize �֐��Ŕ��ʂ��Ă��܂��B�j<br>
	 * result �� CRI_FALSE ��Ԃ�����́ACRI File System
	 * ���C�u�����͑��̓ǂݍ��ݗv������؏������܂���B<br>
	 * �i���[�h�G���[�������� result �� CRI_FALSE ���Z�b�g���������ꍇ�A
	 * �t�@�C���̃��[�h���ł��Ȃ��Ȃ�����A�n���h����
	 * Destroy �֐����珈�������A���Ȃ��Ȃ�\��������܂��B<br>
	 */
	CriFsIoError (CRIAPI *IsReadComplete)(CriFsFileHn filehn, CriBool *result);

	/*JP
	 * \brief �t�@�C���ǂݍ��݂̃L�����Z�����s
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �f�o�C�X���̃t�@�C���ǂݍ��݂ɑ΂��ăL�����Z���𔭍s���A�����ɕ��A����֐��ł��B
	 * �߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B<br>
	 * CRIFS_IO_ERROR_OK�ȊO�̒l��Ԃ��Ă��A
	 * CRI File System�̓����CRIFS_IO_ERROR_OK��Ԃ����ꍇ�Ɠ����ł��B<br>
	 */
	CriFsIoError (CRIAPI *CancelRead)(CriFsFileHn filehn);

	/*JP
	 * \brief �ǂݍ��݃T�C�Y�̎擾
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	read_size	�ǂݍ��߂��T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * ���[�h�������s�Ȃ������ʁA���ۂɃo�b�t�@�[�ɓǂݍ��߂��f�[�^�̃T�C�Y��Ԃ��֐��ł��B<br>
	 * �t�@�C���̏I�[���ł́A Read �֐��Ŏw�肵���T�C�Y���̃f�[�^���K�������ǂݍ��߂�Ƃ͌���܂���B<br>
	 * \attention
	 * ���[�h�G���[�����������ꍇ�A read_size �� -1 ���Z�b�g���A
	 * �֐��̖߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B
	 */
	CriFsIoError (CRIAPI *GetReadSize)(CriFsFileHn filehn, CriSint64 *read_size);

	/*JP
	 * \brief �������݂̊J�n
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[in]	offset	�������݊J�n�ʒu
	 * \param[in]	write_size	�������݃T�C�Y
	 * \param[in]	buffer	�������ݐ�o�b�t�@�[
	 * \param[in]	buffer_size	�o�b�t�@�[�T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �f�[�^�̏������݂��J�n����֐��ł��B<br>
	 * offset �Ŏw�肳�ꂽ�ʒu����A write_size �Ŏw�肳�ꂽ�T�C�Y�������f�[�^��
	 * buffer ���珑�����݂܂��B<br>
	 * �֐��̃C���^�[�t�F�C�X�Ƃ��Ă͔񓯊�I/O�����ɂ�������z�肵�Ă��܂����A
	 * �X���b�h���g�p����ꍇ�i�X���b�h���f���� CRIFS_THREAD_MODEL_MULTI ���w�肷��ꍇ�j
	 * �ɂ́A���̊֐��𓯊�I/O�������g���Ď������Ă���肠��܂���B<br>
	 * �i�֐����Ńt�@�C���̏������݂���������܂ő҂��Ă���肠��܂���B�j<br>
	 * \attention
	 * ���ۂɏ������߂��T�C�Y�́A GetWriteSize �֐��ŕԂ��K�v������܂��B<br>
	 * ����I/O�����ɂ��{�֐�����������ꍇ�ł��A�������߂��T�C�Y�� GetWriteSize �֐�
	 * �����s�����܂ŁA�t�@�C���n���h�����ɕێ�����K�v������܂��B<br>
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *Write)(CriFsFileHn filehn, CriSint64 offset, CriSint64 write_size, void *buffer, CriSint64 buffer_size);

	/*JP
	 * \brief �������݊����`�F�b�N
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	result	�t�@�C���̏������݂������������ǂ���
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �t�@�C���̏������݂������������ǂ������m�F����֐��ł��B<br>
	 * �t�@�C���̏������݂����������ꍇ�� CRI_TRUE ���A
	 * �������ݓr���̏ꍇ�� CRI_FALSE �� result �ɃZ�b�g����K�v������܂��B<br>
	 * \attention
	 * ���C�g�G���[�����������ꍇ�A result �� CRI_TRUE ���Z�b�g���A
	 * �֐��̖߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 * \attention
	 * result �ɂ́A���C�g�����̐��ۂɊ֌W�Ȃ��A���C�g�����������������_
	 * �i�f�o�C�X�ւ̃A�N�Z�X���I���������_�j�� CRI_TRUE ���Z�b�g����K�v������܂��B<br>
	 * ���C�g�G���[�����������ꍇ�ł��A result �� CRI_TRUE ���Z�b�g���A
	 * �֐��̖߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B<br>
	 * �i���C�g�����������������ǂ����ɂ��ẮA GetReadSize �֐��Ŕ��ʂ��Ă��܂��B�j<br>
	 * result �� CRI_FALSE ��Ԃ�����́ACRI File System
	 * ���C�u�����͑��̓ǂݍ��ݗv������؏������܂���B<br>
	 * �i���C�g�G���[�������� result �� CRI_FALSE ���Z�b�g���������ꍇ�A
	 * �t�@�C���̃��[�h���ł��Ȃ��Ȃ�����A�n���h����
	 * Destroy �֐����珈�������A���Ȃ��Ȃ�\��������܂��B<br>
	 */
	CriFsIoError (CRIAPI *IsWriteComplete)(CriFsFileHn filehn, CriBool *result);

	/*JP
	 * \brief �t�@�C���������݂̃L�����Z�����s
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �f�o�C�X���̃t�@�C���������݂ɑ΂��ăL�����Z���𔭍s���A�����ɕ��A����֐��ł��B
	 * �߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B<br>
	 * CRIFS_IO_ERROR_OK�ȊO�̒l��Ԃ��Ă��A
	 * CRI File System�̓����CRIFS_IO_ERROR_OK��Ԃ����ꍇ�Ɠ����ł��B<br>
	 */
	CriFsIoError (CRIAPI *CancelWrite)(CriFsFileHn filehn);

	/*JP
	 * \brief �������݃T�C�Y�̎擾
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	write_size	�������߂��T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * ���C�g�������s�Ȃ������ʁA���ۂɃo�b�t�@�[�ɓǂݍ��߂��f�[�^�̃T�C�Y��Ԃ��֐��ł��B<br>
	 * \attention
	 * ���C�g�G���[�����������ꍇ�A write_size �� -1 ���Z�b�g���A
	 * �֐��̖߂�l�� CRIFS_IO_ERROR_OK ��Ԃ��Ă��������B
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *GetWriteSize)(CriFsFileHn filehn, CriSint64 *write_size);

	/*JP
	 * \brief �t���b�V���̎��s
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �������ݗp�Ƀo�b�t�@�[�����O����Ă���f�[�^���A
	 * �����I�Ƀf�o�C�X�ɏ����o���������s���֐��ł��B<br>
	 * �i ANSI C �W���� API �ł� fflush �֐��ɑ������鏈���ł��B�j<br>
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *Flush)(CriFsFileHn filehn);

	/*JP
	 * \brief �t�@�C���T�C�Y�̕ύX
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	size	�t�@�C���T�C�Y
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �t�@�C���̃T�C�Y���w�肵���T�C�Y�ɕύX����֐��ł��B<br>
	 * \par �⑫:
	 * �{�֐��́ADMA�]���T�C�Y�̐������ɂ��f�o�C�X�ւ̏������݂��o�C�g�P�ʂ�
	 * �s�Ȃ��Ȃ��ꍇ�ɁA�t�@�C���T�C�Y��␳���邽�߂Ɏg�p���܂��B<br>
	 * ���̂��߁A�������݂��o�C�g�P�ʂŉ\�ȃf�o�C�X�ɂ��ẮA���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 * \par ���l:
	 * �f�o�C�X�ŏ������݂��s�Ȃ�Ȃ��ꍇ�ɂ́A���̊֐������������A
	 * �\���̂̃����o�[�� CRI_NULL ���w�肷�邱�Ƃ��\�ł��B<br>
	 */
	CriFsIoError (CRIAPI *Resize)(CriFsFileHn filehn, CriSint64 size);

	/*JP
	 * \brief �l�C�e�B�u�t�@�C���n���h���̎擾
	 * \param[in]	filehn	�t�@�C���n���h��
	 * \param[out]	native_filehn	�l�C�e�B�u�̃t�@�C���n���h��
	 * \return	CriFsIoError	�G���[�R�[�h
	 * \par ����:
	 * �v���b�g�t�H�[��SDK�ŗ��p�����t�@�C���̃n���h�����擾����֐��ł��B<br>
	 * �Ⴆ�΁A ANSI C �W���� fopen �֐����g�p���ăt�@�C�����I�[�v�������ꍇ�A
	 * native_filehn �Ƃ��ăt�@�C���|�C���^�[�i FILE * �j��Ԃ��K�v������܂��B<br>
	 * \par ���l:
	 * ����APLAYSTATION3�ȊO�̋@��ł͂��̊֐�����������K�v�͂���܂���B<br>
	 */
	CriFsIoError (CRIAPI *GetNativeFileHandle)(CriFsFileHn filehn, void **native_filehn);

	/*JP
	 * \brief �ǂݍ��݃v���O���X���Z�R�[���o�b�N�̐ݒ�
	 * \param[in]	filehn		�t�@�C���n���h��
	 * \param[in]	callback    �ǂݍ��݃v���O���X���Z�R�[���o�b�N
	 * \param[in]	obj			�����I�u�W�F�N�g
	 * \par ����:
	 * �{�֐��́A::criFsLoader_GetProgress �œ�����i�����A�P�ʓǂݍ��݃T�C�Y���
	 * �ׂ������x�ōX�V�����邽�߂́A�ǂݍ��݃v���O���X���Z�R�[���o�b�N��ݒ肷��֐��ł��B<br>
	 * �{�֐����������Ȃ��ꍇ��A�{�֐��œn���ꂽ�R�[���o�b�N�֐����g�p���Ȃ��ꍇ�A
	 * ::criFsLoader_GetProgress �œ�����i���́A��{�I�ɒP�ʓǂݍ��݃T�C�Y���ɍX�V����܂��B<br>
	 * �{�֐�����������ꍇ�́A�n���ꂽ�R�[���o�b�N�֐��� Read �֐����ŌĂяo���Ă��������B
	 * �܂��A�Ăяo���ۂɂ͑������� obj�A�������Ƀ������ւ̓ǂݍ��݂����������T�C�Y��
	 * �o�C�g�P�ʂœn���Ă��������B<br>
	 * �Ⴆ�΁A���[�h�v�����f�o�C�X���� 8192byte ���ɕ������ēǂݍ��ޏꍇ�́A
	 * 8192byte �̓ǂݍ��݊������ɁA�������� 8192 ��n���ČĂяo���Ă��������B<br>
	 * ���́A�ǂݍ��݃v���O���X���Z�R�[���o�b�N�Ăяo���ɂ���� ::criFsLoader_GetProgress
	 * �œ�����i�����X�V����܂��B�P�ʓǂݍ��݃T�C�Y���ׂ������x�ōX�V��
	 * �s�����Ƃ� ::criFsLoader_GetProgress �œ�����i���̗��x���ׂ����Ȃ�܂��B<br>
	 * \par ���l:
	 * �ǂݍ��݃��N�G�X�g���ׂ������x�œǂݍ��ݐi�����擾�ł��Ȃ��ꍇ�́A
	 * �������郁���b�g�͂���܂���B
	 * \sa ::criFsLoader_GetProgress
	 */
	CriFsIoError (CRIAPI *SetAddReadProgressCallback)(CriFsFileHn filehn, void(*callback)(void*, CriSint32), void* obj);

	/*JP
	 * \brief �����̓����t�@�C���A�N�Z�X�v�����\���ǂ����̖₢���킹
	 * \param[out]	result	�����̓����t�@�C���A�N�Z�X�v�����\���ǂ���
	 * \par ����:
	 * ����I/O�C���^�[�t�F�[�X�������̓����t�@�C���A�N�Z�X�v�����\�ł��邩�ǂ�����Ԃ��֐��ł��B<br>
	 * �{�֐����������Ȃ��ꍇ�A�s�\�ł���Ƃ݂Ȃ���܂��B<br>
	 * �{�֐�����������Ă��āAresult �� CRI_TRUE �������ꍇ�A
	 * criFsLoader �͌����悭�����t�@�C���̃��[�h���s�����߂ɕ���Ń��[�h�v�����s���悤�ɂȂ�܂��B<br>
	 * \par ���l:
	 * ����Ń��[�h�v�����s���ꍇ�ACriFsFileIoMode �� CRIFS_FILE_IO_MODE_OPEN_EVERY_TIME �ł���K�v������܂��B
	 */
	CriFsIoError(CRIAPI *CanParallelRead)(CriBool *result);
} CriFsIoInterface, *CriFsIoInterfacePtr;

/*JP
 * \brief I/O�I���R�[���o�b�N�֐�
 * \param[in]	path	�t�@�C���̃p�X
 * \param[out]	device_id	�f�o�C�XID
 * \param[out]	ioif	I/O�C���^�[�t�F�C�X
 * \par ����:
 * I/O�I���R�[���o�b�N�֐��́ACRI File System���C�u������I/O�������A
 * ���[�U�[�̓Ǝ�I/O�C���^�[�t�F�[�X�Œu��������ۂɎg�p���܂��B<br>
 * ��̓I�ɂ́A���[�U�[�� ::CriFsSelectIoCbFunc �^�̊֐����������A
 * ���̊֐��� ::criFs_SetSelectIoCallback �֐��ɃZ�b�g����K�v������܂��B<br>
 * ::CriFsSelectIoCbFunc �֐��́A���͂��ꂽ�t�@�C���̃p�X�i������path�j����͂��A
 * ���̃t�@�C�������݂���f�o�C�X��ID�i������device_id�j�ƁA
 * �f�o�C�X�ɃA�N�Z�X���邽�߂�I/O�C���^�[�t�F�C�X�i������ioif�j��Ԃ��K�v������܂��B<br>
 * \par �⑫:
 * ���C�u�������f�t�H���g��Ԃŗ��p����I/O�C���^�[�t�F�C�X�́A ::criFs_GetDefaultIoInterface �֐��Ŏ擾�\�ł��B<br>
 * ����̃t�@�C���݂̂�Ǝ���I/O�C���^�[�t�F�C�X�������������ꍇ�ɂ́A
 * ���̃t�@�C����S�� ::criFs_GetDefaultIoInterface �֐��Ŏ擾����I/O�C���^�[�t�F�C�X�ŏ������Ă��������B<br>
 * \code
 * CriError
 * \endcode
 * \sa criFs_SetSelectIoCallback, criFs_GetDefaultIoInterface
 */
typedef CriError (CRIAPI *CriFsSelectIoCbFunc)(const CriChar8 *path, CriFsDeviceId *device_id, CriFsIoInterfacePtr *ioif);

/*==========================================================================
 *      CriFsBinder API
 *=========================================================================*/
struct CriFsBinderHnObjTag;
/*JP
 * \brief CriFsBinder�n���h��
 * \ingroup FSLIB_BINDER
 * \par �����F
 * �o�C���_�[�Ƃ́A�t�@�C���������ǂ��������߂̃f�[�^�x�[�X�ł��B<br>
 * - CriFsBinderHn (�o�C���_�[�n���h��)�ƃo�C���h<br>
 * �o�C���_�[�𗘗p����ɂ́A�o�C���_�[�n���h��( CriFsBinderHn )���쐬���A
 * CPK�t�@�C���^�t�@�C���^�f�B���N�g�����o�C���_�[�Ɍ��т��܂��B
 * ���̃o�C���_�[�ւ̌��ѕt�����o�C���h�ƌĂт܂��B<br>
 * �o�C���_�[���쐬����ƁA�o�C���_�[�n���h��( CriFsBinderHn )���擾����܂��B<br>
 * - CriFsBindId �i�o�C���hID�j<br>
 * �o�C���_�[�Ƀo�C���h���s���ƁA�o�C���hID���쐬����܂��B�X�̃o�C���h�����ʂ��邽�߂Ɏg�p���܂��B<br>
 * - �t�@�C���̃o�C���h�ƃA���o�C���h<br>
 * �o�C���_�[�ɂ́ACPK�t�@�C����t�@�C���A�f�B���N�g�����ǂ̂悤�ȑg�ݍ��킹�łł��o�C���h�ł��܂��B<br>
 * �o�C���h�������ڂ̃o�C���h��Ԃ��������邱�Ƃ��A���o�C���h�ƌĂт܂��B<br>
 * - ���p�ł���o�C���h��<br>
 * �쐬�ł���o�C���_�[���⓯���Ƀo�C���h�ł���ő吔�́A CriFsConfig ��
 * num_binders (�o�C���_�[��)�� max_binds (�����o�C���h�\�ȍő吔)�Ŏw�肵�܂��B<br>
 * - CPK�t�@�C���̃o�C���h<br>
 * CPK�t�@�C���Ɏ��[����Ă���X�̃t�@�C���i�R���e���c�t�@�C���j�ɃA�N�Z�X����ɂ́A
 * CPK�t�@�C�����o�C���h����K�v������܂��B<br>
 * CPK�t�@�C���̃R���e���c�t�@�C�����o�C���h�ł��܂��B����CPK�t�@�C�����A���o�C���h�����ꍇ�A
 * �o�C���h����Ă���R���e���c�t�@�C�����A���o�C���h����܂��i�ÖٓI�A���o�C���h�j�B<br>
 * - �o�C���_�[�̃v���C�I���e�B<br>
 * �o�C���_�[�́A�ړI�̃t�@�C�����ǂ̃o�C���hID�ɂ���̂����������܂��B<br>
 * ���̃o�C���hID�̌������́A��{�I�ɂ̓o�C���h���ꂽ���ԂɂȂ�܂����A�o�C���hID�̃v���C�I���e�B��
 * ���삷�邱�ƂŁA��������ύX���邱�Ƃ��ł��܂��B<br>
 * - �o�C���_�[��CriFs��API<br>
 * CriFsLoader, CriFsGroupLoader, CriFsBinder�ɂ́A�o�C���_�[�������Ɏ���API������܂��B
 * ���̍ۂɂ́A CriFsBinderHn �� CriFsBindId �A�ǂ�����w�肷��̂��ɒ��ӂ��Ă��������B
 */
typedef struct CriFsBinderHnObjTag *CriFsBinderHn;

/*JP
 * \brief ���[�_�[�v���C�I���e�B
 */
/*EN
 * \brief Priority
 */
typedef enum {
	CRIFSLOADER_PRIORITY_HIGHEST 		= 2,	/*JP< �ō�		*/	/*EN< Highest		*/
	CRIFSLOADER_PRIORITY_ABOVE_NORMAL 	= 1,	/*JP< ��		*/	/*EN< Above normal	*/
	CRIFSLOADER_PRIORITY_NORMAL 		= 0,	/*JP< ����		*/	/*EN< Normal		*/
	CRIFSLOADER_PRIORITY_BELOW_NORMAL 	= -1,	/*JP< ��		*/	/*EN< Below normal	*/
	CRIFSLOADER_PRIORITY_LOWEST 		= -2,	/*JP< �Œ�		*/	/*EN< Lowest		*/
	/* enum be 4bytes */
	CRIFSLOADER_PRIORITY_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriFsLoaderPriority;

/***************************************************************************
 *      �֐��錾
 *      Prototype Functions
 ***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================
 *      CRI File System API
 *=========================================================================*/
/*JP
 * \brief �f�t�H���g�R���t�B�M�����[�V�����̃Z�b�g
 * \ingroup FSLIB_CRIFS
 * \param[in]	p_config	�R���t�B�M�����[�V����
 * \par ����:
 * ::criFs_InitializeLibrary �֐��ɐݒ肷��R���t�B�M�����[�V�����i ::CriFsConfig �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \par �⑫:
 * �R���t�B�M�����[�V�����ɐݒ肷��e�p�����[�^���A�A�v���P�[�V�����Ŏg�p����n���h���̐��ɉ����Ē��߂��邱�ƂŁA
 * ���C�u�������K�v�Ƃ��郁�����T�C�Y���������}���邱�Ƃ��\�ł��B<br>
 * �������A�A�v���P�[�V�������Ŏg�p����n���h���̐������m�łȂ��J�������i�K��A�������T�C�Y���^�C�g�ł͂Ȃ��P�[�X�ł́A
 * �{�}�N�����g�p���邱�Ƃɂ��ŁA�������������ȗ������邱�Ƃ��\�ł��B<br>
 * \attention:
 * �{�}�N���ł́A�قƂ�ǂ̃P�[�X�ŕK�v�[���Ȑ��̃n���h�����m�ۂł���悤�A�R���t�B�M�����[�V�����̊e�p�����[�^�ɑ傫�߂̒l���Z�b�g���܂��B<br>
 * ���̂��߁A�{�}�N�����g�p�����ꍇ�A���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�͑傫���Ȃ�܂��̂ŁA�����ӂ��������B<br>
 * �i�������T�C�Y���^�C�g�ȃP�[�X�ł́A�{�}�N���ŃR���t�B�M�����[�V������������������A�e�p�����[�^���ʂɒ��߂��邱�Ƃ��I�X�X���������܂��B�j<br>
 * \sa
 * CriFsConfig
*/
#define criFs_SetDefaultConfig(p_config)	\
{\
	(p_config)->thread_model		= CRIFS_CONFIG_DEFAULT_THREAD_MODEL;\
	(p_config)->num_binders			= CRIFS_CONFIG_DEFAULT_NUM_BINDERS;\
	(p_config)->num_loaders			= CRIFS_CONFIG_DEFAULT_NUM_LOADERS;\
	(p_config)->num_group_loaders	= CRIFS_CONFIG_DEFAULT_NUM_GROUP_LOADERS;\
	(p_config)->num_stdio_handles	= CRIFS_CONFIG_DEFAULT_NUM_STDIO_HANDLES;\
	(p_config)->num_installers		= CRIFS_CONFIG_DEFAULT_NUM_INSTALLERS;\
	(p_config)->max_binds			= CRIFS_CONFIG_DEFAULT_MAX_BINDS;\
	(p_config)->max_files			= CRIFS_CONFIG_DEFAULT_MAX_FILES;\
	(p_config)->max_path			= CRIFS_CONFIG_DEFAULT_MAX_PATH;\
	(p_config)->version				= CRI_FS_VERSION;\
	(p_config)->version_string		= CRI_FS_VER_NUM;\
	(p_config)->enable_crc_check	= CRI_FALSE;\
}




/*JP
 * \brief �������m�ۊ֐��̓o�^
 * \ingroup FSLIB_CRIFS
 * \param[in]	func		�������m�ۊ֐�
 * \param[in]	obj			���[�U�[�w��I�u�W�F�N�g
 * \par ����:
 * CRI File System���C�u�����Ƀ������m�ۊ֐���o�^���܂��B<br>
 * CRI File System���C�u�����������C�u�������ōs�Ȃ��������m�ۏ������A
 * ���[�U�[�Ǝ��̃������m�ۏ����ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * <br>
 * �{�֐��̎g�p�菇�͈ȉ��̂Ƃ���ł��B<br>
 * (1) ::CriFsMallocFunc �C���^�[�t�F�C�X�ɕ������������m�ۊ֐���p�ӂ���B<br>
 * (2) ::criFs_SetUserMallocFunction �֐����g�p���ACRI File System���C�u�����ɑ΂���
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
 * 	criFs_SetUserMallocFunction(user_malloc, NULL);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * ������ obj �Ɏw�肵���l�́A ::CriFsMallocFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g��{�֐��̈����ɃZ�b�g���Ă����A�R�[���o�b�N�֐��ň������o�R
 * ���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * �������m�ۊ֐���o�^����ۂɂ́A���킹�ă���������֐��i ::CriFsFreeFunc �j��
 * �o�^����K�v������܂��B
 * \sa CriFsMallocFunc, criFs_SetUserFreeFunction
 */
void CRIAPI criFs_SetUserMallocFunction(CriFsMallocFunc func, void *obj);

/*JP
 * \brief ����������֐��̓o�^
 * \ingroup FSLIB_CRIFS
 * \param[in]	func		����������֐�
 * \param[in]	obj			���[�U�[�w��I�u�W�F�N�g
 * \par ����:
 * CRI File System���C�u�����Ƀ���������֐���o�^���܂��B<br>
 * CRI File System���C�u�����������C�u�������ōs�Ȃ�����������������A
 * ���[�U�[�Ǝ��̃�������������ɒu�����������ꍇ�Ɏg�p���܂��B<br>
 * <br>
 * �{�֐��̎g�p�菇�͈ȉ��̂Ƃ���ł��B<br>
 * (1) ::CriFsFreeFunc �C���^�[�t�F�C�X�ɕ���������������֐���p�ӂ���B<br>
 * (2) ::criFs_SetUserFreeFunction �֐����g�p���ACRI File System���C�u�����ɑ΂���
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
 * 	criFs_SetUserFreeFunction(user_free, NULL);
 * 		:
 * }
 * \endcode
 * \par ���l:
 * ������ obj �Ɏw�肵���l�́A ::CriFsFreeFunc �Ɉ����Ƃ��ēn����܂��B<br>
 * �������m�ێ��Ƀ������}�l�[�W���[�����Q�Ƃ���K�v������ꍇ�ɂ́A
 * ���Y�I�u�W�F�N�g��{�֐��̈����ɃZ�b�g���Ă����A�R�[���o�b�N�֐��ň������o�R
 * ���ĎQ�Ƃ��Ă��������B<br>
 * \attention
 * ����������֐���o�^����ۂɂ́A���킹�ă������m�ۊ֐��i ::CriFsMallocFunc �j��
 * �o�^����K�v������܂��B
 * \sa CriFsFreeFunc, criFs_SetUserMallocFunction
 */
void CRIAPI criFs_SetUserFreeFunction(CriFsFreeFunc func, void *obj);















/*JP
 * \brief I/O�I���R�[���o�b�N�̓o�^
 * \ingroup FSLIB_CRIFS
 * \param[in]	func	I/O�I���R�[���o�b�N
 * \return	CriError	�G���[�R�[�h
 * \par ����:
 * I/O�I���R�[���o�b�N�֐��i ::CriFsSelectIoCbFunc �j��o�^���܂��B<br>
 * CRI File System���C�u�����̓t�@�C���ɃA�N�Z�X����ہA�܂����߂ɁA���̃t�@�C�������݂���f�o�C�X��ID�i ::CriFsDeviceId �j�ƁA
 * �f�o�C�X�ɃA�N�Z�X���邽�߂�I/O�C���^�[�t�F�C�X�i ::CriFsIoInterface �j��I�����܂��B<br>
 * �f�t�H���g��Ԃł́A�f�o�C�XID��I/O�C���^�[�t�F�C�X�̑I���̓��C�u�������ňÖٓI�ɍs�Ȃ��܂����A
 * �{�֐����g�p���邱�ƂŁA�f�o�C�XID��I/O�C���^�[�t�F�C�X�����[�U�[�����R�Ɏw�肷�邱�Ƃ��\�ɂȂ�܂��B<br>
 * ����ɂ��A���[�U�[���Ǝ��ɍ쐬����I/O�C���^�[�t�F�C�X���g�p���ăt�@�C���ɃA�N�Z�X���邱�Ƃ��\�ɂȂ�܂��B<br>
 * \code
 * // �Ǝ���I/O�C���^�[�t�F�C�X���`
 * // ���l�j�\���̂̃����o�[�֐��̓��[�U�[���Ǝ��Ɏ����B
 * static CriFsIoInterface g_userIoInterface = {
 * 	userExists,
 * 	userRemove,
 * 	userRename,
 * 	userOpen,
 * 	userClose,
 * 	userGetFileSize,
 * 	userRead,
 * 	userIsReadComplete,
 * 	userGetReadSize,
 * 	userWrite,
 * 	userIsWriteComplete,
 * 	userGetWriteSize,
 * 	userFlush,
 * 	userResize,
 * 	userGetNativeFileHandle
 * };
 *
 * // I/O�I���R�[���o�b�N�֐�
 * CriError user_select_io_callback(
 * 	const CriChar8 *path, CriFsDeviceId *device_id, CriFsIoInterfacePtr *ioif)
 * {
 * 	// �p�X����͂��A�f�o�C�X��ID����肷��
 * 	if (strncmp(path, �c) == 0) {
 * 		(*device_id) = CRIFS_DEVICE_�`;
 * 	} else {
 * 		(*device_id) = CRIFS_DEFAULT_DEVICE;
 * 	}
 *
 * 	// �t�@�C���A�N�Z�X�Ɏg�p����I/O�C���^�[�t�F�C�X���w�肷��
 * 	(*ioif) = g_userIoInterface;
 *
 * 	return (CRIERR_OK);
 * }
 *
 * int main(�c)
 * {
 * 		�F
 * 	// I/O�I���R�[���o�b�N��o�^
 * 	criFs_SetSelectIoCallback(user_select_io_callback);
 * 		�F
 * }
 * \endcode
 * \attention
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \sa CriFsSelectIoCbFunc, criFs_GetDefaultIoInterface
 */
CriError CRIAPI criFs_SetSelectIoCallback(CriFsSelectIoCbFunc func);


#ifdef __cplusplus
}
#endif

/***************************************************************************
 *      ���o�[�W�����Ƃ̌݊��p
 *      For compatibility with old version
 ***************************************************************************/
#define CRI_FS_VERSION		(0xFFFFFFFF)

#endif	/* CRI_FILE_SYSTEM_H_INCLUDED */

/* --- end of file --- */
