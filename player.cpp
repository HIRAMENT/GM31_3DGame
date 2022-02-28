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
#include "scene.h"
#include "sensor.h"
#include "enemy.h"
#include "obb.h"
#include "gauge.h"
#include "number.h"
#include "calculation.h"
#include "collision.h"
#include "movement.h"
#include "ImGUI/imgui.h"
#include "status.h"
#include "hitPoint.h"
#include "attack.h"
#include "meshField.h"
#include "viewSensor.h"
#include <math.h>
#include "playerState.h"
#include "playerIdle.h"
#include "playerDamage.h"

#define BLENDRATE (0.1f)
#define ATTACK_COOLTIME (64)

Player::Player(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene,ObjectType::eObPlayer,drawPriority)
{
	SetPosition(pos);
	m_Transform.SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 0.015f, 0.015f, 0.015f });

	m_Model = ResourceData::GetInstance()->GetAnimationModel(ResourceTag::fPlayer);
	m_Size = m_Model->GetSize() * m_Scale - D3DXVECTOR3(2.0f, 0.0f, 0.0f);
	m_Adjust = D3DXVECTOR3(0.0f, m_Size.y / 2, 0.0f);

	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {2.0f,2.0f}, 2);
	m_Obb = new OBB(m_Position, m_Size, m_Adjust, m_Rotation);

	m_AttackRange = 50;
	m_AttackLength = 10;
	m_ViewSensor = new ViewSensor(scene, m_Position, 5, m_AttackLength, m_AttackRange);
	m_ViewSensor->SetDisplay(m_SensorDisplay = false);

	CreateStatusInfo(scene);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(0, 255, 0);
	
	m_AnimeFrame = 0;
	m_AnimeEndFrame = 100000;
	m_BlendRate = 0.0f;
	m_ChangeAnime = false;

	m_BeforAnime = AnimationTag::Idle;
	m_AfterAnime = AnimationTag::Run;

	m_EffectHandle = -1;

	m_TecPoint = 0;
	m_CostGauge = new Gauge(scene, { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 32 }, {50,50},100,100);
	m_CostGauge->ChangeColor(0, 128, 255);
	m_CostGauge->DegCapacity(100);

	m_State = new PlayerIdle(this);

	m_isDead = false;

	scene->Add(this);
}

void Player::Init()
{
}

void Player::Uninit()
{
	m_Shadow->SetDestroy();
	m_Status->SetDestroy();
	m_ViewSensor->SetDestroy();
	m_CostGauge->SetDestroy();
	delete m_Obb;
	delete m_Effect;
}

void Player::Update()
{
	if (m_Status->GetHitPoint()->GetCoolTimeCounter().GetRest() == m_Status->GetHitPoint()->GetCoolTimeCounter().GetMax() - 1.0f)
	{
		ChangeState(new PlayerDamage(this));
	}

	Animation();

	m_State->Update(this);

	SetPlayer();
}

void Player::Draw()
{
	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationQuaternion(&rot, &m_Transform.GetQuaternion());
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	m_World = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&m_World);

	m_Model->Draw();
}

void Player::SetPlayer()
{
	MeshField* meshField = GetScene()->GetGameObject<MeshField>(ObjectType::eObField);
	m_Position.y = meshField->GetHeight(m_Position);
	SetPosition(m_Transform.GetPosition() + D3DXVECTOR3(0.0f,m_Position.y, 0.0f));
	SetPlayerRotation(m_Transform.GetQuaternion());
	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_Adjust, m_Rotation);
	m_ViewSensor->SetInfo(m_Position, { m_Forward.x, m_Forward.y, -m_Forward.z }, m_AttackRange, m_AttackLength, m_SensorDisplay);
}

void Player::SetPlayerRotation(const Quaternion & qua)
{
	m_Up = qua * Vec3::Up;
	m_Forward = qua * Vec3::Forward;
	m_Right = qua * Vec3::Right;
}

void Player::AddCost(float add)
{
	if(m_TecPoint < 100)
	{ 
		m_TecPoint += add;
		m_CostGauge->AddCapacity(add);
	}
	else
	{
		m_TecPoint = 100;
	}
}

void Player::DecCost(float dec)
{
	m_TecPoint -= dec;
	m_CostGauge->DegCapacity(dec);
}

void Player::ChangeState(PlayerState * state)
{
	delete m_State;
	m_State = state;
}

void Player::SetAnimation(AnimationTag tag)
{
	m_BeforAnime = m_AfterAnime;
	m_AfterAnime = tag;
	m_ChangeAnime = true;
}

void Player::ImGui()
{
	ImGui::Begin("Status");

	ImGui::Text("AttackCoolTime");
	ImGui::SameLine;
	ImGui::Text("%f", m_Status->GetAttack()->GetCoolTime().GetRest());

	ImGui::SetNextTreeNodeOpen(true, ImGuiTreeNodeFlags_None);
	if (ImGui::TreeNode("ViewSensore")) {
		ImGui::SliderInt("Range", &m_AttackRange, 0, 90);
		ImGui::SliderInt("Length", &m_AttackLength, 0, 100);
		ImGui::Checkbox("Display", &m_SensorDisplay);

		ImGui::TreePop();
	}



	ImGui::End();
}

void Player::Animation()
{
	// 前と違ったらアニメーションの切り替え
	if (m_ChangeAnime) {
		m_AnimeFrame = 0;
		m_AnimeEndFrame = ResourceData::GetInstance()->GetAnimationResource(m_AfterAnime)->GetAnimationCount();
		m_BlendRate = 0.0f;
		m_ChangeAnime = false;
	}

	// ブレンドレートの変更
	if (m_BlendRate < 1.0f) { m_BlendRate += BLENDRATE; }

	// アニメーションの更新
	m_Model->Update(m_BeforAnime, m_AfterAnime, m_AnimeFrame, m_BlendRate);

	if (!m_isDead)
	{
		m_AnimeFrame += 1.0f;
	}
}

void Player::CreateStatusInfo(Scene* scene)
{
	StatusInfo info;
	info.m_AttackCoolTime = 60.0f;
	info.m_AttackPower = 100;
	info.m_DifenceValue = 10;
	info.m_HitPointCoolTime = 30.0f;
	info.m_HitPointDimention = 2;
	info.m_HitPointPos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 64, 0);
	info.m_HitPointSize = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	info.m_HitPointValue = 1234;
	info.m_IsNumberDisplay = true;
	m_Status = new Status(scene, &info);
}
