#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_INFO_GROUND = -1,

	SPRITE_PLAYER = 0,

	SPRITE_SWORDMAN = 1, 

	SPRITE_INFO_SHURIKEN = 2,

	SPRITE_COUNT
};

class SpriteManager
{
	List<Sprite*> sprites;

	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};

