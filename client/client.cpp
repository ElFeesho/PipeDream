#include <iostream>

#include "../common/payload.h"
#include "../common/client.h"
#include "../common/transmitter.h"
#include "../common/receiver.h"
#include "../common/gfx.h"
#include "../common/playerstate.h"
#include "../common/level.h"
#include "levelrenderer.h"
#include "../common/sprite.h"
#include "spriterenderer.h"

#include <vector>

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
private:
	Transmitter *transmitter;
	Receiver *receiver;
	vector<Payload*> pendingPayloads;
	Gfx *gfx;
	PlayerState *playerState { 0 };
	Level *currentLevel;

	Sprite *playerSprite;

	void processPayloads(vector<Payload *> payloads);

	TimeProvider *timeProvider;
	SpriteLoader *spriteLoader;
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
	vector<Payload*> readData = receiver->read();

	processPayloads(readData);

	if(playerState != nullptr)
	{
		currentLevel = new Level(playerState->levelName());
		playerSprite = spriteLoader->loadSprites("resources/sprites/character_walking.png")["walk_right"];
		playerState = nullptr;
	}

	if(currentLevel != nullptr)
	{
		LevelRenderer *levelRenderer = new LevelRenderer();
		levelRenderer->loadTileset(gfx);
		//levelRenderer->render(currentLevel, gfx);
		delete levelRenderer;

		playerSprite->update(timeProvider->ticks());
		SpriteRenderer *spriteRenderer = new SpriteRenderer(gfx->openImage("resources/sprites/character_walking.png"));
		spriteRenderer->draw(gfx, playerSprite, 10, 10);
		delete spriteRenderer;
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
	for(auto payload : payloads)
	{
		if(payload->getOrigin() == -1)
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
}
