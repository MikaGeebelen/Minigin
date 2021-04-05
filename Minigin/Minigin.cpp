#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "GameObject.h"
#include "Scene.h"
//components
#include "TransformComponent.h"
#include "TextRenderComponent.h"
#include "TextureRenderComponent.h"
#include "TimeComponent.h"
//observer
#include "Subject.h"
#include "Obserever.h"
#include "Lives.h"
#include "Score.h"
//services
#include "ServiceLocater.h"


using namespace std;
using namespace std::chrono;

void Minigin::Initialize()
{
	m_pSubject = new Subject();
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void Minigin::LoadGame() const
{
	ServiceLocater::RegisterSoundSystem(new SoundSystem());
	ServiceLocater::GetSoundSystem().play("../Data/Diamond.wav",100);
	ServiceLocater::GetSoundSystem().play("../Data/Ouch.wav", 100);
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(),0.f, 0.f, 0.f));
	go->AddComponent(new TextureRenderComponent(go.get(), "background.jpg"));
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 216.f, 180.f, 0.f));
	go->AddComponent(new TextureRenderComponent(go.get(),"logo.png" ));
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 80.f, 20.f, 0.f));
	go->AddComponent(new TextRenderComponent(go.get(), "Programming 4 Assignment", font));
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 0.f, 0.f, 0.f));
	go->AddComponent(new TextRenderComponent(go.get(), "00FPS", font));
	go->AddComponent(new TimeComponent(go.get(),true));
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 0.f, 400.f, 0.f));
	TextRenderComponent* pLives = new TextRenderComponent(go.get(), "Lives: 5", font);
	Lives* livesObserver = new Lives(pLives, 5);
	go->GetSubject()->AddObserver(livesObserver);
	go->AddComponent(pLives);
	scene.Add(go);
	
	InputManager::GetInstance().AddKeyBoardCommand("die1", SDL_SCANCODE_Q, ActionType::pressed, new Die(go->GetSubject()));

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 0.f, 430.f, 0.f));
	TextRenderComponent* pScore = new TextRenderComponent(go.get(), "Score: 0", font);
	Score* pScoreObserver = new Score(pScore, 0);
	go->GetSubject()->AddObserver(pScoreObserver);
	go->AddComponent(pScore);
	scene.Add(go);
	
	InputManager::GetInstance().AddKeyBoardCommand("Score1", SDL_SCANCODE_A, ActionType::pressed, new GainPoints(go->GetSubject()));
	
	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 400.f, 400.f, 0.f));
	pLives = new TextRenderComponent(go.get(), "Lives: 5", font);
	livesObserver = new Lives(pLives, 5);
	go->GetSubject()->AddObserver(livesObserver);
	go->AddComponent(pLives);
	scene.Add(go);
	
	InputManager::GetInstance().AddKeyBoardCommand("die2", SDL_SCANCODE_W, ActionType::pressed, new Die(go->GetSubject()));

	go = std::make_shared<GameObject>();
	go->AddComponent(new TransformComponent(go.get(), 400.f, 430.f, 0.f));
	pScore = new TextRenderComponent(go.get(), "Score: 0", font);
	pScoreObserver = new Score(pScore, 0);
	go->GetSubject()->AddObserver(pScoreObserver);
	go->AddComponent(pScore);
	scene.Add(go);
	
	InputManager::GetInstance().AddKeyBoardCommand("Score2", SDL_SCANCODE_S, ActionType::pressed, new GainPoints(go->GetSubject()));

	InputManager::GetInstance().AddKeyBoardCommand("DSound", SDL_SCANCODE_E, ActionType::pressed, new DiamondSound());
	InputManager::GetInstance().AddKeyBoardCommand("OSound", SDL_SCANCODE_D, ActionType::pressed, new OuchSound());
	InputManager::GetInstance().AddKeyBoardCommand("Switch1", SDL_SCANCODE_R, ActionType::pressed, new SwitchToLogSoundSystem());
	InputManager::GetInstance().AddKeyBoardCommand("Switch2", SDL_SCANCODE_F, ActionType::pressed, new SwitchToRegularSoundSystem());
}

void Minigin::Cleanup()
{
	ServiceLocater::DestroySoundSystem();
	delete m_pSubject;
	
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		bool doContinue = true;
		auto lastTime = high_resolution_clock::now();
		
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			float deltaTime = duration<float>(currentTime - lastTime).count();
			
			doContinue = input.ProcessInput();
			sceneManager.Update(deltaTime);
			renderer.Render();

			lastTime = currentTime;
		}
	}

	Cleanup();
}
