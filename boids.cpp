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

	//  �����ɂ���đ����𒲐�����
	if (m_NearMate == nullptr)
		return D3DXVECTOR3({ 0.0f,0.0f,0.0f });

	D3DXVECTOR3 nearvec = m_NearMate->GetPosition() - m_Position;
	float near_distance = D3DXVec3Length(&nearvec);
	float ratio = near_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// �����Ƃ��߂����Ԃ̕��������߂�
	D3DXVECTOR3 change = nearvec;
	D3DXVec3Normalize(&change, &change);

	if (near_distance < SEPARATION_DIST) {	// �߂������牓����
		change *= -ratio;
	}
	//else if (near_distance > SEPARATION_DIST) {
	//	change *= ratio;
	//}
	else {	// ���������Ȃ瓮�����Ȃ�
		change = { 0.0f,0.0f,0.0f };
		m_IsKeep = true;
	}

	return D3DXVECTOR3(change);
}

float Boids::CanISee(Boids * ptr)
{
	if (this == ptr) return(INFINITY);

	// �����̌v�Z
	D3DXVECTOR3 d = m_Position - ptr->GetPosition();
	float dist = D3DXVec3Length(&d);
	
	// ������ɂ����炻�̋�����Ԃ�
	if (m_Perception > dist) 
		return (dist);

	return (INFINITY);
}

int Boids::SeeFriend(void)
{
	// �������X�g�̏�����
	ClearVisibleList();

	for (Boids* bd : BoidsData::GetInstance()->boidsList)
	{
		float dist = CanISee(bd);

		// ������
		if (dist != INFINITY)
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
	BoidsData::GetInstance()->visibleList.clear();
	
	m_NearMate = nullptr;
	m_NearDistance = INFINITY;
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

D3DXVECTOR3 Boids::FollowTarget(void)
{
	m_IsChase = false;

	D3DXVECTOR3 targetvec = m_Target - m_Position;
	targetvec.y = 0.0f;
	float target_distance = D3DXVec3Length(&targetvec);
	float ratio = target_distance / SEPARATION_DIST;
	if (ratio < MIN_URGENCY) ratio = MIN_URGENCY;
	if (ratio > MAX_URGENCY) ratio = MAX_URGENCY;

	// �����Ƃ��߂����Ԃ̕��������߂�
	D3DXVECTOR3 change = targetvec;
	D3DXVec3Normalize(&change, &change);

	if (target_distance < SEPARATION_DIST) {	// �߂������牓����
		change *= -ratio;
	}
	else if (target_distance > SEPARATION_DIST) {
		change *= ratio;
	}
	else {	// ���������Ȃ瓮�����Ȃ�
		change = { 0.0f,0.0f,0.0f };
		m_IsChase = true;
	}

	return D3DXVECTOR3(change);
}

void Boids::FlockIt(void)
{
	// �O�̏�Ԃ̕ۑ�
	m_OldPosition = m_Position;
	m_Position += m_Movement;
	m_Movement = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
	// ���Ԃ�T��
	this->SeeFriend();

	D3DXVECTOR3 acc = { 0.0f, 0.0f, 0.0f };

	// �Q��̓���
	if (m_SeenNum) {
		acc += KeepDistance();
	}

	// �^�[�Q�b�g�Ɍ������ē���
	acc += FollowTarget();

	// y���͓����Ȃ�
	acc.y = 0.0f;

	// �����̐���
	if (D3DXVec3Length(&acc) > MAX_CHANGE) {
		D3DXVec3Normalize(&acc, &acc);
		acc *= MAX_CHANGE;
	}

	//if (m_IsChase && m_IsKeep) {
	//	acc = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//}

	m_Movement = acc;

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
	//this->ComputeRPY();

}