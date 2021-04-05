#include "MiniginPCH.h"
#include "TextureRenderComponent.h"

#include "GameObject.h"
#include "TransformComponent.h"
#include "ResourceManager.h"
TextureRenderComponent::TextureRenderComponent(dae::GameObject* const parent, std::string texturePath)
	:BaseComponent(parent)
	, m_pTexture(nullptr)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(texturePath);
	
	if (parent->GetComponent<TransformComponent>() == nullptr)
	{
		std::string tep = typeid(TransformComponent).name();
		assert("GameObject needs a transform component to be able to use a TextRenderComponent");
	}
	m_pTransform = parent->GetComponent<TransformComponent>()->GetTransform();
}

TextureRenderComponent::~TextureRenderComponent()
{
}

void TextureRenderComponent::Render()
{
	if (m_pTexture != nullptr)
	{
		const auto pos = m_pTransform->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void TextureRenderComponent::Update(const float& deltaTime)
{
	deltaTime;
}

void TextureRenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_pTexture = texture;
}

