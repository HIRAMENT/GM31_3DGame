#pragma once
#include "gameObject.h"

class OBB;

class Sword : public GameObject
{
public:
	Sword(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetAttack(D3DXVECTOR2 vec);
	OBB* GetObb() const { return m_Obb; }
	bool GetAttack() const { return m_Attack; }
	int GetDamageValue() const { return m_DamageValue; }

private:
	D3DXVECTOR2 m_MovePosition;
	bool m_Attack;
	const int m_DamageValue = 50;
	int m_Angle;
	int m_SwingAngle;
	OBB* m_Obb = nullptr;
	const D3DXVECTOR3 m_Size = { 1.0f,5.0f,1.0f };
};