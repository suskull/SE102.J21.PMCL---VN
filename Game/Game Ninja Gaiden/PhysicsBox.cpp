#include "PhysicsBox.h"

PhysicsBox::PhysicsBox()
{
	dx = 0;
	dy = 0;
	setPhysicsEnable(true);
}

void PhysicsBox::moveX(float dx)
{
	x += dx;
}

void PhysicsBox::moveY(float dy)
{
	y += dy;
}

void PhysicsBox::move(float dx, float dy)
{
	moveX(dx);
	moveY(dy);
}

void PhysicsBox::setDx(float dx)
{
	this->dx = dx;
}
void PhysicsBox::setDy(float dy)
{
	this->dy = dy;
}
float PhysicsBox::getDx()
{
	return dx;
}
float PhysicsBox::getDy()
{
	return dy;
}

void PhysicsBox::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsBox::setVy(float vy)
{
	this->vy = vy;
}

void PhysicsBox::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsBox::setAy(float ay)
{
	this->ay = ay;
}

float PhysicsBox::getVx()
{
	return vx;
}

float PhysicsBox::getVy()
{
	return vy;
}

float PhysicsBox::getAx()
{
	return ax;
}

float PhysicsBox::getAy()
{
	return ay;
}

bool PhysicsBox::isPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsBox::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

void PhysicsBox::updatePhysics(float dt)
{
	if (isPhysicsEnable())
	{
		//setVx(getVx() + getAx() * dt);
		//setVy(getVy() + getAy() * dt);
		setDx(getVx() * dt);
		setDy(getVy() * dt);
	}
}

void PhysicsBox::onCollision(PhysicsBox* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
}

void PhysicsBox::preventMovementWhenCollision(float collisionTime, int nx, int ny)
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


PhysicsBox::~PhysicsBox()
{
}
