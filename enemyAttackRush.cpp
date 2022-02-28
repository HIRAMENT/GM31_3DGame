#include "main.h"
#include "resource.h"
#include "enemy.h"
#include "enemyAttackRush.h"
#include "movement.h"
#include "status.h"
#include "attack.h"
#include "enemyIdle.h"
#include "player.h"
#include "scene.h"
#include "collision.h"

EnemyAttackRush::EnemyAttackRush()
{
	m_AttackCounter = 4.0f;
}

StateResult EnemyAttackRush::Update(Enemy * enemy)
{
	StateResult sr;
	sr = StateResult::Execution;

	m_AttackCounter -= 0.1f;
	int pom = 1;

	Player* player = enemy->GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	if (Collision::GetInstance()->ObbToObb(enemy->GetObb(), player->GetObb()))
	{
		m_AttackCounter.Half();
	}

	if (m_AttackCounter.GetIsFinish())
	{
		sr = StateResult::Success;
	}
	else if (m_AttackCounter.GetRatio() >= 0.75f)
	{
		pom = -1;
	}
	else if(m_AttackCounter.GetRatio() < 0.5f)
	{
		pom = 0;
	}

	D3DXVECTOR3 velocity = Movement::GetInstance()->TargetFollow(enemy->GetPosition(), enemy->GetTargetPosition(), 0.1f) * pom;
	float angle = Movement::GetInstance()->TargetRotation(enemy->GetPosition(), enemy->GetTargetPosition());
	enemy->SetPosition(enemy->GetPosition() + velocity);
	enemy->SetRotation(D3DXVECTOR3(enemy->GetRotation().x, angle, enemy->GetRotation().z));

	return sr;
}
