#include "Player.h"
#include "DirectGraphics.h"
#include "DirectInput.h"

Player::Player() :m_Pos(PLAYER_INNTIAL_POSX, PLAYER_INNTIAL_POSY)
{
	
}

Player::~Player()
{
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
	//ˆÊ’u‚Æ’¸“_î•ñ‚ğ‘ã“ü
	for (int i = 0; i < 4; i++){
		PlayerDraw[i] = PlayerVertex[i];
		PlayerDraw[i].x += m_Pos.x;
		PlayerDraw[i].y += m_Pos.y;
	}
	//Œ³‚Ì‰æ‘œ‚ğã‚É•ûŒü“]Š·‚·‚é
	switch (m_Directon)
	{
	case Player::UP:
		DirectGraphics::GetpInstance()->Direction_Up(PlayerDraw);
		break;
	case Player::DOWN:
		DirectGraphics::GetpInstance()->Direction_Down(PlayerDraw);
		break;
	case Player::RIGHT:
		DirectGraphics::GetpInstance()->Direction_Right(PlayerDraw);
		break;
	case Player::LEFT:
		break;
	}
	static int m_Fcount = 0;
	int remainder = m_Fcount % 15;
	if (remainder <= 4){
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
	}
	else if (remainder <= 9){
		PlayerDraw[0].tu += PLAYER_TU;
		PlayerDraw[1].tu += PLAYER_TU;
		PlayerDraw[2].tu += PLAYER_TU;
		PlayerDraw[3].tu += PLAYER_TU;
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
	}
	else if (remainder <= 14){
		PlayerDraw[0].tu += PLAYER_TU * 2;
		PlayerDraw[1].tu += PLAYER_TU * 2;
		PlayerDraw[2].tu += PLAYER_TU * 2;
		PlayerDraw[3].tu += PLAYER_TU * 2;
		DirectGraphics::GetpInstance()->Render(&m_PlayerTexture, PlayerDraw);
	}
	if (m_Fcount != 60){
		m_Fcount++;
	}
	else{
		m_Fcount = 0;
	}
}

void Player::Update()
{
	DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_W], DIK_W);
	DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_A], DIK_A);
	DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_S], DIK_S);
	DirectInput::GetpInstance()->KeyCheck(&m_Key[KEY_D], DIK_D);
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

	if (m_Key[KEY_W] == KEY_ON){
		m_Directon = UP;//‚à‚µW‚ª‰Ÿ‚³‚ê‚½‚çã‚ÉŒü‚­
	}
	else if (m_Key[KEY_S] == KEY_ON){
		m_Directon = DOWN;//‚à‚µS‚ª‰Ÿ‚³‚ê‚½‚ç‰º‚ÉŒü‚­
	}
	if (m_Key[KEY_A] == KEY_ON){
		m_Directon = LEFT;//‚à‚µA‚ª‰Ÿ‚³‚ê‚½‚ç¶‚ÉŒü‚­
	}
	else if (m_Key[KEY_D] == KEY_ON){
		m_Directon = RIGHT;	//‚à‚µD‚ª‰Ÿ‚³‚ê‚½‚ç‰E‚ÉŒü‚­
	}
}



