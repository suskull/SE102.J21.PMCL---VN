#include "SwordMan.h"



void SwordMan::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{

	Enemy::onCollision(other, collisionTime, nx, ny);
}

SwordMan::SwordMan()
{
}


SwordMan::~SwordMan()
{
	
}
