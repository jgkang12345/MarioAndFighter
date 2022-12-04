#include "pch.h"
#include "MarioAndFighterApp.h"
#include "GameWnd.h"
#include "FPSManager.h"
#include "GameManager.h"
void MarioAndFighterApp::Init(HINSTANCE _hInstance, const TCHAR* _title, const TCHAR* _className, DWORD _width, DWORD _height, int _ncmdShow)
{
	D2D1Core::GetInstance()->Init();
	m_wnd = new GameWnd(_hInstance, _title, _className, _width, _height, _ncmdShow);
	m_gameManger = new GameManager(m_wnd);
}

int MarioAndFighterApp::Dispatch()
{
	MSG msg = {0};
	while (true) 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (g_fpsManger.Cal() && m_gameManger)
		{
			m_gameManger->Update();
			m_gameManger->Render();
		}
		Sleep(1);
	}
	return 0;
}
