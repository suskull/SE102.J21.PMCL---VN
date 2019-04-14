#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
class Soldier
	: public Enemy
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Soldier();
	~Soldier();
};

