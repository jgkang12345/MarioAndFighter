#pragma once
#include <Windows.h>
struct Pos;
class GameWnd;
class Sceen
{
private:
	class Map* m_map;
	class Camera* m_camera;
public:
	Sceen(const char* _mapPath, GameWnd* _wnd) { Init(_mapPath, _wnd); }
	~Sceen() { Clean(); }
public:
	void	Update(GameWnd* _wnd);
	void	Render(GameWnd* _wnd);
	void	Init(const char* _mapPath, GameWnd* _wnd);
	void	KeyDownBind(WPARAM _param);
	void	Clean();
	void	KeyUpBind(WPARAM _wparam);
	void    SettingCamera(const Pos& _pos);
	bool	IsCameraMove(const Pos& _pos);
};

