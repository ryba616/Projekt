#include <allegro.h>
#include "Character.h"

int Character::getX() { return x; }
int Character::getY() { return y; }
char* Character::getGfxPath() { return gfxPath; }

void Character::setX(int _x) { x = _x; }
void Character::setY(int _y) { y = _y; }
void Character::setGfxPath(char *_gfxPath) { gfxPath = _gfxPath; }
