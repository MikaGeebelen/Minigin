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

//game
#include "HexGrid.h"
#include "Qbert.h"
#include "Coily.h"

#include "GridManager.h"

//lua
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int LuaAddPlayer(lua_State* L);
int LuaGenerateGrid(lua_State* L);
int LuaCreateScene(lua_State* L);
int LuaSetSceneActive(lua_State* L);

void QbertApplication::UserInitialize()
{
}

void QbertApplication::UserLoadGame() const
{
	//ResourceManager::GetInstance().Init("../Data/");
	//Scene& start = SceneManager::GetInstance().CreateScene("StartScreen");
	//std::shared_ptr<GameObject> startScreen = std::make_shared<GameObject>();
	//startScreen->AddComponent(new TransformComponent(startScreen.get(), -650.f, -300.f, -0.f));
	//TextureRenderComponent* menuPicture = new TextureRenderComponent(startScreen.get(), "Start01.png");
	//startScreen->AddComponent(menuPicture);
	//std::vector<std::shared_ptr<Texture2D>> menuIcons;
	//menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start01.png"));
	//menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start02.png"));
	//menuIcons.push_back(ResourceManager::GetInstance().LoadTexture("Start03.png"));
	//InputManager::GetInstance().AddKeyBoardCommand("MenuDown", SDL_SCANCODE_DOWN, ActionType::pressed, new CycleThroughMenu(menuPicture, menuIcons));
	//InputManager::GetInstance().AddKeyBoardCommand("ChooseMode", SDL_SCANCODE_KP_ENTER, ActionType::pressed, new CycleThroughMenu(menuPicture, menuIcons));
	//start.Add(startScreen);
	//start.SetIsSceneActive(true);
		
	//ServiceLocater::GetSoundSystem().play("../Data/Diamond.wav",100);
	//ServiceLocater::GetSoundSystem().play("../Data/Ouch.wav", 100);
	//auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	//auto go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(),0.f, 0.f, 0.f));
	//go->AddComponent(new TextureRenderComponent(go.get(), "background.jpg"));
	//scene.Add(go);
	
	/*
	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 216.f, 180.f, 0.f));
	//go->AddComponent(new TextureRenderComponent(go.get(),"logo.png" ));
	//scene.Add(go);

	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 80.f, 20.f, 0.f));
	//go->AddComponent(new TextRenderComponent(go.get(), "Programming 4 Assignment", font));
	//scene.Add(go);

	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 0.f, 0.f, 0.f));
	//go->AddComponent(new TextRenderComponent(go.get(), "00FPS", font));
	//go->AddComponent(new TimeComponent(go.get(),true));
	//scene.Add(go);

	////Qbert 1
	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 0.f, 0.f, 0.f));
	//SubjectComponent* pQbertSubject = new SubjectComponent(go.get());
	//go->AddComponent(pQbertSubject);
	//scene.Add(go);
	//
	//InputManager::GetInstance().AddKeyBoardCommand("die1", SDL_SCANCODE_Q, ActionType::pressed, new Die(pQbertSubject));
	//InputManager::GetInstance().AddKeyBoardCommand("Score1", SDL_SCANCODE_A, ActionType::pressed, new GainPoints(pQbertSubject));

	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 0.f, 400.f, 0.f));
	//TextRenderComponent* pLives = new TextRenderComponent(go.get(), "Lives: 5", font);
	//ObserverComponent* pQbertLives = new ObserverComponent(go.get(), new Lives(pLives, 5));
	//go->AddComponent(pQbertLives);
	//pQbertSubject->AddObserver(pQbertLives);
	//go->AddComponent(pLives);
	//scene.Add(go);

	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 0.f, 430.f, 0.f));
	//TextRenderComponent* pScore = new TextRenderComponent(go.get(), "Score: 0", font);
	//ObserverComponent* pQbertScoreObserver = new ObserverComponent(go.get(),new Score(pScore, 0));
	//go->AddComponent(pQbertScoreObserver);
	//pQbertSubject->AddObserver(pQbertScoreObserver);
	//go->AddComponent(pScore);
	//scene.Add(go);
	//
	////Qbert 2
	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 0.f, 0.f, 0.f));
	//pQbertSubject = new SubjectComponent(go.get());
	//go->AddComponent(pQbertSubject);
	//scene.Add(go);
	//
	//InputManager::GetInstance().AddKeyBoardCommand("die2", SDL_SCANCODE_W, ActionType::pressed, new Die(pQbertSubject));
	//InputManager::GetInstance().AddKeyBoardCommand("Score2", SDL_SCANCODE_S, ActionType::pressed, new GainPoints(pQbertSubject));
	//
	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 400.f, 400.f, 0.f));
	//pLives = new TextRenderComponent(go.get(), "Lives: 5", font);
	//pQbertLives = new ObserverComponent(go.get(), new Lives(pLives, 5));
	//go->AddComponent(pQbertLives);
	//pQbertSubject->AddObserver(pQbertLives);
	//go->AddComponent(pLives);
	//scene.Add(go);
	//
	//go = std::make_shared<GameObject>();
	//go->AddComponent(new TransformComponent(go.get(), 400.f, 430.f, 0.f));
	//pScore = new TextRenderComponent(go.get(), "Score: 0", font);
	//pQbertScoreObserver = new ObserverComponent(go.get(), new Score(pScore, 0));
	//go->AddComponent(pQbertScoreObserver);
	//pQbertSubject->AddObserver(pQbertScoreObserver);
	//go->AddComponent(pScore);
	//scene.Add(go);
	//scene.SetIsSceneActive(true);
	//InputManager::GetInstance().AddKeyBoardCommand("DSound", SDL_SCANCODE_E, ActionType::pressed, new DiamondSound());
	//InputManager::GetInstance().AddKeyBoardCommand("OSound", SDL_SCANCODE_D, ActionType::pressed, new OuchSound());
	//InputManager::GetInstance().AddKeyBoardCommand("Switch1", SDL_SCANCODE_R, ActionType::pressed, new SwitchToLogSoundSystem());
	//InputManager::GetInstance().AddKeyBoardCommand("Switch2", SDL_SCANCODE_F, ActionType::pressed, new SwitchToRegularSoundSystem());
	*/

	//srand((unsigned int)time(nullptr));
	//
	//Transform temp{};
	//temp.SetPosition(300, 100, 0);
	//HexGrid* pGrid = new HexGrid(temp, 25.f, 7, 2, { "../Data/Tiles/CubeOrange.png","../Data/Tiles/CubePurple.png" },true);

	//for(std::shared_ptr<GameObject> object: pGrid->GetGameObjects())
	//{
	//	scene.Add(object);
	//}
	//scene.Add(pGrid->SpawnDiskTile());
	//
	//Qbert* pQbert = new Qbert(1, 6, 0, "../Data/Qbert.png", pGrid);
	//scene.Add(pQbert->GetGameObject());
	//pQbert = new Qbert(2, 6, 6, "../Data/Qbert.png", pGrid);
	//scene.Add(pQbert->GetGameObject());
	//Coily* pCoily = new Coily(0, 0, "../Data/Coily.png",pGrid);
	//scene.Add(pCoily->GetGameObject());
	//
	//scene.SetIsSceneActive(true);

	std::vector<SceneManager::LuaFunctions> functions{};
	SceneManager::LuaFunctions function{"CreateScene",LuaCreateScene};
	functions.push_back(function);
	function = { "GenerateGrid",LuaGenerateGrid };
	functions.push_back(function);
	function = { "AddPlayer",LuaAddPlayer };
	functions.push_back(function);

	SceneManager::GetInstance().CreateScene("../Level1.Lua", functions);
	
}

