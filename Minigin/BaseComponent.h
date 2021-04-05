#pragma once
#include "Transform.h"

namespace dae
{
	class GameObject;
}


class BaseComponent
{
public:
	BaseComponent(dae::GameObject* const parent);
	virtual ~BaseComponent() = 0;
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(BaseComponent&& other) = delete;
	
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render() = 0;

	dae::GameObject* m_pParent;
};




