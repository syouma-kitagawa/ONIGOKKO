#pragma once
class GameClear
{
public:
	GameClear();
	~GameClear();
	void Draw();
	void UpDate();
	int* ClearTexture() { return &m_ClearTexture; }
private:
	int m_ClearTexture;
};

