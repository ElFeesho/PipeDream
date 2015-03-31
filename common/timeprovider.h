//
// Created by Christopher Sawczuk on 31/03/2015.
//

#ifndef PIPEDREAM_TIMEPROVIDER_H
#define PIPEDREAM_TIMEPROVIDER_H

class TimeProvider
{
public:
	virtual ~TimeProvider() {};
	virtual long ticks() = 0;
};

#endif //PIPEDREAM_TIMEPROVIDER_H
