#pragma once
#include "singleton.h"

struct BezierCurveInfo {
	D3DXVECTOR3 ControlPoint[4];
	float Time;
};

class Movement : public Singleton<Movement>
{
public:
	friend class Singleton<Movement>;

	D3DXVECTOR2 CirclualMotion(D3DXVECTOR3 pos, float rad, int angle);
	D3DXVECTOR3 CirclualMotion3D(D3DXVECTOR3 pos, float rad, D3DXVECTOR2 angle);
	D3DXVECTOR3 TargetFollow(D3DXVECTOR3 mpos, D3DXVECTOR3 tpos, float speed);
	float GetTwoVecAngle(D3DXVECTOR3 mvec, D3DXVECTOR3 tvec);
	float GetTwoVecAngle(D3DXVECTOR2 mvec, D3DXVECTOR2 tvec);
	D3DXVECTOR3 BezierCurve(BezierCurveInfo info);

protected:
	Movement() {}
	virtual ~Movement() {}
};