#include <iostream>

#include <server.h>
#include <payload.h>
#include <vector>

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
	vector<Payload*> pendingPayloads;
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
	cout << "Registered receiver: " << receiver << endl;
	this->receiver = receiver;
}

void GameServer::update()
{
	vector<Payload*> readData = receiver->read();
	cout << "Server Update: " << readData.size() << endl;
	transmitter->transmit(pendingPayloads);
	pendingPayloads.clear();
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
