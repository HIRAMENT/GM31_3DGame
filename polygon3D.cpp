#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "polygon3D.h"
#include "scene.h"
struct CONSTANT_BUFFER
{
	D3DMATRIX mWVPs[10];
};

Polygon3D::Polygon3D(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, ResourceTag tag, bool center, bool billboard, int drawPriority)
	:GameObject(scene, ObjectType::eObPolygon3D, drawPriority)
	, m_Size(size)
	, m_TextureTag(tag)
	, m_Display(true)
	, m_isBillboard(billboard)
{
	D3DXVECTOR3 temppos[4];
	D3DXVECTOR3 tempnor;
	if (center){
		if (size.z == 0.0f) {
			temppos[0] = D3DXVECTOR3(-size.x / 2,  size.y / 2, 0.0f);
			temppos[1] = D3DXVECTOR3( size.x / 2,  size.y / 2, 0.0f);
			temppos[2] = D3DXVECTOR3(-size.x / 2, -size.y / 2, 0.0f);
			temppos[3] = D3DXVECTOR3( size.x / 2, -size.y / 2, 0.0f);
			tempnor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		}
		else if(size.y == 0.0f) {
			temppos[0] = D3DXVECTOR3(-size.x / 2, 0.0f,  size.z / 2);
			temppos[1] = D3DXVECTOR3( size.x / 2, 0.0f,  size.z / 2);
			temppos[2] = D3DXVECTOR3(-size.x / 2, 0.0f, -size.z / 2);
			temppos[3] = D3DXVECTOR3( size.x / 2, 0.0f, -size.z / 2);
			tempnor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		}
	}
	else
	{
		if (size.z == 0.0f) {
			temppos[0] = D3DXVECTOR3(0.0f, size.y, 0.0f);
			temppos[1] = D3DXVECTOR3(size.x, size.y, 0.0f);
			temppos[2] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			temppos[3] = D3DXVECTOR3(size.x, 0.0f, 0.0f);
			tempnor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		}
		else if(size.y == 0.0f){
			temppos[0] = D3DXVECTOR3(0.0f, 0.0f, size.z);
			temppos[1] = D3DXVECTOR3(size.x, 0.0f, size.z);
			temppos[2] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
			temppos[3] = D3DXVECTOR3(size.x, 0.0f, 0.0f);
			tempnor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		}
	}

	m_Vertex[0].Position = temppos[0];
	m_Vertex[0].Normal = tempnor;
	m_Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[1].Position = temppos[1];
	m_Vertex[1].Normal = tempnor;
	m_Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);
	m_Vertex[2].Position = temppos[2];
	m_Vertex[2].Normal = tempnor;
	m_Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[3].Position = temppos[3];
	m_Vertex[3].Normal = tempnor;
	m_Vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
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

	SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 1.0f, 1.0f, 1.0f });

	m_TextureCount.x = ResourceData::GetInstance()->GetTextureResource(tag)->GetSideNumber();
	m_TextureCount.y = ResourceData::GetInstance()->GetTextureResource(tag)->GetVerNumber();
	m_TextureCountMax = m_TextureCount.x * m_TextureCount.y;

	m_AnimationCount = 0;
	 m_AnimationSpeed = 0.0f;
	 m_SlideOn = false;
	 m_SliddValue = 0.0f;
	 m_SlideMove = 0.0f;
	 m_VariaRatio = 0.0f;
	 m_BlendMode = BlendMode::NONE;
	 m_ShaderType = ShaderType::UNLIT;
	 m_TextureTagSecond = ResourceTag::NONE;

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
	if (m_SlideOn && Slide())
	{
		m_SlideOn = false;
		m_SlideMove = 0.0f;
		m_AnimationSpeed = 0.0f;
	}

	if (m_TextureCountMax > 1)
	{
		AnimationTexture();
		m_AnimationCount++;
	}
	if (m_AnimationCount >= m_TextureCountMax)
	{
		SetDestroy();
		return;
	}
}

