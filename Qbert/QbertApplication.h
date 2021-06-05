#pragma once
#include <Minigin.h>
#include <string>
class HexGrid;
class scene;
struct lua_State;
class QbertApplication : public Minigin
{
public:
	void UserInitialize() override;
	void UserLoadGame() const override;
	void UserCleanup() override;
	void GameUpdate(const float& deltaTime) override;
	
	void StartGame(const std::string& gameMode) const;

};




