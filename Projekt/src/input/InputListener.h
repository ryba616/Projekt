#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include "../logic/Player.h"


class InputListener
{
public:
	InputListener();
	void run();   //metoda wywolywana w programie i musi spelniac cala funkcje inputlistenera

	bool RIGHT;
	bool LEFT;
	bool JUMP;
	bool ESC;

private:
	void walkListener();  // ustawia pola RIGHT i LEFT - ruch na boki
	void jumpListener(); // ustawia pole JUMP - skakanie
	void interfaceListener(); // ta metoda ma nasluchiwac klawiszy zwiazanych z interfejsem, obecnie jest to tylko klawisz ESC

	// pola pomocnicze
	bool m_isJumpPressed;
};

#endif