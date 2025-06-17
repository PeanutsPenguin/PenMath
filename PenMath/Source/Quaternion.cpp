#include "Quaternion.h"

#include <cmath>

using namespace PenMath;

#pragma region CONSTRUCTORS
Quaternion::Quaternion() : x(0), y(0), z(0), w(0) {}

Quaternion::Quaternion(const Vector4f& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}

Quaternion::Quaternion(const Vector3f& vec, float value) : x(vec.x), y(vec.y), z(vec.z), w(value) {}

Quaternion::Quaternion(float valueA, float valueB, float valueC, float valueD) : x(valueB), y(valueC), z(valueD), w(valueA) {}

Quaternion::Quaternion(float value) : x(value), y(value), z(value), w(value) {}
#pragma endregion

#pragma region OPERATOR

Quaternion::operator Vector4f() const
{
	return Vector4f(this->x, this->y, this->z, this->w);
}

float& Quaternion::operator[](size_t index)
{
	switch (index)
	{
	default:
	case 0:
		return this->w;
	case 1:
		return this->x;
	case 2:
		return this->y;
	case 3:
		return this->z;
	}
}

const float& Quaternion::operator[](size_t index) const
{
	switch (index)
	{
	default:
	case 0:
		return this->w;
	case 1:
		return this->x;
	case 2:
		return this->y;
	case 3:
		return this->z;
	}
}

Quaternion Quaternion::operator-(void) const
{
	return Quaternion(-this->w , -this->x, -this->y, -this->z);
}

bool Quaternion::operator==(const Quaternion & toCompare) const
{
	return this->x == toCompare.x && this->y == toCompare.y && this->z == toCompare.z && this->w == toCompare.w;
}

bool Quaternion::operator!=(const Quaternion & toCompare) const
{
	return this->x != toCompare.x || this->y != toCompare.y || this->z != toCompare.z || this->w != toCompare.w;
}

bool Quaternion::operator<(const Quaternion & toCompare) const
{
	return this->magnitudeSquared() < toCompare.magnitudeSquared();
}

bool Quaternion::operator<=(const Quaternion & toCompare) const
{
	return this->magnitudeSquared() <= toCompare.magnitudeSquared();
}

bool Quaternion::operator>(const Quaternion & toCompare) const
{
	return this->magnitudeSquared() > toCompare.magnitudeSquared();
}

bool Quaternion::operator>=(const Quaternion & toCompare) const
{
	return this->magnitudeSquared() >= toCompare.magnitudeSquared();
}

Quaternion& Quaternion::operator++(void)
{
	++this->x;
	++this->y;
	++this->z;
	++this->w;
	return *this;
}

Quaternion& Quaternion::operator--(void)
{
	--this->x;
	--this->y;
	--this->z;
	--this->w;
	return *this;
}

Quaternion Quaternion::operator+(const Quaternion & toAdd) const
{
	return Quaternion(this->w + toAdd.w, this->x + toAdd.x, this->y + toAdd.y, this->z + toAdd.z);
}

Quaternion& Quaternion::operator+=(const Quaternion & toAdd)
{
	this->x += toAdd.x;
	this->y += toAdd.y;
	this->z += toAdd.z;
	this->w += toAdd.w;
	return *this;
}

Quaternion Quaternion::operator+(float toAdd) const
{
	return Quaternion(this->w + toAdd, this->x + toAdd, this->y + toAdd, this->z + toAdd);
}

Quaternion& Quaternion::operator+=(float toAdd)
{
	this->x += toAdd;
	this->y += toAdd;
	this->z += toAdd;
	this->w += toAdd;
	return *this;
}

Quaternion Quaternion::operator-(const Quaternion & toSubtract) const
{
	return Quaternion(this->w - toSubtract.w, this->x - toSubtract.x, this->y - toSubtract.y, this->z - toSubtract.z);
}

Quaternion& Quaternion::operator-=(const Quaternion & toSubtract)
{
	this->x -= toSubtract.x;
	this->y -= toSubtract.y;
	this->z -= toSubtract.z;
	this->w -= toSubtract.w;
	return *this;
}

Quaternion Quaternion::operator-(float toSubtract) const
{
	return Quaternion(this->w - toSubtract, this->x - toSubtract, this->y - toSubtract, this->z - toSubtract);
}

Quaternion& Quaternion::operator-=(float toSubtract)
{
	this->x -= toSubtract;
	this->y -= toSubtract;
	this->z -= toSubtract;
	this->w -= toSubtract;
	return *this;
}

