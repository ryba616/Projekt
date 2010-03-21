#include "Player.h"

#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

class PlayerControl
{
public:
	PlayerControl(Player *player);
	void run();
private:
	int walkListener(); // sprawdza czy postac rusza sie na boki, zwraca: -1 lewo, 1 prawo, 0 brak
	Player *p;
};

#endif