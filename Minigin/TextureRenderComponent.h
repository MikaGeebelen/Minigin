#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include "Renderer.h"

class TextureRenderComponent :public BaseComponent
{
public:
	TextureRenderComponent(GameObject* const parent, std::string texturePath);
	~TextureRenderComponent();
	TextureRenderComponent(const TextureRenderComponent& other) = delete;
	TextureRenderComponent(TextureRenderComponent&& other) = delete;
	TextureRenderComponent& operator=(const TextureRenderComponent& other) = delete;
	TextureRenderComponent& operator=(TextureRenderComponent&& other) = delete;
	
	void Render() override;
	void Update(const float& deltaTime) override;

	void SetTexture(std::shared_ptr<Texture2D> texture);

private:
	Transform* m_pTransform;
	std::shared_ptr<Texture2D> m_pTexture;
};

