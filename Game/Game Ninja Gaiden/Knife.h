

#include"SpriteManager.h"
#include"AdditionalObject.h"
class Knife :
	public AdditionalObject
{
public:
	void update(float dt) override;
	void onIntersect(MovableRect* other) override;
	Knife();
	~Knife();
};

