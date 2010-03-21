#include <allegro.h>
#include "Window.h"
#include "Player.h"


int main()
{
	// inicjacja biblioteki allegro
	allegro_init();
	install_keyboard();
	install_mouse();

	Player p; // tworzenie obiektu reprezentuj¹cego gracza

	Window w(&p);
	w.drawWindow(); // rysowanie okna

	allegro_exit();
	return 0;
}

END_OF_MAIN();