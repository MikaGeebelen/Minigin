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
	void TouchTile(int x, int y, bool evil = false);
	SubjectComponent* GetSubject();
	
	std::shared_ptr<GameObject> SpawnDiskTile();
	
	std::vector<std::shared_ptr<GameObject>> GetGameObjects();
	
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

	void SwapPicture(int index, bool evil = false);
	void IsLevelFinished();

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
	
};
