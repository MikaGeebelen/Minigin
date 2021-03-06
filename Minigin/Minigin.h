#pragma once
struct SDL_Window;
class Subject;
class ServiceLocater;

class Minigin
{
public:
	void Initialize();
	void LoadGame() const;
	void Cleanup();
	virtual void UserInitialize() = 0;
	virtual void UserLoadGame() const = 0;
	virtual void UserCleanup() = 0;
	virtual void GameUpdate(const float& deltaTime) = 0;
	void Run();
private:
	static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
	SDL_Window* m_Window{};
};
