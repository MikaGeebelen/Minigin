#pragma once
#include "Move.h"
class HexGrid;
class MoveCommand;
class SideFall final: public Move
{
public:
	SideFall(HexGrid* pCurrentGrid, int x, int y, bool IsGoingLeft, float moveTime = 0.5f);
	virtual ~SideFall();
	SideFall(const SideFall& other) = delete;
	SideFall(SideFall&& other) = delete;
	SideFall& operator=(const SideFall& other) = delete;
	SideFall& operator=(SideFall&& other) = delete;

	Transform UpdateMove(const float& deltaTime) override;

private:
	MoveCommand* m_pMoveCommand;
	HexGrid* m_pGrid;
	bool m_GoLeft;
};

