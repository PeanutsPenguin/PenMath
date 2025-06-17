#pragma once
#include <Vector/Vector3/Vector3.h>
#include <Arithmetic.h>

#define TEMPLATE template<typename _Type>
#define VEC3 Vector<3, _Type>

#if defined (VECTOR3_CAST)
	#include <Vector/Vector2/Vector2.h>
	#include <Vector/Vector4/Vector4.h>
#endif

#if defined(VECTOR3_ANGLE)
#include <Angle/Radian.h>
#endif

namespace PenMath
{
#pragma region CONSTRUCTORS

	TEMPLATE
	VEC3::Vector(void) : VEC3(_Type(0)) {}

	TEMPLATE
	VEC3::Vector(_Type val) : VEC3(val, val, val) {}

	TEMPLATE
	VEC3::Vector(_Type valA, _Type valB, _Type valC) : x(valA), y(valB), z(valC) {}

#pragma endregion

#pragma region BASIC_VEC3
	TEMPLATE
	VEC3 VEC3::Zero(void)
	{
		return VEC3();
	}

	TEMPLATE
	VEC3 VEC3::One(void)
	{
		return VEC3(_Type(1));
	}

	TEMPLATE
	VEC3 VEC3::Up(void)
	{
		return VEC3(_Type(0), _Type(1), _Type(0));
	}

	TEMPLATE
	VEC3 VEC3::Down(void)
	{
		return VEC3(_Type(0), _Type(-1), _Type(0));
	}

	TEMPLATE
	VEC3 VEC3::Left(void)
	{
		return VEC3(_Type(-1), _Type(0), _Type(0));
	}

	TEMPLATE
	VEC3 VEC3::Right(void)
	{
		return VEC3(_Type(1), _Type(0), _Type(0));
	}

	TEMPLATE
	VEC3 VEC3::Front(void)
	{
		return VEC3(_Type(0), _Type(0), _Type(1));
	}

	TEMPLATE
	VEC3 VEC3::Back(void)
	{
		return VEC3(_Type(0), _Type(0), _Type(-1));
	}
#pragma endregion

#pragma region OPERATOR_VEC3

#if defined (VECTOR3_CAST)
	TEMPLATE
	VEC3::operator Vector<4, _Type>() const
	{
		return Vector<4, _Type>(this->x, this->y, this->z, static_cast<_Type>(1));
	}

	TEMPLATE
	VEC3::operator Vector<2, _Type>() const
	{
		return Vector<2, _Type>(this->x, this->y);
	}
#endif 

	TEMPLATE
	_Type& VEC3::operator[](size_t index)
	{
		switch (index)
		{
		default:
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		}
	}

	TEMPLATE
	const _Type& VEC3::operator[](size_t index) const
	{
		switch (index)
		{
		default:
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		}
	}

	TEMPLATE
	VEC3 VEC3::operator-(void) const
	{
		return VEC3(-this->x, -this->y, -this->z);
	}

	TEMPLATE
	bool VEC3::operator==(const VEC3& toCompare) const
	{
		return this->x == toCompare.x && this->y == toCompare.y && this->z == toCompare.z;
	}

	TEMPLATE
	bool VEC3::operator!=(const VEC3& toCompare) const
	{
		return this->x != toCompare.x || this->y != toCompare.y || this->z != toCompare.z;
	}

