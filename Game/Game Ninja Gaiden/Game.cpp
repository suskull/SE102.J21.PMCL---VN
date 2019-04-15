#include "Game.h"
#include"KEY.h"
#include"Player.h"
#include"Panther.h"
#include"Throwman.h"
#include"Bird.h"
#include"Soldier.h"
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
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}

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

		case SPRITE_PANTHER:
			obj = new Panther();
			break;

		case SPRITE_THROWMAN:
			obj = new Throwman();
			break;

		case SPRITE_BIRD:
			obj = new Bird();
			break;

		case SPRITE_SOLDIER:
			obj = new Soldier();
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

		objectCategories.at(obj->getCollisionType())->_Add(obj);
	}
}

void Game::InitCollisionTypeCanCollide(string path)
{
	int count;
	ifstream fs(path);
	fs >> count;
	
	for (size_t i = 0; i < count; i++)
	{
		int collisionType1, collisionType2;
		fs >> collisionType1 >> collisionType2;
		CollisionTypeCanCollide* collisionTypeCanCollide = new CollisionTypeCanCollide();
		collisionTypeCanCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCanCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		listCollisionTypeCanCollide._Add(collisionTypeCanCollide);
	}
}

void Game::GameInit()
{
	tilemap = new Tilemap();
	tilemap->Init("resource/map/stage3-1");

	Player* player = Player::getInstance();
	player->set(40, 140, 16, 30);

	InitObjects("resource/map/stage3-1/objects.dat", tilemap->getWorldHeight());
	InitCollisionTypeCanCollide("resource/map/stage3-1/collision_type_collides.dat");


	timeDelay.init(100);

	Camera::getInstance()->set(
		0,
		GLOBALS_D("backbuffer_height"),
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	
}
void Game::GameUpdate(float dt)
{
	KEY::getInstance()->update();
	Player* player = Player::getInstance();


	for (size_t i = 0; i < allObjects.Count; i++)
	{
		allObjects[i]->update(dt);
		Collision::CheckCollision(Player::getInstance(), allObjects[i]);

	}

	player->update(dt);
	Camera::getInstance()->update();
	
	for (size_t i = 0; i < AdditionalObject::getListObject()->Count; i++)
	{
		Collision::CheckCollision(player, AdditionalObject::getListObject()->at(i));
	}

	/* xét va chạm cho các loại đối tượng với nhau */
	for (size_t i = 0; i < listCollisionTypeCanCollide.size(); i++)
	{
		COLLISION_TYPE col1 = listCollisionTypeCanCollide.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = listCollisionTypeCanCollide.at(i)->COLLISION_TYPE_2;

		/* danh sách đối tượng thuộc collision type 1 */
		List<BaseObject*>* collection1 = objectCategories.at(col1);
		/* danh sách đối tượng thuộc collision type 2 */
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				/* cho xét va chạm của đối tượng dựa vào 1 cặp collisionType trong CollisionTypeCollide */
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}

	}

	AdditionalObject::listObjectUpdate(dt);
	if (Sword::getInstance()->getAlive())
		Sword::getInstance()->update(dt);
	
}
void Game::GameRender()
{
	tilemap->render(Camera::getInstance());
	
	Player* player = Player::getInstance();
	player->render(Camera::getInstance());

	for (size_t i = 0; i < allObjects.Count; i++)
	{
		allObjects[i]->render(Camera::getInstance());
	}

	AdditionalObject::listObjectRender(Camera::getInstance());
	if(Sword::getInstance()->getAlive())
		Sword::getInstance()->render(Camera::getInstance());
	
}

Game::Game()
{
}


Game::~Game()
{
}
