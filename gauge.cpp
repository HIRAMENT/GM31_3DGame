#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "resource.h"
#include "input.h"
#include "polygon2D.h"
#include "polygon3D.h"
#include "scene.h"
#include "gauge.h"

Gauge::Gauge(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 adjust, int capa, int drawPriority)
	:GameObject(scene, ObjectType::eObGauge, drawPriority)
	, m_Aspect({ 3.f,0.5f,0.f })
	, m_Adjust(adjust)
{
	SetPosition(pos);
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 1.0f, 1.0f, 1.0f });

	m_Capacity = capa;
	m_DiffCapacity = capa;
	m_MaxCapacity = capa;

	m_BGaugeFrameUI = new Polygon3D(scene, { pos.x + adjust.x, pos.y + adjust.y, pos.z + adjust.z }, { m_Aspect.x, m_Aspect.y, 0.0f }, ResourceTag::tGaugeFrame, false, true ,drawPriority);
	m_BGaugeDecUI   = new Polygon3D(scene, { pos.x + adjust.x, pos.y + adjust.y, pos.z + adjust.z }, { m_Aspect.x, m_Aspect.y, 0.0f }, ResourceTag::tGaugeBase,  false, true ,drawPriority + 1);
	m_BGaugeUI      = new Polygon3D(scene, { pos.x + adjust.x, pos.y + adjust.y, pos.z + adjust.z }, { m_Aspect.x, m_Aspect.y, 0.0f }, ResourceTag::tGaugeBase,  false, true ,drawPriority + 2);
	m_BGaugeDecUI->SetColor(255, 165, 0);

	scene->Add(this);
}

Gauge::Gauge(Scene * scene, D3DXVECTOR2 pos, D3DXVECTOR2 size, int capa, int drawPriority)
	:GameObject(scene, ObjectType::eObGauge, drawPriority)
	, m_Aspect({ 3.f,0.5f,0.f })
{
	SetPosition({pos.x, pos.y, 0.0f});
	SetRotation({ 0.0f, 0.0f, 0.0f });
	SetScale({ 1.0f, 1.0f, 1.0f });

	m_Capacity = capa;
	m_DiffCapacity = capa;
	m_MaxCapacity = capa;

	m_PGaugeFrameUI = new Polygon2D(scene, pos, { m_Aspect.x * size.x, m_Aspect.y * size.y }, ResourceTag::tGaugeFrame, drawPriority);
	m_PGaugeDecUI   = new Polygon2D(scene, pos, { m_Aspect.x * size.x, m_Aspect.y * size.y }, ResourceTag::tGaugeBase, drawPriority + 1);
	m_PGaugeUI      = new Polygon2D(scene, pos, { m_Aspect.x * size.x, m_Aspect.y * size.y }, ResourceTag::tGaugeBase, drawPriority + 2);
	m_PGaugeDecUI->SetColor(255, 165, 0);

	scene->Add(this);
}

void Gauge::Uninit()
{
	if (m_BGaugeFrameUI)
	{
		m_BGaugeFrameUI->SetDestroy();
		m_BGaugeDecUI->SetDestroy();
		m_BGaugeUI->SetDestroy();
	}
	else if (m_PGaugeFrameUI)
	{
		m_PGaugeFrameUI->SetDestroy();
		m_PGaugeDecUI->SetDestroy();
		m_PGaugeUI->SetDestroy();
	}
}

void Gauge::Update()
{	
}

void Gauge::Draw()
{
}

void Gauge::SetGaugePos(D3DXVECTOR3 pos)
{
	if (m_BGaugeFrameUI)
	{
		m_BGaugeFrameUI->SetPosition({ pos.x + m_Adjust.x ,pos.y + m_Adjust.y ,pos.z + m_Adjust.z });
		m_BGaugeDecUI->SetPosition({ pos.x + m_Adjust.x ,pos.y + m_Adjust.y ,pos.z + m_Adjust.z });
		m_BGaugeUI->SetPosition({ pos.x + m_Adjust.x ,pos.y + m_Adjust.y ,pos.z + m_Adjust.z });
	}
}

void Gauge::SetCapacity(int capa)
{
	m_Capacity = capa;
}

void Gauge::DegCapacity(int deg)
{
	m_Capacity -= deg;
	m_DiffCapacity = deg;
	if (m_BGaugeUI)
	{
		m_BGaugeUI->StartSlide(m_MaxCapacity, m_Capacity, 1.0f);
		m_BGaugeDecUI->StartSlide(m_MaxCapacity, m_Capacity, 0.5f);
	}
	else if (m_PGaugeUI)
	{
		m_PGaugeUI->StartSlide(m_MaxCapacity, m_Capacity, 0.5f);
		m_PGaugeDecUI->StartSlide(m_MaxCapacity, m_Capacity, 0.05f);
	}
}

void Gauge::AddCapacity(int add)
{
	m_Capacity += add;
	m_DiffCapacity = add;
	if (m_BGaugeUI)
	{
		m_BGaugeUI->StartSlide(m_MaxCapacity, m_Capacity, 1.0f);
		m_BGaugeDecUI->StartSlide(m_MaxCapacity, m_Capacity, 0.5f);
	}
	else if (m_PGaugeUI)
	{
		m_PGaugeUI->StartSlide(m_MaxCapacity, m_Capacity, 0.05f);
		m_PGaugeDecUI->StartSlide(m_MaxCapacity, m_Capacity, 0.5f);
	}
}

void Gauge::ChangeColor(float r, float g, float b)
{
	if (m_BGaugeUI)
	{
		m_BGaugeUI->SetColor(r, g, b);
	}
	else if (m_PGaugeUI)
	{
		m_PGaugeUI->SetColor(r, g, b);
	}
}

void Gauge::SetDisplay(bool display)
{
	if (m_BGaugeFrameUI)
	{
		m_BGaugeFrameUI->SetDisplay(display);
		m_BGaugeDecUI->SetDisplay(display);
		m_BGaugeUI->SetDisplay(display);
	}
	else if (m_PGaugeFrameUI)
	{
		m_PGaugeFrameUI->SetDisplay(display);
		m_PGaugeDecUI->SetDisplay(display);
		m_PGaugeUI->SetDisplay(display);
	}
}
