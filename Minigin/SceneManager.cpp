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
		scene->Update(deltaTime);
	}
}

void SceneManager::Render()
{
	for (const auto& scene : m_Scenes)
	{
		scene->Render();
	}
}

Scene& SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return *scene;
}

void SceneManager::LoadScene(const std::string& filePath)
{
	lua_State* l = luaL_newstate();
	luaL_openlibs(l);

	luaL_dofile(l, filePath.c_str());
	
	lua_close(l);
}

