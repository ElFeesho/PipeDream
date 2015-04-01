//
// Created by Christopher Sawczuk on 31/03/2015.
//

#include "spriterenderer.h"

static inline int spriteXCoord(int spriteWidthInCells, int frame, int cellWidth)
{
	return (frame % spriteWidthInCells) * cellWidth;
}

static inline int spriteYCoord(int spriteWidthInCells, int frame, int cellHeight)
{
	return (frame / spriteWidthInCells) * cellHeight;
}

SpriteRenderer::SpriteRenderer()
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::draw(Gfx *gfx, Sprite *sprite, int x, int y)
{
	int spriteWidthInCells = sprite->getSpriteSheet()->width() / sprite->width();
	int spriteFrame = sprite->offset() + sprite->frame();
	gfx->drawImage(sprite->getSpriteSheet(), x, y, sprite->width(), sprite->height(),
						spriteXCoord(spriteWidthInCells, spriteFrame, sprite->width()),
						spriteYCoord(spriteWidthInCells, spriteFrame, sprite->height()));
}
