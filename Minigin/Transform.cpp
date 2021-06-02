#include "MiniginPCH.h"
#include "Transform.h"

void Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

bool Transform::IsNearlyEqual(const Transform& otherTransform, float accuracy ) const
{
	return (abs(this->GetPosition().x - otherTransform.GetPosition().x) < accuracy) && (abs(this->GetPosition().y - otherTransform.GetPosition().y) < accuracy) && (abs(this->GetPosition().z - otherTransform.GetPosition().z) < accuracy);
}
