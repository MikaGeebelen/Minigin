#pragma once
#include <Singleton.h>
#include <vector>
#include <string>
class GameObject;
class HexGrid;
class GameManager final : public Singleton<GameManager>
{
public:
	int GetLevel();
	void SetLevel(int level);
	
	void SpawnCoily(int gridX, int gridY, std::string image, HexGrid* playfield, bool IsPlayer = false);
private:
	friend class Singleton<GameManager>;
	GameManager();

	int m_level;
	
};

