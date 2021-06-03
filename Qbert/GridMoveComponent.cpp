#include "GridMoveComponent.h"
#include "HexGrid.h"
#include "Move.h"

GridMoveComponent::GridMoveComponent(GameObject* const parent, HexGrid* pGrid, Move* pMovement, Transform* pObjectPos,int x,int y,bool changeBlocks ,bool increaseBlocks )
	:BaseComponent(parent,false,true)
	,m_pObjectGrid(pGrid)
	,m_pMovementType(pMovement)
	,m_pPosition(pObjectPos)
	,m_X(x)
	,m_Y(y)
	,m_CanChangeBlocks(changeBlocks)
	,m_IncreaseBlocks(increaseBlocks)
{
}

GridMoveComponent::~GridMoveComponent()
{
	delete m_pMovementType;
}

void GridMoveComponent::Render()
{
}

void GridMoveComponent::Update(const float& deltaTime)
{
	*m_pPosition = m_pMovementType->UpdateMove(deltaTime);
	if (m_CanChangeBlocks)
	{
		glm::ivec2 pos = m_pMovementType->GetGridPos();
		if (m_X != pos.x || m_Y != pos.y)
		{
			m_X = pos.x;
			m_Y = pos.y;
			m_pObjectGrid->TouchTile(pos.x, pos.y, !m_IncreaseBlocks);
		}
	}
}

