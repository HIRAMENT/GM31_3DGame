#include "main.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "polygon2D.h"
#include "scene.h"


Polygon2D::Polygon2D(Scene * scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, ResourceTag tag,int drawPriority)
:GameObject(scene, ObjectType::eObPolygon,drawPriority)
,m_Size(size)
,m_TextureTag(tag)
{
	m_Vertex[0].Position = D3DXVECTOR3(pos.x - size.x * 0.5f, pos.y - size.y * 0.5f, 0.0f);
	m_Vertex[0].Normal   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[0].Diffuse  = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	m_Vertex[1].Position = D3DXVECTOR3(pos.x + size.x * 0.5f, pos.y - size.y * 0.5f, 0.0f);
	m_Vertex[1].Normal   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[1].Diffuse  = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	m_Vertex[2].Position = D3DXVECTOR3(pos.x - size.x * 0.5f, pos.y + size.y * 0.5f, 0.0f);
	m_Vertex[2].Normal   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[2].Diffuse  = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	m_Vertex[3].Position = D3DXVECTOR3(pos.x + size.x * 0.5f, pos.y + size.y * 0.5f, 0.0f);
	m_Vertex[3].Normal   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[3].Diffuse  = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	// 頂点バッファ作成
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// バッファのサイズ指定
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// このバッファの説明用のもの
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = m_Vertex;

	Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	m_TexHorCount = ResourceData::GetInstance()->GetTextureResource(tag)->GetSideNumber();
	m_TexVerCount = ResourceData::GetInstance()->GetTextureResource(tag)->GetVerNumber();
	m_TexAllCount = m_TexHorCount * m_TexVerCount;

	m_AnimationCount = 0;
	m_AnimationSpeed = 0.0f;
	m_SliddValue = 0.0f;
	m_SlideMove = 0.0f;
	m_VariaRatio = 0.0f;

	m_SlideOn = false;
	m_Display = true;

	SetPosition({ pos.x,pos.y,0.0f });
	scene->Add(this);
}

void Polygon2D::Init()
{

}

void Polygon2D::Uninit()
{
	m_VertexBuffer->Release();
}

void Polygon2D::Update()
{
	if (m_SlideOn && Slide())
	{
		m_SlideOn = false;
		m_SlideMove = 0.0f;
		m_AnimationSpeed = 0.0f;
	}

	if (m_TexAllCount > 1)
	{
		//m_AnimationCount++;
		//SlideTexture();
	}

	if (m_AnimationCount > m_TexAllCount)
	{
		SetDestroy();
	}
}

void Polygon2D::Draw()
{
	if (m_Display)
	{
		// 頂点データの書き換え
		D3D11_MAPPED_SUBRESOURCE msr;
		Renderer::GetInstance()->GetDeviceContext()->Map(m_VertexBuffer, 0,
			D3D11_MAP_WRITE_DISCARD, 0, &msr);

		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		vertex[0].Position = m_Vertex[0].Position;
		vertex[0].Normal = m_Vertex[0].Normal;
		vertex[0].Diffuse = m_Vertex[0].Diffuse;
		vertex[0].TexCoord = m_Vertex[0].TexCoord;

		vertex[1].Position = m_Vertex[1].Position;
		vertex[1].Normal = m_Vertex[1].Normal;
		vertex[1].Diffuse = m_Vertex[1].Diffuse;
		vertex[1].TexCoord = m_Vertex[1].TexCoord;

		vertex[2].Position = m_Vertex[2].Position;
		vertex[2].Normal = m_Vertex[2].Normal;
		vertex[2].Diffuse = m_Vertex[2].Diffuse;
		vertex[2].TexCoord = m_Vertex[2].TexCoord;

		vertex[3].Position = m_Vertex[3].Position;
		vertex[3].Normal = m_Vertex[3].Normal;
		vertex[3].Diffuse = m_Vertex[3].Diffuse;
		vertex[3].TexCoord = m_Vertex[3].TexCoord;

		Renderer::GetInstance()->GetDeviceContext()->Unmap(m_VertexBuffer, 0);

		// 入力レイアウト設定 fvfs
		Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputUnlit());

		// シェーダー設定
		Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderUnlit(), NULL, 0);		// 描画するものごとに変えられる
		Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderUnlit(), NULL, 0);

		// マトリクス設定
		Renderer::GetInstance()->SetWorldViewProjection2D();	// 前まではいらなかったけど11からは必要になった

		// 頂点バッファ設定
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

		// テクスチャ設定
		Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(m_TextureTag)->GetTexture());	// テクスチャなどをリソースト読んでいる

		// プリミティブトポロジ設定
		Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// 難しい名前に変わっているが、描画の方法を設定しているだけ

		// ポリゴン描画
		Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// 第一引数が頂点数になっているので注意
	}

}

