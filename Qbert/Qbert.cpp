#include "Qbert.h"

#include "HexGrid.h"

#include <vector>
#include <Components.h>

#include "GridMoveComponent.h"
#include "PlayerMove.h"
Qbert::Qbert(int gridX, int gridY, std::string image, HexGrid* playfield)
	:m_pGrid(playfield)
{
	m_pQbert = std::make_shared<GameObject>();
	m_Transform = playfield->GetGridPosition(gridX, gridY);
	m_pQbert->AddComponent(new TransformComponent(m_pQbert.get(),&m_Transform));
	m_pQbert->AddComponent(new TextureRenderComponent(m_pQbert.get(), image));
	m_pQbert->AddComponent(new SubjectComponent(m_pQbert.get()));
	m_pQbert->AddComponent(new GridMoveComponent(m_pQbert.get(), playfield, new PlayerMove("p1", playfield),&m_Transform,gridX,gridY));
}

std::shared_ptr<GameObject> Qbert::GetGameObject()
{
	return m_pQbert;
}
