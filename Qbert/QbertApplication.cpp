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
#include "GridMoveComponent.h"
#include "MenuComponent.h"
//movement rules
#include "PlayerMove.h"
//observer
#include <Observer.h>
#include "Lives.h"
#include "Score.h"
#include "LevelObserver.h"
#include "MenuObserver.h"
//services
#include <ServiceLocater.h>

//game
#include "HexGrid.h"

#include "GridManager.h"
#include "GameManager.h"

//menus
#include "MainMenu.h"

//lua
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int LuaAddPlayer(lua_State* pL);
int LuaGenerateGrid(lua_State* pL);
int LuaCreateScene(lua_State* pL);
int LuaSetSceneActive(lua_State* pL);

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

	auto& scene = SceneManager::GetInstance().CreateScene("Menu");
	
	MainMenu* pMainMenu = new MainMenu();
	Renderer::GetInstance().AddImguiMenu(pMainMenu);

	//menu subject
	std::shared_ptr<GameObject> go = std::make_shared<GameObject>();
	go->AddComponent(new MenuComponent(go.get(), pMainMenu));
	SubjectComponent* pSubjectMenu = new SubjectComponent(go.get());
	go->AddComponent(pSubjectMenu);
	scene.Add(go);
	
	//menu observer
	go = std::make_shared<GameObject>();
	ObserverComponent* pMenu = new ObserverComponent(go.get(), new MenuObserver(this));
	pSubjectMenu->AddObserver(pMenu);
	go->AddComponent(pMenu);
	scene.Add(go);

	SceneManager::GetInstance().SetSceneActive("Menu");

}

void QbertApplication::UserCleanup()
{
	HexGrid* pGrid = GridManager::GetInstance().GetCurrentGrid();
	delete pGrid;
	SceneManager::GetInstance().CloseLua();
}

void QbertApplication::GameUpdate(const float& deltaTime)
{
	GameManager::GetInstance().Update(deltaTime);
}

void QbertApplication::StartGame(const std::string& gameMode) const
{
	std::vector<SceneManager::LuaFunctions> functions{};
	SceneManager::LuaFunctions function{ "CreateScene",LuaCreateScene };
	functions.push_back(function);
	function = { "GenerateGrid",LuaGenerateGrid };
	functions.push_back(function);
	function = { "AddPlayer",LuaAddPlayer };
	functions.push_back(function);
	function = { "SetScene",LuaSetSceneActive };
	functions.push_back(function);

	SceneManager::GetInstance().OpenLua("../Levels.Lua", functions, gameMode);
	SceneManager::GetInstance().UseFunction(gameMode, 1);
	std::shared_ptr<Scene> scene = SceneManager::GetInstance().GetScene("Level1");
}



int LuaAddPlayer(lua_State* pL)
{
	HexGrid* pGrid = GridManager::GetInstance().GetCurrentGrid();

	std::shared_ptr<GameObject> pQbert = std::make_shared<GameObject>();
	Transform* transform = new Transform(pGrid->GetGridPosition((int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4)));
	
	pQbert->AddComponent(new TransformComponent(pQbert.get(), transform));
	pQbert->AddComponent(new TextureRenderComponent(pQbert.get(), lua_tostring(pL, 5)));
	SubjectComponent* pQSub = new SubjectComponent(pQbert.get());
	pQbert->AddComponent(pQSub);
	pQbert->AddComponent(new GridMoveComponent(pQbert.get(), pGrid, new PlayerMove((int)lua_tonumber(pL, 2), pGrid, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4)), transform, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4),lua_toboolean(pL, 6), lua_toboolean(pL, 7)));

	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(pL, 1));
	scene->Add(pQbert);

	if ((int)lua_tonumber(pL, 2) == 1)
	{
		auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

		std::shared_ptr<GameObject> livesTracker = std::make_shared<GameObject>();
		livesTracker->AddComponent(new TransformComponent(livesTracker.get(), 50.f, 50.f, 0.f));
		TextRenderComponent* pLives = new TextRenderComponent(livesTracker.get(), "Lives: " + std::to_string(GameManager::GetInstance().GetLives()), font);
		livesTracker->AddComponent(pLives);
		scene->Add(livesTracker);

		std::shared_ptr<GameObject> scoreTracker = std::make_shared<GameObject>();
		scoreTracker->AddComponent(new TransformComponent(scoreTracker.get(), 50.f, 80.f, 0.f));
		TextRenderComponent* pScore = new TextRenderComponent(scoreTracker.get(), "Score: 0", font);
		scoreTracker->AddComponent(pScore);
		scene->Add(scoreTracker);

		GameManager::GetInstance().SetScoreTextComponent(pScore);
	}
	return 0;
}

int LuaGenerateGrid(lua_State* pL)
{
	Transform temp{};
	temp.SetPosition((float)lua_tonumber(pL,2), (float)lua_tonumber(pL, 3), (float)lua_tonumber(pL, 4));
	std::vector<std::string> paths;
	int textures = (int)lua_tonumber(pL, 7);
	for (int i{9}; i < textures + 9; i++)
	{
		paths.push_back(lua_tostring(pL, i));
	}
	GridManager::GetInstance().SetCurrentGrid(new HexGrid(temp, (float)lua_tonumber(pL, 5), (int)lua_tonumber(pL, 6), (int)lua_tonumber(pL, 7), paths , lua_toboolean(pL,8)));
	
	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(pL, 1));
	for (std::shared_ptr<GameObject> object : GridManager::GetInstance().GetCurrentGrid()->GetGameObjects())
	{
		scene->Add(object);
	}

	int level = GameManager::GetInstance().GetLevel();
	lua_getglobal(pL, "gameMode");
	std::string gameMode = lua_tostring(pL, -1);
	

	std::shared_ptr<GameObject> go = std::make_shared<GameObject>();
	
	ObserverComponent* pLevelObserver = new ObserverComponent(go.get(), new LevelObserver(level,GameManager::GetInstance().GetLives(), gameMode));
	GridManager::GetInstance().GetCurrentGrid()->GetSubject()->AddObserver(pLevelObserver);
	go->AddComponent(pLevelObserver);
	scene->Add(go);

	lua_pushnumber(pL, GameManager::GetInstance().GetLevel());
	lua_setglobal(pL, "level");
	
	return 0;
}

int LuaCreateScene(lua_State* pL)
{
	std::shared_ptr<Scene> oldScene = SceneManager::GetInstance().GetScene(lua_tostring(pL, 1));
	if (oldScene != nullptr)
	{
		oldScene->ClearScene();
	}

	InputManager::GetInstance().ClearInput();
	auto& scene = SceneManager::GetInstance().CreateScene(lua_tostring(pL, 1));
	scene.SetIsSceneActive(true);
	return 0;
}

int LuaSetSceneActive(lua_State* pL)
{
	SceneManager::GetInstance().SetSceneActive(lua_tostring(pL, 1));
	return 0;
}


