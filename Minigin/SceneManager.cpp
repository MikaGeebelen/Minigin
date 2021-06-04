#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


void SceneManager::Update(const float& deltaTime)
{
	for(auto& scene : m_Scenes)
	{
		if (scene->GetIsSceneActive())
		{
			scene->Update(deltaTime);
		}
	}
}

void SceneManager::Render()
{
	for (const auto& scene : m_Scenes)
	{
		if (scene->GetIsSceneActive())
		{
			scene->Render();
		}
	}
}

Scene& SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}

void SceneManager::OpenLua(const std::string& path, std::vector<LuaFunctions> generatorFunctions,const std::string& gameMode)
{
	if (m_pL == nullptr)
	{
		m_pL = luaL_newstate();
		luaL_openlibs(m_pL);
		for (LuaFunctions function : generatorFunctions)
		{
			lua_register(m_pL, function.name.c_str(), function.func);
		}

		luaL_dofile(m_pL, path.c_str());


		lua_pushstring(m_pL, gameMode.c_str());
		lua_setglobal(m_pL, "gameMode");
	}
}

void SceneManager::CloseLua()
{
	lua_close(m_pL);
}

void SceneManager::UseFunction(const std::string& function, int data)
{
	lua_getglobal(m_pL, function.c_str());
	if (lua_isfunction(m_pL, -1))
	{
		lua_pushnumber(m_pL, data);
		lua_pcall(m_pL, 1, 1, 0);
	}
}

std::shared_ptr<Scene> SceneManager::GetScene(const std::string& name)
{
	for (std::shared_ptr<Scene> scene : m_Scenes)
	{
		if (scene->GetSceneName() == name)
		{
			return scene;
		}
	}

	return nullptr;
}

void SceneManager::SetSceneActive(const std::string& name)
{
	for (std::shared_ptr<Scene> scene : m_Scenes)
	{
		scene->SetIsSceneActive(false);
	}

	GetScene(name)->SetIsSceneActive(true);
}




