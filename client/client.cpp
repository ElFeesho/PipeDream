#include <iostream>

#include <client.h>

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
private:
	Transmitter *transmitter;
	Receiver *receiver;
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
	cout << "Client update" << endl;
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

extern "C" {

Client *loadClient()
{
	return new GameClient();
}

}
