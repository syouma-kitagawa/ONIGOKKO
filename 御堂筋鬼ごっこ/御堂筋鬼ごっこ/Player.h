#pragma once

#include "CharObject.h"
#include "DirectInput.h"


#define PLAYER_W 10
#define PLAYER_H 10
#define PLAYER_TU 1
#define PLAYER_TV 1
#define MOVESPEED 2.f

#define PLAYER_INNTIAL_POSX 50.f
#define PLAYER_INNTIAL_POSY 50.f

class Player : public CharObjectBase {
public:
	Player();
	virtual ~Player();
	virtual void Draw();
	virtual void Update();

	enum Direction {
		UNKNOWN,
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	
	int* GetPlayerTexture(){return &m_PlayerTexture;}
	D3DXVECTOR2* GetPos(){return &m_Pos;}
private:
	int m_PlayerTexture;
	Direction m_Directon;
	float m_Tu;
	float m_Tv;
	D3DXVECTOR2 m_Pos;
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
	static int m_Fcount;
};