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
void Drawable::setBasePoint(int _x, int _y)
{
	bx = _x;
	by = _y;
}

void Drawable::prepareNormal()
{
	me = create_bitmap(w, h);
	me = load_bmp(imgPath.c_str(), default_palette);
}

void Drawable::prepareBackground(int bg_w, int bg_h)
{
	me = create_bitmap(w, h);
	BITMAP *bg;
	bg = create_bitmap(bg_w, bg_h);
	bg = load_bmp(imgPath.c_str(), default_palette);
	for (int i = 0; i * bg_w < w; i++) // width - kazda iteracja wstawia kolumne, ilosc iteracji potrzebna do wypelnienia calej szerokosci kolumnami
		for (int j = 0; j * bg_h < h; j++) // height - kazda iteracja wstawia element kolumny
			blit(bg, me, 0, 0, i * bg_w, j * bg_h, bg_w, bg_h);

}



Drawable::Drawable() :
	sx(0),
	sy(0),
	dx(0),
	dy(0)
{}