#include "Soldier.h"





void Soldier::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

Soldier::Soldier()
{
}


Soldier::~Soldier()
{
}
