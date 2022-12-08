#pragma once
#include "Sceen.h"
class GameSceen : public Sceen
{
private:
	class Map* m_map;
	class Camera* m_camera;
	class Player* m_player;
public:
	GameSceen(const char* _mapPath
		, const char* _playerPath
		, const char* _spritPath
		, GameWnd* _wnd) : Sceen() { Init(_mapPath, _playerPath, _spritPath, _wnd); }
	~GameSceen() { Clean(); }
public:
	virtual void	Update(GameWnd* _wnd) override;
	virtual void	Render(GameWnd* _wnd) override;
	virtual void	Init(const char* _mapPath, const char* _playerPath, const char* _spritPath,  GameWnd* _wnd) override;
	virtual void	Clean() override;
	virtual void	KeyDownBind(WPARAM _param) override;
	virtual void	KeyUpBind(WPARAM _wparam) override;
};

