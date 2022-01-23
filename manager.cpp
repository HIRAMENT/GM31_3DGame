#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
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


// 初期化
void Manager::Init()
{
	Renderer::GetInstance()->Init();		// ここでDirectXの初期化をしているのでこの後に書かないと動かない
	Audio::InitMaster();
	ResourceData::GetInstance()->Init();
	MyImGui::GetInstance()->Init();

	Fade::GetInstance();

	SetScene(SceneTag::eGame);
}

// 終了処理
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

// 更新処理
void Manager::Update()
{
	MyImGui::GetInstance()->UpdateStart();

	// マウス関連
	if (Keyboard_IsTrigger(DIK_2)) {
		m_CursorEnable = (m_CursorEnable + 1) % 2;
	}

	HWND hWnd = GetActiveWindow();
	if (GetWindow() != hWnd) {
		m_CursorEnable = false;
	}

	UpdateMouseCursor(m_CursorEnable);
	

	m_Scene->Update();
	Fade::GetInstance()->Update();

	//Information::GetInstance()->Display();

	MyImGui::GetInstance()->UpdateEnd();
}

// 描画処理
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

