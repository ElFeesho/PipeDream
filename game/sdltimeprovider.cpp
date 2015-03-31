//
// Created by Christopher Sawczuk on 31/03/2015.
//

#include <SDL_timer.h>
#include "sdltimeprovider.h"

SDLTimeProvider::SDLTimeProvider()
{

}

SDLTimeProvider::~SDLTimeProvider()
{

}

long SDLTimeProvider::ticks()
{
	return SDL_GetTicks();
}
