#include <allegro.h>
#include "gfx/Graphics.h"
#include "logic/Player.h"
#include "Game.h"

int main()
{
	// inicjacja biblioteki allegro
	allegro_init();
	install_keyboard();
	install_mouse();


	Game game;
	game.run();


	allegro_exit();
	return 0;
}

END_OF_MAIN();