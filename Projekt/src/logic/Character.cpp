#include <allegro.h>
#include "Character.h"

bool Character::isMoveable() { return true; }
int Character::getX() { return x; }
int Character::getY() { return y; }
int Character::getW() { return 40; }
int Character::getH() { return 40; }
char* Character::getGfxPath() { return gfxPath; }

void Character::setX(int _x) { x = _x; }
void Character::setY(int _y) { y = _y; }
void Character::setGfxPath(char *_gfxPath) { gfxPath = _gfxPath; }


bool Character::getCollisionState() { return m_collisionState; }
HTObj *Character::getCollisionTarget() { return m_collisionTarget; }
void Character::setCollisionState(bool p_state) { m_collisionState = p_state; }
void Character::setCollisionTarget(HTObj *p_target) { m_collisionTarget = p_target; }

bool Character::isStanding()
{
	// tutaj musze sprawdzic czy postac stoi
	// 1 - sprawdzam czy w ogole postac jest w kolizji - jezeli nie, na wstepie mozna zwrocic false
	if (!getCollisionState()) return false;

	// 2 - jezeli postac jest w kolizji, musze sprawdzic czy znajduje sie na platformie
	


	return true;

}