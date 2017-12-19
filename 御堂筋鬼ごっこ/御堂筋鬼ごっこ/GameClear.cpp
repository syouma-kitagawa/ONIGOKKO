#include "GameClear.h"
#include "DirectGraphics.h"
#include "Map.h"

GameClear::GameClear()
{
}


GameClear::~GameClear()
{
}

void GameClear::Draw() 
{
	CUSTOMVERTEX  ClearVertex[4]
	{
		{ 0, 0, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ MAP_WIDTH, 0, 1.f, 1.f, 0xFFFFFFFF,1.f, 0.f },
		{ MAP_WIDTH,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0,  MAP_HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f,1.f }
	};
	DirectGraphics::GetpInstance()->Render(&m_ClearTexture, ClearVertex);
}
void GameClear::UpDate()
{

}