#pragma once
#include "SceneManager.h"


class GameObject;
class SceneObject;
class Scene
{
	friend Scene& SceneManager::CreateScene(const std::string& name);
public:
	void Add(const std::shared_ptr<GameObject>& object);

	void Update(const float& deltaTime);
	void Render() const;

	void SetIsSceneActive(bool isSceneActive);
	bool GetIsSceneActive();

	void RemoveObject(GameObject* object);
	void ClearScene();
	
	const std::string& GetSceneName();
	
	~Scene();
	Scene(const Scene& other) = delete;
	Scene(Scene&& other) = delete;
	Scene& operator=(const Scene& other) = delete;
	Scene& operator=(Scene&& other) = delete;

private:
	explicit Scene(const std::string& name);

	std::string m_Name;
	std::vector < std::shared_ptr<GameObject>> m_Objects{};
	bool m_IsSceneActive;
	static unsigned int m_IdCounter;

	std::vector<std::vector<std::shared_ptr<GameObject>>::iterator> m_MarkedForDelete;
};


