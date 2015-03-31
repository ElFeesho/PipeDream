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
	Sprite(int frames, vector<int> delays) : numFrames(frames), frameDelays(delays)
	{
	}

	~Sprite(){}

	void update(long currentTime)
	{
		if(lastChange + frameDelays[currentFrame] > currentTime)
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

	void reset()
	{
		currentFrame = numFrames;
		lastChange = 0;
	}
private:
	const int numFrames;
	const vector<int> frameDelays;

	int currentFrame { 0 };
	long lastChange { 0 };
};

#endif //PIPEDREAM_SPRITE_H
