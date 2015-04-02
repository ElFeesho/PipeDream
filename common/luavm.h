//
// Created by Christopher Sawczuk on 01/04/2015.
//

#include "scriptvm.h"
#include <lua5.2/lua.hpp>

#ifndef PIPEDREAM_LUAVM_H
#define PIPEDREAM_LUAVM_H

class LuaVm : public ScriptVm
{
public:
	LuaVm(SpriteLoader *spriteLoader);
	~LuaVm();
	void init(std::string scriptName) override;
	std::map<std::string, Sprite*> loadSpriteMap(std::string sprite);
	void registerActorCreator(std::function<void(Actor*)> actorCreator);

	void update(long ticks) override;

	void notifyActorCreated(Actor *actor);
private:
	SpriteLoader *spriteLoader;
	lua_State *vmState;
	std::function<void(Actor *)> actorCreatorCallback;
};

#endif //PIPEDREAM_LUAVM_H
