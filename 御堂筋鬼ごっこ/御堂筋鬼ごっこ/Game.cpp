#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TimeLimit.h"
#include "Map.h"
#include "DirectGraphics.h"
#include "GameClear.h"
#include "GameOver.h"
#include "CollisionManager.h"

Game::Game()
{
	CollisionManager::GetcollisionManager()->CreateCollisionManager();
	m_pMap = new Map();
	m_pPlayer = new Player(m_pMap);
	m_pTimeLimit = new TimeLimit();
	m_pGameClear = new GameClear();
	m_pGameOver = new GameOver();
}
Game::~Game()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pTimeLimit;
	delete m_pMap;
	delete m_pGameClear;
	delete m_pGameOver;
}

void Game::Update()
{
	m_pTimeLimit->GameTimeLimit();
	CollisionManager::GetcollisionManager()->Update();
	m_pPlayer->Update();
	//m_pEnemy->Update();
}

void Game::Draw()
{
		DirectGraphics::GetpInstance()->StartRender();
		if (m_pTimeLimit->GetTimeLimitCount() == 0) {
			m_pGameClear->Draw();
		}
		else {
			if (m_pPlayer->GetGameOverFlg()) {
				m_pGameOver->Draw();
			}
			else {
				m_pMap->Draw();
				m_pTimeLimit->GameTimeLimit();
				m_pPlayer->Draw();
				/*CharObjectBase *list[2] = { m_pPlayer, m_pEnemy };
				for (int i = 0; i < 2; i++) {
					list[i]->Draw();
				}*/
			}
		}
		DirectGraphics::GetpInstance()->EndRender();
}
void Game::RunGame()
{
	Update();
	Draw();
}