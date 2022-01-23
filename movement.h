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

	D3DXVECTOR2 CirclualMotion(D3DXVECTOR3 pos, float rad, int angle) const;
	D3DXVECTOR3 CirclualMotion3D(D3DXVECTOR3 pos, float rad, D3DXVECTOR2 angle) const;
	D3DXVECTOR3 TargetFollow(D3DXVECTOR3 mpos, D3DXVECTOR3 tpos, float speed) const;
	float GetTwoVecAngle(D3DXVECTOR3 mvec, D3DXVECTOR3 tvec) const;
	float GetTwoVecAngle(D3DXVECTOR2 mvec, D3DXVECTOR2 tvec) const;
	D3DXVECTOR3 BezierCurve(BezierCurveInfo info) const;
	float TargetRotation(D3DXVECTOR3 mpos, D3DXVECTOR3 tpos) const;

protected:
	Movement() {}
	virtual ~Movement() {}
};