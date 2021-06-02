#include "MoveCommand.h"
#include "HexGrid.h"

MoveCommand::MoveCommand(HexGrid* currentGrid, MoveDir dir, int x, int y)
	:m_MoveDir(dir)
	,m_X(x)
	,m_Y(y)
	,m_pObjectGrid(currentGrid)
	,m_CanMove(true)
{
	m_CurrentLoc = m_pObjectGrid->GetGridPosition(x, y);
	m_NewLoc = m_CurrentLoc;
}

void MoveCommand::changeDir(MoveDir newDir)
{
	m_MoveDir = newDir;
}

void MoveCommand::SetCanMove(bool canMove)
{
	m_CanMove = canMove;
}

const Transform& MoveCommand::GetCurrentLoc()
{
	return m_CurrentLoc;
}

const Transform& MoveCommand::GetNextLoc()
{
	return m_NewLoc;
}

glm::ivec2 MoveCommand::GetCoords()
{
	return glm::ivec2(m_X,m_Y);
}

void MoveCommand::SetCoords(int x, int y)
{
	m_X = x;
	m_Y = y;
}

void MoveCommand::ResetLoc(const Transform& setPos)
{
	m_NewLoc = setPos;
	m_CurrentLoc = setPos;
}

void MoveCommand::Execute()
{
	if (m_CanMove)
	{
		switch (m_MoveDir)
		{
		case MoveDir::RUP:
			m_X--;
			m_Y--;
			break;
		case MoveDir::RDOWN:
			m_X++;
			break;
		case MoveDir::LDOWN:
			m_X++;
			m_Y++;
			break;
		case MoveDir::LUP:
			m_X--;
			break;
		}

		m_NewLoc = m_pObjectGrid->GetGridPosition(m_X, m_Y);
	}
}
