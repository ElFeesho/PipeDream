//
// Created by Christopher Sawczuk on 31/03/2015.
//

#ifndef PIPEDREAM_PNGSPRITELOADER_H
#define PIPEDREAM_PNGSPRITELOADER_H

#include "../common/spriteloader.h"

class PngSpriteLoader : public SpriteLoader
{
public:
	PngSpriteLoader(Gfx *gfxWrapper);
	~PngSpriteLoader();


	virtual std::map<std::string, Sprite*> loadSprites(std::string name) override;
private:
	Gfx *gfx;
};


#endif //PIPEDREAM_PNGSPRITELOADER_H
