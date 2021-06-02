#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)


class Transform final
{
public:
	const glm::vec3& GetPosition() const { return m_Position; }
	void SetPosition(float x, float y, float z);

	bool IsNearlyEqual(const Transform& otherTransform, float accuracy = 1.0f) const;
private:
	glm::vec3 m_Position;
};

