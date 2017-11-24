#include "Game.h"
#include "Player.h"
#include "DirectGraphics.h"

Game::Game()
{
	m_pPlayer = new Player();
}
Game::~Game()
{
	delete m_pPlayer;
}

void Game::Update()
{
		m_pPlayer->Update();
}

void Game::Draw()
{
		DirectGraphics::GetpInstance()->StartRender();
		m_pPlayer->Draw();
		DirectGraphics::GetpInstance()->EndRender();
}
void Game::RunGame()
{
	Update();
	Draw();
}