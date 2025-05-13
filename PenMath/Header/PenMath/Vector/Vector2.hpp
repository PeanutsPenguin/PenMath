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

	TEMPLATE
	Vector<2, int> VEC2::Zero(void)
	{
		return VEC2(0);
	}

	TEMPLATE
	Vector<2, int> VEC2::One(void)
	{
		return VEC2(1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Up(void)
	{
		return VEC2(0, 1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Down(void)
	{
		return VEC2(0, -1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Left(void)
	{
		return VEC2(-1, 0);
	}

	TEMPLATE
	Vector<2, int> VEC2::Right(void)
	{
		return VEC2(1, 0);
	}
}
