//
// Created by Christopher Sawczuk on 31/03/2015.
//

#ifndef PIPEDREAM_SPRITELOADER_H
#define PIPEDREAM_SPRITELOADER_H

#include <string>
#include <map>
#include "sprite.h"

class SpriteLoader
{
public:
	virtual ~SpriteLoader(){}
	virtual std::map<std::string, Sprite*> loadSprites(std::string name) = 0;
};

#endif //PIPEDREAM_SPRITELOADER_H
