#pragma once

#include "singleton.h"
#include <unordered_map>


enum class EffectTag
{
	NONE,
	Dead,
	Attack,
	SpecialAttack,
	Hit,
};


class EffectData;


class EffectDataBase : public Singleton<EffectDataBase>
{
public:
	friend class Singleton<EffectDataBase>;

	void Init();
	void Unitit();

	EffectData* GetEffectData(EffectTag tag) const { return m_EffectData.at(tag); }

private:
	std::unordered_map<EffectTag, EffectData*> m_EffectData;

protected:
	EffectDataBase() {}
	virtual ~EffectDataBase() {}

};