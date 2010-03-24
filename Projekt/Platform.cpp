#include <allegro.h>
#include "Platform.h"

Platform::Platform(int _x, int _y, int _w, int _h) :
	x(_x),
	y(_y),
	w(_w),
	h(_h)
{
}
void Platform::setBitmap(char *bgPath)
{
	gfx = load_bmp(bgPath, default_palette); //ladowanie grafiki
	if (!gfx) //sprawdzamy czy zaladowala sie bitmapka
	{
		set_gfx_mode(GFX_TEXT,0,0,0,0);
		allegro_message("Nie moge zaladowac grafiki tla platformy!");
	}
}
int Platform::getX() { return x; }
int Platform::getY() { return y; }
int Platform::getW() { return w; }
int Platform::getH() { return h; }