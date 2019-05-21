#include "AdditionalObject.h"


List<AdditionalObject*>* AdditionalObject::listObject = 0;
List<AdditionalObject*>* AdditionalObject::getListObject()
{
	if (listObject == 0)
	{
		listObject = new List<AdditionalObject*>();
	}
	return listObject;
}

void AdditionalObject::listObjectUpdate(float dt)
{
	for (size_t i = 0; i < getListObject()->Count; i++)
	{
		auto object = listObject->at(i);
		if (!object->getAlive())
		{
			listObject->_Remove(object);
			delete object;
			i--;
		}
		else
			listObject->at(i)->update(dt);
	}
}

void AdditionalObject::listObjectRender(Camera* camera)
{
	for (size_t i = 0; i < getListObject()->Count; i++)
	{
		listObject->at(i)->render(camera);
	}
}

AdditionalObject::AdditionalObject()
{
	getListObject()->_Add(this);
}


AdditionalObject::~AdditionalObject()
{
}
