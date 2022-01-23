#pragma once

#include "gameObject.h"

class ExperiencePoint;
class Level;
class HitPoint;
class Attack;

class Status : public GameObject
{
public:
	Status(class Scene* scene, class StatusInfo* info);

	void SetDiffence(const int dfe) { m_Difence = dfe; }

	Attack* GetAttack() const { return m_Attack; }
	int GetDifence() const { return m_Difence; }
	ExperiencePoint* GetEXP() const { return m_Exp; }
	Level* GetLevel() const { return m_Level; }
	HitPoint* GetHitPoint() const { return m_HitPoint; }

	void Init() override {}
	void Update() override;
	void Draw() override {}
	void Uninit() override;

protected:
	Attack* m_Attack;
	int m_Difence;
	ExperiencePoint* m_Exp;
	Level* m_Level;
	HitPoint* m_HitPoint;
};

class StatusInfo
{
public:
	// 攻撃関連
	int m_AttackPower;
	float m_AttackCoolTime;

	// 防御関連
	int m_DifenceValue;

	// 体力関連
	int m_HitPointValue;
	float m_HitPointCoolTime;
	int m_HitPointDimention;
	D3DXVECTOR3 m_HitPointPos;
	D3DXVECTOR3 m_HitPointSize;

	// 経験値関連
	int m_ExpValue;

	// レベル関連
	int m_LevelValue;
};