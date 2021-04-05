#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Subject.h"
dae::GameObject::~GameObject()
{
	for (std::pair<std::string, BaseComponent*> comp : m_Components)
	{
		delete comp.second;
	}
	delete m_pSubject;
}

void dae::GameObject::Update(const float& deltaTime)
{
	for(std::pair<std::string,BaseComponent*> comp : m_Components)
	{
		comp.second->Update(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (std::pair<std::string, BaseComponent*> comp : m_Components)
	{
		comp.second->Render();
	}
}

Subject* GameObject::GetSubject()
{
	return m_pSubject;
}



