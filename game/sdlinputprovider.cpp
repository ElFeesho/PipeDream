//
// Created by Christopher Sawczuk on 02/04/2015.
//

#include <SDL_events.h>
#include "sdlinputprovider.h"

SDLInputProvider::SDLInputProvider()
{

}

SDLInputProvider::~SDLInputProvider()
{

}

void SDLInputProvider::addUpPressHandler(buttonPressHandler handler)
{
	upPressHandler = handler;
}

void SDLInputProvider::addDownPressHandler(buttonPressHandler handler)
{
	downPressHandler = handler;
}

void SDLInputProvider::addLeftPressHandler(buttonPressHandler handler)
{
	leftPressHandler = handler;
}

void SDLInputProvider::addRightPressHandler(buttonPressHandler handler)
{
	rightPressHandler = handler;
}

void SDLInputProvider::addAttackPressHandler(buttonPressHandler handler)
{
	attackPressHandler = handler;
}

void SDLInputProvider::addInventoryPressHandler(buttonPressHandler handler)
{
	inventoryPressHandler = handler;
}

void SDLInputProvider::addActionPressHandler(buttonPressHandler handler)
{
	actionPressHandler = handler;
}

void SDLInputProvider::addItemPressHandler(buttonPressHandler handler)
{
	itemPressHandler = handler;
}

void SDLInputProvider::addUpReleaseHandler(buttonPressHandler handler)
{
	upReleaseHandler = handler;
}

void SDLInputProvider::addDownReleaseHandler(buttonPressHandler handler)
{
	downReleaseHandler = handler;
}

void SDLInputProvider::addLeftReleaseHandler(buttonPressHandler handler)
{
	leftReleaseHandler = handler;
}

void SDLInputProvider::addRightReleaseHandler(buttonPressHandler handler)
{
	rightReleaseHandler = handler;
}

void SDLInputProvider::addAttackReleaseHandler(buttonPressHandler handler)
{
	attackReleaseHandler = handler;
}

void SDLInputProvider::addInventoryReleaseHandler(buttonPressHandler handler)
{
	inventoryReleaseHandler = handler;
}

void SDLInputProvider::addActionReleaseHandler(buttonPressHandler handler)
{
	actionReleaseHandler = handler;
}

void SDLInputProvider::addItemReleaseHandler(buttonPressHandler handler)
{
	itemReleaseHandler = handler;
}

void SDLInputProvider::update()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			SDLKey key = event.key.keysym.sym;
			if(key == SDLK_UP)
			{
				upPressHandler();
			}
			else if(key == SDLK_DOWN)
			{
				downPressHandler();
			}
			else if(key == SDLK_LEFT)
			{
				leftPressHandler();
			}
			else if(key == SDLK_RIGHT)
			{
				rightPressHandler();
			}
			else if(key == SDLK_SPACE)
			{
				attackPressHandler();
			}
			else if(key == SDLK_a)
			{
				inventoryPressHandler();
			}
			else if(key == SDLK_f)
			{
				actionPressHandler();
			}
			else if(key == SDLK_g)
			{
				itemPressHandler();
			}
		}
		else if(event.type == SDL_KEYUP)
		{
			SDLKey key = event.key.keysym.sym;
			if(key == SDLK_UP)
			{
				upReleaseHandler();
			}
			else if(key == SDLK_DOWN)
			{
				downReleaseHandler();
			}
			else if(key == SDLK_LEFT)
			{
				leftReleaseHandler();
			}
			else if(key == SDLK_RIGHT)
			{
				rightReleaseHandler();
			}
			else if(key == SDLK_SPACE)
			{
				attackReleaseHandler();
			}
			else if(key == SDLK_a)
			{
				inventoryReleaseHandler();
			}
			else if(key == SDLK_f)
			{
				actionReleaseHandler();
			}
			else if(key == SDLK_g)
			{
				itemReleaseHandler();
			}
		}
	}
}

