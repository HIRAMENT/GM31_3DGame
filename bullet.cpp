#include "main.h"
#include "manager.h"
#include "input.h"
#include "renderer.h"
#include "shader.h"
#include "model.h"
#include "resource.h"
#include "bullet.h"
#include "enemy.h"
#include "scene.h"
#include "player.h"
#include "collision.h"
#include "status.h"
#include "hitPoint.h"
#include <vector>

Bullet::Bullet(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 forward, int drawPriority)
	: GameObject(scene,ObjectType::eObBullet, drawPriority)
{
	m_Position = D3DXVECTOR3(pos);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale    = D3DXVECTOR3(0.3f, 0.3f, 0.3f);
	m_Size = ResourceData::GetInstance()->GetModelResource(ResourceTag::mBullet)->GetSize() * m_Scale;
	m_Forward = forward;

	scene->Add(this);
}

void Bullet::Update()
{
	m_Position += D3DXVECTOR3(m_Forward.x, 0.0f, m_Forward.z) * 0.2f;

	if (GetPosition().x > 24.0f || GetPosition().z > 24.0f ||
		GetPosition().x < -24.0f || GetPosition().z < -24.0f)
	{
		SetDestroy();
		return;
	}

	std::vector<Enemy*> enemyList = GetScene()->GetGameObjects<Enemy>(ObjectType::eObSmallEnemy);
	for (Enemy* enemy : enemyList){
		if (Collision::GetInstance()->ObbToPoint(enemy->GetObb(), m_Position, m_Size)) {
			enemy->GetStatus()->GetHitPoint()->Damage(50);
			SetDestroy();
			return;
		}
	}
}

void Bullet::Draw()
{
	// ���̓��C�A�E�g�ݒ� fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// �V�F�[�_�[�ݒ�
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// �`�悷����̂��Ƃɕς�����
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

	// �}�g���N�X�ݒ�
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(ResourceTag::mBullet)->Draw();
}
