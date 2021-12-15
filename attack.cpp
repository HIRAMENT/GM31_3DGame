#include "main.h"
#include "manager.h"
#include "movement.h"
#include "attack.h"

void Attack::Update()
{
	if (m_CoolTime <= 0)
		m_CoolTime = 0;
	else
		m_CoolTime--;
}

bool Attack::CheckCoolTime()
{
	if (m_CoolTime <= 0)
		return true;

	return false;
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
