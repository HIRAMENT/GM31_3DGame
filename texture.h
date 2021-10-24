#pragma once

#include "resource.h"

class Texture : public ResourceData
{
public:
	Texture() = delete;
	Texture(std::string fileName, int side, int ver);
	~Texture();

	ID3D11ShaderResourceView** GetTexture() { return &m_Texture; }

	int GetSideNumber() const { return m_SideNumber; }
	int GetVerNumber() const  { return m_VerNumber; }
 
private:
	ID3D11ShaderResourceView* m_Texture = nullptr;
	std::string m_FileName;

	int m_SideNumber;
	int m_VerNumber;

	void Load();
	void Unload();
};