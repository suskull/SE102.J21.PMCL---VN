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
	sprites[SPRITE_FLAME]->InitFromFile("resource/sprites/flame/flame.png", "resource/sprites/flame/flame.info.dat");
	sprites[SPRITE_PANTHER]->InitFromFile("resource/tool/Panther/panther.png", "resource/tool/Panther/panther.info.dat");
	sprites[SPRITE_THROWMAN]->InitFromFile("resource/tool/Throwman/image.png", "resource/tool/Throwman/throwman.info.dat");
	sprites[SPRITE_BIRD]->InitFromFile("resource/tool/Bird/image.png", "resource/tool/Bird/bird.info.dat");
	sprites[SPRITE_SOLDIER]->InitFromFile("resource/tool/Soldier/image.png", "resource/tool/Soldier/soldier.info.dat");
	sprites[SPRITE_BUTTERFLY]->InitFromFile("resource/tool/Butterfly/butterfly.png", "resource/tool/Butterfly/butterfly.info.dat");
	sprites[SPRITE_BAT]->InitFromFile("resource/tool/Bat/bat.png", "resource/tool/Bat/bat.info.dat");
	
	sprites[SPRITE_ITEM_SPIRITUAL_STRENGHT_BLUE]->InitFromFile("resource/sprites/Item-SpiritualStrengthBlue/Item-SpiritualStrengthBlue.png", "resource/sprites/Item-SpiritualStrengthBlue/Item-SpiritualStrengthBlue.info.dat");
	sprites[SPRITE_ITEM_BONUS_BLUE]->InitFromFile("resource/sprites/Item-BonusBlue/Item-BonusBlue.png", "resource/sprites/Item-BonusBlue/Item-BonusBlue.info.dat");
	sprites[SPRITE_ITEM_CLOCK]->InitFromFile("resource/sprites/Item-Clock/Item-Clock.png", "resource/sprites/Item-Clock/Item-Clock.info.dat");
	sprites[SPRITE_ITEM_FIRE_WHEEL]->InitFromFile("resource/sprites/Item-FireWheel/Item-FireWheel.png", "resource/sprites/Item-FireWheel/Item-FireWheel.info.dat");
	sprites[SPRITE_ITEM_SHURIKEN]->InitFromFile("resource/sprites/Item-Shuriken/Item-Shuriken.png", "resource/sprites/Item-Shuriken/Item-Shuriken.info.dat");
	sprites[SPRITE_ITEM_SPIRITUAL_STRENGHT_RED]->InitFromFile("resource/sprites/Item-SpiritualStrengthRed/Item-SpiritualStrengthRed.png", "resource/sprites/Item-SpiritualStrengthRed/Item-SpiritualStrengthRed.info.dat");
	sprites[SPRITE_ITEM_RESTORE_PHYSICAL_STRENGHT]->InitFromFile("resource/sprites/Item-RestorePhysicalStrength/Item-RestorePhysicalStrength.png", "resource/sprites/Item-RestorePhysicalStrength/Item-RestorePhysicalStrength.info.dat");
	sprites[SPRITE_ITEM_BONUS_RED]->InitFromFile("resource/sprites/Item-BonusRed/Item-BonusRed.png", "resource/sprites/Item-BonusRed/Item-BonusRed.info.dat");
	sprites[SPRITE_RED_BIRD]->InitFromFile("resource/tool/RedBird/RedBird.png", "resource/tool/RedBird/RedBird.info.dat");
	sprites[SPRITE_RUNNING_MAN]->InitFromFile("resource/tool/RunningMan/RunningMan.png", "resource/tool/RunningMan/RunningMan.info.dat");
	sprites[SPRITE_SITTING_MAN]->InitFromFile("resource/tool/SittingMan/SittingMan.png", "resource/tool/SittingMan/SittingMan.info.dat");
	sprites[SPRITE_ITEM_WINDMILL_SHURIKEN]->InitFromFile("resource/sprites/Item-WindmillShuriken/Item-WindmillShuriken.png", "resource/sprites/Item-WindmillShuriken/Item-WindmillShuriken.info.dat");
	sprites[SPRITE_BOSS]->InitFromFile("resource/tool/Boss/Boss.png", "resource/tool/Boss/Boss.info.dat");


	sprites[SPRITE_KNIFE]->InitFromFile("resource/sprites/knife/image.png", "resource/sprites/knife/knife.info.dat");
	sprites[SPRITE_BULLET]->InitFromFile("resource/sprites/bullet/image.png", "resource/sprites/bullet/bullet.info.dat");

	sprites[SPRITE_INFO_EXPLOSION_EFFECT]->InitFromFile("resource/sprites/ExplosionEffect/ExplosionEffect.png", "resource/sprites/ExplosionEffect/ExplosionEffect.info.dat");
	sprites[SPRITE_ITEMS_IN_SCORE_BAR]->InitFromFile("resource/sprites/scorebar/items.png", "resource/sprites/scorebar/items.info.dat");
}
SpriteManager::~SpriteManager()
{
}
