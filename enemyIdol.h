#pragma once

#include "enemyState.h"

class EnemyIdol : public EnemyState 
{
public:
	EnemyIdol() {}
	~EnemyIdol() {}
	StateResult Update(Enemy* enemy) override { return StateResult::Execution; }
};