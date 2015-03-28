#ifndef __CLIENT_H__
#define __CLIENT_H__

class Transmitter;
class Receiver;
class Gfx;

class Client
{
public:
	virtual ~Client() = 0;
	virtual int supportedPipeDreamVersion() = 0;
	virtual void update() = 0;

	virtual void registerGfx(Gfx *gfx) = 0;
	virtual void registerTransmitter(Transmitter *transmitter) = 0;
	virtual void registerReceiver(Receiver *receiver) = 0;
};

Client::~Client()
{
	// Pure virtual destructors still need to be defined...
}

extern "C" {
Client *loadClient();
}

#endif
