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

void Game::InitObjects(string Objectpath)
{
	int objectCount;
	ifstream fs(Objectpath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		fs >> id;
		switch (id)
		{

		case SPRITE_SWORDMAN:
			obj = new SwordMan();
			break;

		default:
			obj = new BaseObject();
			break;
		}
		/* đọc thông số đối tượng */
		obj->onInitFromFile(fs);
		if (id >= 0)
		{
			obj->setSprite(SPR(id));
		}
		allObjects._Add(obj);
	}
}

void Game::GameInit()
{
	Player* player = Player::getInstance();
	player->set(40, 40, 16, 30);
	swordman = new SwordMan();
	//swordman->set(0, 16, 16, 32); 

	//InitObjects("resource/map/stage3-1/objects.dat");

	currentIndex = 0;
	currentAnimation = 3;

	timeDelay.init(100);

	tilemap = new Tilemap();
	tilemap->Init("resource/map/stage3-1");

	Camera::getInstance()->set(
		0,
		0,
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	bo = new BaseObject();
	bo->set(0, 16, 16, 32);
	//bg = new GameTexture();
	//bg->Init("resource/tool/player.png");
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
	
	//for (size_t i = 0; i < allObjects.Count; i++)
	//{
	//	//allObjects[i]->update(dt);
	//	Collision::CheckCollision(Player::getInstance(), allObjects[i]);
	//}

	Collision::CheckCollision(player, swordman);
	player->update(dt);
	swordman->update(dt);
	Camera::getInstance()->update();
	
	Collision::CheckCollision(player, bo);
}
void Game::GameRender()
{
	tilemap->render(Camera::getInstance());
	
	Player* player = Player::getInstance();
	player->render(Camera::getInstance());
	swordman->render(Camera::getInstance());

	for (size_t i = 0; i < allObjects.Count; i++)
	{
		allObjects[i]->render(Camera::getInstance());
	}
	RECT rect;
	SetRect(&rect, 0, 0, 200, 200);
}

Game::Game()
{
}


Game::~Game()
{
}
