#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	setAx(0);
	setAy(0);
	setVx(0);
	setVy(0);
	setPhysicsEnable(true);
}

void PhysicsObject::onUpdate(float dt)
{
	if (getPhysicsEnable())
	{
		setVx(getVx() + getAx() * dt);
		setVy(getVy() + getAy() * dt);
		setDx(getVx() * dt);
		setDy(getVy() * dt);
	}

	setIsOnGround(false);
}

PhysicsObject::~PhysicsObject()
{
}

float PhysicsObject::getAx()
{
	return ax;
}

float PhysicsObject::getAy()
{
	return ay;
}

float PhysicsObject::getVx()
{
	return vx;
}

float PhysicsObject::getVy()
{
	return vy;
}

void PhysicsObject::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsObject::setAy(float ay)
{
	this->ay = ay;
}

void PhysicsObject::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsObject::setVy(float vy)
{
	this->vy = vy;
}

bool PhysicsObject::getPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsObject::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

bool PhysicsObject::getIsOnGround()
{
	return isOnGround;
}

void PhysicsObject::setIsOnGround(bool isOnGround)
{
	this->isOnGround = isOnGround;
}

void PhysicsObject::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	///* va chạm sàn là va chạm có phản xạ theo hướng từ dưới lên. mà chiều từ dưới lên là chiều dương nên ny=1 */
	//if (ny == 1)
	//{
	//	/* isOnGround = true tức vật có đứng trên sàn */
	//	setIsOnGround(true);
	//}
	BaseObject::onCollision(other, collisionTime, nx, ny);
}


