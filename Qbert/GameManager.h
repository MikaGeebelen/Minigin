#pragma once
#include <Singleton.h>
#include <vector>
#include <string>
class GameObject;
class HexGrid;
class QbertApplication;

class TextRenderComponent;

class GameManager final : public Singleton<GameManager>
{
public:
	void SetGame(const QbertApplication* app);
	const QbertApplication* GetGame();
	
	void Update(const float& deltaTime);
	void Reset();
	
	int GetLevel();
	void SetLevel(int level);

	int GetLives();
	void IncreaseLives(int Lives);
	void DecreaseLives(int Lives);
	void SetLives(int Lives);

	void SetScoreTextComponent(TextRenderComponent* Lives);
	void SetScore(int score);
	void IncreaseScore(int score);
	
	int GetScore();
	
	void EnemySpawnerSetup(bool coilyActive, float coilyRespawnTime, bool greenEnemy, float greenEnemyRespawnTime, bool redEnemy, float redEnemyRespawnTime, bool purpleEnemy, float purpleEnemyRespawnTime);

private:
	friend class Singleton<GameManager>;
	GameManager();

	void SpawnCoily(int gridX, int gridY, std::string image, HexGrid* playfield);
	void SpawnGreenEnemy(int gridX, int gridY, std::string image, HexGrid* playfield);
	void SpawnRedEnemy(int gridX, int gridY, std::string image, HexGrid* playfield);
	void SpawnPurpleEnemy(int gridX, int gridY, std::string image, HexGrid* playfield, bool dir);

	TextRenderComponent* m_pScoreText = nullptr;
	const QbertApplication* m_pGame = nullptr;
	
	int m_Score;
	int m_level;
	int m_Lives = 3;
	
	bool m_IsCoilyActivies;
	bool m_IsGreenActive;
	bool m_IsRedActive;
	bool m_IspurpleActive;

	float m_CoilyTimer;
	float m_RedTimer;
	float m_GreenTimer;
	float m_PurpleTimer;
	
	float m_CoilyRespawnTime;
	float m_RedspawnTime;
	float m_GreenspawnTime;
	float m_PurplespawnTime;

	int Coilys = 0;
	const int m_MaxEachType;
};

