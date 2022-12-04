#pragma once
#include <Windows.h>
class GameManager
{
private:
	class GameWnd* m_wnd;
public:
	~GameManager() {};
	GameManager(GameWnd* m_gameWnd) : m_wnd(m_gameWnd) {};
public:
	void	Init();
	void	Render();
	void	Update();
};

