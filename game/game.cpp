#include <iostream>

#include <server.h>
#include <client.h>

#include "moduleloader.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "PipeDream Game" << endl;
	Server *serverInstance;
	Client *clientInstance;
	try
	{
		ModuleLoader<Server *> serverLoader("../server/server.lib", "loadServer");
		serverInstance = serverLoader.load();

		ModuleLoader<Client *> clientLoader("../client/client.lib", "loadClient");
		clientInstance = clientLoader.load();

		delete serverInstance;
		delete clientInstance;
	}
	catch(ModuleLoaderException *e)
	{
		cerr << "Failed to create server instance from server module" << endl;
		cerr << "Reason: " << e->getErrorReason() << endl;
		delete e;
		return -1;
	}
	return 0;
}
