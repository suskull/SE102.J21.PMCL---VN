#include "Collision.h"
#include<iostream>
#include<string>

using namespace std;
MovableRect* Collision::GetSweptBroadPhaseBox(MovableRect* box)
{
	MovableRect* broadphaseBox = new MovableRect();
	broadphaseBox->setX(box->getDx() > 0 ? box->getX() : (box->getX() + box->getDx()));
	broadphaseBox->setY(box->getDy() > 0 ? (box->getY() + box->getDy()) : box->getY());
	broadphaseBox->setWidth(box->getDx() > 0 ? (box->getWidth() + box->getDx()) : (box->getWidth() - box->getDx()));
	broadphaseBox->setHeight(box->getDy() > 0 ? (box->getHeight() + box->getDy()) : (box->getHeight() - box->getDy()));
	return broadphaseBox;
}

bool Collision::AABBCheck(Rect * M, Rect * S)
{
	return ((M->getX() < S->getX() + S->getWidth() && M->getX() + M->getWidth() > S->getX()) &&
		(M->getY() - M->getHeight() < S->getY() && M->getY() > S->getY() - S->getHeight()));
}

float Collision::SweptAABB(MovableRect* M, MovableRect* S, float& normalx, float& normaly)
{
	//Khoảng cách
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (M->getDx() > 0.0f)
	{
		xInvEntry = S->getX() - (M->getX() + M->getWidth());
		xInvExit = (S->getX() + S->getWidth()) - M->getX();
	}
	else
	{
		xInvEntry = (S->getX() + S->getWidth()) - M->getX();
		xInvExit = S->getX() - (M->getX() + M->getWidth());
	}

	if (M->getDy() > 0.0f)
	{
		yInvEntry = S->getY() - S->getHeight() - M->getY();
		yInvExit = S->getY() - (M->getY() - M->getHeight());
	}
	else
	{
		yInvEntry = S->getY() - (M->getY() - M->getHeight());
		yInvExit = (S->getY() - S->getHeight()) - M->getY();
	}

	//Thời gian 
	float xEntry, yEntry;
	float xExit, yExit;

	if (M->getDx() == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / (float)M->getDx();
		xExit = xInvExit / (float)M->getDx();
	}

	if (M->getDy() == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (float)M->getDy();
		yExit = yInvExit / (float)M->getDy();
	}

	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	else // Va chạm:
	{
		if (xEntry > yEntry)
		{
			if (M->getDx() < 0.0f) // Chạm mặt bên phải:
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else					// Chạm mặt bên trái:
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (M->getDy() < 0.0f) // Chạm mặt bên trên:
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else					// Chạm mặt bên dưới:
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}
		return entryTime;
	}
}
void Collision::CheckCollision(MovableRect* M, MovableRect* S)
{
	MovableRect* broadPhaseBox = GetSweptBroadPhaseBox(M);

	if (AABBCheck(broadPhaseBox, S))
	{
		delete broadPhaseBox; 

		if (AABBCheck(M, S))
		{
			M->onIntersect(S);
			S->onIntersect(M);
		}

		float normalX = 0, normalY = 0;
		float collisionTime = SweptAABB(M, S, normalX, normalY);
		if (collisionTime < 1)
		{
			M->onCollision(S, collisionTime, normalX, normalY);
			S->onCollision(M, collisionTime, normalX, normalY);
		}
		return;
	}
	delete broadPhaseBox;
}

Collision::Collision()
{
}

Collision::~Collision()
{
}