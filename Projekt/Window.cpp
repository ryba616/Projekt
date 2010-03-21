#include <allegro.h>
#include "Window.h"
#include "Player.h"
#include "PlayerControl.h"


Window::Window(Player *player)
{
	p = player;
}

void Window::drawWindow()
{
	// tworzenie okna
	initWindow();

	// ustawienie grafiki gracza
	p->setGFX("./gfx/player.bmp", 40, 40);

	// utworzenie bufora wyœwietlanej czêœci mapy
	initMap();
	initBuffer();

	// utworzenie tla i jego pierwsze wyswietlenie
	setBackground();
	
	// utworzenie obiektu obs³ugi gracza
	PlayerControl pc(p);

	while (!key[KEY_ESC])
	{
		clear_to_color(map, makecol(0, 0, 0));
		clear_to_color(buffer, makecol(0, 0, 0));
		drawBuffer();
		pc.run(); // odpalenie obs³ugi gracza
		rest(1);
	}

}


void Window::setBackground()
{
	bg = create_bitmap(200, 100);
	bg = load_bitmap("./gfx/bg.bmp", default_palette);
}
void Window::initWindow()
{
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
	set_palette(default_palette);
	clear_to_color(screen, makecol(0, 0, 0));
}

void Window::initMap()
{
	map = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
}
void Window::prepareMap()
{
	blit(bg, map, p->getX(), p->getY(), 0, 0, screen->w, screen->h);
}
void Window::prepareBuffer()
{
	prepareMap();
	blit(map, buffer, 0, 0, 0, 0, buffer->w, buffer->h);

	masked_blit(p->getGFX(), buffer, 0, 0, (SCREEN_WIDTH/2) - 20, (SCREEN_HEIGHT/2) - 20, 40, 40);
}

void Window::initBuffer()
{
	buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
}
void Window::drawBuffer()
{
	prepareBuffer();
	blit(buffer, screen, 0, 0, 0, 0, screen->w, screen->h);
}