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
#include "ImGUI/imgui.h"
#include "experiencePoint.h" 
#include "status.h"
#include "hitPoint.h"
#include "attack.h"
#include "meshField.h"
#include "polygon3D.h"
#include "viewSensor.h"
#include <math.h>

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
	m_Size = m_Model->GetSize() * m_Scale;

	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, {2.0f,2.0f}, 2);
	m_Obb = new OBB(m_Position, m_Size, m_Rotation);

	m_AttackRange = 50;
	m_AttackLength = 10;
	m_ViewSensor = new ViewSensor(scene, m_Position, 5, m_AttackLength, m_AttackRange);
	m_ViewSensor->SetDisplay(m_SensorDisplay = false);

	m_Dash = false;

	CreateStatusInfo(scene);
	m_Status->GetHitPoint()->GetGauge()->ChangeColor(0, 255, 0);
	
	m_AnimeFrame = 0;
	m_AnimeEndFrame = 100000;
	m_AnimeFrameRiseValue = 1;
	m_BlendRate = 0.0f;

	m_BeforAnime = AnimationTag::Idle;
	m_AfterAnime = AnimationTag::Run;
	
	scene->Add(this);
}

void Player::Init()
{
}

void Player::Uninit()
{
	m_Shadow->SetDestroy();
	//m_Sword->SetDestroy();
	m_Status->SetDestroy();
	m_ViewSensor->SetDestroy();
	delete m_Obb;
}

void Player::Update()
{
	D3DXVECTOR3 rot = { 0.0f,0.0f,0.0f };
	D3DXVECTOR2 move = { 0.0f,0.0f };
	float angle;
	AnimationTag animation[2] = {m_BeforAnime, m_AfterAnime};
	bool isMove = false;

	Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	D3DXVECTOR2 forward = { camera->GetForwardVec().x,camera->GetForwardVec().z };
	D3DXVECTOR2 right = { camera->GetRightVec().x, camera->GetRightVec().z };

	angle = Movement::GetInstance()->GetTwoVecAngle({ Vec3::Forward.x,Vec3::Forward.z }, forward);
	if (forward.x < 0.0f) angle *= -1;


	if (Keyboard_IsPress(DIK_A)){
		move += right * 0.1f;
		rot.x = radToDeg(angle) + 90;
	}
	if (Keyboard_IsPress(DIK_D)){
		move -= right * 0.1f;
		rot.x = radToDeg(angle) - 90;
	}
	if (Keyboard_IsPress(DIK_W)){
		move += forward * 0.1f;
		rot.x = radToDeg(angle) + 180;
	}
	if (Keyboard_IsPress(DIK_S)){
		move -= forward * 0.1f;
		rot.x = radToDeg(angle);
	}

	m_Transform.Translate({ move.x, 0.0f, move.y });

	if (Mouse_IsRightPress()) 
		m_Dash = true;

	if (m_Dash){
		move.x *= 2;
		move.y *= 2;
		m_Dash = false;
	}

	if (move.x != 0.0f || move.y != 0.0f){
		m_Transform.SetRotation(Vec3::Up, rot.x);
		isMove = true;
	}

	if (Keyboard_IsPress(DIK_SPACE)) {
		animation[0] = AnimationTag::Idle;
		animation[1] = AnimationTag::Jump;
	}

	if (Mouse_IsLeftTrigger()) {
		if (m_Status->GetAttack()->CheckCoolTime()) {
			animation[0] = AnimationTag::Idle;
			animation[1] = AnimationTag::Attack;
			m_Status->GetAttack()->SetCoolTime(ATTACK_COOLTIME);
			std::vector<Enemy*> enemys = GetScene()->GetGameObjects<Enemy>(ObjectType::eObEnemy);
			bool isHit = false;
			for (auto enemy : enemys) {
				isHit = false;

				if (Mouse_IsRightPress()) {
					if (D3DXVec3Length(&(enemy->GetPosition() - m_Position)) < 10){
						isHit = true;
					}
				}
				else	{
					if (m_ViewSensor->WithinRange(m_Position, enemy->GetPosition(), { m_Forward.x, m_Forward.y, -m_Forward.z }, enemy->GetScale())) {
						isHit = true;
					}
				}

				if(isHit)
				{
					enemy->GetStatus()->GetHitPoint()->Damage(m_Status->GetAttack()->GetPower());
					new Polygon3D(GetScene(), enemy->GetPosition(), D3DXVECTOR3(10, 10, 0), ResourceTag::tSlash, true, true, 100);
					ADXSound::GetInstance()->Play(9);
				}
			}
		}
	}

	Animation(animation[0], animation[1], isMove);

	if (m_Status->GetHitPoint()->CheckCollTime())
	{
		std::vector<Enemy*> enemyList = GetScene()->GetGameObjects<Enemy>(ObjectType::eObEnemy);
		for (Enemy* enemy : enemyList)
		{
			if (enemy && enemy->GetAttack() && Collision::GetInstance()->ObbToObb(enemy->GetObb(), m_Obb))
			{
				m_Status->GetHitPoint()->Damage(enemy->GetStatus()->GetAttack()->GetPower());
				ADXSound::GetInstance()->Play(7);
			}
		}
	}

	SetPlayer();



	std::vector<Rock*>rockList = GetScene()->GetGameObjects<Rock>(ObjectType::eObRock);
	for (Rock* rock : rockList)
	{
		if (Collision::GetInstance()->ObbToObb(m_Obb, rock->GetObb()))
		{
			m_Transform.Translate({ -move.x, 0.0f, -move.y });
			SetPlayer();
		}
	}

	//ImGui();
}

