#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Subject.h"
dae::GameObject::~GameObject()
{
	for (BaseComponent* component : m_Components)
	{
		delete component;
	}
	delete m_pSubject;
}

void dae::GameObject::Update(const float& deltaTime)
{
	for (BaseComponent* component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (BaseComponent* component : m_Components)
	{
		component->Render();
	}
}

Subject* GameObject::GetSubject()
{
	return m_pSubject;
}



