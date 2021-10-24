/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 1998 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Middleware Library
 * Module   : CRI Common Header for Windows
 * File     : cri_le_xpt.h
 * Date     : 2013-12-19
 * Version  : 1.17LE
 *
 ****************************************************************************/
#ifndef CRI_INCL_CRI_XPT_H
#define CRI_INCL_CRI_XPT_H

#if defined(__BORLANDC__)
#define XPT_TGT_BCB
#else
#define XPT_TGT_PC
#define XPT_TGT_PC_PRO
#endif

/*****************************************************************************
 * ��{�f�[�^�^�錾
 *****************************************************************************/

#if !defined(_TYPEDEF_CriUint8)
#define _TYPEDEF_CriUint8
typedef unsigned char			CriUint8;		/* �����Ȃ��P�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriSint8)
#define _TYPEDEF_CriSint8
typedef signed char				CriSint8;		/* �������P�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriUint16)
#define _TYPEDEF_CriUint16
typedef unsigned short			CriUint16;		/* �����Ȃ��Q�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriSint16)
#define _TYPEDEF_CriSint16
typedef signed short			CriSint16;		/* �������Q�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriUint32)
#define _TYPEDEF_CriUint32
typedef unsigned long			CriUint32;		/* �����Ȃ��S�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriSint32)
#define _TYPEDEF_CriSint32
typedef signed long				CriSint32;		/* �������S�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriUint64)
#define _TYPEDEF_CriUint64
typedef unsigned __int64		CriUint64;		/* �����Ȃ��W�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriSint64)
#define _TYPEDEF_CriSint64
typedef signed __int64			CriSint64;		/* �������W�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriUint128)
#define _TYPEDEF_CriUint128
typedef struct {								/* �����Ȃ�16�o�C�g���� */
	CriUint64	h;								/* ���64�r�b�g */
	CriUint64	l;								/* ����64�r�b�g */
} CriUint128;
#endif

#if !defined(_TYPEDEF_CriSint128)
#define _TYPEDEF_CriSint128
typedef struct {								/* ������16�o�C�g���� */
	CriSint64	h;								/* ���64�r�b�g */
	CriUint64	l;								/* ����64�r�b�g */
} CriSint128;
#endif

#if !defined(_TYPEDEF_CriFloat16)
#define _TYPEDEF_CriFloat16
typedef signed short			CriFloat16;		/* �Q�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriFloat32)
#define _TYPEDEF_CriFloat32
typedef float					CriFloat32;		/* �S�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriFloat64)
#define _TYPEDEF_CriFloat64
typedef double					CriFloat64;		/* �W�o�C�g���� */
#endif

#if !defined(_TYPEDEF_CriFixed32)
#define _TYPEDEF_CriFixed32
typedef signed long				CriFixed32;		/* �Œ菬���_32�r�b�g */
#endif

#if !defined(_TYPEDEF_CriBool)
#define _TYPEDEF_CriBool
typedef CriSint32				CriBool;		/* �_���^�i�_���萔��l�ɂƂ�j */
#endif

#if !defined(_TYPEDEF_CriChar8)
#define _TYPEDEF_CriChar8
typedef char					CriChar8;		/* �����^ */
#endif

/*****************************************************************************
 * �|�C���^���i�[�\�Ȑ����^
 *****************************************************************************/

#if defined(CRI_WIN64) || defined(_WIN64) || defined(_M_X64)

#if !defined(_TYPEDEF_CriSintPtr)
#define _TYPEDEF_CriSintPtr
typedef signed __int64			CriSintPtr;
#endif

#if !defined(_TYPEDEF_CriUintPtr)
#define _TYPEDEF_CriUintPtr
typedef unsigned __int64		CriUintPtr;
#endif

#else

#if defined(_MSC_VER) && (_MSC_VER >= 1300)

#if !defined(_TYPEDEF_CriSintPtr)
#define _TYPEDEF_CriSintPtr
typedef __w64 signed int		CriSintPtr;
#endif

#if !defined(_TYPEDEF_CriUintPtr)
#define _TYPEDEF_CriUintPtr
typedef __w64 unsigned int		CriUintPtr;
#endif

#else

#if !defined(_TYPEDEF_CriSintPtr)
#define _TYPEDEF_CriSintPtr
typedef CriSint32				CriSintPtr;
#endif

#if !defined(_TYPEDEF_CriUintPtr)
#define _TYPEDEF_CriUintPtr
typedef CriUint32				CriUintPtr;
#endif

#endif

#endif	/* end of _WIN64 */

/*****************************************************************************
 * �萔�}�N��
 * Macros of constant value
 *****************************************************************************/

/* NULL �|�C���^�^ */
#if !defined(CRI_NULL)
#ifdef __cplusplus
#define CRI_NULL	(0)
#else
#define CRI_NULL	((void *)0)
#endif
#endif

/* �_���萔�P�i�U�A�^�j */
#if !defined(CRI_FALSE)
#define CRI_FALSE	(0)
#endif
#if !defined(CRI_TRUE)
#define CRI_TRUE	(1)
#endif

/* �_���萔�Q�i�X�C�b�`�j */
#if !defined(CRI_OFF)
#define CRI_OFF		(0)
#endif
#if !defined(CRI_ON)
#define CRI_ON		(1)
#endif

/* ���ʔ���̒萔�i�����A���s�j */
#if !defined(CRI_OK)
#define CRI_OK		(0)			/* ���� */
#endif
#if !defined(CRI_NG)
#define CRI_NG		(-1)		/* ���s */
#endif

/*****************************************************************************
 * �|�C���^�܂���64�r�b�g�A�h���X���i�[�ł��鐮���^
 * ���l: �|�C���^32bit����ROM�A�h���X���64bit�̊��ŁA���҂𓧉ߓI�Ɉ�����B
 * The integer type which can hold an pointer or an address up to 64 bits.
 * NOTE: In the environment of pointer 32bit and ROM address space 64bit, 
 *       this type can treat both transparently. 
 *****************************************************************************/

#if !defined(_TYPEDEF_CriUint64Adr)
#define _TYPEDEF_CriUint64Adr
typedef CriUint64				CriUint64Adr;		/* �|�C���^�܂���64�r�b�g�A�h���X���i�[�ł��鐮���^ */
#endif

#if !defined(CRI_PTR_TO_UINT64ADR)
#define CRI_PTR_TO_UINT64ADR(ptr)		((CriUint64Adr)(ptr))	/* Convert pointer to CriUint64Adr */
#endif

#if !defined(CRI_UINT64ADR_TO_PTR)
#define CRI_UINT64ADR_TO_PTR(uint64adr)	((void *)(CriUintPtr)(uint64adr))	/* Convert CriUint64Adr to pointer */
#endif

/*****************************************************************************
 * �Ăяo���K��
 *****************************************************************************/

#if !defined(CRIAPI)
#define CRIAPI	__cdecl
#endif

#endif  /* CRI_INCL_CRI_XPT_H */
/* End Of File */
