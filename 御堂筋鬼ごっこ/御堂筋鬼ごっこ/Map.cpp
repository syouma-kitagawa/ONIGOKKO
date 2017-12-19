#include "Map.h"
#include "DirectGraphics.h"



Map::Map()
{
	FILE *fp = NULL;
	fopen_s(&fp, "CSV/Map.csv", "r");

    m_MapDate = new int*[MAPTIP_NUM_H];
	for (int x = 0; x < MAPTIP_NUM_H; x++) {
		m_MapDate[x] = new int[MAPTIP_NUM_W];
	}
	int CollisionCount = 0;
	for (int i = 0; i < MAPTIP_NUM_H; i++) {
		for (int j = 0; j < MAPTIP_NUM_W; j++) {
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
		{ MAP_WIDTH, 0, 1.f, 1.f, 0xFFFFFFFF,1.f, 0.f },
		{ MAP_WIDTH,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f,1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_MapTexture, MapVertex);
}
