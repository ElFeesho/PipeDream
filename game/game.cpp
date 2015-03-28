#include <SDL/SDL.h>

#include <iostream>
#include <SDL_events.h>

#include "../common/server.h"
#include "../common/client.h"

#include "../common/receiver.h"
#include "../common/transmitter.h"
#include "moduleloader.h"
#include "sdlgfx.h"

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

	void transmit(vector<Payload*> data)
	{
		receivedPayloads.insert(receivedPayloads.end(), data.begin(), data.end());
	}
private:
	vector<Payload*> receivedPayloads;
};

class Game {
public:
	Game(Gfx *GFX, ModuleLoader<Server*> *serverModuleLoader, ModuleLoader<Client*> *clientModuleLoader) : gfx(GFX), serverLoader(serverModuleLoader), clientLoader(clientModuleLoader)
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
	}

	void iterate()
	{
		server->update();
		client->update();

		gfx->render();
	}

	bool shouldRun();

private:
	Gfx *gfx { 0 };
	Server *server { 0 };
	Client *client { 0 };
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
		Game game(new SdlGfx(), new ModuleLoader<Server*>("modules/libserver.dylib", "loadServer"), new ModuleLoader<Client*>("modules/libclient.dylib", "loadClient"));
		game.loadModules();

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
