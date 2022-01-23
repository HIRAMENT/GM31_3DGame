#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"

void Shader::Init()
{
	// UnlitTexture
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::UNLIT], &m_VertexLayout[ShaderType::UNLIT], "shader/unlitTextureVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::UNLIT], "shader/unlitTexturePS.cso");
	// Lighting
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::LIGHTING], &m_VertexLayout[ShaderType::LIGHTING], "shader/vertexLightingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::LIGHTING], "shader/vertexLightingPS.cso");
	// ���}�b�v
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::ENVIROMENT], &m_VertexLayout[ShaderType::ENVIROMENT], "shader/envMappingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::ENVIROMENT], "shader/envMappingPS.cso");
	// �u���[
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::DEPTHofFIELD], &m_VertexLayout[ShaderType::DEPTHofFIELD], "shader/depthOfFieldVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::DEPTHofFIELD], "shader/depthOfFieldPS.cso");
	// �������C�e�B���O
	Renderer::GetInstance()->CreateVertexShader(&m_VertexShader[ShaderType::LIMLIGHTING], &m_VertexLayout[ShaderType::LIMLIGHTING], "shader/pixelLimLightingVS.cso");
	Renderer::GetInstance()->CreatePixelShader(&m_PixelShader[ShaderType::LIMLIGHTING], "shader/pixelLimLightingPS.cso");
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
