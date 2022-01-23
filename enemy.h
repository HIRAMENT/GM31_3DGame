#pragma once

#include "gameObject.h"

class EnemyState;
enum class EnemyStateType;
enum class ResourceTag;

enum class EnemyType {
	Small,
	Boss,
};

class Enemy : public GameObject
{
public:
	Enemy(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	EnemyType GetEnemyType() const { return m_Type; }
	bool GetAttack() const { return m_Attack; }
	class OBB* GetObb() const { return m_Obb; }
	class Status* GetStatus() const { return m_Status; }
	virtual int GetDamageValue() const = 0;
	void CreateParticle();
	void ChangeState(EnemyState* next);
	D3DXVECTOR3 GetTargetPosition() const { return m_Target; }

private:
	void SetEnemy();

protected:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	D3DXVECTOR3 m_Target;
	OBB* m_Obb = nullptr;
	class Polygon3D* m_Exclamation = nullptr;
	float m_ExcScale;
	ResourceTag m_ModelTag;
	EnemyType m_Type;
	D3DXVECTOR3 m_Size;

	Status* m_Status;

	bool m_SensorEnter;
	int m_AttackCount;
	int m_SloppyTime;
	const float m_FollowRange;

	EnemyState* m_EnemyState = nullptr;

private:
	class Shadow* m_Shadow = nullptr;
	bool m_Attack;
	int m_AttackCollTime;
	int m_AttackMotionCount;
	D3DXVECTOR3 m_AttackTarget;
	void Attack(D3DXVECTOR3 ppos);
	void SloppyMove();

private:
	D3DXVECTOR3 m_SensorSize;
	D3DXVECTOR3 m_MoveVlaue;
};