#include "Move.h"
#include <Transform.h>

#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/gtx/compatibility.hpp"
#pragma warning(pop)

Move::Move(int x,int y)
	:m_GridPos(x,y)
{
}

glm::ivec2 Move::GetGridPos()
{
	return m_GridPos;
}

Transform Move::LerpPos(glm::vec3 current, glm::vec3 next)
{
	Transform newPos{};
	Transform nextPos{};
	nextPos.SetPosition(next.x, next.y, next.z);

	float newX = glm::lerp(current.x, next.x, m_MoveTime / m_MaxMoveTime);
	float newY = glm::lerp(current.y, next.y, m_MoveTime / m_MaxMoveTime);
	float newZ = glm::lerp(current.z, next.z, m_MoveTime / m_MaxMoveTime);

	newPos.SetPosition(newX, newY, newZ);

	if (m_MoveTime > m_MaxMoveTime)
	{
		m_MoveTime = 0;
		m_IsMoving = false;
	}

	return newPos;
}
