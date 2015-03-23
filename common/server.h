#ifndef __SERVER_H__
#define __SERVER_H__

class Server
{
public:
	virtual ~Server() = 0;
	virtual int supportedPipeDreamVersion() = 0;

	virtual void update() = 0;
};

Server::~Server()
{
	// Pure virtual destructors still need to be defined...
}

extern "C" {
Server *loadServer();
}

#endif
