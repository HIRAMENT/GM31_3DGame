#pragma once
#include "enemy.h"

class SmallEnemy : public Enemy 
{
public:
	SmallEnemy(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

private:
	const D3DXVECTOR3 m_Adjust;
	const int m_HPValue = 500;
	const int m_DamageValue = 50;

public:
	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	int GetDamageValue() const override { return m_DamageValue; }
};