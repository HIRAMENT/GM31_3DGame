#pragma once

#ifdef _DEBUG
#pragma comment (lib, "Effekseerd.lib")
#pragma comment (lib, "EffekseerRendererDX11d.lib")
#else
#pragma comment (lib, "Effekseer.lib")
#pragma comment (lib, "EffekseerRendererDX11.lib")
#endif // _DEBUG

#include "singleton.h"
#include "Effekseer/Effekseer.h"
#include "Effekseer/EffekseerRendererDX11.h"

class EffectData;

class MyEffekseer : public Singleton<MyEffekseer>
{
public:
	friend class Singleton<MyEffekseer>;

	void Init();
	void Uninit();
	void Update();
	void Draw();

	EffekseerRendererDX11::RendererRef CreateRenderer();
	Effekseer::ManagerRef CreateManager(EffekseerRendererDX11::RendererRef renderer);
	//void ResetManager(Effekseer::ManagerRef manager);
	//void ResetRenderer(EffekseerRendererDX11::RendererRef renderer);
	int Play(EffectData* data, D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void Stop(int handle);

	Effekseer::EffectRef CreateEffect(std::u16string fileName);

private:
	Effekseer::Matrix44 ConversionMatrix(D3DXMATRIX matrix);

private:
	EffekseerRendererDX11::RendererRef m_Renderer;
	Effekseer::ManagerRef m_Manager;

protected:
	MyEffekseer() {}
	virtual ~MyEffekseer() {}
};