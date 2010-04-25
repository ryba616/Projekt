#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <allegro.h>


class Drawable
{
public:
	void draw();

private:
	BITMAP **parent;
	BITMAP *me;
	char *imgPath;
	int x;
	int y;
	int w;
	int h;

};

#endif