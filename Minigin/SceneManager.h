#pragma once
#include "Singleton.h"
#include <vector>
#include <memory>
#include <string>

class Scene;
struct lua_State;
class SceneManager final : public Singleton<SceneManager>
{
public:

	struct LuaFunctions
	{
		std::string name;
		int(*func)(lua_State*);
	};
	
	Scene& CreateScene(const std::string& name);
	
	void OpenLua(const std::string& path, std::vector<LuaFunctions> generatorFunctions, const std::string& gameMode);
	void UseFunction(const std::string& function, int data);
	void CloseLua();
	
	std::shared_ptr<Scene> GetScene(const std::string& name);
	std::shared_ptr<Scene> GetActiveScene();
	void SetSceneActive(const std::string& name);

	
	void Update(const float& deltaTime);
	void Render();
private:
	friend class Singleton<SceneManager>;
	SceneManager() = default;
	std::vector<std::shared_ptr<Scene>> m_Scenes;

	lua_State* m_pL;

};

