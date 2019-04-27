#include "Game.h"
#include"KEY.h"
#include"Player.h"
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
#include"ScoreBar.h"
#include"MapManager.h"

Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::GameInit()
{
	auto map = MapManager::getInstance();
	map->InitMap();

	timeDelay.init(100);

	Camera::getInstance()->set(
		0,
		GLOBALS_D("backbuffer_height"),
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	
}
void Game::GameUpdate(float dt)
{
	MapManager::getInstance()->update(dt);
}
void Game::GameRender()
{
	MapManager::getInstance()->render();
}

Game::Game()
{
}


Game::~Game()
{
}
