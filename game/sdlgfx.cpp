//
// Created by Christopher Sawczuk on 28/03/2015.
//

#include <SDL/SDL.h>
#include <SDL_image.h>
#include "sdlgfx.h"

class SDLImage : public Image
{
public:
	SDLImage(std::string filename) {
		image = IMG_Load(filename.c_str());
	}

	~SDLImage() {
		SDL_FreeSurface(image);
	}


	int width() const {
		return image->w;
	}

	virtual int height() const
	{
		return image->h;
	}

	SDL_Surface *getSurface() const
	{
		return image;
	}

private:
	SDL_Surface *image;
};

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

Image *SdlGfx::openImage(std::string filename)
{
	return new SDLImage(filename);
}

void SdlGfx::drawImage(Image *img, int x, int y, int width, int height, int sourceX, int sourceY)
{
	if(width == height && width == -1)
	{
		width = img->width();
		height = img->height();
	}

	SDLImage *image = dynamic_cast<SDLImage*>(img);
	SDL_Surface *screen = SDL_GetVideoSurface();

	SDL_Rect srcRect = { .x = (short)sourceX, .y = (short)sourceY, .w = (unsigned short)width, .h = (unsigned short)height };
	SDL_Rect dstRect = { .x = (short)x, .y = (short)y, .w = (unsigned short)width, .h = (unsigned short)height };

	SDL_BlitSurface(image->getSurface(), &srcRect, screen, &dstRect);
}

int SdlGfx::width()
{
	return SDL_GetVideoSurface()->w;
}

int SdlGfx::height()
{
	return SDL_GetVideoSurface()->h;
}