#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "shader.h"
#include "scene.h"
#include "resource.h"
#include "texture.h"
#include "input.h"
#include "sensor.h"
#include "camera.h"
#include "polygon3D.h"
#include "obb.h"
#include "collision.h"

Sensor::Sensor(Scene * scene, D3DXVECTOR3 pos, int drawPriority, float length, float radius)
	: GameObject(scene, ObjectType::eObSensor,drawPriority)
{
	m_Position = pos;
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };
	m_Length = length;
	m_Radius = radius;

	m_Vertex[0].Position = D3DXVECTOR3(m_Position.x - 5, m_Position.y, m_Position.z + m_Length);
	m_Vertex[0].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

	m_Vertex[1].Position = D3DXVECTOR3(m_Position.x + 5, m_Position.y, m_Position.z + m_Length);
	m_Vertex[1].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

	m_Vertex[2].Position = D3DXVECTOR3(m_Position.x - 5, m_Position.y, m_Position.z);
	m_Vertex[2].Normal = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

	m_Vertex[3].Position = D3DXVECTOR3(m_Position.x + 5, m_Position.y, m_Position.z);
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

	scene->Add(this);
}

Sensor::Sensor(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority)
	: GameObject(scene, ObjectType::eObSensor, drawPriority)
{
	m_Position = pos;
	m_Size = size;
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };
	m_Length = 0.f;
	m_Radius = 0.f;

	m_Range = new Polygon3D(scene, pos, size, ResourceTag::tPlane, drawPriority);
	m_Range->SetDisplay(false);
	m_Obb = new OBB(pos, size, m_Rotation);

	scene->Add(this);
}

bool Sensor::isDetection(D3DXVECTOR3 pos)
{
	// ��^�ɂ�����
	/*// �Z���T�[�Ƒ���̃x�N�g���̌v�Z
	D3DXVECTOR3 sensorVector = { pos.x - m_Position.x, pos.y - m_Position.y, pos.z - m_Position.z};

	// �����̌v�Z
	float sensorLength = D3DXVec3Length(&sensorVector);

	// �����̔�r
	if (m_Length < sensorLength)
	{
		return false;
	}

	// ����̃x�N�g����P�ʃx�N�g���ɂ���
	D3DXVECTOR3 sensorVectorDir;
	D3DXVec3Normalize(&sensorVectorDir,&forward);

	// �����̃x�N�g����P�ʃx�N�g���ɂ���
	D3DXVECTOR3 sensorNormalVector;
	D3DXVec3Normalize(&sensorNormalVector, &sensorVector);

	// ���ς̌v�Z
	float sensorDot = D3DXVec3Dot(&sensorNormalVector, &sensorVectorDir);

	// ��͈̔͂�cos�ɂ���
	float sensorCos = cosf(D3DXToRadian(m_Radius / 2.0f));

	// �����蔻��
	if (sensorCos > sensorDot)
	{
		return false;
	}
	
	return true;*/

	D3DXVECTOR3 LimitMax = { m_Position.x + m_Size.x / 2 ,m_Position.y + m_Size.y / 2 ,m_Position.z + m_Size.z / 2 };
	D3DXVECTOR3 LimitMin = { m_Position.x - m_Size.x / 2 ,m_Position.y - m_Size.y / 2 ,m_Position.z - m_Size.z / 2 };

	if (LimitMax.x > pos.x && LimitMin.x < pos.x)
	{
		if (LimitMax.z > pos.z && LimitMin.z < pos.z)
		{
			return true;
		}
	}

	return false;
}

bool Sensor::isDetection(OBB * obb)
{
	if (Collision::GetInstance()->ObbToObb(m_Obb, obb))
	{
		return true;
	}

	return false;
}

void Sensor::SetRotationForward(Transform transform)
{
	m_Up = transform.GetUp();
	m_Forward = transform.GetForward();
	m_Right = transform.GetRight();
}

void Sensor::SetSensorPosition(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	m_Position = pos;
	m_Range->SetPosition(pos);
	m_Obb->SetObb(pos, size, rot);
}

void Sensor::Update()
{
	if (m_Range && Keyboard_IsTrigger(DIK_1))
	{
		if (m_Range->GetDisplay())
		{
			m_Range->SetDisplay(false);
		}
		else if (!m_Range->GetDisplay())
		{
			m_Range->SetDisplay(true);
		}
	}
}

void Sensor::Uninit()
{
	m_Range->SetDestroy();
	delete m_Obb;
}

void Sensor::Draw()
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
	Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(ResourceTag::tPlane)->GetTexture());	// �e�N�X�`���Ȃǂ����\�[�X�g�ǂ�ł���

	// �v���~�e�B�u�g�|���W�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// ������O�ɕς���Ă��邪�A�`��̕��@��ݒ肵�Ă��邾��

	// �|���S���`��
	Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// �����������_���ɂȂ��Ă���̂Œ���
}
