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

	void registerTransmitter(Transmitter *transmitter);
	void registerReceiver(Receiver *receiver);
private:
	Transmitter *transmitter;
	Receiver *receiver;
};

GameServer::GameServer()
{
	cout << "Created GameServer" << endl;
}

GameServer::~GameServer()
{
	cout << "Destroying GameServer" << endl;
}

void GameServer::registerTransmitter(Transmitter *transmitter)
{
	this->transmitter = transmitter;
}

void GameServer::registerReceiver(Receiver *receiver)
{
	this->receiver = receiver;
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
