

#include"SpriteManager.h"
#include"AdditionalObject.h"
class Bullet :
	public AdditionalObject
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Bullet();
	~Bullet();
};

