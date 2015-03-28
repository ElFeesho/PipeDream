#include <iostream>

#include "../common/payload.h"
#include "../common/client.h"
#include "../common/transmitter.h"
#include "../common/receiver.h"
#include "../common/gfx.h"

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
private:
	Transmitter *transmitter;
	Receiver *receiver;
	vector<Payload*> pendingPayloads;
	Gfx *gfx;
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
	cout << "Client update: " << readData.size() << endl;
	pendingPayloads.push_back(new Payload(1, (unsigned char*)"1234", 4));
	transmitter->transmit(pendingPayloads);
	pendingPayloads.clear();
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
