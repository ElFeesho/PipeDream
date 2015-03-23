#include <iostream>

#include <server.h>
#include <client.h>

#include <receiver.h>
#include <transmitter.h>


#include "moduleloader.h"

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

		clientToServer = new Transceiver();
		serverToClient = new Transceiver();

		server->registerReceiver(clientToServer);
		server->registerTransmitter(serverToClient);

		client->registerReceiver(serverToClient);
		client->registerTransmitter(clientToServer);
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

	Transceiver *clientToServer;
	Transceiver *serverToClient;
};

int main(int argc, char **argv)
{
	cout << "PipeDream Game" << endl;


	try
	{
		Game game(new ModuleLoader<Server*>("../server/server.lib", "loadServer"), new ModuleLoader<Client*>("../client/client.lib", "loadClient"));
		game.loadModules();

		while(1)
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
