//
// Created by Christopher Sawczuk on 01/04/2015.
//

#ifndef PIPEDREAM_SCRIPTVM_H
#define PIPEDREAM_SCRIPTVM_H

#include <string>
#include <functional>
#include "actor.h"
#include "spriteloader.h"

class ScriptVm
{
public:
	virtual ~ScriptVm() {};
	virtual void init(std::string scriptName) = 0;
	virtual void registerActorCreator(std::function<void(Actor*)> actorCreator) = 0;
	virtual void update(long ticks) = 0;
};

#endif //PIPEDREAM_SCRIPTVM_H
