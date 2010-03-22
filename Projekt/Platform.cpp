#include <allegro.h>
#include "Platform.h"

void Platform::Platform(int _x, int _y, int _w, int _h)
{
x=_x;
y=_y;
w=_w;
h=_h;
}
void Platform::setBitmap(char *bgPath)
{
	platform = load_bmp(bgPath,default_palette); //ladowanie grafiki
	if (!platform) //sprawdzamy czy sie zaladowala bitmapka
	{
		set_gfx_mode(GFX_TEXT,0,0,0,0);
		allegro_message("Nie mogê za³adowaæ grafiki platformy!");
	}
}