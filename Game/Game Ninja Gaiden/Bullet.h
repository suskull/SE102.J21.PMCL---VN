

#include"SpriteManager.h"
#include"SubWeapon.h"
class Bullet :
	public SubWeapon
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Bullet();
	~Bullet();
};

