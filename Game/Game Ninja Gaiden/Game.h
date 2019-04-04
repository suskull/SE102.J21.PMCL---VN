#pragma once

#include"GameTexture.h"
#include"List.h"
#include"GameTime.h"
#include"FrameAnimation.h"
#include"Animation.h"
#include"Sprite.h"
#include"Camera.h"
#include"GameDirectX.h"
#include"SpriteManager.h"
#include"SwordMan.h"
class Game
{
	/* singleton pattern */
	static Game* instance;

	/* Khung hình hiện tại */
	int currentIndex;

	/* Animation hiện tại */
	int currentAnimation;

	/* dùng để làm chậm animation */
	GameTime timeDelay;
	
	/* sprite */
	Sprite sprite;

	int x, y;

	GameTexture bg;
	//Camera* camera;

	SwordMan* swordman;

public:
	static Game* getInstance();

	/* Các câu lệnh khởi tạo game */
	void GameInit();
	/* Các câu lệnh cập nhật game */
	void GameUpdate(float dt);
	/* Các câu lệnh vẽ của game */
	void GameRender();
	Game();
	~Game();
};

