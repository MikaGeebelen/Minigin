#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)

class Transform;
class Move
{
public:
	Move(int x, int y);
	virtual Transform UpdateMove(const float& deltaTime) = 0;
	virtual glm::ivec2 GetGridPos();
protected:
	const float m_MaxMoveTime = 0.5f;
	float m_MoveTime = 0.f;
	bool m_IsMoving = false;

	glm::ivec2 m_GridPos;
	
	Transform LerpPos(glm::vec3 current, glm::vec3 next);
};


