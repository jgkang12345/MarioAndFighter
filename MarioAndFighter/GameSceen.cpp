#include "GameSceen.h"
#include "Map.h"
#include "Camera.h"
#include "ResourceManger.h"
#include "GameWnd.h"
void GameSceen::Update(GameWnd* _wnd)
{
	if (m_map && m_camera && m_player)
	{
		m_map->Update(m_player);
		m_camera->Update(m_player, m_map);
	}
}

void GameSceen::Render(GameWnd* _wnd)
{
	ID2D1Bitmap* bitmap;
	_wnd->GetBRT()->BeginDraw();
	_wnd->GetBRT()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	
	m_map->Render(_wnd);
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

void GameSceen::Init(const char* _mapPath, const char* _playerPath, const char* _spritPath, GameWnd* _wnd)
{
	m_player = new Player();
	m_map = new Map(_mapPath, m_player);
	ResourceManger::GetBitmap(m_map->GetFileName(), _wnd->GetRRT());
	m_player->SetFilePath(_playerPath);
	m_player->SetSprite(reinterpret_cast<Sprite*>(ResourceManger::LoadBinaryData(_spritPath)));
	ResourceManger::GetBitmap(m_player->GetFilePath(), _wnd->GetRRT());
	m_camera = new Camera(m_player->GetPos().x, m_player->GetPos().y, m_map);
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
