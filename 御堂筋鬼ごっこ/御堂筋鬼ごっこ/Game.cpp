#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "DirectGraphics.h"

Game::Game()
{
	m_pPlayer = new Player();
	m_pEnemy = new Enemy();
}
Game::~Game()
{
	delete m_pPlayer;
	delete m_pEnemy;
}

void Game::Update()
{
		m_pPlayer->Update();
}

void Game::Draw()
{
		DirectGraphics::GetpInstance()->StartRender();
		m_pPlayer->Draw();
		m_pEnemy->Draw();
		DirectGraphics::GetpInstance()->EndRender();
}
void Game::RunGame()
{
	Update();
	Draw();
}