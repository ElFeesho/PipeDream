#include <SDL/SDL.h>

#include <iostream>

#include "../common/server.h"
#include "../common/client.h"

#include "../common/receiver.h"
#include "../common/transmitter.h"
#include "moduleloader.h"
#include "sdlgfx.h"
#include "../common/joincommand.h"
#include "sdltimeprovider.h"

using namespace std;

class Transceiver : public Receiver, public Transmitter
{
public:
	Transceiver()
	{

	}

	~Transceiver()
	{

	}

	vector<Payload*> read()
	{
		vector<Payload*> pending;
  		pending.swap(receivedPayloads);
  		receivedPayloads.clear();
		return pending;
	}

	void transmit(Payload* data)
	{
		receivedPayloads.push_back(data);
	}
private:
	vector<Payload*> receivedPayloads;
};

class Game {
public:
	Game(SdlGfx *GFX, SDLTimeProvider *timeProviderInstance, ModuleLoader<Server *> *serverModuleLoader,
			  ModuleLoader<Client *> *clientModuleLoader) : gfx(GFX), timeProvider(timeProviderInstance), serverLoader(serverModuleLoader), clientLoader(clientModuleLoader)
	{

	}

	~Game()
	{
		if (server)
		{
			delete server;
		}

		if (client)
		{
			delete client;
		}

		delete serverLoader;
		delete clientLoader;
		delete gfx;
	}

	void loadModules()
	{
		server = serverLoader->load();
		client = clientLoader->load();

		clientToServer = new Transceiver();
		serverToClient = new Transceiver();

		server->registerReceiver(clientToServer);
		server->registerTransmitter(serverToClient);

		client->registerReceiver(serverToClient);
		client->registerTransmitter(clientToServer);
		client->registerGfx(gfx);
		client->registerTimeProvider(timeProvider);
	}

	void iterate()
	{
		server->update();
		client->update();

		gfx->render();
	}

	void clientJoinServer()
	{
		JoinCommand *command = new JoinCommand(1024);
		clientToServer->transmit(command->parcel());
	}

	bool shouldRun();


private:
	Gfx *gfx { 0 };
	Server *server { 0 };
	Client *client { 0 };
	TimeProvider *timeProvider;
	ModuleLoader<Server*> *serverLoader;
	ModuleLoader<Client*> *clientLoader;

	Transceiver *clientToServer;
	Transceiver *serverToClient;
};

int main(int argc, char **argv)
{
	cout << "PipeDream Game" << endl;

	try
	{
		Game game(new SdlGfx(), new SDLTimeProvider(),
					 new ModuleLoader<Server *>("modules/libserver.dylib", "loadServer"),
					 new ModuleLoader<Client *>("modules/libclient.dylib", "loadClient"));
		game.loadModules();

		game.clientJoinServer();

		while(game.shouldRun())
		{
			game.iterate();
		}
	}
	catch(ModuleLoaderException *e)
	{
		cerr << "Failed to load modules" << endl;
		cerr << "Reason: " << e->getErrorReason() << endl;
		delete e;
		return -1;
	}


	return 0;
}

bool Game::shouldRun()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

