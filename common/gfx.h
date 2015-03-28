#ifndef PIPEDREAM_GFX_H
#define PIPEDREAM_GFX_H

class Gfx
{
public:
	virtual ~Gfx() {};
	virtual void render() = 0;
};

#endif //PIPEDREAM_GFX_H
