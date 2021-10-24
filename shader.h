#pragma once
#include "singleton.h"

class Shader : public Singleton<Shader>
{
private:
	ID3D11VertexShader*			m_VertexShaderLighting = NULL;	// 頂点シェーダー
	ID3D11VertexShader*			m_VertexShaderUnlit = NULL;	// 頂点シェーダー
	ID3D11PixelShader*			m_PixelShaderLighting = NULL;	// ピクセルシェーダー
	ID3D11PixelShader*			m_PixelShaderUnlit = NULL;	// ピクセルシェーダー
	ID3D11InputLayout*			m_VertexLayoutLighting = NULL;	// 場所の保存
	ID3D11InputLayout*			m_VertexLayoutUnlit = NULL;	// 場所の保存

public:
	friend class Singleton<Shader>;
	void Init();
	void Uninit();

	ID3D11VertexShader* GetVertexShaderLighting()  { return m_VertexShaderLighting; }
	ID3D11VertexShader* GetVertexShaderUnlit()     { return m_VertexShaderUnlit; }
	ID3D11PixelShader*  GetPixelShaderLighting()   { return m_PixelShaderLighting; }
	ID3D11PixelShader*  GetPixelShaderUnlit()      { return m_PixelShaderUnlit; }
	ID3D11InputLayout*  GetVertexLayputLighting()  { return m_VertexLayoutLighting; }
	ID3D11InputLayout*  GetVertexLayputUnlit()     { return m_VertexLayoutUnlit; }

protected:
	Shader() {}
	virtual ~Shader() {}
};