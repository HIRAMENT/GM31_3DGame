#pragma once

#include "singleton.h"

enum class SceneTag {
	eTitle,
	eTutorial,
	eGame,
	eResult
};

// ‚±‚Ì•Ó‚Í‹Ž”N‚â‚Á‚½‚Ì‚Æ“¯‚¶
class Manager : public Singleton<Manager>
{
private:
	class Scene* m_Scene;

	bool m_CursorEnable = false;
public:
	friend class Singleton<Manager>;

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void SetScene(SceneTag tag);
	Scene* GetScene()const { return m_Scene; }
	void SetCursorEnable(bool ena) { m_CursorEnable = ena; }

protected:
	Manager() {}
	virtual ~Manager() {}
};