#pragma once
#include <Observer.h>
#include <string>
class LevelObserver final : public Observer
{
public:
	LevelObserver(int level, int lives,  const std::string& gameMode );
	void OnNotify(Event* event) override;

private:
	int m_level;
	int m_Lives;
	std::string m_GameMode;
};

