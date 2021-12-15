#pragma once
#include "gameObject.h"

class Sensor : public GameObject
{
public:
	Sensor(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);
	Sensor(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority);
	virtual ~Sensor(){}
	bool isDetection(class OBB* obb);
	void SetRotationForward(Transform transform);
	void SetSensorPosition(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);

	void Init() override {}
	void Uninit() override;
	void Update() override;
	void Draw() override;

	OBB* GetObb() const { return m_Obb; }

private:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	D3DXVECTOR3 m_Size;
	OBB* m_Obb;
};