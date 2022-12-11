#include "Monster.h"
#include "ResourceManger.h"
#include "GameWnd.h"
#include "Player.h"
#include "Animation.h"
#include "Sprite.h"
#include "Bitmap.h"
Monster::~Monster()
{
	if (m_leftMove)
		delete m_leftMove;

	if (m_topMove)
		delete m_topMove;

	if (m_downMove)
		delete m_downMove;
	
	if (m_idle)
		delete m_idle;
}
void Monster::Init(GameWnd* _wnd)
{
	switch (m_objType)
	{
	case NefendesObj:
		NefendesInit(_wnd);
		break;
	case GhostObj:
		GhostInit(_wnd);
		break;
	case KumaObj:
		break;
	}
}

void Monster::NefendesInit(GameWnd* _wnd)
{
	SetFilePath("NefendesObj.png");
	SetIdle(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("NeftendesAnimation.spr")));
	ResourceManger::GetBitmap(GetFilePath(), _wnd->GetRRT());
}

void Monster::GhostInit(GameWnd* _wnd)
{
	SetFilePath("Ghost.png");
	SetIdle(reinterpret_cast<Animation*>(ResourceManger::LoadBinaryData("Ghost.spr")));
	ResourceManger::GetBitmap(GetFilePath(), _wnd->GetRRT());
}

void Monster::SetIdle(Animation* _ani)
{
	m_idle = _ani;
}

void Monster::Update(Map* _map, Player* _player)
{
	switch (m_sceen_state)
	{
	case OVER_WORLD:
		OverWorldUpdate(_map, _player);
		break;

	case BATTLE:
		BattleUpdate(_map, _player);
		break;
	}
}

void Monster::Render(GameWnd* _wnd)
{
	Sprite* frame = nullptr;
	bool isRotate = false;

	switch (m_dir)
	{
	case UP:
		frame = m_topMove->GetFrame();
		break;
	case RIGHT:
		frame = m_leftMove->GetFrame();
		break;
	case DOWN:
		frame = m_downMove->GetFrame();
		break;
	case LEFT:
		frame = m_leftMove->GetFrame();
		isRotate = true;
		break;
	case NONE:
		frame = m_idle->GetFrame();
		break;
	}

	const int width = abs((int)(frame->GetRect().left - frame->GetPivot().x));
	const int height = abs((int)(frame->GetRect().top - frame->GetPivot().y));
	D2D1_RECT_F dest = { m_pos.x - width, m_pos.y - height, m_pos.x + width, m_pos.y };
	if (isRotate)
		_wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Scale(-1.0, 1.0, D2D1::Point2F(m_pos.x, m_pos.x)));
	_wnd->GetBRT()->DrawBitmap(ResourceManger::GetBitmap(m_filePath, _wnd->GetRRT())->GetBitmap(), dest, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, frame->GetRect());
	if (isRotate)
		_wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void Monster::BattleUpdate(Map* _map, Player* _player)
{
}

void Monster::OverWorldUpdate(Map* _map, Player* _player)
{
}
