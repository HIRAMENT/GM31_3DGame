#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "input.h"
#include "gamepad.h"
#include "model.h"
#include "ADX2/adxSound.h"
#include "scene.h"
#include "sword.h"
#include "player.h"
#include "enemy.h"
#include "movement.h"
#include "obb.h"

Sword::Sword(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	: GameObject(scene,ObjectType::eObSword,drawPriority)
{
	SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 0.5f, 0.5f, 0.5f });
	m_MovePosition = { 0.0f,0.0f };
	m_Attack = false;
	m_Angle = 0;
	m_SwingAngle = 0;
	m_Obb = new OBB(m_Position, m_Size, m_Rotation);
	scene->Add(this);
}

void Sword::Init()
{
}

void Sword::Uninit()
{
}

void Sword::Update()
{
	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	D3DXVECTOR3 pos = player->GetPosition();

	if (m_Attack)
	{
		if (m_Rotation.z != degToRad(-90))
		{
			ADXSound::GetInstance()->Play(6);
		}

		float length = 0.0f;
		D3DXVECTOR3 ePos;
		std::vector<Enemy*> enemyList = GetScene()->GetGameObjects<Enemy>(ObjectType::eObSmallEnemy);
		Enemy* bossEnemy = GetScene()->GetGameObject<Enemy>(ObjectType::eObBossEnemy);
		for (Enemy* enemy : enemyList)
		{
			if (length == 0.0f || D3DXVec3LengthSq(&(enemy->GetPosition() - pos)) <= length)
			{
				ePos = enemy->GetPosition();
				length = D3DXVec3LengthSq(&(ePos - pos));			
			}
		}
		if (bossEnemy)
		{
			if (length == 0.0f || D3DXVec3LengthSq(&(bossEnemy->GetPosition() - pos)) <= length)
			{
				ePos = bossEnemy->GetPosition();
				length = D3DXVec3LengthSq(&(ePos - pos));
			}

		}
		float angle = Movement::GetInstance()->GetTwoVecAngle({ 0,1 }, {ePos.x - pos.x,ePos.z - pos.z});
		if ((ePos.x - pos.x) > 0.0f) angle *= -1;

		m_Rotation.z = degToRad(-90);
		m_Rotation.y = degToRad(m_SwingAngle) - angle;
		// 回転処理
		m_MovePosition = Movement::GetInstance()->CirclualMotion(player->GetPosition(), 2, m_Angle + radToDeg(angle));
		m_Angle += 5;
		m_SwingAngle -= 5;
		if (m_Angle >= 180)
		{
			m_Rotation.z = 0;
			m_Rotation.y = 0;
			m_Angle = 0;
			m_SwingAngle = 0;
			m_MovePosition = { 0.0f,0.0f };
			m_Attack = false;
		}

		// 位置の更新
		m_Position.x = m_MovePosition.x;
		m_Position.z = m_MovePosition.y;
	}
	else
	{
		m_Position.x = pos.x;
		m_Position.z = pos.z;
	}


	m_Obb->SetObb(m_Position, m_Size, m_Rotation);
}

void Sword::Draw()
{
	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);

	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	//m_World *= player->GetWorldMatrix();
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(ResourceTag::mSword)->Draw();
}

void Sword::SetAttack(D3DXVECTOR2 vec)
{
	m_Attack = true;
}
