#include <Allegro.h>


#ifndef PLATFORM_H
#define PLATFORM_H

class Platform {
public:
	Platform(int _x, int _y, int _w, int _h);
	void setBitmap(char *bgPath);
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x, y, w, h;
	BITMAP *gfx; //deklaracja bitmapy (wskaznik na nia)
};

#endif