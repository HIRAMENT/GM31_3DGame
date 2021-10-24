/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2015 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for PC
 * File     : cri_atom_pc.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_atom_pc.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_ATOM_PC_H
#define	CRI_INCL_CRI_ATOM_PC_H

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include <Windows.h>
#include <cri_le_xpt.h>
#include <cri_le_error.h>
#include "cri_le_atom.h"
#include "cri_le_atom_ex.h"
#include "cri_le_atom_asr.h"

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
 * \ingroup ATOMLIB_PC
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtom_Initialize_PC �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomConfig_PC �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \attention
 * �{�}�N���͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�}�N���̑���� 
 * ::criAtomEx_SetDefaultConfig_PC �}�N���������p���������B
 * \sa CriAtomConfig_PC
 */
#define criAtom_SetDefaultConfig_PC(p_config)				\
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
 * \ingroup ATOMLIB_PC
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomEx_Initialize_PC �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExConfig_PC �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa CriAtomExConfig_PC
 */
#define criAtomEx_SetDefaultConfig_PC(p_config)				\
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
 * \ingroup ATOMLIB_PC
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtom_Initialize_PC �֐��̈����Ɏw�肵�܂��B<br>
 * \attention
 * �{�\���͉̂��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�\���̂̑���� 
 * ::CriAtomExConfig_PC �\���̂������p���������B
 * \sa criAtom_Initialize_PC, criAtom_SetDefaultConfig_PC
 */
typedef struct CriAtomConfigTag_PC{
	CriAtomConfig			atom;		/*JP< Atom�������p�R���t�B�O�\����		*/
	CriAtomAsrConfig		asr;		/*JP< ASR�������p�R���t�B�O			*/
	CriAtomHcaMxConfig		hca_mx;		/*JP< HCA-MX�������p�R���t�B�O�\����	*/
} CriAtomConfig_PC;

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief Atom���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMLIB_PC
 * CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomEx_Initialize_PC �֐��̈����Ɏw�肵�܂��B<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetDefaultConfig_PC
 */
typedef struct CriAtomExConfigTag_PC{
	CriAtomExConfig			atom_ex;	/*JP< AtomEx�������p�R���t�B�O�\����	*/
	CriAtomExAsrConfig		asr;		/*JP< ASR�������p�R���t�B�O			*/
	CriAtomExHcaMxConfig	hca_mx;		/*JP< HCA-MX�������p�R���t�B�O�\����	*/
} CriAtomExConfig_PC;

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
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomConfig_PC �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_CalculateWorkSize_PC �֐��������p���������B
 * \sa CriAtomConfig_PC, criAtom_Initialize_PC
 */
CriSint32 CRIAPI criAtom_CalculateWorkSize_PC(const CriAtomConfig_PC *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtom_Finalize_PC �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�������p�R���t�B�O�\���̂̓��e�ɉ�����
 * �ω����܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�ɂ́A ::criAtom_CalculateWorkSize_PC 
 * �֐����g�p���Ă��������B<br>
 * \par ���l:
 * ::criAtom_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
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
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtom_Finalize_PC �֐������s���Ă��������B<br>
 * �܂��A ::criAtom_Finalize_PC �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_Initialize_PC �֐��������p���������B
 * \sa CriAtomConfig_PC, criAtom_Finalize_PC,
 * criAtom_SetUserAllocator, criAtom_CalculateWorkSize_PC
 */
void CRIAPI criAtom_Initialize_PC(
	const CriAtomConfig_PC *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMLIB_PC
 * \par ����:
 * ���C�u�������I�����܂��B<br>
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtom_Finalize
 * 	- ::criAtomAsr_Finalize
 * 	- ::criAtomHcaMx_Finalize
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * ::criAtom_Initialize_PC �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * <br>
 * �{�֐��͉��ʃ��C��������API�ł��B<br>
 * AtomEx���C���̋@�\�𗘗p����ۂɂ́A�{�֐��̑���� 
 * ::criAtomEx_Finalize_PC �֐��������p���������B
 * \sa criAtom_Initialize_PC
 */
void CRIAPI criAtom_Finalize_PC(void);

/*JP
 * \brief �T�[�o�[�����X���b�h�̃v���C�I���e�B�ύX
 * \ingroup ATOMLIB_PC
 * \param[in]	prio	�X���b�h�v���C�I���e�B
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃v���C�I���e�B��ύX���܂��B<br>
 * �f�t�H���g��ԁi�{�֐������s���Ȃ��ꍇ�j�ł́A�T�[�o�[�����X���b�h�̃v���C�I���e�B��
 * THREAD_PRIORITY_HIGHEST �ɐݒ肳��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��͉����������s���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s���Ă��A���ʂ͂���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �T�[�o�[�����X���b�h�́ACRI File System���C�u�����ł����p����Ă��܂��B<br>
 * ���ł�CRI File System���C�u������API�ŃT�[�o�[�����X���b�h�̐ݒ��ύX���Ă���ꍇ
 * �{�֐��ɂ��ݒ肪�㏑������܂��̂ł����ӂ��������B<br>
 * \sa criAtom_Initialize_PC, criAtom_GetThreadPriority_PC
 */
void CRIAPI criAtom_SetThreadPriority_PC(int prio);

/*JP
 * \brief �T�[�o�[�����X���b�h�̃v���C�I���e�B�擾
 * \ingroup ATOMLIB_PC
 * \return	int		�X���b�h�v���C�I���e�B
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃v���C�I���e�B���擾���܂��B<br>
 * �擾�ɐ�������ƁA�{�֐��̓T�[�o�[�������s���X���b�h�̃v���C�I���e�B��Ԃ��܂��B<br>
 * �擾�Ɏ��s�����ꍇ�A�{�֐��� THREAD_PRIORITY_ERROR_RETURN ��Ԃ��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s�����ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * \sa criAtom_Initialize_PC, criAtom_SetThreadPriority_PC
 */
int CRIAPI criAtom_GetThreadPriority_PC(void);

/*JP
 * \brief �T�[�o�[�����X���b�h�̃A�t�B�j�e�B�}�X�N�ύX
 * \ingroup ATOMLIB_PC
 * \param[in]	mask	�X���b�h�A�t�B�j�e�B�}�X�N
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃A�t�B�j�e�B�}�X�N��ύX���܂��B<br>
 * �f�t�H���g��ԁi�{�֐������s���Ȃ��ꍇ�j�ł́A�T�[�o�[���������삷��v���Z�b�T��
 * ��ؐ�������܂���B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��͉����������s���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s���Ă��A���ʂ͂���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �T�[�o�[�����X���b�h�́ACRI File System���C�u�����ł����p����Ă��܂��B<br>
 * ���ł�CRI File System���C�u������API�ŃT�[�o�[�����X���b�h�̐ݒ��ύX���Ă���ꍇ
 * �{�֐��ɂ��ݒ肪�㏑������܂��̂ł����ӂ��������B<br>
 * \sa criAtom_Initialize_PC, criAtom_GetThreadAffinityMask_PC
 */
void CRIAPI criAtom_SetThreadAffinityMask_PC(DWORD_PTR mask);

/*JP
 * \brief �T�[�o�[�����X���b�h�̃A�t�B�j�e�B�}�X�N�̎擾
 * \ingroup ATOMLIB_PC
 * \return	DWORD_PTR	�X���b�h�A�t�B�j�e�B�}�X�N
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃A�t�B�j�e�B�}�X�N���擾���܂��B<br>
 * �擾�ɐ�������ƁA�{�֐��̓T�[�o�[�������s���X���b�h�̃A�t�B�j�e�B�}�X�N��Ԃ��܂��B<br>
 * �擾�Ɏ��s�����ꍇ�A�{�֐��� 0 ��Ԃ��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s�����ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * \sa criAtom_Initialize_PC, criAtom_SetThreadAffinityMask_PC
 */
DWORD_PTR CRIAPI criAtom_GetThreadAffinityMask_PC(void);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���C�u�����������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u�������g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomExConfig_PC �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * ::CriAtomExConfig �\���̂�acf_info�����o�ɒl��ݒ肵�Ă���ꍇ�A�{�֐��͎��s��-1��Ԃ��܂��B<br>
 * ��������������ACF�f�[�^�̓o�^���s���ꍇ�́A�{�֐��l���g�p�����������m�ۂł͂Ȃ�ADX2�V�X�e���ɂ��
 * �������A���P�[�^�[���g�p�����������m�ۏ������K�v�ɂȂ�܂��B
 * \sa CriAtomExConfig_PC, criAtomEx_Initialize_PC
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_PC(const CriAtomExConfig_PC *config);

/*JP
 * \brief ���C�u�����̏�����
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���C�u���������������܂��B<br>
 * ���C�u�����̋@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���C�u�����̋@�\�́A�{�֐������s��A ::criAtomEx_Finalize_PC �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * <br>
 * ���C�u����������������ۂɂ́A���C�u�����������ŗ��p���邽�߂̃������̈�i���[�N�̈�j
 * ���m�ۂ���K�v������܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�������p�R���t�B�O�\���̂̓��e�ɉ�����
 * �ω����܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�ɂ́A ::criAtomEx_CalculateWorkSize_PC 
 * �֐����g�p���Ă��������B<br>
 * \par ���l:
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * �{�֐��Ƀ��[�N�̈���w�肷��K�v�͂���܂���B<br>
 * �i work �� NULL �A work_size �� 0 ���w�肷�邱�ƂŁA�o�^�ς݂̃A���P�[�^�[
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
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomEx_Finalize_PC �֐������s���Ă��������B<br>
 * �܂��A ::criAtomEx_Finalize_PC �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa CriAtomExConfig_PC, criAtomEx_Finalize_PC,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_PC
 */
void CRIAPI criAtomEx_Initialize_PC(
	const CriAtomExConfig_PC *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���C�u�����̏I��
 * \ingroup ATOMLIB_PC
 * \par ����:
 * ���C�u�������I�����܂��B<br>
 * \attention
 * �{�֐��͓����I�Ɉȉ��̊֐������s���܂��B<br>
 * 	- ::criAtomEx_Finalize
 * 	- ::criAtomExAsr_Finalize
 * 	- ::criAtomExHcaMx_Finalize
 * �{�֐������s����ꍇ�A��L�֐������s���Ȃ��ł��������B<br>
 * <br>
 * ::criAtomEx_Initialize_PC �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomEx_Initialize_PC
 */
void CRIAPI criAtomEx_Finalize_PC(void);

/*JP
 * \brief �T�[�o�[�����X���b�h�̃v���C�I���e�B�ύX
 * \ingroup ATOMLIB_PC
 * \param[in]	prio	�X���b�h�v���C�I���e�B
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃v���C�I���e�B��ύX���܂��B<br>
 * �f�t�H���g��ԁi�{�֐������s���Ȃ��ꍇ�j�ł́A�T�[�o�[�����X���b�h�̃v���C�I���e�B��
 * THREAD_PRIORITY_HIGHEST �ɐݒ肳��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��͉����������s���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s���Ă��A���ʂ͂���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �T�[�o�[�����X���b�h�́ACRI File System���C�u�����ł����p����Ă��܂��B<br>
 * ���ł�CRI File System���C�u������API�ŃT�[�o�[�����X���b�h�̐ݒ��ύX���Ă���ꍇ
 * �{�֐��ɂ��ݒ肪�㏑������܂��̂ł����ӂ��������B<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadPriority_PC
 */
#define criAtomEx_SetThreadPriority_PC(prio)	\
	criAtom_SetThreadPriority_PC(prio)

/*JP
 * \brief �T�[�o�[�����X���b�h�̃v���C�I���e�B�擾
 * \ingroup ATOMLIB_PC
 * \return	int		�X���b�h�v���C�I���e�B
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃v���C�I���e�B���擾���܂��B<br>
 * �擾�ɐ�������ƁA�{�֐��̓T�[�o�[�������s���X���b�h�̃v���C�I���e�B��Ԃ��܂��B<br>
 * �擾�Ɏ��s�����ꍇ�A�{�֐��� THREAD_PRIORITY_ERROR_RETURN ��Ԃ��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s�����ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadPriority_PC
 */
#define criAtomEx_GetThreadPriority_PC()	\
	criAtom_GetThreadPriority_PC()

/*JP
 * \brief �T�[�o�[�����X���b�h�̃A�t�B�j�e�B�}�X�N�ύX
 * \ingroup ATOMLIB_PC
 * \param[in]	mask	�X���b�h�A�t�B�j�e�B�}�X�N
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃A�t�B�j�e�B�}�X�N��ύX���܂��B<br>
 * �f�t�H���g��ԁi�{�֐������s���Ȃ��ꍇ�j�ł́A�T�[�o�[���������삷��v���Z�b�T��
 * ��ؐ�������܂���B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��͉����������s���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s���Ă��A���ʂ͂���܂���B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �T�[�o�[�����X���b�h�́ACRI File System���C�u�����ł����p����Ă��܂��B<br>
 * ���ł�CRI File System���C�u������API�ŃT�[�o�[�����X���b�h�̐ݒ��ύX���Ă���ꍇ
 * �{�֐��ɂ��ݒ肪�㏑������܂��̂ł����ӂ��������B<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadAffinityMask_PC
 */
#define criAtomEx_SetThreadAffinityMask_PC(mask)	\
	criAtom_SetThreadAffinityMask_PC(mask)

/*JP
 * \brief �T�[�o�[�����X���b�h�̃A�t�B�j�e�B�}�X�N�̎擾
 * \ingroup ATOMLIB_PC
 * \return	DWORD_PTR	�X���b�h�A�t�B�j�e�B�}�X�N
 * \par ����:
 * �T�[�o�[�����i���C�u�����̓��������j���s���X���b�h�̃A�t�B�j�e�B�}�X�N���擾���܂��B<br>
 * �擾�ɐ�������ƁA�{�֐��̓T�[�o�[�������s���X���b�h�̃A�t�B�j�e�B�}�X�N��Ԃ��܂��B<br>
 * �擾�Ɏ��s�����ꍇ�A�{�֐��� 0 ��Ԃ��܂��B<br>
 * \attention:
 * �{�֐��́A���C�u�������������ɃX���b�h���f�����}���`�X���b�h���f��
 * �i ::CRIATOM_THREAD_MODEL_MULTI �j�ɐݒ肵���ꍇ�ɂ̂݌��ʂ𔭊����܂��B<br>
 * ���̃X���b�h���f����I�������ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * <br>
 * �{�֐��͏�������`�I�������O�̊ԂɎ��s����K�v������܂��B<br>
 * �������O��I��������ɖ{�֐������s�����ꍇ�A�{�֐��̓G���[�l��Ԃ��܂��B<br>
 * �i�G���[�R�[���o�b�N���������܂��B�j<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadAffinityMask_PC
 */
#define criAtomEx_GetThreadAffinityMask_PC()	\
	criAtom_GetThreadAffinityMask_PC()

/*==========================================================================
 *      Functions for PCM Output
 *=========================================================================*/
/*JP
 * \brief ���[�UPCM�o�͕����p���[�N�̈�T�C�Y�v�Z
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���[�UPCM�o�͕����Ń��C�u���������������邽�߂ɕK�v�ȁA
 * ���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomExConfig_PC �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��� ::criAtomEx_InitializeForUserPcmOutput_PC 
 * �֐����g�p���ă��C�u����������������ꍇ�Ɏg�p���܂��B<br>
 * ::criAtomEx_Initialize_PC �֐����g�p����ꍇ�ɂ́A�{�֐��ł͂Ȃ�
 * ::criAtomEx_CalculateWorkSize_PC �֐����g�p���ă��[�N�̈�T�C�Y���v�Z���Ă��������B<br>
 * \sa CriAtomExConfig_PC, criAtomEx_InitializeForUserPcmOutput_PC
 */
#define criAtomEx_CalculateWorkSizeForUserPcmOutput_PC(config)	\
	criAtomEx_CalculateWorkSizeForUserPcmOutput(config)

/*JP
 * \brief ���[�UPCM�o�͗p���C�u����������
 * \ingroup ATOMLIB_PC
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���[�UPCM�o�̓��[�h�Ń��C�u���������������܂��B<br>
 * <br>
 * �{�֐����g�p���ď������������s�����ꍇ�AAtom���C�u�����͉����o�͂��s���܂���B<br>
 * ���[�U�� ::criAtomExAsr_GetPcmDataFloat32 
 * �֐����g�p���ă��C�u�����������I��PCM�f�[�^���擾���A
 * �A�v���P�[�V�������ŉ����o�͂��s���K�v������܂��B<br>
 * \attention
 * �{�֐��ƈȉ��̊֐��͕��p�ł��܂���B<br>
 * 	- ::criAtom_Initialize
 * 	- ::criAtomAsr_Initialize
 * 	- ::criAtomHcaMx_Initialize
 * 	- ::criAtom_Initialize_PC
 * \sa CriAtomExConfig_PC, criAtomEx_FinalizeForUserPcmOutput_PC,
 * criAtomExAsr_GetPcmDataFloat32, criAtomEx_CalculateWorkSizeForUserPcmOutput_PC
 */
#define criAtomEx_InitializeForUserPcmOutput_PC(config, work, work_size)	\
	criAtomEx_InitializeForUserPcmOutput(config, work, work_size)

/*JP
 * \brief ���[�UPCM�o�͗p���C�u�����I������
 * \ingroup ATOMLIB_PC
 * \par ����:
 * ���[�UPCM�o�̓��[�h�ŏ��������ꂽ���C�u�����ɑ΂��A�I���������s���܂��B<br>
 * \attention
 * �{�֐��� ::criAtomEx_InitializeForUserPcmOutput_PC 
 * �֐����g�p���ă��C�u�����������������ꍇ�Ɏg�p���܂��B<br>
 * ::criAtomEx_Initialize_PC �֐����g�p�����ꍇ�ɂ́A�{�֐��ł͂Ȃ�
 * ::criAtomEx_Finalize_PC �֐����g�p���ďI���������s���Ă��������B<br>
 * \sa criAtomEx_InitializeForUserPcmOutput_PC
 */
#define criAtomEx_FinalizeForUserPcmOutput_PC()	\
	criAtomEx_FinalizeForUserPcmOutput()

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_ATOM_PC_H */

/* --- end of file --- */
