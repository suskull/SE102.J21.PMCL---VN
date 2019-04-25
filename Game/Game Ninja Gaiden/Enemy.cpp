﻿#include "Enemy.h"
#include"ExplosionEffect.h"
#include"Player.h"

void Enemy::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setIsOnGround(true);
		setVy(0);
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		setVx(-getVx());
	}
	


}

void Enemy::onIntersect(MovableRect* other)
{
	if (!getAlive())
		return;
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
		setAlive(false);

	//lấy từ onCollision
	if (other->getCollisionType() == COLLISION_TYPE_BARRIER_FOR_ENEMY)
	{
		//setAlive(false);
		/*setVx(-getVx());
		if (getDirection() == DIRECTION_LEFT)
		{
			setX(getX() - abs(getWidthCurrentFrame() - getWidth()));
			setWidth(getWidthCurrentFrame());
		}
		else
			setX(getX() + 7);*/
		//
		
		//else
		//	setX(getX() - (getWidthCurrentFrame() - getWidth()));
	}
}

void Enemy::render(Camera* camera)
{
	if (getDirection() == DIRECTION_LEFT)
	{
		setX(getX() - (getWidthCurrentFrame() - getWidth()));
		setWidth(getWidthCurrentFrame());
	}
	PhysicsObject::render(camera);
}


Enemy::Enemy()
{
	setCollisionType(COLLISION_TYPE_ENEMY);
	setAx(0);
	setAy(GLOBALS_D("gravity_ay"));
	setVx(0);
	setVy(0);
	setPhysicsEnable(true);
	setAlive(true);
}


Enemy::~Enemy()
{
}
