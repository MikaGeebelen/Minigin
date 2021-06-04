#include "FallDownMove.h"

#include "HexGrid.h"
#include "MoveCommand.h"

FallDownMove::FallDownMove(HexGrid* pCurrentGrid, int x, int y)
	:Move(x, y)
	,m_pGrid(pCurrentGrid)
{
	m_pMoveCommand = new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN,m_GridPos.x,m_GridPos.y);
}

FallDownMove::~FallDownMove()
{
	delete m_pMoveCommand;
	m_pMoveCommand = nullptr;
}

Transform FallDownMove::UpdateMove(const float& deltaTime)
{
	if (m_CanMove)
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
