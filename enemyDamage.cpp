#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "resource.h"
#include "input.h"
#include "enemy.h"
#include "enemyDamage.h"
#include "enemyIdle.h"
#include "player.h"
#include "scene.h"
#include "enemyDead.h"
#include "status.h"
#include "hitPoint.h"

#define KNOCKBACK (2.0f)

EnemyDamage::EnemyDamage(Enemy* enemy)
{
	m_FrameCount = 1.0f;

	D3DXVECTOR2 normal = D3DXVECTOR2(enemy->GetPosition().x - enemy->GetTargetPosition().x, enemy->GetPosition().z - enemy->GetTargetPosition().z);
	D3DXVec2Normalize(&normal, &normal);
	m_Velocity = D3DXVECTOR3(normal.x * KNOCKBACK, 0.0f, normal.y * KNOCKBACK);
}

StateResult EnemyDamage::Update(Enemy* enemy)
{
	m_FrameCount -= 0.05f;

	enemy->SetPosition(enemy->GetPosition() + (m_Velocity * 0.05f));

	enemy->SetJumpValuse(enemy->GetJumpValue() * 0.05f);

	if (enemy->GetStatus()->GetHitPoint()->GetHitPoint() <= 0)
	{
		enemy->ChangeState(new EnemyDead(enemy));
	}

	if (m_FrameCount.GetIsFinish())
	{
		enemy->ChangeState(new EnemyIdle);
		return StateResult::Success;
	}

	return StateResult::Execution;
}