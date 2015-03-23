#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include <payload.h>
#include <vector>

using std::vector;

class Transmitter
{
public:
	virtual void transmit(vector<Payload*> payloads) = 0;
};

#endif
