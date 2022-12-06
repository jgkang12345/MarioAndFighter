#include "Sceen.h"
#include "GameWnd.h"
#include "ResourceManger.h"
#include "D2D1Core.h"
#include "Map.h"
#include "Bitmap.h"
#include "Type.h"
#include "Sprite.h"
#include "Camera.h"
void Sceen::Update(GameWnd* _wnd)
{
	if (m_map)
		m_map->Update();
}

void Sceen::Render(GameWnd* _wnd)
{
	ID2D1Bitmap* bitmap;
	Player* player = m_map->GetPlayer();
	_wnd->GetBRT()->BeginDraw();
	_wnd->GetBRT()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	_wnd->GetBRT()->DrawBitmap(ResourceManger::GetBitmap(m_map->GetFileName(), _wnd->GetRRT())->GetBitmap());

	const int pivotX = player->GetPos().x;
	const int pivotY = player->GetPos().y;

	const int width = abs(player->GetSprite()->GetRect().left - player->GetSprite()->GetPivot().x);
	const int height = abs(player->GetSprite()->GetRect().top - player->GetSprite()->GetPivot().y);

	D2D1_RECT_F dest = { pivotX - width, player->GetPos().y - height, pivotX + width, player->GetPos().y };

	_wnd->GetBRT()->DrawBitmap(ResourceManger::GetBitmap(player->GetFilePath(), _wnd->GetRRT())->GetBitmap(),dest,1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,player->GetSprite()->GetRect());

	// _wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Scale(D2D1::Size(magnification, magnification)));
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

void Sceen::Init(const char* _mapPath, GameWnd* _wnd)
{
	m_map = reinterpret_cast<Map*>(ResourceManger::LoadBinaryData(_mapPath));

	ResourceManger::GetBitmap(m_map->GetFileName(), _wnd->GetRRT());
	Player* player = m_map->GetPlayer();
	player->SetFilePath("overworld_mario.png");
	Sprite* playerSprite = reinterpret_cast<Sprite*>(ResourceManger::LoadBinaryData("stage1Player.spr"));
	player->SetSprite(playerSprite);
	ResourceManger::GetBitmap(player->GetFilePath(), _wnd->GetRRT());
	
	const int pivotX = player->GetPos().x;
	const int pivotY = player->GetPos().y;

	D2D1_RECT_F cameraZone = { pivotX - cameraW, pivotY - cameraH, pivotX + cameraW, pivotY + cameraH };
	D2D1_RECT_F boundZone = { pivotX - boundW, pivotY - boundH, pivotX + boundW, pivotY + boundH };
	m_camera = new Camera(cameraZone, boundZone);
}

void Sceen::Clean()
{
}
