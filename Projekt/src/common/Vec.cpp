#include "../common/Vec.h"


Vec Vec::normalize()
{
	return Vec(x, y);
}

Vec::Vec(float _x, float _y) :
	x (_x),
	y (_y)
{}

Vec::Vec() {}
