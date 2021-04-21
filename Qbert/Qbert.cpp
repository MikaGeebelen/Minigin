#include "Qbert.h"

#include "HexGrid.h"

#include <vector>
#include <memory>
#include <Components.h>


Qbert::Qbert(int gridX, int gridY, std::string image, HexGrid* playfield)
{
	m_pQbert = new GameObject();
	Transform temp = playfield->GetGridPosition(gridX, gridY);
	m_pQbert->AddComponent(new TransformComponent(m_pQbert, &temp));
	m_pQbert->AddComponent(new TextureRenderComponent(m_pQbert, image));
	m_pQbert->AddComponent(new SubjectComponent(m_pQbert));
}

GameObject* Qbert::GetGameObject()
{
	return m_pQbert;
}
