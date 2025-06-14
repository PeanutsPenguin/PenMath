#pragma once
#include <Vector/Vector2.h>

#define TEMPLATE template<typename _Type>
#define VEC2 Vector<2, _Type>

namespace PenMath
{
	#pragma region CONSTRUCTORS
	TEMPLATE
	VEC2::Vector(void) : VEC2(_Type(0)) {}

	TEMPLATE
	VEC2::Vector(_Type val) : VEC2(val, val) {}

	TEMPLATE
	VEC2::Vector(_Type valA, _Type valB) : x(valA), y(valB) {}
	#pragma endregion

	#pragma region BASIC_VEC2
	TEMPLATE
	Vector<2, int> VEC2::Zero(void)
	{
		return VEC2(0);
	}

	TEMPLATE
	Vector<2, int> VEC2::One(void)
	{
		return VEC2(1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Up(void)
	{
		return VEC2(0, 1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Down(void)
	{
		return VEC2(0, -1);
	}

	TEMPLATE
	Vector<2, int> VEC2::Left(void)
	{
		return VEC2(-1, 0);
	}

	TEMPLATE
	Vector<2, int> VEC2::Right(void)
	{
		return VEC2(1, 0);
	}
	#pragma endregion

	#pragma region OPERATOR_VEC2
	TEMPLATE
	_Type& VEC2::operator[](size_t index)
	{
		switch (index)
		{
		default:
		case 0:
			return this->x;
		case 1:
			return this->y;
		}
	}

	TEMPLATE
	const _Type& VEC2::operator[](size_t index) const 
	{
		switch (index)
		{
		default:
		case 0:
			return this->x;
		case 1:
			return this->y;
		}
	}

	TEMPLATE
	VEC2 VEC2::operator-(void) const 
	{
		return VEC2(-this->x, -this->y);
	}

	TEMPLATE
	bool VEC2::operator==(const VEC2& toCompare) const
	{
		return this->x == toCompare.x && this->y == toCompare.y;
	}

	TEMPLATE
	bool VEC2::operator!=(const VEC2& toCompare) const
	{
		return this->x != toCompare.x || this->y != toCompare.y;
	}

	TEMPLATE
	bool VEC2::operator<(const VEC2& toCompare) const 
	{
		return this->magnitudeSquared() < toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC2::operator<=(const VEC2& toCompare) const
	{
		return this->magnitudeSquared() <= toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC2::operator>(const VEC2& toCompare) const
	{
		return this->magnitudeSquared() > toCompare.magnitudeSquared();
	}

	TEMPLATE
	bool VEC2::operator>=(const VEC2& toCompare) const
	{
		return this->magnitudeSquared() >= toCompare.magnitudeSquared();
	}

	TEMPLATE
	VEC2& VEC2::operator++(void)
	{
		++this->x;
		++this->y;
		return *this;
	}

	TEMPLATE
	VEC2& VEC2::operator--(void)
	{
		--this->x;
		--this->y;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator+(const VEC2& toAdd) const
	{
		return VEC2(this->x + toAdd.x, this->y + toAdd.y);
	}

	TEMPLATE
	VEC2& VEC2::operator+=(const VEC2& toAdd) 
	{
		this->x += toAdd.x;
		this->y += toAdd.y;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator+(_Type toAdd) const
	{
		return VEC2(this->x + toAdd, this->y + toAdd);
	}

	TEMPLATE
	VEC2& VEC2::operator+=(_Type toAdd)
	{
		this->x += toAdd;
		this->y += toAdd;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator-(const VEC2& toSubtract) const
	{
		return VEC2(this->x - toSubtract.x, this->y - toSubtract.y);
	}

	TEMPLATE
	VEC2& VEC2::operator-=(const VEC2& toSubtract)
	{
		this->x -= toSubtract.x;
		this->y -= toSubtract.y;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator-(_Type toSubtract) const
	{
		return VEC2(this->x - toSubtract, this->y - toSubtract);
	}

	TEMPLATE
	VEC2& VEC2::operator-=(_Type toSubtract)
	{
		this->x -= toSubtract;
		this->y -= toSubtract;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator*(const VEC2& toMultiply) const
	{
		return VEC2(this->x * toMultiply.x, this->y * toMultiply.y);
	}

	TEMPLATE 
	VEC2& VEC2::operator*=(const VEC2& toMultiply)
	{
		this->x *= toMultiply.x;
		this->y *= toMultiply.y;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator*(_Type toMultiply) const
	{
		return VEC2(this->x * toMultiply, this->y * toMultiply);
	}
	
	TEMPLATE
	VEC2& VEC2::operator*=(_Type toMultiply)
	{
		this->x *= toMultiply;
		this->y *= toMultiply;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator/(const VEC2& toDivide) const
	{
		return VEC2(this->x / toDivide.x, this->y / toDivide.y);
	}

	TEMPLATE 
	VEC2& VEC2::operator/=(const VEC2& toDivide)
	{
		this->x /= toDivide.x;
		this->y /= toDivide.y;
		return *this;
	}

	TEMPLATE
	VEC2 VEC2::operator/(_Type toDivide) const
	{
		return VEC2(this->x / toDivide, this->y / toDivide);
	}

	TEMPLATE
	VEC2& VEC2::operator/=(_Type toDivide)
	{
		this->x /= toDivide;
		this->y /= toDivide;
		return *this;
	}
	#pragma endregion

	#pragma region FUNC
	TEMPLATE
	_Type VEC2::magnitude(void) const 
	{
		return std::sqrtf(std::powf(static_cast<float>(this->x), 2.f) + std::powf(static_cast<float>(this->y), 2.f));
	}

	TEMPLATE
	_Type VEC2::magnitudeSquared(void) const
	{
		return std::powf(static_cast<float>(this->x), 2.f) + std::powf(static_cast<float>(this->y), 2.f);
	}

	TEMPLATE
	void VEC2::normalize(void)
	{
		*this /= this->magnitude();
	}

	TEMPLATE
	_Type VEC2::dot(const VEC2& vec) const 
	{
		return this->x * vec.x + this->y * vec.y;
	}

	TEMPLATE 
	_Type  VEC2::cross(const VEC2& vec) const 
	{
		return this->x * vec.y - this->y * vec.x;
	}

	TEMPLATE
	VEC2 VEC2::project(const VEC2& vec) const
	{
		return (VEC2::dot(*this, vec) / VEC2::dot(vec, vec)) * vec;
	}

	TEMPLATE
	VEC2 VEC2::reflect(const VEC2& vec) const
	{
		VEC2 normal = VEC2::normalize(vec);
		return *this - normal * VEC2::dot(normal, *this) * static_cast<_Type>(2);
	}
	#pragma endregion

#pragma region STATIC_FUNC
	TEMPLATE
	_Type VEC2::distance(const VEC2& vecA, const VEC2& vecB)
	{
		return (vecA - vecB).magnitude();
	}

	TEMPLATE
	_Type VEC2::distanceSquared(const VEC2& vecA, const VEC2& vecB)
	{
		return (vecA - vecB).magnitudeSquared();
	}

	TEMPLATE
	bool VEC2::isUnit(const VEC2& vec)
	{
		//TODO almostequal()
		return  vec.Magnitude() == _Type(1);
	}

	TEMPLATE
	VEC2 VEC2::normal(const VEC2& vec)
	{
		return vec / vec.magnitude();
	}

	TEMPLATE
	_Type VEC2::dot(const VEC2& vecA, const VEC2& vecB)
	{
		return vecA.x * vecB.x + vecA.y * vecB.y;
	}

	TEMPLATE
	_Type  VEC2::cross(const VEC2& vecA, const VEC2& vecB)
	{
		return vecA.x * vecB.y - vecA.y * vecB.x;
	}

	TEMPLATE
	VEC2 VEC2::project(const VEC2& vecA, const VEC2& vecB)
	{
		return VEC2(vecA.dot(vecB) / vecB.dot(vecB)) * vecB;
	}

	TEMPLATE
	VEC2 VEC2::reflect(const VEC2& vecA, const VEC2& vecB)
	{
		VEC2 normal = VEC2::normal(vecB);
		return vecA - normal * VEC2::dot(normal, vecA) * static_cast<_Type>(2);
	}

#pragma endregion
}
