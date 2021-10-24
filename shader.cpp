#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"

void Shader::Init()
{
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShaderLighting, &m_VertexLayoutLighting, "vertexLightingVS.cso");
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShaderUnlit, &m_VertexLayoutUnlit, "unlitTextureVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShaderLighting, "vertexLightingPS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShaderUnlit, "unlitTexturePS.cso");
}

void Shader::Uninit()
{
	m_VertexLayoutLighting->Release();
	m_VertexLayoutUnlit->Release();
	m_VertexShaderLighting->Release();
	m_VertexShaderUnlit->Release();
	m_PixelShaderLighting->Release();
	m_PixelShaderUnlit->Release();
}
