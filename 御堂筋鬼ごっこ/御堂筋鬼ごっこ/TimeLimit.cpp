#include "TimeLimit.h"


TimeLimit::TimeLimit():m_MultiplesOfTenPos(TIMELIMITPOS_X, TIMELIMITPOS_Y),m_TimeCount(0),m_TimeLimitCount(90)
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
		m_TimeLimitCount--;
	}
	m_TimeNumber[0] = m_TimeLimitCount % 10;
	m_TimeNumber[1] = m_TimeLimitCount / 10;

}
void TimeLimit::DrawTimeLimit()
{
	CUSTOMVERTEX TenthsDraw[4];
	CUSTOMVERTEX MultiplesOfTenDraw[4];
	static CUSTOMVERTEX  LimitTimeVertex[4]{
		{ -TIMENUMBER_W, -TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TIMENUMBER_W, -TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, TIMENUMBER_TU, 0.f },
		{ TIMENUMBER_W,  TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, TIMENUMBER_TU, TIMENUMBER_TV },
		{ -TIMENUMBER_W,  TIMENUMBER_H, 1.f, 1.f, 0xFFFFFFFF, 0.f,TIMENUMBER_TV }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		MultiplesOfTenDraw[i] = LimitTimeVertex[i];
		MultiplesOfTenDraw[i].x += m_MultiplesOfTenPos.x;
		MultiplesOfTenDraw[i].y += m_MultiplesOfTenPos.y;
	}
	for (int i = 0; i < 4; i++) {
		TenthsDraw[i] = LimitTimeVertex[i];
		TenthsDraw[i].x += m_MultiplesOfTenPos.x + TIMENUMBER_W;
		TenthsDraw[i].y += m_MultiplesOfTenPos.y + TIMENUMBER_H;
	}
//ç°ÇÃêîéöÇÇ›Çƒï`âÊÇ∑ÇÈÇ∆Ç±ÇÎswitchÇ© if,elseifÇ≈Ç©Ç≠
	for (int i = 0; i < 2; i++) {
		switch (m_TimeNumber[i])
		{
		case ZERO:

			break;
		case ONE:

			break;
		case TWO:

			break;
		case THREE:

			break;
		case FOUR:

			break;
		case FIVE:

			break;
		case SIX:

			break;
		case SEVEN:

			break;
		case EIGHT:

			break;
		case NINE:

			break;
		default:
			break;
		}
	}
}