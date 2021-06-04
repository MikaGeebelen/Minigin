#include "GameManager.h"
#include <memory>
#include <GameObject.h>
#include <Components.h>

#include "GridMoveComponent.h"
#include "FallDownMove.h"
#include "HexGrid.h"
#include "Scene.h"

#include "SceneManager.h"

int GameManager::GetLevel()
{
	return m_level;
}

void GameManager::SetLevel(int level)
{
	m_level = level;
}

void GameManager::SpawnCoily(int gridX, int gridY, std::string image, HexGrid* playfield, bool )
{
	std::shared_ptr<GameObject> pCoily = std::make_shared<GameObject>();
	Transform* transform = new Transform(playfield->GetGridPosition(gridX, gridY));
	pCoily->AddComponent(new TransformComponent(pCoily.get(), transform));
	pCoily->AddComponent(new TextureRenderComponent(pCoily.get(), image));
	pCoily->AddComponent(new SubjectComponent(pCoily.get()));
	pCoily->AddComponent(new GridMoveComponent(pCoily.get(), playfield, new FallDownMove(playfield, gridX, gridY), transform, gridX, gridY));

	SceneManager::GetInstance().GetActiveScene()->Add(pCoily);
}

GameManager::GameManager()
	:m_level(1)
{
}
