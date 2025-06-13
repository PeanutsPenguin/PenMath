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


		/*****Operators*****/
		Vector<2, _Type>&	operator=(const Vector<2, _Type>&)		= default;			//Default operator = to assign values of another vector

		Vector<2, _Type>&	operator=(Vector<2, _Type>&&)			= default;			//Default operator = to move another vector into this on	

		_Type&				operator[](size_t index);									//Operator [] to acces values 

		const _Type&		operator[](size_t index) const;								//Operator [] to acces values with const

		Vector<2, _Type>	operator-(void) const;										//Operator - to negate the vector 2

		bool				operator==(const Vector<2, _Type>&) const;					//Operator == to see if the vector is equal to another

		bool				operator!=(const Vector<2, _Type>&) const;					//Operator != to see if the vector is different than another

		bool				operator<(const Vector<2, _Type>&) const;					//Operator < for Vector 2 (comparing magnitude)

		bool				operator<=(const Vector<2, _Type>&) const;					//Operator <= for Vector 2 (comparing magnitude)r

		bool				operator>(const Vector<2, _Type>&) const;					//Operator > for Vector 2 (comparing magnitude)er

		bool				operator>=(const Vector<2, _Type>&) const;					//Operator >= for Vector 2 (comparing magnitude)er

		Vector<2, _Type>&	operator++(void);											//Operator ++ for Vector2, Increment by one all elements in vector 		

		Vector<2, _Type>&	operator--(void);											// Operator -- for Vector2, Decrease by one all elements in vector 

		Vector<2, _Type>	operator+(const Vector<2, _Type>& toAdd) const;				//Operator + for Vector2

		Vector<2, _Type>&	operator+=(const Vector<2, _Type>& toAdd);					// Operator += for Vector2

		Vector<2, _Type>	operator+(_Type toAdd) const;								//Operator + for a single value

		Vector<2, _Type>&	operator+=(_Type toAdd);									// Operator += for a single value

		Vector<2, _Type>	operator-(const Vector<2, _Type>& toSubtract) const;		//Operator - for Vector2

		Vector<2, _Type>&	operator-=(const Vector<2, _Type>& toSubtract);				//Operator -= for Vector2

		Vector<2, _Type>	operator-(_Type toSubtract) const;							//Operator - for a single value

		Vector<2, _Type>&	operator-=(_Type toSubtract);								//Operator -= for a single value

		Vector<2, _Type>	operator*(const Vector<2, _Type>& toMultiply) const;		//Operator * to multiply by vector 2 to the current one

		Vector<2, _Type>&	operator*=(const Vector<2, _Type>& toMultiply);				//Operator *= for Vector2

		Vector<2, _Type>	operator*(_Type) const;										//Operator * to multiply by a constant

		Vector<2, _Type>&	operator*=(_Type);											//Operator *= to multiply by a constant

		Vector<2, _Type>	operator/(const Vector<2, _Type>&) const;					//Operator / to divide by a vector 2 to the current one

		Vector<2, _Type>&	operator/=(const Vector<2, _Type>&);						//Operator /= to divide by a vector 2 to the current one

		Vector<2, _Type>	operator/(_Type) const;										//Operator / to divide by a constant

		Vector<2, _Type>&	operator/=(_Type);											//Operator /= to divide by a constant
		/*****Operators*****/


		_Type x;
		_Type y;
	};

	using Vector2 = typename Vector<2, int>;
	using Vector2f = typename Vector<2, float>;
	using Vector2d = typename Vector<2, double>;
}

//TODO CONVERTION OPERATOR FOR BASIC TYPE

#include <Vector/Vector2.hpp>
