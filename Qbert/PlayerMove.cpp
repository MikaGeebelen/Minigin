#include "PlayerMove.h"
#include "InputManager.h"
#include "MoveCommand.h"
#include "HexGrid.h"


PlayerMove::PlayerMove(int playerNum, HexGrid* pCurrentGrid, int x, int y)
	:Move(x,y)
	,m_ActiveMoveCommand(0)
{
	if (playerNum == 1)
	{
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1LUP", SDL_SCANCODE_Q, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1RUP", SDL_SCANCODE_E, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1LDOWN", SDL_SCANCODE_Z, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("RDOWN", SDL_SCANCODE_C, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	}
	else if (playerNum ==2)
	{
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2LUP", SDL_SCANCODE_7, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2RUP", SDL_SCANCODE_9, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2LDOWN", SDL_SCANCODE_1, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2RDOWN", SDL_SCANCODE_3, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	}

}


Transform PlayerMove::UpdateMove(const float& deltaTime)
{
	for (int i{};i<m_MoveCommands.size();i++)
	{
		if (!m_MoveCommands[i]->GetCurrentLoc().IsNearlyEqual(m_MoveCommands[i]->GetNextLoc()))
		{
			m_ActiveMoveCommand = i;
			SetMovementActive(false);
			m_IsMoving = true;
		}
	}
	
	if (!m_IsMoving)
	{
		return  m_MoveCommands[0]->GetCurrentLoc();
	}
	else
	{
		m_MoveTime += deltaTime;

		Transform temp = LerpPos(m_MoveCommands[m_ActiveMoveCommand]->GetCurrentLoc().GetPosition(), m_MoveCommands[m_ActiveMoveCommand]->GetNextLoc().GetPosition());
		if (!m_IsMoving)
		{
			ResetCommands(m_MoveCommands[m_ActiveMoveCommand]->GetNextLoc());
			SetMovementActive(true);
		}
		
		return temp;
	}
	
}

void PlayerMove::SetMovementActive(bool enable)
{
	for (MoveCommand* pCommand : m_MoveCommands)
	{
		pCommand->SetCanMove(enable);
	}
}

void PlayerMove::ResetCommands(Transform newPos)
{
	m_GridPos = m_MoveCommands[m_ActiveMoveCommand]->GetCoords();
	for (MoveCommand* pCommand : m_MoveCommands)
	{
		pCommand->ResetLoc(newPos);
		pCommand->SetCoords(m_GridPos.x, m_GridPos.y);
	}
}




