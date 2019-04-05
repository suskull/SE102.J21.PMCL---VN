#pragma once
#include<Windows.h>
class GameTime
{
	DWORD startTime;
	DWORD tickPerFrame;
	DWORD deltaTime;
public:

	DWORD getStartTime();
	void setStartTime(DWORD startTime);

	DWORD getTickPerFrame();
	void setTickPerFrame(DWORD tickPerFrame);
	
	DWORD getDeltaTime();
	void setDeltaTime(DWORD deltaTime);

	void init(DWORD tickPerFrame);

	virtual bool atTime();

	GameTime(DWORD tickPerFrame);

	GameTime(void);
	~GameTime(void);

	
	
};

