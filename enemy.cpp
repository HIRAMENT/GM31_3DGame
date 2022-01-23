#include "main.h"
#include <time.h>
#include "manager.h"
#include "renderer.h"
#include "resource.h"
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
#include "gauge.h"
#include "shadow.h"
#include "movement.h"
#include "rock.h"
#include "experiencePoint.h"
#include "status.h"
#include "hitPoint.h"
#include "boids.h"
#include "meshField.h"
#include "attack.h"
#include "particle.h"
#include "particleManager.h"
#include "enemyIdol.h" 
#include "enemyMove.h"
#include "enemyDamage.h" 
#include "enemyAttackJump.h"

#define INITIAL_POS_Y (1.0f)

Enemy::Enemy(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority)
	:GameObject(scene, ObjectType::eObEnemy,drawPriority)
	, m_FollowRange(2.0f)
{
	SetPosition(pos);
	SetRotation({ 0.0f, degToRad(180), 0.0f });
	SetScale(size);

	m_Size = size;
	m_SensorSize = { 15.0f,15.0f,15.0f };

	m_Attack = false;
	m_AttackCollTime = 0;
	m_AttackMotionCount = 0;
	m_AttackTarget = { 0.0f,0.0f,0.0f };
	m_AttackCount = 0;

	m_Obb = new OBB(m_Position, size, m_Rotation);
	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {1.0f,1.0f}, 2);

	m_SensorEnter = false;

	m_EnemyState = new EnemyMove();

	scene->Add(this);
}

void Enemy::Init()
{
}

void Enemy::Uninit()
{
	m_Shadow->SetDestroy();
	m_Status->SetDestroy();
	delete m_Obb;
}

void Enemy::Update()
{
	/*m_MoveVlaue = { 0.0f,0.0f,0.0f };

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
	}*/

	// ダメージを受けたらノックバック
	/// カウンターの残りが最大値と同じなら攻撃を受けた直後
	if (m_Status->GetHitPoint()->GetCoolTimeCounter().GetRest() == m_Status->GetHitPoint()->GetCoolTimeCounter().GetMax())
	{
		ChangeState(new EnemyDamage);
	}

	m_EnemyState->Update(this);

	SetEnemy();

	if (m_Status->GetHitPoint()->GetHitPoint() <= 0)
	{
		CreateParticle();
		SetDestroy();
	}
}

void Enemy::Draw()
{
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
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(m_ModelTag)->Draw();
}

void Enemy::SetEnemy()
{
	MeshField* meshField = GetScene()->GetGameObject<MeshField>(ObjectType::eObField);
	m_Position.y = meshField->GetHeight(m_Position) + INITIAL_POS_Y;
	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	m_Target = player->GetPosition();

	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_Rotation);
	m_Status->GetHitPoint()->GetGauge()->SetGaugePos(m_Position);
}

void Enemy::ChangeState(EnemyState* next)
{
	delete m_EnemyState;
	m_EnemyState = next;
}

void Enemy::Attack(D3DXVECTOR3 ppos)
{

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

void Enemy::CreateParticle()
{
	ParticleInfo info;
	info.m_Position = m_Position;
	info.m_TextureTag = ResourceTag::tParticleCircle;
	info.m_DrawPriority = 2;
	info.m_ProductionInterval = 0.0f;
	info.m_BlendMode = BlendMode::ADDITION;
	info.m_ProductionType = ProductionType::Point;
	info.m_is2Dimension = false;
	info.m_isCurve = false;
	info.m_isBillboard = true;
	info.m_ProductionOnes = true;
	info.m_AngleMin = 0;
	info.m_AngleMax = 360;
	info.m_LifeSpanMin = 0.3f;
	info.m_LifeSpanMax = 0.6f;
	info.m_ProductionMin = 25;
	info.m_ProductionMax = 50;
	info.m_ScaleMin = 0.1f;
	info.m_ScaleMax = 0.5f;
	info.m_SpeedMin = 0.1f;
	info.m_SpeedMax = 0.2f;
	info.m_RedMin = 0.0f;
	info.m_RedMax = 0.0f;
	info.m_GreenMin = 0.0f;
	info.m_GreenMax = 1.0f;
	info.m_BlueMin = 1.0f;
	info.m_BlueMax = 1.0f;
	info.m_AlphaMin = 0.5f;
	info.m_AlphaMax = 0.8f;
	info.m_GravityUse = false;
	new ParticleManager(GetScene(), &info);
}
