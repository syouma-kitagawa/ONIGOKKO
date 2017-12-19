#pragma once

class Event
{
public:
	static void CreateInstance();
	~Event();
	static Event* GetInstance() { return pInstance; }
	bool GetPlayerGameOverFlg() { return m_PlayerGameOverFlg; }
	void SetPlayerGameOverFlg(bool PlayerGameOverFlg) { m_PlayerGameOverFlg = PlayerGameOverFlg; }
private:
	Event() {};
	static Event* pInstance;
	bool m_PlayerGameOverFlg = false;
};

