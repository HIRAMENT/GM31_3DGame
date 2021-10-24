/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010 CRI Middleware Co., Ltd.
 *
 * Library  : CRI AtomEx Monitor Library
 * Module   : Monitor Library C Interface Header
 * File     : cri_atom_ex_monitor.h
 *
 ****************************************************************************/
/*!
 *	\file	cri_atom_ex_monitor.h
 */

#ifndef CRI_INCL_CRI_ATOMEX_MONITOR_H
#define CRI_INCL_CRI_ATOMEX_MONITOR_H

/***************************************************************************
 *      �C���N���[�h�t�@�C��
 *      Include files
 ***************************************************************************/

#include "cri_le_xpt.h"
#include "cri_le_atom_ex.h"

/***************************************************************************
 *      �萔�}�N��
 *      Macro Constants
 ***************************************************************************/
/* �o�[�W������� */
/* Version Number */
#define CRIATOMEX_MONITOR_VER_NAME				"CRI AtomEx Monitor"
#define CRIATOMEX_MONITOR_VER_NUM				"1.15.11"
#define CRIATOMEX_MONITOR_VER_MAJOR				(1)
#define CRIATOMEX_MONITOR_VER_MINOR				(15)
#define CRIATOMEX_MONITOR_VER_PATCH				(11)
#define CRIATOMEX_MONITOR_VER_RELEASE			(0)
#define CRIATOMEX_MONITOR_VER_REVISION			(0)
#define CRIATOMEX_MONITOR_VER_OPTION


/*JP
 * \brief �f�t�H���g�v���r���[�I�u�W�F�N�g
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �f�t�H���g�̃v���r���[�I�u�W�F�N�g���ł��B<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_NUM_PUREVIEW_OBJECTS		(200)
/*JP
 * \brief �f�t�H���g�ʐM�o�b�t�@�T�C�Y
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �f�t�H���g�̒ʐM�o�b�t�@�T�C�Y�ł��B<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_COMMUNICATION_BUFFER_SIZE	(2*1024*1024)
/*JP
 * \brief �f�t�H���g�Đ��ʒu���X�V�Ԋu
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �f�t�H���g�̍Đ��ʒu���X�V�Ԋu�ł��B<br>
 * \sa criAtomExMonitor_SetDefaultConfig
 */
#define CRIATOMX_MONITOR_DEFAULT_PLAYBACK_POSITION_UPDATE_INTERVAL	(8)

/*JP
 * \brief ���O�擾���[�h
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * ���O�擾�̃��[�h�ł��B<br>
 * \sa criAtomExMonitor_SetLogMode
 */
#define CRIATOMEX_MONITOR_LOG_MODE_OFF						(0)
#define CRIATOMEX_MONITOR_LOG_MODE_PLAYBACK					(1)			/* �Đ�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_ERROR					(1 << 1)	/* �G���[�֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_LOW_LEVEL_PLAYBACK		(1 << 2)	/* �჌�x���Đ�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_SYSTEM_INFORMATION		(1 << 3)	/* �V�X�e�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_HANDLE_INFORMATION		(1 << 4)	/* �V�X�e�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_CUE_LIMIT				(1 << 5)	/* �L���[���~�b�g�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_PROBABILITY				(1 << 6)	/* �v���o�r���e�B�����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_CATEGORY					(1 << 7)	/* �J�e�S�������֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_EXECUTING_INFORMATION	(1 << 8)	/* ����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_3D_INFO					(1 << 9)	/* 3D����֘A */
#define CRIATOMEX_MONITOR_LOG_MODE_USER_LOG					(1 << 10)	/* ���[�U���O */

#define CRIATOMEX_MONITOR_LOG_MODE_ALL						(0xFFFFFFFF)


/***************************************************************************
 *      �����}�N��
 *      Macro Functions
 ***************************************************************************/
/*JP
 * \brief Atom���j�^�[���C�u�����������R���t�B�O�\���̂Ƀf�t�H���g�l���Z�b�g
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * ::criAtomExMonitor_Initialize �֐��ɐݒ肷��R���t�B�O�\����
 * �i ::CriAtomExMonitorConfig �j�ɁA�f�t�H���g�l���Z�b�g���܂��B<br>
 * \sa criAtomExMonitor_Initialize, CriAtomExMonitorConfig
 */
