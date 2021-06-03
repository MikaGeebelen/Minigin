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

void SceneManager::CreateScene(const std::string& path, std::vector<LuaFunctions> generatorFunctions)
{
	lua_State* pL = luaL_newstate();
	luaL_openlibs(pL);
	for (LuaFunctions function : generatorFunctions)
	{
		lua_register(pL, function.name.c_str(), function.func);
	}

	luaL_dofile(pL, path.c_str());
	
	lua_close(pL);
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




