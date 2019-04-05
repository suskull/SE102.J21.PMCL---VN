#pragma once
#include"MovableRect.h"
class Camera : public MovableRect
{
	static Camera* instance;
public:
	static Camera* getInstance();
	
	void convertWorldToView(float xWorld, float yWorld, float& xView, float& yView);
	
	void update();

	Camera();
	~Camera();
};

