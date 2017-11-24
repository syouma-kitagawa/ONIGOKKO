#pragma once
#include "CharObject.h"

#define ENEMY_W 20.f
#define ENEMY_H 20.f
#define ENEMY_INNTIAL_POSX 100.f
#define ENEMY_INNTIAL_POSY 100.f 

class Enemy : public CharObjectBase{
public:
	Enemy();
	virtual ~Enemy();
	virtual void Draw();
	virtual void Update();
	int* GetEnemyTexture(){return &m_EnemyTexture;}
private:
	int m_EnemyTexture;
	D3DXVECTOR2 m_Pos;
};

