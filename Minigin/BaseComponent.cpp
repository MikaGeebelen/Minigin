#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"

BaseComponent::BaseComponent(dae::GameObject* const parent)
	:m_pParent(parent)
{
}

BaseComponent::~BaseComponent()
{
}
