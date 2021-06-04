#pragma once
#include <BaseComponent.h>
class MainMenu;
class GameObject;
class MenuComponent final: public BaseComponent
{
public:
	MenuComponent(GameObject* const parent, MainMenu* pMenu);
	~MenuComponent() = default;
	MenuComponent(const MenuComponent& other) = delete;
	MenuComponent(MenuComponent&& other) = delete;
	MenuComponent& operator=(const MenuComponent& other) = delete;
	MenuComponent& operator=(MenuComponent&& other) = delete;

	void Render() override;
	void Update(const float& deltaTime) override;
private:
	MainMenu* m_pMenu;
};

