#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "scene.h"
#include "titleCamera.h"

TitleCamera::TitleCamera(Scene * scene, D3DXVECTOR3 pos, int drawpriority)
	: Camera(scene, pos, drawpriority)
{
	scene->Add(this);
}

void TitleCamera::Update()
{
	if (Keyboard_IsPress(DIK_UP))
	{
		m_Position.y -= 0.1f;
	}
	if (Keyboard_IsPress(DIK_DOWN))
	{
		m_Position.y += 0.1f;
	}
	if (Keyboard_IsPress(DIK_RIGHT))
	{
		m_Position.x -= 0.1f;
	}
	if (Keyboard_IsPress(DIK_LEFT))
	{
		m_Position.x += 0.1f;
	}
}
