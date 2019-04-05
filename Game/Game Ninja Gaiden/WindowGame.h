#pragma once
#include<Windows.h>
#include"GameConfiguration.h"
class WindowGame
{
	HWND hWnd;
	static WindowGame* instance;
public:
	void initHandleWindows(HINSTANCE hInstance, int nCmdShow);
	HWND getHandleWindow();
	static WindowGame* getInstance();

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	
	WindowGame(void);
	~WindowGame(void);
};
