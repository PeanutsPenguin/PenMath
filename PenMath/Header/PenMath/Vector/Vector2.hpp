#pragma once 

#include <Vector/Vector2.h>

#define TEMPLATE template<typename _Type>
#define VEC2 Vector<2, _Type>

namespace PenMath
{
	TEMPLATE
	VEC2::Vector(void) : VEC2(_Type(0)) {}

	TEMPLATE
	VEC2::Vector(_Type val) : VEC2(val, val) {}

	TEMPLATE
	VEC2::Vector(_Type valA, _Type valB) : x(valA), y(valB) {}

}
