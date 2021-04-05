#include "MiniginPCH.h"
#include "InputManager.h"
#include <iostream>
bool InputManager::ProcessInput()
{
	DWORD result;
	
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	result = XInputGetState(0, &m_CurrentState);


	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return false;
		}
		for (std::pair<std::string, KeyBoardInputInfo> pair : m_KeyBoardCommands)
		{
			if (e.type == SDL_KEYDOWN && pair.second.actionType == ActionType::pressed)
			{
				if (e.key.keysym.scancode == pair.second.Button)
				{
					pair.second.command->Execute();
				}
				
			}
			if (e.type == SDL_KEYUP && pair.second.actionType == ActionType::released)
			{
				if (e.key.keysym.scancode == pair.second.Button)
				{
					pair.second.command->Execute();
				}
			}
		}
	}

	
	for (std::pair<std::string,InputInfo> pair : m_ConsoleCommands)
	{
		switch (pair.second.actionType)
		{
		case ActionType::pressed:
			if (IsPressed(pair.first))
			{
				pair.second.command->Execute();
			}
			break;
		case ActionType::held:
			if (IsHeld(pair.first))
			{
				pair.second.command->Execute();
			}
			break;
		case ActionType::released:
			if (IsReleased(pair.first))
			{
				pair.second.command->Execute();
			}
			break;
		}
	}

	return true;
}

bool InputManager::IsPressed(const std::string& buttonName)
{
	if (!m_ConsoleCommands.at(buttonName).once && m_CurrentState.Gamepad.wButtons & m_ConsoleCommands.at(buttonName).bitmask)
	{
		m_ConsoleCommands.at(buttonName).once = true;
		return true;
	}
	else if (m_ConsoleCommands.at(buttonName).once && !(m_CurrentState.Gamepad.wButtons & m_ConsoleCommands.at(buttonName).bitmask))
	{
		m_ConsoleCommands.at(buttonName).once = false;
	}
	return false;
}

bool InputManager::IsHeld(const std::string& buttonName)
{
	return m_CurrentState.Gamepad.wButtons & m_ConsoleCommands.at(buttonName).bitmask;
}

bool InputManager::IsReleased(const std::string& buttonName)
{
	if (!m_ConsoleCommands.at(buttonName).once && m_CurrentState.Gamepad.wButtons & m_ConsoleCommands.at(buttonName).bitmask)
	{
		m_ConsoleCommands.at(buttonName).once = true;
	}
	else if (m_ConsoleCommands.at(buttonName).once && !(m_CurrentState.Gamepad.wButtons & m_ConsoleCommands.at(buttonName).bitmask))
	{
		m_ConsoleCommands.at(buttonName).once = false;
		return true;
	}
	return false;
}

void InputManager::AddControllerCommand(unsigned int gamepadBitMask, std::string commandName, ActionType action, Command* command)
{
	InputInfo key(gamepadBitMask, action,command);
	m_ConsoleCommands[commandName] = key;
}

void InputManager::AddKeyBoardCommand(std::string commandName, SDL_Scancode button, ActionType action, Command* command)
{
	KeyBoardInputInfo key(button, action, command);
	m_KeyBoardCommands[commandName] = key;
	
}

InputManager::~InputManager()
{
	for (std::pair<std::string, KeyBoardInputInfo> pair : m_KeyBoardCommands)
	{
		delete pair.second.command;
	}
	for (std::pair<std::string, InputInfo> pair : m_ConsoleCommands)
	{
		delete pair.second.command;
	}
}
