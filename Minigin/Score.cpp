#include "MiniginPCH.h"
#include "Score.h"

Score::Score(TextRenderComponent* text, int score)
	:m_pText(text)
	,m_Score(score)
{
}

void Score::OnNotify(Event event)
{
	switch (event)
	{
	case Event::coily:
		m_Score += 500;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	case Event::disc:
		m_Score += 50;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	case Event::tile:
		m_Score += 25;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	case Event::slick:
	case Event::sam:
		m_Score += 300;
		m_pText->SetText("Score: " + std::to_string(m_Score));
		break;
	}
}
