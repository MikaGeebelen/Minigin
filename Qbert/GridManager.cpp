#include "GridManager.h"

void GridManager::SetCurrentGrid(HexGrid* pGrid)
{
	m_pHexGrid = pGrid;
}

HexGrid* GridManager::GetCurrentGrid()
{
	return m_pHexGrid;
}
