#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <iostream>
#include <map>
#include <string>
#include "sprite.h"
#include "position.h"
#include "../common/spriterenderer.h"

using namespace std;

class Actor
{
public:
	Actor(std::string id, std::map<std::string, Sprite *> sprites) : actorId(id), spriteMap(sprites), currentSprite(nullptr), actorPosition(0, 0)
	{

	}

	~Actor()
	{

	}

	void setCurrentSprite(std::string sprite)
	{
		currentSprite = spriteMap[sprite];
	}

	void draw(Gfx *gfx)
	{
		if (currentSprite != nullptr)
		{
			spriteRenderer.draw(gfx, currentSprite, actorPosition.getX(), actorPosition.getY());
		}
	}

	void update(long ticks)
	{
		if (currentSprite != nullptr)
		{
			currentSprite->update(ticks);
		}
	}

	Position getPosition()
	{
		return actorPosition;
	}

	void setPosition(int x, int y)
	{
		actorPosition.setX(x);
		actorPosition.setY(y);
	}
private:
	std::string actorId;
	std::map<std::string, Sprite *> spriteMap;
	Sprite *currentSprite;
	SpriteRenderer spriteRenderer;
	Position actorPosition;
};

#endif
