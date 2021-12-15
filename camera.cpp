#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "resource.h"
#include "obb.h"
#include "status.h"
#include "camera.h"
#include "scene.h"
#include "input.h"
#include "transform.h"
#include "player.h"
#include "enemy.h"
#include "skydome.h"
#include "movement.h"
#include <algorithm>

Camera::Camera(Scene * scene, D3DXVECTOR3 pos, int drawPriority)
	:GameObject(scene, ObjectType::eObCamera,drawPriority)
{
	SetPosition(pos);
	m_Transform.SetPosition(pos);
	D3DXVECTOR3 position = m_Transform.GetPosition();
	m_Target = { 0.0f,0.0f,0.0f };
	m_TargetEnemy = { 0.0f,0.0f,0.0f };
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

	Player* player = GetScene()->GetGameObject<Player>(ObjectType::eObPlayer);
	D3DXVECTOR3 cpv = player->GetPosition() - m_Position;
	D3DXVec3Normalize(&cpv, &cpv);
	m_Target = player->GetPosition() + D3DXVECTOR3(cpv.x, 0.0f, cpv.z) * 5.0f;

	// Fキー(仮)を押したら一番近い敵をターゲットする
	// (ターゲット中は)

	if (Keyboard_IsPress(DIK_F)) {
		std::vector<Enemy*> enemys = GetScene()->GetGameObjects<Enemy>(ObjectType::eObSmallEnemy);
		float dist, nearest = 1000.0f;
		Enemy* ene = nullptr;
		for (auto enemy : enemys) {
			dist = D3DXVec3Length(&(player->GetPosition() - enemy->GetPosition()));
			if (nearest > dist) {
				nearest = dist;
				ene = enemy;
			}
		}

		// プレイヤーとエネミーを通る直線を見る
		m_TargetEnemy = ene->GetPosition();
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

	D3DXVECTOR3 movepos = Movement::GetInstance()->CirclualMotion3D(m_Target, m_Distance, m_Angle3D);
	m_Position = movepos;

	Skydome* skydome = GetScene()->GetGameObject<Skydome>(ObjectType::eObSkydome);
	skydome->SetPosition(m_Position);
}

void Camera::Draw()
{
	// ビューマトリクス設定
	D3DXMatrixIdentity(&m_ViewMatrix);
	D3DXMatrixLookAtLH(&m_ViewMatrix, &m_Position, &m_Target,&m_Up);
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

bool Camera::CheckView(D3DXVECTOR3 position, D3DXVECTOR3 right, D3DXVECTOR3 size)
{
	D3DXMATRIX vp, invvp;

	vp = m_ViewMatrix * m_ProjectionMatrix;
	D3DXMatrixInverse(&invvp, NULL, &vp);

	D3DXVECTOR3 vpos[4];
	D3DXVECTOR3 wpos[4];

	// カメラから見たときの視錐台の見た奥の端っこの座標
	vpos[0] = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);	// 左上
	vpos[1] = D3DXVECTOR3(1.0f, 1.0f, 1.0f);	// 右上
	vpos[2] = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);	// 左下
	vpos[3] = D3DXVECTOR3(1.0f, -1.0f, 1.0f);	// 右下

	// マトリックスを元に座標を移動
	D3DXVec3TransformCoord(&wpos[0], &vpos[0], &invvp);
	D3DXVec3TransformCoord(&wpos[1], &vpos[1], &invvp);
	D3DXVec3TransformCoord(&wpos[2], &vpos[2], &invvp);
	D3DXVec3TransformCoord(&wpos[3], &vpos[3], &invvp);

	D3DXVECTOR3 v, v1, v2, n, nv;
	float mostsize = std::max(size.x, size.y);
	mostsize = std::max(mostsize, size.z);
	D3DXVECTOR3 ts = { size.x / 2, size.y / 2, size.z / 2 };
	float dot = 0.0f;

	// 左の壁
	// カメラから対象のベクトル
	v1 = wpos[0] - m_Position;
	v2 = wpos[2] - m_Position;
	D3DXVec3Cross(&n, &v1, &v2);
	D3DXVec3Normalize(&nv, &n);
	v = D3DXVECTOR3(position.x, position.y, position.z) + (nv * mostsize) - m_Position;

	if (dot = D3DXVec3Dot(&n, &v) < 0.0f)
		return false;

	// 右の壁
	v1 = wpos[1] - m_Position;
	v2 = wpos[3] - m_Position;
	D3DXVec3Cross(&n, &v1, &v2);
	D3DXVec3Normalize(&nv, &n);
	v = D3DXVECTOR3(position.x, position.y, position.z) - (nv * mostsize) - m_Position;

	if (D3DXVec3Dot(&n, &v) > 0.0f)
		return false;

	// 上の壁
	v = D3DXVECTOR3(position.x, position.y - ts.y, position.z) - m_Position;
	v1 = wpos[0] - m_Position;
	v2 = wpos[1] - m_Position;
	D3DXVec3Cross(&n, &v1, &v2);

	if (D3DXVec3Dot(&n, &v) > 0.0f)
		return false;

	// 下の壁
	v = D3DXVECTOR3(position.x, position.y + ts.y, position.z) - m_Position;
	v1 = wpos[2] - m_Position;
	v2 = wpos[3] - m_Position;
	D3DXVec3Cross(&n, &v1, &v2);

	if (D3DXVec3Dot(&n, &v) < 0.0f)
		return false;

	// 奥の壁
	//v = D3DXVECTOR3(position.x, position.y, position.z + ts.z) - m_Position;
	//v1 = wpos[0] - wpos[2];
	//v2 = wpos[1] - wpos[3];
	//D3DXVec3Cross(&n, &v1, &v2);

	//if (D3DXVec3Dot(&n, &v) > 0.0f)
	//	return false;

	return true;
}
