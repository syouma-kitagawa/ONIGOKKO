#pragma once
class GameOver
{
public:
	GameOver();
	~GameOver();
	void Draw();
	int* GameOverTexture() { return &m_GameOverTexture; }
private:
	int m_GameOverTexture;
};

