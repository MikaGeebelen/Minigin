#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"


unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name),m_IsSceneActive(false) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void Scene::Update(const float& deltaTime)
{
	for(auto& object : m_Objects)
	{
		if (object != nullptr)
		{
			object->Update(deltaTime);
		}
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();
	}
}

void Scene::SetIsSceneActive(bool isSceneActive)
{
	m_IsSceneActive = isSceneActive;
}

bool Scene::GetIsSceneActive()
{
	return  m_IsSceneActive;
}

void Scene::RemoveObject(GameObject* pObject)
{
	for (auto& object : m_Objects)
	{
		if (object.get() == pObject)
		{
			m_Objects.erase(std::find(m_Objects.begin(), m_Objects.end(), object));
		}
	}
}

void Scene::ClearScene()
{
	m_Objects.clear();
}

const std::string& Scene::GetSceneName()
{
	return m_Name;
}

