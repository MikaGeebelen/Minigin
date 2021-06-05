#pragma once
#include "Move.h"
class HexGrid;
class MoveCommand;
class FallDownMove final : public Move
{
public:
	FallDownMove(HexGrid* pCurrentGrid, int x, int y,float moveTime = 0.5f);
	
	virtual ~FallDownMove();
	FallDownMove(const FallDownMove& other) = delete;
	FallDownMove(FallDownMove&& other) = delete;
	FallDownMove& operator=(const FallDownMove& other) = delete;
	FallDownMove& operator=(FallDownMove&& other) = delete;
	
	Transform UpdateMove(const float& deltaTime) override;

private:
	MoveCommand* m_pMoveCommand;
	HexGrid* m_pGrid;
};

