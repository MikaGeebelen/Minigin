#pragma once
namespace dae
{
	class GameObject;
}

class BaseScript
{
public:
	BaseScript(dae::GameObject* const parent);
	virtual ~BaseScript();
	BaseScript(const BaseScript& other) = delete;
	BaseScript(BaseScript&& other) = delete;
	BaseScript& operator=(const BaseScript& other) = delete;
	BaseScript& operator=(BaseScript&& other) = delete;

	virtual void Update(const float& deltaTime) = 0;

	dae::GameObject* m_pParent;
};

