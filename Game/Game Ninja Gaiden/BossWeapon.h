#include"SpriteManager.h"
#include"Weapon.h"
class BossWeapon:
	public Weapon
	
{
public:
	void onIntersect(MovableRect* other) override;
	BossWeapon();
	~BossWeapon();
};

