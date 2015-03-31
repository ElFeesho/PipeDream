//
// Created by Christopher Sawczuk on 31/03/2015.
//

#include "spriterenderer.h"

static inline int spriteXCoord(int spriteWidthInCells, int frame, int cellWidth)
{
	return (frame % spriteWidthInCells)*cellWidth;
}

static inline int spriteYCoord(int spriteWidthInCells, int frame, int cellHeight)
{
	return (frame / spriteWidthInCells)*cellHeight;
}

SpriteRenderer::SpriteRenderer(Image *image, int frame, int width, int height) : spriteImage(image), startFrame(frame), cellWidth(width), cellHeight(height), spriteWidthInCells(image->width()/cellWidth)
{

}

SpriteRenderer::~SpriteRenderer()
{
	delete spriteImage;
}

void SpriteRenderer::draw(Gfx *gfx, Sprite *sprite, int x, int y)
{
	gfx->drawImage(const_cast<Image*>(spriteImage), x, y, cellWidth, cellHeight, spriteXCoord(spriteWidthInCells, startFrame + sprite->frame(), cellWidth), spriteYCoord(spriteWidthInCells, startFrame + sprite->frame(), cellHeight));
}
