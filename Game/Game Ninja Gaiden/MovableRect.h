#pragma once
#include "Rect.h"
class MovableRect :
	public Rect
{
	float dx, dy;
public:
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();

	void goX();
	void goY();

	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);

	void preventMovementWhenCollision(float collisionTime, int nx, int ny);

	MovableRect();
	~MovableRect();
};