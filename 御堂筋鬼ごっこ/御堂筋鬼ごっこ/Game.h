#pragma once
#include<d3dx9.h>

#include "DirectInput.h"

class CollisionManager;
class Player;
class Enemy;
class TimeLimit;
class Map;
class GameClear;
class GameOver;
class SceneManager;
class Game {
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void RunGame();
	Player* GetPlayer(){return m_pPlayer;}
	Enemy* GetEnemy() { return m_pEnemy; }
	TimeLimit* GetTimeLimit() { return m_pTimeLimit; }
	Map* GetMap() { return m_pMap; }
	GameClear* GetGameClear() { return m_pGameClear; }
	GameOver* GetGameOver() { return m_pGameOver; }
private:
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	TimeLimit* m_pTimeLimit;
	Map* m_pMap;
	GameClear* m_pGameClear;
	GameOver* m_pGameOver;
	SceneManager* m_pSceneManager;
};
