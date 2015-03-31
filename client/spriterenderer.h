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
	SpriteRenderer(Image *spriteImage, int startFrame, int cellWidth, int cellHeight);
	~SpriteRenderer();

	void draw(Gfx *gfx, Sprite *sprite, int x, int y);
private:
	const Image *spriteImage;
	const int startFrame;
	const int cellWidth;
	const int cellHeight;
	const int spriteWidthInCells;
};

#endif //PIPEDREAM_SPRITERENDERER_H
