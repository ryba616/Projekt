#include <allegro.h>
#include "Character.h"

int Character::getX() { return x; }
int Character::getY()
{
	return y;
}
void Character::setX(int nX)
{
	x = nX;
}
void Character::setY(int nY)
{
	y = nY;
}
void Character::setGFX(char *gfxPath, int w, int h)
{
	gfx = create_bitmap(w, h);
	gfx = load_bmp(gfxPath, default_palette);
}
BITMAP* Character::getGFX()
{
	return gfx;
}