#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyDamage : public EnemyState
{
public:
	EnemyDamage();
	~EnemyDamage() {}
	StateResult Update(Enemy* enemy) override;

private:
	Counter m_FrameCount;
};