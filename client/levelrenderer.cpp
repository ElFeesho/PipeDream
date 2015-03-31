//
// Created by Christopher Sawczuk on 30/03/2015.
//

#include "levelrenderer.h"

static inline int xCoord(int linearPoint)
{
	return (linearPoint%64)*16;
}

static inline int yCoord(int linearPoint)
{
	return (linearPoint / 64)*16;
}

static inline int tilesetXCoord(int tilesetWidthInTiles, int linearPoint)
{
	return (linearPoint%tilesetWidthInTiles)*16;
}

static inline int tilesetYCoord(int tilesetWidthInTiles, int linearPoint)
{
	return (linearPoint / tilesetWidthInTiles)*16;
}

void LevelRenderer::render(Level *level, Gfx *gfx)
{
	vector<int> bgTiles = level->getBgTiles();

	int tilesetWidthInTiles = tileset->width()/16;
	for(int i = 0; i < 64*64; i++)
	{
		int tile = bgTiles.at(i);
		gfx->drawImage(tileset, xCoord(i), yCoord(i), 16, 16, tilesetXCoord(tilesetWidthInTiles, tile), tilesetYCoord(tilesetWidthInTiles, tile));
	}
}

void LevelRenderer::loadTileset(Gfx *gfx)
{
	tileset = gfx->openImage("resources/tilesets/dungeon.png");
}
