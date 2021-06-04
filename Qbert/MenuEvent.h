#pragma once
#include "Event.h"
class MenuEvent final : public Event
{
public:
	enum class MenuEvents
	{
		Singleplayer,
		MultiPlayer,
		Versus
	};

	MenuEvent(MenuEvents event);
	int GetEvent() override;
private:
	MenuEvents m_Event;
};

