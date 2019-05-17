#include "Boss.h"
#include"SpriteManager.h"
#include "Player.h"
#include"BossWeapon.h"
#include"BossEffect.h"


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

	}

	auto player = Player::getInstance();

	switch (bossState)
	{
	case BOSS_STATE_WAIT:
		setAnimation(BOSS_ACTION_STAND);
		/*	if (abs(getX() - player->getX())  < 50 );*/

		count == 0;
		if (getIsLastFrameAnimationDone())
			count++;
		if (count > 5)
		{
			setVy(300);
			setVx(getDirection() * 120);
			setBossState(BOSS_STATE_JUMP);
			count = 0;

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
					
				//count++;
			
		}
		break;

	
	case BOSS_STATE_DEAD:
		setPhysicsEnable(false);
	

	/*	count = 0;
		count++;*/
		
		BossEffect* be = new BossEffect();
		be->setX(getX()+15);
		be->setY(getY() - 15);
		
		BossEffect* be1 = new BossEffect();
		be1->setX(getX() - 20);
		be1->setY(getY()-15);
		BossEffect* be2 = new BossEffect();
		be2->setX(getX() - 20);
		be2->setY(getY() - 45);
		BossEffect * be3 = new BossEffect();
		be3->setX(getX()+15);
		be3->setY(getY() - 45);

	/*	if (count == 5)
		{
			setAlive(false);
		}*/
		break;


	}

	

	Enemy::update(dt);

	
}

Boss::Boss()
{
	setSprite(SPR(SPRITE_BOSS));
	//setCollisionType(COLLISION_TYPE_BOSS);
}


Boss::~Boss()
{
}
