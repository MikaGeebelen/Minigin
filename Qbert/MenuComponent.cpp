#include "MenuComponent.h"

#include "GameObject.h"
#include "MainMenu.h"

#include "SubjectComponent.h"
#include "MenuEvent.h"

MenuComponent::MenuComponent(GameObject* const parent, MainMenu* pMenu)
	:BaseComponent(parent,false,true)
	,m_pMenu(pMenu)
{
}

void MenuComponent::Render()
{
}

void MenuComponent::Update(const float& )
{
	if (m_pMenu->GetIsGameModeSelected())
	{
		std::string gameMode = m_pMenu->GetGameMode();
		if (gameMode == "levelp1")
		{
			m_pParent->GetComponent<SubjectComponent>()->Notify(new MenuEvent(MenuEvent::MenuEvents::Singleplayer));
		}
		else if (gameMode == "levelp2")
		{
			m_pParent->GetComponent<SubjectComponent>()->Notify(new MenuEvent(MenuEvent::MenuEvents::MultiPlayer));
		}
		else if (gameMode == "levelvs")
		{
			m_pParent->GetComponent<SubjectComponent>()->Notify(new MenuEvent(MenuEvent::MenuEvents::Versus));
		}			

	}
	
}
