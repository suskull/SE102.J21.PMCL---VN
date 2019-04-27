#include "Player.h"
#include"SpriteManager.h"
#include"MapManager.h"

Player* Player::instance = 0;
Player* Player::getInstance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

void Player::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
	if (other->getCollisionType() == COLLISION_TYPE_GROUND)
	{
		setVy(0);
		setIsOnGround(true);
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && !unstoppable)
	{
		setVx(-nx * 50);
		setVy(150);
		setIsOnGround(false);
		setPlayerState(PLAYER_STATE_INJURED);
		ScoreBar::getInstance()->decreaseHealth(1);
		
	}
	if (other->getCollisionType() == COLLISION_TYPE_GATE)
		MapManager::getInstance()->setCurrentMap(1);
	
}

void Player::onIntersect(MovableRect* other)
{
	if (other->getCollisionType() == COLLISION_TYPE_ENEMY && !unstoppable || other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY && !unstoppable)
	{
		setVx(-getDirection() * 50);
		setVy(150);
		setIsOnGround(false);
		setPlayerState(PLAYER_STATE_INJURED);
	}
}


void Player::update(float dt)
{
	Player* player = Player::getInstance();
	float vx = GLOBALS_D("player_vx");
	float vroll = GLOBALS_D("player_roll");
	auto key = KEY::getInstance();

	if (!getAlive())
	{
		setPlayerState(PLAYER_STATE_DIE);
	}

	switch (playerState)
	{
	//xong
	case PLAYER_STATE_STAND:
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		isAttacked = false;

		//trường hợp vừa bị injured xong.
		if (unstoppable)
		{
			setAnimation(PLAYER_ACTION_STAND_UNSTOPPABLE);
			if(getIsLastFrameAnimationDone())
				unstoppable = false;
		}
		else
			setAnimation(PLAYER_ACTION_STAND);
		
		if (key->isLeftDown) {
			setDirection(DIRECTION_LEFT);
			player->setVx(-vx);
			setPlayerState(PLAYER_STATE_RUN);
		}
		else if (key->isRightDown)
		{
			setDirection(DIRECTION_RIGHT);
			player->setVx(vx);
			setPlayerState(PLAYER_STATE_RUN);
		}
		else if (key->isUpDown)
			setPlayerState(PLAYER_STATE_CLIMB);
		else if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_ATTACK);
		else if (key->isSubWeaponDown)
		{
			if(getCurrentSubWeapon() == SUBWEAPON_NULL)
				setPlayerState(PLAYER_STATE_SUBWEAPON_NULL);
			if (getCurrentSubWeapon() == SUBWEAPON_SHURIKEN)
				setPlayerState(PLAYER_STATE_SHURIKEN);
			if (getCurrentSubWeapon() == SUBWEAPON_FIREWHEEL)
				setPlayerState(PLAYER_STATE_FLAME1);
			if (getCurrentSubWeapon() == SUBWEAPON_WINDMILLSHURIKEN)
				setPlayerState(PLAYER_STATE_WINDMILLSHURIKEN);
		}
			
		else if (key->isDownDown)
			setPlayerState(PLAYER_STATE_SIT);
		else if (key->isJumpDown && getIsOnGround()) {
			setVy(vroll);
			setPlayerState(PLAYER_STATE_ROLL);
		}

		else if (key->isFlameDown1)
		{
			setPlayerState(PLAYER_STATE_FLAME1);
		}
		else if (key->isFlameDown2)
		{
			setPlayerState(PLAYER_STATE_FLAME2);
		}
		else if (key->isFlameDown3)
		{
			setPlayerState(PLAYER_STATE_FLAME3);
		}

		else
		{
			//không nhấn nút gì thì nó đứng yên.
			setVx(0);
		}

			break;

	//xong
	case PLAYER_STATE_RUN:
	{
		setAnimation(PLAYER_ACTION_RUN);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (!key->isLeftDown && !key->isRightDown)
			setPlayerState(PLAYER_STATE_STAND);
		else if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_ATTACK);
		else if (key->isJumpDown)
		{
			setVy(vroll);
			setPlayerState(PLAYER_STATE_ROLL);
		}
		break;
	}

	case PLAYER_STATE_CLIMB:
		setAnimation(PLAYER_ACTION_CLIMB);
		break;
	//gần xong
	case PLAYER_STATE_ATTACK: {
		setVx(0);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());

		if (!isAttacked)
		{
			Sword* sword = new Sword();
			sword->setAlive(true);
			setAnimation(PLAYER_ACTION_ATTACK);
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
		{
			setPlayerState(PLAYER_STATE_STAND);
		}
		break;
	}
	case PLAYER_STATE_SUBWEAPON_NULL:
	{
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
		
	//xong	
	case PLAYER_STATE_SHURIKEN: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			if (ScoreBar::getInstance()->decreaseSpiritualStrengh(3))
			{
				Shuriken* shuriken = new Shuriken();
				shuriken->setX(this->getX() + 12 * getDirection());
				this->setVx(0);
				shuriken->setY(this->getY() - 5);
				shuriken->setVx(150 * getDirection());
				isAttacked = true;
			}
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	
	case PLAYER_STATE_WINDMILLSHURIKEN:
	{
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			WindmillShuriken* ws = new WindmillShuriken();
			ws->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			ws->setY(this->getY() - 5);
			ws->setVx(150 * getDirection());
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	//xong
	case PLAYER_STATE_SIT:
		isAttacked = false;
		setDx(0);
		setVx(0);
		setAnimation(PLAYER_ACTION_SIT);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (!key->isDownDown)
			setPlayerState(PLAYER_STATE_STAND);
		if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_SITATTACK);
		break;
	//xong
	case PLAYER_STATE_SITATTACK:
	{
		
		if (!isAttacked)
		{
			Sword* sword = new Sword();
			sword->setAlive(true);
			setAnimation(PLAYER_ACTION_SITATTACK);
			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
		{
			setPlayerState(PLAYER_STATE_SIT);
		}
		break;
	}

	//xong
	case PLAYER_STATE_ROLL:
	{
		setAnimation(PLAYER_ACTION_ROLL);
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());
		if (key->isLeftDown)
			setVx(-vx * 2 / 3);
		if (key->isRightDown)
			setVx(vx * 2 / 3);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);

		if (key->isAttackDown)
			setPlayerState(PLAYER_STATE_ATTACK);
		break;
	}
		
	//chưa dùng tới
	case PLAYER_STATE_ROLLATTACK:
		setAnimation(PLAYER_ACTION_ROLLATTACK);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);
		break;

	case PLAYER_STATE_FLAME1: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			Flame* fl = new Flame();
			fl->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl->setY(this->getY() + 25);
			fl->setVx(70 * getDirection());
			fl->setVy(70);

			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	case PLAYER_STATE_FLAME2: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			Flame* fl = new Flame();
			fl->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl->setY(this->getY() + 25);
			fl->setVx(70 * getDirection());
			fl->setVy(70);

			Flame * fl2 = new Flame();
			fl2->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl2->setY(this->getY() + 60);
			fl2->setVx(70 * getDirection());
			fl2->setVy(70);

			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	case PLAYER_STATE_FLAME3: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			Flame* fl = new Flame();
			fl->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl->setY(this->getY() + 25);
			fl->setVx(70 * getDirection());
			fl->setVy(70);

			Flame * fl2 = new Flame();
			fl2->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl2->setY(this->getY() + 60);
			fl2->setVx(70 * getDirection());
			fl2->setVy(70);

			Flame * fl3 = new Flame();
			fl3->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl3->setY(this->getY() + 95);
			fl3->setVx(70 * getDirection());
			fl3->setVy(70);

			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	case PLAYER_STATE_INJURED:
		unstoppable = true;
		setAnimation(PLAYER_ACTION_INJURED);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	case PLAYER_STATE_DIE:
		setDx(0);
		setDy(0);
		break;
	}

	

	PhysicsObject::update(dt);

}


