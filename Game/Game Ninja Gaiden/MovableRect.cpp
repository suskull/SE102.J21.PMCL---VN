#include "MovableRect.h"

void MovableRect::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
}

void MovableRect::preventMovementWhenCollision(float collisionTime, int nx, int ny)
{
	if (nx != 0)
	{
		setDx(collisionTime * getDx());
	}
	if (ny != 0)
	{
		setDy(collisionTime * getDy());
	}
}

COLLISION_TYPE MovableRect::getCollisionType()
{
	return collisionType;
}

 void MovableRect::setCollisionType(COLLISION_TYPE collisionType)
{
	this->collisionType = collisionType;
}

 void MovableRect::setAlive(bool alive)
 {
	 this->alive = alive;
 }

 bool MovableRect::getAlive()
 {
	 return alive;
 }

 void MovableRect::setIsRender(bool isRender)
 {
	 this->isRender = isRender;
 }

 bool MovableRect::getIsRender()
 {
	 return isRender;
 }

MovableRect::MovableRect()
{
	dx = 0;
	dy = 0;
	alive = true;
	isRender = true;
}

void MovableRect::setDx(float dx)
{
	this->dx = dx;
}
void MovableRect::setDy(float dy)
{
	this->dy = dy;
}
float MovableRect::getDx()
{
	return dx;
}
float MovableRect::getDy()
{
	return dy;
}

void MovableRect::goX()
{
	setX(getX()+dx);
}

void MovableRect::goY()
{
	setY(getY() + dy);
}

MovableRect::~MovableRect()
{
}
