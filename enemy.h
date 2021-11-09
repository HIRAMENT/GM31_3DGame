#pragma once

#include "gameObject.h"

class Enemy : public GameObject
{
protected:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	D3DXVECTOR3 m_Target;
	class Sensor* m_Sensor = nullptr;
	class OBB* m_Obb = nullptr;
	class Billboard* m_Exclamation = nullptr;
	float m_ExcScale;
	ResourceTag m_ModelTag;

	class Status* m_Status = nullptr;

	bool m_SensorEnter;
	int m_AttackCount;
	int m_SloppyTime;

private:
	class Shadow* m_Shadow = nullptr;
	bool m_Attack;
	int m_AttackCollTime;
	int m_AttackMotionCount;
	D3DXVECTOR3 m_AttackTarget;
	void Attack(D3DXVECTOR3 ppos);
	void RushAttack(D3DXVECTOR3 ppos);
	void JumpAttack(D3DXVECTOR3 ppos);

	void TargetMove(D3DXVECTOR3 pPos);
	void SloppyMove();
	void FreeMove();

private:
	D3DXVECTOR3 m_Size;
	D3DXVECTOR3 m_SensorSize;
	D3DXVECTOR3 m_MoveVlaue;

public:
	Enemy(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adjust,int hp, ObjectType type, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetEnemy();
	bool GetAttack() const { return m_Attack; }
	OBB* GetObb() const { return m_Obb; }
	Status* GetStatus() const { return m_Status; }
	virtual int GetDamageValue() const = 0;
};