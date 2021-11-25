#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "movement.h"
#include "obb.h"
#include "collision.h"
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
	m_IsKeep = false;
	m_IsChase = false;
}

D3DXVECTOR3 Boids::KeepDistance(void)
{
	m_IsKeep = false;

	//  距離によって速さを調整する
	if (m_NearMate == nullptr)
		return D3DXVECTOR3({ 0.0f,0.0f,0.0f });

	D3DXVECTOR3 nearvec = m_NearMate->GetPosition() - m_Position;
	float near_distance = D3DXVec3Length(&nearvec);
	float ratio = near_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// もっとも近い仲間の方向を求める
	D3DXVECTOR3 change = nearvec;
	D3DXVec3Normalize(&change, &change);

	if (near_distance < SEPARATION_DIST) {	// 近かったら遠くへ
		change *= -ratio;
	}
	//else if (near_distance > SEPARATION_DIST) {
	//	change *= ratio;
	//}
	else {	// いい感じなら動かさない
		change = { 0.0f,0.0f,0.0f };
		m_IsKeep = true;
	}

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
	float roll, pitch, yaw;

	// 受けた力の計算
	D3DXVECTOR3 d = m_Velocity - m_OldVelocity;
	D3DXVECTOR3 lateralDir;
	D3DXVec3Cross(&lateralDir, &m_Velocity, &d);
	D3DXVec3Cross(&lateralDir, &lateralDir, &m_Velocity);	// 受けた力の速度に直交する成分
	D3DXVec3Normalize(&lateralDir, &lateralDir);

	// トルク計算
	float lateralMag = D3DXVec3Dot(&d, &lateralDir);

	// roll
	if (lateralMag == 0) {
		roll = 0.0f;
	}
	else {
		roll = static_cast<float>(-atan2(GRAVITY, lateralMag) + 3.14159f / 2.0f);
	}

	//pitch
	pitch = static_cast<float>(-atan(m_Velocity.y / sqrt((m_Velocity.z * m_Velocity.z) + (m_Velocity.x * m_Velocity.x))));

	// yaw
	yaw = static_cast<float>(atan2(-m_Velocity.x, -m_Velocity.z));

	//出力
	m_Angle.x = pitch;
	m_Angle.y = yaw;
	m_Angle.z = roll;
}

D3DXVECTOR3 Boids::FollowTarget(void)
{
	m_IsChase = false;

	D3DXVECTOR3 targetvec = m_Target - m_Position;
	targetvec.y = 0.0f;
	float target_distance = D3DXVec3Length(&targetvec);
	float ratio = target_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// もっとも近い仲間の方向を求める
	D3DXVECTOR3 change = targetvec;
	D3DXVec3Normalize(&change, &change);

	if (target_distance < SEPARATION_DIST) {	// 近かったら遠くへ
		change *= -ratio;
	}
	else if (target_distance > SEPARATION_DIST) {
		change *= ratio;
	}
	else {	// いい感じなら動かさない
		change = { 0.0f,0.0f,0.0f };
		m_IsChase = true;
	}

	return D3DXVECTOR3(change);
}

void Boids::FlockIt(void)
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

	// ターゲットに向かって動く
	acc += FollowTarget();

	// y軸は動かない
	acc.y = 0.0f;

	// 加速の制限
	if (D3DXVec3Length(&acc) > MAX_CHANGE) {
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

	//if (m_IsChase && m_IsKeep) {
	//	acc = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//}

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
	//this->ComputeRPY();

}