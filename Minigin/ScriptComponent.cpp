#include "MiniginPCH.h"
#include "ScriptComponent.h"

#include "Script.h"
ScriptComponent::ScriptComponent(GameObject* const parent, Script* script)
	:BaseComponent(parent, false, true)
	,m_pScript(script)
{
	m_pScript->SetParent(parent);
	m_pScript->Start();
}

void ScriptComponent::Update(const float& deltaTime)
{
	m_pScript->Update(deltaTime);
}
