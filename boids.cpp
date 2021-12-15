#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "rock.h"
#include "movement.h"
#include "obb.h"
#include "collision.h"
#include "viewSensor.h"
#include "obb.h"
#include "boids.h"

#include <algorithm>
#include <math.h>

#define SEPARATION_DIST  (3)
#define MIN_URGENCY (0.01f)
#define MAX_URGENCY (0.05f)
#define MAX_CHANGE (10.0f)
#define MAX_SPEED (0.01f)
#define DESIRED_SPEED (1.0f)
#define GRAVITY (0.98f)
#define PERCEPTION_RANGE (5.0f)

#define RAND() ((float)rand()/RAND_MAX)


Boids::Boids(D3DXVECTOR3 pos)
{
	BoidsData::GetInstance()->boidsList.push_back(this);
	m_Position = pos;

	m_NearDistance = INFINITY;
	m_NearMate = nullptr;
	m_Perception = PERCEPTION_RANGE;
	m_SeenNum = 0;
	m_ViewRange = 10;
	m_ViewLenght = 10;
	m_OutLook = new ViewSensor(Manager::GetInstance()->GetScene(), pos, m_ViewRange, m_ViewLenght, 5);
	m_OutLook->SetDisplay(false);
}

D3DXVECTOR3 Boids::KeepDistance(void)
{
	//  距離によって速さを調整する
	if (m_NearMate == nullptr)
		return D3DXVECTOR3({ 0.0f,0.0f,0.0f });

	D3DXVECTOR3 change = SalculatingRatio(m_NearMate->GetPosition(), m_Position, false);

	return D3DXVECTOR3(change);
}

float Boids::CanISee(Boids * ptr)
{
	if (this == ptr) return(INFINITY);

	// 距離の計算
	D3DXVECTOR3 d = m_Position - ptr->GetPosition();
	float dist = D3DXVec3Length(&d);
	
	// 視野内にいたらその距離を返す
	if (m_Perception > dist) 
		return (dist);

	return (INFINITY);
}

int Boids::SeeFriend(void)
{
	// 可視化リストの初期化
	ClearVisibleList();

	for (Boids* bd : BoidsData::GetInstance()->boidsList)
	{
		float dist = CanISee(bd);

		// 可視判定
		if (dist != INFINITY)
		{
			// 見えたら可視化リストに追加
			BoidsData::GetInstance()->visibleList.push_back(bd);

			m_SeenNum++;

			// 一番近いのかの判定
			if (dist < m_NearDistance) {
				m_NearMate = bd;
				m_NearDistance = dist;
			}
		}
	}

	return m_SeenNum;
}

void Boids::ClearVisibleList(void)
{
	// それぞれの初期化
	BoidsData::GetInstance()->visibleList.clear();
	
	m_NearMate = nullptr;
	m_NearDistance = INFINITY;
}

void Boids::ComputeRPY(void)
{
	float angle = Movement::GetInstance()->GetTwoVecAngle({ 0,1 }, { m_Target.x - m_Position.x, m_Target.z - m_Position.z });
	if (m_Target.x - m_Position.x < 0.0f) angle *= -1;
	m_Angle.y = angle;

	//float roll, pitch, yaw;

	//// 受けた力の計算
	//D3DXVECTOR3 d = m_Velocity - m_OldVelocity;
	//D3DXVECTOR3 lateralDir;
	//D3DXVec3Cross(&lateralDir, &m_Velocity, &d);
	//D3DXVec3Cross(&lateralDir, &lateralDir, &m_Velocity);	// 受けた力の速度に直交する成分
	//D3DXVec3Normalize(&lateralDir, &lateralDir);

	//// トルク計算
	//float lateralMag = D3DXVec3Dot(&d, &lateralDir);

	//// roll
	//if (lateralMag == 0) {
	//	roll = 0.0f;
	//}
	//else {
	//	roll = static_cast<float>(-atan2(GRAVITY, lateralMag) + 3.14159f / 2.0f);
	//}

	////pitch
	//pitch = static_cast<float>(-atan(m_Velocity.y / sqrt((m_Velocity.z * m_Velocity.z) + (m_Velocity.x * m_Velocity.x))));

	//// yaw
	//yaw = static_cast<float>(atan2(-m_Velocity.x, -m_Velocity.z));

	////出力
	//m_Angle.x = pitch;
	//m_Angle.y = yaw;
	//m_Angle.z = roll;
}