void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

PLAYER_STATE Player::getPlayerState()
{
	return playerState;
}

void Player::render(Camera* camera)
{
	setY(getY() + (getHeightCurrentFrame() - getHeight()));
	setHeight(getHeightCurrentFrame());
	setX(getX() - (getWidthCurrentFrame() - getWidth())/2);
	setWidth(getWidthCurrentFrame());
	PhysicsObject::render(camera);
}

bool Player::getUnstoppable()
{
	return unstoppable;
}

void Player::setUnstoppable(bool unstoppable)
{
	this->unstoppable = unstoppable;
}

int Player::getCurrentSubWeapon()
{
	return currentSubWeapon;
}

void Player::setCurrentSubWeapon(int currentSubWeapon)
{
	this->currentSubWeapon = currentSubWeapon;
}


void Player::setMakeEnemyPause(bool makeEnemyPause)
{
	this->makeEnemyPause = makeEnemyPause;
}

bool Player::getMakeEnemyPause()
{
	return makeEnemyPause;
}



Player::Player()
{
	setSprite(SPR(SPRITE_PLAYER));
	setDirection(DIRECTION_RIGHT);
	setPlayerState(PLAYER_STATE_STAND);
	setCollisionType(COLLISION_TYPE_PLAYER);
	setCurrentSubWeapon(SUBWEAPON_NULL);
	//setCurrentSubWeapon(SUBWEAPON_SHURIKEN);
}


Player::~Player()
{
}
