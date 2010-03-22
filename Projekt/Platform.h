#include <Allegro.h>


#ifndef PLATFORM_H
#define PLATFORM_H

class Platform {
	int x, y, w, h;
	BITMAP *platforma = NULL; //deklaracja bitmapy (wskaznik na nia)
public:
	Platform(int _x, int _y, int _w, int _h);
	setBitmap(char *bgPath);
	int getX(){return x;}
	int getY(){return y;}
	int getW(){return w;}
	int getH(){return h;}
};

#endif