#pragma once

#include "gameObject.h"

#define MESH_NUM_X   (20 + 1)
#define MESH_NUM_Y   (20 + 1)
#define MESH_SIZE_X  5.0f
#define MESH_SIZE_Y  5.0f
#define INDEX_NUM   ((MESH_NUM_Y + 1) * 2) * (MESH_NUM_X - 1) - 2

class MeshField : public GameObject
{
private:
	ID3D11Buffer*				m_VertexBuffer = NULL;	// 頂点バッファ
	ID3D11Buffer*				m_IndexBuffer = NULL;	// インデクスバッファ

	VERTEX_3D m_Vertex[MESH_NUM_X][MESH_NUM_Y];
	int m_FieldHeight[MESH_NUM_X][MESH_NUM_Y];

public:
	MeshField(class Scene* scene, D3DXVECTOR3 pos, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	float GetHeight(D3DXVECTOR3 position);
};