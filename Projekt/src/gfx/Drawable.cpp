#include <allegro.h>
#include "../gfx/Drawable.h"

void Drawable::draw()
{
	masked_blit(me, *parent, sx, sy, dx, dy, w, h);
}

BITMAP* Drawable::getBitmap() { return me; }

void Drawable::setParent(BITMAP **_parent) { parent = _parent; }
void Drawable::setImgPath(std::string _imgPath) { imgPath = _imgPath; }
void Drawable::setSourcePoint(int _x, int _y)
{
	sx = _x;
	sy = _y;
}
void Drawable::setDestPoint(int _x, int _y)
{
	dx = _x;
	dy = _y;
}
void Drawable::setSize(int _w, int _h)
{
	w = _w;
	h = _h;
}

void Drawable::prepare()
{
	me = create_bitmap(w, h);
	me = load_bmp(imgPath.c_str(), default_palette);
}



Drawable::Drawable() :
	sx(0),
	sy(0),
	dx(0),
	dy(0)
{}