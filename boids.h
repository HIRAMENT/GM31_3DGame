#pragma once

#include <list>
#include "singleton.h"

class OBB;
class Enemy;

class Boids
{
public:
	Boids();
	D3DXVECTOR3 KeepDistance(void);

	float CanISee(Boids* ptr);
	int SeeFriend(void);

	void ClearVisibleList(void);
	void ComputeRPY(void);
	D3DXVECTOR3 FollowTarget(void);

	D3DXVECTOR3 GetPosition(void) const { return m_Position; }
	D3DXVECTOR3 GetOldPosition(void) const { return m_OldPosition; }
	D3DXVECTOR3 GetVelocity(void) const { return m_Velocity; }
	D3DXVECTOR3 GetOldVelocity(void) const { return m_OldVelocity; }
	D3DXVECTOR3 GetRotation(void) const { return m_Angle; }
	bool GetJustDistance(void) const { return m_JustDistance; }

	void SetTarget(D3DXVECTOR3 pos) { m_Target = pos; }

	D3DXVECTOR3 Detour(OBB* obb);

	void FlockIt(Enemy* enemy);

private:
	D3DXVECTOR3 SalculatingRatio(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, bool approach = true);
	D3DXVECTOR3 SalculatingRatio(D3DXVECTOR3 vec, bool approach = true);

public:
	Boids* m_NearMate;

private:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_OldPosition;
	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_OldVelocity;
	D3DXVECTOR3 m_Angle;
	D3DXVECTOR3 m_Target;
	D3DXVECTOR3 m_Movement;
	float m_Speed;
	float m_Perception;
	float m_NearDistance;
	int m_SeenNum;
	bool m_JustDistance;

	class ViewSensor* m_OutLook = nullptr;
	float m_ViewRange;
	float m_ViewLenght;
};

class BoidsData : public Singleton<BoidsData> {
public:
	friend class Singleton<BoidsData>;

	void Add(Boids* boids);
	void Organize();	// nullÇÃóvëfÇçÌèú

public:
	std::list<Boids*> boidsList;
	std::list<Boids*> visibleList;

protected:
	BoidsData() {}
	virtual ~BoidsData() {}
};