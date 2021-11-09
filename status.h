#pragma once

#include "gameObject.h"

class ExperiencePoint;
class Level;
class HitPoint;

class Status : public GameObject
{
public:
	Status(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int atk, int dfe, int exp, int level, int hp, int dim);

	void SetAttack(const int atk) { m_Attack = atk; }
	void SetDiffence(const int dfe) { m_Difence = dfe; }

	int GetAttack() const { return m_Attack; }
	int GetDifence() const { return m_Difence; }
	ExperiencePoint* GetEXP() const { return m_Exp; }
	Level* GetLevel() const { return m_Level; }
	HitPoint* GetHitPoint() const { return m_HitPoint; }

	void Init() override {}
	void Update() override;
	void Draw() override {}
	void Uninit() override;

protected:
	int m_Attack;
	int m_Difence;
	ExperiencePoint* m_Exp;
	Level* m_Level;
	HitPoint* m_HitPoint;
};