#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "polygon3D.h"
#include "scene.h"

Polygon3D::Polygon3D(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, ResourceTag tag, int drawPriority)
	:GameObject(scene, ObjectType::eObField, drawPriority)
	, m_Size(size)
	, m_TextureTag(tag)
	, m_Display(true)
{
	VERTEX_3D vertex[4];

	vertex[0].Position = D3DXVECTOR3(m_Position.x - size.x / 2, 0.0f, m_Position.z + size.z / 2);
	vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	vertex[1].Position = D3DXVECTOR3(m_Position.x + size.x / 2, 0.0f, m_Position.z + size.z / 2);
	vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	vertex[2].Position = D3DXVECTOR3(m_Position.x - size.x / 2, 0.0f, m_Position.z - size.z / 2);
	vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	vertex[3].Position = D3DXVECTOR3(m_Position.x + size.x / 2, 0.0f, m_Position.z - size.z / 2);
	vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	// 頂点バッファ作成
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// バッファのサイズ指定
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// このバッファの説明用のもの
	bd.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = vertex;

	Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 1.0f, 1.0f, 1.0f });
	scene->Add(this);
}

void Polygon3D::Init()
{
}

void Polygon3D::Uninit()
{
	m_VertexBuffer->Release();
}

void Polygon3D::Update()
{
}

void Polygon3D::Draw()
{
	if (m_Display)
	{
		// 入力レイアウト設定 fvfs
		Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

		// シェーダー設定
		Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// 描画するものごとに変えられる
		Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

		// マトリクス設定
		D3DXMATRIX world, scale, rot, trans;
		D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
		D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
		D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
		world = scale * rot * trans;
		Renderer::GetInstance()->SetWorldMatrix(&world);

		// 頂点バッファ設定
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

		// マテリアル設定
		MATERIAL material;
		ZeroMemory(&material, sizeof(material));
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		Renderer::GetInstance()->SetMaterial(material);

		// テクスチャ設定
		Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(m_TextureTag)->GetTexture());	// テクスチャなどをリソースト読んでいる

		// プリミティブトポロジ設定
		Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// 難しい名前に変わっているが、描画の方法を設定しているだけ

		// ポリゴン描画
		Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// 第一引数が頂点数になっているので注意

	}
}
