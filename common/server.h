#ifndef __SERVER_H__
#define __SERVER_H__

class Transmitter;
class Receiver;

class Server
{
public:
	virtual ~Server() = 0;
	virtual int supportedPipeDreamVersion() = 0;

	virtual void update() = 0;

	virtual void registerTransmitter(Transmitter *transmitter) = 0;
	virtual void registerReceiver(Receiver *Receiver) = 0;
};

Server::~Server()
{
	// Pure virtual destructors still need to be defined...
}

extern "C" {
Server *loadServer();
}

#endif
