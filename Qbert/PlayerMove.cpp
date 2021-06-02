#include "PlayerMove.h"
#include "InputManager.h"
#include "MoveCommand.h"
#include "HexGrid.h"

#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/gtx/compatibility.hpp"
#pragma warning(pop)

PlayerMove::PlayerMove(const std::string& playerPrefix, HexGrid* pCurrentGrid)
	:m_IsMoving(false)
	,m_ActiveMoveCommand(0)
	,m_MaxMoveTime(0.5f)
	,m_MoveTime(0.f)
{
	m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LUP));
	InputManager::GetInstance().AddKeyBoardCommand(playerPrefix + "LUP", SDL_SCANCODE_Q, ActionType::pressed, m_MoveCommands[m_MoveCommands.size()-1]);
	m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RUP));
	InputManager::GetInstance().AddKeyBoardCommand(playerPrefix + "RUP", SDL_SCANCODE_E, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::LDOWN));
	InputManager::GetInstance().AddKeyBoardCommand(playerPrefix + "LDOWN", SDL_SCANCODE_A, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
	m_MoveCommands.push_back(new MoveCommand(pCurrentGrid, MoveCommand::MoveDir::RDOWN));
	InputManager::GetInstance().AddKeyBoardCommand(playerPrefix + "RDOWN", SDL_SCANCODE_D, ActionType::pressed, m_MoveCommands[m_MoveCommands.size() - 1]);
}


Transform PlayerMove::UpdateMove(const float& deltaTime)
{
	//inputs defined for player
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
		return LerpPos();
	}
	
}

glm::ivec2 PlayerMove::GetGridPos()
{
	return m_GridPos;
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

Transform PlayerMove::LerpPos()
{
	glm::vec3 currentLoc = m_MoveCommands[m_ActiveMoveCommand]->GetCurrentLoc().GetPosition();
	glm::vec3 nextLoc = m_MoveCommands[m_ActiveMoveCommand]->GetNextLoc().GetPosition();

	Transform newPos{};
	
	float newX = glm::lerp(currentLoc.x, nextLoc.x, m_MoveTime / m_MaxMoveTime);
	float newY = glm::lerp(currentLoc.y, nextLoc.y, m_MoveTime / m_MaxMoveTime);
	float newZ = glm::lerp(currentLoc.z, nextLoc.z, m_MoveTime / m_MaxMoveTime);

	newPos.SetPosition(newX, newY, newZ);
	
	if (m_MoveCommands[m_ActiveMoveCommand]->GetNextLoc().IsNearlyEqual(newPos))
	{
		m_MoveTime = 0;
		m_IsMoving = false;
		ResetCommands(m_MoveCommands[m_ActiveMoveCommand]->GetNextLoc());
		SetMovementActive(true);
		
	}

	return newPos;
}



