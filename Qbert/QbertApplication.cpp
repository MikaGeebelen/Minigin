#include "QbertApplication.h"

#include <string>
#include <vector>
#include <memory>

#include <InputManager.h>
#include <ResourceManager.h>
#include <SceneManager.h>
#include <GameObject.h>
#include <Scene.h>
//components
#include <TransformComponent.h>
#include <TextRenderComponent.h>
#include <TextureRenderComponent.h>
#include <TimeComponent.h>
#include <ObserverComponent.h>
#include <SubjectComponent.h>
//observer
#include <Observer.h>
#include <Lives.h>
#include <Score.h>
//services
#include <ServiceLocater.h>

void QbertApplication::UserInitialize()
{
}

void QbertApplication::UserLoadGame() const
{
	ResourceManager::GetInstance().Init("../Data/");
	Scene& start = SceneManager::GetInstance().CreateScene("StartScreen");
	std::shared_ptr<GameObject> startScreen = std::make_shared<GameObject>();
	startScreen->AddComponent(new TransformComponent(startScreen.get(), 0.f, 0.f, 0.f));
	TextureRenderComponent* menuPicture = new TextureRenderComponent(startScreen.get(), "Start01.png");
	startScreen->AddComponent(menuPicture);
	std::vector<std::shared_ptr<Texture2D>> menuIcons;
	menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start01.png"));
	menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start02.png"));
	menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start03.png"));
	InputManager::GetInstance().AddKeyBoardCommand("MenuUp", SDL_SCANCODE_UP, ActionType::pressed, new CycleThroughMenu(menuPicture, menuIcons));
	InputManager::GetInstance().AddKeyBoardCommand("MenuDown", SDL_SCANCODE_DOWN, ActionType::pressed, new CycleThroughMenu(menuPicture, menuIcons, false));
	start.Add(startScreen);
}

void QbertApplication::UserCleanup()
{
}
