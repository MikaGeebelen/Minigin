#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h"

#include "BaseScript.h"

#include "map"
#include "Subject.h"

namespace dae
{
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

		Subject* GetSubject();

	private:
		std::map<std::string, BaseComponent*> m_Components{};
		Subject* m_pSubject = new Subject();
	};

	template <class component>
	void GameObject::AddComponent(component* pComp)
	{
		static_assert(std::is_base_of<BaseComponent, component>::value, "The provided component does not derive from the BaseComponent Class");
		if (m_Components.find(typeid(pComp).name()) != m_Components.end())
		{
			assert("Component is added twice");
		}
		m_Components[typeid(pComp).name()] = pComp;
	}

	template <class component>
	component* GameObject::GetComponent()
	{
		if (m_Components.find(typeid(component*).name()) != m_Components.end())
		{
			return static_cast<component*>(m_Components.find(typeid(component*).name())->second);
		}
		else
		{
			assert("Component does not exist");
			return nullptr;
		}
	}
}