void Polygon2D::SetAlpha(float alpha)
{
	for (int i = 0; i < 4; i++)
	{
		m_Vertex[i].Diffuse.w = alpha;
	}
}

void Polygon2D::SetColor(float r, float g, float b)
{
	m_Vertex[0].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[1].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[2].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[3].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
}

void Polygon2D::SlideTexture()
{
	Texture* texture = ResourceData::GetInstance()->GetTextureResource(m_TextureTag);
	float x = (1.0f / texture->GetSideNumber()) * (m_AnimationCount % texture->GetSideNumber());
	float y = (1.0f / texture->GetSideNumber()) * (m_AnimationCount / texture->GetSideNumber());

	m_Vertex[0].TexCoord = D3DXVECTOR2(x, y);
	m_Vertex[1].TexCoord = D3DXVECTOR2(x, y + (1.0f / texture->GetSideNumber()));
	m_Vertex[2].TexCoord = D3DXVECTOR2(x + (1.0f / texture->GetSideNumber()), y);
	m_Vertex[3].TexCoord = D3DXVECTOR2(x + (1.0f / texture->GetSideNumber()), y + (1.0f / texture->GetSideNumber()));
}

void Polygon2D::StartSlide(int maxcapa, int capa, float speed = 1.0f)
{
	m_SlideOn = true;
	m_VariaRatio = (1.0f - (float)capa / (float)maxcapa);
	m_SlideMove = m_VariaRatio - m_SliddValue;
	m_AnimationSpeed = speed;
}

void Polygon2D::SetPartition(int section)
{
	float x = (1.0f / m_TexHorCount) * (section % m_TexHorCount);
	float y = (1.0f / m_TexVerCount) * (section / m_TexHorCount);
	m_Vertex[0].TexCoord = D3DXVECTOR2(x, y);
	m_Vertex[1].TexCoord = D3DXVECTOR2(x + (1.0f / m_TexHorCount), y);
	m_Vertex[2].TexCoord = D3DXVECTOR2(x, y + (1.0f / m_TexVerCount));
	m_Vertex[3].TexCoord = D3DXVECTOR2(x + (1.0f / m_TexHorCount), y + (1.0f / m_TexVerCount));
}

bool Polygon2D::Slide()
{
	m_SliddValue += m_SlideMove / ((1.0f - m_AnimationSpeed) * 10);
	if (m_SliddValue >= m_VariaRatio) { m_SliddValue = m_VariaRatio; }
	float minX = m_Position.x - m_Size.x * 0.5f;
	float maxX = m_Position.x + m_Size.x * 0.5f;

	m_Vertex[0].Position = D3DXVECTOR3(minX, m_Position.y - m_Size.y * 0.5f, 0.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[1].Position = D3DXVECTOR3(maxX - m_Size.x * m_SliddValue, m_Position.y - m_Size.y * 0.5f, 0.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f *  (1.0f - m_SliddValue), 0.0f);
	m_Vertex[2].Position = D3DXVECTOR3(minX, m_Position.y + m_Size.y * 0.5f, 0.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[3].Position = D3DXVECTOR3(maxX - m_Size.x * m_SliddValue, m_Position.y + m_Size.y * 0.5f, 0.0f);
	m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f *  (1.0f - m_SliddValue), 1.0f);

	if (m_SliddValue == m_VariaRatio)
	{
		return true;
	}
	else
	{
		return false;
	}
}
