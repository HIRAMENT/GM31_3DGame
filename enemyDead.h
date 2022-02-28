#pragma once

#include "enemyState.h"
#include "counter.h"

class EnemyDead : public EnemyState
{
public:
	EnemyDead(Enemy* enemy);
	~EnemyDead() override {}
	StateResult Update(Enemy* enemy) override;

private:
	void CreateParticle(D3DXVECTOR3 pos);

private:
	Counter m_Time;
	int m_EffectHandle;
};