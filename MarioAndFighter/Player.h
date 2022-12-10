#pragma once
#include "GameObject.h"
#include <Windows.h>
#include "Type.h"
class Sprite;
class Animation;
class Player : public GameObject
{
private:
	SCEEN_STATE m_sceen_state;
	Animation* m_leftMove;
	Animation* m_topMove;
	Animation* m_downMove;
	Animation* m_idle;
public:
	Player() : GameObject(PlayerObj) {};
	virtual ~Player() {};
public:
	void SetLeftMove(Animation* _ani) { m_leftMove = _ani; };
	void SetTopMove(Animation* _ani) { m_topMove = _ani; };
	void SetDownMove(Animation* _ani) { m_downMove = _ani; };
	void SetIdle(Animation* _ani);
	void Update(class Map* _map);
	void Render(class GameWnd* _wnd);
	void KeyUpBind(WPARAM _wparam);
	void KeyDownBind(WPARAM _param);
	void SetSceenState(SCEEN_STATE _state) { m_sceen_state = _state; }
	void BattleUpdate(Map* _map);
	void OverWorldUpdate(Map* _map);
};

