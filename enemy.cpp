#include "main.h"
#include <time.h>
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "model.h"
#include "ADX2/adxSound.h"
#include "enemy.h"
#include "player.h"
#include "sensor.h"
#include "scene.h"
#include "obb.h"
#include "collision.h"
#include "sword.h"
#include "billboard.h"
#include "gauge.h"
#include "shadow.h"
#include "movement.h"
#include "rock.h"
#include "experiencePoint.h"
#include "status.h"
#include "hitPoint.h"

Enemy::Enemy(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adjust, int hp, ObjectType type, int drawPriority)
	:GameObject(scene, type,drawPriority)
{
	SetPosition(pos);
	SetRotation({ 0.0f, degToRad(180), 0.0f });
	SetScale(size * 1.5f);

	m_Status = new Status(scene, pos, adjust, 50, 0, 100, 0, hp, 3);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(255, 0, 0);

	m_Size = size;
	m_SensorSize = { 15.0f,15.0f,15.0f };

	m_Attack = false;
	m_AttackCollTime = 0;
	m_AttackMotionCount = 0;
	m_AttackTarget = { 0.0f,0.0f,0.0f };
	m_AttackCount = 0;

	m_Sensor = new Sensor(scene, m_Position, m_SensorSize, 50);
	m_Obb = new OBB(m_Position, size, m_Rotation);
	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {1.0f,1.0f}, 2);
	if (type == ObjectType::eObSmallEnemy)
	{
		m_ModelTag = ResourceTag::mSmallEnemy;
		//m_HPGauge = new Gauge(scene, pos, adjust, m_HP, 50);
	}
	else if (type == ObjectType::eObBossEnemy)
	{
		m_ModelTag = ResourceTag::mBossEnemy;
		//m_HPGauge = new Gauge(scene, { SCREEN_WIDTH / 2, 32 }, {100,50}, m_HP, 100);
	}

	m_SensorEnter = false;

	scene->Add(this);
}

void Enemy::Init()
{
}

void Enemy::Uninit()
{
	m_Sensor->SetDestroy();
	m_Shadow->SetDestroy();
	m_Status->SetDestroy();
	delete m_Obb;
}

void Enemy::Update()
{
	m_MoveVlaue = { 0.0f,0.0f,0.0f };

	if (m_Exclamation && m_Exclamation->GetDestroy())
	{
		m_Exclamation = nullptr;
	}

	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	if (m_Sensor->isDetection(player->GetObb()))
	{
		if (!m_SensorEnter && !m_Exclamation)
		{
		    m_Exclamation = new Billboard(GetScene(), { m_Position.x, m_Position.y + 2, m_Position.z }, { 2.0f,2.0f }, ResourceTag::tExclamation, true, 50);
			ADXSound::GetInstance()->Play(8);
			m_ExcScale = 0.0f;
			m_Exclamation->SetScale(m_ExcScale);
			m_SensorEnter = true;
			m_AttackCollTime = 0;
			m_Status->GetHitPoint()->GetGauge()->SetDisplay(true);
		}

		TargetMove(player->GetPosition());
		m_AttackCollTime++;
	}
	else
	{
		SloppyMove();
		m_SensorEnter = false;
		m_Status->GetHitPoint()->GetGauge()->SetDisplay(false);
	}

	if(m_Exclamation)
	{
		if (m_ExcScale < 1.0f)
		{
			m_ExcScale += 0.1f;
			m_Exclamation->SetScale(m_ExcScale);
		}
		else if (m_ExcScale >= 1.0f)
		{
			m_ExcScale += 0.1f;
			if (m_ExcScale >= 2.0f)
			{
				m_Exclamation->SetDestroy();
			}
		} 
	}

	if (m_Status->GetHitPoint()->CheckCollTime())
	{
		Sword* sword = GetScene()->GetGameObject<Sword>(ObjectType::eObSword);
		if (sword->GetAttack() && Collision::GetInstance()->ObbToObb(sword->GetObb(), m_Obb))
		{
			new Billboard(GetScene(), m_Position, { 5.0f, 5.0f }, ResourceTag::tSlash,true, 2);
			m_Status->GetHitPoint()->Damage(sword->GetDamageValue());
			ADXSound::GetInstance()->Play(9);
		}
	}


	if (m_Status->GetHitPoint()->GetHitPoint() <= 0) { SetDestroy(); }


	if (!m_Attack && m_AttackCollTime >= 30)
	{
		m_Attack = true;
	}
	else if (m_Attack)
	{
		if (m_AttackCount >= 5)
		{
			JumpAttack(player->GetPosition());
		}
		else
		{
			RushAttack(player->GetPosition());
		}
		
	}

	SetEnemy();

	std::vector<Rock*>rockList = GetScene()->GetGameObjects<Rock>(ObjectType::eObRock);
	for (Rock* rock : rockList)
	{
		if (Collision::GetInstance()->ObbToObb(m_Obb, rock->GetObb()))
		{
			m_Position -= m_MoveVlaue;
			SetEnemy();
		}
	}
}

