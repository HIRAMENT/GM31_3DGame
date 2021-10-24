#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "polygon2D.h"
#include "input.h"
#include "ADX2/adxSound.h"
#include "fade.h"
#include "tutorialScene.h"

unsigned int TutorialScene::m_tBGMID;

void TutorialScene::Init()
{
	m_BG = new Polygon2D(this, { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f }, { SCREEN_WIDTH,SCREEN_HEIGHT }, ResourceTag::tTutorial, 10);
}

void TutorialScene::Update()
{
	Scene::Update();

	if (Keyboard_IsTrigger(DIK_SPACE))
	{
		ADXSound::GetInstance()->Play(5);
		Fade::GetInstance()->FadeIn(SceneTag::eGame);
	}
}

void TutorialScene::Uninit()
{
	ADXSound::GetInstance()->Stop(m_tBGMID);

	Scene::Uninit();
}
