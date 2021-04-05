#include "MiniginPCH.h"
#include "Lives.h"

Lives::Lives(TextRenderComponent* text, int lives)
	:m_pText(text)
	,m_Lives(lives)
{
}

void Lives::OnNotify(Event event)
{
	if (event == Event::died)
	{
		m_Lives--;
		if (m_Lives <= 0)
		{
			m_pText->SetText("Game Over");
			return;
		}
		m_pText->SetText("Lives: " + std::to_string(m_Lives));
	}
}
