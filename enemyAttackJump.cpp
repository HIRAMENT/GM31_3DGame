#include "main.h"
#include "resource.h"
#include "enemy.h"
#include "enemyAttackJump.h"
#include "movement.h"
#include "status.h"
#include "attack.h"
#include "enemyIdol.h"

EnemyAttackJump::EnemyAttackJump()
{
	m_AttackCounter = 4.0f;
}

StateResult EnemyAttackJump::Update(Enemy * enemy)
{
	StateResult sr;
	sr = StateResult::Execution;

	m_AttackCounter -= 0.1f;
	float movey = 1.0f;

	if (m_AttackCounter.GetIsFinish())
	{
		sr = StateResult::Success;
	}
	else if (m_AttackCounter.GetRatio() >= 0.5f)
	{
		movey = -1.0f;
	}

	D3DXVECTOR3 velocity = Movement::GetInstance()->TargetFollow(enemy->GetPosition(), enemy->GetTargetPosition(), 0.1f);
	velocity.y = movey;
	float angle = Movement::GetInstance()->TargetRotation(enemy->GetPosition(), enemy->GetTargetPosition());
	enemy->SetPosition(enemy->GetPosition() + velocity);
	enemy->SetRotation(D3DXVECTOR3(enemy->GetRotation().x, angle, enemy->GetRotation().z));

	return sr;
}
