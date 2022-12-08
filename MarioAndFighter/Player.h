#pragma once
#include "GameObject.h"
#include <Windows.h>
class Sprite;
class Player : public GameObject
{
private:
	Sprite* m_sprite;
public:
	Player() : GameObject(PlayerObj) {};
	virtual ~Player() {};
public:
	void SetSprite(Sprite* _sprite) { m_sprite = _sprite; };
	void Update(class Map* _map);
	void Render(class GameWnd* _wnd);
	Sprite* GetSprite() { return m_sprite; }
	void KeyUpBind(WPARAM _wparam);
	void KeyDownBind(WPARAM _param);
};

