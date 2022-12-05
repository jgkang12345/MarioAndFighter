#include "pch.h"
#include "GameManager.h"
#include "GameWnd.h"
#include "BitmapEntity.h"
#include "FileUtils.h"
void GameManager::Init()
{
	std::vector<TCHAR*> fileList;
	FileUtils::GetInstance()->GetFileList(fileList, _T("*"));
	TCHAR exp[256];
	for (auto& fileName : fileList) 
	{
		FileUtils::GetFileExp(fileName, exp);
		if (0 == _tcscmp(exp, _T("png")))
		{
			char* key = new char[256];
			WideCharToMultiByte(CP_ACP, 0, fileName, 256, key, 256, NULL, NULL);
			BitmapEntity::GetInstance()->Insert(key, D2D1Core::GetInstance()->LoadBitmapByFileName(m_wnd->GetRRT(),fileName));
			delete[] fileName;
		}
	}
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
