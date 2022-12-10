#include "Player.h"
#include "Sprite.h"
#include "Map.h"
#include "Type.h"
#include "GameWnd.h"
#include <stdlib.h>
#include <stdio.h>
#include "ResourceManger.h"
#include "Bitmap.h"
#include "Animation.h"
#include "FPSManager.h"
void Player::SetIdle(Animation* _ani)
{
	m_idle = _ani; 
}
void Player::Update(Map* _map)
{

	switch (m_sceen_state)
	{
	case OVER_WORLD:
		OverWorldUpdate(_map);
		break;

	case BATTLE:
		BattleUpdate(_map);
		break;
	}
}

void Player::Render(GameWnd* _wnd)
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

	const int width = abs((int) (frame->GetRect().left - frame->GetPivot().x));
	const int height = abs((int) (frame->GetRect().top - frame->GetPivot().y));
	D2D1_RECT_F dest = { m_pos.x - width, m_pos.y - height, m_pos.x + width, m_pos.y };
	if (isRotate)
		_wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Scale(-1.0, 1.0, D2D1::Point2F(m_pos.x, m_pos.x)));
	_wnd->GetBRT()->DrawBitmap(ResourceManger::GetBitmap(m_filePath, _wnd->GetRRT())->GetBitmap(), dest, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, frame->GetRect());
	if (isRotate)
		_wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void Player::KeyUpBind(WPARAM _wparam)
{
	switch (_wparam)
	{
	case VK_UP:
		if (m_dir == Dir::UP)
			m_dir = Dir::NONE;
		break;

	case VK_RIGHT:
		if (m_dir == Dir::RIGHT)
			m_dir = Dir::NONE;
		break;

	case VK_DOWN:
		if (m_dir == Dir::DOWN)
			m_dir = Dir::NONE;
		break;

	case VK_LEFT:
		if (m_dir == Dir::LEFT)
			m_dir = Dir::NONE;
		break;
	}
}

void Player::KeyDownBind(WPARAM _param)
{
	switch (_param)
	{
	case VK_UP:
		m_dir = Dir::UP;
		break;

	case VK_RIGHT:
		m_dir = Dir::RIGHT;
		break;

	case VK_DOWN:
		m_dir = Dir::DOWN;
		break;

	case VK_LEFT:
		m_dir = Dir::LEFT;
		break;
	}
}

void Player::BattleUpdate(Map* _map)
{

}

void Player::OverWorldUpdate(Map* _map)
{
	switch (m_dir)
	{
	case UP:
		m_vPower = -powerY;
		m_hPower = 0;
		break;
	case RIGHT:
		m_hPower = powerY;
		m_vPower = 0;
		break;
	case DOWN:
		m_vPower = powerY;
		m_hPower = 0;
		break;
	case LEFT:
		m_hPower = -powerY;
		m_vPower = 0;
		break;
	case NONE:
		m_vPower = 0;
		m_hPower = 0;
		break;
	}

	Pos prevPos = m_pos;
	Pos nextPos = { m_pos.x + m_hPower , m_pos.y + m_vPower };

	switch (_map->GetTileType(nextPos))
	{
	case EMPTYType:
		m_pos = nextPos;
		break;
	case WALLType:
		m_vPower = 0;
		m_hPower = 0;
		break;
	case PlayerType:
		m_pos = nextPos;
		break;
	case NefendesType:
		m_vPower = 0;
		m_hPower = 0;
		break;
	case GhostType:
		m_vPower = 0;
		m_hPower = 0;
		break;
	case KumaType:
		m_vPower = 0;
		m_hPower = 0;
		break;
	case NefendesRect:
		m_vPower = 0;
		m_hPower = 0;
		break;
	}
}
