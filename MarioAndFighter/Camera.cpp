#include "Camera.h"

Camera::Camera(const D2D1_RECT_F& _cameraRect, const D2D1_RECT_F& _boundRect)
{
	m_cameraRect = _cameraRect;
	m_boundRect = _boundRect;
}

Camera::~Camera()
{

}
