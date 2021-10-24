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
#include "billboard.h"
#include "gauge.h"

SmallEnemy::SmallEnemy(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	: Enemy(scene, pos, { 1.f,1.f,1.f }, { -1.5f,2.0f,0.0f }, 500,ObjectType::eObSmallEnemy, drawPriority)
	, m_Size({ 1.f,1.f,1.f })
	, m_Adjust({ -1.5f,2.0f,0.0f })
{
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