#include<Windows.h>
#include"WindowGame.h"
#include"GameDirectX.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#include"Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));

	DWORD startTime = GetTickCount();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD timePerFrame = 1000 / GLOBALS_D("fps");

	Game::getInstance()->GameInit();

	while (msg.message != WM_QUIT)
	{
		DWORD now = GetTickCount();
		
		DWORD deltaTime = now - startTime;
		if (deltaTime >= timePerFrame)
		{
			float time = deltaTime / 1000.0f;
			Game::getInstance()->GameUpdate(time);

			startTime = now;
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			GameDirectX::getInstance()->BeginGraphics();

			Game::getInstance()->GameRender();

			GameDirectX::getInstance()->EndGraphics();
			GameDirectX::getInstance()->PresentBackBuffer();
		}

	}
	return nCmdShow;
}
