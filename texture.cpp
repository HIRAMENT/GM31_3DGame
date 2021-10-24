#include "main.h"
#include "renderer.h"
#include "resource.h"
#include "texture.h"

Texture::Texture(std::string fileName, int side, int all)
	: m_FileName(fileName)
{
	this->Load();
	m_SideNumber = side;
	m_VerNumber = all;
}

Texture::~Texture()
{
	this->Unload();
}

void Texture::Load()
{
	D3DX11CreateShaderResourceViewFromFile(Renderer::GetInstance()->GetDevice(),
		m_FileName.c_str(),
		NULL,
		NULL,
		&m_Texture,
		NULL);

	assert(m_Texture);	// 中身がNULLだとエラーを出してくれるらしい
}

void Texture::Unload()
{
	m_Texture->Release();
}
