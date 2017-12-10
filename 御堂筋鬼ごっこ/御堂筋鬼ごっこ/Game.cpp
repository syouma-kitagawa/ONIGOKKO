#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TimeLimit.h"
#include "Map.h"
#include "DirectGraphics.h"

Game::Game()
{
	m_pMap = new Map();
	m_pPlayer = new Player(m_pMap);
	m_pEnemy = new Enemy();
	m_pTimeLimit = new TimeLimit();

}
Game::~Game()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pTimeLimit;
	delete m_pMap;
}

void Game::Update()
{
	m_pTimeLimit->GameTimeLimit();
	m_pPlayer->Update();
}

void Game::Draw()
{
		DirectGraphics::GetpInstance()->StartRender();
		m_pMap->Draw();
		CharObjectBase *list[2] ={m_pPlayer, m_pEnemy};
		for (int i = 0; i < 2; i++){
			list[i]->Draw();
		}
		DirectGraphics::GetpInstance()->EndRender();
}
void Game::RunGame()
{
	Update();
	Draw();
}