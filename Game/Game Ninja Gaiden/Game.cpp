#include "Game.h"
#include"KEY.h"
#include"Player.h"
Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::GameInit()
{
	Player* player = Player::getInstance();
	player->set(111, 0, 16, 30);
	swordman = new SwordMan();
	swordman->set(0, 0, 17, 30);
	bg.Init("resource/map/Stage3-1.png");

	currentIndex = 0;
	currentAnimation = 3;


	timeDelay.init(100);

	x = 20, y = 30;
}
void Game::GameUpdate(float dt)
{
	KEY::getInstance()->update();
	Player* player = Player::getInstance();
	if (timeDelay.atTime())
	{
		//Player::getInstance()->update(dt);
		Player::getInstance()->getSprite()->update(currentAnimation, currentIndex);
		swordman->getSprite()->update(0,currentIndex);
	}

	float vx = GLOBALS_D("player_vx");
	if (KEY::getInstance()->isLeftDown)
	{
		player->setVx(-vx);
	}
	else if (KEY::getInstance()->isRightDown)
	{
		player->setVx(vx);
	}
	else if (KEY::getInstance()->isUpDown)
	{
		player->setVy(-vx);
	}
	else if (KEY::getInstance()->isDownDown)
	{
		player->setVy(vx);
	}
	else
	{
		player->setVx(0);
		player->setVy(0);
	}
	player->setDx(player->getVx() * dt);
	player->setDy(player->getVy() * dt);
	Collision::CheckCollision(player, swordman);
	player->update(dt);
	
}
void Game::GameRender()
{
	RECT rect;
	SetRect(&rect, 0, 0, 300, 400);
	bg.Render(0, 0, 0, 0, &rect);
	Player* player = Player::getInstance();
	player->getSprite()->render(player->getX(), player->getY(), currentAnimation, currentIndex);
	swordman->getSprite()->render(swordman->getX(), swordman->getY(), 0, currentIndex);
}

Game::Game()
{
}


Game::~Game()
{
}
