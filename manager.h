#pragma once

#include "singleton.h"

enum class SceneTag {
	eTitle,
	eTutorial,
	eGame,
	eResult
};

// ���̕ӂ͋��N������̂Ɠ���
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

protected:
	Manager() {}
	virtual ~Manager() {}
};