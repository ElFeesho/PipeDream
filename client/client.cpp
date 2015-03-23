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
