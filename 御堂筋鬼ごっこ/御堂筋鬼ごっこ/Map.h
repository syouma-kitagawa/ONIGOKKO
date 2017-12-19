#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>

#define MAPTIP_W 25
#define MAPTIP_H 25

#define MAPTIP_NUM_W 34
#define MAPTIP_NUM_H 28

#define MAP_WIDTH 855
#define MAP_HEIGHT 690



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

