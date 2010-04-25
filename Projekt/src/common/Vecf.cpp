#include "../common/Vecf.h"


Vecf Vecf::normalize()
{
	return Vecf(x, y);
}

Vecf::Vecf(float _x, float _y) :
	x (_x),
	y (_y)
{}

Vecf::Vecf() {}
