#pragma once

#include "gameObject.h"

class Skydome : public GameObject
{
private:
	Transform m_Transform;

public:
	Skydome(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
};