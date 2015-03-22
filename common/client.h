#ifndef __CLIENT_H__
#define __CLIENT_H__

class Client
{
public:
	virtual ~Client() = 0;
	virtual int supportedPipeDreamVersion() = 0;
};

extern "C" {

Client *loadClient();

}

#endif
