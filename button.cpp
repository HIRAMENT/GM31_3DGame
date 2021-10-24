#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "resource.h"
#include "scene.h"
#include "polygon2D.h"
#include "button.h"

Button::Button(Scene * scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, ResourceTag tag, int drawPriority)
	: GameObject(scene, ObjectType::eObButton, drawPriority)
{
	m_ButtonUI       = new Polygon2D(scene, pos, size, tag,   drawPriority + 2);
	m_ButtonFrameUI  = new Polygon2D(scene, pos, size, ResourceTag::tButtonFrame,  drawPriority);
	m_ButtonSelectUI = new Polygon2D(scene, pos, size, ResourceTag::tButtonSelect, drawPriority + 1);
	m_ButtonClickUI  = new Polygon2D(scene, pos, size, ResourceTag::tButtonClick,  drawPriority);

	m_SelectAlpha = 0.0f;
	m_SelectMoveValue = 0.05f;
	m_ClickAlpha = 0.0f;
	m_ClickMoveValue = 0.1f;
	m_isClick = false;
	m_isSelect = false;

	m_ButtonSelectUI->SetAlpha(m_SelectAlpha);
	m_ButtonClickUI->SetAlpha(m_ClickAlpha);

	scene->Add(this);
}

void Button::Init()
{
}

void Button::Uninit()
{
}

void Button::Update()
{
	if (m_isSelect)
	{
		m_SelectAlpha += m_SelectMoveValue;
		if (m_SelectAlpha >= 1.0f || m_SelectAlpha <= 0.0f) { m_SelectMoveValue *= -1; }
	}

	if (m_isClick)
	{
		m_ClickAlpha += m_ClickMoveValue;
		if (m_ClickAlpha >= 1.0f || m_ClickAlpha <= 0.0f) { m_ClickMoveValue *= -1; }
	}

	m_ButtonSelectUI->SetAlpha(m_SelectAlpha);
	m_ButtonClickUI->SetAlpha(m_ClickAlpha);
}

void Button::Draw()
{
}

void Button::HaveSelect(bool select)
{
	if (select)
	{
		m_isSelect = true;
	}
	else if(!select)
	{
		m_isSelect = false;
		m_SelectAlpha = 0.0f;
		m_SelectMoveValue = fabsf(m_SelectMoveValue);
	}
}

void Button::HaveClick(bool click)
{
	if(click)
	{ 
		m_isClick = true;
	}
	else if(!click)
	{
		m_isClick = false;
		m_ClickAlpha = 0.0;
		m_ClickMoveValue = fabsf(m_ClickMoveValue);
	}
	
}
