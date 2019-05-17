#pragma once
#include"BaseObject.h"
#include"Player.h"
#include"KEY.h"
class Ladder:public BaseObject
{
public:
	void onIntersect(MovableRect* other) override;
	Ladder();
	~Ladder();
};

