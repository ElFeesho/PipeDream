//
// Created by Christopher Sawczuk on 31/03/2015.
//

#ifndef PIPEDREAM_SPRITE_H
#define PIPEDREAM_SPRITE_H

#include <vector>

using std::vector;

class Sprite
{
public:
	Sprite(int frames, int startFrame, int cellWidth, int cellHeight, int delay) : numFrames(frames), startOffset(startFrame), frameWidth(cellWidth), frameHeight(cellHeight), frameDelay(delay)
	{
	}

	~Sprite(){}

	void update(long currentTime)
	{
		if(lastChange + frameDelay > currentTime)
		{
			lastChange = currentTime;
			currentFrame++;
			if(currentFrame >= numFrames)
			{
				currentFrame = 0;
			}
		}
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

	void reset()
	{
		currentFrame = numFrames;
		lastChange = 0;
	}
private:
	const int numFrames;
	const int startOffset;
	const int frameWidth;
	const int frameHeight;
	const int frameDelay;

	int currentFrame { 0 };
	long lastChange { 0 };
};

#endif //PIPEDREAM_SPRITE_H
