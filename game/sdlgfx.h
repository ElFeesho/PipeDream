//
// Created by Christopher Sawczuk on 28/03/2015.
//

#ifndef PIPEDREAM_SDLGFX_H
#define PIPEDREAM_SDLGFX_H

#include "../common/gfx.h"

class SdlGfx : public Gfx
{
public:
	SdlGfx();
	~SdlGfx();

	void render();

	virtual Image *openImage(std::string filename) override;

	virtual void drawImage(Image *img, int x, int y, int width = -1, int height = -1, int sourceX = 0, int sourceY = 0) override;

	virtual int width();
	virtual int height();
private:
};

#endif //PIPEDREAM_SDLGFX_H
