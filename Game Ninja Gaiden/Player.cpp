#include "Player.h"
#include"SpriteManager.h"
#include"MapManager.h"
#include"Sound.h"

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
	

	if (other->getCollisionType() == COLLISION_TYPE_GROUND && nx == -1)
	{
		setDx(0);
		setVx(0);
	}

	/*if (other->getCollisionType() == COLLISION_TYPE_GROUND && nx == 1)
	{
		setDx(0);
		setVx(0);
	}*/

	if ((other->getCollisionType() == COLLISION_TYPE_ENEMY && !unstoppable && !isReseting) || (other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY && !unstoppable && !isReseting))
	{
		setVx(nx * GLOBALS_D("player_injured_vx"));
		setVy(GLOBALS_D("player_injured_vy"));
		setIsOnGround(false);
		setPlayerState(PLAYER_STATE_INJURED);
		Sound::getInstance()->loadSound("resource/sound/injured.wav", "injured");
		Sound::getInstance()->play("injured", false, 1);
		ScoreBar::getInstance()->decreaseHealth(GLOBALS_D("player_injured_enemy"));
		
	}

	if (other->getCollisionType() == COLLISION_TYPE_BOSS && !unstoppable && !isReseting)
	{
		setVx(-nx * GLOBALS_D("player_injured_vx"));
		setVy(GLOBALS_D("player_injured_vy"));
		setIsOnGround(false);
		setPlayerState(PLAYER_STATE_INJURED);
		ScoreBar::getInstance()->decreaseHealth(GLOBALS_D("player_injured_boss"));

	}
	if (other->getCollisionType() == COLLISION_TYPE_GATE)
	{
		auto mapManager = MapManager::getInstance();
		mapManager->setCurrentMap(mapManager->getCurrentMapIndex() + 1);
	}

	if (other->getCollisionType() == COLLISION_TYPE_LADDER)
	{
		preventMovementWhenCollision(collisionTime, nx, ny);
		setPlayerState(PLAYER_STATE_CLIMB);
	}
	
}

void Player::onIntersect(MovableRect* other)
{
	if ((other->getCollisionType() == COLLISION_TYPE_ENEMY && !unstoppable && !isReseting) ||(other->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY && !unstoppable && !isReseting))
	{
		setVx(-getDirection() * GLOBALS_D("player_injured_vx"));
		setAy(GLOBALS_D("gravity_ay"));
		setVy(GLOBALS_D("player_injured_vy"));
		setPlayerState(PLAYER_STATE_INJURED);
		setIsOnGround(false);
		Sound::getInstance()->loadSound("resource/sound/injured.wav", "injured");
		Sound::getInstance()->play("injured", false, 1);
		ScoreBar::getInstance()->decreaseHealth(GLOBALS_D("player_injured_enemy"));
	}

}


