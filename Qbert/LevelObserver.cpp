#include "LevelObserver.h"
#include "LevelEvent.h"

#include "SceneManager.h"

LevelObserver::LevelObserver(int level, const std::string& gameMode)
	:m_level(level)
	,m_GameMode(gameMode)
{
}


void LevelObserver::OnNotify(Event* event)
{
	switch ((LevelEvent::LevelEvents)event->GetEvent())
	{
	case LevelEvent::LevelEvents::GameOver:
		m_level = 1;
		SceneManager::GetInstance().UseFunction(m_GameMode, 1);
		break;
	case LevelEvent::LevelEvents::LevelFinished:
		m_level++;
		SceneManager::GetInstance().UseFunction(m_GameMode, m_level);
		break;
	case LevelEvent::LevelEvents::LostLife:
		SceneManager::GetInstance().UseFunction(m_GameMode, m_level);
		break;
	}
}
