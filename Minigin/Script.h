#pragma once
class GameObject;
class Script
{
public:
	virtual void Start() = 0;
	virtual void Update(const float& deltaTime) = 0;
	void SetParent(GameObject* parent);
protected:
	GameObject* m_pGameObject;
};
