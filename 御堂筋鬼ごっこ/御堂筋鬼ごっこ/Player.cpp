#include "Player.h"
#include "DirectGraphics.h"
#include "DirectInput.h"
#include "CollisionManager.h"
#include "Collision.h"
#include "Map.h"
#include "Event.h"

Player::Player(Map* map) :m_Pos(PLAYER_INNTIAL_POSX, PLAYER_INNTIAL_POSY)
{
	m_pMap = map;
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(PLAYER_W * 2 - 15, PLAYER_H * 2 - 15));
	m_Collision->SetCoolisionId(Collision::PLAYER);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
}

Player::~Player()
{
	delete m_Collision;
}

void Player::Draw()
{
	CUSTOMVERTEX PlayerDraw[4];
	static CUSTOMVERTEX  PlayerVertex[4]{
		{ -PLAYER_W, -PLAYER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ PLAYER_W, -PLAYER_H, 1.f, 1.f, 0xFFFFFFFF, PLAYER_TU, 0.f },
		{ PLAYER_W,  PLAYER_H, 1.f, 1.f, 0xFFFFFFFF, PLAYER_TU, PLAYER_TV },
		{ -PLAYER_W,  PLAYER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,PLAYER_TV }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++){
		PlayerDraw[i] = PlayerVertex[i];
		PlayerDraw[i].x += m_Pos.x;
		PlayerDraw[i].y += m_Pos.y;
	}
	static int Fcount = 0;
	int remainder = Fcount % 20;
	//プレイヤーの向きにごとにアニメーションを変える

	switch (m_Directon)
	{
	case Player::UP:

		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 4);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 5);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		break;
	case Player::DOWN:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 0);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 1);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		break;
	case Player::RIGHT:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 2);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 3);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		break;
	case Player::LEFT:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 6);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(PlayerDraw, PLAYER_TU, 7);
			DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
		}
		break;
	}
	if (Fcount != 60){
		Fcount++;
	}
	else{
		Fcount = 0;
	}
}

void Player::Update()
{
	int** CurrentMap = m_pMap->GetMapDate();
	int PlayerMapPos_X = (m_Pos.x) / MAPTIP_W;
	int PlayerMapPos_Y = (m_Pos.y)/ MAPTIP_H;
	CurrentMap[PlayerMapPos_Y][PlayerMapPos_X];
	//これは中心点であたり判定をとっている
	if (CurrentMap[PlayerMapPos_Y][PlayerMapPos_X] == 0) {
		m_HitFlg = true;
	}
	if (m_Collision->GetOtherCollisionId() == (Collision::ENEMY)) {
		m_GameOverFlg = true;
		Event::GetInstance()->SetPlayerGameOverFlg(m_GameOverFlg);
	}
	//当たった処理を書く
		DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_W], DIK_W);
		DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_A], DIK_A);
		DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_S], DIK_S);
		DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_D], DIK_D);
		if (m_Pos.x < MAP_WIDTH && m_Pos.x > 0
			&& m_Pos.y < MAP_HEIGHT && m_Pos.y > 0) {
			switch (m_Directon)
			{
			case Player::UP:
				m_Pos.y -= MOVESPEED;
				break;
			case Player::DOWN:
				m_Pos.y += MOVESPEED;
				break;
			case Player::RIGHT:
				m_Pos.x += MOVESPEED;
				break;
			case Player::LEFT:
				m_Pos.x -= MOVESPEED;
				break;
			default:
				break;
			}
		}
		else {
			m_Pos.x = PLAYER_INNTIAL_POSX;
			m_Pos.y = PLAYER_INNTIAL_POSY;
		}

	if (m_Key[KEY_W] == KEY_ON){
		m_Directon = UP;//もしWが押されたら上に向く
	}
	else if (m_Key[KEY_S] == KEY_ON){
		m_Directon = DOWN;//もしSが押されたら下に向く
	}
	if (m_Key[KEY_A] == KEY_ON){
		m_Directon = LEFT;//もしAが押されたら左に向く
	}
	else if (m_Key[KEY_D] == KEY_ON){
		m_Directon = RIGHT;	//もしDが押されたら右に向く
	}
	m_Collision->SetPosition(m_Pos);
}



