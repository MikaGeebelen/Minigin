#include "MiniginPCH.h"
#include "imguiMenu.h"

imguiMenu::~imguiMenu()
{
}

void imguiMenu::AddWindow(SDL_Window* pWindow)
{
	m_pWindow = pWindow;
}

