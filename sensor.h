#pragma once
#include "gameObject.h"

class Sensor : public GameObject
{
public:
	Sensor(class Scene* scene, D3DXVECTOR3 pos, int drawPriority, float length, float radius);
	Sensor(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority);
	virtual ~Sensor(){}
	bool isDetection(D3DXVECTOR3 pos);
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

	VERTEX_3D m_Vertex[4];
	ID3D11Buffer* m_VertexBuffer = NULL;
	D3DXVECTOR3 m_Size;
	class Polygon3D* m_Range;
	float m_Length;
	float m_Radius;
	OBB* m_Obb;
};