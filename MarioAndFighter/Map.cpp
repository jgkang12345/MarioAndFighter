#include "Map.h"
#include "Type.h"
#include <stdio.h>
#include <string.h>
#include "FileUtils.h"
#include "Player.h"
#include "Map.h"
#include "Type.h"
#include "ResourceManger.h"
#include "GameWnd.h"
#include "Bitmap.h"
Map::Map(const char* _mapFilePath, Player* _player)
{
	FILE* p_file = NULL;
	MapDataBinaryFile* file = new MapDataBinaryFile;
	fopen_s(&p_file, _mapFilePath, "rb");
	if (p_file != NULL)
		fread(file, sizeof(MapDataBinaryFile), 1, p_file);
	if (file)
	{
		FileUtils::GetFileName((* file).fileName, m_filePath);
		FileUtils::GetFileName((*file).imgFileName, m_imgFilePath);
		m_XSize = (*file).xSize;
		m_YSize = (*file).ySize;

		m_mapData = new int* [(*file).ySize];
		for (int y = 0; y < (*file).ySize; y++)
		{
			m_mapData[y] = new int[(*file).xSize];
			memset(m_mapData[y], 0, (*file).xSize * 4);
		}

		for (int y = 0; y < m_YSize; y++)
		{
			for (int x = 0; x < m_XSize; x++)
			{
				m_mapData[y][x] = (*file).mapData[y][x];
				if (m_mapData[y][x] == EVENT_TYPE::PlayerType)
				{
					_player->SetPos({ ((((x + 1) * tileWidth) - (x * tileWidth)) / 2) + (x * tileWidth), y * tileWidth + tileWidth });
				}
			}
		}
	}
	delete file;
}

Map::~Map()
{

}

void Map::Update(Player* _player)
{
	_player->Update(this);
}

void Map::Render(GameWnd* _wnd)
{
	_wnd->GetBRT()->DrawBitmap(ResourceManger::GetBitmap(m_imgFilePath, _wnd->GetRRT())->GetBitmap());
}

EVENT_TYPE Map::GetTileType(const Pos& pos)
{
	const int x = pos.x / tileWidth;
	const int y = pos.y / tileWidth;
	
	if (y < 0 || x < 0 || x >= m_XSize || y >= m_YSize || pos.x < 0 || pos.y < 0)
		return EVENT_TYPE::WALLType;

	return (EVENT_TYPE)m_mapData[y][x];
}
