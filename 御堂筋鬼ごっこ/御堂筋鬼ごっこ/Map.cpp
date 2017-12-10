#include "Map.h"
#include "DirectGraphics.h"



Map::Map()
{
	FILE *fp = NULL;
	fopen_s(&fp, "CSV/Map.csv", "r");

    m_MapDate = new int*[MAP_H];
	for (int x = 0; x < MAP_H; x++) {
		m_MapDate[x] = new int[MAP_W];
	}
	int CollisionCount = 0;
	for (int i = 0; i < MAP_H; i++) {
		for (int j = 0; j < MAP_W; j++) {
			m_MapDate[i][j] = 0;
			fscanf_s(fp, "%d,", &m_MapDate[i][j]);
			/*if (m_CookieDate[i][j] == 1) {
				m_Collision.push_back(new Collision);
				CollisionManager::GetcollisionManager()->AddCollision(m_Collision[CollisionCount]);
				m_Collision[CollisionCount]->SetCoolisionId(Collision::COOKIE);
			}*/
		}
	}
	fclose(fp);
}


Map::~Map()
{
}

void Map::Draw()
{
	CUSTOMVERTEX  MapVertex[4]
	{
		{ 0, 0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ DISPLAY_WIDTH, 0, 1.f, 1.f, 0xFFFFFFFF,1.f, 0.f },
		{ DISPLAY_WIDTH,  DISPLAY_HIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,  DISPLAY_HIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f,1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_MapTexture, MapVertex);
}
