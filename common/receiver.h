#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include <payload.h>

#include <vector>

using std::vector;

class Receiver
{
public:
	virtual vector<Payload*> read() = 0;
};

#endif
