#pragma once
#include <vector>
#include <string>
#include <memory>
#include <Transform.h>
class GameObject;
class TextureRenderComponent;
class Texture2D;
class SubjectComponent;

class HexGrid
{
public:
	HexGrid(Transform position, float tileSize ,int height, int states,std::vector<std::string> images, bool cycles = false);
	
	Transform GetGridPosition(int x, int y);
	bool TouchTile(int x, int y, bool evil = false);
	SubjectComponent* GetSubject();

	glm::ivec2 GetClosestPlayerLoc(int x, int y);
	
	std::shared_ptr<GameObject> SpawnDiskTile();
	
	std::vector<std::shared_ptr<GameObject>> GetGameObjects();

	enum class CharacterType
	{
		Player,
		Enemy,
		KillableEnemy,
		Empty
	};

	struct TileOccupation
	{
		int x;
		int y;
		CharacterType type;
		GameObject* pObject;
	};
	
	void SetOccupied(int x, int y, CharacterType type, GameObject* pObject);
	void DestroyObjectOnSpace(int x, int y);
	CharacterType GetIsTileOccupied(int x, int y);
	
	struct Tile
	{
		std::shared_ptr<GameObject> pTile;
		TextureRenderComponent* pTextureRenderer;
		int CurrentTextureNumber;
	};

	struct Disk
	{
		Disk(int x, int y, float tileSize, Transform gridClose);
		std::shared_ptr<GameObject> pDisk;
		int x;
		int y;
		Transform location;
	};

private:

	bool SwapPicture(int index, bool evil = false);
	bool IsLevelFinished();

	bool m_IsLevelFinished;
	float m_Size;
	int m_Height;
	int m_States;
	bool m_Cycles;

	SubjectComponent* m_pSubject;
	
	std::shared_ptr<GameObject> m_pPlayfield;
	
	std::vector<Tile> m_BoardTiles;
	
	std::vector<std::shared_ptr<Texture2D>> m_Textures;

	std::vector<Transform*> m_TilePositions;
	std::vector<std::shared_ptr<Disk>> m_Disks;

	std::vector<TileOccupation> m_Occupations;
};
