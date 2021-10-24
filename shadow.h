#pragma once

#include "gameObject.h"

class Shadow : public GameObject
{
private:
	ID3D11Buffer*				m_VertexBuffer = NULL;	// 頂点バッファ

public:
	Shadow(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
};