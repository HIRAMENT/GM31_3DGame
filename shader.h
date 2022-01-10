#pragma once
#include "singleton.h"
#include <unordered_map>

enum class ShaderType {
	UNLIT,
	LIGHTING,
	ENVIROMENT,
	DEPTHofFIELD,
	LIMLIGHTING,
};

class Shader : public Singleton<Shader>
{
private:
	std::unordered_map<ShaderType, ID3D11VertexShader*> m_VertexShader;
	std::unordered_map<ShaderType, ID3D11PixelShader*> m_PixelShader;
	std::unordered_map<ShaderType, ID3D11InputLayout*> m_VertexLayout;

public:
	friend class Singleton<Shader>;
	void Init();
	void Uninit();

	ID3D11VertexShader* GetVertexShader(ShaderType shader) { return m_VertexShader.at(shader); }
	ID3D11PixelShader*  GetPixelShader(ShaderType shader)  { return m_PixelShader.at(shader);  }
	ID3D11InputLayout*  GetVertexLayout(ShaderType shader) { return m_VertexLayout.at(shader); }

protected:
	Shader() {}
	virtual ~Shader() {}
};