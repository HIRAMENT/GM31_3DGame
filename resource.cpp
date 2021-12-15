#include "main.h"
#include "renderer.h"
#include "resource.h"
#include "model.h"
#include "texture.h"
#include "audio.h"
#include "animationModel.h"

void ResourceData::Init()
{
	InitModel();
	InitTexture();
	InitAnimationModel();
	InitAnimation();
}

void ResourceData::Uninit()
{
	UninitModel();
	UninitTexture();
	UninitAnimationModel();
	UninitAnimation();
}

void ResourceData::InitModel()
{
	m_ModelResource[ResourceTag::mPlayer]  = new Model("asset\\model\\character\\player.obj");
	m_ModelResource[ResourceTag::mSkydome] = new Model("asset\\model\\stage\\skydome.obj");
	m_ModelResource[ResourceTag::mSword]   = new Model("asset\\model\\item\\sword.obj");
	m_ModelResource[ResourceTag::mRock]    = new Model("asset\\model\\stage\\rock.obj");
	m_ModelResource[ResourceTag::mEnemy]    = new Model("asset\\model\\character\\enemy.obj");
	m_ModelResource[ResourceTag::mSmallEnemy]    = new Model("asset\\model\\character\\smallEnemy.obj");
	m_ModelResource[ResourceTag::mBossEnemy]    = new Model("asset\\model\\character\\bossEnemy.obj");
	m_ModelResource[ResourceTag::mBullet]    = new Model("asset\\model\\item\\torus.obj");
	m_ModelResource[ResourceTag::mTestEnemy]    = new Model("asset\\model\\character\\enemy.obj");
}

void ResourceData::InitTexture()
{
	m_TextureResource[ResourceTag::tGround]		       = new Texture("asset/texture/ground.dds", 1, 1);
	m_TextureResource[ResourceTag::tShadow]            = new Texture("asset/texture/shadow.png", 1, 1);
	m_TextureResource[ResourceTag::tTitleBG]           = new Texture("asset/texture/titleBG.png", 1, 1);
	m_TextureResource[ResourceTag::tPlane]             = new Texture("asset/texture/plane.png", 1, 1);
	m_TextureResource[ResourceTag::tSlash]             = new Texture("asset/texture/slash.png", 3, 5);
	m_TextureResource[ResourceTag::tGauge]		       = new Texture("asset/texture/gauge.png", 1, 1);
	m_TextureResource[ResourceTag::tGaugeBase]	       = new Texture("asset/texture/gaugebase.png", 1, 1);
	m_TextureResource[ResourceTag::tGaugeFrame]        = new Texture("asset/texture/gaugeframe.png", 1, 1);
	m_TextureResource[ResourceTag::tNumber]            = new Texture("asset/texture/number.png", 13, 1);
	m_TextureResource[ResourceTag::tExclamation]       = new Texture("asset/texture/exclamation.png", 1, 1);
	m_TextureResource[ResourceTag::tTitleName]         = new Texture("asset/texture/titleName.png", 1, 1);
	m_TextureResource[ResourceTag::tButtonFrame]       = new Texture("asset/texture/buttonFrame.png", 1, 1);
	m_TextureResource[ResourceTag::tButtonSelect]      = new Texture("asset/texture/buttonSelect.png", 1, 1);
	m_TextureResource[ResourceTag::tButtonClick]       = new Texture("asset/texture/buttonClick.png", 1, 1);
	m_TextureResource[ResourceTag::tStartLetter]       = new Texture("asset/texture/start.png", 1, 1);
	m_TextureResource[ResourceTag::tEndLetter]         = new Texture("asset/texture/end.png", 1, 1);
	m_TextureResource[ResourceTag::tReturnTitleLetter] = new Texture("asset/texture/returnTitle.png", 1, 1);
	m_TextureResource[ResourceTag::tGameClear]         = new Texture("asset/texture/clear.png", 1, 1);
	m_TextureResource[ResourceTag::tGameOver]          = new Texture("asset/texture/over.png", 1, 1);
	m_TextureResource[ResourceTag::tGameClearLetter]   = new Texture("asset/texture/gameClear.png", 1, 1);
	m_TextureResource[ResourceTag::tGameOverLetter]    = new Texture("asset/texture/gameOver.png", 1, 1);
	m_TextureResource[ResourceTag::tTree0]             = new Texture("asset/texture/tree0.png", 1, 1);
	m_TextureResource[ResourceTag::tTree1]             = new Texture("asset/texture/tree1.png", 1, 1);
	m_TextureResource[ResourceTag::tTutorial]          = new Texture("asset/texture/tutorial.png", 1, 1);
}

void ResourceData::InitAnimationModel()
{
	m_AnimationModelResource[ResourceTag::fPlayer] = new AnimationModel("asset\\model\\character\\JapanPlayer.fbx");
	//m_AnimationModelResource[ResourceTag::fTest] = new AnimationModel("asset\\model\\test\\nyan.fbx");
}

void ResourceData::InitAnimation()
{
	m_AnimationResource[AnimationTag::Idle] = new Animation("asset\\model\\animation\\idle.fbx");
	m_AnimationResource[AnimationTag::Jump] = new Animation("asset\\model\\animation\\jump.fbx");
	m_AnimationResource[AnimationTag::Run] = new Animation("asset\\model\\animation\\run.fbx");
	m_AnimationResource[AnimationTag::Attack] = new Animation("asset\\model\\animation\\attack.fbx");
	m_AnimationResource[AnimationTag::Dance] = new Animation("asset\\model\\animation\\dance.fbx");
}

void ResourceData::UninitModel()
{
	for (auto it = m_ModelResource.begin(); it != m_ModelResource.end();)
	{
		it = m_ModelResource.erase(it);
	}
	m_ModelResource.clear();
}

void ResourceData::UninitTexture()
{
	for (auto it = m_TextureResource.begin(); it != m_TextureResource.end();)
	{
		it = m_TextureResource.erase(it);
	}
	m_TextureResource.clear();
}

void ResourceData::UninitAnimationModel()
{
	for (auto it = m_AnimationModelResource.begin(); it != m_AnimationModelResource.end();)
	{
		it = m_AnimationModelResource.erase(it);
	}
	m_AnimationModelResource.clear();
}

void ResourceData::UninitAnimation()
{
	for (auto it = m_AnimationResource.begin(); it != m_AnimationResource.end();)
	{
		it = m_AnimationResource.erase(it);
	}
	m_AnimationResource.clear();
}
