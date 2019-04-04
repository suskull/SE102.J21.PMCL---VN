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
}
SpriteManager::~SpriteManager()
{
}
