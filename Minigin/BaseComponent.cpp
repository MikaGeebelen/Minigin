#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"

BaseComponent::BaseComponent(GameObject* const parent)
	:m_pParent(parent)
{
}

BaseComponent::~BaseComponent()
{
}
