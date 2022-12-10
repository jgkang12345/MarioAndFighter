#include "GameSceen.h"
#include "Map.h"
#include "Camera.h"
#include "ResourceManger.h"
#include "GameWnd.h"
#include "Animation.h"
#include "Type.h"
void GameSceen::Update(GameWnd* _wnd)
{
	Map* map = *m_map.begin();

	if (map && m_camera && m_player)
	{
		map->Update(m_player);
		m_camera->Update(m_player, map);
	}
}

void GameSceen::Render(GameWnd* _wnd)
{
	ID2D1Bitmap* bitmap;
	_wnd->GetBRT()->BeginDraw();
	_wnd->GetBRT()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	Map* map = *m_map.begin();
	if (map)
		map->Render(_wnd);
	m_player->Render(_wnd);

	_wnd->GetBRT()->EndDraw();
	_wnd->GetBRT()->GetBitmap(&bitmap);
	_wnd->GetRT()->BeginDraw();

	RECT rect;
	GetClientRect(_wnd->GetHwnd(), &rect);
	D2D1_RECT_F rt_dest = { rect.left, rect.top, rect.right, rect.bottom };
	if (bitmap)
		_wnd->GetRT()->DrawBitmap(bitmap, rt_dest, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, m_camera->GetCameraRect());
	_wnd->GetRT()->EndDraw();
}

void GameSceen::Init(GameWnd* _wnd)
{
	m_player = new Player();
	m_player->SetFilePath("overworld_mario.png");
	m_player->SetLeftMove(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("playerLeftMove2.spr")));
	m_player->SetDownMove(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("playerDownMove.spr")));
	m_player->SetTopMove(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("playerUpMove.spr")));
	m_player->SetIdle(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("playerIdle.spr")));
	ResourceManger::GetBitmap(m_player->GetFilePath(), _wnd->GetRRT());
	const char* aa[mapCount] = { "stage1.map" };
	for (int i = 0; i < mapCount; i++) 
	{
		Map* tempV = new Map(aa[i], m_player, _wnd);
		ResourceManger::GetBitmap(tempV->GetFileName(), _wnd->GetRRT());
		m_map.push_back(tempV);
	}	
	m_camera = new Camera(m_player->GetPos().x, m_player->GetPos().y, *m_map.begin());
}

void GameSceen::Clean()
{
}

void GameSceen::KeyDownBind(WPARAM _param)
{
	m_player->KeyDownBind(_param);
}

void GameSceen::KeyUpBind(WPARAM _wparam)
{
	m_player->KeyUpBind(_wparam);
}
