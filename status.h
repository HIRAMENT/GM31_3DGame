#pragma once

#include "gameObject.h"

class HitPoint;
class Attack;

class Status : public GameObject
{
public:
	Status(class Scene* scene, class StatusInfo* info);

	void SetDiffence(const int dfe) { m_Difence = dfe; }

	Attack* GetAttack() const { return m_Attack; }
	int GetDifence() const { return m_Difence; }
	HitPoint* GetHitPoint() const { return m_HitPoint; }

	void Init() override {}
	void Update() override;
	void Draw() override {}
	void Uninit() override;

protected:
	Attack* m_Attack;
	int m_Difence;
	HitPoint* m_HitPoint;
};

class StatusInfo
{
public:
	// çUåÇä÷òA
	int m_AttackPower;
	float m_AttackCoolTime;

	// ñhå‰ä÷òA
	int m_DifenceValue;

	// ëÃóÕä÷òA
	int m_HitPointValue;
	float m_HitPointCoolTime;
	int m_HitPointDimention;
	D3DXVECTOR3 m_HitPointPos;
	D3DXVECTOR3 m_HitPointSize;
	bool m_IsNumberDisplay;
};