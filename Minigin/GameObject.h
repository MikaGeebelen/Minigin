#pragma once
#include "Transform.h"
#include "BaseComponent.h"
#include "TransformComponent.h"

#include "BaseScript.h"
#include "map"

class Texture2D;
class GameObject final
{
public:
	GameObject() = default;
	virtual ~GameObject();
	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

	virtual void Update(const float& deltaTime) final;
	virtual void Render() const final;

	template<class component> void AddComponent(component* comp);
	template<class component> component* GetComponent();

	template<class component> std::vector<component*> GetComponents();

private:
	std::vector<BaseComponent*> m_Components{};
};

template <class component>
void GameObject::AddComponent(component* pComp)
{
	static_assert(std::is_base_of<BaseComponent, component>::value, "The provided component does not derive from the BaseComponent Class");
	m_Components.push_back(pComp);
}

template <class component>
component* GameObject::GetComponent()
{
	for (size_t i = 0; i < m_Components.size(); i++ )
	{
		component* pComponent = dynamic_cast<component*>(m_Components[i]);
		if (pComponent != nullptr)
		{
			return pComponent;
		}
	}
	return nullptr;
}

template <class component>
std::vector<component*> GameObject::GetComponents()
{
	std::vector<component*> components{};
	for (int i = 0; i < m_Components.size(); i++)
	{
		component* pComponent = dynamic_cast<component*>(m_Components[i]);
		if (pComponent != nullptr)
		{
			components.push_back(pComponent);
		}
	}
	return components;
}

