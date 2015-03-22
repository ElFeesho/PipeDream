#ifndef __SERVER_H__
#define __SERVER_H__

class Server
{
public:
	virtual ~Server() = 0;
	virtual int supportedPipeDreamVersion() = 0;
};

extern "C" {
	Server *loadServer();
}

#endif
