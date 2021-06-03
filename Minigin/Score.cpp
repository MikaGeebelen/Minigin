#include "MiniginPCH.h"
#include "Score.h"
#include "TextRenderComponent.h"
#include "Event.h"
Score::Score(TextRenderComponent* text, int score)
	:m_pText(text)
	,m_Score(score)
{
}

void Score::OnNotify(Event* event)
{
	switch (event->GetEvent())
	{
	case 0:
		m_Score += 500;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	}

}
