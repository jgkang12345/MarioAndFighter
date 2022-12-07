#pragma once
#include <list>
#include <Windows.h>
class Sceen;
class GameWnd;
class SceenManager
{
private:
	static SceenManager* m_instance;
	std::list<Sceen*> m_sceens;
public:
	SceenManager() { };
	~SceenManager() { Clean(); };
public:
	static SceenManager* GetInstance();
	void	Update(GameWnd* _wnd);
	void	Render(GameWnd* _wnd);
	void	Init(GameWnd* _wnd);
	void	KeyDownBind(WPARAM _wparam);
	void	KeyUpBind(WPARAM _wparam);
	void	Clean();
};

