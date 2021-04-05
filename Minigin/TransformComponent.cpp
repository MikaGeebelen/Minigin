#include "MiniginPCH.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(GameObject* const parent, Transform* transform)
	:BaseComponent(parent)
	,m_pTransform(transform)
{
}

TransformComponent::TransformComponent(GameObject* const parent,const float& x, const float& y, const float& z)
	:BaseComponent(parent)
{
	m_pTransform = new Transform{};
	m_pTransform->SetPosition(x, y, z);
}

TransformComponent::~TransformComponent()
{
	delete m_pTransform;
}

void TransformComponent::Render()
{
}

void TransformComponent::Update(const float& )
{
}

void TransformComponent::SetPosition(const float& x, const float& y, const float& z)
{
	m_pTransform->SetPosition(x, y, z);
}

Transform* TransformComponent::GetTransform()
{
	return m_pTransform;
}
