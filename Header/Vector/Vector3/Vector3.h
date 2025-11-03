#pragma once 

#include <Vector/VectorBase.h>

#if defined(VECTOR3_DEBUG)
	#include <ostream>
#endif

namespace PenMath
{
	class Radian;

	template<typename _Type>
	struct Vector<3, _Type>
	{
#pragma region CONSTRUCTORS

		Vector(void);									//Empty constructor							

		/// <summary>
		/// Unique parameter constructor
		/// </summary>
		/// <param name="">x,y AND z value</param>
		Vector(_Type);

		/// <summary>
		/// Parameter constructor
		/// </summary>
		Vector(_Type, _Type, _Type);

		Vector(const Vector<3, _Type>&) = default;		//Default copy constructors 
		Vector(Vector<3, _Type>&&) = default;			//Default move constructors

		~Vector(void) = default;						//Default destructor (yes it's in the constructors category)

		#pragma endregion

#pragma region BASIC_VEC3
		/// <summary>
		/// Return a Vector3 (0, 0, 0)
		/// </summary>
		static Vector<3, _Type>	Zero(void);				

		/// <summary>
		/// Return a Vector3 (1, 1, 1)
		/// </summary>
		static Vector<3, _Type>	One(void);

		/// <summary>
		/// Return a Vector3 (0, 1, 0)
		/// </summary>
		static Vector<3, _Type>	Up(void);

		/// <summary>
		/// Return a Vector3 (0, -1, 0)
		/// </summary>
		static Vector<3, _Type>	Down(void);

		/// <summary>
		/// Return a Vector3 (-1, 0, 0)
		/// </summary>
		static Vector<3, _Type>	Left(void);

		/// <summary>
		/// Return a Vector3 (1, 0, 0)
		/// </summary>
		static Vector<3, _Type>	Right(void);

		/// <summary>
		/// Return a Vector3 (0, 0, 1)
		/// </summary>
		static Vector<3, _Type>	Front(void);
		
		/// <summary>
		/// Return a Vector3 (0, 0, -1)
		/// </summary>
		static Vector<3, _Type>	Back(void);

#pragma endregion

#pragma region OPERATOR_VEC3

		operator Vector<4, _Type>() const;		//Convertion operator into a vector4

		operator Vector<2, _Type>() const;		//Convertion operator into a vector2

		Vector<3, _Type>&	operator=(const Vector<3, _Type>&) = default;					//Default operator = to assign values of another vector

		Vector<3, _Type>&	operator=(Vector<3, _Type>&&) = default;						//Default operator = to move another vector into this on	

		_Type&				operator[](size_t index);										//Operator [] to access values 

		const _Type&		operator[](size_t index) const;									//Operator [] to access values with const

		Vector<3, _Type>	operator-(void) const;											//Operator - to negate the vector 3

		bool				operator==(const Vector<3, _Type>&) const;						//Operator == to see if the vector is equal to another

		bool				operator!=(const Vector<3, _Type>&) const;						//Operator != to see if the vector is different than another

		bool				operator<(const Vector<3, _Type>&) const;						//Operator < for Vector3 (comparing magnitude)

		bool				operator<=(const Vector<3, _Type>&) const;						//Operator <= for Vector3 (comparing magnitude)r

		bool				operator>(const Vector<3, _Type>&) const;						//Operator > for Vector3 (comparing magnitude)er

		bool				operator>=(const Vector<3, _Type>&) const;						//Operator >= for Vector3 (comparing magnitude)er

		Vector<3, _Type>&	operator++(void);												//Operator ++ for Vector3, Increment by one all elements in vector 		

		Vector<3, _Type>&	operator--(void);												//Operator -- for Vector3, Decrease by one all elements in vector 

		Vector<3, _Type>	operator+(const Vector<3, _Type>&) const;						//Operator + for Vector3

		Vector<3, _Type>&	operator+=(const Vector<3, _Type>&);							//Operator += for Vector3

		Vector<3, _Type>	operator+(_Type) const;											//Operator + for a single value

		Vector<3, _Type>&	operator+=(_Type);												//Operator += for a single value

		Vector<3, _Type>	operator-(const Vector<3, _Type>&) const;						//Operator - for Vector3

		Vector<3, _Type>&	operator-=(const Vector<3, _Type>&);							//Operator -= for Vector3

		Vector<3, _Type>	operator-(_Type) const;											//Operator - for a single value

		Vector<3, _Type>&	operator-=(_Type);												//Operator -= for a single value

		Vector<3, _Type>	operator*(const Vector<3, _Type>&) const;						//Operator * to multiply by vector 3 to the current one

