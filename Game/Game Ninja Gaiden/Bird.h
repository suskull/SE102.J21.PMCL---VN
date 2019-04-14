#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
class Bird
	: public Enemy
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Bird();
	~Bird();
};

