#include <allegro.h>
#include "../logic/PlayerPhysics.h"

void PlayerPhysics::move()
{
	if (input->RIGHT) p->setX(p->getX() + 5);
	if (input->LEFT) p->setX(p->getX() - 5);
}




void PlayerPhysics::setPlayer(Player *_p) { p = _p; }
void PlayerPhysics::setInput(InputListener *_input) { input = _input; }
