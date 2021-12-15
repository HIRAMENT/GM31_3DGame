#pragma once
#include "gameObject.h"

class Button : public GameObject
{
private:
	class Polygon2D* m_ButtonUI = nullptr;
	Polygon2D* m_ButtonFrameUI = nullptr;
	Polygon2D* m_ButtonSelectUI = nullptr;
	Polygon2D* m_ButtonClickUI = nullptr;

	float m_SelectAlpha;
	float m_SelectMoveValue;
	bool m_isSelect;
	float m_ClickAlpha;
	float m_ClickMoveValue;
	bool m_isClick;
	
public:
	Button(class Scene* scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, ResourceTag tag, int drawPriority);

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	bool CursorEnter(POINT pos);
	void HaveSelect(bool select);
	void HaveClick(bool click);
};