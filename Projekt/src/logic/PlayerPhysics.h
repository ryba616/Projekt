#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "../common/Vec.h"
#include "../logic/Player.h"
#include "../logic/PlayerPhysics.h"
#include "../input/InputListener.h"

class PlayerPhysics
{
public:
	void move();
	void setPlayer(Player *_p);
	void setInput(InputListener *_input);

private:
	void update();
	Player *p;
	Vec moveVector;
	InputListener *input;

};

#endif