#define criAtomExMonitor_SetDefaultConfig(p_config)	\
{\
	(p_config)->max_preivew_object = CRIATOMX_MONITOR_DEFAULT_NUM_PUREVIEW_OBJECTS;\
	(p_config)->communication_buffer_size = CRIATOMX_MONITOR_DEFAULT_COMMUNICATION_BUFFER_SIZE;\
	(p_config)->additional_buffer = 0;\
	(p_config)->additional_buffer_size = 0;\
	(p_config)->playback_position_update_interval = CRIATOMX_MONITOR_DEFAULT_PLAYBACK_POSITION_UPDATE_INTERVAL;\
}
 
/***************************************************************************
 *      �f�[�^�^�錾
 *      Data Type Declarations
 ***************************************************************************/
/*JP
 * \brief Atom���j�^�[���C�u�����������p�R���t�B�O�\����
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * ���j�^�[���C�u�����̓���d�l���w�肷�邽�߂̍\���̂ł��B<br>
 * ::criAtomExMonitor_Initialize �֐��̈����Ɏw�肵�܂��B<br>
 * <br>
 * CRI AtomEx Monitor���C�u�����́A���������ɖ{�\���̂Ŏw�肳�ꂽ�ݒ�ɉ����āA�������\�[�X��
 * �K�v�Ȃ����m�ۂ��܂��B<br>
 * ���C�u�������K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A�{�\���̂Ŏw�肳�ꂽ�p�����[�^�[�ɉ�����
 * �ω����܂��B
 * \par ���l:
 * �f�t�H���g�ݒ���g�p����ꍇ�A ::criAtomExMonitor_SetDefaultConfig �}�N���ō\���̂Ƀf�t�H���g
 * �p�����[�^�[���Z�b�g������A ::criAtomExMonitor_Initialize �֐��ɍ\���̂��w�肵�Ă��������B<br>
 * \attention
 * �����I�Ƀ����o��������\�������邽�߁A ::criAtomExMonitor_SetDefaultConfig �}�N�����g�p���Ȃ�
 * �ꍇ�ɂ́A�g�p�O�ɕK���\���̂��[���N���A���Ă��������B<br>
 * �i�\���̂̃����o�ɕs��l������Ȃ��悤�����ӂ��������B�j
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_SetDefaultConfig
 */
typedef struct CriAtomExMonitorConfigTag {
	/*JP
		\brief �C���Q�[���v���r���[�p�Ǘ����\�[�X�̍ő�l
		\par ����:
		�����Ŏw�肷��Ǘ����\�[�X�̓C���Q�[���v���r���[���� ACB �n���h���P�ɑ΂��P�����܂��B<br>
		�����Ɏg�p���� ACB �����傫�Ȓl��ݒ肷��悤�ɂ��Ă��������B<br>
	*/
	CriUint32	max_preivew_object;
	/*JP
		\brief �ʐM�p�o�b�t�@�T�C�Y
		\par ����:
		���j�^���C�u�����ƃI�[�T�����O�c�[���Ԃōs���ʐM�Ɏg�p����o�b�t�@�T�C�Y���w�肵�܂��B<br>
		�o�b�t�@�͑��M�p�A��M�p��2������A���ꂼ��ݒ�l�̔����̊g���̈悪����ɕt������܂��B<br>
		���̂��ߎ��ۂɕK�v�ȃo�b�t�@�T�C�Y�͐ݒ�l��3�{�ƂȂ�܂��B<br>
	*/
	CriUint32	communication_buffer_size;
	/*JP
		\brief �ǉ��o�b�t�@
		\par ����:
		TCP/IP�ڑ��ȊO�̐ڑ����s�����A�ʐM�o�b�t�@���O������w�肷��K�v������ꍇ�Ɏg�p���܂��B<br>
		���Ɏw�肪�Ȃ��ꍇ�͎g�p���܂���B<br>
	*/
	CriUintPtr	additional_buffer;
	/*JP
		\brief �ǉ��o�b�t�@�T�C�Y
		\par ����:
		�O���w��̒ʐM�o�b�t�@�T�C�Y�ł��B<br>
	*/
	CriUint32	additional_buffer_size;
	/*JP
		\brief �Đ��ʒu���X�V�Ԋu
		\par ����:
		�T�[�o�������s���ɍĐ��ʒu���̑��M�������s���Ԋu���w�肵�܂��B<br>
		playback_position_update_interval �̒l��ύX���邱�ƂŁA
		�T�[�o�����̎��s�񐔂�ς��邱�ƂȂ��Đ��ʒu���̑��M�p�x�������邱�Ƃ��\�ł��B<br>
		<br>
		playback_position_update_interval �ɂ́A�Đ��ʒu���̑��M���������T�[�o���Ƃɍs�������w�肵�܂��B<br>
		�Ⴆ�΁A playback_position_update_interval �� 2 �ɐݒ肷��ƁA
		�T�[�o���� 2 ��ɑ΂��A 1 �񂾂��Đ��ʒu���̑��M���s���܂��B<br>
		�i�Đ��ʒu���̑��M�p�x�� 1/2 �ɂȂ�܂��B�j<br>
	*/
	CriSint32	playback_position_update_interval;
} CriAtomExMonitorConfig;

