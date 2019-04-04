#include "Game.h"
#include"KEY.h"
#include"Player.h"
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
	//Player::getInstance()->setSprite(sprite);
	//Player::getInstance();
	bg.Init("resource/map/Stage3-1.png");
	//sprite.InitFromFile

	/* cho khung hình hiện tại là 0 */
	currentIndex = 0;
	currentAnimation = 1;


	/* khởi tạo thời gian làm chậm cỡ 1s (100 ms)*/
	timeDelay.init(100);

	x = 20, y = 30;
	//camera = new Camera(512, 448, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
}
/* Các câu lệnh cập nhật game */
void Game::GameUpdate()
{
	KEY::getInstance()->update();
	//camera->Update(Player::getInstance());
	/* Cập nhật sprite	*/
	/* Set ràng buộc thời gian */
	if (timeDelay.atTime())
	{
		//Player::getInstance()->getSprite()->update(currentAnimation, currentIndex);
		sprite.update(currentAnimation, currentIndex);
	}
	if (KEY::getInstance()->isLeftDown)
	{
		x--;
	}
	if (KEY::getInstance()->isRightDown)
	{
		x++;
	}
	if (KEY::getInstance()->isUpDown)
	{
		y--;
	}
	if (KEY::getInstance()->isDownDown)
	{
		y++;
	}
}
/* Các câu lệnh vẽ của game */
void Game::GameRender()
{
	RECT rect;
	SetRect(&rect, 0, 0, 300, 400);
	bg.Render(10, 10, 0, 0, &rect);
	/* vẽ sprite tại vị trí 10,10 */
	//Player::getInstance()->getSprite()->render(x, y, currentAnimation, currentIndex);
	sprite.render(x, y, currentAnimation, currentIndex);
	//camera->SetTransform(GameDirectX::getInstance()->GetDevice());
}

Game::Game()
{
}


Game::~Game()
{
}
