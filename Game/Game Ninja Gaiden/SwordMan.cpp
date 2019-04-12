#include "SwordMan.h"



void SwordMan::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	preventMovementWhenCollision(collisionTime, nx, ny);
}

SwordMan::SwordMan()
{
	setSprite(SPR(SPRITE_SWORDMAN));
	setCollisionType(COLLISION_TYPE_ENEMY);
}


SwordMan::~SwordMan()
{
}
