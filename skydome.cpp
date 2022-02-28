#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "input.h"
#include "gamepad.h"
#include "model.h"
#include "skydome.h"
#include "scene.h"

Skydome::Skydome(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene, ObjectType::eObSkydome, drawPriority)
{
	SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 500.0f, 500.0f, 500.0f });

	scene->Add(this);
}

void Skydome::Init()
{
}

void Skydome::Uninit()
{
}

void Skydome::Update()
{

}

void Skydome::Draw()
{
	// ���̓��C�A�E�g�ݒ� fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::UNLIT));

	// �V�F�[�_�[�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::UNLIT), NULL, 0);		// �`�悷����̂��Ƃɕς�����
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::UNLIT), NULL, 0);

	// �}�g���N�X�ݒ�
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(ResourceTag::mSkydome)->Draw();
}