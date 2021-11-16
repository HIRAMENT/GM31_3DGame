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
	//  �����ɂ���đ����𒲐�����
	D3DXVECTOR3 nearvec = m_NearMate->GetPosition() - m_Position;
	float near_distance = D3DXVec3Length(&nearvec);
	float ratio = near_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// �����Ƃ��߂����Ԃ̕��������߂�
	D3DXVECTOR3 change = nearvec;
	change /= near_distance;

	if (near_distance < SEPARATION_DIST) {	// �߂������牓����
		change *= -ratio;
	}
	else if (near_distance > SEPARATION_DIST) {	// ����������߂���
		change *= ratio;
	}
	else {	// ���������Ȃ瓮�����Ȃ�
		change = { 0.0f,0.0f,0.0f };
	}

	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::MatchHeading(void)
{
	// ��ԋ߂����Ԃ̑����̌����𒲂ׂ�
	D3DXVECTOR3 change = m_NearMate->GetVelocity();
	float near_distance = D3DXVec3Length(&change);

	// �i�X���x�����킹��悤�ɒ�������
	change *= MIN_URGENCY;
	
	return D3DXVECTOR3(change);
}

D3DXVECTOR3 Boids::SteerToCenter(void)
{
	D3DXVECTOR3 change;

	// �����钇�Ԃ̒��S�ʒu�����߂�
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

	// ���S�̌����ɒi�X�߂Â�
	change = center - m_Position;
	float near_distance = D3DXVec3Length(&change);
	change = change / near_distance;
	change *= MIN_URGENCY;
	
	return D3DXVECTOR3(change);
}

float Boids::CanISee(Boids * ptr)
{
	if (this == ptr) return(INFINITY);

	// �����̌v�Z
	D3DXVECTOR3 d = m_Position - ptr->GetPosition();
	float dist = D3DXVec3Length(&d);
	
	// ������ɂ����炻�̋�����Ԃ�
	if (m_Perception > dist) return (dist);

	return (INFINITY);
}

int Boids::SeeFriend(void)
{
	// �������X�g�̏�����
	ClearVisibleList();

	for (Boids* bd : BoidsData::GetInstance()->visibleList)
	{
		float dist;

		// ������
		if (dist = CanISee(bd) != INFINITY)
		{
			// ��������������X�g�ɒǉ�
			BoidsData::GetInstance()->visibleList.push_back(bd);

			m_SeenNum++;

			// ��ԋ߂��̂��̔���
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
	// ���ꂼ��̏�����
	for (Boids* bd : BoidsData::GetInstance()->visibleList) {
		delete bd;
	}
	BoidsData::GetInstance()->visibleList.clear();

	m_NearMate = nullptr;
	m_NearDistance = INFINITY;
}

D3DXVECTOR3 Boids::Cruising(void)
{
	// ���q���x(DESIRED_SPEED)�ɋ߂Â���
	float diff = (m_Speed - DESIRED_SPEED) / MAX_SPEED;
	float urgency = (float)fabs(diff);
	if (urgency < MIN_URGENCY) urgency = MIN_URGENCY;
	if (urgency > MAX_URGENCY) urgency = MAX_URGENCY;

	// �����_�������������
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

	// ���x�ω���͂ɒǉ�����
	D3DXVECTOR3 change2 = m_Velocity;
	D3DXVec3Normalize(&change2, &change2);
	change2 *= (urgency * std::signbit(-diff));

	return D3DXVECTOR3(change2);
}

void Boids::ComputeRPY(void)
{
	float roll, pitch, yaw;

	// �󂯂��͂̌v�Z
	D3DXVECTOR3 d = m_Velocity - m_OldVelocity;
	D3DXVECTOR3 lateralDir;
	D3DXVec3Cross(&lateralDir, &m_Velocity, &d);
	D3DXVec3Cross(&lateralDir, &lateralDir, &m_Velocity);	// �󂯂��͂̑��x�ɒ������鐬��
	D3DXVec3Normalize(&lateralDir, &lateralDir);

	// �g���N�v�Z
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

	//�o��
	m_Angle.x = pitch;
	m_Angle.y = yaw;
	m_Angle.z = roll;
}

void Boids::FlockIt(void)
{
	// �O�̏�Ԃ̕ۑ�
	m_OldPosition = m_Position;
	m_Position += m_Velocity;
	
	// ���Ԃ�T��
	this->SeeFriend();

	D3DXVECTOR3 acc = { 0.0f,0.0f, 0.0f };

	// �Q��̓���
	if (m_SeenNum) {
		acc += KeepDistance();

		acc += MatchHeading();

		acc += SteerToCenter();
	}

	// ����
	acc += Cruising();

	// �����̐���
	if (D3DXVec3Length(&acc) > MAX_CHANGE) {
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

	// ���x�ω�
	m_OldVelocity = m_Velocity;
	m_Velocity += acc;

	// ���������瑬�x������������
	if (m_Speed = D3DXVec3Length(&m_Velocity) > MAX_SPEED) {
		D3DXVec3Normalize(&m_Velocity, &m_Velocity);
		m_Velocity *= MAX_SPEED;
		m_Speed = MAX_SPEED;
	}

	// ��]�̌v�Z
	this->ComputeRPY();
	// ���E�̋��E�̏���

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
