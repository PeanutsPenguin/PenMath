#include "Angle/Degree.h"

using namespace PenMath;

#pragma region CONSTRUCTORS
Degree::Degree(float value) : m_value(value) {}

Degree::Degree(const Degree& cpy) : m_value(cpy.m_value) {}
#pragma endregion

#pragma region IN_CLASS_OPERATORS

Degree Degree::operator-() const
{
	return Degree(-this->m_value);
}

Degree Degree::operator+(const Degree& deg)
{
	return Degree(this->m_value + deg.m_value);
}

Degree& Degree::operator+=(const Degree& deg)
{
	this->m_value += deg.m_value;
	return *this;
}

Degree Degree::operator+(float value)
{
	return Degree(this->m_value + value);
}

Degree& Degree::operator+=(float value)
{
	this->m_value += value;
	return *this;
}

Degree Degree::operator-(const Degree& deg)
{
	return Degree(this->m_value - deg.m_value);
}

Degree& Degree::operator-=(const Degree& deg)
{
	this->m_value -= deg.m_value;
	return *this;
}

Degree Degree::operator-(float value)
{
	return Degree(this->m_value - value);
}

Degree& Degree::operator-=(float value)
{
	this->m_value -= value;
	return *this;
}

Degree Degree::operator*(const Degree& deg)
{
	return Degree(this->m_value * deg.m_value);
}

Degree& Degree::operator*=(const Degree& deg)
{
	this->m_value *= deg.m_value;
	return *this;
}

Degree Degree::operator*(float value)
{
	return Degree(this->m_value * value);
}

Degree& Degree::operator*=(float value)
{
	this->m_value *= value;
	return *this;
}

Degree Degree::operator/(const Degree& deg)
{
	return Degree(this->m_value / deg.m_value);
}

Degree& Degree::operator/=(const Degree& deg)
{
	this->m_value /= deg.m_value;
	return *this;
}

Degree Degree::operator/(float value)
{
	return Degree(this->m_value / value);
}

Degree& Degree::operator/=(float value)
{
	this->m_value /= value;
	return *this;
}

#pragma endregion

#pragma region FUNC

void Degree::wrap(bool range)
{
	this->m_value = this->wrappedValue(range);
}

float Degree::wrappedValue(bool range) const
{
	int int_degree = (int)this->m_value;
	float decimal_part = this->m_value - int_degree;
	float result = 0;

	if (int_degree >= 0)
	{
		result = (int_degree % 360) + decimal_part;
	}
	else
	{
		result = 360 + (int_degree % 360) + decimal_part;
	}

	if (range && result >= 180)
	{
		result -= 360;
	}

	return result;
}

float Degree::raw() const 
{
	return this->m_value;
}

float Degree::radian() const
{
	//TODO Define pi value in future arithmetic file
	return this->m_value * 3.141592653589793f / 180;
}

#pragma endregion

#pragma region OUT_CLASS_OPERATORS

bool PenMath::operator==(Degree degA, Degree degB)
{
	if (degA.wrappedValue() == degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(Degree deg, float value)
{
	if (deg.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator==(float value , Degree deg)
{
	if (deg.wrappedValue() == value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Degree degA, Degree degB)
{
	if (degA.wrappedValue() != degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(Degree deg, float value)
{
	if (deg.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator!=(float value, Degree deg)
{
	if (deg.wrappedValue() != value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Degree degA, Degree degB)
{
	if (degA.wrappedValue() > degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(Degree deg, float value)
{
	if (deg.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>(float value, Degree deg)
{
	if (deg.wrappedValue() > value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Degree degA, Degree degB)
{
	if (degA.wrappedValue() >= degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(Degree deg, float value)
{
	if (deg.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator>=(float value, Degree deg)
{
	if (deg.wrappedValue() >= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Degree degA, Degree degB)
{
	if (degA.wrappedValue() < degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(Degree deg, float value)
{
	if (deg.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<(float value, Degree deg)
{
	if (deg.wrappedValue() < value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Degree degA, Degree degB)
{
	if (degA.wrappedValue() <= degB.wrappedValue())
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(Degree deg, float value)
{
	if (deg.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

bool PenMath::operator<=(float value, Degree deg)
{
	if (deg.wrappedValue() <= value)
	{
		return true;
	}
	return false;
}

#pragma endregion