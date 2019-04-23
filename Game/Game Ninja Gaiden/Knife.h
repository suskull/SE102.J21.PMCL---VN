

#include"SpriteManager.h"
#include"AdditionalObject.h"
#include"Weapon.h"
class Knife :
	public Weapon
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Knife();
	~Knife();
};

