//
// Created by Christopher Sawczuk on 28/03/2015.
//

#ifndef PIPEDREAM_JOINCOMMAND_H
#define PIPEDREAM_JOINCOMMAND_H

#include "../common/command.h"

class JoinCommand : public Command
{
public:
	JoinCommand(int playerId);
	~JoinCommand();

	int getId();

	int getType();

	Payload *parcel() override;

private:
	int id { 0 };
};

#endif //PIPEDREAM_JOINCOMMAND_H
