#pragma once

#include "enemyState.h"

class EnemyMove : public EnemyState
{
public:
	EnemyMove();
	~EnemyMove();
	StateResult Update(Enemy* enemy) override;

private:
	class Boids* m_Boids;
};