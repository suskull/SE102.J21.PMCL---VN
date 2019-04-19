#include "Enemy.h"



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
}

Enemy::Enemy()
{
	setCollisionType(COLLISION_TYPE_ENEMY);
	setAx(0);
	setAy(GLOBALS_D("gravity_ay"));
	setVx(0);
	setVy(0);
	setPhysicsEnable(true);

}


Enemy::~Enemy()
{
}
