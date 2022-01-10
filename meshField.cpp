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
	std::string filename("stage.txt");
	char c;

	std::ifstream input_file(filename);
	if (!input_file.is_open()) {
		for (int y = 0; y < MESH_NUM_Y - 1; y++) {
			for (int x = 0; x < MESH_NUM_X - 1; x++) {
				m_FieldHeight[y][x] = 0;
			}
		}
	}
	else{
		int x = 0, y = 0;
		while (input_file.get(c)) {
			if (c != ',' && c != '\n') {
				m_FieldHeight[y][x] = atoi(&c);
				if (x == MESH_NUM_X - 1) {
					x = 0;
					y++;
				}
				else {
					x++;
				}
			}
		}
	}

	input_file.close();




	{//���_�o�b�t�@�̒��g�𖄂߂�

		for (int x = 0; x < MESH_NUM_X; x++)
		{
			for (int y = 0; y < MESH_NUM_Y; y++)
			{
				// ���_���W�̐ݒ�
				m_Vertex[x][y].Position.x = (x - (MESH_NUM_X - 1) * 0.5f) * MESH_SIZE_X;
				m_Vertex[x][y].Position.y = m_FieldHeight[y][x];
				m_Vertex[x][y].Position.z = (y - (MESH_NUM_Y - 1) * 0.5f) * -MESH_SIZE_Y;

				// �@���̐ݒ�
				m_Vertex[x][y].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

				// ���_�J���[�̐ݒ�
				m_Vertex[x][y].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

				// �e�N�X�`�����W�̐ݒ�
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

				D3DXVec3Cross(&vn, &vy, &vx);	// �O��
				D3DXVec3Normalize(&vn, &vn);	// ���K��
				m_Vertex[x][y].Normal = vn;
			}
		}

		// ���_�o�b�t�@�쐬
		D3D11_BUFFER_DESC bd{};
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(VERTEX_3D) * (MESH_NUM_X * MESH_NUM_Y);		// �o�b�t�@�̃T�C�Y�w��
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// ���̃o�b�t�@�̐����p�̂���
		bd.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA sd{};
		sd.pSysMem = m_Vertex;

		Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);
	}

	unsigned int index[INDEX_NUM];
	{//�C���f�b�N�X�o�b�t�@�̒��g�𖄂߂�

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

			//�Ō�̍s�͂��̏������s��Ȃ�
			if (x < (MESH_NUM_X - 2))
			{
				//�k�ރ|���S�����̃C���f�b�N�X�̐ݒ�
				index[indexNum] = (x + 1) * MESH_NUM_Y + (MESH_NUM_X - 1);
				indexNum++;
				index[indexNum] = MESH_NUM_Y * (x + 1);
				indexNum++;
			}
		}

		// �C���f�N�X�o�b�t�@�̍쐬
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
	// ���̓��C�A�E�g�ݒ� fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// �V�F�[�_�[�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// �`�悷����̂��Ƃɕς�����
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

	// �}�g���N�X�ݒ�
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	// ���_�o�b�t�@�ݒ�
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);
	
	// �C���f�b�N�X�o�b�t�@�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->IASetIndexBuffer(m_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// �}�e���A���ݒ�
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	Renderer::GetInstance()->SetMaterial(material);

	// �e�N�X�`���ݒ�
	Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(ResourceTag::tGround)->GetTexture());	// �e�N�X�`���Ȃǂ����\�[�X�g�ǂ�ł���
	// �v���~�e�B�u�g�|���W�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// ������O�ɕς���Ă��邪�A�`��̕��@��ݒ肵�Ă��邾��

	// �|���S���`��
	Renderer::GetInstance()->GetDeviceContext()->DrawIndexed(INDEX_NUM,0,0);	// �����������_���ɂȂ��Ă���̂Œ���
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
		// ����|���S��
		D3DXVECTOR3 v10;
		v10 = pos0 - pos1;
		D3DXVec3Cross(&n, &v10, &v12);
	}
	else
	{
		// �E���|���S��
		D3DXVECTOR3 v13;
		v13 = pos3 - pos1;
		D3DXVec3Cross(&n, &v12, &v13);
	}

	// �����擾
	py = -((position.x - pos1.x) * n.x + (position.z - pos1.z) * n.z) / n.y + pos1.y;

	return py;
}
