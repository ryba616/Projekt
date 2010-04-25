#include <allegro.h>
#include "Drawable.h"

void Drawable::draw()
{
	blit(me, *parent, x, y, 0, 0, w, h);
}