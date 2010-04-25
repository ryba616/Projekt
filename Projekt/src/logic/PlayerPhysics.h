#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "../common/Vecf.h"
#include "../logic/Player.h"

class PlayerPhysics
{
public:
	void move();
	void setPlayer(Player *p);

private:
	void update();
	Player *p;
	Vecf moveVector;


};

#endif