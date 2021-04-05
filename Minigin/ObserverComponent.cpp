#include "MiniginPCH.h"
#include "ObserverComponent.h"

ObserverComponent::ObserverComponent(GameObject* const parent, Observer* observer)
	:BaseComponent(parent)
	,m_pObserver(observer)
{
}

ObserverComponent::~ObserverComponent()
{
	delete m_pObserver;
}

void ObserverComponent::OnNotify(Observer::Events event)
{
	m_pObserver->OnNotify(event);
}

void ObserverComponent::Render()
{
}

void ObserverComponent::Update(const float& )
{
}
