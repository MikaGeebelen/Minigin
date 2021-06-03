#include "Coily.h"

#include "HexGrid.h"

#include <vector>
#include <Components.h>

#include "GridMoveComponent.h"
#include "FallDownMove.h"
#include "PlayerMove.h"

Coily::Coily(int gridX, int gridY, std::string image, HexGrid* playfield, bool )
	:m_pGrid(playfield)
{
	m_pCoily = std::make_shared<GameObject>();
	m_Transform = playfield->GetGridPosition(gridX, gridY);
	m_pCoily->AddComponent(new TransformComponent(m_pCoily.get(), &m_Transform));
	m_pCoily->AddComponent(new TextureRenderComponent(m_pCoily.get(), image));
	m_pCoily->AddComponent(new SubjectComponent(m_pCoily.get()));
	m_pCoily->AddComponent(new GridMoveComponent(m_pCoily.get(), playfield, new FallDownMove(playfield, gridX, gridY), &m_Transform, gridX, gridY));
}

std::shared_ptr<GameObject> Coily::GetGameObject()
{
	return m_pCoily;
}
