#include "main.h"
#include "gamepad.h"

GamepadX::GamepadX()
{
}

GamepadX::~GamepadX()
{
}

bool GamepadX::ButtonDown(int padNum, InputButton button)
{
	switch (button)
	{
	case A:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_A) return true;
		break;
	case B:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_B) return true;
		break;
	case X:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_X) return true;
		break;
	case Y:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) return true;
		break;
	case UP:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) return true;
		break;
	case DOWN:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) return true;
		break;
	case LEFT:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) return true;
		break;
	case RIGHT:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) return true;
		break;
	case START:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_START) return true;
		break;
	case BACK:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) return true;
		break;
	case LB:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) return true;
		break;
	case RB:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) return true;
		break;
	case LTRIGGER:
		if (m_GamePad[padNum].state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return true;
		break;
	case RTRIGGER:
		if (m_GamePad[padNum].state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return true;
		break;
	case LSTICK:
		if ((m_GamePad[padNum].state.Gamepad.sThumbLX >  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			 m_GamePad[padNum].state.Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(m_GamePad[padNum].state.Gamepad.sThumbLY >  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			 m_GamePad[padNum].state.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {
			return true;
		}
		break;
	case RSTICK:
		if ((m_GamePad[padNum].state.Gamepad.sThumbRX >  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			 m_GamePad[padNum].state.Gamepad.sThumbRX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(m_GamePad[padNum].state.Gamepad.sThumbRY >  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			 m_GamePad[padNum].state.Gamepad.sThumbRY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {
			return true;
		}
		break;
	default:
		return false;
		break;
	}
	return false;
}

bool GamepadX::ButtonHit(int padNum, InputButton button)
{
	switch (button)
	{
	case A:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			if(!(m_GamePad_Old[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_A)) {
				return false;
			}
			else
			{
				return true;
			}
		}
		break;
	case B:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_B) return true;
		break;
	case X:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_X) return true;
		break;
	case Y:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) return true;
		break;
	case UP:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) return true;
		break;
	case DOWN:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) return true;
		break;
	case LEFT:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) return true;
		break;
	case RIGHT:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) return true;
		break;
	case START:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_START) return true;
		break;
	case BACK:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) return true;
		break;
	case LB:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) return true;
		break;
	case RB:
		if (m_GamePad[padNum].state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) return true;
		break;
	case LTRIGGER:
		if (m_GamePad[padNum].state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return true;
		break;
	case RTRIGGER:
		if (m_GamePad[padNum].state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD) return true;
		break;
	case LSTICK:
		if ((m_GamePad[padNum].state.Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			m_GamePad[padNum].state.Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(m_GamePad[padNum].state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
				m_GamePad[padNum].state.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {
			return true;
		}
		break;
	case RSTICK:
		if ((m_GamePad[padNum].state.Gamepad.sThumbRX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			m_GamePad[padNum].state.Gamepad.sThumbRX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(m_GamePad[padNum].state.Gamepad.sThumbRY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
				m_GamePad[padNum].state.Gamepad.sThumbRY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)) {
			return true;
		}
		break;
	default:
		return false;
		break;
	}
	return false;
}


void GamepadX::Init()
{

}

void GamepadX::Update()
{
	FindController();

	for (DWORD i = 0; i < CONTROLLERS_MAX; i++)
	{
		//m_GamePad_Old[i] = m_GamePad[i];

		if (m_GamePad[i].bConnected)
		{
			WORD Buttons = m_GamePad[i].state.Gamepad.wButtons;
			WORD Buttons_old = m_GamePad_Old[i].state.Gamepad.wButtons;
		}

	}
}

DWORD GamepadX::FindController()
{
	DWORD dwResult;
	for (DWORD i = 0; i < CONTROLLERS_MAX; i++)
	{
		dwResult = XInputGetState(i, &m_GamePad[i].state);
		if (dwResult == ERROR_SUCCESS)
		{
			// コントローラあったよ
			m_GamePad[i].bConnected = true;
		}
		else
		{
			// コントローラないよ
			m_GamePad[i].bConnected = false;
		}
	}
	return dwResult;
}
