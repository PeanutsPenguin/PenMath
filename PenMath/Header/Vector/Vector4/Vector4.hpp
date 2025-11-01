#pragma once
#include <Vector/Vector4/Vector4.h>

#include <Arithmetic.h>
#include <cmath>

#define TEMPLATE template<typename _Type>
#define VEC4 Vector<4, _Type>

#if defined (VECTOR4_CAST)
	#include <Vector/Vector2/Vector2.h>
	#include <Vector/Vector3/Vector3.h>
#endif

#if defined(VECTOR4_ANGLE)
	#include <Angle/Radian.h>
#endif

namespace PenMath
{
#pragma region CONSTRUCTORS

	TEMPLATE
	VEC4::Vector(void) : VEC4(_Type(0)) {}

	TEMPLATE
	VEC4::Vector(_Type val) : VEC4(val, val, val, val) {}

	TEMPLATE
	VEC4::Vector(_Type valA, _Type valB, _Type valC, _Type valD) : x(valA), y(valB), z(valC), w(valD) {}

	TEMPLATE 
	VEC4::Vector(const Vector<2, _Type>& vecA, const Vector<2, _Type>& vecB)
	{
		this->x = vecA.x;
		this->y = vecA.y;
		this->z = vecB.x;
		this->w = vecB.y;
	}

	TEMPLATE
	VEC4::Vector(const Vector<3, _Type>& vec, _Type value)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
		this->w = value;
	}

#pragma endregion

