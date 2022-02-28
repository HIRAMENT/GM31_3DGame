#include "enemyIdle.h"
#include "enemy.h"
#include "enemyMove.h"

EnemyIdle::EnemyIdle()
{
	m_Time = 4.0f;
}

StateResult EnemyIdle::Update(Enemy * enemy)
{
	m_Time -= 0.1f;

	if (m_Time.GetIsFinish())
	{
		enemy->ChangeState(new EnemyMove);
		return StateResult::Success;
	}

	return StateResult::Execution;
}
