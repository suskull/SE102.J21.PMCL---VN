#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_INFO_GROUND = -1,

	SPRITE_PLAYER = 0,

	SPRITE_SWORDMAN , 

	SPRITE_PANTHER,

	SPRITE_THROWMAN,

	SPRITE_BIRD,

	SPRITE_SOLDIER,

	SPRITE_BUTTERFLY,

	SPRITE_BAT,

	SPRITE_INFO_SHURIKEN ,

	SPRITE_SWORD,
	
	SPRITE_WINDMILLSHURIKEN,

	SPRITE_FLAME,

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

