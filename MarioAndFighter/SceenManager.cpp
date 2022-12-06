#include "SceenManager.h"
#include "Sceen.h"
void SceenManager::Update(GameWnd* _wnd)
{
	(*m_sceens.begin())->Update(_wnd);
}

void SceenManager::Render(GameWnd* _wnd)
{
	(* m_sceens.begin())->Render(_wnd);
}

void SceenManager::Init(GameWnd* _wnd)
{
	Sceen* sceen = new Sceen("stage1.map", _wnd);
	m_sceens.push_back(sceen);
}

void SceenManager::Clean()
{
}
