#pragma once

#include "gameObject.h"

class Bullet : public GameObject
{
private:
	 D3DXVECTOR3 m_Forward;
	 D3DXVECTOR3 m_Size;
	 
public:
	Bullet(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 forward, int drawPriority);
	void Init() override {}
	void Uninit() override {}
	void Update() override;
	void Draw() override;
};