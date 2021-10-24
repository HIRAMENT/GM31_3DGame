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

public:
	friend class Singleton<Manager>;

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void SetScene(SceneTag tag);

protected:
	Manager() {}
	virtual ~Manager() {}
};