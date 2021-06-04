#include "GridManager.h"
#include "HexGrid.h"
void GridManager::SetCurrentGrid(HexGrid* pGrid)
{
	delete m_pHexGrid;
	m_pHexGrid = pGrid;
}

HexGrid* GridManager::GetCurrentGrid()
{
	return m_pHexGrid;
}
