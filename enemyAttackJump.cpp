#include "main.h"
#include "resource.h"
#include "enemy.h"
#include "enemyAttackJump.h"
#include "movement.h"
#include "status.h"
#include "attack.h"
#include "enemyIdle.h"
#include "collision.h"
#include "player.h"
#include "scene.h"

EnemyAttackJump::EnemyAttackJump()
{
	m_AttackCounter = 4.0f;
}

StateResult EnemyAttackJump::Update(Enemy * enemy)
{
	StateResult sr;
	sr = StateResult::Execution;

	m_AttackCounter -= 0.1f;
	float movey = 0.2f;

	if (m_AttackCounter.GetIsFinish())
	{
		sr = StateResult::Success;
		enemy->SetJumpValuse(0.0f);
	}
	else if (m_AttackCounter.GetRatio() >= 0.5f)
	{
		movey = -0.2f;
	}

	D3DXVECTOR3 velocity = Movement::GetInstance()->TargetFollow(enemy->GetPosition(), enemy->GetTargetPosition(), 0.1f);
	enemy->SetJumpValuse(enemy->GetJumpValue() + movey);
	float angle = Movement::GetInstance()->TargetRotation(enemy->GetPosition(), enemy->GetTargetPosition());
	enemy->SetPosition(enemy->GetPosition() + velocity);
	enemy->SetRotation(D3DXVECTOR3(enemy->GetRotation().x, angle, enemy->GetRotation().z));

	return sr;
}
