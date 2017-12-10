#pragma once
#include "CharObject.h"

#define ENEMY_W 20.f
#define ENEMY_H 25.f
#define ENEMY_TU 0.097f
#define ENEMY_TV 0.488f

#define ENEMY_INNTIAL_POSX 100.f
#define ENEMY_INNTIAL_POSY 100.f 



class Enemy : public CharObjectBase{
public:
	/*enum EnemyNumber {
		ONE,
		TWO,
		THREE,
		FOUR
	};*/
	enum EnemyDirection {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	Enemy();
	virtual ~Enemy();
	virtual void Draw();
	virtual void Update();
	int* GetEnemyTexture(){return &m_EnemyTexture;}
private:
	/*static int m_EnemyNum;
	int m_EnemyId;*/
	int m_EnemyTexture;
	D3DXVECTOR2 m_Pos;
	EnemyDirection m_Direction;
};

