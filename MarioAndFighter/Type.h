#pragma once
#include<d2d1.h>
struct Pos
{
	int x;
	int	y;
};

enum ObjectType : int
{
	PlayerObj = 100,
	NefendesObj = 200,
	GhostObj = 300,
	KumaObj = 400
};

enum Dir : int
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
	NONE = 4
};

struct MapDataBinaryFile
{
	char imgFileName[256]; // path
	char fileName[256];
	int xSize;
	int ySize;
	int mapData[256][256];
};

struct ObjDataBinaryFile
{
	char fileName[256]; // path
	int  xPos;
	int  yPos;
	int  width;
	int  height;
	D2D1_POINT_2F pivotPos;
	int  objectCode;
};

struct SpriteBinaryFileHeader
{
	char fileName[256];
	int resourceType;
	int  spriteCount;
};

struct SpriteBinaryFileData
{
	D2D1_RECT_F		rect;
	D2D1_POINT_2F	pivotPos;
};

enum EVENT_TYPE : int
{
	EMPTYType = 0,
	WALLType = 1,
	PlayerType = 2,
	NefendesType = 3,
	GhostType = 4,
	KumaType = 5
};


enum RESOURCE_TYPE : int
{
	SPRITE = 0,
	ANIMATION = 1,
	EVENT = 2,
	MAP = 3,
	GAME_OBJECT = 4
};

#define magnification 2.0
#define tileWidth 16
#define cameraW	100
#define cameraH 100
#define boundW 50
#define boundH 50