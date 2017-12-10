#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>

#define MAP_W 25
#define MAP_H 25

#define DISPLAY_WIDTH 850
#define DISPLAY_HIGHT 700



class Map
{
public:
	Map();
	~Map();
	void Draw();
	int* GetMapTexture() { return &m_MapTexture; }
	int** GetMapDate() { return m_MapDate; }
private:
	int m_MapTexture;
	//std::vector<Collision*> m_Collision;
	int m_Map;
	int** m_MapDate;
};

