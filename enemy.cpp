#include "main.h"
#include <time.h>
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "shader.h"
#include "model.h"
#include "enemy.h"
#include "player.h"
#include "scene.h"
#include "obb.h"
#include "collision.h"
#include "gauge.h"
#include "shadow.h"
#include "status.h"
#include "hitPoint.h"
#include "meshField.h"
#include "particle.h"
#include "particleManager.h"
#include "enemyIdle.h" 
#include "enemyDamage.h" 
#include "enemyDead.h"

#define INITIAL_POS_Y (1.0f)

Enemy::Enemy(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 size, int drawPriority)
	:GameObject(scene, ObjectType::eObEnemy,drawPriority)
{
	SetPosition(pos);
	SetRotation({ 0.0f, degToRad(180), 0.0f });
	SetScale(size);

	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {1.0f,1.0f}, 2);

	m_EnemyState = new EnemyIdle();

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
	// ダメージを受けたらノックバック
	/// カウンターの残りが最大値と同じなら攻撃を受けた直後
	if (m_Status->GetHitPoint()->GetCoolTimeCounter().GetRest() == m_Status->GetHitPoint()->GetCoolTimeCounter().GetMax())
	{
		ChangeState(new EnemyDamage(this));
	}

	m_EnemyState->Update(this);

	SetEnemy();
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
	m_FieldHeight = meshField->GetHeight(m_Position) + (INITIAL_POS_Y * m_Scale.y);
	m_Position.y = m_FieldHeight + m_JumpValuse;
	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	m_Target = player->GetPosition();

	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_ObbAdjust, m_Rotation);
	m_Status->GetHitPoint()->GetGauge()->SetGaugePos(m_Position);
}

void Enemy::ChangeState(EnemyState* next)
{
	delete m_EnemyState;
	m_EnemyState = next;
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
