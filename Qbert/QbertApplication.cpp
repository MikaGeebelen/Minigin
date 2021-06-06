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
#include "CoilyPlayerMove.h"
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
int LuaSetLevelDifficulty(lua_State* pL);
int LuaCreateMenu(lua_State* pL);

void QbertApplication::UserInitialize()
{
}

void QbertApplication::UserLoadGame() const
{
	std::cout << "yes";
	GameManager::GetInstance().SetGame(this);
	StartGame();
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

void QbertApplication::StartGame() const
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
	function = { "SetLevelDifficulty",LuaSetLevelDifficulty };
	functions.push_back(function);
	function = { "CreateMenu",LuaCreateMenu };
	functions.push_back(function);
	
	SceneManager::GetInstance().OpenLua("Data/Levels.Lua", functions);
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
	if (lua_toboolean(pL, 6))
	{
		pQbert->AddComponent(new GridMoveComponent(pQbert.get(), pGrid, new PlayerMove((int)lua_tonumber(pL, 2), pGrid, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4)), transform, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4), lua_toboolean(pL, 6), lua_toboolean(pL, 7)));
	}
	else
	{
		pQbert->AddComponent(new GridMoveComponent(pQbert.get(), pGrid, new CoilyPlayerMove((int)lua_tonumber(pL, 2), pGrid, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4)), transform, (int)lua_tonumber(pL, 3), (int)lua_tonumber(pL, 4), lua_toboolean(pL, 6), lua_toboolean(pL, 7)));
	}

	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(pL, 1));
	scene->Add(pQbert);

	if ((int)lua_tonumber(pL, 2) == 1)
	{
		auto font = ResourceManager::GetInstance().LoadFont("Data/Lingua.otf", 36);

		std::shared_ptr<GameObject> livesTracker = std::make_shared<GameObject>();
		livesTracker->AddComponent(new TransformComponent(livesTracker.get(), 50.f, 50.f, 0.f));
		TextRenderComponent* pLives = new TextRenderComponent(livesTracker.get(), "Lives: " + std::to_string(GameManager::GetInstance().GetLives()), font);
		livesTracker->AddComponent(pLives);
		scene->Add(livesTracker);

		std::shared_ptr<GameObject> scoreTracker = std::make_shared<GameObject>();
		scoreTracker->AddComponent(new TransformComponent(scoreTracker.get(), 50.f, 80.f, 0.f));
		TextRenderComponent* pScore = new TextRenderComponent(scoreTracker.get(), "Score: " + std::to_string(GameManager::GetInstance().GetScore()), font);
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

int LuaSetLevelDifficulty(lua_State* pL)
{
	GameManager::GetInstance().Reset();
	GameManager::GetInstance().EnemySpawnerSetup(lua_toboolean(pL, 1), (float)lua_tonumber(pL, 2), lua_toboolean(pL, 3), (float)lua_tonumber(pL, 4), lua_toboolean(pL, 5), (float)lua_tonumber(pL, 6), lua_toboolean(pL, 7), (float)lua_tonumber(pL, 8));
	return 0;
}

int LuaCreateMenu(lua_State* pL)
{
	MainMenu* pMainMenu = new MainMenu();
	Renderer::GetInstance().AddImguiMenu(pMainMenu);

	auto scene = SceneManager::GetInstance().GetScene(lua_tostring(pL, 1));
	
	//menu subject
	std::shared_ptr<GameObject> go = std::make_shared<GameObject>();
	go->AddComponent(new MenuComponent(go.get(), pMainMenu));
	SubjectComponent* pSubjectMenu = new SubjectComponent(go.get());
	go->AddComponent(pSubjectMenu);
	scene->Add(go);

	//menu observer
	go = std::make_shared<GameObject>();
	ObserverComponent* pMenu = new ObserverComponent(go.get(), new MenuObserver(GameManager::GetInstance().GetGame()));
	pSubjectMenu->AddObserver(pMenu);
	go->AddComponent(pMenu);
	scene->Add(go);
	return 0;
}