void Player::update(float dt)
{
	Player* player = Player::getInstance();
	float vx = GLOBALS_D("player_vx");
	float vroll = GLOBALS_D("player_roll");
	auto key = KEY::getInstance();


	if ((!getAlive() || ScoreBar::getInstance()->getPlayerHealth() == 0) && !isReseting)
	{

		Sound::getInstance()->loadSound("resource/sound/player_die.wav", "player_die");
		Sound::getInstance()->play("player_die", false, 1);

		string idCurrentMap = MapManager::getInstance()->getCurrentMap()->ID;
		Sound::getInstance()->stop(idCurrentMap);

		setPlayerState(PLAYER_STATE_DIE);
	
	}

	
	//số frame tối đa của state unstoppable.
	if (numberofFrames > 8)
	{
		unstoppable = false;
		numberofFrames = 0;
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
			if (getIsLastFrameAnimationDone())
				numberofFrames +=2;
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
		/*else if (key->isUpDown)
			setPlayerState(PLAYER_STATE_CLIMB);*/
		else if (key->isAttackDown)
		{
		
			setPlayerState(PLAYER_STATE_ATTACK);
		}
			
		else if (key->isSubWeaponDown)
		{
			if (getCurrentSubWeapon() == SUBWEAPON_NULL)
				setPlayerState(PLAYER_STATE_SUBWEAPON_NULL);
			if (getCurrentSubWeapon() == SUBWEAPON_SHURIKEN)
			{
				setPlayerState(PLAYER_STATE_SHURIKEN);
				Sound::getInstance()->loadSound("resource/sound/shuriken.wav", "shuriken");
				Sound::getInstance()->play("shuriken", false, 1);
			}
				
			if (getCurrentSubWeapon() == SUBWEAPON_FIREWHEEL)
			{
				setPlayerState(PLAYER_STATE_FLAME1);
				Sound::getInstance()->loadSound("resource/sound/flame.wav", "flame");
				Sound::getInstance()->play("flame", false, 1);
				
			}
			
			if (getCurrentSubWeapon() == SUBWEAPON_WINDMILLSHURIKEN)
			{
				setPlayerState(PLAYER_STATE_WINDMILLSHURIKEN);
				Sound::getInstance()->loadSound("resource/sound/shuriken1.wav", "shuriken1");
				Sound::getInstance()->play("shuriken1", false, 1);
			}
				
		}

		else if (key->isDownDown)
			setPlayerState(PLAYER_STATE_SIT);
		else if (key->isJumpDown && getIsOnGround()) {
			setVy(vroll);
			setPlayerState(PLAYER_STATE_ROLL);
			Sound::getInstance()->loadSound("resource/sound/jump.wav", "jump");
			Sound::getInstance()->play("jump", false, 1);
		}

		else if (key->isFlameDown1)
		{
			setPlayerState(PLAYER_STATE_FLAME1);
			Sound::getInstance()->loadSound("resource/sound/flame.wav", "flame");
			Sound::getInstance()->play("flame", false, 1);
		}
		else if (key->isFlameDown2)
		{
			setPlayerState(PLAYER_STATE_FLAME2);
			Sound::getInstance()->loadSound("resource/sound/flame.wav", "flame");
			Sound::getInstance()->play("flame", false, 1);
		}
		else if (key->isFlameDown3)
		{

			
			setPlayerState(PLAYER_STATE_FLAME3);
			Sound::getInstance()->loadSound("resource/sound/flame.wav", "flame");
			Sound::getInstance()->play("flame", false, 1);
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
		setY(getY() - (getHeight() - getHeightCurrentFrame()));
		setHeight(getHeightCurrentFrame());

		if (unstoppable)
		{
			setAnimation(PLAYER_ACTION_RUN_UNSTOPPABLE);
			if (getIsLastFrameAnimationDone())
				numberofFrames += 6;
		}
		else
			setAnimation(PLAYER_ACTION_RUN);

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
		setAy(0);
		if (getY() > 132)
		{
			setAnimation(PLAYER_ACTION_STOP_CLIMB);
			setY(132);
		}
			
		if (key->isUpDown)
		{
			setVy(GLOBALS_D("player_climb_vy"));
			setAnimation(PLAYER_ACTION_CLIMB);
		}
		else if (key->isDownDown)
		{
			setVy(-GLOBALS_D("player_climb_vy"));
			setAnimation(PLAYER_ACTION_CLIMB);
		}
		else if (key->isJumpDown)
		{
			setVy(GLOBALS_D("player_climb_jump_vy"));
			setVx(-GLOBALS_D("player_climb_jump_vx"));
			setPhysicsEnable(true);
			setPlayerState(PLAYER_STATE_ROLL);
		}
		else
		{
			setDx(0);
			setDy(0);
			setVx(0);
			setVy(0);
			setAnimation(PLAYER_ACTION_STOP_CLIMB);
		}
			
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
			Sound::getInstance()->loadSound("resource/sound/attack.wav", "attack");
			Sound::getInstance()->play("attack", false, 1);
			
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
			if (ScoreBar::getInstance()->decreaseSpiritualStrengh(GLOBALS_D("spriritual_strenght_per_shuriken")))
			{
				Shuriken* shuriken = new Shuriken();
				shuriken->setX(this->getX() + 12 * getDirection());
				this->setVx(0);
				shuriken->setY(this->getY() - 5);
				shuriken->setVx(GLOBALS_D("shuriken_vx") * getDirection());
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
			if (ScoreBar::getInstance()->decreaseSpiritualStrengh(GLOBALS_D("spriritual_strenght_per_windmillshuriken")))
			{
				WindmillShuriken* ws = new WindmillShuriken();
				ws->setX(this->getX() + getWidthCurrentFrame() * getDirection());
				this->setVx(0);
				ws->setY(this->getY() - 5);
				ws->setVx(GLOBALS_D("shuriken_vx")* getDirection());
				isAttacked = true;
			}
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
			Sound::getInstance()->loadSound("resource/sound/attack.wav", "attack");
			Sound::getInstance()->play("attack", false, 1);
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
		setAy(GLOBALS_D("gravity_ay"));
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
			if (ScoreBar::getInstance()->decreaseSpiritualStrengh(GLOBALS_D("spriritual_strenght_per_flame")))
			{
				Flame* fl = new Flame();
				fl->setX(this->getX() + getWidthCurrentFrame() * getDirection());
				this->setVx(0);
				fl->setY(this->getY() + 25);
				fl->setVx(GLOBALS_D("flame_vx")* getDirection());
				fl->setVy(GLOBALS_D("flame_vy"));

				isAttacked = true;
			}
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}
	/*case PLAYER_STATE_FLAME2: {
		setAnimation(PLAYER_ACTION_SHURIKEN);
		if (getFrameAnimation() == 1 && !isAttacked)
		{
			Flame* fl = new Flame();
			fl->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl->setY(this->getY() + 25);
			fl->setVx(GLOBALS_D("flame_vx")* getDirection());
			fl->setVy(GLOBALS_D("flame_vy"));

			Flame * fl2 = new Flame();
			fl2->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl2->setY(this->getY() + 60);
			fl2->setVx(GLOBALS_D("flame_vx")* getDirection());
			fl2->setVy(GLOBALS_D("flame_vy"));

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
			fl->setVx(GLOBALS_D("flame_vx")* getDirection());
			fl->setVy(GLOBALS_D("flame_vy"));

			Flame * fl2 = new Flame();
			fl2->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl2->setY(this->getY() + 60);
			fl2->setVx(GLOBALS_D("flame_vx")* getDirection());
			fl2->setVy(GLOBALS_D("flame_vy"));

			Flame * fl3 = new Flame();
			fl3->setX(this->getX() + getWidthCurrentFrame() * getDirection());
			this->setVx(0);
			fl3->setY(this->getY() + 95);
			fl3->setVx(GLOBALS_D("flame_vx")* getDirection());
			fl3->setVy(GLOBALS_D("flame_vy"));

			isAttacked = true;
		}
		if (getIsLastFrameAnimationDone())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	}*/
	case PLAYER_STATE_INJURED:
		setPhysicsEnable(true);
		setAy(GLOBALS_D("gravity_ay"));
		unstoppable = true;
		setAnimation(PLAYER_ACTION_INJURED);
		if (getIsOnGround())
			setPlayerState(PLAYER_STATE_STAND);
		break;
	case PLAYER_STATE_DIE:
	{
		setAnimation(PLAYER_ACTION_DIE);
		auto scoreBar = ScoreBar::getInstance();
		auto mapManager = MapManager::getInstance();
		scoreBar->setPlayerHealth(0);
		scoreBar->setIsPauseGame(true);
		setDx(0);
		setDy(0);
		isReseting = true;
		

		if (scoreBar->getDieTime() <= 0)
		{
			//khởi tạo lại cho Player.
			setAlive(true);
			setIsRender(true);
			setVy(0);
			setVx(0);
			setPlayerState(PLAYER_STATE_STAND);
			ScoreBar::getInstance()->setPlayerHealth(GLOBALS_D("player_health"));
			ScoreBar::getInstance()->setBossHealth(GLOBALS_D("boss_health"));

			if (scoreBar->getPlayerLife() > 0)
			{
				// còn mạng thì quay về map HIỆN TẠI
				scoreBar->decreasePlayerLife();
				mapManager->setCurrentMap(mapManager->getCurrentMapIndex());

				setX(MapManager::getInstance()->getCurrentMap()->playerX);
				setY(MapManager::getInstance()->getCurrentMap()->playerY);
			}
			else
				// hết mạng thì quay vào map ĐẦU TIÊN
			{
				scoreBar->resetScoreGame();
				mapManager->setCurrentMap(0);

				setX(MapManager::getInstance()->getCurrentMap()->playerX);
				setY(MapManager::getInstance()->getCurrentMap()->playerY);
			}
			isReseting = false;
			scoreBar->setDieTime(GLOBALS_D("seconds_for_die"));
			scoreBar->setIsPauseGame(false);
		}

		
		break;
	}

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
