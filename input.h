//=============================================================================
//
// ���͏��� [input.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

// �v���O������������Ƃ��Ɏg��
#define	USE_KEYBOARD										// �錾����ƃL�[�{�[�h�ő���\�ɂȂ�
#define	USE_MOUSE											// �錾����ƃ}�E�X�ő���\�ɂȂ�
#define	USE_PAD												// �錾����ƃp�b�h�ő���\�ɂȂ�


/* game pad��� */
#define BUTTON_UP		0x00000001l	// �����L�[��(.IY<0)
#define BUTTON_DOWN		0x00000002l	// �����L�[��(.IY>0)
#define BUTTON_LEFT		0x00000004l	// �����L�[��(.IX<0)
#define BUTTON_RIGHT	0x00000008l	// �����L�[�E(.IX>0)
#define BUTTON_A		0x00000010l	// �`�{�^��(.rgbButtons[0]&0x80)
#define BUTTON_B		0x00000020l	// �a�{�^��(.rgbButtons[1]&0x80)
#define BUTTON_X		0x00000040l	// �b�{�^��(.rgbButtons[2]&0x80)	
#define BUTTON_Y		0x00000080l	// �w�{�^��(.rgbButtons[3]&0x80)	
#define BUTTON_LB		0x00000100l	// �x�{�^��(.rgbButtons[4]&0x80)	
#define BUTTON_RB		0x00000200l	// �y�{�^��(.rgbButtons[5]&0x80)	
#define BUTTON_BACK		0x00000400l	// �k�{�^��(.rgbButtons[6]&0x80)
#define BUTTON_START	0x00000800l	// �q�{�^��(.rgbButtons[7]&0x80)
#define BUTTON_R		0x00001000l	// �r�s�`�q�s�{�^��(.rgbButtons[8]&0x80)
#define BUTTON_M		0x00002000l	// �l�{�^��(.rgbButtons[9]&0x80)
#define GAMEPADMAX		4			// �����ɐڑ�����W���C�p�b�h�̍ő吔���Z�b�g


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitInput(HINSTANCE hInst, HWND hWnd);
void UninitInput(void);
void UpdateInput(void);

//---------------------------- keyboard
bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);
bool Keyboard_IsRepeat(int nKey);
bool Keyboard_IsRelease(int nKey);

//---------------------------- mouse
BOOL Mouse_IsLeftPress(void);      // ���N���b�N�������
BOOL Mouse_IsLeftTrigger(void);    // ���N���b�N�����u��
BOOL Mouse_IsRightPress(void);     // �E�N���b�N�������
BOOL Mouse_IsRightTrigger(void);   // �E�N���b�N�����u��
BOOL Mouse_IsCenterPress(void);    // ���N���b�N�������
BOOL Mouse_IsCenterTrigger(void);  // ���N���b�N�����u��
long Mouse_GetMoveX(void);         // �}�E�X��X�����ɓ��������Βl
long Mouse_GetMoveY(void);         // �}�E�X��Y�����ɓ��������Βl
long Mouse_GetMoveZ(void);         // �}�E�X�z�C�[�������������Βl

//---------------------------- game pad
BOOL GamePad_IsButtonPress(int padNo,DWORD button);
BOOL GamePad_IsButtonTrigger(int padNo,DWORD button);

void UpdateMouseCursor(bool vaild);


