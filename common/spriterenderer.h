//
// Created by Christopher Sawczuk on 31/03/2015.
//

#ifndef PIPEDREAM_SPRITERENDERER_H
#define PIPEDREAM_SPRITERENDERER_H

#include "../common/gfx.h"
#include "../common/sprite.h"

class SpriteRenderer
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void draw(Gfx *gfx, Sprite *sprite, int x, int y);
};

#endif //PIPEDREAM_SPRITERENDERER_H
