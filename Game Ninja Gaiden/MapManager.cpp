#include "MapManager.h"
#include "GameUtils.h"
#include"Tilemap.h"
#include"Player.h"
#include"SwordMan.h"
#include"CollisionTypeCanCollide.h"
#include"Collision.h"
#include<string>
#include"RedBird.h"
#include"RunningMan.h"
#include"SittingMan.h"
#include"ItemWindmillShuriken.h"
#include"Boss.h"
#include"Grid.h"
#include "Sound.h"

MapManager* MapManager::instance = 0;
MapManager* MapManager::getInstance()
{
	if (instance == 0)
		instance = new MapManager();
	return instance;
}

Map* MapManager::getCurrentMap()
{
	return currentMap;
}

void MapManager::setCurrentMap(int currentMapIndex)
{
	this->currentMapIndex = currentMapIndex;
	this->currentMap = listMap.at(currentMapIndex);
	ScoreBar::getInstance()->setCurrentStageNumber(currentMapIndex + 1);

	isChangeMap = true;
}

int MapManager::getCurrentMapIndex()
{
	return currentMapIndex;
}

void MapManager::InitMap()
{
	resetValue();

	currentTileMap = new Tilemap();
	string idPath = "resource/map/" + currentMap->ID;
	currentTileMap->Init(idPath.c_str());
	Player* player = Player::getInstance();
	player->set(currentMap->playerX, currentMap->playerY, 16, 30);

	string objectPath = "resource/map/" + currentMap->ID + "/objects.dat";
	InitObjects(objectPath.c_str(), currentTileMap->getWorldHeight());

	string collisionPath = "resource/map/" + currentMap->ID + "/collision_type_collides.dat";
	InitCollisionTypeCanCollide(collisionPath.c_str());

	string GridPath = "resource/map/" + currentMap->ID + "/grid.dat";
	Grid::getInstance()->initGrid(GridPath, currentTileMap->getWorldHeight());
	
	//update sound
	switch (getCurrentMapIndex())
	{
	case 0:
		Sound::getInstance()->stop("stage3-2");
		Sound::getInstance()->stop("stage3-3");
		Sound::getInstance()->loadSound("resource/sound/stage3-1.wav", "stage3-1");
		Sound::getInstance()->play("stage3-1", true, 0);
		break;
	case 1:
		Sound::getInstance()->stop("stage3-1");
		Sound::getInstance()->loadSound("resource/sound/stage3-2.wav", "stage3-2");
		Sound::getInstance()->play("stage3-2", true, 0);
		break;
	case 2:
		Sound::getInstance()->stop("stage3-2");
		Sound::getInstance()->loadSound("resource/sound/stage3-3.wav", "stage3-3");
		Sound::getInstance()->play("stage3-3", true, 0);
		break;
	}
}

void MapManager::InitObjects(string objectPath, int worldHeight)
{
	int objectCount;
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}

	ifstream fs(objectPath);
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

		case SPRITE_BUTTERFLY:
			obj = new Butterfly();
			break;

		case SPRITE_BAT:
			obj = new Bat();
			break;

		case SPRITE_ITEM_SPIRITUAL_STRENGHT_BLUE:
			obj = new ItemSpiritualStrenghtBlue();
			break;

		case SPRITE_ITEM_BONUS_BLUE:
			obj = new ItemBonusBlue();
			break;

		case SPRITE_ITEM_CLOCK:
			obj = new ItemClock();
			break;

		case SPRITE_ITEM_FIRE_WHEEL:
			obj = new ItemFireWheel();
			break;

		case SPRITE_ITEM_SHURIKEN:
			obj = new ItemShuriken();
			break;

		case SPRITE_ITEM_SPIRITUAL_STRENGHT_RED:
			obj = new ItemSpiritualStrengtRed();
			break;

		case SPRITE_ITEM_RESTORE_PHYSICAL_STRENGHT:
			obj = new ItemRestorePhysicalStrenght();
			break;

		case SPRITE_ITEM_BONUS_RED:
			obj = new ItemBonusRed();
			break;

		case SPRITE_RED_BIRD:
			obj = new RedBird();
			break;

		case SPRITE_RUNNING_MAN:
			obj = new RunningMan();
			break;

		case SPRITE_SITTING_MAN:
			obj = new SittingMan();
			break;

		case SPRITE_ITEM_WINDMILL_SHURIKEN:
			obj = new ItemWindmillShuriken();
			break;

		case SPRITE_BOSS:
			obj = new Boss();
			break;

		default:
			obj = new BaseObject();
			break;
		}

		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			obj->setSprite(SPR(id));
		}
		allObjects._Add(obj);

		objectCategories.at(obj->getCollisionType())->_Add(obj);
	}
}

void MapManager::InitCollisionTypeCanCollide(string path)
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

