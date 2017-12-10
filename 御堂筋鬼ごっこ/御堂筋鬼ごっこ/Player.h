#pragma once

#include "CharObject.h"
#include "DirectInput.h"
#include "Collision.h"

#define PLAYER_W 20
#define PLAYER_H 25
#define PLAYER_TU 0.097f
#define PLAYER_TV 0.488f
#define MOVESPEED 2.f

#define PLAYER_INNTIAL_POSX 50.f
#define PLAYER_INNTIAL_POSY 50.f

class Map;

class Player : public CharObjectBase {
public:
	enum PlayerDirection {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	Player(Map* map);
	virtual ~Player();
	virtual void Draw();
	virtual void Update();
	int* GetPlayerTexture(){return &m_PlayerTexture;}
	D3DXVECTOR2* GetPos(){return &m_Pos;}
private:
	Map* m_pMap;
	Collision* m_Collision;
	int m_PlayerTexture;
	PlayerDirection m_Directon;
	float m_Tu;
	float m_Tv;
	D3DXVECTOR2 m_Pos;
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
	bool m_HitFlg = false;
};