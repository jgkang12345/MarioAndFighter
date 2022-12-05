#pragma once
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