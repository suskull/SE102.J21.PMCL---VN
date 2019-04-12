#pragma once
#include "Rect.h"
#include "CollisionType.h"
class MovableRect :
	public Rect
{
	float dx, dy;
	COLLISION_TYPE collisionType;
public:
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();

	void goX();
	void goY();

	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);

	void preventMovementWhenCollision(float collisionTime, int nx, int ny);

	COLLISION_TYPE getCollisionType();
	void setCollisionType(COLLISION_TYPE collisionType);

	MovableRect();
	~MovableRect();
};