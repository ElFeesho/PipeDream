//
// Created by Christopher Sawczuk on 31/03/2015.
//

#include "../common/timeprovider.h"

#ifndef PIPEDREAM_SDLTIMEPROVIDER_H
#define PIPEDREAM_SDLTIMEPROVIDER_H

class SDLTimeProvider : public TimeProvider
{
public:
	SDLTimeProvider();
	~SDLTimeProvider();
	long ticks();
};

#endif //PIPEDREAM_SDLTIMEPROVIDER_H
