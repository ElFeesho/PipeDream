//
// Created by Christopher Sawczuk on 28/03/2015.
//

#include <SDL/SDL.h>
#include "sdlgfx.h"

SdlGfx::SdlGfx()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(800, 600, 0, SDL_SWSURFACE);
}

SdlGfx::~SdlGfx()
{
	SDL_FreeSurface(SDL_GetVideoSurface());
	SDL_Quit();
}

void SdlGfx::render()
{
	SDL_Flip(SDL_GetVideoSurface());
}
