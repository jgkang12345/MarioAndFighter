#pragma once
#include <map>
#include "Bitmap.h"
class BitmapEntity
{
private:
	static BitmapEntity* m_instance;
	std::map <char*, Bitmap*> m_bitmapDB;
public:
	static BitmapEntity* GetInstance();	
	Bitmap*	 Select(char* _key);
	void	 Insert(char* _key, Bitmap* _bitmap);
};

