#pragma once
#include "singleton.h"

class OBB;

class Collision : public Singleton<Collision>
{
public:
	bool ObbToObb(OBB* Obb1, OBB* Obb2);
	float LenSegOnSeparateAxis(D3DXVECTOR3* sep, D3DXVECTOR3* e1, D3DXVECTOR3* e2, D3DXVECTOR3* e3 = 0);	// ìäâeê¸ï™ÇÃéZèo
	bool ObbToPoint(OBB* obb, D3DXVECTOR3 pos2, D3DXVECTOR3 size2);
	bool BoundingBox2D(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);
	bool BoundingBox3D(D3DXVECTOR3 pos1, D3DXVECTOR3 size1, D3DXVECTOR3 pos2, D3DXVECTOR3 size2);
	bool CheckCircle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float dist);

	friend class Singleton<Collision>;

protected:
	Collision() {}
	virtual ~Collision() {}

private:


};