#include "Enemy.h"



void Enemy::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
}

void Enemy::onIntersect(MovableRect* other)
{
}

Enemy::Enemy()
{
	setCollisionType(COLLISION_TYPE_ENEMY);
	setPhysicsEnable(true);
	setAx(0);
	setAy(GLOBALS_D("gravity_ay"));
	setVx(0);
	setVy(0);
}


Enemy::~Enemy()
{
}
