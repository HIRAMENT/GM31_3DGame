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

Sensor::Sensor(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene, ObjectType::eObSensor, drawPriority - 1)
{
	m_Position = pos;
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };
}

Sensor::Sensor(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority)
	: GameObject(scene, ObjectType::eObSensor, drawPriority)
{
	m_Position = pos;
	m_Size = size;
	m_Rotation = { 0.0f, 0.0f, 0.0f };
	m_Scale = { 1.0f, 1.0f, 1.0f };
	m_Obb = new OBB(pos, size, {0.0f,0.0f,0.0f}, m_Rotation);

	scene->Add(this);
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
	m_Obb->SetObb(pos, size, { 0.0f,0.0f,0.0f }, rot);
}

void Sensor::Update()
{

}

void Sensor::Uninit()
{
	delete m_Obb;
}

void Sensor::Draw()
{
	//// ���̓��C�A�E�g�ݒ� fvfs
	//Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

	//// �V�F�[�_�[�ݒ�
	//Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// �`�悷����̂��Ƃɕς�����
	//Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

	//// �}�g���N�X�ݒ�
	//D3DXMATRIX world, scale, rot, trans;
	//D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	//D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	//D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	//world = scale * rot * trans;
	//Renderer::GetInstance()->SetWorldMatrix(&world);

	//// ���_�o�b�t�@�ݒ�
	//UINT stride = sizeof(VERTEX_3D);
	//UINT offset = 0;
	//Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

	//// �}�e���A���ݒ�
	//MATERIAL material;
	//ZeroMemory(&material, sizeof(material));
	//material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//Renderer::GetInstance()->SetMaterial(material);

	//// �e�N�X�`���ݒ�
	//Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(ResourceTag::tPlane)->GetTexture());	// �e�N�X�`���Ȃǂ����\�[�X�g�ǂ�ł���

	//// �v���~�e�B�u�g�|���W�ݒ�
	//Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// ������O�ɕς���Ă��邪�A�`��̕��@��ݒ肵�Ă��邾��

	//// �|���S���`��
	//Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// �����������_���ɂȂ��Ă���̂Œ���
}
