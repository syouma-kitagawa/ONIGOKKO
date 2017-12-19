#pragma once
#include "CharObject.h"
#include "Collision.h"
#include "EnemyManager.h"

#define ENEMY_W 15.f
#define ENEMY_H 20.f
#define ENEMY_TU 0.097f
#define ENEMY_TV 0.488f

#define ENEMY_INNTIAL_POSX 140.f
#define ENEMY_INNTIAL_POSY 120.f 



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
	Enemy(float InntialPosX,float InntialPosY,float NextPosX,float NextPosY);
	virtual ~Enemy();
	virtual void Draw();
	virtual void Update();
	int* GetEnemyTexture(){return &m_EnemyTexture;}
private:
	/*static int m_EnemyNum;
	int m_EnemyId;*/
	int m_EnemyTexture;
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_NextPos;
	EnemyDirection m_Direction;
	Collision* m_Collision;
	int Fcount = 0;
	bool ReverseFlg = false;
};

