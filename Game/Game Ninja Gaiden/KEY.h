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
		isShurikenDown,
		isFlameDown1,
		isFlameDown2,
		isFlameDown3;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};

