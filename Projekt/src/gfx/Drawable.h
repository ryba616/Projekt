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
	void prepareNormal();
	void prepareBackground(int bg_w, int bg_h);
	BITMAP* getBitmap();
	void setBasePoint(int _x, int _y);

	
	int sx; // source
	int sy;
	int dx; // destination
	int dy;
	int w;
	int h;
	int bx; // base (bazowe polozenie)
	int by;

private:
	BITMAP **parent;
	BITMAP *me;
	std::string imgPath;

};

#endif