void QbertApplication::UserCleanup()
{
}

int LuaAddPlayer(lua_State* L)
{
	HexGrid* pGrid = GridManager::GetInstance().GetCurrentGrid();
	Qbert* pQbert = new Qbert((int)lua_tonumber(L, 2), (int)lua_tonumber(L, 3), (int)lua_tonumber(L, 4), lua_tostring(L, 5), pGrid);
	
	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(L, 1));
	scene->Add(pQbert->GetGameObject());
	return 0;
}

int LuaGenerateGrid(lua_State* L)
{
	Transform temp{};
	temp.SetPosition((float)lua_tonumber(L,2), (float)lua_tonumber(L, 3), (float)lua_tonumber(L, 4));
	std::vector<std::string> paths;
	int textures = (int)lua_tonumber(L, 7);
	for (int i{9}; i < textures + 9; i++)
	{
		paths.push_back(lua_tostring(L, i));
	}
	GridManager::GetInstance().SetCurrentGrid(new HexGrid(temp, (float)lua_tonumber(L, 5), (int)lua_tonumber(L, 6), (int)lua_tonumber(L, 7), paths , lua_toboolean(L,8)));
	
	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(L, 1));
	for (std::shared_ptr<GameObject> object : GridManager::GetInstance().GetCurrentGrid()->GetGameObjects())
	{
		scene->Add(object);
	}
	return 0;
}

int LuaCreateScene(lua_State* L)
{
	auto& scene = SceneManager::GetInstance().CreateScene(lua_tostring(L, 1));
	scene.SetIsSceneActive(true);
	return 0;
}