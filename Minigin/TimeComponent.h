#pragma once
#include "BaseComponent.h"
class TextRenderComponent;
class TimeComponent :public BaseComponent
{
public:
	TimeComponent(GameObject* const parent, bool renderFPS);
	~TimeComponent();
	TimeComponent(const TimeComponent& other) = delete;
	TimeComponent(TimeComponent&& other) = delete;
	TimeComponent& operator=(const TimeComponent& other) = delete;
	TimeComponent& operator=(TimeComponent&& other) = delete;

	int GetFPS();
	
	void Update(const float& deltaTime) override;
	void Render() override;
private:
	float m_DeltaTime;
	TextRenderComponent* m_pText;
	bool m_RenderFPS;
};

