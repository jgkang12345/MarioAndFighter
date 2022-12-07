#include "Player.h"
#include "Sprite.h"
#include "Map.h"
#include "Type.h"
void Player::Update(Map* _map)
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
		break;
	case PlayerType:
		m_pos = nextPos;
		break;
	case NefendesType:
		break;
	case GhostType:
		break;
	case KumaType:
		break;
	}
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
