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
		Vector(Vector<2, _Type>&&)		= default;		//Default move constructors

		~Vector(void) = default;						//Default destructor (yes it's in the constructors category)
		/*****CONSTRUCTORS*****/

		/*****Basic Vector2*****/
		
		/// <summary>
		/// //Return a vector (0, 0)
		/// </summary>
		/// <returns>(0, 0)</returns>
		static Vector<2, int>	Zero(void);			

		/// <summary>
		/// //Return a vector (1, 1)
		/// </summary>
		/// <returns>(1, 1)</returns>
		static Vector<2, int>	One(void);			
		
		/// <summary>
		/// //Return a vector (0, 1)
		/// </summary>
		/// <returns>(0, 1)</returns>
		static Vector<2, int>	Up(void);			

		/// <summary>
		/// //Return a vector (0, -1)
		/// </summary>
		/// <returns>(0, -1)</returns>
		static Vector<2, int>	Down(void);			

		/// <summary>
		/// //Return a vector (-1, 0)
		/// </summary>
		/// <returns>(-1, 0)</returns>
		static Vector<2, int>	Left(void);			

		/// <summary>
		/// //Return a vector (0, 1)
		/// </summary>
		/// <returns>(0, 1)</returns>
		static Vector<2, int>	Right(void);		
		/*****Basic Vector2*****/

		_Type x;
		_Type y;
	};


	using Vector2f = typename Vector<2, float>;
}

#include <Vector/Vector2.hpp>
