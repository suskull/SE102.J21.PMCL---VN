#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
class Throwman
	: public Enemy
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Throwman();
	~Throwman();
};

