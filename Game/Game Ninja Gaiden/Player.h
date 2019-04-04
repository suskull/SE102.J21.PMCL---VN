#pragma once
#include "MovableObject.h"
class Player: public MovableObject
{
	static Player* instance;
public:
	static Player* getInstance();
	Player();
	~Player();
};

