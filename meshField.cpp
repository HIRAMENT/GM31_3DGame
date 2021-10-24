#include <fstream>
#include <string>
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "shader.h"
#include "scene.h"
#include "meshField.h"

MeshField::MeshField(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	: GameObject(scene, ObjectType::eObField, drawPriority)
{
	std::ifstream ifs("stage.txt");
	std::string line;
	int x = 0, y = 0;
	while (std::getline(ifs, line))
	{
		for (int i = 0; line[i] != '\0'; i++)
		{
			if (line[i] != ',')
			{
				m_FieldHeight[y][x] = atoi(&line[i]);
				x++;
			}
		}
		y++;
	}

	{//頂点バッファの中身を埋める

		for (int x = 0; x < MESH_NUM_X; x++)
		{
			for (int y = 0; y < MESH_NUM_Y; y++)
			{
				// 頂点座標の設定
				m_Vertex[x][y].Position.x = (x - (MESH_NUM_X - 1) * 0.5f) * MESH_SIZE_X;
				m_Vertex[x][y].Position.y = m_FieldHeight[y][x];
				m_Vertex[x][y].Position.z = (y - (MESH_NUM_Y - 1) * 0.5f) * -MESH_SIZE_Y;

				// 法線の設定
				m_Vertex[x][y].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

				// 頂点カラーの設定
				m_Vertex[x][y].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

				// テクスチャ座標の設定
				m_Vertex[x][y].TexCoord = D3DXVECTOR2(x * 0.5f, y * 0.5f);
			}
		}

		for (int x = 1; x < MESH_NUM_X - 1; x++)
		{
			for (int y = 1; y < MESH_NUM_Y - 1; y++)
			{
				D3DXVECTOR3 vx, vy, vn;

				vx = m_Vertex[x + 1][y].Position - m_Vertex[x - 1][y].Position;
				vy = m_Vertex[x][y - 1].Position - m_Vertex[x][y + 1].Position;

				D3DXVec3Cross(&vn, &vy, &vx);	// 外積
				D3DXVec3Normalize(&vn, &vn);	// 正規化
				m_Vertex[x][y].Normal = vn;
			}
		}

		// 頂点バッファ作成
		D3D11_BUFFER_DESC bd{};
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(VERTEX_3D) * (MESH_NUM_X * MESH_NUM_Y);		// バッファのサイズ指定
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// このバッファの説明用のもの
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA sd{};
		sd.pSysMem = m_Vertex;

		Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);
	}

	unsigned int index[INDEX_NUM];
	{//インデックスバッファの中身を埋める

		int indexNum = 0;
		for (int x = 0; x < (MESH_NUM_X - 1); x++)
		{
			for (int y = 0; y < MESH_NUM_Y; y++)
			{
				index[indexNum] = x * MESH_NUM_Y + y;
				indexNum++;
				index[indexNum] = (x + 1) * MESH_NUM_Y + y;
				indexNum++;
			}

			//最後の行はこの処理を行わない
			if (x < (MESH_NUM_X - 2))
			{
				//縮退ポリゴン分のインデックスの設定
				index[indexNum] = (x + 1) * MESH_NUM_Y + (MESH_NUM_X - 1);
				indexNum++;
				index[indexNum] = MESH_NUM_Y * (x + 1);
				indexNum++;
			}
		}

		// インデクスバッファの作成
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(unsigned int) * INDEX_NUM;
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.pSysMem = index;

		Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_IndexBuffer);
	}

	m_Position = { 0.0f, 0.0f, 0.0f };
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };

	scene->Add(this);
}

void MeshField::Init()
{
	
}

void MeshField::Uninit()
{
	m_VertexBuffer->Release();
	m_IndexBuffer->Release();
}

void MeshField::Update()
{
}

void MeshField::Draw()
{
	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);
	
	// インデックスバッファ設定
	Renderer::GetInstance()->GetDeviceContext()->IASetIndexBuffer(m_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	Renderer::GetInstance()->SetMaterial(material);

	// テクスチャ設定
	Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(ResourceTag::tGround)->GetTexture());	// テクスチャなどをリソースト読んでいる
	// プリミティブトポロジ設定
	Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// 難しい名前に変わっているが、描画の方法を設定しているだけ

	// ポリゴン描画
	Renderer::GetInstance()->GetDeviceContext()->DrawIndexed(INDEX_NUM,0,0);	// 第一引数が頂点数になっているので注意
}

float MeshField::GetHeight(D3DXVECTOR3 position)
{
	int x, z;

	x = position.x / MESH_SIZE_X + (MESH_NUM_X - 1) * 0.5f;
	z = position.z / -MESH_SIZE_Y + (MESH_NUM_Y - 1) * 0.5f;

	D3DXVECTOR3 pos0, pos1, pos2, pos3;

	pos0 = m_Vertex[x][z].Position;
	pos1 = m_Vertex[x + 1][z].Position;
	pos2 = m_Vertex[x][z + 1].Position;
	pos3 = m_Vertex[x + 1][z + 1].Position;

	D3DXVECTOR3 v12, v1p, c;

	v12 = pos2 - pos1;
	v1p = position - pos1;

	D3DXVec3Cross(&c, &v12, &v1p);

	float py;
	D3DXVECTOR3 n;

	if (c.y > 0.0f)
	{
		// 左上ポリゴン
		D3DXVECTOR3 v10;
		v10 = pos0 - pos1;
		D3DXVec3Cross(&n, &v10, &v12);
	}
	else
	{
		// 右下ポリゴン
		D3DXVECTOR3 v13;
		v13 = pos3 - pos1;
		D3DXVec3Cross(&n, &v12, &v13);
	}

	// 高さ取得
	py = -((position.x - pos1.x) * n.x + (position.z - pos1.z) * n.z) / n.y + pos1.y;

	return py;
}
