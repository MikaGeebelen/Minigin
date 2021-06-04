#include "MainMenu.h"

#include "imgui-master/imgui.h"
#include "imgui-master/backends/imgui_impl_sdl.h"
#include "imgui-master/backends/imgui_impl_opengl2.h"

MainMenu::MainMenu()
	:m_GameMode("")
	,m_SelectedGameMode(false)
{
}

void MainMenu::render()
{
	if (!m_SelectedGameMode)
	{
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplSDL2_NewFrame(m_pWindow);
		ImGui::NewFrame();


		if (ImGui::Button("single player"))
		{
			m_SelectedGameMode = true;
			m_GameMode = "levelp1";
		}

		if (ImGui::Button("co-op"))
		{
			m_SelectedGameMode = true;
			m_GameMode = "levelp2";
		}

		if (ImGui::Button("versus"))
		{
			m_SelectedGameMode = true;
			m_GameMode = "levelvs";
		}

		ImGui::Render();
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	}
}

const std::string& MainMenu::GetGameMode()
{
	return m_GameMode;
}

bool MainMenu::GetIsGameModeSelected()
{
	return m_SelectedGameMode;
}
