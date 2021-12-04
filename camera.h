#pragma once

#include "gameObject.h"
#include "transform.h"

class Camera : public GameObject
{
private:
	Transform m_Transform;

	D3DXVECTOR3 m_Target;
	D3DXVECTOR3 m_TargetEnemy;

	D3DXMATRIX m_ViewMatrix;
	D3DXMATRIX m_ProjectionMatrix;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;
	const float m_Distance = 10;
	int m_Angle;
	D3DXVECTOR2 m_Angle3D;

	void SetCamera();
	void SetCameraRotation(const Quaternion& qua);

public:
	Camera(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	D3DXMATRIX GetViewMatrix() const { return m_ViewMatrix; }
	D3DXVECTOR3 GetForwardVec() const;
	D3DXVECTOR3 GetRightVec() const;
	bool CheckView(D3DXVECTOR3 position, D3DXVECTOR3 size);
};