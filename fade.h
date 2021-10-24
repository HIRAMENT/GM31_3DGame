#pragma once
#include "singleton.h"

enum class FadeTag
{
	eNone,
	eFadeIn,
	eFadeOut,
};

class Fade : public Singleton<Fade>
{
	friend class Singleton<Fade>;
	Fade() :Singleton() { Init(); }

private:
	ID3D11Buffer* m_VertexBuffer = NULL;	// 頂点バッファ
	FadeTag m_FadeTag = FadeTag::eNone;
	SceneTag m_SceneTag;

	D3DXVECTOR4 m_Diffuse;
	float m_Speed = 0.0f;
	bool m_FadeConduct;

	void Init();

protected:
	virtual ~Fade() {}
public:
	void Uninit();
	void Update();
	void Draw();
	void FadeIn(SceneTag tag);
	void SetSpeed(float speed) { m_Speed = speed; }
	void SetColor(D3DXVECTOR3 color);
};