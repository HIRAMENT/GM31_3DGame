#pragma once

enum class StateResult {
	Execution,
	Success,
	Failure,
};

class Enemy;

class EnemyState
{
public:
	virtual ~EnemyState() {}
	virtual StateResult Update(Enemy* enemy) = 0;
};