#ifndef PIPEDREAM_GFX_H
#define PIPEDREAM_GFX_H

#include <string>

class Image
{
public:
	virtual ~Image() {}
	virtual int width() = 0;
	virtual int height() = 0;
};

class Gfx
{
public:
	virtual ~Gfx() {};
	virtual Image *openImage(std::string filename) = 0;
	virtual void drawImage(Image *img, int x, int y, int width = -1, int height = -1, int sourceX = -1, int sourceY = -1) = 0;
	virtual void render() = 0;
	virtual int width() = 0;
	virtual int height() = 0;
};

#endif //PIPEDREAM_GFX_H