void Enemy::Draw()
{
	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(m_ModelTag)->Draw();
}

void Enemy::SetEnemy()
{
	m_Position += m_MoveVlaue;
	m_Sensor->SetSensorPosition(m_Position, m_SensorSize, m_Rotation);
	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_Rotation);
	//m_HPGauge->SetGaugePos(m_Position);
	m_Status->GetHitPoint()->GetGauge()->SetGaugePos(m_Position);
}

void Enemy::Attack(D3DXVECTOR3 ppos)
{

}

void Enemy::RushAttack(D3DXVECTOR3 ppos)
{
	m_AttackMotionCount++;

	if (m_AttackMotionCount >= 20 && m_AttackMotionCount < 30)
	{
		m_MoveVlaue.x += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).x;
		m_MoveVlaue.z += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).z;
	}
	if (m_AttackMotionCount >= 30 && m_AttackMotionCount < 40)
	{
		m_MoveVlaue.x -= Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).x;
		m_MoveVlaue.z -= Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).z;
	}
	if (m_AttackMotionCount >= 40)
	{
		m_AttackMotionCount = 0;
		m_Attack = false;
		m_AttackCollTime = 0;
		m_AttackCount++;
	}
}

void Enemy::JumpAttack(D3DXVECTOR3 ppos)
{
	m_AttackMotionCount++;

	if (m_AttackMotionCount >= 20 && m_AttackMotionCount < 40)
	{
		m_MoveVlaue.x += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).x;
		m_MoveVlaue.z += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).z;
		m_MoveVlaue.y += 1.0f;
	}
	if (m_AttackMotionCount >= 40 && m_AttackMotionCount < 60)
	{
		m_MoveVlaue.x += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).x;
		m_MoveVlaue.z += Movement::GetInstance()->TargetFollow(m_Position, ppos, 0.1f).z;
		m_MoveVlaue.y -= 1.0f;
	}
	if (m_AttackMotionCount >= 60)
	{
		m_AttackMotionCount = 0;
		m_Attack = false;
		m_AttackCollTime = 0;
		m_AttackCount = 0;
	}
}

void Enemy::TargetMove(D3DXVECTOR3 pPos)
{
	m_Position.x += Movement::GetInstance()->TargetFollow(m_Position, pPos, 0.05f).x;
	m_Position.z += Movement::GetInstance()->TargetFollow(m_Position, pPos, 0.05f).z;
	float angle = Movement::GetInstance()->GetTwoVecAngle({ 0,1 }, { pPos.x - m_Position.x, pPos.z - m_Position.z });
	if (pPos.x - m_Position.x < 0.0f) angle *= -1;
	m_Rotation.y = angle;
}

void Enemy::SloppyMove()
{
	m_SloppyTime++;
	srand(time(NULL));

	if (m_SloppyTime >= 20 && m_SloppyTime < 40)
	{
		m_Rotation.y += rand() % 10 * 0.01f;
	}
	if (m_SloppyTime >= 60 && m_SloppyTime < 80)
	{
		m_Rotation.y -= rand() % 10 * 0.01f;
	}
	if (m_SloppyTime >= 80)
	{
		m_SloppyTime = 0;
	}
}

void Enemy::FreeMove()
{
	
}

