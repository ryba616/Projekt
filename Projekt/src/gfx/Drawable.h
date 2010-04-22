#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <allegro.h>
#include <string>


class Drawable
{
public:
	void draw();


private:
	BITMAP **parent;
	BITMAP *me;
	std::string imgPath;
	int x;
	int y;
	int w;
	int h;


};

#endif