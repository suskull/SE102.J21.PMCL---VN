#include "KEY.h"

DWORD getKeyChar(char keyChar)
{
	return ((int)keyChar - 'a') + 0x41;
}

KEY* KEY::instance = 0;
KEY* KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	isUpDown = GetAsyncKeyState(VK_UP);
	isDownDown = GetAsyncKeyState(VK_DOWN);
	isLeftDown = GetAsyncKeyState(VK_LEFT);
	isRightDown = GetAsyncKeyState(VK_RIGHT);
	isAttackDown = GetAsyncKeyState(getKeyChar('c'));
	isJumpDown = GetAsyncKeyState(getKeyChar('x'));
	isShurikenDown = GetAsyncKeyState(VK_SPACE);
	isFlameDown1 = GetAsyncKeyState(getKeyChar('f'));
	isFlameDown2 = GetAsyncKeyState(getKeyChar('g'));
	isFlameDown3 = GetAsyncKeyState(getKeyChar('h'));
}

KEY::KEY()
{
}


KEY::~KEY()
{
}
