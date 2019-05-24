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
	if (other->getCollisionType() == COLLISION_TYPE_WEAPON && getIsLastFrameAnimationDone())
	{
		ScoreBar::getInstance()->decreaseBossHealth(GLOBALS_D("boss_decrease_health_per_attack"));
		//setBossState(BOSS_STATE_INJURED);
	}
}

void Boss::update(float dt)
{

	if (ScoreBar::getInstance()->getBossHealth() == 0)
	{

		setBossState(BOSS_STATE_DEAD);
		Sound::getInstance()->loadSound("resource/sound/be.wav", "be");
		Sound::getInstance()->play("be", true, 4);
		
	}

	auto player = Player::getInstance();

	switch (bossState)
	{
	case BOSS_STATE_WAIT:
		setAnimation(BOSS_ACTION_STAND);
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > GLOBALS_D("boss_time_per_jump"))
		{
			setVy(GLOBALS_D("boss_vy"));
			setVx(getDirection() * GLOBALS_D("boss_vx"));
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
				bl->setX(getX() + (getDirection() * 10));
				bl->setY(getY() - 30);
				bl->setDirection(getDirection());
				bl->setVx(getDirection() * GLOBALS_D("boss_weapon_vx"));
			}


		}
		break;

	case BOSS_STATE_INJURED:
		setAnimation(BOSS_ACTION_INJURED);
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 2)
		{
			setBossState(BOSS_STATE_JUMP);
			count = 0;
		}
		break;

	case BOSS_STATE_DEAD:
		setAnimation(BOSS_ACTION_STAND);
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
}


Boss::~Boss()
{
}
