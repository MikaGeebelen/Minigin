#pragma once
#include "Move.h"
#include <vector>
class HexGrid;
class MoveCommand;
class CoilyPlayerMove final : public Move
{
public:
	CoilyPlayerMove(int playerNum,HexGrid* pCurrentGrid, int x, int y, float moveTime = 0.5f);

	virtual ~CoilyPlayerMove();
	CoilyPlayerMove(const CoilyPlayerMove& other) = delete;
	CoilyPlayerMove(CoilyPlayerMove&& other) = delete;
	CoilyPlayerMove& operator=(const CoilyPlayerMove& other) = delete;
	CoilyPlayerMove& operator=(CoilyPlayerMove&& other) = delete;

	Transform UpdateMove(const float& deltaTime) override;

private:
	std::vector<MoveCommand*> m_MoveCommands;
	MoveCommand* m_pMoveCommand;
	HexGrid* m_pGrid;
	int m_ActiveMoveCommand;
	bool m_IsFalling = true;

	void SetMovementActive(bool enable);
	void ResetCommands(Transform newPos);
};

