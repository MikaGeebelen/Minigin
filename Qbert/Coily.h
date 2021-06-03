#pragma once
#include <string>
#include <memory>
#include <Transform.h>
class HexGrid;
class GameObject;
class Coily
{
public:
	Coily(int gridX, int gridY, std::string image, HexGrid* playfield,bool IsPlayer = false);
	std::shared_ptr<GameObject> GetGameObject();

private:
	std::shared_ptr<GameObject> m_pCoily;
	HexGrid* m_pGrid;
	Transform m_Transform;
};