void Polygon3D::Draw()
{
	if (m_Display)
	{
		// 頂点データの書き換え
		D3D11_MAPPED_SUBRESOURCE msr;
		Renderer::GetInstance()->GetDeviceContext()->Map(m_VertexBuffer, 0,
			D3D11_MAP_WRITE_DISCARD, 0, &msr);

		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		vertex[0].Position = m_Vertex[0].Position;
		vertex[0].Normal   = m_Vertex[0].Normal;
		vertex[0].Diffuse  = m_Vertex[0].Diffuse;
		vertex[0].TexCoord = m_Vertex[0].TexCoord;

		vertex[1].Position = m_Vertex[1].Position;
		vertex[1].Normal   = m_Vertex[1].Normal;
		vertex[1].Diffuse  = m_Vertex[1].Diffuse;
		vertex[1].TexCoord = m_Vertex[1].TexCoord;

		vertex[2].Position = m_Vertex[2].Position;
		vertex[2].Normal   = m_Vertex[2].Normal;
		vertex[2].Diffuse  = m_Vertex[2].Diffuse;
		vertex[2].TexCoord = m_Vertex[2].TexCoord;

		vertex[3].Position = m_Vertex[3].Position;
		vertex[3].Normal   = m_Vertex[3].Normal;
		vertex[3].Diffuse  = m_Vertex[3].Diffuse;
		vertex[3].TexCoord = m_Vertex[3].TexCoord;

		Renderer::GetInstance()->GetDeviceContext()->Unmap(m_VertexBuffer, 0);

		// 入力レイアウト設定 fvfs
		Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(m_ShaderType));

		// シェーダー設定
		Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(m_ShaderType), NULL, 0);		// 描画するものごとに変えられる
		Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(m_ShaderType), NULL, 0);

		if(m_isBillboard)
		{
			if (m_TextureTag == ResourceTag::tParticleCircle)
			{
				int sla = 0;
			}
			// カメラのビューマトリクスの取得
			Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
			D3DXMATRIX view = camera->GetViewMatrix();

			// ビューの逆行列
			D3DXMATRIX invView;
			D3DXMatrixInverse(&invView, nullptr, &view);
			invView._41 = 0.0f;
			invView._42 = 0.0f;
			invView._43 = 0.0f;

			// マトリクス設定
			D3DXMATRIX world, scale, trans;
			D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
			D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
			world = scale * invView * trans;
			Renderer::GetInstance()->SetWorldMatrix(&world);
		}
		else
		{
			// マトリクス設定
			D3DXMATRIX world, scale,rot, trans;
			D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
			D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
			D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
			world = scale * rot * trans;
			Renderer::GetInstance()->SetWorldMatrix(&world);
		}

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
		if (m_TextureTagSecond != ResourceTag::NONE) {
			Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(1, 1, ResourceData::GetInstance()->GetTextureResource(m_TextureTagSecond)->GetTexture());
		}
		

		// プリミティブトポロジ設定
		Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// 難しい名前に変わっているが、描画の方法を設定しているだけ

		Renderer::GetInstance()->SetRenderBlend(m_BlendMode);

		// ポリゴン描画
		Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// 第一引数が頂点数になっているので注意

		Renderer::GetInstance()->SetRenderBlend(BlendMode::NONE);
	}
}

void Polygon3D::SetVertex(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4)
{
	m_Vertex[0].Position = pos1;
	m_Vertex[1].Position = pos2;
	m_Vertex[2].Position = pos3;
	m_Vertex[3].Position = pos4;
}

void Polygon3D::SetAlpha(float alpha)
{
	m_Vertex[0].Diffuse.w = alpha;
	m_Vertex[1].Diffuse.w = alpha;
	m_Vertex[2].Diffuse.w = alpha;
	m_Vertex[3].Diffuse.w = alpha;
}

void Polygon3D::SetColor(float r, float g, float b)
{
	m_Vertex[0].Diffuse = D3DXVECTOR4(r, g, b, m_Vertex[0].Diffuse.w);
	m_Vertex[1].Diffuse = D3DXVECTOR4(r, g, b, m_Vertex[1].Diffuse.w);
	m_Vertex[2].Diffuse = D3DXVECTOR4(r, g, b, m_Vertex[2].Diffuse.w);
	m_Vertex[3].Diffuse = D3DXVECTOR4(r, g, b, m_Vertex[3].Diffuse.w);
}

void Polygon3D::AnimationTexture()
{
	float x = (1.0f / (int)m_TextureCount.x) * (m_AnimationCount % (int)m_TextureCount.x);
	float y = (1.0f / (int)m_TextureCount.y) * (m_AnimationCount / (int)m_TextureCount.x);

	m_Vertex[0].TexCoord = D3DXVECTOR2(x,                                  y);
	m_Vertex[1].TexCoord = D3DXVECTOR2(x + (1.0f / (int)m_TextureCount.x), y);
	m_Vertex[2].TexCoord = D3DXVECTOR2(x,                                  y + (1.0f / (int)m_TextureCount.y));
	m_Vertex[3].TexCoord = D3DXVECTOR2(x + (1.0f / (int)m_TextureCount.x), y + (1.0f / (int)m_TextureCount.y));
}

void Polygon3D::StartSlide(int maxcapa, int capa, int speed)
{
	m_SlideOn = true;
	m_VariaRatio = 1.0f - (float)capa / (float)maxcapa;
	m_SlideMove = m_VariaRatio - m_SliddValue;
	m_AnimationSpeed = speed;
}

bool Polygon3D::Slide()
{
	m_SliddValue += m_SlideMove / ((1.0f - m_AnimationSpeed) * 10);
	if (m_SliddValue >= m_VariaRatio) { m_SliddValue = m_VariaRatio; }

	m_Vertex[0].Position = D3DXVECTOR3(0.0f, m_Size.y, 0.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[1].Position = D3DXVECTOR3(m_Size.x * (1.0f - m_SliddValue), m_Size.y, 0.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f * (1.0f - m_SliddValue), 0.0f);
	m_Vertex[2].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[3].Position = D3DXVECTOR3(m_Size.x * (1.0f - m_SliddValue), 0.0f, 0.0f);
	m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f * (1.0f - m_SliddValue), 1.0f);

	if (m_SliddValue == m_VariaRatio)
		return true;

	return false;
}
