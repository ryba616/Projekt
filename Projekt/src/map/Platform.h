#ifndef PLATFORM_H
#define PLATFORM_H

#include <Allegro.h>


class Platform {
public:
	Platform(int _x, int _y, int _w, int _h);
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x, y, w, h;
};

#endif