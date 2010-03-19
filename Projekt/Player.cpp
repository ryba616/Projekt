#include <allegro.h>
#include "Player.h"


Player::Player()
{
	setGFX("./gfx/player.bmp", 40, 40);
	x = 0;
	y = 0;
}
Player::~Player()
{
//	destroy_bitmap(gfx);
}


BITMAP* Player::generateBitmap() // DEPRECATED
{
	BITMAP *bmp = NULL;
	bmp = create_bitmap(40, 40);
	//clear_to_color(bmp, makecol(255, 0, 0));
	bmp = load_bmp("./gfx/player.bmp", default_palette);

	return bmp;
}