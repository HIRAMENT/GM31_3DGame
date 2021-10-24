/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2017 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header
 * File     : cri_atom_asr.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_atom_asr.h
 */

/* ���d��`�h�~					*/
/* Prevention of redefinition	*/
#ifndef	CRI_ATOM_ASR_H_INCLUDED
#define	CRI_ATOM_ASR_H_INCLUDED

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/
#include "cri_le_xpt.h"
#include "cri_le_atom.h"
#include "cri_le_atom_ex.h"

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/
/*JP
 * \brief �ő�`�����l����
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR�������\�ȍő�`�����l�����ł��B
 */
#define CRIATOMEXASR_MAX_CHANNELS		(8)

/*JP
 * \brief �f�t�t�H���g�̃o�X��
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * �f�t�H���g�̃o�X���ł��B
 */
#define CRIATOMEXASR_DEFAULT_NUM_BUSES	(8)

/*JP
 * \brief �ő�`�����l����
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR�������\�ȍő�o�X���ł��B
 */
#define CRIATOMEXASR_MAX_BUSES			(64)

/*JP
 * \brief �f�t�H���gASR���b�NID
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ���������Ɏ����I�ɍ쐬�����ASR���b�NID�ł��B <br>
 * \sa criAtomExAsrRack_Create, criAtomExAsrRack_Destroy
 */
#define CRIATOMEXASR_RACK_DEFAULT_ID	(0)

/*JP
 * \brief �s���ȃ��b�NID
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ::criAtomExAsrRack_Create �֐��Ɏ��s�����ۂɕԂ�l�ł��B <br>
 * \sa criAtomExAsrRack_Create, criAtomExAsrRack_Destroy
 */
#define CRIATOMEXASR_RACK_ILLEGAL_ID	(-1)

/*JP
 * \brief ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̍ő�o�^��
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * �o�^�\�ȃ��[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̍ő吔�ł��B<br>
 * \sa  criAtomExAsr_RegisterEffectInterface, criAtomExAsr_UnregisterEffectInterface
 */
#define CRIATOMEXASR_MAX_NUM_USER_EFFECT_INTERFACES	(256)

/*==========================================================================
 *      CRI ASR�o�X�G�t�F�N�g��
 *=========================================================================*/
/*JP
 * \brief �U����͊�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_AMPLITUDE_ANALYZER_NAME		"CRIWARE/AmplitudeAnalyzer"

/*JP
 * \brief �o�X�E�o�b�t�@�[�v�[���̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_BUS_BUFFER_POOL                "CRIWARE/BusBufferPool"

/*JP
 * \brief �o�C�N�A�b�h�t�B���^�[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_BIQUAD_FILTER_NAME				"CRIWARE/Biquad"

/*JP
 * \brief �o���h�p�X�t�B���^�[�i2���̃o�^�[���[�X�t�B���^�[�j�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_BANDPASS_FILTER_NAME			"CRIWARE/Bandpass"

/*JP
 * \brief �R�[���X�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_CHORUS_NAME					"CRIWARE/Chorus"

/*JP
 * \brief �t�����W���[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_FLANGER_NAME					"CRIWARE/Flanger"

/*JP
 * \brief �R���v���b�T�[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_COMPRESSOR_NAME				"CRIWARE/Compressor"

/*JP
 * \brief ���~�b�^�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_LIMITER_NAME					"CRIWARE/Limiter"

/*JP
 * \brief �f�B���C�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_DELAY_NAME						"CRIWARE/Delay"

/*JP
 * \brief �G�R�[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_ECHO_NAME						"CRIWARE/Echo"

/*JP
 * \brief �}���`�^�b�v�f�B���C�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_MULTITAP_DELAY_NAME			"CRIWARE/MultiTapDelay"

/*JP
 * \brief �f�B�X�g�[�V�����̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_DISTORTION_NAME				"CRIWARE/Distortion"

/*JP
 * \brief I3DL2���o�[�u�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_I3DL2_REVERB_NAME				"CRIWARE/I3DL2Reverb"

/*JP
 * \brief �}�g���N�X�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_MATRIX_NAME					"CRIWARE/Matrix"

/*JP
 * \brief 3�o���h�C�R���C�U�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_3BANDS_EQUALIZER_NAME			"CRIWARE/3BandsEQ"

/*JP
 * \brief 32�o���h�C�R���C�U�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_32BANDS_EQUALIZER_NAME			"CRIWARE/32BandsEQ"

/*JP
 * \brief �s�b�`�V�t�^�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_PITCH_SHIFTER_NAME				"CRIWARE/PitchShifter"

/*JP
 * \brief ���o�[�u�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_REVERB_NAME					"CRIWARE/Reverb"

/*JP
 * \brief �T���E���_�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_SURROUNDER_NAME				"CRIWARE/Surrounder"
 
/*JP
 * \brief �r�b�g�N���b�V���[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_BIT_CRUSHER_NAME				"CRIWARE/BitCrusher"

/*JP
 * \brief �t�F�[�U�[�̃G�t�F�N�g��
 * \ingroup  ATOMEXLIB_ASR
 */
#define CRIATOMEXASR_PHASER_NAME					"CRIWARE/Phaser"

 /*JP
  * \brief IR���o�[�u�̃G�t�F�N�g��
  * \ingroup  ATOMEXLIB_ASR
  */
#define CRIATOMEXASR_IR_REVERB_NAME					"CRIWARE/IRReverb"

/*==========================================================================
 *      CRI ASR�o�X�G�t�F�N�g �p�����[�^�[��`�}�N��
 *=========================================================================*/
/*JP
 * \defgroup CRIATOMASR_DSP_PARAM ASR�o�X�G�t�F�N�g�̃p�����[�^�[
 * \ingroup  ATOMEXLIB_ASR
 * \par ����:
 * ASR�o�X�Ŏg�p����CRIWARE�Г����G�t�F�N�g�̃p�����[�^�[�Ɋւ����`�ł��B<br>
 * ::criAtomExAsrRack_SetEffectParameter �֐��� ::criAtomExAsrRack_SetEffectParameter 
 * �֐��Ŏw�肷��C���f�b�N�X�̒�`�ƁA����̃p�����[�^�[�̐ݒ�l�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_AMPLITUDE_ANALYZER �U����͊�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �U����͊�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �������ݐ�̃T�C�h�`�F�C���e�[�u��ID
 * \ingroup CRIATOMASR_DSP_PARAM_AMPLITUDE_ANALYZER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɐU����͊킪�������ސ�̃e�[�u��ID���w�肵�܂��B<br>
 * �e�[�u��ID�𓯈�ɂ����G�t�F�N�g���m�ł́A��͌��ʂ����L���鎖���ł��܂��B
 */
#define CRIATOMEXASR_AMPLITUDE_ANALYZER_PARAMETER_SIDE_CHAIN_TABLE_ID	(0)

/*JP
 * \brief �U����͊�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_AMPLITUDE_ANALYZER 
 * \par ����:
 * �U����͊�̃p�����[�^�[���ł��B
 */
