#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../logic/Player.h"
#include "../map/Platform.h"
#include "../map/Map.h"
#include "../common/Vec.h"
#include "../gfx/Drawable.h"
#include <vector>


class Graphics
{
public:
	void init(); // inicjuje (tworzy) okno gry
	void drawWindow(); // rysuje okno gry
	void setPlayer(Player *_p); // zapisuje wskaŸnik na gracza do pola p
	void setMap(Map *_m); // zapisuje wskaznik na instancje mapy
	void createElements(); // tworzy elementy do narysowania

	Vecf offset; // przesuniecie elementow wzgledem gracza


private:
	void loadMapData(); // zapisuje w pola dane potrzebne do rysowania elementów mapy pobrane z instancji klasy Map
	void prepareBuffer(); // rysuje wszystkie elementy (Drawable) na bufor
	void countOffset(); // oblicza aktualny offset

	std::vector<Platform> platforms; // kontener zawieraj¹cy instancjê klasy Platform, ale tylko te które maj¹ zostaæ wyœwietlone na ekranie
//	std::vector<BITMAP*> platform_bitmaps; // kontener zawieraj¹cy przygotowane do wyœwietlenia bitmapy platform
	std::vector<Drawable> environment; // kontener zawierajacy wszystkie elementy otoczenia
	
	Drawable bg; // tlo
	Drawable player; // grafika gracza

	BITMAP *buffer;
	char *bgPath; // sciezka do tla
	Player *p;
	Map *map;
	
	static const int RESOLUTION_WIDTH = 800; // tych stalych nalezy uzyc do okreslania rozdzielczosci okna
	static const int RESOLUTION_HEIGHT = 600;

};

#endif


// PROBLEMY
/*
1.	wsadzenie wszystkich elementow ktore maja zostac narysowane do jednej kolekcji, a nastepnie rysowanie ich po kolei stwarza dosyc powazny problem,
	mianowicie nie uwzglednia koniecznosci zachowania priorytetow (pewne grupy elementow musza byc rysowane w odpowiedniej kolejnosci - np tlo musi
	zostac narysowane w pierwszej kolejnosci, nastepnie platformy, na koncu postacie)
	TODO:	albo dodac do klasy Drawable pole priority i przy rysowaniu robic to zgodnie z priorytetami, albo stworzyc z kilka z gory okreslonych grup
			elementow (kilka wektorow), sklanialbym sie ku pierwszemu rozwiazaniu
ryba
*/