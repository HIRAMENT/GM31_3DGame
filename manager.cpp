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
#include "myImGui.h"
#include "ImGUI/imgui.h"
#include "information.h"


// ‰Šú‰»
void Manager::Init()
{
	Renderer::GetInstance()->Init();		// ‚±‚±‚ÅDirectX‚Ì‰Šú‰»‚ð‚µ‚Ä‚¢‚é‚Ì‚Å‚±‚ÌŒã‚É‘‚©‚È‚¢‚Æ“®‚©‚È‚¢
	Audio::InitMaster();
	ResourceData::GetInstance()->Init();
	MyImGui::GetInstance()->Init();

	Fade::GetInstance();

	SetScene(SceneTag::eGame);
}

// I—¹ˆ—
void Manager::Uninit()
{
	m_Scene->Uninit();
	delete m_Scene;

	MyImGui::GetInstance()->Uninit();
	Fade::GetInstance()->Uninit();
	Audio::UninitMaster();
	ResourceData::GetInstance()->Uninit();
	Renderer::GetInstance()->Uninit();
}

// XVˆ—
void Manager::Update()
{
	MyImGui::GetInstance()->UpdateStart();

	m_Scene->Update();
	Fade::GetInstance()->Update();

	Information::GetInstance()->Display();

	MyImGui::GetInstance()->UpdateEnd();
}

// •`‰æˆ—
void Manager::Draw()
{
	Renderer::GetInstance()->Begin();

	m_Scene->Draw();
	Fade::GetInstance()->Draw();
	MyImGui::GetInstance()->Draw();

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

