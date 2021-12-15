#pragma once

#include "gameObject.h"

class Polygon3D : public GameObject
{
public:
	Polygon3D(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, ResourceTag tag, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetVertex(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4);

	void SetDisplay(bool display) { m_Display = display; }
	bool GetDisplay() const { return m_Display; }

private:
	VERTEX_3D m_Vertex[4];
	
	ID3D11Buffer*				m_VertexBuffer = NULL;	// 頂点バッファ

	D3DXVECTOR3 m_Size;
	ResourceTag m_TextureTag;

	bool m_Display;
};