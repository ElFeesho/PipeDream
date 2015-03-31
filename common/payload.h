#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

#include <cstdio>

class Payload
{
public:
	Payload(int origin, unsigned char *data, size_t length) : payloadOrigin(origin), payloadData(data), payloadLength(length) {}
	~Payload() {
		delete payloadData;
	}

	int getOrigin()
	{
		return payloadOrigin;
	}

	unsigned char *getPayloadData()
	{
		return payloadData;
	}

	size_t getPayloadLength()
	{
		return payloadLength;
	}

private:
	int payloadOrigin;
	unsigned char *payloadData;
	size_t payloadLength;
};

#endif
