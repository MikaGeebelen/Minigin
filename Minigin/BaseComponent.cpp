#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"

BaseComponent::BaseComponent(GameObject* const parent,bool const isRenderable, bool const isUpadatable)
	:m_pParent(parent)
	,m_IsRenderable(isRenderable)
	,m_IsUpdatable(isUpadatable)
{
}

BaseComponent::~BaseComponent()
{
}

bool BaseComponent::GetIsRenderable()
{
	return m_IsRenderable;
}

bool BaseComponent::GetIsUpdatable()
{
	return m_IsUpdatable;
}
