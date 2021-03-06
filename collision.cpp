#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "shader.h"
#include "scene.h"
#include "camera.h"
#include "collision.h"
#include "obb.h"

bool Collision::ObbToObb(OBB * Obb1, OBB * Obb2)
{
	// eûüxNgÌmÛ
	// W»ûüxNg
	D3DXVECTOR3 NAe1 = Obb1->GetDirection(0), Ae1 = NAe1 * Obb1->GetLength(0);
	D3DXVECTOR3 NAe2 = Obb1->GetDirection(1), Ae2 = NAe2 * Obb1->GetLength(1);
	D3DXVECTOR3 NAe3 = Obb1->GetDirection(2), Ae3 = NAe3 * Obb1->GetLength(2);
	D3DXVECTOR3 NBe1 = Obb2->GetDirection(0), Be1 = NBe1 * Obb2->GetLength(0);
	D3DXVECTOR3 NBe2 = Obb2->GetDirection(1), Be2 = NBe2 * Obb2->GetLength(1);
	D3DXVECTOR3 NBe3 = Obb2->GetDirection(2), Be3 = NBe3 * Obb2->GetLength(2);
	D3DXVECTOR3 Interval = Obb1->GetPosition() - Obb2->GetPosition();

	// ª²FAe1
	float rA = D3DXVec3Length(&Ae1);
	float rB = LenSegOnSeparateAxis(&NAe1, &Be1, &Be2, &Be3);
	float le = fabs(D3DXVec3Dot(&Interval, &NAe1));

	// ª£² : Ae2
	rA = D3DXVec3Length(&Ae2);
	rB = LenSegOnSeparateAxis(&NAe2, &Be1, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NAe2));
	if (le > rA + rB)
		return false;

	// ª£² : Ae3
	rA = D3DXVec3Length(&Ae3);
	rB = LenSegOnSeparateAxis(&NAe3, &Be1, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NAe3));
	if (le > rA + rB)
		return false;

	// ª£² : Be1
	rA = LenSegOnSeparateAxis(&NBe1, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be1);
	le = fabs(D3DXVec3Dot(&Interval, &NBe1));
	if (le > rA + rB)
		return false;

	// ª£² : Be2
	rA = LenSegOnSeparateAxis(&NBe2, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be2);
	le = fabs(D3DXVec3Dot(&Interval, &NBe2));
	if (le > rA + rB)
		return false;

	// ª£² : Be3
	rA = LenSegOnSeparateAxis(&NBe3, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NBe3));
	if (le > rA + rB)
		return false;

	// ª£² : C11
	D3DXVECTOR3 Cross;
	D3DXVec3Cross(&Cross, &NAe1, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C12
	D3DXVec3Cross(&Cross, &NAe1, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C13
	D3DXVec3Cross(&Cross, &NAe1, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C21
	D3DXVec3Cross(&Cross, &NAe2, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C22
	D3DXVec3Cross(&Cross, &NAe2, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C23
	D3DXVec3Cross(&Cross, &NAe2, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C31
	D3DXVec3Cross(&Cross, &NAe3, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C32
	D3DXVec3Cross(&Cross, &NAe3, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£² : C33
	D3DXVec3Cross(&Cross, &NAe3, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// ª£½Êª¶ÝµÈ¢ÌÅuÕËµÄ¢év
	return true;
}

float Collision::LenSegOnSeparateAxis(D3DXVECTOR3 * sep, D3DXVECTOR3 * e1, D3DXVECTOR3 * e2, D3DXVECTOR3* e3)
{
	// 3ÂÌàÏÌâÎlÌafeüª·ðZo
	// ª²sepÍW»³êÄ¢é±Æ
	float r1 = fabs(D3DXVec3Dot(sep, e1));
	float r2 = fabs(D3DXVec3Dot(sep, e2));
	float r3 = e3 ? fabs(D3DXVec3Dot(sep, e3)) : 0;
	return r1 + r2 + r3;
}

bool Collision::ObbToPoint(OBB* obb, D3DXVECTOR3 pos2, D3DXVECTOR3 size2)
{
	//D3DXVECTOR3 vector(0.0f, 0.0f, 0.0f);

	//for(int i = 0; i < 3; i++)
	//{
	//	float length = D3DXVec2Length(&pos1)
	//
	//}

	return false;
}