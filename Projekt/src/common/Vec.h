#ifndef VEC_H
#define VEC_H

template<class Type>
class Vec
{
public:
	Vec();
	Vec(Type p_x, Type p_y);
	Vec normalize();
	Type x, y;

};

template<class Type>
Vec<Type> Vec<Type>::normalize()
{
	return Vec(x, y);
}

template<class Type>
Vec<Type>::Vec(Type p_x, Type p_y) :
	x (p_x),
	y (p_y)
{}

template<class Type>
Vec<Type>::Vec() :
	x (0),
	y (0)
{}

typedef Vec<float> Vecf;
typedef Vec<int> Veci;


#endif