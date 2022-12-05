#pragma once
#include "Type.h"
class Map
{
private:
	int** m_mapData;
	int   m_XSize;
	int   m_YSize;
	char* m_fileName;
public:
	Map(const MapDataBinaryFile& file);
	~Map();
};

