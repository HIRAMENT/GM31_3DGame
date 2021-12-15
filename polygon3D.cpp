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
	m_Vertex[0].Position = D3DXVECTOR3(m_Position.x - size.x / 2, 0.0f, m_Position.z + size.z / 2);
	m_Vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	m_Vertex[1].Position = D3DXVECTOR3(m_Position.x + size.x / 2, 0.0f, m_Position.z + size.z / 2);
	m_Vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	m_Vertex[2].Position = D3DXVECTOR3(m_Position.x - size.x / 2, 0.0f, m_Position.z - size.z / 2);
	m_Vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	m_Vertex[3].Position = D3DXVECTOR3(m_Position.x + size.x / 2, 0.0f, m_Position.z - size.z / 2);
	m_Vertex[3].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);

	// ���_�o�b�t�@�쐬
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// �o�b�t�@�̃T�C�Y�w��
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// ���̃o�b�t�@�̐����p�̂���
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = m_Vertex;

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
		// ���_�f�[�^�̏�������
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

		// ���̓��C�A�E�g�ݒ� fvfs
		Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

		// �V�F�[�_�[�ݒ�
		Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// �`�悷����̂��Ƃɕς�����
		Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

		// �}�g���N�X�ݒ�
		D3DXMATRIX world, scale, rot, trans;
		D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
		D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
		D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
		world = scale * rot * trans;
		Renderer::GetInstance()->SetWorldMatrix(&world);

		// ���_�o�b�t�@�ݒ�
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

		// �}�e���A���ݒ�
		MATERIAL material;
		ZeroMemory(&material, sizeof(material));
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		Renderer::GetInstance()->SetMaterial(material);

		// �e�N�X�`���ݒ�
		Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(m_TextureTag)->GetTexture());	// �e�N�X�`���Ȃǂ����\�[�X�g�ǂ�ł���

		// �v���~�e�B�u�g�|���W�ݒ�
		Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// ������O�ɕς���Ă��邪�A�`��̕��@��ݒ肵�Ă��邾��

		// �|���S���`��
		Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// �����������_���ɂȂ��Ă���̂Œ���

	}
}

void Polygon3D::SetVertex(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, D3DXVECTOR3 pos3, D3DXVECTOR3 pos4)
{
	m_Vertex[0].Position = pos1;
	m_Vertex[1].Position = pos2;
	m_Vertex[2].Position = pos3;
	m_Vertex[3].Position = pos4;
}
