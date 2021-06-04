#pragma once
#include <imguiMenu.h>
#include <string>
class MainMenu final: public imguiMenu
{
public:
	MainMenu();
	void render() override;

	const std::string& GetGameMode();
	bool GetIsGameModeSelected();
private:
	std::string m_GameMode;
	bool m_SelectedGameMode;
};