void MapManager::update(float dt)
{
	
	
	//thêm
	Grid::getInstance()->update(allObjects, objectsInCamera);

	KEY::getInstance()->update();
	Player* player = Player::getInstance();
	
	if (isChangeMap)
	{
		InitMap();
		Camera::getInstance()->set(
			0,
			GLOBALS_D("backbuffer_height"),
			GLOBALS_D("backbuffer_width"),
			GLOBALS_D("backbuffer_height"));
		isChangeMap = false;
	}

	for (size_t i = 0; i < objectsInCamera.Count; i++)
	{
		objectsInCamera[i]->update(dt);
		if (player->getAlive() && objectsInCamera[i]->getAlive())
		{
			Collision::CheckCollision(Player::getInstance(), objectsInCamera[i]);
			if (objectsInCamera[i]->getCollisionType() == COLLISION_TYPE_ENEMY)
				if (player->getMakeEnemyPause())
					objectsInCamera[i]->setIsPause(true);
				else objectsInCamera[i]->setIsPause(false);
			Collision::CheckCollision(objectsInCamera[i], Player::getInstance());
		}

		if (ScoreBar::getInstance()->getIsPauseGame())
		{
			objectsInCamera[i]->setIsPause(true);
		}
	}

	

	player->update(dt);
	Camera::getInstance()->update();

	for (size_t i = 0; i < AdditionalObject::getListObject()->Count; i++)
	{
		Collision::CheckCollision(player, AdditionalObject::getListObject()->at(i));
		Collision::CheckCollision(AdditionalObject::getListObject()->at(i), player);

		//xét va chạm giữa Weapon và ...
		if (AdditionalObject::getListObject()->at(i)->getCollisionType() == COLLISION_TYPE_WEAPON)
		{
			//xét va chạm giữa Weapon và Enemy trong map
			List<BaseObject*>* collection_Enemies = objectCategories.at(COLLISION_TYPE_ENEMY);
			for (size_t j = 0; j < collection_Enemies->size(); j++)
			{
				Collision::CheckCollision(AdditionalObject::getListObject()->at(i), collection_Enemies->at(j));
			}
			//xét va chạm giữa Weapon và Boss trong map
			List<BaseObject*>* collection_Boss = objectCategories.at(COLLISION_TYPE_BOSS);
			for (size_t j = 0; j < collection_Boss->size(); j++)
			{
				Collision::CheckCollision(AdditionalObject::getListObject()->at(i), collection_Boss->at(j));
			}

			//xét va chạm giữa Weapon và BirdsHaveItem
			List<BaseObject*>* collection_BirdsHaveItem = objectCategories.at(COLLISION_TYPE_BUTTERFLY);
			for (size_t k = 0; k < collection_BirdsHaveItem->size(); k++)
			{
				Collision::CheckCollision(AdditionalObject::getListObject()->at(i), collection_BirdsHaveItem->at(k));
			}

			//xét va chạm giữa Weapon và Items
			List<BaseObject*>* collection_Items = objectCategories.at(COLLISION_TYPE_ITEM);
			for (size_t p = 0; p < collection_Items->size(); p++)
			{
				Collision::CheckCollision(AdditionalObject::getListObject()->at(i), collection_Items->at(p));
			}

			//Xét va chạm giữa Weapon và WeaponEnemy
			for (size_t t = 0; t < AdditionalObject::getListObject()->Count; t++)
			{
				if (AdditionalObject::getListObject()->at(t)->getCollisionType() == COLLISION_TYPE_WEAPON_ENEMY)
				{
					Collision::CheckCollision(AdditionalObject::getListObject()->at(i), AdditionalObject::getListObject()->at(t));
				}
			}
		}
	}





	for (size_t i = 0; i < listCollisionTypeCanCollide.size(); i++)
	{
		COLLISION_TYPE col1 = listCollisionTypeCanCollide.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = listCollisionTypeCanCollide.at(i)->COLLISION_TYPE_2;

		List<BaseObject*>* collection1 = objectCategories.at(col1);
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}

	}

	AdditionalObject::listObjectUpdate(dt);
	ScoreBar::getInstance()->update();

}

void MapManager::render()
{
	currentTileMap->render(Camera::getInstance());

	Player* player = Player::getInstance();
	player->render(Camera::getInstance());

	for (size_t i = 0; i < objectsInCamera.Count; i++)
	{
		objectsInCamera[i]->render(Camera::getInstance());
	}

	AdditionalObject::listObjectRender(Camera::getInstance());

	ScoreBar::getInstance()->render();
}

void MapManager::resetValue()
{
	currentTileMap = NULL;
	allObjects.Clear();
	listCollisionTypeCanCollide.Clear();
	objectCategories.Clear();
	objectsInCamera.Clear();
	Grid::getInstance()->resetlistCells();
	AdditionalObject::getListObject()->Clear();
}

MapManager::MapManager()
{
	int numberOfMap = 0;
	ifstream fs("resource/map/MapManager.txt");
	ignoreLineIfstream(fs, 1);
	fs >> numberOfMap;
	for (size_t i = 0; i < numberOfMap; i++)
	{
		ignoreLineIfstream(fs, 2);
		Map* map = new Map();
		fs >> map->ID;
		ignoreLineIfstream(fs, 2);
		fs >> map->width >> map->height >> map->playerX >> map->playerY;

		listMap._Add(map);
	}
	setCurrentMap(1);

	//do mới khởi tạo
	isChangeMap = false;
}


MapManager::~MapManager()
{
}
