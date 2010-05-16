#include "Collision.h"
#include "HTObj.h"
#include <vector>

HTObj *Collision::getObj1() { return obj1; }
HTObj *Collision::getObj2() { return obj2; }

Collision::Collision(HTObj *p_obj1, HTObj *p_obj2) :
	obj1 (p_obj1),
	obj2 (p_obj2)
{}
