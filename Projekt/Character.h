#include <allegro.h>

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
	int getX();
	int getY();
	void setX(int nX);
	void setY(int nY);
	void setGFX(char *gfxPath, int w, int h);
	void draw();

protected:
	BITMAP *gfx;
	int x;
	int y;
	
};

#endif