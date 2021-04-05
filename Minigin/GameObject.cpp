#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Subject.h"
GameObject::~GameObject()
{
	for (BaseComponent* component : m_Components)
	{
		delete component;
	}
	delete m_pSubject;
}

void GameObject::Update(const float& deltaTime)
{
	for (BaseComponent* component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void GameObject::Render() const
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



