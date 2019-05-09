﻿#pragma once
class Rect
{
protected:
	float x, y, width, height;
public:
	float getX();
	float getY();
	float getWidth();
	float getHeight();

	virtual void setX(float x);
	void setY(float y);
	void setWidth(float width);
	virtual void setHeight(float height);

	void setLocation(float x, float y);
	void setSize(float width, float height);

	void set(float x, float y, float width, float height);
	void set(Rect rect);
	float getleft();

	float getRight();
	float getTop();
	float getBottom();
	float getMidX();
	float getMidY();

	Rect();
	virtual ~Rect();
};

