#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "audio.h"
#include "fade.h"
#include "scene.h"
#include "titleScene.h"
#include "tutorialScene.h"
#include "gameScene.h"
#include "resultScene.h"
#include "resource.h"

// ‰Šú‰»
void Manager::Init()
{
	Renderer::GetInstance()->Init();		// ‚±‚±‚ÅDirectX‚Ì‰Šú‰»‚ð‚µ‚Ä‚¢‚é‚Ì‚Å‚±‚ÌŒã‚É‘‚©‚È‚¢‚Æ“®‚©‚È‚¢
	Audio::InitMaster();
	ResourceData::GetInstance()->Init();
	Fade::GetInstance();

	SetScene(SceneTag::eTitle);
}

// I—¹ˆ—
void Manager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;

	Fade::GetInstance()->Uninit();
	Audio::UninitMaster();
	ResourceData::GetInstance()->Uninit();
	Renderer::GetInstance()->Uninit();
}

// XVˆ—
void Manager::Update()
{
	m_Scene->Update();
	//if (GetCursorPos(GetMousePos()) && ClientToScreen(GetWindow(), GetMousePos()))
	//{
	//	std::string pien = "pien";
	//}
	Fade::GetInstance()->Update();
}

// •`‰æˆ—
void Manager::Draw()
{
	Renderer::GetInstance()->Begin();

	m_Scene->Draw();
	Fade::GetInstance()->Draw();

	Renderer::GetInstance()->End();
}

void Manager::SetScene(SceneTag tag)
{
	if (m_Scene)
	{
		m_Scene->Uninit();
		delete m_Scene;
	}
	
	switch (tag)
	{
	case SceneTag::eTitle:
		m_Scene = new TitleScene();
		break;
	case SceneTag::eTutorial:
		m_Scene = new TutorialScene();
		break;
	case SceneTag::eGame:
		m_Scene = new GameScene();
		break;
	case SceneTag::eResult:
		m_Scene = new ResultScene();
		break;
	default:
		break;
	}

	m_Scene->Init();
}
