#pragma once
#include <string>
class Scene;
struct lua_State;
class QbertSceneLoader
{
public:
	
	void LoadScene(Scene& scene, const std::string& filePath);
	void StartLua();
	void CloseLua();

private:
	lua_State* m_pL;
};

