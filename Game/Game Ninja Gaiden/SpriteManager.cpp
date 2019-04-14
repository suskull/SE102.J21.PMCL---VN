#include "SpriteManager.h"
SpriteManager* SpriteManager::instance = 0;
SpriteManager* SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite* SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		sprites._Add(new Sprite());
	}


	sprites[SPRITE_PLAYER]->InitFromFile("resource/tool/player/image.png", "resource/tool/player/player.info.dat");
	sprites[SPRITE_SWORDMAN]->InitFromFile("resource/tool/SwordMan/image.png", "resource/tool/SwordMan/SwordMan.info.dat"); 
	sprites[SPRITE_INFO_SHURIKEN]->InitFromFile("resource/sprites/shuriken/shuriken.png", "resource/sprites/shuriken/shuriken.info.dat");
	sprites[SPRITE_SWORD]->InitFromFile("resource/sprites/sword/sword.png", "resource/sprites/sword/sword.info.dat");
	sprites[SPRITE_WINDMILLSHURIKEN]->InitFromFile("resource/sprites/windmillshuriken/windmillshuriken.png", "resource/sprites/windmillshuriken/windmillshuriken.info.dat");
	sprites[SPRITE_PANTHER]->InitFromFile("resource/tool/Panther/panther.png", "resource/tool/Panther/panther.info.dat");
	sprites[SPRITE_THROWMAN]->InitFromFile("resource/tool/Throwman/image.png", "resource/tool/Throwman/throwman.info.dat");
	sprites[SPRITE_BIRD]->InitFromFile("resource/tool/Bird/image.png", "resource/tool/Bird/bird.info.dat");
	sprites[SPRITE_SOLDIER]->InitFromFile("resource/tool/Soldier/image.png", "resource/tool/Soldier/soldier.info.dat");
}
SpriteManager::~SpriteManager()
{
}
