#pragma once

#include "gameObject.h"

class Polygon3D : public GameObject
{
private:
	ID3D11Buffer*				m_VertexBuffer = NULL;	// 頂点バッファ
	
	D3DXVECTOR3 m_Size;
	ResourceTag m_TextureTag;

	bool m_Display;

public:
	Polygon3D(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, ResourceTag tag, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetDisplay(bool display) { m_Display = display; }
	bool GetDisplay() const { return m_Display; }
};