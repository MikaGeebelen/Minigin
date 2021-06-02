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
	PlayerMove(const std::string& playerPrefix,HexGrid* pCurrentGrid);
	Transform UpdateMove(const float& deltaTime) override;
	glm::ivec2 GetGridPos();

private:
	std::vector<MoveCommand*> m_MoveCommands;
	bool m_IsMoving;
	int m_ActiveMoveCommand;

	const float m_MaxMoveTime;
	float m_MoveTime;
	glm::ivec2 m_GridPos;

	void SetMovementActive(bool enable);
	void ResetCommands(Transform newPos);
	Transform LerpPos();
};

