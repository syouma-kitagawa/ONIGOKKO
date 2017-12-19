#pragma once

#include "DirectGraphics.h"

#define TIMENUMBER_W 15
#define TIMENUMBER_H 15

#define TIMENUMBER_TU 0.1
#define TIMENUMBER_TV 0.8

#define TIMELIMITPOS_X 800
#define TIMELIMITPOS_Y 30



enum NUMBER {
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};

class TimeLimit
{
public:
	TimeLimit();
	~TimeLimit();
	void GameTimeLimit();
	void SetTimeLimit();
	void DrawTimeLimit();
	int GetTimeLimitCount() { return m_TimeLimitCount; }
	int* GetTimeNumberTexture() { return &m_TimeNumberTexture; }
private:
	int m_TimeCount;
	int m_TimeLimitCount;
	int m_TimeNumber[2];
	D3DXVECTOR2 m_Pos;
	int kMaxNumberOfDigits = 2;
	int m_TimeNumberTexture;
};

