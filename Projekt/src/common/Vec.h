#ifndef VEC_H
#define VEC_H

class Vec
{
public:
	Vec();
	Vec(float _x, float _y);
	Vec normalize();
	float x, y;

};


#endif