#pragma once

#include "gameObject.h"
#include "counter.h"

enum class AnimationTag;

class Player : public GameObject 
{
private:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	D3DXVECTOR3 m_Size;
	D3DXVECTOR3 m_Adjust;

	class Shadow* m_Shadow = nullptr;
	class OBB* m_Obb = nullptr;
	class ViewSensor* m_ViewSensor = nullptr;

	class Status* m_Status = nullptr;

	class AnimationModel* m_Model = nullptr;
	int m_AnimeFrame;
	int m_AnimeEndFrame;
	AnimationTag m_BeforAnime;
	AnimationTag m_AfterAnime;
	float m_BlendRate;
	bool m_ChangeAnime;

	int m_AttackRange;
	int m_AttackLength;
	bool m_SensorDisplay;

	class EffectManager* m_Effect;
	int m_EffectHandle;

	Counter m_Cost;
	int m_TecPoint;
	class Gauge* m_CostGauge;

	class PlayerState* m_State;
	
	bool m_isDead;

private:
	void ImGui();
	void Animation();
	void CreateStatusInfo(class Scene* scene);

public:
	Player(class Scene* scene,D3DXVECTOR3 pos,int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	D3DXVECTOR3 GetForward() const { return m_Forward; }
	D3DXVECTOR3 GetQuaRight() const { return m_Right; }
	OBB* GetObb() const { return m_Obb; }
	Status* GetStatus() const { return m_Status; }
	Transform GetTransform() const { return m_Transform; }
	int GetTecPoint() const { return m_TecPoint; }
	Gauge* GetCostGauge() const { return m_CostGauge; }
	ViewSensor* GetViewSensor() const { return m_ViewSensor; }
	int GetAnimeFrame() const { return m_AnimeFrame; }
	int GetAnimeEndFrame() const { return m_AnimeEndFrame; }
	bool GetisDead() const { return m_isDead; }
	void SetPlayer();
	void SetPlayerRotation(const Quaternion& qua);
	void SetTransformPos(D3DXVECTOR3 pos) { m_Transform.SetPosition(pos); }
	void SetTransformRot(D3DXVECTOR3 axis, float deg) { m_Transform.SetRotation(axis, deg); }
	void SetTransformTrans(D3DXVECTOR3 trans) { m_Transform.Translate(trans); }
	void SetTecPoint(int point) { m_TecPoint = point; }
	void SetisDead(bool dead) { m_isDead = dead; }
	void AddCost(float add);
	void DecCost(float dec);
	void ChangeState(PlayerState* state);
	void SetAnimation(AnimationTag tag);
	bool isAnimationFinish() { return m_AnimeFrame >= m_AnimeEndFrame; };
};