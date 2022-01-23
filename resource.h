#pragma once
#include "singleton.h"
#include <unordered_map>

enum class ResourceTag
{
	NONE,

	tGround,
	tShadow,
	tTitleBG,
	tPlane,
	tSlash,
	tGauge,
	tGaugeBase,
	tGaugeFrame,
	tNumber,
	tExclamation,
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
	tTree0,
	tTree1,
	tTutorial,
	tTitleTemp,
	tTitleSphare,
	tTargetMarker,

	tParticleStar,
	tParticleHeart,
	tParticleCircle,
	tParticleFire,

	mPlayer,
	mSkydome,
	mSword,
	mRock,
	mEnemy,
	mSmallEnemy,
	mBossEnemy,
	mBullet,
	mTestEnemy,

	fPlayer,
	fTest,

};

enum class AnimationTag
{
	Idle,
	Jump,
	Run,
	Attack,
	Dance,
};

enum class ResourceType
{
	Texture,
	Model,
	FBX,
};

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

//class Resource : public Singleton<Resource>
//{
//private:
//	std::unordered_map<ResourceTag, ResourceData*> m_ResourceData;
//
//public:
//	void Init();
//	void Uninit();
//
//	template <typename T>
//	T* GetResource(ResourceTag tag) { return (T*)m_ResourceData.at(tag); }
//
//protected:
//	Resource() {}
//	virtual ~Resource() {}
//};
