#pragma once
#include "singleton.h"

class OBB;

class Collision : public Singleton<Collision>
{
public:
	bool ObbToObb(OBB* Obb1, OBB* Obb2);
	float LenSegOnSeparateAxis(D3DXVECTOR3* sep, D3DXVECTOR3* e1, D3DXVECTOR3* e2, D3DXVECTOR3* e3 = 0);	// ìäâeê¸ï™ÇÃéZèo
	bool ObbToPoint(OBB* obb, D3DXVECTOR3 pos2, D3DXVECTOR3 size2);

	friend class Singleton<Collision>;

protected:
	Collision() {}
	virtual ~Collision() {}

private:


};