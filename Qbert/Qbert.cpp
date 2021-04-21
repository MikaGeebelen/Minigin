#include "Qbert.h"

#include "HexGrid.h"

#include <vector>
#include <Components.h>


Qbert::Qbert(int gridX, int gridY, std::string image, HexGrid* playfield)
	:m_pGrid(playfield)
	,x(gridX)
	,y(gridY)
{
	m_pQbert = std::make_shared<GameObject>();
	m_Transform = playfield->GetGridPosition(gridX, gridY);
	m_pQbert->AddComponent(new TransformComponent(m_pQbert.get(),&m_Transform));
	m_pQbert->AddComponent(new TextureRenderComponent(m_pQbert.get(), image));
	m_pQbert->AddComponent(new SubjectComponent(m_pQbert.get()));
}

std::shared_ptr<GameObject> Qbert::GetGameObject()
{
	return m_pQbert;
}

void Qbert::Move(MoveDir dir)
{
	switch (dir)
	{
	case MoveDir::topLeft:
		x--;
		m_Transform = m_pGrid->GetGridPosition(x, y);
		break;
	case MoveDir::topRight:
		x--;
		y--;
		m_Transform = m_pGrid->GetGridPosition(x, y);
		break;
	case MoveDir::bottemLeft:
		x++;
		y++;
		m_Transform = m_pGrid->GetGridPosition(x, y);
		break;
	case MoveDir::bottemRight:
		x++;
		m_Transform = m_pGrid->GetGridPosition(x, y);
		break;
	}
}
