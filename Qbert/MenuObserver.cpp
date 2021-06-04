#include "MenuObserver.h"

#include "Event.h"
#include "MenuEvent.h"
#include "QbertApplication.h"
MenuObserver::MenuObserver(const QbertApplication* pApplication)
	:m_pApp(pApplication)
{
}

void MenuObserver::OnNotify(Event* event)
{
	switch ((MenuEvent::MenuEvents)event->GetEvent())
	{
	case MenuEvent::MenuEvents::Singleplayer:
		m_pApp->StartGame("levelp1");
		break;
	case MenuEvent::MenuEvents::MultiPlayer:
		m_pApp->StartGame("levelp2");
		break;
	case MenuEvent::MenuEvents::Versus:
		m_pApp->StartGame("levelvs");
		break;
	}
	
}
