#pragma once
#include<d3dx9.h>

#include "DirectInput.h"
class Player;
class Enemy;
class TimeLimit;
class Map;
class Game {
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void RunGame();
	Player* GetPlayer(){return m_pPlayer;}
	Enemy* GetEnemy() { return m_pEnemy; }
	Map* GetMap() { return m_pMap; }
private:
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	TimeLimit* m_pTimeLimit;
	Map* m_pMap;
};
