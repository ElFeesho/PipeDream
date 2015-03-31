#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <map>
#include "sprite.h"

class Actor
{
public:
	Actor();
	~Actor();

private:
	std::map<std::string, Sprite *> spriteMap;

};

#endif
