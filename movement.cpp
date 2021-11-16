#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "shader.h"
#include "scene.h"
#include "camera.h"
#include "movement.h"

D3DXVECTOR2 Movement::CirclualMotion(D3DXVECTOR3 pos, float rad, int angle)
{
	D3DXVECTOR2 rotpos = { 0.0f,0.0f };
	rotpos.x = pos.x + rad * cos(degToRad(angle));
	rotpos.y = pos.z + rad * sin(degToRad(angle));

	return rotpos;
}

D3DXVECTOR3 Movement::CirclualMotion3D(D3DXVECTOR3 pos, float rad, D3DXVECTOR2 angle)
{
	D3DXVECTOR3 rotpos = { 0.0f,0.0f,0.0f };
	rotpos.x = pos.x + rad * std::cosf(degToRad(angle.x));
	rotpos.z = pos.z + rad * std::sinf(degToRad(angle.x));
	rotpos.y = pos.y + rad * std::cosf(degToRad(angle.y));
	//rotpos.z = pos.z + rad * sin(degToRad(angle.y));

	return rotpos;
}

D3DXVECTOR3 Movement::TargetFollow(D3DXVECTOR3 mpos, D3DXVECTOR3 tpos, float speed)
{
	D3DXVECTOR3 direction;
	D3DXVec3Normalize(&direction, &(tpos - mpos));
	return direction * speed;	// �L�����̕����Ɉړ�
}

float Movement::GetTwoVecAngle(D3DXVECTOR3 mvec, D3DXVECTOR3 tvec)
{
	//�x�N�g��A��B�̒������v�Z����
	float length_M = D3DXVec3Length(&mvec);
	float length_T = D3DXVec3Length(&tvec);

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = D3DXVec3Dot(&mvec,&tvec) / (length_M * length_T);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(cos_sita);

	//���W�A���łȂ�0�`180�̊p�x�łق����ꍇ�̓R�����g�O��
	//sita = sita * 180.0 / PI;

	return sita;
}

float Movement::GetTwoVecAngle(D3DXVECTOR2 mvec, D3DXVECTOR2 tvec)
{
	//�x�N�g��A��B�̒������v�Z����
	float length_M = D3DXVec2Length(&mvec);
	float length_T = D3DXVec2Length(&tvec);

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = D3DXVec2Dot(&mvec, &tvec) / (length_M * length_T);

	//cos�Ƃ���Ƃ����߂�
	float sita = acos(cos_sita);

	//���W�A���łȂ�0�`180�̊p�x�łق����ꍇ�̓R�����g�O��
	//sita = sita * 180.0 / PI;

	return sita;
}
