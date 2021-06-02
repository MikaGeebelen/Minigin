#pragma once
#include "Move.h"
class HexGrid;
class MoveCommand;
class FallDownMove final : public Move
{
public:
	FallDownMove(HexGrid* pCurrentGrid, int x, int y);
	Transform UpdateMove(const float& deltaTime) override;

private:
	MoveCommand* m_pMoveCommand;
};

