#include <allegro.h>
#include "Platform.h"

int Platform::getX() { return x; }
int Platform::getY() { return y; }
int Platform::getW() { return w; }
int Platform::getH() { return h; }


Platform::Platform(int _x, int _y, int _w, int _h) :
	x(_x),
	y(_y),
	w(_w),
	h(_h)
{}
