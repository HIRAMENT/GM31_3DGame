#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "resource.h"
#include "shader.h"
#include "scene.h"
#include "camera.h"
#include "collision.h"
#include "obb.h"
#include "box.h"

bool Collision::ObbToObb(OBB * Obb1, OBB * Obb2)
{
	// デバッグボックスのテクスチャの初期化
	Obb1->GetBox()->SetTexture(ResourceTag::tDebugLine);
	Obb2->GetBox()->SetTexture(ResourceTag::tDebugLine);

	// 各方向ベクトルの確保
	// 標準化方向ベクトル
	D3DXVECTOR3 NAe1 = Obb1->GetDirection(0), Ae1 = NAe1 * Obb1->GetLength(0);
	D3DXVECTOR3 NAe2 = Obb1->GetDirection(1), Ae2 = NAe2 * Obb1->GetLength(1);
	D3DXVECTOR3 NAe3 = Obb1->GetDirection(2), Ae3 = NAe3 * Obb1->GetLength(2);
	D3DXVECTOR3 NBe1 = Obb2->GetDirection(0), Be1 = NBe1 * Obb2->GetLength(0);
	D3DXVECTOR3 NBe2 = Obb2->GetDirection(1), Be2 = NBe2 * Obb2->GetLength(1);
	D3DXVECTOR3 NBe3 = Obb2->GetDirection(2), Be3 = NBe3 * Obb2->GetLength(2);
	D3DXVECTOR3 Interval = Obb1->GetPosition() - Obb2->GetPosition();

	// 分割軸：Ae1
	float rA = D3DXVec3Length(&Ae1);
	float rB = LenSegOnSeparateAxis(&NAe1, &Be1, &Be2, &Be3);
	float le = fabs(D3DXVec3Dot(&Interval, &NAe1));
	if (le > rA + rB)
		return false; // 衝突していない

	// 分離軸 : Ae2
	rA = D3DXVec3Length(&Ae2);
	rB = LenSegOnSeparateAxis(&NAe2, &Be1, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NAe2));
	if (le > rA + rB)
		return false;

	// 分離軸 : Ae3
	rA = D3DXVec3Length(&Ae3);
	rB = LenSegOnSeparateAxis(&NAe3, &Be1, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NAe3));
	if (le > rA + rB)
		return false;

	// 分離軸 : Be1
	rA = LenSegOnSeparateAxis(&NBe1, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be1);
	le = fabs(D3DXVec3Dot(&Interval, &NBe1));
	if (le > rA + rB)
		return false;

	// 分離軸 : Be2
	rA = LenSegOnSeparateAxis(&NBe2, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be2);
	le = fabs(D3DXVec3Dot(&Interval, &NBe2));
	if (le > rA + rB)
		return false;

	// 分離軸 : Be3
	rA = LenSegOnSeparateAxis(&NBe3, &Ae1, &Ae2, &Ae3);
	rB = D3DXVec3Length(&Be3);
	le = fabs(D3DXVec3Dot(&Interval, &NBe3));
	if (le > rA + rB)
		return false;

	// 分離軸 : C11
	D3DXVECTOR3 Cross;
	D3DXVec3Cross(&Cross, &NAe1, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C12
	D3DXVec3Cross(&Cross, &NAe1, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C13
	D3DXVec3Cross(&Cross, &NAe1, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C21
	D3DXVec3Cross(&Cross, &NAe2, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C22
	D3DXVec3Cross(&Cross, &NAe2, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C23
	D3DXVec3Cross(&Cross, &NAe2, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C31
	D3DXVec3Cross(&Cross, &NAe3, &NBe1);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C32
	D3DXVec3Cross(&Cross, &NAe3, &NBe2);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離軸 : C33
	D3DXVec3Cross(&Cross, &NAe3, &NBe3);
	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	le = fabs(D3DXVec3Dot(&Interval, &Cross));
	if (le > rA + rB)
		return false;

	// 分離平面が存在しないので「衝突している」
	//Obb1->GetBox()->SetTexture(ResourceTag::tDebugLineHit);
	//Obb2->GetBox()->SetTexture(ResourceTag::tDebugLineHit);
	return true;
}

float Collision::LenSegOnSeparateAxis(D3DXVECTOR3 * sep, D3DXVECTOR3 * e1, D3DXVECTOR3 * e2, D3DXVECTOR3* e3)
{
	// 3つの内積の絶対値の和デ投影線分長を算出
	// 分割軸sepは標準化されていること
	float r1 = fabs(D3DXVec3Dot(sep, e1));
	float r2 = fabs(D3DXVec3Dot(sep, e2));
	float r3 = e3 ? fabs(D3DXVec3Dot(sep, e3)) : 0;
	return r1 + r2 + r3;
}

bool Collision::ObbToPoint(OBB* obb, D3DXVECTOR3 pos2, D3DXVECTOR3 size2)
{
	D3DXVECTOR3 direction = obb->GetPosition() - pos2;

	D3DXVECTOR3 obbx, obbz;
	float obbLenx, obbLenz;

	obbx = obb->GetDirection(0) * obb->GetLength(0);
	obbLenx = D3DXVec3Length(&obbx);
	obbx /= obbLenx;

	obbz = obb->GetDirection(2) * obb->GetLength(2);
	obbLenz = D3DXVec3Length(&obbz);
	obbz /= obbLenz;

	float lenx, lenz;
	lenx = D3DXVec3Dot(&obbx, &direction);
	lenz = D3DXVec3Dot(&obbz, &direction);

	if (fabs(lenx) < obbLenx && fabs(lenz) < obbLenz) 
	{
		return true;
	}

	return false;
}

bool Collision::BoundingBox2D(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2)
{
	float left_1   = pos1.x - size1.x / 2;
	float right_1  = pos1.x + size1.x / 2;
	float top_1    = pos1.y - size1.y / 2;
	float buttom_1 = pos1.y + size1.y / 2;

	float left_2   = pos2.x - size2.x / 2;
	float right_2  = pos2.x + size2.x / 2;
	float top_2    = pos2.y - size2.y / 2;
	float buttom_2 = pos2.y + size2.y / 2;

	if (left_1 < right_2)
		if (right_1 > left_2)
			if (top_1 < buttom_2)
				if (buttom_1 > top_2)
					return true;

	return false;
}

bool Collision::BoundingBox3D(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2)
{
	float left_1   = pos1.x - size1.x / 2;
	float right_1  = pos1.x + size1.x / 2;
	float top_1    = pos1.y + size1.y / 2;
	float buttom_1 = pos1.y - size1.y / 2;
	float front_1  = pos1.z - size1.z / 2;
	float back_1   = pos1.z + size1.z / 2;

	float left_2   = pos2.x - size2.x / 2;
	float right_2  = pos2.x + size2.x / 2;
	float top_2    = pos2.y - size2.y / 2;
	float buttom_2 = pos2.y + size2.y / 2;	
	float front_2  = pos2.z - size2.z / 2;
	float back_2   = pos2.z + size2.z / 2;

	if (left_1 > right_2)
		if (right_1 < left_2)
			if (top_1 < buttom_2)
				if (buttom_1 > top_2)
					if(front_1 > back_2)
						if(back_1 < front_2)
					return false;

	return true;
}

bool Collision::CheckCircle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float dist)
{
	float distance = D3DXVec3Length(&(pos2 - pos1));
	return dist >= distance;
}
