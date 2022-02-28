#pragma once

#include "gameObject.h"
#include "transform.h"

class Camera : public GameObject
{
public:
	Camera(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	virtual void Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void SetTarget(D3DXVECTOR3 target) { m_Target = target; }
	D3DXMATRIX GetViewMatrix() const { return m_ViewMatrix; }
	D3DXMATRIX GetProjectionMatrix() const { return m_ProjectionMatrix; }
	D3DXVECTOR3 GetForwardVec() const;
	D3DXVECTOR3 GetRightVec() const;

	bool CheckView(D3DXVECTOR3 position, D3DXVECTOR3 right, D3DXVECTOR3 size);

protected:
	D3DXVECTOR3 m_Target;
	D3DXMATRIX m_ViewMatrix;
	D3DXMATRIX m_ProjectionMatrix;
};