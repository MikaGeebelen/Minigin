#pragma once
#include <Observer.h>
#include <string>
class LevelObserver final : public Observer
{
public:
	LevelObserver(int level,const std::string& gameMode );
	void OnNotify(Event* event) override;

private:
	int m_level;
	std::string m_GameMode;
};

