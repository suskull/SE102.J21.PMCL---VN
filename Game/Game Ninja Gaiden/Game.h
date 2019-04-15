#pragma once

#include"GameTexture.h"
#include"List.h"
#include"GameTime.h"
#include"FrameAnimation.h"
#include"Animation.h"
#include"Sprite.h"
#include"Camera.h"
#include"GameDirectX.h"
#include"SpriteManager.h"
#include"SwordMan.h"
#include"Collision.h"
#include"GameConfiguration.h"
#include"Tilemap.h"
#include"AdditionalObject.h"
#include"Sword.h"
#include"CollisionType.h"
#include"CollisionTypeCanCollide.h"

class Game
{
	static Game* instance;

	int currentIndex;

	int currentAnimation;

	GameTime timeDelay;
	
	Sprite sprite;

	int x, y;


	Tilemap* tilemap;

	List<BaseObject*> allObjects;

	List<CollisionTypeCanCollide*> listCollisionTypeCanCollide;

	List<List<BaseObject*>*> objectCategories;
public:
	static Game* getInstance();
	void InitObjects(string path, int worldHeight);
	void InitCollisionTypeCanCollide(string path);

	void GameInit();
	void GameUpdate(float dt);
	void GameRender();
	Game();
	~Game();
};

