#pragma once
#include "PhysicsObject.h"
#include"Player.h"
class Item :
	public PhysicsObject
{
public:
	Item();
	~Item();
	void onIntersect(MovableRect* other) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
};

