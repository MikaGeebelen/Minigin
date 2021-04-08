#include "MiniginPCH.h"
#include "Command.h"
#include "TextureRenderComponent.h"
#include "Texture2D.h"
void CycleThroughMenu::Execute()
{
	m_pMenu->SetTexture(m_Pictures[m_CurrentPicture]);
	if (m_CyclesUp)
	{
		m_CurrentPicture++;
	}
	else
	{
		m_CurrentPicture--;
	}

	if (m_CurrentPicture >= m_Pictures.size())
	{
		m_CurrentPicture = 0;
	}
	else if (m_CurrentPicture <= 0)
	{
		m_CurrentPicture = m_Pictures.size() - 1;
	}
}
