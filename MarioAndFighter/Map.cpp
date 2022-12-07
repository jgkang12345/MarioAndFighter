#include "Map.h"
#include "Type.h"
#include <stdio.h>
#include <string.h>
#include "FileUtils.h"
#include "Player.h"
#include "Map.h"
#include "Type.h"
#include "ResourceManger.h"
Map::Map(const MapDataBinaryFile& _data)
{
	FileUtils::GetFileName(_data.fileName, m_filePath);
	FileUtils::GetFileName(_data.imgFileName, m_imgFilePath);
	m_XSize = _data.xSize;
	m_YSize = _data.ySize;

	m_mapData = new int* [_data.ySize];
	for (int y = 0; y < _data.ySize; y++) 
	{
		m_mapData[y] = new int[_data.xSize];
		memset(m_mapData[y], 0, _data.xSize * 4);
	}

	for (int y = 0; y < m_YSize; y++)
	{
		for (int x = 0; x < m_XSize; x++)
		{
			m_mapData[y][x] = _data.mapData[y][x];
			if (m_mapData[y][x] == EVENT_TYPE::PlayerType)
			{
				m_player = new Player();
				m_player->SetPos({ ((((x + 1) * tileWidth) - (x * tileWidth)) / 2) + (x * tileWidth), y * tileWidth + tileWidth });
			}
		}
	}
}

Map::~Map()
{

}

void Map::Update()
{
	if (m_player)
		m_player->Update(this);
}

EVENT_TYPE Map::GetTileType(const Pos& pos)
{
	const int x = pos.x / tileWidth;
	const int y = pos.y / tileWidth;
	
	if (y < 0 || x < 0 || x >= m_XSize || y >= m_YSize || pos.x < 0 || pos.y < 0)
		return EVENT_TYPE::WALLType;

	return (EVENT_TYPE)m_mapData[y][x];
}
