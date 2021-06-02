#include "HexGrid.h"
#include <vector>
#include <memory>
#include <Components.h>

#include "ResourceManager.h"

HexGrid::HexGrid(Transform position,float tileSize, int height, int states, std::vector<std::string> images, bool cycles)
	:m_Height(height)
	,m_Size(tileSize)
	,m_States(states)
	,m_Cycles(cycles)
{
	m_pPlayfield = std::make_shared<GameObject>();
	m_pPlayfield->AddComponent(new TransformComponent(m_pPlayfield.get(), &position));
	//m_pPlayfield->AddComponent(new ObserverComponent(m_pPlayfield,))

	for (const std::string& path : images)
	{
		m_Textures.push_back(ResourceManager::GetInstance().LoadTexture(path));
	}

	
	int offset = (height-1) * 2 + 1;
	for (int i = 1; i < height; i++)
	{
		offset += ((height-1) - i);
	}

	float tempWidth = sqrt(3.f) * tileSize;
	float tempHeight = 2 * tileSize;
	float pyramidWidthOffset = tileSize;
	for (int x{};x<height;x++)
	{
		if (x % 2)
		{
			pyramidWidthOffset += tileSize;
		}
		else
		{
			pyramidWidthOffset -= tileSize;
		}
		if ((x-1)%2)
		{
			if (x-1 > 0)
			{
				pyramidWidthOffset += tempWidth;
			}
		}
		
		
		for (int y{}; y < x+1; y++)
		{
			Transform temp{};

			temp.SetPosition(position.GetPosition().x + (y * tempWidth) - pyramidWidthOffset,
							 position.GetPosition().y + (x * tempHeight * 0.75f),
							 position.GetPosition().z);
			m_TilePositions.push_back(temp);
		}
	}
	for (int i{}; i < offset; i++)
	{
		Tile tile;
		tile.pTile = std::make_shared<GameObject>();
		tile.pTile->AddComponent(new TransformComponent(tile.pTile.get(), &m_TilePositions[i]));
		tile.pTextureRenderer = new TextureRenderComponent(tile.pTile.get(), images[0]);
		tile.CurrentTextureNumber = 0;
		tile.pTile->AddComponent(tile.pTextureRenderer);

		m_BoardTiles.push_back(tile);
	}
}

Transform HexGrid::GetGridPosition(int x, int y)
{
	if (x >= m_Height || y > x || y < 0 || x < 0)
	{
		return m_TilePositions[0];
	}
	
	int offset = x * 2;
	for (int i{ 1 }; i < x; i++)
	{
		offset += (x - i);
	}

	int index = offset - y;
	
	return m_TilePositions[index];
}

void HexGrid::TouchTile(int x, int y, bool evil)
{
	//	 index layout
	//	        [y,x]
	//	     [1,1][0,1] 
	//    [2,2][1,2][0,2]
	//	[3,3][2,3][1,3][0,3]

	if (x >= m_Height || y > x || y < 0 || x < 0)
	{
		SwapPicture(0, evil);
		return;
	}
	
	int offset = x * 2;
	for (int i {1}; i < x; i++)
	{
		offset += (x - i);
	}

	int index = offset - y;
	SwapPicture(index, evil);
}

std::vector<std::shared_ptr<GameObject>> HexGrid::GetGameObjects()
{
	std::vector<std::shared_ptr<GameObject>> m_GameObjects{};
	for(Tile tile: m_BoardTiles)
	{
		m_GameObjects.push_back(tile.pTile);
	}
	m_GameObjects.push_back(m_pPlayfield);
	return m_GameObjects;
}

void HexGrid::SwapPicture(int index, bool evil)
{
	if (evil)
	{
		if (m_BoardTiles[index].CurrentTextureNumber - 1 > 0)
		{
			m_BoardTiles[index].CurrentTextureNumber--;
		}
		else
		{
			if (m_Cycles)
			{
				m_BoardTiles[index].CurrentTextureNumber = (int)m_Textures.size() - 1;
			}
		}
	}
	else if (m_BoardTiles[index].CurrentTextureNumber + 1 >= m_Textures.size())
	{
		if (m_Cycles)
		{
			m_BoardTiles[index].CurrentTextureNumber = 0;
		}
	}
	else
	{
		m_BoardTiles[index].CurrentTextureNumber++;
	}
	
	m_BoardTiles[index].pTextureRenderer->SetTexture(m_Textures[m_BoardTiles[index].CurrentTextureNumber]);
}
