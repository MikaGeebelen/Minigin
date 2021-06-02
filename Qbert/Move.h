#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)

class Transform;
class Move
{
public:
	Move();
	virtual Transform UpdateMove(const float& deltaTime) = 0;
	virtual glm::ivec2 GetGridPos() = 0;
};


