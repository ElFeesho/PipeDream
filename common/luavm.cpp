//
// Created by Christopher Sawczuk on 01/04/2015.
//

#include "luavm.h"
#include "luawrapper.h"

static std::map<lua_State *, LuaVm*> vmMap;

static luaL_Reg Actor_table[] = {
		{ NULL, NULL }
};

static Actor *Actor_new(lua_State *state)
{
	const char* id = luaL_checkstring(state, 1);
	const char* spriteFile = luaL_checkstring(state, 2);
	Actor *actor = new Actor(id, vmMap[state]->loadSpriteMap(spriteFile));
	vmMap[state]->notifyActorCreated(actor);
	return actor;
}

static int Actor_getPosition(lua_State *state)
{
	Actor *actor = luaW_check<Actor>(state, 1);
	lua_pushinteger(state, actor->getPosition().getX());
	lua_pushinteger(state, actor->getPosition().getY());
	return 2;
}

static int Actor_setPosition(lua_State *state)
{
	Actor *actor = luaW_check<Actor>(state, 1);
	actor->setPosition(luaL_checknumber(state, 2), luaL_checknumber(state, 3));
	return 0;
}


static int Actor_setCurrentSprite(lua_State *state)
{
	Actor *actor = luaW_check<Actor>(state, 1);
	actor->setCurrentSprite(luaL_checkstring(state, 2));
	return 0;
}

static luaL_Reg Actor_metatable[] = {
		{ "getPosition", Actor_getPosition },
		{ "setPosition", Actor_setPosition },
		{ "setCurrentSprite", Actor_setCurrentSprite},
		{ NULL, NULL }
};

LuaVm::LuaVm(SpriteLoader *loader) : spriteLoader(loader)
{
	vmState = luaL_newstate();
	vmMap[vmState] = this;
}

LuaVm::~LuaVm()
{
	lua_close(vmState);
	vmMap.erase(vmMap.find(vmState));
}

void LuaVm::init(std::string scriptName)
{
	luaL_openlibs(vmState);
	luaW_register<Actor>(vmState, "Actor", Actor_table, Actor_metatable, Actor_new);
	luaL_loadfile(vmState, scriptName.c_str());
	lua_pcall(vmState, 0, 0, 0);

}

std::map<std::string, Sprite *> LuaVm::loadSpriteMap(std::string sprite)
{
	return spriteLoader->loadSprites(sprite);
}

void LuaVm::registerActorCreator(std::function<void(Actor *)> actorCreator)
{
	actorCreatorCallback = actorCreator;
}

void LuaVm::update(long ticks)
{
	lua_getglobal(vmState, "onUpdate");
	lua_pushnumber(vmState, ticks);
	if(lua_pcall(vmState, 1, 0, 0) != 0)
	{
		cout << "error running function `f': " << lua_tostring(vmState, -1) << endl;
	}
}

void LuaVm::notifyActorCreated(Actor *actor)
{
	actorCreatorCallback(actor);
}
