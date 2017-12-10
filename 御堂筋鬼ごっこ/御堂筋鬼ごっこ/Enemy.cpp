#include "Enemy.h"
#include "DirectGraphics.h"

//int Enemy::m_EnemyNum = 0;

Enemy::Enemy(): m_Pos(ENEMY_INNTIAL_POSX, ENEMY_INNTIAL_POSY)
{
	//m_EnemyId = m_EnemyNum;
	//m_EnemyNum++;
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
		{ -ENEMY_W,  ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, ENEMY_TU }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++){
		EnemyDraw[i] = EnemyVertex[i];
		EnemyDraw[i].x += m_Pos.x;
		EnemyDraw[i].y += m_Pos.y;
	}
	static int Fcount = 0;
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
void Enemy::Update() {};