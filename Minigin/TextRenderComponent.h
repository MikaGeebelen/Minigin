#pragma once
#include "BaseComponent.h"
#include "Font.h"
#include "Texture2D.h"
#include "Renderer.h"

class TextRenderComponent : public BaseComponent
{
public:
	TextRenderComponent(GameObject* const parent, std::string text, const std::shared_ptr<Font>& font);
	~TextRenderComponent();
	TextRenderComponent(const TextRenderComponent& other) = delete;
	TextRenderComponent(TextRenderComponent&& other) = delete;
	TextRenderComponent& operator=(const TextRenderComponent& other) = delete;
	TextRenderComponent& operator=(TextRenderComponent&& other) = delete;
	
	void Render() override;
	void Update(const float& deltaTime) override;
	
	void SetText(const std::string& text);
	const std::string& GetText();

private:
	std::string m_Text;
	Transform* m_pTransform;
	std::shared_ptr<Font> m_Font;
	std::shared_ptr<Texture2D> m_Texture;
};

