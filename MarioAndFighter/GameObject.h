#pragma once
#include "Type.h"
class GameObject
{
protected:
	Pos		   m_pos = {0, 0};
	Dir		   m_dir = Dir::NONE;
	ObjectType m_objType;
	int		   m_hPower = 0;
	int		   m_vPower = 0;
public:
	GameObject(ObjectType _type) : m_objType(_type) {};
	~GameObject() {};
public:
	Pos	GetPos() { return m_pos; }
	Dir GetDir() { return m_dir; }
	ObjectType GetObjectType() { return m_objType; }

	void SetPos(const Pos& _pos) { m_pos = _pos; }
	void SetDir(Dir _dir) { m_dir = _dir; }
	void SetObjectType(ObjectType _type) { m_objType = _type; }
	void SetHPower(int _hPower) { m_hPower = _hPower; }
	void SetVPower(int _vPower) { m_vPower = _vPower; }
};

