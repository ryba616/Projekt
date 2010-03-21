#include "Player.h"

#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
	Window(Player *player);
	void drawWindow();
private:
	void setBackground();
	void initBuffer(); // tworzy bufor
	void drawBuffer(); // nanosi mape i gracza na bufor a nastepnie rysuje go na screenie
	void initMap(); // tworzy map
	void prepareMap(); // nanosi na map wszystkie elementy
	void prepareBuffer(); // wyswietla mape na screen
	void initWindow();

	BITMAP *bg;
	BITMAP *map;
	BITMAP *buffer;
	Player *p;

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

};

#endif