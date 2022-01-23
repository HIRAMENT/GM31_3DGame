#pragma once

#include "enemyState.h"

class EnemyAttack : public EnemyState
{
public:
	EnemyAttack();
	virtual ~EnemyAttack();	
	virtual StateResult Update(Enemy* enemy);

private:
	EnemyState* m_State;
};