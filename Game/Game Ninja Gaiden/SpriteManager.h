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

	SPRITE_RED_BIRD,

	SPRITE_RUNNING_MAN,

	SPRITE_SITTING_MAN,

	SPRITE_ITEM_WINDMILL_SHURIKEN,

	SPRITE_BOSS,


	SPRITE_INFO_SHURIKEN ,

	SPRITE_SWORD,
	
	SPRITE_WINDMILLSHURIKEN,

	SPRITE_FLAME,

	SPRITE_KNIFE,

	SPRITE_BULLET,

	SPRITE_INFO_EXPLOSION_EFFECT,

	SPRITE_ITEMS_IN_SCORE_BAR,

	SPRITE_WEAPON_SITTINGMAN,

	SPRITE_SHOT_EFFECT,
	SPRITE_BOSS_WEAPON,
	SPRITE_BOSS_EFFECT,

	SPRITE_COUNT
};

enum SPRITE_ITEMS_IN_SCOREBAR
{
	SPRITE_ITEMS_NUMBER,
	SPRITE_ITEMS_LOST_HEALTH,
	SPRITE_ITEMS_SHURIKEN,
	SPRITE_ITEMS_FIREWHEEL,
	SPRITE_ITEMS_WINDMILL_SHURIKEN
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

