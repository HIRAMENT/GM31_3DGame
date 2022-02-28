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
#include "enemy.h"
#include "tree.h"
#include "obstancle.h"

#include <algorithm>
#include <math.h>

#define SEPARATION_DIST_ENEMY   (4.0f)
#define SEPARATION_DIST_PLAYER  (3.0f)
#define SEPARATION_DIST_OBJECT  (3.0f)
#define MIN_URGENCY (0.01f)
#define MAX_URGENCY (0.05f)
#define MAX_CHANGE (10.0f)
#define MAX_SPEED (0.01f)
#define DESIRED_SPEED (1.0f)
#define GRAVITY (0.98f)
#define PERCEPTION_RANGE (5.0f)

Boids::Boids()
{
	m_Position = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_NearDistance = INFINITY;
	m_NearMate = nullptr;
	m_Perception = PERCEPTION_RANGE;
	m_SeenNum = 0;
	m_ViewRange = 10;
	m_ViewLenght = 10;
	m_OutLook = new ViewSensor(Manager::GetInstance()->GetScene(), m_Position, m_ViewRange, m_ViewLenght, 5);
	m_OutLook->SetDisplay(false);

	BoidsData::GetInstance()->Add(this);
}

D3DXVECTOR3 Boids::KeepDistance(void)
{
	//  距離によって速さを調整する
	if (m_NearMate == nullptr)
		return D3DXVECTOR3({ 0.0f,0.0f,0.0f });

	D3DXVECTOR3 change = SalculatingRatio(m_NearMate->GetPosition(), m_Position, SEPARATION_DIST_ENEMY, false);

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
			if (dist < m_NearDistance) 
			{
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
	m_SeenNum = 0;
}

void Boids::ComputeRPY(void)
{
	float angle = Movement::GetInstance()->GetTwoVecAngle({ 0,1 }, { m_Target.x - m_Position.x, m_Target.z - m_Position.z });
	if (m_Target.x - m_Position.x < 0.0f) angle *= -1;
	m_Angle.y = angle;
}

D3DXVECTOR3 Boids::FollowTarget(void)
{
	m_JustDistance = false;
	D3DXVECTOR3 change = SalculatingRatio(m_Target, m_Position, SEPARATION_DIST_PLAYER);
	if (change == D3DXVECTOR3(0.0f, 0.0f, 0.0f))
	{ 
		m_JustDistance = true;
	}
	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::Detour(OBB* obb)
{
	m_OutLook->SetInfo(m_Position, m_Target - m_Position, m_ViewRange, m_ViewLenght, false);

	// 障害物に当たったら
	std::vector<Obstancle*> obstancles = Manager::GetInstance()->GetScene()->GetGameObjects<Obstancle>(ObjectType::eObObstancle);
	OBB* nearobjobb = nullptr;
	GameObject* nearobj = nullptr;
	float dist = 1000.0;
	float length = 0.0f;
	D3DXVECTOR3 d = { 0.0f,0.0f,0.0f };
	for (Obstancle* obs : obstancles)
	{
		d = obs->GetPosition() - m_Position;
		length = D3DXVec3Length(&d);
		if (length < m_ViewLenght && dist > length)
		{
			dist = length;
			nearobj = obs;
			nearobjobb = obs->GetObb();
		}
	}

	if (nearobj && !Collision::GetInstance()->ObbToObb(nearobjobb, obb))
	{
		nearobj = nullptr;
	}

	if (nearobj == nullptr) 
	{
		return D3DXVECTOR3(0, 0, 0);
	}

	//角の座標が欲しいならライトのベクトルからフォワードのベクトル文を引くなりすれば出る
	// 右と左の二点を求めて近いほうを取る
	D3DXVECTOR3 direction[4] = {};
	D3DXVECTOR3 nearvec = {};
	D3DXVECTOR3 right   = nearobjobb->GetDirection(Direction::eRight) * nearobjobb->GetLength(Direction::eRight);
	D3DXVECTOR3 forward = nearobjobb->GetDirection(Direction::eForward) * nearobjobb->GetLength(Direction::eForward);
	direction[0] =  right * 1.5f + forward * 1.5f;
	direction[1] =  right * 1.5f - forward * 1.5f;
	direction[2] = -right * 1.5f + forward * 1.5f;
	direction[3] = -right * 1.5f - forward * 1.5f;
	for (int i = 1; i < 4; i++) 
	{
		nearvec = std::min((direction[i - 1] - m_Position), (direction[i] - m_Position));
	}
	D3DXVec3Normalize(&nearvec, &nearvec);

	D3DXVECTOR3 change = SalculatingRatio(nearvec, SEPARATION_DIST_OBJECT) + SalculatingRatio(nearobj->GetPosition() - m_Position, SEPARATION_DIST_OBJECT, false);

	return D3DXVECTOR3(change);
}

void Boids::FlockIt(Enemy* enemy)
{
	m_Position = enemy->GetPosition();
	m_Movement = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	// 仲間を探す
	this->SeeFriend();

	D3DXVECTOR3 acc = { 0.0f, 0.0f, 0.0f };

	// 障害物をよける
	D3DXVECTOR3 det = Detour(enemy->GetObb());
	acc += det;

	if (det == D3DXVECTOR3(0.0f, 0.0f, 0.0f))
	{
		// 群れの動作
		if (m_SeenNum) 
		{
			acc += KeepDistance();
		}
		// ターゲットに向かって動く
		if (acc != D3DXVECTOR3(0.0f, 0.0f, 0.0f))
		{
			acc += FollowTarget() * 0.85f;
		}
		else 
		{
			acc += FollowTarget();
		}
	}

	// y軸は動かない
	acc.y = 0.0f;

	// 加速の制限
	if (D3DXVec3Length(&acc) > MAX_CHANGE) 
	{
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

	m_Movement = acc;

	// 速度変化
	m_OldVelocity = m_Velocity;
	m_Velocity += acc;

	// 速すぎたら速度制限をかける
	if (m_Speed = D3DXVec3Length(&m_Velocity) > MAX_SPEED) 
	{
		D3DXVec3Normalize(&m_Velocity, &m_Velocity);
		m_Velocity *= MAX_SPEED;
		m_Speed = MAX_SPEED;
	}

	// 回転の計算
	this->ComputeRPY();

	// 位置の更新
	m_Position += m_Movement;

	BoidsData::GetInstance()->Organize();
}

D3DXVECTOR3 Boids::SalculatingRatio(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, float dist, bool approach)
{
	D3DXVECTOR3 vector = vec1 - vec2;

	D3DXVECTOR3 change = SalculatingRatio(vector, dist, approach);

	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::SalculatingRatio(D3DXVECTOR3 vec, float dist, bool approach)
{
	vec.y = 0.0f;
	float distance = D3DXVec3Length(&vec);
	float ratio = distance / dist;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	D3DXVECTOR3 change = vec;
	D3DXVec3Normalize(&change, &change);

	if (static_cast<int>(distance) < dist) 
	{	// 近かったら遠くへ
		change *= -ratio;
	}
	else if (approach && static_cast<int>(distance) > dist) 
	{
		change *= ratio;
	}
	else 
	{	// いい感じなら動かさない
		change = { 0.0f,0.0f,0.0f };
	}

	return D3DXVECTOR3(change);
}

void BoidsData::Add(Boids * boids)
{
	// 要素が無ければただ入れる
	if (boidsList.empty())
	{
		boidsList.push_back(boids);
	}
	else // 要素があれば重複してるか確認して入れる
	{
		auto it = std::find(boidsList.begin(), boidsList.end(), boids);
		auto end = boidsList.end();
		if (it == end)
		{
			boidsList.push_back(boids);
		}
	}
}

void BoidsData::Organize()
{
	boidsList.remove_if([](Boids* boids) {return boids == nullptr; });
}

void BoidsData::Erasure(Boids * boids)
{
	boidsList.remove(boids);
}
