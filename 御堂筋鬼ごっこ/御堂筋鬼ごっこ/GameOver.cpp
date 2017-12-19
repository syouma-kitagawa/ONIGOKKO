#include "GameOver.h"
#include "DirectGraphics.h"
#include "Map.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}

void GameOver::Draw() 
{
	CUSTOMVERTEX  OverVertex[4]
	{
		{ 0, 0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ MAP_WIDTH, 0, 1.f, 1.f, 0xFFFFFFFF,1.f, 0.f },
		{ MAP_WIDTH,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f,1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_GameOverTexture, OverVertex);
}