#include "QbertSceneLoader.h"
#include "Scene.h"
#include "SceneManager.h"

#include <iostream>

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

void QbertSceneLoader::StartLua()
{
	m_pL = luaL_newstate();
	luaL_openlibs(m_pL);
}

void QbertSceneLoader::CloseLua()
{
	if (m_pL != nullptr)
	{
		std::cout << "Call start lua first before trying to close lua\n";
		return;
	}
	lua_close(m_pL);
}

void QbertSceneLoader::LoadScene(Scene& , const std::string& filePath)
{
	if (m_pL != nullptr)
	{
		std::cout << "Call start lua first before loading scenes\n";
		return;
	}

	luaL_dofile(m_pL, filePath.c_str());
	lua_getglobal(m_pL, "StartScreen");
	if (lua_isfunction(m_pL, -1))
	{
		lua_pcall(m_pL, 0, 0, 0);
		lua_getglobal(m_pL, "buttons");
		int buttons = (int)lua_tonumber(m_pL, -1);
		for (int i{}; i < buttons; i++)
		{

		}
	}

}