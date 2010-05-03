#ifndef PLATFORM_H
#define PLATFORM_H

#include <Allegro.h>
#include "../common/Vec.h"


class Platform {
public:
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x, y, w, h;
};

#endif