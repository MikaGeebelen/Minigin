#pragma once
struct SDL_Window;
class imguiMenu
{
public:
	imguiMenu() = default;
	virtual ~imguiMenu();
	imguiMenu(const imguiMenu& other) = delete;
	imguiMenu(imguiMenu&& other) = delete;
	imguiMenu& operator=(const imguiMenu& other) = delete;
	imguiMenu& operator=(imguiMenu&& other) = delete;
	
	virtual void render() = 0;
	void AddWindow(SDL_Window* pWindow);
protected:
	SDL_Window* m_pWindow = nullptr;

};

