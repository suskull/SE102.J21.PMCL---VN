#pragma once
#include "PhysicsObject.h"
class RedBird :
	public PhysicsObject
{
public:
	void onIntersect(MovableRect* other) override;
	RedBird();
	~RedBird();
};

