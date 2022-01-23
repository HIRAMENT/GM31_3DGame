#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "obb.h"
#include "status.h"
#include "scene.h"
#include "input.h"
#include "player.h"
#include "enemy.h"
#include "skydome.h"
#include "movement.h"
#include <algorithm>
#include "gameCamera.h"
#include "targetMark.h"

GameCamera::GameCamera(Scene * scene, D3DXVECTOR3 pos, int drawpriority)
	: Camera(scene, pos, drawpriority)
{
	m_TargetMarker = new TargetMark(scene, this, 5);
	m_Player = nullptr;
	m_Angle3D = { -90,60 };
	scene->Add(this);
}

void GameCamera::Update()
{
	if (Keyboard_IsPress(DIK_UP))
	{
		m_Angle3D.y -= 1.0f;
		if (m_Angle3D.y <= 0) m_Angle3D.y = 0;
	}
	if (Keyboard_IsPress(DIK_DOWN))
	{
		m_Angle3D.y += 1.0f;
		if (m_Angle3D.y >= 180) m_Angle3D.y = 180;
	}
	if (Keyboard_IsPress(DIK_RIGHT))
	{
		m_Angle3D.x -= 1.0f;
		if (m_Angle3D.x < -90) m_Angle3D.x = 270;
	}
	if (Keyboard_IsPress(DIK_LEFT))
	{
		m_Angle3D.x += 1.0f;
		if (m_Angle3D.x > 270) m_Angle3D.x = -90;
	}

	if (m_Player == nullptr)
	{
		m_Player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	}

	D3DXVECTOR3 cpv = m_Player->GetPosition() - m_Position;
	D3DXVec3Normalize(&cpv, &cpv);
	m_Target = m_Player->GetPosition() + D3DXVECTOR3(cpv.x, 0.0f, cpv.z) * 5.0f;

	// Fキー(仮)を押したら一番近い敵をターゲットする
	if (Keyboard_IsTrigger(DIK_F)) {
		if (!m_TargetMarker->isSetingTarget()) {
			std::vector<Enemy*> enemys = GetScene()->GetGameObjects<Enemy>(ObjectType::eObSmallEnemy);
			float dist, nearest = 1000.0f;
			for (auto enemy : enemys) {
				dist = D3DXVec3Length(&(m_Player->GetPosition() - enemy->GetPosition()));
				if (nearest > dist) {
					nearest = dist;
					m_TargetMarker->SetTarget(enemy);
				}
			}
		}
		else {
			m_TargetMarker->ResetTarget();
		}

		// プレイヤーとエネミーを通る直線を見る
	}

	if (m_TargetMarker->isSetingTarget()) {
		if (m_TargetMarker->GetTargetObj()->GetDestroy()) {
			m_TargetMarker->ResetTarget();
		}
		else {
			D3DXVECTOR3 tv = m_TargetMarker->GetTargetObj()->GetPosition() - m_Player->GetPosition();
			D3DXVec3Normalize(&tv, &tv);
			m_Position = m_Player->GetPosition() - tv * 10.0f + D3DXVECTOR3(0.0f, 10.0f, 0.0f);
		}
	}
	else {
		D3DXVECTOR2 mouseMove;
		mouseMove.x = Mouse_GetMoveX();
		mouseMove.y = Mouse_GetMoveY();

		if (mouseMove.x != 0)
		{
			m_Angle3D.x -= mouseMove.x * 0.05f;
			if (m_Angle3D.x < -90) m_Angle3D.x = 270;
			if (m_Angle3D.x > 270) m_Angle3D.x = -90;
		}
		if (mouseMove.y != 0)
		{
			m_Angle3D.y -= mouseMove.y * 0.05f;
			if (m_Angle3D.y <= 0) m_Angle3D.y = 0;
			if (m_Angle3D.y >= 180) m_Angle3D.y = 180;
		}

		D3DXVECTOR3 movepos = Movement::GetInstance()->CirclualMotion3D(m_Target, m_Distance, m_Angle3D);
		m_Position = movepos;
	}

	Skydome* skydome = GetScene()->GetGameObject<Skydome>(ObjectType::eObSkydome);
	//skydome->SetPosition(m_Position);
}
