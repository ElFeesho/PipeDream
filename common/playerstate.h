#ifndef __PLAYERSTATE_H__
#define __PLAYERSTATE_H__

#include "../common/canparcel.h"

#include <string>

using namespace std;

class PlayerState : public CanParcel
{
public:
	PlayerState() {};
	~PlayerState() {};

	string levelName()
	{
		return "test.map";
	};

	virtual Payload *parcel() override
	{
		return new Payload(-1, (unsigned char*)"1234", 4);
	};

private:
};

#endif

