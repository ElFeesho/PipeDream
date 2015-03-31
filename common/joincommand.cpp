//
// Created by Christopher Sawczuk on 28/03/2015.
//

#include <string.h>
#include "../common/joincommand.h"
#include "../common/payload.h"


JoinCommand::JoinCommand(int playerId) : id(playerId)
{
}

JoinCommand::~JoinCommand()
{

}

int JoinCommand::getType()
{
	return 1;
}

int JoinCommand::getId()
{
	return id;
}

Payload *JoinCommand::parcel()
{
	unsigned char *data = new unsigned char[sizeof(int)*2];
	int type = getType();
	memcpy(data, &type, sizeof(int));
	memcpy(data+sizeof(int), &id, sizeof(int));
	return new Payload(id, data, sizeof(int)*2);
}
