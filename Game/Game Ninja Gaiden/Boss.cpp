#include "Boss.h"
#include"SpriteManager.h"


void Boss::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void Boss::update(float dt)
{
	switch (bossState)
	{
	case BOSS_STATE_STAND:
		setAnimation(BOSS_ACTION_STAND);
		isJumpping = false;
		if (getIsLastFrameAnimationDone() && !isJumpping)
		{
			count++;
		}
		if (count > 5)
		{
			count == 0;
			setVy(150);
			setVx(-150);
			setBossState(BOSS_STATE_JUMP);
		}
		break;
	case BOSS_STATE_JUMP:
		setAnimation(BOSS_ACTION_JUMP);
		break;
	}
	Enemy::update(dt);
}

Boss::Boss()
{
	setSprite(SPR(SPRITE_BOSS));
}


Boss::~Boss()
{
}
