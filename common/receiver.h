#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include <vector>

class Payload;

using std::vector;

class Receiver
{
public:
	virtual vector<Payload*> read() = 0;
};

#endif
