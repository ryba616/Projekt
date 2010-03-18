#include <allegro.h>
#include "Character.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character {
public:
	Player();
	~Player();
	BITMAP* generateBitmap(); // DEPRECATED
private:
};

#endif