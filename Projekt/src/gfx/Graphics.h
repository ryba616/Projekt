#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../logic/Player.h"
#include "../map/Platform.h"
#include "../map/Map.h"
#include "Drawable.h"
#include <vector>


class Graphics
{
public:
	void init(); // inicjuje (tworzy) okno gry
	void drawWindow(); // rysuje okno gry
	void loadMapDatas(Map *map); // zapisuje w pola dane potrzebne do rysowania elementów mapy pobrane z instancji klasy Map
	void loadPlayer(Player *_p); // zapisuje wskaŸnik na gracza do pola p



private:

	std::vector<Platform> platforms; // kontener zawieraj¹cy instancjê klasy Platform, ale tylko te które maj¹ zostaæ wyœwietlone na ekranie
	std::vector<BITMAP*> platform_bitmaps; // kontener zawieraj¹cy przygotowane do wyœwietlenia bitmapy platform

	std::vector<Drawable> graphics; // kontener zawierajacy wszystkie obiekty ktore maja zostac narysowane na buforze

	BITMAP *buffer;
	Player *p;

	static const int RESOLUTION_WIDTH = 800; // tych stalych nalezy uzyc do okreslania rozdzielczosci okna
	static const int RESOLUTION_HEIGHT = 600;

};

#endif