#include <allegro.h>
#include "Graphics.h"

void Graphics::init()
{
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0, 0);//pe³ny ekran wydaje mi siê stosowniejszy niz okno, ale jak cos to zmien na WINDOWED
	set_palette(default_palette);
	clear_to_color(screen, makecol(0, 0, 0));

	buffer = create_bitmap(RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
}

void Graphics::loadPlayer(Player *_p)
{
	p = _p;
}

void Graphics::drawWindow()
{
	init();

	for(unsigned int i = 0; i < graphics.size() ; ++i)
	{
		graphics[i].draw();
	}

}

void Graphics::loadMapDatas(Map *map)
{
	platforms = map->getPlatforms();
	//z tego co widze to nie mozna nic wiecej wyciagnac z map, mam racje?
}