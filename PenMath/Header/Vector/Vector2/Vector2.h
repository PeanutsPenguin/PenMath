#pragma once 

#include <Vector/VectorBase.h>

#if defined(VECTOR2_DEBUG)
#include <ostream>
#endif

namespace PenMath
{
	class Radian;

	template<typename _Type>
	struct Vector<2, _Type>
	{
#pragma region CONSTRUCTORS
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
#pragma endregion

#pragma region BASIC_VEC2
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
#pragma endregion

#pragma region OPERATOR_VEC2

		operator Vector<4, _Type>() const;		//Convertion operator into a vector4

		operator Vector<3, _Type>() const;		//Convertion operator into a vector2

		Vector<2, _Type>&	operator=(const Vector<2, _Type>&)		= default;			//Default operator = to assign values of another vector

		Vector<2, _Type>&	operator=(Vector<2, _Type>&&)			= default;			//Default operator = to move another vector into this on	

		_Type&				operator[](size_t index);									//Operator [] to access values 

		const _Type&		operator[](size_t index) const;								//Operator [] to access values with const

		Vector<2, _Type>	operator-(void) const;										//Operator - to negate the vector 2

		bool				operator==(const Vector<2, _Type>&) const;					//Operator == to see if the vector is equal to another

		bool				operator!=(const Vector<2, _Type>&) const;					//Operator != to see if the vector is different than another

		bool				operator<(const Vector<2, _Type>&) const;					//Operator < for Vector 2 (comparing magnitude)

		bool				operator<=(const Vector<2, _Type>&) const;					//Operator <= for Vector 2 (comparing magnitude)r

		bool				operator>(const Vector<2, _Type>&) const;					//Operator > for Vector 2 (comparing magnitude)er

		bool				operator>=(const Vector<2, _Type>&) const;					//Operator >= for Vector 2 (comparing magnitude)er

		Vector<2, _Type>&	operator++(void);											//Operator ++ for Vector2, Increment by one all elements in vector 		

		Vector<2, _Type>&	operator--(void);											//Operator -- for Vector2, Decrease by one all elements in vector 

		Vector<2, _Type>	operator+(const Vector<2, _Type>&) const;					//Operator + for Vector2

		Vector<2, _Type>&	operator+=(const Vector<2, _Type>&);						//Operator += for Vector2

		Vector<2, _Type>	operator+(_Type) const;										//Operator + for a single value

		Vector<2, _Type>&	operator+=(_Type);											//Operator += for a single value

		Vector<2, _Type>	operator-(const Vector<2, _Type>&) const;					//Operator - for Vector2

		Vector<2, _Type>&	operator-=(const Vector<2, _Type>&);						//Operator -= for Vector2

		Vector<2, _Type>	operator-(_Type) const;										//Operator - for a single value

		Vector<2, _Type>&	operator-=(_Type);											//Operator -= for a single value

		Vector<2, _Type>	operator*(const Vector<2, _Type>&) const;					//Operator * to multiply by vector 2 to the current one

		Vector<2, _Type>&	operator*=(const Vector<2, _Type>&);						//Operator *= for Vector2

		Vector<2, _Type>	operator*(_Type) const;										//Operator * to multiply by a constant

		Vector<2, _Type>&	operator*=(_Type);											//Operator *= to multiply by a constant

		Vector<2, _Type>	operator/(const Vector<2, _Type>&) const;					//Operator / to divide by a vector 2 to the current one

		Vector<2, _Type>&	operator/=(const Vector<2, _Type>&);						//Operator /= to divide by a vector 2 to the current one

		Vector<2, _Type>	operator/(_Type) const;										//Operator / to divide by a constant

		Vector<2, _Type>&	operator/=(_Type);											//Operator /= to divide by a constantR
#pragma endregion
		
#pragma region FUNC
		_Type				magnitude(void) const;													//Return the magnitude of the vector

		_Type				magnitudeSquared(void) const;											//Return the squared magnitude of the vector

		/// <summary>
		/// Normalize this vector (divide by its magnitude)
		/// </summary>
		void				normalize(void);

		/// <summary>
		/// Return the dot product with the Vec2 in parameter
		/// </summary>
		_Type				dot(const Vector<2, _Type>&) const;

		/// <summary>
		/// Return the cross product with the Vec2 in parameter
		/// </summary>
		_Type				cross(const Vector<2, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<2, _Type>	project(const Vector<2, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<2, _Type>	reflect(const Vector<2, _Type>&) const;
#pragma endregion

#pragma region STATIC_FUNC
		/// <summary>
		/// Returns distance between two Vec2 
		/// </summary>
		static _Type				distance(const Vector<2, _Type>&, const Vector<2, _Type>&);

		/// <summary>
		/// Returns distance squared between two Vec2 (bypass the sqrt of the distance() function)
		/// </summary>
		static _Type				distanceSquared(const Vector<2, _Type>&, const Vector<2, _Type>&);

		/// <summary>
		/// Returns true if the vector is unit
		/// </summary>
		static bool					isUnit(const Vector<2, _Type>&);

		/// <summary>
		/// Return the normal vector of the vector in parameter
		/// </summary>
		static Vector<2, _Type>		normal(const Vector<2, _Type>&);

		/// <summary>
		/// Return the dot product between two Vec2
		/// </summary>
		static _Type				dot(const Vector<2, _Type>&, const Vector<2, _Type>&);	

		/// <summary>
		/// Return the cross product between two Vec2
		/// </summary>
		static _Type				cross(const Vector<2, _Type>&, const Vector<2, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary>
		static Vector<2, _Type>		project(const Vector<2, _Type>&, const Vector<2, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary>
		static Vector<2, _Type>		reflect(const Vector<2, _Type>&, const Vector<2, _Type>&);
#pragma endregion

#pragma region ANGLE

#if defined(VECTOR2_ANGLE)
		static Radian		angle(const Vector<2, _Type>&, const Vector<2, _Type>&);										//Return the radian angle between two vectors 

		static Radian		angle(const Vector<2, _Type>&, const Vector<2, _Type>&, const Vector<2, _Type>&);				//Return the radian angle between three vectors 
#endif
#pragma endregion
		_Type x;
		_Type y;
	};

#if defined(VECTOR2_DEBUG)

	template <typename _Type>
	std::ostream& operator<<(std::ostream&, const Vector<2, _Type>&);			//Operator << to debug a vector in the console

#endif
	using Vector2 =		typename Vector<2, int>;
	using Vector2f =	typename Vector<2, float>;
	using Vector2d =	typename Vector<2, double>;
}

//TODO CONVERTION OPERATOR FOR BASIC TYPE
#include <Vector/Vector2/Vector2.hpp>