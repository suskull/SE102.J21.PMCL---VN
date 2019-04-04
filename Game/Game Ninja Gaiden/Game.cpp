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
	Player::getInstance()->set(52, 350, 16, 30);
	swordman = new SwordMan();
	swordman->set(200, 350, 16, 30);
	bg.Init("resource/map/Stage3-1.png");

	currentIndex = 0;
	currentAnimation = 3;


	timeDelay.init(100);

	x = 20, y = 30;
}
void Game::GameUpdate(float dt)
{
	KEY::getInstance()->update();

	if (timeDelay.atTime())
	{
		//Player::getInstance()->update(dt);
		Player::getInstance()->getSprite()->update(currentAnimation, currentIndex);
		swordman->getSprite()->update(0,currentIndex);
	}
	if (KEY::getInstance()->isLeftDown)
	{
		x--;
	}
	if (KEY::getInstance()->isRightDown)
	{
		x++;
	}
	if (KEY::getInstance()->isUpDown)
	{
		y--;
	}
	if (KEY::getInstance()->isDownDown)
	{
		y++;
	}
	
}
void Game::GameRender()
{
	RECT rect;
	SetRect(&rect, 0, 0, 300, 400);
	bg.Render(10, 10, 0, 0, &rect);
	Player::getInstance()->getSprite()->render(x, y, currentAnimation, currentIndex);
	swordman->getSprite()->render(100, 100, 0, currentIndex);
}

Game::Game()
{
}


Game::~Game()
{
}
