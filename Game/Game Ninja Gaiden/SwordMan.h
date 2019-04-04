#pragma once
#include "MovableObject.h"
#include"SpriteManager.h"
class SwordMan
	: public MovableObject
{
public:
	void onCollision(PhysicsBox* other, float collisionTime, int nx, int ny) override;

	SwordMan();
	~SwordMan();
};

