#include <iostream>

#include <server.h>

using namespace std;

class GameServer : public Server
{
public:
	GameServer();
	~GameServer();
	int supportedPipeDreamVersion();
	void update();
};

GameServer::GameServer()
{
	cout << "Created GameServer" << endl;
}

GameServer::~GameServer()
{
	cout << "Destroying GameServer" << endl;
}

void GameServer::update()
{
	cout << "Server Update" << endl;
}

int GameServer::supportedPipeDreamVersion()
{
	return 1;
}

extern "C" {

Server *loadServer()
{
	return new GameServer();
}

}
