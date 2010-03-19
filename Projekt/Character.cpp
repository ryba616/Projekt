#include <allegro.h>
#include "Character.h"

int Character::getX()
{
	return x;
}
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
	//clear_to_color(bmp, makecol(255, 0, 0));
	gfx = load_bmp(gfxPath, default_palette);
}
void Character::draw()
{
	masked_blit(gfx, screen, 0, 0, x, y, gfx->w, gfx->h);
}