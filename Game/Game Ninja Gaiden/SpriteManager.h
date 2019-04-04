#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_PLAYER = 0,

	SPRITE_SWORDMAN = 1, 

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

