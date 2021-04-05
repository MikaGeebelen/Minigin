﻿#include "MiniginPCH.h"
#include "SubjectComponent.h"


#include "Observer.h"
#include "ObserverComponent.h"


SubjectComponent::SubjectComponent(GameObject* const parent)
	:BaseComponent(parent)
	,m_pObserevers{}
{
}

SubjectComponent::~SubjectComponent()
{
}

void SubjectComponent::AddObserver(ObserverComponent* obserever)
{
	m_pObserevers.push_back(obserever);
}

void SubjectComponent::RemoveObserver(ObserverComponent* obserever)
{
	std::vector<ObserverComponent*>::iterator it = std::find(m_pObserevers.begin(), m_pObserevers.end(), obserever);
	if (it != m_pObserevers.end())
	{
		m_pObserevers.erase(it);
	}
}

void SubjectComponent::Notify(Observer::Events event)
{
	for (ObserverComponent* observer : m_pObserevers)
	{
		observer->OnNotify(event);
	}
}

void SubjectComponent::Render()
{
}

void SubjectComponent::Update(const float& )
{
}