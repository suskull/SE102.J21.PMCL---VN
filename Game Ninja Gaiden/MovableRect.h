#pragma once
#include "Rect.h"
#include "CollisionType.h"
class MovableRect :
	public Rect
{
	float dx, dy;
	COLLISION_TYPE collisionType;
	bool alive;
	bool isRender;
public:
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();

	void goX();
	void goY();

	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	virtual void onIntersect(MovableRect* other){}

	void preventMovementWhenCollision(float collisionTime, int nx, int ny);

	COLLISION_TYPE getCollisionType();
	void setCollisionType(COLLISION_TYPE collisionType);

	void setAlive(bool alive);
	bool getAlive();

	void setIsRender(bool isRender);
	bool getIsRender();

	MovableRect();
	~MovableRect();
};