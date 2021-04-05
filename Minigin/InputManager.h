#pragma once
#include <Windows.h>
#include <windef.h>
#include <Xinput.h>
#pragma comment (lib,"XInput.lib")

#include <map>
#include <memory>
#include "Command.h"
#include <string>
#include "Singleton.h"
#include <SDL.h>

enum class ActionType
{
	pressed,
	held,
	released
};

struct InputInfo
{
	InputInfo()
		:bitmask(0)
		, actionType(ActionType::pressed)
		, command(nullptr)
		, once(false)
	{}
	InputInfo(unsigned int mask, ActionType action, Command* command)
		:bitmask(mask)
		,actionType(action)
		,command(command)
		,once(false)
	{}
	
	unsigned int bitmask;
	ActionType actionType;
	bool once;
	Command* command;
};

struct KeyBoardInputInfo
{
	KeyBoardInputInfo()
		:Button()
		, actionType(ActionType::pressed)
		, command(command)
	{}
	KeyBoardInputInfo(SDL_Scancode button, ActionType action, Command* command)
		:Button(button)
		, actionType(action)
		, command(command)
	{}

	SDL_Scancode Button;
	ActionType actionType;
	Command* command;
};

class InputManager final : public Singleton<InputManager>
{
public:
	bool ProcessInput();

	void AddControllerCommand(unsigned int gamepadBitMask, std::string commandName, ActionType action, Command* command);
	void AddKeyBoardCommand(std::string commandName, SDL_Scancode button, ActionType action, Command* command);
	~InputManager();

private:
	bool IsPressed(const std::string& buttonName);
	bool IsHeld(const std::string& buttonName);
	bool IsReleased(const std::string& buttonName);
	
	using ControllerCommandsMap = std::map< std::string, InputInfo>;
	ControllerCommandsMap m_ConsoleCommands;

	using KeyBoardCommandsMap = std::map< std::string, KeyBoardInputInfo>;
	KeyBoardCommandsMap m_KeyBoardCommands;

	XINPUT_STATE m_CurrentState;
	
};
