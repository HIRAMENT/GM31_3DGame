#include "main.h"
#include "renderer.h"
#include "resource.h"
#include "player.h"
#include "debugCamera.h"
#include "scene.h"
#include "particle.h"
#include "particleManager.h"

DebugCamera::DebugCamera(Scene * scene, D3DXVECTOR3 pos, int drawpriority)
	:Camera(scene,pos,drawpriority)
{
	m_Type = ObjectType::eObDebugCamera;
	m_Player = nullptr;
	//CreateParticle();
	scene->Add(this);
}

void DebugCamera::Update()
{
	if (m_Player == nullptr)
	{
		m_Player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	}
	m_Position = m_Player->GetPosition() + D3DXVECTOR3(0.0f, 30.0f, -1.0f);
	m_Target = m_Player->GetPosition();
}

void DebugCamera::Draw()
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

void DebugCamera::CreateParticle()
{
	ParticleInfo info;
	info.m_Position = { 0.0f,-9.0f,1.0f };
	info.m_TextureTag = ResourceTag::tParticleHeart;
	info.m_DrawPriority = 2;
	info.m_ProductionInterval = 5.0f;
	info.m_BlendMode = BlendMode::MULTIPLE;
	info.m_ProductionType = ProductionType::Region;
	info.m_ProductionPosMin = D3DXVECTOR3(-7.0f, 5.0f, 10.0f);
	info.m_ProductionPosMax = D3DXVECTOR3( 3.0f, 5.0f, 10.0f);
	info.m_is2Dimension = false;
	info.m_isCurve = true;
	info.m_isBillboard = false;
	info.m_ProductionOnes = false;
	info.m_CurveRateMin = -1.0f;
	info.m_CurveRateMax = 1.0f;
	info.m_AngleMin = 45;
	info.m_AngleMax = 90;
	info.m_LifeSpanMin = 3.0f;
	info.m_LifeSpanMax = 5.0f;
	info.m_ProductionMin = 100;
	info.m_ProductionMax = 150;
	info.m_ScaleMin = 0.1f;
	info.m_ScaleMax = 2.0f;
	info.m_SpeedMin = 0.05f;
	info.m_SpeedMax = 0.1f;
	info.m_RotationMin = 0.02f;
	info.m_RotationMax = 0.04f;
	info.m_RedMin = 0.0f;
	info.m_RedMax = 1.0f;
	info.m_GreenMin = 0.0f;
	info.m_GreenMax = 1.0f;
	info.m_BlueMin = 0.0f;
	info.m_BlueMax = 1.0f;
	info.m_AlphaMin = 0.5f;
	info.m_AlphaMax = 1.0f;
	info.m_GravityUse = true;
	info.m_Gravity = D3DXVECTOR3(0.0f, 0.001f, 0.0f);
	m_PManager = new ParticleManager(GetScene(), &info);
}
