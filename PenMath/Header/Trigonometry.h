#pragma once

namespace PenMath
{
	constexpr float c_pi		= 3.141592653589793f;		// useful constant pi -> 3.141592...
	constexpr float c_2pi		= 6.283185307179586f;		// useful constant 2 * pi -> 6.28318...
	constexpr float c_halfPi	= 1.570796326794896f;		// useful constant pi / 2 -> 1.57079...

	/// <summary>
	/// Sinus function (using Bhaskara I's approximation)
	/// </summary>
	/// <param name="angle">value in RADIAN</param>
	float sin(float angle);

	/// <summary>
	/// Cosinus function (using Bhaskara I's approximation)
	/// </summary>
	/// <param name="angle">value in RADIAN</param>
	float cos(float angle);

	/// <summary>
	/// Tan function (using Bhaskara I's approximation)
	/// </summary>
	/// <param name="angle">value in RADIAN</param>
	float tan(float angle);

	float asin(float value);

	float acos(float value);

	float atan(float value);

	float atan2(float valueA, float valueB);
}