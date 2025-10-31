#pragma once 

#define EPSILON 0.000001f
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

namespace PenMath
{
	/// <summary>
	/// Return true when values are equal to 10^-6
	/// </summary>
	/// <param name="a">: First number</param>
	/// <param name="b">: Second number</param>
	/// <returns>A true boolean if values are equal to 10^-6</returns>
	bool	almostEqual(float a, float b);

	/// <summary>
	/// Clamp a float to his highest integervalue
	/// </summary>
	/// <param name="value">: self-explaining</param>
	/// <returns>Lowest integer value higher or equal to parameter</returns>
	int		ceiling(float value);

	/// <summary>
	/// Clamp a float to his lowest integer value
	/// </summary>
	/// <param name="value">: self-explaining</param>
	/// <returns>Highest integer value lower or equal to parameter</returns>
	int		floor(float value);

	/// <summary>
	/// Clamp a value between a range
	/// </summary>
	/// <param name="value">: Value that needs clamping</param>
	/// <param name="min">: Minimum the value can have</param>
	/// <param name="max">: Maximum the value can have</param>
	/// <returns>Return min value or max value if the value is higher or lower, resturn the value if it's in range</returns>
	float	clamp(float value, float min, float max);

	/// <param name="numerator">: self-explaining</param>
	/// <param name="denominator">: self-explaining</param>
	/// <returns>The floating point remainder of a division</returns>
	float	fmod(float numerator, float denominator);	


	/// <summary>
	/// Power function (exemple 2^2 = 4)
	/// </summary>
	/// <param name="base">: Number that'll be multiplied</param>
	/// <param name="exponent">: Exponent of the number</param>
	/// <returns>The result of base^exponent</returns>
	float	power(float base, int exponent);
	
	/// <summary>
	/// Extract the floating point of a float (usefull for Square root, std::frexp)
	/// </summary>
	/// <param name="value">Base float number</param>
	/// <param name="mantissa"></param>
	/// <param name="exponent"></param>
	void	separatefloat(float value, float& mantissa, int& exponent);

	/// <summary>
	/// Will investigate
	/// </summary>
	/// <param name="mantissa"></param>
	/// <param name="exponent"></param>
	/// <returns></returns>
	float assembleFloat(float mantissa, int exponent);

	/// <summary>
	/// Well, self-explenatory i guess
	/// </summary>
	/// <param name="value">The value you want the sqaure root from</param>
	/// <returns>The result</returns>
	float squareRoot(float value);
}