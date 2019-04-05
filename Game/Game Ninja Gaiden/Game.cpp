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
	swordman->set(150, 150, 17, 30);

	currentIndex = 0;
	currentAnimation = 3;

	timeDelay.init(100);

	tilemap = new Tilemap();
	tilemap->Init("resource/map/stage3-1");
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
	
	Collision::CheckCollision(player, swordman);
	player->update(dt);
	
}
void Game::GameRender()
{
	tilemap->render();
	
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
