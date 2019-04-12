#pragma once
#include<Windows.h>
class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,
		isUpDown,
		isDownDown,
		isAttackDown,
		isJumpDown,
		isShurikenDown;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};

