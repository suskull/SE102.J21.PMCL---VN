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

void Game::InitObjects(string Objectpath, int worldHeight)
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
		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			obj->setSprite(SPR(id));
		}
		allObjects._Add(obj);
	}
}

void Game::GameInit()
{
	tilemap = new Tilemap();
	tilemap->Init("resource/map/stage3-1");

	Player* player = Player::getInstance();
	player->set(40, 140, 16, 30);
	swordman = new SwordMan();
	swordman->set(100, 100, 16, 32); 

	InitObjects("resource/map/stage3-1/objects.dat", tilemap->getWorldHeight());

	currentIndex = 0;
	currentAnimation = 3;

	timeDelay.init(100);

	

	Camera::getInstance()->set(
		0,
		GLOBALS_D("backbuffer_height"),
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	//bo = new BaseObject();
	//bo->set(0, 64, 16, 16);
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

	
	
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		//allObjects[i]->update(dt);
		Collision::CheckCollision(Player::getInstance(), allObjects[i]);
		Collision::CheckCollision(swordman, allObjects[i]);
	}

	Collision::CheckCollision(player, swordman);
	player->update(dt);
	swordman->update(dt);
	Camera::getInstance()->update();
	
	AdditionalObject::listObjectUpdate(dt);
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

	AdditionalObject::listObjectRender(Camera::getInstance());

}

Game::Game()
{
}


Game::~Game()
{
}