D3DXVECTOR3 Boids::FollowTarget(void)
{
	D3DXVECTOR3 change = SalculatingRatio(m_Target, m_Position);

	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::Detour(OBB* obb)
{
	m_OutLook->SetInfo(m_Position, m_Target - m_Position, m_ViewRange, m_ViewLenght, false);

	// 障害物に当たったら
	std::vector<Rock*> rocks = Manager::GetInstance()->GetScene()->GetGameObjects<Rock>(ObjectType::eObRock);
	Rock* nearobj = nullptr;
	float dist = 1000.0;
	float length = 0.0f;
	D3DXVECTOR3 d = { 0.0f,0.0f,0.0f };
	for (Rock* rock : rocks) {
		d = rock->GetPosition() - m_Position;
		length = D3DXVec3Length(&d);
		if (length < m_ViewLenght && dist > length) {
			dist = length;
			nearobj = rock;
		}
	}

	if (nearobj && !Collision::GetInstance()->ObbToObb(nearobj->GetObb(), obb)) {
		nearobj = nullptr;
	}

	if (nearobj == nullptr) {
		return D3DXVECTOR3(0, 0, 0);
	}

	//角の座標が欲しいならライトのベクトルからフォワードのベクトル文を引くなりすれば出る
	// 右と左の二点を求めて近いほうを取る
	D3DXVECTOR3 direction[4] = {};
	D3DXVECTOR3 nearvec = {};
	D3DXVECTOR3 right   = nearobj->GetObb()->GetDirection(Direction::eRight) * nearobj->GetObb()->GetLength(Direction::eRight);
	D3DXVECTOR3 forward = nearobj->GetObb()->GetDirection(Direction::eForward) * nearobj->GetObb()->GetLength(Direction::eForward);
	direction[0] =  right * 1.5f + forward * 1.5f;
	direction[1] =  right * 1.5f - forward * 1.5f;
	direction[2] = -right * 1.5f + forward * 1.5f;
	direction[3] = -right * 1.5f - forward * 1.5f;
	for (int i = 1; i < 4; i++) 
	{
		nearvec = std::min((direction[i - 1] - m_Position), (direction[i] - m_Position));
	}
	D3DXVec3Normalize(&nearvec, &nearvec);

	D3DXVECTOR3 change = SalculatingRatio(nearvec) + SalculatingRatio(nearobj->GetPosition() - m_Position, false);

	return D3DXVECTOR3(change);
}

void Boids::FlockIt(OBB* obb)
{
	// 前の状態の保存
	m_OldPosition = m_Position;
	m_Position += m_Movement;
	m_Movement = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	// 仲間を探す
	this->SeeFriend();

	D3DXVECTOR3 acc = { 0.0f, 0.0f, 0.0f };

	// 群れの動作
	if (m_SeenNum) {
		acc += KeepDistance();
	}

	// 障害物をよける
	D3DXVECTOR3 det = Detour(obb);
	acc += det;

	// ターゲットに向かって動く
	if (det == D3DXVECTOR3(0.0f, 0.0f, 0.0f)) {
		acc += FollowTarget();
	}

	// y軸は動かない
	acc.y = 0.0f;

	// 加速の制限
	if (D3DXVec3Length(&acc) > MAX_CHANGE) {
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

	m_Movement = acc;

	// 速度変化
	m_OldVelocity = m_Velocity;
	m_Velocity += acc;

	// 速すぎたら速度制限をかける
	if (m_Speed = D3DXVec3Length(&m_Velocity) > MAX_SPEED) {
		D3DXVec3Normalize(&m_Velocity, &m_Velocity);
		m_Velocity *= MAX_SPEED;
		m_Speed = MAX_SPEED;
	}

	// 回転の計算
	this->ComputeRPY();

}

D3DXVECTOR3 Boids::SalculatingRatio(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, bool approach)
{
	D3DXVECTOR3 vector = vec1 - vec2;

	D3DXVECTOR3 change = SalculatingRatio(vector, approach);

	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::SalculatingRatio(D3DXVECTOR3 vec, bool approach)
{
	vec.y = 0.0f;
	float distance = D3DXVec3Length(&vec);
	float ratio = distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	D3DXVECTOR3 change = vec;
	D3DXVec3Normalize(&change, &change);

	if (distance < SEPARATION_DIST) {	// 近かったら遠くへ
		change *= -ratio;
	}
	else if (approach && distance > SEPARATION_DIST) {
		change *= ratio;
	}
	else {	// いい感じなら動かさない
		change = { 0.0f,0.0f,0.0f };
	}

	return D3DXVECTOR3(change);
}
