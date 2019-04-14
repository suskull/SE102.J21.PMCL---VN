#include "Panther.h"



void Panther::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

Panther::Panther()
{
}


Panther::~Panther()
{
}
