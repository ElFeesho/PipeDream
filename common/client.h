#ifndef __CLIENT_H__
#define __CLIENT_H__

class Client
{
public:
	virtual ~Client() = 0;
	virtual int supportedPipeDreamVersion() = 0;
	virtual void update() = 0;
};

Client::~Client()
{
	// Pure virtual destructors still need to be defined...
}

void Client::update()
{

}

extern "C" {
Client *loadClient();
}

#endif
