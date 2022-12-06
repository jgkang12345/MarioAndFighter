#pragma once
#include "GameObject.h"
class Sprite;
class Player : public GameObject
{
private:
	Sprite* m_sprite;
public:
	Player() : GameObject(PlayerObj) {};
	~Player();
public:
	void SetSprite(Sprite* _sprite) { m_sprite = _sprite; };
	void Update();
	Sprite* GetSprite() { return m_sprite; }
};

