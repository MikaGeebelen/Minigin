#pragma once
#include "Transform.h"

class GameObject;
class BaseComponent
{
public:
	BaseComponent(GameObject* const parent, bool const isRenderable = false, bool const isUpadatable = false);
	virtual ~BaseComponent() = 0;
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(BaseComponent&& other) = delete;
	
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render() = 0;

	bool GetIsRenderable();
	bool GetIsUpdatable();
	
	GameObject* m_pParent;
protected:
	bool m_IsRenderable;
	bool m_IsUpdatable;
};




