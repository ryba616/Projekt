#include <allegro.h>
#include "InputListener.h"


void InputListener::run()
{
}

int InputListener::walkListener()
{
	if(key[KEY_LEFT]) return -1;
	if(key[KEY_RIGHT]) return 1;
	return 0;
}


InputListener::InputListener(Player *player) :
	p(player)
{
}