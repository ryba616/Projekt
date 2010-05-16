#include <allegro.h>
#include "Graphics.h"

void Graphics::init()
{
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0, 0);//pe³ny ekran wydaje mi siê stosowniejszy niz okno, ale jak cos to zmien na WINDOWED
	set_palette(default_palette);
	clear_to_color(screen, makecol(0, 0, 0));

	buffer = create_bitmap(RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
}

void Graphics::setPlayer(Player *_p) { p = _p; }
void Graphics::setMap(Map *_m) { map = _m; }

void Graphics::drawWindow()
{
	countOffset();
	prepareBuffer();
	blit(buffer, screen, 0, 0, 0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
}

void Graphics::loadMapData()
{
	platforms = map->getPlatforms();
}

void Graphics::createElements() // raczej nazwa metody do zmiany
{
	// tlo
	bg.setParent(&buffer);
	bg.setImgPath(map->getBgPath());
	bg.setSourcePoint(offset.x, offset.y);
	bg.setSize(RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	bg.prepareNormal();

	// player
	player.setParent(&buffer);
	player.setImgPath("./gfx/player.bmp");
	player.setDestPoint((RESOLUTION_WIDTH/2)-20, (RESOLUTION_HEIGHT/2)-20);
	player.setSize(40, 40);
	player.prepareNormal();

	loadMapData();
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		Drawable p;
		p.setParent(&buffer);
		p.setImgPath(platforms[i].getBgPath());
		p.setSize(platforms[i].getW(), platforms[i].getH());
		p.setBasePoint(platforms[i].getX(), platforms[i].getY());
		p.setDestPoint(offset.x, offset.y);
		p.prepareBackground(10, 10);
		environment.push_back(p);
	}
}

void Graphics::prepareBuffer()
{
	clear_to_color(buffer, makecol(0,0,0));

	// tlo
	bg.setSourcePoint(offset.x, offset.y);
	bg.draw();


	// elementy otoczenia
	for(unsigned int i = 0; i < environment.size(); i++)
	{
		environment[i].setDestPoint(environment[i].bx - offset.x, environment[i].by - offset.y);
		environment[i].draw();
	}

	
	// player
	player.draw();
}

// TODO
void Graphics::countOffset()
{
	offset.x = -((RESOLUTION_WIDTH/2)-20) + p->getX();
	offset.y = -((RESOLUTION_HEIGHT/2)-20) + p->getY();
}