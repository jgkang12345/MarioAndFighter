#include "pch.h"
#include "GameManager.h"
#include "GameWnd.h"
void GameManager::Init()
{

}

void GameManager::Render()
{
	ID2D1Bitmap* bitmap;
	m_wnd->GetBRT()->BeginDraw();
	m_wnd->GetBRT()->Clear(D2D1::ColorF(D2D1::ColorF::DarkGray));

	/**
	*	이부분에 렌더링 작업을 합니다.
	**/

	
	m_wnd->GetBRT()->SetTransform(D2D1::Matrix3x2F::Scale(D2D1::Size(2.0, 2.0)));
	m_wnd->GetBRT()->EndDraw();
	m_wnd->GetBRT()->GetBitmap(&bitmap);

	m_wnd->RenderProcess(bitmap);
}

void GameManager::Update()
{

}
