#include "LevelEvent.h"

LevelEvent::LevelEvent(LevelEvents event)
	:m_Event(event)
{
}

int LevelEvent::GetEvent()
{
	return (int)m_Event;
}
