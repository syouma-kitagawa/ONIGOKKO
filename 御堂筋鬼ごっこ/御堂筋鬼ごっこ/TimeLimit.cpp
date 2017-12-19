#include "TimeLimit.h"
#include "Game.h"
#include "Event.h"

TimeLimit::TimeLimit():m_Pos(TIMELIMITPOS_X, TIMELIMITPOS_Y),m_TimeCount(0),m_TimeLimitCount(60)
{
}


TimeLimit::~TimeLimit()
{
}

void TimeLimit::GameTimeLimit()
{
	SetTimeLimit();
	DrawTimeLimit();
}
void TimeLimit::SetTimeLimit()
{
	m_TimeCount++;
	if (m_TimeCount == 60) {
		m_TimeCount = 0;
		if (m_TimeLimitCount != 0 && Event::GetInstance()->GetPlayerGameOverFlg() == false) {
			m_TimeLimitCount--;
		}
	}

}
void TimeLimit::DrawTimeLimit()
{
	D3DXVECTOR2 pos = m_Pos;
	int kWidth = 24;
	for (int i = 0; i < kMaxNumberOfDigits; ++i) {

		pos.x -= kWidth + 2.0f;

		int NumPower = 1;

		for (int j = 0; j < i; ++j){
			NumPower *= 10;
		}
		int num = (m_TimeLimitCount / (NumPower)) % 10;
		num -= 1;

		CUSTOMVERTEX DrawTime[4];
		CUSTOMVERTEX  Vertex[4]{
			{ -TIMENUMBER_W, -TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{  TIMENUMBER_W, -TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, TIMENUMBER_TU, 0.f },
			{  TIMENUMBER_W,  TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, TIMENUMBER_TU, TIMENUMBER_TV },
			{ -TIMENUMBER_W,  TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,TIMENUMBER_TV }
		};
		//ˆÊ’u‚Æ’¸“_î•ñ‚ð‘ã“ü
		for (int k = 0; k < 4; k++) {
			DrawTime[k] = Vertex[k];
			DrawTime[k].x += pos.x;
			DrawTime[k].y += pos.y;
		}
			DirectGraphics::GetpInstance()->Animation(DrawTime, TIMENUMBER_TU, num);
			DirectGraphics::GetpInstance()->Render(&m_TimeNumberTexture, DrawTime);
	}
}