#pragma once
#include "BaseScript.h"

#include "TextRenderComponent.h"
#include "TimeComponent.h"
class FPSClock : public BaseScript
{
public:
	FPSClock(dae::GameObject* const parent);
	~FPSClock();
	FPSClock(const FPSClock& other) = delete;
	FPSClock(FPSClock&& other) = delete;
	FPSClock& operator=(const FPSClock& other) = delete;
	FPSClock& operator=(FPSClock&& other) = delete;

	void Update(const float& deltaTime) override;

private:
	TimeComponent* m_pTime;
	TextRenderComponent* m_pText;
	float m_Time;
};

