#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "boids.h"
#include <algorithm>
#include <math.h>

#define SEPARATION_DIST  (10)
#define MIN_URGENCY (0.1f)
#define MAX_URGENCY (1.0f)
#define MAX_CHANGE (10.0f)
#define MAX_SPEED (10.0f)
#define DESIRED_SPEED (1.0f)
#define GRAVITY (0.98f)
#define PERCEPTION_RANGE (0.15f)


Boids::Boids(D3DXVECTOR3 pos)
{
	BoidsData::GetInstance()->boidsList.push_back(this);
	m_Position = pos;

	m_NearDistance = INFINITY;
	m_NearMate = nullptr;
	m_Perception = PERCEPTION_RANGE;
	m_SeenNum = 0;
}

D3DXVECTOR3 Boids::KeepDistance(void)
{
	//  距離によって速さを調整する
	D3DXVECTOR3 nearvec = m_NearMate->GetPosition() - m_Position;
	float near_distance = D3DXVec3Length(&nearvec);
	float ratio = near_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// もっとも近い仲間の方向を求める
	D3DXVECTOR3 change = nearvec;
	change /= near_distance;

	if (near_distance < SEPARATION_DIST) {	// 近かったら遠くへ
		change *= -ratio;
	}
	else if (near_distance > SEPARATION_DIST) {	// 遠かったら近くへ
		change *= ratio;
	}
	else {	// いい感じなら動かさない
		change = { 0.0f,0.0f,0.0f };
	}

	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::MatchHeading(void)
{
	// 一番近い仲間の速さの向きを調べる
	D3DXVECTOR3 change = m_NearMate->GetVelocity();
	float near_distance = D3DXVec3Length(&change);

	// 段々速度を合わせるように調整する
	change *= MIN_URGENCY;
	
	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::SteerToCenter(void)
{
	D3DXVECTOR3 change;

	// 見える仲間の中心位置を求める
	D3DXVECTOR3 center = { 0.0f, 0.0f, 0.0f };
	int matenum = 0;
	for (Boids* bd : BoidsData::GetInstance()->boidsList)
	{
		if (bd != this)
		{
			center += bd->GetPosition();
			matenum++;
		}
	}

	center /= matenum;

	// 中心の向きに段々近づく
	change = center - m_Position;
	float near_distance = D3DXVec3Length(&change);
	change = change / near_distance;
	change *= MIN_URGENCY;
	
	return D3DXVECTOR3(change);
}

float Boids::CanISee(Boids * ptr)
{
	if (this == ptr) return(INFINITY);

	// 距離の計算
	D3DXVECTOR3 d = m_Position - ptr->GetPosition();
	float dist = D3DXVec3Length(&d);
	
	// 視野内にいたらその距離を返す
	if (m_Perception > dist) return (dist);

	return (INFINITY);
}

int Boids::SeeFriend(void)
{
	// 可視化リストの初期化
	ClearVisibleList();

	for (Boids* bd : BoidsData::GetInstance()->visibleList)
	{
		float dist;

		// 可視判定
		if (dist = CanISee(bd) != INFINITY)
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
	for (Boids* bd : BoidsData::GetInstance()->visibleList) {
		delete bd;
	}
	BoidsData::GetInstance()->visibleList.clear();

	m_NearMate = nullptr;
	m_NearDistance = INFINITY;
}

D3DXVECTOR3 Boids::Cruising(void)
{
	// 巡航速度(DESIRED_SPEED)に近づける
	float diff = (m_Speed - DESIRED_SPEED) / MAX_SPEED;
	float urgency = (float)fabs(diff);
	if (urgency < MIN_URGENCY) urgency = MIN_URGENCY;
	if (urgency > MAX_URGENCY) urgency = MAX_URGENCY;

	// ランダム性を取り入れる
	D3DXVECTOR3 change;
		float jitter = rand();
	if (jitter < 0.45f) {
		change.x += MIN_URGENCY * std::signbit(diff);
	}
	else if (jitter < 0.90f) {
		change.z += MIN_URGENCY * std::signbit(diff);
	}
	else{
		change.y += MIN_URGENCY * std::signbit(diff);
	}

	// 速度変化を力に追加する
	D3DXVECTOR3 change2 = m_Velocity;
	D3DXVec3Normalize(&change2, &change2);
	change2 *= (urgency * std::signbit(-diff));

	return D3DXVECTOR3(change2);
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

void Boids::FlockIt(void)
{
	// 前の状態の保存
	m_OldPosition = m_Position;
	m_Position += m_Velocity;
	
	// 仲間を探す
	this->SeeFriend();

	D3DXVECTOR3 acc = { 0.0f,0.0f, 0.0f };

	// 群れの動作
	if (m_SeenNum) {
		acc += KeepDistance();

		acc += MatchHeading();

		acc += SteerToCenter();
	}

	// 巡回
	acc += Cruising();

	// 加速の制限
	if (D3DXVec3Length(&acc) > MAX_CHANGE) {
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

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
	// 世界の境界の処理

}

//D3DXVECTOR3 operator+=(const D3DXVECTOR3 & pos, const D3DXVECTOR3 pos1)
//{
//	return D3DXVECTOR3({ pos.x + pos1.x, pos.y + pos1.y });
//}

//float GetLength(const D3DXVECTOR3 & vec)
//{
//	return std::sqrtf(vec.x * vec.x + vec.y * vec.y);
//}

//D3DXVECTOR3 GetNormalize(const D3DXVECTOR3 & vec)
//{
//	float dist = std::sqrtf(vec.x * vec.x + vec.y * vec.y);
//	return D3DXVECTOR3({ vec.x / dist, vec.y / dist });
//}
