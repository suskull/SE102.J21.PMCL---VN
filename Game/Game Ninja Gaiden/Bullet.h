

#include"SpriteManager.h"
#include"Weapon.h"
class Bullet :
	public Weapon
{
public:
	void onIntersect(MovableRect* other) override;
	Bullet();
	~Bullet();
};

