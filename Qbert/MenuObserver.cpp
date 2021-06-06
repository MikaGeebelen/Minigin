#include "MenuObserver.h"

#include "Event.h"
#include "MenuEvent.h"
#include "QbertApplication.h"

#include "SceneManager.h"
MenuObserver::MenuObserver(const QbertApplication* pApplication)
	:m_pApp(pApplication)
{
}

void MenuObserver::OnNotify(Event* event)
{
	switch ((MenuEvent::MenuEvents)event->GetEvent())
	{
	case MenuEvent::MenuEvents::Singleplayer:
		//m_pApp->StartGame("levelp1");
		SceneManager::GetInstance().UseFunction("levelp1", 1);
		break;
	case MenuEvent::MenuEvents::MultiPlayer:
		SceneManager::GetInstance().UseFunction("levelp2", 1);
		break;
	case MenuEvent::MenuEvents::Versus:
		SceneManager::GetInstance().UseFunction("levelvs", 1);
		break;
	}
	
}
