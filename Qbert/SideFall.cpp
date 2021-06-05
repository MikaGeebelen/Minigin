#include "SideFall.h"

#include "HexGrid.h"
#include "MoveCommand.h"

SideFall::SideFall(HexGrid* pCurrentGrid, int x, int y, bool IsGoingLeft, float moveTime)
	:Move(x, y, moveTime)
	,m_pGrid(pCurrentGrid)
	,m_GoLeft(IsGoingLeft)
{
	m_pMoveCommand = new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y);
}

SideFall::~SideFall()
{
	delete m_pMoveCommand;
	m_pMoveCommand = nullptr;
}

Transform SideFall::UpdateMove(const float& deltaTime)
{
	if (m_CanMove)
	{
		if (m_pMoveCommand->GetCurrentLoc().IsNearlyEqual(m_pMoveCommand->GetNextLoc()))
		{

			if (m_GoLeft)
			{
				if (rand() % 2)
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::LUP);
				}
				else
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::LDOWN);
				}
			}
			else
			{
				if (rand() % 2)
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::RUP);
				}
				else
				{
					m_pMoveCommand->changeDir(MoveCommand::MoveDir::RDOWN);
				}
			}

			m_pMoveCommand->Execute();
			m_IsMoving = true;
			if (m_pMoveCommand->GetNextLoc().IsNearlyEqual(Transform()))
			{
				m_pMoveCommand->ResetLoc(m_pMoveCommand->GetCurrentLoc());
				m_CanMove = false;
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
	else
	{
		return m_pMoveCommand->GetCurrentLoc();
	}
}
