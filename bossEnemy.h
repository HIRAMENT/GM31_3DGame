#pragma once
#include "enemy.h"

class BossEnemy : public Enemy
{
public:
	BossEnemy(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

private:
	const D3DXVECTOR3 m_Adjust = { -1.0f,2.0f,0.0f };
	const int m_HPValue = 1000;
	const int m_DamageValue = 100;

public:
	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	int GetDamageValue() const override { return m_DamageValue; }
	void CreateStatus(Scene* scene) override;
};