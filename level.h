#pragma once

class Level
{
public:
	Level(const int level) : m_Level(level) {}
	int GetLevel() const { return m_Level; }
	void SetLevel(const int level) { m_Level = level; }
	void LevelUP(const int exp) { m_Level++; }

private:
	int m_Level = 0;

};