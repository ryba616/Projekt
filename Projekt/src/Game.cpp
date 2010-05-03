#include "Game.h"


void Game::init()
{
	map.setMapPath("./maps/default/");
	map.loadInfo();
//	map.loadPlatforms();

	gfx.init(); // inicjacja grafiki, okna gry
	gfx.setMap(&map);
	gfx.setPlayer(&p);
	gfx.createElements();
	
	p.setX(600);
	p.setY(400);

	physics.setPlayer(&p);
	physics.setInput(&input);


}

void Game::run()
{
	// glowna petla gry
	do
	{
		// warstwa input
		input.run();

		// warstwa logiczna
		physics.move();

		// warstwa rysujaca
		gfx.drawWindow();

		// testy
//		if (input.LEFT) clear_to_color(screen, makecol(255, 255, 255));
//		else clear_to_color(screen, makecol(0, 0, 0));
//		textout_ex(screen, font, map.getBgPath().c_str(), 10, 10, makecol(0, 0, 255), -1);

		rest(1);
	} while (!input.ESC);
}


