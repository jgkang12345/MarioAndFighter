#pragma once
#include <d2d1.h>
class Camera
{
private:
	D2D1_RECT_F m_cameraRect;
	D2D1_RECT_F	m_boundRect;
public:
	Camera(const D2D1_RECT_F& _cameraRect, const D2D1_RECT_F& _boundRect);
	~Camera();
public:
	D2D1_RECT_F GetCameraRect() { return m_cameraRect; }
	D2D1_RECT_F GetBoundRect() { return m_boundRect; }
};

