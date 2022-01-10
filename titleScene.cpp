#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "calculation.h"
#include "polygon2D.h"
#include "polygon3D.h"
#include "input.h"
#include "ADX2/adxSound.h"
#include "fade.h"
#include "titleCamera.h"
#include "rock.h"
#include "button.h"
#include "particle.h"
#include "particleManager.h"
#include "titleScene.h"
#include "tutorialScene.h"

void TitleScene::Init()
{
	new TitleCamera(this, D3DXVECTOR3(0.0f, 0.0f, -10.0f), 2);

	m_BG = new Polygon3D(this, { 0.0f,0.0f,10.0f }, { 29.5f,16.5f,0.0f }, ResourceTag::tTitleTemp, true, false, 2);
	m_BG->SetShaderType(ShaderType::UNLIT);
	m_TitleName = new Polygon3D(this, { 0.0f,1.0f,-3.0f }, { 9.5f,2.5f,0.0f }, ResourceTag::tTitleName, true, false, 3);
	m_TitleName->SetTextureTagSecond(ResourceTag::tTitleSphare);
	m_TitleName->SetShaderType(ShaderType::ENVIROMENT);
	m_StartButton = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.7f }, { 256, 64 }, ResourceTag::tStartLetter, 101);
	m_ExitButton  = new Button(this, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.9f }, { 256, 64 }, ResourceTag::tEndLetter, 101);

	CreateParticle();

	m_Select = 0;

	m_CursorEnter = false;

	m_BGMID = ADXSound::GetInstance()->Play(0);
}

void TitleScene::Update()
{
	Scene::Update();

	// マウスでの選択
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
	// キーボードでの選択
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
	// 決定
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

void TitleScene::CreateParticle()
{
	ParticleInfo info;
	info.m_Position = { 0.0f,-9.0f,1.0f };
	info.m_TextureTag = ResourceTag::tParticleCircle;
	info.m_DrawPriority = 2;
	info.m_ProductionInterval = 7.0f;
	info.m_BlendMode = BlendMode::ADDITION;
	info.m_ProductionType = ProductionType::Region;
	info.m_ProductionPosMin = D3DXVECTOR3(-7.0f, -3.0f, -5.0f);
	info.m_ProductionPosMax = D3DXVECTOR3( 7.0f,  3.0f,  5.0f);
	info.m_is2Dimension = false;
	info.m_isCurve = true;
	info.m_CurveRateMin = -1.0f;
	info.m_CurveRateMax = 1.0f;
	info.m_AngleMin = 90;
	info.m_AngleMax = 90;
	info.m_LifeSpanMin = 5.0f;
	info.m_LifeSpanMax = 10.0f;
	info.m_ProductionMin = 50;
	info.m_ProductionMax = 100;
	info.m_ScaleMin = 0.1f;
	info.m_ScaleMax = 0.3f;
	info.m_SpeedMin = 0.03f;
	info.m_SpeedMax = 0.08f;
	info.m_RotationMin = 0.01f;
	info.m_RotationMax = 0.05f;
	info.m_RedMin = 1.0f;
	info.m_RedMax = 1.0f;
	info.m_GreenMin = 0.0f;
	info.m_GreenMax = 1.0f;
	info.m_BlueMin = 0.0f;
	info.m_BlueMax = 0.0f;
	info.m_GravityUse = false;
	info.m_Gravity = D3DXVECTOR3(0.0f, -0.001f, 0.0f);
	new ParticleManager(this, &info);
}

