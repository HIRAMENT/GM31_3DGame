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
	class OBB* GetObb() const { return m_Obb; }
	class Status* GetStatus() const { return m_Status; }
	virtual int GetDamageValue() const = 0;
	float GetJumpValue() const { return m_JumpValuse; }
	float GetFieldHeight() const { return m_FieldHeight; }
	void SetJumpValuse(float val) { m_JumpValuse = val; }
	void CreateParticle();
	void ChangeState(EnemyState* next);
	D3DXVECTOR3 GetTargetPosition() const { return m_Target; }
	virtual void CreateStatus(Scene* scene) = 0;

private:
	void SetEnemy();

protected:
	D3DXVECTOR3 m_Target;
	OBB* m_Obb = nullptr;
	ResourceTag m_ModelTag;
	EnemyType m_Type;
	D3DXVECTOR3 m_Size;
	D3DXVECTOR3 m_ObbAdjust;
	float m_JumpValuse;
	float m_FieldHeight;

	Status* m_Status;

	EnemyState* m_EnemyState = nullptr;

private:
	class Shadow* m_Shadow = nullptr;
};