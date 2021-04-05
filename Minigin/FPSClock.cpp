#include "MiniginPCH.h"
#include "FPSClock.h"

#include "GameObject.h"

FPSClock::FPSClock(dae::GameObject* const parent)
	:BaseScript(parent)
	,m_Time(0.f)
{
	m_pText = parent->GetComponent<TextRenderComponent>();
	m_pTime = parent->GetComponent<TimeComponent>();
}

FPSClock::~FPSClock()
{
}

void FPSClock::Update(const float& deltaTime)
{


}
