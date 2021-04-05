#include "MiniginPCH.h"
#include "TimeComponent.h"

#include "GameObject.h"
#include "BaseComponent.h"
#include "TextRenderComponent.h"

TimeComponent::TimeComponent(dae::GameObject* const parent,bool renderFPS)
	:BaseComponent(parent)
	,m_RenderFPS(renderFPS)
	,m_DeltaTime(0)
{
	if (renderFPS)
	{
		m_pText = parent->GetComponent<TextRenderComponent>();
		if (m_pText == nullptr)
		{
			std::cout << "To render the fps a textrendercomponent is required";
			m_RenderFPS = false;
		}
	}
}

TimeComponent::~TimeComponent()
{
}

int TimeComponent::GetFPS()
{
	return int(1.0f / m_DeltaTime);
}

void TimeComponent::Update(const float& deltaTime)
{
	m_DeltaTime = deltaTime;
	if (m_RenderFPS )
	{
		std::string fpsText{};
		fpsText = std::to_string(GetFPS()) + " FPS";
		m_pText->SetText(fpsText);
	}
}

void TimeComponent::Render()
{
}
