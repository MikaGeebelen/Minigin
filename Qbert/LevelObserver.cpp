#include "LevelObserver.h"
#include "LevelEvent.h"

#include "SceneManager.h"
#include "GameManager.h"

LevelObserver::LevelObserver(int level, int lives, const std::string& gameMode)
	:m_level(level)
	,m_Lives(lives)
	,m_GameMode(gameMode)
{
}


void LevelObserver::OnNotify(Event* event)
{
	switch ((LevelEvent::LevelEvents)event->GetEvent())
	{
	case LevelEvent::LevelEvents::LevelFinished:
		m_level++;
		m_Lives++;
		GameManager::GetInstance().IncreaseScore(50);
		GameManager::GetInstance().Reset();
		GameManager::GetInstance().SetLives(m_Lives);
		GameManager::GetInstance().SetLevel(m_level);
		SceneManager::GetInstance().UseFunction(m_GameMode, m_level);
		break;
	case LevelEvent::LevelEvents::LostLife:
		m_Lives--;
		if (m_Lives == 0)
		{
			m_level = 1;
			GameManager::GetInstance().Reset();
			GameManager::GetInstance().SetLevel(m_level);
			GameManager::GetInstance().SetScore(0);
			GameManager::GetInstance().SetLives(3);
			SceneManager::GetInstance().UseFunction("menu", 1);
		}
		else
		{
			GameManager::GetInstance().Reset();
			GameManager::GetInstance().SetLives(m_Lives);
			SceneManager::GetInstance().UseFunction(m_GameMode, m_level);
		}
		break;
	}
}
