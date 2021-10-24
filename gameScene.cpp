#include "main.h"
#include <time.h>
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "ADX2/adxSound.h"
#include "audio.h"
#include "fade.h"
#include "gameObject.h"
#include "polygon2D.h"
#include "field.h"
#include "meshField.h"
#include "camera.h"
#include "animationModel.h"
#include "model.h"
#include "player.h"
#include "smallEnemy.h"
#include "bossEnemy.h"
#include "skydome.h"
#include "sword.h"
#include "rock.h"
#include "tree.h"
#include "sensor.h"
#include "gameScene.h"
#include "resultScene.h"


void GameScene::Init()
{
	new Camera(this, { 0.0f,5.0f,-20.0f }, 0);
	//new Field(this, { 0.0f,0.0f,0.0f }, 1);
	new MeshField({ this, {0.0f,0.0f,0.0f}, 1 });
	new Skydome(this, { 0.0f,0.0f,0.0f }, 1);
	new Player(this, { 0.0f,1.0f,-10.0f }, 2);
	new SmallEnemy(this, { -10.0f,1.0f,5.0f }, 2);
	new SmallEnemy(this, { 0.0f,1.0f,5.0f }, 2);
	new SmallEnemy(this, { 10.0f,1.0f,5.0f }, 2);
	new BossEnemy(this, { 0.0f, 3.0f,20.0f }, 2);

	srand(time(NULL));

	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 sca;
	for (int i = 0; i < 50; i++)
	{
		pos.x = rand() % 150 - 75;
		pos.z = rand() % 150 - 75;
		if (pos.x <= 2.0f && pos.x >= -2.0f)
		{
			if (pos.z >= -12.0f && pos.z <= -8.0f)
			{
				pos.x += 3.0f;
				pos.z += 3.0f;
			}
		}
		rot.x = degToRad(rand() % 360);
		rot.y = degToRad(rand() % 360);
		rot.z = degToRad(rand() % 360);
		sca.x    = rand() % 5 + 1;
		sca.y    = rand() % 5 + 1;
		sca.z    = rand() % 5 + 1;
		new Rock(this, { pos.x,0.f,pos.z }, { rot.x,rot.y,rot.z }, { sca.x, sca.y, sca.z }, 2);
	}

	for (int i = 0; i < 100; i++)
	{
		pos.x = rand() % 150 - 75;
		pos.z = rand() % 150 - 75;
		new tree(this, { pos.x,9.5f,pos.z }, { 20.0f,20.0f,20.0f }, 2);
	}

	m_BGMID = ADXSound::GetInstance()->Play(1);
}

void GameScene::Update()
{
	Scene::Update();

	POINT ScreenPoint;
	GetCursorPos(&ScreenPoint);
	ScreenPoint = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SetCursorPos(ScreenPoint.x, ScreenPoint.y);
	ShowCursor(false);


	if (Keyboard_IsTrigger(DIK_SPACE))
	{
		new SmallEnemy(this, GetGameObject<BossEnemy>(ObjectType::eObBossEnemy)->GetUp() * 7.0f, 5);
	}

	if (!GetGameObject<Enemy>(ObjectType::eObBossEnemy))
	{
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		ResultScene::SetClear(true);
	}
	if (GetGameObject<Player>(ObjectType::eObPlayer)->GetHP() <= 0)
	{
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		Fade::GetInstance()->SetColor({ 1.0f,0.0f,0.0f });
		ResultScene::SetClear(false);
	}
}

void GameScene::Uninit()
{
	ADXSound::GetInstance()->Stop(m_BGMID);

	Scene::Uninit();
}
