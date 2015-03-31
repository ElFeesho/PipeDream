//
// Created by Christopher Sawczuk on 30/03/2015.
//

#ifndef PIPEDREAM_LEVELRENDERER_H
#define PIPEDREAM_LEVELRENDERER_H

#include "../common/level.h"
#include "../common/gfx.h"
#include <string>

class LevelRenderer
{
public:
	LevelRenderer(){}
	~LevelRenderer(){
		delete tileset;
	}

	void loadTileset(Gfx *gfx);
	void render(Level *level, Gfx *gfx);
private:
	Image *tileset;
};

#endif //PIPEDREAM_LEVELRENDERER_H
