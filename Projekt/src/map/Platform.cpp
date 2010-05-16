#include <allegro.h>
#include "Platform.h"

void Platform::setX(int _x) { x = _x; }
void Platform::setY(int _y) { y = _y; }
void Platform::setW(int _w) { w = _w; }
void Platform::setH(int _h) { h = _h; }
void Platform::setBgPath(std::string _bgPath) { bgPath = _bgPath; }

bool Platform::isMoveable() { return false; }
int Platform::getX() { return x; }
int Platform::getY() { return y; }
int Platform::getW() { return w; }
int Platform::getH() { return h; }
std::string Platform::getBgPath() { return bgPath; }


bool Platform::getCollisionState() { return m_collisionState; }
HTObj *Platform::getCollisionTarget() { return m_collisionTarget; }
void Platform::setCollisionState(bool p_state) { m_collisionState = p_state; }
void Platform::setCollisionTarget(HTObj *p_target) { m_collisionTarget = p_target; }