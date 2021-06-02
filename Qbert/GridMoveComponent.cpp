#include "GridMoveComponent.h"
#include "HexGrid.h"
#include "Move.h"

GridMoveComponent::GridMoveComponent(GameObject* const parent, HexGrid* pGrid, Move* pMovement, Transform* pObjectPos,int x,int y)
	:BaseComponent(parent,false,true)
	,m_pObjectGrid(pGrid)
	,m_pMovementType(pMovement)
	,m_pPosition(pObjectPos)
	,m_X(x)
	,m_Y(y)
{
	*m_pPosition = m_pObjectGrid->GetGridPosition(m_X, m_Y);
}

void GridMoveComponent::Render()
{
}

void GridMoveComponent::Update(const float& deltaTime)
{
	*m_pPosition = m_pMovementType->UpdateMove(deltaTime);
	glm::ivec2 pos = m_pMovementType->GetGridPos();
	if (m_X != pos.x || m_Y != pos.y)
	{
		m_X = pos.x;
		m_Y = pos.y;
		m_pObjectGrid->QbertTouch(pos.x, pos.y);
	}
}

