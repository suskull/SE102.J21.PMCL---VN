#pragma once
#include "PhysicsObject.h"
#include "Camera.h"
class AdditionalObject :
	public PhysicsObject
{
	static List<AdditionalObject*>* listObject;
public:
	static List<AdditionalObject*>* getListObject();
	static void listObjectUpdate(float dt);
	static void listObjectRender(Camera* camera);
	AdditionalObject();
	~AdditionalObject();
};

