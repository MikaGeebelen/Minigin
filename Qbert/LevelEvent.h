#pragma once
#include "Event.h"
class LevelEvent final : public Event
{
public:
	enum class LevelEvents
	{
		GameOver,
		LostLife,
		LevelFinished
	};
	
	LevelEvent(LevelEvents event);
	int GetEvent() override;
private:
	LevelEvents m_Event;
};

