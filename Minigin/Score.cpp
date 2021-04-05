#include "MiniginPCH.h"
#include "Score.h"
#include "TextRenderComponent.h"

Score::Score(TextRenderComponent* text, int score)
	:m_pText(text)
	,m_Score(score)
{
}

void Score::OnNotify(Events event)
{
	switch (event)
	{
	case Events::Coily:
		m_Score += 500;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	}

}
