#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <allegro.h>
#include <string>


class Drawable
{
public:
	Drawable();
	void draw();
	void setParent(BITMAP **_parent);
	void setSourcePoint(int _x, int _y);
	void setDestPoint(int _x, int _y);
	void setSize(int _w, int _h);
	void setImgPath(std::string _imgPath);
	void prepare();
	BITMAP* getBitmap();

	
	int sx; // source
	int sy;
	int dx; // destination
	int dy;
	int w;
	int h;

private:
	BITMAP **parent;
	BITMAP *me;
	std::string imgPath;

};

#endif