		Vector<3, _Type>&	operator*=(const Vector<3, _Type>&);							//Operator *= for Vector3

		Vector<3, _Type>	operator*(_Type) const;											//Operator * to multiply by a constant

		Vector<3, _Type>&	operator*=(_Type);												//Operator *= to multiply by a constant

		Vector<3, _Type>	operator/(const Vector<3, _Type>&) const;						//Operator / to divide by a vector 3 to the current one

		Vector<3, _Type>&	operator/=(const Vector<3, _Type>&);							//Operator /= to divide by a vector 3 to the current one

		Vector<3, _Type>	operator/(_Type) const;											//Operator / to divide by a constant

		Vector<3, _Type>&	operator/=(_Type);												//Operator /= to divide by a constantR
#pragma endregion

#pragma region FUNC

		_Type	magnitude(void) const;

		_Type	magnitudeSquared(void) const;

		/// <summary>
		/// Normalize this vector (divide by its magnitude)
		/// </summary>
		void				normalize(void);

		/// <summary>
		/// Return the dot product with the Vec3 in parameter
		/// </summary>
		_Type				dot(const Vector<3, _Type>&) const;

		/// <summary>
		/// Return the cross product with the Vec3 in parameter
		/// </summary>
		Vector<3, _Type>	cross(const Vector<3, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<3, _Type>	project(const Vector<3, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<3, _Type>	reflect(const Vector<3, _Type>&) const;

		#pragma endregion

#pragma region STATIC_FUNC

		/// <summary>
		/// Return the distance between the two Vector3
		/// </summary>
		static _Type				distance(const Vector<3, _Type>&, const Vector<3, _Type>&);

		/// <summary>
		/// Return the distance squared between the two Vector3 (bypass the sqrt() from the distance() function)
		/// </summary>
		static _Type				distanceSquared(const Vector<3, _Type>&, const Vector<3, _Type>&);

#if defined(VECTOR3_CAST)
		/// <summary>
		/// Return the 2D distance between two vectors
		/// </summary>
		static _Type				distance2(const Vector<3, _Type>&, const Vector<3, _Type>&);	

		/// <summary>
		/// Return the 2D distance between two vectors
		/// </summary>
		static _Type				distance2Squared(const Vector<3, _Type>&, const Vector<3, _Type>&);
#endif
		/// <summary>
		/// Returns true if the vector is unit
		/// </summary>
		static bool					isUnit(const Vector<3, _Type>&);

		/// <summary>
		/// Return the normal vector of the vector in parameter
		/// </summary>
		static Vector<3, _Type>		normal(const Vector<3, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary
		static Vector<3, _Type>		project(const Vector<3, _Type>&, const Vector<3, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary>
		static Vector<3, _Type>		reflect(const Vector<3, _Type>&, const Vector<3, _Type>&);	

		/// <summary>
		/// Return the dot product between two Vec3
		/// </summary>
		static _Type				dot(const Vector<3, _Type>&, const Vector<3, _Type>&);

		/// <summary>
		/// Return the cross product between two Vec3
		/// </summary>
		static Vector<3, _Type>		cross(const Vector<3, _Type>&, const Vector<3, _Type>&);

		#pragma endregion

#pragma region ANGLE

#if defined(VECTOR3_ANGLE)
		/// <summary>
		/// Return the angle in Radian between two vector3
		/// </summary>
		static Radian		angle(const Vector<3, _Type>&, const Vector<3, _Type>&);

		/// <summary>
		/// Return the angle in Radian between three vector3
		/// </summary>
		static Radian		angle(const Vector<3, _Type>&, const Vector<3, _Type>&, const Vector<3, _Type>&);

		/// <summary> 
		/// Return the angle between the calling vector and the vector in parameter
		/// </summary>
		Radian				angleFrom(const Vector<3, _Type>& other, bool range) const;

		/// <summary>
		/// Rotate the vector with three radian for each axis
		/// </summary>
		void				rotate(const Radian&, const Radian&, const Radian&);		

		/// <summary>
		/// Rotate the vector with a specific radian and a vec 3 for wich axis 
		/// </summary>
		void				rotate(const Radian&, const Vector<3, _Type>&);					
#endif
#pragma endregion

		_Type x;
		_Type y;
		_Type z;
	};

#if defined(VECTOR3_DEBUG)

	template <typename _Type>
	std::ostream& operator<<(std::ostream&, const Vector<3, _Type>&);			//Operator << to debug a vector in the console

#endif

	using Vector3 = typename Vector<3, int>;
	using Vector3f = typename Vector<3, float>;
	using Vector3d = typename Vector<3, double>;
}

#include <Vector/Vector3/Vector3.hpp>