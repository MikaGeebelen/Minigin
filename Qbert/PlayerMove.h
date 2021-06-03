#pragma once

#include "Move.h"
#include "string"
#include "vector"
class HexGrid;
class MoveCommand;
class Transform;

class PlayerMove final : public Move
{
public:
	PlayerMove(int playerNum,HexGrid* pCurrentGrid, int x, int y);
	Transform UpdateMove(const float& deltaTime) override;

private:
	std::vector<MoveCommand*> m_MoveCommands;
	HexGrid* m_pGrid;
	int m_ActiveMoveCommand;

	void SetMovementActive(bool enable);
	void ResetCommands(Transform newPos);
};

