#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "model.h"
#include "bossEnemy.h"
#include "player.h"
#include "sensor.h"
#include "scene.h"
#include "obb.h"
#include "collision.h"
#include "sword.h"
#include "gauge.h"

BossEnemy::BossEnemy(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:Enemy(scene, pos, { 5.f,5.f,5.f }, { -1.5f,4.0f,1.0f }, 1000, ObjectType::eObBossEnemy, drawPriority)
	, m_Size({ 3.f,3.f,3.f })
	, m_Adjust({ -1.5f,4.0f,1.0f })
{
	SetScale(m_Size);
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