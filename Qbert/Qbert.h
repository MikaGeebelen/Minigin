#pragma once
#include <string>
class HexGrid;
class GameObject;
class Qbert
{
public:
	Qbert(int gridX,int gridY, std::string image ,HexGrid* playfield);
	
	GameObject* GetGameObject();


private:
	GameObject* m_pQbert;
	
};
