#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"

void Shader::Init()
{
	// UnlitTexture
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::UNLIT], &m_VertexLayout[ShaderType::UNLIT], "unlitTextureVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::UNLIT], "unlitTexturePS.cso");
	// Lighting
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::LIGHTING], &m_VertexLayout[ShaderType::LIGHTING], "vertexLightingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::LIGHTING], "vertexLightingPS.cso");
	// 環境マップ
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::ENVIROMENT], &m_VertexLayout[ShaderType::ENVIROMENT], "envMappingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::ENVIROMENT], "envMappingPS.cso");
	// ブラー
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::DEPTHofFIELD], &m_VertexLayout[ShaderType::DEPTHofFIELD], "depthOfFieldVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::DEPTHofFIELD], "depthOfFieldPS.cso");
	// リムライティング
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::LIMLIGHTING], &m_VertexLayout[ShaderType::LIMLIGHTING], "pixelLimLightingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::LIMLIGHTING], "pixelLimLightingPS.cso");
}

void Shader::Uninit()
{
	for (auto it = m_VertexShader.begin(); it != m_VertexShader.end();)
	{
		(*it).second->Release();
		it = m_VertexShader.erase(it);
	}
	m_VertexShader.clear();

	for (auto it = m_PixelShader.begin(); it != m_PixelShader.end();)
	{
		(*it).second->Release();
		it = m_PixelShader.erase(it);
	}
	m_PixelShader.clear();

	for (auto it = m_VertexLayout.begin(); it != m_VertexLayout.end();)
	{
		(*it).second->Release();
		it = m_VertexLayout.erase(it);
	}
	m_VertexLayout.clear();
}
