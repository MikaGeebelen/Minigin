#include "HexGrid.h"
#include <vector>
#include <memory>
#include <Components.h>

#include "ResourceManager.h"
#include "SceneManager.h"

//level events
#include "LevelEvent.h"
#include "Scene.h"

HexGrid::HexGrid(Transform position,float tileSize, int height, int states, std::vector<std::string> images, bool cycles)
	:m_Height(height)
	,m_Size(tileSize)
	,m_States(states)
	,m_Cycles(cycles)
	,m_Disks()
{
	m_pPlayfield = std::make_shared<GameObject>();
	m_pPlayfield->AddComponent(new TransformComponent(m_pPlayfield.get(), new Transform(position)));
	m_pSubject = new SubjectComponent(m_pPlayfield.get());
	m_pPlayfield->AddComponent(m_pSubject);
	
	for (const std::string& path : images)
	{
		m_Textures.push_back(ResourceManager::GetInstance().LoadTexture(path));
	}

	int offset = (height-1) * 2 + 1;
	for (int i = 1; i < height; i++)
	{
		offset += ((height-1) - i);
	}

	float tempWidth = 2 * tileSize;
	float tempHeight = sqrt(3.f) * tileSize;
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
			m_TilePositions.push_back(new Transform(temp));
		}
	}
	
	for (int i{}; i < offset; i++)
	{
		Tile tile;
		tile.pTile = std::make_shared<GameObject>();
		tile.pTile->AddComponent(new TransformComponent(tile.pTile.get(), m_TilePositions[i]));
		tile.pTextureRenderer = new TextureRenderComponent(tile.pTile.get(), images[0]);
		tile.CurrentTextureNumber = 0;
		tile.pTile->AddComponent(tile.pTextureRenderer);

		m_BoardTiles.push_back(tile);
	}
}

Transform HexGrid::GetGridPosition(int x, int y)
{
	for (std::shared_ptr<Disk> pDisk : m_Disks)
	{
		if (pDisk->x == x && pDisk->y == y)
		{
			return GetGridPosition(0,0);
		}
	}

	if (x >= m_Height || y > x || y < 0 || x < 0)
	{
		return Transform();
	}
	
	int offset = x * 2;
	for (int i{ 1 }; i < x; i++)
	{
		offset += (x - i);
	}

	int index = offset - y;
	
	return *m_TilePositions[index];
}

bool HexGrid::TouchTile(int x, int y, bool evil)
{
	//	 index layout
	//	        [y,x]
	//	     [1,1][0,1] 
	//    [2,2][1,2][0,2]
	//	[3,3][2,3][1,3][0,3]

	if (x >= m_Height || y > x || y < 0 || x < 0)
	{
		return SwapPicture(0, evil);
	}
	
	int offset = x * 2;
	for (int i {1}; i < x; i++)
	{
		offset += (x - i);
	}

	int index = offset - y;
	return SwapPicture(index, evil);
}

SubjectComponent* HexGrid::GetSubject()
{
	return m_pSubject;
}

glm::ivec2 HexGrid::GetClosestPlayerLoc(int x, int y)
{
	std::vector<glm::ivec2> playerPositions;
	for (TileOccupation tile : m_Occupations)
	{
		if (tile.type == CharacterType::Player)
		{
			return glm::ivec2(tile.x, tile.y);
		}
	}

	int distance = INT_MAX;
	glm::ivec2 closestPos{};
	for (glm::ivec2 pos : playerPositions)
	{
		int newDistance = pos.x - x + pos.y - y;
		if (newDistance < distance)
		{
			distance = newDistance;
			closestPos = pos;
		}
	}
	
	return closestPos;
}

std::shared_ptr<GameObject> HexGrid::SpawnDiskTile()
{
	int randX = rand() % (m_Height - 1);
	bool isLeft = rand() % 2;
	if (isLeft)
	{
		m_Disks.push_back(std::make_shared<Disk>(randX, randX + 1, m_Size, GetGridPosition(randX, randX)));
	}
	else
	{
		m_Disks.push_back(std::make_shared<Disk>(randX, -1, m_Size, GetGridPosition(randX, 0)));
	}
	return m_Disks[m_Disks.size() - 1]->pDisk;
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

void HexGrid::SetOccupied(int x, int y, CharacterType type, GameObject* pObject)
{
	for (TileOccupation& tile : m_Occupations)
	{
		if (tile.x == x && tile.y == y)
		{
			tile.type = type;
			tile.pObject = pObject;
			return;
		}
	}
	m_Occupations.push_back({x,y,type,pObject});
}

void HexGrid::DestroyObjectOnSpace(int x, int y)
{
	for (TileOccupation tile : m_Occupations)
	{
		if (tile.x == x && tile.y == y)
		{
			SceneManager::GetInstance().GetActiveScene()->RemoveObject(tile.pObject);
		}
	}
}

HexGrid::CharacterType HexGrid::GetIsTileOccupied(int x, int y)
{
	for (TileOccupation tile : m_Occupations)
	{
		if (tile.x == x && tile.y == y)
		{
			return tile.type;
		}
	}
	
	return CharacterType::Empty;
}

HexGrid::Disk::Disk(int x, int y,float tileSize,Transform gridClose)
	:x(x)
	,y(y)
{
	pDisk = std::make_shared<GameObject>();
	pDisk->AddComponent(new TransformComponent(pDisk.get(), &location));
	pDisk->AddComponent(new TextureRenderComponent(pDisk.get(), "../Data/Coily.png"));

	if (y<0)
	{
		location.SetPosition(gridClose.GetPosition().x + tileSize * 2,
			gridClose.GetPosition().y,
			gridClose.GetPosition().z);
	}
	else
	{
		location.SetPosition(gridClose.GetPosition().x - tileSize * 2,
			gridClose.GetPosition().y,
			gridClose.GetPosition().z);
	}

	
}

bool HexGrid::SwapPicture(int index, bool evil)
{
	if (evil)
	{
		if (m_BoardTiles[index].CurrentTextureNumber  > 0)
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
	else if (m_BoardTiles[index].CurrentTextureNumber + 1 >= (int)m_Textures.size())
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
	return IsLevelFinished();
}

bool HexGrid::IsLevelFinished()
{
	for (Tile tile : m_BoardTiles)
	{
		if (tile.CurrentTextureNumber != m_States - 1)
		{
			return false;
		}
	}
	m_pSubject->Notify(new LevelEvent(LevelEvent::LevelEvents::LevelFinished));
	return true;
}
