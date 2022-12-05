#pragma once
#include <Windows.h>
#include <list>
class GameManager
{
private:
	class GameWnd* m_wnd;
	std::list<class Map*> m_map;
public:
	~GameManager() {};
	GameManager(GameWnd* m_gameWnd) : m_wnd(m_gameWnd) { Init(); };
public:
	void	Init();
	void	Render();
	void	Update();
};

