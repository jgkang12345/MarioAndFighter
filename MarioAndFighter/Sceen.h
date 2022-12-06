#pragma once
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
	void	Clean();
};

