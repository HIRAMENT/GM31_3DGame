#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "resource.h"
#include "shader.h"
#include "scene.h"
#include "fade.h"

void Fade::Init()
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Normal   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse  = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	// 頂点バッファ作成
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// バッファのサイズ指定
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// このバッファの説明用のもの
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = vertex;

	Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	m_Diffuse = { 1.0f,1.0f,1.0f,0.0f };
	m_Speed = 0.45f;
	m_FadeTag = FadeTag::eNone;
	m_SceneTag = SceneTag::eTitle;
	m_FadeConduct = false;
}

void Fade::Uninit()
{
}

void Fade::Update()
{
	switch (m_FadeTag)
	{
	case FadeTag::eFadeIn:
		if (m_Diffuse.w >= 1.0f)
		{
			m_FadeTag = FadeTag::eFadeOut;
			Manager::GetInstance()->SetScene(m_SceneTag);
			break;
		}

		m_Diffuse.w += 0.1f * m_Speed;
		break;

	case FadeTag::eFadeOut:
		if (m_Diffuse.w <= 0.0f)
		{
			m_FadeTag = FadeTag::eNone;
			m_Diffuse.w = 0.0f;
			m_FadeConduct = false;
			break;
		}

		m_Diffuse.w -= 0.1f * m_Speed;
		break;

	default:
		break;
	}
}

void Fade::Draw()
{
	// 頂点データの書き換え
	D3D11_MAPPED_SUBRESOURCE msr;
	Renderer::GetInstance()->GetDeviceContext()->Map(m_VertexBuffer, 0,
		D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	vertex[0].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[0].Diffuse = m_Diffuse;
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[1].Diffuse = m_Diffuse;
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[2].Diffuse = m_Diffuse;
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vertex[3].Diffuse = m_Diffuse;
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	Renderer::GetInstance()->GetDeviceContext()->Unmap(m_VertexBuffer, 0);

	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::UNLIT));

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::UNLIT), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::UNLIT), NULL, 0);

	// マトリクス設定
	Renderer::GetInstance()->SetWorldViewProjection2D();	// 前まではいらなかったけど11からは必要になった

	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

	// テクスチャ設定
	Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(ResourceTag::tPlane)->GetTexture());	// テクスチャなどをリソースト読んでいる

	// プリミティブトポロジ設定
	Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// 難しい名前に変わっているが、描画の方法を設定しているだけ

	// ポリゴン描画
	Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// 第一引数が頂点数になっているので注意
}

void Fade::FadeIn(SceneTag tag)
{
	if (m_FadeConduct) return;

	m_Diffuse.w = 0.0f;
	m_FadeTag = FadeTag::eFadeIn;
	m_SceneTag = tag;
	m_FadeConduct = true;
}

void Fade::SetColor(D3DXVECTOR3 color)
{
	m_Diffuse.x = color.x;
	m_Diffuse.y = color.y;
	m_Diffuse.z = color.z;
}
