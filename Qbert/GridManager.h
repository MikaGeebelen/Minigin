#pragma once
#include <Singleton.h>
#include <memory>
#include <vector>
class GameObject;
class HexGrid;
class GridManager final : public Singleton<GridManager>
{
public:
	void SetCurrentGrid(HexGrid* pGrid);
	HexGrid* GetCurrentGrid();

private:
	friend class Singleton<GridManager>;
	GridManager() = default;
	HexGrid* m_pHexGrid;
};

