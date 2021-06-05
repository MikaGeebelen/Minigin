#include "GameManager.h"
#include <memory>
#include <GameObject.h>
#include <Components.h>

#include "GridMoveComponent.h"
#include "FallDownMove.h"
#include "CoilyAIMove.h"
#include "HexGrid.h"
#include "Scene.h"

#include "SceneManager.h"
#include "GridManager.h"

void GameManager::Update(const float& deltaTime)
{
	if (GridManager::GetInstance().GetCurrentGrid() != nullptr)
	{
		if (m_IsCoilyActivies)
		{
			m_CoilyTimer += deltaTime;
			if (m_CoilyTimer > m_CoilyRespawnTime && !(Coilys >= 1) && m_IsCoilyActivies)
			{
				SpawnCoily(0, 0, "../Data/Coily.png", GridManager::GetInstance().GetCurrentGrid());
				Coilys++;
				m_CoilyTimer = 0.f;
			}
		}

		if (m_IsGreenActive)
		{
			m_GreenTimer += deltaTime;
			if (m_GreenTimer > m_GreenspawnTime)
			{
				std::string picture;
				if (rand()%2)
				{
					picture = "../Data/Sam.png";
				}
				else
				{
					picture = "../Data/Slick.png";
				}
				SpawnGreenEnemy(0, 0, picture, GridManager::GetInstance().GetCurrentGrid());
				m_GreenTimer = 0.f;
			}
		}

		if (m_IsRedActive)
		{
			m_RedTimer += deltaTime;
			if (m_RedTimer > m_RedspawnTime)
			{
				if (rand() % 2)
				{
					SpawnRedEnemy(1, 0, "../Data/Orb.png", GridManager::GetInstance().GetCurrentGrid());
				}
				else
				{
					SpawnRedEnemy(1, 1, "../Data/Orb.png", GridManager::GetInstance().GetCurrentGrid());
				}
				m_RedTimer = 0.f;
			}
		}

		if (m_IspurpleActive)
		{
			m_PurpleTimer += deltaTime;
			if (m_PurpleTimer > m_PurplespawnTime)
			{
				if (rand() % 2)
				{
					SpawnPurpleEnemy(6, 6, "../Data/ugg.png", GridManager::GetInstance().GetCurrentGrid());
				}
				else
				{
					SpawnPurpleEnemy(6, 0, "../Data/WrongWay.png", GridManager::GetInstance().GetCurrentGrid());
				}
				

				m_RedTimer = 0.f;
			}
		}
	}
}

void GameManager::Reset()
{
	m_CoilyTimer = 0.f;
	m_RedTimer = 0.f;
	m_PurpleTimer = 0.f;
	m_GreenTimer = 0.f;
	Coilys = 0;
}

int GameManager::GetLevel()
{
	return m_level;
}

void GameManager::SetLevel(int level)
{
	m_level = level;
}

int GameManager::GetLives()
{
	return m_Lives;
}

void GameManager::SetLives(int Lives)
{
	m_Lives = Lives;
}

void GameManager::SetScoreTextComponent(TextRenderComponent* pScore)
{
	m_pScoreText = pScore;
}

void GameManager::SetScore(int Lives)
{
	m_Score = Lives;
	if (m_pScoreText != nullptr)
	{
		m_pScoreText->SetText("Score: " + std::to_string(m_Score));
	}
}

int GameManager::GetScore()
{
	return m_Score;
}

void GameManager::EnemySpawnerSetup(bool coilyActive, float coilyRespawnTime, bool greenEnemy,
                                    float greenEnemyRespawnTime, bool redEnemy, float redEnemyRespawnTime, bool purpleEnemy,
                                    float purpleEnemyRespawnTime)
{
	m_IsCoilyActivies = coilyActive;
	m_IsGreenActive = greenEnemy;
	m_IsRedActive = redEnemy;
	m_IspurpleActive = purpleEnemy;

	m_CoilyRespawnTime = coilyRespawnTime;
	m_RedspawnTime = redEnemyRespawnTime;
	m_GreenspawnTime = greenEnemyRespawnTime;
	m_PurplespawnTime = purpleEnemyRespawnTime;
}

void GameManager::SpawnCoily(int gridX, int gridY, std::string image, HexGrid* playfield )
{
	std::shared_ptr<GameObject> pCoily = std::make_shared<GameObject>();
	Transform* transform = new Transform(playfield->GetGridPosition(gridX, gridY));
	pCoily->AddComponent(new TransformComponent(pCoily.get(), transform));
	pCoily->AddComponent(new TextureRenderComponent(pCoily.get(), image));
	pCoily->AddComponent(new SubjectComponent(pCoily.get()));
	pCoily->AddComponent(new GridMoveComponent(pCoily.get(), playfield, new CoilyAIMove(playfield, gridX, gridY , 0.75f), transform, gridX, gridY));

	SceneManager::GetInstance().GetActiveScene()->Add(pCoily);
}

void GameManager::SpawnGreenEnemy(int gridX, int gridY, std::string image, HexGrid* playfield)
{
	std::shared_ptr<GameObject> pGreen = std::make_shared<GameObject>();
	Transform* transform = new Transform(playfield->GetGridPosition(gridX, gridY));
	pGreen->AddComponent(new TransformComponent(pGreen.get(), transform));
	pGreen->AddComponent(new TextureRenderComponent(pGreen.get(), image));
	pGreen->AddComponent(new GridMoveComponent(pGreen.get(), playfield, new FallDownMove(playfield, gridX, gridY , 1.f), transform, gridX, gridY,true));

	SceneManager::GetInstance().GetActiveScene()->Add(pGreen);
}

void GameManager::SpawnRedEnemy(int gridX, int gridY, std::string image, HexGrid* playfield)
{
	std::shared_ptr<GameObject> pRed = std::make_shared<GameObject>();
	Transform* transform = new Transform(playfield->GetGridPosition(gridX, gridY));
	pRed->AddComponent(new TransformComponent(pRed.get(), transform));
	pRed->AddComponent(new TextureRenderComponent(pRed.get(), image));
	pRed->AddComponent(new GridMoveComponent(pRed.get(), playfield, new FallDownMove(playfield, gridX, gridY , 1.f), transform, gridX, gridY));

	SceneManager::GetInstance().GetActiveScene()->Add(pRed);
}

void GameManager::SpawnPurpleEnemy(int gridX, int gridY, std::string image, HexGrid* playfield)
{
	std::shared_ptr<GameObject> pPurple = std::make_shared<GameObject>();
	Transform* transform = new Transform(playfield->GetGridPosition(gridX, gridY));
	pPurple->AddComponent(new TransformComponent(pPurple.get(), transform));
	pPurple->AddComponent(new TextureRenderComponent(pPurple.get(), image));
	pPurple->AddComponent(new GridMoveComponent(pPurple.get(), playfield, new FallDownMove(playfield, gridX, gridY,1.f), transform, gridX, gridY));

	SceneManager::GetInstance().GetActiveScene()->Add(pPurple);
}

GameManager::GameManager()
	:m_level(1)
	,m_CoilyTimer(0.f)
	,m_RedTimer(0.f)
	,m_PurpleTimer(0.f)
	,m_GreenTimer(0.f)
	,m_MaxEachType(2)
{
	EnemySpawnerSetup(true, 2.f, true, 10.f, true, 4.f, false, 0.f);
}
