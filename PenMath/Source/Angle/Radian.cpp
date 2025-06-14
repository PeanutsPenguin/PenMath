#include "Angle/Radian.h"
#include "Angle/Degree.h"

using namespace PenMath;

#pragma region CONSTRUCTORS
Radian::Radian(float value) : m_value(value) {}

Radian::Radian(const Radian& cpy) : m_value(cpy.m_value) {}
#pragma endregion

#pragma region IN_CLASS_OPERATORS

Radian Radian::operator-() const
{
	return Radian(-this->m_value);
}

PenMath::Radian::operator Degree() const
{
	return Degree(this->degree());
}

Radian Radian::operator+(const Radian& deg)
{
	return Radian(this->m_value + deg.m_value);
}

Radian& Radian::operator+=(const Radian& deg)
{
	this->m_value += deg.m_value;
	return *this;
}

Radian Radian::operator+(float value)
{
	return Radian(this->m_value + value);
}

Radian& Radian::operator+=(float value)
{
	this->m_value += value;
	return *this;
}

Radian Radian::operator-(const Radian& deg)
{
	return Radian(this->m_value - deg.m_value);
}

Radian& Radian::operator-=(const Radian& deg)
{
	this->m_value -= deg.m_value;
	return *this;
}

Radian Radian::operator-(float value)
{
	return Radian(this->m_value - value);
}

Radian& Radian::operator-=(float value)
{
	this->m_value -= value;
	return *this;
}

Radian Radian::operator*(const Radian& deg)
{
	return Radian(this->m_value * deg.m_value);
}

Radian& Radian::operator*=(const Radian& deg)
{
	this->m_value *= deg.m_value;
	return *this;
}

Radian Radian::operator*(float value)
{
	return Radian(this->m_value * value);
}

Radian& Radian::operator*=(float value)
{
	this->m_value *= value;
	return *this;
}

Radian Radian::operator/(const Radian& deg)
{
	return Radian(this->m_value / deg.m_value);
}

Radian& Radian::operator/=(const Radian& deg)
{
	this->m_value /= deg.m_value;
	return *this;
}

Radian Radian::operator/(float value)
{
	return Radian(this->m_value / value);
}

Radian& Radian::operator/=(float value)
{
	this->m_value /= value;
	return *this;
}

#pragma endregion

#pragma region FUNC

void Radian::wrap(bool range)
{
	this->m_value = this->wrappedValue(range);
}

float Radian::wrappedValue(bool range) const
{
	float result = 0;

	//TODO Define pi value in future arithmetic file
	/* Checking if a m_value is already in the wanted range */
	if ((range && m_value >= -1 * 3.141592653589793f && m_value < 3.141592653589793f)
		|| (!range && m_value >= 0 && m_value < 2 * 3.141592653589793f))
		return m_value;
	/* Checking if m_value is strictly inferior to 2Pi so that
	in the case where m_value = 2Pi, 0 will be returned */
	/* Same for [-Pi, Pi] */

	//Replace with floor in arithmetic
	//result =  this->m_value -  (2 * 3.141592653589793f) * std::floor(angle / twoPi);

	if (range && result >= 3.141592653589793f)
	{
		result -= 2.0f * 3.141592653589793f;
	}

	return result;
}

float Radian::raw() const
{
	return this->m_value;
}

float Radian::degree() const
{
	//TODO Define pi value in future arithmetic file
	return this->m_value * 180 / 3.141592653589793f;
}

#pragma endregion

#pragma region OUT_CLASS_OPERATORS

bool PenMath::operator==(Radian degA, Radian degB)
{
	if (degA.wrappedValue() == degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(Radian deg, float value)
{
	if (deg.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(float value, Radian deg)
{
	if (deg.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Radian degA, Radian degB)
{
	if (degA.wrappedValue() != degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Radian deg, float value)
{
	if (deg.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(float value, Radian deg)
{
	if (deg.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Radian degA, Radian degB)
{
	if (degA.wrappedValue() > degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Radian deg, float value)
{
	if (deg.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(float value, Radian deg)
{
	if (deg.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Radian degA, Radian degB)
{
	if (degA.wrappedValue() >= degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Radian deg, float value)
{
	if (deg.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(float value, Radian deg)
{
	if (deg.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Radian degA, Radian degB)
{
	if (degA.wrappedValue() < degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Radian deg, float value)
{
	if (deg.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(float value, Radian deg)
{
	if (deg.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Radian degA, Radian degB)
{
	if (degA.wrappedValue() <= degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Radian deg, float value)
{
	if (deg.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(float value, Radian deg)
{
	if (deg.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

#pragma endregion