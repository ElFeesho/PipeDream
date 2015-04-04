#include <iostream>

#include "../common/payload.h"
#include "../common/client.h"
#include "../common/transmitter.h"
#include "../common/receiver.h"
#include "../common/playerstate.h"
#include "../common/level.h"
#include "../common/actor.h"
#include "../common/luavm.h"

using namespace std;

class GameClient : public Client
{
public:
	GameClient();

	~GameClient();

	void update();

	int supportedPipeDreamVersion();

	void registerTransmitter(Transmitter *transmitter);

	void registerReceiver(Receiver *receiver);

	void registerGfx(Gfx *gfx);

	void registerTimeProvider(TimeProvider *timeProvider);

	void registerSpriteLoader(SpriteLoader *spriteLoader);

	void registerInputProvider(InputProvider *inputProvider);

private:
	Transmitter *transmitter;
	Receiver *receiver;
	vector<Payload *> pendingPayloads;
	Gfx *gfx;
	PlayerState *playerState{0};
	Level *currentLevel{nullptr};
	Actor *player{nullptr};

	void processPayloads(vector<Payload *> payloads);

	TimeProvider *timeProvider;
	SpriteLoader *spriteLoader;
	LuaVm *vm;

	vector<Actor*> actors;
};

GameClient::GameClient()
{
	cout << "Created GameClient" << endl;

}

GameClient::~GameClient()
{
	cout << "Destroying GameClient" << endl;
}

void GameClient::update()
{
	vector<Payload *> readData = receiver->read();

	processPayloads(readData);

	if (playerState != nullptr)
	{
		playerState = nullptr;
		vm->init("resources/player.lua");
	}

	if (actors.size() > 0)
	{
		long ticks = timeProvider->ticks();
		vm->update(ticks);
		for(auto actor : actors)
		{
			actor->update(ticks);
			actor->draw(gfx);
		}
	}


	gfx->render();
}

void GameClient::registerTransmitter(Transmitter *transmitter)
{
	this->transmitter = transmitter;
}

void GameClient::registerReceiver(Receiver *receiver)
{
	this->receiver = receiver;
}

int GameClient::supportedPipeDreamVersion()
{
	return 1;
}

void GameClient::registerGfx(Gfx *gfx)
{
	this->gfx = gfx;
}

extern "C" {

Client *loadClient()
{
	return new GameClient();
}

}

void GameClient::processPayloads(vector<Payload *> payloads)
{
	for (auto payload : payloads)
	{
		if (payload->getOrigin() == -1)
		{
			playerState = new PlayerState();
		}
	}
}

void GameClient::registerTimeProvider(TimeProvider *timeProvider)
{
	this->timeProvider = timeProvider;
}

void GameClient::registerSpriteLoader(SpriteLoader *spriteLoader)
{
	this->spriteLoader = spriteLoader;
	vm = new LuaVm(spriteLoader);
	vm->registerActorCreator([&](Actor *actor)
									 {
										 this->actors.push_back(actor);
									 });
}

void GameClient::registerInputProvider(InputProvider *inputProvider)
{
	inputProvider->addUpPressHandler([&](){

	});
	inputProvider->addUpReleaseHandler([&](){

	});

	inputProvider->addDownPressHandler([&](){

	});
	inputProvider->addDownReleaseHandler([&](){

	});

	inputProvider->addRightPressHandler([&](){

	});
	inputProvider->addRightReleaseHandler([&](){

	});

	inputProvider->addLeftPressHandler([&](){

	});
	inputProvider->addLeftReleaseHandler([&](){

	});
}
