#include "BitmapEntity.h"
BitmapEntity* BitmapEntity::m_instance = nullptr;
BitmapEntity* BitmapEntity::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new BitmapEntity();
	return m_instance;
}

Bitmap* BitmapEntity::Select(char* _key)
{
	if (m_bitmapDB.find(_key) != m_bitmapDB.end())
		return m_bitmapDB.find(_key)->second;
	else
		return nullptr;
}

void BitmapEntity::Insert(char* _key, Bitmap* _bitmap)
{
	m_bitmapDB.insert({ _key, _bitmap });
}
