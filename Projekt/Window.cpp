#include <allegro.h>
#include "Window.h"
#include "Player.h"


void Window::drawWindow()
{
	allegro_init();
	install_keyboard();
	
	initWindow();

	drawBackground();
	Player p;
	p.draw();

	readkey();

	allegro_exit();
}
void Window::initWindow()
{
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	set_palette(default_palette);
	clear_to_color(screen, makecol(173, 216, 230));
}
void Window::setBackground()
{
	bg = create_bitmap(200, 100);
	bg = load_bitmap("./gfx/bg.bmp", default_palette);
}
void Window::drawBackground()
{
	setBackground();
	blit(bg, screen, 0, 0, 0, 0, bg->w, bg->h);
}

