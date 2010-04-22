#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include "../logic/Player.h"


class InputListener
{
public:
	InputListener(Player *player);
	void run();   //metoda wywolywana w programie i musi spelniac cala funkcje inputlistenera
	bool isPressedRight();
	bool isPressedLeft();
	bool isPressedESC();
private:
	int walkListener();  // sprawdza czy postac rusza sie na boki, zwraca: -1 lewo, 1 prawo, 0 brak
	int interfaceListener(); // ta metoda ma nasluchiwac klawiszy zwiazanych z interfejsem, obecnie jest to tylko klawisz ESC
	Player *p;

	static bool RIGHT;
	static bool LEFT;
	static bool ESC;


};

#endif