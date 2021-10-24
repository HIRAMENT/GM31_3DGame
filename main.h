#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NOMINMAX
#include <windows.h>
#include <assert.h>



#pragma warning(push)
#pragma warning(disable:4005)

#define DIRECTINPUT_VERSION 0x0800
#include <d3d11.h>
#include <d3dx9.h>
#include <d3dx11.h>
#include <xinput.h>
#include "dinput.h"

#pragma warning(pop)



#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "xinput.lib")


#define SCREEN_WIDTH	(960)
#define SCREEN_HEIGHT	(540)


HWND GetWindow();
