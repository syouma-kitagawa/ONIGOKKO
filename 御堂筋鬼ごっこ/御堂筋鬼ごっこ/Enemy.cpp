#include "Enemy.h"
#include "DirectGraphics.h"
#include "CollisionManager.h"


Enemy::Enemy(float InntialPosX, float InntialPosY, float NextPosX, float NextPosY)
	: m_Pos(InntialPosX, InntialPosY),m_NextPos(NextPosX, NextPosY)
{
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(ENEMY_W * 2 - 15, ENEMY_H * 2 - 15));
	m_Collision->SetCoolisionId(Collision::ENEMY);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
}


Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	CUSTOMVERTEX EnemyDraw[4];
	static CUSTOMVERTEX  EnemyVertex[4]{
		{ -ENEMY_W, -ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ENEMY_W, -ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, ENEMY_TU, 0.f },
		{  ENEMY_W,  ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, ENEMY_TU, ENEMY_TV },
		{ -ENEMY_W,  ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,  ENEMY_TV }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++){
		EnemyDraw[i] = EnemyVertex[i];
		EnemyDraw[i].x += m_Pos.x;
		EnemyDraw[i].y += m_Pos.y;
	}
	int remainder = Fcount % 20;
	//プレイヤーの向きにごとにアニメーションを変える
	switch (m_Direction)
	{
	case Enemy::UP:

		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 4);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 5);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		break;
	case Enemy::DOWN:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 0);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 1);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		break;
	case Enemy::RIGHT:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 2);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 3);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		break;
	case Enemy::LEFT:
		if (remainder <= 9) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 6);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		else if (remainder <= 19) {
			DirectGraphics::GetpInstance()->Animation(EnemyDraw, ENEMY_TU, 7);
			DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
		}
		break;
	}
	if (Fcount != 60) {
		Fcount++;
	}
	else {
		Fcount = 0;
	}
}
void Enemy::Update() 
{

	if (ReverseFlg == false) {
		if (m_Pos.x < m_NextPos[0]) {
			m_Direction = RIGHT;
			m_Pos.x += 1;
		}
		else if (m_Pos.y < m_NextPos[1]) {
			m_Direction = DOWN;
			m_Pos.y += 1;
		}

		if (m_Pos.y == m_NextPos[1]) {
			ReverseFlg = true;
		}
	}
	else {
	if (m_Pos.x > ENEMY_INNTIAL_POSX) {
		m_Direction = LEFT;
		m_Pos.x -= 1;
	}
	else if (m_Pos.y > ENEMY_INNTIAL_POSY) {
		m_Direction = UP;
		m_Pos.y -= 1;
	}
	if (m_Pos.x == ENEMY_INNTIAL_POSX && m_Pos.y == ENEMY_INNTIAL_POSY) {
		ReverseFlg = false;
	}
	}
	m_Collision->SetPosition(m_Pos);

};