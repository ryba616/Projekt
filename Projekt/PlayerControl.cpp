#include <allegro.h>
#include "PlayerControl.h"


PlayerControl::PlayerControl(Player *player) :
	p(player)
{
}

void PlayerControl::run()
{
	if (walkListener() == -1) p->setX(p->getX() - 10);
	if (walkListener() == 1) p->setX(p->getX() + 10);
}

int PlayerControl::walkListener()
{
	if(key[KEY_LEFT]) return -1;
	if(key[KEY_RIGHT]) return 1;
	return 0;
}