/*JP
 * \brief �f�[�^�X�V�^�C�v
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �C���Q�[���v���r���[����AtomCraft�i�I�[�T�����O�c�[���j�ɂ��f�[�^�X�V�̃^�[�Q�b�g�ł��B<br>
 * \sa CriAtomExMonitorDataUpdateNotificationInfo
 */
typedef enum CriAtomExMonitorDataUpdateTargetTag {
	CRIATOMEXMONITOR_DATA_UPDATE_TARGET_ACF = 0,			/*JP< ACF�X�V */
	CRIATOMEXMONITOR_DATA_UPDATE_TARGET_ACB = 1,			/*JP< ACB�X�V */
	/* enum size is 4bytes */
	CRIATOMEXMONITOR_DATA_UPDATE_TARGET_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExMonitorDataUpdateTarget;

/*JP
 * \brief �f�[�^�X�V�X�e�[�^�X
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �C���Q�[���v���r���[����AtomCraft�i�I�[�T�����O�c�[���j�ɂ��f�[�^�X�V�̏�Ԃł��B<br>
 * \sa CriAtomExMonitorDataUpdateNotificationInfo
 */
typedef enum CriAtomExMonitorDataUpdateEventTag {
	CRIATOMEXMONITOR_DATA_UPDATE_EVENT_BEGIN = 0,	/*JP< �J�n�C�x���g */
	CRIATOMEXMONITOR_DATA_UPDATE_EVENT_END   = 1,	/*JP< �I���C�x���g */
	/* enum size is 4bytes */
	CRIATOMEXMONITOR_DATA_UPDATE_EVENT_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
} CriAtomExMonitorDataUpdateEvent;

/*JP
 * \brief �f�[�^�X�V���
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �C���Q�[���v���r���[����AtomCraft�i�I�[�T�����O�c�[���j�ɂ��f�[�^�X�V���ł��B<br>
 * \sa criAtomExMonitor_SetDataUpdateNotificationCallback
 */
typedef struct CriAtomExMonitorDataUpdateNotificationInfoTag {
	CriAtomExMonitorDataUpdateTarget target;				/*JP< �X�V�^�[�Q�b�g */
	CriAtomExMonitorDataUpdateEvent event;				/*JP< �C�x���g */
	CriAtomExAcbHn acb_hn;								/*JP< ACB�n���h�� */
	const CriChar8* name;								/*JP< ���O */
} CriAtomExMonitorDataUpdateNotificationInfo;

/*JP
 * \brief �I�[�T�����O�c�[���ɂ��f�[�^�X�V�ʒm���擾�R�[���o�b�N�֐�
 * \ingroup ATOMEXLIB_ACB
 * \par ����:
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \param[in]	info		�f�[�^�X�V�ʒm���擾
 * \return					�Ȃ�
 * \par ����:
 * �C���Q�[���v���r���[���ɃI�[�T�����O�c�[������̃f�[�^�X�V���������������ꍇ�ɌĂяo���R�[���o�b�N�֐��ł��B<br>
 * �C���Q�[���v���r���[���ɃA�v���P�[�V�������Ńf�[�^�X�V��Ԃ��擾�������ꍇ�Ɏg�p���܂��B<br>
 * <br>
 * �R�[���o�b�N�֐��̓o�^�ɂ� ::criAtomExMonitor_SetDataUpdateNotificationCallback �֐����g�p���܂��B<br>
 * �o�^�����R�[���o�b�N�֐��́A�C���Q�[���v���r���[���ɃI�[�T�����O�c�[������̃f�[�^�X�V�O��̃^�C�~���O�Ŏ��s����܂��B<br>
 * \attention
 * ��{�I�ɁA�R�[���o�b�N�֐����ł�Atom���C�u����API���g�p���Ȃ��ł��������B<br>
 * �{�R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖�肪�������܂��̂ŁA
 * �����ӂ��������B<br>
 * �R�[���o�b�N�֐��Ɉ����Ƃ��ēn�����CriAtomExMonitorDataUpdateNotificationInfo�\���̂ւ̎Q�Ƃ̓R�[���o�b�N�֐��������ōs���Ă��������B<br>
 * �R�[���o�b�N�֐��O�ŎQ�Ƃ���ꍇ�́A�ʗ̈�ɓ��e��ۑ����Ă���s���Ă��������B
 * \sa criAtomExMonitor_SetDataUpdateNotificationCallback, CriAtomExMonitorDataUpdateNotificationInfo
 */
typedef void (CRIAPI *CriAtomExMonitorDataUpdateNotificationCbFunc)(
	void *obj, const CriAtomExMonitorDataUpdateNotificationInfo* info);

/*	Log Callback Function type	*/
typedef void (*CriAtomExMonitorLogCbFunc)(void* obj, const CriChar8 *log_string);

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

/*JP
 * \brief ���j�^�[�@�\�������p���[�N�̈�T�C�Y�̌v�Z
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \return		CriSint32	���[�N�̈�T�C�Y
 * \par ����:
 * ���j�^�[�@�\���g�p���邽�߂ɕK�v�ȁA���[�N�̈�̃T�C�Y���擾���܂��B<br>
 * <br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s����ƁA�{�֐��� -1 ��Ԃ��܂��B<br>
 * ���[�N�̈�T�C�Y�̌v�Z�Ɏ��s�������R�ɂ��ẮA�G���[�R�[���o�b�N�̃��b�Z�[�W�Ŋm�F�\�ł��B<br>
 * \par ���l:
 * ���j�^�[�@�\���K�v�Ƃ��郏�[�N�̈�̃T�C�Y�́A���j�^�[�@�\�������p�R���t�B�O
 * �\���́i ::CriAtomExMonitorConfig �j�̓��e�ɂ���ĕω����܂��B<br>
 * <br>
 * ������NULL���w�肵���ꍇ�A�f�t�H���g�ݒ�
 * �i ::criAtomExMonitor_SetDefaultConfig �K�p���Ɠ����p�����[�^�j��
 * ���[�N�̈�T�C�Y���v�Z���܂��B
 * <br>
 * ���� config �̏��́A�֐����ł̂ݎQ�Ƃ���܂��B<br>
 * �֐��𔲂�����͎Q�Ƃ���܂���̂ŁA�֐����s��� config �̗̈��������Ă�
 * ��肠��܂���B
 * \sa criAtomExMonitor_SetDefaultConfig, criAtomExMonitor_Initialize, CriAtomExMonitorConfig
 */
CriSint32 CRIAPI criAtomExMonitor_CalculateWorkSize(const CriAtomExMonitorConfig* config);

/*JP
 * \brief ���j�^�[�@�\�̏�����
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param[in]	config		�������p�R���t�B�O�\����
 * \param[in]	work		���[�N�̈�
 * \param[in]	work_size	���[�N�̈�T�C�Y
 * \par ����:
 * ���j�^�[�@�\�����������܂��B<br>
 * ���j�^�[�@�\�𗘗p����ɂ́A�K�����̊֐������s����K�v������܂��B<br>
 * �i���j�^�[�@�\�́A�{�֐������s��A ::criAtomExMonitor_Finalize �֐������s����܂ł̊ԁA
 * ���p�\�ł��B�j<br>
 * �{�֐��̌Ăяo���́AcriAtomEx_Initialize �֐����s�� ::criAtomEx_Finalize �֐������s����܂ł̊Ԃ�
 * �s���悤�ɂ��Ă��������B<br>
 * \sa criAtomExMonitor_Finalize, CriAtomExMonitorConfig
 */
void CRIAPI criAtomExMonitor_Initialize(
	const CriAtomExMonitorConfig *config, void *work, CriSint32 work_size);

/*JP
 * \brief ���j�^�[�@�\�̏I��
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * ���j�^�[�@�\���I�����܂��B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomExMonitor_Initialize
 */
void CRIAPI criAtomExMonitor_Finalize(void);

/*JP
 * \brief �T�[�o�[IP�A�h���X������̎擾
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �T�[�o�[IP�A�h���X��������擾���܂��B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_GetClientIpString
 */
const CriChar8* CRIAPI criAtomExMonitor_GetServerIpString(void);

/*JP
 * \brief �N���C�A���gIP�A�h���X������̎擾
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \par ����:
 * �N���C�A���gIP�A�h���X��������擾���܂��B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_GetServerIpString
 */
const CriChar8* CRIAPI criAtomExMonitor_GetClientIpString(void);

/*JP
 * \brief �c�[���ڑ���Ԃ̎擾
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \return		CriBool	�ڑ���ԁiCRI_TRUE:�ڑ��ACRI_FALSE:���ڑ��j
 * \par ����:
 * �c�[���ڑ���Ԃ��擾���܂��B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomExMonitor_Initialize
 */
CriBool CRIAPI criAtomExMonitor_IsConnected(void);

/*JP
 * \brief ���O�擾�R�[���o�b�N�̓o�^
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param		cbf			�R�[���o�b�N�֐�
 * \param		obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * ���O�擾�p�R�[���o�b�N�֐���o�^���܂��B<br>
 * �֐���o�^����ƃ��O�擾���J�n���ANULL��ݒ肷�邱�ƂŃ��O�擾���~���܂��B<br>
 * �擾���郍�O�̃��[�h�ؑւ� ::criAtomExMonitor_SetLogMode �֐��Őݒ�w�肭�������B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa criAtomExMonitor_Initialize, criAtomExMonitor_SetLogMode
 */
void CRIAPI criAtomExMonitor_SetLogCallback(CriAtomExMonitorLogCbFunc cbf, void* obj);

/*JP
 * \brief ���O���[�h�̐ݒ�
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param		mode		���O�o�̓��[�h
 * \par ����:
 * ���O�擾�̃��[�h��ݒ肵�܂��B<br>
 * �{�֐��Őݒ肵�����[�h�ɂ��������� ::criAtomExMonitor_SetLogCallback �֐���
 * �o�^�������O�擾�p�R�[���o�b�N�֐����Ăяo����܂��B<br>
 * \sa criAtomExMonitor_SetLogCallback
 */
void CRIAPI criAtomExMonitor_SetLogMode(CriUint32 mode);

/*JP
 * \brief ���[�U���O�̏o��
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param		message		���[�U���O���b�Z�[�W
 * \par ����:
 * ���[�U���O���o�͂��܂��B<br>
 * �{�֐��ɂ���ďo�͂������O�̓��O�擾�R�[���o�b�N��v���t�@�C���Ŏ擾�A�m�F���s���܂��B
 * \sa criAtomExMonitor_SetLogCallback
 */
void CRIAPI criAtomExMonitor_OutputUserLog(const CriChar8* message);

/*JP
 * \brief �f�[�^�X�V�ʒm�R�[���o�b�N�֐��̓o�^
 * \ingroup ATOMEXMONITORLIB_GLOBAL
 * \param[in]	func		�f�[�^�X�V�ʒm�R�[���o�b�N�֐�
 * \param[in]	obj			���[�U�w��I�u�W�F�N�g
 * \par ����:
 * �C���Q�[���v���r���[���ɃI�[�T�����O�c�[������̃f�[�^�X�V���������������ꍇ�ɌĂяo���R�[���o�b�N�֐���o�^���܂��B<br>
 * \attention
 * �R�[���o�b�N�֐����ŁAAtom���C�u������API�����s���Ȃ��ł��������B<br>
 * �R�[���o�b�N�֐���AtomMonitor���C�u�������̃T�[�o������������s����܂��B<br>
 * ���̂��߁A�T�[�o�����ւ̊��荞�݂��l�����Ȃ�API�����s�����ꍇ�A
 * �G���[������������A�f�b�h���b�N����������\��������܂��B<br>
 * <br>
 * �R�[���o�b�N�֐����Œ����ԏ������u���b�N����ƁA���؂ꓙ�̖��
 * ���������܂��̂ŁA�����ӂ��������B<br>
 * <br>
 * �R�[���o�b�N�֐���1�����o�^�ł��܂���B<br>
 * �o�^����𕡐���s�����ꍇ�A���ɓo�^�ς݂̃R�[���o�b�N�֐����A
 * �ォ��o�^�����R�[���o�b�N�֐��ɂ��㏑������Ă��܂��܂��B<br>
 * <br>
 * func��NULL���w�肷��Ƃ��Ƃœo�^�ς݊֐��̓o�^�������s���܂��B<br>
 * \attention
 * ::criAtomExMonitor_Initialize �֐����s�O�ɖ{�֐������s���邱�Ƃ͂ł��܂���B<br>
 * \sa CriAtomExMonitorDataUpdateNotificationCbFunc, CriAtomExMonitorDataUpdateNotificationInfo
 */
void CRIAPI criAtomExMonitor_SetDataUpdateNotificationCallback(
	CriAtomExMonitorDataUpdateNotificationCbFunc func, void *obj);

/***************************************************************************
 *      ���o�[�W�����Ƃ̌݊��p
 *      For compatibility with old version
 ***************************************************************************/
#define CRIATOMEX_MONITOR_VERSION				(0xFFFFFFFF)

#ifdef __cplusplus
}
#endif

#endif //	CRI_INCL_CRI_ATOMEX_MONITOR_H
