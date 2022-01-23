#pragma once

#include "gameObject.h"

enum class AnimationTag;

class Player : public GameObject 
{
private:
	Transform m_Transform;
	D3DXVECTOR3 m_Up = Vec3::Up;
	D3DXVECTOR3 m_Forward = Vec3::Forward;
	D3DXVECTOR3 m_Right = Vec3::Right;

	D3DXVECTOR3 m_Size;

	class Shadow* m_Shadow = nullptr;
	class OBB* m_Obb = nullptr;
	class ViewSensor* m_ViewSensor = nullptr;
	bool m_Dash;

	class Status* m_Status = nullptr;

	class AnimationModel* m_Model = nullptr;
	int m_AnimeFrame;
	int m_AnimeEndFrame;
	int m_AnimeFrameRiseValue;
	AnimationTag m_BeforAnime;
	AnimationTag m_AfterAnime;
	float m_BlendRate;

	int m_AttackRange;
	int m_AttackLength;
	bool m_SensorDisplay;

private:
	void ImGui();
	void Animation(AnimationTag anime1, AnimationTag anime2, bool isMove);
	void CreateStatusInfo(Scene* scene);

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
	void SetPlayer();
	void SetPlayerRotation(const Quaternion& qua);
};