#define CRIATOMEXASR_AMPLITUDE_ANALYZER_NUM_PARAMETERS					(1)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER �o�C�N�A�b�h�t�B���^�[�E�o���h�p�X�t�B���^�[�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �o�C�N�A�b�h�t�B���^�[�E�o���h�p�X�t�B���^�[�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �^�C�v
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo�C�N�A�b�h�t�B���^�[�̃^�C�v���w�肵�܂��B<br>
 * \sa CRIATOMEXASR_BIQUAD_FILTER_TYPE_LOWPASS, CRIATOMEXASR_BIQUAD_FILTER_TYPE_HIGHPASS, CRIATOMEXASR_BIQUAD_FILTER_TYPE_NOTCH, CRIATOMEXASR_BIQUAD_FILTER_TYPE_LOWSHELF, CRIATOMEXASR_BIQUAD_FILTER_TYPE_HIGHSHELF, CRIATOMEXASR_BIQUAD_FILTER_TYPE_PEAKING
 */
#define CRIATOMEXASR_BIQUAD_FILTER_PARAMETER_TYPE						(0)

/*JP
 * \brief �������g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo�C�N�A�b�h�t�B���^�[�̏������g�����w�肵�܂��B<br>
 * �������g���̓^�C�v�Ɉˑ����ĕω����܂��B
 * | �^�C�v  | ���g��  |
 * | :-----: | :-: |
 * | ���[�p�X�t�B���^�[�A�n�C�p�X�t�B���^�[ | �Ւf���g�� |
 * | �m�b�`�t�B���^�[�A�s�[�L���O�t�B���^�[�A���[�V�F���t�t�B���^�[�A�n�C�V�F���t�t�B���^�[ | ���S���g�� |
 */
#define CRIATOMEXASR_BIQUAD_FILTER_PARAMETER_FREQUENCY					(1)

/*JP
 * \brief Q�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo�C�N�A�b�h�t�B���^�[��Q�l�i��s�x�A�N�I���e�B�t�@�N�^�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��10.0f�ł��B�o���h�p�X�t�B���^�[�ȊO�ł͐M�������̍ۂɍŏ��l��0.001f�ɐ�������܂��B
 */
#define CRIATOMEXASR_BIQUAD_FILTER_PARAMETER_QUALITY_FACTOR				(2)

/*JP
 * \brief �o�̓Q�C��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo�C�N�A�b�h�t�B���^�[�̏o�̓Q�C�����w�肵�܂��B<br>
 * �o�̓Q�C�����K�p�����̂̓��[�V�F���t�t�B���^�[�A�n�C�V�F���t�t�B���^�[�A�s�[�L���O�t�B���^�[�݂̂ƂȂ�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��5.0f�ł��B���[�V�F���t�A�n�C�V�F���t�A�s�[�L���O�t�B���^�[�̏ꍇ�͐M�������̍ۂɍŏ��l�� ��1/65536.0f�ɐ�������܂��B
 */
#define CRIATOMEXASR_BIQUAD_FILTER_PARAMETER_GAIN						(3)

/*JP
 * \brief �o�C�N�A�b�h�t�B���^�[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �o�C�N�A�b�h�t�B���^�[�̃p�����[�^�[���ł��B
 */
#define CRIATOMEXASR_BIQUAD_FILTER_NUM_PARAMETERS						(4)

/*JP
 * \brief ���[�p�X�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_LOWPASS							(0)

/*JP
 * \brief �n�C�p�X�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_HIGHPASS						(1)

/*JP
 * \brief �m�b�`�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_NOTCH							(2)

/*JP
 * \brief ���[�V�F���t�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_LOWSHELF						(3)

/*JP
 * \brief �n�C�V�F���t�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_HIGHSHELF						(4)

/*JP
 * \brief �s�[�L���O�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 */
#define CRIATOMEXASR_BIQUAD_FILTER_TYPE_PEAKING							(5)

/*JP
 * \brief ���Ւf�i�J�b�g�I�t�j���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo���h�p�X�t�B���^�[�i2���̃o�^�[���[�X�t�B���^�[�j�̒��Ւf���g�����w�肵�܂��B<br>
 * �p�����[�^�[�̍ŏ��l��24.0f�A�ő�l��24000.0f�ł��B
 */
#define CRIATOMEXASR_BANDPASS_FILTER_PARAMETER_LOW_FREQ					(0)

/*JP
 * \brief ����Ւf�i�J�b�g�I�t�j���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀo���h�p�X�t�B���^�[�i2���̃o�^�[���[�X�t�B���^�[�j�̍���Ւf���g�����w�肵�܂��B<br>
 * �p�����[�^�[�̍ŏ��l��24.0f�A�ő�l��24000.0f�ł��B
 */
#define CRIATOMEXASR_BANDPASS_FILTER_PARAMETER_HIGH_FREQ				(1)

/*JP
 * \brief �o���h�p�X�t�B���^�[�i2���̃o�^�[���[�X�t�B���^�[�j�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_BIQUAD_FILTER 
 * \par ����:
 * �o���h�p�X�t�B���^�[�̃p�����[�^�[���ł��B
 */
#define CRIATOMEXASR_BANDPASS_FILTER_NUM_PARAMETERS						(2)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_CHORUS �R�[���X�E�t�����W���[�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �R�[���X�E�t�����W���[�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X�̒x���iLFO�̒��S�ƂȂ�x���j���Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��30.0f�A�ŏ��l��0.1f�A�ő�l��100.f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_DELAY_TIME_MS						(0)

/*JP
 * \brief �[���iLFO�U���j
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X�̐[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.2f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_DEPTH								(1)

/*JP
 * \brief ���[�g�i�X�s�[�h�ALFO���g���j[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X��LFO�̃��[�g���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.01f�A�ő�l��100.0f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_RATE								(2)

/*JP
 * \brief �t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X�̃t�B�[�h�o�b�N�Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_FEEDBACK							(3)

/*JP
 * \brief dry�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X��dry�i�����j�����̃~�b�N�X�������w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.7f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_DRY_MIX							(4)

/*JP
 * \brief �R�[���X�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 */
#define CRIATOMEXASR_CHORUS_NUM_PARAMETERS								(8)

/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[�̒x���iLFO�̒��S�ƂȂ�x���j���Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��10.0f�A�ŏ��l��0.1f�A�ő�l��10.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_DELAY_TIME_MS					(0)

/*JP
 * \brief �[���iLFO�U���j
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[�̐[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.1f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_DEPTH							(1)

/*JP
 * \brief ���[�g�i�X�s�[�h�ALFO���g���j[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[��LFO�̃��[�g���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.01f�A�ő�l��100.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_RATE								(2)

/*JP
 * \brief �t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[�̃t�B�[�h�o�b�N�Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_FEEDBACK							(3)

/*JP
 * \brief dry�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[��dry�i�����j�����̃~�b�N�X�������w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_DRY_MIX							(4)

/*JP
 * \brief wet�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�����W���[��wet�i�����j�����̃~�b�N�X�������w�肵�܂��B
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_FLANGER_PARAMETER_WET_MIX							(5)

/*JP
 * \brief �t�����W���[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 */
#define CRIATOMEXASR_FLANGER_NUM_PARAMETERS								(6)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_COMPRESSOR �R���v���b�T�[�E���~�b�^�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �R���v���b�T�[�E���~�b�^�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �X���b�V�����h
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃X���b�V�����h�i�U�������k����n�߂�臒l�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B<br>
 * \note ���V�I�l����dB�l�ւ̕ϊ��̓��V�I�l�ɏ�p�ΐ��i�ꂪ10�̑ΐ��j��������l��20.0f���悶�邱�ƂŎ擾�ł��܂��B
 * \code
 * // db�l db ���烌�V�I�l ratio �֕ϊ�
 * ratio = powf(10.0f, db / 20.0f);
 * // ���V�I�l ratio ����Z���g�l cent �֕ϊ�
 * db = 20.0f * log10f(ratio);
 * \endcode
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_THRESHOLD						(0)

/*JP
 * \brief ���V�I
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃��V�I�i���k�l�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l�A�ő�l�ɐ����͂���܂��񂪁A�M�������̍ۂɍŏ��l��0.01f�ɐ�������܂��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_RATIO							(1)

/*JP
 * \brief �A�^�b�N����[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃A�^�b�N���ԁi�w�肵�����V�I�Ɉ��k�����܂ł̎��ԁj���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��3000.0f�ł��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_ATTACK_TIME_MS				(2)

/*JP
 * \brief �����[�X����[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃����[�X���ԁi�U����臒l�ȉ��ɂȂ�����Ɉ��k���I���܂ł̎��ԁj���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��50000.0f�ł��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_RELEASE_TIME_MS				(3)

/*JP
 * \brief �ő�o�̓Q�C��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̍ő�o�̓Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l�� 10��(-24/5)��i-96dB�ɑ����j�A�ő�l��10��(12/5)��i48dB�ɑ����j�ł��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_OUTPUT_GAIN					(4)

/*JP
 * \brief �T���E���h�����N�̋���
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃T���E���h�����N�̋������w�肵�܂��B<br>
 * �T���E���h�����N�@�\�Ƃ́A�S�`�����l�����ōŒ�̐U���l��p���Ĉ��k���|���鋭����ω�������@�\�ł��B<br>
 * 1.0f�̎��ɑS�`�����l�����ōŒ�̐U���l�����S�Ɏg�p���A0.0f�ŃT���E���h�����N�@�\��OFF�ɂȂ�܂��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_SURROUND_LINK					(5)

/*JP
 * \brief �X�v���b�gEQ�̃^�C�v
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃X�v���b�gEQ�̃^�C�v���w�肵�܂��B<br>
 * �X�v���b�gEQ�Ƃ͑ш��񕪊�����EQ�ł��B�t�B���^�[�ɂ���Ď��o�����ш�݂̂ɃR���v���b�T�[���|���A�c�����ш�ƍ������܂��B
 * \sa CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_NONE, CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_LOWPASS, CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_HIGHPASS, CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_BANDPASS, CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_NOTCH
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_SPLIT_EQ_TYPE					(6)

/*JP
 * \brief �X�v���b�gEQ�̏������g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃X�v���b�gEQ�̏������g�����w�肵�܂��B<br>
 * �p�����[�^�[�̍ŏ��l��24.0f�A�ő�l��24000.0f�ł��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_SPLIT_EQ_FREQUENCY			(7)

/*JP
 * \brief �X�v���b�gEQ��Q�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR���v���b�T�[�̃X�v���b�gEQ��Q�l�i��s�x�A�N�I���e�B�t�@�N�^�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��10.0f�ł��B
 */
#define CRIATOMEXASR_COMPRESSOR_PARAMETER_SPLIT_EQ_QUALITY_FACTOR		(8)

/*JP
 * \brief �R���v���b�T�[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_NUM_PARAMETERS							(9)

/*JP
 * \brief �X�v���b�gEQ���g�p���Ȃ��ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_NONE						(0)

/*JP
 * \brief �X�v���b�gEQ�Ń��[�p�X�t�B���^�[���g�p����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_LOWPASS					(1)

/*JP
 * \brief �X�v���b�gEQ�Ńn�C�p�X�t�B���^�[���g�p����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_HIGHPASS					(2)

/*JP
 * \brief �X�v���b�gEQ�Ńo���h�p�X�t�B���^�[���g�p����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_BANDPASS					(3)

/*JP
 * \brief �X�v���b�gEQ�Ńm�b�`�t�B���^�[���g�p����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_SPLIT_EQ_TYPE_NOTCH						(4)

/*JP
 * \brief �R���v���b�T�[���������g�̐U���v�����ʂɂ�蓮�삳����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_MODE_NORMAL								(0)

/*JP
 * \brief �R���v���b�T�[���T�C�h�`�F�C�����g�p���ē��삳����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_MODE_SIDE_CHAIN							(1)

/*JP
 * \brief �R���v���b�T�[�̐U�����m�^�C�v���s�[�N�l�ɂ���ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_TYPE_PEAK								(0)

/*JP
 * \brief �R���v���b�T�[�̐U�����m�^�C�v��RMS�ɂ���ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_COMPRESSOR_TYPE_RMS								(1)

/*JP
 * \brief �X���b�V�����h
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̃X���b�V�����h�i�U�������k�����臒l�j���w�肵�܂��B<br>
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_THRESHOLD						(0)

/*JP
 * \brief �A�^�b�N����[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̃A�^�b�N���ԁi���k����������܂ł̎��ԁj���w�肵�܂��B
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��200.0f�ł��B
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_ATTACK_TIME_MS					(1)

/*JP
 * \brief �����[�X����[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̃����[�X���ԁi�U����臒l�ȉ��ɂȂ�����Ɉ��k���I���܂ł̎��ԁj���w�肵�܂��B
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��50000.0f�ł��B
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_RELEASE_TIME_MS					(2)

/*JP
 * \brief �ő�o�̓Q�C��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̍ő�o�̓Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l�� 10��-4.8��i-96dB�ɑ����j�A�ő�l��10��2.4��i48dB�ɑ����j�ł��B
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_OUTPUT_GAIN						(3)

/*JP
 * \brief �T���E���h�����N�̋���
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̃T���E���h�����N�̋������w�肵�܂��B<br>
 * �T���E���h�����N�@�\�Ƃ́A�S�`�����l�����ōŒ�̐U���l��p���Ĉ��k���|���鋭����ω�������@�\�ł��B<br>
 * 1.0f�̎��ɑS�`�����l�����ōŒ�̐U���l�����S�Ɏg�p���A0.0f�ŃT���E���h�����N�@�\��OFF�ɂȂ�܂��B
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_SURROUND_LINK					(4)

/*JP
 * \brief �U�����o�l�^�C�v
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��~�b�^�̐U�����o�l�^�C�v���w�肵�܂��B
 * \sa CRIATOMEXASR_LIMITER_TYPE_PEAK, CRIATOMEXASR_LIMITER_TYPE_RMS
 */
#define CRIATOMEXASR_LIMITER_PARAMETER_TYPE								(5)

/*JP
 * \brief ���~�b�^�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_LIMITER_NUM_PARAMETERS								(6)
																	
/*JP
 * \brief ���~�b�^���������g�̐U���v�����ʂɂ�蓮�삳����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_LIMITER_MODE_NORMAL								(0)

/*JP
 * \brief ���~�b�^���T�C�h�`�F�C���ɂ�蓮�삳����ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_LIMITER_MODE_SIDE_CHAIN							(1)

/*JP
 * \brief ���~�b�^�̐U�����m�^�C�v���s�[�N�l�ɂ���ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_LIMITER_TYPE_PEAK									(0)

/*JP
 * \brief ���~�b�^�̐U�����m�^�C�v��RMS�ɂ���ۂ̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_COMPRESSOR
 */
#define CRIATOMEXASR_LIMITER_TYPE_RMS									(1)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_DELAY �f�B���C�E�G�R�[�E�}���`�^�b�v�f�B���C�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �f�B���C�E�G�R�[�E�}���`�^�b�v�f�B���C�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀf�B���C�̒x�����Ԃ��w�肵�܂��B<br>
 * �ő�f�B���C���Ԃ̔����̒l�ŏ���������܂��B �p�����[�^�[�̍ŏ��l��50.0f�A�ő�l��1000.0f�ł��B
 */
#define CRIATOMEXASR_DELAY_PARAMETER_DELAY_TIME_MS						(0)

/*JP
 * \brief �f�B���C�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_DELAY_NUM_PARAMETERS								(1)

/*JP
 * \brief �f�B���C�Őݒ�\�ȍŏ��̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_DELAY_PARAMETER_MIN_DELAY_TIME_MS					(50.0f)

/*JP
 * \brief �f�B���C�Őݒ�\�ȍő�̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \attention �R���t�B�O�ݒ肵���l�ȏ�ɐݒ肵�Ă��A������̒l���D�悵�Đ�������܂��B
 */
#define CRIATOMEXASR_DELAY_PARAMETER_MAX_DELAY_TIME_MS					(1000.0f)

/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃG�R�[�̒x�����Ԃ��w�肵�܂��B
 */
#define CRIATOMEXASR_ECHO_PARAMETER_DELAY_TIME_MS						(0)

/*JP
 * \brief �t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃG�R�[�̃t�B�[�h�o�b�N�Q�C�����w�肵�܂��B<br>
 * �t�B�[�h�o�b�N�Q�C�����傫�����ɂ��G�R�[���͍Đ����~���Ă��~�܂�Ȃ��_�ɒ��ӂ��ĉ������B�܂��A�t�B�[�h�o�b�N�Q�C���̐�Βl�̍ő�l��1.0f�ł����A�����I�ɂ�0.99f�ɐ؂�l�߂���ׁA�����U�����Ă��܂��i�G�R�[�������Ȃ��j���͂���܂���B
 * \par ����:
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-0.99f�A�ő�l��0.99f�ł��B��L�̐����ɂ��A1.0f��ݒ肵���ꍇ�ł������������܂��B
 */
#define CRIATOMEXASR_ECHO_PARAMETER_FB_GAIN								(1)

/*JP
 * \brief �G�R�[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_ECHO_NUM_PARAMETERS								(2)

/*JP
 * \brief �G�R�[�Őݒ�\�ȍŏ��̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_ECHO_PARAMETER_MIN_DELAY_TIME_MS					(0.0f)

/*JP
 * \brief �G�R�[�Őݒ�\�ȍő�̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \attention �R���t�B�O�Őݒ肵���ő�x�����Ԃ����A������̒l���D�悵�Đ�������܂��B
 */
#define CRIATOMEXASR_ECHO_PARAMETER_MAX_DELAY_TIME_MS					(1000.0f)

/*JP
 * \brief �G�R�[�Őݒ�\�ȍŏ��̃t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_ECHO_PARAMETER_MIN_FB_GAIN							(-0.99f)

/*JP
 * \brief �G�R�[�Őݒ�\�ȍő�̃t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_ECHO_PARAMETER_MAX_FB_GAIN							(0.99f)

/*JP
 * \brief �}���`�^�b�v�f�B���C�̃^�b�v��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_MULTITAP_DELAY_NUM_TAPS							(4)

/*JP
 * \brief �}���`�^�b�v�f�B���C�̏o�̓`�����l����
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \par ����:
 * �ʏ��4�`�����l���iL, R, �T���E���hL, �T���E���hR�j�ɐݒ肳��܂��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_NUM_CHANNELS						(4)

/*JP
 * \brief �}���`�^�b�v�f�B���C�Őݒ�\�ȍő�̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \attention �R���t�B�O�ł��̒l�ȏ�ɐݒ肵�Ă��A������̒l���D�悵�Đ�������܂��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_MAX_DELAY_TIME_MS			(10000.0f)

/*JP
 * \brief �}���`�^�b�v�f�B���C��1�^�b�v������̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP				(4)

/*JP
 * \brief �}���`�^�b�v�f�B���C�̃t�B�[�h�o�b�N�ʑ��a����l
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \par ����:
 * �}���`�^�b�v�f�B���C�ł͊e�^�b�v�Ńt�B�[�h�o�b�N���s���̂ŁA�o�͂����U���Ă��܂��ꍇ������܂��B�S�^�b�v�̃t�B�[�h�o�b�N���a����l��p���āA���U���Ȃ�ׂ�������܂��B
 * \attention ���̏���l��p���Ă��o�͂����U����ꍇ������܂��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_MAX_SUM_FEEDBACK_GAIN		(0.90f)

/*JP
 * \brief �}���`�^�b�v�f�B���C�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 */
#define CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETERS \
	(CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP * CRIATOMEXASR_MULTITAP_DELAY_NUM_TAPS)	

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_DISTORTION �f�B�X�g�[�V�����̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �f�B�X�g�[�V�����Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �c�݂̋���[dB]
 * \ingroup CRIATOMASR_DSP_PARAM_DISTORTION
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀf�B�X�g�[�V�����̘c�݂̋����i�h���C�u�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��48.0f�ł��B
 */
#define CRIATOMEXASR_DISTORTION_PARAMETER_DRIVE_DB						(0)

/*JP
 * \brief dry�����̊���
 * \ingroup CRIATOMASR_DSP_PARAM_DISTORTION
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀf�B�X�g�[�V������dry�i�����j�������~�b�N�X���銄�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_DISTORTION_PARAMETER_DRY_MIX						(1)

/*JP
 * \brief wet�����̊���
 * \ingroup CRIATOMASR_DSP_PARAM_DISTORTION
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀf�B�X�g�[�V������wet�i�c�݁j�������~�b�N�X���銄�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_DISTORTION_PARAMETER_WET_MIX						(2)

/*JP
 * \brief �ŏI�o�̓��x��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_DISTORTION
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀf�B�X�g�[�V�����̍ŏI�o�̓��x�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��10��2.4��i48dB�ɑ�������l�j�ł��B
 */
#define CRIATOMEXASR_DISTORTION_PARAMETER_OUTPUT_GAIN					(3)

/*JP
 * \brief �f�B�X�g�[�V�����̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_DISTORTION
 */
#define CRIATOMEXASR_DISTORTION_NUM_PARAMETERS							(4)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB I3DL2���o�[�u�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief I3DL2���o�[�u�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 * \attention �v���Z�b�g�̓p�����[�^�[�C���f�b�N�X0-10�܂ł̏�񂪕��񂾔z��ł���A
 *			  �C���f�b�N�X11-13�ɂ��Ă͎w��ł��܂���B
 */
/*JP
 * \brief �G�t�F�N�g�S�̂̏o�̓{�����[��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̍ŏI�o�̓{�����[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��-1000.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_ROOM						(0)

/*JP
 * \brief �Q�Ǝ��g���i����j�����̃{�����[��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̎Q�Ǝ��g���i����j�����̃{�����[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��-100.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_ROOM_HF						(1)

/*JP
 * \brief �㕔�c�����̌�������[sec]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����̌������Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.49f�A�ŏ��l��0.1f�A�ő�l��20.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_DECAY_TIME					(2)

/*JP
 * \brief �㕔�c�����̒���g�������ɑ΂��鍂���g�����̔�
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����ɂ�����A����g�����ɑ΂��鍂���g�����̔䗦���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.83f�A�ŏ��l��0.1f�A�ő�l��2.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_DECAY_HF_RATIO				(3)

/*JP
 * \brief �������ˉ��̃{�����[��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̏������ˉ��̃{�����[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��-2602f�A�ŏ��l��-10000.0f�A�ő�l��1000.0�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REFLECTIONS					(4)

/*JP
 * \brief �������ˉ��̒x������[sec]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̏������ˉ��̃{�����[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.007f�A�ŏ��l��0.0f�A�ő�l��0.3f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REFLECTIONS_DELAY			(5)

/*JP
 * \brief �㕔�c�����̃{�����[��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����̃{�����[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��200f�A�ŏ��l��-10000.0f�A�ő�l��2000.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REVERB						(6)

/*JP
 * \brief �㕔�c�����̒x������[sec]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����̒x�����Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.011f�A�ŏ��l��0.0f�A�ő�l��0.1f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REVERB_DELAY				(7)

/*JP
 * \brief �㕔�c�����̃G�R�[���x[%]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����̃G�R�[���x���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��100.0f�A�ŏ��l��0.0f�A�ő�l��100.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_DIFFUSION					(8)

/*JP
 * \brief �㕔�c�����̃��[�_�����x[%]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̌㕔�c�����̃��[�_�����x���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��100.0f�A�ŏ��l��0.0f�A�ő�l��100.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_DENSITY						(9)

/*JP
 * \brief RoomHF�̎Q�Ǝ��g���i����j[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u��RoomHF�̎Q�Ǝ��g���i����j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��5000.0f�A�ŏ��l��20.0f�A�ő�l��20000.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_HF_REFERENCE				(10)

/*JP
 * \brief �t�����g�����̓��̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃t�����g�iL,R�`�����l���j�����̓��̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_FRONT_INPUT					(11)

/*JP
 * \brief ���A�����̓��̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃��A�i�T���E���hL,�T���E���hR�`�����l���j�����̓��̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REAR_INPUT					(12)

/*JP
 * \brief �Z���^�[�����̓��̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃Z���^�[�iC�`�����l���j�����̓��̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��-10000.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_CENTER_INPUT				(13)

/*JP
 * \brief �t�����g�����̏o�̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃t�����g�iL,R�`�����l���j�����̏o�̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_FRONT_OUTPUT				(14)

/*JP
 * \brief ���A�����̏o�̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃��A�i�T���E���hL,�T���E���hR�`�����l���j�����̏o�̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_REAR_OUTPUT					(15)

/*JP
 * \brief �Z���^�[�����̏o�̓��x��[mB]
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��I3DL2���o�[�u�̃Z���^�[�iC�`�����l���j�����̏o�̓��x�����w�肵�܂��B<br>
 * I3DL2���o�[�u�̃v���Z�b�g�ł͎w��ł��Ȃ����ɒ��ӂ��ĉ������B<br>
 * �p�����[�^�[�̏����l��-10000.0f�A�ŏ��l��-10000.0f�A�ő�l��0.0f�ł��B
 */
#define CRIATOMEXASR_I3DL2_REVERB_PARAMETER_CENTER_OUTPUT				(16)

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_NUM_PARAMETERS						(17)

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: GENERIC
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_GENERIC \
	{ -1000,  -100, 1.49f, 0.83f,  -2602, 0.007f,    200, 0.011f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: PADDED CELL
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PADDEDCELL \
	{ -1000, -6000, 0.17f, 0.10f,  -1204, 0.001f,    207, 0.002f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ROOM \
	{ -1000,  -454, 0.40f, 0.83f,  -1646, 0.002f,     53, 0.003f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: BATH ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_BATHROOM \
	{ -1000, -1200, 1.49f, 0.54f,   -370, 0.007f,   1030, 0.011f, 100.0f,  60.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: LIVING ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LIVINGROOM \
	{ -1000, -6000, 0.50f, 0.10f,  -1376, 0.003f,  -1104, 0.004f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: STONE ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_STONEROOM \
	{ -1000,  -300, 2.31f, 0.64f,   -711, 0.012f,     83, 0.017f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: AUDITORIUM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_AUDITORIUM \
	{ -1000,  -476, 4.32f, 0.59f,   -789, 0.020f,   -289, 0.030f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: CONCERT HALL
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CONCERTHALL \
	{ -1000,  -500, 3.92f, 0.70f,  -1230, 0.020f,     -2, 0.029f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: CAVE
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CAVE \
	{ -1000,     0, 2.91f, 1.30f,   -602, 0.015f,   -302, 0.022f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: ARENA
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ARENA \
	{ -1000,  -698, 7.24f, 0.33f,  -1166, 0.020f,     16, 0.030f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: HANGER
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_HANGAR \
	{ -1000, -1000, 10.05f, 0.23f,   -602, 0.020f,    198, 0.030f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: CARPETED HALL WAY
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CARPETEDHALLWAY \
	{ -1000, -4000, 0.30f, 0.10f,  -1831, 0.002f,  -1630, 0.030f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: HALL WAY
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_HALLWAY \
	{ -1000,  -300, 1.49f, 0.59f,  -1219, 0.007f,    441, 0.011f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: STONE CORRIDOR
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_STONECORRIDOR \
	{ -1000,  -237, 2.70f, 0.79f,  -1214, 0.013f,    395, 0.020f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: ALLEY
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_ALLEY \
	{ -1000,  -270, 1.49f, 0.86f,  -1204, 0.007f,     -4, 0.011f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: FOREST
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_FOREST \
	{ -1000, -3300, 1.49f, 0.54f,  -2560, 0.162f,   -613, 0.088f,  79.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: CITY
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_CITY \
	{ -1000,  -800, 1.49f, 0.67f,  -2273, 0.007f,  -2217, 0.011f,  50.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: MOUNTAINS
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MOUNTAINS \
	{ -1000, -2500, 1.49f, 0.21f,  -2780, 0.300f,  -2014, 0.100f,  27.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: QUARRY
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_QUARRY \
	{ -1000, -1000, 1.49f, 0.83f, -10000, 0.061f,    500, 0.025f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: PLAIN
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PLAIN \
	{ -1000, -2000, 1.49f, 0.50f,  -2466, 0.179f,  -2514, 0.100f,  21.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: PARKING LOT
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PARKINGLOT \
	{ -1000,     0, 1.65f, 1.50f,  -1363, 0.008f,  -1153, 0.012f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: SEWER PIPE
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_SEWERPIPE \
	{ -1000, -1000, 2.81f, 0.14f,    429, 0.014f,    648, 0.021f,  80.0f,  60.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: UNDER WATER
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_UNDERWATER \
	{ -1000, -4000, 1.49f, 0.10f,   -449, 0.007f,   1700, 0.011f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: SMALL ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_SMALLROOM \
	{ -1000,  -600, 1.10f, 0.83f,   -400, 0.005f,    500, 0.010f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: MEDIUM ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MEDIUMROOM \
	{ -1000,  -600, 1.30f, 0.83f,  -1000, 0.010f,   -200, 0.020f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: LARGE ROOM
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LARGEROOM \
	{ -1000,  -600, 1.50f, 0.83f,  -1600, 0.020f,  -1000, 0.040f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: MEDIUM HALL
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_MEDIUMHALL \
	{ -1000,  -600, 1.80f, 0.70f,  -1300, 0.015f,   -800, 0.030f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: LARGE HALL
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_LARGEHALL \
	{ -1000,  -600, 1.80f, 0.70f,  -2000, 0.030f,  -1400, 0.060f, 100.0f, 100.0f, 5000.0f}

/*JP
 * \brief I3DL2���o�[�u�̃p�����[�^�[�̃v���Z�b�g: PLATE
 * \ingroup CRIATOMASR_DSP_PARAM_I3DL2_REVERB
 */
#define CRIATOMEXASR_I3DL2_REVERB_PRESET_PLATE \
	{ -1000,  -200, 1.30f, 0.90f,      0, 0.002f,      0, 0.010f, 100.0f,  75.0f, 5000.0f}

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_MATRIX �}�g���N�X�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �}�g���N�X�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */

/*JP
 * \brief ��������ő�̃`�����l����
 * \ingroup CRIATOMASR_DSP_PARAM_MATRIX
 * \par ����:
 * �}�g���N�X�̏����\�ȍő�̓��o�̓`�����l�����ł��B
 */
#define CRIATOMEXASR_MATRIX_MAX_NUM_CHANNELS							(8)

/*JP
 * \brief �}�g���N�X�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_MATRIX
 */
#define CRIATOMEXASR_MATRIX_NUM_PARAMETERS							\
	(CRIATOMEXASR_MATRIX_MAX_NUM_CHANNELS * CRIATOMEXASR_MATRIX_MAX_NUM_CHANNELS)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ 3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief 3�o���h�C�R���C�U�E32�o���h�C�R���C�U�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */

/*JP
 * \brief ���[�V�F���t�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_LOWSHELF 			(0)

/*JP
 * \brief �n�C�V�F���t�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_HIGHSHELF			(1)

/*JP
 * \brief �s�[�L���O�t�B���^�[���w�肷�鎞�̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_PEAKING 			(2)

/*JP
 * \brief 3�o���h�C�R���C�U/32�o���h�C�R���C�U��1�o���h������̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND 				(4)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER �s�b�`�V�t�^�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �s�b�`�V�t�^�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �s�b�`�ύX��[���V�I]
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀs�b�`�V�t�^�̃s�b�`�ύX�ʂ��w�肵�܂��B<br>
 * �s�b�`�V�t�g�l�i�Z���g�l�j�̔䗦�i���V�I�j�ł��B�p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.25f�i-2400�Z���g�ɑ����j�A�ő�l��4.0f�i2400�Z���g�ɑ����j�B<br>
 * \note ���V�I�l����Z���g�l�ւ̕ϊ��̓��V�I�l�ɒꂪ2�̑ΐ���������l�ɁA1200.0f���悶�邱�ƂŎ擾�ł��܂��B
 * \code
 * // �Z���g�l cent ���烌�V�I�l ratio �֕ϊ�
 * ratio = powf(2.0f, cent / 1200.0f);
 * // ���V�I�l ratio ����Z���g�l cent �֕ϊ�
 * cent = 1200.0f * log2f(ratio);
 * \endcode
 */
#define CRIATOMEXASR_PITCH_SHIFTER_PARAMETER_PITCH_RATIO				(0)

/*JP
 * \brief �t�H���}���g�ύX��[���V�I]
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀs�b�`�V�t�^�̃t�H���}���g�ύX�ʂ��w�肵�܂��B<br>
 * �s�b�`�V�t�g�l�i�Z���g�l�j�̔䗦�i���V�I�j�ł��B�p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.25f�i-2400�Z���g�ɑ����j�A�ő�l��4.0f�i2400�Z���g�ɑ����j�B<br>
 * \note ���V�I�l����Z���g�l�ւ̕ϊ��̓��V�I�l�ɒꂪ2�̑ΐ���������l�ɁA1200.0f���悶�邱�ƂŎ擾�ł��܂��B
 * \code
 * // �Z���g�l cent ���烌�V�I�l ratio �֕ϊ�
 * ratio = powf(2.0f, cent / 1200.0f);
 * // ���V�I�l ratio ����Z���g�l cent �֕ϊ�
 * cent = 1200.0f * log2f(ratio);
 * \endcode
 */
#define CRIATOMEXASR_PITCH_SHIFTER_PARAMETER_FORMANT_RATIO				(1)

/*JP
 * \brief ���샂�[�h
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀs�b�`�V�t�^�̓��샂�[�h���w�肵�܂��B<br>
 * ��ʊ����d�����邩�ۂ��A�l�Ԃ̐����܂񂾉����i�s�b�`�̂��鉹���j���ۂ��œK�؂ȓ��샂�[�h���قȂ�܂��B
 * \sa CRIATOMEXASR_PITCH_SHIFTER_MODE_MUSIC, CRIATOMEXASR_PITCH_SHIFTER_MODE_VOCAL, CRIATOMEXASR_PITCH_SHIFTER_MODE_SE, CRIATOMEXASR_PITCH_SHIFTER_MODE_SPEECH
 */
#define CRIATOMEXASR_PITCH_SHIFTER_PARAMETER_MODE						(2)

/*JP
 * \brief ���͉����f�[�^�̃s�b�`���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɓ��͉����f�[�^�̃s�b�`���g�����w�肵�܂��B<br>
 * �t�H���}���g��͂̍ۂ̃q���g���ɂȂ�܂����A���ۂ̉����f�[�^�ɂ������ꂽ�l���w�肷��Ɖ����ɎG�����t������邽�ߒ��ӂ��ĉ������B�w�肵�Ȃ������ꍇ�̓f�t�H���g�̃s�b�`�i459.375Hz�j�������Ŏg�p����܂��B
 */
#define CRIATOMEXASR_PITCH_SHIFTER_PARAMETER_DATA_PITCH_FREQUENCY		(3)

/*JP
 * \brief �s�b�`�V�t�^�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER
 */
#define CRIATOMEXASR_PITCH_SHIFTER_NUM_PARAMETERS						(4)

/*JP
 * \brief �s�b�`�V�t�^�̓��샂�[�h�ŉ��y���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER 
 * \par ����:
 * LR��MS�ϊ��iL,Rch�̉�����M,Sch�ɕϊ����s���j���s���A�t�H���}���g�V�t�g���s���܂���B
 */
#define CRIATOMEXASR_PITCH_SHIFTER_MODE_MUSIC							(0)

/*JP
 * \brief �s�b�`�V�t�^�̓��샂�[�h�Ń{�[�J�����w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER 
 * \par ����:
 * LR��MS�ϊ����s���A���t�H���}���g�V�t�g���s���܂��B
 */
#define CRIATOMEXASR_PITCH_SHIFTER_MODE_VOCAL							(1)

/*JP
 * \brief �s�b�`�V�t�^�̓��샂�[�h��SE���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER 
 * \par ����:
 * LR��MS�ϊ��͍s�킸�A�t�H���}���g�V�t�g���s���܂���B
 */
#define CRIATOMEXASR_PITCH_SHIFTER_MODE_SE								(2)

/*JP
 * \brief �s�b�`�V�t�^�̓��샂�[�h�ŃX�s�[�`���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_PITCH_SHIFTER 
 * \par ����:
 * LR��MS�ϊ��͍s�킸�A�t�H���}���g�V�t�g�͍s���܂��B
 */
#define CRIATOMEXASR_PITCH_SHIFTER_MODE_SPEECH							(3)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_REVERB ���o�[�u�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief ���o�[�u�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �c������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��o�[�u�̎c�����Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��3000.0f�A�ŏ��l��1.0f�A�ő�l��20000.0f�ł��B
 */
#define CRIATOMEXASR_REVERB_PARAMETER_REVERB_TIME_MS					(0)

/*JP
 * \brief ���[���T�C�Y[m]
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��o�[�u�̃��[���T�C�Y���w�肵�܂��B<br>
 * �ő僋�[���T�C�Y�̔����̒l�ŏ���������܂��B�p�����[�^�[�̍ŏ��l��1.0f�A�ő�l��50.0f�ł��B
 */
#define CRIATOMEXASR_REVERB_PARAMETER_ROOM_SIZE_M						(1)

/*JP
 * \brief �v���f�B���C����[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��o�[�u�̃v���f�B���C���Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̍ŏ��l��10.0f�A�ő�l��1000.0f�ł��B
 */
#define CRIATOMEXASR_REVERB_PARAMETER_PRE_DELAY_TIME_MS					(2)

/*JP
 * \brief ���J�b�g�I�t���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��o�[�u�o�͂̒��J�b�g�I�t���g�����w�肵�܂��B<br>
 * �����l��0.0f�ł��B�p�����[�^�[�̍ŏ��l��0.0f�A�ő�l��24000.0f�ł��B
 */
#define CRIATOMEXASR_REVERB_PARAMETER_LOW_COF							(3)

/*JP
 * \brief ����J�b�g�I�t���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ��o�[�u�o�͂̍���J�b�g�I�t���g�����w�肵�܂��B<br>
 * �����l��8000.0f�ł��B�p�����[�^�[�̍ŏ��l��8000.0f�A�ő�l��24000.f�ł��B
 */
#define CRIATOMEXASR_REVERB_PARAMETER_HIGH_COF							(4)

/*JP
 * \brief ���o�[�u�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB
 */
#define CRIATOMEXASR_REVERB_NUM_PARAMETERS								(5)

/*JP
 * \brief ���o�[�u�̓��샂�[�h�ŃT���E���h���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB 
 * \par ����:
 * �SCh�̓��͂����m�����փ~�b�N�X���A�o��Ch�ɍ��킹�ă}�g���N�X�T���E���h�ɓW�J���s���܂��B<br>
 * 
 *  - �o��Ch��5Ch�ȉ��̏ꍇ�́A�X�e���I�o�͂��s���܂��B
 *  - �o��Ch��6Ch�ȏ�̏ꍇ�́A�T���E���hCh�i�T���E���hL,RCh�j�Ƀ��ACh�i���AL,RCh�j��
 *    �t�ʑ��̐M�����o�͂��܂��B
 *
 * \attention �Z���^�[Ch��LFE�̏o�͖͂����ɂȂ�܂��B
 */
#define CRIATOMEXASR_REVERB_MODE_DEF_SURROUND							(0)

/*JP
 * \brief ���o�[�u�̓��샂�[�h�ŃX�e���I���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB 
 * \par ����:
 * 2Ch�œ��o�͂��s���܂��B
 */
#define CRIATOMEXASR_REVERB_MODE_DEF_STEREO								(1)

/*JP
 * \brief ���o�[�u�̓��샂�[�h�Ń��A�݂̂��w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB 
 * \par ����:
 * ���ACh�i���AL,RCh�j�݂̂œ��o�͂��s���܂��B
 */
#define CRIATOMEXASR_REVERB_MODE_DEF_REAR_ONLY							(2)

/*JP
 * \brief ���o�[�u�̓��샂�[�h�ŃZ���^�[�݂̂��w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_REVERB 
 * \par ����:
 * �Z���^�[Ch�݂̂œ��o�͂��s���܂��B
 */
#define CRIATOMEXASR_REVERB_MODE_DEF_CENTER_ONLY						(3)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_SURROUNDER �T���E���_�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �T���E���_�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief ���샂�[�h
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃT���E���_�̓��샂�[�h���w�肵�܂��B
 * \sa CRIATOMEXASR_SURROUNDER_MODE_STRAIGHT, CRIATOMEXASR_SURROUNDER_MODE_CROSS, CRIATOMEXASR_SURROUNDER_MODE_MATRIX
 */
#define CRIATOMEXASR_SURROUNDER_PARAMETER_MODE							(0)

/*JP
 * \brief �T���E���h�����̒x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃT���E���_�̃T���E���h�`�����l�������̒x�����Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��500.0f�ł��B
 */
#define CRIATOMEXASR_SURROUNDER_PARAMETER_DELAY_TIME_MS					(1)

/*JP
 * \brief �T���E���h�����̃Q�C��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃT���E���_�̃T���E���h�`�����l�������̏o�̓Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��10��2.4��i48dB�ɑ����j�ł��B
 */
#define CRIATOMEXASR_SURROUNDER_PARAMETER_GAIN							(2)

/*JP
 * \brief �T���E���_�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 */
#define CRIATOMEXASR_SURROUNDER_NUM_PARAMETERS							(3)


/*JP
 * \brief �T���E���_�̓��샂�[�h�ŃX�g���[�g���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * ���͂�LCh���T���E���hLCh�ɁARCh���T���E���hRCh�ɓW�J���܂��B
 */
#define CRIATOMEXASR_SURROUNDER_MODE_STRAIGHT							(0)

/*JP
 * \brief �T���E���_�̓��샂�[�h�ŃN���X���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * ���͂�LCh���T���E���hRCh�ɁARCh���T���E���hLCh�ɓW�J���܂��B
 */
#define CRIATOMEXASR_SURROUNDER_MODE_CROSS								(1)

/*JP
 * \brief �T���E���_�̓��샂�[�h�Ń}�g���N�X���w�肷��ۂ̃p�����[�^�[�̐ݒ�l
 * \ingroup CRIATOMASR_DSP_PARAM_SURROUNDER
 * \par ����:
 * ���͂�LCh - RCh�iLCh���͂���RCh���͂��������������́j���T���E���hLCh�ɁARCh - LCh���T���E���hRCh�ɓW�J���܂��B
 */
#define CRIATOMEXASR_SURROUNDER_MODE_MATRIX								(2)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER �r�b�g�N���b�V���[�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �r�b�g�N���b�V���[�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �c�݂̋���[dB]
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[�̘c�݂̋����i�h���C�u�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��48.0f�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_DRIVE_DB						(0)

/*JP
 * \brief �ʎq���r�b�g��
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[�̗ʎq���r�b�g�����w�肵�܂��B<br>
 * �������ݒ肷��قǐU����Lo-Fi�ɂȂ�܂��B<br>
 * �p�����[�^�[�̏����l��8�A�ŏ��l��1�A�ő�l��24�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_DEPTH_BITS					(1)

/*JP
 * \brief �_�E���T���v�����O
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[�̃_�E���T���v�����O���w�肵�܂��B<br>
 * �傫���ݒ肷��قǎ��Ԃ�Lo-Fi�ɂȂ�܂��B<br>
 * �p�����[�^�[�̏����l��8�A�ŏ��l��1�A�ő�l��100�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_DOWN_SAMPLING				(2)

/*JP
 * \brief dry�����̊���
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[��dry�i�����j�������~�b�N�X���銄�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_DRY_MIX						(3)

/*JP
 * \brief wet�����̊���
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[��wet�i�c�݁j�������~�b�N�X���銄�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_WET_MIX						(4)

/*JP
 * \brief �ŏI�o�̓��x��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀr�b�g�N���b�V���[�̍ŏI�o�̓��x�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��10��2.4��i48dB�ɑ�������l�j�ł��B
 */
#define CRIATOMEXASR_BIT_CRUSHER_PARAMETER_OUTPUT_GAIN					(5)

/*JP
 * \brief �r�b�g�N���b�V���[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_BIT_CRUSHER
 */
#define CRIATOMEXASR_BIT_CRUSHER_NUM_PARAMETERS							(6)

/*JP
 * \defgroup CRIATOMASR_DSP_PARAM_PHASER �t�F�[�U�[�̃p�����[�^�[
 * \ingroup CRIATOMASR_DSP_PARAM
 * \brief �t�F�[�U�[�Őݒ肷��p�����[�^�[�̒�`�ł��B
 * \sa criAtomExAsrRack_SetEffectParameter, criAtomExAsrRack_GetEffectParameter
 */
/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[�̃t�F�C�W���O���ʂ̋������w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��8�A�ŏ��l��4�A�ő�l��12�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_STAGES							(0)

/*JP
 * \brief �[���iLFO�U���j
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[�̐[�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_DEPTH								(1)

/*JP
 * \brief ���[�g�i�X�s�[�h�ALFO���g���j[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[��LFO�̃��[�g���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.01f�A�ő�l��100.0f�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_RATE								(2)

/*JP
 * \brief �t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[�̃t�B�[�h�o�b�N�Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_FEEDBACK							(3)

/*JP
 * \brief dry�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[��dry�i�����j�����̃~�b�N�X�������w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_DRY_MIX							(4)

/*JP
 * \brief wet�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀt�F�[�U�[��wet�i�����j�����̃~�b�N�X�������w�肵�܂��B
 * �p�����[�^�[�̏����l��0.71f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_PHASER_PARAMETER_WET_MIX							(5)

/*JP
 * \brief �t�F�[�U�[�̃p�����[�^�[��
 * \ingroup CRIATOMASR_DSP_PARAM_PHASER
 */
#define CRIATOMEXASR_PHASER_NUM_PARAMETERS								(6)

/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx ASR API
 *=========================================================================*/
/*JP
 * \brief ASR�̏������R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ::criAtomExAsr_Initialize �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExAsrConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomExAsr_Initialize, CriAtomExAsrConfig
 */
#define criAtomExAsr_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->num_buses = CRIATOMEXASR_DEFAULT_NUM_BUSES; \
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_NATIVE;\
	(p_config)->context	= NULL;\
	(p_config)->max_racks = 8;\
	(p_config)->ambisonics_order_type = CRIATOMAMBISONICS_ORDER_TYPE_NONE;\
}

/*JP
 * \brief ���x������@�\�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ::criAtomExAsr_AttachBusAnalyzer �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExAsrBusAnalyzerConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomExAsr_AttachBusAnalyzer, CriAtomExAsrBusAnalyzerConfig
 */
#define criAtomExAsr_SetDefaultConfigForBusAnalyzer(p_config) \
{\
	(p_config)->interval = 50;\
	(p_config)->peak_hold_time = 1000;\
}

/*==========================================================================
 *      CRI AtomEx ASR Rack API
 *=========================================================================*/
/*JP
 * \brief CriAtomAsrConfig�ւ̃f�t�H���g�p�����[�^�[���Z�b�g
 * \ingroup ATOMLIB_ASR
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomAsr_Initialize �֐��ɐݒ肷��R���t�B�O�\���́i ::CriAtomAsrConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa
 * CriAtomAsrConfig
*/
#define criAtomExAsrRack_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->num_buses = CRIATOMEXASR_DEFAULT_NUM_BUSES; \
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_NATIVE;\
	(p_config)->output_rack_id = 0;\
	(p_config)->context = NULL;\
}

/*==========================================================================
 *      CRI Atom ASR API
 *=========================================================================*/
/*JP
 * \brief CriAtomAsrConfig�ւ̃f�t�H���g�p�����[�^�[���Z�b�g
 * \ingroup ATOMLIB_ASR
 * \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
 * \par ����:
 * ::criAtomAsr_Initialize �֐��ɐݒ肷��R���t�B�O�\���́i ::CriAtomAsrConfig �j�ɁA
 * �f�t�H���g�̒l���Z�b�g���܂��B<br>
 * \sa
 * CriAtomAsrConfig
*/
#define criAtomAsr_SetDefaultConfig(p_config)	\
{\
	(p_config)->server_frequency = 60.0f;\
	(p_config)->num_buses = CRIATOMEXASR_DEFAULT_NUM_BUSES; \
	(p_config)->output_channels = CRIATOM_DEFAULT_OUTPUT_CHANNELS;\
	(p_config)->output_sampling_rate = CRIATOM_DEFAULT_OUTPUT_SAMPLING_RATE;\
	(p_config)->sound_renderer_type	= CRIATOM_SOUND_RENDERER_NATIVE;\
	(p_config)->context	= NULL;\
	(p_config)->max_racks = 8;\
	(p_config)->ambisonics_order_type = CRIATOMAMBISONICS_ORDER_TYPE_NONE;\
}

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
* \brief ���C�u�����������p�R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
* \ingroup ATOMEXLIB_GLOBAL
* \param[out]	p_config	�������p�R���t�B�O�\���̂ւ̃|�C���^
* \par ����:
* ::criAtomEx_InitializeForUserPcmOutput �֐��ɐݒ肷��R���t�B�O�\����
* �i ::CriAtomExConfigForUserPcmOutput �j�ɁA�f�t�H���g�̒l���Z�b�g���܂��B<br>
* \sa CriAtomExConfigForUserPcmOutput
*/
#define criAtomEx_SetDefaultConfigForUserPcmOutput(p_config)			\
{															\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
	criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
}

/*==========================================================================
 *      CRI ASR�o�X�G�t�F�N�g �p�����[�^�[�C���f�b�N�X�A�N�Z�X�}�N��
 *=========================================================================*/
/*JP
 * \brief wet�����̃~�b�N�X
 * \ingroup CRIATOMASR_DSP_PARAM_CHORUS
 * \param[in] tap_index	�ݒ�Ώۂ̃��W�����[�^�^�b�v�̃C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�ɃR�[���X��wet�i�t�B�[�h�o�b�N�j�����̃~�b�N�X���������W�����[�^�̃C���f�b�N�X�ɂ��w�肵�܂��B<br>
 * �S�Ẵ^�b�v�Ńp�����[�^�[�̏����l��0.5f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_CHORUS_PARAMETER_WET_MIX(tap_index)				\
	((tap_index) + 5)

/*JP
 * \brief �Z���h���x��[�U��]
 * \param[in] input_ch	�ݒ�Ώۂ̓��̓`�����l��
 * \param[in] output_ch	�ݒ�Ώۂ̏o�̓`�����l��
 * \ingroup CRIATOMASR_DSP_PARAM_MATRIX
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ}�g���N�X�̃Z���h���x������o�̓`�����l������p���Ďw�肵�܂��B<br>
 * �p�����[�^�[�̍ŏ��l��0.0f�A�ő�l��1.0f�ł��B�����l�ɂ�input_ch == output_ch�̗v�f�ɂ�1.0f�A����ȊO�ɂ�0.0f���Z�b�g����܂��B
 */
#define CRIATOMEXASR_MATRIX_PARAMETER_LEVELS(input_ch, output_ch)		\
	((input_ch) * CRIATOMEXASR_MATRIX_MAX_NUM_CHANNELS + (output_ch))

/*JP
 * \brief �e�o���h�̃t�B���^�[�^�C�v
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 * \param[in] band_index	�ݒ�Ώۂ̃o���h�C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̊e�o���h�̃t�B���^�[�̃^�C�v���w�肵�܂��B<br>
 * �e�o���h�̃t�B���^�[�̓o�C�N�A�b�h�t�B���^�[����\������܂��B
 * \attention 32�o���h�C�R���C�U�ł́A�c�[����ŗL���ɂ����o���h�̃t�B���^�[�݂̂��L���ɂȂ�A�o���h�����L���ɂȂ��Ă���o���h���݂̂ɐ�������܂��B
 * \sa CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_LOWSHELF, CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_HIGHSHELF, CRIATOMEXASR_MULTIBANDS_EQ_BAND_FILTER_TYPE_PEAKING
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_PARAMETER_TYPE(band_index)			\
	(CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND * (band_index))

/*JP
 * \brief �e�o���h�̒��S���g��[Hz]
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 * \param[in] band_index	�ݒ�Ώۂ̃o���h�C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̊e�o���h�̃t�B���^�[�̒��S���g�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��24.0f�A�ŏ��l��24.0f�A�ő�l��24000.f�ł��B
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_PARAMETER_FREQUENCY(band_index)		\
	(CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND * (band_index) + 1)	

/*JP
 * \brief �e�o���h��Q�l
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 * \param[in] band_index	�ݒ�Ώۂ̃o���h�C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̊e�o���h��Q�l�i��s�x�A�N�I���e�B�t�@�N�^�j���w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��10.0f�ł��B<br>
 * �o���h�p�X�t�B���^�[�ȊO�ł͐M�������̍ۂɍŏ��l��0.001f�ɐ�������܂��B
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_PARAMETER_QUALITY_FACTOR(band_index)	\
	(CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND * (band_index) + 2)	

/*JP
 * \brief �e�o���h�̏o�̓Q�C��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 * \param[in] band_index	�ݒ�Ώۂ̃o���h�C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X��3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̊e�o���h�̏o�̓Q�C�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��1.0f�A�ŏ��l��0.0f�A�ő�l��5.0f�ł��B<br>
 * ���[�V�F���t�A�n�C�V�F���t�A�s�[�L���O�t�B���^�[�̏ꍇ�͐M�������̍ۂɍŏ��l�� ��1/65536.0f�ɐ�������܂��B
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_PARAMETER_GAIN(band_index)			\
	(CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND * (band_index) + 3)	

/*JP
 * \brief 3�o���h�C�R���C�U�E32�o���h�C�R���C�U�̑S�p�����[�^�[�����A�o���h���w��ɂ��v�Z���܂��B
 * \ingroup CRIATOMASR_DSP_PARAM_MULTIBANDS_EQ
 * \param[in] num_bands	�o���h��
 */
#define CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETERS(num_bands)			\
	((num_bands) * CRIATOMEXASR_MULTIBANDS_EQ_NUM_PARAMETER_PAR_BAND)

/*JP
 * \brief �x������[ms]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \param[in] i_tap	�ݒ�Ώۂ̃^�b�v�̃C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ}���`�^�b�v�f�B���C�̊e�^�b�v�̒x�����Ԃ��w�肵�܂��B<br>
 * �p�����[�^�[�̏����l�͍ő�f�B���C���Ԃ̔����̒l�A�ő�l��10000.0f�A�ŏ��l��4�̃^�b�v1,2,3,4���ꂼ���20.0f�A40.0f�A60.0f�A80.0f�ɐ�������܂��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_DELAY_TIME_MS(i_tap)		\
	(0 + (i_tap) * CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP)

/*JP
 * \brief �o�̓��x��[�U��]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \param[in] i_tap	�ݒ�Ώۂ̃^�b�v�̃C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ}���`�^�b�v�f�B���C�̊e�^�b�v�̏o�̓��x�����w�肵�܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l��1.0f�ł��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_LEVEL(i_tap)				\
	(1 + (i_tap) * CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP)

/*JP
 * \brief �����i�p���j�p�x[��]
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \param[in] i_tap	�ݒ�Ώۂ̃^�b�v�̃C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ}���`�^�b�v�f�B���C�̊e�^�b�v�̐��������̊p�x���w�肵�܂��B<br>
 * ���̊p�x���w�肷�邱�ƂŁA���������ɍL������������x��������\���ł��܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��-180.0f�A�ő�l��180.f�ł��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_AZIMUTH(i_tap)			\
	(2 + (i_tap) * CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP)

/*JP
 * \brief �t�B�[�h�o�b�N�Q�C��
 * \ingroup CRIATOMASR_DSP_PARAM_DELAY
 * \param[in] i_tap	�ݒ�Ώۂ̃^�b�v�̃C���f�b�N�X
 * \par ����:
 * �{�p�����[�^�[�C���f�b�N�X�Ƀ}���`�^�b�v�f�B���C�̃t�B�[�h�o�b�N�Q�C�����w�肵�܂��B
 * \attention �t�B�[�h�o�b�N�Q�C�����傫������Əo�͂����U���܂��B<br>
 * �p�����[�^�[�̏����l��0.0f�A�ŏ��l��0.0f�A�ő�l�͊e�^�b�v��1.0f�ł����A�S�^�b�v�̑��a��0.90f�ɂȂ�悤�ɐ�������܂��B
 */
#define CRIATOMEXASR_MULTITAP_DELAY_PARAMETER_FEEDBACK(i_tap)			\
	(3 + (i_tap) * CRIATOMEXASR_MULTITAP_DELAY_NUM_PARAMETER_PAR_TAP)

/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx ASR API
 *=========================================================================*/
/*JP
 * \brief ASR�������p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_ASR
 * ASR�iAtom Sound Renderer�j�̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExAsr_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomExAsr_SetDefaultConfig �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomExAsr_Initialize �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExAsr_SetDefaultConfig 
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExAsr_Initialize, criAtomExAsr_SetDefaultConfig
 */
typedef struct CriAtomExAsrConfigTag {
	/*JP
		\brief �T�[�o�[�����̎��s�p�x
		\par ����:
		�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		\attention
		Atom���C�u�������������Ɏw�肵���l�i ::CriAtomExConfig �\���̂�
		server_frequency �j�ƁA�����l���Z�b�g����K�v������܂��B<br>
		\sa CriAtomConfig
	*/
	CriFloat32 server_frequency;

	/*JP
		\par ����:
		\brief �o�X��
		\par ����:
		ASR���쐬����o�X�̐����w�肵�܂��B<br>
		�o�X�̓T�E���h�̃~�b�N�X��A�G�t�F�N�g�̊Ǘ������s���܂��B<br>
		�}�X�^�[�o�X�̗̈��1���܂߂邽�߁A�K��1�ȏ�̒l��ݒ肵�ĉ������B<br>
	*/
	CriSint32 num_buses;

	/*JP
		\brief �o�̓`�����l����
		ASR�̏o�̓`�����l�������w�肵�܂��B<br>
		�p��3D��������3D�|�W�V���j���O�@�\���g�p����ꍇ��6ch�ȏ���w�肵�܂��B<br>
	*/
	CriSint32 output_channels;
	
	/*JP
		\brief �o�̓T���v�����O���[�g
		\par ����:
		�o�͂���я����ߒ��̃T���v�����O���[�g���w�肵�܂��B<br>
		�ʏ�A�^�[�Q�b�g�@�̃T�E���h�f�o�C�X�̃T���v�����O���[�g���w�肵�܂��B<br>
		\par ���l:
		�Ⴍ����Ə������ׂ������邱�Ƃ��ł��܂��������������܂��B<br>
	*/
	CriSint32 output_sampling_rate;
	
	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		ASR�̏o�͐�T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		\attention
		CRIATOM_SOUND_RENDERER_ASR�����CRIATOM_SOUND_RENDERER_DEFAULT�͎w�肵�Ȃ��ł��������B
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[��ASR���b�N���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
	
	/*JP
		\brief ASR���b�N�̍ő吔
		\par ����:
		�쐬�\��ASR���b�N�̍ő���ł��B<br>
	*/
	CriSint32 max_racks;

	/*JP
		\brief Ambisonics�̃I�[�_�[�^�C�v
		\par ����:
		Atom���C�u������Ambisonics�̍Đ����s���ہA�ǂ̃I�[�_�[�^�C�v���g�p���邩�ݒ肵�܂��B<br>
		\par ���l:
		Ambisonics�̍Đ��ɔ�Ή��̃v���b�g�t�H�[���ł́A���̒l�͖�������܂��B<br>
		�܂��A ::CRIATOMAMBISONICS_ORDER_TYPE_NONE ���w�肵���ꍇ�AAmbisonics�̍Đ����s���܂���B<br>
	 */
	CriAtomAmbisonicsOrderType ambisonics_order_type;
} CriAtomExAsrConfig;

/*JP
 * \brief ���x������@�\�A�^�b�`�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_ASR
 * ���x������@�\���o�X�ɃA�^�b�`���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAsr_AttachBusAnalyzer �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomExAsr_SetDefaultConfigForBusAnalyzer �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomExAsr_AttachBusAnalyzer �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExAsr_SetDefaultConfigForBusAnalyzer
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExAsr_AttachBusAnalyzer
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
	CriSint32 peak_hold_time;
} CriAtomExAsrBusAnalyzerConfig;

/*JP
 * \brief ���x��������
 * \par ����:
 * �o�X�̃��x����������擾���邽�߂̍\���̂ł��B<br>
 * ::criAtomExAsr_GetBusAnalyzerInfo �֐��ŗ��p���܂��B
 * \par ���l:
 * �e���x���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �ȉ��̃R�[�h�Ńf�V�x���\�L�ɕϊ����邱�Ƃ��ł��܂��B<br>
 * dB = 10.0f * log10f(level);
 * \sa criAtomExAsr_GetBusAnalyzerInfo
 */
typedef struct CriAtomExAsrBusAnalyzerInfoTag {
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
	CriFloat32 rms_levels[CRIATOMEXASR_MAX_CHANNELS];
	
	/*JP
		\brief �s�[�N���x��
		\par ����:
		����Ԋu�Ԃ̉����U���̍ő�l�ł��B<br>
	*/
	CriFloat32 peak_levels[CRIATOMEXASR_MAX_CHANNELS];
	
	/*JP
		\brief �s�[�N�z�[���h���x��
		\par ����:
		�z�[���h���Ă���s�[�N���x���l�ł��B<br>
	*/
	CriFloat32 peak_hold_levels[CRIATOMEXASR_MAX_CHANNELS];
} CriAtomExAsrBusAnalyzerInfo;

/*JP
 * \brief �p�����\����
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * �o�X�ɂ�����p�������܂Ƃ߂��\���̂ł��B<br>
 * �o�X�̃p�����̐ݒ��擾�Ɏg�p���܂��B
 * \sa criAtomExAsr_SetBusPanInfoByName, criAtomExAsr_GetBusPanInfoByName, criAtomExAsrRack_SetBusPanInfoByName, criAtomExAsrRack_GetBusPanInfoByName
 */
typedef struct CriAtomExAsrBusPanInfoTag {
	/*JP
		\brief ����
		\par ����:
		�p���ɂ����鉹�ʂł��B<br>
		0.0f �` 1.0f�͈̔͂Őݒ�E�擾����܂��B<br>
		�܂��A�ʏ�̉��ʂƊ|�����킳��܂��B
	*/
	CriFloat32 volume;
	/*JP
		\brief �p�x
		\par ����:
		�p���ɂ�����p�x�ł��B<br>
		0.0f �𐳖ʂƂ��� -180.0f �` 180.0f�͈̔͂Őݒ�E�擾����܂��B
	*/
	CriFloat32 angle;
	/*JP
		\brief �C���e���A����
		\par ����:
		�p���ɂ�����C���e���A�����ł��B<br>
		0.0f �` 1.0f�͈̔͂Őݒ�E�擾����܂��B
	*/
	CriFloat32 distance;
	/*JP
		\brief �X�v���b�h
		\par ����:
		�p���ɂ�����X�v���b�h�ł��B<br>
		0.0f �` 1.0f�͈̔͂Őݒ�E�擾����܂��B
	*/
	CriFloat32 spread;
} CriAtomExAsrBusPanInfo;

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_PLAYER
 * \par ����:
 * \param[in]		obj				���[�U�w��I�u�W�F�N�g
 * \param[in]		format			PCM�̌`��
 * \param[in]		num_channels	�`�����l����
 * \param[in]		num_samples		�T���v����
 * \param[in,out]	data			PCM�f�[�^�̃`�����l���z��
 * \return							�Ȃ�
 * \par ����:
 * �o�X�ɓo�^���邱�Ƃ��ł��� PCM �f�[�^���󂯎��R�[���o�b�N�֐��ł��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExAsr_SetBusFilterCallback �֐����g�p���܂��B<br>
 * �R�[���o�b�N�֐���o�^����ƁA�T�E���h�����_���������������s���x�ɁA
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
 * �T���v������32�̔{���ŁA������32�A�����256�ƂȂ�܂��B<br>
 * �܂��A�T���v�����̓v���b�g�t�H�[���f�o�C�X�̏o�͂̐i���ɉ����ĕω����܂��B<br>
 * �� 6 �����i data �z��j�ɂ́A�e�`�����l���� PCM �f�[�^�z��̐擪�A�h���X���i�[����Ă��܂��B<br>
 * �i�񎟌��z��̐擪�A�h���X�ł͂Ȃ��A�`�����l�����Ƃ� PCM �f�[�^�z��̐擪�A�h���X���i�[����
 * �ꎟ���̃|�C���^�z��ł��B�j<br>
 * �i�[����Ă��� PCM �f�[�^�̓o�X�ɐݒ肳��Ă���G�t�F�N�g�̏�����̉����ł��B<br>
 * <br>
 * �v���b�g�t�H�[���ɂ���āA PCM �f�[�^�̃t�H�[�}�b�g�͈قȂ�܂��B<br>
 * ���s���̃f�[�^�t�H�[�}�b�g�ɂ��ẮA�� 3 �����i format �j�Ŕ��ʉ\�ł��B<br>
 * PCM �f�[�^�̃t�H�[�}�b�g�� 16 bit �����^�̏ꍇ�A format �� CRIATOM_PCM_FORMAT_SINT16 �ƂȂ�A
 * PCM �f�[�^�̃t�H�[�}�b�g�� 32 bit ���������_���^�̏ꍇ�A format �� CRIATOM_PCM_FORMAT_FLOAT32 �ƂȂ�܂��B<br>
 * ���ꂼ��̃P�[�X�� PCM �f�[�^�̒l��͈قȂ�܂��̂ł����ӂ��������B<br>
 * - CRIATOM_PCM_FORMAT_SINT16 ���� -32768 �` +32767
 * - CRIATOM_PCM_FORMAT_FLOAT32 ���� -1.0f �` +1.0f
 * 
 * �i���d�����̃~�L�V���O��O�i�̃G�t�F�N�g�ɂ���Ă͏�L�͈͂𒴂����l���o��\��������܂��B�j<br>
 * \attention
 * <br>
 * �{�R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪��������\��������܂��B<br>
 * \sa criAtomExAsr_SetBusFilterCallback
 */
typedef void (*CriAtomExAsrBusFilterCbFunc)(void *obj, CriAtomPcmFormat format,
	CriSint32 num_channels, CriSint32 num_samples, void *data[]);

/*JP
 * \brief �G�t�F�N�g�C���^�[�t�F�[�X�\���̂̕s���S�^
 * \par ����:
 * �G�t�F�N�g�C���^�[�t�F�[�X�o�^�֐��̈����^�ł��B
 * \sa criAtomExAsr_RegisterEffectInterface, criAtomExAsr_UnregisterEffectInterface
 */
typedef const struct CriAfxInterfaceWithVersionTag* CriAtomExAsrAfxInterfaceWithVersionPtr;

/*JP
 * \brief IR���o�[�u�G�t�F�N�g�̕��׌v���\����
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * IR���o�[�u�̕��׌v���œ���������܂Ƃ߂��\���̂ł��B
 * IR���o�[�u�͈��T���v����1�u���b�N�Ƃ��Ĕ񓯊��ŏ������A�u���b�N�P�ʂŕ��ׂ��v�����܂��B
 * \attention
 * �v���b�g�t�H�[���ɂ���Čv���������e���قȂ�ꍇ������܂��B<br>
 * �ڂ����͊e�v���b�g�t�H�[����CRI ADX2 �}�j���A���� IR ���o�[�u���Q�Ƃ��Ă��������B
 * \sa criAtomExAsr_GetIrReverbPerformanceInfo
 */
typedef struct CriAtomExAsrIrReverbPerformanceInfoTag {
	/*JP
		\brief �u���b�N�T�C�Y
		\par ����:
		Craft�Őݒ�\��IR���o�[�u��1�u���b�N�̃T���v�����ł��B
		\par ���l:
		����IR���o�[�u�̃u���b�N�T�C�Y��512,1024�݂̂��T�|�[�g���܂��B<br>
		�o�X��IR���o�[�u�G�t�F�N�g�����݂��Ȃ��ꍇ�A0��Ԃ��܂��B
    */
	CriUint32 blocksize;
	
	/*JP
		\brief �T���v�����O���[�g
		\par ����:
		IR���o�[�u�����T���v�����O���[�g�ł��B
		\par ���l:
		���݌���IR���o�[�u�̃T���v�����O���[�g��48000Hz�݂̂��T�|�[�g���܂��B<br>
		�o�X��IR���o�[�u�G�t�F�N�g�����݂��Ȃ��ꍇ�A0��Ԃ��܂��B
    */
	CriUint32 sampling_rate;
	
	/*JP
		\brief ������
		\par ����:
		IR���o�[�u��1�u���b�N�̏����񐔂ł��B
    */
	CriUint32 process_count;

	/*JP
		\brief �ŐV�������ԁi�}�C�N���b�j
		\par ����:
		IR���o�[�u�̍ŐV��1�u���b�N�̏����ɂ����������Ԃł��B
	*/
	CriUint32 last_process_time;

	/*JP
		\brief �ő又�����ԁi�}�C�N���b�j
		\par ����:
		IR���o�[�u�̌v�����Z�b�g����擾���_�܂łōł�����1�u���b�N�̏������Ԃł��B
	*/
	CriUint32 max_process_time;

	/*JP
		\brief ���Ϗ������ԁi�}�C�N���b�j
		\par ����:
		IR���o�[�u�̌v�����Z�b�g����擾���_�܂�1�u���b�N�̕��Ϗ������Ԃł��B
	*/
	CriUint32 average_process_time;

	/*JP
		\brief �ŐV�����C���^�[�o���i�}�C�N���b�j
		\par ����:
		IR���o�[�u�̍ŐV��1�u���b�N�̏����Ԋu�ł��B
	*/
	CriUint32 last_process_interval;

	/*JP
		\brief �ő又���C���^�[�o���i�}�C�N���b�j
		\par ����:
		IR���o�[�u�̌v�����Z�b�g����擾���_�܂łōł�����1�u���b�N�̏����C���^�[�o���ł��B
	*/
	CriUint32 max_process_interval;

	/*JP
		\brief ���Ϗ������ԁi�}�C�N���b�j
		\par ����:
		IR���o�[�u�̌v�����Z�b�g����擾���_�܂�1�u���b�N�̕��Ϗ����C���^�[�o���ł��B
	*/
	CriUint32 average_process_interval;

} CriAtomExAsrIrReverbPerformanceInfo;

/*==========================================================================
 *      CRI AtomEx ASR Rack API
 *=========================================================================*/

/*JP
 * \brief ASR���b�NID
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR���b�N�Ǘ��p��ID�^�ł��B<br>
 * ::criAtomExAsrRack_Create �֐���ASR���b�N���쐬����Ǝ擾�ł��܂��B<br>
 * \sa criAtomExAsrRack_Create, criAtomExAsrRack_AttachDspBusSetting
 */
typedef CriSint32 CriAtomExAsrRackId;

/*JP
 * \brief ASR���b�N�쐬�p�R���t�B�O�\����
 * \ingroup ATOMEXLIB_ASR
 * ASR�iAtom Sound Renderer�j�̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExAsrRack_Create �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomExAsrRack_SetDefaultConfig �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomExAsrRack_Create �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExAsrRack_SetDefaultConfig 
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExAsrRack_Create, criAtomExAsrRack_SetDefaultConfig
 */
typedef struct CriAtomExAsrRackConfigTag {
	/*JP
		\brief �T�[�o�[�����̎��s�p�x
		\par ����:
		�T�[�o�[���������s����p�x���w�肵�܂��B<br>
		\attention
		Atom���C�u�������������Ɏw�肵���l�i ::CriAtomExConfig �\���̂�
		server_frequency �j�ƁA�����l���Z�b�g����K�v������܂��B<br>
		\sa CriAtomConfig
	*/
	CriFloat32 server_frequency;
	
	/*JP
		\par ����:
		\brief �o�X��
		\par ����:
		ASR���쐬����o�X�̐����w�肵�܂��B<br>
		�o�X�̓T�E���h�̃~�b�N�X��A�G�t�F�N�g�̊Ǘ������s���܂��B<br>
	*/
	CriSint32 num_buses;

	/*JP
		\brief �o�̓`�����l����
		\par ����:
		ASR���b�N�̏o�̓`�����l�������w�肵�܂��B<br>
		�p��3D��������3D�|�W�V���j���O�@�\���g�p����ꍇ��6ch�ȏ���w�肵�܂��B<br>
	*/
	CriSint32 output_channels;
	
	/*JP
		\brief �o�̓T���v�����O���[�g
		\par ����:
		ASR���b�N�̏o�͂���я����ߒ��̃T���v�����O���[�g���w�肵�܂��B<br>
		�ʏ�A�^�[�Q�b�g�@�̃T�E���h�f�o�C�X�̃T���v�����O���[�g���w�肵�܂��B<br>
		\par ���l:
		�Ⴍ����Ə������ׂ������邱�Ƃ��ł��܂��������������܂��B<br>
	*/
	CriSint32 output_sampling_rate;
	
	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		ASR���b�N�̏o�͐�T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
	*/
	CriAtomSoundRendererType sound_renderer_type;

	/*JP
		\brief �o�͐�ASR���b�NID
		\par ����:
		ASR���b�N�̏o�͐�ASR���b�NID���w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_ASR ���w�肵���ꍇ�̂ݗL���ł��B<br>
	*/
	CriAtomExAsrRackId output_rack_id;

	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[��ASR���b�N���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;
} CriAtomExAsrRackConfig;

/*==========================================================================
 *      CRI Atom ASR API
 *=========================================================================*/
/*JP
 * \brief ASR�������p�R���t�B�O�\����
 * \ingroup ATOMLIB_ASR
 * ASR�iAtom Sound Renderer�j�̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomAsr_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomAsr_SetDefaultConfig �}�N����
 * �\���̂Ƀf�t�H���g�p�����[�^�[���Z�b�g������A ::criAtomAsr_Initialize �֐�
 * �ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomAsr_SetDefaultConfig 
 * �}�N�����g�p���Ȃ��ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomAsr_Initialize, criAtomAsr_SetDefaultConfig
 */
typedef struct CriAtomAsrConfigTag {
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
		\par ����:
		\brief �o�X��
		\par ����:
		ASR���쐬����o�X�̐����w�肵�܂��B<br>
		�o�X�̓T�E���h�̃~�b�N�X��A�G�t�F�N�g�̊Ǘ������s���܂��B<br>
	*/
	CriSint32 num_buses;

	/*JP
		\brief �o�̓`�����l����
		\par ����:
		ASR�̏o�̓`�����l�������w�肵�܂��B<br>
		�p��3D��������3D�|�W�V���j���O�@�\���g�p����ꍇ��6ch�ȏ���w�肵�܂��B<br>
	*/
	CriSint32 output_channels;
	
	/*JP
		\brief �o�̓T���v�����O���[�g
		\par ����:
		�o�͂���я����ߒ��̃T���v�����O���[�g���w�肵�܂��B<br>
		�ʏ�A�^�[�Q�b�g�@�̃T�E���h�f�o�C�X�̃T���v�����O���[�g���w�肵�܂��B<br>
		\par ���l:
		�Ⴍ����Ə������ׂ������邱�Ƃ��ł��܂��������������Ȃ�܂��B<br>
	*/
	CriSint32 output_sampling_rate;
	
	/*JP
		\brief �T�E���h�����_���^�C�v
		\par ����:
		ASR�̏o�͐�T�E���h�����_���̎�ʂ��w�肵�܂��B<br>
		sound_renderer_type �� CRIATOM_SOUND_RENDERER_NATIVE ���w�肵���ꍇ�A
		�����f�[�^�̓f�t�H���g�ݒ�̊e�v���b�g�t�H�[���̃T�E���h�o�͂ɓ]������܂��B<br>
		\attention
		CRIATOM_SOUND_RENDERER_ASR�����CRIATOM_SOUND_RENDERER_DEFAULT�͎w�肵�Ȃ��ł��������B
	*/
	CriAtomSoundRendererType sound_renderer_type;
	
	/*JP
		\brief �v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^
		\par ����:
		�v���b�g�t�H�[���ŗL�̃p�����[�^�[�ւ̃|�C���^���w�肵�܂��B
		NULL���w�肵���ꍇ�A�v���b�g�t�H�[�����̃f�t�H���g�p�����[�^�[��ASR���b�N���쐬���܂��B<br>
		�p�����[�^�[�\���̂͊e�v���b�g�t�H�[���ŗL�w�b�_�[�ɒ�`����Ă��܂��B
		�p�����[�^�[�\���̂���`����Ă��Ȃ��v���b�g�t�H�[���ł́A���NULL���w�肵�Ă��������B
	*/
	void *context;

	/*JP
		\brief ASR���b�N�̍ő吔
		\par ����:
		�쐬�\��ASR���b�N�̍ő���ł��B<br>
	*/
	CriSint32 max_racks;

	/*JP
		\brief Ambisonics�̃I�[�_�[�^�C�v
		\par ����:
		Atom���C�u������Ambisonics�̍Đ����s���ہA�ǂ̃I�[�_�[�^�C�v���g�p���邩�ݒ肵�܂��B<br>
		\par ���l:
		Ambisonics�̍Đ��ɔ�Ή��̃v���b�g�t�H�[���ł́A���̒l�͖�������܂��B<br>
		�܂��A ::CRIATOMAMBISONICS_ORDER_TYPE_NONE ���w�肵���ꍇ�AAmbisonics�̍Đ����s���܂���B<br>
	 */
	CriAtomAmbisonicsOrderType ambisonics_order_type;
} CriAtomAsrConfig;

/*==========================================================================
*      CRI AtomEx API
*=========================================================================*/
/*JP
* \brief Atom���C�u�����������p�R���t�B�O�\����
* \ingroup ATOMLIB_PC
* CRI Atom���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
* ::criAtomEx_InitializeForUserPcmOutput �֐��̈����Ɏw�肵�܂��B<br>
* \sa criAtomEx_InitializeForUserPcmOutput, criAtomEx_SetDefaultConfigForUserPcmOutput
*/
typedef struct CriAtomExConfigForUserPcmOutputTag {
	CriAtomExConfig			atom_ex;	/*JP< AtomEx�������p�R���t�B�O�\����	*/
	CriAtomExAsrConfig		asr;		/*JP< ASR�������p�R���t�B�O			*/
	CriAtomExHcaMxConfig	hca_mx;		/*JP< HCA-MX�������p�R���t�B�O�\����	*/
} CriAtomExConfigForUserPcmOutput;

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
 *      CRI AtomEx ASR API
 *=========================================================================*/
/*JP
 * \brief ASR�������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config	ASR�������p�R���t�B�O�\����
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExAsr_Initialize �֐���ASR�̏��������s���ꍇ�A
 * �{�֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ASR�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR�������p�R���t�B�O
 * �\���́i ::CriAtomExAsrConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx_SetUserAllocator, criAtomExAsr_Initialize
 */
CriSint32 CRIAPI criAtomExAsr_CalculateWorkSize(const CriAtomExAsrConfig *config);

/*JP
 * \brief ���[�N�̈�T�C�Y�v�Z�p�R���t�B�O�\���̂̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config	ASR�������p�R���t�B�O�\����
 * \par ����:
 * ���[�N�̈�T�C�Y�̌v�Z�p�ɁAASR�������p�R���t�B�O�\����
 * �i ::CriAtomExAsrConfig �\���́j�����o�^���܂��B<br>
 * <br>
 * �G�t�F�N�g�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�̃T�C�Y�́A
 * ASR���������i ::criAtomExAsr_Initialize �֐����s���j
 * �ɐݒ肷��\���̂̃p�����[�^�[�ɂ���ĕω����܂��B<br>
 * ���̂��߁A�ʏ�̓G�t�F�N�g�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z����O�ɁA
 * ASR������������K�v������܂��B<br>
 * �{�֐����g�p����ASR�������p�R���t�B�O�\���̂�o�^�����ꍇ�A
 * �G�t�F�N�g�̃A�^�b�`�ɕK�v�ȃ��[�N�̈�̃T�C�Y���A
 * �����������Ȃ��Ɍv�Z�\�ɂȂ�܂��B<br>
 * �i ::criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData
 * �֐������s�\�ƂȂ�܂��B�j<br>
 * \par ���l:
 * �����i config �j�� NULL ���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B<br>
 * <br>
 * ����A�{�֐��ň�U�R���t�B�O�\���̂�ݒ肷��ƁA
 * �ݒ�O�̏�ԁi����������Ԃł̃��[�N�̈�T�C�Y�v�Z���G���[�Ƃ��铮��j
 * �ɖ߂����Ƃ��ł��Ȃ��Ȃ�܂��B<br>
 * �i�֐����ēx���s���ăp�����[�^�[���㏑�����邱�Ƃ͉\�ł��B�j<br>
 * \attention
 * �{�֐��œo�^�����������p�R���t�B�O�\���̂́A
 * ASR����������Ԃł̃��[�N�̈�T�C�Y�v�Z�ɂ����g�p����܂���B<br>
 * ASR��������ɂ͖{�֐��ɐݒ肵���p�����[�^�[�ł͂Ȃ��A
 * ���������Ɏw�肳�ꂽ�p�����[�^�[�����[�N�̈�T�C�Y�̌v�Z�Ɏg�p����܂��B<br>
 * �i�{�֐��œo�^����\���̂̃p�����[�^�[�ƁA
 * ASR�̏������Ɏg�p����\���̂̃p�����[�^�[���قȂ�ꍇ�A
 * ���[�N�̈�T�C�Y���s�����A�n���h���̍쐬�Ɏ��s���鋰�ꂪ����܂��B�j<br>
 * <br>
 * �{�֐������s�����ꍇ�ł��A ::criAtomEx_CalculateWorkSizeForDspBusSetting 
 * �֐��͎g�p�ł��܂���B<br>
 * DSP�o�X�ݒ�A�^�b�`�p���[�N�̈�T�C�Y�̌v�Z�ɂ́A
 * ::criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData 
 * �֐����g�p���Ă��������B�j<br>
 * \par ��:
 * \code
 * 	CriAtomExAsrConfig asr_config;
 * 	
 * 	// ���[�N�̈�v�Z�p��ASR�������ݒ�����o�^
 * 	criAtomExAsr_SetDefaultConfig(&asr_config);
 * 	criAtomExAsr_SetConfigForWorkSizeCalculation(&asr_config);
 * 	
 * 	// DSP�o�X�ݒ�A�^�b�`�p���[�N�̈�T�C�Y�̌v�Z
 * 	dsp_work_size = criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData(
 * 		acf_data, acf_data_size, "DspBusSetting_0");
 * 		�F
 * \endcode
 * \sa criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData
 */
void CRIAPI criAtomExAsr_SetConfigForWorkSizeCalculation(const CriAtomExAsrConfig *config);

/*JP
 * \brief ASR�̏�����
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config		ASR�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏��������s���܂��B<br>
 * �{�֐������s���邱�Ƃ�ASR���N����ASR���b�N��1�ǉ�����A�����_�����O���ʂ̏o�͂��J�n���܂��B<br>
 * \par ���l:
 * ASR�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR�������p�R���t�B�O
 * �\���́i ::CriAtomExAsrConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�<br>
 * �i ::criAtomExAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j�ŏ������������s���܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomExAsr_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtomExAsr_Finalize �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa criAtomEx_SetUserAllocator, criAtomExAsr_Finalize, criAtomExAsrRack_Create
 */
void CRIAPI criAtomExAsr_Initialize(
	const CriAtomExAsrConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ASR�̏I��
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏I���������s���܂��B<br>
 * �{�֐������s���邱�ƂŁA�����_�����O���ʂ̏o�͂���~����܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * ASR���������Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iASR���������Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A<br>
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa criAtomEx_SetUserAllocator, criAtomExAsr_Initialize
 */
void CRIAPI criAtomExAsr_Finalize(void);

/*JP
 * \brief �o�X�̃{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	volume		�{�����[���l
 * \par ����:
 * �o�X�̃{�����[����ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�{�����[���A�|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * �{�����[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * �{�����[���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsr_SetBusVolumeByName(const CriChar8* bus_name, CriFloat32 volume);

/*JP
 * \brief �o�X�̃{�����[���̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	volume		�{�����[���l
 * \par ����:
 * �o�X�̃{�����[����ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�{�����[���A�|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * �{�����[���l�͎����l�œ����܂��B<br>
 * �{�����[���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsr_GetBusVolumeByName(const CriChar8* bus_name, CriFloat32 *volume);

/*JP
 * \brief �o�X�̃p�����̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	pan_info	�p�����
 * \par ����:
 * �o�X�̃p������ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�p���̃Z���h��ɗL���ł��B
 * \par ���l:
 * �{�֐��̓f�t�H���g�� ASR ���b�N�� DSP �o�X�ݒ���Q�Ƃ��܂��B<br>
 * �C�ӂ� ASR ���b�N�� DSP �o�X�ݒ���Q�Ƃ���ꍇ�A ::criAtomExAsrRack_SetBusPanInfoByName �֐����g�p���Ă��������B<br>
 * <br>
 * �p�����̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B
 */
void CRIAPI criAtomExAsr_SetBusPanInfoByName(const CriChar8 *bus_name, const CriAtomExAsrBusPanInfo *pan_info);

/*JP
 * \brief �o�X�̃p�����̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[out]	pan_info	�p�����
 * \par ����:
 * �o�X�̃p�������擾���܂��B
 * \par ���l:
 * �{�֐��̓f�t�H���g�� ASR ���b�N�� DSP �o�X�ݒ���Q�Ƃ��܂��B<br>
 * �C�ӂ� ASR ���b�N�� DSP �o�X�ݒ���Q�Ƃ���ꍇ�A ::criAtomExAsrRack_GetBusPanInfoByName �֐����g�p���Ă��������B
 */
void CRIAPI criAtomExAsr_GetBusPanInfoByName(const CriChar8 *bus_name, CriAtomExAsrBusPanInfo *pan_info);

/*JP
 * \brief �o�X�̃��x���s��̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name		�o�X��
 * \param[in]	input_channels	���̓`�����l����
 * \param[in]	output_channels	�o�̓`�����l����
 * \param[in]	matrix			���x���s���1�����ɕ\�������x���l�̔z��
 * \par ����:
 * �o�X�̃��x���s���ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * ���x���}�g���b�N�X�́A�����f�[�^�̊e�`�����l���̉������A�ǂ̃X�s�[�J�[����
 * �ǂ̒��x�̉��ʂŏo�͂��邩���w�肷�邽�߂̎d�g�݂ł��B<br>
 * matrix��[input_channels * output_channels]�̔z��ł��B<br>
 * ���̓`�����l��ch_in����o�̓`�����l��ch_out�ɃZ���h����郌�x����
 * matrix[ch_in * output_channels + ch_out]�ɃZ�b�g���܂��B<br>
 * ���x���s��̃f�t�H���g�l�͒P�ʍs��ł��B<br>
 * <br>
 * ���x���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * ���x���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃��x���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 */
void CRIAPI criAtomExAsr_SetBusMatrixByName(const CriChar8* bus_name, 
	CriSint32 input_channels, CriSint32 output_channels, const CriFloat32 matrix[]);

/*JP
 * \brief �o�X�̃Z���h���x���̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name 		�o�X��
 * \param[in]	sendto_bus_name �Z���h��̃o�X��
 * \param[in]	level			���x���l
 * \par ����:
 * �Z���h��o�X�ɉ����f�[�^�𑗂�ۂ̃��x����ݒ肵�܂��B<br>
 * <br>
 * ���x���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * ���x���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃��x���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * ���x���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsr_SetBusSendLevelByName(
	const CriChar8* bus_name, const CriChar8* sendto_bus_name, CriFloat32 level);

/*JP
 * \brief �G�t�F�N�g���쎞�p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name		�o�X��
 * \param[in]	effect_name		�G�t�F�N�g��
 * \param[in]	parameter_index	�G�t�F�N�g���쎞�p�����[�^�[�C���f�b�N�X
 * \param[in]	parameter_value �G�t�F�N�g���쎞�p�����[�^�[�ݒ�l
 * \par ����:
 * �f�t�H���g��ASR���b�NID���g�p���ăG�t�F�N�g�̓��쎞�p�����[�^�[��ݒ肵�܂��B<br>
 * ���쎞�p�����[�^�[��ݒ肷��ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B<br>
 * �w�肵���o�X�Ɏw�肵��ID�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * �Z�b�g�����p�����[�^�[��criAtomExAsr_UpdateParameter�֐����ĂԂ܂Ŏ��ۂɃG�t�F�N�g�ɔ��f����܂���B<br>
 * �p�����[�^�[�C���f�b�N�X�Ǝ��ۂ̃p�����[�^�[�̑Ή��ɂ��ẮA�e�G�t�F�N�g�̃p�����[�^�[�C���f�b�N�X�i \ref CRIATOMASR_DSP_PARAM �j�����Q�Ɖ������B
 * \sa criAtomEx_AttachDspBusSetting, criAtomExAsr_UpdateEffectParameters
 */
void CRIAPI criAtomExAsr_SetEffectParameter(
	const CriChar8* bus_name, const CriChar8* effect_name, 
	CriUint32 parameter_index, CriFloat32 parameter_value);

/*JP
 * \brief �G�t�F�N�g���쎞�p�����[�^�[�̔��f
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name		�o�X��
 * \param[in]	effect_name		�G�t�F�N�g��
 * \par ����:
 * �f�t�H���g��ASR���b�NID���g�p���ăG�t�F�N�g�̓��쎞�p�����[�^�[�𔽉f���܂��B<br>
 * ���쎞�p�����[�^�[�����ۂɔ��f����ɂ́AcriAtomExAsr_SetEffectParameter �̑��ɂ��{�֐����Ăяo���ĉ������B
 * \sa criAtomEx_AttachDspBusSetting, criAtomExAsr_SetEffectParameter
 */
void CRIAPI criAtomExAsr_UpdateEffectParameters(const CriChar8* bus_name, const CriChar8* effect_name);

/*JP
 * \brief �G�t�F�N�g���쎞�p�����[�^�[�̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]		bus_name		�o�X��
 * \param[in]		effect_name		�G�t�F�N�g��
 * \param[in]		parameter_index	�G�t�F�N�g���쎞�p�����[�^�[�C���f�b�N�X
 * \return �w�肵���p�����[�^�[�C���f�b�N�X�̃G�t�F�N�g���쎞�p�����[�^�[�l��Ԃ��܂��B
 * \par ����:
 * �f�t�H���g��ASR���b�NID���g�p���ăG�t�F�N�g�̓��쎞�p�����[�^�[���擾���܂��B<br>
 * ���쎞�p�����[�^�[���擾����ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B�w�肵���o�X�Ɏw�肵�����O�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * ���쎞�p�����[�^�[�̏ڍׂɂ��ẮA�e�G�t�F�N�g�̃p�����[�^�[�C���f�b�N�X�i \ref CRIATOMASR_DSP_PARAM �j�����Q�Ɖ������B
 * \sa criAtomEx_AttachDspBusSetting
 */
CriFloat32 CRIAPI criAtomExAsr_GetEffectParameter(
	const CriChar8* bus_name, const CriChar8* effect_name, CriUint32 parameter_index);

/*JP
 * \brief �G�t�F�N�g�̃o�C�p�X�ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	effect_name	�G�t�F�N�g��
 * \param[in]	bypass		�o�C�p�X�ݒ�iCRI_TRUE:�o�C�p�X���s��, CRI_FALSE:�o�C�p�X���s��Ȃ��j
 * \par ����:
 * �G�t�F�N�g�̃o�C�p�X�ݒ���s���܂��B<br>
 * �o�C�p�X�ݒ肳�ꂽ�G�t�F�N�g�͉��������̍ہA�X���[�����悤�ɂȂ�܂��B<br>
 * �G�t�F�N�g�̃o�C�p�X�ݒ������ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B�w�肵���o�X�Ɏw�肵��ID�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * \attention
 * �����Đ����Ƀo�C�p�X�ݒ���s���ƃm�C�Y���������邱�Ƃ�����܂��B<br>
 * \sa criAtomEx_AttachDspBusSetting
 */
void CRIAPI criAtomExAsr_SetEffectBypass(
	const CriChar8* bus_name, const CriChar8* effect_name, CriBool bypass);

/*JP
 * \brief ���x������@�\�̒ǉ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	config		���x������@�\�̃R���t�B�O�\����
 * \par ����:
 * �o�X�Ƀ��x������@�\��ǉ����A���x�����菈�����J�n���܂��B<br>
 * �{�֐������s��A ::criAtomExAsr_GetBusAnalyzerInfo �֐������s���邱�ƂŁA
 * RMS���x���i�����j�A�s�[�N���x���i�ő�U���j�A�s�[�N�z�[���h���x����
 * �擾���邱�Ƃ��\�ł��B
 * �����o�X�̃��x�����v������ɂ́A�o�X���Ƃɖ{�֐����Ăяo���K�v������܂��B
 * \par ��:
 * \code
 * 	// ���x��������擾�p�\����
 * 	CriAtomExAsrBusAnalyzerInfo info;
 * 	
 * 	// 0�ԃo�X�i�}�X�^�[�o�X�j�Ƀ��x������@�\�̒ǉ�
 * 	criAtomExAsr_AttachBusAnalyzer(0, NULL);
 * 	
 * 	�@�@�F
 * 	
 * 	// ���x��������̎擾
 * 	criAtomExAsr_GetBusAnalyzerInfo(0, &info);
 * 	
 * 	// �v�����ʂ̕\��
 *  for (i = 0; i < CRIATOMEXASR_MAX_CHANNELS; i++) {
 * 	    printf("[%d] RMS: %1.6f, Peak: %1.6f, Hold: %1.6f", 
 * 	        i, info.rms_levels[i], info.peak_levels[i], info.peak_hold_levels[i]);
 *  }
 * \endcode
 * \attention
 * �{�֐��� ::criAtomEx_AttachDspBusSetting �֐��Ɠ���̃��\�[�X�𑀍삵�܂��B<br>
 * ���̂��߁A����� ::criAtomEx_AttachDspBusSetting �֐������s����ƁA
 * ::criAtomExAsr_GetBusAnalyzerInfo �֐��ɂ����擾���ł��Ȃ��Ȃ�܂��B<br>
 * �{�֐��� ::criAtomEx_AttachDspBusSetting �֐��𕹗p����ۂɂ́A
 * ::criAtomEx_AttachDspBusSetting �֐������s����O�Ɉ�U
 * ::criAtomExAsr_DetachBusAnalyzer �֐��Ń��x������@�\�𖳌������A
 * ::criAtomEx_AttachDspBusSetting �֐����s��ɍēx�{�֐������s���Ă��������B<br>
 * \code
 * 		�F
 * 	// DSP�o�X�ݒ�̕ύX�O�Ɉ�U���x������@�𖳌���
 * 	criAtomExAsr_DetachBusAnalyzer(0);
 * 	
 * 	// DSP�o�X�ݒ�̍X�V
 * 	criAtomEx_AttachDspBusSetting("DspBusSetting_0", NULL, 0);
 * 	
 * 	// ���x������@�̍ăA�^�b�`
 * 	criAtomExAsr_AttachBusAnalyzer(0, NULL);
 * 		�F
 * \endcode
 * \sa criAtomExAsr_GetBusAnalyzerInfo, criAtomExAsr_DetachBusAnalyzer
 */
void CRIAPI criAtomExAsr_AttachBusAnalyzerByName(
	const CriChar8* bus_name, const CriAtomExAsrBusAnalyzerConfig* config);

/*JP
 * \brief ���x������@�\�̍폜
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \par ����:
 * �o�X���烌�x������@�\���폜���܂��B
 * \sa criAtomExAsr_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsr_DetachBusAnalyzerByName(const CriChar8* bus_name);

/*JP
 * \brief ���x�����茋�ʂ̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[out]	info		���x�����茋�ʂ̍\����
 * \par ����:
 * �o�X���烌�x������@�\�̌��ʂ��擾���܂��B
 * \sa criAtomExAsr_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsr_GetBusAnalyzerInfoByName(
	const CriChar8* bus_name, CriAtomExAsrBusAnalyzerInfo *info);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	bus_name	�o�X��
 * \param[in]	pre_func	�G�t�F�N�g�����O�̃t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	post_func	�G�t�F�N�g������̃t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �o�X�ɗ���Ă��� PCM �f�[�^���󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�T�E���h�����_���������������s�����^�C�~���O�ŌĂяo����܂��B<br>
 * �G�t�F�N�g�����O�ƃG�t�F�N�g�������2��ނ̎g�p���Ȃ��ق���NULL�w�肪�\�ł��B<br>
 * \attention
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �g�`�t�B���^�[�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * \sa CriAtomExPlayerFilterCbFunc
 */
void CRIAPI criAtomExAsr_SetBusFilterCallbackByName(const CriChar8* bus_name, 
	CriAtomExAsrBusFilterCbFunc pre_func, CriAtomExAsrBusFilterCbFunc post_func, void *obj);

/*JP
 * \brief �ő�o�X�����擾
 * \ingroup ATOMEXLIB_ASR
 * \return						�ő�o�X��
 * \par ����:
 * ���p�\�ȍő�o�X�����擾���܂��B
 * <br>
 * �f�t�H���g�ݒ�ł� ::CRIATOMEXASR_DEFAULT_NUM_BUSES ��Ԃ��܂��B
 * <br>
 * �ő�o�X����ύX����ɂ́ACriAtomExAsrConfig::num_buses ��ύX����
 * ASR���b�N���쐬���Ă��������B
 * \sa CriAtomExAsrConfig, criAtomExAsr_Create, criAtomExAsr_SetDefaultConfig
 */
CriSint32 CRIAPI criAtomExAsr_GetNumBuses(void);

/*JP
 * \brief ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	afx_interface	���[�U��`�G�t�F�N�g�̃o�[�W�������t���C���^�[�t�F�[�X
 * \return						�o�^�ɐ����������H�iCRI_TRUE:�o�^�ɐ�������, CRI_FALSE:�o�^�Ɏ��s�����j
 * \par ����:
 * ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X��ASR�ɓo�^���܂��B<br>
 * ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X��o�^�����G�t�F�N�g��DSP�o�X�ݒ���A�^�b�`����ۂɎg�p�ł���悤�ɂȂ�܂��B<br>
 * �ȉ��̏����ɊY������ꍇ�́A���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^�Ɏ��s���A�G���[�R�[���o�b�N���Ԃ�܂�:
 *  - ����̃G�t�F�N�g���������[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�����ɓo�^����Ă���
 *  - Atom���g�p���Ă��郆�[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�ƈقȂ�
 *  - ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^������i ::CRIATOMEXASR_MAX_NUM_USER_EFFECT_INTERFACES �j�ɒB����
 * \attention
 * �{�֐���CRI ADX2 Audio Effect Plugin SDK�ō쐬�������[�U��`�G�t�F�N�g��o�^����ꍇ�ɂ̂ݎg�p���ĉ������B<br>
 * ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�́A���[�U��`�G�t�F�N�g���܂�DSP�o�X�ݒ���A�^�b�`����O��<br>
 * �{�֐��ɂ���ēo�^���s���ĉ������B<br>
 * ACF�Ƀf�t�H���gDSP�o�X�ݒ肪���݂���ꍇ�AACF�̓o�^�i ::criAtomEx_RegisterAcfFile, ::criAtomEx_RegisterAcfData �֐��j�ɂ���Ă�DSP�o�X�ݒ肪�A�^�b�`����邽�߁A<br>
 * ���[�U��`�G�t�F�N�g���f�t�H���gDSP�o�X�ݒ�Ɋ܂܂�Ă���ꍇ��ACF��o�^����O�Ƀ��[�U��`�G�t�F�N�g�C���^�[�t�F�[�X��o�^���ĉ������B<br>
 * ��x�o�^���s�����C���^�[�t�F�[�X�̃|�C���^�́ADSP�o�X�ݒ���A�^�b�`���Ă���ԎQ�Ƃ��ꑱ���܂��B<br>
 * Atom���C�u�����g�p���ɃC���^�[�t�F�[�X�̓o�^�������s���ꍇ�́A ::criAtomExAsr_UnregisterEffectInterface ���g�p���ĉ������B
 * \sa criAtomExAsr_UnregisterEffectInterface, criAtomEx_AttachDspBusSetting, criAtomEx_DetachDspBusSetting, criAtomEx_RegisterAcfFile, criAtomEx_RegisterAcfData 
 */
CriBool CRIAPI criAtomExAsr_RegisterEffectInterface(CriAtomExAsrAfxInterfaceWithVersionPtr afx_interface);

/*JP
 * \brief ���[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^����
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	afx_interface	���[�U��`�G�t�F�N�g�̃o�[�W�������t���C���^�[�t�F�[�X
 * \par ����:
 * �G�t�F�N�g�C���^�[�t�F�[�X�̓o�^���������܂��B<br>
 * �o�^�����������G�t�F�N�g��DSP�o�X�ݒ���A�^�b�`����ۂɎg�p�ł��Ȃ��Ȃ�܂��B<br>
 * �o�^�������s���Ă��Ȃ��G�t�F�N�g�C���^�[�t�F�[�X�̓o�^���������邱�Ƃ͂ł��܂���i�G���[�R�[���o�b�N���Ԃ�܂��j�B
 * \attention
 * �{�֐���CRI ADX2 Audio Effect Plugin SDK�ō쐬�������[�U��`�G�t�F�N�g��o�^��������ꍇ�ɂ̂ݎg�p���ĉ������B<br>
 * �o�^���s�������[�U��`�G�t�F�N�g�C���^�[�t�F�[�X��DSP�o�X�ݒ肪�A�^�b�`����Ă���ԎQ�Ƃ��ꑱ���邽�߁A<br>
 * �{�֐��͕K�� ::criAtomEx_DetachDspBusSetting �̌Ăяo���̌�ɍs���ĉ������B<br>
 * Atom���C�u�����̏I�����i::criAtomEx_Finalize �֐��̌Ăяo�����j�ɂ͑S�Ẵ��[�U��`�G�t�F�N�g�C���^�[�t�F�[�X�̓o�^����������܂��B
 * \sa criAtomExAsr_RegisterEffectInterface, criAtomEx_AttachDspBusSetting, criAtomEx_DetachDspBusSetting
 */
void CRIAPI criAtomExAsr_UnregisterEffectInterface(CriAtomExAsrAfxInterfaceWithVersionPtr afx_interface);

/*JP
 * \brief IR���o�[�u�G�t�F�N�g�̕��׌v�����Z�b�g
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR�G�t�F�N�g��IR���o�[�u�̕��׌v�������Z�b�g���܂��B
 * \par ���l:
 * DSP�o�X��IR���o�[�u�G�t�F�N�g���Z�b�g����Ă��Ȃ��Ă��{�֐����Ăяo�����Ƃ͉\�ł����A������������܂���B
 * \sa criAtomExAsr_GetIrReverbPerformanceInfo
 */
void CRIAPI criAtomExAsr_ResetIrReverbPerformanceInfo(void);

/*JP
 * \brief IR���o�[�u�G�t�F�N�g�̕��׌v��
 * \ingroup ATOMEXLIB_ASR
 * \param[out]	info	IR���o�[�u�̕��׌v�����\����
 * \par ����:
 * DSP�o�X���IR���o�[�u�G�t�F�N�g�̕��ׂ����܂Ƃ߂Čv�����܂��B<br>
 * \par ���l:
 * DSP�o�X��IR���o�[�u�G�t�F�N�g���Z�b�g����Ă��Ȃ��Ă��{�֐����Ăяo�����Ƃ͉\�ł����A������������܂���B
 * \attention
 * �v���b�g�t�H�[���ɂ���Čv���������e���قȂ�ꍇ������܂��B<br>
 * �ڂ����͊e�v���b�g�t�H�[����CRI ADX2 �}�j���A���� IR ���o�[�u���Q�Ƃ��Ă��������B
 * \sa criAtomExAsr_ResetIrReverbPerformanceInfo
 */
void CRIAPI criAtomExAsr_GetIrReverbPerformanceInfo(CriAtomExAsrIrReverbPerformanceInfo *info);

/*==========================================================================
 *      CRI AtomEx ASR Rack API
 *=========================================================================*/
/*JP
 * \brief ASR���b�N�쐬�p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config	ASR�������p�R���t�B�O�\����
 * \par ����:
 * ASR���b�N�̍쐬�ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomExAsrRack_Create �֐���ASR�̏��������s���ꍇ�A
 * �{�֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ASR���b�N�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR���b�N�������p�R���t�B�O
 * �\���́i ::CriAtomExAsrRackConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomEx_SetUserAllocator, criAtomExAsrRack_Create
 */
CriSint32 CRIAPI criAtomExAsrRack_CalculateWorkSize(const CriAtomExAsrRackConfig *config);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config		ASR���b�N�쐬�p�R���t�B�O�\����
 * \param[in]	setting		DSP�o�X�ݒ�̖��O
 * \return		CriSint32	�K�v���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��o�X���\�z����̂ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * �{�֐������s����ɂ́A���炩����::criAtomEx_RegisterAcfConfig �֐���ACF����
 * �o�^���Ă����K�v������܂�<br>
 * config�ɂ� ::criAtomExAsrRack_Create �֐��Ɏw�肷����̂Ɠ����\���̂��w�肵�Ă��������B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́ACRI Atom Craft�ō쐬����
 * DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \sa criAtomExAsrRack_AttachDspBusSetting, criAtomEx_RegisterAcfConfig
 */
CriSint32 CRIAPI criAtomExAsrRack_CalculateWorkSizeForDspBusSettingFromConfig(
	const CriAtomExAsrRackConfig *config, const CriChar8 *setting);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	acf_data		ACF�f�[�^
 * \param[in]	acf_data_size	ACF�f�[�^�T�C�Y
 * \param[in]	rack_config		ASR���b�N�쐬�p�R���t�B�O�\����
 * \param[in]	setting			DSP�o�X�ݒ�̖��O
 * \return		CriSint32		�K�v���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��o�X���\�z����̂ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * ::criAtomExAsrRack_CalculateWorkSizeForDspBusSettingFromConfig �֐��ƈႢ�A
 * ��������Ƀ��[�h�ς݂�ACF�f�[�^���g�p���ă��[�N�������T�C�Y�̌v�Z���\�ł��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́ACRI Atom Craft�ō쐬����
 * DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \sa criAtomExAsrRack_AttachDspBusSetting, criAtomEx_RegisterAcfConfig
 */
CriSint32 CRIAPI criAtomExAsrRack_CalculateWorkSizeForDspBusSettingFromAcfDataAndConfig(
	void *acf_data, CriSint32 acf_data_size,
	const CriAtomExAsrRackConfig *rack_config, const CriChar8 *setting);

/*JP
 * \brief ASR���b�N�̍쐬
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	config				ASR�������p�R���t�B�O�\����
 * \param[in]	work				���[�N�̈�
 * \param[in]	work_size			���[�N�̈�T�C�Y
 * \return		CriAtomExAsrRackId 	ASR���b�NID
 * \par ����:
 * ASR���b�N�̍쐬���s���܂��B<br>
 * ASR���b�N�Ƃ̓o�X�̏W���̂̂��ƂŁADSP�o�X�ݒ���A�^�b�`���邱�Ƃ��ł��܂��B<br>
 * �{�֐������s���邱�Ƃ�ASR��ASR���b�N���ǉ�����A�����_�����O���ʂ̏o�͂��J�n���܂��B<br>
 * ���̊֐��Œǉ�����ASR���b�N�͏o�͐��I�����邱�Ƃ��ł��A�v���b�g�t�H�[���l�C�e�B�u��
 * �T�E���h�����_�����AASR��I�����邱�Ƃő���ASR���b�N�ɏo�͂��邱�Ƃ��\�ł��B<br>
 * \par ���l:
 * ::criAtomExAsr_Initialize �֐������s����ƁA�f�t�H���g��ASR���b�N���ǉ�����܂��B<br>
 * criAtomExAsr_*** �֐��̓f�t�H���g��ASR���b�N�𑀍삷��API�ɂȂ�܂��B<br>
 * <br>
 * ASR�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR�������p�R���t�B�O
 * �\���́i ::CriAtomExAsrConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�<br>
 * �i ::criAtomExAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j�ŏ������������s���܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B<br>
 * ASR���b�N�̐����ɐ��������ꍇ�́A�{�֐��͐�������ASR���b�NID��Ԃ��܂��B
 * �����Ɏ��s�����ꍇ�� -1 ��Ԃ��܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomEx_SetUserAllocator, criAtomExAsrRack_Destroy, criAtomExAsrRack_AttachDspBusSetting
 */
CriAtomExAsrRackId CRIAPI criAtomExAsrRack_Create(
	const CriAtomExAsrRackConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ASR���b�N�̔j��
 * \ingroup ATOMEXLIB_ASR
 * \par ����:
 * ASR���b�N�̔j�����s���܂��B<br>
 * �{�֐������s���邱�ƂŁA�����_�����O���ʂ̏o�͂���~����܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * ASR���b�N�쐬���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iASR���b�N�쐬���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A<br>
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa criAtomEx_SetUserAllocator, criAtomExAsrRack_Create
 */
void CRIAPI criAtomExAsrRack_Destroy(CriAtomExAsrRackId rack_id);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`�p���[�N�T�C�Y�̌v�Z
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	setting		DSP�o�X�ݒ�̖��O
 * \return		CriSint32	�K�v���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��o�X���\�z����̂ɕK�v�ȃ��[�N�̈�T�C�Y���v�Z���܂��B<br>
 * �{�֐������s����ɂ́A���炩����::criAtomEx_RegisterAcfConfig �֐���ACF����
 * �o�^���Ă����K�v������܂�<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́ACRI Atom Craft�ō쐬����
 * DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \sa criAtomExAsrRack_AttachDspBusSetting, criAtomEx_RegisterAcfConfig
 */
CriSint32 CRIAPI criAtomExAsrRack_CalculateWorkSizeForDspBusSetting(
	CriAtomExAsrRackId rack_id, const CriChar8 *setting);

/*JP
 * \brief DSP�o�X�ݒ�̃A�^�b�`
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	setting		DSP�o�X�ݒ�̖��O
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * DSP�o�X�ݒ肩��o�X���\�z����ASR���b�N�ɃA�^�b�`���܂��B<br>
 * �{�֐������s����ɂ́A���炩����::criAtomEx_RegisterAcfConfig �֐���ACF����
 * �o�^���Ă����K�v������܂�<br>
 * \par ���l:
 * DSP�o�X�ݒ�̃A�^�b�`�ɕK�v�ȃ��[�N�������̃T�C�Y�́A
 * CRI Atom Craft�ō쐬����DSP�o�X�ݒ�̓��e�ɂ���ĕω����܂��B<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa criAtomExAsrRack_DetachDspBusSetting, criAtomEx_RegisterAcfConfig
 */
void CRIAPI criAtomExAsrRack_AttachDspBusSetting(CriAtomExAsrRackId rack_id,
	const CriChar8 *setting, void *work, CriSint32 work_size);

/*JP
 * \brief DSP�o�X�ݒ�̃f�^�b�`
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \par ����:
 * DSP�o�X�ݒ��ASR���b�N����f�^�b�`���܂��B<br>
 * ::criAtomEx_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * DSP�o�X�ݒ�A�^�b�`���Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iDSP�o�X�ݒ�A�^�b�`���Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * \sa criAtomExAsrRack_AttachDspBusSetting
 */
void CRIAPI criAtomExAsrRack_DetachDspBusSetting(CriAtomExAsrRackId rack_id);

/*JP
 * \brief DSP�o�X�X�i�b�v�V���b�g�̓K�p
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	snapshot_name	�X�i�b�v�V���b�g��
 * \param[in]	time_ms			���ԁi�~���b�j
 * \par ����:
 * DSP�o�X�X�i�b�v�V���b�g��K�p���܂��B<br>
 * �{�֐����Ăяo���ƁA�X�i�b�v�V���b�g�Őݒ肵���p�����[�^�[�� time_ms �|���ĕω����܂��B<br>
 * ���� snapshot_name �� CRI_NULL ���w�肷��ƁA����DSP�o�X�ݒ�̏�ԁi�X�i�b�v�V���b�g���K�p����Ă��Ȃ���ԁj�ɖ߂�܂��B<br>
 * \sa criAtomExAsrRack_AttachDspBusSetting
 */
void CRIAPI criAtomExAsrRack_ApplyDspBusSnapshot(CriAtomExAsrRackId rack_id,
	const CriChar8 *snapshot_name, CriSint32 time_ms);

/*JP
 * \brief �K�p����DSP�o�X�X�i�b�v�V���b�g���̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \par ����:
 * ASR���b�NID���w�肵�ēK�p����DSP�o�X�X�i�b�v�V���b�g�����擾���܂��B
 * �X�i�b�v�V���b�g���K�p����Ă��Ȃ��ꍇ��CRI_NULL���Ԃ�܂��B
 * \sa criAtomExAsrRack_ApplyDspBusSnapshot
 */
const CriChar8* CRIAPI criAtomExAsrRack_GetAppliedDspBusSnapshotName(CriAtomExAsrRackId rack_id);

/*JP
 * \brief �o�X�̃{�����[���̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[in]	volume		�{�����[���l
 * \par ����:
 * �o�X�̃{�����[����ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�{�����[���A�|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * �{�����[���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * �{�����[���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃{�����[���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * �{�����[���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsrRack_SetBusVolumeByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriFloat32 volume);

/*JP
 * \brief �o�X�̃{�����[���̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[in]	volume		�{�����[���l
 * \par ����:
 * �o�X�̃{�����[����ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�{�����[���A�|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * �{�����[���l�͎����l�œ����܂��B<br>
 * �{�����[���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsrRack_GetBusVolumeByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriFloat32* volume);

/*JP
 * \brief �o�X�̃p�����̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR ���b�N ID
 * \param[in]	bus_name	�o�X��
 * \param[in]	pan_info	�p�����
 * \par ����:
 * �o�X�̃p������ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * �p�����̃f�t�H���g�l�� CRI Atom Craft �Őݒ肵���l�ł��B
 */
void CRIAPI criAtomExAsrRack_SetBusPanInfoByName(CriAtomExAsrRackId rack_id, const CriChar8 *bus_name,
	const CriAtomExAsrBusPanInfo *pan_info);

/*JP
 * \brief �o�X�̃p�����̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR ���b�N ID
 * \param[in]	bus_name	�o�X��
 * \param[out]	pan_info	�p�����
 * \par ����:
 * �o�X�̃p�������擾���܂��B
 */
void CRIAPI criAtomExAsrRack_GetBusPanInfoByName(CriAtomExAsrRackId rack_id, const CriChar8 *bus_name,
	CriAtomExAsrBusPanInfo *pan_info);

/*JP
 * \brief �o�X�̃��x���s��̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \param[in]	bus_name		�o�X��
 * \param[in]	input_channels	���̓`�����l����
 * \param[in]	output_channels	�o�̓`�����l����
 * \param[in]	matrix			���x���s���1�����ɕ\�������x���l�̔z��
 * \par ����:
 * �o�X�̃��x���s���ݒ肵�܂��B<br>
 * �Z���h�^�C�v���|�X�g�p���̃Z���h��ɗL���ł��B<br>
 * <br>
 * ���x���}�g���b�N�X�́A�����f�[�^�̊e�`�����l���̉������A�ǂ̃X�s�[�J�[����
 * �ǂ̒��x�̉��ʂŏo�͂��邩���w�肷�邽�߂̎d�g�݂ł��B<br>
 * matrix��[input_channels * output_channels]�̔z��ł��B<br>
 * ���̓`�����l��ch_in����o�̓`�����l��ch_out�ɃZ���h����郌�x����
 * matrix[ch_in * output_channels + ch_out]�ɃZ�b�g���܂��B<br>
 * ���x���s��̃f�t�H���g�l�͒P�ʍs��ł��B<br>
 * <br>
 * ���x���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * ���x���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃��x���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 */
void CRIAPI criAtomExAsrRack_SetBusMatrixByName(
	CriAtomExAsrRackId rack_id, const CriChar8* bus_name, CriSint32 input_channels, 
	CriSint32 output_channels, const CriFloat32 matrix[]);

/*JP
 * \brief �o�X�̃Z���h���x���̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \param[in]	bus_name		�o�X��
 * \param[in]	sendto_bus_name	�Z���h��̃o�X��
 * \param[in]	level			���x���l
 * \par ����:
 * �Z���h��o�X�ɉ����f�[�^�𑗂�ۂ̃��x����ݒ肵�܂��B<br>
 * <br>
 * ���x���l�ɂ́A0.0f�`1.0f�͈̔͂Ŏ����l���w�肵�܂��B<br>
 * ���x���l�͉����f�[�^�̐U���ɑ΂���{���ł��i�P�ʂ̓f�V�x���ł͂���܂���j�B<br>
 * �Ⴆ�΁A1.0f���w�肵���ꍇ�A�����͂��̂܂܂̃��x���ŏo�͂���܂��B<br>
 * 0.5f���w�肵���ꍇ�A�����g�`�̐U���𔼕��ɂ����f�[�^�Ɠ������ʁi-6dB�j��
 * �������o�͂���܂��B<br>
 * 0.0f���w�肵���ꍇ�A�����̓~���[�g����܂��i�����ɂȂ�܂��j�B<br>
 * ���x���̃f�t�H���g�l��CRI Atom Craft�Őݒ肵���l�ł��B<br>
 */
void CRIAPI criAtomExAsrRack_SetBusSendLevelByName(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, const CriChar8* sendto_bus_name, CriFloat32 level);

/*JP
 * \brief �G�t�F�N�g���쎞�p�����[�^�[�̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \param[in]	bus_name		�o�X��
 * \param[in]	effect_name		�G�t�F�N�g��
 * \param[in]	parameter_index	�G�t�F�N�g���쎞�p�����[�^�[�C���f�b�N�X
 * \param[in]	parameter_value �G�t�F�N�g�p�����[�^�[�ݒ�l
 * \par ����:
 * �G�t�F�N�g�̓��쎞�p�����[�^�[��ݒ肵�܂��B<br>
 * �G�t�F�N�g�p�����[�^�[��ݒ肷��ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B�w�肵���o�X�Ɏw�肵�����O�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * �܂��A
 * �G�t�F�N�g�̃p�����[�^�[�́A�e�G�t�F�N�g�̃p�����[�^�[�C���f�b�N�X�i \ref CRIATOMASR_DSP_PARAM �j�����Q�Ɖ������B
 * \sa criAtomEx_AttachDspBusSetting, criAtomExAsrRack_UpdateEffectParameters
 */
void CRIAPI criAtomExAsrRack_SetEffectParameter(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, const CriChar8* effect_name, 
	const CriUint32 parameter_index, const CriFloat32 parameter_value);

/*JP
 * \brief �G�t�F�N�g�̓��쎞�p�����[�^�[�̔��f
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \param[in]	bus_name		�o�X��
 * \param[in]	effect_name		�G�t�F�N�g��
 * \par ����:
 * �G�t�F�N�g�̓��쎞�p�����[�^�[�𔽉f���܂��B<br>
 * ���쎞�p�����[�^�[�����ۂɔ��f����ɂ́AcriAtomExAsrRack_SetEffectParameter �̑��ɂ��{�֐����Ăяo���ĉ������B
 * \sa criAtomEx_AttachDspBusSetting, criAtomExAsrRack_SetEffectParameter
 */
void CRIAPI criAtomExAsrRack_UpdateEffectParameters(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, const CriChar8* effect_name);

/*JP
 * \brief �G�t�F�N�g�̓��쎞�p�����[�^�[�̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]		rack_id			ASR���b�NID
 * \param[in]		bus_name		�o�X��
 * \param[in]		effect_name		�G�t�F�N�g��
 * \param[in]		parameter_index	�G�t�F�N�g�̓��쎞�p�����[�^�[�C���f�b�N�X
 * \return �w�肵���p�����[�^�[�C���f�b�N�X�l�̃G�t�F�N�g�p�����[�^�[�l��Ԃ��܂��B
 * \par ����:
 * �G�t�F�N�g�̓��쎞�p�����[�^�[���擾���܂��B<br>
 * ���쎞�p�����[�^�[���擾����ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B�w�肵���o�X�Ɏw�肵�����O�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * �G�t�F�N�g�̓��쎞�p�����[�^�[�̏ڍׂ́A�e�G�t�F�N�g�̃p�����[�^�[�C���f�b�N�X�i \ref CRIATOMASR_DSP_PARAM �j�����Q�Ɖ������B
 * \sa criAtomEx_AttachDspBusSetting
 */
CriFloat32 CRIAPI criAtomExAsrRack_GetEffectParameter(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, const CriChar8* effect_name, 
	const CriUint32 parameter_index);

/*JP
 * \brief �G�t�F�N�g�̃o�C�p�X�ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[in]	effect_name	�G�t�F�N�g��
 * \param[in]	bypass		�o�C�p�X�ݒ�iCRI_TRUE:�o�C�p�X���s��, CRI_FALSE:�o�C�p�X���s��Ȃ��j
 * \par ����:
 * �G�t�F�N�g�̃o�C�p�X�ݒ���s���܂��B<br>
 * �o�C�p�X�ݒ肳�ꂽ�G�t�F�N�g�͉��������̍ہA�X���[�����悤�ɂȂ�܂��B<br>
 * �G�t�F�N�g�̃o�C�p�X�ݒ������ۂ́A�{�֐��Ăяo���O�ɂ��炩����
 * ::criAtomEx_AttachDspBusSetting �֐��Ńo�X���\�z����Ă���K�v������܂��B<br>
 * �ǂ̃o�X�ɂǂ̃G�t�F�N�g�����݂��邩�́A�A�^�b�`����DSP�o�X�ݒ�Ɉˑ����܂��B�w�肵���o�X�Ɏw�肵�����O�̃G�t�F�N�g�����݂��Ȃ��ꍇ�A�֐��͎��s���܂��B<br>
 * \attention
 * �����Đ����Ƀo�C�p�X�ݒ���s���ƃm�C�Y���������邱�Ƃ�����܂��B<br>
 * \sa criAtomEx_AttachDspBusSetting
 */
void CRIAPI criAtomExAsrRack_SetEffectBypass(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, const CriChar8* effect_name, const CriBool bypass);

/*JP
 * \brief ���x������@�\�̒ǉ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[in]	config		���x������@�\�̃R���t�B�O�\����
 * \par ����:
 * �o�X�Ƀ��x������@�\��ǉ����A���x�����菈�����J�n���܂��B<br>
 * �{�֐������s��A ::criAtomExAsrRack_GetBusAnalyzerInfo �֐������s���邱�ƂŁA
 * RMS���x���i�����j�A�s�[�N���x���i�ő�U���j�A�s�[�N�z�[���h���x����
 * �擾���邱�Ƃ��\�ł��B
 * �����o�X�̃��x�����v������ɂ́A�o�X���Ƃɖ{�֐����Ăяo���K�v������܂��B
 * \attention
 * �{�֐��� ::criAtomExAsrRack_AttachDspBusSetting �֐��Ɠ���̃��\�[�X�𑀍삵�܂��B<br>
 * ���̂��߁A����� ::criAtomExAsrRack_AttachDspBusSetting �֐������s����ƁA
 * ::criAtomExAsrRack_GetBusAnalyzerInfo �֐��ɂ����擾���ł��Ȃ��Ȃ�܂��B<br>
 * �{�֐��� ::criAtomExAsrRack_AttachDspBusSetting �֐��𕹗p����ۂɂ́A
 * ::criAtomExAsrRack_AttachDspBusSetting �֐������s����O�Ɉ�U
 * ::criAtomExAsrRack_DetachBusAnalyzer �֐��Ń��x������@�\�𖳌������A
 * ::criAtomExAsrRack_AttachDspBusSetting �֐����s��ɍēx�{�֐������s���Ă��������B<br>
 * \sa criAtomExAsrRack_GetBusAnalyzerInfo, criAtomExAsrRack_DetachBusAnalyzer
 */
void CRIAPI criAtomExAsrRack_AttachBusAnalyzerByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, const CriAtomExAsrBusAnalyzerConfig* config);

/*JP
 * \brief ���x������@�\�̍폜
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \par ����:
 * �o�X���烌�x������@�\���폜���܂��B
 * \sa criAtomExAsrRack_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsrRack_DetachBusAnalyzerByName(
	CriAtomExAsrRackId rack_id, const CriChar8* bus_name);

/*JP
 * \brief ���x�����茋�ʂ̎擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[out]	info		���x�����茋�ʂ̍\����
 * \par ����:
 * �o�X���烌�x������@�\�̌��ʂ��擾���܂��B
 * \sa criAtomExAsrRack_AttachBusAnalyzer
 */
void CRIAPI criAtomExAsrRack_GetBusAnalyzerInfoByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriAtomExAsrBusAnalyzerInfo *info);

/*JP
 * \brief �g�`�t�B���^�[�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id		ASR���b�NID
 * \param[in]	bus_name	�o�X��
 * \param[in]	pre_func	�G�t�F�N�g�����O�̃t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	post_func	�G�t�F�N�g������̃t�B���^�[�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �o�X�ɗ���Ă��� PCM �f�[�^���󂯎��R�[���o�b�N�֐���o�^���܂��B<br>
 * �o�^���ꂽ�R�[���o�b�N�֐��́A�T�E���h�����_���������������s�����^�C�~���O�ŌĂяo����܂��B<br>
 * �G�t�F�N�g�����O�ƃG�t�F�N�g�������2��ނ̎g�p���Ȃ��ق���NULL�w�肪�\�ł��B<br>
 * \attention
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���Atom���C�u�������̃T�[�o�[����������s����܂��B<br>
 * ���̂��߁A�T�[�o�[�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �g�`�t�B���^�[�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * \sa CriAtomExPlayerFilterCbFunc
 */
void CRIAPI criAtomExAsrRack_SetBusFilterCallbackByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriAtomExAsrBusFilterCbFunc pre_func, 
	CriAtomExAsrBusFilterCbFunc post_func, void *obj);

/*JP
 * \brief ���ASR���b�NID�̐ݒ�
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \param[in]	alt_rack_id		���ASR���b�NID
 * \par ����:
 * �w�肵��ID��ASR���b�N�����݂��Ȃ��ꍇ�ɁA����ɂȂ�ASR���b�N��ID��ݒ肵�܂��B<br>
 * �i rack_id ��ASR���b�N�����݂��Ȃ��ꍇ�ɁA���̉����� alt_rack_id ��ASR���b�N�o�R�ŏo�͂��܂��B�j<br>
 * <br>
 * �f�t�H���g�ݒ�� ::CRIATOMEXASR_RACK_DEFAULT_ID
 * �i�w�肵��ID��ASR���b�N���Ȃ���΃f�t�H���gASR����o�͂���j�ł��B<br>
 * \par ���l:
 * ���݂��Ȃ�ASR���b�N�ւ̏o�͂��G���[�Ƃ��Ĉ��������ꍇ�A
 * alt_rack_id �� rack_id �Ɠ����l��ݒ肵�Ă��������B<br>
 */
void CRIAPI criAtomExAsrRack_SetAlternateRackId(
	CriAtomExAsrRackId rack_id, CriAtomExAsrRackId alt_rack_id);

/*JP
 * \brief �ő�o�X�����擾
 * \ingroup ATOMEXLIB_ASR
 * \param[in]	rack_id			ASR���b�NID
 * \return						�ő�o�X��
 * \par ����:
 * �w�肵��ID��ASR���b�N�ŗ��p�\�ȍő�o�X�����擾���܂��B
 * <br>
 * �f�t�H���g�ݒ�ł� ::CRIATOMEXASR_DEFAULT_NUM_BUSES ��Ԃ��܂��B
 * <br>
 * �ő�o�X����ύX����ɂ́ACriAtomExAsrRackConfig::num_buses ��ύX����
 * ASR���b�N���쐬���Ă��������B
 * \sa CriAtomExAsrRackConfig, criAtomExAsrRack_Create, criAtomExAsrRack_SetDefaultConfig
 */
CriSint32 CRIAPI criAtomExAsrRack_GetNumBuses(CriAtomExAsrRackId rack_id);

/*JP
* \brief PCM�f�[�^�̎擾
* \ingroup ATOMLIB_PC
* \param[in]	output_channels		�o�̓o�b�t�@�[�̃`�����l����
* \param[in]	output_samples		�o�̓o�b�t�@�[�Ɋi�[�\�ȃT���v����
* \param[out]	output_buffer		�o�̓o�b�t�@�[
* \return		CriSint32			�擾�ł����T���v����
* \retval		0�ȏ�				�擾�ł����T���v����
* \retval		���l				�G���[������
* \par ����:
* Atom���C�u�����̏o��PCM�f�[�^���擾���܂��B<br>
* <br>
* �{�֐����g�p����ɂ́A���O�� ::criAtomEx_InitializeForUserPcmOutput
* �֐����g�p���ă��C�u���������������Ă����K�v������܂��B<br>
* \attention
* �{�֐��̌Ăяo���́A�Ɨ������X���b�h��Œ���I�ɍs���K�v������܂��B<br>
* ����AAtom���C�u������API�ɂ́A
* PCM�f�[�^���o�͂����܂ŏ�����Ԃ��Ȃ����̂����������݂��܂��B<br>
* �i�{�C�X�v�[���̔j���������B�j<br>
* �����������֐��Ɩ{�֐��Ƃ𓯈�X���b�h��ŏ��ԂɌĂяo���ƁA
* ���YAPI��PCM�f�[�^�̏o�͂��i���ɑ҂�������`�ɂȂ�A
* ���������A���Ȃ��Ȃ�\��������܂��B<br>
* \sa criAtomEx_InitializeForUserPcmOutput
*/
CriSint32 CRIAPI criAtomExAsr_GetPcmDataFloat32(
	CriSint32 output_channels, CriSint32 output_samples, CriFloat32 *output_buffer[]);

/*JP
* \brief PCM�f�[�^�c�ʂ̎擾
* \ingroup ATOMLIB_PC
* \return CriSint32 PCM�f�[�^�c�ʁi�T���v�����P�ʁj
* \par ����:
* ::criAtomExAsr_GetPcmDataFloat32 �֐��Ŏ擾�\�ȃT���v������Ԃ��܂��B<br>
* \sa criAtomExAsr_GetPcmDataFloat32
*/
CriSint32 CRIAPI criAtomExAsr_GetNumBufferedSamples(void);

/*JP
* \brief PCM�o�b�t�@�[�T�C�Y�̎w��
* \ingroup ATOMLIB_PC
* \param[in]	num_samples	PCM�o�b�t�@�[�T�C�Y�i�T���v�����P�ʁj
* \par ����:
* Atom���C�u��������PCM�f�[�^�̕ۑ��Ɏg�p����o�b�t�@�[�̃T�C�Y���w�肵�܂��B<br>
* �i�T�C�Y�̓T���v�����P�ʂŎw�肵�܂��B�j<br>
* <br>
* �o�b�t�@�[�T�C�Y�� 0 ���w�肵���ꍇ�A2V���̃o�b�t�@�[���쐬����܂��B<br>
* \par ���l:
* ���[�UPCM�o�͕�����Atom���C�u�����������������ꍇ�A
* Atom���C�u������ASR�̏o�͌��ʂ����C�u�������̃o�b�t�@�[�iPCM�o�b�t�@�[�j�ɕێ����܂��B<br>
* �f�t�H���g��Ԃł́APCM�o�b�t�@�[�̃T�C�Y�̓��C�u�������������̃p�����[�^�[�ɉ����Ď����I�Ɍ��肳��܂����A
* �{�֐������s���邱�ƂŁAPCM�o�b�t�@�[�̃T�C�Y��C�ӂ̃T�C�Y�ɕύX���邱�Ƃ��\�ł��B<br>
* \attention
* PCM�o�b�t�@�[�̊m�ۂ� ::criAtomEx_InitializeForUserPcmOutput �֐����ōs���܂��B<br>
* ���̂��߁A�{�֐��� ::criAtomEx_InitializeForUserPcmOutput
* �֐�������Ɏ��s����K�v������܂��B<br>
* <br>
* PCM�o�b�t�@�[�ɒ~������PCM�f�[�^�̃T���v�������A
* ���[�U��PCM�f�[�^���擾����Ԋu��菭�Ȃ��ꍇ�A
* ���r�؂ꓙ�̖�肪��������\��������܂��B<br>
* �t�ɁAPCM�o�b�t�@�[�̃T�C�Y���傫������ꍇ�A
* �����J�n����T�E���h�o�͂܂ł̒x�����傫���Ȃ�\��������܂��B<br>
* <br>
* PC���ł́APCM�o�b�t�@�[�T�C�Y�������������ꍇ�ɍĐ����������s���邩�ǂ������A
* �T�E���h�f�o�C�X�̐��\�ɂ����E����܂��B<br>
* �����̊��ŉ��r�؂�Ȃ��Đ����s�������ꍇ�ɂ́A
* PCM�o�b�t�@�[�T�C�Y�ɂ�����x�傫�߂̒l���w�肷�邩�A
* �܂��͉\�Ȍ���Z���Ԋu�� ::criAtomExAsr_GetPcmDataFloat32 �֐������s���Ă��������B<br>
*/
void CRIAPI criAtomExAsr_SetPcmBufferSize(CriSint32 num_samples);

/*JP
* \brief ASR���b�N��PCM�f�[�^�̎擾
* \ingroup ATOMLIB_PC
* \param[in]	rack_id			ASR���b�NID
* \param[in]	output_channels		�o�̓o�b�t�@�[�̃`�����l����
* \param[in]	output_samples		�o�̓o�b�t�@�[�Ɋi�[�\�ȃT���v����
* \param[out]	output_buffer		�o�̓o�b�t�@�[
* \return		CriSint32			�擾�ł����T���v����
* \retval		0�ȏ�				�擾�ł����T���v����
* \retval		���l				�G���[������
* \par ����:
* ASR���b�N�̏o��PCM�f�[�^���擾���܂��B<br>
* <br>
* �{�֐����g�p����ɂ́A���O�� ::criAtomEx_InitializeForUserPcmOutput
* �֐����g�p���ă��C�u���������������Ă����K�v������܂��B<br>
* \attention
* �{�֐��̌Ăяo���́A�Ɨ������X���b�h��Œ���I�ɍs���K�v������܂��B<br>
* ����AAtom���C�u������API�ɂ́A
* PCM�f�[�^���o�͂����܂ŏ�����Ԃ��Ȃ����̂����������݂��܂��B<br>
* �i�{�C�X�v�[���̔j���������B�j<br>
* �����������֐��Ɩ{�֐��Ƃ𓯈�X���b�h��ŏ��ԂɌĂяo���ƁA
* ���YAPI��PCM�f�[�^�̏o�͂��i���ɑ҂�������`�ɂȂ�A
* ���������A���Ȃ��Ȃ�\��������܂��B<br>
* \sa criAtomEx_InitializeForUserPcmOutput
*/
CriSint32 CRIAPI criAtomExAsrRack_GetPcmDataFloat32(CriAtomExAsrRackId rack_id,
	CriSint32 output_channels, CriSint32 output_samples, CriFloat32 *output_buffer[]);

/*JP
* \brief ASR���b�N��PCM�f�[�^�c�ʂ̎擾
* \ingroup ATOMLIB_PC
* \return CriSint32 PCM�f�[�^�c�ʁi�T���v�����P�ʁj
* \par ����:
* ::criAtomExAsrRack_GetPcmDataFloat32 �֐��Ŏ擾�\�ȃT���v������Ԃ��܂��B<br>
* \sa criAtomExAsrRack_GetPcmDataFloat32
*/
CriSint32 CRIAPI criAtomExAsrRack_GetNumBufferedSamples(CriAtomExAsrRackId rack_id);

/*JP
* \brief �w�肵���o�X�̐U����͊�̉�͌��ʎ擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_no				�o�X�ԍ�
* \param[out]	rms					�U�����ʏo�̓o�b�t�@�[
* \param[in]	num_channels		�U�����ʏo�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �U����͊�̌��݂̉�͌��ʁiRMS�l�j���擾���܂��B
* �w�肵���o�X�ɐU����͊킪�Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetAmplitudeAnalyzerRms(CriAtomExAsrRackId rack_id,
	CriSint32 bus_no, CriFloat32* rms, CriUint32 num_channels);

/*JP
* \brief �w�肵���o�X�̐U����͊�̉�͌��ʎ擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_name			�o�X��
* \param[out]	rms					�U�����ʏo�̓o�b�t�@�[
* \param[in]	num_channels		�U�����ʏo�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �U����͊�̌��݂̉�͌��ʁiRMS�l�j���擾���܂��B<br>
* �w�肵���o�X�ɐU����͊킪�Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetAmplitudeAnalyzerRmsByName(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, CriFloat32* rms, CriUint32 num_channels);

/*JP
* \brief �w�肵���o�X�̃R���v���b�T�[�̐U����Z�l�擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_no				�o�X�ԍ�
* \param[out]	gain				�U����Z�l�o�̓o�b�t�@�[
* \param[in]	num_channels		�U����Z�l�o�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �R���v���b�T�[�����͔g�`�ɏ�Z����l���擾���܂��B<br>
* �w�肵���o�X�ɃR���v���b�T�[���Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetCompressorGain(CriAtomExAsrRackId rack_id,
	CriSint32 bus_no, CriFloat32* gain, CriUint32 num_channels);

/*JP
* \brief �w�肵���o�X�̃R���v���b�T�[�̐U����Z�l�擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_name			�o�X��
* \param[out]	gain				�U����Z�l�o�̓o�b�t�@�[
* \param[in]	num_channels		�U����Z�l�o�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �R���v���b�T�[�����͔g�`�ɏ�Z����l���擾���܂��B<br>
* �w�肵���o�X�ɃR���v���b�T�[���Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetCompressorGainByName(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, CriFloat32* gain, CriUint32 num_channels);

/*JP
* \brief �w�肵���o�X�̃R���v���b�T�[�̐U���l�擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_no				�o�X�ԍ�
* \param[out]	rms					�U����Z�l�o�̓o�b�t�@�[
* \param[in]	num_channels		�U����Z�l�o�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �R���v���b�T�[�ɓK�p����Ă���U���l���擾���܂��B<br>
* �w�肵���o�X�ɃR���v���b�T�[���Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetCompressorRms(CriAtomExAsrRackId rack_id,
	CriSint32 bus_no, CriFloat32* rms, CriUint32 num_channels);

/*JP
* \brief �w�肵���o�X�̃R���v���b�T�[�̐U���l�擾
* \param[in]	rack_id				ASR���b�NID
* \param[in]	bus_name			�o�X��
* \param[out]	rms					�U���l�o�̓o�b�t�@�[
* \param[in]	num_channels		�U���l�o�̓o�b�t�@�[�̃`�����l����
* \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
* \par ����:
* �R���v���b�T�[�ɓK�p����Ă���U���l���擾���܂��B<br>
* �w�肵���o�X�ɃR���v���b�T�[���Ȃ��ꍇ��A�w�肵���`�����l������ASR�o�X���������ꍇ�A�擾�Ɏ��s���܂��B
*/
CriBool CRIAPI criAtomExAsrRack_GetCompressorRmsByName(CriAtomExAsrRackId rack_id,
	const CriChar8* bus_name, CriFloat32* rms, CriUint32 num_channels);

/*JP
 * \brief �w�肵��ASR���b�N��AISAC�R���g���[���ɒl��K�p�i�R���g���[��ID�w��j
 * \param[in]	rack_id				ASR���b�NID
 * \param[in]	control_id			AISAC�R���g���[��ID
 * \param[in]	control_value		AISAC�R���g���[���l
 * \return	CriBool �K�p�ɐ����������H�iCRI_TRUE:�K�p�ɐ�������, CRI_FALSE:�K�p�Ɏ��s�����j
 * \par ����:
 * �w�肵��ASR���b�N�ɃA�^�b�`����Ă���DSP�o�X�ݒ��AISAC�R���g���[���ɒl���Z�b�g���܂��B<br>
 * ���s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ���܂��B
 */
CriBool CRIAPI criAtomExAsrRack_SetAisacControlById(CriAtomExAsrRackId rack_id,
	CriAtomExAisacControlId control_id, CriFloat32 control_value);

/*JP
 * \brief �w�肵��ASR���b�N��AISAC�R���g���[���ɒl��K�p�i�R���g���[�����w��j
 * \param[in]	rack_id				ASR���b�NID
 * \param[in]	control_name		AISAC�R���g���[����
 * \param[in]	control_value		AISAC�R���g���[���l
 * \return	CriBool �K�p�ɐ����������H�iCRI_TRUE:�K�p�ɐ�������, CRI_FALSE:�K�p�Ɏ��s�����j
 * \par ����:
 * �w�肵��ASR���b�N�ɃA�^�b�`����Ă���DSP�o�X�ݒ��AISAC�R���g���[���ɒl���Z�b�g���܂��B<br>
 * ���s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ���܂��B
 */
CriBool CRIAPI criAtomExAsrRack_SetAisacControlByName(CriAtomExAsrRackId rack_id,
	const CriChar8* control_name, CriFloat32 control_value);

/*JP
 * \brief �w�肵��ASR���b�N��AISAC�R���g���[���ɒl���擾�i�R���g���[��ID�w��j
 * \param[in]	rack_id				ASR���b�NID
 * \param[in]	control_id			AISAC�R���g���[��ID
 * \param[out]	control_value		AISAC�R���g���[���l
 * \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
 * \par ����:
 * �w�肵��ASR���b�N�ɃA�^�b�`����Ă���DSP�o�X�ݒ��AISAC�R���g���[���ɒl���擾���܂��B<br>
 * ���s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ���܂��B
 */
CriBool CRIAPI criAtomExAsrRack_GetAisacControlById(CriAtomExAsrRackId rack_id,
	CriAtomExAisacControlId control_id, CriFloat32 *control_value);

/*JP
 * \brief �w�肵��ASR���b�N��AISAC�R���g���[���ɒl���擾�i�R���g���[�����w��j
 * \param[in]	rack_id				ASR���b�NID
 * \param[in]	control_name		AISAC�R���g���[����
 * \param[out]	control_value		AISAC�R���g���[���l
 * \return	CriBool �擾�ɐ����������H�iCRI_TRUE:�擾�ɐ�������, CRI_FALSE:�擾�Ɏ��s�����j
 * \par ����:
 * �w�肵��ASR���b�N�ɃA�^�b�`����Ă���DSP�o�X�ݒ��AISAC�R���g���[���ɒl���擾���܂��B<br>
 * ���s�����ꍇ�A�G���[�R�[���o�b�N���Ԃ���܂��B
 */
CriBool CRIAPI criAtomExAsrRack_GetAisacControlByName(CriAtomExAsrRackId rack_id,
	const CriChar8* control_name, CriFloat32 *control_value);
/*==========================================================================
 *      CRI Atom ASR API
 *=========================================================================*/
/*JP
 * \brief ASR�������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMLIB_ASR
 * \param[in]	config	ASR�������p�R���t�B�O�\����
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏������ɕK�v�ȃ��[�N�̈�̃T�C�Y���擾���܂��B<br>
 * ::criAtom_SetUserAllocator �}�N���ɂ��A���P�[�^�[�o�^���s�킸��
 * ::criAtomAsr_Initialize �֐���ASR�̏��������s���ꍇ�A
 * �{�֐��Ōv�Z�����T�C�Y���̃����������[�N�̈�Ƃ��ēn���K�v������܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ASR�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR�������p�R���t�B�O
 * �\���́i ::CriAtomAsrConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtom_SetUserAllocator, criAtomAsr_Initialize
 */
CriSint32 CRIAPI criAtomAsr_CalculateWorkSize(const CriAtomAsrConfig *config);

/*JP
 * \brief ASR�̏�����
 * \ingroup ATOMLIB_ASR
 * \param[in]	config		ASR�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏��������s���܂��B<br>
 * �{�֐������s���邱�Ƃ�ASR���N������A�����_�����O���ʂ̏o�͂��J�n���܂��B<br>
 * \par ���l:
 * ASR�̏������ɕK�v�ȃ��[�N�������̃T�C�Y�́AASR�������p�R���t�B�O
 * �\���́i ::CriAtomAsrConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�<br>
 * �i ::criAtomAsr_SetDefaultConfig �K�p���Ɠ����p�����[�^�[�j�ŏ������������s���܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B<br>
 * \attention
 * �{�֐������s����O�ɁA���C�u���������������Ă����K�v������܂��B<br>
 * <br>
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B
 * <br>
 * �{�֐������s��A�K���΂ɂȂ� ::criAtomAsr_Finalize �֐������s���Ă��������B<br>
 * �܂��A ::criAtomAsr_Finalize �֐������s����܂ł́A�{�֐����ēx���s���Ȃ��ł��������B<br>
 * \sa criAtom_SetUserAllocator, criAtomAsr_Finalize
 */
void CRIAPI criAtomAsr_Initialize(
	const CriAtomAsrConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ASR�̏I��
 * \ingroup ATOMLIB_ASR
 * \par ����:
 * ASR�iAtom Sound Renderer�j�̏I���������s���܂��B<br>
 * �{�֐������s���邱�ƂŁA�����_�����O���ʂ̏o�͂���~����܂��B<br>
 * ::criAtom_SetUserAllocator �}�N�����g�p���ăA���P�[�^�[��o�^�ς݂̏ꍇ�A
 * ASR���������Ɋm�ۂ��ꂽ�������̈悪�������܂��B<br>
 * �iASR���������Ƀ��[�N�̈��n�����ꍇ�A�{�֐����s��ł����
 * ���[�N�̈������\�ł��B�j<br>
 * \attention
 * �{�֐��͊������A�^�̊֐��ł��B<br>
 * �{�֐������s����ƁA���΂炭�̊�Atom���C�u�����̃T�[�o�[�������u���b�N����܂��B<br>
 * �����Đ����ɖ{�֐������s����ƁA���r�؂ꓙ�̕s�����������\�������邽�߁A<br>
 * �{�֐��̌Ăяo���̓V�[���̐؂�ւ�蓙�A���וϓ������e�ł���^�C�~���O�ōs���Ă��������B<br>
 * \sa criAtom_SetUserAllocator, criAtomAsr_Initialize
 */
void CRIAPI criAtomAsr_Finalize(void);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ���[�UPCM�o�͕����p���[�N�̈�T�C�Y�v�Z
 * \ingroup ATOMEXLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���[�UPCM�o�͕����Ń��C�u���������������邽�߂ɕK�v�ȁA
 * ���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * \par ���l:
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���C�u�����������p�R���t�B�O
 * �\���́i ::CriAtomExConfigForUserPcmOutput �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \attention
 * �{�֐��� ::criAtomEx_InitializeForUserPcmOutput �֐����g�p����
 * ���C�u����������������ꍇ�Ɏg�p���܂��B<br>
 * ::criAtomEx_Initialize �֐����g�p����ꍇ�ɂ́A�{�֐��ł͂Ȃ�
 * ::criAtomEx_CalculateWorkSize �֐����g�p���ă��[�N�̈�T�C�Y���v�Z���Ă��������B<br>
 * \sa CriAtomExConfigForUserPcmOutput, criAtomEx_InitializeForUserPcmOutput
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSizeForUserPcmOutput(
	const CriAtomExConfigForUserPcmOutput *config);

/*JP
 * \brief ���[�UPCM�o�͗p���C�u����������
 * \ingroup ATOMEXLIB_GLOBAL
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
 * 	- ::criAtomEx_Initialize
 * 	- ::criAtomExAsr_Initialize
 * 	- ::criAtomExHcaMx_Initialize
 * 	- �e�v���b�g�t�H�[���ɂ�����Atom���C�u�����������֐�
 * \sa CriAtomExConfigForUserPcmOutput, criAtomEx_FinalizeForUserPcmOutput,
 * criAtomExAsr_GetPcmDataFloat32, criAtomEx_CalculateWorkSizeForUserPcmOutput
 */
void CRIAPI criAtomEx_InitializeForUserPcmOutput(
	const CriAtomExConfigForUserPcmOutput *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���[�UPCM�o�͗p���C�u�����I������
 * \ingroup ATOMEXLIB_GLOBAL
 * \par ����:
 * ���[�UPCM�o�̓��[�h�ŏ��������ꂽ���C�u�����ɑ΂��A�I���������s���܂��B<br>
 * \attention
 * �{�֐��� ::criAtomEx_InitializeForUserPcmOutput
 * �֐����g�p���ă��C�u�����������������ꍇ�Ɏg�p���܂��B<br>
 * ::criAtomEx_Initialize �֐����g�p�����ꍇ�ɂ́A�{�֐��ł͂Ȃ�
 * ::criAtomEx_Finalize �֐����g�p���ďI���������s���Ă��������B<br>
 * \sa criAtomEx_InitializeForUserPcmOutput
 */
void CRIAPI criAtomEx_FinalizeForUserPcmOutput(void);

/***************************************************************************
 *      �b��API�i�g�p�͂��T���������j
 *      Tentative API (Please don't use it)
 ***************************************************************************/
/* �ȉ��ɐ錾����Ă���֐���Atom�̓��������p�A�Q�[���G���W���Ƃ̘A�g���ɂ�
 * �b��I�Ɏg�p����Ă���API�ł��B
 * ����̃A�b�v�f�[�g�ɂė\���Ȃ��ύX�E�폜���s���邽�߁A�g�p�͂��T���������B
 */
void CRIAPI criAtomExAsr_PauseOutputVoice(CriBool sw);
CriBool CRIAPI criAtomExAsrRack_GetNumOutputSamples(
	CriAtomExAsrRackId rack_id, CriSint64 *num_samples, CriSint32 *sampling_rate);
CriSint32 CRIAPI criAtomExAsrRack_GetOutputChannels(CriAtomExAsrRackId rack_id);
CriUint16 CRIAPI criAtomExAsrRack_GetBusNumber(
	CriAtomExAsrRackId rack_id, const CriChar8 *bus_name);
void CRIAPI criAtomAsr_PauseOutputVoice(CriBool sw);
CriSint32 CRIAPI criAtomExAsrRack_GetAmbisonicRackId(void);

#ifdef __cplusplus
}
#endif

/***************************************************************************
 *      ���o�[�W�����Ƃ̌݊��p
 *      For compatibility with old version
 ***************************************************************************/
#define CRIATOMEXASR_DEFAULT_NUM_BASES	(CRIATOMEXASR_DEFAULT_NUM_BUSES)
#define CRIATOMEXASR_MAX_BASES			(CRIATOMEXASR_MAX_BUSES)
#define criAtomExAsr_CalculateWorkSizeForDspBusSettingFromAcfData(acf_data, acf_buffer_size, setting_name)	\
	criAtomEx_CalculateWorkSizeForDspBusSettingFromAcfData((acf_data), (acf_buffer_size), (setting_name))
#define criAtomExAsr_CalculateWorkSizeForDspBusSetting(setting) \
	criAtomEx_CalculateWorkSizeForDspBusSetting(setting)
#define criAtomExAsr_AttachDspBusSetting(setting, work, work_size) \
	criAtomEx_AttachDspBusSetting(setting, work, work_size)
#define criAtomExAsr_DetachDspBusSetting() \
	criAtomEx_DetachDspBusSetting()
/* �����_���[�̏o��Ch���ݒ�ɉ����āA�����Ń_�E���~�b�N�X���邽�߉��L2�֐��͖����ɂ��Ă��܂� */
#define criAtomExAsr_SetDownmixMode(downmix_mode)
#define criAtomExAsrRack_SetDownmixMode(rack_id, downmix_mode)

/* ��\�L�}�N�� */
#define CRIATOMEXASR_BIQUAD_FILTER_ANALYZER_NAME				"CRIWARE/Biquad"
#define CRIATOMEXASR_BANDPASS_FILTER_PARAMETER_TYPE				(-1)
#define CRIATOMEXASR_BUTTERWORTH_FILTER_PARAMETER_TYPE			(-1)
#define CRIATOMEXASR_BUTTERWORTH_FILTER_PARAMETER_LOW_FREQ		(0)
#define CRIATOMEXASR_BUTTERWORTH_FILTER_PARAMETER_HIGH_FREQ		(1)
#define CRIATOMEXASR_BUTTERWORTH_FILTER_NUM_PARAMETERS			(2)

/* 
 * CRI Atom Ver.2.13.00 �ȍ~�ł́AASR�o�X�Ɏg�p����G�t�F�N�g�̎��ʂ�
 * id�i�񋓌^�j���當����ɕύX���A�܂��G�t�F�N�g�̃p�����[�^�[�͍\���̂���float�z��ɕύX���Ă��܂��B
 * ���̕ύX�ɔ����A�ȉ��̗񋓌^�ƍ\���͓̂����I�Ɏg�p���܂���B
 * �ߋ��݊��ׁ̈A�^��`�������c���܂��B
 */
typedef enum {
	CRIATOMEXASR_DSP_ID_INVALID = 0,		
	CRIATOMEXASR_DSP_ID_BANDPASS_FILTER,	
	CRIATOMEXASR_DSP_ID_BIQUAD_FILTER,		
	CRIATOMEXASR_DSP_ID_DELAY,				
	CRIATOMEXASR_DSP_ID_ECHO,				
	CRIATOMEXASR_DSP_ID_REVERB,				
	CRIATOMEXASR_DSP_ID_PITCH_SHIFTER,		
	CRIATOMEXASR_DSP_ID_3BAND_EQ,			
	CRIATOMEXASR_DSP_ID_COMPRESSOR,			
	CRIATOMEXASR_DSP_ID_COMPRESSOR_EX,		
	CRIATOMEXASR_DSP_ID_CHORUS,				
	CRIATOMEXASR_DSP_ID_FLANGER,			
	CRIATOMEXASR_DSP_ID_DISTORTION,			
	CRIATOMEXASR_DSP_ID_AMPLITUDE_ANALYZER,	
	CRIATOMEXASR_DSP_ID_SURROUNDER,			
	CRIATOMEXASR_DSP_ID_I3DL2_REVERB,		
	CRIATOMEXASR_DSP_ID_MULTI_TAP_DELAY,	
	CRIATOMEXASR_DSP_ID_LIMITER,			
	CRIATOMEXASR_DSP_ID_MATRIX,				
	CRIATOMEXASR_DSP_ID_32BANDS_EQ,
	CRIATOMEXASR_DSP_ID_BIT_CRUSHER,
	CRIATOMEXASR_DSP_ID_PHASER,
    CRIATOMEXASR_DSP_ID_BUS_BUFFER_POOL,
    CRIATOMEXASR_DSP_ID_MID_SIDE,
	CRIATOMEXASR_DSP_ID_IR_REVERB,
	CRIATOMEXASR_DSP_ID_CHANNELSPLIT_EQ,
	CRIATOMEXASR_DSP_ID_NO_TYPE = 0xFF,
	CRIATOMEXASR_DSP_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrDspId;

typedef struct CriAtomExAsrBandpassFilterParameterTag {
	CriFloat32 cof_high;
	CriFloat32 cof_low;
} CriAtomExAsrBandpassFilterParameter;

typedef struct CriAtomExAsrBiquadFilterParameterTag {
	CriAtomExBiquadFilterType type;
	CriFloat32 frequency;
	CriFloat32 q_value;
	CriFloat32 gain;
} CriAtomExAsrBiquadFilterParameter;

typedef struct CriAtomExAsrDelayParameterTag {
	CriFloat32 max_delay_time_ms;
	CriFloat32 delay_time_ms;
} CriAtomExAsrDelayParameter;

typedef struct CriAtomExAsrEchoParameterTag {
	CriFloat32 max_delay_time_ms;
	CriFloat32 delay_time_ms;
	CriFloat32 gain;
} CriAtomExAsrEchoParameter;

typedef enum {
	CRIATOMEXASR_REVERB_MODE_SURROUND = 0,
	CRIATOMEXASR_REVERB_MODE_STEREO,
	CRIATOMEXASR_REVERB_MODE_REAR_ONLY,
	CRIATOMEXASR_REVERB_MODE_CENTER_ONLY,
	CRIATOMEXASR_REVERB_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrReverbMode;

typedef struct CriAtomExAsrReverbParameterTag {
	CriFloat32 max_predelay_time_ms;
	CriFloat32 max_room_size;
	CriAtomExAsrReverbMode mode;
	CriFloat32 reverb_time_ms;
	CriFloat32 room_size;
	CriFloat32 predelay_time_ms;
	CriFloat32 cof_low;
	CriFloat32 cof_high;
} CriAtomExAsrReverbParameter;

typedef enum {
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_128 = 0,
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_256,    
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_512,    
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_1024,   
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_2048,   
	CRIATOMEXASR_PITCHSHIFTER_WINDOW_WIDTH_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrPitchShifterWindowWidthType;

typedef enum {
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_1 = 0, 
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_2,     
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_4,     
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_8,     
	CRIATOMEXASR_PITCHSHIFTER_OVERLAP_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrPitchShifterOverlapType;

typedef struct CriAtomExAsrPitchShifterParameterTag {
	CriFloat32 pitch_cent;
	CriFloat32 formant_cent;
	CriSint32 mode;
    CriAtomExAsrPitchShifterWindowWidthType window_width;
    CriAtomExAsrPitchShifterOverlapType overlap;
} CriAtomExAsrPitchShifterParameter;

typedef enum {
	CRIATOMEX_EQ_BAND_TYPE_LOWSHELF 	= 0,	
	CRIATOMEX_EQ_BAND_TYPE_HIGHSHELF 	= 1,	
	CRIATOMEX_EQ_BAND_TYPE_PEAKING 		= 2,	
	CRIATOMEX_EQ_BAND_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrEqBandType;

typedef struct CriAtomExAsr3BandsEqParameterTag {
	struct {
		CriAtomExAsrEqBandType type;
		CriFloat32 frequency;
		CriFloat32 q_value;
		CriFloat32 gain;
	} bands[3];
} CriAtomExAsr3BandsEqParameter;

typedef struct CriAtomExAsr32BandsEqParameterTag {
	CriSint32 num_used_bands;
	struct {
		CriAtomExAsrEqBandType type;
		CriFloat32 frequency;
		CriFloat32 q_value;
		CriFloat32 gain;
	} bands[32];
} CriAtomExAsr32BandsEqParameter;

typedef struct CriAtomExAsrCompressorParameterTag {
	CriFloat32 threshold;
	CriFloat32 ratio;
	CriFloat32 attack_time;
	CriFloat32 release_time;
	CriFloat32 output_gain; 
	CriFloat32 surround_link;
	CriSint32 side_chain_input_bus_no;
} CriAtomExAsrCompressorParameter;

typedef enum {
	CRIATOMEXASR_SPLIT_EQ_NONE     = 0,
	CRIATOMEXASR_SPLIT_EQ_LOWPASS  = 1,
	CRIATOMEXASR_SPLIT_EQ_HIGHPASS = 2,
	CRIATOMEXASR_SPLIT_EQ_BANDPASS = 3,
	CRIATOMEXASR_SPLIT_EQ_NOTCH    = 4,
	CRIATOMEXASR_SPLIT_EQ_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrSplitEqType;

typedef struct CriAtomExAsrCompressorExParameterTag {
	CriAtomExAsrCompressorParameter base;
	CriAtomExAsrSplitEqType eq_type;
	CriFloat32 frequency;
	CriFloat32 q_value;
} CriAtomExAsrCompressorExParameter;

typedef struct CriAtomExAsrChorusParameterTag {
	CriFloat32 max_delay_time_ms;
	CriFloat32 delay_time_ms;
	CriFloat32 rate;
	CriFloat32 depth;
	CriFloat32 feedback;
	CriFloat32 dry_mix; 
	CriFloat32 wet_mix1;
	CriFloat32 wet_mix2;
	CriFloat32 wet_mix3;
} CriAtomExAsrChorusParameter;

typedef struct CriAtomExAsrFlangerParameterTag {
	CriFloat32 delay_time_ms;
	CriFloat32 rate;
	CriFloat32 depth;
	CriFloat32 feedback;
	CriFloat32 dry_mix; 
	CriFloat32 wet_mix;
} CriAtomExAsrFlangerParameter;

typedef struct CriAtomExAsrDistortionParameterTag {
	CriFloat32 drive;
	CriFloat32 dry_mix; 
	CriFloat32 wet_mix;
	CriFloat32 output_gain; 
} CriAtomExAsrDistortionParameter;

typedef enum {
	CRIATOMEX_SURROUNDER_MODE_STRAIGHT = 0,
	CRIATOMEX_SURROUNDER_MODE_CROSS = 1,
	CRIATOMEX_SURROUNDER_MODE_MATRIX = 2,
	CRIATOMEX_SURROUNDER_MODE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrSurrounderMode;

typedef struct CriAtomExAsrSurrounderParameterTag {
	CriFloat32 max_delay_time_ms;
	CriFloat32 delay_time_ms;
	CriFloat32 gain;
	CriAtomExAsrSurrounderMode mode;
} CriAtomExAsrSurrounderParameter;

typedef struct CriAtomExAsrI3DL2ReverbParameterTag {
	CriFloat32 room;
	CriFloat32 room_hf;
	CriFloat32 decay_time;
	CriFloat32 decay_hf_ratio;
	CriFloat32 reflections;
	CriFloat32 reflections_delay;
	CriFloat32 reverb;
	CriFloat32 reverb_delay;
	CriFloat32 diffusion;
	CriFloat32 density;
	CriFloat32 hf_reference;
	CriFloat32 front_input;
	CriFloat32 rear_input;
	CriFloat32 center_input;
	CriFloat32 front_output;
	CriFloat32 rear_output;
	CriFloat32 center_output;
} CriAtomExAsrI3DL2ReverbParameter;

typedef struct CriAtomExAsrMultiTapDelayParameterTag {
	CriFloat32 max_delay_time_ms;
	struct {
		CriFloat32 delay_time_ms;
		CriFloat32 level;
		CriFloat32 pan;
		CriFloat32 feedback;
	} taps[4];
} CriAtomExAsrMultiTapDelayParameter;

typedef enum {
	CRIATOMEX_LIMITER_TYPE_PEAK = 0,
	CRIATOMEX_LIMITER_TYPE_RMS = 1,
	CRIATOMEX_LIMITER_TYPE_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExAsrLimiterType;

typedef struct CriAtomExAsrLimiterParameterTag {
	CriAtomExAsrLimiterType type;
	CriFloat32 threshold;
	CriFloat32 attack_time;
	CriFloat32 release_time;
	CriFloat32 output_gain; 
	CriFloat32 surround_link;
	CriSint32 side_chain_input_bus_no;
} CriAtomExAsrLimiterParameter;

typedef struct CriAtomExAsrMatrixParameterTag {
	CriFloat32		levels[CRIATOMEXASR_MAX_CHANNELS][CRIATOMEXASR_MAX_CHANNELS];
} CriAtomExAsrMatrixParameter;

#ifdef __cplusplus
extern "C" {
#endif

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsr_SetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetDspParameter(
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, const void* parameter);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsr_SetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetDspParameterByName(
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, const void* parameter);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsr_GetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetDspParameter(
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, void* parameter_buf, CriSint32 parameter_size);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsr_GetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetDspParameterByName(
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, void* parameter_buf, CriSint32 parameter_size);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_SetEffectBypass �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetDspBypass(
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, CriBool bypass);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƌx�����������܂����A�����͍s���܂��B
 * ::criAtomExAsrRack_SetEffectBypass �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetDspBypassByName(
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, CriBool bypass);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusVolumeByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusVolume(CriSint32 bus_no, CriFloat32 volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_GetBusVolumeByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetBusVolume(CriSint32 bus_no, CriFloat32 *volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusPan3d(CriSint32 bus_no, 
	CriFloat32 pan3d_angle, CriFloat32 pan3d_distance, CriFloat32 pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_GetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetBusPan3d(CriSint32 bus_no, 
	CriFloat32 *pan3d_angle, CriFloat32 *pan3d_distance, CriFloat32 *pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusPan3dByName(const CriChar8* bus_name,
	CriFloat32 pan3d_angle, CriFloat32 pan3d_distance, CriFloat32 pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_GetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetBusPan3dByName(const CriChar8* bus_name,
	CriFloat32 *pan3d_angle, CriFloat32 *pan3d_distance, CriFloat32 *pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusMatrixByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusMatrix(CriSint32 bus_no, 
	CriSint32 input_channels, CriSint32 output_channels, const CriFloat32 matrix[]);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusSendLevelByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusSendLevel(
	CriSint32 bus_no, CriSint32 sendto_no, CriFloat32 level);
/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_AttachBusAnalyzerByName �֐��̎g�p���������ĉ������B
 */

void CRIAPI criAtomExAsr_AttachBusAnalyzer(
	CriSint32 bus_no, const CriAtomExAsrBusAnalyzerConfig* config);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_DetachBusAnalyzerByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_DetachBusAnalyzer(CriSint32 bus_no);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_GetBusAnalyzerInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_GetBusAnalyzerInfo(
	CriSint32 bus_no, CriAtomExAsrBusAnalyzerInfo *info);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsr_SetBusFilterCallbackByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsr_SetBusFilterCallback(CriSint32 bus_no, 
	CriAtomExAsrBusFilterCbFunc pre_func, CriAtomExAsrBusFilterCbFunc post_func, void *obj);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_SetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetDspParameter(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, const void* parameter);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_SetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetDspParameterByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, const void* parameter);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_GetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetDspParameter(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, void* parameter_buf, CriSint32 parameter_size);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_GetEffectParameter �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetDspParameterByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, void* parameter_buf, CriSint32 parameter_size);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƃG���[�R�[���o�b�N���Ԃ�܂��B
 * ::criAtomExAsrRack_SetEffectBypass �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetDspBypass(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriAtomExAsrDspId dsp_id, CriBool bypass);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * �Ăяo���ƌx�����������܂����A�����͍s���܂��B
 * ::criAtomExAsrRack_SetEffectBypass �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetDspBypassByName(CriAtomExAsrRackId rack_id, 
	const CriChar8* bus_name, CriAtomExAsrDspId dsp_id, CriBool bypass);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusVolumeByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusVolume(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriFloat32 volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_GetBusVolumeByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetBusVolume(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriFloat32* volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusPan3d(CriAtomExAsrRackId rack_id, CriSint32 bus_no, 
	CriFloat32 pan3d_angle, CriFloat32 pan3d_distance, CriFloat32 pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_GetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetBusPan3d(CriAtomExAsrRackId rack_id, CriSint32 bus_no, 
	CriFloat32 *pan3d_angle, CriFloat32 *pan3d_distance, CriFloat32 *pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusPan3dByName(CriAtomExAsrRackId rack_id, const CriChar8* bus_name,
	CriFloat32 pan3d_angle, CriFloat32 pan3d_distance, CriFloat32 pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_GetBusPanInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetBusPan3dByName(CriAtomExAsrRackId rack_id, const CriChar8* bus_name,
	CriFloat32 *pan3d_angle, CriFloat32 *pan3d_distance, CriFloat32 *pan3d_volume);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusMatrixByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusMatrix(
	CriAtomExAsrRackId rack_id, CriSint32 bus_no, CriSint32 input_channels, 
	CriSint32 output_channels, const CriFloat32 matrix[]);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusSendLevelByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusSendLevel(CriAtomExAsrRackId rack_id,
	CriSint32 bus_no, CriSint32 sendto_no, CriFloat32 level);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_AttachBusAnalyzerByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_AttachBusAnalyzer(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, const CriAtomExAsrBusAnalyzerConfig* config);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_DetachBusAnalyzerByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_DetachBusAnalyzer(
	CriAtomExAsrRackId rack_id, CriSint32 bus_no);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_GetBusAnalyzerInfoByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_GetBusAnalyzerInfo(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriAtomExAsrBusAnalyzerInfo *info);

/*JP
 * \deprecated
 * �폜�\��̔񐄏�API�ł��B
 * ::criAtomExAsrRack_SetBusFilterCallbackByName �֐��̎g�p���������ĉ������B
 */
void CRIAPI criAtomExAsrRack_SetBusFilterCallback(CriAtomExAsrRackId rack_id, 
	CriSint32 bus_no, CriAtomExAsrBusFilterCbFunc pre_func, 
	CriAtomExAsrBusFilterCbFunc post_func, void *obj);

#ifdef __cplusplus
}
#endif


#endif	/* CRI_ATOM_ASR_H_INCLUDED */

/* --- end of file --- */
