#pragma once
#include<d3dx9.h>

#include "DirectInput.h"
class Player;

class Game {
public:
	Game();
	virtual ~Game();
	virtual void Draw();
	virtual void Update();
	void RunGame();
	Player* GetPlayer()
	{
		return m_pPlayer;
	}
private:
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
	Player* m_pPlayer;
};
