#pragma once
#include "BaseComponent.h"

class GameObject;
class TransformComponent :public BaseComponent
{
public:
	TransformComponent(GameObject* const parent, Transform* transform);
	TransformComponent(GameObject* const parent, const float& x, const float& y, const float& z);
	~TransformComponent();
	TransformComponent(const TransformComponent& other) = delete;
	TransformComponent(TransformComponent&& other) = delete;
	TransformComponent& operator=(const TransformComponent& other) = delete;
	TransformComponent& operator=(TransformComponent&& other) = delete;
	
	void Render() override;
	void Update(const float& deltaTime) override;

	void SetPosition(const float& x, const float& y, const float& z);
	Transform* GetTransform();
private:
	Transform* m_pTransform;
};

