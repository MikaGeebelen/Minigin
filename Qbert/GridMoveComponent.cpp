#include "GridMoveComponent.h"

#include "GameObject.h"
#include "HexGrid.h"
#include "Move.h"
#include "SubjectComponent.h"
#include "LevelEvent.h"

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

	glm::ivec2 pos = m_pMovementType->GetGridPos();
	if (m_X != pos.x || m_Y != pos.y)
	{
		m_pObjectGrid->SetOccupied(m_X, m_Y, HexGrid::CharacterType::Empty);
		m_X = pos.x;
		m_Y = pos.y;

		
		if (m_CanChangeBlocks)
		{
			m_pObjectGrid->TouchTile(pos.x, pos.y, !m_IncreaseBlocks);
		}

		HexGrid::CharacterType type;
		if (m_CanChangeBlocks && m_IncreaseBlocks)
		{
			type = HexGrid::CharacterType::Player;

		}
		else if (m_CanChangeBlocks && !m_IncreaseBlocks)
		{
			type = HexGrid::CharacterType::KillableEnemy;
		}
		else
		{
			type = HexGrid::CharacterType::Enemy;
		}

		HexGrid::CharacterType typeOnTile = m_pObjectGrid->GetIsTileOccupied(m_X, m_Y);
		m_pObjectGrid->SetOccupied(m_X, m_Y, type);
		

		switch (typeOnTile)
		{
		case HexGrid::CharacterType::Player:
			if (type == HexGrid::CharacterType::Enemy)
			{
				m_pObjectGrid->GetSubject()->Notify(new LevelEvent(LevelEvent::LevelEvents::LostLife)); //reset map
			}
			else if (type == HexGrid::CharacterType::KillableEnemy)
			{
				m_pParent->GetComponent<SubjectComponent>(); //add points
			}
			break;
		case HexGrid::CharacterType::KillableEnemy:
			m_pParent->GetComponent<SubjectComponent>(); // add points
			break;
		case HexGrid::CharacterType::Enemy:
			if (type == HexGrid::CharacterType::Player)
			{
				m_pObjectGrid->GetSubject()->Notify(new LevelEvent(LevelEvent::LevelEvents::LostLife)); //reset map
			}
			break;
		}


	}

}

