#include "main.h"
#include "manager.h"
#include "shader.h"
#include "renderer.h"
#include "input.h"
#include "gamepad.h"
#include "ADX2/adxSound.h"
#include "animationModel.h"
#include "model.h"
#include "player.h"
#include "shadow.h"
#include "sword.h"
#include "scene.h"
#include "sensor.h"
#include "enemy.h"
#include "obb.h"
#include "gauge.h"
#include "number.h"
#include "calculation.h"
#include "collision.h"
#include "camera.h"
#include "movement.h"
#include "rock.h"
#include "fileManager.h"

Player::Player(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene,ObjectType::eObPlayer,drawPriority)
	, m_Size({1.0f,1.0f,1.0f})
{
	SetPosition(pos);
	m_Transform.SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 0.015f, 0.015f, 0.015f });
	m_HP = 1234;
	m_HPMax = 1234;
	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {2.0f,2.0f}, 2);
	m_Sword = new Sword(scene, { pos.x ,pos.y, pos.z }, 2);
	m_Obb = new OBB(m_Position, m_Size, m_Rotation);
	m_HPGauge = new Gauge(scene, { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 64 }, { 100.0f,100.0f}, m_HP, 100);
	m_HPGauge->ChangeColor(0, 255, 0);
	for (int i = 0; i < 4; i++)
	{
		m_HPNumber[i]    = new Number(scene, { (float)SCREEN_WIDTH / 2 - (16 * (i + 1)),            (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HP, i + 1), 110);
		m_HPMaxNumber[i] = new Number(scene, { (float)SCREEN_WIDTH / 2 + (16 * 5) - (16 * (i + 1)), (float)SCREEN_HEIGHT - 64,0 }, { 24,24,0 }, Calculation::GetInstance()->ExtractDigit(m_HP, i + 1), 110);
	}
	m_HPSlashNumber = new Number(scene, { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 64 ,0 }, { 24, 24, 0 }, 12, 110);
	m_HitCoolTime = 0;
	m_Dash = false;

	m_Model = ResourceData::GetInstance()->GetAnimationModel(ResourceTag::fPlayer);
	
	m_AnimeFrame = 0;
	m_BlendRate = 0.0f;
	
	scene->Add(this);
}

void Player::Init()
{
}

void Player::Uninit()
{
	m_Shadow->SetDestroy();
	m_Sword->SetDestroy();
	m_HPGauge->SetDestroy();
	for (int i = 0; i < 4; i++)
	{
		m_HPNumber[i]->SetDestroy();
		m_HPMaxNumber[i]->SetDestroy();
	}
	m_HPSlashNumber->SetDestroy();
	delete m_Obb;

	delete m_Model;
}

void Player::Update()
{
	D3DXVECTOR3 rot = { 0.0f,0.0f,0.0f };
	D3DXVECTOR2 move = { 0.0f,0.0f };
	float angle;
	bool isMove = false;

	Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	D3DXVECTOR2 forward = { camera->GetForwardVec().x,camera->GetForwardVec().z };
	D3DXVECTOR2 right = { camera->GetRightVec().x, camera->GetRightVec().z };

	angle = Movement::GetInstance()->GetTwoVecAngle({ Vec3::Forward.x,Vec3::Forward.z }, forward);
	if (forward.x <= -0.01f) angle *= -1;

	if (Keyboard_IsPress(DIK_A))
	{
		move += right * 0.1f;
		rot.x = radToDeg(angle) - 90;
		isMove = true;
	}
	if (Keyboard_IsPress(DIK_D))
	{
		move -= right * 0.1f;
		rot.x = radToDeg(angle) + 90;
		isMove = true;
	}
	if (Keyboard_IsPress(DIK_W))
	{
		move += forward * 0.1f;
		rot.x = radToDeg(angle);
		isMove = true;
	}
	if (Keyboard_IsPress(DIK_S))
	{
		move -= forward * 0.1f;
		rot.x = radToDeg(angle) + 180;
		isMove = true;
	}

	if (Mouse_IsLeftTrigger()) 
	{
		m_Sword->SetAttack({m_Forward.x, m_Forward.z}); 
	}
	if (Mouse_IsRightPress()) { m_Dash = true; }

	if (m_Dash)
	{
		move.x *= 2;
		move.y *= 2;
		m_Dash = false;
	}
	m_Transform.Translate({move.x, 0.0f, move.y});
	if (isMove)
	{
		if (m_BlendRate <= 1.0f) { m_BlendRate += 0.1f; }
		m_Transform.SetRotation(Vec3::Up, rot.x);
	}
	else
	{
		if (m_BlendRate >= 0.0f) { m_BlendRate -= 0.1f; }
	}

	m_Model->Update(AnimationTag::Idle, AnimationTag::Run, m_AnimeFrame, m_BlendRate);


	if (!m_HitCoolTime)
	{
		std::vector<Enemy*> enemyList = GetScene()->GetGameObjects<Enemy>(ObjectType::eObSmallEnemy);
		Enemy* bossEnemy = GetScene()->GetGameObject<Enemy>(ObjectType::eObBossEnemy);
		for (Enemy* enemy : enemyList)
		{
			if (enemy && enemy->GetAttack() && Collision::GetInstance()->ObbToObb(enemy->GetObb(), m_Obb))
			{
				TakeDamage(enemy->GetDamageValue());
				ADXSound::GetInstance()->Play(7);
				m_HitCoolTime++;
			}
		}
		if (bossEnemy && bossEnemy->GetAttack() && Collision::GetInstance()->ObbToObb(bossEnemy->GetObb(), m_Obb))
		{
			TakeDamage(bossEnemy->GetDamageValue());
			ADXSound::GetInstance()->Play(7);
			m_HitCoolTime++;
		}
	}
	else if (m_HitCoolTime)
	{
		m_HitCoolTime++;
		if (m_HitCoolTime > HITCOOLTIME_MAX) m_HitCoolTime = 0;
	}

	SetPlayer();
	m_AnimeFrame++;

	std::vector<Rock*>rockList = GetScene()->GetGameObjects<Rock>(ObjectType::eObRock);
	for (Rock* rock : rockList)
	{
		if (Collision::GetInstance()->ObbToObb(m_Obb, rock->GetObb()))
		{
			m_Transform.Translate({ -move.x, 0.0f, -move.y });
			SetPlayer();
		}
	}
}

void Player::Draw()
{
	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	//D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixRotationQuaternion(&rot, &m_Transform.GetQuaternion());
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	m_World = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&m_World);

	//Resource::GetInstance()->GetModelResource(ResourceTag::mPlayer)->Draw();
	m_Model->Draw();
}

void Player::SetPlayer()
{
	SetPosition(m_Transform.GetPosition());
	SetPlayerRotation(m_Transform.GetQuaternion());
	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_Rotation);
}

void Player::SetPlayerRotation(const Quaternion & qua)
{
	m_Up = qua * Vec3::Up;
	m_Forward = qua * Vec3::Forward;
	m_Right = qua * Vec3::Right;
}

void Player::TakeDamage(int damage)
{
	m_HP -= damage;
	if (m_HP <= 0) 
	{
		m_HP = 0;
	}
	m_HPGauge->DegCapacity(damage);
	for (int i = 0; i < 4; i++)
	{
		m_HPNumber[i]->ChangeNumber(Calculation::GetInstance()->ExtractDigit(m_HP, i + 1));
	}
}
