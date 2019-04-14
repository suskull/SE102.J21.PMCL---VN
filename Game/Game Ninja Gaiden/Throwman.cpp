#include "Throwman.h"



void Throwman::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

Throwman::Throwman()
{
}


Throwman::~Throwman()
{
}
