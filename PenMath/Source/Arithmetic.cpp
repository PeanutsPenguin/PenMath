#include <Arithmetic.h>

namespace PenMath
{
	bool almostEqual(float valueA, float valueB)
	{
		return FLOAT_EQ(valueA, valueB);
	}

	int ceiling(float value)
	{
		return (int)(value + 1);
	}

	float clamp(float value, float min, float max)
	{
		if (min > max)
		{
			return clamp(value, max, min);
		}

		if (value >= min && value <= max)
			return value;

		return (value < min ? min : max);
	}

	int floor(float value)
	{
		return (int)value;
	}

	float fmod(float numerator, float denominator)
	{
		return numerator - ((int)(numerator / denominator)) * denominator;
	}

	float power(float value, int exponent)
	{
		if (exponent == 0)
			return 1.f;
		else if (value == 0)
			return 0.f;

		float result = value;
		for (int i = 1; i < exponent; i++)
		{
			result *= value;
		}

		return result;
	}

	//Check this video if you want to rly understand this non-sense : https://youtu.be/p8u_k2LIZyo
	void separatefloat(float value, float& mantissa, int& exponent)
	{
		int binValue = *(int*)&value;

		exponent = ((binValue >> 23) & 0xFF) - 127;

		int mantissaBits = binValue & 0x7FFFFF;

		float fraction = 1.0f + (float)mantissaBits / (1 << 23);

		if (binValue & 0x80000000)
			fraction = -fraction;

		mantissa = fraction;
	}

	float assembleFloat(float mantissa, int exponent)
	{
		return mantissa * power(2.f, exponent);
	}

	float squareRoot(float value)
	{
		if (value <= 0)
			return 0;       // if negative number throw an exception?

		int exp = 0;
		float mantissa;

		separatefloat(value, mantissa, exp); // extract binary exponent from x

		if (exp & 1) {      // we want exponent to be even
			exp--;
			mantissa *= 2;
		}

		float y = (1 + mantissa) / 2; // first approximation
		float z = 0;

		while (y != z) {    // yes, we CAN compare doubles here!
			z = y;
			y = (y + mantissa / y) / 2;
		}

		return assembleFloat(y, exp / 2); // multiply answer by 2^(exp/2)}
	}
}



