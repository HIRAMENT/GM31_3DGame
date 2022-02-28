#pragma once
#include "singleton.h"
#include <unordered_map>

enum class ResourceTag
{
	NONE,

	tGround,
	tShadow,
	tPlane,
	tSlash,
	tGauge,
	tGaugeBase,
	tGaugeFrame,
	tNumber,
	tTitleName,
	tButtonFrame,
	tButtonSelect,
	tButtonClick,
	tStartLetter,
	tEndLetter,
	tReturnTitleLetter,
	tGameClear,
	tGameOver,
	tGameClearLetter,
	tGameOverLetter,
	tTutorial,
	tTitleTemp,
	tTitleSphare,
	tTargetMarker,
	tDebugLine,
	tDebugLineHit,
	tDebugSensor,
	tDebugSensorHit,

	tParticleStar,
	tParticleHeart,
	tParticleCircle,
	tParticleFire,

	mPlayer,
	mSkydome,
	mRock,
	mTree,
	mSmallEnemy,
	mBossEnemy,

	fPlayer,
	fTest,
};

enum class AnimationTag
{
	Idle,
	Jump,
	Run,
	Attack,
	Avoidance,
	Dash,
	Hit,
	Dead,
	Backstep,
};

enum class ResourceType
{
	Texture,
	Model,
	FBX,
};

class EffectDataBase;
enum class EffectTag;

class ResourceData : public Singleton<ResourceData>
{
public:
	friend class Singleton<ResourceData>;

	void Init();
	void Uninit();

	class Model*   GetModelResource(ResourceTag tag) { return m_ModelResource.at(tag); }
	class Texture* GetTextureResource(ResourceTag tag) { return m_TextureResource.at(tag); }
	class AnimationModel* GetAnimationModel(ResourceTag tag) { return m_AnimationModelResource.at(tag); }
	class Animation* GetAnimationResource(AnimationTag tag) {return m_AnimationResource.at(tag); }
	class EffectData* GetEffectResource(EffectTag tag) const;
	
private:
	std::unordered_map<ResourceTag,  class Model*>            m_ModelResource;
	std::unordered_map<ResourceTag,  class Texture*>          m_TextureResource;
	std::unordered_map<ResourceTag,  class AnimationModel*>   m_AnimationModelResource;
	std::unordered_map<AnimationTag, class Animation*>          m_AnimationResource;

	void InitModel();
	void InitTexture();
	void InitAnimationModel();
	void InitAnimation();
	void UninitModel();
	void UninitTexture();
	void UninitAnimationModel();
	void UninitAnimation();

protected:
	ResourceData() {}
	virtual ~ResourceData() {}
};
