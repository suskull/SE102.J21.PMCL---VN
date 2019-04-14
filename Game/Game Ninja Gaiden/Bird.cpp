#include "Bird.h"



void Bird::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

Bird::Bird()
{
	setAx(0);
	setAy(GLOBALS_D("gravity_ay"));
	setVx(0);
	setVy(0);
}


Bird::~Bird()
{
}
