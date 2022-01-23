#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyAttackRush : public EnemyState
{
public:
	EnemyAttackRush();
	~EnemyAttackRush() {}
	StateResult Update(Enemy* enemy) override;

private:
	Counter m_AttackCounter;
};