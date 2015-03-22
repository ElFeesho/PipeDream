#include <iostream>

#include <client.h>

using namespace std;

class GameClient : public Client
{
public:
	GameClient();
	~GameClient();
	int supportedPipeDreamVersion();
};

GameClient::GameClient()
{
	cout << "Created GameClient" << endl;
}

GameClient::~GameClient()
{
	cout << "Destroying GameClient" << endl;
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
