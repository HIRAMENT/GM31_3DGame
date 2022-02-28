#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "model.h"
#include "smallEnemy.h"
#include "player.h"
#include "scene.h"
#include "obb.h"
#include "gauge.h"
#include "status.h"
#include "hitPoint.h"

SmallEnemy::SmallEnemy(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	: Enemy(scene, pos, { 1.f,1.f,1.f }, drawPriority)
	, m_Adjust({ -1.5f,2.0f,0.0f })
{
	m_ModelTag = ResourceTag::mSmallEnemy;
	m_Type = EnemyType::Small;
	m_Size = ResourceData::GetInstance()->GetModelResource(m_ModelTag)->GetSize() * m_Scale;
	m_ObbAdjust = D3DXVECTOR3(0.0f, -0.3f, 0.0f);
	m_Obb = new OBB(m_Position, m_Size, m_ObbAdjust, m_Rotation);
	CreateStatus(scene);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(255, 0, 0);
}

void SmallEnemy::Init()
{
}

void SmallEnemy::Uninit()
{
	Enemy::Uninit();
}

void SmallEnemy::Update()
{
	Enemy::Update();
}

void SmallEnemy::Draw()
{
	Enemy::Draw();
}

void SmallEnemy::CreateStatus(Scene* scene)
{
	StatusInfo info;
	info.m_AttackCoolTime = 100.0f;
	info.m_AttackPower = 50;
	info.m_DifenceValue = 10;
	info.m_HitPointCoolTime = 30.0f;
	info.m_HitPointDimention = 3;
	info.m_HitPointPos = m_Position;
	info.m_HitPointSize = D3DXVECTOR3(-1.5f, 2.0f, 0.0f);
	info.m_HitPointValue = 300;
	m_Status = new Status(scene, &info);
}
