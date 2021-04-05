#include "MiniginPCH.h"
#include "Lives.h"
#include "TextRenderComponent.h"

Lives::Lives(TextRenderComponent* text, int lives)
	:m_pText(text)
	,m_Lives(lives)
{
}

void Lives::OnNotify(Events event)
{
	switch (event)
	{
	case Events::Died:
		m_Lives--;
		if (m_Lives <= 0)
		{
			m_pText->SetText("Game Over");
			return;
		}
		m_pText->SetText("Lives: " + std::to_string(m_Lives));
		break;
	}
}
