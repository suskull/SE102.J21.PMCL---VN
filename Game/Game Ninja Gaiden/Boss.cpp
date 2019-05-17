#include "Boss.h"
#include"SpriteManager.h"
#include "Player.h"
#include"BossWeapon.h"
#include"BossEffect.h"
#include "Sound.h"


void Boss::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void Boss::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(DIRECTION_LEFT);
	}
	else
	{
		setDirection(DIRECTION_RIGHT);
	}
}

void Boss::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	//isJumpping = false;
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setIsOnGround(true);
		setVy(0);
		preventMovementWhenCollision(collisionTime, nx, ny);
		setDirectionFollowPlayer();

	}
}

void Boss::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON)
	{
		ScoreBar::getInstance()->decreaseBossHealth(1);

	}
}

void Boss::update(float dt)
{

	if (ScoreBar::getInstance()->getBossHealth() == 0)
	{

		setBossState(BOSS_STATE_DEAD);
		Sound::getInstance()->loadSound("resource/sound/31.wav", "31");
		Sound::getInstance()->play("31", true, 4);
		
	}

	auto player = Player::getInstance();

	switch (bossState)
	{
	case BOSS_STATE_WAIT:
		setAnimation(BOSS_ACTION_STAND);
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 5)
		{
			setVy(300);
			setVx(getDirection() * 120);
			count = 0;
			setBossState(BOSS_STATE_JUMP);
			
			Sound::getInstance()->loadSound("resource/sound/BossJump.wav", "BossJump");
			Sound::getInstance()->play("BossJump", false, 1);
		}
		break;
	case BOSS_STATE_JUMP:
		
		setAnimation(BOSS_ACTION_JUMP);
		
		if (getIsOnGround())
		{
			setBossState(BOSS_STATE_WAIT);
			setAnimation(BOSS_ACTION_STAND);

			if (getIsRender())
			{
				BossWeapon* bl = new BossWeapon();
				bl->setX(getX() + (getDirection() * 30));
				bl->setY(getY() - 30);
				bl->setDirection(getDirection());
				bl->setVx(getDirection() * 80);
			}


		}
		break;


	case BOSS_STATE_DEAD:
		
		setVx(0);
		setVy(0);

		if (getIsLastFrameAnimationDone())
		{
			count++;
		}
		if (count >= 4)
		{
			
			BossEffect* be = new BossEffect();
			be->setX(getMidX() + 15);
			be->setY(getMidY() - 15);

			BossEffect * be1 = new BossEffect();
			be1->setX(getMidX() - 15);
			be1->setY(getMidY() - 15);

			BossEffect * be2 = new BossEffect();
			be2->setX(getMidX() - 15);
			be2->setY(getMidY() - 35);

			BossEffect * be3 = new BossEffect();
			be3->setX(getMidX() + 15);
			be3->setY(getMidY() - 35);

			count = 0;
		}
		break;
	}



	Enemy::update(dt);


}



Boss::Boss()
{
	setSprite(SPR(SPRITE_BOSS));
	setCollisionType(COLLISION_TYPE_BOSS);
}


Boss::~Boss()
{
}
