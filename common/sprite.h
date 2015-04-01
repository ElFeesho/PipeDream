#ifndef PIPEDREAM_SPRITE_H
#define PIPEDREAM_SPRITE_H

#include <vector>
#include "gfx.h"

using std::vector;

class Sprite
{
public:
	Sprite(Image *image, int frames, int startFrame, int cellWidth, int cellHeight, int delay) : spriteSheet(image), numFrames(frames), startOffset(startFrame), frameWidth(cellWidth), frameHeight(cellHeight), frameDelay(delay)
	{
	}

	~Sprite(){
		delete spriteSheet;
	}

	void update(long currentTime)
	{
		if(lastChange + frameDelay < currentTime)
		{
			lastChange = currentTime;
			currentFrame++;
			if(currentFrame >= numFrames)
			{
				currentFrame = 0;
			}
		}
	}

	Image *getSpriteSheet()
	{
		return spriteSheet;
	}

	int frame(){
		return currentFrame;
	}

	int width()
	{
		return frameWidth;
	}

	int height()
	{
		return frameHeight;
	}

	int offset()
	{
		return startOffset;
	}

	void reset(long currentTime)
	{
		currentFrame = 0;
		lastChange = currentTime;
	}
private:
	Image *spriteSheet;
	const int numFrames;
	const int startOffset;
	const int frameWidth;
	const int frameHeight;
	const int frameDelay;

	int currentFrame { 0 };
	long lastChange { 0 };
};

#endif //PIPEDREAM_SPRITE_H
