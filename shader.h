#pragma once
#include "singleton.h"

class Shader : public Singleton<Shader>
{
private:
	ID3D11VertexShader*			m_VertexShaderLighting = NULL;	// ���_�V�F�[�_�[
	ID3D11VertexShader*			m_VertexShaderUnlit = NULL;	// ���_�V�F�[�_�[
	ID3D11PixelShader*			m_PixelShaderLighting = NULL;	// �s�N�Z���V�F�[�_�[
	ID3D11PixelShader*			m_PixelShaderUnlit = NULL;	// �s�N�Z���V�F�[�_�[
	ID3D11InputLayout*			m_VertexLayoutLighting = NULL;	// �ꏊ�̕ۑ�
	ID3D11InputLayout*			m_VertexLayoutUnlit = NULL;	// �ꏊ�̕ۑ�

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