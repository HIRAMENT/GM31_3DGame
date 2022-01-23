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
#include "gameCamera.h"
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
#include "status.h"
#include "hitPoint.h"

#define PHASE_MAX (1)

void GameScene::Init()
{
	new GameCamera(this, { 0.0f,5.0f,-20.0f }, 2);
	new MeshField({ this, {0.0f,0.0f,0.0f}, 1 });
	new Skydome(this, { 0.0f,0.0f,0.0f }, 1);
	new Player(this, { 0.0f,0.0f,-10.0f }, 2);

	srand(time(NULL));

	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 sca;

	for (int i = 0; i < 15; i++)
	{
		pos.x = rand() % 60 - 30;
		pos.z = rand() % 60 - 30;
		new SmallEnemy(this, { pos.x,1.0f,pos.z }, 2);
	}

	//new SmallEnemy(this, { -6.0f,1.0f,0.0f }, 2);
	//new SmallEnemy(this, { 6.0f,1.0f,0.0f }, 2);


	for (int i = 0; i < 50; i++)
	{
		pos.x = rand() % 150 - 75;
		pos.z = rand() % 150 - 75;
		if (pos.x <= 8.0f && pos.x >= -8.0f)
		{
			if (pos.z >= -18.0f && pos.z <= -2.0f)
			{
				pos.x += 8.0f;
				pos.z += 8.0f;
			}
		}
		rot.x = degToRad(rand() % 360);
		rot.y = degToRad(rand() % 360);
		rot.z = degToRad(rand() % 360);
		sca.x    = rand() % 5 + 1;
		sca.y    = rand() % 5 + 1;
		sca.z    = rand() % 5 + 1;
		//new Rock(this, { pos.x,1.f,pos.z }, { rot.x,rot.y,rot.z }, { sca.x, sca.y, sca.z }, 2);
	}

	//for (int i = 0; i < 50; i++)
	//{
	//	pos.x = rand() % 150 - 75;
	//	pos.z = rand() % 150 - 75;
	//	new tree(this, { pos.x,9.5f,pos.z }, { 20.0f,20.0f,20.0f }, 2);
	//}

	m_PhaseCount = 0;

	Manager::GetInstance()->SetCursorEnable(true);

	m_BGMID = ADXSound::GetInstance()->Play(1);
}

void GameScene::Update()
{
	Scene::Update();

	if (m_PhaseCount < PHASE_MAX && GetGameObjects<Enemy>(ObjectType::eObEnemy).size() == 0)
	{
		D3DXVECTOR3 pos;
		m_PhaseCount++;
		if (m_PhaseCount < PHASE_MAX) {
			for (int i = 0; i < 15; i++)
			{
				pos.x = rand() % 60 - 30;
				pos.z = rand() % 60 - 30;
				//new SmallEnemy(this, { pos.x,1.0f,pos.z }, 2);
			}
		}
		else if (m_PhaseCount == PHASE_MAX) {
			new BossEnemy(this, { 0.0f, 3.0f,20.0f }, 2);
		}

		new SmallEnemy(this, { 0.0f,1.0f,0.0f }, 2);
		
	}
	if (m_PhaseCount == PHASE_MAX && !GetGameObject<Enemy>(ObjectType::eObEnemy)) {
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		ResultScene::SetClear(true);
	}
	if (GetGameObject<Player>(ObjectType::eObPlayer)->GetStatus()->GetHitPoint()->GetHitPoint() <= 0)
	{
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		Fade::GetInstance()->SetColor({ 1.0f,0.0f,0.0f });
		ResultScene::SetClear(false);
	}
}


void GameScene::Draw()
{
	std::list<GameObject*> obj = m_GameObject;
	D3DXVECTOR3 cpos = GetGameObject<Camera>(ObjectType::eObCamera)->GetPosition();
	obj.sort([cpos](GameObject* obj1, GameObject* obj2)
	{
		if (obj1->GetDrawPriority() > 100){
			return false;
		}
		else if (obj2->GetDrawPriority() > 100) {
			return true;
		}

		D3DXVECTOR3 vec1 = obj1->GetPosition() - cpos;
		float len1 = D3DXVec3Length(&vec1);

		D3DXVECTOR3 vec2 = obj2->GetPosition() - cpos;
		float len2 = D3DXVec3Length(&vec2);

		if (len1 < len2) {
			return true;
		}

		return false;
	});

	for (GameObject* object : obj)
	{
		object->Draw();
	}
}


void GameScene::Uninit()
{
	ADXSound::GetInstance()->Stop(m_BGMID);

	Scene::Uninit();
}
