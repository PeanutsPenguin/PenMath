#pragma once

#include "Vector/VectorBase.h"

namespace PenMath
{
	template<typename _Type>
	struct Vector<2, _Type>
	{
		/*****CONSTRUCTORS*****/
		
		Vector(void);									//Empty constructor							

		/// <summary>
		/// Unique parameter constructor
		/// </summary>
		/// <param name="value">x AND y value</param>
		Vector(_Type value);							

		/// <summary>
		/// Parameter constructor
		/// </summary>
		/// <param name="valueA">x value</param>
		/// <param name="valueB">y value</param>
		Vector(_Type valueA, _Type valueB);				

		Vector(const Vector<2, _Type>&) = default;		//Default copy constructors 
		Vector(const Vector<2, _Type>&&) = default;		//Default move constructors

		~Vector(void) = default;						//Default destructor (yes it's in the constructors category)
		/*****CONSTRUCTORS*****/

		_Type x;
		_Type y;
	};
}

#include <Vector/Vector2.hpp>
