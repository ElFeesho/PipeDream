//
// Created by Christopher Sawczuk on 28/03/2015.
//

#ifndef PIPEDREAM_COMMAND_H
#define PIPEDREAM_COMMAND_H

#include "../common/canparcel.h"

class Command : public CanParcel
{
public:
	virtual ~Command() {};
	virtual int getType() = 0;
	virtual Payload *parcel() = 0;
};

#endif //PIPEDREAM_COMMAND_H
