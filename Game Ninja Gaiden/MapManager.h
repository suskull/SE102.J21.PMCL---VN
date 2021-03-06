﻿#pragma once
#include "List.h"
#include"Panther.h"
#include"Throwman.h"
#include"Bird.h"
#include"Soldier.h"
#include"Butterfly.h"
#include"Bat.h"
#include"ItemSpiritualStrenghtBlue.h"
#include"ItemBonusBlue.h"
#include"ItemClock.h"
#include"ItemFireWheel.h"
#include"ItemShuriken.h"
#include"ItemSpiritualStrengtRed.h"
#include"ItemRestorePhysicalStrenght.h"
#include"ItemBonusRed.h"
#include"CollisionTypeCanCollide.h"
#include<string>

struct Map
{
	string ID;
	int width, height;
	int playerX, playerY;
};

class MapManager
{
	static MapManager* instance;
	List<Map*> listMap;
	bool isChangeMap;
	Map* currentMap;
	int currentMapIndex; // thêm để tự động chuyển map kế tiếp khi Play chạm Gate.

	Tilemap* currentTileMap;

	List<BaseObject*> allObjects;

	List<BaseObject*> objectsInCamera;

	List<CollisionTypeCanCollide*> listCollisionTypeCanCollide;

	List<List<BaseObject*>*> objectCategories;
public:
	static MapManager* getInstance();
	
	Map* getCurrentMap();
	void setCurrentMap(int currentMapIndex);

	int getCurrentMapIndex();

	void InitMap();
	void InitObjects(string Objectpath, int worldHeight);
	void InitCollisionTypeCanCollide(string path);
	void update(float dt);
	void render();
	void resetValue();
	MapManager();
	~MapManager();
};

