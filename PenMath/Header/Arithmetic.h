#pragma once 

#define EPSILON 0.000001f
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

namespace PenMath
{
	bool	almostEqual(float, float);		// Return true when values are equal to 10^-6
	int		ceiling(float);					// Return lowest integer value higher or equal to parameter (Round-up)
	float	clamp(float, float, float);		// Return parameter limited by the given range
	int		floor(float);					// Return highest integer value lower or equal to parameter (Round-down)
	float	power(float, int);				// Return base^exponent
	float	fmod(float, float);				// Return floating point remainder of a division
	void	swap(int&, int&);				// Swaps 2 integers
	void	swap(float&, float&);			// Swaps 2 floats
}