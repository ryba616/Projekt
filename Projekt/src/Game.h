#ifndef GAME_H
#define GAME_H

#include "logic/Player.h"
#include "logic/PlayerPhysics.h"
#include "gfx/Graphics.h"
#include "input/InputListener.h"
#include "map/Map.h"


class Game
{
public:
	void init();
	void run();

private:
	Player p;
	Graphics gfx;
	InputListener input;
	Map map;
	PlayerPhysics physics;

};


#endif