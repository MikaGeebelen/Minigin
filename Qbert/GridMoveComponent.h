#pragma once
#include "BaseComponent.h"
class HexGrid;
class Move;
class GridMoveComponent : public BaseComponent
{
public:
	GridMoveComponent(GameObject* const parent, HexGrid* pGrid,Move* pMovement,Transform* pObjectPos, int x, int y);
	~GridMoveComponent() = default;
	GridMoveComponent(const GridMoveComponent& other) = delete;
	GridMoveComponent(GridMoveComponent&& other) = delete;
	GridMoveComponent& operator=(const GridMoveComponent& other) = delete;
	GridMoveComponent& operator=(GridMoveComponent&& other) = delete;

	void Render() override;
	void Update(const float& deltaTime) override;

private:
	HexGrid* m_pObjectGrid;
	Move* m_pMovementType;
	int m_X;
	int m_Y;
	Transform* m_pPosition;
};

