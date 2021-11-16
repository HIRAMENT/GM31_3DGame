#pragma once

#include <list>
#include "singleton.h"

class Boids
{
public:
	Boids(D3DXVECTOR3 pos);
	D3DXVECTOR3 KeepDistance(void);
	D3DXVECTOR3 MatchHeading(void);
	D3DXVECTOR3 SteerToCenter(void);

	float CanISee(Boids* ptr);
	int SeeFriend(void);

	void ClearVisibleList(void);
	D3DXVECTOR3 Cruising(void);
	void ComputeRPY(void);
	D3DXVECTOR3 GetPosition(void) const { return m_Position; }
	D3DXVECTOR3 GetOldPosition(void) const { return m_OldPosition; }
	D3DXVECTOR3 GetVelocity(void) const { return m_Velocity; }
	D3DXVECTOR3 GetOldVelocity(void) const { return m_OldVelocity; }
	D3DXVECTOR3 GetRotation(void) const { return m_Angle; }

	void FlockIt(void);


public:
	Boids* m_NearMate;

private:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_OldPosition;
	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_OldVelocity;
	D3DXVECTOR3 m_Angle;
	float m_Speed;
	float m_Perception;
	float m_NearDistance;
	int m_SeenNum;
};

class BoidsData : public Singleton<BoidsData> {
public:
	friend class Singleton<BoidsData>;

public:
	std::list<Boids*> boidsList;
	std::list<Boids*> visibleList;

protected:
	BoidsData() {}
	virtual ~BoidsData() {}
};