#include "main.h"
#include "effectDataBase.h"
#include "effectData.h"

void EffectDataBase::Init()
{
	m_EffectData[EffectTag::Dead] = new EffectData(u"asset/effect/EnemyDead.efkefc", D3DXVECTOR3(0.7f, 0.7f, 0.7f));
	m_EffectData[EffectTag::Attack] = new EffectData(u"asset/effect/attack.efkefc", D3DXVECTOR3(2.0f, 2.0f, 2.0f));
	m_EffectData[EffectTag::SpecialAttack] = new EffectData(u"asset/effect/playerAttack.efkefc", D3DXVECTOR3(3.0f, 3.0f, 3.0f));
	m_EffectData[EffectTag::Hit] = new EffectData(u"asset/effect/hit.efkefc", D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}

void EffectDataBase::Unitit()
{
	for (auto it = m_EffectData.begin(); it != m_EffectData.end();)
	{
		it = m_EffectData.erase(it);
	}
	m_EffectData.clear();
}