#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyAttackJump : public EnemyState
{
public:
	EnemyAttackJump();
	~EnemyAttackJump() {}
	StateResult Update(Enemy* enemy) override;

private:
	Counter m_AttackCounter;
};