#pragma once

#include "gameObject.h"

class Field : public GameObject
{
private:
	ID3D11Buffer*				m_VertexBuffer = NULL;	// 頂点バッファ
	//ID3D11ShaderResourceView*	m_Texture = NULL;		// テクスチャ

public:
	Field(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
};