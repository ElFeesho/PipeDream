#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <map>
#include <string>
#include "sprite.h"
#include "position.h"
#include "../client/spriterenderer.h"

class Actor
{
public:
	Actor(std::map<std::string, Sprite *> sprites) : spriteMap(sprites), currentSprite(nullptr), actorPosition(0, 0)
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
private:
	std::map<std::string, Sprite *> spriteMap;
	Sprite *currentSprite;
	SpriteRenderer spriteRenderer;
	Position actorPosition;
};

#endif
