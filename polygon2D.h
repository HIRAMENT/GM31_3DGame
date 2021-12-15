#pragma once

#include "gameObject.h"
#include "resource.h"

class Polygon2D : public GameObject
{
private:	
	ID3D11Buffer*	m_VertexBuffer = NULL;	// 頂点バッファ
	ResourceTag		m_TextureTag;
	D3DXVECTOR2		m_Size;
	VERTEX_3D		m_Vertex[4];

	int m_AnimationCount;
	int m_TexHorCount, m_TexVerCount;
	int m_TexAllCount;
	float m_AnimationSpeed;
	bool m_SlideOn;
	float m_SliddValue;
	float m_SlideMove;
	float m_VariaRatio;
	bool m_Display;

public:
	Polygon2D(class Scene* scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, ResourceTag tag, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetAlpha(float alpha);
	void SetColor(float r, float g, float b);
	void SlideTexture();
	void StartSlide(int maxcapa, int capa, float speed);
	void SetPartition(int section);
	void SetDisplay(bool display) { m_Display = display; }
	bool GetDisplay()const { return m_Display; }
	D3DXVECTOR2 GetSize()const { return m_Size; }

private:
	bool Slide();
};
