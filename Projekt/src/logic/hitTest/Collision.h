#ifndef COLLISION_H
#define COLLISION_H

#include <Allegro.h>
#include "HTObj.h"
#include <vector>

class Collision
{
public:
	Collision(HTObj *p_obj1, HTObj *p_obj2);
	HTObj *getObj1();
	HTObj *getObj2();

private:
	HTObj *obj1;
	HTObj *obj2;
};

#endif