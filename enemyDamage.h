#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyDamage : public EnemyState
{
public:
	EnemyDamage(Enemy* enemy);
	~EnemyDamage() {}
	StateResult Update(Enemy* enemy) override;

private:
	Counter m_FrameCount;
	D3DXVECTOR3 m_Velocity;
};