#pragma region OPERATOR_VEC4
	TEMPLATE
	VEC4::operator Vector<3, _Type>() const
	{
		return Vector<3, _Type>(this->x, this->y, this->z);
	}

	TEMPLATE
	VEC4::operator Vector<2, _Type>() const
	{
		return Vector<2, _Type>(this->x, this->y);
	}

	TEMPLATE
	_Type& VEC4::operator[](size_t index)
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
		case 3:
			return this->w;
		}
	}

	TEMPLATE
	const _Type& VEC4::operator[](size_t index) const
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
		case 3:
			return this->w;
		}
	}

	TEMPLATE
	VEC4 VEC4::operator-(void) const
	{
		return VEC4(-this->x, -this->y, -this->z, -this->w);
	}

	TEMPLATE
	bool VEC4::operator==(const VEC4& toCompare) const
	{
		return this->x == toCompare.x && this->y == toCompare.y && this->z == toCompare.z && this->w == toCompare.w;
	}

	TEMPLATE
	bool VEC4::operator!=(const VEC4& toCompare) const
	{
		return this->x != toCompare.x || this->y != toCompare.y || this->z != toCompare.z || this->w != toCompare.w;
	}

	TEMPLATE
	bool VEC4::operator<(const VEC4& toCompare) const
	{
		return this->magnitudeSquared() < toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC4::operator<=(const VEC4& toCompare) const
	{
		return this->magnitudeSquared() <= toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC4::operator>(const VEC4& toCompare) const
	{
		return this->magnitudeSquared() > toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC4::operator>=(const VEC4& toCompare) const
	{
		return this->magnitudeSquared() >= toCompare.magnitudeSquared();
	}

	TEMPLATE
	VEC4& VEC4::operator++(void)
	{
		++this->x;
		++this->y;
		++this->z;
		++this->w;
		return *this;
	}

	TEMPLATE
		VEC4& VEC4::operator--(void)
	{
		--this->x;
		--this->y;
		--this->z;
		--this->w;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator+(const VEC4& toAdd) const
	{
		return VEC4(this->x + toAdd.x, this->y + toAdd.y, this->z + toAdd.z, this->w + toAdd.w);
	}

	TEMPLATE
	VEC4& VEC4::operator+=(const VEC4& toAdd)
	{
		this->x += toAdd.x;
		this->y += toAdd.y;
		this->z += toAdd.z;
		this->w += toAdd.w;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator+(_Type toAdd) const
	{
		return VEC4(this->x + toAdd, this->y + toAdd, this->z + toAdd, this->w + toAdd);
	}

	TEMPLATE
	VEC4& VEC4::operator+=(_Type toAdd)
	{
		this->x += toAdd;
		this->y += toAdd;
		this->z += toAdd;
		this->w += toAdd;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator-(const VEC4& toSubtract) const
	{
		return VEC4(this->x - toSubtract.x, this->y - toSubtract.y, this->z - toSubtract.z, this->w - toSubtract.w);
	}

	TEMPLATE
	VEC4& VEC4::operator-=(const VEC4& toSubtract)
	{
		this->x -= toSubtract.x;
		this->y -= toSubtract.y;
		this->z -= toSubtract.z;
		this->w -= toSubtract.w;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator-(_Type toSubtract) const
	{
		return VEC4(this->x - toSubtract, this->y - toSubtract, this->z - toSubtract, this->w -  toSubtract);
	}

	TEMPLATE
	VEC4& VEC4::operator-=(_Type toSubtract)
	{
		this->x -= toSubtract;
		this->y -= toSubtract;
		this->z -= toSubtract;
		this->w -= toSubtract;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator*(const VEC4& toMultiply) const
	{
		return VEC4(this->x * toMultiply.x, this->y * toMultiply.y, this->z * toMultiply.z, this->w * toMultiply.w);
	}

	TEMPLATE
	VEC4& VEC4::operator*=(const VEC4& toMultiply)
	{
		this->x *= toMultiply.x;
		this->y *= toMultiply.y;
		this->z *= toMultiply.z;
		this->w *= toMultiply.w;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator*(_Type toMultiply) const
	{
		return VEC4(this->x * toMultiply, this->y * toMultiply, this->z * toMultiply, this->w * toMultiply);
	}

	TEMPLATE
	VEC4& VEC4::operator*=(_Type toMultiply)
	{
		this->x *= toMultiply;
		this->y *= toMultiply;
		this->z *= toMultiply;
		this->w *= toMultiply;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator/(const VEC4& toDivide) const
	{
		return VEC4(this->x / toDivide.x, this->y / toDivide.y, this->z / toDivide.z, this->w / toDivide.w);
	}

	TEMPLATE
	VEC4& VEC4::operator/=(const VEC4& toDivide)
	{
		this->x /= toDivide.x;
		this->y /= toDivide.y;
		this->z /= toDivide.z;
		this->w /= toDivide.w;
		return *this;
	}

	TEMPLATE
	VEC4 VEC4::operator/(_Type toDivide) const
	{
		return VEC4(this->x / toDivide, this->y / toDivide, this->z / toDivide, this->w / toDivide);
	}

	TEMPLATE
		VEC4& VEC4::operator/=(_Type toDivide)
	{
		this->x /= toDivide;
		this->y /= toDivide;
		this->z /= toDivide;
		this->w /= toDivide;
		return *this;
	}
#pragma endregion

#pragma region FUNC

	TEMPLATE
	_Type VEC4::magnitude(void) const
	{
		return squareRoot(power(static_cast<float>(this->x), 2.f) + power(static_cast<float>(this->y), 2.f) + power(static_cast<float>(this->z), 2.f) + power(static_cast<float>(this->w), 2.f));
	}

	TEMPLATE
	_Type VEC4::magnitudeSquared(void) const
	{
		return power(static_cast<float>(this->x), 2.f) + power(static_cast<float>(this->y), 2.f) + power(static_cast<float>(this->z), 2.f) + power(static_cast<float>(this->w), 2.f);
	}

	TEMPLATE
	void VEC4::normalize(void)
	{
		return this->operator/(this->magnitude());
	}

	TEMPLATE
	_Type VEC4::dot(const VEC4& vec) const
	{
		return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
	}

	TEMPLATE
		VEC4 VEC4::project(const VEC4& vec) const
	{
		return vec * (VEC4::dot(*this, vec) / VEC4::dot(vec, vec));
	}

	TEMPLATE
		VEC4 VEC4::reflect(const VEC4& vec) const
	{
		VEC4 N = VEC4::normalize(vec);
		return vec - N * VEC4::dot(N, *this) * static_cast<_Type>(2);
	}

#pragma endregion

#pragma region STATIC_FUNC

	TEMPLATE
	_Type VEC4::distance(const VEC4& vecA, const VEC4& vecB)
	{
		return vecB.operator-(vecA).magnitude();
	}

	TEMPLATE
	_Type VEC4::distanceSquared(const VEC4& vecA, const VEC4& vecB)
	{
		return vecB.operator-(vecA).magnitudeSquared();
	}

#if defined (VECTOR4_CAST)
	TEMPLATE
	_Type VEC4::distance2(const VEC4& vecA, const VEC4& vecB)
	{
		return Vector<2, _Type>(vecB).operator-(Vector<2, _Type>(vecA)).magnitude();
	}

	TEMPLATE
	_Type VEC4::distance2Squared(const VEC4& vecA, const VEC4& vecB)
	{
		return Vector<2, _Type>(vecB).operator-(Vector<2, _Type>(vecA)).magnitudeSquared();
	}

#endif

	TEMPLATE
	bool VEC4::isUnit(const VEC4& vec)
	{
		return FLOAT_EQ(vec.magnitude(), _Type(1));
	}

	TEMPLATE
	VEC4 VEC4::normal(const VEC4& vec)
	{
		return vec.operator/(vec.magnitude());
	}

	TEMPLATE
	VEC4 VEC4::project(const VEC4& vecA, const VEC4& vecB)
	{
		return vecB * (VEC4::dot(vecA, vecB) / VEC4::dot(vecB, vecB));
	}

	TEMPLATE
	VEC4 VEC4::reflect(const VEC4& vecA, const VEC4& vecB)
	{
		VEC4 N = VEC4::normal(vecB);
		return vecA - N * VEC4::dot(N, vecA) * static_cast<_Type>(2);
	}

	TEMPLATE
	_Type VEC4::dot(const VEC4& vecA, const VEC4& vecB)
	{
		return vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z + vecA.w * vecB.w;
	}
#pragma endregion

#if defined(VECTOR4_DEBUG)
	TEMPLATE
	std::ostream& operator<<(std::ostream& os, const VEC4& vec)
	{
		os << "Vector4 : ";
		os << "{" << vec.x;
		os << ", " << vec.y;
		os << ", " << vec.z;
		os << ", " << vec.w << "}";
		return os;
	}
#endif
}