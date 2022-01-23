#include "main.h"
#include "manager.h"
#include "movement.h"
#include "attack.h"

Attack::Attack(int pow, float time)
	: m_Power(pow)
	, m_CoolTime(time)
{
	m_CoolTime -= time;
}

void Attack::Update()
{
	m_CoolTime -= 0.1f;
}

bool Attack::CheckCoolTime()
{
	return m_CoolTime.GetIsFinish();
}

bool Attack::CheckHit(D3DXVECTOR3 vec, D3DXVECTOR3 forward, float ang, float len)
{
	float angle = 0.0f;
	float length = 0.0f;
	D3DXVECTOR2 vpe;
	vpe = { vec.x, vec.z};
	angle = Movement::GetInstance()->GetTwoVecAngle({ -forward.x, -forward.z }, { vpe.x, vpe.y });
	angle = fabs(angle * 180 / 3.14159);
	length = D3DXVec2Length(&vpe);
	if (angle < ang && length < len) {
		return true;
	}

	return false;
}
