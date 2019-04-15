#include "Bird.h"



void Bird::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

Bird::Bird()
{
	setPhysicsEnable(false);
}


Bird::~Bird()
{
}
