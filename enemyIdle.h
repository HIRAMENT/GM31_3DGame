#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyIdle : public EnemyState 
{
public:
	EnemyIdle();
	~EnemyIdle() {}
	StateResult Update(Enemy* enemy) override;

private:
	Counter m_Time;
};