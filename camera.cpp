#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"
#include "scene.h"
#include "input.h"
#include "transform.h"
#include "player.h"
#include "skydome.h"
#include "movement.h"

Camera::Camera(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene, ObjectType::eObCamera,drawPriority)
{
	SetPosition(pos);
	m_Transform.SetPosition(pos);
	D3DXVECTOR3 position = m_Transform.GetPosition();
	m_Target = { 0.0f,0.0f,0.0f };
	m_Angle = -90;
	m_Angle3D = { -90,60 };
	scene->Add(this);
}

void Camera::Init()
{
}

void Camera::Uninit()
{
}

void Camera::Update()
{
	if (Keyboard_IsPress(DIK_UP))
	{
		m_Angle3D.y -= 1.0f;
		if (m_Angle3D.y <= 0) m_Angle3D.y = 0;
	}
	if (Keyboard_IsPress(DIK_DOWN))
	{
		m_Angle3D.y += 1.0f;
		if (m_Angle3D.y >= 180) m_Angle3D.y = 180;
	}
	if (Keyboard_IsPress(DIK_RIGHT))
	{
		m_Angle3D.x -= 1.0f;
		if (m_Angle3D.x < -90) m_Angle3D.x = 270;
	}
	if (Keyboard_IsPress(DIK_LEFT))
	{
		m_Angle3D.x += 1.0f;
		if (m_Angle3D.x > 270) m_Angle3D.x = -90;
	}

	D3DXVECTOR2 mouseMove;
	mouseMove.x = Mouse_GetMoveX();
	mouseMove.y = Mouse_GetMoveY();


	if (mouseMove.x != 0)
	{
		m_Angle3D.x -= mouseMove.x * 0.05f;
		if (m_Angle3D.x < -90) m_Angle3D.x = 270;
		if (m_Angle3D.x > 270) m_Angle3D.x = -90;
	}
	if (mouseMove.y != 0)
	{
		m_Angle3D.y -= mouseMove.y * 0.05f;
		if (m_Angle3D.y <= 0) m_Angle3D.y = 0;
		if (m_Angle3D.y >= 180) m_Angle3D.y = 180;
	}

	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	m_Target = player->GetPosition();

	D3DXVECTOR3 movepos = Movement::GetInstance()->CirclualMotion3D(m_Target, m_Distance, m_Angle3D);
	m_Position = movepos;

	Skydome* skydome = GetScene()->GetGameObject<Skydome>(ObjectType::eObSkydome);
	skydome->SetPosition(m_Position);
}

void Camera::Draw()
{
	// ビューマトリクス設定
	D3DXMatrixIdentity(&m_ViewMatrix);
	D3DXMatrixLookAtLH(&m_ViewMatrix, &GetPosition(), &m_Target,&m_Up);
	Renderer::GetInstance()->SetViewMatrix(&m_ViewMatrix);

	// プロジェクションマトリクス設定
	D3DXMatrixIdentity(&m_ProjectionMatrix);
	D3DXMatrixPerspectiveFovLH(&m_ProjectionMatrix, degToRad(45),
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);  // 最後のは表示範囲の設定
	Renderer::GetInstance()->SetProjectionMatrix(&m_ProjectionMatrix);
}

void Camera::SetCamera()
{
	SetPosition(m_Transform.GetPosition());
	SetCameraRotation(m_Transform.GetQuaternion());
}

void Camera::SetCameraRotation(const Quaternion & qua)
{
	m_Up = qua * Vec3::Up;
	m_Forward = qua * Vec3::Forward;
	m_Right = qua * Vec3::Right;
}

D3DXVECTOR3 Camera::GetForwardVec() const
{
	D3DXVECTOR3 vector;
	D3DXVec3Normalize(&vector, &(m_Target - m_Position));
	return vector;
}

D3DXVECTOR3 Camera::GetRightVec() const
{
	D3DXVECTOR3 right;
	right.x = -GetForwardVec().z;
	right.y =  GetForwardVec().y;
	right.z =  GetForwardVec().x;

	return right;
}
