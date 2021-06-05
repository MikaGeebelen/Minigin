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
			MoveCommand::MoveDir dir = MoveCommand::MoveDir::LUP;
			if (m_GoLeft)
			{
				if (rand() % 2)
				{
					dir = MoveCommand::MoveDir::LUP;
					m_pMoveCommand->changeDir(dir);
				}
				else
				{
					dir = MoveCommand::MoveDir::LDOWN;
					m_pMoveCommand->changeDir(dir);
				}
			}
			else
			{
				if (rand() % 2)
				{
					dir = MoveCommand::MoveDir::RUP;
					m_pMoveCommand->changeDir(dir);
				}
				else
				{
					dir = MoveCommand::MoveDir::RDOWN;
					m_pMoveCommand->changeDir(dir);
				}
			}
			glm::ivec2 pos =  m_pMoveCommand->GetCoords();
			m_pMoveCommand->Execute();
			m_IsMoving = true;
			if (m_pMoveCommand->GetNextLoc().IsNearlyEqual(Transform()))
			{
				if (dir == MoveCommand::MoveDir::LUP)
				{
					dir = MoveCommand::MoveDir::LDOWN;
				}
				else if (dir == MoveCommand::MoveDir::LDOWN)
				{
					dir = MoveCommand::MoveDir::LUP;
				}
				else if (dir == MoveCommand::MoveDir::RUP)
				{
					dir = MoveCommand::MoveDir::RDOWN;
				}
				else if (dir == MoveCommand::MoveDir::RDOWN)
				{
					dir = MoveCommand::MoveDir::RUP;
				}
				m_pMoveCommand->SetCoords(pos.x, pos.y);
				m_pMoveCommand->changeDir(dir);
				m_pMoveCommand->ResetLoc(m_pMoveCommand->GetCurrentLoc());
				m_pMoveCommand->Execute();
				if (m_pMoveCommand->GetNextLoc().IsNearlyEqual(Transform()))
				{
					m_CanMove = false;
				}
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
