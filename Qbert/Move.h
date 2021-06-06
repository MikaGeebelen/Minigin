#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)

class Transform;
class Move
{
public:
	Move(int x, int y, float moveTime = 0.5f);
	virtual ~Move() = default;
	Move(const Move& other) = delete;
	Move(Move&& other) = delete;
	Move& operator=(const Move& other) = delete;
	Move& operator=(Move&& other) = delete;
	
	virtual Transform UpdateMove(const float& deltaTime) = 0;
	virtual glm::ivec2 GetGridPos();
	virtual bool GetCanMove();
	virtual bool GetIsMoving();
protected:
	const float m_MaxMoveTime = 0.5f;
	float m_MoveTime = 0.f;
	bool m_IsMoving = false;
	bool m_CanMove = true;

	glm::ivec2 m_GridPos;
	
	Transform LerpPos(glm::vec3 current, glm::vec3 next);
};


