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

	// ���_�o�b�t�@�쐬
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// �o�b�t�@�̃T�C�Y�w��
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// ���̃o�b�t�@�̐����p�̂���
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
