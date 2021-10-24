#pragma once
#include "GameObject.h"

class Billboard : public GameObject
{
public:
	Billboard(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, ResourceTag tag, bool centered, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetAlpha(float alpha);
	void SetColor(float r, float g, float b);
	void AnimationTexture();
	void StartSlide(int maxcapa, int capa, int speed);
	void SetDisplay(bool display) { m_Display = display; }
	bool GetDisplay() const { return m_Display; }
private:
	bool Slide();

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
};