	TEMPLATE
	bool VEC3::operator<(const VEC3& toCompare) const
	{
		return this->magnitudeSquared() < toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC3::operator<=(const VEC3& toCompare) const
	{
		return this->magnitudeSquared() <= toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC3::operator>(const VEC3& toCompare) const
	{
		return this->magnitudeSquared() > toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC3::operator>=(const VEC3& toCompare) const
	{
		return this->magnitudeSquared() >= toCompare.magnitudeSquared();
	}

	TEMPLATE
	VEC3& VEC3::operator++(void)
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	TEMPLATE
	VEC3& VEC3::operator--(void)
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator+(const VEC3& toAdd) const
	{
		return VEC3(this->x + toAdd.x, this->y + toAdd.y, this->z + toAdd.z);
	}

	TEMPLATE
	VEC3& VEC3::operator+=(const VEC3& toAdd)
	{
		this->x += toAdd.x;
		this->y += toAdd.y;
		this->z += toAdd.z;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator+(_Type toAdd) const
	{
		return VEC3(this->x + toAdd, this->y + toAdd, this->z + toAdd);
	}

	TEMPLATE
	VEC3& VEC3::operator+=(_Type toAdd)
	{
		this->x += toAdd;
		this->y += toAdd;
		this->z += toAdd;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator-(const VEC3& toSubtract) const
	{
		return VEC3(this->x - toSubtract.x, this->y - toSubtract.y, this->z - toSubtract.z);
	}

	TEMPLATE
	VEC3& VEC3::operator-=(const VEC3& toSubtract)
	{
		this->x -= toSubtract.x;
		this->y -= toSubtract.y;
		this->z -= toSubtract.z;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator-(_Type toSubtract) const
	{
		return VEC3(this->x - toSubtract, this->y - toSubtract, this->z - toSubtract.z);
	}

	TEMPLATE
	VEC3& VEC3::operator-=(_Type toSubtract)
	{
		this->x -= toSubtract;
		this->y -= toSubtract;
		this->z -= toSubtract
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator*(const VEC3& toMultiply) const
	{
		return VEC3(this->x * toMultiply.x, this->y * toMultiply.y, this->z * toMultiply.z);
	}

	TEMPLATE
	VEC3& VEC3::operator*=(const VEC3& toMultiply)
	{
		this->x *= toMultiply.x;
		this->y *= toMultiply.y;
		this->z *= toMultiply.z;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator*(_Type toMultiply) const
	{
		return VEC3(this->x * toMultiply, this->y * toMultiply, this->z * toMultiply);
	}

	TEMPLATE
	VEC3& VEC3::operator*=(_Type toMultiply)
	{
		this->x *= toMultiply;
		this->y *= toMultiply;
		this->z *= toMultiply;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator/(const VEC3& toDivide) const
	{
		return VEC3(this->x / toDivide.x, this->y / toDivide.y, this->z / toDivide.z);
	}

	TEMPLATE
	VEC3& VEC3::operator/=(const VEC3& toDivide)
	{
		this->x /= toDivide.x;
		this->y /= toDivide.y;
		this->z /= toDivide.z;
		return *this;
	}

	TEMPLATE
	VEC3 VEC3::operator/(_Type toDivide) const
	{
		return VEC3(this->x / toDivide, this->y / toDivide, this->z / toDivide);
	}

	TEMPLATE
	VEC3& VEC3::operator/=(_Type toDivide)
	{
		this->x /= toDivide;
		this->y /= toDivide;
		this->z /= toDivide;
		return *this;
	}
#pragma endregion

#pragma region FUNC

	TEMPLATE
	_Type VEC3::magnitude(void) const
	{
		return std::sqrtf(power(static_cast<float>(this->x), 2.f) + power(static_cast<float>(this->y), 2.f) + power(static_cast<float>(this->z), 2.f));
	}

	TEMPLATE
	_Type VEC3::magnitudeSquared(void) const
	{
		return power(static_cast<float>(this->x), 2.f) + power(static_cast<float>(this->y), 2.f) + power(static_cast<float>(this->z), 2.f);
	}

	TEMPLATE
	void VEC3::normalize(void)
	{
		return this->operator/(this->magnitude());
	}

	TEMPLATE
	_Type VEC3::dot(const VEC3& vec) const 
	{
		return this->x * vec.x + this->y * vec.y + this->z * vec.z;
	}

	TEMPLATE
	VEC3 VEC3::cross(const VEC3& vec) const 
	{
		return VEC3(this->y * vec.z - this->z * vec.y, this->z * vec.x - this->x * vec.z, this->x * vec.y - this->y * vec.x);
	}

	TEMPLATE
	VEC3 VEC3::project(const VEC3& vec) const
	{
		return vec * (VEC3::dot(*this, vec) / VEC3::dot(vec, vec));
	}

	TEMPLATE
	VEC3 VEC3::reflect(const VEC3& vec) const 
	{
		VEC3 N = VEC3::normalize(vec);
		return vec - N * VEC3::dot(N, *this) * static_cast<_Type>(2);
	}

#pragma endregion

#pragma region STATIC_FUNC

	TEMPLATE
	_Type VEC3::distance(const VEC3& vecA, const VEC3& vecB)
	{
		return vecB.operator-(vecA).magnitude();
	}

	TEMPLATE
	_Type VEC3::distanceSquared(const VEC3& vecA, const VEC3& vecB)
	{
		return vecB.operator-(vecA).magnitudeSquared();
	}

#if defined (VECTOR3_CAST)
	TEMPLATE
	_Type VEC3::distance2(const VEC3& vecA, const VEC3& vecB)
	{
		return Vector<2, _Type>(vecB).operator-(Vector<2, _Type>(vecA)).magnitude();
	}

	TEMPLATE
	_Type VEC3::distance2Squared(const VEC3& vecA, const VEC3& vecB)
	{
		return Vector<2, _Type>(vecB).operator-(Vector<2, _Type>(vecA)).magnitudeSquared();
	}

#endif

	TEMPLATE
	bool VEC3::isUnit(const VEC3& vec)
	{
		return FLOAT_EQ(vec.magnitude(), _Type(1));
	}

	TEMPLATE
	VEC3 VEC3::normal(const VEC3& vec)
	{
		return vec.operator/(vec.magnitude());
	}

	TEMPLATE
	VEC3 VEC3::project(const VEC3& a, const VEC3& b)
	{
		return b * (VEC3::dot(a, b) / VEC3::dot(b, b));
	}

	TEMPLATE
	VEC3 VEC3::reflect(const VEC3& a, const VEC3& b)
	{
		VEC3 N = VEC3::normal(b);
		return a - N * VEC3::dot(N, a) * static_cast<_Type>(2);
	}

	TEMPLATE
	_Type VEC3::dot(const VEC3& a, const VEC3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	TEMPLATE
	VEC3 VEC3::cross(const VEC3& a, const VEC3& b)
	{
		return VEC3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

#pragma endregion

#pragma region ANGLE

#if defined(VECTOR3_ANGLE)
	TEMPLATE
	Radian VEC3::angle(const VEC3& vecA, const VEC3& vecB)
	{
		VEC3 normA = VEC3::normal(vecA);
		VEC3 normB = VEC3::normal(vecB);

		float value = VEC3::dot(normA, normB);

		if (std::isnan(value))
			std::cerr << "__FUNCTION__ : Dot product of normal(vecA) and normal(vecB) = nan\n";

		return Radian(std::acos(value));
	}

	TEMPLATE
	Radian VEC3::angle(const VEC3& a, const VEC3& b, const VEC3& c)
	{
		VEC3 vec1(a.x - b.x, a.y - b.y, a.z - b.z);
		VEC3 vec2(c.x - b.x, c.y - b.y, c.z - b.z);

		return VEC3::angle(vec1, vec2);
	}

	TEMPLATE
	Radian VEC3::angleFrom(const VEC3& other, bool range) const
	{
		float dot = VEC3::dot(*this, other);
		float magnitudeDenom = (this->magnitude() * other.magnitude());
		float limitedAngle = std::acosf(dot / magnitudeDenom);

		if (!range)
		{
			return Radian(limitedAngle);
		}

		float cross = VEC3::cross(*this, other).Magnitude();

		float radian;
		if (std::asinf(cross / magnitudeDenom) < 0)
		{
			radian = g_2pi - limitedAngle;
			return Radian(radian);
		}

		return Radian(limitedAngle);
	}

	TEMPLATE
	void VEC3::rotate(const Radian& xRot, const Radian& yRot, const Radian& zRot)
	{
		float cosZ = std::cosf(zRot.raw());
		float sinZ = std::sinf(zRot.raw());

		float cosX = std::cosf(xRot.raw());
		float sinX = std::sinf(xRot.raw());

		float cosY = std::cosf(yRot.raw());
		float sinY = std::sinf(yRot.raw());

		float tempX = this->x * (cosZ * cosY + sinZ * sinX * sinY)
			+ this->y * (-cosZ * sinY + sinZ * sinX * cosY)
			+ this->z * (sinZ * cosX);

		float tempY = this->x * (sinY * cosX)
			+ this->y * (cosY * cosX)
			+ this->z * -sinX;

		float tempZ = this->x * (-sinZ * cosY + cosZ * sinX * sinY)
			+ this->y * (sinZ * sinY + cosZ * sinX * cosY)
			+ this->z * (cosZ * cosX);

		this->x = tempX, this->y = tempY, this->z = tempZ;;
	}

	TEMPLATE
	void VEC3::rotate(const Radian& angle, const VEC3& other)
	{
		float cosR = std::cosf(angle.raw());
		float sinR = std::sinf(angle.raw());

		VEC3 unitOther;

		if (!VEC3::isUnit(other))
			unitOther =VEC3::normal(other);
		else
			unitOther = other;

		VEC3 temp = unitOther * (1 - cosR);

		float tempX = this->x * (cosR + temp.x * unitOther.x)
			+ this->y * (temp.y * unitOther.x - sinR * unitOther.z)
			+ this->z * (temp.z * unitOther.x + sinR * unitOther.y);
		
		float tempY = this->x * (temp.x * unitOther.y + sinR * unitOther.z)
			+ this->y * (cosR + temp.y * unitOther.y)
			+ this->z * (temp.z * unitOther.y - sinR * unitOther.x);

		float tempZ = this->x * (temp.x * unitOther.z - sinR * unitOther.y)
			+ this->y * (temp.y * unitOther.z + sinR * unitOther.x)
			+ this->z * (cosR + temp.z * unitOther.z);

		this->x = tempX, this->y = tempY, this->z = tempZ;
	}
#endif
#pragma endregion

#if defined(VECTOR3_DEBUG)
	TEMPLATE
		std::ostream& operator<<(std::ostream& os, const VEC4& vec)
	{
		os << "Vector4 : ";
		os << "{" << vec.x;
		os << ", " << vec.y;
		os << ", " << vec.z << "}";
		return os;
	}
#endif
}