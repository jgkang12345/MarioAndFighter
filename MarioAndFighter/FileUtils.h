#pragma once
#include "pch.h"
class FileUtils
{
private:
	static FileUtils* m_instance;
public:
	FileUtils() {};
	~FileUtils() {};
public:
	static FileUtils* GetInstance();
	static void GetFileExp(IN TCHAR* _fileName, OUT TCHAR* _ret);
	static void GetFileList(std::vector<TCHAR*>& _fileList, const TCHAR* _rootPath);
};

