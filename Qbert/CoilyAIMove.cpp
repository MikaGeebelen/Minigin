#include "CoilyAIMove.h"
#include "HexGrid.h"
#include "MoveCommand.h"
CoilyAIMove::CoilyAIMove(HexGrid* pCurrentGrid, int x, int y, float moveTime )
	:Move(x,y, moveTime)
	,m_pGrid(pCurrentGrid)
{
	m_pMoveCommand = new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y);
}

CoilyAIMove::~CoilyAIMove()
{
	delete m_pMoveCommand;
	m_pMoveCommand = nullptr;
}

Transform CoilyAIMove::UpdateMove(const float& deltaTime)
{
	if (m_IsFalling)
	{
		if (m_pMoveCommand->GetCurrentLoc().IsNearlyEqual(m_pMoveCommand->GetNextLoc()))
		{
			if (rand() % 2)
			{
				m_pMoveCommand->changeDir(MoveCommand::MoveDir::LDOWN);
			}
			else
			{
				m_pMoveCommand->changeDir(MoveCommand::MoveDir::RDOWN);
			}
			m_pMoveCommand->Execute();
			m_IsMoving = true;
			if (m_pMoveCommand->GetNextLoc().IsNearlyEqual(Transform()))
			{
				m_pMoveCommand->ResetLoc(m_pMoveCommand->GetCurrentLoc());
				m_IsFalling = false;
			}
		}
	}
	else
	{
		if (m_pMoveCommand->GetCurrentLoc().IsNearlyEqual(m_pMoveCommand->GetNextLoc()))
		{
			glm::ivec2 playerPos = m_pGrid->GetClosestPlayerLoc(m_GridPos.x, m_GridPos.y);
			if (playerPos.x > m_GridPos.x)
			{
				if (playerPos.y > m_GridPos.y)
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::LDOWN);
				}
				else
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::RDOWN);
				}
			}
			else if (playerPos.x <= m_GridPos.x)
			{
				if (playerPos.y >= m_GridPos.y)
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::LUP);
				}
				else
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::RUP);
				}
			}
			m_pMoveCommand->Execute();
			m_IsMoving = true;
		}
	}
	if (!m_IsMoving)
	{
		return  m_pMoveCommand->GetCurrentLoc();
	}
	else
	{
		m_MoveTime += deltaTime;
		Transform temp = LerpPos(m_pMoveCommand->GetCurrentLoc().GetPosition(), m_pMoveCommand->GetNextLoc().GetPosition());

		if (!m_IsMoving)
		{
			m_pMoveCommand->ResetLoc(m_pMoveCommand->GetNextLoc());
			m_GridPos = m_pMoveCommand->GetCoords();
			m_pMoveCommand->SetCoords(m_GridPos.x, m_GridPos.y);
		}

		return temp;
	}
}
