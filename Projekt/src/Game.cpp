#include "Game.h"


void Game::init()
{
	gfx.init(); // inicjacja grafiki (okna gry)
	
	// inicjacja fizyki - przekazanie wskaznika na gracza i na warstwe input z ktorej pobierane sa informacje
	physics.setPlayer(&p);
	physics.setInput(&input);
	physics.setHitTest(&ht);

	// inicjacja mapy - ustawienie sciezki do mapy, wczytanie informacji z plikow mapy
	map.setMapPath("./maps/default/");
	map.loadInfo();
	map.loadPlatforms();

	// inicjacja warstwy hit test - wypelnienie kontenerow obiektow do testowania (gracz, platformy)
	ht.addCharacter(&p);
	ht.setMap(&map);
	ht.loadPlatforms();

	// inicjacja grafiki - przekazanie wskaznika na mape, na gracza oraz stworzenie elementow do rysowania
	gfx.setMap(&map);
	gfx.setPlayer(&p);
	gfx.createElements();

	//poczatkowa pozycja gracza
	p.setX(600);
	p.setY(400);

}

void Game::run()
{
	// glowna petla gry
	do
	{

		// warstwa rysujaca - rysuje okno na podstawie wszystkich danych z poprzedniej iteracji
		gfx.drawWindow();

		// warstwa input - sprawdza stan klawiszy w aktualnej iteracji
		input.run();

		// warstwa hit test - sprawdza hittesty
		ht.run();

		// warstwa logiczna - obliczenia zwiazane z gra (fizyka czyli ruch elementow)
		physics.move();


		// testy
//		if (input.LEFT) clear_to_color(screen, makecol(255, 255, 255));
//		else clear_to_color(screen, makecol(0, 0, 0));
		std::string test;
		char buff[256];
		_itoa_s(gfx.offset.x, buff, 10);
		test = "x: ";
		test += buff;
		_itoa_s(gfx.offset.y, buff, 10);
		test += " y: ";
		test += buff;

//		textout_ex(screen, font, buff, 40, 60, makecol(255, 255, 0), -1);

//		textout_ex(screen, font, map.getMapPath().c_str(), 10, 10, makecol(0, 0, 255), -1);
//		textout_ex(screen, font, test.c_str(), 10, 10, makecol(0, 0, 255), -1);

		rest(6);
	} while (!input.ESC);
}


