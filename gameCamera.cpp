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

	// マウスホイールを押したら一番近い敵をターゲットする
	if (Keyboard_IsRelease(DIK_F))
	{
		if (!m_TargetMarker->isSetingTarget()) 
		{
			std::vector<Enemy*> enemys = GetScene()->GetGameObjects<Enemy>(ObjectType::eObEnemy);
			float dist, nearest = 1000.0f;
			for (auto enemy : enemys) 
			{
				dist = D3DXVec3Length(&(m_Player->GetPosition() - enemy->GetPosition()));
				if (nearest > dist) 
				{
					nearest = dist;
					m_TargetMarker->SetTarget(enemy);
				}
			}
		}
		else 
		{
			m_TargetMarker->ResetTarget();
		}
	}

	D3DXVECTOR3 circlecenter;
	D3DXVECTOR3 cpv = m_Player->GetPosition() - m_Position;
	D3DXVec3Normalize(&cpv, &cpv);

	if (m_TargetMarker->isSetingTarget()) 
	{
		D3DXVECTOR3 ptv = m_TargetMarker->GetTargetObj()->GetPosition() - m_Player->GetPosition();
		D3DXVECTOR3 ctv = m_TargetMarker->GetTargetObj()->GetPosition() - m_Position;
		D3DXVec3Normalize(&ptv, &ptv);
		D3DXVec3Normalize(&ctv, &ctv);
		float angle_x = Movement::GetInstance()->GetTwoVecAngle(D3DXVECTOR2(0.0f, 1.0f), D3DXVECTOR2(ptv.x, ptv.z));
		float angle_y = Movement::GetInstance()->GetTwoVecAngle(D3DXVECTOR2(1.0f, 0.0f), D3DXVECTOR2(ptv.y, ptv.z));
		if (ptv.x < 0.0f) angle_x *= -1;
		m_Angle3D.x = -90 - D3DXToDegree(angle_x);
		m_Target = m_TargetMarker->GetTargetObj()->GetPosition() - D3DXVECTOR3(ctv.x, 0.0f, ctv.z) * 5.0f;

		circlecenter = m_Player->GetPosition() + D3DXVECTOR3(cpv.x, 0.0f, cpv.z) * 5.0f;
	}
	else
	{
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

		circlecenter = m_Target;
	}

	m_Target = m_Player->GetPosition() + D3DXVECTOR3(cpv.x, 0.0f, cpv.z) * 5.0f;

	D3DXVECTOR3 movepos = Movement::GetInstance()->CirclualMotion3D(circlecenter, m_Distance, m_Angle3D);
	m_Position = movepos;
}

void GameCamera::Draw()
{
	if (m_isUse)
	{
		// ビューマトリクス設定
		D3DXMatrixIdentity(&m_ViewMatrix);
		D3DXMatrixLookAtLH(&m_ViewMatrix, &m_Position, &m_Target, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
		Renderer::GetInstance()->SetViewMatrix(&m_ViewMatrix);

		// プロジェクションマトリクス設定
		D3DXMatrixIdentity(&m_ProjectionMatrix);
		D3DXMatrixPerspectiveFovLH(&m_ProjectionMatrix, degToRad(45),
			(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);  // 最後のは表示範囲の設定
		Renderer::GetInstance()->SetProjectionMatrix(&m_ProjectionMatrix);

		Renderer::GetInstance()->SetCameraPosition(m_Position);
	}
}
