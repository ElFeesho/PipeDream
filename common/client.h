#ifndef __CLIENT_H__
#define __CLIENT_H__

class Client
{
public:
	virtual ~Client() = 0;
	virtual int supportedPipeDreamVersion() = 0;
};

Client::~Client()
{
	// Pure virtual destructors still need to be defined...
}

extern "C" {
Client *loadClient();
}

#endif
