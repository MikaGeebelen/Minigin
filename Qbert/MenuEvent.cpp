#include "MenuEvent.h"

MenuEvent::MenuEvent(MenuEvents event)
	:m_Event(event)
{
}

int MenuEvent::GetEvent()
{
	return (int)m_Event;
}
