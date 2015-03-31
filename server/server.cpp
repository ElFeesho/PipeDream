#include <iostream>
#include <map>

#include "../common/server.h"
#include "../common/payload.h"
#include "../common/playerstate.h"
#include "../common/transmitter.h"
#include "../common/receiver.h"

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
	map<int, PlayerState*> playerStates;

	void processPayloads(vector<Payload *> payloads);
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

	processPayloads(readData);
	// Update entities?
}

int GameServer::supportedPipeDreamVersion()
{
	return 1;
}

void GameServer::processPayloads(vector<Payload *> payloads)
{
	for(auto payload : payloads)
	{
		cout << "ORIGIN: " << payload->getOrigin() << endl;
		playerStates[payload->getOrigin()] = new PlayerState();
		pendingPayloads.push_back(playerStates[payload->getOrigin()]->parcel());
	}
	for(auto payload : pendingPayloads)
	{
		transmitter->transmit(payload);
	}
	pendingPayloads.clear();
}

extern "C" {

Server *loadServer()
{
	return new GameServer();
}

}
