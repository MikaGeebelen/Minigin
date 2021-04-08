#pragma once
#include "BaseComponent.h"

class Script;

class ScriptComponent :public BaseComponent
{
	ScriptComponent(GameObject* const parent, Script* script);
	virtual void Update(const float& deltaTime) override;
private:
	Script* m_pScript;
};