void Player::Draw()
{
	Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	if (!camera->CheckView(m_Position, m_Right, m_Size))
		return;


	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

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
	MeshField* meshField = GetScene()->GetGameObject<MeshField>(ObjectType::eObField);
	m_Position.y = meshField->GetHeight(m_Position);
	SetPosition(m_Transform.GetPosition());
	SetPlayerRotation(m_Transform.GetQuaternion());
	m_Shadow->SetPosition({ m_Position.x, 0.f,m_Position.z });
	m_Obb->SetObb(m_Position, m_Size, m_Rotation);
	m_ViewSensor->SetInfo(m_Position, { m_Forward.x, m_Forward.y, -m_Forward.z }, m_AttackRange, m_AttackLength, m_SensorDisplay);
}

void Player::SetPlayerRotation(const Quaternion & qua)
{
	m_Up = qua * Vec3::Up;
	m_Forward = qua * Vec3::Forward;
	m_Right = qua * Vec3::Right;
}

void Player::ImGui()
{
	ImGui::Begin("Status");
	//ImGui::SliderInt("Attack",m_Status->, 0, 10);

	ImGui::Text("AttackCoolTime");
	ImGui::SameLine;
	ImGui::Text("%d", m_Status->GetAttack()->GetCoolTime());

	ImGui::SetNextTreeNodeOpen(true, ImGuiTreeNodeFlags_None);
	if (ImGui::TreeNode("ViewSensore")) {
		ImGui::SliderInt("Range", &m_AttackRange, 0, 90);
		ImGui::SliderInt("Length", &m_AttackLength, 0, 100);
		ImGui::Checkbox("Display", &m_SensorDisplay);

		ImGui::TreePop();
	}



	ImGui::End();
}

void Player::Animation(AnimationTag anime1, AnimationTag anime2, bool isMove)
{
	// 前と違ったらアニメーションの切り替え
	if (m_BeforAnime != anime1 || m_AfterAnime != anime2) {
		m_BeforAnime = anime1;
		m_AfterAnime = anime2;
		m_AnimeFrame = 0;
		m_AnimeEndFrame = ResourceData::GetInstance()->GetAnimationResource(m_AfterAnime)->GetAnimationCount();
		m_BlendRate = 0.0f;
		if (m_AfterAnime == AnimationTag::Attack) { 
			m_AnimeFrameRiseValue = 2; 
		}
	}

	// アニメーション関連の初期化
	if (m_AnimeFrame >= m_AnimeEndFrame) {
		m_AnimeFrame = 0;
		m_AnimeEndFrame = 1000;
		m_AnimeFrameRiseValue = 1;
		m_BeforAnime = AnimationTag::Idle;
		m_AfterAnime = AnimationTag::Run;
		m_BlendRate = 0.0f;
	}

	// ブレンドレートの変更
	if (m_AfterAnime == AnimationTag::Run)
	{
		if (isMove)
		{
			if (m_BlendRate < 1.0f) { m_BlendRate += BLENDRATE; }	// 動き出したらブレンドレートを上げる
		}
		else if (!isMove)
		{
			if (m_BlendRate > 0.0f) { m_BlendRate -= BLENDRATE; }	// 動いてないときにブレンドレートを下げる
		}
	}
	else
	{
		if (m_AnimeFrame >= 0.0f && m_AnimeFrame < m_AnimeFrameRiseValue / BLENDRATE) {
			m_BlendRate += BLENDRATE;
		}
		else if (m_AnimeEndFrame - (m_AnimeFrameRiseValue / BLENDRATE) <= m_AnimeFrame && m_AnimeEndFrame > m_AnimeFrame) {
			m_BlendRate -= BLENDRATE;
		}
	}
	

	// アニメーションの更新
	m_Model->Update(m_BeforAnime, m_AfterAnime, m_AnimeFrame, m_BlendRate);

	m_AnimeFrame += m_AnimeFrameRiseValue;
}

void Player::CreateStatusInfo(Scene* scene)
{
	StatusInfo info;
	info.m_AttackCoolTime = 50.0f;
	info.m_AttackPower = 100;
	info.m_DifenceValue = 10;
	info.m_ExpValue = 0;
	info.m_HitPointCoolTime = 30.0f;
	info.m_HitPointDimention = 2;
	info.m_HitPointPos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 64, 0);
	info.m_HitPointSize = D3DXVECTOR3(100.0f, 100.0f, 0.0f);
	info.m_HitPointValue = 1234;
	info.m_LevelValue = 1;
	m_Status = new Status(scene, &info);
}
