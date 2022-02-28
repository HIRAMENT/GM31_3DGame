#pragma once

#include "Effekseer/Effekseer.h"

class EffectData
{
public:
	EffectData() = delete;
	EffectData(std::u16string filename, D3DXVECTOR3 scale);

	Effekseer::EffectRef GetEffect() const { return m_Effect; }
	D3DXVECTOR3 GetScale() const { return m_Scale; }


private:
	Effekseer::EffectRef m_Effect;
	D3DXVECTOR3 m_Scale;
};