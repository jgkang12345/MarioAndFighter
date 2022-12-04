#pragma once
#include <Windows.h>
class GameWnd;
class GameManager;
class MarioAndFighterApp
{
private:
	HINSTANCE	m_hInstance;
	TCHAR		m_className;
	TCHAR		m_classTitle;
	DWORD		m_width;
	DWORD		m_height;
	HWND		m_hwnd;
	GameWnd*	m_wnd;
	GameManager* m_gameManger;
public:
	MarioAndFighterApp() = default;
	~MarioAndFighterApp() {};
public:
	void	Init(HINSTANCE, const TCHAR*, const TCHAR*, DWORD, DWORD, int);
	int		Dispatch();
public:
	static LRESULT CALLBACK  WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
