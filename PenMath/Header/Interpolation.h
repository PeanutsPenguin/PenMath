#pragma once 

#if defined(LERP_DEGREE)
	#include "Angle/Degree.h"
#endif

#if defined(LERP_RADIAN)
	#include "Angle/Radian.h"
#endif

#if defined(LERP_VECTOR2)
	#include "Vector/Vector2/Vector2.h"
#endif

#if defined(LERP_VECTOR3)
	#include "Vector/Vector3/Vector3.h"
#endif

#if defined(LERP_VECTOR4)
	#include "Vector/Vector4/Vector4.h"
#endif

namespace PenMath
{
	/// <summary>
	/// Lerp a value between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	float Lerp(float& valueA, float& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}

#if defined(LERP_DEGREE)
	/// <summary>
	/// Lerp a value between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	Degree	Lerp(Degree& valueA, Degree& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}
#endif

#if defined(LERP_RADIAN)
	/// <summary>
	/// Lerp a value between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	Radian	Lerp(Radian& valueA, Radian& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}
#endif

#if defined(LERP_VECTOR2)
	/// <summary>
	/// Lerp a Vector2 between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	template<typename _Type>
	Vector<2, _Type>	Lerp(Vector<2, _Type>& valueA, Vector<2, _Type>& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}
#endif

#if defined(LERP_VECTOR3)
	/// <summary>
	/// Lerp a Vector2 between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	template<typename _Type>
	Vector<3, _Type>	Lerp(Vector<3, _Type>& valueA, Vector<3, _Type>& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}
#endif

#if defined(LERP_VECTOR4)
	/// <summary>
	/// Lerp a Vector2 between valueA and valueB by ratio
	/// </summary>
	/// <param name="valueA">Base value</param>
	/// <param name="valueB">To go value</param>
	/// <param name="ratio">self-explainatory</param>
	template<typename _Type>
	Vector<4, _Type>	Lerp(Vector<4, _Type>& valueA, Vector<4, _Type>& valueB, float ratio)
	{
		if (ratio == 0)
			return valueA;
		else if (ratio == 1.f)
			return valueB;

		return (valueB - valueA) * ratio + valueA;
	}
#endif
}