Quaternion Quaternion::operator*(const Quaternion & toMultiply) const
{
	Vector3f const lhsIm = Vector3f(this->x, this->y, this->z);
	Vector3f const rhsIm = Vector3f(toMultiply.x, toMultiply.y, toMultiply.z);

	return Quaternion(rhsIm * this->w + lhsIm * toMultiply.w + Vector3f::cross(lhsIm, rhsIm), 
		this->w * toMultiply.w - Vector3f::dot(lhsIm, rhsIm));
}

Quaternion& Quaternion::operator*=(const Quaternion & toMultiply)
{
	Quaternion result = *this * toMultiply;
	memcpy(this, &result, sizeof(result));
	return *this;
}

Quaternion Quaternion::operator*(float toMultiply) const
{
	return Quaternion(this->w * toMultiply, this->x * toMultiply, this->y * toMultiply, this->z * toMultiply);
}

Quaternion& Quaternion::operator*=(float toMultiply)
{
	this->x *= toMultiply;
	this->y *= toMultiply;
	this->z *= toMultiply;
	this->w *= toMultiply;
	return *this;
}

Quaternion Quaternion::operator/(const Quaternion & toDivide) const
{
	return Quaternion(this->w / toDivide.w, this->x / toDivide.x, this->y / toDivide.y, this->z / toDivide.z);
}

Quaternion& Quaternion::operator/=(const Quaternion & toDivide)
{
	this->x /= toDivide.x;
	this->y /= toDivide.y;
	this->z /= toDivide.z;
	this->w /= toDivide.w;
	return *this;
}

Quaternion Quaternion::operator/(float toDivide) const
{
	return Quaternion(this->w / toDivide, this->x / toDivide, this->y / toDivide, this->z / toDivide);
}

Quaternion& Quaternion::operator/=(float toDivide)
{
	this->x /= toDivide;
	this->y /= toDivide;
	this->z /= toDivide;
	this->w /= toDivide;
	return *this;
}
#pragma endregion

#pragma region FUNC

void Quaternion::normalize()
{
	if(!almostEqual(this->magnitudeSquared(), 1.f))
		*this /= this->magnitude();
}

bool Quaternion::isUnit() const 
{
	return almostEqual(this->magnitudeSquared(), 1.f);
}

float Quaternion::magnitude() const
{
	float const mSquared = this->magnitudeSquared();
	return almostEqual(mSquared, 1.f) ? 1.f : std::sqrtf(mSquared);
}

float Quaternion::magnitudeSquared() const 
{
	return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
}

void Quaternion::conjugate(void)
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

void Quaternion::inverse(void)
{
	float const magnitude = this->magnitude();
	float const mult = almostEqual(magnitude, 1.f) ? 1.f : 1.f / magnitude;

	this->conjugate();

	*this *= mult;
}

Vector3f Quaternion::rotate(const Vector3f& vec) const
{
	Vector3f quatVector{ this->x, this->y, this->z };
	Vector3f uv = Vector3f::cross(quatVector, vec);
	Vector3f uuv = Vector3f::cross(quatVector, uv);

	return	vec + ((uv *this->w) + uuv) * 2;
}

#pragma endregion

#pragma region STATIC_FUNC

Quaternion Quaternion::normal(const Quaternion& quat)
{
	float const magnitude = quat.magnitude();
	return almostEqual(magnitude, 1.f) ? quat : quat / magnitude;
}

bool Quaternion::isUnit(const Quaternion& quat)
{
	return almostEqual(quat.magnitudeSquared(), 1.f);;
}

Quaternion Quaternion::conjugate(const Quaternion& quat)
{
	return Quaternion(-Vector3f(quat.x, quat.y, quat.z), quat.w);
}

Quaternion Quaternion::inverse(const Quaternion& quat)
{
	float const magnitude = quat.magnitude();
	float const mult = almostEqual(magnitude, 1.f) ? 1.f : 1.f / magnitude;

	return Quaternion::conjugate(quat) * mult;
}

Vector3f Quaternion::rotate(const Quaternion& quat, const Vector3f& vec)
{
	return quat.rotate(vec);
}

Quaternion Quaternion::slerp(const Quaternion& quatA, const Quaternion& quatB, float lerp)
{
	float RawCosom = Vector4f::dot(quatA, quatB);

	float const Sign = RawCosom >= 0.f ? 1.f : -1.f;
	RawCosom *= Sign;

	float Scale0 = 1.f - lerp;
	float Scale1 = lerp * Sign;

	if (RawCosom < 1.f)
	{
		float const Omega = std::acos(RawCosom);
		float const InvSin = 1.f / std::sin(Omega);
		Scale0 = std::sin(Scale0 * Omega) * InvSin;
		Scale1 = std::sin(Scale1 * Omega) * InvSin;
	}

	return quatA * Scale0 + quatB * Scale1;
}
