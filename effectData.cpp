#include "main.h"
#include "effectData.h"
#include "myEffekseer.h"

EffectData::EffectData(std::u16string  filename, D3DXVECTOR3 scale)
{
	m_Effect = MyEffekseer::GetInstance()->CreateEffect(filename);
	m_Scale = scale;
}
