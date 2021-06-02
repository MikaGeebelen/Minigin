#pragma once
#include <vector>
#include <string>
#include <memory>
class Transform;
class GameObject;
class TextureRenderComponent;
class Texture2D;
class HexGrid
{
public:
	HexGrid(Transform position, float tileSize ,int height, int states,std::vector<std::string> images, bool cycles = false);
	Transform GetGridPosition(int x, int y);
	void TouchTile(int x, int y, bool evil = false);
	
	std::vector<std::shared_ptr<GameObject>> GetGameObjects();
	
	struct Tile
	{
		std::shared_ptr<GameObject> pTile;
		TextureRenderComponent* pTextureRenderer;
		int CurrentTextureNumber;
	};

private:

	void SwapPicture(int index, bool evil = false);

	float m_Size;
	int m_Height;
	int m_States;
	bool m_Cycles;

	std::shared_ptr<GameObject> m_pPlayfield;
	
	std::vector<Tile> m_BoardTiles;
	
	std::vector<std::shared_ptr<Texture2D>> m_Textures;

	std::vector<Transform> m_TilePositions;

	
};
