#pragma once
#include <string>
#include <memory>
#include <Transform.h>
class HexGrid;
class GameObject;
class Qbert
{
public:
	Qbert(int gridX,int gridY, std::string image ,HexGrid* playfield);
	
	std::shared_ptr<GameObject> GetGameObject();

private:
	std::shared_ptr<GameObject> m_pQbert;
	HexGrid* m_pGrid;
	Transform m_Transform;
};
