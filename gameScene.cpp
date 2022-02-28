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
#include "meshField.h"
#include "gameCamera.h"
#include "debugCamera.h"
#include "animationModel.h"
#include "model.h"
#include "player.h"
#include "smallEnemy.h"
#include "bossEnemy.h"
#include "skydome.h"
#include "rock.h"
#include "tree.h"
#include "sensor.h"
#include "gameScene.h"
#include "resultScene.h"
#include "status.h"
#include "hitPoint.h"
#include "box.h"
#include "collision.h"
#include "calculation.h"

#define PHASE_MAX (1)

void GameScene::Init()
{
	m_DebugCamera = new DebugCamera(this, { 0.0f,5.0f,-20.0f }, 2);
	m_DebugCamera->SetUse(false);
	m_GameCamera = new GameCamera(this, { 0.0f,5.0f,-20.0f }, 2);
	m_GameCamera->SetUse(true);
	m_CameraType = ObjectType::eObCamera;

	std::vector<D3DXVECTOR3> objectPos;

	new MeshField({ this, {0.0f,0.0f,0.0f}, 1 });
	new Skydome(this, { 0.0f,0.0f,0.0f }, 1);
	new Player(this, { 0.0f,0.0f,-10.0f }, 2);
	objectPos.push_back(D3DXVECTOR3(0.0f, 0.0f, -10.0f));
	
	srand(time(NULL));

	D3DXVECTOR3 pos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 rot(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 sca(0.0f, 0.0f, 0.0f);
	float pom = 1;

	for (int i = 0; i < 25; i++)
	{
		pos.x = rand() % 60 - 30;
		pos.z = rand() % 60 - 30;
		new SmallEnemy(this, { pos.x,1.0f,pos.z }, 2);
		objectPos.push_back(D3DXVECTOR3(pos.x, 0.0f, pos.z));
	}

  	for (int i = 0; i < 35; i++)
	{
		pos.x = rand() % 150 - 75;
		pos.z = rand() % 150 - 75;
		
		for (D3DXVECTOR3 opos : objectPos)
		{
			if (Collision::GetInstance()->CheckCircle(pos, opos, 5.0f))
			{
				pom = Calculation::GetInstance()->RandomSign();
				pos.x += (rand() % 5 + 5) * pom;
				pos.y += (rand() % 5 + 5) * pom;
			}
		}

		if (pos.x <= 5.0f && pos.x >= -5.0f)
		{
			if (pos.z >= -15.0f && pos.z <= -5.0f)
			{
				pom = Calculation::GetInstance()->RandomSign();
				pos.x += (rand() % 5 + 5) * pom;
				pos.y += (rand() % 5 + 5) * pom;
			}
		}

		rot.x = degToRad(rand() % 360);
		rot.y = degToRad(rand() % 360);
		rot.z = degToRad(rand() % 360);
		sca.x    = rand() % 5 + 1;
		sca.y    = rand() % 5 + 1;
		sca.z    = rand() % 5 + 1;
		new Rock(this, { pos.x,1.f,pos.z }, { rot.x,rot.y,rot.z }, { sca.x, sca.y, sca.z }, 2);
		objectPos.push_back(D3DXVECTOR3(pos.x, 0.0f, pos.z));
	}

	for (int i = 0; i < 50; i++)
	{
		pos.x = rand() % 150 - 75;
		pos.z = rand() % 150 - 75;

		for (D3DXVECTOR3 opos : objectPos)
		{
			if (Collision::GetInstance()->CheckCircle(pos, opos, 5.0f))
			{
				pom = Calculation::GetInstance()->RandomSign();
				pos.x += (rand() % 5 + 5) * pom;
				pos.y += (rand() % 5 + 5) * pom;
			}
		}

		if (pos.x <= 5.0f && pos.x >= -5.0f)
		{
			if (pos.z >= -15.0f && pos.z <= -5.0f)
			{
				pom = Calculation::GetInstance()->RandomSign();
				pos.x += (rand() % 5 + 5) * pom;
				pos.y += (rand() % 5 + 5) * pom;
			}
		}
		new Tree(this, { pos.x,0.0,pos.z }, { 3.0f,3.0f,3.0f }, 2);
		objectPos.push_back(D3DXVECTOR3(pos.x, 0.0f, pos.z));
	}

	m_PhaseCount = 0;

	Manager::GetInstance()->SetCursorEnable(true);

	m_BGMID = ADXSound::GetInstance()->Play(1);
}

void GameScene::Update()
{
	Scene::Update();

	if (Keyboard_IsTrigger(DIK_0))
	{
		if (m_CameraType == ObjectType::eObCamera)
		{
			m_CameraType = ObjectType::eObDebugCamera;
			m_GameCamera->SetUse(false);
			m_DebugCamera->SetUse(true);
		}
		else
		{
			m_CameraType = ObjectType::eObCamera;
			m_GameCamera->SetUse(true);
			m_DebugCamera->SetUse(false);
		}
	}

	if (m_PhaseCount < PHASE_MAX && GetGameObjects<Enemy>(ObjectType::eObEnemy).size() == 0)
	{
		D3DXVECTOR3 pos;
		m_PhaseCount++;
		if (m_PhaseCount < PHASE_MAX) 
		{
			for (int i = 0; i < 15; i++)
			{
				pos.x = rand() % 60 - 30;
				pos.z = rand() % 60 - 30;
				new SmallEnemy(this, { pos.x,1.0f,pos.z }, 2);
			}
		}
		else if (m_PhaseCount == PHASE_MAX) 
		{
			new BossEnemy(this, { 0.0f, 3.0f,10.0f }, 2);
		}
	}
	if (m_PhaseCount == PHASE_MAX && !GetGameObject<Enemy>(ObjectType::eObEnemy)) 
	{
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		ResultScene::SetClear(true);
	}
	if (GetGameObject<Player>(ObjectType::eObPlayer)->GetisDead())
	{
		Fade::GetInstance()->FadeIn(SceneTag::eResult);
		Fade::GetInstance()->SetColor({ 1.0f,0.0f,0.0f });
		ResultScene::SetClear(false);
	}
}


void GameScene::Draw()
{
	std::list<GameObject*> obj = m_GameObject;
	D3DXVECTOR3 cpos = GetGameObject<Camera>(m_CameraType)->GetPosition();
	obj.sort([cpos](GameObject* obj1, GameObject* obj2)
	{
		if (obj1->GetDrawPriority() > 100)
		{
			return false;
		}
		else if (obj2->GetDrawPriority() > 100) 
		{
			return true;
		}

		D3DXVECTOR3 vec1 = obj1->GetPosition() - cpos;
		float len1 = D3DXVec3Length(&vec1);

		D3DXVECTOR3 vec2 = obj2->GetPosition() - cpos;
		float len2 = D3DXVec3Length(&vec2);

		if (len1 < len2) 
		{
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
