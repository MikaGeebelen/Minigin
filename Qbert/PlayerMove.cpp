#include "PlayerMove.h"
#include "InputManager.h"
#include "MoveCommand.h"
#include "HexGrid.h"


PlayerMove::PlayerMove(int playerNum, HexGrid* pCurrentGrid, int x, int y)
	:Move(x,y)
	,m_ActiveMoveCommand(0)
	,m_pGrid(pCurrentGrid)
{
	if (playerNum == 1)
	{
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1LUP", SDL_SCANCODE_Q, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(0 ,XINPUT_GAMEPAD_X,"1CONLUP", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1RUP", SDL_SCANCODE_W, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(0, XINPUT_GAMEPAD_Y, "1CONRUP", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1LDOWN", SDL_SCANCODE_A, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(0, XINPUT_GAMEPAD_A, "1CONLDOWN", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("1RDOWN", SDL_SCANCODE_S, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(0, XINPUT_GAMEPAD_B, "1CONRDOWN", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	}
	else if (playerNum ==2)
	{
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2LUP", SDL_SCANCODE_I, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(1, XINPUT_GAMEPAD_X, "2CONLUP", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2RUP", SDL_SCANCODE_O, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(1, XINPUT_GAMEPAD_Y, "2CONRUP", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2LDOWN", SDL_SCANCODE_K, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(1, XINPUT_GAMEPAD_A, "2CONLDOWN", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddKeyBoardCommand("2RDOWN", SDL_SCANCODE_L, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
		m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN, m_GridPos.x, m_GridPos.y));
		InputManager::GetInstance().AddControllerCommand(1, XINPUT_GAMEPAD_B, "2CONRDOWN", ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	}

}


Transform PlayerMove::UpdateMove(const float& deltaTime)
{
	for (size_t i{};i< m_MoveCommands.size();i++)
	{
		if (!m_MoveCommands[i]->GetCurrentLoc().IsNearlyEqual(m_MoveCommands[i]->GetNextLoc()))
		{
			if (!m_MoveCommands[i]->GetNextLoc().IsNearlyEqual(Transform()))
			{
				m_ActiveMoveCommand = (int)i;
				SetMovementActive(false);
				m_IsMoving = true;
			}
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
	
	if (m_GridPos.y > m_GridPos.x || m_GridPos.y < 0)
	{
		m_GridPos = { 0,0 };
	}

	for (MoveCommand* pCommand : m_MoveCommands)
	{
		pCommand->ResetLoc(newPos);
		pCommand->SetCoords(m_GridPos.x, m_GridPos.y);
	}
}




