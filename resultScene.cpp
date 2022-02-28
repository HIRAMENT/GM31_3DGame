#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "ADX2/adxSound.h"
#include "fade.h"
#include "resultScene.h"
#include "polygon2D.h"
#include "button.h"

bool ResultScene::m_Clear;

void ResultScene::Init()
{
	if (m_Clear)
	{
		m_BG = new Polygon2D(this, { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f }, { SCREEN_WIDTH,SCREEN_HEIGHT }, ResourceTag::tGameClear, 10);
		m_TitleName = new Polygon2D(this, { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.25f }, { 640.f,128.f }, ResourceTag::tGameClearLetter, 11);
		m_BGMID = ADXSound::GetInstance()->Play(2);
	}
	else if(!m_Clear)
	{
		m_BG = new Polygon2D(this, { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f }, { SCREEN_WIDTH,SCREEN_HEIGHT }, ResourceTag::tGameOver, 10);
		m_TitleName = new Polygon2D(this, { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.25f }, { 640.f,128.f }, ResourceTag::tGameOverLetter, 11);
		m_BGMID = ADXSound::GetInstance()->Play(3);
	}
	m_ReturnButton = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.7f }, { 256, 64 }, ResourceTag::tReturnTitleLetter, 11);
	m_ExitButton = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.9f }, { 256, 64 }, ResourceTag::tEndLetter, 11);

	m_Select = 0;
	m_CursorEnter = false;

	Manager::GetInstance()->SetCursorEnable(false);
}

void ResultScene::Update()
{
	Scene::Update();

	POINT mouse = {};
	GetCursorPos(&mouse);
	ScreenToClient(GetWindow(), &mouse);
	if (m_ReturnButton->CursorEnter(mouse))
	{
		if (m_Select != 0) 
		{
			m_Select = 0;
			ADXSound::GetInstance()->Play(4);
		}
		m_CursorEnter = true;
	}
	else if (m_ExitButton->CursorEnter(mouse))
	{
		if (m_Select != 1) 
		{
			m_Select = 1;
			ADXSound::GetInstance()->Play(4);
		}
		m_CursorEnter = true;
	}
	else
	{
		m_CursorEnter = false;
	}

	if (Keyboard_IsTrigger(DIK_DOWN))
	{
		m_Select = (m_Select + 1) % m_SelectMax;
		ADXSound::GetInstance()->Play(4);
	}
	if (Keyboard_IsTrigger(DIK_UP))
	{
		m_Select = (m_Select + m_SelectMax - 1) % m_SelectMax;
		ADXSound::GetInstance()->Play(4);
	}

	switch (m_Select)
	{
	case 0:
		m_ReturnButton->HaveSelect(true);
		m_ExitButton->HaveSelect(false);
		break;
	case 1:
		m_ReturnButton->HaveSelect(false);
		m_ExitButton->HaveSelect(true);
		break;
	default:
		break;
	}

	if (Keyboard_IsTrigger(DIK_SPACE) || m_CursorEnter && Mouse_IsLeftTrigger())
	{
		ADXSound::GetInstance()->Play(5);
		switch (m_Select)
		{
		case 0:
			Fade::GetInstance()->FadeIn(SceneTag::eTitle);
			Fade::GetInstance()->SetColor({ 1.0f, 1.0f, 1.0f });
			m_ReturnButton->HaveClick(true);
			break;
		case 1:
			DestroyWindow(GetWindow());
			m_ExitButton->HaveClick(true);
			break;
		default:
			break;
		}
	}
}

void ResultScene::Uninit()
{
	ADXSound::GetInstance()->Stop(m_BGMID);

	Scene::Uninit();
}
