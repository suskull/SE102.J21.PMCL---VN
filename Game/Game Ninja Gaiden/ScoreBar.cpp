#include "ScoreBar.h"
#include"Player.h"

#define NUMBER_WIDTH 8
#define HEALTH_WIDTH 4

ScoreBar* ScoreBar::instance = 0;
ScoreBar* ScoreBar::getInstance()
{
	if (instance == 0)
		instance = new ScoreBar();
	return instance;
}

ScoreBar::ScoreBar()
{
	scoreBar = new GameTexture("resource/sprites/scorebar/scorebar.png", D3DCOLOR_XRGB(10, 20, 60));
	itemsInScoreBar = SpriteManager::getInstance()->getSprite(SPRITE_ITEMS_IN_SCORE_BAR);
	gameTime.setTickPerFrame(1000);

	//Load location.
	ifstream ifs("resource/sprites/scorebar/items_location.txt");
	ignoreLineIfstream(ifs, 1);
	ifs >> scoreLocation.X >> scoreLocation.Y >> scoreLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> timeLocation.X >> timeLocation.Y >> timeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> playerLifeLocation.X >> playerLifeLocation.Y >> playerLifeLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);


	ignoreLineIfstream(ifs, 2);
	ifs >> subWeaponLocation.X >> subWeaponLocation.Y;

	ignoreLineIfstream(ifs, 2);
	ifs >> stageLocation.X >> stageLocation.Y >> stageLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> playerHealthLocation.X >> playerHealthLocation.Y >> playerHealthLocation.MaxLength;

	ignoreLineIfstream(ifs, 2);
	ifs >> bossHealthLocation.X >> bossHealthLocation.Y >> bossHealthLocation.MaxLength;

	setScore(123456);
	setTime(151);
	setPlayerLife(2);
	
	setCurrentStageNumber(1);
	//setHealth(playerHealthLocation.MaxLength);
}


ScoreBar::~ScoreBar()
{
}

void ScoreBar::render()
{
	scoreBar->Render(0, 0, 0, 0, 0);
	renderNumber(score, scoreLocation.X, scoreLocation.Y, scoreLocation.MaxLength);
	renderNumber(time, timeLocation.X, timeLocation.Y, timeLocation.MaxLength);
	renderNumber(playerLife, playerLifeLocation.X, playerLifeLocation.Y, playerLifeLocation.MaxLength);
	
	auto player = Player::getInstance();
	if (player->getCurrentSubWeapon() != SUBWEAPON_NULL)
	{
		itemsInScoreBar->render(subWeaponLocation.X, subWeaponLocation.Y, player->getCurrentSubWeapon() + 1, 0);
	}
	renderNumber(currentStageNumber, stageLocation.X, stageLocation.Y, stageLocation.MaxLength);
	//renderHealth(health, playerHealthLocation.X, playerHealthLocation.Y, playerHealthLocation.MaxLength);
}

void ScoreBar::update()
{
	if (gameTime.atTime())
	{
		decreaseTime(1);
	}
}

void ScoreBar::setTime(int time)
{
	if (time >= 0)
	{
		this->time = time;
	}
}

void ScoreBar::decreaseTime(int time)
{
	if(this->time > 0)
		this->time -= time;
}

int ScoreBar::getPlayerHealth()
{
	return playerHealth;
}

void ScoreBar::setPlayerHealth(int health)
{
	this->playerHealth = health;
}

//void ScoreBar::increaseHealth(int health)
//{
//	setHealth(this->health + health);
//}

void ScoreBar::restorePlayerHealth()
{
	this->playerHealth = playerHealthLocation.MaxLength;
}

void ScoreBar::renderNumber(int num, int x, int y, int maxLength)
{
	int currentX = x + NUMBER_WIDTH * maxLength;
	int length = 0;
	while (num != 0)
	{
		currentX -= NUMBER_WIDTH;
		int value = num % 10;
		itemsInScoreBar->render(currentX, y, SPRITE_ITEMS_NUMBER, value);
		num /= 10;
		length++;
	}
	for (; length < maxLength; length++)
	{
		currentX -= NUMBER_WIDTH;
		itemsInScoreBar->render(currentX, y, SPRITE_ITEMS_NUMBER, 0);
	}
}

void ScoreBar::renderHealth(int currentHealth, int x, int y, int maxHealth)
{
	int sub = maxHealth - currentHealth;
	int currentX = x + HEALTH_WIDTH * maxHealth;
	while (sub != 0)
	{
		currentX -= HEALTH_WIDTH;
		itemsInScoreBar->render(currentX, y, SPRITE_ITEMS_LOST_HEALTH, 0);
		sub -= 1;
	}
}

int ScoreBar::getPlayerLife()
{
	return playerLife;
}

void ScoreBar::setPlayerLife(int playerLife)
{
	this->playerLife = playerLife;
}

void ScoreBar::increasePlayerLife(int playerLife)
{
	setPlayerLife(this->playerLife + playerLife);
}



void ScoreBar::setCurrentStageNumber(int currentStageNumber)
{
	this->currentStageNumber = currentStageNumber;
}

int ScoreBar::getCurrentStageNumber()
{
	return currentStageNumber;
}

void ScoreBar::increaseCurrentStageNumber(int number)
{
	setCurrentStageNumber(this->currentStageNumber + number);
}

void ScoreBar::setScore(int score)
{
	this->score = score;
}

int ScoreBar::getScore()
{
	return score;
}

void ScoreBar::increaseScore(int score)
{
	setScore(this->score + score);
}


int ScoreBar::getBossHealth()
{
	return 0;
}

void ScoreBar::setBossHealth(int health)
{
}

void ScoreBar::increaseBossHealth(int health)
{
}

void ScoreBar::restoreBossHealth()
{
}
