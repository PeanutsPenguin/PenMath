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

	float fmod(float numerator, float denominator)
	{
		return numerator - ((int)(numerator / denominator)) * denominator;
	}

	void swap(int& valueA, int& valueB)
	{
		int cpy = valueA;
		valueA = valueB;
		valueB = cpy;
	}

	void swap(float& valueA, float& valueB)
	{
		float cpy = valueA;
		valueA = valueB;
		valueB = cpy;
	}
}



