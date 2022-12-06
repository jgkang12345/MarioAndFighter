#pragma once
#include <list>
class Sceen;
class GameWnd;
class SceenManager
{
private:
	std::list<Sceen*> m_sceens;
public:
	SceenManager(GameWnd* _wnd) { Init(_wnd); };
	~SceenManager() { Clean(); };
public:
	void	Update(GameWnd* _wnd);
	void	Render(GameWnd* _wnd);
	void	Init(GameWnd* _wnd);
	void	Clean();
};

