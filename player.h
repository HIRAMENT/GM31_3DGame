#pragma once

#include "gameObject.h"

class Player : public GameObject 
{
private:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	const D3DXVECTOR3 m_Size;
	int m_HP;
	int m_HPMax;
	float m_BlendRate;

	class Shadow* m_Shadow = nullptr;
	class Sword* m_Sword = nullptr;
	class OBB* m_Obb = nullptr;
	class Gauge* m_HPGauge = nullptr;
	class Number*  m_HPNumber[4] = {};
	Number*  m_HPSlashNumber = nullptr;
	Number*  m_HPMaxNumber[4] = {};
	int m_HitCoolTime;
	const int HITCOOLTIME_MAX = 36;
	bool m_Dash;

	class AnimationModel* m_Model = nullptr;
	int m_AnimeFrame;

private:
	void TakeDamage(int damage);

public:
	Player(class Scene* scene,D3DXVECTOR3 pos,int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	D3DXVECTOR3 GetForward() const { return m_Forward; }
	D3DXVECTOR3 GetQuaRight() const { return m_Right; }
	OBB* GetObb() const { return m_Obb; }
	void SetPlayer();
	void SetPlayerRotation(const Quaternion& qua);
	int GetHP() const { return m_HP; }
};