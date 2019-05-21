#include "Sprite.h"
/* khởi lớp đọc file */
#include<fstream>
using namespace std;


void Sprite::InitFromFile(const char * imagePath, const char * infoPath)
{
	image = new GameTexture();
	ifstream fs(infoPath);
	ignoreLineIfstream(fs, 2);
	int a, r, g, b;
	fs >> a >> r >> g >> b;

	image->Init(imagePath, D3DCOLOR_ARGB(a, r, g, b));
	ignoreLineIfstream(fs, 2);
	int animationCount;
	fs >> animationCount;
	for (size_t i = 0; i < animationCount; i++)
	{
		Animation* animation = new Animation();
		ignoreLineIfstream(fs, 6);
		int frameCount;
		fs >> frameCount;
		ignoreLineIfstream(fs, 3);
		for (size_t frameIndex = 0; frameIndex < frameCount; frameIndex++)
		{
			FrameAnimation* frame = new FrameAnimation();
			int x, y, width, height, anchorX, anchorY;
			fs >> x >> y >> width >> height >> anchorX >> anchorY;
			SetRect(frame, x, y, x + width, y + height);
			frame->anchorX = anchorX;
			frame->anchorY = anchorY;
			animation->frames._Add(frame);
		}
		animations._Add(animation);
	}
}

void Sprite::update(int animationIndex, int& frameIndex)
{
	frameIndex = animations.at(animationIndex)->NextFrame(frameIndex);
}

void Sprite::render(int x, int y, int animationIndex, int frameIndex)
{
	auto animation = animations.at(animationIndex);
	auto frame = animation->frames.at(frameIndex);
	image->Render(x, y, frame->anchorX, frame->anchorY, frame);
}

Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}
