#pragma once
#include "vector2.h"
#include "singleton.h"

enum InputButton
{
	A,
	B,
	X,
	Y,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	START,
	BACK,
	LB,
	RB,
	LTRIGGER,
	RTRIGGER,
	LSTICK,
	RSTICK,

	BUTTON_MAX
};

class GamepadX : public Singleton<GamepadX>
{
public:
	friend class Singleton<GamepadX>;

	// �{�^���������Ă����
	bool ButtonDown(int padNum, InputButton button);
	// �{�^�����������u��
	bool ButtonHit(int padNum, InputButton button);

	void Init();
	void Update();

private:
	static const int CONTROLLERS_MAX = 4;

	typedef struct {
		XINPUT_STATE state;
		bool bConnected;
	} CONTOROLER_STATE;

	CONTOROLER_STATE m_GamePad[CONTROLLERS_MAX];
	CONTOROLER_STATE m_GamePad_Old[CONTROLLERS_MAX];

	DWORD FindController();				// �Ȃ����Ă�R���g���[����T���Ĕԍ���Ԃ�

	float m_ButtonPushTime[InputButton::BUTTON_MAX];

protected:
	GamepadX();
	virtual~GamepadX();
};