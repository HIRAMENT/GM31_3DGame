#pragma once

#include "gameObject.h"
#include "shader.h"

class Polygon3D : public GameObject
{
public:
	Polygon3D(class Scene* scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, ResourceTag tag, bool center, bool billboard, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void SetDisplay(bool display) { m_Display = display; }
	bool GetDisplay() const { return m_Display; }
	void SetShaderType(ShaderType type) { m_ShaderType = type; }
	void SetBlendMode(BlendMode mode) { m_BlendMode = mode; }
	void SetVertex(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4);
	void SetAlpha(float alpha);
	void SetColor(float r, float g, float b);
	void SetTextureTagSecond(ResourceTag tag) { m_TextureTagSecond = tag; }
	void AnimationTexture();
	void StartSlide(int maxcapa, int capa, int speed);
	bool Slide();

protected:
	VERTEX_3D m_Vertex[4];
	ID3D11Buffer* m_VertexBuffer = NULL;	// 頂点バッファ
	D3DXVECTOR3 m_Size;
	ResourceTag m_TextureTag;
	ResourceTag m_TextureTagSecond;
	D3DXVECTOR2 m_TextureCount;
	bool m_isBillboard;
	int m_TextureCountMax;
	int m_AnimationCount;
	float m_AnimationSpeed;
	bool m_SlideOn;
	float m_SliddValue;
	float m_SlideMove;
	float m_VariaRatio;
	bool m_Display;
	BlendMode m_BlendMode;
	ShaderType m_ShaderType;
};