#include "SceenManager.h"
#include "Sceen.h"
SceenManager* SceenManager::m_instance = nullptr;
SceenManager* SceenManager::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new SceenManager();
	return m_instance;
}
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

void SceenManager::KeyDownBind(WPARAM _wparam)
{
	(*m_sceens.begin())->KeyDownBind(_wparam);
}

void SceenManager::KeyUpBind(WPARAM _wparam)
{
	(*m_sceens.begin())->KeyUpBind(_wparam);
}

void SceenManager::Clean()
{

}
