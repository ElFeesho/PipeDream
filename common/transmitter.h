#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include <vector>

using std::vector;

class Payload;

class Transmitter
{
public:
	virtual void transmit(vector<Payload*> payloads) = 0;
};

#endif
