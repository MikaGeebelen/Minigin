#pragma once
#include "Move.h"
class HexGrid;
class MoveCommand;
class CoilyAIMove final: public Move
{
public:
	CoilyAIMove(HexGrid* pCurrentGrid, int x, int y,float moveTime = 0.5f);

	virtual ~CoilyAIMove();
	CoilyAIMove(const CoilyAIMove& other) = delete;
	CoilyAIMove(CoilyAIMove&& other) = delete;
	CoilyAIMove& operator=(const CoilyAIMove& other) = delete;
	CoilyAIMove& operator=(CoilyAIMove&& other) = delete;

	Transform UpdateMove(const float& deltaTime) override;

private:
	MoveCommand* m_pMoveCommand;
	HexGrid* m_pGrid;
	bool m_IsFalling = true;
};

