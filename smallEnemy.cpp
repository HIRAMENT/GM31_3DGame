#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "model.h"
#include "smallEnemy.h"
#include "player.h"
#include "sensor.h"
#include "scene.h"
#include "obb.h"
#include "collision.h"
#include "sword.h"
#include "gauge.h"
#include "status.h"
#include "hitPoint.h"

SmallEnemy::SmallEnemy(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	: Enemy(scene, pos, { 1.f,1.f,1.f }, drawPriority)
	, m_Adjust({ -1.5f,2.0f,0.0f })
{
	m_ModelTag = ResourceTag::mSmallEnemy;
	m_Type = EnemyType::Small;
	StatusInfo info;
	info.m_AttackCoolTime = 50.0f;
	info.m_AttackPower = 100;
	info.m_DifenceValue = 10;
	info.m_ExpValue = 0;
	info.m_HitPointCoolTime = 30.0f;
	info.m_HitPointDimention = 3;
	info.m_HitPointPos = pos;
	info.m_HitPointSize = D3DXVECTOR3(-1.5f, 2.0f, 0.0f);
	info.m_HitPointValue = 500;
	info.m_LevelValue = 1;
	m_Status = new Status(scene, &info);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(255, 0, 0);

	SetScale(m_Size);
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