#pragma once
#include "Enemy.h"
#include"SpriteManager.h"
class SwordMan
	: public Enemy
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	SwordMan();
	~SwordMan();
};

