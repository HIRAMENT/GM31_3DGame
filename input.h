//=============================================================================
//
// 入力処理 [input.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

// プログラム分けするときに使う
#define	USE_KEYBOARD										// 宣言するとキーボードで操作可能になる
#define	USE_MOUSE											// 宣言するとマウスで操作可能になる
#define	USE_PAD												// 宣言するとパッドで操作可能になる


/* game pad情報 */
#define BUTTON_UP		0x00000001l	// 方向キー上(.IY<0)
#define BUTTON_DOWN		0x00000002l	// 方向キー下(.IY>0)
#define BUTTON_LEFT		0x00000004l	// 方向キー左(.IX<0)
#define BUTTON_RIGHT	0x00000008l	// 方向キー右(.IX>0)
#define BUTTON_A		0x00000010l	// Ａボタン(.rgbButtons[0]&0x80)
#define BUTTON_B		0x00000020l	// Ｂボタン(.rgbButtons[1]&0x80)
#define BUTTON_X		0x00000040l	// Ｃボタン(.rgbButtons[2]&0x80)	
#define BUTTON_Y		0x00000080l	// Ｘボタン(.rgbButtons[3]&0x80)	
#define BUTTON_LB		0x00000100l	// Ｙボタン(.rgbButtons[4]&0x80)	
#define BUTTON_RB		0x00000200l	// Ｚボタン(.rgbButtons[5]&0x80)	
#define BUTTON_BACK		0x00000400l	// Ｌボタン(.rgbButtons[6]&0x80)
#define BUTTON_START	0x00000800l	// Ｒボタン(.rgbButtons[7]&0x80)
#define BUTTON_R		0x00001000l	// ＳＴＡＲＴボタン(.rgbButtons[8]&0x80)
#define BUTTON_M		0x00002000l	// Ｍボタン(.rgbButtons[9]&0x80)
#define GAMEPADMAX		4			// 同時に接続するジョイパッドの最大数をセット


//*****************************************************************************
// プロトタイプ宣言
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
BOOL Mouse_IsLeftPress(void);      // 左クリックした状態
BOOL Mouse_IsLeftTrigger(void);    // 左クリックした瞬間
BOOL Mouse_IsRightPress(void);     // 右クリックした状態
BOOL Mouse_IsRightTrigger(void);   // 右クリックした瞬間
BOOL Mouse_IsCenterPress(void);    // 中クリックした状態
BOOL Mouse_IsCenterTrigger(void);  // 中クリックした瞬間
long Mouse_GetMoveX(void);         // マウスがX方向に動いた相対値
long Mouse_GetMoveY(void);         // マウスがY方向に動いた相対値
long Mouse_GetMoveZ(void);         // マウスホイールが動いた相対値

//---------------------------- game pad
BOOL GamePad_IsButtonPress(int padNo,DWORD button);
BOOL GamePad_IsButtonTrigger(int padNo,DWORD button);

void UpdateMouseCursor(bool vaild);


