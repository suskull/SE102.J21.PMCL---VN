﻿#pragma once

#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

enum SPRITE_INFO
{
	SPRITE_INFO_GROUND = -1,

	SPRITE_PLAYER,

	SPRITE_SWORDMAN , 

	SPRITE_PANTHER,

	SPRITE_THROWMAN,

	SPRITE_BIRD,

	SPRITE_SOLDIER,

	SPRITE_BUTTERFLY,

	SPRITE_BAT,


	SPRITE_ITEM_SPIRITUAL_STRENGHT_BLUE,

	SPRITE_ITEM_BONUS_BLUE,
	
	SPRITE_ITEM_CLOCK,

	SPRITE_ITEM_FIRE_WHEEL,

	SPRITE_ITEM_SHURIKEN,

	SPRITE_ITEM_SPIRITUAL_STRENGHT_RED,

	SPRITE_ITEM_RESTORE_PHYSICAL_STRENGHT,

	SPRITE_ITEM_BONUS_RED,


	SPRITE_INFO_SHURIKEN ,

	SPRITE_SWORD,
	
	SPRITE_WINDMILLSHURIKEN,

	SPRITE_FLAME,

	SPRITE_KNIFE,

	SPRITE_BULLET,

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

