#pragma once 

#include <Vector/VectorBase.h>

#if defined(VECTOR4_DEBUG)
	#include <ostream>
#endif

namespace PenMath
{
	template<typename _Type>
	struct Vector<4, _Type>
	{
#pragma region CONSTRUCTORS

		Vector(void);									//Empty constructor							

		/// <summary>
		/// Unique parameter constructor
		/// </summary>
		/// <param name="">x, y, z AND w value</param>
		Vector(_Type);

		/// <summary>
		/// Parameter constructor
		/// </summary>
		Vector(_Type, _Type, _Type, _Type);

		Vector(const Vector<2, _Type>&, const Vector<2, _Type>&);		//Constructors with two Vector2

		Vector(const Vector<3, _Type>& xyz, _Type);						//Constructor with 1 vec3 and w value 

		Vector(const Vector<4, _Type>&) = default;		//Default copy constructors 
		Vector(Vector<4, _Type>&&) = default;			//Default move constructors

		~Vector(void) = default;						//Default destructor (yes it's in the constructors category)

#pragma endregion

#pragma region OPERATOR

#if defined(VECTOR4_CAST)
		operator Vector<3, _Type>() const;		//Convertion operator into a vector3

		operator Vector<2, _Type>() const;		//Convertion operator into a vector2
#endif

		Vector<4, _Type>&	operator=(const Vector<4, _Type>&) = default;					//Default operator = to assign values of another vector

		Vector<4, _Type>&	operator=(Vector<4, _Type>&&) = default;						//Default operator = to move another vector into this on	

		_Type&				operator[](size_t index);										//Operator [] to access values 

		const _Type&		operator[](size_t index) const;									//Operator [] to access values with const

		Vector<4, _Type>	operator-(void) const;											//Operator - to negate the vector 2

		bool				operator==(const Vector<4, _Type>&) const;						//Operator == to see if the vector is equal to another

		bool				operator!=(const Vector<4, _Type>&) const;						//Operator != to see if the vector is different than another

		bool				operator<(const Vector<4, _Type>&) const;						//Operator < for Vector4 (comparing magnitude)

		bool				operator<=(const Vector<4, _Type>&) const;						//Operator <= for Vector4 (comparing magnitude)r

		bool				operator>(const Vector<4, _Type>&) const;						//Operator > for Vector4 (comparing magnitude)er

		bool				operator>=(const Vector<4, _Type>&) const;						//Operator >= for Vector4 (comparing magnitude)er

		Vector<4, _Type>&	operator++(void);												//Operator ++ for Vector4, Increment by one all elements in vector 		

		Vector<4, _Type>&	operator--(void);												//Operator -- for Vector4, Decrease by one all elements in vector 

		Vector<4, _Type>	operator+(const Vector<4, _Type>&) const;						//Operator + for Vector4

		Vector<4, _Type>&	operator+=(const Vector<4, _Type>&);							//Operator += for Vector4

		Vector<4, _Type>	operator+(_Type) const;											//Operator + for a single value

		Vector<4, _Type>&	operator+=(_Type);												//Operator += for a single value

		Vector<4, _Type>	operator-(const Vector<4, _Type>&) const;						//Operator - for Vector4

		Vector<4, _Type>&	operator-=(const Vector<4, _Type>&);							//Operator -= for Vector4

		Vector<4, _Type>	operator-(_Type) const;											//Operator - for a single value

		Vector<4, _Type>&	operator-=(_Type);												//Operator -= for a single value

		Vector<4, _Type>	operator*(const Vector<4, _Type>&) const;						//Operator * to multiply by vector 2 to the current one

		Vector<4, _Type>&	operator*=(const Vector<4, _Type>&);							//Operator *= for Vector4

		Vector<4, _Type>	operator*(_Type) const;											//Operator * to multiply by a constant

		Vector<4, _Type>&	operator*=(_Type);												//Operator *= to multiply by a constant

		Vector<4, _Type>	operator/(const Vector<4, _Type>&) const;						//Operator / to divide by a vector 4 to the current one

		Vector<4, _Type>&	operator/=(const Vector<4, _Type>&);							//Operator /= to divide by a vector 4 to the current one

		Vector<4, _Type>	operator/(_Type) const;											//Operator / to divide by a constant

		Vector<4, _Type>&	operator/=(_Type);												//Operator /= to divide by a constant 

#pragma endregion
		
#pragma region FUNC

		_Type	magnitude(void) const;

		_Type	magnitudeSquared(void) const;

		/// <summary>
		/// Normalize this vector (divide by its magnitude)
		/// </summary>
		void				normalize(void);

		/// <summary>
		/// Return the dot product with the Vec4 in parameter
		/// </summary>
		_Type				dot(const Vector<4, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<4, _Type>	project(const Vector<4, _Type>&) const;

		/// <summary>
		/// Return the projection of this vector on the one in parameter
		/// </summary>
		Vector<4, _Type>	reflect(const Vector<4, _Type>&) const;

		#pragma endregion

#pragma region STATIC_FUNC

		/// <summary>
		/// Return the distance between the two Vector4
		/// </summary>
		static _Type				distance(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Return the distance squared between the two Vector4 (bypass the sqrt() from the distance() function)
		/// </summary>
		static _Type				distanceSquared(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Return the 2D distance between two vectors
		/// </summary>
		static _Type				distance2(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Return the 2D distance between two vectors
		/// </summary>
		static _Type				distance2Squared(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Returns true if the vector is unit
		/// </summary>
		static bool					isUnit(const Vector<4, _Type>&);

		/// <summary>
		/// Return the normal vector of the vector in parameter
		/// </summary>
		static Vector<4, _Type>		normal(const Vector<4, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary
		static Vector<4, _Type>		project(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Project the first vector on the other
		/// </summary>
		static Vector<4, _Type>		reflect(const Vector<4, _Type>&, const Vector<4, _Type>&);

		/// <summary>
		/// Return the dot product between two Vec4
		/// </summary>
		static _Type				dot(const Vector<4, _Type>&, const Vector<4, _Type>&);

#pragma endregion

		_Type x;
		_Type y;
		_Type z;
		_Type w;
	};

#if defined(VECTOR4_DEBUG)

	template <typename _Type>
	std::ostream& operator<<(std::ostream&, const Vector<3, _Type>&);			//Operator << to debug a vector in the console

#endif


	using Vector4 = typename Vector<4, int>;
	using Vector4f = typename Vector<4, float>;
	using Vector4d = typename Vector<4, double>;

}

#include <Vector/Vector4/Vector4.hpp>