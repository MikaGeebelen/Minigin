#pragma once
#include <Command.h>
class HexGrid;
class MoveCommand final :public Command
{
public:
	enum class MoveDir
	{
		RUP,
		RDOWN,
		LUP,
		LDOWN
	};
	
	MoveCommand(HexGrid* currentGrid,MoveDir dir, int x = 0,int y = 0);
	void changeDir(MoveDir newDir);
	void SetCanMove(bool canMove);

	const Transform& GetCurrentLoc();
	const Transform& GetNextLoc();
	glm::ivec2 GetCoords();
	void SetCoords(int x, int y);
	
	void ResetLoc(const Transform& setPos);
	
	void Execute() override;
private:
	int m_X;//current location
	int m_Y;
	HexGrid* m_pObjectGrid;
	MoveDir m_MoveDir;

	bool m_CanMove;
	Transform m_CurrentLoc;
	Transform m_NewLoc;
};

