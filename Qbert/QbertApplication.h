#pragma once
#include <Minigin.h>
class HexGrid;
class scene;
struct lua_State;
class QbertApplication : public Minigin
{
public:
	void UserInitialize() override;
	void UserLoadGame() const override;
	void UserCleanup() override;
};




