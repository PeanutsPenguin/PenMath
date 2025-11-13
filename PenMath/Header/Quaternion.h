#pragma once 

#include <Vector/Vector3/Vector3.hpp>
#include <Vector/Vector4/Vector4.hpp>

#if defined(QUATERNION_DEBUG)
	#include <ostream>
#endif

namespace PenMath
{
	class Mat4;

	/// <summary>
	/// This class will include <Vector3.h>, <Vector4.h>
	/// It'll compile <cmath> but will nor include it
	/// </summary>
	struct Quaternion
	{
		#pragma region CONSTRUCTORS

		Quaternion(void);

		Quaternion(Quaternion const& other) = default;
		Quaternion(Quaternion&& other) = default;

		/// <summary>
		/// x, y, z, w
		/// </summary>
		Quaternion(const Vector4f&);

		/// <summary>
		/// xyz, w
		/// </summary>
		Quaternion(const Vector3f&, float);

		/// <summary>
		/// w, x, y, z
		/// </summary>
		Quaternion(float, float, float, float);

		Quaternion(float);
		#pragma endregion

		#pragma region OPERATOR

		operator Vector4f() const;													//Conversion operator into a Vector4

		Quaternion&			operator=(const Quaternion&) = default;					//Default operator = to assign values of another quaternion

		Quaternion&			operator=(Quaternion&&) = default;						//Default operator = to move another quaternion into this one	

		float&				operator[](size_t index);								//Operator [] to access values 

		const float&		operator[](size_t index) const;							//Operator [] to access values with const

		Quaternion			operator-(void) const;									//Operator - to negate the quaternion

		bool				operator==(const Quaternion&) const;					//Operator == to see if the quaternion is equal to another

		bool				operator!=(const Quaternion&) const;					//Operator != to see if the quaternion is different than another

		bool				operator<(const Quaternion&) const;						//Operator < for quaternion (comparing magnitude)

		bool				operator<=(const Quaternion&) const;					//Operator <= for quaternion (comparing magnitude)

		bool				operator>(const Quaternion&) const;						//Operator > for quaternion (comparing magnitude)

		bool				operator>=(const Quaternion&) const;					//Operator >= for quaternion (comparing magnitude)

		Quaternion&			operator++(void);										//Operator ++ for quaternion, Increment by one all elements in the quaternion 		

		Quaternion&			operator--(void);										//Operator -- for quaternion, Decrease by one all elements in the quaternion 

		Quaternion			operator+(const Quaternion&) const;						//Operator + for quaternion

		Quaternion&			operator+=(const Quaternion&);							//Operator += for quaternion

		Quaternion			operator+(float) const;									//Operator + for a quaternion with a single value

		Quaternion&			operator+=(float);										//Operator += for a quaternion with a single value

		Quaternion			operator-(const Quaternion&) const;						//Operator - for quaternion

		Quaternion&			operator-=(const Quaternion&);							//Operator -= for quaternion

		Quaternion			operator-(float) const;									//Operator - for a quaternion with a single value

		Quaternion&			operator-=(float);										//Operator -= for a quaternion with a single value

		Quaternion			operator*(const Quaternion&) const;						//Operator * to multiply a quaternion to the current one

		Quaternion&			operator*=(const Quaternion&);							//Operator *= for quaternion

		Quaternion			operator*(float) const;									//Operator * to multiply by a constant

		Quaternion&			operator*=(float);										//Operator *= to multiply by a constant

		Quaternion			operator/(const Quaternion&) const;						//Operator / to divide by the current quaternion by another

		Quaternion&			operator/=(const Quaternion&);							//Operator /= to divide the current quaternion by another

		Quaternion			operator/(float) const;									//Operator / to divide by a constant

		Quaternion&			operator/=(float);										//Operator /= to divide by a constant
#pragma endregion

		#pragma region FUNC

		/// <summary>
		/// Normalize the Quaternion (divide by its magnitude)
		/// </summary>
		void normalize(void);

		/// <summary>
		/// Returns true of the quaternion is unit
		/// </summary>
		bool isUnit(void) const;

		float magnitude(void) const;

		float magnitudeSquared(void) const;

		/// <summary>
		/// Change sign of xyz
		/// </summary>
		void conjugate(void);

		/// <summary>
		/// A Quaternion multiplied by its inverse returns an identity Quaternion
		/// </summary>
		void inverse(void);

		/// <summary>
		/// Rotates a 3D point with the quaternion (Returns the new point)
		/// </summary>
		Vector3f rotate(const Vector3f&) const;

		void setRotationEuler(const PenMath::Vector3f& angles);

		Vector3f getRotationEuler() const noexcept;

		Quaternion fromAxis(const Vector3f& axis, float angle);

		#pragma endregion

		#pragma region STATIC_FUNC

		/// <summary>
		///Returns the normal of the quaternion (divide by its magnitude)
		/// </summary>
		static Quaternion normal(const Quaternion&);

		/// <summary>
		/// Returns true of the quaternion is unit
		/// </summary>
		static bool isUnit(const Quaternion&);

		/// <summary>
		/// Change sign of xyz
		/// </summary>
		static Quaternion conjugate(const Quaternion&);

		/// <summary>
		/// A Quaternion multiplied by its inverse returns an identity Quaternion
		/// </summary>
		static Quaternion inverse(const Quaternion&);

		static Vector3f rotate(const Quaternion&, const Vector3f&);

		/// <summary>
		/// Useful for animation (i don't remember my classes i can't tell you more) 
		/// </summary>
		static Quaternion slerp(const Quaternion&, const Quaternion&, float);
		#pragma endregion

		#pragma region CAST

#if defined(QUATERNION_CAST)
		static Mat4 Matrix(Quaternion const& quat);

		static Mat4 Rotation(Quaternion quat);
#endif

		#pragma endregion
		float x;
		float y;
		float z;
		float w;
	};

#if defined(QUATERNION_DEBUG)
	std::ostream& operator<<(std::ostream& os, const Quaternion& quat)
	{
		os << "Quaternion(" << quat.x << ", " << quat.y << ", " << quat.z << ", " << quat.w << ")";
		return os;
	}
#endif

}
