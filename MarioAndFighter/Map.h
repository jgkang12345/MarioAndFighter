#pragma once
#include "Type.h"
#include "Player.h"
class Map
{
private:
	int** m_mapData;
	int   m_XSize;
	int   m_YSize;
	char m_filePath[256];
	char m_imgFilePath[256];
	class Player* m_player;
	class Bitmap* m_playerBitmap;
public:
	Map(const MapDataBinaryFile& file);
	~Map();
public:
	char* GetFileName() { return m_imgFilePath; }
	Player* GetPlayer() { return m_player; }
	void	Update();
	EVENT_TYPE	GetTileType(const Pos& pos);
};

