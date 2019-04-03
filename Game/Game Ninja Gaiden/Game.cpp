#include "Game.h"


/* singleton pattern */
Game * Game::instance = 0;
Game * Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

/* Các câu lệnh khởi tạo game */
void Game::GameInit()
{
	/* khởi tạo sprite bằng file */
	sprite.InitFromFile("resource/tool/player/image.png", "resource/tool/player/player.info.dat");
	

	/* cho khung hình hiện tại là 0 */
	currentIndex = 0;
	currentAnimation = 1;


	/* khởi tạo thời gian làm chậm cỡ 1s (100 ms)*/
	timeDelay.init(100);
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate()
{
	/* Cập nhật sprite	*/
	/* Set ràng buộc thời gian */
	if (timeDelay.atTime())
	{
		sprite.update(currentAnimation, currentIndex);
	}
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	/* vẽ sprite tại vị trí 10,10 */
	sprite.render(10, 10, currentAnimation, currentIndex);
}

Game::Game()
{
}


Game::~Game()
{
}
