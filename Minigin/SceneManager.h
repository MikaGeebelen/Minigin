#pragma once
#include "Singleton.h"


class Scene;
class SceneManager final : public Singleton<SceneManager>
{
public:
	Scene& CreateScene(const std::string& name);
	void LoadScene(const std::string& filePath);
	void Update(const float& deltaTime);
	void Render();
private:
	friend class Singleton<SceneManager>;
	SceneManager() = default;
	std::vector<std::shared_ptr<Scene>> m_Scenes;
};

