#include "Enemy.h"
#include "DirectGraphics.h"



Enemy::Enemy(): m_Pos(ENEMY_INNTIAL_POSX, ENEMY_INNTIAL_POSY)
{

}


Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	CUSTOMVERTEX EnemyDraw[4];
	static CUSTOMVERTEX  EnemyVertex[4]{
		{ -ENEMY_W, -ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ENEMY_W, -ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ENEMY_W,  ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ENEMY_W,  ENEMY_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++){
		EnemyDraw[i] = EnemyVertex[i];
		EnemyDraw[i].x += m_Pos.x;
		EnemyDraw[i].y += m_Pos.y;
	}
	DirectGraphics::GetpInstance()->Render(&m_EnemyTexture, EnemyDraw);
}
void Enemy::Update() {};