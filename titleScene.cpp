#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "polygon2D.h"
#include "input.h"
#include "ADX2/adxSound.h"
#include "fade.h"
#include "button.h"
#include "titleScene.h"
#include "tutorialScene.h"

void TitleScene::Init()
{
	m_BG = new Polygon2D(this, { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f}, { SCREEN_WIDTH,SCREEN_HEIGHT }, ResourceTag::tTitleBG, 100);
	m_TitleName  = new Polygon2D(this, { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.25f }, { 640.f,128.f }, ResourceTag::tTitleName, 101);
	m_StartButton = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.7f }, { 256, 64 }, ResourceTag::tStartLetter, 101);
	m_ExitButton  = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.9f }, { 256, 64 }, ResourceTag::tEndLetter, 101);

	m_Select = 0;

	m_CursorEnter = false;

	m_BGMID = ADXSound::GetInstance()->Play(0);
}

void TitleScene::Update()
{
	Scene::Update();

	POINT mouse = {};
	GetCursorPos(&mouse);
	ScreenToClient(GetWindow(), &mouse);
	if (m_StartButton->CursorEnter(mouse)) 
	{
		if (m_Select != 0) {
			m_Select = 0;
			ADXSound::GetInstance()->Play(4);
		}
		m_CursorEnter = true;
	}
	else if (m_ExitButton->CursorEnter(mouse)) 
	{
		if (m_Select != 1) {
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
		m_StartButton->HaveSelect(true);
		m_ExitButton->HaveSelect(false);
		break;
	case 1:
		m_StartButton->HaveSelect(false);
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
			TutorialScene::SetBGMID(m_BGMID);
			Fade::GetInstance()->FadeIn(SceneTag::eTutorial);
			Fade::GetInstance()->SetColor({ 1.0f, 1.0f, 1.0f });
			m_StartButton->HaveClick(true);
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

void TitleScene::Uninit()
{
	Scene::Uninit();
}
