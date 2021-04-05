#include "MiniginPCH.h"
#include "TextRenderComponent.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "GameObject.h"
#include "TransformComponent.h"

TextRenderComponent::TextRenderComponent(GameObject* const parent, std::string text, const std::shared_ptr<Font>& font)
	:BaseComponent(parent,true)
	,m_Font(font)
	,m_Texture(nullptr)
    ,m_pTransform(nullptr)
{
	SetText(text);
	if (parent->GetComponent<TransformComponent>() == nullptr)
	{
		std::string tep = typeid(TransformComponent).name();
		assert("GameObject needs a transform component to be able to use a TextRenderComponent");
	}
	m_pTransform = parent->GetComponent<TransformComponent>()->GetTransform();
	
}

TextRenderComponent::~TextRenderComponent()
{
}

void TextRenderComponent::Render()
{
	if (m_Texture != nullptr)
	{
		const auto pos = m_pTransform->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void TextRenderComponent::Update(const float& )
{
}

void TextRenderComponent::SetText(const std::string& text)
{
	m_Text = text;
	
	const SDL_Color color = { 255,255,255 }; // only white text is supported now
	const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
	if (surf == nullptr)
	{
		throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
	}
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	if (texture == nullptr)
	{
		throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
	}
	SDL_FreeSurface(surf);
	m_Texture = std::make_shared<Texture2D>(texture);
}

const std::string& TextRenderComponent::GetText()
{
	return m_Text;
}
