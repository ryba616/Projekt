#include <allegro.h>
#include "gfx/Graphics.h"
#include "logic/Player.h"

int main()
{
	// inicjacja biblioteki allegro
	allegro_init();
	install_keyboard();
	install_mouse();



	allegro_exit();
	return 0;
}

END_OF_MAIN();