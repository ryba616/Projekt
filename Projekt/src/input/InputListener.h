#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include "../logic/Player.h"


class InputListener
{
public:
	void run();   //metoda wywolywana w programie i musi spelniac cala funkcje inputlistenera

	bool RIGHT;
	bool LEFT;
	bool ESC;

private:
	void walkListener();  // sprawdza czy postac rusza sie na boki, zwraca: -1 lewo, 1 prawo, 0 brak
	void interfaceListener(); // ta metoda ma nasluchiwac klawiszy zwiazanych z interfejsem, obecnie jest to tylko klawisz ESC

};

#endif