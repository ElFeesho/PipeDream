#include <iostream>

#include <server.h>
#include <client.h>

#include "moduleloader.h"

using namespace std;

class Game {
public:
	Game(ModuleLoader<Server*> *serverModuleLoader, ModuleLoader<Client*> *clientModuleLoader) : serverLoader(serverModuleLoader), clientLoader(clientModuleLoader)
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
	}

	void loadModules()
	{
		server = serverLoader->load();
		client = clientLoader->load();
	}

	void iterate()
	{
		server->update();
		client->update();
	}
private:
	Server *server { 0 };
	Client *client { 0 };
	ModuleLoader<Server*> *serverLoader;
	ModuleLoader<Client*> *clientLoader;
};

int main(int argc, char **argv)
{
	cout << "PipeDream Game" << endl;
	Game game(new ModuleLoader<Server*>("../server/server.lib", "loadServer"), new ModuleLoader<Client*>("../client/client.lib", "loadClient"));

	try
	{
		game.loadModules();
	}
	catch(ModuleLoaderException *e)
	{
		cerr << "Failed to load modules" << endl;
		cerr << "Reason: " << e->getErrorReason() << endl;
		delete e;
		return -1;
	}

	while(1)
	{
		game.iterate();
	}

	return 0;
}
