#pragma once
#include "PhysicsObject.h"
#include"SpriteManager.h"
class SwordMan
	: public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;

	SwordMan();
	~SwordMan();
};

