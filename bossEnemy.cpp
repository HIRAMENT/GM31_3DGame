#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "bossEnemy.h"
#include "scene.h"
#include "obb.h"
#include "gauge.h"
#include "status.h"
#include "hitPoint.h"

BossEnemy::BossEnemy(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:Enemy(scene, pos, { 3.f,3.f,3.f }, drawPriority)
	, m_Adjust({ -1.5f,4.0f,1.0f })
{
	m_ModelTag = ResourceTag::mBossEnemy;
	m_Type = EnemyType::Boss;
	m_Size = ResourceData::GetInstance()->GetModelResource(m_ModelTag)->GetSize() * m_Scale;
	m_ObbAdjust = D3DXVECTOR3(0.0f, -0.7, 0.0f);
	m_Obb = new OBB(m_Position, m_Size, m_ObbAdjust, m_Rotation);
	CreateStatus(scene);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(255, 0, 0);
}

void BossEnemy::Init()
{
	Enemy::Init();
}

void BossEnemy::Uninit()
{
	Enemy::Uninit();
}

void BossEnemy::Update()
{
	Enemy::Update();
}

void BossEnemy::Draw()
{
	Enemy::Draw();
}

void BossEnemy::CreateStatus(Scene* scene)
{
	StatusInfo info;
	info.m_AttackCoolTime = 100.0f;
	info.m_AttackPower = 100;
	info.m_DifenceValue = 10;
	info.m_HitPointCoolTime = 30.0f;
	info.m_HitPointDimention = 2;
	info.m_HitPointPos = D3DXVECTOR3(SCREEN_WIDTH / 2, 32, 0);
	info.m_HitPointSize = D3DXVECTOR3(100, 50, 0);
	info.m_HitPointValue = 1000;
	info.m_IsNumberDisplay = true;
	m_Status = new Status(scene, &info);
}
